#include "core_llvm_runner.h"
namespace core_llvm {


	inline bool CpuRunnerLLVM::handler_pr26() {
		return true;
	};

	inline bool CpuRunnerLLVM::handler_pr2E() {
		return true;
	};

	inline bool CpuRunnerLLVM::handler_pr36() {
		return true;
	};

	inline bool CpuRunnerLLVM::handler_pr3E() {
		return true;
	};

	inline bool CpuRunnerLLVM::handler_pr64() {
		return true;
	};

	inline bool CpuRunnerLLVM::handler_pr65() {
		return true;
	};

	inline bool CpuRunnerLLVM::handler_pr66() {
		return true;
	};

	inline bool CpuRunnerLLVM::handler_pr67() {
		return true;
	};

	inline bool CpuRunnerLLVM::handler_prF0() {
		return true;
	};

	inline bool CpuRunnerLLVM::handler_prF2() {
		return true;
	};

	inline bool CpuRunnerLLVM::handler_prF3() {
		return true;
	};

	/* _00_ADD_Eb_Gb
	 description: Add
	*/
	inline bool CpuRunnerLLVM::handler_in_00_ADD_Eb_Gb(Bit8u insb) {
		return true;
	}

	/* _01_ADD_Evqp_Gvqp
	 description: Add
	*/
	inline bool CpuRunnerLLVM::handler_in_01_ADD_Evqp_Gvqp(Bit8u insb) {
		return true;
	}

	/* _02_ADD_Gb_Eb
	 description: Add
	*/
	inline bool CpuRunnerLLVM::handler_in_02_ADD_Gb_Eb(Bit8u insb) {
		return true;
	}

	/* _03_ADD_Gvqp_Evqp
	 description: Add
	*/
	inline bool CpuRunnerLLVM::handler_in_03_ADD_Gvqp_Evqp(Bit8u insb) {
		return true;
	}

	/* _04_ADD_ALb_Ib
	 description: Add
	*/
	inline bool CpuRunnerLLVM::handler_in_04_ADD_ALb_Ib(Bit8u insb) {
		return true;
	}

	/* _05_ADD_rAXvqp_Ivds
	 description: Add
	*/
	inline bool CpuRunnerLLVM::handler_in_05_ADD_rAXvqp_Ivds(Bit8u insb) {
		return true;
	}

	/* _06_PUSH_ESw
	 description: Push Word, Doubleword or Quadword Onto the Stack
	*/
	inline bool CpuRunnerLLVM::handler_in_06_PUSH_ESw(Bit8u insb) {
		return true;
	}

	/* _07_POP_ESw
	 description: Pop a Value from the Stack
	*/
	inline bool CpuRunnerLLVM::handler_in_07_POP_ESw(Bit8u insb) {
		return true;
	}

	/* _08_OR_Eb_Gb
	 description: Logical Inclusive OR
	*/
	inline bool CpuRunnerLLVM::handler_in_08_OR_Eb_Gb(Bit8u insb) {
		return true;
	}

	/* _09_OR_Evqp_Gvqp
	 description: Logical Inclusive OR
	*/
	inline bool CpuRunnerLLVM::handler_in_09_OR_Evqp_Gvqp(Bit8u insb) {
		return true;
	}

	/* _0A_OR_Gb_Eb
	 description: Logical Inclusive OR
	*/
	inline bool CpuRunnerLLVM::handler_in_0A_OR_Gb_Eb(Bit8u insb) {
		return true;
	}

	/* _0B_OR_Gvqp_Evqp
	 description: Logical Inclusive OR
	*/
	inline bool CpuRunnerLLVM::handler_in_0B_OR_Gvqp_Evqp(Bit8u insb) {
		return true;
	}

	/* _0C_OR_ALb_Ib
	 description: Logical Inclusive OR
	*/
	inline bool CpuRunnerLLVM::handler_in_0C_OR_ALb_Ib(Bit8u insb) {
		return true;
	}

	/* _0D_OR_rAXvqp_Ivds
	 description: Logical Inclusive OR
	*/
	inline bool CpuRunnerLLVM::handler_in_0D_OR_rAXvqp_Ivds(Bit8u insb) {
		return true;
	}

	/* _0E_PUSH_CSw
	 description: Push Word, Doubleword or Quadword Onto the Stack
	*/
	inline bool CpuRunnerLLVM::handler_in_0E_PUSH_CSw(Bit8u insb) {
		return true;
	}

	/* _0F_00_00_SLDT_Mw
	 description: Store Local Descriptor Table Register
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_00_00_SLDT_Mw(Bit8u insb) {
		return true;
	}

	/* _0F_00_01_STR_Mw
	 description: Store Task Register
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_00_01_STR_Mw(Bit8u insb) {
		return true;
	}

	/* _0F_00_02_LLDT_Ew
	 description: Load Local Descriptor Table Register
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_00_02_LLDT_Ew(Bit8u insb) {
		return true;
	}

	/* _0F_00_03_LTR_Ew
	 description: Load Task Register
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_00_03_LTR_Ew(Bit8u insb) {
		return true;
	}

	/* _0F_00_04_VERR_Ew
	 description: Verify a Segment for Reading
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_00_04_VERR_Ew(Bit8u insb) {
		return true;
	}

	/* _0F_00_05_VERW_Ew
	 description: Verify a Segment for Writing
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_00_05_VERW_Ew(Bit8u insb) {
		return true;
	}

	/* _0F_01_00_SGDT_Ms
	 description: Store Global Descriptor Table Register
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_01_00_SGDT_Ms(Bit8u insb) {
		return true;
	}

	/* _0F_01_01_SIDT_Ms
	 description: Store Interrupt Descriptor Table Register
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_01_01_SIDT_Ms(Bit8u insb) {
		return true;
	}

	/* _0F_01_02_LGDT_Ms
	 description: Load Global Descriptor Table Register
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_01_02_LGDT_Ms(Bit8u insb) {
		return true;
	}

	/* _0F_01_03_LIDT_Ms
	 description: Load Interrupt Descriptor Table Register
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_01_03_LIDT_Ms(Bit8u insb) {
		return true;
	}

	/* _0F_01_04_SMSW_Mw
	 description: Store Machine Status Word
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_01_04_SMSW_Mw(Bit8u insb) {
		return true;
	}

	/* _0F_01_06_LMSW_Ew
	 description: Load Machine Status Word
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_01_06_LMSW_Ew(Bit8u insb) {
		return true;
	}

	/* _0F_01_07_INVLPG
	 description: Invalidate TLB Entry
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_01_07_INVLPG(Bit8u insb) {
		return true;
	}

	/* _0F_01_D0_XGETBV
	 description: Get Value of Extended Control Register
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_01_D0_XGETBV(Bit8u insb) {
		return true;
	}

	/* _0F_01_D1_XSETBV
	 description: Set Extended Control Register
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_01_D1_XSETBV(Bit8u insb) {
		return true;
	}

	/* _0F_01_F9_RDTSCP
	 description: Read Time-Stamp Counter and Processor ID
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_01_F9_RDTSCP(Bit8u insb) {
		return true;
	}

	/* _0F_02_LAR_Gvqp_Mw
	 description: Load Access Rights Byte
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_02_LAR_Gvqp_Mw(Bit8u insb) {
		return true;
	}

	/* _0F_03_LSL_Gvqp_Mw
	 description: Load Segment Limit
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_03_LSL_Gvqp_Mw(Bit8u insb) {
		return true;
	}

	/* _0F_06_CLTS
	 description: Clear Task-Switched Flag in CR0
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_06_CLTS(Bit8u insb) {
		return true;
	}

	/* _0F_07_LOADALL
	 description: Load All of the CPU Registers
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_07_LOADALL(Bit8u insb) {
		return true;
	}

	/* _0F_08_INVD
	 description: Invalidate Internal Caches
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_08_INVD(Bit8u insb) {
		return true;
	}

	/* _0F_09_WBINVD
	 description: Write Back and Invalidate Cache
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_09_WBINVD(Bit8u insb) {
		return true;
	}

	/* _0F_1F_00_NOP_Ev
	 description: No Operation
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_1F_00_NOP_Ev(Bit8u insb) {
		return true;
	}

	/* _0F_1F_07_HINT_NOP_Ev
	 description: Hintable NOP
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_1F_07_HINT_NOP_Ev(Bit8u insb) {
		return true;
	}

	/* _0F_20_MOV_Hd_Cd
	 description: Move to/from Control Registers
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_20_MOV_Hd_Cd(Bit8u insb) {
		return true;
	}

	/* _0F_21_MOV_Hd_Dd
	 description: Move to/from Debug Registers
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_21_MOV_Hd_Dd(Bit8u insb) {
		return true;
	}

	/* _0F_22_MOV_Cd_Hd
	 description: Move to/from Control Registers
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_22_MOV_Cd_Hd(Bit8u insb) {
		return true;
	}

	/* _0F_23_MOV_Dq_Hq
	 description: Move to/from Debug Registers
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_23_MOV_Dq_Hq(Bit8u insb) {
		return true;
	}

	/* _0F_24_MOV_Hd_Td
	 description: Move to/from Test Registers
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_24_MOV_Hd_Td(Bit8u insb) {
		return true;
	}

	/* _0F_26_MOV_Td_Hd
	 description: Move to/from Test Registers
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_26_MOV_Td_Hd(Bit8u insb) {
		return true;
	}

	/* _0F_30_WRMSR
	 description: Write to Model Specific Register
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_30_WRMSR(Bit8u insb) {
		return true;
	}

	/* _0F_31_RDTSC
	 description: Read Time-Stamp Counter
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_31_RDTSC(Bit8u insb) {
		return true;
	}

	/* _0F_32_RDMSR
	 description: Read from Model Specific Register
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_32_RDMSR(Bit8u insb) {
		return true;
	}

	/* _0F_33_RDPMC
	 description: Read Performance-Monitoring Counters
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_33_RDPMC(Bit8u insb) {
		return true;
	}

	/* _0F_34_SYSENTER
	 description: Fast System Call
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_34_SYSENTER(Bit8u insb) {
		return true;
	}

	/* _0F_35_SYSEXIT
	 description: Fast Return from Fast System Call
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_35_SYSEXIT(Bit8u insb) {
		return true;
	}

	/* _0F_38_F0_MOVBE_Gvqp_Mvqp
	 description: Move Data After Swapping Bytes
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_38_F0_MOVBE_Gvqp_Mvqp(Bit8u insb) {
		return true;
	}

	/* _0F_38_F1_MOVBE_Mvqp_Gvqp
	 description: Move Data After Swapping Bytes
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_38_F1_MOVBE_Mvqp_Gvqp(Bit8u insb) {
		return true;
	}

	/* _0F_40_CMOVO_Gvqp_Evqp
	 description: Conditional Move - overflow (OF=1)
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_40_CMOVO_Gvqp_Evqp(Bit8u insb) {
		return true;
	}

	/* _0F_41_CMOVNO_Gvqp_Evqp
	 description: Conditional Move - not overflow (OF=0)
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_41_CMOVNO_Gvqp_Evqp(Bit8u insb) {
		return true;
	}

	/* _0F_42_CMOVB_Gvqp_Evqp
	 description: Conditional Move - below/not above or equal/carry (CF=1)
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_42_CMOVB_Gvqp_Evqp(Bit8u insb) {
		return true;
	}

	/* _0F_43_CMOVNB_Gvqp_Evqp
	 description: Conditional Move - not below/above or equal/not carry (CF=0)
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_43_CMOVNB_Gvqp_Evqp(Bit8u insb) {
		return true;
	}

	/* _0F_44_CMOVZ_Gvqp_Evqp
	 description: Conditional Move - zero/equal (ZF=0)
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_44_CMOVZ_Gvqp_Evqp(Bit8u insb) {
		return true;
	}

	/* _0F_45_CMOVNZ_Gvqp_Evqp
	 description: Conditional Move - not zero/not equal (ZF=1)
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_45_CMOVNZ_Gvqp_Evqp(Bit8u insb) {
		return true;
	}

	/* _0F_46_CMOVBE_Gvqp_Evqp
	 description: Conditional Move - below or equal/not above (CF=1 AND ZF=1)
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_46_CMOVBE_Gvqp_Evqp(Bit8u insb) {
		return true;
	}

	/* _0F_47_CMOVNBE_Gvqp_Evqp
	 description: Conditional Move - not below or equal/above (CF=0 AND ZF=0)
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_47_CMOVNBE_Gvqp_Evqp(Bit8u insb) {
		return true;
	}

	/* _0F_48_CMOVS_Gvqp_Evqp
	 description: Conditional Move - sign (SF=1)
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_48_CMOVS_Gvqp_Evqp(Bit8u insb) {
		return true;
	}

	/* _0F_49_CMOVNS_Gvqp_Evqp
	 description: Conditional Move - not sign (SF=0)
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_49_CMOVNS_Gvqp_Evqp(Bit8u insb) {
		return true;
	}

	/* _0F_4A_CMOVP_Gvqp_Evqp
	 description: Conditional Move - parity/parity even (PF=1)
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_4A_CMOVP_Gvqp_Evqp(Bit8u insb) {
		return true;
	}

	/* _0F_4B_CMOVNP_Gvqp_Evqp
	 description: Conditional Move - not parity/parity odd
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_4B_CMOVNP_Gvqp_Evqp(Bit8u insb) {
		return true;
	}

	/* _0F_4C_CMOVL_Gvqp_Evqp
	 description: Conditional Move - less/not greater (SF!=OF)
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_4C_CMOVL_Gvqp_Evqp(Bit8u insb) {
		return true;
	}

	/* _0F_4D_CMOVNL_Gvqp_Evqp
	 description: Conditional Move - not less/greater or equal (SF=OF)
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_4D_CMOVNL_Gvqp_Evqp(Bit8u insb) {
		return true;
	}

	/* _0F_4E_CMOVLE_Gvqp_Evqp
	 description: Conditional Move - less or equal/not greater ((ZF=1) OR (SF!=OF))
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_4E_CMOVLE_Gvqp_Evqp(Bit8u insb) {
		return true;
	}

	/* _0F_4F_CMOVNLE_Gvqp_Evqp
	 description: Conditional Move - not less nor equal/greater ((ZF=0) AND (SF=OF))
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_4F_CMOVNLE_Gvqp_Evqp(Bit8u insb) {
		return true;
	}

	/* _0F_80_JO_Jvds
	 description: Jump short if overflow (OF=1)
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_80_JO_Jvds(Bit8u insb) {
		return true;
	}

	/* _0F_81_JNO_Jvds
	 description: Jump short if not overflow (OF=0)
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_81_JNO_Jvds(Bit8u insb) {
		return true;
	}

	/* _0F_82_JB_Jvds
	 description: Jump short if below/not above or equal/carry (CF=1)
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_82_JB_Jvds(Bit8u insb) {
		return true;
	}

	/* _0F_83_JNB_Jvds
	 description: Jump short if not below/above or equal/not carry (CF=0)
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_83_JNB_Jvds(Bit8u insb) {
		return true;
	}

	/* _0F_84_JZ_Jvds
	 description: Jump short if zero/equal (ZF=0)
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_84_JZ_Jvds(Bit8u insb) {
		return true;
	}

	/* _0F_85_JNZ_Jvds
	 description: Jump short if not zero/not equal (ZF=1)
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_85_JNZ_Jvds(Bit8u insb) {
		return true;
	}

	/* _0F_86_JBE_Jvds
	 description: Jump short if below or equal/not above (CF=1 AND ZF=1)
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_86_JBE_Jvds(Bit8u insb) {
		return true;
	}

	/* _0F_87_JNBE_Jvds
	 description: Jump short if not below or equal/above (CF=0 AND ZF=0)
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_87_JNBE_Jvds(Bit8u insb) {
		return true;
	}

	/* _0F_88_JS_Jvds
	 description: Jump short if sign (SF=1)
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_88_JS_Jvds(Bit8u insb) {
		return true;
	}

	/* _0F_89_JNS_Jvds
	 description: Jump short if not sign (SF=0)
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_89_JNS_Jvds(Bit8u insb) {
		return true;
	}

	/* _0F_8A_JP_Jvds
	 description: Jump short if parity/parity even (PF=1)
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_8A_JP_Jvds(Bit8u insb) {
		return true;
	}

	/* _0F_8B_JNP_Jvds
	 description: Jump short if not parity/parity odd
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_8B_JNP_Jvds(Bit8u insb) {
		return true;
	}

	/* _0F_8C_JL_Jvds
	 description: Jump short if less/not greater (SF!=OF)
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_8C_JL_Jvds(Bit8u insb) {
		return true;
	}

	/* _0F_8D_JNL_Jvds
	 description: Jump short if not less/greater or equal (SF=OF)
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_8D_JNL_Jvds(Bit8u insb) {
		return true;
	}

	/* _0F_8E_JLE_Jvds
	 description: Jump short if less or equal/not greater ((ZF=1) OR (SF!=OF))
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_8E_JLE_Jvds(Bit8u insb) {
		return true;
	}

	/* _0F_8F_JNLE_Jvds
	 description: Jump short if not less nor equal/greater ((ZF=0) AND (SF=OF))
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_8F_JNLE_Jvds(Bit8u insb) {
		return true;
	}

	/* _0F_90_00_SETO_Eb
	 description: Set Byte on Condition - overflow (OF=1)
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_90_00_SETO_Eb(Bit8u insb) {
		return true;
	}

	/* _0F_91_00_SETNO_Eb
	 description: Set Byte on Condition - not overflow (OF=0)
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_91_00_SETNO_Eb(Bit8u insb) {
		return true;
	}

	/* _0F_92_00_SETB_Eb
	 description: Set Byte on Condition - below/not above or equal/carry (CF=1)
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_92_00_SETB_Eb(Bit8u insb) {
		return true;
	}

	/* _0F_93_00_SETNB_Eb
	 description: Set Byte on Condition - not below/above or equal/not carry (CF=0)
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_93_00_SETNB_Eb(Bit8u insb) {
		return true;
	}

	/* _0F_94_00_SETZ_Eb
	 description: Set Byte on Condition - zero/equal (ZF=0)
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_94_00_SETZ_Eb(Bit8u insb) {
		return true;
	}

	/* _0F_95_00_SETNZ_Eb
	 description: Set Byte on Condition - not zero/not equal (ZF=1)
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_95_00_SETNZ_Eb(Bit8u insb) {
		return true;
	}

	/* _0F_96_00_SETBE_Eb
	 description: Set Byte on Condition - below or equal/not above (CF=1 AND ZF=1)
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_96_00_SETBE_Eb(Bit8u insb) {
		return true;
	}

	/* _0F_97_00_SETNBE_Eb
	 description: Set Byte on Condition - not below or equal/above (CF=0 AND ZF=0)
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_97_00_SETNBE_Eb(Bit8u insb) {
		return true;
	}

	/* _0F_98_00_SETS_Eb
	 description: Set Byte on Condition - sign (SF=1)
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_98_00_SETS_Eb(Bit8u insb) {
		return true;
	}

	/* _0F_99_00_SETNS_Eb
	 description: Set Byte on Condition - not sign (SF=0)
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_99_00_SETNS_Eb(Bit8u insb) {
		return true;
	}

	/* _0F_9A_00_SETP_Eb
	 description: Set Byte on Condition - parity/parity even (PF=1)
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_9A_00_SETP_Eb(Bit8u insb) {
		return true;
	}

	/* _0F_9B_00_SETNP_Eb
	 description: Set Byte on Condition - not parity/parity odd
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_9B_00_SETNP_Eb(Bit8u insb) {
		return true;
	}

	/* _0F_9C_00_SETL_Eb
	 description: Set Byte on Condition - less/not greater (SF!=OF)
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_9C_00_SETL_Eb(Bit8u insb) {
		return true;
	}

	/* _0F_9D_00_SETNL_Eb
	 description: Set Byte on Condition - not less/greater or equal (SF=OF)
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_9D_00_SETNL_Eb(Bit8u insb) {
		return true;
	}

	/* _0F_9E_00_SETLE_Eb
	 description: Set Byte on Condition - less or equal/not greater ((ZF=1) OR (SF!=OF))
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_9E_00_SETLE_Eb(Bit8u insb) {
		return true;
	}

	/* _0F_9F_00_SETNLE_Eb
	 description: Set Byte on Condition - not less nor equal/greater ((ZF=0) AND (SF=OF))
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_9F_00_SETNLE_Eb(Bit8u insb) {
		return true;
	}

	/* _0F_A0_PUSH_FSw
	 description: Push Word, Doubleword or Quadword Onto the Stack
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_A0_PUSH_FSw(Bit8u insb) {
		return true;
	}

	/* _0F_A1_POP_FSw
	 description: Pop a Value from the Stack
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_A1_POP_FSw(Bit8u insb) {
		return true;
	}

	/* _0F_A2_CPUID
	 description: CPU Identification
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_A2_CPUID(Bit8u insb) {
		return true;
	}

	/* _0F_A3_BT_Gvqp
	 description: Bit Test
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_A3_BT_Gvqp(Bit8u insb) {
		return true;
	}

	/* _0F_A4_SHLD_Evqp_Ib
	 description: Double Precision Shift Left
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_A4_SHLD_Evqp_Ib(Bit8u insb) {
		return true;
	}

	/* _0F_A5_SHLD_Evqp_CLb
	 description: Double Precision Shift Left
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_A5_SHLD_Evqp_CLb(Bit8u insb) {
		return true;
	}

	/* _0F_A8_PUSH_GSw
	 description: Push Word, Doubleword or Quadword Onto the Stack
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_A8_PUSH_GSw(Bit8u insb) {
		return true;
	}

	/* _0F_A9_POP_GSw
	 description: Pop a Value from the Stack
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_A9_POP_GSw(Bit8u insb) {
		return true;
	}

	/* _0F_AA_RSM
	 description: Resume from System Management Mode
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_AA_RSM(Bit8u insb) {
		return true;
	}

	/* _0F_AB_BTS_Evqp_Gvqp
	 description: Bit Test and Set
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_AB_BTS_Evqp_Gvqp(Bit8u insb) {
		return true;
	}

	/* _0F_AC_SHRD_Evqp_Ib
	 description: Double Precision Shift Right
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_AC_SHRD_Evqp_Ib(Bit8u insb) {
		return true;
	}

	/* _0F_AD_SHRD_Evqp_CLb
	 description: Double Precision Shift Right
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_AD_SHRD_Evqp_CLb(Bit8u insb) {
		return true;
	}

	/* _0F_AE_00_FXSAVE_Mstx
	 description: Save x87 FPU, MMX, XMM, and MXCSR State
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_AE_00_FXSAVE_Mstx(Bit8u insb) {
		return true;
	}

	/* _0F_AE_01_FXRSTOR_Mstx
	 description: Restore x87 FPU, MMX, XMM, and MXCSR State
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_AE_01_FXRSTOR_Mstx(Bit8u insb) {
		return true;
	}

	/* _0F_AE_04_XSAVE
	 description: Save Processor Extended States
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_AE_04_XSAVE(Bit8u insb) {
		return true;
	}

	/* _0F_AE_05_XRSTOR
	 description: Restore Processor Extended States
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_AE_05_XRSTOR(Bit8u insb) {
		return true;
	}

	/* _0F_AF_IMUL_Gvqp_Evqp
	 description: Signed Multiply
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_AF_IMUL_Gvqp_Evqp(Bit8u insb) {
		return true;
	}

	/* _0F_B0_CMPXCHG_Eb_Gb
	 description: Compare and Exchange
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_B0_CMPXCHG_Eb_Gb(Bit8u insb) {
		return true;
	}

	/* _0F_B1_CMPXCHG_Evqp_Gvqp
	 description: Compare and Exchange
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_B1_CMPXCHG_Evqp_Gvqp(Bit8u insb) {
		return true;
	}

	/* _0F_B2_LSS_Gvqp_Mptp
	 description: Load Far Pointer
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_B2_LSS_Gvqp_Mptp(Bit8u insb) {
		return true;
	}

	/* _0F_B3_BTR_Evqp_Gvqp
	 description: Bit Test and Reset
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_B3_BTR_Evqp_Gvqp(Bit8u insb) {
		return true;
	}

	/* _0F_B4_LFS_Gvqp_Mptp
	 description: Load Far Pointer
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_B4_LFS_Gvqp_Mptp(Bit8u insb) {
		return true;
	}

	/* _0F_B5_LGS_Gvqp_Mptp
	 description: Load Far Pointer
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_B5_LGS_Gvqp_Mptp(Bit8u insb) {
		return true;
	}

	/* _0F_B6_MOVZX_Gvqp_Eb
	 description: Move with Zero-Extend
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_B6_MOVZX_Gvqp_Eb(Bit8u insb) {
		return true;
	}

	/* _0F_B7_MOVZX_Gvqp_Ew
	 description: Move with Zero-Extend
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_B7_MOVZX_Gvqp_Ew(Bit8u insb) {
		return true;
	}

	/* _0F_BA_04_BT_Ib
	 description: Bit Test
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_BA_04_BT_Ib(Bit8u insb) {
		return true;
	}

	/* _0F_BA_05_BTS_Evqp_Ib
	 description: Bit Test and Set
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_BA_05_BTS_Evqp_Ib(Bit8u insb) {
		return true;
	}

	/* _0F_BA_06_BTR_Evqp_Ib
	 description: Bit Test and Reset
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_BA_06_BTR_Evqp_Ib(Bit8u insb) {
		return true;
	}

	/* _0F_BA_07_BTC_Evqp_Ib
	 description: Bit Test and Complement
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_BA_07_BTC_Evqp_Ib(Bit8u insb) {
		return true;
	}

	/* _0F_BB_BTC_Evqp_Gvqp
	 description: Bit Test and Complement
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_BB_BTC_Evqp_Gvqp(Bit8u insb) {
		return true;
	}

	/* _0F_BC_BSF_Gvqp_Evqp
	 description: Bit Scan Forward
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_BC_BSF_Gvqp_Evqp(Bit8u insb) {
		return true;
	}

	/* _0F_BD_BSR_Gvqp_Evqp
	 description: Bit Scan Reverse
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_BD_BSR_Gvqp_Evqp(Bit8u insb) {
		return true;
	}

	/* _0F_BE_MOVSX_Gvqp_Eb
	 description: Move with Sign-Extension
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_BE_MOVSX_Gvqp_Eb(Bit8u insb) {
		return true;
	}

	/* _0F_BF_MOVSX_Gvqp_Ew
	 description: Move with Sign-Extension
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_BF_MOVSX_Gvqp_Ew(Bit8u insb) {
		return true;
	}

	/* _0F_C0_XADD_Gb
	 description: Exchange and Add
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_C0_XADD_Gb(Bit8u insb) {
		return true;
	}

	/* _0F_C1_XADD_Gvqp
	 description: Exchange and Add
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_C1_XADD_Gvqp(Bit8u insb) {
		return true;
	}

	/* _0F_C7_01_CMPXCHG8B_Mq
	 description: Compare and Exchange Bytes
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_C7_01_CMPXCHG8B_Mq(Bit8u insb) {
		return true;
	}

	/* _0F_C8_BSWAP_rAXvqp
	 description: Byte Swap
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_C8_BSWAP_rAXvqp(Bit8u insb) {
		return true;
	}

	/* _0F_C9_BSWAP_rCXvqp
	 description: Byte Swap
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_C9_BSWAP_rCXvqp(Bit8u insb) {
		return true;
	}

	/* _0F_CA_BSWAP_rDXvqp
	 description: Byte Swap
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_CA_BSWAP_rDXvqp(Bit8u insb) {
		return true;
	}

	/* _0F_CB_BSWAP_rBXvqp
	 description: Byte Swap
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_CB_BSWAP_rBXvqp(Bit8u insb) {
		return true;
	}

	/* _0F_CC_BSWAP_rSPvqp
	 description: Byte Swap
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_CC_BSWAP_rSPvqp(Bit8u insb) {
		return true;
	}

	/* _0F_CD_BSWAP_rBPvqp
	 description: Byte Swap
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_CD_BSWAP_rBPvqp(Bit8u insb) {
		return true;
	}

	/* _0F_CE_BSWAP_rSIvqp
	 description: Byte Swap
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_CE_BSWAP_rSIvqp(Bit8u insb) {
		return true;
	}

	/* _0F_CF_BSWAP_rDIvqp
	 description: Byte Swap
	*/
	inline bool CpuRunnerLLVM::handler_in_0F_CF_BSWAP_rDIvqp(Bit8u insb) {
		return true;
	}

