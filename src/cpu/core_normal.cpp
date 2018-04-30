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

#define CPU_PIC_CHECK 1
#define CPU_TRAP_CHECK 1

#define OPCODE_NONE            0x000
#define OPCODE_0F            0x100
#define OPCODE_SIZE            0x200

#define PREFIX_ADDR            0x1
#define PREFIX_REP            0x2

#define TEST_PREFIX_ADDR    (core.prefixes & PREFIX_ADDR)
#define TEST_PREFIX_REP        (core.prefixes & PREFIX_REP)

#define DO_PREFIX_SEG(_SEG)                    \
    BaseDS=SegBase(_SEG);                    \
    BaseSS=SegBase(_SEG);                    \
    core.base_val_ds=_SEG;                    \
    goto restart_opcode;

#define DO_PREFIX_ADDR()                                \
    core.prefixes=(core.prefixes & ~PREFIX_ADDR) |        \
    (cpu.code.big ^ PREFIX_ADDR);                        \
    core.ea_table=&EATable[(core.prefixes&1) * 256];    \
    goto restart_opcode;

#define DO_PREFIX_REP(_ZERO)                \
    core.prefixes|=PREFIX_REP;                \
    core.rep_zero=_ZERO;                    \
    goto restart_opcode;

typedef PhysPt(*GetEAHandler)(void);

static const Bit32u AddrMaskTable[2] = {0x0000ffff, 0xffffffff};

static struct {
	Bitu opcode_index;
	PhysPt cseip;
	PhysPt base_ds, base_ss;
	SegNames base_val_ds;
	bool rep_zero;
	Bitu prefixes;
	GetEAHandler *ea_table;
} core;

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

