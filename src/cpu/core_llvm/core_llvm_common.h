//
// Created by 张航 on 2018/5/15.
//

#ifndef PROJECT_CORE_LLVM_COMMON_H
#define PROJECT_CORE_LLVM_COMMON_H

#include <exception>
#include "cpu.h"
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

#pragma pack(push, 1)
struct Bit48u{
    Bit16u w_value;
    Bit32u d_value;
    Bit48u(Bit16u w, Bit32u d) {
        w_value = w;
        d_value = d;
    }
};
#pragma pack(pop)

template<typename operand_type>
class GeneralReference {
public:
    virtual inline operand_type Read() = 0;
    virtual inline void Write(operand_type value) = 0;
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

protected:
    operand_type &mRegister;
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

template<> inline Bit48u ReadMemory<Bit48u>(PhysPt address) {
	Bit16u w = mem_readw(address);
	Bit32u d = mem_readw(address + sizeof(w));
	return Bit48u(w, d);
}

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

template<> inline void WriteMemory<Bit48u>(PhysPt address, Bit48u value) {
	mem_writew(address, value.w_value);
	mem_writed(address + sizeof(value.w_value), value.d_value);
}

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

protected:
    operand_type &mSegmentRegister;
    operand_type &mGeneralRegister;
};

class IllegalInstructionException : public std::exception {
public:
    const char* what() const _NOEXCEPT {
        return "Illegal Instruction";
    }
};

class CpuRunnerLLVMBase {

public:
    PhysPt cseip;
    PhysPt base_ds, base_ss;
    SegNames base_val_ds;

    union {
        struct {
            Bitu segment_override;
            Bitu rep;
            Bitu operand_size_override;
            Bitu address_size_override;
        } prefixes;
        Bit32u all_prefix;
    } option_prefix;
    Bit8u mandatory_prefix;

    inline void SaveIP() {
        reg_eip = GetIP();
    }

    inline void LoadIP() {
        cseip = (SegBase(cs) + reg_eip);
    }

public:

    bool Is32BitAddressMode() const {
        return false;
    }

    bool Is32BitOperandMode() const {
        return false;
    }

    template<typename operand_type> GeneralReference<operand_type> *GetRmMod(Bit8u rm_mod) {
        auto mod = static_cast<Bit8u>(rm_mod & 0xc0u);
        auto rm = static_cast<Bit8u>(rm_mod & 0x38u);
        if (mod >= 0xc0) {
            // Refer to a register
            return GetGeneralRegister<operand_type>(rm >> 3);
        } else {
            // Refer to a memory
            return GetRM_Memory<operand_type>(rm, mod);
        }
    }

    template<typename operand_type> GeneralReference<operand_type> *GetRmRm(Bit8u rm_mod) {
        auto rm = static_cast<Bit8u>(rm_mod & 0x38u);
        return GetGeneralRegister<operand_type>(rm >> 3);
    }

    template<typename operand_type> GeneralReference<operand_type> *GetRmReg(Bit8u rm_mod) {
        auto reg = static_cast<Bit8u>(rm_mod & 0x07u);
        return GetGeneralRegister<operand_type>(reg);
    }

    template<typename operand_type> GeneralReference<operand_type> *GetRmMem(Bit8u rm_mod) {
        auto mod = static_cast<Bit8u>(rm_mod & 0xc0u);
        auto rm = static_cast<Bit8u>(rm_mod & 0x38u);
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

    template<typename operand_type> inline MemoryReference<operand_type> *GetMemoryReference(PhysPt address) {
        static MemoryReference<operand_type> sMemoryAddress;
        sMemoryAddress.SetAddress(address);
        return &sMemoryAddress;
    }

protected:
    inline PhysPt GetIP() {
        return (cseip - SegBase(cs));
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

    static GeneralRegister<Bit8u> **mGeneralRegister8Bit;
    static GeneralRegister<Bit16u> **mGeneralRegister16Bit;
    static GeneralRegister<Bit32u> **mGeneralRegister32Bit;
    static Bit32u SIBZero;
    static Bit32u *SIBIndex[8];
};

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
    switch (rm) {
        case 0x40:offset = static_cast<Bit8s>(Fetch<Bit8u>());
            break;
        case 0x80:offset = static_cast<Bit16s>(Fetch<Bit16u>());
            break;
        default:
            throw IllegalInstructionException();
    }
    switch (mod) {
        case 0x00:base = reg_bx + reg_si;
            break;
        case 0x01:base = reg_bx + reg_di;
            break;
        case 0x02:base = reg_bp + reg_si;
            break;
        case 0x03:base = reg_bp + reg_di;
            break;
        case 0x04:base = reg_si;
            break;
        case 0x05:base = reg_di;
            break;
        case 0x06:base = Fetch<Bit16u>();
            break;
        case 0x07:base = reg_bx;
            break;
        default:
            throw IllegalInstructionException();
    }
    return BaseDS + (Bit16u) (base + offset);
}

template<> inline PhysPt CpuRunnerLLVMBase::GetRM_MemoryAddress<Bit32u>(Bit8u rm, Bit8u mod) {
    Bit32u base = 0;
    Bit32s offset = 0;
    switch (mod) {
        case 0x00:base = reg_eax;
            break;
        case 0x01:base = reg_ecx;
            break;
        case 0x02:base = reg_edx;
            break;
        case 0x03:base = reg_ebx;
            break;
        case 0x04:base = GetRM_Sib(mod);
            break;
        case 0x05:base = Fetch<Bit32u>();
            break;
        case 0x06:base = reg_esi;
            break;
        case 0x07:base = reg_edi;
            break;
        default:
            throw IllegalInstructionException();
    }
    switch (rm) {
        case 0x40:offset = static_cast<Bit8s>(Fetch<Bit8u>());
            break;
        case 0x80:offset = static_cast<Bit32s>(Fetch<Bit32u>());
            break;
        default:
            throw IllegalInstructionException();
    }
    return BaseDS + base + offset;
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

}

#endif //PROJECT_CORE_LLVM_COMMON_H