	/* _10_ADC_Eb_Gb
	 description: Add with Carry
	*/
	inline bool CpuRunnerLLVM::handler_in_10_ADC_Eb_Gb(Bit8u insb) {
		return true;
	}

	/* _11_ADC_Evqp_Gvqp
	 description: Add with Carry
	*/
	inline bool CpuRunnerLLVM::handler_in_11_ADC_Evqp_Gvqp(Bit8u insb) {
		return true;
	}

	/* _12_ADC_Gb_Eb
	 description: Add with Carry
	*/
	inline bool CpuRunnerLLVM::handler_in_12_ADC_Gb_Eb(Bit8u insb) {
		return true;
	}

	/* _13_ADC_Gvqp_Evqp
	 description: Add with Carry
	*/
	inline bool CpuRunnerLLVM::handler_in_13_ADC_Gvqp_Evqp(Bit8u insb) {
		return true;
	}

	/* _14_ADC_ALb_Ib
	 description: Add with Carry
	*/
	inline bool CpuRunnerLLVM::handler_in_14_ADC_ALb_Ib(Bit8u insb) {
		return true;
	}

	/* _15_ADC_rAXvqp_Ivds
	 description: Add with Carry
	*/
	inline bool CpuRunnerLLVM::handler_in_15_ADC_rAXvqp_Ivds(Bit8u insb) {
		return true;
	}

	/* _16_PUSH_SSw
	 description: Push Word, Doubleword or Quadword Onto the Stack
	*/
	inline bool CpuRunnerLLVM::handler_in_16_PUSH_SSw(Bit8u insb) {
		return true;
	}

	/* _17_POP_SSw
	 description: Pop a Value from the Stack
	*/
	inline bool CpuRunnerLLVM::handler_in_17_POP_SSw(Bit8u insb) {
		return true;
	}

	/* _18_SBB_Eb_Gb
	 description: Integer Subtraction with Borrow
	*/
	inline bool CpuRunnerLLVM::handler_in_18_SBB_Eb_Gb(Bit8u insb) {
		return true;
	}

	/* _19_SBB_Evqp_Gvqp
	 description: Integer Subtraction with Borrow
	*/
	inline bool CpuRunnerLLVM::handler_in_19_SBB_Evqp_Gvqp(Bit8u insb) {
		return true;
	}

	/* _1A_SBB_Gb_Eb
	 description: Integer Subtraction with Borrow
	*/
	inline bool CpuRunnerLLVM::handler_in_1A_SBB_Gb_Eb(Bit8u insb) {
		return true;
	}

	/* _1B_SBB_Gvqp_Evqp
	 description: Integer Subtraction with Borrow
	*/
	inline bool CpuRunnerLLVM::handler_in_1B_SBB_Gvqp_Evqp(Bit8u insb) {
		return true;
	}

	/* _1C_SBB_ALb_Ib
	 description: Integer Subtraction with Borrow
	*/
	inline bool CpuRunnerLLVM::handler_in_1C_SBB_ALb_Ib(Bit8u insb) {
		return true;
	}

	/* _1D_SBB_rAXvqp_Ivds
	 description: Integer Subtraction with Borrow
	*/
	inline bool CpuRunnerLLVM::handler_in_1D_SBB_rAXvqp_Ivds(Bit8u insb) {
		return true;
	}

	/* _1E_PUSH_DSw
	 description: Push Word, Doubleword or Quadword Onto the Stack
	*/
	inline bool CpuRunnerLLVM::handler_in_1E_PUSH_DSw(Bit8u insb) {
		return true;
	}

	/* _1F_POP_DSw
	 description: Pop a Value from the Stack
	*/
	inline bool CpuRunnerLLVM::handler_in_1F_POP_DSw(Bit8u insb) {
		return true;
	}

	/* _20_AND_Eb_Gb
	 description: Logical AND
	*/
	inline bool CpuRunnerLLVM::handler_in_20_AND_Eb_Gb(Bit8u insb) {
		return true;
	}

	/* _21_AND_Evqp_Gvqp
	 description: Logical AND
	*/
	inline bool CpuRunnerLLVM::handler_in_21_AND_Evqp_Gvqp(Bit8u insb) {
		return true;
	}

	/* _22_AND_Gb_Eb
	 description: Logical AND
	*/
	inline bool CpuRunnerLLVM::handler_in_22_AND_Gb_Eb(Bit8u insb) {
		return true;
	}

	/* _23_AND_Gvqp_Evqp
	 description: Logical AND
	*/
	inline bool CpuRunnerLLVM::handler_in_23_AND_Gvqp_Evqp(Bit8u insb) {
		return true;
	}

	/* _24_AND_ALb_Ib
	 description: Logical AND
	*/
	inline bool CpuRunnerLLVM::handler_in_24_AND_ALb_Ib(Bit8u insb) {
		return true;
	}

	/* _25_AND_rAXvqp_Ivds
	 description: Logical AND
	*/
	inline bool CpuRunnerLLVM::handler_in_25_AND_rAXvqp_Ivds(Bit8u insb) {
		return true;
	}

	/* _27_DAA
	 description: Decimal Adjust AL after Addition
	*/
	inline bool CpuRunnerLLVM::handler_in_27_DAA(Bit8u insb) {
		return true;
	}

	/* _28_SUB_Eb_Gb
	 description: Subtract
	*/
	inline bool CpuRunnerLLVM::handler_in_28_SUB_Eb_Gb(Bit8u insb) {
		return true;
	}

	/* _29_SUB_Evqp_Gvqp
	 description: Subtract
	*/
	inline bool CpuRunnerLLVM::handler_in_29_SUB_Evqp_Gvqp(Bit8u insb) {
		return true;
	}

	/* _2A_SUB_Gb_Eb
	 description: Subtract
	*/
	inline bool CpuRunnerLLVM::handler_in_2A_SUB_Gb_Eb(Bit8u insb) {
		return true;
	}

	/* _2B_SUB_Gvqp_Evqp
	 description: Subtract
	*/
	inline bool CpuRunnerLLVM::handler_in_2B_SUB_Gvqp_Evqp(Bit8u insb) {
		return true;
	}

	/* _2C_SUB_ALb_Ib
	 description: Subtract
	*/
	inline bool CpuRunnerLLVM::handler_in_2C_SUB_ALb_Ib(Bit8u insb) {
		return true;
	}

	/* _2D_SUB_rAXvqp_Ivds
	 description: Subtract
	*/
	inline bool CpuRunnerLLVM::handler_in_2D_SUB_rAXvqp_Ivds(Bit8u insb) {
		return true;
	}

	/* _2F_DAS
	 description: Decimal Adjust AL after Subtraction
	*/
	inline bool CpuRunnerLLVM::handler_in_2F_DAS(Bit8u insb) {
		return true;
	}

	/* _30_XOR_Eb_Gb
	 description: Logical Exclusive OR
	*/
	inline bool CpuRunnerLLVM::handler_in_30_XOR_Eb_Gb(Bit8u insb) {
		return true;
	}

	/* _31_XOR_Evqp_Gvqp
	 description: Logical Exclusive OR
	*/
	inline bool CpuRunnerLLVM::handler_in_31_XOR_Evqp_Gvqp(Bit8u insb) {
		return true;
	}

	/* _32_XOR_Gb_Eb
	 description: Logical Exclusive OR
	*/
	inline bool CpuRunnerLLVM::handler_in_32_XOR_Gb_Eb(Bit8u insb) {
		return true;
	}

	/* _33_XOR_Gvqp_Evqp
	 description: Logical Exclusive OR
	*/
	inline bool CpuRunnerLLVM::handler_in_33_XOR_Gvqp_Evqp(Bit8u insb) {
		return true;
	}

	/* _34_XOR_ALb_Ib
	 description: Logical Exclusive OR
	*/
	inline bool CpuRunnerLLVM::handler_in_34_XOR_ALb_Ib(Bit8u insb) {
		return true;
	}

	/* _35_XOR_rAXvqp_Ivds
	 description: Logical Exclusive OR
	*/
	inline bool CpuRunnerLLVM::handler_in_35_XOR_rAXvqp_Ivds(Bit8u insb) {
		return true;
	}

	/* _37_AAA
	 description: ASCII Adjust After Addition
	*/
	inline bool CpuRunnerLLVM::handler_in_37_AAA(Bit8u insb) {
		return true;
	}

	/* _38_CMP_Gb
	 description: Compare Two Operands
	*/
	inline bool CpuRunnerLLVM::handler_in_38_CMP_Gb(Bit8u insb) {
		return true;
	}

