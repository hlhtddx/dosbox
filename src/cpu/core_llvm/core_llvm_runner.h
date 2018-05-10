#include "core_llvm_common.h"

#ifndef PROJECT_CORE_LLVM_H
#define PROJECT_CORE_LLVM_H
namespace core_llvm {

	class CpuRunnerLLVM : public CpuRunnerLLVMBase {

	private:

		inline bool handler_pr26();

		inline bool handler_pr2E();

		inline bool handler_pr36();

		inline bool handler_pr3E();

		inline bool handler_pr64();

		inline bool handler_pr65();

		inline bool handler_pr66();

		inline bool handler_pr67();

		inline bool handler_prF0();

		inline bool handler_prF2();

		inline bool handler_prF3();

		/* _00_ADD_Eb_Gb */
		inline bool handler_in_00_ADD_Eb_Gb(Bit8u insb);

		/* _01_ADD_Evqp_Gvqp */
		inline bool handler_in_01_ADD_Evqp_Gvqp(Bit8u insb);

		/* _02_ADD_Gb_Eb */
		inline bool handler_in_02_ADD_Gb_Eb(Bit8u insb);

		/* _03_ADD_Gvqp_Evqp */
		inline bool handler_in_03_ADD_Gvqp_Evqp(Bit8u insb);

		/* _04_ADD_ALb_Ib */
		inline bool handler_in_04_ADD_ALb_Ib(Bit8u insb);

		/* _05_ADD_rAXvqp_Ivds */
		inline bool handler_in_05_ADD_rAXvqp_Ivds(Bit8u insb);

		/* _06_PUSH_ESw */
		inline bool handler_in_06_PUSH_ESw(Bit8u insb);

		/* _07_POP_ESw */
		inline bool handler_in_07_POP_ESw(Bit8u insb);

		/* _08_OR_Eb_Gb */
		inline bool handler_in_08_OR_Eb_Gb(Bit8u insb);

		/* _09_OR_Evqp_Gvqp */
		inline bool handler_in_09_OR_Evqp_Gvqp(Bit8u insb);

		/* _0A_OR_Gb_Eb */
		inline bool handler_in_0A_OR_Gb_Eb(Bit8u insb);

		/* _0B_OR_Gvqp_Evqp */
		inline bool handler_in_0B_OR_Gvqp_Evqp(Bit8u insb);

		/* _0C_OR_ALb_Ib */
		inline bool handler_in_0C_OR_ALb_Ib(Bit8u insb);

		/* _0D_OR_rAXvqp_Ivds */
		inline bool handler_in_0D_OR_rAXvqp_Ivds(Bit8u insb);

		/* _0E_PUSH_CSw */
		inline bool handler_in_0E_PUSH_CSw(Bit8u insb);

		/* _0F_00_00_SLDT_Mw */
		inline bool handler_in_0F_00_00_SLDT_Mw(Bit8u insb);

		/* _0F_00_01_STR_Mw */
		inline bool handler_in_0F_00_01_STR_Mw(Bit8u insb);

		/* _0F_00_02_LLDT_Ew */
		inline bool handler_in_0F_00_02_LLDT_Ew(Bit8u insb);

		/* _0F_00_03_LTR_Ew */
		inline bool handler_in_0F_00_03_LTR_Ew(Bit8u insb);

		/* _0F_00_04_VERR_Ew */
		inline bool handler_in_0F_00_04_VERR_Ew(Bit8u insb);

		/* _0F_00_05_VERW_Ew */
		inline bool handler_in_0F_00_05_VERW_Ew(Bit8u insb);

		/* _0F_01_00_SGDT_Ms */
		inline bool handler_in_0F_01_00_SGDT_Ms(Bit8u insb);

		/* _0F_01_01_SIDT_Ms */
		inline bool handler_in_0F_01_01_SIDT_Ms(Bit8u insb);

		/* _0F_01_02_LGDT_Ms */
		inline bool handler_in_0F_01_02_LGDT_Ms(Bit8u insb);

		/* _0F_01_03_LIDT_Ms */
		inline bool handler_in_0F_01_03_LIDT_Ms(Bit8u insb);

		/* _0F_01_04_SMSW_Mw */
		inline bool handler_in_0F_01_04_SMSW_Mw(Bit8u insb);

		/* _0F_01_06_LMSW_Ew */
		inline bool handler_in_0F_01_06_LMSW_Ew(Bit8u insb);

		/* _0F_01_07_INVLPG */
		inline bool handler_in_0F_01_07_INVLPG(Bit8u insb);

		/* _0F_01_D0_XGETBV */
		inline bool handler_in_0F_01_D0_XGETBV(Bit8u insb);

		/* _0F_01_D1_XSETBV */
		inline bool handler_in_0F_01_D1_XSETBV(Bit8u insb);

		/* _0F_01_F9_RDTSCP */
		inline bool handler_in_0F_01_F9_RDTSCP(Bit8u insb);

		/* _0F_02_LAR_Gvqp_Mw */
		inline bool handler_in_0F_02_LAR_Gvqp_Mw(Bit8u insb);

		/* _0F_03_LSL_Gvqp_Mw */
		inline bool handler_in_0F_03_LSL_Gvqp_Mw(Bit8u insb);

		/* _0F_06_CLTS */
		inline bool handler_in_0F_06_CLTS(Bit8u insb);

		/* _0F_07_LOADALL */
		inline bool handler_in_0F_07_LOADALL(Bit8u insb);

		/* _0F_08_INVD */
		inline bool handler_in_0F_08_INVD(Bit8u insb);

		/* _0F_09_WBINVD */
		inline bool handler_in_0F_09_WBINVD(Bit8u insb);

		/* _0F_1F_00_NOP_Ev */
		inline bool handler_in_0F_1F_00_NOP_Ev(Bit8u insb);

		/* _0F_1F_07_HINT_NOP_Ev */
		inline bool handler_in_0F_1F_07_HINT_NOP_Ev(Bit8u insb);

		/* _0F_20_MOV_Hd_Cd */
		inline bool handler_in_0F_20_MOV_Hd_Cd(Bit8u insb);

		/* _0F_21_MOV_Hd_Dd */
		inline bool handler_in_0F_21_MOV_Hd_Dd(Bit8u insb);

		/* _0F_22_MOV_Cd_Hd */
		inline bool handler_in_0F_22_MOV_Cd_Hd(Bit8u insb);

		/* _0F_23_MOV_Dq_Hq */
		inline bool handler_in_0F_23_MOV_Dq_Hq(Bit8u insb);

		/* _0F_24_MOV_Hd_Td */
		inline bool handler_in_0F_24_MOV_Hd_Td(Bit8u insb);

		/* _0F_26_MOV_Td_Hd */
		inline bool handler_in_0F_26_MOV_Td_Hd(Bit8u insb);

		/* _0F_30_WRMSR */
		inline bool handler_in_0F_30_WRMSR(Bit8u insb);

		/* _0F_31_RDTSC */
		inline bool handler_in_0F_31_RDTSC(Bit8u insb);

		/* _0F_32_RDMSR */
		inline bool handler_in_0F_32_RDMSR(Bit8u insb);

		/* _0F_33_RDPMC */
		inline bool handler_in_0F_33_RDPMC(Bit8u insb);

		/* _0F_34_SYSENTER */
		inline bool handler_in_0F_34_SYSENTER(Bit8u insb);

		/* _0F_35_SYSEXIT */
		inline bool handler_in_0F_35_SYSEXIT(Bit8u insb);

		/* _0F_38_F0_MOVBE_Gvqp_Mvqp */
		inline bool handler_in_0F_38_F0_MOVBE_Gvqp_Mvqp(Bit8u insb);

		/* _0F_38_F1_MOVBE_Mvqp_Gvqp */
		inline bool handler_in_0F_38_F1_MOVBE_Mvqp_Gvqp(Bit8u insb);

