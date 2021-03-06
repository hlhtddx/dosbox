//
// Created by 张航 on 2018/5/15.
//

#ifndef PROJECT_CORE_LLVM_COMMON_H
#define PROJECT_CORE_LLVM_COMMON_H

#include <stdexcept>
#include <functional>
#include "callback.h"
#include "cpu.h"
#include "inout.h"
#include "../lazyflags.h"

#if (!C_CORE_INLINE)
#define LoadMb(off)                mem_readb(off)
#define LoadMw(off)            mem_readw(off)
#define LoadMd(off)            mem_readd(off)
#define SaveMb(off, val)    mem_writeb(off,val)
#define SaveMw(off, val)    mem_writew(off,val)
#define SaveMd(off, val)    mem_writed(off,val)
#else
#include "paging.h"
#define LoadMb(off) 		mem_readb_inline(off)
#define LoadMw(off) 		mem_readw_inline(off)
#define LoadMd(off) 		mem_readd_inline(off)
#define SaveMb(off, val)	mem_writeb_inline(off,val)
#define SaveMw(off, val)	mem_writew_inline(off,val)
#define SaveMd(off, val)	mem_writed_inline(off,val)
#endif

#define SegBase(c)    SegPhys(c)
#define BaseDS        base_ds
#define BaseSS        base_ss

namespace core_llvm {

class IllegalInstructionException : public std::runtime_error {
public:
    explicit IllegalInstructionException() : std::runtime_error("Illegal Instruction") {}
};

class NotSupportException : public std::runtime_error {
public:
    explicit NotSupportException() : std::runtime_error("Not supported operation") {}
};

template<typename operand_type>
class GeneralReference {
public:
    virtual inline operand_type Read() = 0;
    virtual inline void Write(operand_type value) = 0;
    virtual inline operand_type Read(Bits offset) = 0;
    virtual inline void Write(Bits offset, operand_type value) = 0;
    virtual inline operand_type GetEffectiveAddress() = 0;
};

template<typename operand_type>
class GeneralRegister : public GeneralReference<operand_type> {
public:
    explicit GeneralRegister(operand_type &reg_number)
        : mRegister(reg_number) {}

    virtual inline operand_type Read() {
        return mRegister;
    }

    virtual inline void Write(operand_type value) {
        mRegister = value;
    }

    virtual inline operand_type Read(Bits offset) {
        throw NotSupportException();
    }

    virtual inline void Write(Bits offset, operand_type value) {
        throw NotSupportException();
    }

    virtual inline operand_type GetEffectiveAddress() {
        throw IllegalInstructionException();
    }

protected:
    operand_type &mRegister;
};

template<typename operand_type>
class SegmentRegister : public GeneralReference<operand_type> {
public:
    explicit SegmentRegister(SegNames reg_number)
        : mSegNames(reg_number) {}

    virtual inline operand_type Read() {
        return SegValue(mSegNames);
    }

    virtual inline void Write(operand_type value) {
        CPU_SetSegGeneral(mSegNames, value);
    }

    virtual inline operand_type Read(Bits offset) {
        throw NotSupportException();
    }

    virtual inline void Write(Bits offset, operand_type value) {
        throw NotSupportException();
    }

    virtual inline operand_type GetEffectiveAddress() {
        throw IllegalInstructionException();
    }

protected:
    SegNames mSegNames;
};

template <typename operand_type> operand_type ReadMemory(PhysPt address);
template <typename operand_type> void WriteMemory(PhysPt address, operand_type value);

template<> inline Bit8u ReadMemory<Bit8u>(PhysPt address) {
	return LoadMb(address);
}

template<> inline Bit16u ReadMemory<Bit16u>(PhysPt address) {
	return LoadMw(address);
}

template<> inline Bit32u ReadMemory<Bit32u>(PhysPt address) {
	return LoadMd(address);
}
//
//template<> inline Bit48u ReadMemory<Bit48u>(PhysPt address) {
//	Bit16u w = mem_readw(address);
//	Bit32u d = mem_readw(address + sizeof(w));
//	return Bit48u(w, d);
//}

template<> inline Bit8s ReadMemory<Bit8s>(PhysPt address) {
	return LoadMb(address);
}

template<> inline Bit16s ReadMemory<Bit16s>(PhysPt address) {
	return LoadMw(address);
}

template<> inline Bit32s ReadMemory<Bit32s>(PhysPt address) {
	return LoadMd(address);
}

template<> inline void WriteMemory<Bit8u>(PhysPt address, Bit8u value) {
	return SaveMb(address, value);
}

template<> inline void WriteMemory<Bit16u>(PhysPt address, Bit16u value) {
	return SaveMw(address, value);
}

template<> inline void WriteMemory<Bit32u>(PhysPt address, Bit32u value) {
	return SaveMd(address, value);
}
//
//template<> inline void WriteMemory<Bit48u>(PhysPt address, Bit48u value) {
//	mem_writew(address, value.w_value);
//	mem_writed(address + sizeof(value.w_value), value.d_value);
//}

template<> inline void WriteMemory<Bit8s>(PhysPt address, Bit8s value) {
	return SaveMb(address, static_cast<Bit8u>(value));
}

template<> inline void WriteMemory<Bit16s>(PhysPt address, Bit16s value) {
	return SaveMw(address, static_cast<Bit16u>(value));
}

template<> inline void WriteMemory<Bit32s>(PhysPt address, Bit32s value) {
	return SaveMd(address, static_cast<Bit32u>(value));
}

template<typename data_type> inline data_type Load(PhysPt address);
template<typename data_type> inline void Save(PhysPt address, data_type value);

template<typename operand_type>
class MemoryReference : public GeneralReference<operand_type> {
public:
    MemoryReference() {
    }