	/* _39_CMP_Gvqp
	 description: Compare Two Operands
	*/
	inline bool CpuRunnerLLVM::handler_in_39_CMP_Gvqp(Bit8u insb) {
		return true;
	}

	/* _3A_CMP_Eb
	 description: Compare Two Operands
	*/
	inline bool CpuRunnerLLVM::handler_in_3A_CMP_Eb(Bit8u insb) {
		return true;
	}

	/* _3B_CMP_Evqp
	 description: Compare Two Operands
	*/
	inline bool CpuRunnerLLVM::handler_in_3B_CMP_Evqp(Bit8u insb) {
		return true;
	}

	/* _3C_CMP_Ib
	 description: Compare Two Operands
	*/
	inline bool CpuRunnerLLVM::handler_in_3C_CMP_Ib(Bit8u insb) {
		return true;
	}

	/* _3D_CMP_Ivds
	 description: Compare Two Operands
	*/
	inline bool CpuRunnerLLVM::handler_in_3D_CMP_Ivds(Bit8u insb) {
		return true;
	}

	/* _3F_AAS
	 description: ASCII Adjust AL After Subtraction
	*/
	inline bool CpuRunnerLLVM::handler_in_3F_AAS(Bit8u insb) {
		return true;
	}

	/* _40_INC_rAXv
	 description: Increment by 1
	*/
	inline bool CpuRunnerLLVM::handler_in_40_INC_rAXv(Bit8u insb) {
		return true;
	}

	/* _41_INC_rCXv
	 description: Increment by 1
	*/
	inline bool CpuRunnerLLVM::handler_in_41_INC_rCXv(Bit8u insb) {
		return true;
	}

	/* _42_INC_rDXv
	 description: Increment by 1
	*/
	inline bool CpuRunnerLLVM::handler_in_42_INC_rDXv(Bit8u insb) {
		return true;
	}

	/* _43_INC_rBXv
	 description: Increment by 1
	*/
	inline bool CpuRunnerLLVM::handler_in_43_INC_rBXv(Bit8u insb) {
		return true;
	}

	/* _44_INC_rSPv
	 description: Increment by 1
	*/
	inline bool CpuRunnerLLVM::handler_in_44_INC_rSPv(Bit8u insb) {
		return true;
	}

	/* _45_INC_rBPv
	 description: Increment by 1
	*/
	inline bool CpuRunnerLLVM::handler_in_45_INC_rBPv(Bit8u insb) {
		return true;
	}

	/* _46_INC_rSIv
	 description: Increment by 1
	*/
	inline bool CpuRunnerLLVM::handler_in_46_INC_rSIv(Bit8u insb) {
		return true;
	}

	/* _47_INC_rDIv
	 description: Increment by 1
	*/
	inline bool CpuRunnerLLVM::handler_in_47_INC_rDIv(Bit8u insb) {
		return true;
	}

	/* _48_DEC_rAXv
	 description: Decrement by 1
	*/
	inline bool CpuRunnerLLVM::handler_in_48_DEC_rAXv(Bit8u insb) {
		return true;
	}

	/* _49_DEC_rCXv
	 description: Decrement by 1
	*/
	inline bool CpuRunnerLLVM::handler_in_49_DEC_rCXv(Bit8u insb) {
		return true;
	}

	/* _4A_DEC_rDXv
	 description: Decrement by 1
	*/
	inline bool CpuRunnerLLVM::handler_in_4A_DEC_rDXv(Bit8u insb) {
		return true;
	}

	/* _4B_DEC_rBXv
	 description: Decrement by 1
	*/
	inline bool CpuRunnerLLVM::handler_in_4B_DEC_rBXv(Bit8u insb) {
		return true;
	}

	/* _4C_DEC_rSPv
	 description: Decrement by 1
	*/
	inline bool CpuRunnerLLVM::handler_in_4C_DEC_rSPv(Bit8u insb) {
		return true;
	}

	/* _4D_DEC_rBPv
	 description: Decrement by 1
	*/
	inline bool CpuRunnerLLVM::handler_in_4D_DEC_rBPv(Bit8u insb) {
		return true;
	}

	/* _4E_DEC_rSIv
	 description: Decrement by 1
	*/
	inline bool CpuRunnerLLVM::handler_in_4E_DEC_rSIv(Bit8u insb) {
		return true;
	}

	/* _4F_DEC_rDIv
	 description: Decrement by 1
	*/
	inline bool CpuRunnerLLVM::handler_in_4F_DEC_rDIv(Bit8u insb) {
		return true;
	}

	/* _50_PUSH_rAXv
	 description: Push Word, Doubleword or Quadword Onto the Stack
	*/
	inline bool CpuRunnerLLVM::handler_in_50_PUSH_rAXv(Bit8u insb) {
		return true;
	}

	/* _51_PUSH_rCXv
	 description: Push Word, Doubleword or Quadword Onto the Stack
	*/
	inline bool CpuRunnerLLVM::handler_in_51_PUSH_rCXv(Bit8u insb) {
		return true;
	}

	/* _52_PUSH_rDXv
	 description: Push Word, Doubleword or Quadword Onto the Stack
	*/
	inline bool CpuRunnerLLVM::handler_in_52_PUSH_rDXv(Bit8u insb) {
		return true;
	}

	/* _53_PUSH_rBXv
	 description: Push Word, Doubleword or Quadword Onto the Stack
	*/
	inline bool CpuRunnerLLVM::handler_in_53_PUSH_rBXv(Bit8u insb) {
		return true;
	}

	/* _54_PUSH_rSPv
	 description: Push Word, Doubleword or Quadword Onto the Stack
	*/
	inline bool CpuRunnerLLVM::handler_in_54_PUSH_rSPv(Bit8u insb) {
		return true;
	}

	/* _55_PUSH_rBPv
	 description: Push Word, Doubleword or Quadword Onto the Stack
	*/
	inline bool CpuRunnerLLVM::handler_in_55_PUSH_rBPv(Bit8u insb) {
		return true;
	}

	/* _56_PUSH_rSIv
	 description: Push Word, Doubleword or Quadword Onto the Stack
	*/
	inline bool CpuRunnerLLVM::handler_in_56_PUSH_rSIv(Bit8u insb) {
		return true;
	}

	/* _57_PUSH_rDIv
	 description: Push Word, Doubleword or Quadword Onto the Stack
	*/
	inline bool CpuRunnerLLVM::handler_in_57_PUSH_rDIv(Bit8u insb) {
		return true;
	}

	/* _58_POP_rAXv
	 description: Pop a Value from the Stack
	*/
	inline bool CpuRunnerLLVM::handler_in_58_POP_rAXv(Bit8u insb) {
		return true;
	}

	/* _59_POP_rCXv
	 description: Pop a Value from the Stack
	*/
	inline bool CpuRunnerLLVM::handler_in_59_POP_rCXv(Bit8u insb) {
		return true;
	}

	/* _5A_POP_rDXv
	 description: Pop a Value from the Stack
	*/
	inline bool CpuRunnerLLVM::handler_in_5A_POP_rDXv(Bit8u insb) {
		return true;
	}

	/* _5B_POP_rBXv
	 description: Pop a Value from the Stack
	*/
	inline bool CpuRunnerLLVM::handler_in_5B_POP_rBXv(Bit8u insb) {
		return true;
	}

	/* _5C_POP_rSPv
	 description: Pop a Value from the Stack
	*/
	inline bool CpuRunnerLLVM::handler_in_5C_POP_rSPv(Bit8u insb) {
		return true;
	}

	/* _5D_POP_rBPv
	 description: Pop a Value from the Stack
	*/
	inline bool CpuRunnerLLVM::handler_in_5D_POP_rBPv(Bit8u insb) {
		return true;
	}

	/* _5E_POP_rSIv
	 description: Pop a Value from the Stack
	*/
	inline bool CpuRunnerLLVM::handler_in_5E_POP_rSIv(Bit8u insb) {
		return true;
	}

	/* _5F_POP_rDIv
	 description: Pop a Value from the Stack
	*/
	inline bool CpuRunnerLLVM::handler_in_5F_POP_rDIv(Bit8u insb) {
		return true;
	}

	/* _60_PUSHA
	 description: Push All General-Purpose Registers
	*/
	inline bool CpuRunnerLLVM::handler_in_60_PUSHA(Bit8u insb) {
		return true;
	}

	/* _61_POPA
	 description: Pop All General-Purpose Registers
	*/
	inline bool CpuRunnerLLVM::handler_in_61_POPA(Bit8u insb) {
		return true;
	}

	/* _62_BOUND_Ma
	 description: Check Array Index Against Bounds
	*/
	inline bool CpuRunnerLLVM::handler_in_62_BOUND_Ma(Bit8u insb) {
		return true;
	}

	/* _63_ARPL_Gw
	 description: Adjust RPL Field of Segment Selector
	*/
	inline bool CpuRunnerLLVM::handler_in_63_ARPL_Gw(Bit8u insb) {
		return true;
	}

	/* _68_PUSH_Ivs
	 description: Push Word, Doubleword or Quadword Onto the Stack
	*/
	inline bool CpuRunnerLLVM::handler_in_68_PUSH_Ivs(Bit8u insb) {
		return true;
	}

	/* _69_IMUL_Gvqp_Ivds
	 description: Signed Multiply
	*/
	inline bool CpuRunnerLLVM::handler_in_69_IMUL_Gvqp_Ivds(Bit8u insb) {
		return true;
	}

	/* _6A_PUSH_Ibss
	 description: Push Word, Doubleword or Quadword Onto the Stack
	*/
	inline bool CpuRunnerLLVM::handler_in_6A_PUSH_Ibss(Bit8u insb) {
		return true;
	}

	/* _6B_IMUL_Gvqp_Ibs
	 description: Signed Multiply
	*/
	inline bool CpuRunnerLLVM::handler_in_6B_IMUL_Gvqp_Ibs(Bit8u insb) {
		return true;
	}

	/* _6C_INS_Yb_DXw
	 description: Input from Port to String
	*/
	inline bool CpuRunnerLLVM::handler_in_6C_INS_Yb_DXw(Bit8u insb) {
		return true;
	}

	/* _6D_INS_Ywo_DXw
	 description: Input from Port to String
	*/
	inline bool CpuRunnerLLVM::handler_in_6D_INS_Ywo_DXw(Bit8u insb) {
		return true;
	}

	/* _6E_OUTS_DXw_Xb
	 description: Output String to Port
	*/
	inline bool CpuRunnerLLVM::handler_in_6E_OUTS_DXw_Xb(Bit8u insb) {
		return true;
	}

	/* _6F_OUTS_DXw_Xwo
	 description: Output String to Port
	*/
	inline bool CpuRunnerLLVM::handler_in_6F_OUTS_DXw_Xwo(Bit8u insb) {
		return true;
	}

	/* _70_JO_Jbs
	 description: Jump short if overflow (OF=1)
	*/
	inline bool CpuRunnerLLVM::handler_in_70_JO_Jbs(Bit8u insb) {
		return true;
	}

	/* _71_JNO_Jbs
	 description: Jump short if not overflow (OF=0)
	*/
	inline bool CpuRunnerLLVM::handler_in_71_JNO_Jbs(Bit8u insb) {
		return true;
	}

	/* _72_JB_Jbs
	 description: Jump short if below/not above or equal/carry (CF=1)
	*/
	inline bool CpuRunnerLLVM::handler_in_72_JB_Jbs(Bit8u insb) {
		return true;
	}

	/* _73_JNB_Jbs
	 description: Jump short if not below/above or equal/not carry (CF=0)
	*/
	inline bool CpuRunnerLLVM::handler_in_73_JNB_Jbs(Bit8u insb) {
		return true;
	}

	/* _74_JZ_Jbs
	 description: Jump short if zero/equal (ZF=0)
	*/
	inline bool CpuRunnerLLVM::handler_in_74_JZ_Jbs(Bit8u insb) {
		return true;
	}

	/* _75_JNZ_Jbs
	 description: Jump short if not zero/not equal (ZF=1)
	*/
	inline bool CpuRunnerLLVM::handler_in_75_JNZ_Jbs(Bit8u insb) {
		return true;
	}

	/* _76_JBE_Jbs
	 description: Jump short if below or equal/not above (CF=1 AND ZF=1)
	*/
	inline bool CpuRunnerLLVM::handler_in_76_JBE_Jbs(Bit8u insb) {
		return true;
	}

	/* _77_JNBE_Jbs
	 description: Jump short if not below or equal/above (CF=0 AND ZF=0)
	*/
	inline bool CpuRunnerLLVM::handler_in_77_JNBE_Jbs(Bit8u insb) {
		return true;
	}

	/* _78_JS_Jbs
	 description: Jump short if sign (SF=1)
	*/
	inline bool CpuRunnerLLVM::handler_in_78_JS_Jbs(Bit8u insb) {
		return true;
	}

	/* _79_JNS_Jbs
	 description: Jump short if not sign (SF=0)
	*/
	inline bool CpuRunnerLLVM::handler_in_79_JNS_Jbs(Bit8u insb) {
		return true;
	}

	/* _7A_JP_Jbs
	 description: Jump short if parity/parity even (PF=1)
	*/
	inline bool CpuRunnerLLVM::handler_in_7A_JP_Jbs(Bit8u insb) {
		return true;
	}

	/* _7B_JNP_Jbs
	 description: Jump short if not parity/parity odd
	*/
	inline bool CpuRunnerLLVM::handler_in_7B_JNP_Jbs(Bit8u insb) {
		return true;
	}

	/* _7C_JL_Jbs
	 description: Jump short if less/not greater (SF!=OF)
	*/
	inline bool CpuRunnerLLVM::handler_in_7C_JL_Jbs(Bit8u insb) {
		return true;
	}

	/* _7D_JNL_Jbs
	 description: Jump short if not less/greater or equal (SF=OF)
	*/
	inline bool CpuRunnerLLVM::handler_in_7D_JNL_Jbs(Bit8u insb) {
		return true;
	}

	/* _7E_JLE_Jbs
	 description: Jump short if less or equal/not greater ((ZF=1) OR (SF!=OF))
	*/
	inline bool CpuRunnerLLVM::handler_in_7E_JLE_Jbs(Bit8u insb) {
		return true;
	}

	/* _7F_JNLE_Jbs
	 description: Jump short if not less nor equal/greater ((ZF=0) AND (SF=OF))
	*/
	inline bool CpuRunnerLLVM::handler_in_7F_JNLE_Jbs(Bit8u insb) {
		return true;
	}

	/* _81_00_ADD_Evqp_Ivds
	 description: Add
	*/
	inline bool CpuRunnerLLVM::handler_in_81_00_ADD_Evqp_Ivds(Bit8u insb) {
		return true;
	}

	/* _81_01_OR_Evqp_Ivds
	 description: Logical Inclusive OR
	*/
	inline bool CpuRunnerLLVM::handler_in_81_01_OR_Evqp_Ivds(Bit8u insb) {
		return true;
	}

	/* _81_02_ADC_Evqp_Ivds
	 description: Add with Carry
	*/
	inline bool CpuRunnerLLVM::handler_in_81_02_ADC_Evqp_Ivds(Bit8u insb) {
		return true;
	}

	/* _81_03_SBB_Evqp_Ivds
	 description: Integer Subtraction with Borrow
	*/
	inline bool CpuRunnerLLVM::handler_in_81_03_SBB_Evqp_Ivds(Bit8u insb) {
		return true;
	}

	/* _81_04_AND_Evqp_Ivds
	 description: Logical AND
	*/
	inline bool CpuRunnerLLVM::handler_in_81_04_AND_Evqp_Ivds(Bit8u insb) {
		return true;
	}

	/* _81_05_SUB_Evqp_Ivds
	 description: Subtract
	*/
	inline bool CpuRunnerLLVM::handler_in_81_05_SUB_Evqp_Ivds(Bit8u insb) {
		return true;
	}

	/* _81_06_XOR_Evqp_Ivds
	 description: Logical Exclusive OR
	*/
	inline bool CpuRunnerLLVM::handler_in_81_06_XOR_Evqp_Ivds(Bit8u insb) {
		return true;
	}

	/* _81_07_CMP_Ivds
	 description: Compare Two Operands
	*/
	inline bool CpuRunnerLLVM::handler_in_81_07_CMP_Ivds(Bit8u insb) {
		return true;
	}

	/* _82_00_ADD_Eb_Ib
	 description: Add
	*/
	inline bool CpuRunnerLLVM::handler_in_82_00_ADD_Eb_Ib(Bit8u insb) {
		return true;
	}

	/* _82_01_OR_Eb_Ib
	 description: Logical Inclusive OR
	*/
	inline bool CpuRunnerLLVM::handler_in_82_01_OR_Eb_Ib(Bit8u insb) {
		return true;
	}

	/* _82_02_ADC_Eb_Ib
	 description: Add with Carry
	*/
	inline bool CpuRunnerLLVM::handler_in_82_02_ADC_Eb_Ib(Bit8u insb) {
		return true;
	}

	/* _82_03_SBB_Eb_Ib
	 description: Integer Subtraction with Borrow
	*/
	inline bool CpuRunnerLLVM::handler_in_82_03_SBB_Eb_Ib(Bit8u insb) {
		return true;
	}

	/* _82_04_AND_Eb_Ib
	 description: Logical AND
	*/
	inline bool CpuRunnerLLVM::handler_in_82_04_AND_Eb_Ib(Bit8u insb) {
		return true;
	}

	/* _82_05_SUB_Eb_Ib
	 description: Subtract
	*/
	inline bool CpuRunnerLLVM::handler_in_82_05_SUB_Eb_Ib(Bit8u insb) {
		return true;
	}

	/* _82_06_XOR_Eb_Ib
	 description: Logical Exclusive OR
	*/
	inline bool CpuRunnerLLVM::handler_in_82_06_XOR_Eb_Ib(Bit8u insb) {
		return true;
	}

	/* _82_07_CMP_Ib
	 description: Compare Two Operands
	*/
	inline bool CpuRunnerLLVM::handler_in_82_07_CMP_Ib(Bit8u insb) {
		return true;
	}

	/* _83_00_ADD_Evqp_Ibs
	 description: Add
	*/
	inline bool CpuRunnerLLVM::handler_in_83_00_ADD_Evqp_Ibs(Bit8u insb) {
		return true;
	}

	/* _83_01_OR_Evqp_Ibs
	 description: Logical Inclusive OR
	*/
	inline bool CpuRunnerLLVM::handler_in_83_01_OR_Evqp_Ibs(Bit8u insb) {
		return true;
	}