		/* _0F_40_CMOVO_Gvqp_Evqp */
		inline bool handler_in_0F_40_CMOVO_Gvqp_Evqp(Bit8u insb);

		/* _0F_41_CMOVNO_Gvqp_Evqp */
		inline bool handler_in_0F_41_CMOVNO_Gvqp_Evqp(Bit8u insb);

		/* _0F_42_CMOVB_Gvqp_Evqp */
		inline bool handler_in_0F_42_CMOVB_Gvqp_Evqp(Bit8u insb);

		/* _0F_43_CMOVNB_Gvqp_Evqp */
		inline bool handler_in_0F_43_CMOVNB_Gvqp_Evqp(Bit8u insb);

		/* _0F_44_CMOVZ_Gvqp_Evqp */
		inline bool handler_in_0F_44_CMOVZ_Gvqp_Evqp(Bit8u insb);

		/* _0F_45_CMOVNZ_Gvqp_Evqp */
		inline bool handler_in_0F_45_CMOVNZ_Gvqp_Evqp(Bit8u insb);

		/* _0F_46_CMOVBE_Gvqp_Evqp */
		inline bool handler_in_0F_46_CMOVBE_Gvqp_Evqp(Bit8u insb);

		/* _0F_47_CMOVNBE_Gvqp_Evqp */
		inline bool handler_in_0F_47_CMOVNBE_Gvqp_Evqp(Bit8u insb);

		/* _0F_48_CMOVS_Gvqp_Evqp */
		inline bool handler_in_0F_48_CMOVS_Gvqp_Evqp(Bit8u insb);

		/* _0F_49_CMOVNS_Gvqp_Evqp */
		inline bool handler_in_0F_49_CMOVNS_Gvqp_Evqp(Bit8u insb);

		/* _0F_4A_CMOVP_Gvqp_Evqp */
		inline bool handler_in_0F_4A_CMOVP_Gvqp_Evqp(Bit8u insb);

		/* _0F_4B_CMOVNP_Gvqp_Evqp */
		inline bool handler_in_0F_4B_CMOVNP_Gvqp_Evqp(Bit8u insb);

		/* _0F_4C_CMOVL_Gvqp_Evqp */
		inline bool handler_in_0F_4C_CMOVL_Gvqp_Evqp(Bit8u insb);

		/* _0F_4D_CMOVNL_Gvqp_Evqp */
		inline bool handler_in_0F_4D_CMOVNL_Gvqp_Evqp(Bit8u insb);

		/* _0F_4E_CMOVLE_Gvqp_Evqp */
		inline bool handler_in_0F_4E_CMOVLE_Gvqp_Evqp(Bit8u insb);

		/* _0F_4F_CMOVNLE_Gvqp_Evqp */
		inline bool handler_in_0F_4F_CMOVNLE_Gvqp_Evqp(Bit8u insb);

		/* _0F_80_JO_Jvds */
		inline bool handler_in_0F_80_JO_Jvds(Bit8u insb);

		/* _0F_81_JNO_Jvds */
		inline bool handler_in_0F_81_JNO_Jvds(Bit8u insb);

		/* _0F_82_JB_Jvds */
		inline bool handler_in_0F_82_JB_Jvds(Bit8u insb);

		/* _0F_83_JNB_Jvds */
		inline bool handler_in_0F_83_JNB_Jvds(Bit8u insb);

		/* _0F_84_JZ_Jvds */
		inline bool handler_in_0F_84_JZ_Jvds(Bit8u insb);

		/* _0F_85_JNZ_Jvds */
		inline bool handler_in_0F_85_JNZ_Jvds(Bit8u insb);

		/* _0F_86_JBE_Jvds */
		inline bool handler_in_0F_86_JBE_Jvds(Bit8u insb);

		/* _0F_87_JNBE_Jvds */
		inline bool handler_in_0F_87_JNBE_Jvds(Bit8u insb);

		/* _0F_88_JS_Jvds */
		inline bool handler_in_0F_88_JS_Jvds(Bit8u insb);

		/* _0F_89_JNS_Jvds */
		inline bool handler_in_0F_89_JNS_Jvds(Bit8u insb);

		/* _0F_8A_JP_Jvds */
		inline bool handler_in_0F_8A_JP_Jvds(Bit8u insb);

		/* _0F_8B_JNP_Jvds */
		inline bool handler_in_0F_8B_JNP_Jvds(Bit8u insb);

		/* _0F_8C_JL_Jvds */
		inline bool handler_in_0F_8C_JL_Jvds(Bit8u insb);

		/* _0F_8D_JNL_Jvds */
		inline bool handler_in_0F_8D_JNL_Jvds(Bit8u insb);

		/* _0F_8E_JLE_Jvds */
		inline bool handler_in_0F_8E_JLE_Jvds(Bit8u insb);

		/* _0F_8F_JNLE_Jvds */
		inline bool handler_in_0F_8F_JNLE_Jvds(Bit8u insb);

		/* _0F_90_00_SETO_Eb */
		inline bool handler_in_0F_90_00_SETO_Eb(Bit8u insb);

		/* _0F_91_00_SETNO_Eb */
		inline bool handler_in_0F_91_00_SETNO_Eb(Bit8u insb);

		/* _0F_92_00_SETB_Eb */
		inline bool handler_in_0F_92_00_SETB_Eb(Bit8u insb);

		/* _0F_93_00_SETNB_Eb */
		inline bool handler_in_0F_93_00_SETNB_Eb(Bit8u insb);

		/* _0F_94_00_SETZ_Eb */
		inline bool handler_in_0F_94_00_SETZ_Eb(Bit8u insb);

		/* _0F_95_00_SETNZ_Eb */
		inline bool handler_in_0F_95_00_SETNZ_Eb(Bit8u insb);

		/* _0F_96_00_SETBE_Eb */
		inline bool handler_in_0F_96_00_SETBE_Eb(Bit8u insb);

		/* _0F_97_00_SETNBE_Eb */
		inline bool handler_in_0F_97_00_SETNBE_Eb(Bit8u insb);

		/* _0F_98_00_SETS_Eb */
		inline bool handler_in_0F_98_00_SETS_Eb(Bit8u insb);

		/* _0F_99_00_SETNS_Eb */
		inline bool handler_in_0F_99_00_SETNS_Eb(Bit8u insb);

		/* _0F_9A_00_SETP_Eb */
		inline bool handler_in_0F_9A_00_SETP_Eb(Bit8u insb);

		/* _0F_9B_00_SETNP_Eb */
		inline bool handler_in_0F_9B_00_SETNP_Eb(Bit8u insb);

		/* _0F_9C_00_SETL_Eb */
		inline bool handler_in_0F_9C_00_SETL_Eb(Bit8u insb);

		/* _0F_9D_00_SETNL_Eb */
		inline bool handler_in_0F_9D_00_SETNL_Eb(Bit8u insb);

		/* _0F_9E_00_SETLE_Eb */
		inline bool handler_in_0F_9E_00_SETLE_Eb(Bit8u insb);

		/* _0F_9F_00_SETNLE_Eb */
		inline bool handler_in_0F_9F_00_SETNLE_Eb(Bit8u insb);

		/* _0F_A0_PUSH_FSw */
		inline bool handler_in_0F_A0_PUSH_FSw(Bit8u insb);

		/* _0F_A1_POP_FSw */
		inline bool handler_in_0F_A1_POP_FSw(Bit8u insb);

		/* _0F_A2_CPUID */
		inline bool handler_in_0F_A2_CPUID(Bit8u insb);

		/* _0F_A3_BT_Gvqp */
		inline bool handler_in_0F_A3_BT_Gvqp(Bit8u insb);

		/* _0F_A4_SHLD_Evqp_Ib */
		inline bool handler_in_0F_A4_SHLD_Evqp_Ib(Bit8u insb);

		/* _0F_A5_SHLD_Evqp_CLb */
		inline bool handler_in_0F_A5_SHLD_Evqp_CLb(Bit8u insb);