Bits CPU_Core_Normal_Run(void) {
	while (CPU_Cycles-- > 0) {
		LOADIP;
		core.opcode_index = cpu.code.big * 0x200;
		core.prefixes = cpu.code.big;
		core.ea_table = &EATable[cpu.code.big * 256];
		BaseDS = SegBase(ds);
		BaseSS = SegBase(ss);
		core.base_val_ds = ds;
#if C_DEBUG
#if C_HEAVY_DEBUG
		if (DEBUG_HeavyIsBreakpoint()) {
			FillFlags();
			return debugCallback;
		};
#endif
		cycle_count++;
#endif
restart_opcode:
		switch (core.opcode_index + Fetchb()) {
//#include "core_normal/prefix_none.h"

		CASE_B(0x00)                                                /* ADD Eb,Gb */
		RMEbGb(ADDB);
			break;
		CASE_W(0x01)                                                /* ADD Ew,Gw */
		RMEwGw(ADDW);
			break;
		CASE_B(0x02)                                                /* ADD Gb,Eb */
		RMGbEb(ADDB);
			break;
		CASE_W(0x03)                                                /* ADD Gw,Ew */
		RMGwEw(ADDW);
			break;
		CASE_B(0x04)                                                /* ADD AL,Ib */
		ALIb(ADDB);
			break;
		CASE_W(0x05)                                                /* ADD AX,Iw */
		AXIw(ADDW);
			break;
		CASE_W(0x06)                                                /* PUSH ES */
			Push_16(SegValue(es));
			break;
		CASE_W(0x07)                                                /* POP ES */
			if (CPU_PopSeg(es, false)) RUNEXCEPTION();
			break;
		CASE_B(0x08)                                                /* OR Eb,Gb */
		RMEbGb(ORB);
			break;
		CASE_W(0x09)                                                /* OR Ew,Gw */
		RMEwGw(ORW);
			break;
		CASE_B(0x0a)                                                /* OR Gb,Eb */
		RMGbEb(ORB);
			break;
		CASE_W(0x0b)                                                /* OR Gw,Ew */
		RMGwEw(ORW);
			break;
		CASE_B(0x0c)                                                /* OR AL,Ib */
		ALIb(ORB);
			break;
		CASE_W(0x0d)                                                /* OR AX,Iw */
		AXIw(ORW);
			break;
		CASE_W(0x0e)                                                /* PUSH CS */
			Push_16(SegValue(cs));
			break;
		CASE_B(0x0f)                                                /* 2 byte opcodes*/
			core.opcode_index |= OPCODE_0F;
			goto restart_opcode;
			break;
		CASE_B(0x10)                                                /* ADC Eb,Gb */
		RMEbGb(ADCB);
			break;
		CASE_W(0x11)                                                /* ADC Ew,Gw */
		RMEwGw(ADCW);
			break;
		CASE_B(0x12)                                                /* ADC Gb,Eb */
		RMGbEb(ADCB);
			break;
		CASE_W(0x13)                                                /* ADC Gw,Ew */
		RMGwEw(ADCW);
			break;
		CASE_B(0x14)                                                /* ADC AL,Ib */
		ALIb(ADCB);
			break;
		CASE_W(0x15)                                                /* ADC AX,Iw */
		AXIw(ADCW);
			break;
		CASE_W(0x16)                                                /* PUSH SS */
			Push_16(SegValue(ss));
			break;
		CASE_W(0x17)                                                /* POP SS */
			if (CPU_PopSeg(ss, false)) RUNEXCEPTION();
			CPU_Cycles++; //Always do another instruction
			break;
		CASE_B(0x18)                                                /* SBB Eb,Gb */
		RMEbGb(SBBB);
			break;
		CASE_W(0x19)                                                /* SBB Ew,Gw */
		RMEwGw(SBBW);
			break;
		CASE_B(0x1a)                                                /* SBB Gb,Eb */
		RMGbEb(SBBB);
			break;
		CASE_W(0x1b)                                                /* SBB Gw,Ew */
		RMGwEw(SBBW);
			break;
		CASE_B(0x1c)                                                /* SBB AL,Ib */
		ALIb(SBBB);
			break;
		CASE_W(0x1d)                                                /* SBB AX,Iw */
		AXIw(SBBW);
			break;
		CASE_W(0x1e)                                                /* PUSH DS */
			Push_16(SegValue(ds));
			break;
		CASE_W(0x1f)                                                /* POP DS */
			if (CPU_PopSeg(ds, false)) RUNEXCEPTION();
			break;
		CASE_B(0x20)                                                /* AND Eb,Gb */
		RMEbGb(ANDB);
			break;
		CASE_W(0x21)                                                /* AND Ew,Gw */
		RMEwGw(ANDW);
			break;
		CASE_B(0x22)                                                /* AND Gb,Eb */
		RMGbEb(ANDB);
			break;
		CASE_W(0x23)                                                /* AND Gw,Ew */
		RMGwEw(ANDW);
			break;
		CASE_B(0x24)                                                /* AND AL,Ib */
		ALIb(ANDB);
			break;
		CASE_W(0x25)                                                /* AND AX,Iw */
			AXIw(ANDW);
			break;
		CASE_B(0x26)                                                /* SEG ES: */
		DO_PREFIX_SEG(es);
			break;
		CASE_B(0x27)                                                /* DAA */
		DAA();
			break;
		CASE_B(0x28)                                                /* SUB Eb,Gb */
		RMEbGb(SUBB);
			break;
		CASE_W(0x29)                                                /* SUB Ew,Gw */
		RMEwGw(SUBW);
			break;
		CASE_B(0x2a)                                                /* SUB Gb,Eb */
		RMGbEb(SUBB);
			break;
		CASE_W(0x2b)                                                /* SUB Gw,Ew */
		RMGwEw(SUBW);
			break;
		CASE_B(0x2c)                                                /* SUB AL,Ib */
		ALIb(SUBB);
			break;
		CASE_W(0x2d)                                                /* SUB AX,Iw */
		AXIw(SUBW);
			break;
		CASE_B(0x2e)                                                /* SEG CS: */
		DO_PREFIX_SEG(cs);
			break;
		CASE_B(0x2f)                                                /* DAS */
		DAS();
			break;
		CASE_B(0x30)                                                /* XOR Eb,Gb */
		RMEbGb(XORB);
			break;
		CASE_W(0x31)                                                /* XOR Ew,Gw */
		RMEwGw(XORW);
			break;
		CASE_B(0x32)                                                /* XOR Gb,Eb */
		RMGbEb(XORB);
			break;
		CASE_W(0x33)                                                /* XOR Gw,Ew */
		RMGwEw(XORW);
			break;
		CASE_B(0x34)                                                /* XOR AL,Ib */
		ALIb(XORB);
			break;
		CASE_W(0x35)                                                /* XOR AX,Iw */
		AXIw(XORW);
			break;
		CASE_B(0x36)                                                /* SEG SS: */
		DO_PREFIX_SEG(ss);
			break;
		CASE_B(0x37)                                                /* AAA */
		AAA();
			break;
		CASE_B(0x38)                                                /* CMP Eb,Gb */
		RMEbGb(CMPB);
			break;
		CASE_W(0x39)                                                /* CMP Ew,Gw */
		RMEwGw(CMPW);
			break;
		CASE_B(0x3a)                                                /* CMP Gb,Eb */
		RMGbEb(CMPB);
			break;
		CASE_W(0x3b)                                                /* CMP Gw,Ew */
		RMGwEw(CMPW);
			break;
		CASE_B(0x3c)                                                /* CMP AL,Ib */
		ALIb(CMPB);
			break;
		CASE_W(0x3d)                                                /* CMP AX,Iw */
		AXIw(CMPW);
			break;
		CASE_B(0x3e)                                                /* SEG DS: */
		DO_PREFIX_SEG(ds);
			break;
		CASE_B(0x3f)                                                /* AAS */
		AAS();
			break;
		CASE_W(0x40)                                                /* INC AX */
		INCW(reg_ax, LoadRw, SaveRw);
			break;
		CASE_W(0x41)                                                /* INC CX */
		INCW(reg_cx, LoadRw, SaveRw);
			break;
		CASE_W(0x42)                                                /* INC DX */
		INCW(reg_dx, LoadRw, SaveRw);
			break;
		CASE_W(0x43)                                                /* INC BX */
		INCW(reg_bx, LoadRw, SaveRw);
			break;
		CASE_W(0x44)                                                /* INC SP */
		INCW(reg_sp, LoadRw, SaveRw);
			break;
		CASE_W(0x45)                                                /* INC BP */
		INCW(reg_bp, LoadRw, SaveRw);
			break;
		CASE_W(0x46)                                                /* INC SI */
		INCW(reg_si, LoadRw, SaveRw);
			break;
		CASE_W(0x47)                                                /* INC DI */
		INCW(reg_di, LoadRw, SaveRw);
			break;
		CASE_W(0x48)                                                /* DEC AX */
		DECW(reg_ax, LoadRw, SaveRw);
			break;
		CASE_W(0x49)                                                /* DEC CX */
		DECW(reg_cx, LoadRw, SaveRw);
			break;
		CASE_W(0x4a)                                                /* DEC DX */
		DECW(reg_dx, LoadRw, SaveRw);
			break;
		CASE_W(0x4b)                                                /* DEC BX */
		DECW(reg_bx, LoadRw, SaveRw);
			break;
		CASE_W(0x4c)                                                /* DEC SP */
		DECW(reg_sp, LoadRw, SaveRw);
			break;
		CASE_W(0x4d)                                                /* DEC BP */
		DECW(reg_bp, LoadRw, SaveRw);
			break;
		CASE_W(0x4e)                                                /* DEC SI */
		DECW(reg_si, LoadRw, SaveRw);
			break;
		CASE_W(0x4f)                                                /* DEC DI */
		DECW(reg_di, LoadRw, SaveRw);
			break;
		CASE_W(0x50)                                                /* PUSH AX */
			Push_16(reg_ax);
			break;
		CASE_W(0x51)                                                /* PUSH CX */
			Push_16(reg_cx);
			break;
		CASE_W(0x52)                                                /* PUSH DX */
			Push_16(reg_dx);
			break;
		CASE_W(0x53)                                                /* PUSH BX */
			Push_16(reg_bx);
			break;
		CASE_W(0x54)                                                /* PUSH SP */
			Push_16(reg_sp);
			break;
		CASE_W(0x55)                                                /* PUSH BP */
			Push_16(reg_bp);
			break;
		CASE_W(0x56)                                                /* PUSH SI */
			Push_16(reg_si);
			break;
		CASE_W(0x57)                                                /* PUSH DI */
			Push_16(reg_di);
			break;
		CASE_W(0x58)                                                /* POP AX */
			reg_ax = Pop_16();
			break;
		CASE_W(0x59)                                                /* POP CX */
			reg_cx = Pop_16();
			break;
		CASE_W(0x5a)                                                /* POP DX */
			reg_dx = Pop_16();
			break;
		CASE_W(0x5b)                                                /* POP BX */
			reg_bx = Pop_16();
			break;
		CASE_W(0x5c)                                                /* POP SP */
			reg_sp = Pop_16();
			break;
		CASE_W(0x5d)                                                /* POP BP */
			reg_bp = Pop_16();
			break;
		CASE_W(0x5e)                                                /* POP SI */
			reg_si = Pop_16();
			break;
		CASE_W(0x5f)                                                /* POP DI */
			reg_di = Pop_16();
			break;
		CASE_W(0x60)                                                /* PUSHA */
		{
			Bit16u old_sp = reg_sp;
			Push_16(reg_ax);
			Push_16(reg_cx);
			Push_16(reg_dx);
			Push_16(reg_bx);
			Push_16(old_sp);
			Push_16(reg_bp);
			Push_16(reg_si);
			Push_16(reg_di);
		}
			break;
		CASE_W(0x61)                                                /* POPA */
			reg_di = Pop_16();
			reg_si = Pop_16();
			reg_bp = Pop_16();
			Pop_16();//Don't save SP
			reg_bx = Pop_16();
			reg_dx = Pop_16();
			reg_cx = Pop_16();
			reg_ax = Pop_16();
			break;
		CASE_W(0x62)                                                /* BOUND */
		{
			Bit16s bound_min, bound_max;
			GetRMrw;
			GetEAa;
			bound_min = LoadMw(eaa);
			bound_max = LoadMw(eaa + 2);
			if ((((Bit16s) *rmrw) < bound_min) || (((Bit16s) *rmrw) > bound_max)) {
				EXCEPTION(5);
			}
		}
			break;
		CASE_W(0x63)                                                /* ARPL Ew,Rw */
		{
			if ((reg_flags & FLAG_VM) || (!cpu.pmode)) goto illegal_opcode;
			GetRMrw;
			if (rm >= 0xc0) {
				GetEArw;
				Bitu new_sel = *earw;
				CPU_ARPL(new_sel, *rmrw);
				*earw = (Bit16u) new_sel;
			} else {
				GetEAa;
				Bitu new_sel = LoadMw(eaa);
				CPU_ARPL(new_sel, *rmrw);
				SaveMw(eaa, (Bit16u) new_sel);
			}
		}
			break;
		CASE_B(0x64)                                                /* SEG FS: */
		DO_PREFIX_SEG(fs);
			break;
		CASE_B(0x65)                                                /* SEG GS: */
		DO_PREFIX_SEG(gs);
			break;
		CASE_B(0x66)                                                /* Operand Size Prefix */
			core.opcode_index = (cpu.code.big ^ 0x1) * 0x200;
			goto restart_opcode;
		CASE_B(0x67)                                                /* Address Size Prefix */
		DO_PREFIX_ADDR();
		CASE_W(0x68)                                                /* PUSH Iw */
			Push_16(Fetchw());
			break;
		CASE_W(0x69)                                                /* IMUL Gw,Ew,Iw */
		RMGwEwOp3(DIMULW, Fetchws());
			break;
		CASE_W(0x6a)                                                /* PUSH Ib */
			Push_16(Fetchbs());
			break;
		CASE_W(0x6b)                                                /* IMUL Gw,Ew,Ib */
		RMGwEwOp3(DIMULW, Fetchbs());
			break;
		CASE_B(0x6c)                                                /* INSB */
			if (CPU_IO_Exception(reg_dx, 1)) RUNEXCEPTION();
			DoString(R_INSB);
			break;
		CASE_W(0x6d)                                                /* INSW */
			if (CPU_IO_Exception(reg_dx, 2)) RUNEXCEPTION();
			DoString(R_INSW);
			break;
		CASE_B(0x6e)                                                /* OUTSB */
			if (CPU_IO_Exception(reg_dx, 1)) RUNEXCEPTION();
			DoString(R_OUTSB);
			break;
		CASE_W(0x6f)                                                /* OUTSW */
			if (CPU_IO_Exception(reg_dx, 2)) RUNEXCEPTION();
			DoString(R_OUTSW);
			break;
		CASE_W(0x70)                                                /* JO */
		JumpCond16_b(TFLG_O);
			break;
		CASE_W(0x71)                                                /* JNO */
		JumpCond16_b(TFLG_NO);
			break;
		CASE_W(0x72)                                                /* JB */
		JumpCond16_b(TFLG_B);
			break;
		CASE_W(0x73)                                                /* JNB */
		JumpCond16_b(TFLG_NB);
			break;
		CASE_W(0x74)                                                /* JZ */
		JumpCond16_b(TFLG_Z);
			break;
		CASE_W(0x75)                                                /* JNZ */
		JumpCond16_b(TFLG_NZ);
			break;
		CASE_W(0x76)                                                /* JBE */
		JumpCond16_b(TFLG_BE);
			break;
		CASE_W(0x77)                                                /* JNBE */
		JumpCond16_b(TFLG_NBE);
			break;
		CASE_W(0x78)                                                /* JS */
		JumpCond16_b(TFLG_S);
			break;
		CASE_W(0x79)                                                /* JNS */
		JumpCond16_b(TFLG_NS);
			break;
		CASE_W(0x7a)                                                /* JP */
		JumpCond16_b(TFLG_P);
			break;
		CASE_W(0x7b)                                                /* JNP */
		JumpCond16_b(TFLG_NP);
			break;
		CASE_W(0x7c)                                                /* JL */
		JumpCond16_b(TFLG_L);
			break;
		CASE_W(0x7d)                                                /* JNL */
		JumpCond16_b(TFLG_NL);
			break;
		CASE_W(0x7e)                                                /* JLE */
		JumpCond16_b(TFLG_LE);
			break;
		CASE_W(0x7f)                                                /* JNLE */
		JumpCond16_b(TFLG_NLE);
			break;
		CASE_B(0x80)                                                /* Grpl Eb,Ib */
		CASE_B(0x82)                                                /* Grpl Eb,Ib Mirror instruction*/
		{
			GetRM;
			Bitu which = (rm >> 3) & 7;
			if (rm >= 0xc0) {
				GetEArb;
				Bit8u ib = Fetchb();
				switch (which) {
				case 0x00:
				ADDB(*earb, ib, LoadRb, SaveRb);
					break;
				case 0x01:
				ORB(*earb, ib, LoadRb, SaveRb);
					break;
				case 0x02:
				ADCB(*earb, ib, LoadRb, SaveRb);
					break;
				case 0x03:
				SBBB(*earb, ib, LoadRb, SaveRb);
					break;
				case 0x04:
				ANDB(*earb, ib, LoadRb, SaveRb);
					break;
				case 0x05:
				SUBB(*earb, ib, LoadRb, SaveRb);
					break;
				case 0x06:
				XORB(*earb, ib, LoadRb, SaveRb);
					break;
				case 0x07:
				CMPB(*earb, ib, LoadRb, SaveRb);
					break;
				}
			} else {
				GetEAa;
				Bit8u ib = Fetchb();
				switch (which) {
				case 0x00:
				ADDB(eaa, ib, LoadMb, SaveMb);
					break;
				case 0x01:
				ORB(eaa, ib, LoadMb, SaveMb);
					break;
				case 0x02:
				ADCB(eaa, ib, LoadMb, SaveMb);
					break;
				case 0x03:
				SBBB(eaa, ib, LoadMb, SaveMb);
					break;
				case 0x04:
				ANDB(eaa, ib, LoadMb, SaveMb);
					break;
				case 0x05:
				SUBB(eaa, ib, LoadMb, SaveMb);
					break;
				case 0x06:
				XORB(eaa, ib, LoadMb, SaveMb);
					break;
				case 0x07:
				CMPB(eaa, ib, LoadMb, SaveMb);
					break;
				}
			}
			break;
		}
		CASE_W(0x81)                                                /* Grpl Ew,Iw */
		{
			GetRM;
			Bitu which = (rm >> 3) & 7;
			if (rm >= 0xc0) {
				GetEArw;
				Bit16u iw = Fetchw();
				switch (which) {
				case 0x00:
				ADDW(*earw, iw, LoadRw, SaveRw);
					break;
				case 0x01:
				ORW(*earw, iw, LoadRw, SaveRw);
					break;
				case 0x02:
				ADCW(*earw, iw, LoadRw, SaveRw);
					break;
				case 0x03:
				SBBW(*earw, iw, LoadRw, SaveRw);
					break;
				case 0x04:
				ANDW(*earw, iw, LoadRw, SaveRw);
					break;
				case 0x05:
				SUBW(*earw, iw, LoadRw, SaveRw);
					break;
				case 0x06:
				XORW(*earw, iw, LoadRw, SaveRw);
					break;
				case 0x07:
				CMPW(*earw, iw, LoadRw, SaveRw);
					break;
				}
			} else {
				GetEAa;
				Bit16u iw = Fetchw();
				switch (which) {
				case 0x00:
				ADDW(eaa, iw, LoadMw, SaveMw);
					break;
				case 0x01:
				ORW(eaa, iw, LoadMw, SaveMw);
					break;
				case 0x02:
				ADCW(eaa, iw, LoadMw, SaveMw);
					break;
				case 0x03:
				SBBW(eaa, iw, LoadMw, SaveMw);
					break;
				case 0x04:
				ANDW(eaa, iw, LoadMw, SaveMw);
					break;
				case 0x05:
				SUBW(eaa, iw, LoadMw, SaveMw);
					break;
				case 0x06:
				XORW(eaa, iw, LoadMw, SaveMw);
					break;
				case 0x07:
				CMPW(eaa, iw, LoadMw, SaveMw);
					break;
				}
			}
			break;
		}
		CASE_W(0x83)                                                /* Grpl Ew,Ix */
		{
			GetRM;
			Bitu which = (rm >> 3) & 7;
			if (rm >= 0xc0) {
				GetEArw;
				Bit16u iw = (Bit16s) Fetchbs();
				switch (which) {
				case 0x00:
				ADDW(*earw, iw, LoadRw, SaveRw);
					break;
				case 0x01:
				ORW(*earw, iw, LoadRw, SaveRw);
					break;
				case 0x02:
				ADCW(*earw, iw, LoadRw, SaveRw);
					break;
				case 0x03:
				SBBW(*earw, iw, LoadRw, SaveRw);
					break;
				case 0x04:
				ANDW(*earw, iw, LoadRw, SaveRw);
					break;
				case 0x05:
				SUBW(*earw, iw, LoadRw, SaveRw);
					break;
				case 0x06:
				XORW(*earw, iw, LoadRw, SaveRw);
					break;
				case 0x07:
				CMPW(*earw, iw, LoadRw, SaveRw);
					break;
				}
			} else {
				GetEAa;
				Bit16u iw = (Bit16s) Fetchbs();
				switch (which) {
				case 0x00:
				ADDW(eaa, iw, LoadMw, SaveMw);
					break;
				case 0x01:
				ORW(eaa, iw, LoadMw, SaveMw);
					break;
				case 0x02:
				ADCW(eaa, iw, LoadMw, SaveMw);
					break;
				case 0x03:
				SBBW(eaa, iw, LoadMw, SaveMw);
					break;
				case 0x04:
				ANDW(eaa, iw, LoadMw, SaveMw);
					break;
				case 0x05:
				SUBW(eaa, iw, LoadMw, SaveMw);
					break;
				case 0x06:
				XORW(eaa, iw, LoadMw, SaveMw);
					break;
				case 0x07:
				CMPW(eaa, iw, LoadMw, SaveMw);
					break;
				}
			}
			break;
		}
		CASE_B(0x84)                                                /* TEST Eb,Gb */
		RMEbGb(TESTB);
			break;
		CASE_W(0x85)                                                /* TEST Ew,Gw */
		RMEwGw(TESTW);
			break;
		CASE_B(0x86)                                                /* XCHG Eb,Gb */
		{
			GetRMrb;
			Bit8u oldrmrb = *rmrb;
			if (rm >= 0xc0) {
				GetEArb;
				*rmrb = *earb;
				*earb = oldrmrb;
			} else {
				GetEAa;
				*rmrb = LoadMb(eaa);
				SaveMb(eaa, oldrmrb);
			}
			break;
		}
		CASE_W(0x87)                                                /* XCHG Ew,Gw */
		{
			GetRMrw;
			Bit16u oldrmrw = *rmrw;
			if (rm >= 0xc0) {
				GetEArw;
				*rmrw = *earw;
				*earw = oldrmrw;
			} else {
				GetEAa;
				*rmrw = LoadMw(eaa);
				SaveMw(eaa, oldrmrw);
			}
			break;
		}
		CASE_B(0x88)                                                /* MOV Eb,Gb */
		{
			GetRMrb;
			if (rm >= 0xc0) {
				GetEArb;
				*earb = *rmrb;
			} else {
				if (cpu.pmode) {
					if ((rm == 0x05 && (!cpu.code.big))) {
						Descriptor desc;
						cpu.gdt.GetDescriptor(SegValue(core.base_val_ds), desc);
						if ((desc.Type() == DESC_CODE_R_NC_A) || (desc.Type() == DESC_CODE_R_NC_NA)) {
							CPU_Exception(EXCEPTION_GP, SegValue(core.base_val_ds) & 0xfffc);
							continue;
						}
					}
				}
				GetEAa;
				SaveMb(eaa, *rmrb);
			}
			break;
		}
		CASE_W(0x89)                                                /* MOV Ew,Gw */
		{
			GetRMrw;
			if (rm >= 0xc0) {
				GetEArw;
				*earw = *rmrw;
			} else {
				GetEAa;
				SaveMw(eaa, *rmrw);
			}
			break;
		}
		CASE_B(0x8a)                                                /* MOV Gb,Eb */
		{
			GetRMrb;
			if (rm >= 0xc0) {
				GetEArb;
				*rmrb = *earb;
			} else {
				GetEAa;
				*rmrb = LoadMb(eaa);
			}
			break;
		}
		CASE_W(0x8b)                                                /* MOV Gw,Ew */
		{
			GetRMrw;
			if (rm >= 0xc0) {
				GetEArw;
				*rmrw = *earw;
			} else {
				GetEAa;
				*rmrw = LoadMw(eaa);
			}
			break;
		}
		CASE_W(0x8c)                                                /* Mov Ew,Sw */
		{
			GetRM;
			Bit16u val;
			Bitu which = (rm >> 3) & 7;
			switch (which) {
			case 0x00:                    /* MOV Ew,ES */
				val = SegValue(es);
				break;
			case 0x01:                    /* MOV Ew,CS */
				val = SegValue(cs);
				break;
			case 0x02:                    /* MOV Ew,SS */
				val = SegValue(ss);
				break;
			case 0x03:                    /* MOV Ew,DS */
				val = SegValue(ds);
				break;
			case 0x04:                    /* MOV Ew,FS */
				val = SegValue(fs);
				break;
			case 0x05:                    /* MOV Ew,GS */
				val = SegValue(gs);
				break;
			default:
				LOG(LOG_CPU, LOG_ERROR)("CPU:8c:Illegal RM Byte");
				goto illegal_opcode;
			}
			if (rm >= 0xc0) {
				GetEArw;
				*earw = val;
			} else {
				GetEAa;
				SaveMw(eaa, val);
			}
			break;
		}
		CASE_W(0x8d)                                                /* LEA Gw */
		{
			//Little hack to always use segprefixed version
			BaseDS = BaseSS = 0;
			GetRMrw;
			if (TEST_PREFIX_ADDR) {
				*rmrw = (Bit16u) (*EATable[256 + rm])();
			} else {
				*rmrw = (Bit16u) (*EATable[rm])();
			}
			break;
		}
		CASE_B(0x8e)                                                /* MOV Sw,Ew */
		{
			GetRM;
			Bit16u val;
			Bitu which = (rm >> 3) & 7;
			if (rm >= 0xc0) {
				GetEArw;
				val = *earw;
			} else {
				GetEAa;
				val = LoadMw(eaa);
			}
			switch (which) {
			case 0x02:                    /* MOV SS,Ew */
				CPU_Cycles++; //Always do another instruction
			case 0x00:                    /* MOV ES,Ew */
			case 0x03:                    /* MOV DS,Ew */
			case 0x05:                    /* MOV GS,Ew */
			case 0x04:                    /* MOV FS,Ew */
				if (CPU_SetSegGeneral((SegNames) which, val)) RUNEXCEPTION();
				break;
			default:
				goto illegal_opcode;
			}
			break;
		}
		CASE_W(0x8f)                                                /* POP Ew */
		{
			Bit16u val = Pop_16();
			GetRM;
			if (rm >= 0xc0) {
				GetEArw;
				*earw = val;
			} else {
				GetEAa;
				SaveMw(eaa, val);
			}
			break;
		}
		CASE_B(0x90)                                                /* NOP */
			break;
		CASE_W(0x91)                                                /* XCHG CX,AX */
		{
			Bit16u temp = reg_ax;
			reg_ax = reg_cx;
			reg_cx = temp;
		}
			break;
		CASE_W(0x92)                                                /* XCHG DX,AX */
		{
			Bit16u temp = reg_ax;
			reg_ax = reg_dx;
			reg_dx = temp;
		}
			break;
		CASE_W(0x93)                                                /* XCHG BX,AX */
		{
			Bit16u temp = reg_ax;
			reg_ax = reg_bx;
			reg_bx = temp;
		}
			break;
		CASE_W(0x94)                                                /* XCHG SP,AX */
		{
			Bit16u temp = reg_ax;
			reg_ax = reg_sp;
			reg_sp = temp;
		}
			break;
		CASE_W(0x95)                                                /* XCHG BP,AX */
		{
			Bit16u temp = reg_ax;
			reg_ax = reg_bp;
			reg_bp = temp;
		}
			break;
		CASE_W(0x96)                                                /* XCHG SI,AX */
		{
			Bit16u temp = reg_ax;
			reg_ax = reg_si;
			reg_si = temp;
		}
			break;
		CASE_W(0x97)                                                /* XCHG DI,AX */
		{
			Bit16u temp = reg_ax;
			reg_ax = reg_di;
			reg_di = temp;
		}
			break;
		CASE_W(0x98)                                                /* CBW */
			reg_ax = (Bit8s) reg_al;
			break;
		CASE_W(0x99)                                                /* CWD */
			if (reg_ax & 0x8000) reg_dx = 0xffff;
			else
				reg_dx = 0;
			break;
		CASE_W(0x9a)                                                /* CALL Ap */
		{
			FillFlags();
			Bit16u newip = Fetchw();
			Bit16u newcs = Fetchw();
			CPU_CALL(false, newcs, newip, GETIP);
#if CPU_TRAP_CHECK
			if (GETFLAG(TF)) {
				cpudecoder = CPU_Core_Normal_Trap_Run;
				return CBRET_NONE;
			}
#endif
			continue;
		}
		CASE_B(0x9b)                                                /* WAIT */
			break; /* No waiting here */
		CASE_W(0x9c)                                                /* PUSHF */
			if (CPU_PUSHF(false)) RUNEXCEPTION();
			break;
		CASE_W(0x9d)                                                /* POPF */
			if (CPU_POPF(false)) RUNEXCEPTION();
#if CPU_TRAP_CHECK
			if (GETFLAG(TF)) {
				cpudecoder = CPU_Core_Normal_Trap_Run;
				goto decode_end;
			}
#endif
#if    CPU_PIC_CHECK
			if (GETFLAG(IF) && PIC_IRQCheck) goto decode_end;
#endif
			break;
		CASE_B(0x9e)                                                /* SAHF */
		SETFLAGSb(reg_ah);
			break;
		CASE_B(0x9f)                                                /* LAHF */
			FillFlags();
			reg_ah = reg_flags & 0xff;
			break;
		CASE_B(0xa0)                                                /* MOV AL,Ob */
		{
			GetEADirect;
			reg_al = LoadMb(eaa);
		}
			break;
		CASE_W(0xa1)                                                /* MOV AX,Ow */
		{
			GetEADirect;
			reg_ax = LoadMw(eaa);
		}
			break;
		CASE_B(0xa2)                                                /* MOV Ob,AL */
		{
			GetEADirect;
			SaveMb(eaa, reg_al);
		}
			break;
		CASE_W(0xa3)                                                /* MOV Ow,AX */
		{
			GetEADirect;
			SaveMw(eaa, reg_ax);
		}
			break;
		CASE_B(0xa4)                                                /* MOVSB */
			DoString(R_MOVSB);
			break;
		CASE_W(0xa5)                                                /* MOVSW */
			DoString(R_MOVSW);
			break;
		CASE_B(0xa6)                                                /* CMPSB */
			DoString(R_CMPSB);
			break;
		CASE_W(0xa7)                                                /* CMPSW */
			DoString(R_CMPSW);
			break;
		CASE_B(0xa8)                                                /* TEST AL,Ib */
		ALIb(TESTB);
			break;
		CASE_W(0xa9)                                                /* TEST AX,Iw */
		AXIw(TESTW);
			break;
		CASE_B(0xaa)                                                /* STOSB */
			DoString(R_STOSB);
			break;
		CASE_W(0xab)                                                /* STOSW */
			DoString(R_STOSW);
			break;
		CASE_B(0xac)                                                /* LODSB */
			DoString(R_LODSB);
			break;
		CASE_W(0xad)                                                /* LODSW */
			DoString(R_LODSW);
			break;
		CASE_B(0xae)                                                /* SCASB */
			DoString(R_SCASB);
			break;
		CASE_W(0xaf)                                                /* SCASW */
			DoString(R_SCASW);
			break;
		CASE_B(0xb0)                                                /* MOV AL,Ib */
			reg_al = Fetchb();
			break;
		CASE_B(0xb1)                                                /* MOV CL,Ib */
			reg_cl = Fetchb();
			break;
		CASE_B(0xb2)                                                /* MOV DL,Ib */
			reg_dl = Fetchb();
			break;
		CASE_B(0xb3)                                                /* MOV BL,Ib */
			reg_bl = Fetchb();
			break;
		CASE_B(0xb4)                                                /* MOV AH,Ib */
			reg_ah = Fetchb();
			break;
		CASE_B(0xb5)                                                /* MOV CH,Ib */
			reg_ch = Fetchb();
			break;
		CASE_B(0xb6)                                                /* MOV DH,Ib */
			reg_dh = Fetchb();
			break;
		CASE_B(0xb7)                                                /* MOV BH,Ib */
			reg_bh = Fetchb();
			break;
		CASE_W(0xb8)                                                /* MOV AX,Iw */
			reg_ax = Fetchw();
			break;
		CASE_W(0xb9)                                                /* MOV CX,Iw */
			reg_cx = Fetchw();
			break;
		CASE_W(0xba)                                                /* MOV DX,Iw */
			reg_dx = Fetchw();
			break;
		CASE_W(0xbb)                                                /* MOV BX,Iw */
			reg_bx = Fetchw();
			break;
		CASE_W(0xbc)                                                /* MOV SP,Iw */
			reg_sp = Fetchw();
			break;
		CASE_W(0xbd)                                                /* MOV BP.Iw */
			reg_bp = Fetchw();
			break;
		CASE_W(0xbe)                                                /* MOV SI,Iw */
			reg_si = Fetchw();
			break;
		CASE_W(0xbf)                                                /* MOV DI,Iw */
			reg_di = Fetchw();
			break;
		CASE_B(0xc0)                                                /* GRP2 Eb,Ib */
		GRP2B(Fetchb());
			break;
		CASE_W(0xc1)                                                /* GRP2 Ew,Ib */
		GRP2W(Fetchb());
			break;
		CASE_W(0xc2)                                                /* RETN Iw */
			reg_eip = Pop_16();
			reg_esp += Fetchw();
			continue;
		CASE_W(0xc3)                                                /* RETN */
			reg_eip = Pop_16();
			continue;
		CASE_W(0xc4)                                                /* LES */
		{
			GetRMrw;
			if (rm >= 0xc0) goto illegal_opcode;
			GetEAa;
			if (CPU_SetSegGeneral(es, LoadMw(eaa + 2))) RUNEXCEPTION();
			*rmrw = LoadMw(eaa);
			break;
		}
		CASE_W(0xc5)                                                /* LDS */
		{
			GetRMrw;
			if (rm >= 0xc0) goto illegal_opcode;
			GetEAa;
			if (CPU_SetSegGeneral(ds, LoadMw(eaa + 2))) RUNEXCEPTION();
			*rmrw = LoadMw(eaa);
			break;
		}
		CASE_B(0xc6)                                                /* MOV Eb,Ib */
		{
			GetRM;
			if (rm >= 0xc0) {
				GetEArb;
				*earb = Fetchb();
			} else {
				GetEAa;
				SaveMb(eaa, Fetchb());
			}
			break;
		}
		CASE_W(0xc7)                                                /* MOV EW,Iw */
		{
			GetRM;
			if (rm >= 0xc0) {
				GetEArw;
				*earw = Fetchw();
			} else {
				GetEAa;
				SaveMw(eaa, Fetchw());
			}
			break;
		}
		CASE_W(0xc8)                                                /* ENTER Iw,Ib */
		{
			Bitu bytes = Fetchw();
			Bitu level = Fetchb();
			CPU_ENTER(false, bytes, level);
		}
			break;
		CASE_W(0xc9)                                                /* LEAVE */
			reg_esp &= cpu.stack.notmask;
			reg_esp |= (reg_ebp & cpu.stack.mask);
			reg_bp = Pop_16();
			break;
		CASE_W(0xca)                                                /* RETF Iw */
		{
			Bitu words = Fetchw();
			FillFlags();
			CPU_RET(false, words, GETIP);
			continue;
		}
		CASE_W(0xcb)                                                /* RETF */
			FillFlags();
			CPU_RET(false, 0, GETIP);
			continue;
		CASE_B(0xcc)                                                /* INT3 */
#if C_DEBUG
			FillFlags();
if (DEBUG_Breakpoint())
return debugCallback;
#endif
			CPU_SW_Interrupt_NoIOPLCheck(3, GETIP);
#if CPU_TRAP_CHECK
			cpu.trap_skip = true;
#endif
			continue;
		CASE_B(0xcd)                                                /* INT Ib */
		{
			Bit8u num = Fetchb();
#if C_DEBUG
			FillFlags();
	if (DEBUG_IntBreakpoint(num)) {
		return debugCallback;
	}
#endif
			CPU_SW_Interrupt(num, GETIP);
#if CPU_TRAP_CHECK
			cpu.trap_skip = true;
#endif
			continue;
		}
		CASE_B(0xce)                                                /* INTO */
			if (get_OF()) {
				CPU_SW_Interrupt(4, GETIP);
#if CPU_TRAP_CHECK
				cpu.trap_skip = true;
#endif
				continue;
			}
			break;
		CASE_W(0xcf)                                                /* IRET */
		{
			CPU_IRET(false, GETIP);
#if CPU_TRAP_CHECK
			if (GETFLAG(TF)) {
				cpudecoder = CPU_Core_Normal_Trap_Run;
				return CBRET_NONE;
			}
#endif
#if CPU_PIC_CHECK
			if (GETFLAG(IF) && PIC_IRQCheck) return CBRET_NONE;
#endif
			continue;
		}
		CASE_B(0xd0)                                                /* GRP2 Eb,1 */
		GRP2B(1);
			break;
		CASE_W(0xd1)                                                /* GRP2 Ew,1 */
		GRP2W(1);
			break;
		CASE_B(0xd2)                                                /* GRP2 Eb,CL */
		GRP2B(reg_cl);
			break;
		CASE_W(0xd3)                                                /* GRP2 Ew,CL */
		GRP2W(reg_cl);
			break;
		CASE_B(0xd4)                                                /* AAM Ib */
		AAM(Fetchb());
			break;
		CASE_B(0xd5)                                                /* AAD Ib */
		AAD(Fetchb());
			break;
		CASE_B(0xd6)                                                /* SALC */
			reg_al = get_CF() ? 0xFF : 0;
			break;
		CASE_B(0xd7)                                                /* XLAT */
			if (TEST_PREFIX_ADDR) {
				reg_al = LoadMb(BaseDS + (Bit32u) (reg_ebx + reg_al));
			} else {
				reg_al = LoadMb(BaseDS + (Bit16u) (reg_bx + reg_al));
			}
			break;
#ifdef CPU_FPU
		CASE_B(0xd8)                                                /* FPU ESC 0 */
		FPU_ESC(0);
			break;
		CASE_B(0xd9)                                                /* FPU ESC 1 */
		FPU_ESC(1);
			break;
		CASE_B(0xda)                                                /* FPU ESC 2 */
		FPU_ESC(2);
			break;
		CASE_B(0xdb)                                                /* FPU ESC 3 */
		FPU_ESC(3);
			break;
		CASE_B(0xdc)                                                /* FPU ESC 4 */
		FPU_ESC(4);
			break;
		CASE_B(0xdd)                                                /* FPU ESC 5 */
		FPU_ESC(5);
			break;
		CASE_B(0xde)                                                /* FPU ESC 6 */
		FPU_ESC(6);
			break;
		CASE_B(0xdf)                                                /* FPU ESC 7 */
		FPU_ESC(7);
			break;
#else
			CASE_B(0xd8)												/* FPU ESC 0 */
CASE_B(0xd9)												/* FPU ESC 1 */
CASE_B(0xda)												/* FPU ESC 2 */
CASE_B(0xdb)												/* FPU ESC 3 */
CASE_B(0xdc)												/* FPU ESC 4 */
CASE_B(0xdd)												/* FPU ESC 5 */
CASE_B(0xde)												/* FPU ESC 6 */
CASE_B(0xdf)												/* FPU ESC 7 */
{
	LOG(LOG_CPU, LOG_NORMAL)("FPU used");
	Bit8u rm = Fetchb();
	if (rm < 0xc0) GetEAa;
}
break;
#endif
		CASE_W(0xe0)                                                /* LOOPNZ */
			if (TEST_PREFIX_ADDR) {
				JumpCond16_b(--reg_ecx && !get_ZF());
			} else {
				JumpCond16_b(--reg_cx && !get_ZF());
			}
			break;
		CASE_W(0xe1)                                                /* LOOPZ */
			if (TEST_PREFIX_ADDR) {
				JumpCond16_b(--reg_ecx && get_ZF());
			} else {
				JumpCond16_b(--reg_cx && get_ZF());
			}
			break;
		CASE_W(0xe2)                                                /* LOOP */
			if (TEST_PREFIX_ADDR) {
				JumpCond16_b(--reg_ecx);
			} else {
				JumpCond16_b(--reg_cx);
			}
			break;
		CASE_W(0xe3)                                                /* JCXZ */
		JumpCond16_b(!(reg_ecx & AddrMaskTable[core.prefixes & PREFIX_ADDR]));
			break;
		CASE_B(0xe4)                                                /* IN AL,Ib */
		{
			Bitu port = Fetchb();
			if (CPU_IO_Exception(port, 1)) RUNEXCEPTION();
			reg_al = IO_ReadB(port);
			break;
		}
		CASE_W(0xe5)                                                /* IN AX,Ib */
		{
			Bitu port = Fetchb();
			if (CPU_IO_Exception(port, 2)) RUNEXCEPTION();
			reg_ax = IO_ReadW(port);
			break;
		}
		CASE_B(0xe6)                                                /* OUT Ib,AL */
		{
			Bitu port = Fetchb();
			if (CPU_IO_Exception(port, 1)) RUNEXCEPTION();
			IO_WriteB(port, reg_al);
			break;
		}
		CASE_W(0xe7)                                                /* OUT Ib,AX */
		{
			Bitu port = Fetchb();
			if (CPU_IO_Exception(port, 2)) RUNEXCEPTION();
			IO_WriteW(port, reg_ax);
			break;
		}
		CASE_W(0xe8)                                                /* CALL Jw */
		{
			Bit16u addip = Fetchws();
			SAVEIP;
			Push_16(reg_eip);
			reg_eip = (Bit16u) (reg_eip + addip);
			continue;
		}
		CASE_W(0xe9)                                                /* JMP Jw */
		{
			Bit16u addip = Fetchws();
			SAVEIP;
			reg_eip = (Bit16u) (reg_eip + addip);
			continue;
		}
		CASE_W(0xea)                                                /* JMP Ap */
		{
			Bit16u newip = Fetchw();
			Bit16u newcs = Fetchw();
			FillFlags();
			CPU_JMP(false, newcs, newip, GETIP);
#if CPU_TRAP_CHECK
			if (GETFLAG(TF)) {
				cpudecoder = CPU_Core_Normal_Trap_Run;
				return CBRET_NONE;
			}
#endif
			continue;
		}
		CASE_W(0xeb)                                                /* JMP Jb */
		{
			Bit16s addip = Fetchbs();
			SAVEIP;
			reg_eip = (Bit16u) (reg_eip + addip);
			continue;
		}
		CASE_B(0xec)                                                /* IN AL,DX */
			if (CPU_IO_Exception(reg_dx, 1)) RUNEXCEPTION();
			reg_al = IO_ReadB(reg_dx);
			break;
		CASE_W(0xed)                                                /* IN AX,DX */
			if (CPU_IO_Exception(reg_dx, 2)) RUNEXCEPTION();
			reg_ax = IO_ReadW(reg_dx);
			break;
		CASE_B(0xee)                                                /* OUT DX,AL */
			if (CPU_IO_Exception(reg_dx, 1)) RUNEXCEPTION();
			IO_WriteB(reg_dx, reg_al);
			break;
		CASE_W(0xef)                                                /* OUT DX,AX */
			if (CPU_IO_Exception(reg_dx, 2)) RUNEXCEPTION();
			IO_WriteW(reg_dx, reg_ax);
			break;
		CASE_B(0xf0)                                                /* LOCK */
			LOG(LOG_CPU, LOG_NORMAL)("CPU:LOCK"); /* FIXME: see case D_LOCK in core_full/load.h */
			break;
		CASE_B(0xf1)                                                /* ICEBP */
			CPU_SW_Interrupt_NoIOPLCheck(1, GETIP);
#if CPU_TRAP_CHECK
			cpu.trap_skip = true;
#endif
			continue;
		CASE_B(0xf2)                                                /* REPNZ */
		DO_PREFIX_REP(false);
			break;
		CASE_B(0xf3)                                                /* REPZ */
		DO_PREFIX_REP(true);
			break;
		CASE_B(0xf4)                                                /* HLT */
			if (cpu.pmode && cpu.cpl) EXCEPTION(EXCEPTION_GP);
			FillFlags();
			CPU_HLT(GETIP);
			return CBRET_NONE;        //Needs to return for hlt cpu core
		CASE_B(0xf5)                                                /* CMC */
			FillFlags();
			SETFLAGBIT(CF, !(reg_flags & FLAG_CF));
			break;
		CASE_B(0xf6)                                                /* GRP3 Eb(,Ib) */
		{
			GetRM;
			Bitu which = (rm >> 3) & 7;
			switch (which) {
			case 0x00:                                            /* TEST Eb,Ib */
			case 0x01:                                            /* TEST Eb,Ib Undocumented*/
			{
				if (rm >= 0xc0) {
					GetEArb;
					TESTB(*earb, Fetchb(), LoadRb, 0)
				} else {
					GetEAa;
					TESTB(eaa, Fetchb(), LoadMb, 0);
				}
				break;
			}
			case 0x02:                                            /* NOT Eb */
			{
				if (rm >= 0xc0) {
					GetEArb;
					*earb = ~*earb;
				} else {
					GetEAa;
					SaveMb(eaa, ~LoadMb(eaa));
				}
				break;
			}
			case 0x03:                                            /* NEG Eb */
			{
				lflags.type = t_NEGb;
				if (rm >= 0xc0) {
					GetEArb;
					lf_var1b = *earb;
					lf_resb = 0 - lf_var1b;
					*earb = lf_resb;
				} else {
					GetEAa;
					lf_var1b = LoadMb(eaa);
					lf_resb = 0 - lf_var1b;
					SaveMb(eaa, lf_resb);
				}
				break;
			}
			case 0x04:                                            /* MUL AL,Eb */
			RMEb(MULB);
				break;
			case 0x05:                                            /* IMUL AL,Eb */
			RMEb(IMULB);
				break;
			case 0x06:                                            /* DIV Eb */
			RMEb(DIVB);
				break;
			case 0x07:                                            /* IDIV Eb */
			RMEb(IDIVB);
				break;
			}
			break;
		}
		CASE_W(0xf7)                                                /* GRP3 Ew(,Iw) */
		{
			GetRM;
			Bitu which = (rm >> 3) & 7;
			switch (which) {
			case 0x00:                                            /* TEST Ew,Iw */
			case 0x01:                                            /* TEST Ew,Iw Undocumented*/
			{
				if (rm >= 0xc0) {
					GetEArw;
					TESTW(*earw, Fetchw(), LoadRw, SaveRw);
				} else {
					GetEAa;
					TESTW(eaa, Fetchw(), LoadMw, SaveMw);
				}
				break;
			}
			case 0x02:                                            /* NOT Ew */
			{
				if (rm >= 0xc0) {
					GetEArw;
					*earw = ~*earw;
				} else {
					GetEAa;
					SaveMw(eaa, ~LoadMw(eaa));
				}
				break;
			}
			case 0x03:                                            /* NEG Ew */
			{
				lflags.type = t_NEGw;
				if (rm >= 0xc0) {
					GetEArw;
					lf_var1w = *earw;
					lf_resw = 0 - lf_var1w;
					*earw = lf_resw;
				} else {
					GetEAa;
					lf_var1w = LoadMw(eaa);
					lf_resw = 0 - lf_var1w;
					SaveMw(eaa, lf_resw);
				}
				break;
			}
			case 0x04:                                            /* MUL AX,Ew */
			RMEw(MULW);
				break;
			case 0x05:                                            /* IMUL AX,Ew */
			RMEw(IMULW)
				break;
			case 0x06:                                            /* DIV Ew */
			RMEw(DIVW)
				break;
			case 0x07:                                            /* IDIV Ew */
			RMEw(IDIVW)
				break;
			}
			break;
		}
		CASE_B(0xf8)                                                /* CLC */
			FillFlags();
			SETFLAGBIT(CF, false);
			break;
		CASE_B(0xf9)                                                /* STC */
			FillFlags();
			SETFLAGBIT(CF, true);
			break;
		CASE_B(0xfa)                                                /* CLI */
			if (CPU_CLI()) RUNEXCEPTION();
			break;
		CASE_B(0xfb)                                                /* STI */
			if (CPU_STI()) RUNEXCEPTION();
#if CPU_PIC_CHECK
			if (GETFLAG(IF) && PIC_IRQCheck) goto decode_end;
#endif
			break;
		CASE_B(0xfc)                                                /* CLD */
			SETFLAGBIT(DF, false);
			cpu.direction = 1;
			break;
		CASE_B(0xfd)                                                /* STD */
			SETFLAGBIT(DF, true);
			cpu.direction = -1;
			break;
		CASE_B(0xfe)                                                /* GRP4 Eb */
		{
			GetRM;
			Bitu which = (rm >> 3) & 7;
			switch (which) {
			case 0x00:                                        /* INC Eb */
			RMEb(INCB);
				break;
			case 0x01:                                        /* DEC Eb */
			RMEb(DECB);
				break;
			case 0x07:                                        /* CallBack */
			{
				Bitu cb = Fetchw();
				FillFlags();
				SAVEIP;
				return cb;
			}
			default:
				E_Exit("Illegal GRP4 Call %d", (rm >> 3) & 7);
				break;
			}
			break;
		}
		CASE_W(0xff)                                                /* GRP5 Ew */
		{
			GetRM;
			Bitu which = (rm >> 3) & 7;
			switch (which) {
			case 0x00:                                        /* INC Ew */
			RMEw(INCW);
				break;
			case 0x01:                                        /* DEC Ew */
			RMEw(DECW);
				break;
			case 0x02:                                        /* CALL Ev */
				if (rm >= 0xc0) {
					GetEArw;
					reg_eip = *earw;
				} else {
					GetEAa;
					reg_eip = LoadMw(eaa);
				}
				Push_16(GETIP);
				continue;
			case 0x03:                                        /* CALL Ep */
			{
				if (rm >= 0xc0) goto illegal_opcode;
				GetEAa;
				Bit16u newip = LoadMw(eaa);
				Bit16u newcs = LoadMw(eaa + 2);
				FillFlags();
				CPU_CALL(false, newcs, newip, GETIP);
#if CPU_TRAP_CHECK
				if (GETFLAG(TF)) {
					cpudecoder = CPU_Core_Normal_Trap_Run;
					return CBRET_NONE;
				}
#endif
				continue;
			}
				break;
			case 0x04:                                        /* JMP Ev */
				if (rm >= 0xc0) {
					GetEArw;
					reg_eip = *earw;
				} else {
					GetEAa;
					reg_eip = LoadMw(eaa);
				}
				continue;
			case 0x05:                                        /* JMP Ep */
			{
				if (rm >= 0xc0) goto illegal_opcode;
				GetEAa;
				Bit16u newip = LoadMw(eaa);
				Bit16u newcs = LoadMw(eaa + 2);
				FillFlags();
				CPU_JMP(false, newcs, newip, GETIP);
#if CPU_TRAP_CHECK
				if (GETFLAG(TF)) {
					cpudecoder = CPU_Core_Normal_Trap_Run;
					return CBRET_NONE;
				}
#endif
				continue;
			}
				break;
			case 0x06:                                        /* PUSH Ev */
				if (rm >= 0xc0) {
					GetEArw;
					Push_16(*earw);
				} else {
					GetEAa;
					Push_16(LoadMw(eaa));
				}
				break;
			default:
				LOG(LOG_CPU, LOG_ERROR)("CPU:GRP5:Illegal Call %2X", which);
				goto illegal_opcode;
			}
			break;
		}

// #include "core_normal/prefix_0f.h"

		CASE_0F_W(0x00)                                                /* GRP 6 Exxx */
		{
			if ((reg_flags & FLAG_VM) || (!cpu.pmode)) goto illegal_opcode;
			GetRM;
			Bitu which = (rm >> 3) & 7;
			switch (which) {
			case 0x00:    /* SLDT */
			case 0x01:    /* STR */
			{
				Bitu saveval;
				if (!which) saveval = CPU_SLDT();
				else saveval = CPU_STR();
				if (rm >= 0xc0) {
					GetEArw;
					*earw = saveval;
				} else {
					GetEAa;
					SaveMw(eaa, saveval);
				}
			}
				break;
			case 0x02:
			case 0x03:
			case 0x04:
			case 0x05: {
				Bitu loadval;
				if (rm >= 0xc0) {
					GetEArw;
					loadval = *earw;
				} else {
					GetEAa;
					loadval = LoadMw(eaa);
				}
				switch (which) {
				case 0x02:
					if (cpu.cpl) EXCEPTION(EXCEPTION_GP);
					if (CPU_LLDT(loadval)) RUNEXCEPTION();
					break;
				case 0x03:
					if (cpu.cpl) EXCEPTION(EXCEPTION_GP);
					if (CPU_LTR(loadval)) RUNEXCEPTION();
					break;
				case 0x04:
					CPU_VERR(loadval);
					break;
				case 0x05:
					CPU_VERW(loadval);
					break;
				}
			}
				break;
			default:
				goto illegal_opcode;
			}
		}
			break;
		CASE_0F_W(0x01)                                                /* Group 7 Ew */
		{
			GetRM;
			Bitu which = (rm >> 3) & 7;
			if (rm < 0xc0) { //First ones all use EA
				GetEAa;
				Bitu limit;
				switch (which) {
				case 0x00:                                        /* SGDT */
					SaveMw(eaa, CPU_SGDT_limit());
					SaveMd(eaa + 2, CPU_SGDT_base());
					break;
				case 0x01:                                        /* SIDT */
					SaveMw(eaa, CPU_SIDT_limit());
					SaveMd(eaa + 2, CPU_SIDT_base());
					break;
				case 0x02:                                        /* LGDT */
					if (cpu.pmode && cpu.cpl) EXCEPTION(EXCEPTION_GP);
					CPU_LGDT(LoadMw(eaa), LoadMd(eaa + 2) & 0xFFFFFF);
					break;
				case 0x03:                                        /* LIDT */
					if (cpu.pmode && cpu.cpl) EXCEPTION(EXCEPTION_GP);
					CPU_LIDT(LoadMw(eaa), LoadMd(eaa + 2) & 0xFFFFFF);
					break;
				case 0x04:                                        /* SMSW */
					SaveMw(eaa, CPU_SMSW());
					break;
				case 0x06:                                        /* LMSW */
					limit = LoadMw(eaa);
					if (CPU_LMSW(limit)) RUNEXCEPTION();
					break;
				case 0x07:                                        /* INVLPG */
					if (cpu.pmode && cpu.cpl) EXCEPTION(EXCEPTION_GP);
					PAGING_ClearTLB();
					break;
				}
			} else {
				GetEArw;
				switch (which) {
				case 0x02:                                        /* LGDT */
					if (cpu.pmode && cpu.cpl) EXCEPTION(EXCEPTION_GP);
					goto illegal_opcode;
				case 0x03:                                        /* LIDT */
					if (cpu.pmode && cpu.cpl) EXCEPTION(EXCEPTION_GP);
					goto illegal_opcode;
				case 0x04:                                        /* SMSW */
					*earw = CPU_SMSW();
					break;
				case 0x06:                                        /* LMSW */
					if (CPU_LMSW(*earw)) RUNEXCEPTION();
					break;
				default:
					goto illegal_opcode;
				}
			}
		}
			break;
		CASE_0F_W(0x02)                                                /* LAR Gw,Ew */
		{
			if ((reg_flags & FLAG_VM) || (!cpu.pmode)) goto illegal_opcode;
			GetRMrw;
			Bitu ar = *rmrw;
			if (rm >= 0xc0) {
				GetEArw;
				CPU_LAR(*earw, ar);
			} else {
				GetEAa;
				CPU_LAR(LoadMw(eaa), ar);
			}
			*rmrw = (Bit16u) ar;
		}
			break;
		CASE_0F_W(0x03)                                                /* LSL Gw,Ew */
		{
			if ((reg_flags & FLAG_VM) || (!cpu.pmode)) goto illegal_opcode;
			GetRMrw;
			Bitu limit = *rmrw;
			if (rm >= 0xc0) {
				GetEArw;
				CPU_LSL(*earw, limit);
			} else {
				GetEAa;
				CPU_LSL(LoadMw(eaa), limit);
			}
			*rmrw = (Bit16u) limit;
		}
			break;
		CASE_0F_B(0x06)                                                /* CLTS */
			if (cpu.pmode && cpu.cpl) EXCEPTION(EXCEPTION_GP);
			cpu.cr0 &= (~CR0_TASKSWITCH);
			break;
		CASE_0F_B(0x08)                                                /* INVD */
		CASE_0F_B(0x09)                                                /* WBINVD */
			if (CPU_ArchitectureType < CPU_ARCHTYPE_486OLDSLOW) goto illegal_opcode;
			if (cpu.pmode && cpu.cpl) EXCEPTION(EXCEPTION_GP);
			break;
		CASE_0F_B(0x20)                                                /* MOV Rd.CRx */
		{
			GetRM;
			Bitu which = (rm >> 3) & 7;
			if (rm < 0xc0) {
				rm |= 0xc0;
				LOG(LOG_CPU, LOG_ERROR)("MOV XXX,CR%u with non-register", which);
			}
			GetEArd;
			Bit32u crx_value;
			if (CPU_READ_CRX(which, crx_value)) RUNEXCEPTION();
			*eard = crx_value;
		}
			break;
		CASE_0F_B(0x21)                                                /* MOV Rd,DRx */
		{
			GetRM;
			Bitu which = (rm >> 3) & 7;
			if (rm < 0xc0) {
				rm |= 0xc0;
				LOG(LOG_CPU, LOG_ERROR)("MOV XXX,DR%u with non-register", which);
			}
			GetEArd;
			Bit32u drx_value;
			if (CPU_READ_DRX(which, drx_value)) RUNEXCEPTION();
			*eard = drx_value;
		}
			break;
		CASE_0F_B(0x22)                                                /* MOV CRx,Rd */
		{
			GetRM;
			Bitu which = (rm >> 3) & 7;
			if (rm < 0xc0) {
				rm |= 0xc0;
				LOG(LOG_CPU, LOG_ERROR)("MOV XXX,CR%u with non-register", which);
			}
			GetEArd;
			if (CPU_WRITE_CRX(which, *eard)) RUNEXCEPTION();
		}
			break;
		CASE_0F_B(0x23)                                                /* MOV DRx,Rd */
		{
			GetRM;
			Bitu which = (rm >> 3) & 7;
			if (rm < 0xc0) {
				rm |= 0xc0;
				LOG(LOG_CPU, LOG_ERROR)("MOV DR%u,XXX with non-register", which);
			}
			GetEArd;
			if (CPU_WRITE_DRX(which, *eard)) RUNEXCEPTION();
		}
			break;
		CASE_0F_B(0x24)                                                /* MOV Rd,TRx */
		{
			GetRM;
			Bitu which = (rm >> 3) & 7;
			if (rm < 0xc0) {
				rm |= 0xc0;
				LOG(LOG_CPU, LOG_ERROR)("MOV XXX,TR%u with non-register", which);
			}
			GetEArd;
			Bit32u trx_value;
			if (CPU_READ_TRX(which, trx_value)) RUNEXCEPTION();
			*eard = trx_value;
		}
			break;
		CASE_0F_B(0x26)                                                /* MOV TRx,Rd */
		{
			GetRM;
			Bitu which = (rm >> 3) & 7;
			if (rm < 0xc0) {
				rm |= 0xc0;
				LOG(LOG_CPU, LOG_ERROR)("MOV TR%u,XXX with non-register", which);
			}
			GetEArd;
			if (CPU_WRITE_TRX(which, *eard)) RUNEXCEPTION();
		}
			break;
		CASE_0F_B(0x31)                                                /* RDTSC */
		{
			if (CPU_ArchitectureType < CPU_ARCHTYPE_PENTIUMSLOW) goto illegal_opcode;
			/* Use a fixed number when in auto cycles mode as else the reported value changes constantly */
			Bit64s tsc = (Bit64s) (PIC_FullIndex() * (double) (CPU_CycleAutoAdjust ? 70000 : CPU_CycleMax));
			reg_edx = (Bit32u) (tsc >> 32);
			reg_eax = (Bit32u) (tsc & 0xffffffff);
		}
			break;
		CASE_0F_W(0x80)                                                /* JO */
		JumpCond16_w(TFLG_O);
			break;
		CASE_0F_W(0x81)                                                /* JNO */
		JumpCond16_w(TFLG_NO);
			break;
		CASE_0F_W(0x82)                                                /* JB */
		JumpCond16_w(TFLG_B);
			break;
		CASE_0F_W(0x83)                                                /* JNB */
		JumpCond16_w(TFLG_NB);
			break;
		CASE_0F_W(0x84)                                                /* JZ */
		JumpCond16_w(TFLG_Z);
			break;
		CASE_0F_W(0x85)                                                /* JNZ */
		JumpCond16_w(TFLG_NZ);
			break;
		CASE_0F_W(0x86)                                                /* JBE */
		JumpCond16_w(TFLG_BE);
			break;
		CASE_0F_W(0x87)                                                /* JNBE */
		JumpCond16_w(TFLG_NBE);
			break;
		CASE_0F_W(0x88)                                                /* JS */
		JumpCond16_w(TFLG_S);
			break;
		CASE_0F_W(0x89)                                                /* JNS */
		JumpCond16_w(TFLG_NS);
			break;
		CASE_0F_W(0x8a)                                                /* JP */
		JumpCond16_w(TFLG_P);
			break;
		CASE_0F_W(0x8b)                                                /* JNP */
		JumpCond16_w(TFLG_NP);
			break;
		CASE_0F_W(0x8c)                                                /* JL */
		JumpCond16_w(TFLG_L);
			break;
		CASE_0F_W(0x8d)                                                /* JNL */
		JumpCond16_w(TFLG_NL);
			break;
		CASE_0F_W(0x8e)                                                /* JLE */
		JumpCond16_w(TFLG_LE);
			break;
		CASE_0F_W(0x8f)                                                /* JNLE */
		JumpCond16_w(TFLG_NLE);
			break;
		CASE_0F_B(0x90)                                                /* SETO */
		SETcc(TFLG_O);
			break;
		CASE_0F_B(0x91)                                                /* SETNO */
		SETcc(TFLG_NO);
			break;
		CASE_0F_B(0x92)                                                /* SETB */
		SETcc(TFLG_B);
			break;
		CASE_0F_B(0x93)                                                /* SETNB */
		SETcc(TFLG_NB);
			break;
		CASE_0F_B(0x94)                                                /* SETZ */
		SETcc(TFLG_Z);
			break;
		CASE_0F_B(0x95)                                                /* SETNZ */
		SETcc(TFLG_NZ);
			break;
		CASE_0F_B(0x96)                                                /* SETBE */
		SETcc(TFLG_BE);
			break;
		CASE_0F_B(0x97)                                                /* SETNBE */
		SETcc(TFLG_NBE);
			break;
		CASE_0F_B(0x98)                                                /* SETS */
		SETcc(TFLG_S);
			break;
		CASE_0F_B(0x99)                                                /* SETNS */
		SETcc(TFLG_NS);
			break;
		CASE_0F_B(0x9a)                                                /* SETP */
		SETcc(TFLG_P);
			break;
		CASE_0F_B(0x9b)                                                /* SETNP */
		SETcc(TFLG_NP);
			break;
		CASE_0F_B(0x9c)                                                /* SETL */
		SETcc(TFLG_L);
			break;
		CASE_0F_B(0x9d)                                                /* SETNL */
		SETcc(TFLG_NL);
			break;
		CASE_0F_B(0x9e)                                                /* SETLE */
		SETcc(TFLG_LE);
			break;
		CASE_0F_B(0x9f)                                                /* SETNLE */
		SETcc(TFLG_NLE);
			break;

		CASE_0F_W(0xa0)                                                /* PUSH FS */
			Push_16(SegValue(fs));
			break;
		CASE_0F_W(0xa1)                                                /* POP FS */
			if (CPU_PopSeg(fs, false)) RUNEXCEPTION();
			break;
		CASE_0F_B(0xa2)                                                /* CPUID */
			if (!CPU_CPUID()) goto illegal_opcode;
			break;
		CASE_0F_W(0xa3)                                                /* BT Ew,Gw */
		{
			FillFlags();
			GetRMrw;
			Bit16u mask = 1 << (*rmrw & 15);
			if (rm >= 0xc0) {
				GetEArw;
				SETFLAGBIT(CF, (*earw & mask));
			} else {
				GetEAa;
				eaa += (((Bit16s) *rmrw) >> 4) * 2;
				Bit16u old = LoadMw(eaa);
				SETFLAGBIT(CF, (old & mask));
			}
			break;
		}
		CASE_0F_W(0xa4)                                                /* SHLD Ew,Gw,Ib */
		RMEwGwOp3(DSHLW, Fetchb());
			break;
		CASE_0F_W(0xa5)                                                /* SHLD Ew,Gw,CL */
		RMEwGwOp3(DSHLW, reg_cl);
			break;
		CASE_0F_W(0xa8)                                                /* PUSH GS */
			Push_16(SegValue(gs));
			break;
		CASE_0F_W(0xa9)                                                /* POP GS */
			if (CPU_PopSeg(gs, false)) RUNEXCEPTION();
			break;
		CASE_0F_W(0xab)                                                /* BTS Ew,Gw */
		{
			FillFlags();
			GetRMrw;
			Bit16u mask = 1 << (*rmrw & 15);
			if (rm >= 0xc0) {
				GetEArw;
				SETFLAGBIT(CF, (*earw & mask));
				*earw |= mask;
			} else {
				GetEAa;
				eaa += (((Bit16s) *rmrw) >> 4) * 2;
				Bit16u old = LoadMw(eaa);
				SETFLAGBIT(CF, (old & mask));
				SaveMw(eaa, old | mask);
			}
			break;
		}
		CASE_0F_W(0xac)                                                /* SHRD Ew,Gw,Ib */
		RMEwGwOp3(DSHRW, Fetchb());
			break;
		CASE_0F_W(0xad)                                                /* SHRD Ew,Gw,CL */
		RMEwGwOp3(DSHRW, reg_cl);
			break;
		CASE_0F_W(0xaf)                                                /* IMUL Gw,Ew */
		RMGwEwOp3(DIMULW, *rmrw);
			break;
		CASE_0F_B(0xb0)                                        /* cmpxchg Eb,Gb */
		{
			if (CPU_ArchitectureType < CPU_ARCHTYPE_486OLDSLOW) goto illegal_opcode;
			FillFlags();
			GetRMrb;
			if (rm >= 0xc0) {
				GetEArb;
				if (reg_al == *earb) {
					*earb = *rmrb;
					SETFLAGBIT(ZF, 1);
				} else {
					reg_al = *earb;
					SETFLAGBIT(ZF, 0);
				}
			} else {
				GetEAa;
				Bit8u val = LoadMb(eaa);
				if (reg_al == val) {
					SaveMb(eaa, *rmrb);
					SETFLAGBIT(ZF, 1);
				} else {
					SaveMb(eaa, val);    // cmpxchg always issues a write
					reg_al = val;
					SETFLAGBIT(ZF, 0);
				}
			}
			break;
		}
		CASE_0F_W(0xb1)                                    /* cmpxchg Ew,Gw */
		{
			if (CPU_ArchitectureType < CPU_ARCHTYPE_486OLDSLOW) goto illegal_opcode;
			FillFlags();
			GetRMrw;
			if (rm >= 0xc0) {
				GetEArw;
				if (reg_ax == *earw) {
					*earw = *rmrw;
					SETFLAGBIT(ZF, 1);
				} else {
					reg_ax = *earw;
					SETFLAGBIT(ZF, 0);
				}
			} else {
				GetEAa;
				Bit16u val = LoadMw(eaa);
				if (reg_ax == val) {
					SaveMw(eaa, *rmrw);
					SETFLAGBIT(ZF, 1);
				} else {
					SaveMw(eaa, val);    // cmpxchg always issues a write
					reg_ax = val;
					SETFLAGBIT(ZF, 0);
				}
			}
			break;
		}

		CASE_0F_W(0xb2)                                                /* LSS Ew */
		{
			GetRMrw;
			if (rm >= 0xc0) goto illegal_opcode;
			GetEAa;
			if (CPU_SetSegGeneral(ss, LoadMw(eaa + 2))) RUNEXCEPTION();
			*rmrw = LoadMw(eaa);
			break;
		}
		CASE_0F_W(0xb3)                                                /* BTR Ew,Gw */
		{
			FillFlags();
			GetRMrw;
			Bit16u mask = 1 << (*rmrw & 15);
			if (rm >= 0xc0) {
				GetEArw;
				SETFLAGBIT(CF, (*earw & mask));
				*earw &= ~mask;
			} else {
				GetEAa;
				eaa += (((Bit16s) *rmrw) >> 4) * 2;
				Bit16u old = LoadMw(eaa);
				SETFLAGBIT(CF, (old & mask));
				SaveMw(eaa, old & ~mask);
			}
			break;
		}
		CASE_0F_W(0xb4)                                                /* LFS Ew */
		{
			GetRMrw;
			if (rm >= 0xc0) goto illegal_opcode;
			GetEAa;
			if (CPU_SetSegGeneral(fs, LoadMw(eaa + 2))) RUNEXCEPTION();
			*rmrw = LoadMw(eaa);
			break;
		}
		CASE_0F_W(0xb5)                                                /* LGS Ew */
		{
			GetRMrw;
			if (rm >= 0xc0) goto illegal_opcode;
			GetEAa;
			if (CPU_SetSegGeneral(gs, LoadMw(eaa + 2))) RUNEXCEPTION();
			*rmrw = LoadMw(eaa);
			break;
		}
		CASE_0F_W(0xb6)                                                /* MOVZX Gw,Eb */
		{
			GetRMrw;
			if (rm >= 0xc0) {
				GetEArb;
				*rmrw = *earb;
			} else {
				GetEAa;
				*rmrw = LoadMb(eaa);
			}
			break;
		}
		CASE_0F_W(0xb7)                                                /* MOVZX Gw,Ew */
		CASE_0F_W(0xbf)                                                /* MOVSX Gw,Ew */
		{
			GetRMrw;
			if (rm >= 0xc0) {
				GetEArw;
				*rmrw = *earw;
			} else {
				GetEAa;
				*rmrw = LoadMw(eaa);
			}
			break;
		}
		CASE_0F_W(0xba)                                                /* GRP8 Ew,Ib */
		{
			FillFlags();
			GetRM;
			if (rm >= 0xc0) {
				GetEArw;
				Bit16u mask = 1 << (Fetchb() & 15);
				SETFLAGBIT(CF, (*earw & mask));
				switch (rm & 0x38) {
				case 0x20:                                        /* BT */
					break;
				case 0x28:                                        /* BTS */
					*earw |= mask;
					break;
				case 0x30:                                        /* BTR */
					*earw &= ~mask;
					break;
				case 0x38:                                        /* BTC */
					*earw ^= mask;
					break;
				default:
					E_Exit("CPU:0F:BA:Illegal subfunction %X", rm & 0x38);
				}
			} else {
				GetEAa;
				Bit16u old = LoadMw(eaa);
				Bit16u mask = 1 << (Fetchb() & 15);
				SETFLAGBIT(CF, (old & mask));
				switch (rm & 0x38) {
				case 0x20:                                        /* BT */
					break;
				case 0x28:                                        /* BTS */
					SaveMw(eaa, old | mask);
					break;
				case 0x30:                                        /* BTR */
					SaveMw(eaa, old & ~mask);
					break;
				case 0x38:                                        /* BTC */
					SaveMw(eaa, old ^ mask);
					break;
				default:
					E_Exit("CPU:0F:BA:Illegal subfunction %X", rm & 0x38);
				}
			}
			break;
		}
		CASE_0F_W(0xbb)                                                /* BTC Ew,Gw */
		{
			FillFlags();
			GetRMrw;
			Bit16u mask = 1 << (*rmrw & 15);
			if (rm >= 0xc0) {
				GetEArw;
				SETFLAGBIT(CF, (*earw & mask));
				*earw ^= mask;
			} else {
				GetEAa;
				eaa += (((Bit16s) *rmrw) >> 4) * 2;
				Bit16u old = LoadMw(eaa);
				SETFLAGBIT(CF, (old & mask));
				SaveMw(eaa, old ^ mask);
			}
			break;
		}
		CASE_0F_W(0xbc)                                                /* BSF Gw,Ew */
		{
			GetRMrw;
			Bit16u result, value;
			if (rm >= 0xc0) {
				GetEArw;
				value = *earw;
			} else {
				GetEAa;
				value = LoadMw(eaa);
			}
			if (value == 0) {
				SETFLAGBIT(ZF, true);
			} else {
				result = 0;
				while ((value & 0x01) == 0) {
					result++;
					value >>= 1;
				}
				SETFLAGBIT(ZF, false);
				*rmrw = result;
			}
			lflags.type = t_UNKNOWN;
			break;
		}
		CASE_0F_W(0xbd)                                                /* BSR Gw,Ew */
		{
			GetRMrw;
			Bit16u result, value;
			if (rm >= 0xc0) {
				GetEArw;
				value = *earw;
			} else {
				GetEAa;
				value = LoadMw(eaa);
			}
			if (value == 0) {
				SETFLAGBIT(ZF, true);
			} else {
				result = 15;    // Operandsize-1
				while ((value & 0x8000) == 0) {
					result--;
					value <<= 1;
				}
				SETFLAGBIT(ZF, false);
				*rmrw = result;
			}
			lflags.type = t_UNKNOWN;
			break;
		}
		CASE_0F_W(0xbe)                                                /* MOVSX Gw,Eb */
		{
			GetRMrw;
			if (rm >= 0xc0) {
				GetEArb;
				*rmrw = *(Bit8s *) earb;
			} else {
				GetEAa;
				*rmrw = LoadMbs(eaa);
			}
			break;
		}
		CASE_0F_B(0xc0)                                                /* XADD Gb,Eb */
		{
			if (CPU_ArchitectureType < CPU_ARCHTYPE_486OLDSLOW) goto illegal_opcode;
			GetRMrb;
			Bit8u oldrmrb = *rmrb;
			if (rm >= 0xc0) {
				GetEArb;
				*rmrb = *earb;
				*earb += oldrmrb;
			} else {
				GetEAa;
				*rmrb = LoadMb(eaa);
				SaveMb(eaa, LoadMb(eaa) + oldrmrb);
			}
			break;
		}
		CASE_0F_W(0xc1)                                                /* XADD Gw,Ew */
		{
			if (CPU_ArchitectureType < CPU_ARCHTYPE_486OLDSLOW) goto illegal_opcode;
			GetRMrw;
			Bit16u oldrmrw = *rmrw;
			if (rm >= 0xc0) {
				GetEArw;
				*rmrw = *earw;
				*earw += oldrmrw;
			} else {
				GetEAa;
				*rmrw = LoadMw(eaa);
				SaveMw(eaa, LoadMw(eaa) + oldrmrw);
			}
			break;
		}
		CASE_0F_W(0xc8)                                                /* BSWAP AX */
			if (CPU_ArchitectureType < CPU_ARCHTYPE_486OLDSLOW) goto illegal_opcode;
			BSWAPW(reg_ax);
			break;
		CASE_0F_W(0xc9)                                                /* BSWAP CX */
			if (CPU_ArchitectureType < CPU_ARCHTYPE_486OLDSLOW) goto illegal_opcode;
			BSWAPW(reg_cx);
			break;
		CASE_0F_W(0xca)                                                /* BSWAP DX */
			if (CPU_ArchitectureType < CPU_ARCHTYPE_486OLDSLOW) goto illegal_opcode;
			BSWAPW(reg_dx);
			break;
		CASE_0F_W(0xcb)                                                /* BSWAP BX */
			if (CPU_ArchitectureType < CPU_ARCHTYPE_486OLDSLOW) goto illegal_opcode;
			BSWAPW(reg_bx);
			break;
		CASE_0F_W(0xcc)                                                /* BSWAP SP */
			if (CPU_ArchitectureType < CPU_ARCHTYPE_486OLDSLOW) goto illegal_opcode;
			BSWAPW(reg_sp);
			break;
		CASE_0F_W(0xcd)                                                /* BSWAP BP */
			if (CPU_ArchitectureType < CPU_ARCHTYPE_486OLDSLOW) goto illegal_opcode;
			BSWAPW(reg_bp);
			break;
		CASE_0F_W(0xce)                                                /* BSWAP SI */
			if (CPU_ArchitectureType < CPU_ARCHTYPE_486OLDSLOW) goto illegal_opcode;
			BSWAPW(reg_si);
			break;
		CASE_0F_W(0xcf)                                                /* BSWAP DI */
			if (CPU_ArchitectureType < CPU_ARCHTYPE_486OLDSLOW) goto illegal_opcode;
			BSWAPW(reg_di);
			break;

// #include "core_normal/prefix_66.h"

		CASE_D(0x01)                                                /* ADD Ed,Gd */
		RMEdGd(ADDD);
			break;
		CASE_D(0x03)                                                /* ADD Gd,Ed */
		RMGdEd(ADDD);
			break;
		CASE_D(0x05)                                                /* ADD EAX,Id */
		EAXId(ADDD);
			break;
		CASE_D(0x06)                                                /* PUSH ES */
			Push_32(SegValue(es));
			break;
		CASE_D(0x07)                                                /* POP ES */
			if (CPU_PopSeg(es, true)) RUNEXCEPTION();
			break;
		CASE_D(0x09)                                                /* OR Ed,Gd */
		RMEdGd(ORD);
			break;
		CASE_D(0x0b)                                                /* OR Gd,Ed */
		RMGdEd(ORD);
			break;
		CASE_D(0x0d)                                                /* OR EAX,Id */
		EAXId(ORD);
			break;
		CASE_D(0x0e)                                                /* PUSH CS */
			Push_32(SegValue(cs));
			break;
		CASE_D(0x11)                                                /* ADC Ed,Gd */
		RMEdGd(ADCD);
			break;
		CASE_D(0x13)                                                /* ADC Gd,Ed */
		RMGdEd(ADCD);
			break;
		CASE_D(0x15)                                                /* ADC EAX,Id */
		EAXId(ADCD);
			break;
		CASE_D(0x16)                                                /* PUSH SS */
			Push_32(SegValue(ss));
			break;
		CASE_D(0x17)                                                /* POP SS */
			if (CPU_PopSeg(ss, true)) RUNEXCEPTION();
			CPU_Cycles++;
			break;
		CASE_D(0x19)                                                /* SBB Ed,Gd */
		RMEdGd(SBBD);
			break;
		CASE_D(0x1b)                                                /* SBB Gd,Ed */
		RMGdEd(SBBD);
			break;
		CASE_D(0x1d)                                                /* SBB EAX,Id */
		EAXId(SBBD);
			break;
		CASE_D(0x1e)                                                /* PUSH DS */
			Push_32(SegValue(ds));
			break;
		CASE_D(0x1f)                                                /* POP DS */
			if (CPU_PopSeg(ds, true)) RUNEXCEPTION();
			break;
		CASE_D(0x21)                                                /* AND Ed,Gd */
		RMEdGd(ANDD);
			break;
		CASE_D(0x23)                                                /* AND Gd,Ed */
		RMGdEd(ANDD);
			break;
		CASE_D(0x25)                                                /* AND EAX,Id */
		EAXId(ANDD);
			break;
		CASE_D(0x29)                                                /* SUB Ed,Gd */
		RMEdGd(SUBD);
			break;
		CASE_D(0x2b)                                                /* SUB Gd,Ed */
		RMGdEd(SUBD);
			break;
		CASE_D(0x2d)                                                /* SUB EAX,Id */
		EAXId(SUBD);
			break;
		CASE_D(0x31)                                                /* XOR Ed,Gd */
		RMEdGd(XORD);
			break;
		CASE_D(0x33)                                                /* XOR Gd,Ed */
		RMGdEd(XORD);
			break;
		CASE_D(0x35)                                                /* XOR EAX,Id */
		EAXId(XORD);
			break;
		CASE_D(0x39)                                                /* CMP Ed,Gd */
		RMEdGd(CMPD);
			break;
		CASE_D(0x3b)                                                /* CMP Gd,Ed */
		RMGdEd(CMPD);
			break;
		CASE_D(0x3d)                                                /* CMP EAX,Id */
		EAXId(CMPD);
			break;
		CASE_D(0x40)                                                /* INC EAX */
		INCD(reg_eax, LoadRd, SaveRd);
			break;
		CASE_D(0x41)                                                /* INC ECX */
		INCD(reg_ecx, LoadRd, SaveRd);
			break;
		CASE_D(0x42)                                                /* INC EDX */
		INCD(reg_edx, LoadRd, SaveRd);
			break;
		CASE_D(0x43)                                                /* INC EBX */
		INCD(reg_ebx, LoadRd, SaveRd);
			break;
		CASE_D(0x44)                                                /* INC ESP */
		INCD(reg_esp, LoadRd, SaveRd);
			break;
		CASE_D(0x45)                                                /* INC EBP */
		INCD(reg_ebp, LoadRd, SaveRd);
			break;
		CASE_D(0x46)                                                /* INC ESI */
		INCD(reg_esi, LoadRd, SaveRd);
			break;
		CASE_D(0x47)                                                /* INC EDI */
		INCD(reg_edi, LoadRd, SaveRd);
			break;
		CASE_D(0x48)                                                /* DEC EAX */
		DECD(reg_eax, LoadRd, SaveRd);
			break;
		CASE_D(0x49)                                                /* DEC ECX */
		DECD(reg_ecx, LoadRd, SaveRd);
			break;
		CASE_D(0x4a)                                                /* DEC EDX */
		DECD(reg_edx, LoadRd, SaveRd);
			break;
		CASE_D(0x4b)                                                /* DEC EBX */
		DECD(reg_ebx, LoadRd, SaveRd);
			break;
		CASE_D(0x4c)                                                /* DEC ESP */
		DECD(reg_esp, LoadRd, SaveRd);
			break;
		CASE_D(0x4d)                                                /* DEC EBP */
		DECD(reg_ebp, LoadRd, SaveRd);
			break;
		CASE_D(0x4e)                                                /* DEC ESI */
		DECD(reg_esi, LoadRd, SaveRd);
			break;
		CASE_D(0x4f)                                                /* DEC EDI */
		DECD(reg_edi, LoadRd, SaveRd);
			break;
		CASE_D(0x50)                                                /* PUSH EAX */
			Push_32(reg_eax);
			break;
		CASE_D(0x51)                                                /* PUSH ECX */
			Push_32(reg_ecx);
			break;
		CASE_D(0x52)                                                /* PUSH EDX */
			Push_32(reg_edx);
			break;
		CASE_D(0x53)                                                /* PUSH EBX */
			Push_32(reg_ebx);
			break;
		CASE_D(0x54)                                                /* PUSH ESP */
			Push_32(reg_esp);
			break;
		CASE_D(0x55)                                                /* PUSH EBP */
			Push_32(reg_ebp);
			break;
		CASE_D(0x56)                                                /* PUSH ESI */
			Push_32(reg_esi);
			break;
		CASE_D(0x57)                                                /* PUSH EDI */
			Push_32(reg_edi);
			break;
		CASE_D(0x58)                                                /* POP EAX */
			reg_eax = Pop_32();
			break;
		CASE_D(0x59)                                                /* POP ECX */
			reg_ecx = Pop_32();
			break;
		CASE_D(0x5a)                                                /* POP EDX */
			reg_edx = Pop_32();
			break;
		CASE_D(0x5b)                                                /* POP EBX */
			reg_ebx = Pop_32();
			break;
		CASE_D(0x5c)                                                /* POP ESP */
			reg_esp = Pop_32();
			break;
		CASE_D(0x5d)                                                /* POP EBP */
			reg_ebp = Pop_32();
			break;
		CASE_D(0x5e)                                                /* POP ESI */
			reg_esi = Pop_32();
			break;
		CASE_D(0x5f)                                                /* POP EDI */
			reg_edi = Pop_32();
			break;
		CASE_D(0x60)                                                /* PUSHAD */
		{
			Bitu tmpesp = reg_esp;
			Push_32(reg_eax);
			Push_32(reg_ecx);
			Push_32(reg_edx);
			Push_32(reg_ebx);
			Push_32(tmpesp);
			Push_32(reg_ebp);
			Push_32(reg_esi);
			Push_32(reg_edi);
		};
			break;
		CASE_D(0x61)                                                /* POPAD */
			reg_edi = Pop_32();
			reg_esi = Pop_32();
			reg_ebp = Pop_32();
			Pop_32();//Don't save ESP
			reg_ebx = Pop_32();
			reg_edx = Pop_32();
			reg_ecx = Pop_32();
			reg_eax = Pop_32();
			break;
		CASE_D(0x62)                                                /* BOUND Ed */
		{
			Bit32s bound_min, bound_max;
			GetRMrd;
			GetEAa;
			bound_min = LoadMd(eaa);
			bound_max = LoadMd(eaa + 4);
			if ((((Bit32s) *rmrd) < bound_min) || (((Bit32s) *rmrd) > bound_max)) {
				EXCEPTION(5);
			}
		}
			break;
		CASE_D(0x63)                                                /* ARPL Ed,Rd */
		{
			if (((cpu.pmode) && (reg_flags & FLAG_VM)) || (!cpu.pmode)) goto illegal_opcode;
			GetRMrw;
			if (rm >= 0xc0) {
				GetEArd;
				Bitu new_sel = (Bit16u) *eard;
				CPU_ARPL(new_sel, *rmrw);
				*eard = (Bit32u) new_sel;
			} else {
				GetEAa;
				Bitu new_sel = LoadMw(eaa);
				CPU_ARPL(new_sel, *rmrw);
				SaveMd(eaa, (Bit32u) new_sel);
			}
		}
			break;
		CASE_D(0x68)                                                /* PUSH Id */
			Push_32(Fetchd());
			break;
		CASE_D(0x69)                                                /* IMUL Gd,Ed,Id */
		RMGdEdOp3(DIMULD, Fetchds());
			break;
		CASE_D(0x6a)                                                /* PUSH Ib */
			Push_32(Fetchbs());
			break;
		CASE_D(0x6b)                                                /* IMUL Gd,Ed,Ib */
		RMGdEdOp3(DIMULD, Fetchbs());
			break;
		CASE_D(0x6d)                                                /* INSD */
			if (CPU_IO_Exception(reg_dx, 4)) RUNEXCEPTION();
			DoString(R_INSD);
			break;
		CASE_D(0x6f)                                                /* OUTSD */
			if (CPU_IO_Exception(reg_dx, 4)) RUNEXCEPTION();
			DoString(R_OUTSD);
			break;
		CASE_D(0x70)                                                /* JO */
		JumpCond32_b(TFLG_O);
			break;
		CASE_D(0x71)                                                /* JNO */
		JumpCond32_b(TFLG_NO);
			break;
		CASE_D(0x72)                                                /* JB */
		JumpCond32_b(TFLG_B);
			break;
		CASE_D(0x73)                                                /* JNB */
		JumpCond32_b(TFLG_NB);
			break;
		CASE_D(0x74)                                                /* JZ */
		JumpCond32_b(TFLG_Z);
			break;
		CASE_D(0x75)                                                /* JNZ */
		JumpCond32_b(TFLG_NZ);
			break;
		CASE_D(0x76)                                                /* JBE */
		JumpCond32_b(TFLG_BE);
			break;
		CASE_D(0x77)                                                /* JNBE */
		JumpCond32_b(TFLG_NBE);
			break;
		CASE_D(0x78)                                                /* JS */
		JumpCond32_b(TFLG_S);
			break;
		CASE_D(0x79)                                                /* JNS */
		JumpCond32_b(TFLG_NS);
			break;
		CASE_D(0x7a)                                                /* JP */
		JumpCond32_b(TFLG_P);
			break;
		CASE_D(0x7b)                                                /* JNP */
		JumpCond32_b(TFLG_NP);
			break;
		CASE_D(0x7c)                                                /* JL */
		JumpCond32_b(TFLG_L);
			break;
		CASE_D(0x7d)                                                /* JNL */
		JumpCond32_b(TFLG_NL);
			break;
		CASE_D(0x7e)                                                /* JLE */
		JumpCond32_b(TFLG_LE);
			break;
		CASE_D(0x7f)                                                /* JNLE */
		JumpCond32_b(TFLG_NLE);
			break;
		CASE_D(0x81)                                                /* Grpl Ed,Id */
		{
			GetRM;
			Bitu which = (rm >> 3) & 7;
			if (rm >= 0xc0) {
				GetEArd;
				Bit32u id = Fetchd();
				switch (which) {
				case 0x00:
				ADDD(*eard, id, LoadRd, SaveRd);
					break;
				case 0x01:
				ORD(*eard, id, LoadRd, SaveRd);
					break;
				case 0x02:
				ADCD(*eard, id, LoadRd, SaveRd);
					break;
				case 0x03:
				SBBD(*eard, id, LoadRd, SaveRd);
					break;
				case 0x04:
				ANDD(*eard, id, LoadRd, SaveRd);
					break;
				case 0x05:
				SUBD(*eard, id, LoadRd, SaveRd);
					break;
				case 0x06:
				XORD(*eard, id, LoadRd, SaveRd);
					break;
				case 0x07:
				CMPD(*eard, id, LoadRd, SaveRd);
					break;
				}
			} else {
				GetEAa;
				Bit32u id = Fetchd();
				switch (which) {
				case 0x00:
				ADDD(eaa, id, LoadMd, SaveMd);
					break;
				case 0x01:
				ORD(eaa, id, LoadMd, SaveMd);
					break;
				case 0x02:
				ADCD(eaa, id, LoadMd, SaveMd);
					break;
				case 0x03:
				SBBD(eaa, id, LoadMd, SaveMd);
					break;
				case 0x04:
				ANDD(eaa, id, LoadMd, SaveMd);
					break;
				case 0x05:
				SUBD(eaa, id, LoadMd, SaveMd);
					break;
				case 0x06:
				XORD(eaa, id, LoadMd, SaveMd);
					break;
				case 0x07:
				CMPD(eaa, id, LoadMd, SaveMd);
					break;
				}
			}
		}
			break;
		CASE_D(0x83)                                                /* Grpl Ed,Ix */
		{
			GetRM;
			Bitu which = (rm >> 3) & 7;
			if (rm >= 0xc0) {
				GetEArd;
				Bit32u id = (Bit32s) Fetchbs();
				switch (which) {
				case 0x00:
				ADDD(*eard, id, LoadRd, SaveRd);
					break;
				case 0x01:
				ORD(*eard, id, LoadRd, SaveRd);
					break;
				case 0x02:
				ADCD(*eard, id, LoadRd, SaveRd);
					break;
				case 0x03:
				SBBD(*eard, id, LoadRd, SaveRd);
					break;
				case 0x04:
				ANDD(*eard, id, LoadRd, SaveRd);
					break;
				case 0x05:
				SUBD(*eard, id, LoadRd, SaveRd);
					break;
				case 0x06:
				XORD(*eard, id, LoadRd, SaveRd);
					break;
				case 0x07:
				CMPD(*eard, id, LoadRd, SaveRd);
					break;
				}
			} else {
				GetEAa;
				Bit32u id = (Bit32s) Fetchbs();
				switch (which) {
				case 0x00:
				ADDD(eaa, id, LoadMd, SaveMd);
					break;
				case 0x01:
				ORD(eaa, id, LoadMd, SaveMd);
					break;
				case 0x02:
				ADCD(eaa, id, LoadMd, SaveMd);
					break;
				case 0x03:
				SBBD(eaa, id, LoadMd, SaveMd);
					break;
				case 0x04:
				ANDD(eaa, id, LoadMd, SaveMd);
					break;
				case 0x05:
				SUBD(eaa, id, LoadMd, SaveMd);
					break;
				case 0x06:
				XORD(eaa, id, LoadMd, SaveMd);
					break;
				case 0x07:
				CMPD(eaa, id, LoadMd, SaveMd);
					break;
				}
			}
		}
			break;
		CASE_D(0x85)                                                /* TEST Ed,Gd */
		RMEdGd(TESTD);
			break;
		CASE_D(0x87)                                                /* XCHG Ed,Gd */
		{
			GetRMrd;
			Bit32u oldrmrd = *rmrd;
			if (rm >= 0xc0) {
				GetEArd;
				*rmrd = *eard;
				*eard = oldrmrd;
			} else {
				GetEAa;
				*rmrd = LoadMd(eaa);
				SaveMd(eaa, oldrmrd);
			}
			break;
		}
		CASE_D(0x89)                                                /* MOV Ed,Gd */
		{
			GetRMrd;
			if (rm >= 0xc0) {
				GetEArd;
				*eard = *rmrd;
			} else {
				GetEAa;
				SaveMd(eaa, *rmrd);
			}
			break;
		}
		CASE_D(0x8b)                                                /* MOV Gd,Ed */
		{
			GetRMrd;
			if (rm >= 0xc0) {
				GetEArd;
				*rmrd = *eard;
			} else {
				GetEAa;
				*rmrd = LoadMd(eaa);
			}
			break;
		}
		CASE_D(0x8c)                                                /* Mov Ew,Sw */
		{
			GetRM;
			Bit16u val;
			Bitu which = (rm >> 3) & 7;
			switch (which) {
			case 0x00:                    /* MOV Ew,ES */
				val = SegValue(es);
				break;
			case 0x01:                    /* MOV Ew,CS */
				val = SegValue(cs);
				break;
			case 0x02:                    /* MOV Ew,SS */
				val = SegValue(ss);
				break;
			case 0x03:                    /* MOV Ew,DS */
				val = SegValue(ds);
				break;
			case 0x04:                    /* MOV Ew,FS */
				val = SegValue(fs);
				break;
			case 0x05:                    /* MOV Ew,GS */
				val = SegValue(gs);
				break;
			default:
				LOG(LOG_CPU, LOG_ERROR)("CPU:8c:Illegal RM Byte");
				goto illegal_opcode;
			}
			if (rm >= 0xc0) {
				GetEArd;
				*eard = val;
			} else {
				GetEAa;
				SaveMw(eaa, val);
			}
			break;
		}
		CASE_D(0x8d)                                                /* LEA Gd */
		{
			//Little hack to always use segprefixed version
			GetRMrd;
			BaseDS = BaseSS = 0;
			if (TEST_PREFIX_ADDR) {
				*rmrd = (Bit32u) (*EATable[256 + rm])();
			} else {
				*rmrd = (Bit32u) (*EATable[rm])();
			}
			break;
		}
		CASE_D(0x8f)                                                /* POP Ed */
		{
			Bit32u val = Pop_32();
			GetRM;
			if (rm >= 0xc0) {
				GetEArd;
				*eard = val;
			} else {
				GetEAa;
				SaveMd(eaa, val);
			}
			break;
		}
		CASE_D(0x91)                                                /* XCHG ECX,EAX */
		{
			Bit32u temp = reg_eax;
			reg_eax = reg_ecx;
			reg_ecx = temp;
			break;
		}
		CASE_D(0x92)                                                /* XCHG EDX,EAX */
		{
			Bit32u temp = reg_eax;
			reg_eax = reg_edx;
			reg_edx = temp;
			break;
		}
			break;
		CASE_D(0x93)                                                /* XCHG EBX,EAX */
		{
			Bit32u temp = reg_eax;
			reg_eax = reg_ebx;
			reg_ebx = temp;
			break;
		}
			break;
		CASE_D(0x94)                                                /* XCHG ESP,EAX */
		{
			Bit32u temp = reg_eax;
			reg_eax = reg_esp;
			reg_esp = temp;
			break;
		}
			break;
		CASE_D(0x95)                                                /* XCHG EBP,EAX */
		{
			Bit32u temp = reg_eax;
			reg_eax = reg_ebp;
			reg_ebp = temp;
			break;
		}
			break;
		CASE_D(0x96)                                                /* XCHG ESI,EAX */
		{
			Bit32u temp = reg_eax;
			reg_eax = reg_esi;
			reg_esi = temp;
			break;
		}
			break;
		CASE_D(0x97)                                                /* XCHG EDI,EAX */
		{
			Bit32u temp = reg_eax;
			reg_eax = reg_edi;
			reg_edi = temp;
			break;
		}
			break;
		CASE_D(0x98)                                                /* CWDE */
			reg_eax = (Bit16s) reg_ax;
			break;
		CASE_D(0x99)                                                /* CDQ */
			if (reg_eax & 0x80000000) reg_edx = 0xffffffff;
			else
				reg_edx = 0;
			break;
		CASE_D(0x9a)                                                /* CALL FAR Ad */
		{
			Bit32u newip = Fetchd();
			Bit16u newcs = Fetchw();
			FillFlags();
			CPU_CALL(true, newcs, newip, GETIP);
#if CPU_TRAP_CHECK
			if (GETFLAG(TF)) {
				cpudecoder = CPU_Core_Normal_Trap_Run;
				return CBRET_NONE;
			}
#endif
			continue;
		}
		CASE_D(0x9c)                                                /* PUSHFD */
			if (CPU_PUSHF(true)) RUNEXCEPTION();
			break;
		CASE_D(0x9d)                                                /* POPFD */
			if (CPU_POPF(true)) RUNEXCEPTION();
#if CPU_TRAP_CHECK
			if (GETFLAG(TF)) {
				cpudecoder = CPU_Core_Normal_Trap_Run;
				goto decode_end;
			}
#endif
#if CPU_PIC_CHECK
			if (GETFLAG(IF) && PIC_IRQCheck) goto decode_end;
#endif
			break;
		CASE_D(0xa1)                                                /* MOV EAX,Od */
		{
			GetEADirect;
			reg_eax = LoadMd(eaa);
		}
			break;
		CASE_D(0xa3)                                                /* MOV Od,EAX */
		{
			GetEADirect;
			SaveMd(eaa, reg_eax);
		}
			break;
		CASE_D(0xa5)                                                /* MOVSD */
			DoString(R_MOVSD);
			break;
		CASE_D(0xa7)                                                /* CMPSD */
			DoString(R_CMPSD);
			break;
		CASE_D(0xa9)                                                /* TEST EAX,Id */
		EAXId(TESTD);
			break;
		CASE_D(0xab)                                                /* STOSD */
			DoString(R_STOSD);
			break;
		CASE_D(0xad)                                                /* LODSD */
			DoString(R_LODSD);
			break;
		CASE_D(0xaf)                                                /* SCASD */
			DoString(R_SCASD);
			break;
		CASE_D(0xb8)                                                /* MOV EAX,Id */
			reg_eax = Fetchd();
			break;
		CASE_D(0xb9)                                                /* MOV ECX,Id */
			reg_ecx = Fetchd();
			break;
		CASE_D(0xba)                                                /* MOV EDX,Iw */
			reg_edx = Fetchd();
			break;
		CASE_D(0xbb)                                                /* MOV EBX,Id */
			reg_ebx = Fetchd();
			break;
		CASE_D(0xbc)                                                /* MOV ESP,Id */
			reg_esp = Fetchd();
			break;
		CASE_D(0xbd)                                                /* MOV EBP.Id */
			reg_ebp = Fetchd();
			break;
		CASE_D(0xbe)                                                /* MOV ESI,Id */
			reg_esi = Fetchd();
			break;
		CASE_D(0xbf)                                                /* MOV EDI,Id */
			reg_edi = Fetchd();
			break;
		CASE_D(0xc1)                                                /* GRP2 Ed,Ib */
		GRP2D(Fetchb());
			break;
		CASE_D(0xc2)                                                /* RETN Iw */
			reg_eip = Pop_32();
			reg_esp += Fetchw();
			continue;
		CASE_D(0xc3)                                                /* RETN */
			reg_eip = Pop_32();
			continue;
		CASE_D(0xc4)                                                /* LES */
		{
			GetRMrd;
			if (rm >= 0xc0) goto illegal_opcode;
			GetEAa;
			if (CPU_SetSegGeneral(es, LoadMw(eaa + 4))) RUNEXCEPTION();
			*rmrd = LoadMd(eaa);
			break;
		}
		CASE_D(0xc5)                                                /* LDS */
		{
			GetRMrd;
			if (rm >= 0xc0) goto illegal_opcode;
			GetEAa;
			if (CPU_SetSegGeneral(ds, LoadMw(eaa + 4))) RUNEXCEPTION();
			*rmrd = LoadMd(eaa);
			break;
		}
		CASE_D(0xc7)                                                /* MOV Ed,Id */
		{
			GetRM;
			if (rm >= 0xc0) {
				GetEArd;
				*eard = Fetchd();
			} else {
				GetEAa;
				SaveMd(eaa, Fetchd());
			}
			break;
		}
		CASE_D(0xc8)                                                /* ENTER Iw,Ib */
		{
			Bitu bytes = Fetchw();
			Bitu level = Fetchb();
			CPU_ENTER(true, bytes, level);
		}
			break;
		CASE_D(0xc9)                                                /* LEAVE */
			reg_esp &= cpu.stack.notmask;
			reg_esp |= (reg_ebp & cpu.stack.mask);
			reg_ebp = Pop_32();
			break;
		CASE_D(0xca)                                                /* RETF Iw */
		{
			Bitu words = Fetchw();
			FillFlags();
			CPU_RET(true, words, GETIP);
			continue;
		}
		CASE_D(0xcb)                                                /* RETF */
		{
			FillFlags();
			CPU_RET(true, 0, GETIP);
			continue;
		}
		CASE_D(0xcf)                                                /* IRET */
		{
			CPU_IRET(true, GETIP);
#if CPU_TRAP_CHECK
			if (GETFLAG(TF)) {
				cpudecoder = CPU_Core_Normal_Trap_Run;
				return CBRET_NONE;
			}
#endif
#if CPU_PIC_CHECK
			if (GETFLAG(IF) && PIC_IRQCheck) return CBRET_NONE;
#endif
			continue;
		}
		CASE_D(0xd1)                                                /* GRP2 Ed,1 */
		GRP2D(1);
			break;
		CASE_D(0xd3)                                                /* GRP2 Ed,CL */
		GRP2D(reg_cl);
			break;
		CASE_D(0xe0)                                                /* LOOPNZ */
			if (TEST_PREFIX_ADDR) {
				JumpCond32_b(--reg_ecx && !get_ZF());
			} else {
				JumpCond32_b(--reg_cx && !get_ZF());
			}
			break;
		CASE_D(0xe1)                                                /* LOOPZ */
			if (TEST_PREFIX_ADDR) {
				JumpCond32_b(--reg_ecx && get_ZF());
			} else {
				JumpCond32_b(--reg_cx && get_ZF());
			}
			break;
		CASE_D(0xe2)                                                /* LOOP */
			if (TEST_PREFIX_ADDR) {
				JumpCond32_b(--reg_ecx);
			} else {
				JumpCond32_b(--reg_cx);
			}
			break;
		CASE_D(0xe3)                                                /* JCXZ */
		JumpCond32_b(!(reg_ecx & AddrMaskTable[core.prefixes & PREFIX_ADDR]));
			break;
		CASE_D(0xe5)                                                /* IN EAX,Ib */
		{
			Bitu port = Fetchb();
			if (CPU_IO_Exception(port, 4)) RUNEXCEPTION();
			reg_eax = IO_ReadD(port);
			break;
		}
		CASE_D(0xe7)                                                /* OUT Ib,EAX */
		{
			Bitu port = Fetchb();
			if (CPU_IO_Exception(port, 4)) RUNEXCEPTION();
			IO_WriteD(port, reg_eax);
			break;
		}
		CASE_D(0xe8)                                                /* CALL Jd */
		{
			Bit32s addip = Fetchds();
			SAVEIP;
			Push_32(reg_eip);
			reg_eip += addip;
			continue;
		}
		CASE_D(0xe9)                                                /* JMP Jd */
		{
			Bit32s addip = Fetchds();
			SAVEIP;
			reg_eip += addip;
			continue;
		}
		CASE_D(0xea)                                                /* JMP Ad */
		{
			Bit32u newip = Fetchd();
			Bit16u newcs = Fetchw();
			FillFlags();
			CPU_JMP(true, newcs, newip, GETIP);
#if CPU_TRAP_CHECK
			if (GETFLAG(TF)) {
				cpudecoder = CPU_Core_Normal_Trap_Run;
				return CBRET_NONE;
			}
#endif
			continue;
		}
		CASE_D(0xeb)                                                /* JMP Jb */
		{
			Bit32s addip = Fetchbs();
			SAVEIP;
			reg_eip += addip;
			continue;
		}
		CASE_D(0xed)                                                /* IN EAX,DX */
			reg_eax = IO_ReadD(reg_dx);
			break;
		CASE_D(0xef)                                                /* OUT DX,EAX */
			IO_WriteD(reg_dx, reg_eax);
			break;
		CASE_D(0xf7)                                                /* GRP3 Ed(,Id) */
		{
			GetRM;
			Bitu which = (rm >> 3) & 7;
			switch (which) {
			case 0x00:                                            /* TEST Ed,Id */
			case 0x01:                                            /* TEST Ed,Id Undocumented*/
			{
				if (rm >= 0xc0) {
					GetEArd;
					TESTD(*eard, Fetchd(), LoadRd, SaveRd);
				} else {
					GetEAa;
					TESTD(eaa, Fetchd(), LoadMd, SaveMd);
				}
				break;
			}
			case 0x02:                                            /* NOT Ed */
			{
				if (rm >= 0xc0) {
					GetEArd;
					*eard = ~*eard;
				} else {
					GetEAa;
					SaveMd(eaa, ~LoadMd(eaa));
				}
				break;
			}
			case 0x03:                                            /* NEG Ed */
			{
				lflags.type = t_NEGd;
				if (rm >= 0xc0) {
					GetEArd;
					lf_var1d = *eard;
					lf_resd = 0 - lf_var1d;
					*eard = lf_resd;
				} else {
					GetEAa;
					lf_var1d = LoadMd(eaa);
					lf_resd = 0 - lf_var1d;
					SaveMd(eaa, lf_resd);
				}
				break;
			}
			case 0x04:                                            /* MUL EAX,Ed */
			RMEd(MULD);
				break;
			case 0x05:                                            /* IMUL EAX,Ed */
			RMEd(IMULD);
				break;
			case 0x06:                                            /* DIV Ed */
			RMEd(DIVD);
				break;
			case 0x07:                                            /* IDIV Ed */
			RMEd(IDIVD);
				break;
			}
			break;
		}
		CASE_D(0xff)                                                /* GRP 5 Ed */
		{
			GetRM;
			Bitu which = (rm >> 3) & 7;
			switch (which) {
			case 0x00:                                            /* INC Ed */
			RMEd(INCD);
				break;
			case 0x01:                                            /* DEC Ed */
			RMEd(DECD);
				break;
			case 0x02:                                            /* CALL NEAR Ed */
				if (rm >= 0xc0) {
					GetEArd;
					reg_eip = *eard;
				} else {
					GetEAa;
					reg_eip = LoadMd(eaa);
				}
				Push_32(GETIP);
				continue;
			case 0x03:                                            /* CALL FAR Ed */
			{
				if (rm >= 0xc0) goto illegal_opcode;
				GetEAa;
				Bit32u newip = LoadMd(eaa);
				Bit16u newcs = LoadMw(eaa + 4);
				FillFlags();
				CPU_CALL(true, newcs, newip, GETIP);
#if CPU_TRAP_CHECK
				if (GETFLAG(TF)) {
					cpudecoder = CPU_Core_Normal_Trap_Run;
					return CBRET_NONE;
				}
#endif
				continue;
			}
			case 0x04:                                            /* JMP NEAR Ed */
				if (rm >= 0xc0) {
					GetEArd;
					reg_eip = *eard;
				} else {
					GetEAa;
					reg_eip = LoadMd(eaa);
				}
				continue;
			case 0x05:                                            /* JMP FAR Ed */
			{
				if (rm >= 0xc0) goto illegal_opcode;
				GetEAa;
				Bit32u newip = LoadMd(eaa);
				Bit16u newcs = LoadMw(eaa + 4);
				FillFlags();
				CPU_JMP(true, newcs, newip, GETIP);
#if CPU_TRAP_CHECK
				if (GETFLAG(TF)) {
					cpudecoder = CPU_Core_Normal_Trap_Run;
					return CBRET_NONE;
				}
#endif
				continue;
			}
				break;
			case 0x06:                                            /* Push Ed */
				if (rm >= 0xc0) {
					GetEArd;
					Push_32(*eard);
				} else {
					GetEAa;
					Push_32(LoadMd(eaa));
				}
				break;
			default:
				LOG(LOG_CPU, LOG_ERROR)("CPU:66:GRP5:Illegal call %2X", which);
				goto illegal_opcode;
			}
			break;
		}

//#include "core_normal/prefix_66_0f.h"

		CASE_0F_D(0x00)                                                /* GRP 6 Exxx */
		{
			if ((reg_flags & FLAG_VM) || (!cpu.pmode)) goto illegal_opcode;
			GetRM;
			Bitu which = (rm >> 3) & 7;
			switch (which) {
			case 0x00:    /* SLDT */
			case 0x01:    /* STR */
			{
				Bitu saveval;
				if (!which) saveval = CPU_SLDT();
				else saveval = CPU_STR();
				if (rm >= 0xc0) {
					GetEArw;
					*earw = (Bit16u) saveval;
				} else {
					GetEAa;
					SaveMw(eaa, saveval);
				}
			}
				break;
			case 0x02:
			case 0x03:
			case 0x04:
			case 0x05: {
				/* Just use 16-bit loads since were only using selectors */
				Bitu loadval;
				if (rm >= 0xc0) {
					GetEArw;
					loadval = *earw;
				} else {
					GetEAa;
					loadval = LoadMw(eaa);
				}
				switch (which) {
				case 0x02:
					if (cpu.cpl) EXCEPTION(EXCEPTION_GP);
					if (CPU_LLDT(loadval)) RUNEXCEPTION();
					break;
				case 0x03:
					if (cpu.cpl) EXCEPTION(EXCEPTION_GP);
					if (CPU_LTR(loadval)) RUNEXCEPTION();
					break;
				case 0x04:
					CPU_VERR(loadval);
					break;
				case 0x05:
					CPU_VERW(loadval);
					break;
				}
			}
				break;
			default:
				LOG(LOG_CPU, LOG_ERROR)("GRP6:Illegal call %2X", which);
				goto illegal_opcode;
			}
		}
			break;
		CASE_0F_D(0x01)                                                /* Group 7 Ed */
		{
			GetRM;
			Bitu which = (rm >> 3) & 7;
			if (rm < 0xc0) { //First ones all use EA
				GetEAa;
				Bitu limit;
				switch (which) {
				case 0x00:                                        /* SGDT */
					SaveMw(eaa, (Bit16u) CPU_SGDT_limit());
					SaveMd(eaa + 2, (Bit32u) CPU_SGDT_base());
					break;
				case 0x01:                                        /* SIDT */
					SaveMw(eaa, (Bit16u) CPU_SIDT_limit());
					SaveMd(eaa + 2, (Bit32u) CPU_SIDT_base());
					break;
				case 0x02:                                        /* LGDT */
					if (cpu.pmode && cpu.cpl) EXCEPTION(EXCEPTION_GP);
					CPU_LGDT(LoadMw(eaa), LoadMd(eaa + 2));
					break;
				case 0x03:                                        /* LIDT */
					if (cpu.pmode && cpu.cpl) EXCEPTION(EXCEPTION_GP);
					CPU_LIDT(LoadMw(eaa), LoadMd(eaa + 2));
					break;
				case 0x04:                                        /* SMSW */
					SaveMw(eaa, (Bit16u) CPU_SMSW());
					break;
				case 0x06:                                        /* LMSW */
					limit = LoadMw(eaa);
					if (CPU_LMSW((Bit16u) limit)) RUNEXCEPTION();
					break;
				case 0x07:                                        /* INVLPG */
					if (cpu.pmode && cpu.cpl) EXCEPTION(EXCEPTION_GP);
					PAGING_ClearTLB();
					break;
				}
			} else {
				GetEArd;
				switch (which) {
				case 0x02:                                        /* LGDT */
					if (cpu.pmode && cpu.cpl) EXCEPTION(EXCEPTION_GP);
					goto illegal_opcode;
				case 0x03:                                        /* LIDT */
					if (cpu.pmode && cpu.cpl) EXCEPTION(EXCEPTION_GP);
					goto illegal_opcode;
				case 0x04:                                        /* SMSW */
					*eard = (Bit32u) CPU_SMSW();
					break;
				case 0x06:                                        /* LMSW */
					if (CPU_LMSW(*eard)) RUNEXCEPTION();
					break;
				default:
					LOG(LOG_CPU, LOG_ERROR)("Illegal group 7 RM subfunction %d", which);
					goto illegal_opcode;
					break;
				}

			}
		}
			break;
		CASE_0F_D(0x02)                                                /* LAR Gd,Ed */
		{
			if ((reg_flags & FLAG_VM) || (!cpu.pmode)) goto illegal_opcode;
			GetRMrd;
			Bitu ar = *rmrd;
			if (rm >= 0xc0) {
				GetEArw;
				CPU_LAR(*earw, ar);
			} else {
				GetEAa;
				CPU_LAR(LoadMw(eaa), ar);
			}
			*rmrd = (Bit32u) ar;
		}
			break;
		CASE_0F_D(0x03)                                                /* LSL Gd,Ew */
		{
			if ((reg_flags & FLAG_VM) || (!cpu.pmode)) goto illegal_opcode;
			GetRMrd;
			Bitu limit = *rmrd;
			/* Just load 16-bit values for selectors */
			if (rm >= 0xc0) {
				GetEArw;
				CPU_LSL(*earw, limit);
			} else {
				GetEAa;
				CPU_LSL(LoadMw(eaa), limit);
			}
			*rmrd = (Bit32u) limit;
		}
			break;
		CASE_0F_D(0x80)                                                /* JO */
		JumpCond32_d(TFLG_O);
			break;
		CASE_0F_D(0x81)                                                /* JNO */
		JumpCond32_d(TFLG_NO);
			break;
		CASE_0F_D(0x82)                                                /* JB */
		JumpCond32_d(TFLG_B);
			break;
		CASE_0F_D(0x83)                                                /* JNB */
		JumpCond32_d(TFLG_NB);
			break;
		CASE_0F_D(0x84)                                                /* JZ */
		JumpCond32_d(TFLG_Z);
			break;
		CASE_0F_D(0x85)                                                /* JNZ */
		JumpCond32_d(TFLG_NZ);
			break;
		CASE_0F_D(0x86)                                                /* JBE */
		JumpCond32_d(TFLG_BE);
			break;
		CASE_0F_D(0x87)                                                /* JNBE */
		JumpCond32_d(TFLG_NBE);
			break;
		CASE_0F_D(0x88)                                                /* JS */
		JumpCond32_d(TFLG_S);
			break;
		CASE_0F_D(0x89)                                                /* JNS */
		JumpCond32_d(TFLG_NS);
			break;
		CASE_0F_D(0x8a)                                                /* JP */
		JumpCond32_d(TFLG_P);
			break;
		CASE_0F_D(0x8b)                                                /* JNP */
		JumpCond32_d(TFLG_NP);
			break;
		CASE_0F_D(0x8c)                                                /* JL */
		JumpCond32_d(TFLG_L);
			break;
		CASE_0F_D(0x8d)                                                /* JNL */
		JumpCond32_d(TFLG_NL);
			break;
		CASE_0F_D(0x8e)                                                /* JLE */
		JumpCond32_d(TFLG_LE);
			break;
		CASE_0F_D(0x8f)                                                /* JNLE */
		JumpCond32_d(TFLG_NLE);
			break;

		CASE_0F_D(0xa0)                                                /* PUSH FS */
			Push_32(SegValue(fs));
			break;
		CASE_0F_D(0xa1)                                                /* POP FS */
			if (CPU_PopSeg(fs, true)) RUNEXCEPTION();
			break;
		CASE_0F_D(0xa3)                                                /* BT Ed,Gd */
		{
			FillFlags();
			GetRMrd;
			Bit32u mask = 1 << (*rmrd & 31);
			if (rm >= 0xc0) {
				GetEArd;
				SETFLAGBIT(CF, (*eard & mask));
			} else {
				GetEAa;
				eaa += (((Bit32s) *rmrd) >> 5) * 4;
				Bit32u old = LoadMd(eaa);
				SETFLAGBIT(CF, (old & mask));
			}
			break;
		}
		CASE_0F_D(0xa4)                                                /* SHLD Ed,Gd,Ib */
		RMEdGdOp3(DSHLD, Fetchb());
			break;
		CASE_0F_D(0xa5)                                                /* SHLD Ed,Gd,CL */
		RMEdGdOp3(DSHLD, reg_cl);
			break;
		CASE_0F_D(0xa8)                                                /* PUSH GS */
			Push_32(SegValue(gs));
			break;
		CASE_0F_D(0xa9)                                                /* POP GS */
			if (CPU_PopSeg(gs, true)) RUNEXCEPTION();
			break;
		CASE_0F_D(0xab)                                                /* BTS Ed,Gd */
		{
			FillFlags();
			GetRMrd;
			Bit32u mask = 1 << (*rmrd & 31);
			if (rm >= 0xc0) {
				GetEArd;
				SETFLAGBIT(CF, (*eard & mask));
				*eard |= mask;
			} else {
				GetEAa;
				eaa += (((Bit32s) *rmrd) >> 5) * 4;
				Bit32u old = LoadMd(eaa);
				SETFLAGBIT(CF, (old & mask));
				SaveMd(eaa, old | mask);
			}
			break;
		}

		CASE_0F_D(0xac)                                                /* SHRD Ed,Gd,Ib */
		RMEdGdOp3(DSHRD, Fetchb());
			break;
		CASE_0F_D(0xad)                                                /* SHRD Ed,Gd,CL */
		RMEdGdOp3(DSHRD, reg_cl);
			break;
		CASE_0F_D(0xaf)                                                /* IMUL Gd,Ed */
		{
			RMGdEdOp3(DIMULD, *rmrd);
			break;
		}
		CASE_0F_D(0xb1)                                                /* CMPXCHG Ed,Gd */
		{
			if (CPU_ArchitectureType < CPU_ARCHTYPE_486NEWSLOW) goto illegal_opcode;
			FillFlags();
			GetRMrd;
			if (rm >= 0xc0) {
				GetEArd;
				if (*eard == reg_eax) {
					*eard = *rmrd;
					SETFLAGBIT(ZF, 1);
				} else {
					reg_eax = *eard;
					SETFLAGBIT(ZF, 0);
				}
			} else {
				GetEAa;
				Bit32u val = LoadMd(eaa);
				if (val == reg_eax) {
					SaveMd(eaa, *rmrd);
					SETFLAGBIT(ZF, 1);
				} else {
					SaveMd(eaa, val);    // cmpxchg always issues a write
					reg_eax = val;
					SETFLAGBIT(ZF, 0);
				}
			}
			break;
		}
		CASE_0F_D(0xb2)                                                /* LSS Ed */
		{
			GetRMrd;
			if (rm >= 0xc0) goto illegal_opcode;
			GetEAa;
			if (CPU_SetSegGeneral(ss, LoadMw(eaa + 4))) RUNEXCEPTION();
			*rmrd = LoadMd(eaa);
			break;
		}
		CASE_0F_D(0xb3)                                                /* BTR Ed,Gd */
		{
			FillFlags();
			GetRMrd;
			Bit32u mask = 1 << (*rmrd & 31);
			if (rm >= 0xc0) {
				GetEArd;
				SETFLAGBIT(CF, (*eard & mask));
				*eard &= ~mask;
			} else {
				GetEAa;
				eaa += (((Bit32s) *rmrd) >> 5) * 4;
				Bit32u old = LoadMd(eaa);
				SETFLAGBIT(CF, (old & mask));
				SaveMd(eaa, old & ~mask);
			}
			break;
		}
		CASE_0F_D(0xb4)                                                /* LFS Ed */
		{
			GetRMrd;
			if (rm >= 0xc0) goto illegal_opcode;
			GetEAa;
			if (CPU_SetSegGeneral(fs, LoadMw(eaa + 4))) RUNEXCEPTION();
			*rmrd = LoadMd(eaa);
			break;
		}
		CASE_0F_D(0xb5)                                                /* LGS Ed */
		{
			GetRMrd;
			if (rm >= 0xc0) goto illegal_opcode;
			GetEAa;
			if (CPU_SetSegGeneral(gs, LoadMw(eaa + 4))) RUNEXCEPTION();
			*rmrd = LoadMd(eaa);
			break;
		}
		CASE_0F_D(0xb6)                                                /* MOVZX Gd,Eb */
		{
			GetRMrd;
			if (rm >= 0xc0) {
				GetEArb;
				*rmrd = *earb;
			} else {
				GetEAa;
				*rmrd = LoadMb(eaa);
			}
			break;
		}
		CASE_0F_D(0xb7)                                                /* MOVXZ Gd,Ew */
		{
			GetRMrd;
			if (rm >= 0xc0) {
				GetEArw;
				*rmrd = *earw;
			} else {
				GetEAa;
				*rmrd = LoadMw(eaa);
			}
			break;
		}
		CASE_0F_D(0xba)                                                /* GRP8 Ed,Ib */
		{
			FillFlags();
			GetRM;
			if (rm >= 0xc0) {
				GetEArd;
				Bit32u mask = 1 << (Fetchb() & 31);
				SETFLAGBIT(CF, (*eard & mask));
				switch (rm & 0x38) {
				case 0x20:                                            /* BT */
					break;
				case 0x28:                                            /* BTS */
					*eard |= mask;
					break;
				case 0x30:                                            /* BTR */
					*eard &= ~mask;
					break;
				case 0x38:                                            /* BTC */
					if (GETFLAG(CF)) *eard &= ~mask;
					else *eard |= mask;
					break;
				default:
					E_Exit("CPU:66:0F:BA:Illegal subfunction %X", rm & 0x38);
				}
			} else {
				GetEAa;
				Bit32u old = LoadMd(eaa);
				Bit32u mask = 1 << (Fetchb() & 31);
				SETFLAGBIT(CF, (old & mask));
				switch (rm & 0x38) {
				case 0x20:                                            /* BT */
					break;
				case 0x28:                                            /* BTS */
					SaveMd(eaa, old | mask);
					break;
				case 0x30:                                            /* BTR */
					SaveMd(eaa, old & ~mask);
					break;
				case 0x38:                                            /* BTC */
					if (GETFLAG(CF)) old &= ~mask;
					else old |= mask;
					SaveMd(eaa, old);
					break;
				default:
					E_Exit("CPU:66:0F:BA:Illegal subfunction %X", rm & 0x38);
				}
			}
			break;
		}
		CASE_0F_D(0xbb)                                                /* BTC Ed,Gd */
		{
			FillFlags();
			GetRMrd;
			Bit32u mask = 1 << (*rmrd & 31);
			if (rm >= 0xc0) {
				GetEArd;
				SETFLAGBIT(CF, (*eard & mask));
				*eard ^= mask;
			} else {
				GetEAa;
				eaa += (((Bit32s) *rmrd) >> 5) * 4;
				Bit32u old = LoadMd(eaa);
				SETFLAGBIT(CF, (old & mask));
				SaveMd(eaa, old ^ mask);
			}
			break;
		}
		CASE_0F_D(0xbc)                                                /* BSF Gd,Ed */
		{
			GetRMrd;
			Bit32u result, value;
			if (rm >= 0xc0) {
				GetEArd;
				value = *eard;
			} else {
				GetEAa;
				value = LoadMd(eaa);
			}
			if (value == 0) {
				SETFLAGBIT(ZF, true);
			} else {
				result = 0;
				while ((value & 0x01) == 0) {
					result++;
					value >>= 1;
				}
				SETFLAGBIT(ZF, false);
				*rmrd = result;
			}
			lflags.type = t_UNKNOWN;
			break;
		}
		CASE_0F_D(0xbd)                                                /*  BSR Gd,Ed */
		{
			GetRMrd;
			Bit32u result, value;
			if (rm >= 0xc0) {
				GetEArd;
				value = *eard;
			} else {
				GetEAa;
				value = LoadMd(eaa);
			}
			if (value == 0) {
				SETFLAGBIT(ZF, true);
			} else {
				result = 31;    // Operandsize-1
				while ((value & 0x80000000) == 0) {
					result--;
					value <<= 1;
				}
				SETFLAGBIT(ZF, false);
				*rmrd = result;
			}
			lflags.type = t_UNKNOWN;
			break;
		}
		CASE_0F_D(0xbe)                                                /* MOVSX Gd,Eb */
		{
			GetRMrd;
			if (rm >= 0xc0) {
				GetEArb;
				*rmrd = *(Bit8s *) earb;
			} else {
				GetEAa;
				*rmrd = LoadMbs(eaa);
			}
			break;
		}
		CASE_0F_D(0xbf)                                                /* MOVSX Gd,Ew */
		{
			GetRMrd;
			if (rm >= 0xc0) {
				GetEArw;
				*rmrd = *(Bit16s *) earw;
			} else {
				GetEAa;
				*rmrd = LoadMws(eaa);
			}
			break;
		}
		CASE_0F_D(0xc1)                                                /* XADD Gd,Ed */
		{
			if (CPU_ArchitectureType < CPU_ARCHTYPE_486OLDSLOW) goto illegal_opcode;
			GetRMrd;
			Bit32u oldrmrd = *rmrd;
			if (rm >= 0xc0) {
				GetEArd;
				*rmrd = *eard;
				*eard += oldrmrd;
			} else {
				GetEAa;
				*rmrd = LoadMd(eaa);
				SaveMd(eaa, LoadMd(eaa) + oldrmrd);
			}
			break;
		}
		CASE_0F_D(0xc8)                                                /* BSWAP EAX */
			if (CPU_ArchitectureType < CPU_ARCHTYPE_486OLDSLOW) goto illegal_opcode;
			BSWAPD(reg_eax);
			break;
		CASE_0F_D(0xc9)                                                /* BSWAP ECX */
			if (CPU_ArchitectureType < CPU_ARCHTYPE_486OLDSLOW) goto illegal_opcode;
			BSWAPD(reg_ecx);
			break;
		CASE_0F_D(0xca)                                                /* BSWAP EDX */
			if (CPU_ArchitectureType < CPU_ARCHTYPE_486OLDSLOW) goto illegal_opcode;
			BSWAPD(reg_edx);
			break;
		CASE_0F_D(0xcb)                                                /* BSWAP EBX */
			if (CPU_ArchitectureType < CPU_ARCHTYPE_486OLDSLOW) goto illegal_opcode;
			BSWAPD(reg_ebx);
			break;
		CASE_0F_D(0xcc)                                                /* BSWAP ESP */
			if (CPU_ArchitectureType < CPU_ARCHTYPE_486OLDSLOW) goto illegal_opcode;
			BSWAPD(reg_esp);
			break;
		CASE_0F_D(0xcd)                                                /* BSWAP EBP */
			if (CPU_ArchitectureType < CPU_ARCHTYPE_486OLDSLOW) goto illegal_opcode;
			BSWAPD(reg_ebp);
			break;
		CASE_0F_D(0xce)                                                /* BSWAP ESI */
			if (CPU_ArchitectureType < CPU_ARCHTYPE_486OLDSLOW) goto illegal_opcode;
			BSWAPD(reg_esi);
			break;
		CASE_0F_D(0xcf)                                                /* BSWAP EDI */
			if (CPU_ArchitectureType < CPU_ARCHTYPE_486OLDSLOW) goto illegal_opcode;
			BSWAPD(reg_edi);
			break;
// After all
		default:
	illegal_opcode:
#if C_DEBUG
		{
			Bitu len = (GETIP - reg_eip);
			LOADIP;
			if (len > 16) len = 16;
			char tempcode[16 * 2 + 1]; char * writecode = tempcode;
			for (; len > 0; len--) {
				sprintf(writecode, "%02X", mem_readb(core.cseip++));
				writecode += 2;
			}
			LOG(LOG_CPU, LOG_NORMAL)("Illegal/Unhandled opcode %s", tempcode);
		}
#endif
			CPU_Exception(6, 0);
			continue;
		}
		SAVEIP;
	}
	FillFlags();
	return CBRET_NONE;
decode_end:
	SAVEIP;
	FillFlags();
	return CBRET_NONE;
}

Bits CPU_Core_Normal_Trap_Run(void) {
	Bits oldCycles = CPU_Cycles;
	CPU_Cycles = 1;
	cpu.trap_skip = false;

	Bits ret = CPU_Core_Normal_Run();
	if (!cpu.trap_skip) CPU_HW_Interrupt(1);
	CPU_Cycles = oldCycles - 1;
	cpudecoder = &CPU_Core_Normal_Run;

	return ret;
}

void CPU_Core_Normal_Init(void) {

}