	/* _83_02_ADC_Evqp_Ibs
	 description: Add with Carry
	*/
	inline bool CpuRunnerLLVM::handler_in_83_02_ADC_Evqp_Ibs(Bit8u insb) {
		return true;
	}

	/* _83_03_SBB_Evqp_Ibs
	 description: Integer Subtraction with Borrow
	*/
	inline bool CpuRunnerLLVM::handler_in_83_03_SBB_Evqp_Ibs(Bit8u insb) {
		return true;
	}

	/* _83_04_AND_Evqp_Ibs
	 description: Logical AND
	*/
	inline bool CpuRunnerLLVM::handler_in_83_04_AND_Evqp_Ibs(Bit8u insb) {
		return true;
	}

	/* _83_05_SUB_Evqp_Ibs
	 description: Subtract
	*/
	inline bool CpuRunnerLLVM::handler_in_83_05_SUB_Evqp_Ibs(Bit8u insb) {
		return true;
	}

	/* _83_06_XOR_Evqp_Ibs
	 description: Logical Exclusive OR
	*/
	inline bool CpuRunnerLLVM::handler_in_83_06_XOR_Evqp_Ibs(Bit8u insb) {
		return true;
	}

	/* _83_07_CMP_Ibs
	 description: Compare Two Operands
	*/
	inline bool CpuRunnerLLVM::handler_in_83_07_CMP_Ibs(Bit8u insb) {
		return true;
	}

	/* _84_TEST_Gb
	 description: Logical Compare
	*/
	inline bool CpuRunnerLLVM::handler_in_84_TEST_Gb(Bit8u insb) {
		return true;
	}

	/* _85_TEST_Gvqp
	 description: Logical Compare
	*/
	inline bool CpuRunnerLLVM::handler_in_85_TEST_Gvqp(Bit8u insb) {
		return true;
	}

	/* _86_XCHG_Eb
	 description: Exchange Register/Memory with Register
	*/
	inline bool CpuRunnerLLVM::handler_in_86_XCHG_Eb(Bit8u insb) {
		return true;
	}

	/* _87_XCHG_Evqp
	 description: Exchange Register/Memory with Register
	*/
	inline bool CpuRunnerLLVM::handler_in_87_XCHG_Evqp(Bit8u insb) {
		return true;
	}

	/* _88_MOV_Eb_Gb
	 description: Move
	*/
	inline bool CpuRunnerLLVM::handler_in_88_MOV_Eb_Gb(Bit8u insb) {
		return true;
	}

	/* _89_MOV_Evqp_Gvqp
	 description: Move
	*/
	inline bool CpuRunnerLLVM::handler_in_89_MOV_Evqp_Gvqp(Bit8u insb) {
		return true;
	}

	/* _8A_MOV_Gb_Eb
	 description: Move
	*/
	inline bool CpuRunnerLLVM::handler_in_8A_MOV_Gb_Eb(Bit8u insb) {
		return true;
	}

	/* _8B_MOV_Gvqp_Evqp
	 description: Move
	*/
	inline bool CpuRunnerLLVM::handler_in_8B_MOV_Gvqp_Evqp(Bit8u insb) {
		return true;
	}

	/* _8C_MOV_Mw_Sw
	 description: Move
	*/
	inline bool CpuRunnerLLVM::handler_in_8C_MOV_Mw_Sw(Bit8u insb) {
		return true;
	}

	/* _8D_LEA_Gvqp
	 description: Load Effective Address
	*/
	inline bool CpuRunnerLLVM::handler_in_8D_LEA_Gvqp(Bit8u insb) {
		return true;
	}

	/* _8E_MOV_Sw_Ew
	 description: Move
	*/
	inline bool CpuRunnerLLVM::handler_in_8E_MOV_Sw_Ew(Bit8u insb) {
		return true;
	}

	/* _8F_00_POP_Ev
	 description: Pop a Value from the Stack
	*/
	inline bool CpuRunnerLLVM::handler_in_8F_00_POP_Ev(Bit8u insb) {
		return true;
	}

	/* _90_XCHG_rAXvqp
	 description: Exchange Register/Memory with Register
	*/
	inline bool CpuRunnerLLVM::handler_in_90_XCHG_rAXvqp(Bit8u insb) {
		return true;
	}

	/* _91_XCHG_rAXvqp
	 description: Exchange Register/Memory with Register
	*/
	inline bool CpuRunnerLLVM::handler_in_91_XCHG_rAXvqp(Bit8u insb) {
		return true;
	}

	/* _92_XCHG_rAXvqp
	 description: Exchange Register/Memory with Register
	*/
	inline bool CpuRunnerLLVM::handler_in_92_XCHG_rAXvqp(Bit8u insb) {
		return true;
	}

	/* _93_XCHG_rAXvqp
	 description: Exchange Register/Memory with Register
	*/
	inline bool CpuRunnerLLVM::handler_in_93_XCHG_rAXvqp(Bit8u insb) {
		return true;
	}

	/* _94_XCHG_rAXvqp
	 description: Exchange Register/Memory with Register
	*/
	inline bool CpuRunnerLLVM::handler_in_94_XCHG_rAXvqp(Bit8u insb) {
		return true;
	}

	/* _95_XCHG_rAXvqp
	 description: Exchange Register/Memory with Register
	*/
	inline bool CpuRunnerLLVM::handler_in_95_XCHG_rAXvqp(Bit8u insb) {
		return true;
	}

	/* _96_XCHG_rAXvqp
	 description: Exchange Register/Memory with Register
	*/
	inline bool CpuRunnerLLVM::handler_in_96_XCHG_rAXvqp(Bit8u insb) {
		return true;
	}

	/* _97_XCHG_rAXvqp
	 description: Exchange Register/Memory with Register
	*/
	inline bool CpuRunnerLLVM::handler_in_97_XCHG_rAXvqp(Bit8u insb) {
		return true;
	}

	/* _98_CBW
	 description: Convert Byte to Word
	*/
	inline bool CpuRunnerLLVM::handler_in_98_CBW(Bit8u insb) {
		return true;
	}

	/* _98_CWDE
	 description: Convert Word to Doubleword
	*/
	inline bool CpuRunnerLLVM::handler_in_98_CWDE(Bit8u insb) {
		return true;
	}

	/* _99_CDQ
	 description: Convert Doubleword to Quadword
	*/
	inline bool CpuRunnerLLVM::handler_in_99_CDQ(Bit8u insb) {
		return true;
	}

	/* _99_CWD
	 description: Convert Word to Doubleword
	*/
	inline bool CpuRunnerLLVM::handler_in_99_CWD(Bit8u insb) {
		return true;
	}

	/* _9A_CALLF_Ap
	 description: Call Procedure
	*/
	inline bool CpuRunnerLLVM::handler_in_9A_CALLF_Ap(Bit8u insb) {
		return true;
	}

	/* _9B_FWAIT
	 description: Check pending unmasked floating-point exceptions
	*/
	inline bool CpuRunnerLLVM::handler_in_9B_FWAIT(Bit8u insb) {
		return true;
	}

	/* _9C_PUSHF
	 description: Push FLAGS Register onto the Stack
	*/
	inline bool CpuRunnerLLVM::handler_in_9C_PUSHF(Bit8u insb) {
		return true;
	}

	/* _9D_POPF
	 description: Pop Stack into FLAGS Register
	*/
	inline bool CpuRunnerLLVM::handler_in_9D_POPF(Bit8u insb) {
		return true;
	}

	/* _9E_SAHF
	 description: Store AH into Flags
	*/
	inline bool CpuRunnerLLVM::handler_in_9E_SAHF(Bit8u insb) {
		return true;
	}

	/* _9F_LAHF
	 description: Load Status Flags into AH Register
	*/
	inline bool CpuRunnerLLVM::handler_in_9F_LAHF(Bit8u insb) {
		return true;
	}

	/* _A0_MOV_ALb_Ob
	 description: Move
	*/
	inline bool CpuRunnerLLVM::handler_in_A0_MOV_ALb_Ob(Bit8u insb) {
		return true;
	}

	/* _A1_MOV_rAXvqp_Ovqp
	 description: Move
	*/
	inline bool CpuRunnerLLVM::handler_in_A1_MOV_rAXvqp_Ovqp(Bit8u insb) {
		return true;
	}

	/* _A2_MOV_Ob_ALb
	 description: Move
	*/
	inline bool CpuRunnerLLVM::handler_in_A2_MOV_Ob_ALb(Bit8u insb) {
		return true;
	}

	/* _A3_MOV_Ovqp_rAXvqp
	 description: Move
	*/
	inline bool CpuRunnerLLVM::handler_in_A3_MOV_Ovqp_rAXvqp(Bit8u insb) {
		return true;
	}

	/* _A4_MOVS_Yb_Xb
	 description: Move Data from String to String
	*/
	inline bool CpuRunnerLLVM::handler_in_A4_MOVS_Yb_Xb(Bit8u insb) {
		return true;
	}

	/* _A5_MOVS_Ywo_Xwo
	 description: Move Data from String to String
	*/
	inline bool CpuRunnerLLVM::handler_in_A5_MOVS_Ywo_Xwo(Bit8u insb) {
		return true;
	}

	/* _A6_CMPS_Xb
	 description: Compare String Operands
	*/
	inline bool CpuRunnerLLVM::handler_in_A6_CMPS_Xb(Bit8u insb) {
		return true;
	}

	/* _A7_CMPS_Xwo
	 description: Compare String Operands
	*/
	inline bool CpuRunnerLLVM::handler_in_A7_CMPS_Xwo(Bit8u insb) {
		return true;
	}

	/* _A8_TEST_Ib
	 description: Logical Compare
	*/
	inline bool CpuRunnerLLVM::handler_in_A8_TEST_Ib(Bit8u insb) {
		return true;
	}

	/* _A9_TEST_Ivds
	 description: Logical Compare
	*/
	inline bool CpuRunnerLLVM::handler_in_A9_TEST_Ivds(Bit8u insb) {
		return true;
	}

	/* _AA_STOS_Yb
	 description: Store String
	*/
	inline bool CpuRunnerLLVM::handler_in_AA_STOS_Yb(Bit8u insb) {
		return true;
	}

	/* _AB_STOS_Ywo
	 description: Store String
	*/
	inline bool CpuRunnerLLVM::handler_in_AB_STOS_Ywo(Bit8u insb) {
		return true;
	}

	/* _AC_LODS_Xb
	 description: Load String
	*/
	inline bool CpuRunnerLLVM::handler_in_AC_LODS_Xb(Bit8u insb) {
		return true;
	}

	/* _AD_LODS_Xwo
	 description: Load String
	*/
	inline bool CpuRunnerLLVM::handler_in_AD_LODS_Xwo(Bit8u insb) {
		return true;
	}

	/* _AE_SCAS_Yb
	 description: Scan String
	*/
	inline bool CpuRunnerLLVM::handler_in_AE_SCAS_Yb(Bit8u insb) {
		return true;
	}

	/* _AF_SCAS_Ywo
	 description: Scan String
	*/
	inline bool CpuRunnerLLVM::handler_in_AF_SCAS_Ywo(Bit8u insb) {
		return true;
	}

	/* _B0_MOV_ALb_Ib
	 description: Move
	*/
	inline bool CpuRunnerLLVM::handler_in_B0_MOV_ALb_Ib(Bit8u insb) {
		return true;
	}

	/* _B1_MOV_CLb_Ib
	 description: Move
	*/
	inline bool CpuRunnerLLVM::handler_in_B1_MOV_CLb_Ib(Bit8u insb) {
		return true;
	}

	/* _B2_MOV_DLb_Ib
	 description: Move
	*/
	inline bool CpuRunnerLLVM::handler_in_B2_MOV_DLb_Ib(Bit8u insb) {
		return true;
	}

	/* _B4_MOV_AHb_Ib
	 description: Move
	*/
	inline bool CpuRunnerLLVM::handler_in_B4_MOV_AHb_Ib(Bit8u insb) {
		return true;
	}

	/* _B5_MOV_CHb_Ib
	 description: Move
	*/
	inline bool CpuRunnerLLVM::handler_in_B5_MOV_CHb_Ib(Bit8u insb) {
		return true;
	}

	/* _B6_MOV_DHb_Ib
	 description: Move
	*/
	inline bool CpuRunnerLLVM::handler_in_B6_MOV_DHb_Ib(Bit8u insb) {
		return true;
	}

	/* _B7_MOV_BHb_Ib
	 description: Move
	*/
	inline bool CpuRunnerLLVM::handler_in_B7_MOV_BHb_Ib(Bit8u insb) {
		return true;
	}

	/* _B8_MOV_rAXvqp_Ivqp
	 description: Move
	*/
	inline bool CpuRunnerLLVM::handler_in_B8_MOV_rAXvqp_Ivqp(Bit8u insb) {
		return true;
	}

	/* _B9_MOV_rCXvqp_Ivqp
	 description: Move
	*/
	inline bool CpuRunnerLLVM::handler_in_B9_MOV_rCXvqp_Ivqp(Bit8u insb) {
		return true;
	}

	/* _BA_MOV_rDXvqp_Ivqp
	 description: Move
	*/
	inline bool CpuRunnerLLVM::handler_in_BA_MOV_rDXvqp_Ivqp(Bit8u insb) {
		return true;
	}

	/* _BB_MOV_rBXvqp_Ivqp
	 description: Move
	*/
	inline bool CpuRunnerLLVM::handler_in_BB_MOV_rBXvqp_Ivqp(Bit8u insb) {
		return true;
	}

	/* _BC_MOV_rSPvqp_Ivqp
	 description: Move
	*/
	inline bool CpuRunnerLLVM::handler_in_BC_MOV_rSPvqp_Ivqp(Bit8u insb) {
		return true;
	}

	/* _BD_MOV_rBPvqp_Ivqp
	 description: Move
	*/
	inline bool CpuRunnerLLVM::handler_in_BD_MOV_rBPvqp_Ivqp(Bit8u insb) {
		return true;
	}

	/* _BE_MOV_rSIvqp_Ivqp
	 description: Move
	*/
	inline bool CpuRunnerLLVM::handler_in_BE_MOV_rSIvqp_Ivqp(Bit8u insb) {
		return true;
	}

	/* _BF_MOV_rDIvqp_Ivqp
	 description: Move
	*/
	inline bool CpuRunnerLLVM::handler_in_BF_MOV_rDIvqp_Ivqp(Bit8u insb) {
		return true;
	}

	/* _C0_00_ROL_Eb_Ib
	 description: Rotate
	*/
	inline bool CpuRunnerLLVM::handler_in_C0_00_ROL_Eb_Ib(Bit8u insb) {
		return true;
	}

	/* _C0_01_ROR_Eb_Ib
	 description: Rotate
	*/
	inline bool CpuRunnerLLVM::handler_in_C0_01_ROR_Eb_Ib(Bit8u insb) {
		return true;
	}

	/* _C0_02_RCL_Eb_Ib
	 description: Rotate
	*/
	inline bool CpuRunnerLLVM::handler_in_C0_02_RCL_Eb_Ib(Bit8u insb) {
		return true;
	}

	/* _C0_03_RCR_Eb_Ib
	 description: Rotate
	*/
	inline bool CpuRunnerLLVM::handler_in_C0_03_RCR_Eb_Ib(Bit8u insb) {
		return true;
	}

	/* _C0_04_SHL_Eb_Ib
	 description: Shift
	*/
	inline bool CpuRunnerLLVM::handler_in_C0_04_SHL_Eb_Ib(Bit8u insb) {
		return true;
	}

	/* _C0_05_SHR_Eb_Ib
	 description: Shift
	*/
	inline bool CpuRunnerLLVM::handler_in_C0_05_SHR_Eb_Ib(Bit8u insb) {
		return true;
	}

	/* _C0_06_SAL_Eb_Ib
	 description: Shift
	*/
	inline bool CpuRunnerLLVM::handler_in_C0_06_SAL_Eb_Ib(Bit8u insb) {
		return true;
	}

	/* _C0_07_SAR_Eb_Ib
	 description: Shift
	*/
	inline bool CpuRunnerLLVM::handler_in_C0_07_SAR_Eb_Ib(Bit8u insb) {
		return true;
	}

	/* _C1_00_ROL_Evqp_Ib
	 description: Rotate
	*/
	inline bool CpuRunnerLLVM::handler_in_C1_00_ROL_Evqp_Ib(Bit8u insb) {
		return true;
	}

	/* _C1_01_ROR_Evqp_Ib
	 description: Rotate
	*/
	inline bool CpuRunnerLLVM::handler_in_C1_01_ROR_Evqp_Ib(Bit8u insb) {
		return true;
	}

	/* _C1_02_RCL_Evqp_Ib
	 description: Rotate
	*/
	inline bool CpuRunnerLLVM::handler_in_C1_02_RCL_Evqp_Ib(Bit8u insb) {
		return true;
	}

	/* _C1_03_RCR_Evqp_Ib
	 description: Rotate
	*/
	inline bool CpuRunnerLLVM::handler_in_C1_03_RCR_Evqp_Ib(Bit8u insb) {
		return true;
	}

	/* _C1_04_SHL_Evqp_Ib
	 description: Shift
	*/
	inline bool CpuRunnerLLVM::handler_in_C1_04_SHL_Evqp_Ib(Bit8u insb) {
		return true;
	}

	/* _C1_05_SHR_Evqp_Ib
	 description: Shift
	*/
	inline bool CpuRunnerLLVM::handler_in_C1_05_SHR_Evqp_Ib(Bit8u insb) {
		return true;
	}

	/* _C1_06_SAL_Evqp_Ib
	 description: Shift
	*/
	inline bool CpuRunnerLLVM::handler_in_C1_06_SAL_Evqp_Ib(Bit8u insb) {
		return true;
	}

	/* _C1_07_SAR_Evqp_Ib
	 description: Shift
	*/
	inline bool CpuRunnerLLVM::handler_in_C1_07_SAR_Evqp_Ib(Bit8u insb) {
		return true;
	}

	/* _C2_RETN_Iw
	 description: Return from procedure
	*/
	inline bool CpuRunnerLLVM::handler_in_C2_RETN_Iw(Bit8u insb) {
		return true;
	}

	/* _C3_RETN
	 description: Return from procedure
	*/
	inline bool CpuRunnerLLVM::handler_in_C3_RETN(Bit8u insb) {
		return true;
	}

	/* _C4_LES_Gv_Mp
	 description: Load Far Pointer
	*/
	inline bool CpuRunnerLLVM::handler_in_C4_LES_Gv_Mp(Bit8u insb) {
		return true;
	}