		/* _0F_A8_PUSH_GSw */
		inline bool handler_in_0F_A8_PUSH_GSw(Bit8u insb);

		/* _0F_A9_POP_GSw */
		inline bool handler_in_0F_A9_POP_GSw(Bit8u insb);

		/* _0F_AA_RSM */
		inline bool handler_in_0F_AA_RSM(Bit8u insb);

		/* _0F_AB_BTS_Evqp_Gvqp */
		inline bool handler_in_0F_AB_BTS_Evqp_Gvqp(Bit8u insb);

		/* _0F_AC_SHRD_Evqp_Ib */
		inline bool handler_in_0F_AC_SHRD_Evqp_Ib(Bit8u insb);

		/* _0F_AD_SHRD_Evqp_CLb */
		inline bool handler_in_0F_AD_SHRD_Evqp_CLb(Bit8u insb);

		/* _0F_AE_00_FXSAVE_Mstx */
		inline bool handler_in_0F_AE_00_FXSAVE_Mstx(Bit8u insb);

		/* _0F_AE_01_FXRSTOR_Mstx */
		inline bool handler_in_0F_AE_01_FXRSTOR_Mstx(Bit8u insb);

		/* _0F_AE_04_XSAVE */
		inline bool handler_in_0F_AE_04_XSAVE(Bit8u insb);

		/* _0F_AE_05_XRSTOR */
		inline bool handler_in_0F_AE_05_XRSTOR(Bit8u insb);

		/* _0F_AF_IMUL_Gvqp_Evqp */
		inline bool handler_in_0F_AF_IMUL_Gvqp_Evqp(Bit8u insb);

		/* _0F_B0_CMPXCHG_Eb_Gb */
		inline bool handler_in_0F_B0_CMPXCHG_Eb_Gb(Bit8u insb);

		/* _0F_B1_CMPXCHG_Evqp_Gvqp */
		inline bool handler_in_0F_B1_CMPXCHG_Evqp_Gvqp(Bit8u insb);

		/* _0F_B2_LSS_Gvqp_Mptp */
		inline bool handler_in_0F_B2_LSS_Gvqp_Mptp(Bit8u insb);

		/* _0F_B3_BTR_Evqp_Gvqp */
		inline bool handler_in_0F_B3_BTR_Evqp_Gvqp(Bit8u insb);

		/* _0F_B4_LFS_Gvqp_Mptp */
		inline bool handler_in_0F_B4_LFS_Gvqp_Mptp(Bit8u insb);

		/* _0F_B5_LGS_Gvqp_Mptp */
		inline bool handler_in_0F_B5_LGS_Gvqp_Mptp(Bit8u insb);

		/* _0F_B6_MOVZX_Gvqp_Eb */
		inline bool handler_in_0F_B6_MOVZX_Gvqp_Eb(Bit8u insb);

		/* _0F_B7_MOVZX_Gvqp_Ew */
		inline bool handler_in_0F_B7_MOVZX_Gvqp_Ew(Bit8u insb);

		/* _0F_BA_04_BT_Ib */
		inline bool handler_in_0F_BA_04_BT_Ib(Bit8u insb);

		/* _0F_BA_05_BTS_Evqp_Ib */
		inline bool handler_in_0F_BA_05_BTS_Evqp_Ib(Bit8u insb);

		/* _0F_BA_06_BTR_Evqp_Ib */
		inline bool handler_in_0F_BA_06_BTR_Evqp_Ib(Bit8u insb);

		/* _0F_BA_07_BTC_Evqp_Ib */
		inline bool handler_in_0F_BA_07_BTC_Evqp_Ib(Bit8u insb);

		/* _0F_BB_BTC_Evqp_Gvqp */
		inline bool handler_in_0F_BB_BTC_Evqp_Gvqp(Bit8u insb);

		/* _0F_BC_BSF_Gvqp_Evqp */
		inline bool handler_in_0F_BC_BSF_Gvqp_Evqp(Bit8u insb);

		/* _0F_BD_BSR_Gvqp_Evqp */
		inline bool handler_in_0F_BD_BSR_Gvqp_Evqp(Bit8u insb);

		/* _0F_BE_MOVSX_Gvqp_Eb */
		inline bool handler_in_0F_BE_MOVSX_Gvqp_Eb(Bit8u insb);

		/* _0F_BF_MOVSX_Gvqp_Ew */
		inline bool handler_in_0F_BF_MOVSX_Gvqp_Ew(Bit8u insb);

		/* _0F_C0_XADD_Gb */
		inline bool handler_in_0F_C0_XADD_Gb(Bit8u insb);

		/* _0F_C1_XADD_Gvqp */
		inline bool handler_in_0F_C1_XADD_Gvqp(Bit8u insb);

		/* _0F_C7_01_CMPXCHG8B_Mq */
		inline bool handler_in_0F_C7_01_CMPXCHG8B_Mq(Bit8u insb);

		/* _0F_C8_BSWAP_rAXvqp */
		inline bool handler_in_0F_C8_BSWAP_rAXvqp(Bit8u insb);

		/* _0F_C9_BSWAP_rCXvqp */
		inline bool handler_in_0F_C9_BSWAP_rCXvqp(Bit8u insb);

		/* _0F_CA_BSWAP_rDXvqp */
		inline bool handler_in_0F_CA_BSWAP_rDXvqp(Bit8u insb);

		/* _0F_CB_BSWAP_rBXvqp */
		inline bool handler_in_0F_CB_BSWAP_rBXvqp(Bit8u insb);

		/* _0F_CC_BSWAP_rSPvqp */
		inline bool handler_in_0F_CC_BSWAP_rSPvqp(Bit8u insb);

		/* _0F_CD_BSWAP_rBPvqp */
		inline bool handler_in_0F_CD_BSWAP_rBPvqp(Bit8u insb);

		/* _0F_CE_BSWAP_rSIvqp */
		inline bool handler_in_0F_CE_BSWAP_rSIvqp(Bit8u insb);

		/* _0F_CF_BSWAP_rDIvqp */
		inline bool handler_in_0F_CF_BSWAP_rDIvqp(Bit8u insb);

		/* _10_ADC_Eb_Gb */
		inline bool handler_in_10_ADC_Eb_Gb(Bit8u insb);

		/* _11_ADC_Evqp_Gvqp */
		inline bool handler_in_11_ADC_Evqp_Gvqp(Bit8u insb);

		/* _12_ADC_Gb_Eb */
		inline bool handler_in_12_ADC_Gb_Eb(Bit8u insb);

		/* _13_ADC_Gvqp_Evqp */
		inline bool handler_in_13_ADC_Gvqp_Evqp(Bit8u insb);

		/* _14_ADC_ALb_Ib */
		inline bool handler_in_14_ADC_ALb_Ib(Bit8u insb);

		/* _15_ADC_rAXvqp_Ivds */
		inline bool handler_in_15_ADC_rAXvqp_Ivds(Bit8u insb);

		/* _16_PUSH_SSw */
		inline bool handler_in_16_PUSH_SSw(Bit8u insb);

		/* _17_POP_SSw */
		inline bool handler_in_17_POP_SSw(Bit8u insb);

		/* _18_SBB_Eb_Gb */
		inline bool handler_in_18_SBB_Eb_Gb(Bit8u insb);

		/* _19_SBB_Evqp_Gvqp */
		inline bool handler_in_19_SBB_Evqp_Gvqp(Bit8u insb);

		/* _1A_SBB_Gb_Eb */
		inline bool handler_in_1A_SBB_Gb_Eb(Bit8u insb);

		/* _1B_SBB_Gvqp_Evqp */
		inline bool handler_in_1B_SBB_Gvqp_Evqp(Bit8u insb);

		/* _1C_SBB_ALb_Ib */
		inline bool handler_in_1C_SBB_ALb_Ib(Bit8u insb);

		/* _1D_SBB_rAXvqp_Ivds */
		inline bool handler_in_1D_SBB_rAXvqp_Ivds(Bit8u insb);