    void SetAddress(const PhysPt &address) {
        mAddress = address;
    }

    virtual inline operand_type Read() {
        return ReadMemory<operand_type>(mAddress);
    }

    virtual inline void Write(operand_type value) {
        WriteMemory<operand_type>(mAddress, value);
    }

    virtual inline operand_type Read(Bits offset) {
        return ReadMemory<operand_type>(mAddress + offset);
    }

    virtual inline void Write(Bits offset, operand_type value) {
        WriteMemory<operand_type>(mAddress + offset, value);
    }

    virtual inline operand_type GetEffectiveAddress() {
        return mAddress;
    }

protected:
    PhysPt mAddress;
};

template<typename operand_type>
class RegMemoryReference : public GeneralReference<operand_type> {
public:
    RegMemoryReference(operand_type &gen_register, operand_type &seg_register)
    : mGeneralRegister(gen_register)
    , mSegmentRegister(seg_register)
    {
    }

    virtual inline operand_type Read() {
        PhysPt address = SegBase(mSegmentRegister) + mGeneralRegister;
        return ReadMemory<operand_type>(address);
    }

    virtual inline void Write(operand_type value) {
        PhysPt address = SegBase(mSegmentRegister) + mGeneralRegister;
        WriteMemory<operand_type>(address, value);
    }

    virtual inline operand_type Read(Bits offset) {
        PhysPt address = SegBase(mSegmentRegister) + mGeneralRegister;
        return ReadMemory<operand_type>(address + offset);
    }

    virtual inline void Write(Bits offset, operand_type value) {
        PhysPt address = SegBase(mSegmentRegister) + mGeneralRegister;
        WriteMemory<operand_type>(address + offset, value);
    }

protected:
    operand_type &mSegmentRegister;
    operand_type &mGeneralRegister;
};

enum {
    I_AX = 0,
    I_CX, I_DX, I_BX, I_SP, I_BP, I_SI, I_DI
};
static Bit8u* GenRegisters8u[] = {&reg_al, &reg_cl, &reg_dl, &reg_bl, &reg_ah, &reg_ch, &reg_dh, &reg_bh, };
static Bit16u* GenRegisters16u[] = {&reg_ax, &reg_cx, &reg_dx, &reg_bx, &reg_sp, &reg_bp, &reg_si, &reg_di, };
static Bit32u* GenRegisters32u[] = {&reg_eax, &reg_ecx, &reg_edx, &reg_ebx, &reg_esp, &reg_ebp, &reg_esi, &reg_edi, };

template<typename operand_type> inline operand_type& GetGenRegister(int index);
template<> inline Bit8u& GetGenRegister<Bit8u>(int index) {
    return *GenRegisters8u[index];
}

template<> inline Bit16u& GetGenRegister<Bit16u>(int index) {
    return *GenRegisters16u[index];
}

template<> inline Bit32u& GetGenRegister<Bit32u>(int index) {
    return *GenRegisters32u[index];
}

template<typename operand_type> inline void IO_Write(Bitu port, Bitu val);
template<typename operand_type> inline Bitu IO_Read(Bitu port);

template<> inline void IO_Write<Bit8u>(Bitu port, Bitu val) {
    return IO_WriteB(port, val);
}

template<> inline void IO_Write<Bit16u>(Bitu port, Bitu val) {
    return IO_WriteW(port, val);
}

template<> inline void IO_Write<Bit32u>(Bitu port, Bitu val) {
    return IO_WriteD(port, val);
}

template<> inline Bitu IO_Read<Bit8u>(Bitu port) {
    return IO_ReadB(port);
}

template<> inline Bitu IO_Read<Bit16u>(Bitu port) {
    return IO_ReadW(port);
}

template<> inline Bitu IO_Read<Bit32u>(Bitu port) {
    return IO_ReadD(port);
}

class CpuRunnerLLVMBase {

public:
    PhysPt cseip;
    PhysPt base_ds, base_ss;
    SegNames base_val_ds;
    bool m_bRestoreIP;
    Bits m_nReturnVal;

    union {
        struct {
            Bit8u segment_override;
            Bit8u rep;
            Bit8u operand_size_override;
            Bit8u address_size_override;
        } prefixes;
        Bit32u all_prefix;
    } option_prefix;

    Bit8u mandatory_prefix;

    enum prefix_rep_flag {
        REP_NONE = 0,
        REPZ,
        REPNZ,
        REP_LOCK,
    };

    enum prefix_segment_flag {
        SEGMENT_NONE = 0,
        SEGMENT_CS,
        SEGMENT_SS,
        SEGMENT_DS,
        SEGMENT_ES,
        SEGMENT_FS,
        SEGMENT_GS,
    };

    enum prefix_operand_size_flag {
        OPERAND_SIZE_NONE = 0,
        OPERAND_SIZE_OVERRIDE,
    };

    enum prefix_address_size_flag {
        ADDRESS_SIZE_NONE = 0,
        ADDRESS_SIZE_OVERRIDE,
    };

    inline void SaveIP() {
        reg_eip = GetIP();
    }

    inline void LoadIP() {
        cseip = (SegBase(cs) + reg_eip);
    }

	inline void LogUDException() {
		Bitu len = (GetIP() - reg_eip);
		LoadIP();
		if (len > 16) len = 16;
		char tempcode[16 * 2 + 1]; char * writecode = tempcode;
		for (; len > 0; len--) {
			sprintf(writecode, "%02X", mem_readb(cseip++));
			writecode += 2;
		}
		LOG(LOG_CPU, LOG_NORMAL)("Illegal/Unhandled opcode %s", tempcode);
	}

    void PrepareParsing() {
        LoadIP();
        base_ds = SegBase(ds);
        base_ss = SegBase(ss);
        base_val_ds = ds;
        m_bRestoreIP = true;
        m_nReturnVal = CBRET_NONE;
    }

public:

    bool Is32BitAddressMode() const {
        return false;
    }

    bool Is32BitOperandMode() const {
        return false;
    }

    bool Is_REP_Zero() const {
        return option_prefix.prefixes.rep == REPZ;
    }

    bool HasPrefixRepeat() const {
        return option_prefix.prefixes.rep == REPZ || option_prefix.prefixes.rep == REPNZ;
    }

    bool RestoreEIP() const {
        return m_bRestoreIP;
    }

    template<typename operand_type> GeneralReference<operand_type> *GetRmMod(Bit8u rm_mod) {
        auto mod = static_cast<Bit8u>(rm_mod & 0xc0u);
        auto reg = static_cast<Bit8u>(rm_mod & 0x38u);
        auto rm = static_cast<Bit8u>(rm_mod & 0x7u);
        if (mod >= 0xc0) {
            // Refer to a register
            return GetGeneralRegister<operand_type>(rm);
        } else {
            // Refer to a memory
            return GetRM_Memory<operand_type>(rm, mod);
        }
    }

    template<typename operand_type> GeneralReference<operand_type> *GetRmRm(Bit8u rm_mod) {
        auto rm = static_cast<Bit8u>(rm_mod & 0x7u);
        return GetGeneralRegister<operand_type>(rm);
    }

    template<typename operand_type> GeneralReference<operand_type> *GetRmReg(Bit8u rm_mod) {
        auto reg = static_cast<Bit8u>(rm_mod & 0x38u);
        return GetGeneralRegister<operand_type>(reg >> 3);
    }

    template<typename operand_type> GeneralReference<operand_type> *GetRmSreg(Bit8u rm_mod) {
        auto reg = static_cast<Bit8u>(rm_mod & 0x38u);
        return GetSegmentRegister<operand_type>(reg >> 3);
    }

    template<typename operand_type> GeneralReference<operand_type> *GetRmMem(Bit8u rm_mod) {
        auto mod = static_cast<Bit8u>(rm_mod & 0xc0u);
        auto rm = static_cast<Bit8u>(rm_mod & 0x7u);
        return GetRM_Memory<operand_type>(rm, mod);
    }

    template<typename data_type> data_type GetImmediate() {
        return GetImmediateNumber<data_type>();
    }

protected:

    template<typename operand_type>
    operand_type GetImmediateNumber() {
        return Fetch<operand_type>();
    }
    inline PhysPt GetRM_Sib(Bit8u mod);
    template<typename address_type> inline PhysPt GetRM_MemoryAddress(Bit8u rm, Bit8u mod);
    template<typename operand_type> inline PhysPt GetMemoryAddress(operand_type operand);

    template<typename operand_type> inline MemoryReference<operand_type> *GetRM_Memory(Bit8u rm, Bit8u mod) {
        PhysPt address = Is32BitAddressMode() ? GetRM_MemoryAddress<Bit32u>(rm, mod) : GetRM_MemoryAddress<Bit16u>(rm, mod);
        return GetMemoryReference<operand_type>(address);
    }

    template<typename operand_type> inline GeneralReference<operand_type> *GetGeneralRegister(Bit8u reg);
    template<typename operand_type> inline GeneralReference<operand_type> *GetSegmentRegister(Bit8u reg);

    template<typename operand_type> inline MemoryReference<operand_type> *GetMemoryReference(PhysPt address) {
        static MemoryReference<operand_type> sMemoryAddress;
        sMemoryAddress.SetAddress(address);
        return &sMemoryAddress;
    }

protected:
    inline PhysPt GetIP() {
        return (cseip - SegBase(cs));
    }
    
    inline void DoPrefixSegment(SegNames seg_name) {
        BaseDS = SegBase(seg_name);
        BaseSS = SegBase(seg_name);
        base_val_ds = seg_name;
    }

    template<typename data_type>
    inline data_type Fetch() {
        auto temp = ReadMemory<data_type>(cseip);
        cseip += sizeof(temp);
        return temp;
    }

    inline void RunException() {
        CPU_Exception(cpu.exception.which,cpu.exception.error);
    }

    inline void RaiseException(Bitu which) {
        CPU_Exception(which);
    }

    inline PhysPt GetDirectEffectiveAddress() {
        PhysPt eaa;
        if (Is32BitAddressMode()) {
            eaa = BaseDS + Fetch<Bit32u>();
        } else {
            eaa = BaseDS + Fetch<Bit16u>();
        }
        return eaa;
    }

	template<typename operand_type> void JumpCondition(Bit32u condition, operand_type offset) {
		SaveIP();
		if (condition) {
			reg_ip += offset;
			m_bRestoreIP = false;
		}
	}
protected:
    template<typename data_type> inline bool Do_ROL(GeneralReference<data_type> *destination, Bit8u source);
    template<typename data_type> inline bool Do_ROR(GeneralReference<data_type> *destination, Bit8u source);
    template<typename data_type> inline bool Do_RCL(GeneralReference<data_type> *destination, Bit8u source);
    template<typename data_type> inline bool Do_RCR(GeneralReference<data_type> *destination, Bit8u source);
    template<typename data_type> inline bool Do_SHL(GeneralReference<data_type> *destination, Bit8u source);
    template<typename data_type> inline bool Do_SHR(GeneralReference<data_type> *destination, Bit8u source);
    template<typename data_type> inline bool Do_SAR(GeneralReference<data_type> *destination, Bit8u source);