	/* _C5_LDS_Gv_Mp
	 description: Load Far Pointer
	*/
	inline bool CpuRunnerLLVM::handler_in_C5_LDS_Gv_Mp(Bit8u insb) {
		return true;
	}

	/* _C6_00_MOV_Eb_Ib
	 description: Move
	*/
	inline bool CpuRunnerLLVM::handler_in_C6_00_MOV_Eb_Ib(Bit8u insb) {
		return true;
	}

	/* _C7_00_MOV_Evqp_Ivds
	 description: Move
	*/
	inline bool CpuRunnerLLVM::handler_in_C7_00_MOV_Evqp_Ivds(Bit8u insb) {
		return true;
	}

	/* _C8_ENTER_Ib
	 description: Make Stack Frame for Procedure Parameters
	*/
	inline bool CpuRunnerLLVM::handler_in_C8_ENTER_Ib(Bit8u insb) {
		return true;
	}

	/* _C9_LEAVE
	 description: High Level Procedure Exit
	*/
	inline bool CpuRunnerLLVM::handler_in_C9_LEAVE(Bit8u insb) {
		return true;
	}

	/* _CA_RETF_Iw
	 description: Return from procedure
	*/
	inline bool CpuRunnerLLVM::handler_in_CA_RETF_Iw(Bit8u insb) {
		return true;
	}

	/* _CB_RETF
	 description: Return from procedure
	*/
	inline bool CpuRunnerLLVM::handler_in_CB_RETF(Bit8u insb) {
		return true;
	}

	/* _CC_INT
	 description: Call to Interrupt Procedure
	*/
	inline bool CpuRunnerLLVM::handler_in_CC_INT(Bit8u insb) {
		return true;
	}

	/* _CD_INT_Ib
	 description: Call to Interrupt Procedure
	*/
	inline bool CpuRunnerLLVM::handler_in_CD_INT_Ib(Bit8u insb) {
		return true;
	}

	/* _CE_INTO
	 description: Call to Interrupt Procedure
	*/
	inline bool CpuRunnerLLVM::handler_in_CE_INTO(Bit8u insb) {
		return true;
	}

	/* _CF_IRET
	 description: Interrupt Return
	*/
	inline bool CpuRunnerLLVM::handler_in_CF_IRET(Bit8u insb) {
		return true;
	}

	/* _D0_00_ROL_Eb
	 description: Rotate
	*/
	inline bool CpuRunnerLLVM::handler_in_D0_00_ROL_Eb(Bit8u insb) {
		return true;
	}

	/* _D0_01_ROR_Eb
	 description: Rotate
	*/
	inline bool CpuRunnerLLVM::handler_in_D0_01_ROR_Eb(Bit8u insb) {
		return true;
	}

	/* _D0_02_RCL_Eb
	 description: Rotate
	*/
	inline bool CpuRunnerLLVM::handler_in_D0_02_RCL_Eb(Bit8u insb) {
		return true;
	}

	/* _D0_03_RCR_Eb
	 description: Rotate
	*/
	inline bool CpuRunnerLLVM::handler_in_D0_03_RCR_Eb(Bit8u insb) {
		return true;
	}

	/* _D0_04_SHL_Eb
	 description: Shift
	*/
	inline bool CpuRunnerLLVM::handler_in_D0_04_SHL_Eb(Bit8u insb) {
		return true;
	}

	/* _D0_05_SHR_Eb
	 description: Shift
	*/
	inline bool CpuRunnerLLVM::handler_in_D0_05_SHR_Eb(Bit8u insb) {
		return true;
	}

	/* _D0_06_SAL_Eb
	 description: Shift
	*/
	inline bool CpuRunnerLLVM::handler_in_D0_06_SAL_Eb(Bit8u insb) {
		return true;
	}

	/* _D0_07_SAR_Eb
	 description: Shift
	*/
	inline bool CpuRunnerLLVM::handler_in_D0_07_SAR_Eb(Bit8u insb) {
		return true;
	}

	/* _D1_00_ROL_Evqp
	 description: Rotate
	*/
	inline bool CpuRunnerLLVM::handler_in_D1_00_ROL_Evqp(Bit8u insb) {
		return true;
	}

	/* _D1_01_ROR_Evqp
	 description: Rotate
	*/
	inline bool CpuRunnerLLVM::handler_in_D1_01_ROR_Evqp(Bit8u insb) {
		return true;
	}

	/* _D1_02_RCL_Evqp
	 description: Rotate
	*/
	inline bool CpuRunnerLLVM::handler_in_D1_02_RCL_Evqp(Bit8u insb) {
		return true;
	}

	/* _D1_03_RCR_Evqp
	 description: Rotate
	*/
	inline bool CpuRunnerLLVM::handler_in_D1_03_RCR_Evqp(Bit8u insb) {
		return true;
	}

	/* _D1_04_SHL_Evqp
	 description: Shift
	*/
	inline bool CpuRunnerLLVM::handler_in_D1_04_SHL_Evqp(Bit8u insb) {
		return true;
	}

	/* _D1_05_SHR_Evqp
	 description: Shift
	*/
	inline bool CpuRunnerLLVM::handler_in_D1_05_SHR_Evqp(Bit8u insb) {
		return true;
	}

	/* _D1_06_SAL_Evqp
	 description: Shift
	*/
	inline bool CpuRunnerLLVM::handler_in_D1_06_SAL_Evqp(Bit8u insb) {
		return true;
	}

	/* _D1_07_SAR_Evqp
	 description: Shift
	*/
	inline bool CpuRunnerLLVM::handler_in_D1_07_SAR_Evqp(Bit8u insb) {
		return true;
	}

	/* _D2_00_ROL_Eb_CLb
	 description: Rotate
	*/
	inline bool CpuRunnerLLVM::handler_in_D2_00_ROL_Eb_CLb(Bit8u insb) {
		return true;
	}

	/* _D2_01_ROR_Eb_CLb
	 description: Rotate
	*/
	inline bool CpuRunnerLLVM::handler_in_D2_01_ROR_Eb_CLb(Bit8u insb) {
		return true;
	}

	/* _D2_02_RCL_Eb_CLb
	 description: Rotate
	*/
	inline bool CpuRunnerLLVM::handler_in_D2_02_RCL_Eb_CLb(Bit8u insb) {
		return true;
	}

	/* _D2_03_RCR_Eb_CLb
	 description: Rotate
	*/
	inline bool CpuRunnerLLVM::handler_in_D2_03_RCR_Eb_CLb(Bit8u insb) {
		return true;
	}

	/* _D2_04_SHL_Eb_CLb
	 description: Shift
	*/
	inline bool CpuRunnerLLVM::handler_in_D2_04_SHL_Eb_CLb(Bit8u insb) {
		return true;
	}

	/* _D2_05_SHR_Eb_CLb
	 description: Shift
	*/
	inline bool CpuRunnerLLVM::handler_in_D2_05_SHR_Eb_CLb(Bit8u insb) {
		return true;
	}

	/* _D2_06_SAL_Eb_CLb
	 description: Shift
	*/
	inline bool CpuRunnerLLVM::handler_in_D2_06_SAL_Eb_CLb(Bit8u insb) {
		return true;
	}

	/* _D2_07_SAR_Eb_CLb
	 description: Shift
	*/
	inline bool CpuRunnerLLVM::handler_in_D2_07_SAR_Eb_CLb(Bit8u insb) {
		return true;
	}

	/* _D3_00_ROL_Evqp_CLb
	 description: Rotate
	*/
	inline bool CpuRunnerLLVM::handler_in_D3_00_ROL_Evqp_CLb(Bit8u insb) {
		return true;
	}

	/* _D3_01_ROR_Evqp_CLb
	 description: Rotate
	*/
	inline bool CpuRunnerLLVM::handler_in_D3_01_ROR_Evqp_CLb(Bit8u insb) {
		return true;
	}

	/* _D3_02_RCL_Evqp_CLb
	 description: Rotate
	*/
	inline bool CpuRunnerLLVM::handler_in_D3_02_RCL_Evqp_CLb(Bit8u insb) {
		return true;
	}

	/* _D3_03_RCR_Evqp_CLb
	 description: Rotate
	*/
	inline bool CpuRunnerLLVM::handler_in_D3_03_RCR_Evqp_CLb(Bit8u insb) {
		return true;
	}

	/* _D3_04_SHL_Evqp_CLb
	 description: Shift
	*/
	inline bool CpuRunnerLLVM::handler_in_D3_04_SHL_Evqp_CLb(Bit8u insb) {
		return true;
	}

	/* _D3_05_SHR_Evqp_CLb
	 description: Shift
	*/
	inline bool CpuRunnerLLVM::handler_in_D3_05_SHR_Evqp_CLb(Bit8u insb) {
		return true;
	}

	/* _D3_06_SAL_Evqp_CLb
	 description: Shift
	*/
	inline bool CpuRunnerLLVM::handler_in_D3_06_SAL_Evqp_CLb(Bit8u insb) {
		return true;
	}

	/* _D3_07_SAR_Evqp_CLb
	 description: Shift
	*/
	inline bool CpuRunnerLLVM::handler_in_D3_07_SAR_Evqp_CLb(Bit8u insb) {
		return true;
	}

	/* _D4_AMX_Ib
	 description: Adjust AX After Multiply
	*/
	inline bool CpuRunnerLLVM::handler_in_D4_AMX_Ib(Bit8u insb) {
		return true;
	}

	/* _D5_ADX_Ib
	 description: Adjust AX Before Division
	*/
	inline bool CpuRunnerLLVM::handler_in_D5_ADX_Ib(Bit8u insb) {
		return true;
	}

	/* _D6_SALC
	 description: Set AL If Carry
	*/
	inline bool CpuRunnerLLVM::handler_in_D6_SALC(Bit8u insb) {
		return true;
	}

	/* _D7_XLAT_BBb
	 description: Table Look-up Translation
	*/
	inline bool CpuRunnerLLVM::handler_in_D7_XLAT_BBb(Bit8u insb) {
		return true;
	}

	/* _E0_LOOPNZ_Jbs
	 description: Decrement count; Jump short if count!=0 and ZF=0
	*/
	inline bool CpuRunnerLLVM::handler_in_E0_LOOPNZ_Jbs(Bit8u insb) {
		return true;
	}

	/* _E1_LOOPZ_Jbs
	 description: Decrement count; Jump short if count!=0 and ZF=1
	*/
	inline bool CpuRunnerLLVM::handler_in_E1_LOOPZ_Jbs(Bit8u insb) {
		return true;
	}

	/* _E2_LOOP_Jbs
	 description: Decrement count; Jump short if count!=0
	*/
	inline bool CpuRunnerLLVM::handler_in_E2_LOOP_Jbs(Bit8u insb) {
		return true;
	}

	/* _E3_JCXZ_Jbs
	 description: Jump short if eCX register is 0
	*/
	inline bool CpuRunnerLLVM::handler_in_E3_JCXZ_Jbs(Bit8u insb) {
		return true;
	}

	/* _E4_IN_ALb_Ib
	 description: Input from Port
	*/
	inline bool CpuRunnerLLVM::handler_in_E4_IN_ALb_Ib(Bit8u insb) {
		return true;
	}

	/* _E5_IN_rAXv_Ib
	 description: Input from Port
	*/
	inline bool CpuRunnerLLVM::handler_in_E5_IN_rAXv_Ib(Bit8u insb) {
		return true;
	}

	/* _E6_OUT_Ib_ALb
	 description: Output to Port
	*/
	inline bool CpuRunnerLLVM::handler_in_E6_OUT_Ib_ALb(Bit8u insb) {
		return true;
	}

	/* _E7_OUT_Ib_rAXv
	 description: Output to Port
	*/
	inline bool CpuRunnerLLVM::handler_in_E7_OUT_Ib_rAXv(Bit8u insb) {
		return true;
	}

	/* _E8_CALL_Jvds
	 description: Call Procedure
	*/
	inline bool CpuRunnerLLVM::handler_in_E8_CALL_Jvds(Bit8u insb) {
		return true;
	}

	/* _E9_JMP_Jvds
	 description: Jump
	*/
	inline bool CpuRunnerLLVM::handler_in_E9_JMP_Jvds(Bit8u insb) {
		return true;
	}

	/* _EA_JMPF_Ap
	 description: Jump
	*/
	inline bool CpuRunnerLLVM::handler_in_EA_JMPF_Ap(Bit8u insb) {
		return true;
	}

	/* _EB_JMP_Jbs
	 description: Jump
	*/
	inline bool CpuRunnerLLVM::handler_in_EB_JMP_Jbs(Bit8u insb) {
		return true;
	}

	/* _EC_IN_ALb_DXw
	 description: Input from Port
	*/
	inline bool CpuRunnerLLVM::handler_in_EC_IN_ALb_DXw(Bit8u insb) {
		return true;
	}

	/* _ED_IN_rAXv_DXw
	 description: Input from Port
	*/
	inline bool CpuRunnerLLVM::handler_in_ED_IN_rAXv_DXw(Bit8u insb) {
		return true;
	}

	/* _EE_OUT_DXw_ALb
	 description: Output to Port
	*/
	inline bool CpuRunnerLLVM::handler_in_EE_OUT_DXw_ALb(Bit8u insb) {
		return true;
	}

	/* _EF_OUT_DXw_rAXv
	 description: Output to Port
	*/
	inline bool CpuRunnerLLVM::handler_in_EF_OUT_DXw_rAXv(Bit8u insb) {
		return true;
	}

	/* _F1_INT1
	 description: Call to Interrupt Procedure
	*/
	inline bool CpuRunnerLLVM::handler_in_F1_INT1(Bit8u insb) {
		return true;
	}

	/* _F3_0F_B8_POPCNT_Gvqp_Evqp
	 description: Bit Population Count
	*/
	inline bool CpuRunnerLLVM::handler_in_F3_0F_B8_POPCNT_Gvqp_Evqp(Bit8u insb) {
		return true;
	}

	/* _F3_90_NOP
	 description: No Operation
	*/
	inline bool CpuRunnerLLVM::handler_in_F3_90_NOP(Bit8u insb) {
		return true;
	}

	/* _F4_HLT
	 description: Halt
	*/
	inline bool CpuRunnerLLVM::handler_in_F4_HLT(Bit8u insb) {
		return true;
	}

	/* _F5_CMC
	 description: Complement Carry Flag
	*/
	inline bool CpuRunnerLLVM::handler_in_F5_CMC(Bit8u insb) {
		return true;
	}

	/* _F6_01_TEST_Ib
	 description: Logical Compare
	*/
	inline bool CpuRunnerLLVM::handler_in_F6_01_TEST_Ib(Bit8u insb) {
		return true;
	}

	/* _F6_02_NOT_Eb
	 description: One's Complement Negation
	*/
	inline bool CpuRunnerLLVM::handler_in_F6_02_NOT_Eb(Bit8u insb) {
		return true;
	}

	/* _F6_03_NEG_Eb
	 description: Two's Complement Negation
	*/
	inline bool CpuRunnerLLVM::handler_in_F6_03_NEG_Eb(Bit8u insb) {
		return true;
	}

	/* _F6_04_MUL_Eb
	 description: Unsigned Multiply
	*/
	inline bool CpuRunnerLLVM::handler_in_F6_04_MUL_Eb(Bit8u insb) {
		return true;
	}

	/* _F6_05_IMUL_Eb
	 description: Signed Multiply
	*/
	inline bool CpuRunnerLLVM::handler_in_F6_05_IMUL_Eb(Bit8u insb) {
		return true;
	}

	/* _F6_06_DIV_Eb
	 description: Unsigned Divide
	*/
	inline bool CpuRunnerLLVM::handler_in_F6_06_DIV_Eb(Bit8u insb) {
		return true;
	}

	/* _F6_07_IDIV_Eb
	 description: Signed Divide
	*/
	inline bool CpuRunnerLLVM::handler_in_F6_07_IDIV_Eb(Bit8u insb) {
		return true;
	}

	/* _F7_01_TEST_Ivqp
	 description: Logical Compare
	*/
	inline bool CpuRunnerLLVM::handler_in_F7_01_TEST_Ivqp(Bit8u insb) {
		return true;
	}

	/* _F7_02_NOT_Evqp
	 description: One's Complement Negation
	*/
	inline bool CpuRunnerLLVM::handler_in_F7_02_NOT_Evqp(Bit8u insb) {
		return true;
	}

	/* _F7_03_NEG_Evqp
	 description: Two's Complement Negation
	*/
	inline bool CpuRunnerLLVM::handler_in_F7_03_NEG_Evqp(Bit8u insb) {
		return true;
	}

	/* _F7_04_MUL_Evqp
	 description: Unsigned Multiply
	*/
	inline bool CpuRunnerLLVM::handler_in_F7_04_MUL_Evqp(Bit8u insb) {
		return true;
	}

	/* _F7_05_IMUL_Evqp
	 description: Signed Multiply
	*/
	inline bool CpuRunnerLLVM::handler_in_F7_05_IMUL_Evqp(Bit8u insb) {
		return true;
	}

	/* _F7_06_DIV_Evqp
	 description: Unsigned Divide
	*/
	inline bool CpuRunnerLLVM::handler_in_F7_06_DIV_Evqp(Bit8u insb) {
		return true;
	}

	/* _F7_07_IDIV_Evqp
	 description: Signed Divide
	*/
	inline bool CpuRunnerLLVM::handler_in_F7_07_IDIV_Evqp(Bit8u insb) {
		return true;
	}

	/* _F8_CLC
	 description: Clear Carry Flag
	*/
	inline bool CpuRunnerLLVM::handler_in_F8_CLC(Bit8u insb) {
		return true;
	}

	/* _F9_STC
	 description: Set Carry Flag
	*/
	inline bool CpuRunnerLLVM::handler_in_F9_STC(Bit8u insb) {
		return true;
	}

	/* _FA_CLI
	 description: Clear Interrupt Flag
	*/
	inline bool CpuRunnerLLVM::handler_in_FA_CLI(Bit8u insb) {
		return true;
	}

	/* _FB_STI
	 description: Set Interrupt Flag
	*/
	inline bool CpuRunnerLLVM::handler_in_FB_STI(Bit8u insb) {
		return true;
	}

	/* _FC_CLD
	 description: Clear Direction Flag
	*/
	inline bool CpuRunnerLLVM::handler_in_FC_CLD(Bit8u insb) {
		return true;
	}

	/* _FD_STD
	 description: Set Direction Flag
	*/
	inline bool CpuRunnerLLVM::handler_in_FD_STD(Bit8u insb) {
		return true;
	}