		/* _1E_PUSH_DSw */
		inline bool handler_in_1E_PUSH_DSw(Bit8u insb);

		/* _1F_POP_DSw */
		inline bool handler_in_1F_POP_DSw(Bit8u insb);

		/* _20_AND_Eb_Gb */
		inline bool handler_in_20_AND_Eb_Gb(Bit8u insb);

		/* _21_AND_Evqp_Gvqp */
		inline bool handler_in_21_AND_Evqp_Gvqp(Bit8u insb);

		/* _22_AND_Gb_Eb */
		inline bool handler_in_22_AND_Gb_Eb(Bit8u insb);

		/* _23_AND_Gvqp_Evqp */
		inline bool handler_in_23_AND_Gvqp_Evqp(Bit8u insb);

		/* _24_AND_ALb_Ib */
		inline bool handler_in_24_AND_ALb_Ib(Bit8u insb);

		/* _25_AND_rAXvqp_Ivds */
		inline bool handler_in_25_AND_rAXvqp_Ivds(Bit8u insb);

		/* _27_DAA */
		inline bool handler_in_27_DAA(Bit8u insb);

		/* _28_SUB_Eb_Gb */
		inline bool handler_in_28_SUB_Eb_Gb(Bit8u insb);

		/* _29_SUB_Evqp_Gvqp */
		inline bool handler_in_29_SUB_Evqp_Gvqp(Bit8u insb);

		/* _2A_SUB_Gb_Eb */
		inline bool handler_in_2A_SUB_Gb_Eb(Bit8u insb);

		/* _2B_SUB_Gvqp_Evqp */
		inline bool handler_in_2B_SUB_Gvqp_Evqp(Bit8u insb);

		/* _2C_SUB_ALb_Ib */
		inline bool handler_in_2C_SUB_ALb_Ib(Bit8u insb);

		/* _2D_SUB_rAXvqp_Ivds */
		inline bool handler_in_2D_SUB_rAXvqp_Ivds(Bit8u insb);

		/* _2F_DAS */
		inline bool handler_in_2F_DAS(Bit8u insb);

		/* _30_XOR_Eb_Gb */
		inline bool handler_in_30_XOR_Eb_Gb(Bit8u insb);

		/* _31_XOR_Evqp_Gvqp */
		inline bool handler_in_31_XOR_Evqp_Gvqp(Bit8u insb);

		/* _32_XOR_Gb_Eb */
		inline bool handler_in_32_XOR_Gb_Eb(Bit8u insb);

		/* _33_XOR_Gvqp_Evqp */
		inline bool handler_in_33_XOR_Gvqp_Evqp(Bit8u insb);

		/* _34_XOR_ALb_Ib */
		inline bool handler_in_34_XOR_ALb_Ib(Bit8u insb);

		/* _35_XOR_rAXvqp_Ivds */
		inline bool handler_in_35_XOR_rAXvqp_Ivds(Bit8u insb);

		/* _37_AAA */
		inline bool handler_in_37_AAA(Bit8u insb);

		/* _38_CMP_Gb */
		inline bool handler_in_38_CMP_Gb(Bit8u insb);

		/* _39_CMP_Gvqp */
		inline bool handler_in_39_CMP_Gvqp(Bit8u insb);

		/* _3A_CMP_Eb */
		inline bool handler_in_3A_CMP_Eb(Bit8u insb);

		/* _3B_CMP_Evqp */
		inline bool handler_in_3B_CMP_Evqp(Bit8u insb);

		/* _3C_CMP_Ib */
		inline bool handler_in_3C_CMP_Ib(Bit8u insb);

		/* _3D_CMP_Ivds */
		inline bool handler_in_3D_CMP_Ivds(Bit8u insb);

		/* _3F_AAS */
		inline bool handler_in_3F_AAS(Bit8u insb);

		/* _40_INC_rAXv */
		inline bool handler_in_40_INC_rAXv(Bit8u insb);

		/* _41_INC_rCXv */
		inline bool handler_in_41_INC_rCXv(Bit8u insb);

		/* _42_INC_rDXv */
		inline bool handler_in_42_INC_rDXv(Bit8u insb);

		/* _43_INC_rBXv */
		inline bool handler_in_43_INC_rBXv(Bit8u insb);

		/* _44_INC_rSPv */
		inline bool handler_in_44_INC_rSPv(Bit8u insb);

		/* _45_INC_rBPv */
		inline bool handler_in_45_INC_rBPv(Bit8u insb);

		/* _46_INC_rSIv */
		inline bool handler_in_46_INC_rSIv(Bit8u insb);

		/* _47_INC_rDIv */
		inline bool handler_in_47_INC_rDIv(Bit8u insb);

		/* _48_DEC_rAXv */
		inline bool handler_in_48_DEC_rAXv(Bit8u insb);

		/* _49_DEC_rCXv */
		inline bool handler_in_49_DEC_rCXv(Bit8u insb);

		/* _4A_DEC_rDXv */
		inline bool handler_in_4A_DEC_rDXv(Bit8u insb);

		/* _4B_DEC_rBXv */
		inline bool handler_in_4B_DEC_rBXv(Bit8u insb);

		/* _4C_DEC_rSPv */
		inline bool handler_in_4C_DEC_rSPv(Bit8u insb);

		/* _4D_DEC_rBPv */
		inline bool handler_in_4D_DEC_rBPv(Bit8u insb);

		/* _4E_DEC_rSIv */
		inline bool handler_in_4E_DEC_rSIv(Bit8u insb);

		/* _4F_DEC_rDIv */
		inline bool handler_in_4F_DEC_rDIv(Bit8u insb);

		/* _50_PUSH_rAXv */
		inline bool handler_in_50_PUSH_rAXv(Bit8u insb);

		/* _51_PUSH_rCXv */
		inline bool handler_in_51_PUSH_rCXv(Bit8u insb);

		/* _52_PUSH_rDXv */
		inline bool handler_in_52_PUSH_rDXv(Bit8u insb);

		/* _53_PUSH_rBXv */
		inline bool handler_in_53_PUSH_rBXv(Bit8u insb);

		/* _54_PUSH_rSPv */
		inline bool handler_in_54_PUSH_rSPv(Bit8u insb);

		/* _55_PUSH_rBPv */
		inline bool handler_in_55_PUSH_rBPv(Bit8u insb);

		/* _56_PUSH_rSIv */
		inline bool handler_in_56_PUSH_rSIv(Bit8u insb);

		/* _57_PUSH_rDIv */
		inline bool handler_in_57_PUSH_rDIv(Bit8u insb);

		/* _58_POP_rAXv */
		inline bool handler_in_58_POP_rAXv(Bit8u insb);

		/* _59_POP_rCXv */
		inline bool handler_in_59_POP_rCXv(Bit8u insb);

		/* _5A_POP_rDXv */
		inline bool handler_in_5A_POP_rDXv(Bit8u insb);

		/* _5B_POP_rBXv */
		inline bool handler_in_5B_POP_rBXv(Bit8u insb);

		/* _5C_POP_rSPv */
		inline bool handler_in_5C_POP_rSPv(Bit8u insb);

		/* _5D_POP_rBPv */
		inline bool handler_in_5D_POP_rBPv(Bit8u insb);

		/* _5E_POP_rSIv */
		inline bool handler_in_5E_POP_rSIv(Bit8u insb);

		/* _5F_POP_rDIv */
		inline bool handler_in_5F_POP_rDIv(Bit8u insb);

		/* _60_PUSHA */
		inline bool handler_in_60_PUSHA(Bit8u insb);

		/* _61_POPA */
		inline bool handler_in_61_POPA(Bit8u insb);

		/* _62_BOUND_Ma */
		inline bool handler_in_62_BOUND_Ma(Bit8u insb);

		/* _63_ARPL_Gw */
		inline bool handler_in_63_ARPL_Gw(Bit8u insb);

		/* _68_PUSH_Ivs */
		inline bool handler_in_68_PUSH_Ivs(Bit8u insb);