    static GeneralRegister<Bit8u> **mGeneralRegister8Bit;
    static GeneralRegister<Bit16u> **mGeneralRegister16Bit;
    static GeneralRegister<Bit32u> **mGeneralRegister32Bit;
    static SegmentRegister<Bit16u> **mSegmentRegister16Bit;
    static Bit32u SIBZero;
    static Bit32u *SIBIndex[8];
    static constexpr Bit32u AddrMaskTable[2] = {0x0000ffff, 0xffffffff};

public:
    typedef std::function<void(PhysPt si_base, PhysPt di_base, Bitu &si_index, Bitu &di_index, Bitu &count, Bits add_mask, Bits add_index)> string_func;
    template<typename data_type> inline void DO_CMP(data_type op1, data_type op2);

    template<typename data_type> void R_OUTS(PhysPt si_base, PhysPt di_base, Bitu &si_index, Bitu &di_index, Bitu &count, Bits add_mask, Bits add_index) {
        add_index *= sizeof(data_type);
        Bit16u port = GetGenRegister<Bit16u>(I_DX);
        for (; count > 0; count--) {
            IO_Write<data_type>(port, ReadMemory<data_type>(si_base + si_index));
            si_index = (si_index + add_index) & add_mask;
        }
    }

    template<typename data_type> void R_INS(PhysPt si_base, PhysPt di_base, Bitu &si_index, Bitu &di_index, Bitu &count, Bits add_mask, Bits add_index) {
        add_index *= sizeof(data_type);
        Bit16u port = GetGenRegister<Bit16u>(I_DX);
        for (; count > 0; count--) {
            WriteMemory<data_type>(di_base + di_index, IO_Read<data_type>(port));
            di_index = (di_index + add_index) & add_mask;
        }
    }

    template<typename data_type> void R_STOS(PhysPt si_base, PhysPt di_base, Bitu &si_index, Bitu &di_index, Bitu &count, Bits add_mask, Bits add_index) {
        add_index *= sizeof(data_type);
        for (; count > 0; count--) {
            WriteMemory<data_type>(di_base + di_index, GetGenRegister<data_type>(I_AX));
            di_index = (di_index + add_index) & add_mask;
        }
    }

    template<typename data_type> void R_MOVS(PhysPt si_base, PhysPt di_base, Bitu &si_index, Bitu &di_index, Bitu &count, Bits add_mask, Bits add_index) {
        add_index *= sizeof(data_type);
        for (; count > 0; count--) {
            data_type val = ReadMemory<data_type>(si_base + si_index);
            WriteMemory<data_type>(di_base + di_index, val);
            di_index = (di_index + add_index) & add_mask;
            si_index = (si_index + add_index) & add_mask;
        }
    }

    template<typename data_type> void R_LODS(PhysPt si_base, PhysPt di_base, Bitu &si_index, Bitu &di_index, Bitu &count, Bits add_mask, Bits add_index) {
        add_index *= sizeof(data_type);
        for (; count > 0; count--) {
            GetGenRegister<data_type>(I_AX) = ReadMemory<data_type>(si_base + si_index);
            si_index = (si_index + add_index) & add_mask;
        }
    }

    template<typename data_type> void R_SCAS(PhysPt si_base, PhysPt di_base, Bitu &si_index, Bitu &di_index, Bitu &count, Bits add_mask, Bits add_index) {
        add_index *= sizeof(data_type);
        data_type val2;
        data_type val1 = GetGenRegister<data_type>(I_AX);
        for (; count > 0;) {
            count--; CPU_Cycles--;
            val2 = ReadMemory<data_type>(di_base + di_index);
            di_index = (di_index + add_index) & add_mask;
            if ((val1 == val2) != Is_REP_Zero())
                break;
        }
        DO_CMP<data_type>(val1, val2);
    }

    template<typename data_type> void R_CMPS(PhysPt si_base, PhysPt di_base, Bitu &si_index, Bitu &di_index, Bitu &count, Bits add_mask, Bits add_index) {
        add_index *= sizeof(data_type);
        data_type val1;
        data_type val2;
        for (; count > 0;) {
            count--; CPU_Cycles--;
            val1 = ReadMemory<data_type>(si_base + si_index);
            val2 = ReadMemory<data_type>(di_base + di_index);
            si_index = (si_index + add_index) & add_mask;
            di_index = (di_index + add_index) & add_mask;
            if ((val1 == val2) != Is_REP_Zero())
                break;
        }
        DO_CMP<data_type>(val1, val2);
    }