	/* _FE_00_INC_Eb
	 description: Increment by 1
	*/
	inline bool CpuRunnerLLVM::handler_in_FE_00_INC_Eb(Bit8u insb) {
		return true;
	}

	/* _FE_01_DEC_Eb
	 description: Decrement by 1
	*/
	inline bool CpuRunnerLLVM::handler_in_FE_01_DEC_Eb(Bit8u insb) {
		return true;
	}

	/* _FF_00_INC_Evqp
	 description: Increment by 1
	*/
	inline bool CpuRunnerLLVM::handler_in_FF_00_INC_Evqp(Bit8u insb) {
		return true;
	}

	/* _FF_01_DEC_Evqp
	 description: Decrement by 1
	*/
	inline bool CpuRunnerLLVM::handler_in_FF_01_DEC_Evqp(Bit8u insb) {
		return true;
	}

	/* _FF_02_CALL_Ev
	 description: Call Procedure
	*/
	inline bool CpuRunnerLLVM::handler_in_FF_02_CALL_Ev(Bit8u insb) {
		return true;
	}

	/* _FF_03_CALLF_Mptp
	 description: Call Procedure
	*/
	inline bool CpuRunnerLLVM::handler_in_FF_03_CALLF_Mptp(Bit8u insb) {
		return true;
	}

	/* _FF_04_JMP_Ev
	 description: Jump
	*/
	inline bool CpuRunnerLLVM::handler_in_FF_04_JMP_Ev(Bit8u insb) {
		return true;
	}

	/* _FF_05_JMPF_Mptp
	 description: Jump
	*/
	inline bool CpuRunnerLLVM::handler_in_FF_05_JMPF_Mptp(Bit8u insb) {
		return true;
	}

	/* _FF_06_PUSH_Ev
	 description: Push Word, Doubleword or Quadword Onto the Stack
	*/
	inline bool CpuRunnerLLVM::handler_in_FF_06_PUSH_Ev(Bit8u insb) {
		return true;
	}

	inline bool CpuRunnerLLVM::handler_st(Bit8u insb) {

		switch(insb) {
		case 0x00:
			return handler_in_00_ADD_Eb_Gb(insb);
		case 0x01:
			return handler_in_01_ADD_Evqp_Gvqp(insb);
		case 0x02:
			return handler_in_02_ADD_Gb_Eb(insb);
		case 0x03:
			return handler_in_03_ADD_Gvqp_Evqp(insb);
		case 0x04:
			return handler_in_04_ADD_ALb_Ib(insb);
		case 0x05:
			return handler_in_05_ADD_rAXvqp_Ivds(insb);
		case 0x06:
			return handler_in_06_PUSH_ESw(insb);
		case 0x07:
			return handler_in_07_POP_ESw(insb);
		case 0x08:
			return handler_in_08_OR_Eb_Gb(insb);
		case 0x09:
			return handler_in_09_OR_Evqp_Gvqp(insb);
		case 0x0a:
			return handler_in_0A_OR_Gb_Eb(insb);
		case 0x0b:
			return handler_in_0B_OR_Gvqp_Evqp(insb);
		case 0x0c:
			return handler_in_0C_OR_ALb_Ib(insb);
		case 0x0d:
			return handler_in_0D_OR_rAXvqp_Ivds(insb);
		case 0x0e:
			return handler_in_0E_PUSH_CSw(insb);
		case 0x0f:
			insb = Fetchb();
			return handler_st_0F(insb);
		case 0x10:
			return handler_in_10_ADC_Eb_Gb(insb);
		case 0x11:
			return handler_in_11_ADC_Evqp_Gvqp(insb);
		case 0x12:
			return handler_in_12_ADC_Gb_Eb(insb);
		case 0x13:
			return handler_in_13_ADC_Gvqp_Evqp(insb);
		case 0x14:
			return handler_in_14_ADC_ALb_Ib(insb);
		case 0x15:
			return handler_in_15_ADC_rAXvqp_Ivds(insb);
		case 0x16:
			return handler_in_16_PUSH_SSw(insb);
		case 0x17:
			return handler_in_17_POP_SSw(insb);
		case 0x18:
			return handler_in_18_SBB_Eb_Gb(insb);
		case 0x19:
			return handler_in_19_SBB_Evqp_Gvqp(insb);
		case 0x1a:
			return handler_in_1A_SBB_Gb_Eb(insb);
		case 0x1b:
			return handler_in_1B_SBB_Gvqp_Evqp(insb);
		case 0x1c:
			return handler_in_1C_SBB_ALb_Ib(insb);
		case 0x1d:
			return handler_in_1D_SBB_rAXvqp_Ivds(insb);
		case 0x1e:
			return handler_in_1E_PUSH_DSw(insb);
		case 0x1f:
			return handler_in_1F_POP_DSw(insb);
		case 0x20:
			return handler_in_20_AND_Eb_Gb(insb);
		case 0x21:
			return handler_in_21_AND_Evqp_Gvqp(insb);
		case 0x22:
			return handler_in_22_AND_Gb_Eb(insb);
		case 0x23:
			return handler_in_23_AND_Gvqp_Evqp(insb);
		case 0x24:
			return handler_in_24_AND_ALb_Ib(insb);
		case 0x25:
			return handler_in_25_AND_rAXvqp_Ivds(insb);
		case 0x27:
			return handler_in_27_DAA(insb);
		case 0x28:
			return handler_in_28_SUB_Eb_Gb(insb);
		case 0x29:
			return handler_in_29_SUB_Evqp_Gvqp(insb);
		case 0x2a:
			return handler_in_2A_SUB_Gb_Eb(insb);
		case 0x2b:
			return handler_in_2B_SUB_Gvqp_Evqp(insb);
		case 0x2c:
			return handler_in_2C_SUB_ALb_Ib(insb);
		case 0x2d:
			return handler_in_2D_SUB_rAXvqp_Ivds(insb);
		case 0x2f:
			return handler_in_2F_DAS(insb);
		case 0x30:
			return handler_in_30_XOR_Eb_Gb(insb);
		case 0x31:
			return handler_in_31_XOR_Evqp_Gvqp(insb);
		case 0x32:
			return handler_in_32_XOR_Gb_Eb(insb);
		case 0x33:
			return handler_in_33_XOR_Gvqp_Evqp(insb);
		case 0x34:
			return handler_in_34_XOR_ALb_Ib(insb);
		case 0x35:
			return handler_in_35_XOR_rAXvqp_Ivds(insb);
		case 0x37:
			return handler_in_37_AAA(insb);
		case 0x38:
			return handler_in_38_CMP_Gb(insb);
		case 0x39:
			return handler_in_39_CMP_Gvqp(insb);
		case 0x3a:
			return handler_in_3A_CMP_Eb(insb);
		case 0x3b:
			return handler_in_3B_CMP_Evqp(insb);
		case 0x3c:
			return handler_in_3C_CMP_Ib(insb);
		case 0x3d:
			return handler_in_3D_CMP_Ivds(insb);
		case 0x3f:
			return handler_in_3F_AAS(insb);
		case 0x40:
			return handler_in_40_INC_rAXv(insb);
		case 0x41:
			return handler_in_41_INC_rCXv(insb);
		case 0x42:
			return handler_in_42_INC_rDXv(insb);
		case 0x43:
			return handler_in_43_INC_rBXv(insb);
		case 0x44:
			return handler_in_44_INC_rSPv(insb);
		case 0x45:
			return handler_in_45_INC_rBPv(insb);
		case 0x46:
			return handler_in_46_INC_rSIv(insb);
		case 0x47:
			return handler_in_47_INC_rDIv(insb);
		case 0x48:
			return handler_in_48_DEC_rAXv(insb);
		case 0x49:
			return handler_in_49_DEC_rCXv(insb);
		case 0x4a:
			return handler_in_4A_DEC_rDXv(insb);
		case 0x4b:
			return handler_in_4B_DEC_rBXv(insb);
		case 0x4c:
			return handler_in_4C_DEC_rSPv(insb);
		case 0x4d:
			return handler_in_4D_DEC_rBPv(insb);
		case 0x4e:
			return handler_in_4E_DEC_rSIv(insb);
		case 0x4f:
			return handler_in_4F_DEC_rDIv(insb);
		case 0x50:
			return handler_in_50_PUSH_rAXv(insb);
		case 0x51:
			return handler_in_51_PUSH_rCXv(insb);
		case 0x52:
			return handler_in_52_PUSH_rDXv(insb);
		case 0x53:
			return handler_in_53_PUSH_rBXv(insb);
		case 0x54:
			return handler_in_54_PUSH_rSPv(insb);
		case 0x55:
			return handler_in_55_PUSH_rBPv(insb);
		case 0x56:
			return handler_in_56_PUSH_rSIv(insb);
		case 0x57:
			return handler_in_57_PUSH_rDIv(insb);
		case 0x58:
			return handler_in_58_POP_rAXv(insb);
		case 0x59:
			return handler_in_59_POP_rCXv(insb);
		case 0x5a:
			return handler_in_5A_POP_rDXv(insb);
		case 0x5b:
			return handler_in_5B_POP_rBXv(insb);
		case 0x5c:
			return handler_in_5C_POP_rSPv(insb);
		case 0x5d:
			return handler_in_5D_POP_rBPv(insb);
		case 0x5e:
			return handler_in_5E_POP_rSIv(insb);
		case 0x5f:
			return handler_in_5F_POP_rDIv(insb);
		case 0x60:
			return handler_in_60_PUSHA(insb);
		case 0x61:
			return handler_in_61_POPA(insb);
		case 0x62:
			return handler_in_62_BOUND_Ma(insb);
		case 0x63:
			return handler_in_63_ARPL_Gw(insb);
		case 0x66:
			return handler_st_66(insb);
		case 0x68:
			return handler_in_68_PUSH_Ivs(insb);
		case 0x69:
			return handler_in_69_IMUL_Gvqp_Ivds(insb);
		case 0x6a:
			return handler_in_6A_PUSH_Ibss(insb);
		case 0x6b:
			return handler_in_6B_IMUL_Gvqp_Ibs(insb);
		case 0x6c:
			return handler_in_6C_INS_Yb_DXw(insb);
		case 0x6d:
			return handler_in_6D_INS_Ywo_DXw(insb);
		case 0x6e:
			return handler_in_6E_OUTS_DXw_Xb(insb);
		case 0x6f:
			return handler_in_6F_OUTS_DXw_Xwo(insb);
		case 0x70:
			return handler_in_70_JO_Jbs(insb);
		case 0x71:
			return handler_in_71_JNO_Jbs(insb);
		case 0x72:
			return handler_in_72_JB_Jbs(insb);
		case 0x73:
			return handler_in_73_JNB_Jbs(insb);
		case 0x74:
			return handler_in_74_JZ_Jbs(insb);
		case 0x75:
			return handler_in_75_JNZ_Jbs(insb);
		case 0x76:
			return handler_in_76_JBE_Jbs(insb);
		case 0x77:
			return handler_in_77_JNBE_Jbs(insb);
		case 0x78:
			return handler_in_78_JS_Jbs(insb);
		case 0x79:
			return handler_in_79_JNS_Jbs(insb);
		case 0x7a:
			return handler_in_7A_JP_Jbs(insb);
		case 0x7b:
			return handler_in_7B_JNP_Jbs(insb);
		case 0x7c:
			return handler_in_7C_JL_Jbs(insb);
		case 0x7d:
			return handler_in_7D_JNL_Jbs(insb);
		case 0x7e:
			return handler_in_7E_JLE_Jbs(insb);
		case 0x7f:
			return handler_in_7F_JNLE_Jbs(insb);
		case 0x81:
			return handler_st_81(insb);
		case 0x82:
			return handler_st_82(insb);
		case 0x83:
			return handler_st_83(insb);
		case 0x84:
			return handler_in_84_TEST_Gb(insb);
		case 0x85:
			return handler_in_85_TEST_Gvqp(insb);
		case 0x86:
			return handler_in_86_XCHG_Eb(insb);
		case 0x87:
			return handler_in_87_XCHG_Evqp(insb);
		case 0x88:
			return handler_in_88_MOV_Eb_Gb(insb);
		case 0x89:
			return handler_in_89_MOV_Evqp_Gvqp(insb);
		case 0x8a:
			return handler_in_8A_MOV_Gb_Eb(insb);
		case 0x8b:
			return handler_in_8B_MOV_Gvqp_Evqp(insb);
		case 0x8c:
			return handler_in_8C_MOV_Mw_Sw(insb);
		case 0x8d:
			return handler_in_8D_LEA_Gvqp(insb);
		case 0x8e:
			return handler_in_8E_MOV_Sw_Ew(insb);
		case 0x8f:
			return handler_st_8F(insb);
		case 0x90:
			return handler_in_90_XCHG_rAXvqp(insb);
		case 0x91:
			return handler_in_91_XCHG_rAXvqp(insb);
		case 0x92:
			return handler_in_92_XCHG_rAXvqp(insb);
		case 0x93:
			return handler_in_93_XCHG_rAXvqp(insb);
		case 0x94:
			return handler_in_94_XCHG_rAXvqp(insb);
		case 0x95:
			return handler_in_95_XCHG_rAXvqp(insb);
		case 0x96:
			return handler_in_96_XCHG_rAXvqp(insb);
		case 0x97:
			return handler_in_97_XCHG_rAXvqp(insb);
		case 0x98:
			return handler_in_98_CWDE(insb);
		case 0x99:
			return handler_in_99_CDQ(insb);
		case 0x9a:
			return handler_in_9A_CALLF_Ap(insb);
		case 0x9b:
			return handler_in_9B_FWAIT(insb);
		case 0x9c:
			return handler_in_9C_PUSHF(insb);
		case 0x9d:
			return handler_in_9D_POPF(insb);
		case 0x9e:
			return handler_in_9E_SAHF(insb);
		case 0x9f:
			return handler_in_9F_LAHF(insb);
		case 0xa0:
			return handler_in_A0_MOV_ALb_Ob(insb);
		case 0xa1:
			return handler_in_A1_MOV_rAXvqp_Ovqp(insb);
		case 0xa2:
			return handler_in_A2_MOV_Ob_ALb(insb);
		case 0xa3:
			return handler_in_A3_MOV_Ovqp_rAXvqp(insb);
		case 0xa4:
			return handler_in_A4_MOVS_Yb_Xb(insb);
		case 0xa5:
			return handler_in_A5_MOVS_Ywo_Xwo(insb);
		case 0xa6:
			return handler_in_A6_CMPS_Xb(insb);
		case 0xa7:
			return handler_in_A7_CMPS_Xwo(insb);
		case 0xa8:
			return handler_in_A8_TEST_Ib(insb);
		case 0xa9:
			return handler_in_A9_TEST_Ivds(insb);
		case 0xaa:
			return handler_in_AA_STOS_Yb(insb);
		case 0xab:
			return handler_in_AB_STOS_Ywo(insb);
		case 0xac:
			return handler_in_AC_LODS_Xb(insb);
		case 0xad:
			return handler_in_AD_LODS_Xwo(insb);
		case 0xae:
			return handler_in_AE_SCAS_Yb(insb);
		case 0xaf:
			return handler_in_AF_SCAS_Ywo(insb);
		case 0xb0:
			return handler_in_B0_MOV_ALb_Ib(insb);
		case 0xb1:
			return handler_in_B1_MOV_CLb_Ib(insb);
		case 0xb2:
			return handler_in_B2_MOV_DLb_Ib(insb);
		case 0xb4:
			return handler_in_B4_MOV_AHb_Ib(insb);
		case 0xb5:
			return handler_in_B5_MOV_CHb_Ib(insb);
		case 0xb6:
			return handler_in_B6_MOV_DHb_Ib(insb);
		case 0xb7:
			return handler_in_B7_MOV_BHb_Ib(insb);
		case 0xb8:
			return handler_in_B8_MOV_rAXvqp_Ivqp(insb);
		case 0xb9:
			return handler_in_B9_MOV_rCXvqp_Ivqp(insb);
		case 0xba:
			return handler_in_BA_MOV_rDXvqp_Ivqp(insb);
		case 0xbb:
			return handler_in_BB_MOV_rBXvqp_Ivqp(insb);
		case 0xbc:
			return handler_in_BC_MOV_rSPvqp_Ivqp(insb);
		case 0xbd:
			return handler_in_BD_MOV_rBPvqp_Ivqp(insb);
		case 0xbe:
			return handler_in_BE_MOV_rSIvqp_Ivqp(insb);
		case 0xbf:
			return handler_in_BF_MOV_rDIvqp_Ivqp(insb);
		case 0xc0:
			return handler_st_C0(insb);
		case 0xc1:
			return handler_st_C1(insb);
		case 0xc2:
			return handler_in_C2_RETN_Iw(insb);
		case 0xc3:
			return handler_in_C3_RETN(insb);
		case 0xc4:
			return handler_in_C4_LES_Gv_Mp(insb);
		case 0xc5:
			return handler_in_C5_LDS_Gv_Mp(insb);
		case 0xc6:
			return handler_st_C6(insb);
		case 0xc7:
			return handler_st_C7(insb);
		case 0xc8:
			return handler_in_C8_ENTER_Ib(insb);
		case 0xc9:
			return handler_in_C9_LEAVE(insb);
		case 0xca:
			return handler_in_CA_RETF_Iw(insb);
		case 0xcb:
			return handler_in_CB_RETF(insb);
		case 0xcc:
			return handler_in_CC_INT(insb);
		case 0xcd:
			return handler_in_CD_INT_Ib(insb);
		case 0xce:
			return handler_in_CE_INTO(insb);
		case 0xcf:
			return handler_in_CF_IRET(insb);
		case 0xd0:
			return handler_st_D0(insb);
		case 0xd1:
			return handler_st_D1(insb);
		case 0xd2:
			return handler_st_D2(insb);
		case 0xd3:
			return handler_st_D3(insb);
		case 0xd4:
			return handler_in_D4_AMX_Ib(insb);
		case 0xd5:
			return handler_in_D5_ADX_Ib(insb);
		case 0xd6:
			return handler_in_D6_SALC(insb);
		case 0xd7:
			return handler_in_D7_XLAT_BBb(insb);
		case 0xe0:
			return handler_in_E0_LOOPNZ_Jbs(insb);
		case 0xe1:
			return handler_in_E1_LOOPZ_Jbs(insb);
		case 0xe2:
			return handler_in_E2_LOOP_Jbs(insb);
		case 0xe3:
			return handler_in_E3_JCXZ_Jbs(insb);
		case 0xe4:
			return handler_in_E4_IN_ALb_Ib(insb);
		case 0xe5:
			return handler_in_E5_IN_rAXv_Ib(insb);
		case 0xe6:
			return handler_in_E6_OUT_Ib_ALb(insb);
		case 0xe7:
			return handler_in_E7_OUT_Ib_rAXv(insb);
		case 0xe8:
			return handler_in_E8_CALL_Jvds(insb);
		case 0xe9:
			return handler_in_E9_JMP_Jvds(insb);
		case 0xea:
			return handler_in_EA_JMPF_Ap(insb);
		case 0xeb:
			return handler_in_EB_JMP_Jbs(insb);
		case 0xec:
			return handler_in_EC_IN_ALb_DXw(insb);
		case 0xed:
			return handler_in_ED_IN_rAXv_DXw(insb);
		case 0xee:
			return handler_in_EE_OUT_DXw_ALb(insb);
		case 0xef:
			return handler_in_EF_OUT_DXw_rAXv(insb);
		case 0xf1:
			return handler_in_F1_INT1(insb);
		case 0xf2:
			return handler_st_F2(insb);
		case 0xf3:
			insb = Fetchb();
			return handler_st_F3(insb);
		case 0xf4:
			return handler_in_F4_HLT(insb);
		case 0xf5:
			return handler_in_F5_CMC(insb);
		case 0xf6:
			return handler_st_F6(insb);
		case 0xf7:
			return handler_st_F7(insb);
		case 0xf8:
			return handler_in_F8_CLC(insb);
		case 0xf9:
			return handler_in_F9_STC(insb);
		case 0xfa:
			return handler_in_FA_CLI(insb);
		case 0xfb:
			return handler_in_FB_STI(insb);
		case 0xfc:
			return handler_in_FC_CLD(insb);
		case 0xfd:
			return handler_in_FD_STD(insb);
		case 0xfe:
			return handler_st_FE(insb);
		case 0xff:
			return handler_st_FF(insb);

		default:
			break;
		};
		return false;
	};