		/* _69_IMUL_Gvqp_Ivds */
		inline bool handler_in_69_IMUL_Gvqp_Ivds(Bit8u insb);

		/* _6A_PUSH_Ibss */
		inline bool handler_in_6A_PUSH_Ibss(Bit8u insb);

		/* _6B_IMUL_Gvqp_Ibs */
		inline bool handler_in_6B_IMUL_Gvqp_Ibs(Bit8u insb);

		/* _6C_INS_Yb_DXw */
		inline bool handler_in_6C_INS_Yb_DXw(Bit8u insb);

		/* _6D_INS_Ywo_DXw */
		inline bool handler_in_6D_INS_Ywo_DXw(Bit8u insb);

		/* _6E_OUTS_DXw_Xb */
		inline bool handler_in_6E_OUTS_DXw_Xb(Bit8u insb);

		/* _6F_OUTS_DXw_Xwo */
		inline bool handler_in_6F_OUTS_DXw_Xwo(Bit8u insb);

		/* _70_JO_Jbs */
		inline bool handler_in_70_JO_Jbs(Bit8u insb);

		/* _71_JNO_Jbs */
		inline bool handler_in_71_JNO_Jbs(Bit8u insb);

		/* _72_JB_Jbs */
		inline bool handler_in_72_JB_Jbs(Bit8u insb);

		/* _73_JNB_Jbs */
		inline bool handler_in_73_JNB_Jbs(Bit8u insb);

		/* _74_JZ_Jbs */
		inline bool handler_in_74_JZ_Jbs(Bit8u insb);

		/* _75_JNZ_Jbs */
		inline bool handler_in_75_JNZ_Jbs(Bit8u insb);

		/* _76_JBE_Jbs */
		inline bool handler_in_76_JBE_Jbs(Bit8u insb);

		/* _77_JNBE_Jbs */
		inline bool handler_in_77_JNBE_Jbs(Bit8u insb);

		/* _78_JS_Jbs */
		inline bool handler_in_78_JS_Jbs(Bit8u insb);

		/* _79_JNS_Jbs */
		inline bool handler_in_79_JNS_Jbs(Bit8u insb);

		/* _7A_JP_Jbs */
		inline bool handler_in_7A_JP_Jbs(Bit8u insb);

		/* _7B_JNP_Jbs */
		inline bool handler_in_7B_JNP_Jbs(Bit8u insb);

		/* _7C_JL_Jbs */
		inline bool handler_in_7C_JL_Jbs(Bit8u insb);

		/* _7D_JNL_Jbs */
		inline bool handler_in_7D_JNL_Jbs(Bit8u insb);

		/* _7E_JLE_Jbs */
		inline bool handler_in_7E_JLE_Jbs(Bit8u insb);

		/* _7F_JNLE_Jbs */
		inline bool handler_in_7F_JNLE_Jbs(Bit8u insb);

		/* _81_00_ADD_Evqp_Ivds */
		inline bool handler_in_81_00_ADD_Evqp_Ivds(Bit8u insb);

		/* _81_01_OR_Evqp_Ivds */
		inline bool handler_in_81_01_OR_Evqp_Ivds(Bit8u insb);

		/* _81_02_ADC_Evqp_Ivds */
		inline bool handler_in_81_02_ADC_Evqp_Ivds(Bit8u insb);

		/* _81_03_SBB_Evqp_Ivds */
		inline bool handler_in_81_03_SBB_Evqp_Ivds(Bit8u insb);

		/* _81_04_AND_Evqp_Ivds */
		inline bool handler_in_81_04_AND_Evqp_Ivds(Bit8u insb);

		/* _81_05_SUB_Evqp_Ivds */
		inline bool handler_in_81_05_SUB_Evqp_Ivds(Bit8u insb);

		/* _81_06_XOR_Evqp_Ivds */
		inline bool handler_in_81_06_XOR_Evqp_Ivds(Bit8u insb);

		/* _81_07_CMP_Ivds */
		inline bool handler_in_81_07_CMP_Ivds(Bit8u insb);

		/* _82_00_ADD_Eb_Ib */
		inline bool handler_in_82_00_ADD_Eb_Ib(Bit8u insb);

		/* _82_01_OR_Eb_Ib */
		inline bool handler_in_82_01_OR_Eb_Ib(Bit8u insb);

		/* _82_02_ADC_Eb_Ib */
		inline bool handler_in_82_02_ADC_Eb_Ib(Bit8u insb);

		/* _82_03_SBB_Eb_Ib */
		inline bool handler_in_82_03_SBB_Eb_Ib(Bit8u insb);

		/* _82_04_AND_Eb_Ib */
		inline bool handler_in_82_04_AND_Eb_Ib(Bit8u insb);

		/* _82_05_SUB_Eb_Ib */
		inline bool handler_in_82_05_SUB_Eb_Ib(Bit8u insb);

		/* _82_06_XOR_Eb_Ib */
		inline bool handler_in_82_06_XOR_Eb_Ib(Bit8u insb);

		/* _82_07_CMP_Ib */
		inline bool handler_in_82_07_CMP_Ib(Bit8u insb);

		/* _83_00_ADD_Evqp_Ibs */
		inline bool handler_in_83_00_ADD_Evqp_Ibs(Bit8u insb);

		/* _83_01_OR_Evqp_Ibs */
		inline bool handler_in_83_01_OR_Evqp_Ibs(Bit8u insb);

		/* _83_02_ADC_Evqp_Ibs */
		inline bool handler_in_83_02_ADC_Evqp_Ibs(Bit8u insb);

		/* _83_03_SBB_Evqp_Ibs */
		inline bool handler_in_83_03_SBB_Evqp_Ibs(Bit8u insb);

		/* _83_04_AND_Evqp_Ibs */
		inline bool handler_in_83_04_AND_Evqp_Ibs(Bit8u insb);

		/* _83_05_SUB_Evqp_Ibs */
		inline bool handler_in_83_05_SUB_Evqp_Ibs(Bit8u insb);

		/* _83_06_XOR_Evqp_Ibs */
		inline bool handler_in_83_06_XOR_Evqp_Ibs(Bit8u insb);

		/* _83_07_CMP_Ibs */
		inline bool handler_in_83_07_CMP_Ibs(Bit8u insb);

		/* _84_TEST_Gb */
		inline bool handler_in_84_TEST_Gb(Bit8u insb);

		/* _85_TEST_Gvqp */
		inline bool handler_in_85_TEST_Gvqp(Bit8u insb);

		/* _86_XCHG_Eb */
		inline bool handler_in_86_XCHG_Eb(Bit8u insb);

		/* _87_XCHG_Evqp */
		inline bool handler_in_87_XCHG_Evqp(Bit8u insb);

		/* _88_MOV_Eb_Gb */
		inline bool handler_in_88_MOV_Eb_Gb(Bit8u insb);

		/* _89_MOV_Evqp_Gvqp */
		inline bool handler_in_89_MOV_Evqp_Gvqp(Bit8u insb);

		/* _8A_MOV_Gb_Eb */
		inline bool handler_in_8A_MOV_Gb_Eb(Bit8u insb);

		/* _8B_MOV_Gvqp_Evqp */
		inline bool handler_in_8B_MOV_Gvqp_Evqp(Bit8u insb);

		/* _8C_MOV_Mw_Sw */
		inline bool handler_in_8C_MOV_Mw_Sw(Bit8u insb);

		/* _8D_LEA_Gvqp */
		inline bool handler_in_8D_LEA_Gvqp(Bit8u insb);

		/* _8E_MOV_Sw_Ew */
		inline bool handler_in_8E_MOV_Sw_Ew(Bit8u insb);

		/* _8F_00_POP_Ev */
		inline bool handler_in_8F_00_POP_Ev(Bit8u insb);

		/* _90_XCHG_rAXvqp */
		inline bool handler_in_90_XCHG_rAXvqp(Bit8u insb);