    void DoString(string_func func, bool interruptable) {
        PhysPt  si_base, di_base;
        Bitu	si_index, di_index;
        Bitu	add_mask;
        Bitu	count, count_left;
        Bits	add_index;

        si_base = BaseDS;
        di_base = SegBase(es);
        add_mask = Is32BitAddressMode() ? 0xffffffff : 0x0000ffff;
        si_index = reg_esi & add_mask;
        di_index = reg_edi & add_mask;
        count = reg_ecx & add_mask;
        if (!HasPrefixRepeat()) {
            count = 1;
        } else {
            CPU_Cycles++;
            /* Calculate amount of ops to do before cycles run out */
            if ((count > (Bitu) CPU_Cycles) && !interruptable) {
                count_left = count - CPU_Cycles;
                count = CPU_Cycles;
                CPU_Cycles = 0;
                LoadIP();        //RESET IP to the start
            } else {
                /* Won't interrupt scas and cmps instruction since they can interrupt themselves */
                if ((count <= 1) && (CPU_Cycles <= 1))
                    CPU_Cycles--;
                else if (interruptable)
                    CPU_Cycles -= count;
                count_left = 0;
            }
        }
        add_index = cpu.direction;
        if (count) {
            func(si_base, di_base, si_index, di_index, count, add_mask, add_index);
        }
        /* Clean up after certain amount of instructions */
        reg_esi &= (~add_mask);
        reg_esi |= (si_index & add_mask);
        reg_edi &= (~add_mask);
        reg_edi |= (di_index & add_mask);
        reg_edi |= (di_index & add_mask);
        if (HasPrefixRepeat()) {
            count += count_left;
            reg_ecx &= (~add_mask);
            reg_ecx |= (count & add_mask);
        }
    }

};

template<> inline void CpuRunnerLLVMBase::DO_CMP<Bit8u>(Bit8u op1, Bit8u op2) {
    lf_var1b = op1;
    lf_var2b = op2;
    lf_resb = lf_var1b - lf_var2b;
    lflags.type = t_CMPb;
    FillFlags();
}

template<> inline void CpuRunnerLLVMBase::DO_CMP<Bit16u>(Bit16u op1, Bit16u op2) {
    lf_var1w = op1;
    lf_var2w = op2;
    lf_resw = lf_var1w - lf_var2w;
    lflags.type = t_CMPw;
    FillFlags();
}

template<> inline void CpuRunnerLLVMBase::DO_CMP<Bit32u>(Bit32u op1, Bit32u op2) {
    lf_var1d = op1;
    lf_var2d = op2;
    lf_resd = lf_var1d - lf_var2d;
    lflags.type = t_CMPd;
    FillFlags();
}

inline PhysPt CpuRunnerLLVMBase::GetRM_Sib(Bit8u mode) {
    auto sib = Fetch<Bit8u>();
    PhysPt base = 0;
    switch (sib & 0x07u) {
        case 0:    /* EAX Base */
            base = BaseDS + reg_eax;
            break;
        case 1:    /* ECX Base */
            base = BaseDS + reg_ecx;
            break;
        case 2:    /* EDX Base */
            base = BaseDS + reg_edx;
            break;
        case 3:    /* EBX Base */
            base = BaseDS + reg_ebx;
            break;
        case 4:    /* ESP Base */
            base = BaseSS + reg_esp;
            break;
        case 5:    /* #1 Base */
            if (!mode) {
                base = BaseDS + Fetch<Bit32u>();
                break;
            } else {
                base = BaseSS + reg_ebp;
                break;
            }
        case 6:    /* ESI Base */
            base = BaseDS + reg_esi;
            break;
        case 7:    /* EDI Base */
            base = BaseDS + reg_edi;
            break;
        default:
            throw IllegalInstructionException();
    }
    base += *SIBIndex[(sib >> 3u) & 7u] << (sib >> 6u);
    return base;
}

template<> inline PhysPt CpuRunnerLLVMBase::GetRM_MemoryAddress<Bit16u>(Bit8u rm, Bit8u mod) {
    Bit16u base = 0;
    Bit16s offset = 0;
    PhysPt segment = BaseDS;
    switch (mod) {
        case 0x00:
            break;
        case 0x40:
            offset = static_cast<Bit8s>(Fetch<Bit8u>());
            break;
        case 0x80:
            offset = static_cast<Bit16s>(Fetch<Bit16u>());
            break;
        default:
            throw IllegalInstructionException();
    }
    switch (rm) {
        case 0x00:
            base = reg_bx + reg_si;
            break;
        case 0x01:
            base = reg_bx + reg_di;
            break;
        case 0x02:
            segment = BaseSS;
            base = reg_bp + reg_si;
            break;
        case 0x03:
            segment = BaseSS;
            base = reg_bp + reg_di;
            break;
        case 0x04:
            base = reg_si;
            break;
        case 0x05:
            base = reg_di;
            break;
        case 0x06:
            if (mod == 0x00) {
                base = Fetch<Bit16u>();
            } else {
                segment = BaseSS;
                base = reg_bp;
            }
            break;
        case 0x07:
            base = reg_bx;
            break;
        default:
            throw IllegalInstructionException();
    }
    return segment + (Bit16u) (base + offset);
}

template<> inline PhysPt CpuRunnerLLVMBase::GetRM_MemoryAddress<Bit32u>(Bit8u rm, Bit8u mod) {
    Bit32u base = 0;
    Bit32s offset = 0;
    switch (rm) {
        case 0x00:
            base = BaseDS + reg_eax;
            break;
        case 0x01:
            base = BaseDS + reg_ecx;
            break;
        case 0x02:
            base = BaseDS + reg_edx;
            break;
        case 0x03:
            base = BaseDS + reg_ebx;
            break;
        case 0x04:
            base = GetRM_Sib(mod >> 6);
            break;
        case 0x05:
            if (mod == 0x00) {
                base = BaseDS + Fetch<Bit32u>();
            } else {
                base = BaseSS + reg_ebp;
            }
            break;
        case 0x06:
            base = BaseDS + reg_esi;
            break;
        case 0x07:
            base = BaseDS + reg_edi;
            break;
        default:
            throw IllegalInstructionException();
    }
    switch (mod) {
        case 0x00:
            break;
        case 0x40:
            offset = static_cast<Bit8s>(Fetch<Bit8u>());
            break;
        case 0x80:
            offset = static_cast<Bit32s>(Fetch<Bit32u>());
            break;
        default:
            throw IllegalInstructionException();
    }
    return base + offset;
}

template<> inline GeneralReference<Bit8u> *CpuRunnerLLVMBase::GetGeneralRegister<Bit8u>(Bit8u reg) {
    if (!mGeneralRegister8Bit) {
        mGeneralRegister8Bit = new GeneralRegister<Bit8u> *[8];
        mGeneralRegister8Bit[0] = new GeneralRegister<Bit8u>(reg_al);
        mGeneralRegister8Bit[1] = new GeneralRegister<Bit8u>(reg_cl);
        mGeneralRegister8Bit[2] = new GeneralRegister<Bit8u>(reg_dl);
        mGeneralRegister8Bit[3] = new GeneralRegister<Bit8u>(reg_bl);
        mGeneralRegister8Bit[4] = new GeneralRegister<Bit8u>(reg_ah);
        mGeneralRegister8Bit[5] = new GeneralRegister<Bit8u>(reg_ch);
        mGeneralRegister8Bit[6] = new GeneralRegister<Bit8u>(reg_dh);
        mGeneralRegister8Bit[7] = new GeneralRegister<Bit8u>(reg_bh);
    }
    return mGeneralRegister8Bit[reg];
}

template<> inline GeneralReference<Bit16u> *CpuRunnerLLVMBase::GetGeneralRegister<Bit16u>(Bit8u reg) {
    if (!mGeneralRegister16Bit) {
        mGeneralRegister16Bit = new GeneralRegister<Bit16u> *[8];
        mGeneralRegister16Bit[0] = new GeneralRegister<Bit16u>(reg_ax);
        mGeneralRegister16Bit[1] = new GeneralRegister<Bit16u>(reg_cx);
        mGeneralRegister16Bit[2] = new GeneralRegister<Bit16u>(reg_dx);
        mGeneralRegister16Bit[3] = new GeneralRegister<Bit16u>(reg_bx);
        mGeneralRegister16Bit[4] = new GeneralRegister<Bit16u>(reg_sp);
        mGeneralRegister16Bit[5] = new GeneralRegister<Bit16u>(reg_bp);
        mGeneralRegister16Bit[6] = new GeneralRegister<Bit16u>(reg_si);
        mGeneralRegister16Bit[7] = new GeneralRegister<Bit16u>(reg_di);
    }
    return mGeneralRegister16Bit[reg];
}

template<> inline GeneralReference<Bit32u> *CpuRunnerLLVMBase::GetGeneralRegister<Bit32u>(Bit8u reg) {
    if (!mGeneralRegister32Bit) {
        mGeneralRegister32Bit = new GeneralRegister<Bit32u> *[8];
        mGeneralRegister32Bit[0] = new GeneralRegister<Bit32u>(reg_eax);
        mGeneralRegister32Bit[1] = new GeneralRegister<Bit32u>(reg_ecx);
        mGeneralRegister32Bit[2] = new GeneralRegister<Bit32u>(reg_edx);
        mGeneralRegister32Bit[3] = new GeneralRegister<Bit32u>(reg_ebx);
        mGeneralRegister32Bit[4] = new GeneralRegister<Bit32u>(reg_esp);
        mGeneralRegister32Bit[5] = new GeneralRegister<Bit32u>(reg_ebp);
        mGeneralRegister32Bit[6] = new GeneralRegister<Bit32u>(reg_esi);
        mGeneralRegister32Bit[7] = new GeneralRegister<Bit32u>(reg_edi);
    }
    return mGeneralRegister32Bit[reg];
}

template<> inline GeneralReference<Bit16u> *CpuRunnerLLVMBase::GetSegmentRegister<Bit16u>(Bit8u reg) {
    if (!mSegmentRegister16Bit) {
        mSegmentRegister16Bit = new SegmentRegister<Bit16u> *[8];
        mSegmentRegister16Bit[0] = new SegmentRegister<Bit16u>(es);
        mSegmentRegister16Bit[1] = new SegmentRegister<Bit16u>(cs);
        mSegmentRegister16Bit[2] = new SegmentRegister<Bit16u>(ss);
        mSegmentRegister16Bit[3] = new SegmentRegister<Bit16u>(ds);
        mSegmentRegister16Bit[4] = new SegmentRegister<Bit16u>(fs);
        mSegmentRegister16Bit[5] = new SegmentRegister<Bit16u>(gs);
        mSegmentRegister16Bit[6] = nullptr;
        mSegmentRegister16Bit[7] = nullptr;
    }
    return mSegmentRegister16Bit[reg];
}

/*
 ROL
*/
template<> inline bool CpuRunnerLLVMBase::Do_ROL<Bit8u>(GeneralReference<Bit8u> *destination, Bit8u source) {
    Bit8u op1 = destination->Read();
    if (!(source & 0x7)) {
        if (source & 0x18) {
            FillFlagsNoCFOF();
            SETFLAGBIT(CF, op1 & 1);
            SETFLAGBIT(OF, (op1 & 1) ^ (op1 >> 7));
        }
        return true;
    }
    FillFlagsNoCFOF();
    lf_var1b = op1;
    lf_var2b = source & 0x07u;
    lf_resb = (lf_var1b << lf_var2b) |
        (lf_var1b >> (8 - lf_var2b));
    destination->Write(lf_resb);
    SETFLAGBIT(CF, lf_resb & 1);
    SETFLAGBIT(OF, (lf_resb & 1) ^ (lf_resb >> 7));
    return true;
}

template<> inline bool CpuRunnerLLVMBase::Do_ROL<Bit16u>(GeneralReference<Bit16u> *destination, Bit8u source) {
    Bit16u op1 = destination->Read();
    if (!(source & 0xf)) {
        if (source & 0x10) {
            FillFlagsNoCFOF();
            SETFLAGBIT(CF, op1 & 1);
            SETFLAGBIT(OF, (op1 & 1) ^ (op1 >> 15));
        }
        return true;
    }
    FillFlagsNoCFOF();
    lf_var1w = op1;
    lf_var2b = source & 0x0fu;
    lf_resw = (lf_var1w << lf_var2b) |
        (lf_var1w >> (16 - lf_var2b));
    destination->Write(lf_resw);
    SETFLAGBIT(CF, lf_resw & 1);
    SETFLAGBIT(OF, (lf_resw & 1) ^ (lf_resw >> 15));
    return true;
}

template<> inline bool CpuRunnerLLVMBase::Do_ROL<Bit32u>(GeneralReference<Bit32u> *destination, Bit8u source) {
    Bit32u op1 = destination->Read();
    lf_var1d = destination->Read();
    if (!source) {
        return true;
    }
    FillFlagsNoCFOF();
    lf_var1d = op1;
    lf_var2b = source;
    lf_resd = (lf_var1d << lf_var2b) |
        (lf_var1d >> (32 - lf_var2b));
    destination->Write(lf_resd);
    SETFLAGBIT(CF, lf_resd & 1);
    SETFLAGBIT(OF, (lf_resd & 1) ^ (lf_resd >> 31));
    return true;
}

/*
 ROR
*/
template<> inline bool CpuRunnerLLVMBase::Do_ROR(GeneralReference<Bit8u> *destination, Bit8u source) {
    Bit8u op1 = destination->Read();
    if (!(source & 0x7)) {
        if (source & 0x18) {
            FillFlagsNoCFOF();
            SETFLAGBIT(CF, op1 >> 7);
            SETFLAGBIT(OF, (op1 >> 7) ^ ((op1 >> 6) & 1));
        }
        return true;
    }
    FillFlagsNoCFOF();
    lf_var1b = op1;
    lf_var2b = source & 0x07;
    lf_resb = (lf_var1b >> lf_var2b) |
        (lf_var1b << (8 - lf_var2b));
    destination->Write(lf_resb);
    SETFLAGBIT(CF, lf_resb & 0x80);
    SETFLAGBIT(OF, (lf_resb ^ (lf_resb << 1)) & 0x80);
    return true;
}

template<> inline bool CpuRunnerLLVMBase::Do_ROR(GeneralReference<Bit16u> *destination, Bit8u source) {
    Bit16u op1 = destination->Read();
    if (!(source & 0xf)) {
        if (source & 0x10) {
            FillFlagsNoCFOF();
            SETFLAGBIT(CF, op1 >> 15);
            SETFLAGBIT(OF, (op1 >> 15) ^ ((op1 >> 14) & 1));
        }
        return true;
    }
    FillFlagsNoCFOF();
    lf_var1w = op1;
    lf_var2b = source & 0x0fu;
    lf_resw = (lf_var1w >> lf_var2b) |
        (lf_var1w << (16 - lf_var2b));
    destination->Write(lf_resw);
    SETFLAGBIT(CF, lf_resw & 0x8000);
    SETFLAGBIT(OF, (lf_resw ^ (lf_resw << 1)) & 0x8000);
    return true;
}

template<> inline bool CpuRunnerLLVMBase::Do_ROR(GeneralReference<Bit32u> *destination, Bit8u source) {
    if (!source) {
        return true;
    }
    FillFlagsNoCFOF();
    lf_var1d = destination->Read();
    lf_var2b = source;
    lf_resd = (lf_var1d >> lf_var2b) |
        (lf_var1d << (32 - lf_var2b));
    destination->Write(lf_resd);
    SETFLAGBIT(CF, lf_resd & 0x80000000);
    SETFLAGBIT(OF, (lf_resd ^ (lf_resd << 1)) & 0x80000000);
    return true;
}

/*
 RCL
*/
template<> inline bool CpuRunnerLLVMBase::Do_RCL(GeneralReference<Bit8u> *destination, Bit8u source) {
    Bit8u cf = (Bit8u) FillFlags() & 0x1;
    lf_var1b = destination->Read();
    lf_var2b = source % 9;
    lf_resb = (lf_var1b << lf_var2b) |
        (cf << (lf_var2b - 1)) |
        (lf_var1b >> (9 - lf_var2b));
    destination->Write(lf_resb);
    SETFLAGBIT(CF, ((lf_var1b >> (8 - lf_var2b)) & 1));
    SETFLAGBIT(OF, (reg_flags & 1) ^ (lf_resb >> 7));
    return true;
}

template<> inline bool CpuRunnerLLVMBase::Do_RCL(GeneralReference<Bit16u> *destination, Bit8u source) {
    auto cf = (Bit16u) (FillFlags() & 0x1);
    lf_var1w = destination->Read();
    lf_var2b = source % 17;
    lf_resw = (lf_var1w << lf_var2b) |
        (cf << (lf_var2b - 1)) |
        (lf_var1w >> (17 - lf_var2b));
    destination->Write(lf_resw);
    SETFLAGBIT(CF, ((lf_var1w >> (16 - lf_var2b)) & 1));
    SETFLAGBIT(OF, (reg_flags & 1) ^ (lf_resw >> 15));
    return true;
}

template<> inline bool CpuRunnerLLVMBase::Do_RCL(GeneralReference<Bit32u> *destination, Bit8u source) {
    auto cf = (Bit32u) (FillFlags() & 0x1);
    lf_var1d = destination->Read();
    lf_var2b = source;
    if (lf_var2b == 1) {
        lf_resd = (lf_var1d << 1) | cf;
    } else {
        lf_resd = (lf_var1d << lf_var2b) |
            (cf << (lf_var2b - 1)) |
            (lf_var1d >> (33 - lf_var2b));
    }
    destination->Write(lf_resd);
    SETFLAGBIT(CF, ((lf_var1d >> (32 - lf_var2b)) & 1));
    SETFLAGBIT(OF, (reg_flags & 1) ^ (lf_resd >> 31));
    return true;
}

/*
 RCR
*/
template<> inline bool CpuRunnerLLVMBase::Do_RCR(GeneralReference<Bit8u> *destination, Bit8u source) {
    if (source % 9) {
        Bit8u cf = (Bit8u) FillFlags() & 0x1;
        lf_var1b = destination->Read();
        lf_var2b = source % 9;
        lf_resb = (lf_var1b >> lf_var2b) |
            (cf << (8 - lf_var2b)) |
            (lf_var1b << (9 - lf_var2b));
        destination->Write(lf_resb);
        SETFLAGBIT(CF, (lf_var1b >> (lf_var2b - 1)) & 1);
        SETFLAGBIT(OF, (lf_resb ^ (lf_resb << 1)) & 0x80);
    }
    return true;
}

template<> inline bool CpuRunnerLLVMBase::Do_RCR(GeneralReference<Bit16u> *destination, Bit8u source) {
    if (source % 17) {
        auto cf = (Bit16u) (FillFlags() & 0x1);
        lf_var1w = destination->Read();
        lf_var2b = source % 17;
        lf_resw = (lf_var1w >> lf_var2b) |
            (cf << (16 - lf_var2b)) |
            (lf_var1w << (17 - lf_var2b));
        destination->Write(lf_resw);
        SETFLAGBIT(CF, (lf_var1w >> (lf_var2b - 1)) & 1);
        SETFLAGBIT(OF, (lf_resw ^ (lf_resw << 1)) & 0x8000);
    }
    return true;
}

template<> inline bool CpuRunnerLLVMBase::Do_RCR(GeneralReference<Bit32u> *destination, Bit8u source) {
    if (source) {
        auto cf = (Bit32u) (FillFlags() & 0x1);
        lf_var1w = destination->Read();
        lf_var2b = source;
        if (lf_var2b == 1) {
            lf_resd = lf_var1d >> 1 | cf << 31;
        } else {
            lf_resd = (lf_var1d >> lf_var2b) |
                (cf << (32 - lf_var2b)) |
                (lf_var1d << (33 - lf_var2b));
        }
        destination->Write(lf_resw);
        SETFLAGBIT(CF, (lf_var1d >> (lf_var2b - 1)) & 1);
        SETFLAGBIT(OF, (lf_resd ^ (lf_resd << 1)) & 0x80000000);
    }
    return true;
}

/*
 SHL
*/
template<> inline bool CpuRunnerLLVMBase::Do_SHL(GeneralReference<Bit8u> *destination, Bit8u source) {
    if (source) {
        lf_var1b = destination->Read();
        lf_var2b = source;
        lf_resb = lf_var1b << lf_var2b;
        destination->Write(lf_resb);
        lflags.type = t_SHLb;
    }
    return true;
}

template<> inline bool CpuRunnerLLVMBase::Do_SHL(GeneralReference<Bit16u> *destination, Bit8u source) {
    if (source) {
        lf_var1w = destination->Read();
        lf_var2b = source;
        lf_resw = lf_var1w << lf_var2b;
        destination->Write(lf_resw);
        lflags.type = t_SHLw;
    }
    return true;
}

template<> inline bool CpuRunnerLLVMBase::Do_SHL(GeneralReference<Bit32u> *destination, Bit8u source) {
    if (source) {
        lf_var1d = destination->Read();
        lf_var2b = source;
        lf_resd = lf_var1d << lf_var2b;
        destination->Write(lf_resd);
        lflags.type = t_SHLd;
    }
    return true;
}

/*
 SHR
*/
template<> inline bool CpuRunnerLLVMBase::Do_SHR(GeneralReference<Bit8u> *destination, Bit8u source) {
    if (source) {
        lf_var1b = destination->Read();
        lf_var2b = source;
        lf_resb = lf_var1b >> lf_var2b;
        destination->Write(lf_resb);
        lflags.type = t_SHRb;
    }
    return true;
}

template<> inline bool CpuRunnerLLVMBase::Do_SHR(GeneralReference<Bit16u> *destination, Bit8u source) {
    if (source) {
        lf_var1w = destination->Read();
        lf_var2b = source;
        lf_resw = lf_var1w >> lf_var2b;
        destination->Write(lf_resw);
        lflags.type = t_SHRw;
    }
    return true;
}

template<> inline bool CpuRunnerLLVMBase::Do_SHR(GeneralReference<Bit32u> *destination, Bit8u source) {
    if (source) {
        lf_var1d = destination->Read();
        lf_var2b = source;
        lf_resd = lf_var1d >> lf_var2b;
        destination->Write(lf_resd);
        lflags.type = t_SHRd;
    }
    return true;
}

/*
 SAR
*/
template<> inline bool CpuRunnerLLVMBase::Do_SAR(GeneralReference<Bit8u> *destination, Bit8u source) {
    if (source) {
        lf_var1b = destination->Read();
        lf_var2b = source;
        if (lf_var1b & 0x80) {
            lf_resb = (lf_var1b >> lf_var2b) | (0xff << (8 - lf_var2b));
        } else {
            lf_resb = lf_var1b >> lf_var2b;
        }
        destination->Write(lf_resb);
        lflags.type = t_SARb;
    }
    return true;
}

template<> inline bool CpuRunnerLLVMBase::Do_SAR(GeneralReference<Bit16u> *destination, Bit8u source) {
    if (source) {
        lf_var1w = destination->Read();
        lf_var2b = source;

        if (lf_var2b > 16)
            lf_var2b = 16;

        if (lf_var1w & 0x8000) {
            lf_resw = (lf_var1w >> lf_var2b) |
                (0xffff << (16 - lf_var2b));
        } else {
            lf_resw = lf_var1w >> lf_var2b;
        }
        destination->Write(lf_resw);
        lflags.type = t_SARw;
    }
    return true;
}

template<> inline bool CpuRunnerLLVMBase::Do_SAR(GeneralReference<Bit32u> *destination, Bit8u source) {
    if (source) {
        lf_var1d = destination->Read();
        lf_var2b = source;
        if (lf_var1d & 0x80000000) {
            lf_resd = (lf_var1d >> lf_var2b) |
                (0xffffffff << (32 - lf_var2b));
        } else {
            lf_resd = lf_var1d >> lf_var2b;
        }
        destination->Write(lf_resd);
        lflags.type = t_SARd;
    }
    return true;
}

}

#endif //PROJECT_CORE_LLVM_COMMON_H