	inline bool CpuRunnerLLVM::handler_st_0F(Bit8u insb) {

		switch(insb) {
		case 0x00:
			return handler_st_0F_00(insb);
		case 0x01:
			insb = Fetchb();
			return handler_st_0F_01(insb);
		case 0x02:
			return handler_in_0F_02_LAR_Gvqp_Mw(insb);
		case 0x03:
			return handler_in_0F_03_LSL_Gvqp_Mw(insb);
		case 0x06:
			return handler_in_0F_06_CLTS(insb);
		case 0x07:
			return handler_in_0F_07_LOADALL(insb);
		case 0x08:
			return handler_in_0F_08_INVD(insb);
		case 0x09:
			return handler_in_0F_09_WBINVD(insb);
		case 0x1f:
			return handler_st_0F_1F(insb);
		case 0x20:
			return handler_in_0F_20_MOV_Hd_Cd(insb);
		case 0x21:
			return handler_in_0F_21_MOV_Hd_Dd(insb);
		case 0x22:
			return handler_in_0F_22_MOV_Cd_Hd(insb);
		case 0x23:
			return handler_in_0F_23_MOV_Dq_Hq(insb);
		case 0x24:
			return handler_in_0F_24_MOV_Hd_Td(insb);
		case 0x26:
			return handler_in_0F_26_MOV_Td_Hd(insb);
		case 0x30:
			return handler_in_0F_30_WRMSR(insb);
		case 0x31:
			return handler_in_0F_31_RDTSC(insb);
		case 0x32:
			return handler_in_0F_32_RDMSR(insb);
		case 0x33:
			return handler_in_0F_33_RDPMC(insb);
		case 0x34:
			return handler_in_0F_34_SYSENTER(insb);
		case 0x35:
			return handler_in_0F_35_SYSEXIT(insb);
		case 0x38:
			insb = Fetchb();
			return handler_st_0F_38(insb);
		case 0x40:
			return handler_in_0F_40_CMOVO_Gvqp_Evqp(insb);
		case 0x41:
			return handler_in_0F_41_CMOVNO_Gvqp_Evqp(insb);
		case 0x42:
			return handler_in_0F_42_CMOVB_Gvqp_Evqp(insb);
		case 0x43:
			return handler_in_0F_43_CMOVNB_Gvqp_Evqp(insb);
		case 0x44:
			return handler_in_0F_44_CMOVZ_Gvqp_Evqp(insb);
		case 0x45:
			return handler_in_0F_45_CMOVNZ_Gvqp_Evqp(insb);
		case 0x46:
			return handler_in_0F_46_CMOVBE_Gvqp_Evqp(insb);
		case 0x47:
			return handler_in_0F_47_CMOVNBE_Gvqp_Evqp(insb);
		case 0x48:
			return handler_in_0F_48_CMOVS_Gvqp_Evqp(insb);
		case 0x49:
			return handler_in_0F_49_CMOVNS_Gvqp_Evqp(insb);
		case 0x4a:
			return handler_in_0F_4A_CMOVP_Gvqp_Evqp(insb);
		case 0x4b:
			return handler_in_0F_4B_CMOVNP_Gvqp_Evqp(insb);
		case 0x4c:
			return handler_in_0F_4C_CMOVL_Gvqp_Evqp(insb);
		case 0x4d:
			return handler_in_0F_4D_CMOVNL_Gvqp_Evqp(insb);
		case 0x4e:
			return handler_in_0F_4E_CMOVLE_Gvqp_Evqp(insb);
		case 0x4f:
			return handler_in_0F_4F_CMOVNLE_Gvqp_Evqp(insb);
		case 0x80:
			return handler_in_0F_80_JO_Jvds(insb);
		case 0x81:
			return handler_in_0F_81_JNO_Jvds(insb);
		case 0x82:
			return handler_in_0F_82_JB_Jvds(insb);
		case 0x83:
			return handler_in_0F_83_JNB_Jvds(insb);
		case 0x84:
			return handler_in_0F_84_JZ_Jvds(insb);
		case 0x85:
			return handler_in_0F_85_JNZ_Jvds(insb);
		case 0x86:
			return handler_in_0F_86_JBE_Jvds(insb);
		case 0x87:
			return handler_in_0F_87_JNBE_Jvds(insb);
		case 0x88:
			return handler_in_0F_88_JS_Jvds(insb);
		case 0x89:
			return handler_in_0F_89_JNS_Jvds(insb);
		case 0x8a:
			return handler_in_0F_8A_JP_Jvds(insb);
		case 0x8b:
			return handler_in_0F_8B_JNP_Jvds(insb);
		case 0x8c:
			return handler_in_0F_8C_JL_Jvds(insb);
		case 0x8d:
			return handler_in_0F_8D_JNL_Jvds(insb);
		case 0x8e:
			return handler_in_0F_8E_JLE_Jvds(insb);
		case 0x8f:
			return handler_in_0F_8F_JNLE_Jvds(insb);
		case 0x90:
			return handler_st_0F_90(insb);
		case 0x91:
			return handler_st_0F_91(insb);
		case 0x92:
			return handler_st_0F_92(insb);
		case 0x93:
			return handler_st_0F_93(insb);
		case 0x94:
			return handler_st_0F_94(insb);
		case 0x95:
			return handler_st_0F_95(insb);
		case 0x96:
			return handler_st_0F_96(insb);
		case 0x97:
			return handler_st_0F_97(insb);
		case 0x98:
			return handler_st_0F_98(insb);
		case 0x99:
			return handler_st_0F_99(insb);
		case 0x9a:
			return handler_st_0F_9A(insb);
		case 0x9b:
			return handler_st_0F_9B(insb);
		case 0x9c:
			return handler_st_0F_9C(insb);
		case 0x9d:
			return handler_st_0F_9D(insb);
		case 0x9e:
			return handler_st_0F_9E(insb);
		case 0x9f:
			return handler_st_0F_9F(insb);
		case 0xa0:
			return handler_in_0F_A0_PUSH_FSw(insb);
		case 0xa1:
			return handler_in_0F_A1_POP_FSw(insb);
		case 0xa2:
			return handler_in_0F_A2_CPUID(insb);
		case 0xa3:
			return handler_in_0F_A3_BT_Gvqp(insb);
		case 0xa4:
			return handler_in_0F_A4_SHLD_Evqp_Ib(insb);
		case 0xa5:
			return handler_in_0F_A5_SHLD_Evqp_CLb(insb);
		case 0xa8:
			return handler_in_0F_A8_PUSH_GSw(insb);
		case 0xa9:
			return handler_in_0F_A9_POP_GSw(insb);
		case 0xaa:
			return handler_in_0F_AA_RSM(insb);
		case 0xab:
			return handler_in_0F_AB_BTS_Evqp_Gvqp(insb);
		case 0xac:
			return handler_in_0F_AC_SHRD_Evqp_Ib(insb);
		case 0xad:
			return handler_in_0F_AD_SHRD_Evqp_CLb(insb);
		case 0xae:
			return handler_st_0F_AE(insb);
		case 0xaf:
			return handler_in_0F_AF_IMUL_Gvqp_Evqp(insb);
		case 0xb0:
			return handler_in_0F_B0_CMPXCHG_Eb_Gb(insb);
		case 0xb1:
			return handler_in_0F_B1_CMPXCHG_Evqp_Gvqp(insb);
		case 0xb2:
			return handler_in_0F_B2_LSS_Gvqp_Mptp(insb);
		case 0xb3:
			return handler_in_0F_B3_BTR_Evqp_Gvqp(insb);
		case 0xb4:
			return handler_in_0F_B4_LFS_Gvqp_Mptp(insb);
		case 0xb5:
			return handler_in_0F_B5_LGS_Gvqp_Mptp(insb);
		case 0xb6:
			return handler_in_0F_B6_MOVZX_Gvqp_Eb(insb);
		case 0xb7:
			return handler_in_0F_B7_MOVZX_Gvqp_Ew(insb);
		case 0xba:
			return handler_st_0F_BA(insb);
		case 0xbb:
			return handler_in_0F_BB_BTC_Evqp_Gvqp(insb);
		case 0xbc:
			return handler_in_0F_BC_BSF_Gvqp_Evqp(insb);
		case 0xbd:
			return handler_in_0F_BD_BSR_Gvqp_Evqp(insb);
		case 0xbe:
			return handler_in_0F_BE_MOVSX_Gvqp_Eb(insb);
		case 0xbf:
			return handler_in_0F_BF_MOVSX_Gvqp_Ew(insb);
		case 0xc0:
			return handler_in_0F_C0_XADD_Gb(insb);
		case 0xc1:
			return handler_in_0F_C1_XADD_Gvqp(insb);
		case 0xc7:
			return handler_st_0F_C7(insb);
		case 0xc8:
			return handler_in_0F_C8_BSWAP_rAXvqp(insb);
		case 0xc9:
			return handler_in_0F_C9_BSWAP_rCXvqp(insb);
		case 0xca:
			return handler_in_0F_CA_BSWAP_rDXvqp(insb);
		case 0xcb:
			return handler_in_0F_CB_BSWAP_rBXvqp(insb);
		case 0xcc:
			return handler_in_0F_CC_BSWAP_rSPvqp(insb);
		case 0xcd:
			return handler_in_0F_CD_BSWAP_rBPvqp(insb);
		case 0xce:
			return handler_in_0F_CE_BSWAP_rSIvqp(insb);
		case 0xcf:
			return handler_in_0F_CF_BSWAP_rDIvqp(insb);

		default:
			break;
		};
		return false;
	};

	inline bool CpuRunnerLLVM::handler_st_0F_00(Bit8u insb) {

		Bit8u rmmod = Fetchb();
		Bit8u rm = static_cast<Bit8u>(rmmod & 0x38);
		Bit8u mod = static_cast<Bit8u>(rmmod & 0xc0);

		switch(rm) {
		case 0x00:
			if (mod != 0xc0)
				return handler_in_0F_00_00_SLDT_Mw(insb);
		case 0x01:
			if (mod != 0xc0)
				return handler_in_0F_00_01_STR_Mw(insb);
		case 0x02:
			return handler_in_0F_00_02_LLDT_Ew(insb);
		case 0x03:
			return handler_in_0F_00_03_LTR_Ew(insb);
		case 0x04:
			return handler_in_0F_00_04_VERR_Ew(insb);
		case 0x05:
			return handler_in_0F_00_05_VERW_Ew(insb);

		default:
			break;
		};
		return false;
	};

	inline bool CpuRunnerLLVM::handler_st_0F_01(Bit8u insb) {

		switch(insb) {
		case 0xd0:
			return handler_in_0F_01_D0_XGETBV(insb);
		case 0xd1:
			return handler_in_0F_01_D1_XSETBV(insb);
		case 0xf9:
			return handler_in_0F_01_F9_RDTSCP(insb);

		default:
			break;
		};

		Bit8u rmmod = Fetchb();
		Bit8u rm = static_cast<Bit8u>(rmmod & 0x38);
		Bit8u mod = static_cast<Bit8u>(rmmod & 0xc0);

		switch(rm) {
		case 0x00:
			return handler_in_0F_01_00_SGDT_Ms(insb);
		case 0x01:
			return handler_in_0F_01_01_SIDT_Ms(insb);
		case 0x02:
			return handler_in_0F_01_02_LGDT_Ms(insb);
		case 0x03:
			return handler_in_0F_01_03_LIDT_Ms(insb);
		case 0x04:
			if (mod != 0xc0)
				return handler_in_0F_01_04_SMSW_Mw(insb);
		case 0x06:
			return handler_in_0F_01_06_LMSW_Ew(insb);
		case 0x07:
			return handler_in_0F_01_07_INVLPG(insb);

		default:
			break;
		};
		return false;
	};

	inline bool CpuRunnerLLVM::handler_st_0F_1F(Bit8u insb) {

		Bit8u rmmod = Fetchb();
		Bit8u rm = static_cast<Bit8u>(rmmod & 0x38);

		switch(rm) {
		case 0x00:
			return handler_in_0F_1F_00_NOP_Ev(insb);
		case 0x07:
			return handler_in_0F_1F_07_HINT_NOP_Ev(insb);

		default:
			break;
		};
		return false;
	};

	inline bool CpuRunnerLLVM::handler_st_0F_38(Bit8u insb) {

		switch(insb) {
		case 0xf0:
			return handler_in_0F_38_F0_MOVBE_Gvqp_Mvqp(insb);
		case 0xf1:
			return handler_in_0F_38_F1_MOVBE_Mvqp_Gvqp(insb);

		default:
			break;
		};
		return false;
	};

	inline bool CpuRunnerLLVM::handler_st_0F_90(Bit8u insb) {

		Bit8u rmmod = Fetchb();
		Bit8u rm = static_cast<Bit8u>(rmmod & 0x38);

		switch(rm) {
		case 0x00:
			return handler_in_0F_90_00_SETO_Eb(insb);

		default:
			break;
		};
		return false;
	};

	inline bool CpuRunnerLLVM::handler_st_0F_91(Bit8u insb) {

		Bit8u rmmod = Fetchb();
		Bit8u rm = static_cast<Bit8u>(rmmod & 0x38);

		switch(rm) {
		case 0x00:
			return handler_in_0F_91_00_SETNO_Eb(insb);

		default:
			break;
		};
		return false;
	};

	inline bool CpuRunnerLLVM::handler_st_0F_92(Bit8u insb) {

		Bit8u rmmod = Fetchb();
		Bit8u rm = static_cast<Bit8u>(rmmod & 0x38);

		switch(rm) {
		case 0x00:
			return handler_in_0F_92_00_SETB_Eb(insb);

		default:
			break;
		};
		return false;
	};

	inline bool CpuRunnerLLVM::handler_st_0F_93(Bit8u insb) {

		Bit8u rmmod = Fetchb();
		Bit8u rm = static_cast<Bit8u>(rmmod & 0x38);

		switch(rm) {
		case 0x00:
			return handler_in_0F_93_00_SETNB_Eb(insb);

		default:
			break;
		};
		return false;
	};

	inline bool CpuRunnerLLVM::handler_st_0F_94(Bit8u insb) {

		Bit8u rmmod = Fetchb();
		Bit8u rm = static_cast<Bit8u>(rmmod & 0x38);

		switch(rm) {
		case 0x00:
			return handler_in_0F_94_00_SETZ_Eb(insb);

		default:
			break;
		};
		return false;
	};

	inline bool CpuRunnerLLVM::handler_st_0F_95(Bit8u insb) {

		Bit8u rmmod = Fetchb();
		Bit8u rm = static_cast<Bit8u>(rmmod & 0x38);

		switch(rm) {
		case 0x00:
			return handler_in_0F_95_00_SETNZ_Eb(insb);

		default:
			break;
		};
		return false;
	};

	inline bool CpuRunnerLLVM::handler_st_0F_96(Bit8u insb) {

		Bit8u rmmod = Fetchb();
		Bit8u rm = static_cast<Bit8u>(rmmod & 0x38);

		switch(rm) {
		case 0x00:
			return handler_in_0F_96_00_SETBE_Eb(insb);

		default:
			break;
		};
		return false;
	};

	inline bool CpuRunnerLLVM::handler_st_0F_97(Bit8u insb) {

		Bit8u rmmod = Fetchb();
		Bit8u rm = static_cast<Bit8u>(rmmod & 0x38);

		switch(rm) {
		case 0x00:
			return handler_in_0F_97_00_SETNBE_Eb(insb);

		default:
			break;
		};
		return false;
	};

	inline bool CpuRunnerLLVM::handler_st_0F_98(Bit8u insb) {

		Bit8u rmmod = Fetchb();
		Bit8u rm = static_cast<Bit8u>(rmmod & 0x38);

		switch(rm) {
		case 0x00:
			return handler_in_0F_98_00_SETS_Eb(insb);

		default:
			break;
		};
		return false;
	};

	inline bool CpuRunnerLLVM::handler_st_0F_99(Bit8u insb) {

		Bit8u rmmod = Fetchb();
		Bit8u rm = static_cast<Bit8u>(rmmod & 0x38);

		switch(rm) {
		case 0x00:
			return handler_in_0F_99_00_SETNS_Eb(insb);

		default:
			break;
		};
		return false;
	};

	inline bool CpuRunnerLLVM::handler_st_0F_9A(Bit8u insb) {

		Bit8u rmmod = Fetchb();
		Bit8u rm = static_cast<Bit8u>(rmmod & 0x38);

		switch(rm) {
		case 0x00:
			return handler_in_0F_9A_00_SETP_Eb(insb);

		default:
			break;
		};
		return false;
	};