		/* _91_XCHG_rAXvqp */
		inline bool handler_in_91_XCHG_rAXvqp(Bit8u insb);

		/* _92_XCHG_rAXvqp */
		inline bool handler_in_92_XCHG_rAXvqp(Bit8u insb);

		/* _93_XCHG_rAXvqp */
		inline bool handler_in_93_XCHG_rAXvqp(Bit8u insb);

		/* _94_XCHG_rAXvqp */
		inline bool handler_in_94_XCHG_rAXvqp(Bit8u insb);

		/* _95_XCHG_rAXvqp */
		inline bool handler_in_95_XCHG_rAXvqp(Bit8u insb);

		/* _96_XCHG_rAXvqp */
		inline bool handler_in_96_XCHG_rAXvqp(Bit8u insb);

		/* _97_XCHG_rAXvqp */
		inline bool handler_in_97_XCHG_rAXvqp(Bit8u insb);

		/* _98_CBW */
		inline bool handler_in_98_CBW(Bit8u insb);

		/* _98_CWDE */
		inline bool handler_in_98_CWDE(Bit8u insb);

		/* _99_CDQ */
		inline bool handler_in_99_CDQ(Bit8u insb);

		/* _99_CWD */
		inline bool handler_in_99_CWD(Bit8u insb);

		/* _9A_CALLF_Ap */
		inline bool handler_in_9A_CALLF_Ap(Bit8u insb);

		/* _9B_FWAIT */
		inline bool handler_in_9B_FWAIT(Bit8u insb);

		/* _9C_PUSHF */
		inline bool handler_in_9C_PUSHF(Bit8u insb);

		/* _9D_POPF */
		inline bool handler_in_9D_POPF(Bit8u insb);

		/* _9E_SAHF */
		inline bool handler_in_9E_SAHF(Bit8u insb);

		/* _9F_LAHF */
		inline bool handler_in_9F_LAHF(Bit8u insb);

		/* _A0_MOV_ALb_Ob */
		inline bool handler_in_A0_MOV_ALb_Ob(Bit8u insb);

		/* _A1_MOV_rAXvqp_Ovqp */
		inline bool handler_in_A1_MOV_rAXvqp_Ovqp(Bit8u insb);

		/* _A2_MOV_Ob_ALb */
		inline bool handler_in_A2_MOV_Ob_ALb(Bit8u insb);

		/* _A3_MOV_Ovqp_rAXvqp */
		inline bool handler_in_A3_MOV_Ovqp_rAXvqp(Bit8u insb);

		/* _A4_MOVS_Yb_Xb */
		inline bool handler_in_A4_MOVS_Yb_Xb(Bit8u insb);

		/* _A5_MOVS_Ywo_Xwo */
		inline bool handler_in_A5_MOVS_Ywo_Xwo(Bit8u insb);

		/* _A6_CMPS_Xb */
		inline bool handler_in_A6_CMPS_Xb(Bit8u insb);

		/* _A7_CMPS_Xwo */
		inline bool handler_in_A7_CMPS_Xwo(Bit8u insb);

		/* _A8_TEST_Ib */
		inline bool handler_in_A8_TEST_Ib(Bit8u insb);

		/* _A9_TEST_Ivds */
		inline bool handler_in_A9_TEST_Ivds(Bit8u insb);

		/* _AA_STOS_Yb */
		inline bool handler_in_AA_STOS_Yb(Bit8u insb);

		/* _AB_STOS_Ywo */
		inline bool handler_in_AB_STOS_Ywo(Bit8u insb);

		/* _AC_LODS_Xb */
		inline bool handler_in_AC_LODS_Xb(Bit8u insb);

		/* _AD_LODS_Xwo */
		inline bool handler_in_AD_LODS_Xwo(Bit8u insb);

		/* _AE_SCAS_Yb */
		inline bool handler_in_AE_SCAS_Yb(Bit8u insb);

		/* _AF_SCAS_Ywo */
		inline bool handler_in_AF_SCAS_Ywo(Bit8u insb);

		/* _B0_MOV_ALb_Ib */
		inline bool handler_in_B0_MOV_ALb_Ib(Bit8u insb);

		/* _B1_MOV_CLb_Ib */
		inline bool handler_in_B1_MOV_CLb_Ib(Bit8u insb);

		/* _B2_MOV_DLb_Ib */
		inline bool handler_in_B2_MOV_DLb_Ib(Bit8u insb);

		/* _B4_MOV_AHb_Ib */
		inline bool handler_in_B4_MOV_AHb_Ib(Bit8u insb);

		/* _B5_MOV_CHb_Ib */
		inline bool handler_in_B5_MOV_CHb_Ib(Bit8u insb);

		/* _B6_MOV_DHb_Ib */
		inline bool handler_in_B6_MOV_DHb_Ib(Bit8u insb);

		/* _B7_MOV_BHb_Ib */
		inline bool handler_in_B7_MOV_BHb_Ib(Bit8u insb);

		/* _B8_MOV_rAXvqp_Ivqp */
		inline bool handler_in_B8_MOV_rAXvqp_Ivqp(Bit8u insb);

		/* _B9_MOV_rCXvqp_Ivqp */
		inline bool handler_in_B9_MOV_rCXvqp_Ivqp(Bit8u insb);

		/* _BA_MOV_rDXvqp_Ivqp */
		inline bool handler_in_BA_MOV_rDXvqp_Ivqp(Bit8u insb);

		/* _BB_MOV_rBXvqp_Ivqp */
		inline bool handler_in_BB_MOV_rBXvqp_Ivqp(Bit8u insb);

		/* _BC_MOV_rSPvqp_Ivqp */
		inline bool handler_in_BC_MOV_rSPvqp_Ivqp(Bit8u insb);

		/* _BD_MOV_rBPvqp_Ivqp */
		inline bool handler_in_BD_MOV_rBPvqp_Ivqp(Bit8u insb);

		/* _BE_MOV_rSIvqp_Ivqp */
		inline bool handler_in_BE_MOV_rSIvqp_Ivqp(Bit8u insb);

		/* _BF_MOV_rDIvqp_Ivqp */
		inline bool handler_in_BF_MOV_rDIvqp_Ivqp(Bit8u insb);

		/* _C0_00_ROL_Eb_Ib */
		inline bool handler_in_C0_00_ROL_Eb_Ib(Bit8u insb);

		/* _C0_01_ROR_Eb_Ib */
		inline bool handler_in_C0_01_ROR_Eb_Ib(Bit8u insb);

		/* _C0_02_RCL_Eb_Ib */
		inline bool handler_in_C0_02_RCL_Eb_Ib(Bit8u insb);

		/* _C0_03_RCR_Eb_Ib */
		inline bool handler_in_C0_03_RCR_Eb_Ib(Bit8u insb);

		/* _C0_04_SHL_Eb_Ib */
		inline bool handler_in_C0_04_SHL_Eb_Ib(Bit8u insb);

		/* _C0_05_SHR_Eb_Ib */
		inline bool handler_in_C0_05_SHR_Eb_Ib(Bit8u insb);

		/* _C0_06_SAL_Eb_Ib */
		inline bool handler_in_C0_06_SAL_Eb_Ib(Bit8u insb);

		/* _C0_07_SAR_Eb_Ib */
		inline bool handler_in_C0_07_SAR_Eb_Ib(Bit8u insb);

		/* _C1_00_ROL_Evqp_Ib */
		inline bool handler_in_C1_00_ROL_Evqp_Ib(Bit8u insb);

		/* _C1_01_ROR_Evqp_Ib */
		inline bool handler_in_C1_01_ROR_Evqp_Ib(Bit8u insb);

		/* _C1_02_RCL_Evqp_Ib */
		inline bool handler_in_C1_02_RCL_Evqp_Ib(Bit8u insb);

		/* _C1_03_RCR_Evqp_Ib */
		inline bool handler_in_C1_03_RCR_Evqp_Ib(Bit8u insb);

