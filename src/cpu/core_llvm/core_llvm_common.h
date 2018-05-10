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

#define SegBase(c)    SegPhys(c)
#define BaseDS        base_ds
#define BaseSS        base_ss

namespace core_llvm {

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

	protected:
		inline PhysPt GetIP() {
			return (cseip - SegBase(cs));
		}

		inline Bit8u Fetchb() {
			Bit8u temp = LoadMb(cseip);
			cseip += 1;
			return temp;
		}

		inline Bit16u Fetchw() {
			Bit16u temp = LoadMw(cseip);
			cseip += 2;
			return temp;
		}

		inline Bit32u Fetchd() {
			Bit32u temp = LoadMd(cseip);
			cseip += 4;
			return temp;
		}
	};



}

#endif //PROJECT_CORE_LLVM_COMMON_H
