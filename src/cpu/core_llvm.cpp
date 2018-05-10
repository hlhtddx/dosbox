/*
 *  Copyright (C) 2002-2017  The DOSBox Team
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2 of the License, or
 *  (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 */

#include <stdio.h>

#include "dosbox.h"
#include "mem.h"
#include "cpu.h"
#include "lazyflags.h"
#include "inout.h"
#include "callback.h"
#include "pic.h"
#include "fpu.h"
#include "paging.h"

#if C_DEBUG
#include "debug.h"
#endif

#if (!C_CORE_INLINE)
#define LoadMb(off) mem_readb(off)
#define LoadMw(off) mem_readw(off)
#define LoadMd(off) mem_readd(off)
#define SaveMb(off, val)    mem_writeb(off,val)
#define SaveMw(off, val)    mem_writew(off,val)
#define SaveMd(off, val)    mem_writed(off,val)
#else
#include "paging.h"
#define LoadMb(off) mem_readb_inline(off)
#define LoadMw(off) mem_readw_inline(off)
#define LoadMd(off) mem_readd_inline(off)
#define SaveMb(off,val)	mem_writeb_inline(off,val)
#define SaveMw(off,val)	mem_writew_inline(off,val)
#define SaveMd(off,val)	mem_writed_inline(off,val)
#endif

extern Bitu cycle_count;

#if C_FPU
#define CPU_FPU    1                        //Enable FPU escape instructions
#endif

#include "core_llvm/core_llvm.h"

#define CPU_PIC_CHECK	1
#define CPU_TRAP_CHECK	1

#define OPCODE_NONE			0x000
#define OPCODE_0F			0x100
#define OPCODE_SIZE			0x200

#define PREFIX_ADDR			0x1
#define PREFIX_REP			0x2

#define TEST_PREFIX_ADDR	(core.prefixes & PREFIX_ADDR)
#define TEST_PREFIX_REP		(core.prefixes & PREFIX_REP)

#define DO_PREFIX_SEG(_SEG)				\
    BaseDS=SegBase(_SEG);				\
    BaseSS=SegBase(_SEG);				\
    core.base_val_ds=_SEG;				\
    goto restart_opcode;

#define DO_PREFIX_ADDR()								\
    core.prefixes=(core.prefixes & ~PREFIX_ADDR) |		\
    (cpu.code.big ^ PREFIX_ADDR);						\
    core.ea_table=&EATable[(core.prefixes&1) * 256];	\
    goto restart_opcode;

#define DO_PREFIX_REP(_ZERO)				\
    core.prefixes|=PREFIX_REP;				\
    core.rep_zero=_ZERO;					\
    goto restart_opcode;

typedef PhysPt(*GetEAHandler)(void);

static const Bit32u AddrMaskTable[2] = {0x0000ffff, 0xffffffff};

#define GETIP        (core.cseip-SegBase(cs))
#define SAVEIP        reg_eip=GETIP;
#define LOADIP        core.cseip=(SegBase(cs)+reg_eip);

#define SegBase(c)    SegPhys(c)
#define BaseDS        core.base_ds
#define BaseSS        core.base_ss

static inline Bit8u Fetchb() {
	Bit8u temp = LoadMb(core.cseip);
	core.cseip += 1;
	return temp;
}

static inline Bit16u Fetchw() {
	Bit16u temp = LoadMw(core.cseip);
	core.cseip += 2;
	return temp;
}
static inline Bit32u Fetchd() {
	Bit32u temp = LoadMd(core.cseip);
	core.cseip += 4;
	return temp;
}

#define Push_16 CPU_Push16
#define Push_32 CPU_Push32
#define Pop_16 CPU_Pop16
#define Pop_32 CPU_Pop32

#include "instructions.h"
#include "core_normal/support.h"
#include "core_normal/string.h"

#define EALookupTable (core.ea_table)

#if CHECK_ALL_INSTRUCTIONS
static bool inst_used[0x300] = { 0 };
void DumpUsedInstruction() {
	printf("    0  1  2  3  4  5  6  7  8  9  A  B  C  D  E  F");
	for(int i = 0; i < 0x300; i++) {
		if ((i % 0x10) == 0) {
			printf("\n%03X:", i >> 4);
		}
		printf(" %s ", inst_used[i] ? "X" : " ");
	}
}
#endif
CpuRunnerX86 llvm_runner;

Bits CPU_Core_LLVM_Run(void) {
	while (CPU_Cycles-- > 0) {
		LOADIP;
		llvm_runner.Parse(core.cseip);
		SAVEIP;
	}
	FillFlags();
	return CBRET_NONE;
}

Bits CPU_Core_LLVM_Trap_Run(void) {
	Bits oldCycles = CPU_Cycles;
	CPU_Cycles = 1;
	cpu.trap_skip = false;

	Bits ret = CPU_Core_LLVM_Run();
	if (!cpu.trap_skip) CPU_HW_Interrupt(1);
	CPU_Cycles = oldCycles - 1;
	cpudecoder = &CPU_Core_LLVM_Run;

	return ret;
}

void CPU_Core_LLVM_Init(void) {

}