		/* _C1_04_SHL_Evqp_Ib */
		inline bool handler_in_C1_04_SHL_Evqp_Ib(Bit8u insb);

		/* _C1_05_SHR_Evqp_Ib */
		inline bool handler_in_C1_05_SHR_Evqp_Ib(Bit8u insb);

		/* _C1_06_SAL_Evqp_Ib */
		inline bool handler_in_C1_06_SAL_Evqp_Ib(Bit8u insb);

		/* _C1_07_SAR_Evqp_Ib */
		inline bool handler_in_C1_07_SAR_Evqp_Ib(Bit8u insb);

		/* _C2_RETN_Iw */
		inline bool handler_in_C2_RETN_Iw(Bit8u insb);

		/* _C3_RETN */
		inline bool handler_in_C3_RETN(Bit8u insb);

		/* _C4_LES_Gv_Mp */
		inline bool handler_in_C4_LES_Gv_Mp(Bit8u insb);

		/* _C5_LDS_Gv_Mp */
		inline bool handler_in_C5_LDS_Gv_Mp(Bit8u insb);

		/* _C6_00_MOV_Eb_Ib */
		inline bool handler_in_C6_00_MOV_Eb_Ib(Bit8u insb);

		/* _C7_00_MOV_Evqp_Ivds */
		inline bool handler_in_C7_00_MOV_Evqp_Ivds(Bit8u insb);

		/* _C8_ENTER_Ib */
		inline bool handler_in_C8_ENTER_Ib(Bit8u insb);

		/* _C9_LEAVE */
		inline bool handler_in_C9_LEAVE(Bit8u insb);

		/* _CA_RETF_Iw */
		inline bool handler_in_CA_RETF_Iw(Bit8u insb);

		/* _CB_RETF */
		inline bool handler_in_CB_RETF(Bit8u insb);

		/* _CC_INT */
		inline bool handler_in_CC_INT(Bit8u insb);

		/* _CD_INT_Ib */
		inline bool handler_in_CD_INT_Ib(Bit8u insb);

		/* _CE_INTO */
		inline bool handler_in_CE_INTO(Bit8u insb);

		/* _CF_IRET */
		inline bool handler_in_CF_IRET(Bit8u insb);

		/* _D0_00_ROL_Eb */
		inline bool handler_in_D0_00_ROL_Eb(Bit8u insb);

		/* _D0_01_ROR_Eb */
		inline bool handler_in_D0_01_ROR_Eb(Bit8u insb);

		/* _D0_02_RCL_Eb */
		inline bool handler_in_D0_02_RCL_Eb(Bit8u insb);

		/* _D0_03_RCR_Eb */
		inline bool handler_in_D0_03_RCR_Eb(Bit8u insb);

		/* _D0_04_SHL_Eb */
		inline bool handler_in_D0_04_SHL_Eb(Bit8u insb);

		/* _D0_05_SHR_Eb */
		inline bool handler_in_D0_05_SHR_Eb(Bit8u insb);

		/* _D0_06_SAL_Eb */
		inline bool handler_in_D0_06_SAL_Eb(Bit8u insb);

		/* _D0_07_SAR_Eb */
		inline bool handler_in_D0_07_SAR_Eb(Bit8u insb);

		/* _D1_00_ROL_Evqp */
		inline bool handler_in_D1_00_ROL_Evqp(Bit8u insb);

		/* _D1_01_ROR_Evqp */
		inline bool handler_in_D1_01_ROR_Evqp(Bit8u insb);

		/* _D1_02_RCL_Evqp */
		inline bool handler_in_D1_02_RCL_Evqp(Bit8u insb);

		/* _D1_03_RCR_Evqp */
		inline bool handler_in_D1_03_RCR_Evqp(Bit8u insb);

		/* _D1_04_SHL_Evqp */
		inline bool handler_in_D1_04_SHL_Evqp(Bit8u insb);

		/* _D1_05_SHR_Evqp */
		inline bool handler_in_D1_05_SHR_Evqp(Bit8u insb);

		/* _D1_06_SAL_Evqp */
		inline bool handler_in_D1_06_SAL_Evqp(Bit8u insb);

		/* _D1_07_SAR_Evqp */
		inline bool handler_in_D1_07_SAR_Evqp(Bit8u insb);

		/* _D2_00_ROL_Eb_CLb */
		inline bool handler_in_D2_00_ROL_Eb_CLb(Bit8u insb);

		/* _D2_01_ROR_Eb_CLb */
		inline bool handler_in_D2_01_ROR_Eb_CLb(Bit8u insb);

		/* _D2_02_RCL_Eb_CLb */
		inline bool handler_in_D2_02_RCL_Eb_CLb(Bit8u insb);

		/* _D2_03_RCR_Eb_CLb */
		inline bool handler_in_D2_03_RCR_Eb_CLb(Bit8u insb);

		/* _D2_04_SHL_Eb_CLb */
		inline bool handler_in_D2_04_SHL_Eb_CLb(Bit8u insb);

		/* _D2_05_SHR_Eb_CLb */
		inline bool handler_in_D2_05_SHR_Eb_CLb(Bit8u insb);

		/* _D2_06_SAL_Eb_CLb */
		inline bool handler_in_D2_06_SAL_Eb_CLb(Bit8u insb);

		/* _D2_07_SAR_Eb_CLb */
		inline bool handler_in_D2_07_SAR_Eb_CLb(Bit8u insb);

		/* _D3_00_ROL_Evqp_CLb */
		inline bool handler_in_D3_00_ROL_Evqp_CLb(Bit8u insb);

		/* _D3_01_ROR_Evqp_CLb */
		inline bool handler_in_D3_01_ROR_Evqp_CLb(Bit8u insb);

		/* _D3_02_RCL_Evqp_CLb */
		inline bool handler_in_D3_02_RCL_Evqp_CLb(Bit8u insb);

		/* _D3_03_RCR_Evqp_CLb */
		inline bool handler_in_D3_03_RCR_Evqp_CLb(Bit8u insb);

		/* _D3_04_SHL_Evqp_CLb */
		inline bool handler_in_D3_04_SHL_Evqp_CLb(Bit8u insb);

		/* _D3_05_SHR_Evqp_CLb */
		inline bool handler_in_D3_05_SHR_Evqp_CLb(Bit8u insb);

		/* _D3_06_SAL_Evqp_CLb */
		inline bool handler_in_D3_06_SAL_Evqp_CLb(Bit8u insb);

		/* _D3_07_SAR_Evqp_CLb */
		inline bool handler_in_D3_07_SAR_Evqp_CLb(Bit8u insb);

		/* _D4_AMX_Ib */
		inline bool handler_in_D4_AMX_Ib(Bit8u insb);

		/* _D5_ADX_Ib */
		inline bool handler_in_D5_ADX_Ib(Bit8u insb);

		/* _D6_SALC */
		inline bool handler_in_D6_SALC(Bit8u insb);

		/* _D7_XLAT_BBb */
		inline bool handler_in_D7_XLAT_BBb(Bit8u insb);

		/* _E0_LOOPNZ_Jbs */
		inline bool handler_in_E0_LOOPNZ_Jbs(Bit8u insb);

		/* _E1_LOOPZ_Jbs */
		inline bool handler_in_E1_LOOPZ_Jbs(Bit8u insb);

		/* _E2_LOOP_Jbs */
		inline bool handler_in_E2_LOOP_Jbs(Bit8u insb);

		/* _E3_JCXZ_Jbs */
		inline bool handler_in_E3_JCXZ_Jbs(Bit8u insb);

		/* _E4_IN_ALb_Ib */
		inline bool handler_in_E4_IN_ALb_Ib(Bit8u insb);

		/* _E5_IN_rAXv_Ib */
		inline bool handler_in_E5_IN_rAXv_Ib(Bit8u insb);

		/* _E6_OUT_Ib_ALb */
		inline bool handler_in_E6_OUT_Ib_ALb(Bit8u insb);

