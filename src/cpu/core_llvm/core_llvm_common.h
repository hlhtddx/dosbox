//
// Created by 张航 on 2018/5/15.
//

#ifndef PROJECT_CORE_LLVM_COMMON_H
#define PROJECT_CORE_LLVM_COMMON_H

#include "cpu.h"

#if (!C_CORE_INLINE)
#define LoadMb(off)        	mem_readb(off)
    #define LoadMw(off)        	mem_readw(off)
    #define LoadMd(off)        	mem_readd(off)
    #define SaveMb(off, val)	mem_writeb(off,val)
    #define SaveMw(off, val)	mem_writew(off,val)
    #define SaveMd(off, val)	mem_writed(off,val)
#else
#include "paging.h"
#define LoadMb(off) 		mem_readb_inline(off)
#define LoadMw(off) 		mem_readw_inline(off)
#define LoadMd(off) 		mem_readd_inline(off)
#define SaveMb(off, val)	mem_writeb_inline(off,val)
#define SaveMw(off, val)	mem_writew_inline(off,val)
#define SaveMd(off, val)	mem_writed_inline(off,val)
#endif

static inline Bit8u Fetchb(PhysPt cseip) {
	Bit8u temp = LoadMb(cseip);
	cseip += 1;
	return temp;
}

static inline Bit16u Fetchw(PhysPt cseip) {
	Bit16u temp = LoadMw(cseip);
	cseip += 2;
	return temp;
}

static inline Bit32u Fetchd(PhysPt cseip) {
	Bit32u temp = LoadMd(cseip);
	cseip += 4;
	return temp;
}

static struct {
	Bitu opcode_index;
	PhysPt cseip;
	PhysPt base_ds, base_ss;
	SegNames base_val_ds;
	bool rep_zero;
	Bitu prefixes;
} core;

#endif //PROJECT_CORE_LLVM_COMMON_H