	inline bool CpuRunnerLLVM::handler_st_0F_9B(Bit8u insb) {

		Bit8u rmmod = Fetchb();
		Bit8u rm = static_cast<Bit8u>(rmmod & 0x38);

		switch(rm) {
		case 0x00:
			return handler_in_0F_9B_00_SETNP_Eb(insb);

		default:
			break;
		};
		return false;
	};

	inline bool CpuRunnerLLVM::handler_st_0F_9C(Bit8u insb) {

		Bit8u rmmod = Fetchb();
		Bit8u rm = static_cast<Bit8u>(rmmod & 0x38);

		switch(rm) {
		case 0x00:
			return handler_in_0F_9C_00_SETL_Eb(insb);

		default:
			break;
		};
		return false;
	};

	inline bool CpuRunnerLLVM::handler_st_0F_9D(Bit8u insb) {

		Bit8u rmmod = Fetchb();
		Bit8u rm = static_cast<Bit8u>(rmmod & 0x38);

		switch(rm) {
		case 0x00:
			return handler_in_0F_9D_00_SETNL_Eb(insb);

		default:
			break;
		};
		return false;
	};

	inline bool CpuRunnerLLVM::handler_st_0F_9E(Bit8u insb) {

		Bit8u rmmod = Fetchb();
		Bit8u rm = static_cast<Bit8u>(rmmod & 0x38);

		switch(rm) {
		case 0x00:
			return handler_in_0F_9E_00_SETLE_Eb(insb);

		default:
			break;
		};
		return false;
	};

	inline bool CpuRunnerLLVM::handler_st_0F_9F(Bit8u insb) {

		Bit8u rmmod = Fetchb();
		Bit8u rm = static_cast<Bit8u>(rmmod & 0x38);

		switch(rm) {
		case 0x00:
			return handler_in_0F_9F_00_SETNLE_Eb(insb);

		default:
			break;
		};
		return false;
	};

	inline bool CpuRunnerLLVM::handler_st_0F_AE(Bit8u insb) {

		Bit8u rmmod = Fetchb();
		Bit8u rm = static_cast<Bit8u>(rmmod & 0x38);
		Bit8u mod = static_cast<Bit8u>(rmmod & 0xc0);

		switch(rm) {
		case 0x00:
			return handler_in_0F_AE_00_FXSAVE_Mstx(insb);
		case 0x01:
			return handler_in_0F_AE_01_FXRSTOR_Mstx(insb);
		case 0x04:
			return handler_in_0F_AE_04_XSAVE(insb);
		case 0x05:
			if (mod != 0xc0)
				return handler_in_0F_AE_05_XRSTOR(insb);

		default:
			break;
		};
		return false;
	};

	inline bool CpuRunnerLLVM::handler_st_0F_BA(Bit8u insb) {

		Bit8u rmmod = Fetchb();
		Bit8u rm = static_cast<Bit8u>(rmmod & 0x38);

		switch(rm) {
		case 0x04:
			return handler_in_0F_BA_04_BT_Ib(insb);
		case 0x05:
			return handler_in_0F_BA_05_BTS_Evqp_Ib(insb);
		case 0x06:
			return handler_in_0F_BA_06_BTR_Evqp_Ib(insb);
		case 0x07:
			return handler_in_0F_BA_07_BTC_Evqp_Ib(insb);

		default:
			break;
		};
		return false;
	};

	inline bool CpuRunnerLLVM::handler_st_0F_C7(Bit8u insb) {

		Bit8u rmmod = Fetchb();
		Bit8u rm = static_cast<Bit8u>(rmmod & 0x38);

		switch(rm) {
		case 0x01:
			return handler_in_0F_C7_01_CMPXCHG8B_Mq(insb);

		default:
			break;
		};
		return false;
	};

	inline bool CpuRunnerLLVM::handler_st_66(Bit8u insb) {
		return false;
	};

	inline bool CpuRunnerLLVM::handler_st_81(Bit8u insb) {

		Bit8u rmmod = Fetchb();
		Bit8u rm = static_cast<Bit8u>(rmmod & 0x38);

		switch(rm) {
		case 0x00:
			return handler_in_81_00_ADD_Evqp_Ivds(insb);
		case 0x01:
			return handler_in_81_01_OR_Evqp_Ivds(insb);
		case 0x02:
			return handler_in_81_02_ADC_Evqp_Ivds(insb);
		case 0x03:
			return handler_in_81_03_SBB_Evqp_Ivds(insb);
		case 0x04:
			return handler_in_81_04_AND_Evqp_Ivds(insb);
		case 0x05:
			return handler_in_81_05_SUB_Evqp_Ivds(insb);
		case 0x06:
			return handler_in_81_06_XOR_Evqp_Ivds(insb);
		case 0x07:
			return handler_in_81_07_CMP_Ivds(insb);

		default:
			break;
		};
		return false;
	};

	inline bool CpuRunnerLLVM::handler_st_82(Bit8u insb) {

		Bit8u rmmod = Fetchb();
		Bit8u rm = static_cast<Bit8u>(rmmod & 0x38);

		switch(rm) {
		case 0x00:
			return handler_in_82_00_ADD_Eb_Ib(insb);
		case 0x01:
			return handler_in_82_01_OR_Eb_Ib(insb);
		case 0x02:
			return handler_in_82_02_ADC_Eb_Ib(insb);
		case 0x03:
			return handler_in_82_03_SBB_Eb_Ib(insb);
		case 0x04:
			return handler_in_82_04_AND_Eb_Ib(insb);
		case 0x05:
			return handler_in_82_05_SUB_Eb_Ib(insb);
		case 0x06:
			return handler_in_82_06_XOR_Eb_Ib(insb);
		case 0x07:
			return handler_in_82_07_CMP_Ib(insb);

		default:
			break;
		};
		return false;
	};

	inline bool CpuRunnerLLVM::handler_st_83(Bit8u insb) {

		Bit8u rmmod = Fetchb();
		Bit8u rm = static_cast<Bit8u>(rmmod & 0x38);

		switch(rm) {
		case 0x00:
			return handler_in_83_00_ADD_Evqp_Ibs(insb);
		case 0x01:
			return handler_in_83_01_OR_Evqp_Ibs(insb);
		case 0x02:
			return handler_in_83_02_ADC_Evqp_Ibs(insb);
		case 0x03:
			return handler_in_83_03_SBB_Evqp_Ibs(insb);
		case 0x04:
			return handler_in_83_04_AND_Evqp_Ibs(insb);
		case 0x05:
			return handler_in_83_05_SUB_Evqp_Ibs(insb);
		case 0x06:
			return handler_in_83_06_XOR_Evqp_Ibs(insb);
		case 0x07:
			return handler_in_83_07_CMP_Ibs(insb);

		default:
			break;
		};
		return false;
	};

	inline bool CpuRunnerLLVM::handler_st_8F(Bit8u insb) {

		Bit8u rmmod = Fetchb();
		Bit8u rm = static_cast<Bit8u>(rmmod & 0x38);

		switch(rm) {
		case 0x00:
			return handler_in_8F_00_POP_Ev(insb);

		default:
			break;
		};
		return false;
	};

	inline bool CpuRunnerLLVM::handler_st_C0(Bit8u insb) {

		Bit8u rmmod = Fetchb();
		Bit8u rm = static_cast<Bit8u>(rmmod & 0x38);

		switch(rm) {
		case 0x00:
			return handler_in_C0_00_ROL_Eb_Ib(insb);
		case 0x01:
			return handler_in_C0_01_ROR_Eb_Ib(insb);
		case 0x02:
			return handler_in_C0_02_RCL_Eb_Ib(insb);
		case 0x03:
			return handler_in_C0_03_RCR_Eb_Ib(insb);
		case 0x04:
			return handler_in_C0_04_SHL_Eb_Ib(insb);
		case 0x05:
			return handler_in_C0_05_SHR_Eb_Ib(insb);
		case 0x06:
			return handler_in_C0_06_SAL_Eb_Ib(insb);
		case 0x07:
			return handler_in_C0_07_SAR_Eb_Ib(insb);

		default:
			break;
		};
		return false;
	};

	inline bool CpuRunnerLLVM::handler_st_C1(Bit8u insb) {

		Bit8u rmmod = Fetchb();
		Bit8u rm = static_cast<Bit8u>(rmmod & 0x38);

		switch(rm) {
		case 0x00:
			return handler_in_C1_00_ROL_Evqp_Ib(insb);
		case 0x01:
			return handler_in_C1_01_ROR_Evqp_Ib(insb);
		case 0x02:
			return handler_in_C1_02_RCL_Evqp_Ib(insb);
		case 0x03:
			return handler_in_C1_03_RCR_Evqp_Ib(insb);
		case 0x04:
			return handler_in_C1_04_SHL_Evqp_Ib(insb);
		case 0x05:
			return handler_in_C1_05_SHR_Evqp_Ib(insb);
		case 0x06:
			return handler_in_C1_06_SAL_Evqp_Ib(insb);
		case 0x07:
			return handler_in_C1_07_SAR_Evqp_Ib(insb);

		default:
			break;
		};
		return false;
	};

	inline bool CpuRunnerLLVM::handler_st_C6(Bit8u insb) {

		Bit8u rmmod = Fetchb();
		Bit8u rm = static_cast<Bit8u>(rmmod & 0x38);

		switch(rm) {
		case 0x00:
			return handler_in_C6_00_MOV_Eb_Ib(insb);

		default:
			break;
		};
		return false;
	};

	inline bool CpuRunnerLLVM::handler_st_C7(Bit8u insb) {

		Bit8u rmmod = Fetchb();
		Bit8u rm = static_cast<Bit8u>(rmmod & 0x38);

		switch(rm) {
		case 0x00:
			return handler_in_C7_00_MOV_Evqp_Ivds(insb);

		default:
			break;
		};
		return false;
	};

	inline bool CpuRunnerLLVM::handler_st_D0(Bit8u insb) {

		Bit8u rmmod = Fetchb();
		Bit8u rm = static_cast<Bit8u>(rmmod & 0x38);

		switch(rm) {
		case 0x00:
			return handler_in_D0_00_ROL_Eb(insb);
		case 0x01:
			return handler_in_D0_01_ROR_Eb(insb);
		case 0x02:
			return handler_in_D0_02_RCL_Eb(insb);
		case 0x03:
			return handler_in_D0_03_RCR_Eb(insb);
		case 0x04:
			return handler_in_D0_04_SHL_Eb(insb);
		case 0x05:
			return handler_in_D0_05_SHR_Eb(insb);
		case 0x06:
			return handler_in_D0_06_SAL_Eb(insb);
		case 0x07:
			return handler_in_D0_07_SAR_Eb(insb);

		default:
			break;
		};
		return false;
	};

	inline bool CpuRunnerLLVM::handler_st_D1(Bit8u insb) {

		Bit8u rmmod = Fetchb();
		Bit8u rm = static_cast<Bit8u>(rmmod & 0x38);

		switch(rm) {
		case 0x00:
			return handler_in_D1_00_ROL_Evqp(insb);
		case 0x01:
			return handler_in_D1_01_ROR_Evqp(insb);
		case 0x02:
			return handler_in_D1_02_RCL_Evqp(insb);
		case 0x03:
			return handler_in_D1_03_RCR_Evqp(insb);
		case 0x04:
			return handler_in_D1_04_SHL_Evqp(insb);
		case 0x05:
			return handler_in_D1_05_SHR_Evqp(insb);
		case 0x06:
			return handler_in_D1_06_SAL_Evqp(insb);
		case 0x07:
			return handler_in_D1_07_SAR_Evqp(insb);

		default:
			break;
		};
		return false;
	};

	inline bool CpuRunnerLLVM::handler_st_D2(Bit8u insb) {

		Bit8u rmmod = Fetchb();
		Bit8u rm = static_cast<Bit8u>(rmmod & 0x38);

		switch(rm) {
		case 0x00:
			return handler_in_D2_00_ROL_Eb_CLb(insb);
		case 0x01:
			return handler_in_D2_01_ROR_Eb_CLb(insb);
		case 0x02:
			return handler_in_D2_02_RCL_Eb_CLb(insb);
		case 0x03:
			return handler_in_D2_03_RCR_Eb_CLb(insb);
		case 0x04:
			return handler_in_D2_04_SHL_Eb_CLb(insb);
		case 0x05:
			return handler_in_D2_05_SHR_Eb_CLb(insb);
		case 0x06:
			return handler_in_D2_06_SAL_Eb_CLb(insb);
		case 0x07:
			return handler_in_D2_07_SAR_Eb_CLb(insb);

		default:
			break;
		};
		return false;
	};

	inline bool CpuRunnerLLVM::handler_st_D3(Bit8u insb) {

		Bit8u rmmod = Fetchb();
		Bit8u rm = static_cast<Bit8u>(rmmod & 0x38);

		switch(rm) {
		case 0x00:
			return handler_in_D3_00_ROL_Evqp_CLb(insb);
		case 0x01:
			return handler_in_D3_01_ROR_Evqp_CLb(insb);
		case 0x02:
			return handler_in_D3_02_RCL_Evqp_CLb(insb);
		case 0x03:
			return handler_in_D3_03_RCR_Evqp_CLb(insb);
		case 0x04:
			return handler_in_D3_04_SHL_Evqp_CLb(insb);
		case 0x05:
			return handler_in_D3_05_SHR_Evqp_CLb(insb);
		case 0x06:
			return handler_in_D3_06_SAL_Evqp_CLb(insb);
		case 0x07:
			return handler_in_D3_07_SAR_Evqp_CLb(insb);

		default:
			break;
		};
		return false;
	};

	inline bool CpuRunnerLLVM::handler_st_F2(Bit8u insb) {
		return false;
	};

	inline bool CpuRunnerLLVM::handler_st_F3(Bit8u insb) {

		switch(insb) {
		case 0x90:
			return handler_in_F3_90_NOP(insb);

		default:
			break;
		};
		return false;
	};

	inline bool CpuRunnerLLVM::handler_st_F3_0F(Bit8u insb) {

		switch(insb) {
		case 0xb8:
			return handler_in_F3_0F_B8_POPCNT_Gvqp_Evqp(insb);

		default:
			break;
		};
		return false;
	};

	inline bool CpuRunnerLLVM::handler_st_F6(Bit8u insb) {

		Bit8u rmmod = Fetchb();
		Bit8u rm = static_cast<Bit8u>(rmmod & 0x38);

		switch(rm) {
		case 0x01:
			return handler_in_F6_01_TEST_Ib(insb);
		case 0x02:
			return handler_in_F6_02_NOT_Eb(insb);
		case 0x03:
			return handler_in_F6_03_NEG_Eb(insb);
		case 0x04:
			return handler_in_F6_04_MUL_Eb(insb);
		case 0x05:
			return handler_in_F6_05_IMUL_Eb(insb);
		case 0x06:
			return handler_in_F6_06_DIV_Eb(insb);
		case 0x07:
			return handler_in_F6_07_IDIV_Eb(insb);

		default:
			break;
		};
		return false;
	};

	inline bool CpuRunnerLLVM::handler_st_F7(Bit8u insb) {

		Bit8u rmmod = Fetchb();
		Bit8u rm = static_cast<Bit8u>(rmmod & 0x38);

		switch(rm) {
		case 0x01:
			return handler_in_F7_01_TEST_Ivqp(insb);
		case 0x02:
			return handler_in_F7_02_NOT_Evqp(insb);
		case 0x03:
			return handler_in_F7_03_NEG_Evqp(insb);
		case 0x04:
			return handler_in_F7_04_MUL_Evqp(insb);
		case 0x05:
			return handler_in_F7_05_IMUL_Evqp(insb);
		case 0x06:
			return handler_in_F7_06_DIV_Evqp(insb);
		case 0x07:
			return handler_in_F7_07_IDIV_Evqp(insb);

		default:
			break;
		};
		return false;
	};

	inline bool CpuRunnerLLVM::handler_st_FE(Bit8u insb) {

		Bit8u rmmod = Fetchb();
		Bit8u rm = static_cast<Bit8u>(rmmod & 0x38);

		switch(rm) {
		case 0x00:
			return handler_in_FE_00_INC_Eb(insb);
		case 0x01:
			return handler_in_FE_01_DEC_Eb(insb);

		default:
			break;
		};
		return false;
	};

	inline bool CpuRunnerLLVM::handler_st_FF(Bit8u insb) {

		Bit8u rmmod = Fetchb();
		Bit8u rm = static_cast<Bit8u>(rmmod & 0x38);

		switch(rm) {
		case 0x00:
			return handler_in_FF_00_INC_Evqp(insb);
		case 0x01:
			return handler_in_FF_01_DEC_Evqp(insb);
		case 0x02:
			return handler_in_FF_02_CALL_Ev(insb);
		case 0x03:
			return handler_in_FF_03_CALLF_Mptp(insb);
		case 0x04:
			return handler_in_FF_04_JMP_Ev(insb);
		case 0x05:
			return handler_in_FF_05_JMPF_Mptp(insb);
		case 0x06:
			return handler_in_FF_06_PUSH_Ev(insb);

		default:
			break;
		};
		return false;
	};

	Bit8u CpuRunnerLLVM::ParsePrefix() {
		option_prefix.all_prefix = 0;
		mandatory_prefix = 0;
		bool expect_prefix = false;
		Bit8u insb = 0;
		do {
			insb = Fetchb();
			switch (insb) {
			case 0x26:
				handler_pr26();
				mandatory_prefix = 0;
				break;
			case 0x2e:
				handler_pr2E();
				mandatory_prefix = 0;
				break;
			case 0x36:
				handler_pr36();
				mandatory_prefix = 0;
				break;
			case 0x3e:
				handler_pr3E();
				mandatory_prefix = 0;
				break;
			case 0x64:
				handler_pr64();
				mandatory_prefix = 0;
				break;
			case 0x65:
				handler_pr65();
				mandatory_prefix = 0;
				break;
			case 0x66:
				handler_pr66();
				mandatory_prefix = insb;
				break;
			case 0x67:
				handler_pr67();
				mandatory_prefix = 0;
				break;
			case 0xf0:
				handler_prF0();
				mandatory_prefix = 0;
				break;
			case 0xf2:
				handler_prF2();
				mandatory_prefix = insb;
				break;
			case 0xf3:
				handler_prF3();
				mandatory_prefix = insb;
				break;
			default:
				expect_prefix = true;
				break;
			}
		} while (expect_prefix);
		return insb;
	}


	bool CpuRunnerLLVM::Parse() {
		Bit8u insb = ParsePrefix();
		return handler_st(insb);
	}

}