		/* _E7_OUT_Ib_rAXv */
		inline bool handler_in_E7_OUT_Ib_rAXv(Bit8u insb);

		/* _E8_CALL_Jvds */
		inline bool handler_in_E8_CALL_Jvds(Bit8u insb);

		/* _E9_JMP_Jvds */
		inline bool handler_in_E9_JMP_Jvds(Bit8u insb);

		/* _EA_JMPF_Ap */
		inline bool handler_in_EA_JMPF_Ap(Bit8u insb);

		/* _EB_JMP_Jbs */
		inline bool handler_in_EB_JMP_Jbs(Bit8u insb);

		/* _EC_IN_ALb_DXw */
		inline bool handler_in_EC_IN_ALb_DXw(Bit8u insb);

		/* _ED_IN_rAXv_DXw */
		inline bool handler_in_ED_IN_rAXv_DXw(Bit8u insb);

		/* _EE_OUT_DXw_ALb */
		inline bool handler_in_EE_OUT_DXw_ALb(Bit8u insb);

		/* _EF_OUT_DXw_rAXv */
		inline bool handler_in_EF_OUT_DXw_rAXv(Bit8u insb);

		/* _F1_INT1 */
		inline bool handler_in_F1_INT1(Bit8u insb);

		/* _F3_0F_B8_POPCNT_Gvqp_Evqp */
		inline bool handler_in_F3_0F_B8_POPCNT_Gvqp_Evqp(Bit8u insb);

		/* _F3_90_NOP */
		inline bool handler_in_F3_90_NOP(Bit8u insb);

		/* _F4_HLT */
		inline bool handler_in_F4_HLT(Bit8u insb);

		/* _F5_CMC */
		inline bool handler_in_F5_CMC(Bit8u insb);

		/* _F6_01_TEST_Ib */
		inline bool handler_in_F6_01_TEST_Ib(Bit8u insb);

		/* _F6_02_NOT_Eb */
		inline bool handler_in_F6_02_NOT_Eb(Bit8u insb);

		/* _F6_03_NEG_Eb */
		inline bool handler_in_F6_03_NEG_Eb(Bit8u insb);

		/* _F6_04_MUL_Eb */
		inline bool handler_in_F6_04_MUL_Eb(Bit8u insb);

		/* _F6_05_IMUL_Eb */
		inline bool handler_in_F6_05_IMUL_Eb(Bit8u insb);

		/* _F6_06_DIV_Eb */
		inline bool handler_in_F6_06_DIV_Eb(Bit8u insb);

		/* _F6_07_IDIV_Eb */
		inline bool handler_in_F6_07_IDIV_Eb(Bit8u insb);

		/* _F7_01_TEST_Ivqp */
		inline bool handler_in_F7_01_TEST_Ivqp(Bit8u insb);

		/* _F7_02_NOT_Evqp */
		inline bool handler_in_F7_02_NOT_Evqp(Bit8u insb);

		/* _F7_03_NEG_Evqp */
		inline bool handler_in_F7_03_NEG_Evqp(Bit8u insb);

		/* _F7_04_MUL_Evqp */
		inline bool handler_in_F7_04_MUL_Evqp(Bit8u insb);

		/* _F7_05_IMUL_Evqp */
		inline bool handler_in_F7_05_IMUL_Evqp(Bit8u insb);

		/* _F7_06_DIV_Evqp */
		inline bool handler_in_F7_06_DIV_Evqp(Bit8u insb);

		/* _F7_07_IDIV_Evqp */
		inline bool handler_in_F7_07_IDIV_Evqp(Bit8u insb);

		/* _F8_CLC */
		inline bool handler_in_F8_CLC(Bit8u insb);

		/* _F9_STC */
		inline bool handler_in_F9_STC(Bit8u insb);

		/* _FA_CLI */
		inline bool handler_in_FA_CLI(Bit8u insb);

		/* _FB_STI */
		inline bool handler_in_FB_STI(Bit8u insb);

		/* _FC_CLD */
		inline bool handler_in_FC_CLD(Bit8u insb);

		/* _FD_STD */
		inline bool handler_in_FD_STD(Bit8u insb);

		/* _FE_00_INC_Eb */
		inline bool handler_in_FE_00_INC_Eb(Bit8u insb);

		/* _FE_01_DEC_Eb */
		inline bool handler_in_FE_01_DEC_Eb(Bit8u insb);

		/* _FF_00_INC_Evqp */
		inline bool handler_in_FF_00_INC_Evqp(Bit8u insb);

		/* _FF_01_DEC_Evqp */
		inline bool handler_in_FF_01_DEC_Evqp(Bit8u insb);

		/* _FF_02_CALL_Ev */
		inline bool handler_in_FF_02_CALL_Ev(Bit8u insb);

		/* _FF_03_CALLF_Mptp */
		inline bool handler_in_FF_03_CALLF_Mptp(Bit8u insb);

		/* _FF_04_JMP_Ev */
		inline bool handler_in_FF_04_JMP_Ev(Bit8u insb);

		/* _FF_05_JMPF_Mptp */
		inline bool handler_in_FF_05_JMPF_Mptp(Bit8u insb);

		/* _FF_06_PUSH_Ev */
		inline bool handler_in_FF_06_PUSH_Ev(Bit8u insb);

		inline bool handler_st(Bit8u insb);

		inline bool handler_st_0F(Bit8u insb);

		inline bool handler_st_0F_00(Bit8u insb);

		inline bool handler_st_0F_01(Bit8u insb);

		inline bool handler_st_0F_1F(Bit8u insb);

		inline bool handler_st_0F_38(Bit8u insb);

		inline bool handler_st_0F_90(Bit8u insb);

		inline bool handler_st_0F_91(Bit8u insb);

		inline bool handler_st_0F_92(Bit8u insb);

		inline bool handler_st_0F_93(Bit8u insb);

		inline bool handler_st_0F_94(Bit8u insb);

		inline bool handler_st_0F_95(Bit8u insb);

		inline bool handler_st_0F_96(Bit8u insb);

		inline bool handler_st_0F_97(Bit8u insb);

		inline bool handler_st_0F_98(Bit8u insb);

		inline bool handler_st_0F_99(Bit8u insb);

		inline bool handler_st_0F_9A(Bit8u insb);

		inline bool handler_st_0F_9B(Bit8u insb);

		inline bool handler_st_0F_9C(Bit8u insb);

		inline bool handler_st_0F_9D(Bit8u insb);

		inline bool handler_st_0F_9E(Bit8u insb);

		inline bool handler_st_0F_9F(Bit8u insb);

		inline bool handler_st_0F_AE(Bit8u insb);

		inline bool handler_st_0F_BA(Bit8u insb);

		inline bool handler_st_0F_C7(Bit8u insb);

		inline bool handler_st_66(Bit8u insb);

		inline bool handler_st_81(Bit8u insb);

		inline bool handler_st_82(Bit8u insb);

		inline bool handler_st_83(Bit8u insb);

		inline bool handler_st_8F(Bit8u insb);

		inline bool handler_st_C0(Bit8u insb);

		inline bool handler_st_C1(Bit8u insb);

		inline bool handler_st_C6(Bit8u insb);

		inline bool handler_st_C7(Bit8u insb);

		inline bool handler_st_D0(Bit8u insb);

		inline bool handler_st_D1(Bit8u insb);

		inline bool handler_st_D2(Bit8u insb);

		inline bool handler_st_D3(Bit8u insb);

		inline bool handler_st_F2(Bit8u insb);

		inline bool handler_st_F3(Bit8u insb);

		inline bool handler_st_F3_0F(Bit8u insb);

		inline bool handler_st_F6(Bit8u insb);

		inline bool handler_st_F7(Bit8u insb);

		inline bool handler_st_FE(Bit8u insb);

		inline bool handler_st_FF(Bit8u insb);
		Bit8u ParsePrefix();

	public:
		bool Parse();
	};

}

#endif //PROJECT_CORE_LLVM_H
