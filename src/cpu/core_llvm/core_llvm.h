//
// Created by 张航 on 2018/5/9.
//

#ifndef PROJECT_CORE_LLVM_H
#define PROJECT_CORE_LLVM_H

#include <memory.h>
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

static struct {
	Bitu opcode_index;
	PhysPt cseip;
	PhysPt base_ds, base_ss;
	SegNames base_val_ds;
	bool rep_zero;
	Bitu prefixes;
	GetEAHandler *ea_table;
} core;

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

class cpu_x86_instruction {
public:
	const static Bit32u OPCODE_INVALID = UINT32_MAX;
	cpu_x86_instruction() {
		prefixRepeat = 0;
		prefixSegment = 0;
		prefixOperand = false;
		prefixAddress = false;
		opcode = OPCODE_INVALID;
		modRM = 0;
		sib = 0;
	}

	inline bool Decode(PhysPt &cseip) {
		for (;;) {
			Bit8u inst_b = Fetchb(cseip);
			switch (inst_b) {
			case 0xf0:
			case 0xf2:
			case 0xf3:    // Lock and repeat prefixes
				prefixRepeat = inst_b;
				continue;
			case 0x26:    // ES Segment override prefixes
			case 0x2e:    // CS Segment override prefixes or Branch not taken (used only with Jcc instructions)
			case 0x36:    // SS Segment override prefixes
			case 0x3e:    // DS Segment override prefixes or Branch taken (used only with Jcc instructions)
			case 0x64:    // FS Segment override prefixes
			case 0x65:    // GS Segment override prefixes
				prefixSegment = inst_b;
				continue;
			case 0x66:    // Operand-size override prefix or mandatory prefix for some instructions
				prefixOperand = true;
				continue;
			case 0x67:    // Address-size override prefix
				prefixAddress = true;
				continue;
			case 0x0f:    // 2-bytes escape byte
				return Decode2ndByte(cseip);
			default:
				break;
			}
			return Decode1stByte(inst_b, cseip);
		}
		return false;
	}

	inline bool Decode1stByte(Bit8u inst_b, PhysPt& cseip) {
		switch(inst_b) {
		}
		return false;
	}

	inline bool Decode2ndByte(PhysPt& cseip) {
		Bit8u inst_b = Fetchb(cseip);
		switch(inst_b) {
		case 0x38:
		case 0x3a:	// 3-bytes escape byte
			return Decode3rdByte(cseip);
			break;
		case 0x00:
			break;
		}
		return false;
	}

	inline bool Decode3rdByte(PhysPt& cseip) {
		Bit8u inst_b = Fetchb(cseip);
		switch(inst_b) {
		case 0x38:
		case 0x3a:	// 3-bytes escape byte
			break;
		}
		return false;
	}

public:
	Bit8u GetPrefixRepeat() const {
		return prefixRepeat;
	}
	Bit8u GetPrefixSegment() const {
		return prefixSegment;
	}
	bool GetPrefixOperand() const {
		return prefixOperand;
	}
	bool GetPrefixAddress() const {
		return prefixAddress;
	}

private:
	static bool defaultSize; // True=Dword(32 Bits), False=Word(16 Bits)
	Bit8u prefixRepeat;		//F0h, F2h, F3h
	Bit8u prefixSegment;	//2Eh, 36h, 3Eh, 26h, 64h, 65h
	bool prefixOperand;	//66h
	bool prefixAddress;	//67h

	Bit32u 	opcode;
	Bit8u	modRM;
	Bit8u	sib;
};

#endif //PROJECT_CORE_LLVM_H
