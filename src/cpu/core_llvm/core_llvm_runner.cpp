#include "core_llvm_runner.h"
namespace core_llvm {
const OpState CpuRunnerX86::table_st_w_w[] = {
	// 00
	in_ADD_w_rm_mod_reg_u8_rm_reg_reg_u8, in_ADD_w_rm_mod_reg_u16_rm_reg_reg_u16, in_ADD_w_rm_reg_reg_u8_rm_mod_reg_u8, in_ADD_w_rm_reg_reg_u16_rm_mod_reg_u16, in_ADD_reg_gen_u8_imm_u8, in_ADD_reg_gen_u16_imm_i16, in_PUSH_reg_seg_u16, in_POP_reg_seg_u16, 
	// 08
	in_OR_w_rm_mod_reg_u8_rm_reg_reg_u8, in_OR_w_rm_mod_reg_u16_rm_reg_reg_u16, in_OR_w_rm_reg_reg_u8_rm_mod_reg_u8, in_OR_w_rm_reg_reg_u16_rm_mod_reg_u16, in_OR_reg_gen_u8_imm_u8, in_OR_reg_gen_u16_imm_i16, in_PUSH_reg_seg_1_u16, st_w_w_0F, 
	// 10
	in_ADC_w_rm_mod_reg_u8_rm_reg_reg_u8, in_ADC_w_rm_mod_reg_u16_rm_reg_reg_u16, in_ADC_w_rm_reg_reg_u8_rm_mod_reg_u8, in_ADC_w_rm_reg_reg_u16_rm_mod_reg_u16, in_ADC_reg_gen_u8_imm_u8, in_ADC_reg_gen_u16_imm_i16, in_PUSH_reg_seg_2_u16, in_POP_reg_seg_2_u16, 
	// 18
	in_SBB_w_rm_mod_reg_u8_rm_reg_reg_u8, in_SBB_w_rm_mod_reg_u16_rm_reg_reg_u16, in_SBB_w_rm_reg_reg_u8_rm_mod_reg_u8, in_SBB_w_rm_reg_reg_u16_rm_mod_reg_u16, in_SBB_reg_gen_u8_imm_u8, in_SBB_reg_gen_u16_imm_i16, in_PUSH_reg_seg_3_u16, in_POP_reg_seg_3_u16, 
	// 20
	in_AND_w_rm_mod_reg_u8_rm_reg_reg_u8, in_AND_w_rm_mod_reg_u16_rm_reg_reg_u16, in_AND_w_rm_reg_reg_u8_rm_mod_reg_u8, in_AND_w_rm_reg_reg_u16_rm_mod_reg_u16, in_AND_reg_gen_u8_imm_u8, in_AND_reg_gen_u16_imm_i16, pr_w_d_26, in_DAA, 
	// 28
	in_SUB_w_rm_mod_reg_u8_rm_reg_reg_u8, in_SUB_w_rm_mod_reg_u16_rm_reg_reg_u16, in_SUB_w_rm_reg_reg_u8_rm_mod_reg_u8, in_SUB_w_rm_reg_reg_u16_rm_mod_reg_u16, in_SUB_reg_gen_u8_imm_u8, in_SUB_reg_gen_u16_imm_i16, pr_w_d_2E, in_DAS, 
	// 30
	in_XOR_w_rm_mod_reg_u8_rm_reg_reg_u8, in_XOR_w_rm_mod_reg_u16_rm_reg_reg_u16, in_XOR_w_rm_reg_reg_u8_rm_mod_reg_u8, in_XOR_w_rm_reg_reg_u16_rm_mod_reg_u16, in_XOR_reg_gen_u8_imm_u8, in_XOR_reg_gen_u16_imm_i16, pr_w_d_36, in_AAA, 
	// 38
	in_CMP_w_rm_reg_reg_u8, in_CMP_w_rm_reg_reg_u16, in_CMP_w_rm_mod_reg_u8, in_CMP_w_rm_mod_reg_u16, in_CMP_imm_u8, in_CMP_imm_i16, pr_w_d_3E, in_AAS, 
	// 40
	in_INC_reg_reg_u16, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_DEC_reg_reg_u16, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_PUSH_reg_reg_u16, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_POP_reg_reg_u16, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_PUSHA, in_POPA, in_BOUND_w_rm_mem_u16, in_ARPL_w_rm_reg_reg_u16, pr_w_d_64, pr_w_d_65, st_w_d_66, st_d_d, 
	// 68
	in_PUSH_imm_i16, in_IMUL_w_rm_reg_reg_u16_imm_i16, in_PUSH_imm_i8, in_IMUL_w_rm_reg_reg_u16_imm_u8, in_INS_w_mem_reg_7_u8_reg_gen_2_u16, in_INS_w_mem_reg_7_u16_reg_gen_2_u16, in_OUTS_w_reg_gen_2_u16_mem_reg_6_u8, in_OUTS_w_reg_gen_2_u16_mem_reg_6_u16, 
	// 70
	in_JO_w_mem_imm_J_u8, in_JNO_w_mem_imm_J_u8, in_JB_w_mem_imm_J_u8, in_JNB_w_mem_imm_J_u8, in_JZ_w_mem_imm_J_u8, in_JNZ_w_mem_imm_J_u8, in_JBE_w_mem_imm_J_u8, in_JNBE_w_mem_imm_J_u8, 
	// 78
	in_JS_w_mem_imm_J_u8, in_JNS_w_mem_imm_J_u8, in_JP_w_mem_imm_J_u8, in_JNP_w_mem_imm_J_u8, in_JL_w_mem_imm_J_u8, in_JNL_w_mem_imm_J_u8, in_JLE_w_mem_imm_J_u8, in_JNLE_w_mem_imm_J_u8, 
	// 80
	in_illegal, st_w_w_81, st_w_w_82, st_w_w_83, in_TEST_w_rm_reg_reg_u8, in_TEST_w_rm_reg_reg_u16, in_XCHG_w_rm_mod_reg_u8, in_XCHG_w_rm_mod_reg_u16, 
	// 88
	in_MOV_w_rm_mod_reg_u8_rm_reg_reg_u8, in_MOV_w_rm_mod_reg_u16_rm_reg_reg_u16, in_MOV_w_rm_reg_reg_u8_rm_mod_reg_u8, in_MOV_w_rm_reg_reg_u16_rm_mod_reg_u16, in_MOV_w_rm_mem_u16_rm_reg_seg_u16, in_LEA_rm_reg_reg_u16, in_MOV_w_rm_reg_seg_u16_rm_mod_reg_u16, st_w_w_8F, 
	// 90
	in_XCHG_reg_gen_u16, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_CBW, in_CWD, in_CALLF_w_mem_imm_p32, in_FWAIT, in_PUSHF, in_POPF, in_illegal, in_illegal, 
	// A0
	in_MOV_w_reg_gen_u8_mem_imm_O_u8, in_MOV_w_reg_gen_u16_mem_imm_O_u16, in_MOV_w_mem_imm_O_u8_reg_gen_u8, in_MOV_w_mem_imm_O_u16_reg_gen_u16, in_MOVS_w_mem_reg_7_u8_mem_reg_6_u8, in_MOVS_w_mem_reg_7_u16_mem_reg_6_u16, in_CMPS_w_mem_reg_6_u8, in_CMPS_w_mem_reg_6_u16, 
	// A8
	in_TEST_imm_u8, in_TEST_imm_i16, in_STOS_w_mem_reg_7_u8, in_STOS_w_mem_reg_7_u16, in_LODS_w_mem_reg_6_u8, in_LODS_w_mem_reg_6_u16, in_SCAS_w_mem_reg_7_u8, in_SCAS_w_mem_reg_7_u16, 
	// B0
	in_MOV_reg_reg_u8_imm_u8, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_MOV_reg_reg_u16_imm_u16, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	st_w_w_C0, st_w_w_C1, in_RETN_imm_u16, in_RETN, in_LES_w_rm_reg_reg_u16_rm_mem_p32, in_LDS_w_rm_reg_reg_u16_rm_mem_p32, st_w_w_C6, st_w_w_C7, 
	// C8
	in_ENTER_imm_u8, in_LEAVE, in_RETF_imm_u16, in_RETF, in_INT, in_INT_imm_u8, in_INTO, in_IRET, 
	// D0
	st_w_w_D0, st_w_w_D1, st_w_w_D2, st_w_w_D3, in_AMX_imm_u8, in_ADX_imm_u8, in_illegal, in_XLAT_w_mem_reg_3_u8, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_LOOPNZ_w_mem_imm_J_u8, in_LOOPZ_w_mem_imm_J_u8, in_LOOP_w_mem_imm_J_u8, in_JCXZ_w_mem_imm_J_u8, in_IN_reg_gen_u8_imm_u8, in_IN_reg_gen_u16_imm_u8, in_OUT_imm_u8_reg_gen_u8, in_OUT_imm_u8_reg_gen_u16, 
	// E8
	in_illegal, in_illegal, in_JMPF_w_mem_imm_p32, in_JMP_w_mem_imm_J_u8, in_IN_reg_gen_u8_reg_gen_2_u16, in_IN_reg_gen_u16_reg_gen_2_u16, in_OUT_reg_gen_2_u16_reg_gen_u8, in_OUT_reg_gen_2_u16_reg_gen_u16, 
	// F0
	pr_d_d_F0, in_illegal, pr_w_d_F2, pr_w_d_F3, in_HLT, in_CMC, st_w_w_F6, st_w_w_F7, 
	// F8
	in_CLC, in_STC, in_CLI, in_STI, in_CLD, in_STD, st_w_w_FE, st_w_w_FF, 
};
const OpState CpuRunnerX86::table_st_w_d[] = {
	// 00
	in_ADD_w_rm_mod_reg_u8_rm_reg_reg_u8, in_ADD_w_rm_mod_reg_u32_rm_reg_reg_u32, in_ADD_w_rm_reg_reg_u8_rm_mod_reg_u8, in_ADD_w_rm_reg_reg_u32_rm_mod_reg_u32, in_ADD_reg_gen_u8_imm_u8, in_ADD_reg_gen_u32_imm_i32, in_PUSH_reg_seg_u16, in_POP_reg_seg_u16, 
	// 08
	in_OR_w_rm_mod_reg_u8_rm_reg_reg_u8, in_OR_w_rm_mod_reg_u32_rm_reg_reg_u32, in_OR_w_rm_reg_reg_u8_rm_mod_reg_u8, in_OR_w_rm_reg_reg_u32_rm_mod_reg_u32, in_OR_reg_gen_u8_imm_u8, in_OR_reg_gen_u32_imm_i32, in_PUSH_reg_seg_1_u16, st_w_d_0F, 
	// 10
	in_ADC_w_rm_mod_reg_u8_rm_reg_reg_u8, in_ADC_w_rm_mod_reg_u32_rm_reg_reg_u32, in_ADC_w_rm_reg_reg_u8_rm_mod_reg_u8, in_ADC_w_rm_reg_reg_u32_rm_mod_reg_u32, in_ADC_reg_gen_u8_imm_u8, in_ADC_reg_gen_u32_imm_i32, in_PUSH_reg_seg_2_u16, in_POP_reg_seg_2_u16, 
	// 18
	in_SBB_w_rm_mod_reg_u8_rm_reg_reg_u8, in_SBB_w_rm_mod_reg_u32_rm_reg_reg_u32, in_SBB_w_rm_reg_reg_u8_rm_mod_reg_u8, in_SBB_w_rm_reg_reg_u32_rm_mod_reg_u32, in_SBB_reg_gen_u8_imm_u8, in_SBB_reg_gen_u32_imm_i32, in_PUSH_reg_seg_3_u16, in_POP_reg_seg_3_u16, 
	// 20
	in_AND_w_rm_mod_reg_u8_rm_reg_reg_u8, in_AND_w_rm_mod_reg_u32_rm_reg_reg_u32, in_AND_w_rm_reg_reg_u8_rm_mod_reg_u8, in_AND_w_rm_reg_reg_u32_rm_mod_reg_u32, in_AND_reg_gen_u8_imm_u8, in_AND_reg_gen_u32_imm_i32, pr_w_w_26, in_DAA, 
	// 28
	in_SUB_w_rm_mod_reg_u8_rm_reg_reg_u8, in_SUB_w_rm_mod_reg_u32_rm_reg_reg_u32, in_SUB_w_rm_reg_reg_u8_rm_mod_reg_u8, in_SUB_w_rm_reg_reg_u32_rm_mod_reg_u32, in_SUB_reg_gen_u8_imm_u8, in_SUB_reg_gen_u32_imm_i32, pr_w_w_2E, in_DAS, 
	// 30
	in_XOR_w_rm_mod_reg_u8_rm_reg_reg_u8, in_XOR_w_rm_mod_reg_u32_rm_reg_reg_u32, in_XOR_w_rm_reg_reg_u8_rm_mod_reg_u8, in_XOR_w_rm_reg_reg_u32_rm_mod_reg_u32, in_XOR_reg_gen_u8_imm_u8, in_XOR_reg_gen_u32_imm_i32, pr_w_w_36, in_AAA, 
	// 38
	in_CMP_w_rm_reg_reg_u8, in_CMP_w_rm_reg_reg_u32, in_CMP_w_rm_mod_reg_u8, in_CMP_w_rm_mod_reg_u32, in_CMP_imm_u8, in_CMP_imm_i32, pr_w_w_3E, in_AAS, 
	// 40
	in_INC_reg_reg_u16, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_DEC_reg_reg_u16, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_PUSH_reg_reg_u16, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_POP_reg_reg_u16, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_PUSHA, in_POPA, in_BOUND_w_rm_mem_u16, in_ARPL_w_rm_reg_reg_u16, pr_w_w_64, pr_w_w_65, st_w_w_66, st_d_w, 
	// 68
	in_PUSH_imm_i16, in_IMUL_w_rm_reg_reg_u16_imm_i16, in_PUSH_imm_i8, in_IMUL_w_rm_reg_reg_u16_imm_u8, in_INS_w_mem_reg_7_u8_reg_gen_2_u16, in_INS_w_mem_reg_7_u32_reg_gen_2_u16, in_OUTS_w_reg_gen_2_u16_mem_reg_6_u8, in_OUTS_w_reg_gen_2_u16_mem_reg_6_u32, 
	// 70
	in_JO_w_mem_imm_J_u8, in_JNO_w_mem_imm_J_u8, in_JB_w_mem_imm_J_u8, in_JNB_w_mem_imm_J_u8, in_JZ_w_mem_imm_J_u8, in_JNZ_w_mem_imm_J_u8, in_JBE_w_mem_imm_J_u8, in_JNBE_w_mem_imm_J_u8, 
	// 78
	in_JS_w_mem_imm_J_u8, in_JNS_w_mem_imm_J_u8, in_JP_w_mem_imm_J_u8, in_JNP_w_mem_imm_J_u8, in_JL_w_mem_imm_J_u8, in_JNL_w_mem_imm_J_u8, in_JLE_w_mem_imm_J_u8, in_JNLE_w_mem_imm_J_u8, 
	// 80
	in_illegal, st_w_d_81, st_w_d_82, st_w_d_83, in_TEST_w_rm_reg_reg_u8, in_TEST_w_rm_reg_reg_u32, in_XCHG_w_rm_mod_reg_u8, in_XCHG_w_rm_mod_reg_u32, 
	// 88
	in_MOV_w_rm_mod_reg_u8_rm_reg_reg_u8, in_MOV_w_rm_mod_reg_u32_rm_reg_reg_u32, in_MOV_w_rm_reg_reg_u8_rm_mod_reg_u8, in_MOV_w_rm_reg_reg_u16_rm_mod_reg_u16, in_MOV_w_rm_mem_u16_rm_reg_seg_u16, in_LEA_rm_reg_reg_u16, in_MOV_w_rm_reg_seg_u16_rm_mod_reg_u16, st_w_d_8F, 
	// 90
	in_XCHG_reg_gen_u16, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_CWDE, in_CDQ, in_CALLF_w_mem_imm_p32, in_FWAIT, in_PUSHF, in_POPF, in_illegal, in_illegal, 
	// A0
	in_MOV_w_reg_gen_u8_mem_imm_O_u8, in_MOV_w_reg_gen_u32_mem_imm_O_u32, in_MOV_w_mem_imm_O_u8_reg_gen_u8, in_MOV_w_mem_imm_O_u32_reg_gen_u32, in_MOVS_w_mem_reg_7_u8_mem_reg_6_u8, in_MOVS_w_mem_reg_7_u32_mem_reg_6_u32, in_CMPS_w_mem_reg_6_u8, in_CMPS_w_mem_reg_6_u32, 
	// A8
	in_TEST_imm_u8, in_TEST_imm_i32, in_STOS_w_mem_reg_7_u8, in_STOS_w_mem_reg_7_u32, in_LODS_w_mem_reg_6_u8, in_LODS_w_mem_reg_6_u32, in_SCAS_w_mem_reg_7_u8, in_SCAS_w_mem_reg_7_u32, 
	// B0
	in_MOV_reg_reg_u8_imm_u8, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_MOV_reg_reg_u16_imm_u16, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	st_w_d_C0, st_w_d_C1, in_RETN_imm_u16, in_RETN, in_LES_w_rm_reg_reg_u16_rm_mem_p32, in_LDS_w_rm_reg_reg_u16_rm_mem_p32, st_w_d_C6, st_w_d_C7, 
	// C8
	in_ENTER_imm_u8, in_LEAVE, in_RETF_imm_u16, in_RETF, in_INT, in_INT_imm_u8, in_INTO, in_IRET, 
	// D0
	st_w_d_D0, st_w_d_D1, st_w_d_D2, st_w_d_D3, in_AMX_imm_u8, in_ADX_imm_u8, in_illegal, in_XLAT_w_mem_reg_3_u8, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_LOOPNZ_w_mem_imm_J_u8, in_LOOPZ_w_mem_imm_J_u8, in_LOOP_w_mem_imm_J_u8, in_JCXZ_w_mem_imm_J_u8, in_IN_reg_gen_u8_imm_u8, in_IN_reg_gen_u32_imm_u8, in_OUT_imm_u8_reg_gen_u8, in_OUT_imm_u8_reg_gen_u32, 
	// E8
	in_illegal, in_illegal, in_JMPF_w_mem_imm_p32, in_JMP_w_mem_imm_J_u8, in_IN_reg_gen_u8_reg_gen_2_u16, in_IN_reg_gen_u32_reg_gen_2_u16, in_OUT_reg_gen_2_u16_reg_gen_u8, in_OUT_reg_gen_2_u16_reg_gen_u32, 
	// F0
	pr_d_w_F0, in_illegal, pr_w_w_F2, pr_w_w_F3, in_HLT, in_CMC, st_w_d_F6, st_w_d_F7, 
	// F8
	in_CLC, in_STC, in_CLI, in_STI, in_CLD, in_STD, st_w_d_FE, st_w_d_FF, 
};
const OpState CpuRunnerX86::table_st_d_w[] = {
	// 00
	in_ADD_d_rm_mod_reg_u8_rm_reg_reg_u8, in_ADD_d_rm_mod_reg_u16_rm_reg_reg_u16, in_ADD_d_rm_reg_reg_u8_rm_mod_reg_u8, in_ADD_d_rm_reg_reg_u16_rm_mod_reg_u16, in_ADD_reg_gen_u8_imm_u8, in_ADD_reg_gen_u16_imm_i16, in_PUSH_reg_seg_u16, in_POP_reg_seg_u16, 
	// 08
	in_OR_d_rm_mod_reg_u8_rm_reg_reg_u8, in_OR_d_rm_mod_reg_u16_rm_reg_reg_u16, in_OR_d_rm_reg_reg_u8_rm_mod_reg_u8, in_OR_d_rm_reg_reg_u16_rm_mod_reg_u16, in_OR_reg_gen_u8_imm_u8, in_OR_reg_gen_u16_imm_i16, in_PUSH_reg_seg_1_u16, st_d_w_0F, 
	// 10
	in_ADC_d_rm_mod_reg_u8_rm_reg_reg_u8, in_ADC_d_rm_mod_reg_u16_rm_reg_reg_u16, in_ADC_d_rm_reg_reg_u8_rm_mod_reg_u8, in_ADC_d_rm_reg_reg_u16_rm_mod_reg_u16, in_ADC_reg_gen_u8_imm_u8, in_ADC_reg_gen_u16_imm_i16, in_PUSH_reg_seg_2_u16, in_POP_reg_seg_2_u16, 
	// 18
	in_SBB_d_rm_mod_reg_u8_rm_reg_reg_u8, in_SBB_d_rm_mod_reg_u16_rm_reg_reg_u16, in_SBB_d_rm_reg_reg_u8_rm_mod_reg_u8, in_SBB_d_rm_reg_reg_u16_rm_mod_reg_u16, in_SBB_reg_gen_u8_imm_u8, in_SBB_reg_gen_u16_imm_i16, in_PUSH_reg_seg_3_u16, in_POP_reg_seg_3_u16, 
	// 20
	in_AND_d_rm_mod_reg_u8_rm_reg_reg_u8, in_AND_d_rm_mod_reg_u16_rm_reg_reg_u16, in_AND_d_rm_reg_reg_u8_rm_mod_reg_u8, in_AND_d_rm_reg_reg_u16_rm_mod_reg_u16, in_AND_reg_gen_u8_imm_u8, in_AND_reg_gen_u16_imm_i16, pr_d_d_26, in_DAA, 
	// 28
	in_SUB_d_rm_mod_reg_u8_rm_reg_reg_u8, in_SUB_d_rm_mod_reg_u16_rm_reg_reg_u16, in_SUB_d_rm_reg_reg_u8_rm_mod_reg_u8, in_SUB_d_rm_reg_reg_u16_rm_mod_reg_u16, in_SUB_reg_gen_u8_imm_u8, in_SUB_reg_gen_u16_imm_i16, pr_d_d_2E, in_DAS, 
	// 30
	in_XOR_d_rm_mod_reg_u8_rm_reg_reg_u8, in_XOR_d_rm_mod_reg_u16_rm_reg_reg_u16, in_XOR_d_rm_reg_reg_u8_rm_mod_reg_u8, in_XOR_d_rm_reg_reg_u16_rm_mod_reg_u16, in_XOR_reg_gen_u8_imm_u8, in_XOR_reg_gen_u16_imm_i16, pr_d_d_36, in_AAA, 
	// 38
	in_CMP_d_rm_reg_reg_u8, in_CMP_d_rm_reg_reg_u16, in_CMP_d_rm_mod_reg_u8, in_CMP_d_rm_mod_reg_u16, in_CMP_imm_u8, in_CMP_imm_i16, pr_d_d_3E, in_AAS, 
	// 40
	in_INC_reg_reg_u16, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_DEC_reg_reg_u16, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_PUSH_reg_reg_u16, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_POP_reg_reg_u16, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_PUSHA, in_POPA, in_BOUND_d_rm_mem_u16, in_ARPL_d_rm_reg_reg_u16, pr_d_d_64, pr_d_d_65, st_d_d_66, st_w_d, 
	// 68
	in_PUSH_imm_i16, in_IMUL_d_rm_reg_reg_u16_imm_i16, in_PUSH_imm_i8, in_IMUL_d_rm_reg_reg_u16_imm_u8, in_INS_d_mem_reg_7_u8_reg_gen_2_u16, in_INS_d_mem_reg_7_u16_reg_gen_2_u16, in_OUTS_d_reg_gen_2_u16_mem_reg_6_u8, in_OUTS_d_reg_gen_2_u16_mem_reg_6_u16, 
	// 70
	in_JO_d_mem_imm_J_u8, in_JNO_d_mem_imm_J_u8, in_JB_d_mem_imm_J_u8, in_JNB_d_mem_imm_J_u8, in_JZ_d_mem_imm_J_u8, in_JNZ_d_mem_imm_J_u8, in_JBE_d_mem_imm_J_u8, in_JNBE_d_mem_imm_J_u8, 
	// 78
	in_JS_d_mem_imm_J_u8, in_JNS_d_mem_imm_J_u8, in_JP_d_mem_imm_J_u8, in_JNP_d_mem_imm_J_u8, in_JL_d_mem_imm_J_u8, in_JNL_d_mem_imm_J_u8, in_JLE_d_mem_imm_J_u8, in_JNLE_d_mem_imm_J_u8, 
	// 80
	in_illegal, st_d_w_81, st_d_w_82, st_d_w_83, in_TEST_d_rm_reg_reg_u8, in_TEST_d_rm_reg_reg_u16, in_XCHG_d_rm_mod_reg_u8, in_XCHG_d_rm_mod_reg_u16, 
	// 88
	in_MOV_d_rm_mod_reg_u8_rm_reg_reg_u8, in_MOV_d_rm_mod_reg_u16_rm_reg_reg_u16, in_MOV_d_rm_reg_reg_u8_rm_mod_reg_u8, in_MOV_d_rm_reg_reg_u16_rm_mod_reg_u16, in_MOV_d_rm_mem_u16_rm_reg_seg_u16, in_LEA_rm_reg_reg_u16, in_MOV_d_rm_reg_seg_u16_rm_mod_reg_u16, st_d_w_8F, 
	// 90
	in_XCHG_reg_gen_u16, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_CBW, in_CWD, in_CALLF_d_mem_imm_p32, in_FWAIT, in_PUSHF, in_POPF, in_illegal, in_illegal, 
	// A0
	in_MOV_d_reg_gen_u8_mem_imm_O_u8, in_MOV_d_reg_gen_u16_mem_imm_O_u16, in_MOV_d_mem_imm_O_u8_reg_gen_u8, in_MOV_d_mem_imm_O_u16_reg_gen_u16, in_MOVS_d_mem_reg_7_u8_mem_reg_6_u8, in_MOVS_d_mem_reg_7_u16_mem_reg_6_u16, in_CMPS_d_mem_reg_6_u8, in_CMPS_d_mem_reg_6_u16, 
	// A8
	in_TEST_imm_u8, in_TEST_imm_i16, in_STOS_d_mem_reg_7_u8, in_STOS_d_mem_reg_7_u16, in_LODS_d_mem_reg_6_u8, in_LODS_d_mem_reg_6_u16, in_SCAS_d_mem_reg_7_u8, in_SCAS_d_mem_reg_7_u16, 
	// B0
	in_MOV_reg_reg_u8_imm_u8, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_MOV_reg_reg_u16_imm_u16, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	st_d_w_C0, st_d_w_C1, in_RETN_imm_u16, in_RETN, in_LES_d_rm_reg_reg_u16_rm_mem_p32, in_LDS_d_rm_reg_reg_u16_rm_mem_p32, st_d_w_C6, st_d_w_C7, 
	// C8
	in_ENTER_imm_u8, in_LEAVE, in_RETF_imm_u16, in_RETF, in_INT, in_INT_imm_u8, in_INTO, in_IRET, 
	// D0
	st_d_w_D0, st_d_w_D1, st_d_w_D2, st_d_w_D3, in_AMX_imm_u8, in_ADX_imm_u8, in_illegal, in_XLAT_d_mem_reg_3_u8, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_LOOPNZ_d_mem_imm_J_u8, in_LOOPZ_d_mem_imm_J_u8, in_LOOP_d_mem_imm_J_u8, in_JCXZ_d_mem_imm_J_u8, in_IN_reg_gen_u8_imm_u8, in_IN_reg_gen_u16_imm_u8, in_OUT_imm_u8_reg_gen_u8, in_OUT_imm_u8_reg_gen_u16, 
	// E8
	in_illegal, in_illegal, in_JMPF_d_mem_imm_p32, in_JMP_d_mem_imm_J_u8, in_IN_reg_gen_u8_reg_gen_2_u16, in_IN_reg_gen_u16_reg_gen_2_u16, in_OUT_reg_gen_2_u16_reg_gen_u8, in_OUT_reg_gen_2_u16_reg_gen_u16, 
	// F0
	pr_w_d_F0, in_illegal, pr_d_d_F2, pr_d_d_F3, in_HLT, in_CMC, st_d_w_F6, st_d_w_F7, 
	// F8
	in_CLC, in_STC, in_CLI, in_STI, in_CLD, in_STD, st_d_w_FE, st_d_w_FF, 
};
const OpState CpuRunnerX86::table_st_d_d[] = {
	// 00
	in_ADD_d_rm_mod_reg_u8_rm_reg_reg_u8, in_ADD_d_rm_mod_reg_u32_rm_reg_reg_u32, in_ADD_d_rm_reg_reg_u8_rm_mod_reg_u8, in_ADD_d_rm_reg_reg_u32_rm_mod_reg_u32, in_ADD_reg_gen_u8_imm_u8, in_ADD_reg_gen_u32_imm_i32, in_PUSH_reg_seg_u16, in_POP_reg_seg_u16, 
	// 08
	in_OR_d_rm_mod_reg_u8_rm_reg_reg_u8, in_OR_d_rm_mod_reg_u32_rm_reg_reg_u32, in_OR_d_rm_reg_reg_u8_rm_mod_reg_u8, in_OR_d_rm_reg_reg_u32_rm_mod_reg_u32, in_OR_reg_gen_u8_imm_u8, in_OR_reg_gen_u32_imm_i32, in_PUSH_reg_seg_1_u16, st_d_d_0F, 
	// 10
	in_ADC_d_rm_mod_reg_u8_rm_reg_reg_u8, in_ADC_d_rm_mod_reg_u32_rm_reg_reg_u32, in_ADC_d_rm_reg_reg_u8_rm_mod_reg_u8, in_ADC_d_rm_reg_reg_u32_rm_mod_reg_u32, in_ADC_reg_gen_u8_imm_u8, in_ADC_reg_gen_u32_imm_i32, in_PUSH_reg_seg_2_u16, in_POP_reg_seg_2_u16, 
	// 18
	in_SBB_d_rm_mod_reg_u8_rm_reg_reg_u8, in_SBB_d_rm_mod_reg_u32_rm_reg_reg_u32, in_SBB_d_rm_reg_reg_u8_rm_mod_reg_u8, in_SBB_d_rm_reg_reg_u32_rm_mod_reg_u32, in_SBB_reg_gen_u8_imm_u8, in_SBB_reg_gen_u32_imm_i32, in_PUSH_reg_seg_3_u16, in_POP_reg_seg_3_u16, 
	// 20
	in_AND_d_rm_mod_reg_u8_rm_reg_reg_u8, in_AND_d_rm_mod_reg_u32_rm_reg_reg_u32, in_AND_d_rm_reg_reg_u8_rm_mod_reg_u8, in_AND_d_rm_reg_reg_u32_rm_mod_reg_u32, in_AND_reg_gen_u8_imm_u8, in_AND_reg_gen_u32_imm_i32, pr_d_w_26, in_DAA, 
	// 28
	in_SUB_d_rm_mod_reg_u8_rm_reg_reg_u8, in_SUB_d_rm_mod_reg_u32_rm_reg_reg_u32, in_SUB_d_rm_reg_reg_u8_rm_mod_reg_u8, in_SUB_d_rm_reg_reg_u32_rm_mod_reg_u32, in_SUB_reg_gen_u8_imm_u8, in_SUB_reg_gen_u32_imm_i32, pr_d_w_2E, in_DAS, 
	// 30
	in_XOR_d_rm_mod_reg_u8_rm_reg_reg_u8, in_XOR_d_rm_mod_reg_u32_rm_reg_reg_u32, in_XOR_d_rm_reg_reg_u8_rm_mod_reg_u8, in_XOR_d_rm_reg_reg_u32_rm_mod_reg_u32, in_XOR_reg_gen_u8_imm_u8, in_XOR_reg_gen_u32_imm_i32, pr_d_w_36, in_AAA, 
	// 38
	in_CMP_d_rm_reg_reg_u8, in_CMP_d_rm_reg_reg_u32, in_CMP_d_rm_mod_reg_u8, in_CMP_d_rm_mod_reg_u32, in_CMP_imm_u8, in_CMP_imm_i32, pr_d_w_3E, in_AAS, 
	// 40
	in_INC_reg_reg_u16, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_DEC_reg_reg_u16, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_PUSH_reg_reg_u16, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_POP_reg_reg_u16, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_PUSHA, in_POPA, in_BOUND_d_rm_mem_u16, in_ARPL_d_rm_reg_reg_u16, pr_d_w_64, pr_d_w_65, st_d_w_66, st_w_w, 
	// 68
	in_PUSH_imm_i16, in_IMUL_d_rm_reg_reg_u16_imm_i16, in_PUSH_imm_i8, in_IMUL_d_rm_reg_reg_u16_imm_u8, in_INS_d_mem_reg_7_u8_reg_gen_2_u16, in_INS_d_mem_reg_7_u32_reg_gen_2_u16, in_OUTS_d_reg_gen_2_u16_mem_reg_6_u8, in_OUTS_d_reg_gen_2_u16_mem_reg_6_u32, 
	// 70
	in_JO_d_mem_imm_J_u8, in_JNO_d_mem_imm_J_u8, in_JB_d_mem_imm_J_u8, in_JNB_d_mem_imm_J_u8, in_JZ_d_mem_imm_J_u8, in_JNZ_d_mem_imm_J_u8, in_JBE_d_mem_imm_J_u8, in_JNBE_d_mem_imm_J_u8, 
	// 78
	in_JS_d_mem_imm_J_u8, in_JNS_d_mem_imm_J_u8, in_JP_d_mem_imm_J_u8, in_JNP_d_mem_imm_J_u8, in_JL_d_mem_imm_J_u8, in_JNL_d_mem_imm_J_u8, in_JLE_d_mem_imm_J_u8, in_JNLE_d_mem_imm_J_u8, 
	// 80
	in_illegal, st_d_d_81, st_d_d_82, st_d_d_83, in_TEST_d_rm_reg_reg_u8, in_TEST_d_rm_reg_reg_u32, in_XCHG_d_rm_mod_reg_u8, in_XCHG_d_rm_mod_reg_u32, 
	// 88
	in_MOV_d_rm_mod_reg_u8_rm_reg_reg_u8, in_MOV_d_rm_mod_reg_u32_rm_reg_reg_u32, in_MOV_d_rm_reg_reg_u8_rm_mod_reg_u8, in_MOV_d_rm_reg_reg_u16_rm_mod_reg_u16, in_MOV_d_rm_mem_u16_rm_reg_seg_u16, in_LEA_rm_reg_reg_u16, in_MOV_d_rm_reg_seg_u16_rm_mod_reg_u16, st_d_d_8F, 
	// 90
	in_XCHG_reg_gen_u16, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_CWDE, in_CDQ, in_CALLF_d_mem_imm_p32, in_FWAIT, in_PUSHF, in_POPF, in_illegal, in_illegal, 
	// A0
	in_MOV_d_reg_gen_u8_mem_imm_O_u8, in_MOV_d_reg_gen_u32_mem_imm_O_u32, in_MOV_d_mem_imm_O_u8_reg_gen_u8, in_MOV_d_mem_imm_O_u32_reg_gen_u32, in_MOVS_d_mem_reg_7_u8_mem_reg_6_u8, in_MOVS_d_mem_reg_7_u32_mem_reg_6_u32, in_CMPS_d_mem_reg_6_u8, in_CMPS_d_mem_reg_6_u32, 
	// A8
	in_TEST_imm_u8, in_TEST_imm_i32, in_STOS_d_mem_reg_7_u8, in_STOS_d_mem_reg_7_u32, in_LODS_d_mem_reg_6_u8, in_LODS_d_mem_reg_6_u32, in_SCAS_d_mem_reg_7_u8, in_SCAS_d_mem_reg_7_u32, 
	// B0
	in_MOV_reg_reg_u8_imm_u8, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_MOV_reg_reg_u16_imm_u16, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	st_d_d_C0, st_d_d_C1, in_RETN_imm_u16, in_RETN, in_LES_d_rm_reg_reg_u16_rm_mem_p32, in_LDS_d_rm_reg_reg_u16_rm_mem_p32, st_d_d_C6, st_d_d_C7, 
	// C8
	in_ENTER_imm_u8, in_LEAVE, in_RETF_imm_u16, in_RETF, in_INT, in_INT_imm_u8, in_INTO, in_IRET, 
	// D0
	st_d_d_D0, st_d_d_D1, st_d_d_D2, st_d_d_D3, in_AMX_imm_u8, in_ADX_imm_u8, in_illegal, in_XLAT_d_mem_reg_3_u8, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_LOOPNZ_d_mem_imm_J_u8, in_LOOPZ_d_mem_imm_J_u8, in_LOOP_d_mem_imm_J_u8, in_JCXZ_d_mem_imm_J_u8, in_IN_reg_gen_u8_imm_u8, in_IN_reg_gen_u32_imm_u8, in_OUT_imm_u8_reg_gen_u8, in_OUT_imm_u8_reg_gen_u32, 
	// E8
	in_illegal, in_illegal, in_JMPF_d_mem_imm_p32, in_JMP_d_mem_imm_J_u8, in_IN_reg_gen_u8_reg_gen_2_u16, in_IN_reg_gen_u32_reg_gen_2_u16, in_OUT_reg_gen_2_u16_reg_gen_u8, in_OUT_reg_gen_2_u16_reg_gen_u32, 
	// F0
	pr_w_w_F0, in_illegal, pr_d_w_F2, pr_d_w_F3, in_HLT, in_CMC, st_d_d_F6, st_d_d_F7, 
	// F8
	in_CLC, in_STC, in_CLI, in_STI, in_CLD, in_STD, st_d_d_FE, st_d_d_FF, 
};
const OpState CpuRunnerX86::table_st_w_w_66[] = {
	// 00
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_st_w_w_F2[] = {
	// 00
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_st_w_w_F3[] = {
	// 00
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_PAUSE, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_st_w_d_66[] = {
	// 00
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_st_w_d_F2[] = {
	// 00
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_st_w_d_F3[] = {
	// 00
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_PAUSE, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_st_d_w_66[] = {
	// 00
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_st_d_w_F2[] = {
	// 00
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_st_d_w_F3[] = {
	// 00
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_PAUSE, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_st_d_d_66[] = {
	// 00
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_st_d_d_F2[] = {
	// 00
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_st_d_d_F3[] = {
	// 00
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_PAUSE, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_st_w_w_82[] = {
	// 00
	in_ADD_w_rm_mod_reg_u8_imm_u8, in_ADD_w_rm_mod_reg_u8_imm_u8, in_ADD_w_rm_mod_reg_u8_imm_u8, in_ADD_w_rm_mod_reg_u8_imm_u8, in_ADD_w_rm_mod_reg_u8_imm_u8, in_ADD_w_rm_mod_reg_u8_imm_u8, in_ADD_w_rm_mod_reg_u8_imm_u8, in_ADD_w_rm_mod_reg_u8_imm_u8, 
	// 08
	in_OR_w_rm_mod_reg_u8_imm_u8, in_OR_w_rm_mod_reg_u8_imm_u8, in_OR_w_rm_mod_reg_u8_imm_u8, in_OR_w_rm_mod_reg_u8_imm_u8, in_OR_w_rm_mod_reg_u8_imm_u8, in_OR_w_rm_mod_reg_u8_imm_u8, in_OR_w_rm_mod_reg_u8_imm_u8, in_OR_w_rm_mod_reg_u8_imm_u8, 
	// 10
	in_ADC_w_rm_mod_reg_u8_imm_u8, in_ADC_w_rm_mod_reg_u8_imm_u8, in_ADC_w_rm_mod_reg_u8_imm_u8, in_ADC_w_rm_mod_reg_u8_imm_u8, in_ADC_w_rm_mod_reg_u8_imm_u8, in_ADC_w_rm_mod_reg_u8_imm_u8, in_ADC_w_rm_mod_reg_u8_imm_u8, in_ADC_w_rm_mod_reg_u8_imm_u8, 
	// 18
	in_SBB_w_rm_mod_reg_u8_imm_u8, in_SBB_w_rm_mod_reg_u8_imm_u8, in_SBB_w_rm_mod_reg_u8_imm_u8, in_SBB_w_rm_mod_reg_u8_imm_u8, in_SBB_w_rm_mod_reg_u8_imm_u8, in_SBB_w_rm_mod_reg_u8_imm_u8, in_SBB_w_rm_mod_reg_u8_imm_u8, in_SBB_w_rm_mod_reg_u8_imm_u8, 
	// 20
	in_AND_w_rm_mod_reg_u8_imm_u8, in_AND_w_rm_mod_reg_u8_imm_u8, in_AND_w_rm_mod_reg_u8_imm_u8, in_AND_w_rm_mod_reg_u8_imm_u8, in_AND_w_rm_mod_reg_u8_imm_u8, in_AND_w_rm_mod_reg_u8_imm_u8, in_AND_w_rm_mod_reg_u8_imm_u8, in_AND_w_rm_mod_reg_u8_imm_u8, 
	// 28
	in_SUB_w_rm_mod_reg_u8_imm_u8, in_SUB_w_rm_mod_reg_u8_imm_u8, in_SUB_w_rm_mod_reg_u8_imm_u8, in_SUB_w_rm_mod_reg_u8_imm_u8, in_SUB_w_rm_mod_reg_u8_imm_u8, in_SUB_w_rm_mod_reg_u8_imm_u8, in_SUB_w_rm_mod_reg_u8_imm_u8, in_SUB_w_rm_mod_reg_u8_imm_u8, 
	// 30
	in_XOR_w_rm_mod_reg_u8_imm_u8, in_XOR_w_rm_mod_reg_u8_imm_u8, in_XOR_w_rm_mod_reg_u8_imm_u8, in_XOR_w_rm_mod_reg_u8_imm_u8, in_XOR_w_rm_mod_reg_u8_imm_u8, in_XOR_w_rm_mod_reg_u8_imm_u8, in_XOR_w_rm_mod_reg_u8_imm_u8, in_XOR_w_rm_mod_reg_u8_imm_u8, 
	// 38
	in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, 
	// 40
	in_ADD_w_rm_mod_reg_u8_imm_u8, in_ADD_w_rm_mod_reg_u8_imm_u8, in_ADD_w_rm_mod_reg_u8_imm_u8, in_ADD_w_rm_mod_reg_u8_imm_u8, in_ADD_w_rm_mod_reg_u8_imm_u8, in_ADD_w_rm_mod_reg_u8_imm_u8, in_ADD_w_rm_mod_reg_u8_imm_u8, in_ADD_w_rm_mod_reg_u8_imm_u8, 
	// 48
	in_OR_w_rm_mod_reg_u8_imm_u8, in_OR_w_rm_mod_reg_u8_imm_u8, in_OR_w_rm_mod_reg_u8_imm_u8, in_OR_w_rm_mod_reg_u8_imm_u8, in_OR_w_rm_mod_reg_u8_imm_u8, in_OR_w_rm_mod_reg_u8_imm_u8, in_OR_w_rm_mod_reg_u8_imm_u8, in_OR_w_rm_mod_reg_u8_imm_u8, 
	// 50
	in_ADC_w_rm_mod_reg_u8_imm_u8, in_ADC_w_rm_mod_reg_u8_imm_u8, in_ADC_w_rm_mod_reg_u8_imm_u8, in_ADC_w_rm_mod_reg_u8_imm_u8, in_ADC_w_rm_mod_reg_u8_imm_u8, in_ADC_w_rm_mod_reg_u8_imm_u8, in_ADC_w_rm_mod_reg_u8_imm_u8, in_ADC_w_rm_mod_reg_u8_imm_u8, 
	// 58
	in_SBB_w_rm_mod_reg_u8_imm_u8, in_SBB_w_rm_mod_reg_u8_imm_u8, in_SBB_w_rm_mod_reg_u8_imm_u8, in_SBB_w_rm_mod_reg_u8_imm_u8, in_SBB_w_rm_mod_reg_u8_imm_u8, in_SBB_w_rm_mod_reg_u8_imm_u8, in_SBB_w_rm_mod_reg_u8_imm_u8, in_SBB_w_rm_mod_reg_u8_imm_u8, 
	// 60
	in_AND_w_rm_mod_reg_u8_imm_u8, in_AND_w_rm_mod_reg_u8_imm_u8, in_AND_w_rm_mod_reg_u8_imm_u8, in_AND_w_rm_mod_reg_u8_imm_u8, in_AND_w_rm_mod_reg_u8_imm_u8, in_AND_w_rm_mod_reg_u8_imm_u8, in_AND_w_rm_mod_reg_u8_imm_u8, in_AND_w_rm_mod_reg_u8_imm_u8, 
	// 68
	in_SUB_w_rm_mod_reg_u8_imm_u8, in_SUB_w_rm_mod_reg_u8_imm_u8, in_SUB_w_rm_mod_reg_u8_imm_u8, in_SUB_w_rm_mod_reg_u8_imm_u8, in_SUB_w_rm_mod_reg_u8_imm_u8, in_SUB_w_rm_mod_reg_u8_imm_u8, in_SUB_w_rm_mod_reg_u8_imm_u8, in_SUB_w_rm_mod_reg_u8_imm_u8, 
	// 70
	in_XOR_w_rm_mod_reg_u8_imm_u8, in_XOR_w_rm_mod_reg_u8_imm_u8, in_XOR_w_rm_mod_reg_u8_imm_u8, in_XOR_w_rm_mod_reg_u8_imm_u8, in_XOR_w_rm_mod_reg_u8_imm_u8, in_XOR_w_rm_mod_reg_u8_imm_u8, in_XOR_w_rm_mod_reg_u8_imm_u8, in_XOR_w_rm_mod_reg_u8_imm_u8, 
	// 78
	in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, 
	// 80
	in_ADD_w_rm_mod_reg_u8_imm_u8, in_ADD_w_rm_mod_reg_u8_imm_u8, in_ADD_w_rm_mod_reg_u8_imm_u8, in_ADD_w_rm_mod_reg_u8_imm_u8, in_ADD_w_rm_mod_reg_u8_imm_u8, in_ADD_w_rm_mod_reg_u8_imm_u8, in_ADD_w_rm_mod_reg_u8_imm_u8, in_ADD_w_rm_mod_reg_u8_imm_u8, 
	// 88
	in_OR_w_rm_mod_reg_u8_imm_u8, in_OR_w_rm_mod_reg_u8_imm_u8, in_OR_w_rm_mod_reg_u8_imm_u8, in_OR_w_rm_mod_reg_u8_imm_u8, in_OR_w_rm_mod_reg_u8_imm_u8, in_OR_w_rm_mod_reg_u8_imm_u8, in_OR_w_rm_mod_reg_u8_imm_u8, in_OR_w_rm_mod_reg_u8_imm_u8, 
	// 90
	in_ADC_w_rm_mod_reg_u8_imm_u8, in_ADC_w_rm_mod_reg_u8_imm_u8, in_ADC_w_rm_mod_reg_u8_imm_u8, in_ADC_w_rm_mod_reg_u8_imm_u8, in_ADC_w_rm_mod_reg_u8_imm_u8, in_ADC_w_rm_mod_reg_u8_imm_u8, in_ADC_w_rm_mod_reg_u8_imm_u8, in_ADC_w_rm_mod_reg_u8_imm_u8, 
	// 98
	in_SBB_w_rm_mod_reg_u8_imm_u8, in_SBB_w_rm_mod_reg_u8_imm_u8, in_SBB_w_rm_mod_reg_u8_imm_u8, in_SBB_w_rm_mod_reg_u8_imm_u8, in_SBB_w_rm_mod_reg_u8_imm_u8, in_SBB_w_rm_mod_reg_u8_imm_u8, in_SBB_w_rm_mod_reg_u8_imm_u8, in_SBB_w_rm_mod_reg_u8_imm_u8, 
	// A0
	in_AND_w_rm_mod_reg_u8_imm_u8, in_AND_w_rm_mod_reg_u8_imm_u8, in_AND_w_rm_mod_reg_u8_imm_u8, in_AND_w_rm_mod_reg_u8_imm_u8, in_AND_w_rm_mod_reg_u8_imm_u8, in_AND_w_rm_mod_reg_u8_imm_u8, in_AND_w_rm_mod_reg_u8_imm_u8, in_AND_w_rm_mod_reg_u8_imm_u8, 
	// A8
	in_SUB_w_rm_mod_reg_u8_imm_u8, in_SUB_w_rm_mod_reg_u8_imm_u8, in_SUB_w_rm_mod_reg_u8_imm_u8, in_SUB_w_rm_mod_reg_u8_imm_u8, in_SUB_w_rm_mod_reg_u8_imm_u8, in_SUB_w_rm_mod_reg_u8_imm_u8, in_SUB_w_rm_mod_reg_u8_imm_u8, in_SUB_w_rm_mod_reg_u8_imm_u8, 
	// B0
	in_XOR_w_rm_mod_reg_u8_imm_u8, in_XOR_w_rm_mod_reg_u8_imm_u8, in_XOR_w_rm_mod_reg_u8_imm_u8, in_XOR_w_rm_mod_reg_u8_imm_u8, in_XOR_w_rm_mod_reg_u8_imm_u8, in_XOR_w_rm_mod_reg_u8_imm_u8, in_XOR_w_rm_mod_reg_u8_imm_u8, in_XOR_w_rm_mod_reg_u8_imm_u8, 
	// B8
	in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, 
	// C0
	in_ADD_w_rm_mod_reg_u8_imm_u8, in_ADD_w_rm_mod_reg_u8_imm_u8, in_ADD_w_rm_mod_reg_u8_imm_u8, in_ADD_w_rm_mod_reg_u8_imm_u8, in_ADD_w_rm_mod_reg_u8_imm_u8, in_ADD_w_rm_mod_reg_u8_imm_u8, in_ADD_w_rm_mod_reg_u8_imm_u8, in_ADD_w_rm_mod_reg_u8_imm_u8, 
	// C8
	in_OR_w_rm_mod_reg_u8_imm_u8, in_OR_w_rm_mod_reg_u8_imm_u8, in_OR_w_rm_mod_reg_u8_imm_u8, in_OR_w_rm_mod_reg_u8_imm_u8, in_OR_w_rm_mod_reg_u8_imm_u8, in_OR_w_rm_mod_reg_u8_imm_u8, in_OR_w_rm_mod_reg_u8_imm_u8, in_OR_w_rm_mod_reg_u8_imm_u8, 
	// D0
	in_ADC_w_rm_mod_reg_u8_imm_u8, in_ADC_w_rm_mod_reg_u8_imm_u8, in_ADC_w_rm_mod_reg_u8_imm_u8, in_ADC_w_rm_mod_reg_u8_imm_u8, in_ADC_w_rm_mod_reg_u8_imm_u8, in_ADC_w_rm_mod_reg_u8_imm_u8, in_ADC_w_rm_mod_reg_u8_imm_u8, in_ADC_w_rm_mod_reg_u8_imm_u8, 
	// D8
	in_SBB_w_rm_mod_reg_u8_imm_u8, in_SBB_w_rm_mod_reg_u8_imm_u8, in_SBB_w_rm_mod_reg_u8_imm_u8, in_SBB_w_rm_mod_reg_u8_imm_u8, in_SBB_w_rm_mod_reg_u8_imm_u8, in_SBB_w_rm_mod_reg_u8_imm_u8, in_SBB_w_rm_mod_reg_u8_imm_u8, in_SBB_w_rm_mod_reg_u8_imm_u8, 
	// E0
	in_AND_w_rm_mod_reg_u8_imm_u8, in_AND_w_rm_mod_reg_u8_imm_u8, in_AND_w_rm_mod_reg_u8_imm_u8, in_AND_w_rm_mod_reg_u8_imm_u8, in_AND_w_rm_mod_reg_u8_imm_u8, in_AND_w_rm_mod_reg_u8_imm_u8, in_AND_w_rm_mod_reg_u8_imm_u8, in_AND_w_rm_mod_reg_u8_imm_u8, 
	// E8
	in_SUB_w_rm_mod_reg_u8_imm_u8, in_SUB_w_rm_mod_reg_u8_imm_u8, in_SUB_w_rm_mod_reg_u8_imm_u8, in_SUB_w_rm_mod_reg_u8_imm_u8, in_SUB_w_rm_mod_reg_u8_imm_u8, in_SUB_w_rm_mod_reg_u8_imm_u8, in_SUB_w_rm_mod_reg_u8_imm_u8, in_SUB_w_rm_mod_reg_u8_imm_u8, 
	// F0
	in_XOR_w_rm_mod_reg_u8_imm_u8, in_XOR_w_rm_mod_reg_u8_imm_u8, in_XOR_w_rm_mod_reg_u8_imm_u8, in_XOR_w_rm_mod_reg_u8_imm_u8, in_XOR_w_rm_mod_reg_u8_imm_u8, in_XOR_w_rm_mod_reg_u8_imm_u8, in_XOR_w_rm_mod_reg_u8_imm_u8, in_XOR_w_rm_mod_reg_u8_imm_u8, 
	// F8
	in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, 
};
const OpState CpuRunnerX86::table_st_w_d_82[] = {
	// 00
	in_ADD_w_rm_mod_reg_u8_imm_u8, in_ADD_w_rm_mod_reg_u8_imm_u8, in_ADD_w_rm_mod_reg_u8_imm_u8, in_ADD_w_rm_mod_reg_u8_imm_u8, in_ADD_w_rm_mod_reg_u8_imm_u8, in_ADD_w_rm_mod_reg_u8_imm_u8, in_ADD_w_rm_mod_reg_u8_imm_u8, in_ADD_w_rm_mod_reg_u8_imm_u8, 
	// 08
	in_OR_w_rm_mod_reg_u8_imm_u8, in_OR_w_rm_mod_reg_u8_imm_u8, in_OR_w_rm_mod_reg_u8_imm_u8, in_OR_w_rm_mod_reg_u8_imm_u8, in_OR_w_rm_mod_reg_u8_imm_u8, in_OR_w_rm_mod_reg_u8_imm_u8, in_OR_w_rm_mod_reg_u8_imm_u8, in_OR_w_rm_mod_reg_u8_imm_u8, 
	// 10
	in_ADC_w_rm_mod_reg_u8_imm_u8, in_ADC_w_rm_mod_reg_u8_imm_u8, in_ADC_w_rm_mod_reg_u8_imm_u8, in_ADC_w_rm_mod_reg_u8_imm_u8, in_ADC_w_rm_mod_reg_u8_imm_u8, in_ADC_w_rm_mod_reg_u8_imm_u8, in_ADC_w_rm_mod_reg_u8_imm_u8, in_ADC_w_rm_mod_reg_u8_imm_u8, 
	// 18
	in_SBB_w_rm_mod_reg_u8_imm_u8, in_SBB_w_rm_mod_reg_u8_imm_u8, in_SBB_w_rm_mod_reg_u8_imm_u8, in_SBB_w_rm_mod_reg_u8_imm_u8, in_SBB_w_rm_mod_reg_u8_imm_u8, in_SBB_w_rm_mod_reg_u8_imm_u8, in_SBB_w_rm_mod_reg_u8_imm_u8, in_SBB_w_rm_mod_reg_u8_imm_u8, 
	// 20
	in_AND_w_rm_mod_reg_u8_imm_u8, in_AND_w_rm_mod_reg_u8_imm_u8, in_AND_w_rm_mod_reg_u8_imm_u8, in_AND_w_rm_mod_reg_u8_imm_u8, in_AND_w_rm_mod_reg_u8_imm_u8, in_AND_w_rm_mod_reg_u8_imm_u8, in_AND_w_rm_mod_reg_u8_imm_u8, in_AND_w_rm_mod_reg_u8_imm_u8, 
	// 28
	in_SUB_w_rm_mod_reg_u8_imm_u8, in_SUB_w_rm_mod_reg_u8_imm_u8, in_SUB_w_rm_mod_reg_u8_imm_u8, in_SUB_w_rm_mod_reg_u8_imm_u8, in_SUB_w_rm_mod_reg_u8_imm_u8, in_SUB_w_rm_mod_reg_u8_imm_u8, in_SUB_w_rm_mod_reg_u8_imm_u8, in_SUB_w_rm_mod_reg_u8_imm_u8, 
	// 30
	in_XOR_w_rm_mod_reg_u8_imm_u8, in_XOR_w_rm_mod_reg_u8_imm_u8, in_XOR_w_rm_mod_reg_u8_imm_u8, in_XOR_w_rm_mod_reg_u8_imm_u8, in_XOR_w_rm_mod_reg_u8_imm_u8, in_XOR_w_rm_mod_reg_u8_imm_u8, in_XOR_w_rm_mod_reg_u8_imm_u8, in_XOR_w_rm_mod_reg_u8_imm_u8, 
	// 38
	in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, 
	// 40
	in_ADD_w_rm_mod_reg_u8_imm_u8, in_ADD_w_rm_mod_reg_u8_imm_u8, in_ADD_w_rm_mod_reg_u8_imm_u8, in_ADD_w_rm_mod_reg_u8_imm_u8, in_ADD_w_rm_mod_reg_u8_imm_u8, in_ADD_w_rm_mod_reg_u8_imm_u8, in_ADD_w_rm_mod_reg_u8_imm_u8, in_ADD_w_rm_mod_reg_u8_imm_u8, 
	// 48
	in_OR_w_rm_mod_reg_u8_imm_u8, in_OR_w_rm_mod_reg_u8_imm_u8, in_OR_w_rm_mod_reg_u8_imm_u8, in_OR_w_rm_mod_reg_u8_imm_u8, in_OR_w_rm_mod_reg_u8_imm_u8, in_OR_w_rm_mod_reg_u8_imm_u8, in_OR_w_rm_mod_reg_u8_imm_u8, in_OR_w_rm_mod_reg_u8_imm_u8, 
	// 50
	in_ADC_w_rm_mod_reg_u8_imm_u8, in_ADC_w_rm_mod_reg_u8_imm_u8, in_ADC_w_rm_mod_reg_u8_imm_u8, in_ADC_w_rm_mod_reg_u8_imm_u8, in_ADC_w_rm_mod_reg_u8_imm_u8, in_ADC_w_rm_mod_reg_u8_imm_u8, in_ADC_w_rm_mod_reg_u8_imm_u8, in_ADC_w_rm_mod_reg_u8_imm_u8, 
	// 58
	in_SBB_w_rm_mod_reg_u8_imm_u8, in_SBB_w_rm_mod_reg_u8_imm_u8, in_SBB_w_rm_mod_reg_u8_imm_u8, in_SBB_w_rm_mod_reg_u8_imm_u8, in_SBB_w_rm_mod_reg_u8_imm_u8, in_SBB_w_rm_mod_reg_u8_imm_u8, in_SBB_w_rm_mod_reg_u8_imm_u8, in_SBB_w_rm_mod_reg_u8_imm_u8, 
	// 60
	in_AND_w_rm_mod_reg_u8_imm_u8, in_AND_w_rm_mod_reg_u8_imm_u8, in_AND_w_rm_mod_reg_u8_imm_u8, in_AND_w_rm_mod_reg_u8_imm_u8, in_AND_w_rm_mod_reg_u8_imm_u8, in_AND_w_rm_mod_reg_u8_imm_u8, in_AND_w_rm_mod_reg_u8_imm_u8, in_AND_w_rm_mod_reg_u8_imm_u8, 
	// 68
	in_SUB_w_rm_mod_reg_u8_imm_u8, in_SUB_w_rm_mod_reg_u8_imm_u8, in_SUB_w_rm_mod_reg_u8_imm_u8, in_SUB_w_rm_mod_reg_u8_imm_u8, in_SUB_w_rm_mod_reg_u8_imm_u8, in_SUB_w_rm_mod_reg_u8_imm_u8, in_SUB_w_rm_mod_reg_u8_imm_u8, in_SUB_w_rm_mod_reg_u8_imm_u8, 
	// 70
	in_XOR_w_rm_mod_reg_u8_imm_u8, in_XOR_w_rm_mod_reg_u8_imm_u8, in_XOR_w_rm_mod_reg_u8_imm_u8, in_XOR_w_rm_mod_reg_u8_imm_u8, in_XOR_w_rm_mod_reg_u8_imm_u8, in_XOR_w_rm_mod_reg_u8_imm_u8, in_XOR_w_rm_mod_reg_u8_imm_u8, in_XOR_w_rm_mod_reg_u8_imm_u8, 
	// 78
	in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, 
	// 80
	in_ADD_w_rm_mod_reg_u8_imm_u8, in_ADD_w_rm_mod_reg_u8_imm_u8, in_ADD_w_rm_mod_reg_u8_imm_u8, in_ADD_w_rm_mod_reg_u8_imm_u8, in_ADD_w_rm_mod_reg_u8_imm_u8, in_ADD_w_rm_mod_reg_u8_imm_u8, in_ADD_w_rm_mod_reg_u8_imm_u8, in_ADD_w_rm_mod_reg_u8_imm_u8, 
	// 88
	in_OR_w_rm_mod_reg_u8_imm_u8, in_OR_w_rm_mod_reg_u8_imm_u8, in_OR_w_rm_mod_reg_u8_imm_u8, in_OR_w_rm_mod_reg_u8_imm_u8, in_OR_w_rm_mod_reg_u8_imm_u8, in_OR_w_rm_mod_reg_u8_imm_u8, in_OR_w_rm_mod_reg_u8_imm_u8, in_OR_w_rm_mod_reg_u8_imm_u8, 
	// 90
	in_ADC_w_rm_mod_reg_u8_imm_u8, in_ADC_w_rm_mod_reg_u8_imm_u8, in_ADC_w_rm_mod_reg_u8_imm_u8, in_ADC_w_rm_mod_reg_u8_imm_u8, in_ADC_w_rm_mod_reg_u8_imm_u8, in_ADC_w_rm_mod_reg_u8_imm_u8, in_ADC_w_rm_mod_reg_u8_imm_u8, in_ADC_w_rm_mod_reg_u8_imm_u8, 
	// 98
	in_SBB_w_rm_mod_reg_u8_imm_u8, in_SBB_w_rm_mod_reg_u8_imm_u8, in_SBB_w_rm_mod_reg_u8_imm_u8, in_SBB_w_rm_mod_reg_u8_imm_u8, in_SBB_w_rm_mod_reg_u8_imm_u8, in_SBB_w_rm_mod_reg_u8_imm_u8, in_SBB_w_rm_mod_reg_u8_imm_u8, in_SBB_w_rm_mod_reg_u8_imm_u8, 
	// A0
	in_AND_w_rm_mod_reg_u8_imm_u8, in_AND_w_rm_mod_reg_u8_imm_u8, in_AND_w_rm_mod_reg_u8_imm_u8, in_AND_w_rm_mod_reg_u8_imm_u8, in_AND_w_rm_mod_reg_u8_imm_u8, in_AND_w_rm_mod_reg_u8_imm_u8, in_AND_w_rm_mod_reg_u8_imm_u8, in_AND_w_rm_mod_reg_u8_imm_u8, 
	// A8
	in_SUB_w_rm_mod_reg_u8_imm_u8, in_SUB_w_rm_mod_reg_u8_imm_u8, in_SUB_w_rm_mod_reg_u8_imm_u8, in_SUB_w_rm_mod_reg_u8_imm_u8, in_SUB_w_rm_mod_reg_u8_imm_u8, in_SUB_w_rm_mod_reg_u8_imm_u8, in_SUB_w_rm_mod_reg_u8_imm_u8, in_SUB_w_rm_mod_reg_u8_imm_u8, 
	// B0
	in_XOR_w_rm_mod_reg_u8_imm_u8, in_XOR_w_rm_mod_reg_u8_imm_u8, in_XOR_w_rm_mod_reg_u8_imm_u8, in_XOR_w_rm_mod_reg_u8_imm_u8, in_XOR_w_rm_mod_reg_u8_imm_u8, in_XOR_w_rm_mod_reg_u8_imm_u8, in_XOR_w_rm_mod_reg_u8_imm_u8, in_XOR_w_rm_mod_reg_u8_imm_u8, 
	// B8
	in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, 
	// C0
	in_ADD_w_rm_mod_reg_u8_imm_u8, in_ADD_w_rm_mod_reg_u8_imm_u8, in_ADD_w_rm_mod_reg_u8_imm_u8, in_ADD_w_rm_mod_reg_u8_imm_u8, in_ADD_w_rm_mod_reg_u8_imm_u8, in_ADD_w_rm_mod_reg_u8_imm_u8, in_ADD_w_rm_mod_reg_u8_imm_u8, in_ADD_w_rm_mod_reg_u8_imm_u8, 
	// C8
	in_OR_w_rm_mod_reg_u8_imm_u8, in_OR_w_rm_mod_reg_u8_imm_u8, in_OR_w_rm_mod_reg_u8_imm_u8, in_OR_w_rm_mod_reg_u8_imm_u8, in_OR_w_rm_mod_reg_u8_imm_u8, in_OR_w_rm_mod_reg_u8_imm_u8, in_OR_w_rm_mod_reg_u8_imm_u8, in_OR_w_rm_mod_reg_u8_imm_u8, 
	// D0
	in_ADC_w_rm_mod_reg_u8_imm_u8, in_ADC_w_rm_mod_reg_u8_imm_u8, in_ADC_w_rm_mod_reg_u8_imm_u8, in_ADC_w_rm_mod_reg_u8_imm_u8, in_ADC_w_rm_mod_reg_u8_imm_u8, in_ADC_w_rm_mod_reg_u8_imm_u8, in_ADC_w_rm_mod_reg_u8_imm_u8, in_ADC_w_rm_mod_reg_u8_imm_u8, 
	// D8
	in_SBB_w_rm_mod_reg_u8_imm_u8, in_SBB_w_rm_mod_reg_u8_imm_u8, in_SBB_w_rm_mod_reg_u8_imm_u8, in_SBB_w_rm_mod_reg_u8_imm_u8, in_SBB_w_rm_mod_reg_u8_imm_u8, in_SBB_w_rm_mod_reg_u8_imm_u8, in_SBB_w_rm_mod_reg_u8_imm_u8, in_SBB_w_rm_mod_reg_u8_imm_u8, 
	// E0
	in_AND_w_rm_mod_reg_u8_imm_u8, in_AND_w_rm_mod_reg_u8_imm_u8, in_AND_w_rm_mod_reg_u8_imm_u8, in_AND_w_rm_mod_reg_u8_imm_u8, in_AND_w_rm_mod_reg_u8_imm_u8, in_AND_w_rm_mod_reg_u8_imm_u8, in_AND_w_rm_mod_reg_u8_imm_u8, in_AND_w_rm_mod_reg_u8_imm_u8, 
	// E8
	in_SUB_w_rm_mod_reg_u8_imm_u8, in_SUB_w_rm_mod_reg_u8_imm_u8, in_SUB_w_rm_mod_reg_u8_imm_u8, in_SUB_w_rm_mod_reg_u8_imm_u8, in_SUB_w_rm_mod_reg_u8_imm_u8, in_SUB_w_rm_mod_reg_u8_imm_u8, in_SUB_w_rm_mod_reg_u8_imm_u8, in_SUB_w_rm_mod_reg_u8_imm_u8, 
	// F0
	in_XOR_w_rm_mod_reg_u8_imm_u8, in_XOR_w_rm_mod_reg_u8_imm_u8, in_XOR_w_rm_mod_reg_u8_imm_u8, in_XOR_w_rm_mod_reg_u8_imm_u8, in_XOR_w_rm_mod_reg_u8_imm_u8, in_XOR_w_rm_mod_reg_u8_imm_u8, in_XOR_w_rm_mod_reg_u8_imm_u8, in_XOR_w_rm_mod_reg_u8_imm_u8, 
	// F8
	in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, 
};
const OpState CpuRunnerX86::table_st_d_w_82[] = {
	// 00
	in_ADD_d_rm_mod_reg_u8_imm_u8, in_ADD_d_rm_mod_reg_u8_imm_u8, in_ADD_d_rm_mod_reg_u8_imm_u8, in_ADD_d_rm_mod_reg_u8_imm_u8, in_ADD_d_rm_mod_reg_u8_imm_u8, in_ADD_d_rm_mod_reg_u8_imm_u8, in_ADD_d_rm_mod_reg_u8_imm_u8, in_ADD_d_rm_mod_reg_u8_imm_u8, 
	// 08
	in_OR_d_rm_mod_reg_u8_imm_u8, in_OR_d_rm_mod_reg_u8_imm_u8, in_OR_d_rm_mod_reg_u8_imm_u8, in_OR_d_rm_mod_reg_u8_imm_u8, in_OR_d_rm_mod_reg_u8_imm_u8, in_OR_d_rm_mod_reg_u8_imm_u8, in_OR_d_rm_mod_reg_u8_imm_u8, in_OR_d_rm_mod_reg_u8_imm_u8, 
	// 10
	in_ADC_d_rm_mod_reg_u8_imm_u8, in_ADC_d_rm_mod_reg_u8_imm_u8, in_ADC_d_rm_mod_reg_u8_imm_u8, in_ADC_d_rm_mod_reg_u8_imm_u8, in_ADC_d_rm_mod_reg_u8_imm_u8, in_ADC_d_rm_mod_reg_u8_imm_u8, in_ADC_d_rm_mod_reg_u8_imm_u8, in_ADC_d_rm_mod_reg_u8_imm_u8, 
	// 18
	in_SBB_d_rm_mod_reg_u8_imm_u8, in_SBB_d_rm_mod_reg_u8_imm_u8, in_SBB_d_rm_mod_reg_u8_imm_u8, in_SBB_d_rm_mod_reg_u8_imm_u8, in_SBB_d_rm_mod_reg_u8_imm_u8, in_SBB_d_rm_mod_reg_u8_imm_u8, in_SBB_d_rm_mod_reg_u8_imm_u8, in_SBB_d_rm_mod_reg_u8_imm_u8, 
	// 20
	in_AND_d_rm_mod_reg_u8_imm_u8, in_AND_d_rm_mod_reg_u8_imm_u8, in_AND_d_rm_mod_reg_u8_imm_u8, in_AND_d_rm_mod_reg_u8_imm_u8, in_AND_d_rm_mod_reg_u8_imm_u8, in_AND_d_rm_mod_reg_u8_imm_u8, in_AND_d_rm_mod_reg_u8_imm_u8, in_AND_d_rm_mod_reg_u8_imm_u8, 
	// 28
	in_SUB_d_rm_mod_reg_u8_imm_u8, in_SUB_d_rm_mod_reg_u8_imm_u8, in_SUB_d_rm_mod_reg_u8_imm_u8, in_SUB_d_rm_mod_reg_u8_imm_u8, in_SUB_d_rm_mod_reg_u8_imm_u8, in_SUB_d_rm_mod_reg_u8_imm_u8, in_SUB_d_rm_mod_reg_u8_imm_u8, in_SUB_d_rm_mod_reg_u8_imm_u8, 
	// 30
	in_XOR_d_rm_mod_reg_u8_imm_u8, in_XOR_d_rm_mod_reg_u8_imm_u8, in_XOR_d_rm_mod_reg_u8_imm_u8, in_XOR_d_rm_mod_reg_u8_imm_u8, in_XOR_d_rm_mod_reg_u8_imm_u8, in_XOR_d_rm_mod_reg_u8_imm_u8, in_XOR_d_rm_mod_reg_u8_imm_u8, in_XOR_d_rm_mod_reg_u8_imm_u8, 
	// 38
	in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, 
	// 40
	in_ADD_d_rm_mod_reg_u8_imm_u8, in_ADD_d_rm_mod_reg_u8_imm_u8, in_ADD_d_rm_mod_reg_u8_imm_u8, in_ADD_d_rm_mod_reg_u8_imm_u8, in_ADD_d_rm_mod_reg_u8_imm_u8, in_ADD_d_rm_mod_reg_u8_imm_u8, in_ADD_d_rm_mod_reg_u8_imm_u8, in_ADD_d_rm_mod_reg_u8_imm_u8, 
	// 48
	in_OR_d_rm_mod_reg_u8_imm_u8, in_OR_d_rm_mod_reg_u8_imm_u8, in_OR_d_rm_mod_reg_u8_imm_u8, in_OR_d_rm_mod_reg_u8_imm_u8, in_OR_d_rm_mod_reg_u8_imm_u8, in_OR_d_rm_mod_reg_u8_imm_u8, in_OR_d_rm_mod_reg_u8_imm_u8, in_OR_d_rm_mod_reg_u8_imm_u8, 
	// 50
	in_ADC_d_rm_mod_reg_u8_imm_u8, in_ADC_d_rm_mod_reg_u8_imm_u8, in_ADC_d_rm_mod_reg_u8_imm_u8, in_ADC_d_rm_mod_reg_u8_imm_u8, in_ADC_d_rm_mod_reg_u8_imm_u8, in_ADC_d_rm_mod_reg_u8_imm_u8, in_ADC_d_rm_mod_reg_u8_imm_u8, in_ADC_d_rm_mod_reg_u8_imm_u8, 
	// 58
	in_SBB_d_rm_mod_reg_u8_imm_u8, in_SBB_d_rm_mod_reg_u8_imm_u8, in_SBB_d_rm_mod_reg_u8_imm_u8, in_SBB_d_rm_mod_reg_u8_imm_u8, in_SBB_d_rm_mod_reg_u8_imm_u8, in_SBB_d_rm_mod_reg_u8_imm_u8, in_SBB_d_rm_mod_reg_u8_imm_u8, in_SBB_d_rm_mod_reg_u8_imm_u8, 
	// 60
	in_AND_d_rm_mod_reg_u8_imm_u8, in_AND_d_rm_mod_reg_u8_imm_u8, in_AND_d_rm_mod_reg_u8_imm_u8, in_AND_d_rm_mod_reg_u8_imm_u8, in_AND_d_rm_mod_reg_u8_imm_u8, in_AND_d_rm_mod_reg_u8_imm_u8, in_AND_d_rm_mod_reg_u8_imm_u8, in_AND_d_rm_mod_reg_u8_imm_u8, 
	// 68
	in_SUB_d_rm_mod_reg_u8_imm_u8, in_SUB_d_rm_mod_reg_u8_imm_u8, in_SUB_d_rm_mod_reg_u8_imm_u8, in_SUB_d_rm_mod_reg_u8_imm_u8, in_SUB_d_rm_mod_reg_u8_imm_u8, in_SUB_d_rm_mod_reg_u8_imm_u8, in_SUB_d_rm_mod_reg_u8_imm_u8, in_SUB_d_rm_mod_reg_u8_imm_u8, 
	// 70
	in_XOR_d_rm_mod_reg_u8_imm_u8, in_XOR_d_rm_mod_reg_u8_imm_u8, in_XOR_d_rm_mod_reg_u8_imm_u8, in_XOR_d_rm_mod_reg_u8_imm_u8, in_XOR_d_rm_mod_reg_u8_imm_u8, in_XOR_d_rm_mod_reg_u8_imm_u8, in_XOR_d_rm_mod_reg_u8_imm_u8, in_XOR_d_rm_mod_reg_u8_imm_u8, 
	// 78
	in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, 
	// 80
	in_ADD_d_rm_mod_reg_u8_imm_u8, in_ADD_d_rm_mod_reg_u8_imm_u8, in_ADD_d_rm_mod_reg_u8_imm_u8, in_ADD_d_rm_mod_reg_u8_imm_u8, in_ADD_d_rm_mod_reg_u8_imm_u8, in_ADD_d_rm_mod_reg_u8_imm_u8, in_ADD_d_rm_mod_reg_u8_imm_u8, in_ADD_d_rm_mod_reg_u8_imm_u8, 
	// 88
	in_OR_d_rm_mod_reg_u8_imm_u8, in_OR_d_rm_mod_reg_u8_imm_u8, in_OR_d_rm_mod_reg_u8_imm_u8, in_OR_d_rm_mod_reg_u8_imm_u8, in_OR_d_rm_mod_reg_u8_imm_u8, in_OR_d_rm_mod_reg_u8_imm_u8, in_OR_d_rm_mod_reg_u8_imm_u8, in_OR_d_rm_mod_reg_u8_imm_u8, 
	// 90
	in_ADC_d_rm_mod_reg_u8_imm_u8, in_ADC_d_rm_mod_reg_u8_imm_u8, in_ADC_d_rm_mod_reg_u8_imm_u8, in_ADC_d_rm_mod_reg_u8_imm_u8, in_ADC_d_rm_mod_reg_u8_imm_u8, in_ADC_d_rm_mod_reg_u8_imm_u8, in_ADC_d_rm_mod_reg_u8_imm_u8, in_ADC_d_rm_mod_reg_u8_imm_u8, 
	// 98
	in_SBB_d_rm_mod_reg_u8_imm_u8, in_SBB_d_rm_mod_reg_u8_imm_u8, in_SBB_d_rm_mod_reg_u8_imm_u8, in_SBB_d_rm_mod_reg_u8_imm_u8, in_SBB_d_rm_mod_reg_u8_imm_u8, in_SBB_d_rm_mod_reg_u8_imm_u8, in_SBB_d_rm_mod_reg_u8_imm_u8, in_SBB_d_rm_mod_reg_u8_imm_u8, 
	// A0
	in_AND_d_rm_mod_reg_u8_imm_u8, in_AND_d_rm_mod_reg_u8_imm_u8, in_AND_d_rm_mod_reg_u8_imm_u8, in_AND_d_rm_mod_reg_u8_imm_u8, in_AND_d_rm_mod_reg_u8_imm_u8, in_AND_d_rm_mod_reg_u8_imm_u8, in_AND_d_rm_mod_reg_u8_imm_u8, in_AND_d_rm_mod_reg_u8_imm_u8, 
	// A8
	in_SUB_d_rm_mod_reg_u8_imm_u8, in_SUB_d_rm_mod_reg_u8_imm_u8, in_SUB_d_rm_mod_reg_u8_imm_u8, in_SUB_d_rm_mod_reg_u8_imm_u8, in_SUB_d_rm_mod_reg_u8_imm_u8, in_SUB_d_rm_mod_reg_u8_imm_u8, in_SUB_d_rm_mod_reg_u8_imm_u8, in_SUB_d_rm_mod_reg_u8_imm_u8, 
	// B0
	in_XOR_d_rm_mod_reg_u8_imm_u8, in_XOR_d_rm_mod_reg_u8_imm_u8, in_XOR_d_rm_mod_reg_u8_imm_u8, in_XOR_d_rm_mod_reg_u8_imm_u8, in_XOR_d_rm_mod_reg_u8_imm_u8, in_XOR_d_rm_mod_reg_u8_imm_u8, in_XOR_d_rm_mod_reg_u8_imm_u8, in_XOR_d_rm_mod_reg_u8_imm_u8, 
	// B8
	in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, 
	// C0
	in_ADD_d_rm_mod_reg_u8_imm_u8, in_ADD_d_rm_mod_reg_u8_imm_u8, in_ADD_d_rm_mod_reg_u8_imm_u8, in_ADD_d_rm_mod_reg_u8_imm_u8, in_ADD_d_rm_mod_reg_u8_imm_u8, in_ADD_d_rm_mod_reg_u8_imm_u8, in_ADD_d_rm_mod_reg_u8_imm_u8, in_ADD_d_rm_mod_reg_u8_imm_u8, 
	// C8
	in_OR_d_rm_mod_reg_u8_imm_u8, in_OR_d_rm_mod_reg_u8_imm_u8, in_OR_d_rm_mod_reg_u8_imm_u8, in_OR_d_rm_mod_reg_u8_imm_u8, in_OR_d_rm_mod_reg_u8_imm_u8, in_OR_d_rm_mod_reg_u8_imm_u8, in_OR_d_rm_mod_reg_u8_imm_u8, in_OR_d_rm_mod_reg_u8_imm_u8, 
	// D0
	in_ADC_d_rm_mod_reg_u8_imm_u8, in_ADC_d_rm_mod_reg_u8_imm_u8, in_ADC_d_rm_mod_reg_u8_imm_u8, in_ADC_d_rm_mod_reg_u8_imm_u8, in_ADC_d_rm_mod_reg_u8_imm_u8, in_ADC_d_rm_mod_reg_u8_imm_u8, in_ADC_d_rm_mod_reg_u8_imm_u8, in_ADC_d_rm_mod_reg_u8_imm_u8, 
	// D8
	in_SBB_d_rm_mod_reg_u8_imm_u8, in_SBB_d_rm_mod_reg_u8_imm_u8, in_SBB_d_rm_mod_reg_u8_imm_u8, in_SBB_d_rm_mod_reg_u8_imm_u8, in_SBB_d_rm_mod_reg_u8_imm_u8, in_SBB_d_rm_mod_reg_u8_imm_u8, in_SBB_d_rm_mod_reg_u8_imm_u8, in_SBB_d_rm_mod_reg_u8_imm_u8, 
	// E0
	in_AND_d_rm_mod_reg_u8_imm_u8, in_AND_d_rm_mod_reg_u8_imm_u8, in_AND_d_rm_mod_reg_u8_imm_u8, in_AND_d_rm_mod_reg_u8_imm_u8, in_AND_d_rm_mod_reg_u8_imm_u8, in_AND_d_rm_mod_reg_u8_imm_u8, in_AND_d_rm_mod_reg_u8_imm_u8, in_AND_d_rm_mod_reg_u8_imm_u8, 
	// E8
	in_SUB_d_rm_mod_reg_u8_imm_u8, in_SUB_d_rm_mod_reg_u8_imm_u8, in_SUB_d_rm_mod_reg_u8_imm_u8, in_SUB_d_rm_mod_reg_u8_imm_u8, in_SUB_d_rm_mod_reg_u8_imm_u8, in_SUB_d_rm_mod_reg_u8_imm_u8, in_SUB_d_rm_mod_reg_u8_imm_u8, in_SUB_d_rm_mod_reg_u8_imm_u8, 
	// F0
	in_XOR_d_rm_mod_reg_u8_imm_u8, in_XOR_d_rm_mod_reg_u8_imm_u8, in_XOR_d_rm_mod_reg_u8_imm_u8, in_XOR_d_rm_mod_reg_u8_imm_u8, in_XOR_d_rm_mod_reg_u8_imm_u8, in_XOR_d_rm_mod_reg_u8_imm_u8, in_XOR_d_rm_mod_reg_u8_imm_u8, in_XOR_d_rm_mod_reg_u8_imm_u8, 
	// F8
	in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, 
};
const OpState CpuRunnerX86::table_st_d_d_82[] = {
	// 00
	in_ADD_d_rm_mod_reg_u8_imm_u8, in_ADD_d_rm_mod_reg_u8_imm_u8, in_ADD_d_rm_mod_reg_u8_imm_u8, in_ADD_d_rm_mod_reg_u8_imm_u8, in_ADD_d_rm_mod_reg_u8_imm_u8, in_ADD_d_rm_mod_reg_u8_imm_u8, in_ADD_d_rm_mod_reg_u8_imm_u8, in_ADD_d_rm_mod_reg_u8_imm_u8, 
	// 08
	in_OR_d_rm_mod_reg_u8_imm_u8, in_OR_d_rm_mod_reg_u8_imm_u8, in_OR_d_rm_mod_reg_u8_imm_u8, in_OR_d_rm_mod_reg_u8_imm_u8, in_OR_d_rm_mod_reg_u8_imm_u8, in_OR_d_rm_mod_reg_u8_imm_u8, in_OR_d_rm_mod_reg_u8_imm_u8, in_OR_d_rm_mod_reg_u8_imm_u8, 
	// 10
	in_ADC_d_rm_mod_reg_u8_imm_u8, in_ADC_d_rm_mod_reg_u8_imm_u8, in_ADC_d_rm_mod_reg_u8_imm_u8, in_ADC_d_rm_mod_reg_u8_imm_u8, in_ADC_d_rm_mod_reg_u8_imm_u8, in_ADC_d_rm_mod_reg_u8_imm_u8, in_ADC_d_rm_mod_reg_u8_imm_u8, in_ADC_d_rm_mod_reg_u8_imm_u8, 
	// 18
	in_SBB_d_rm_mod_reg_u8_imm_u8, in_SBB_d_rm_mod_reg_u8_imm_u8, in_SBB_d_rm_mod_reg_u8_imm_u8, in_SBB_d_rm_mod_reg_u8_imm_u8, in_SBB_d_rm_mod_reg_u8_imm_u8, in_SBB_d_rm_mod_reg_u8_imm_u8, in_SBB_d_rm_mod_reg_u8_imm_u8, in_SBB_d_rm_mod_reg_u8_imm_u8, 
	// 20
	in_AND_d_rm_mod_reg_u8_imm_u8, in_AND_d_rm_mod_reg_u8_imm_u8, in_AND_d_rm_mod_reg_u8_imm_u8, in_AND_d_rm_mod_reg_u8_imm_u8, in_AND_d_rm_mod_reg_u8_imm_u8, in_AND_d_rm_mod_reg_u8_imm_u8, in_AND_d_rm_mod_reg_u8_imm_u8, in_AND_d_rm_mod_reg_u8_imm_u8, 
	// 28
	in_SUB_d_rm_mod_reg_u8_imm_u8, in_SUB_d_rm_mod_reg_u8_imm_u8, in_SUB_d_rm_mod_reg_u8_imm_u8, in_SUB_d_rm_mod_reg_u8_imm_u8, in_SUB_d_rm_mod_reg_u8_imm_u8, in_SUB_d_rm_mod_reg_u8_imm_u8, in_SUB_d_rm_mod_reg_u8_imm_u8, in_SUB_d_rm_mod_reg_u8_imm_u8, 
	// 30
	in_XOR_d_rm_mod_reg_u8_imm_u8, in_XOR_d_rm_mod_reg_u8_imm_u8, in_XOR_d_rm_mod_reg_u8_imm_u8, in_XOR_d_rm_mod_reg_u8_imm_u8, in_XOR_d_rm_mod_reg_u8_imm_u8, in_XOR_d_rm_mod_reg_u8_imm_u8, in_XOR_d_rm_mod_reg_u8_imm_u8, in_XOR_d_rm_mod_reg_u8_imm_u8, 
	// 38
	in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, 
	// 40
	in_ADD_d_rm_mod_reg_u8_imm_u8, in_ADD_d_rm_mod_reg_u8_imm_u8, in_ADD_d_rm_mod_reg_u8_imm_u8, in_ADD_d_rm_mod_reg_u8_imm_u8, in_ADD_d_rm_mod_reg_u8_imm_u8, in_ADD_d_rm_mod_reg_u8_imm_u8, in_ADD_d_rm_mod_reg_u8_imm_u8, in_ADD_d_rm_mod_reg_u8_imm_u8, 
	// 48
	in_OR_d_rm_mod_reg_u8_imm_u8, in_OR_d_rm_mod_reg_u8_imm_u8, in_OR_d_rm_mod_reg_u8_imm_u8, in_OR_d_rm_mod_reg_u8_imm_u8, in_OR_d_rm_mod_reg_u8_imm_u8, in_OR_d_rm_mod_reg_u8_imm_u8, in_OR_d_rm_mod_reg_u8_imm_u8, in_OR_d_rm_mod_reg_u8_imm_u8, 
	// 50
	in_ADC_d_rm_mod_reg_u8_imm_u8, in_ADC_d_rm_mod_reg_u8_imm_u8, in_ADC_d_rm_mod_reg_u8_imm_u8, in_ADC_d_rm_mod_reg_u8_imm_u8, in_ADC_d_rm_mod_reg_u8_imm_u8, in_ADC_d_rm_mod_reg_u8_imm_u8, in_ADC_d_rm_mod_reg_u8_imm_u8, in_ADC_d_rm_mod_reg_u8_imm_u8, 
	// 58
	in_SBB_d_rm_mod_reg_u8_imm_u8, in_SBB_d_rm_mod_reg_u8_imm_u8, in_SBB_d_rm_mod_reg_u8_imm_u8, in_SBB_d_rm_mod_reg_u8_imm_u8, in_SBB_d_rm_mod_reg_u8_imm_u8, in_SBB_d_rm_mod_reg_u8_imm_u8, in_SBB_d_rm_mod_reg_u8_imm_u8, in_SBB_d_rm_mod_reg_u8_imm_u8, 
	// 60
	in_AND_d_rm_mod_reg_u8_imm_u8, in_AND_d_rm_mod_reg_u8_imm_u8, in_AND_d_rm_mod_reg_u8_imm_u8, in_AND_d_rm_mod_reg_u8_imm_u8, in_AND_d_rm_mod_reg_u8_imm_u8, in_AND_d_rm_mod_reg_u8_imm_u8, in_AND_d_rm_mod_reg_u8_imm_u8, in_AND_d_rm_mod_reg_u8_imm_u8, 
	// 68
	in_SUB_d_rm_mod_reg_u8_imm_u8, in_SUB_d_rm_mod_reg_u8_imm_u8, in_SUB_d_rm_mod_reg_u8_imm_u8, in_SUB_d_rm_mod_reg_u8_imm_u8, in_SUB_d_rm_mod_reg_u8_imm_u8, in_SUB_d_rm_mod_reg_u8_imm_u8, in_SUB_d_rm_mod_reg_u8_imm_u8, in_SUB_d_rm_mod_reg_u8_imm_u8, 
	// 70
	in_XOR_d_rm_mod_reg_u8_imm_u8, in_XOR_d_rm_mod_reg_u8_imm_u8, in_XOR_d_rm_mod_reg_u8_imm_u8, in_XOR_d_rm_mod_reg_u8_imm_u8, in_XOR_d_rm_mod_reg_u8_imm_u8, in_XOR_d_rm_mod_reg_u8_imm_u8, in_XOR_d_rm_mod_reg_u8_imm_u8, in_XOR_d_rm_mod_reg_u8_imm_u8, 
	// 78
	in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, 
	// 80
	in_ADD_d_rm_mod_reg_u8_imm_u8, in_ADD_d_rm_mod_reg_u8_imm_u8, in_ADD_d_rm_mod_reg_u8_imm_u8, in_ADD_d_rm_mod_reg_u8_imm_u8, in_ADD_d_rm_mod_reg_u8_imm_u8, in_ADD_d_rm_mod_reg_u8_imm_u8, in_ADD_d_rm_mod_reg_u8_imm_u8, in_ADD_d_rm_mod_reg_u8_imm_u8, 
	// 88
	in_OR_d_rm_mod_reg_u8_imm_u8, in_OR_d_rm_mod_reg_u8_imm_u8, in_OR_d_rm_mod_reg_u8_imm_u8, in_OR_d_rm_mod_reg_u8_imm_u8, in_OR_d_rm_mod_reg_u8_imm_u8, in_OR_d_rm_mod_reg_u8_imm_u8, in_OR_d_rm_mod_reg_u8_imm_u8, in_OR_d_rm_mod_reg_u8_imm_u8, 
	// 90
	in_ADC_d_rm_mod_reg_u8_imm_u8, in_ADC_d_rm_mod_reg_u8_imm_u8, in_ADC_d_rm_mod_reg_u8_imm_u8, in_ADC_d_rm_mod_reg_u8_imm_u8, in_ADC_d_rm_mod_reg_u8_imm_u8, in_ADC_d_rm_mod_reg_u8_imm_u8, in_ADC_d_rm_mod_reg_u8_imm_u8, in_ADC_d_rm_mod_reg_u8_imm_u8, 
	// 98
	in_SBB_d_rm_mod_reg_u8_imm_u8, in_SBB_d_rm_mod_reg_u8_imm_u8, in_SBB_d_rm_mod_reg_u8_imm_u8, in_SBB_d_rm_mod_reg_u8_imm_u8, in_SBB_d_rm_mod_reg_u8_imm_u8, in_SBB_d_rm_mod_reg_u8_imm_u8, in_SBB_d_rm_mod_reg_u8_imm_u8, in_SBB_d_rm_mod_reg_u8_imm_u8, 
	// A0
	in_AND_d_rm_mod_reg_u8_imm_u8, in_AND_d_rm_mod_reg_u8_imm_u8, in_AND_d_rm_mod_reg_u8_imm_u8, in_AND_d_rm_mod_reg_u8_imm_u8, in_AND_d_rm_mod_reg_u8_imm_u8, in_AND_d_rm_mod_reg_u8_imm_u8, in_AND_d_rm_mod_reg_u8_imm_u8, in_AND_d_rm_mod_reg_u8_imm_u8, 
	// A8
	in_SUB_d_rm_mod_reg_u8_imm_u8, in_SUB_d_rm_mod_reg_u8_imm_u8, in_SUB_d_rm_mod_reg_u8_imm_u8, in_SUB_d_rm_mod_reg_u8_imm_u8, in_SUB_d_rm_mod_reg_u8_imm_u8, in_SUB_d_rm_mod_reg_u8_imm_u8, in_SUB_d_rm_mod_reg_u8_imm_u8, in_SUB_d_rm_mod_reg_u8_imm_u8, 
	// B0
	in_XOR_d_rm_mod_reg_u8_imm_u8, in_XOR_d_rm_mod_reg_u8_imm_u8, in_XOR_d_rm_mod_reg_u8_imm_u8, in_XOR_d_rm_mod_reg_u8_imm_u8, in_XOR_d_rm_mod_reg_u8_imm_u8, in_XOR_d_rm_mod_reg_u8_imm_u8, in_XOR_d_rm_mod_reg_u8_imm_u8, in_XOR_d_rm_mod_reg_u8_imm_u8, 
	// B8
	in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, 
	// C0
	in_ADD_d_rm_mod_reg_u8_imm_u8, in_ADD_d_rm_mod_reg_u8_imm_u8, in_ADD_d_rm_mod_reg_u8_imm_u8, in_ADD_d_rm_mod_reg_u8_imm_u8, in_ADD_d_rm_mod_reg_u8_imm_u8, in_ADD_d_rm_mod_reg_u8_imm_u8, in_ADD_d_rm_mod_reg_u8_imm_u8, in_ADD_d_rm_mod_reg_u8_imm_u8, 
	// C8
	in_OR_d_rm_mod_reg_u8_imm_u8, in_OR_d_rm_mod_reg_u8_imm_u8, in_OR_d_rm_mod_reg_u8_imm_u8, in_OR_d_rm_mod_reg_u8_imm_u8, in_OR_d_rm_mod_reg_u8_imm_u8, in_OR_d_rm_mod_reg_u8_imm_u8, in_OR_d_rm_mod_reg_u8_imm_u8, in_OR_d_rm_mod_reg_u8_imm_u8, 
	// D0
	in_ADC_d_rm_mod_reg_u8_imm_u8, in_ADC_d_rm_mod_reg_u8_imm_u8, in_ADC_d_rm_mod_reg_u8_imm_u8, in_ADC_d_rm_mod_reg_u8_imm_u8, in_ADC_d_rm_mod_reg_u8_imm_u8, in_ADC_d_rm_mod_reg_u8_imm_u8, in_ADC_d_rm_mod_reg_u8_imm_u8, in_ADC_d_rm_mod_reg_u8_imm_u8, 
	// D8
	in_SBB_d_rm_mod_reg_u8_imm_u8, in_SBB_d_rm_mod_reg_u8_imm_u8, in_SBB_d_rm_mod_reg_u8_imm_u8, in_SBB_d_rm_mod_reg_u8_imm_u8, in_SBB_d_rm_mod_reg_u8_imm_u8, in_SBB_d_rm_mod_reg_u8_imm_u8, in_SBB_d_rm_mod_reg_u8_imm_u8, in_SBB_d_rm_mod_reg_u8_imm_u8, 
	// E0
	in_AND_d_rm_mod_reg_u8_imm_u8, in_AND_d_rm_mod_reg_u8_imm_u8, in_AND_d_rm_mod_reg_u8_imm_u8, in_AND_d_rm_mod_reg_u8_imm_u8, in_AND_d_rm_mod_reg_u8_imm_u8, in_AND_d_rm_mod_reg_u8_imm_u8, in_AND_d_rm_mod_reg_u8_imm_u8, in_AND_d_rm_mod_reg_u8_imm_u8, 
	// E8
	in_SUB_d_rm_mod_reg_u8_imm_u8, in_SUB_d_rm_mod_reg_u8_imm_u8, in_SUB_d_rm_mod_reg_u8_imm_u8, in_SUB_d_rm_mod_reg_u8_imm_u8, in_SUB_d_rm_mod_reg_u8_imm_u8, in_SUB_d_rm_mod_reg_u8_imm_u8, in_SUB_d_rm_mod_reg_u8_imm_u8, in_SUB_d_rm_mod_reg_u8_imm_u8, 
	// F0
	in_XOR_d_rm_mod_reg_u8_imm_u8, in_XOR_d_rm_mod_reg_u8_imm_u8, in_XOR_d_rm_mod_reg_u8_imm_u8, in_XOR_d_rm_mod_reg_u8_imm_u8, in_XOR_d_rm_mod_reg_u8_imm_u8, in_XOR_d_rm_mod_reg_u8_imm_u8, in_XOR_d_rm_mod_reg_u8_imm_u8, in_XOR_d_rm_mod_reg_u8_imm_u8, 
	// F8
	in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, 
};
const OpState CpuRunnerX86::table_st_w_w_81[] = {
	// 00
	in_ADD_w_rm_mod_reg_u16_imm_i16, in_ADD_w_rm_mod_reg_u16_imm_i16, in_ADD_w_rm_mod_reg_u16_imm_i16, in_ADD_w_rm_mod_reg_u16_imm_i16, in_ADD_w_rm_mod_reg_u16_imm_i16, in_ADD_w_rm_mod_reg_u16_imm_i16, in_ADD_w_rm_mod_reg_u16_imm_i16, in_ADD_w_rm_mod_reg_u16_imm_i16, 
	// 08
	in_OR_w_rm_mod_reg_u16_imm_i16, in_OR_w_rm_mod_reg_u16_imm_i16, in_OR_w_rm_mod_reg_u16_imm_i16, in_OR_w_rm_mod_reg_u16_imm_i16, in_OR_w_rm_mod_reg_u16_imm_i16, in_OR_w_rm_mod_reg_u16_imm_i16, in_OR_w_rm_mod_reg_u16_imm_i16, in_OR_w_rm_mod_reg_u16_imm_i16, 
	// 10
	in_ADC_w_rm_mod_reg_u16_imm_i16, in_ADC_w_rm_mod_reg_u16_imm_i16, in_ADC_w_rm_mod_reg_u16_imm_i16, in_ADC_w_rm_mod_reg_u16_imm_i16, in_ADC_w_rm_mod_reg_u16_imm_i16, in_ADC_w_rm_mod_reg_u16_imm_i16, in_ADC_w_rm_mod_reg_u16_imm_i16, in_ADC_w_rm_mod_reg_u16_imm_i16, 
	// 18
	in_SBB_w_rm_mod_reg_u16_imm_i16, in_SBB_w_rm_mod_reg_u16_imm_i16, in_SBB_w_rm_mod_reg_u16_imm_i16, in_SBB_w_rm_mod_reg_u16_imm_i16, in_SBB_w_rm_mod_reg_u16_imm_i16, in_SBB_w_rm_mod_reg_u16_imm_i16, in_SBB_w_rm_mod_reg_u16_imm_i16, in_SBB_w_rm_mod_reg_u16_imm_i16, 
	// 20
	in_AND_w_rm_mod_reg_u16_imm_i16, in_AND_w_rm_mod_reg_u16_imm_i16, in_AND_w_rm_mod_reg_u16_imm_i16, in_AND_w_rm_mod_reg_u16_imm_i16, in_AND_w_rm_mod_reg_u16_imm_i16, in_AND_w_rm_mod_reg_u16_imm_i16, in_AND_w_rm_mod_reg_u16_imm_i16, in_AND_w_rm_mod_reg_u16_imm_i16, 
	// 28
	in_SUB_w_rm_mod_reg_u16_imm_i16, in_SUB_w_rm_mod_reg_u16_imm_i16, in_SUB_w_rm_mod_reg_u16_imm_i16, in_SUB_w_rm_mod_reg_u16_imm_i16, in_SUB_w_rm_mod_reg_u16_imm_i16, in_SUB_w_rm_mod_reg_u16_imm_i16, in_SUB_w_rm_mod_reg_u16_imm_i16, in_SUB_w_rm_mod_reg_u16_imm_i16, 
	// 30
	in_XOR_w_rm_mod_reg_u16_imm_i16, in_XOR_w_rm_mod_reg_u16_imm_i16, in_XOR_w_rm_mod_reg_u16_imm_i16, in_XOR_w_rm_mod_reg_u16_imm_i16, in_XOR_w_rm_mod_reg_u16_imm_i16, in_XOR_w_rm_mod_reg_u16_imm_i16, in_XOR_w_rm_mod_reg_u16_imm_i16, in_XOR_w_rm_mod_reg_u16_imm_i16, 
	// 38
	in_CMP_w_imm_i16, in_CMP_w_imm_i16, in_CMP_w_imm_i16, in_CMP_w_imm_i16, in_CMP_w_imm_i16, in_CMP_w_imm_i16, in_CMP_w_imm_i16, in_CMP_w_imm_i16, 
	// 40
	in_ADD_w_rm_mod_reg_u16_imm_i16, in_ADD_w_rm_mod_reg_u16_imm_i16, in_ADD_w_rm_mod_reg_u16_imm_i16, in_ADD_w_rm_mod_reg_u16_imm_i16, in_ADD_w_rm_mod_reg_u16_imm_i16, in_ADD_w_rm_mod_reg_u16_imm_i16, in_ADD_w_rm_mod_reg_u16_imm_i16, in_ADD_w_rm_mod_reg_u16_imm_i16, 
	// 48
	in_OR_w_rm_mod_reg_u16_imm_i16, in_OR_w_rm_mod_reg_u16_imm_i16, in_OR_w_rm_mod_reg_u16_imm_i16, in_OR_w_rm_mod_reg_u16_imm_i16, in_OR_w_rm_mod_reg_u16_imm_i16, in_OR_w_rm_mod_reg_u16_imm_i16, in_OR_w_rm_mod_reg_u16_imm_i16, in_OR_w_rm_mod_reg_u16_imm_i16, 
	// 50
	in_ADC_w_rm_mod_reg_u16_imm_i16, in_ADC_w_rm_mod_reg_u16_imm_i16, in_ADC_w_rm_mod_reg_u16_imm_i16, in_ADC_w_rm_mod_reg_u16_imm_i16, in_ADC_w_rm_mod_reg_u16_imm_i16, in_ADC_w_rm_mod_reg_u16_imm_i16, in_ADC_w_rm_mod_reg_u16_imm_i16, in_ADC_w_rm_mod_reg_u16_imm_i16, 
	// 58
	in_SBB_w_rm_mod_reg_u16_imm_i16, in_SBB_w_rm_mod_reg_u16_imm_i16, in_SBB_w_rm_mod_reg_u16_imm_i16, in_SBB_w_rm_mod_reg_u16_imm_i16, in_SBB_w_rm_mod_reg_u16_imm_i16, in_SBB_w_rm_mod_reg_u16_imm_i16, in_SBB_w_rm_mod_reg_u16_imm_i16, in_SBB_w_rm_mod_reg_u16_imm_i16, 
	// 60
	in_AND_w_rm_mod_reg_u16_imm_i16, in_AND_w_rm_mod_reg_u16_imm_i16, in_AND_w_rm_mod_reg_u16_imm_i16, in_AND_w_rm_mod_reg_u16_imm_i16, in_AND_w_rm_mod_reg_u16_imm_i16, in_AND_w_rm_mod_reg_u16_imm_i16, in_AND_w_rm_mod_reg_u16_imm_i16, in_AND_w_rm_mod_reg_u16_imm_i16, 
	// 68
	in_SUB_w_rm_mod_reg_u16_imm_i16, in_SUB_w_rm_mod_reg_u16_imm_i16, in_SUB_w_rm_mod_reg_u16_imm_i16, in_SUB_w_rm_mod_reg_u16_imm_i16, in_SUB_w_rm_mod_reg_u16_imm_i16, in_SUB_w_rm_mod_reg_u16_imm_i16, in_SUB_w_rm_mod_reg_u16_imm_i16, in_SUB_w_rm_mod_reg_u16_imm_i16, 
	// 70
	in_XOR_w_rm_mod_reg_u16_imm_i16, in_XOR_w_rm_mod_reg_u16_imm_i16, in_XOR_w_rm_mod_reg_u16_imm_i16, in_XOR_w_rm_mod_reg_u16_imm_i16, in_XOR_w_rm_mod_reg_u16_imm_i16, in_XOR_w_rm_mod_reg_u16_imm_i16, in_XOR_w_rm_mod_reg_u16_imm_i16, in_XOR_w_rm_mod_reg_u16_imm_i16, 
	// 78
	in_CMP_w_imm_i16, in_CMP_w_imm_i16, in_CMP_w_imm_i16, in_CMP_w_imm_i16, in_CMP_w_imm_i16, in_CMP_w_imm_i16, in_CMP_w_imm_i16, in_CMP_w_imm_i16, 
	// 80
	in_ADD_w_rm_mod_reg_u16_imm_i16, in_ADD_w_rm_mod_reg_u16_imm_i16, in_ADD_w_rm_mod_reg_u16_imm_i16, in_ADD_w_rm_mod_reg_u16_imm_i16, in_ADD_w_rm_mod_reg_u16_imm_i16, in_ADD_w_rm_mod_reg_u16_imm_i16, in_ADD_w_rm_mod_reg_u16_imm_i16, in_ADD_w_rm_mod_reg_u16_imm_i16, 
	// 88
	in_OR_w_rm_mod_reg_u16_imm_i16, in_OR_w_rm_mod_reg_u16_imm_i16, in_OR_w_rm_mod_reg_u16_imm_i16, in_OR_w_rm_mod_reg_u16_imm_i16, in_OR_w_rm_mod_reg_u16_imm_i16, in_OR_w_rm_mod_reg_u16_imm_i16, in_OR_w_rm_mod_reg_u16_imm_i16, in_OR_w_rm_mod_reg_u16_imm_i16, 
	// 90
	in_ADC_w_rm_mod_reg_u16_imm_i16, in_ADC_w_rm_mod_reg_u16_imm_i16, in_ADC_w_rm_mod_reg_u16_imm_i16, in_ADC_w_rm_mod_reg_u16_imm_i16, in_ADC_w_rm_mod_reg_u16_imm_i16, in_ADC_w_rm_mod_reg_u16_imm_i16, in_ADC_w_rm_mod_reg_u16_imm_i16, in_ADC_w_rm_mod_reg_u16_imm_i16, 
	// 98
	in_SBB_w_rm_mod_reg_u16_imm_i16, in_SBB_w_rm_mod_reg_u16_imm_i16, in_SBB_w_rm_mod_reg_u16_imm_i16, in_SBB_w_rm_mod_reg_u16_imm_i16, in_SBB_w_rm_mod_reg_u16_imm_i16, in_SBB_w_rm_mod_reg_u16_imm_i16, in_SBB_w_rm_mod_reg_u16_imm_i16, in_SBB_w_rm_mod_reg_u16_imm_i16, 
	// A0
	in_AND_w_rm_mod_reg_u16_imm_i16, in_AND_w_rm_mod_reg_u16_imm_i16, in_AND_w_rm_mod_reg_u16_imm_i16, in_AND_w_rm_mod_reg_u16_imm_i16, in_AND_w_rm_mod_reg_u16_imm_i16, in_AND_w_rm_mod_reg_u16_imm_i16, in_AND_w_rm_mod_reg_u16_imm_i16, in_AND_w_rm_mod_reg_u16_imm_i16, 
	// A8
	in_SUB_w_rm_mod_reg_u16_imm_i16, in_SUB_w_rm_mod_reg_u16_imm_i16, in_SUB_w_rm_mod_reg_u16_imm_i16, in_SUB_w_rm_mod_reg_u16_imm_i16, in_SUB_w_rm_mod_reg_u16_imm_i16, in_SUB_w_rm_mod_reg_u16_imm_i16, in_SUB_w_rm_mod_reg_u16_imm_i16, in_SUB_w_rm_mod_reg_u16_imm_i16, 
	// B0
	in_XOR_w_rm_mod_reg_u16_imm_i16, in_XOR_w_rm_mod_reg_u16_imm_i16, in_XOR_w_rm_mod_reg_u16_imm_i16, in_XOR_w_rm_mod_reg_u16_imm_i16, in_XOR_w_rm_mod_reg_u16_imm_i16, in_XOR_w_rm_mod_reg_u16_imm_i16, in_XOR_w_rm_mod_reg_u16_imm_i16, in_XOR_w_rm_mod_reg_u16_imm_i16, 
	// B8
	in_CMP_w_imm_i16, in_CMP_w_imm_i16, in_CMP_w_imm_i16, in_CMP_w_imm_i16, in_CMP_w_imm_i16, in_CMP_w_imm_i16, in_CMP_w_imm_i16, in_CMP_w_imm_i16, 
	// C0
	in_ADD_w_rm_mod_reg_u16_imm_i16, in_ADD_w_rm_mod_reg_u16_imm_i16, in_ADD_w_rm_mod_reg_u16_imm_i16, in_ADD_w_rm_mod_reg_u16_imm_i16, in_ADD_w_rm_mod_reg_u16_imm_i16, in_ADD_w_rm_mod_reg_u16_imm_i16, in_ADD_w_rm_mod_reg_u16_imm_i16, in_ADD_w_rm_mod_reg_u16_imm_i16, 
	// C8
	in_OR_w_rm_mod_reg_u16_imm_i16, in_OR_w_rm_mod_reg_u16_imm_i16, in_OR_w_rm_mod_reg_u16_imm_i16, in_OR_w_rm_mod_reg_u16_imm_i16, in_OR_w_rm_mod_reg_u16_imm_i16, in_OR_w_rm_mod_reg_u16_imm_i16, in_OR_w_rm_mod_reg_u16_imm_i16, in_OR_w_rm_mod_reg_u16_imm_i16, 
	// D0
	in_ADC_w_rm_mod_reg_u16_imm_i16, in_ADC_w_rm_mod_reg_u16_imm_i16, in_ADC_w_rm_mod_reg_u16_imm_i16, in_ADC_w_rm_mod_reg_u16_imm_i16, in_ADC_w_rm_mod_reg_u16_imm_i16, in_ADC_w_rm_mod_reg_u16_imm_i16, in_ADC_w_rm_mod_reg_u16_imm_i16, in_ADC_w_rm_mod_reg_u16_imm_i16, 
	// D8
	in_SBB_w_rm_mod_reg_u16_imm_i16, in_SBB_w_rm_mod_reg_u16_imm_i16, in_SBB_w_rm_mod_reg_u16_imm_i16, in_SBB_w_rm_mod_reg_u16_imm_i16, in_SBB_w_rm_mod_reg_u16_imm_i16, in_SBB_w_rm_mod_reg_u16_imm_i16, in_SBB_w_rm_mod_reg_u16_imm_i16, in_SBB_w_rm_mod_reg_u16_imm_i16, 
	// E0
	in_AND_w_rm_mod_reg_u16_imm_i16, in_AND_w_rm_mod_reg_u16_imm_i16, in_AND_w_rm_mod_reg_u16_imm_i16, in_AND_w_rm_mod_reg_u16_imm_i16, in_AND_w_rm_mod_reg_u16_imm_i16, in_AND_w_rm_mod_reg_u16_imm_i16, in_AND_w_rm_mod_reg_u16_imm_i16, in_AND_w_rm_mod_reg_u16_imm_i16, 
	// E8
	in_SUB_w_rm_mod_reg_u16_imm_i16, in_SUB_w_rm_mod_reg_u16_imm_i16, in_SUB_w_rm_mod_reg_u16_imm_i16, in_SUB_w_rm_mod_reg_u16_imm_i16, in_SUB_w_rm_mod_reg_u16_imm_i16, in_SUB_w_rm_mod_reg_u16_imm_i16, in_SUB_w_rm_mod_reg_u16_imm_i16, in_SUB_w_rm_mod_reg_u16_imm_i16, 
	// F0
	in_XOR_w_rm_mod_reg_u16_imm_i16, in_XOR_w_rm_mod_reg_u16_imm_i16, in_XOR_w_rm_mod_reg_u16_imm_i16, in_XOR_w_rm_mod_reg_u16_imm_i16, in_XOR_w_rm_mod_reg_u16_imm_i16, in_XOR_w_rm_mod_reg_u16_imm_i16, in_XOR_w_rm_mod_reg_u16_imm_i16, in_XOR_w_rm_mod_reg_u16_imm_i16, 
	// F8
	in_CMP_w_imm_i16, in_CMP_w_imm_i16, in_CMP_w_imm_i16, in_CMP_w_imm_i16, in_CMP_w_imm_i16, in_CMP_w_imm_i16, in_CMP_w_imm_i16, in_CMP_w_imm_i16, 
};
const OpState CpuRunnerX86::table_st_w_d_81[] = {
	// 00
	in_ADD_w_rm_mod_reg_u32_imm_i32, in_ADD_w_rm_mod_reg_u32_imm_i32, in_ADD_w_rm_mod_reg_u32_imm_i32, in_ADD_w_rm_mod_reg_u32_imm_i32, in_ADD_w_rm_mod_reg_u32_imm_i32, in_ADD_w_rm_mod_reg_u32_imm_i32, in_ADD_w_rm_mod_reg_u32_imm_i32, in_ADD_w_rm_mod_reg_u32_imm_i32, 
	// 08
	in_OR_w_rm_mod_reg_u32_imm_i32, in_OR_w_rm_mod_reg_u32_imm_i32, in_OR_w_rm_mod_reg_u32_imm_i32, in_OR_w_rm_mod_reg_u32_imm_i32, in_OR_w_rm_mod_reg_u32_imm_i32, in_OR_w_rm_mod_reg_u32_imm_i32, in_OR_w_rm_mod_reg_u32_imm_i32, in_OR_w_rm_mod_reg_u32_imm_i32, 
	// 10
	in_ADC_w_rm_mod_reg_u32_imm_i32, in_ADC_w_rm_mod_reg_u32_imm_i32, in_ADC_w_rm_mod_reg_u32_imm_i32, in_ADC_w_rm_mod_reg_u32_imm_i32, in_ADC_w_rm_mod_reg_u32_imm_i32, in_ADC_w_rm_mod_reg_u32_imm_i32, in_ADC_w_rm_mod_reg_u32_imm_i32, in_ADC_w_rm_mod_reg_u32_imm_i32, 
	// 18
	in_SBB_w_rm_mod_reg_u32_imm_i32, in_SBB_w_rm_mod_reg_u32_imm_i32, in_SBB_w_rm_mod_reg_u32_imm_i32, in_SBB_w_rm_mod_reg_u32_imm_i32, in_SBB_w_rm_mod_reg_u32_imm_i32, in_SBB_w_rm_mod_reg_u32_imm_i32, in_SBB_w_rm_mod_reg_u32_imm_i32, in_SBB_w_rm_mod_reg_u32_imm_i32, 
	// 20
	in_AND_w_rm_mod_reg_u32_imm_i32, in_AND_w_rm_mod_reg_u32_imm_i32, in_AND_w_rm_mod_reg_u32_imm_i32, in_AND_w_rm_mod_reg_u32_imm_i32, in_AND_w_rm_mod_reg_u32_imm_i32, in_AND_w_rm_mod_reg_u32_imm_i32, in_AND_w_rm_mod_reg_u32_imm_i32, in_AND_w_rm_mod_reg_u32_imm_i32, 
	// 28
	in_SUB_w_rm_mod_reg_u32_imm_i32, in_SUB_w_rm_mod_reg_u32_imm_i32, in_SUB_w_rm_mod_reg_u32_imm_i32, in_SUB_w_rm_mod_reg_u32_imm_i32, in_SUB_w_rm_mod_reg_u32_imm_i32, in_SUB_w_rm_mod_reg_u32_imm_i32, in_SUB_w_rm_mod_reg_u32_imm_i32, in_SUB_w_rm_mod_reg_u32_imm_i32, 
	// 30
	in_XOR_w_rm_mod_reg_u32_imm_i32, in_XOR_w_rm_mod_reg_u32_imm_i32, in_XOR_w_rm_mod_reg_u32_imm_i32, in_XOR_w_rm_mod_reg_u32_imm_i32, in_XOR_w_rm_mod_reg_u32_imm_i32, in_XOR_w_rm_mod_reg_u32_imm_i32, in_XOR_w_rm_mod_reg_u32_imm_i32, in_XOR_w_rm_mod_reg_u32_imm_i32, 
	// 38
	in_CMP_w_imm_i32, in_CMP_w_imm_i32, in_CMP_w_imm_i32, in_CMP_w_imm_i32, in_CMP_w_imm_i32, in_CMP_w_imm_i32, in_CMP_w_imm_i32, in_CMP_w_imm_i32, 
	// 40
	in_ADD_w_rm_mod_reg_u32_imm_i32, in_ADD_w_rm_mod_reg_u32_imm_i32, in_ADD_w_rm_mod_reg_u32_imm_i32, in_ADD_w_rm_mod_reg_u32_imm_i32, in_ADD_w_rm_mod_reg_u32_imm_i32, in_ADD_w_rm_mod_reg_u32_imm_i32, in_ADD_w_rm_mod_reg_u32_imm_i32, in_ADD_w_rm_mod_reg_u32_imm_i32, 
	// 48
	in_OR_w_rm_mod_reg_u32_imm_i32, in_OR_w_rm_mod_reg_u32_imm_i32, in_OR_w_rm_mod_reg_u32_imm_i32, in_OR_w_rm_mod_reg_u32_imm_i32, in_OR_w_rm_mod_reg_u32_imm_i32, in_OR_w_rm_mod_reg_u32_imm_i32, in_OR_w_rm_mod_reg_u32_imm_i32, in_OR_w_rm_mod_reg_u32_imm_i32, 
	// 50
	in_ADC_w_rm_mod_reg_u32_imm_i32, in_ADC_w_rm_mod_reg_u32_imm_i32, in_ADC_w_rm_mod_reg_u32_imm_i32, in_ADC_w_rm_mod_reg_u32_imm_i32, in_ADC_w_rm_mod_reg_u32_imm_i32, in_ADC_w_rm_mod_reg_u32_imm_i32, in_ADC_w_rm_mod_reg_u32_imm_i32, in_ADC_w_rm_mod_reg_u32_imm_i32, 
	// 58
	in_SBB_w_rm_mod_reg_u32_imm_i32, in_SBB_w_rm_mod_reg_u32_imm_i32, in_SBB_w_rm_mod_reg_u32_imm_i32, in_SBB_w_rm_mod_reg_u32_imm_i32, in_SBB_w_rm_mod_reg_u32_imm_i32, in_SBB_w_rm_mod_reg_u32_imm_i32, in_SBB_w_rm_mod_reg_u32_imm_i32, in_SBB_w_rm_mod_reg_u32_imm_i32, 
	// 60
	in_AND_w_rm_mod_reg_u32_imm_i32, in_AND_w_rm_mod_reg_u32_imm_i32, in_AND_w_rm_mod_reg_u32_imm_i32, in_AND_w_rm_mod_reg_u32_imm_i32, in_AND_w_rm_mod_reg_u32_imm_i32, in_AND_w_rm_mod_reg_u32_imm_i32, in_AND_w_rm_mod_reg_u32_imm_i32, in_AND_w_rm_mod_reg_u32_imm_i32, 
	// 68
	in_SUB_w_rm_mod_reg_u32_imm_i32, in_SUB_w_rm_mod_reg_u32_imm_i32, in_SUB_w_rm_mod_reg_u32_imm_i32, in_SUB_w_rm_mod_reg_u32_imm_i32, in_SUB_w_rm_mod_reg_u32_imm_i32, in_SUB_w_rm_mod_reg_u32_imm_i32, in_SUB_w_rm_mod_reg_u32_imm_i32, in_SUB_w_rm_mod_reg_u32_imm_i32, 
	// 70
	in_XOR_w_rm_mod_reg_u32_imm_i32, in_XOR_w_rm_mod_reg_u32_imm_i32, in_XOR_w_rm_mod_reg_u32_imm_i32, in_XOR_w_rm_mod_reg_u32_imm_i32, in_XOR_w_rm_mod_reg_u32_imm_i32, in_XOR_w_rm_mod_reg_u32_imm_i32, in_XOR_w_rm_mod_reg_u32_imm_i32, in_XOR_w_rm_mod_reg_u32_imm_i32, 
	// 78
	in_CMP_w_imm_i32, in_CMP_w_imm_i32, in_CMP_w_imm_i32, in_CMP_w_imm_i32, in_CMP_w_imm_i32, in_CMP_w_imm_i32, in_CMP_w_imm_i32, in_CMP_w_imm_i32, 
	// 80
	in_ADD_w_rm_mod_reg_u32_imm_i32, in_ADD_w_rm_mod_reg_u32_imm_i32, in_ADD_w_rm_mod_reg_u32_imm_i32, in_ADD_w_rm_mod_reg_u32_imm_i32, in_ADD_w_rm_mod_reg_u32_imm_i32, in_ADD_w_rm_mod_reg_u32_imm_i32, in_ADD_w_rm_mod_reg_u32_imm_i32, in_ADD_w_rm_mod_reg_u32_imm_i32, 
	// 88
	in_OR_w_rm_mod_reg_u32_imm_i32, in_OR_w_rm_mod_reg_u32_imm_i32, in_OR_w_rm_mod_reg_u32_imm_i32, in_OR_w_rm_mod_reg_u32_imm_i32, in_OR_w_rm_mod_reg_u32_imm_i32, in_OR_w_rm_mod_reg_u32_imm_i32, in_OR_w_rm_mod_reg_u32_imm_i32, in_OR_w_rm_mod_reg_u32_imm_i32, 
	// 90
	in_ADC_w_rm_mod_reg_u32_imm_i32, in_ADC_w_rm_mod_reg_u32_imm_i32, in_ADC_w_rm_mod_reg_u32_imm_i32, in_ADC_w_rm_mod_reg_u32_imm_i32, in_ADC_w_rm_mod_reg_u32_imm_i32, in_ADC_w_rm_mod_reg_u32_imm_i32, in_ADC_w_rm_mod_reg_u32_imm_i32, in_ADC_w_rm_mod_reg_u32_imm_i32, 
	// 98
	in_SBB_w_rm_mod_reg_u32_imm_i32, in_SBB_w_rm_mod_reg_u32_imm_i32, in_SBB_w_rm_mod_reg_u32_imm_i32, in_SBB_w_rm_mod_reg_u32_imm_i32, in_SBB_w_rm_mod_reg_u32_imm_i32, in_SBB_w_rm_mod_reg_u32_imm_i32, in_SBB_w_rm_mod_reg_u32_imm_i32, in_SBB_w_rm_mod_reg_u32_imm_i32, 
	// A0
	in_AND_w_rm_mod_reg_u32_imm_i32, in_AND_w_rm_mod_reg_u32_imm_i32, in_AND_w_rm_mod_reg_u32_imm_i32, in_AND_w_rm_mod_reg_u32_imm_i32, in_AND_w_rm_mod_reg_u32_imm_i32, in_AND_w_rm_mod_reg_u32_imm_i32, in_AND_w_rm_mod_reg_u32_imm_i32, in_AND_w_rm_mod_reg_u32_imm_i32, 
	// A8
	in_SUB_w_rm_mod_reg_u32_imm_i32, in_SUB_w_rm_mod_reg_u32_imm_i32, in_SUB_w_rm_mod_reg_u32_imm_i32, in_SUB_w_rm_mod_reg_u32_imm_i32, in_SUB_w_rm_mod_reg_u32_imm_i32, in_SUB_w_rm_mod_reg_u32_imm_i32, in_SUB_w_rm_mod_reg_u32_imm_i32, in_SUB_w_rm_mod_reg_u32_imm_i32, 
	// B0
	in_XOR_w_rm_mod_reg_u32_imm_i32, in_XOR_w_rm_mod_reg_u32_imm_i32, in_XOR_w_rm_mod_reg_u32_imm_i32, in_XOR_w_rm_mod_reg_u32_imm_i32, in_XOR_w_rm_mod_reg_u32_imm_i32, in_XOR_w_rm_mod_reg_u32_imm_i32, in_XOR_w_rm_mod_reg_u32_imm_i32, in_XOR_w_rm_mod_reg_u32_imm_i32, 
	// B8
	in_CMP_w_imm_i32, in_CMP_w_imm_i32, in_CMP_w_imm_i32, in_CMP_w_imm_i32, in_CMP_w_imm_i32, in_CMP_w_imm_i32, in_CMP_w_imm_i32, in_CMP_w_imm_i32, 
	// C0
	in_ADD_w_rm_mod_reg_u32_imm_i32, in_ADD_w_rm_mod_reg_u32_imm_i32, in_ADD_w_rm_mod_reg_u32_imm_i32, in_ADD_w_rm_mod_reg_u32_imm_i32, in_ADD_w_rm_mod_reg_u32_imm_i32, in_ADD_w_rm_mod_reg_u32_imm_i32, in_ADD_w_rm_mod_reg_u32_imm_i32, in_ADD_w_rm_mod_reg_u32_imm_i32, 
	// C8
	in_OR_w_rm_mod_reg_u32_imm_i32, in_OR_w_rm_mod_reg_u32_imm_i32, in_OR_w_rm_mod_reg_u32_imm_i32, in_OR_w_rm_mod_reg_u32_imm_i32, in_OR_w_rm_mod_reg_u32_imm_i32, in_OR_w_rm_mod_reg_u32_imm_i32, in_OR_w_rm_mod_reg_u32_imm_i32, in_OR_w_rm_mod_reg_u32_imm_i32, 
	// D0
	in_ADC_w_rm_mod_reg_u32_imm_i32, in_ADC_w_rm_mod_reg_u32_imm_i32, in_ADC_w_rm_mod_reg_u32_imm_i32, in_ADC_w_rm_mod_reg_u32_imm_i32, in_ADC_w_rm_mod_reg_u32_imm_i32, in_ADC_w_rm_mod_reg_u32_imm_i32, in_ADC_w_rm_mod_reg_u32_imm_i32, in_ADC_w_rm_mod_reg_u32_imm_i32, 
	// D8
	in_SBB_w_rm_mod_reg_u32_imm_i32, in_SBB_w_rm_mod_reg_u32_imm_i32, in_SBB_w_rm_mod_reg_u32_imm_i32, in_SBB_w_rm_mod_reg_u32_imm_i32, in_SBB_w_rm_mod_reg_u32_imm_i32, in_SBB_w_rm_mod_reg_u32_imm_i32, in_SBB_w_rm_mod_reg_u32_imm_i32, in_SBB_w_rm_mod_reg_u32_imm_i32, 
	// E0
	in_AND_w_rm_mod_reg_u32_imm_i32, in_AND_w_rm_mod_reg_u32_imm_i32, in_AND_w_rm_mod_reg_u32_imm_i32, in_AND_w_rm_mod_reg_u32_imm_i32, in_AND_w_rm_mod_reg_u32_imm_i32, in_AND_w_rm_mod_reg_u32_imm_i32, in_AND_w_rm_mod_reg_u32_imm_i32, in_AND_w_rm_mod_reg_u32_imm_i32, 
	// E8
	in_SUB_w_rm_mod_reg_u32_imm_i32, in_SUB_w_rm_mod_reg_u32_imm_i32, in_SUB_w_rm_mod_reg_u32_imm_i32, in_SUB_w_rm_mod_reg_u32_imm_i32, in_SUB_w_rm_mod_reg_u32_imm_i32, in_SUB_w_rm_mod_reg_u32_imm_i32, in_SUB_w_rm_mod_reg_u32_imm_i32, in_SUB_w_rm_mod_reg_u32_imm_i32, 
	// F0
	in_XOR_w_rm_mod_reg_u32_imm_i32, in_XOR_w_rm_mod_reg_u32_imm_i32, in_XOR_w_rm_mod_reg_u32_imm_i32, in_XOR_w_rm_mod_reg_u32_imm_i32, in_XOR_w_rm_mod_reg_u32_imm_i32, in_XOR_w_rm_mod_reg_u32_imm_i32, in_XOR_w_rm_mod_reg_u32_imm_i32, in_XOR_w_rm_mod_reg_u32_imm_i32, 
	// F8
	in_CMP_w_imm_i32, in_CMP_w_imm_i32, in_CMP_w_imm_i32, in_CMP_w_imm_i32, in_CMP_w_imm_i32, in_CMP_w_imm_i32, in_CMP_w_imm_i32, in_CMP_w_imm_i32, 
};
const OpState CpuRunnerX86::table_st_d_w_81[] = {
	// 00
	in_ADD_d_rm_mod_reg_u16_imm_i16, in_ADD_d_rm_mod_reg_u16_imm_i16, in_ADD_d_rm_mod_reg_u16_imm_i16, in_ADD_d_rm_mod_reg_u16_imm_i16, in_ADD_d_rm_mod_reg_u16_imm_i16, in_ADD_d_rm_mod_reg_u16_imm_i16, in_ADD_d_rm_mod_reg_u16_imm_i16, in_ADD_d_rm_mod_reg_u16_imm_i16, 
	// 08
	in_OR_d_rm_mod_reg_u16_imm_i16, in_OR_d_rm_mod_reg_u16_imm_i16, in_OR_d_rm_mod_reg_u16_imm_i16, in_OR_d_rm_mod_reg_u16_imm_i16, in_OR_d_rm_mod_reg_u16_imm_i16, in_OR_d_rm_mod_reg_u16_imm_i16, in_OR_d_rm_mod_reg_u16_imm_i16, in_OR_d_rm_mod_reg_u16_imm_i16, 
	// 10
	in_ADC_d_rm_mod_reg_u16_imm_i16, in_ADC_d_rm_mod_reg_u16_imm_i16, in_ADC_d_rm_mod_reg_u16_imm_i16, in_ADC_d_rm_mod_reg_u16_imm_i16, in_ADC_d_rm_mod_reg_u16_imm_i16, in_ADC_d_rm_mod_reg_u16_imm_i16, in_ADC_d_rm_mod_reg_u16_imm_i16, in_ADC_d_rm_mod_reg_u16_imm_i16, 
	// 18
	in_SBB_d_rm_mod_reg_u16_imm_i16, in_SBB_d_rm_mod_reg_u16_imm_i16, in_SBB_d_rm_mod_reg_u16_imm_i16, in_SBB_d_rm_mod_reg_u16_imm_i16, in_SBB_d_rm_mod_reg_u16_imm_i16, in_SBB_d_rm_mod_reg_u16_imm_i16, in_SBB_d_rm_mod_reg_u16_imm_i16, in_SBB_d_rm_mod_reg_u16_imm_i16, 
	// 20
	in_AND_d_rm_mod_reg_u16_imm_i16, in_AND_d_rm_mod_reg_u16_imm_i16, in_AND_d_rm_mod_reg_u16_imm_i16, in_AND_d_rm_mod_reg_u16_imm_i16, in_AND_d_rm_mod_reg_u16_imm_i16, in_AND_d_rm_mod_reg_u16_imm_i16, in_AND_d_rm_mod_reg_u16_imm_i16, in_AND_d_rm_mod_reg_u16_imm_i16, 
	// 28
	in_SUB_d_rm_mod_reg_u16_imm_i16, in_SUB_d_rm_mod_reg_u16_imm_i16, in_SUB_d_rm_mod_reg_u16_imm_i16, in_SUB_d_rm_mod_reg_u16_imm_i16, in_SUB_d_rm_mod_reg_u16_imm_i16, in_SUB_d_rm_mod_reg_u16_imm_i16, in_SUB_d_rm_mod_reg_u16_imm_i16, in_SUB_d_rm_mod_reg_u16_imm_i16, 
	// 30
	in_XOR_d_rm_mod_reg_u16_imm_i16, in_XOR_d_rm_mod_reg_u16_imm_i16, in_XOR_d_rm_mod_reg_u16_imm_i16, in_XOR_d_rm_mod_reg_u16_imm_i16, in_XOR_d_rm_mod_reg_u16_imm_i16, in_XOR_d_rm_mod_reg_u16_imm_i16, in_XOR_d_rm_mod_reg_u16_imm_i16, in_XOR_d_rm_mod_reg_u16_imm_i16, 
	// 38
	in_CMP_d_imm_i16, in_CMP_d_imm_i16, in_CMP_d_imm_i16, in_CMP_d_imm_i16, in_CMP_d_imm_i16, in_CMP_d_imm_i16, in_CMP_d_imm_i16, in_CMP_d_imm_i16, 
	// 40
	in_ADD_d_rm_mod_reg_u16_imm_i16, in_ADD_d_rm_mod_reg_u16_imm_i16, in_ADD_d_rm_mod_reg_u16_imm_i16, in_ADD_d_rm_mod_reg_u16_imm_i16, in_ADD_d_rm_mod_reg_u16_imm_i16, in_ADD_d_rm_mod_reg_u16_imm_i16, in_ADD_d_rm_mod_reg_u16_imm_i16, in_ADD_d_rm_mod_reg_u16_imm_i16, 
	// 48
	in_OR_d_rm_mod_reg_u16_imm_i16, in_OR_d_rm_mod_reg_u16_imm_i16, in_OR_d_rm_mod_reg_u16_imm_i16, in_OR_d_rm_mod_reg_u16_imm_i16, in_OR_d_rm_mod_reg_u16_imm_i16, in_OR_d_rm_mod_reg_u16_imm_i16, in_OR_d_rm_mod_reg_u16_imm_i16, in_OR_d_rm_mod_reg_u16_imm_i16, 
	// 50
	in_ADC_d_rm_mod_reg_u16_imm_i16, in_ADC_d_rm_mod_reg_u16_imm_i16, in_ADC_d_rm_mod_reg_u16_imm_i16, in_ADC_d_rm_mod_reg_u16_imm_i16, in_ADC_d_rm_mod_reg_u16_imm_i16, in_ADC_d_rm_mod_reg_u16_imm_i16, in_ADC_d_rm_mod_reg_u16_imm_i16, in_ADC_d_rm_mod_reg_u16_imm_i16, 
	// 58
	in_SBB_d_rm_mod_reg_u16_imm_i16, in_SBB_d_rm_mod_reg_u16_imm_i16, in_SBB_d_rm_mod_reg_u16_imm_i16, in_SBB_d_rm_mod_reg_u16_imm_i16, in_SBB_d_rm_mod_reg_u16_imm_i16, in_SBB_d_rm_mod_reg_u16_imm_i16, in_SBB_d_rm_mod_reg_u16_imm_i16, in_SBB_d_rm_mod_reg_u16_imm_i16, 
	// 60
	in_AND_d_rm_mod_reg_u16_imm_i16, in_AND_d_rm_mod_reg_u16_imm_i16, in_AND_d_rm_mod_reg_u16_imm_i16, in_AND_d_rm_mod_reg_u16_imm_i16, in_AND_d_rm_mod_reg_u16_imm_i16, in_AND_d_rm_mod_reg_u16_imm_i16, in_AND_d_rm_mod_reg_u16_imm_i16, in_AND_d_rm_mod_reg_u16_imm_i16, 
	// 68
	in_SUB_d_rm_mod_reg_u16_imm_i16, in_SUB_d_rm_mod_reg_u16_imm_i16, in_SUB_d_rm_mod_reg_u16_imm_i16, in_SUB_d_rm_mod_reg_u16_imm_i16, in_SUB_d_rm_mod_reg_u16_imm_i16, in_SUB_d_rm_mod_reg_u16_imm_i16, in_SUB_d_rm_mod_reg_u16_imm_i16, in_SUB_d_rm_mod_reg_u16_imm_i16, 
	// 70
	in_XOR_d_rm_mod_reg_u16_imm_i16, in_XOR_d_rm_mod_reg_u16_imm_i16, in_XOR_d_rm_mod_reg_u16_imm_i16, in_XOR_d_rm_mod_reg_u16_imm_i16, in_XOR_d_rm_mod_reg_u16_imm_i16, in_XOR_d_rm_mod_reg_u16_imm_i16, in_XOR_d_rm_mod_reg_u16_imm_i16, in_XOR_d_rm_mod_reg_u16_imm_i16, 
	// 78
	in_CMP_d_imm_i16, in_CMP_d_imm_i16, in_CMP_d_imm_i16, in_CMP_d_imm_i16, in_CMP_d_imm_i16, in_CMP_d_imm_i16, in_CMP_d_imm_i16, in_CMP_d_imm_i16, 
	// 80
	in_ADD_d_rm_mod_reg_u16_imm_i16, in_ADD_d_rm_mod_reg_u16_imm_i16, in_ADD_d_rm_mod_reg_u16_imm_i16, in_ADD_d_rm_mod_reg_u16_imm_i16, in_ADD_d_rm_mod_reg_u16_imm_i16, in_ADD_d_rm_mod_reg_u16_imm_i16, in_ADD_d_rm_mod_reg_u16_imm_i16, in_ADD_d_rm_mod_reg_u16_imm_i16, 
	// 88
	in_OR_d_rm_mod_reg_u16_imm_i16, in_OR_d_rm_mod_reg_u16_imm_i16, in_OR_d_rm_mod_reg_u16_imm_i16, in_OR_d_rm_mod_reg_u16_imm_i16, in_OR_d_rm_mod_reg_u16_imm_i16, in_OR_d_rm_mod_reg_u16_imm_i16, in_OR_d_rm_mod_reg_u16_imm_i16, in_OR_d_rm_mod_reg_u16_imm_i16, 
	// 90
	in_ADC_d_rm_mod_reg_u16_imm_i16, in_ADC_d_rm_mod_reg_u16_imm_i16, in_ADC_d_rm_mod_reg_u16_imm_i16, in_ADC_d_rm_mod_reg_u16_imm_i16, in_ADC_d_rm_mod_reg_u16_imm_i16, in_ADC_d_rm_mod_reg_u16_imm_i16, in_ADC_d_rm_mod_reg_u16_imm_i16, in_ADC_d_rm_mod_reg_u16_imm_i16, 
	// 98
	in_SBB_d_rm_mod_reg_u16_imm_i16, in_SBB_d_rm_mod_reg_u16_imm_i16, in_SBB_d_rm_mod_reg_u16_imm_i16, in_SBB_d_rm_mod_reg_u16_imm_i16, in_SBB_d_rm_mod_reg_u16_imm_i16, in_SBB_d_rm_mod_reg_u16_imm_i16, in_SBB_d_rm_mod_reg_u16_imm_i16, in_SBB_d_rm_mod_reg_u16_imm_i16, 
	// A0
	in_AND_d_rm_mod_reg_u16_imm_i16, in_AND_d_rm_mod_reg_u16_imm_i16, in_AND_d_rm_mod_reg_u16_imm_i16, in_AND_d_rm_mod_reg_u16_imm_i16, in_AND_d_rm_mod_reg_u16_imm_i16, in_AND_d_rm_mod_reg_u16_imm_i16, in_AND_d_rm_mod_reg_u16_imm_i16, in_AND_d_rm_mod_reg_u16_imm_i16, 
	// A8
	in_SUB_d_rm_mod_reg_u16_imm_i16, in_SUB_d_rm_mod_reg_u16_imm_i16, in_SUB_d_rm_mod_reg_u16_imm_i16, in_SUB_d_rm_mod_reg_u16_imm_i16, in_SUB_d_rm_mod_reg_u16_imm_i16, in_SUB_d_rm_mod_reg_u16_imm_i16, in_SUB_d_rm_mod_reg_u16_imm_i16, in_SUB_d_rm_mod_reg_u16_imm_i16, 
	// B0
	in_XOR_d_rm_mod_reg_u16_imm_i16, in_XOR_d_rm_mod_reg_u16_imm_i16, in_XOR_d_rm_mod_reg_u16_imm_i16, in_XOR_d_rm_mod_reg_u16_imm_i16, in_XOR_d_rm_mod_reg_u16_imm_i16, in_XOR_d_rm_mod_reg_u16_imm_i16, in_XOR_d_rm_mod_reg_u16_imm_i16, in_XOR_d_rm_mod_reg_u16_imm_i16, 
	// B8
	in_CMP_d_imm_i16, in_CMP_d_imm_i16, in_CMP_d_imm_i16, in_CMP_d_imm_i16, in_CMP_d_imm_i16, in_CMP_d_imm_i16, in_CMP_d_imm_i16, in_CMP_d_imm_i16, 
	// C0
	in_ADD_d_rm_mod_reg_u16_imm_i16, in_ADD_d_rm_mod_reg_u16_imm_i16, in_ADD_d_rm_mod_reg_u16_imm_i16, in_ADD_d_rm_mod_reg_u16_imm_i16, in_ADD_d_rm_mod_reg_u16_imm_i16, in_ADD_d_rm_mod_reg_u16_imm_i16, in_ADD_d_rm_mod_reg_u16_imm_i16, in_ADD_d_rm_mod_reg_u16_imm_i16, 
	// C8
	in_OR_d_rm_mod_reg_u16_imm_i16, in_OR_d_rm_mod_reg_u16_imm_i16, in_OR_d_rm_mod_reg_u16_imm_i16, in_OR_d_rm_mod_reg_u16_imm_i16, in_OR_d_rm_mod_reg_u16_imm_i16, in_OR_d_rm_mod_reg_u16_imm_i16, in_OR_d_rm_mod_reg_u16_imm_i16, in_OR_d_rm_mod_reg_u16_imm_i16, 
	// D0
	in_ADC_d_rm_mod_reg_u16_imm_i16, in_ADC_d_rm_mod_reg_u16_imm_i16, in_ADC_d_rm_mod_reg_u16_imm_i16, in_ADC_d_rm_mod_reg_u16_imm_i16, in_ADC_d_rm_mod_reg_u16_imm_i16, in_ADC_d_rm_mod_reg_u16_imm_i16, in_ADC_d_rm_mod_reg_u16_imm_i16, in_ADC_d_rm_mod_reg_u16_imm_i16, 
	// D8
	in_SBB_d_rm_mod_reg_u16_imm_i16, in_SBB_d_rm_mod_reg_u16_imm_i16, in_SBB_d_rm_mod_reg_u16_imm_i16, in_SBB_d_rm_mod_reg_u16_imm_i16, in_SBB_d_rm_mod_reg_u16_imm_i16, in_SBB_d_rm_mod_reg_u16_imm_i16, in_SBB_d_rm_mod_reg_u16_imm_i16, in_SBB_d_rm_mod_reg_u16_imm_i16, 
	// E0
	in_AND_d_rm_mod_reg_u16_imm_i16, in_AND_d_rm_mod_reg_u16_imm_i16, in_AND_d_rm_mod_reg_u16_imm_i16, in_AND_d_rm_mod_reg_u16_imm_i16, in_AND_d_rm_mod_reg_u16_imm_i16, in_AND_d_rm_mod_reg_u16_imm_i16, in_AND_d_rm_mod_reg_u16_imm_i16, in_AND_d_rm_mod_reg_u16_imm_i16, 
	// E8
	in_SUB_d_rm_mod_reg_u16_imm_i16, in_SUB_d_rm_mod_reg_u16_imm_i16, in_SUB_d_rm_mod_reg_u16_imm_i16, in_SUB_d_rm_mod_reg_u16_imm_i16, in_SUB_d_rm_mod_reg_u16_imm_i16, in_SUB_d_rm_mod_reg_u16_imm_i16, in_SUB_d_rm_mod_reg_u16_imm_i16, in_SUB_d_rm_mod_reg_u16_imm_i16, 
	// F0
	in_XOR_d_rm_mod_reg_u16_imm_i16, in_XOR_d_rm_mod_reg_u16_imm_i16, in_XOR_d_rm_mod_reg_u16_imm_i16, in_XOR_d_rm_mod_reg_u16_imm_i16, in_XOR_d_rm_mod_reg_u16_imm_i16, in_XOR_d_rm_mod_reg_u16_imm_i16, in_XOR_d_rm_mod_reg_u16_imm_i16, in_XOR_d_rm_mod_reg_u16_imm_i16, 
	// F8
	in_CMP_d_imm_i16, in_CMP_d_imm_i16, in_CMP_d_imm_i16, in_CMP_d_imm_i16, in_CMP_d_imm_i16, in_CMP_d_imm_i16, in_CMP_d_imm_i16, in_CMP_d_imm_i16, 
};
const OpState CpuRunnerX86::table_st_d_d_81[] = {
	// 00
	in_ADD_d_rm_mod_reg_u32_imm_i32, in_ADD_d_rm_mod_reg_u32_imm_i32, in_ADD_d_rm_mod_reg_u32_imm_i32, in_ADD_d_rm_mod_reg_u32_imm_i32, in_ADD_d_rm_mod_reg_u32_imm_i32, in_ADD_d_rm_mod_reg_u32_imm_i32, in_ADD_d_rm_mod_reg_u32_imm_i32, in_ADD_d_rm_mod_reg_u32_imm_i32, 
	// 08
	in_OR_d_rm_mod_reg_u32_imm_i32, in_OR_d_rm_mod_reg_u32_imm_i32, in_OR_d_rm_mod_reg_u32_imm_i32, in_OR_d_rm_mod_reg_u32_imm_i32, in_OR_d_rm_mod_reg_u32_imm_i32, in_OR_d_rm_mod_reg_u32_imm_i32, in_OR_d_rm_mod_reg_u32_imm_i32, in_OR_d_rm_mod_reg_u32_imm_i32, 
	// 10
	in_ADC_d_rm_mod_reg_u32_imm_i32, in_ADC_d_rm_mod_reg_u32_imm_i32, in_ADC_d_rm_mod_reg_u32_imm_i32, in_ADC_d_rm_mod_reg_u32_imm_i32, in_ADC_d_rm_mod_reg_u32_imm_i32, in_ADC_d_rm_mod_reg_u32_imm_i32, in_ADC_d_rm_mod_reg_u32_imm_i32, in_ADC_d_rm_mod_reg_u32_imm_i32, 
	// 18
	in_SBB_d_rm_mod_reg_u32_imm_i32, in_SBB_d_rm_mod_reg_u32_imm_i32, in_SBB_d_rm_mod_reg_u32_imm_i32, in_SBB_d_rm_mod_reg_u32_imm_i32, in_SBB_d_rm_mod_reg_u32_imm_i32, in_SBB_d_rm_mod_reg_u32_imm_i32, in_SBB_d_rm_mod_reg_u32_imm_i32, in_SBB_d_rm_mod_reg_u32_imm_i32, 
	// 20
	in_AND_d_rm_mod_reg_u32_imm_i32, in_AND_d_rm_mod_reg_u32_imm_i32, in_AND_d_rm_mod_reg_u32_imm_i32, in_AND_d_rm_mod_reg_u32_imm_i32, in_AND_d_rm_mod_reg_u32_imm_i32, in_AND_d_rm_mod_reg_u32_imm_i32, in_AND_d_rm_mod_reg_u32_imm_i32, in_AND_d_rm_mod_reg_u32_imm_i32, 
	// 28
	in_SUB_d_rm_mod_reg_u32_imm_i32, in_SUB_d_rm_mod_reg_u32_imm_i32, in_SUB_d_rm_mod_reg_u32_imm_i32, in_SUB_d_rm_mod_reg_u32_imm_i32, in_SUB_d_rm_mod_reg_u32_imm_i32, in_SUB_d_rm_mod_reg_u32_imm_i32, in_SUB_d_rm_mod_reg_u32_imm_i32, in_SUB_d_rm_mod_reg_u32_imm_i32, 
	// 30
	in_XOR_d_rm_mod_reg_u32_imm_i32, in_XOR_d_rm_mod_reg_u32_imm_i32, in_XOR_d_rm_mod_reg_u32_imm_i32, in_XOR_d_rm_mod_reg_u32_imm_i32, in_XOR_d_rm_mod_reg_u32_imm_i32, in_XOR_d_rm_mod_reg_u32_imm_i32, in_XOR_d_rm_mod_reg_u32_imm_i32, in_XOR_d_rm_mod_reg_u32_imm_i32, 
	// 38
	in_CMP_d_imm_i32, in_CMP_d_imm_i32, in_CMP_d_imm_i32, in_CMP_d_imm_i32, in_CMP_d_imm_i32, in_CMP_d_imm_i32, in_CMP_d_imm_i32, in_CMP_d_imm_i32, 
	// 40
	in_ADD_d_rm_mod_reg_u32_imm_i32, in_ADD_d_rm_mod_reg_u32_imm_i32, in_ADD_d_rm_mod_reg_u32_imm_i32, in_ADD_d_rm_mod_reg_u32_imm_i32, in_ADD_d_rm_mod_reg_u32_imm_i32, in_ADD_d_rm_mod_reg_u32_imm_i32, in_ADD_d_rm_mod_reg_u32_imm_i32, in_ADD_d_rm_mod_reg_u32_imm_i32, 
	// 48
	in_OR_d_rm_mod_reg_u32_imm_i32, in_OR_d_rm_mod_reg_u32_imm_i32, in_OR_d_rm_mod_reg_u32_imm_i32, in_OR_d_rm_mod_reg_u32_imm_i32, in_OR_d_rm_mod_reg_u32_imm_i32, in_OR_d_rm_mod_reg_u32_imm_i32, in_OR_d_rm_mod_reg_u32_imm_i32, in_OR_d_rm_mod_reg_u32_imm_i32, 
	// 50
	in_ADC_d_rm_mod_reg_u32_imm_i32, in_ADC_d_rm_mod_reg_u32_imm_i32, in_ADC_d_rm_mod_reg_u32_imm_i32, in_ADC_d_rm_mod_reg_u32_imm_i32, in_ADC_d_rm_mod_reg_u32_imm_i32, in_ADC_d_rm_mod_reg_u32_imm_i32, in_ADC_d_rm_mod_reg_u32_imm_i32, in_ADC_d_rm_mod_reg_u32_imm_i32, 
	// 58
	in_SBB_d_rm_mod_reg_u32_imm_i32, in_SBB_d_rm_mod_reg_u32_imm_i32, in_SBB_d_rm_mod_reg_u32_imm_i32, in_SBB_d_rm_mod_reg_u32_imm_i32, in_SBB_d_rm_mod_reg_u32_imm_i32, in_SBB_d_rm_mod_reg_u32_imm_i32, in_SBB_d_rm_mod_reg_u32_imm_i32, in_SBB_d_rm_mod_reg_u32_imm_i32, 
	// 60
	in_AND_d_rm_mod_reg_u32_imm_i32, in_AND_d_rm_mod_reg_u32_imm_i32, in_AND_d_rm_mod_reg_u32_imm_i32, in_AND_d_rm_mod_reg_u32_imm_i32, in_AND_d_rm_mod_reg_u32_imm_i32, in_AND_d_rm_mod_reg_u32_imm_i32, in_AND_d_rm_mod_reg_u32_imm_i32, in_AND_d_rm_mod_reg_u32_imm_i32, 
	// 68
	in_SUB_d_rm_mod_reg_u32_imm_i32, in_SUB_d_rm_mod_reg_u32_imm_i32, in_SUB_d_rm_mod_reg_u32_imm_i32, in_SUB_d_rm_mod_reg_u32_imm_i32, in_SUB_d_rm_mod_reg_u32_imm_i32, in_SUB_d_rm_mod_reg_u32_imm_i32, in_SUB_d_rm_mod_reg_u32_imm_i32, in_SUB_d_rm_mod_reg_u32_imm_i32, 
	// 70
	in_XOR_d_rm_mod_reg_u32_imm_i32, in_XOR_d_rm_mod_reg_u32_imm_i32, in_XOR_d_rm_mod_reg_u32_imm_i32, in_XOR_d_rm_mod_reg_u32_imm_i32, in_XOR_d_rm_mod_reg_u32_imm_i32, in_XOR_d_rm_mod_reg_u32_imm_i32, in_XOR_d_rm_mod_reg_u32_imm_i32, in_XOR_d_rm_mod_reg_u32_imm_i32, 
	// 78
	in_CMP_d_imm_i32, in_CMP_d_imm_i32, in_CMP_d_imm_i32, in_CMP_d_imm_i32, in_CMP_d_imm_i32, in_CMP_d_imm_i32, in_CMP_d_imm_i32, in_CMP_d_imm_i32, 
	// 80
	in_ADD_d_rm_mod_reg_u32_imm_i32, in_ADD_d_rm_mod_reg_u32_imm_i32, in_ADD_d_rm_mod_reg_u32_imm_i32, in_ADD_d_rm_mod_reg_u32_imm_i32, in_ADD_d_rm_mod_reg_u32_imm_i32, in_ADD_d_rm_mod_reg_u32_imm_i32, in_ADD_d_rm_mod_reg_u32_imm_i32, in_ADD_d_rm_mod_reg_u32_imm_i32, 
	// 88
	in_OR_d_rm_mod_reg_u32_imm_i32, in_OR_d_rm_mod_reg_u32_imm_i32, in_OR_d_rm_mod_reg_u32_imm_i32, in_OR_d_rm_mod_reg_u32_imm_i32, in_OR_d_rm_mod_reg_u32_imm_i32, in_OR_d_rm_mod_reg_u32_imm_i32, in_OR_d_rm_mod_reg_u32_imm_i32, in_OR_d_rm_mod_reg_u32_imm_i32, 
	// 90
	in_ADC_d_rm_mod_reg_u32_imm_i32, in_ADC_d_rm_mod_reg_u32_imm_i32, in_ADC_d_rm_mod_reg_u32_imm_i32, in_ADC_d_rm_mod_reg_u32_imm_i32, in_ADC_d_rm_mod_reg_u32_imm_i32, in_ADC_d_rm_mod_reg_u32_imm_i32, in_ADC_d_rm_mod_reg_u32_imm_i32, in_ADC_d_rm_mod_reg_u32_imm_i32, 
	// 98
	in_SBB_d_rm_mod_reg_u32_imm_i32, in_SBB_d_rm_mod_reg_u32_imm_i32, in_SBB_d_rm_mod_reg_u32_imm_i32, in_SBB_d_rm_mod_reg_u32_imm_i32, in_SBB_d_rm_mod_reg_u32_imm_i32, in_SBB_d_rm_mod_reg_u32_imm_i32, in_SBB_d_rm_mod_reg_u32_imm_i32, in_SBB_d_rm_mod_reg_u32_imm_i32, 
	// A0
	in_AND_d_rm_mod_reg_u32_imm_i32, in_AND_d_rm_mod_reg_u32_imm_i32, in_AND_d_rm_mod_reg_u32_imm_i32, in_AND_d_rm_mod_reg_u32_imm_i32, in_AND_d_rm_mod_reg_u32_imm_i32, in_AND_d_rm_mod_reg_u32_imm_i32, in_AND_d_rm_mod_reg_u32_imm_i32, in_AND_d_rm_mod_reg_u32_imm_i32, 
	// A8
	in_SUB_d_rm_mod_reg_u32_imm_i32, in_SUB_d_rm_mod_reg_u32_imm_i32, in_SUB_d_rm_mod_reg_u32_imm_i32, in_SUB_d_rm_mod_reg_u32_imm_i32, in_SUB_d_rm_mod_reg_u32_imm_i32, in_SUB_d_rm_mod_reg_u32_imm_i32, in_SUB_d_rm_mod_reg_u32_imm_i32, in_SUB_d_rm_mod_reg_u32_imm_i32, 
	// B0
	in_XOR_d_rm_mod_reg_u32_imm_i32, in_XOR_d_rm_mod_reg_u32_imm_i32, in_XOR_d_rm_mod_reg_u32_imm_i32, in_XOR_d_rm_mod_reg_u32_imm_i32, in_XOR_d_rm_mod_reg_u32_imm_i32, in_XOR_d_rm_mod_reg_u32_imm_i32, in_XOR_d_rm_mod_reg_u32_imm_i32, in_XOR_d_rm_mod_reg_u32_imm_i32, 
	// B8
	in_CMP_d_imm_i32, in_CMP_d_imm_i32, in_CMP_d_imm_i32, in_CMP_d_imm_i32, in_CMP_d_imm_i32, in_CMP_d_imm_i32, in_CMP_d_imm_i32, in_CMP_d_imm_i32, 
	// C0
	in_ADD_d_rm_mod_reg_u32_imm_i32, in_ADD_d_rm_mod_reg_u32_imm_i32, in_ADD_d_rm_mod_reg_u32_imm_i32, in_ADD_d_rm_mod_reg_u32_imm_i32, in_ADD_d_rm_mod_reg_u32_imm_i32, in_ADD_d_rm_mod_reg_u32_imm_i32, in_ADD_d_rm_mod_reg_u32_imm_i32, in_ADD_d_rm_mod_reg_u32_imm_i32, 
	// C8
	in_OR_d_rm_mod_reg_u32_imm_i32, in_OR_d_rm_mod_reg_u32_imm_i32, in_OR_d_rm_mod_reg_u32_imm_i32, in_OR_d_rm_mod_reg_u32_imm_i32, in_OR_d_rm_mod_reg_u32_imm_i32, in_OR_d_rm_mod_reg_u32_imm_i32, in_OR_d_rm_mod_reg_u32_imm_i32, in_OR_d_rm_mod_reg_u32_imm_i32, 
	// D0
	in_ADC_d_rm_mod_reg_u32_imm_i32, in_ADC_d_rm_mod_reg_u32_imm_i32, in_ADC_d_rm_mod_reg_u32_imm_i32, in_ADC_d_rm_mod_reg_u32_imm_i32, in_ADC_d_rm_mod_reg_u32_imm_i32, in_ADC_d_rm_mod_reg_u32_imm_i32, in_ADC_d_rm_mod_reg_u32_imm_i32, in_ADC_d_rm_mod_reg_u32_imm_i32, 
	// D8
	in_SBB_d_rm_mod_reg_u32_imm_i32, in_SBB_d_rm_mod_reg_u32_imm_i32, in_SBB_d_rm_mod_reg_u32_imm_i32, in_SBB_d_rm_mod_reg_u32_imm_i32, in_SBB_d_rm_mod_reg_u32_imm_i32, in_SBB_d_rm_mod_reg_u32_imm_i32, in_SBB_d_rm_mod_reg_u32_imm_i32, in_SBB_d_rm_mod_reg_u32_imm_i32, 
	// E0
	in_AND_d_rm_mod_reg_u32_imm_i32, in_AND_d_rm_mod_reg_u32_imm_i32, in_AND_d_rm_mod_reg_u32_imm_i32, in_AND_d_rm_mod_reg_u32_imm_i32, in_AND_d_rm_mod_reg_u32_imm_i32, in_AND_d_rm_mod_reg_u32_imm_i32, in_AND_d_rm_mod_reg_u32_imm_i32, in_AND_d_rm_mod_reg_u32_imm_i32, 
	// E8
	in_SUB_d_rm_mod_reg_u32_imm_i32, in_SUB_d_rm_mod_reg_u32_imm_i32, in_SUB_d_rm_mod_reg_u32_imm_i32, in_SUB_d_rm_mod_reg_u32_imm_i32, in_SUB_d_rm_mod_reg_u32_imm_i32, in_SUB_d_rm_mod_reg_u32_imm_i32, in_SUB_d_rm_mod_reg_u32_imm_i32, in_SUB_d_rm_mod_reg_u32_imm_i32, 
	// F0
	in_XOR_d_rm_mod_reg_u32_imm_i32, in_XOR_d_rm_mod_reg_u32_imm_i32, in_XOR_d_rm_mod_reg_u32_imm_i32, in_XOR_d_rm_mod_reg_u32_imm_i32, in_XOR_d_rm_mod_reg_u32_imm_i32, in_XOR_d_rm_mod_reg_u32_imm_i32, in_XOR_d_rm_mod_reg_u32_imm_i32, in_XOR_d_rm_mod_reg_u32_imm_i32, 
	// F8
	in_CMP_d_imm_i32, in_CMP_d_imm_i32, in_CMP_d_imm_i32, in_CMP_d_imm_i32, in_CMP_d_imm_i32, in_CMP_d_imm_i32, in_CMP_d_imm_i32, in_CMP_d_imm_i32, 
};
const OpState CpuRunnerX86::table_st_w_w_83[] = {
	// 00
	in_ADD_w_rm_mod_reg_u16_imm_u8, in_ADD_w_rm_mod_reg_u16_imm_u8, in_ADD_w_rm_mod_reg_u16_imm_u8, in_ADD_w_rm_mod_reg_u16_imm_u8, in_ADD_w_rm_mod_reg_u16_imm_u8, in_ADD_w_rm_mod_reg_u16_imm_u8, in_ADD_w_rm_mod_reg_u16_imm_u8, in_ADD_w_rm_mod_reg_u16_imm_u8, 
	// 08
	in_OR_w_rm_mod_reg_u16_imm_u8, in_OR_w_rm_mod_reg_u16_imm_u8, in_OR_w_rm_mod_reg_u16_imm_u8, in_OR_w_rm_mod_reg_u16_imm_u8, in_OR_w_rm_mod_reg_u16_imm_u8, in_OR_w_rm_mod_reg_u16_imm_u8, in_OR_w_rm_mod_reg_u16_imm_u8, in_OR_w_rm_mod_reg_u16_imm_u8, 
	// 10
	in_ADC_w_rm_mod_reg_u16_imm_u8, in_ADC_w_rm_mod_reg_u16_imm_u8, in_ADC_w_rm_mod_reg_u16_imm_u8, in_ADC_w_rm_mod_reg_u16_imm_u8, in_ADC_w_rm_mod_reg_u16_imm_u8, in_ADC_w_rm_mod_reg_u16_imm_u8, in_ADC_w_rm_mod_reg_u16_imm_u8, in_ADC_w_rm_mod_reg_u16_imm_u8, 
	// 18
	in_SBB_w_rm_mod_reg_u16_imm_u8, in_SBB_w_rm_mod_reg_u16_imm_u8, in_SBB_w_rm_mod_reg_u16_imm_u8, in_SBB_w_rm_mod_reg_u16_imm_u8, in_SBB_w_rm_mod_reg_u16_imm_u8, in_SBB_w_rm_mod_reg_u16_imm_u8, in_SBB_w_rm_mod_reg_u16_imm_u8, in_SBB_w_rm_mod_reg_u16_imm_u8, 
	// 20
	in_AND_w_rm_mod_reg_u16_imm_u8, in_AND_w_rm_mod_reg_u16_imm_u8, in_AND_w_rm_mod_reg_u16_imm_u8, in_AND_w_rm_mod_reg_u16_imm_u8, in_AND_w_rm_mod_reg_u16_imm_u8, in_AND_w_rm_mod_reg_u16_imm_u8, in_AND_w_rm_mod_reg_u16_imm_u8, in_AND_w_rm_mod_reg_u16_imm_u8, 
	// 28
	in_SUB_w_rm_mod_reg_u16_imm_u8, in_SUB_w_rm_mod_reg_u16_imm_u8, in_SUB_w_rm_mod_reg_u16_imm_u8, in_SUB_w_rm_mod_reg_u16_imm_u8, in_SUB_w_rm_mod_reg_u16_imm_u8, in_SUB_w_rm_mod_reg_u16_imm_u8, in_SUB_w_rm_mod_reg_u16_imm_u8, in_SUB_w_rm_mod_reg_u16_imm_u8, 
	// 30
	in_XOR_w_rm_mod_reg_u16_imm_u8, in_XOR_w_rm_mod_reg_u16_imm_u8, in_XOR_w_rm_mod_reg_u16_imm_u8, in_XOR_w_rm_mod_reg_u16_imm_u8, in_XOR_w_rm_mod_reg_u16_imm_u8, in_XOR_w_rm_mod_reg_u16_imm_u8, in_XOR_w_rm_mod_reg_u16_imm_u8, in_XOR_w_rm_mod_reg_u16_imm_u8, 
	// 38
	in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, 
	// 40
	in_ADD_w_rm_mod_reg_u16_imm_u8, in_ADD_w_rm_mod_reg_u16_imm_u8, in_ADD_w_rm_mod_reg_u16_imm_u8, in_ADD_w_rm_mod_reg_u16_imm_u8, in_ADD_w_rm_mod_reg_u16_imm_u8, in_ADD_w_rm_mod_reg_u16_imm_u8, in_ADD_w_rm_mod_reg_u16_imm_u8, in_ADD_w_rm_mod_reg_u16_imm_u8, 
	// 48
	in_OR_w_rm_mod_reg_u16_imm_u8, in_OR_w_rm_mod_reg_u16_imm_u8, in_OR_w_rm_mod_reg_u16_imm_u8, in_OR_w_rm_mod_reg_u16_imm_u8, in_OR_w_rm_mod_reg_u16_imm_u8, in_OR_w_rm_mod_reg_u16_imm_u8, in_OR_w_rm_mod_reg_u16_imm_u8, in_OR_w_rm_mod_reg_u16_imm_u8, 
	// 50
	in_ADC_w_rm_mod_reg_u16_imm_u8, in_ADC_w_rm_mod_reg_u16_imm_u8, in_ADC_w_rm_mod_reg_u16_imm_u8, in_ADC_w_rm_mod_reg_u16_imm_u8, in_ADC_w_rm_mod_reg_u16_imm_u8, in_ADC_w_rm_mod_reg_u16_imm_u8, in_ADC_w_rm_mod_reg_u16_imm_u8, in_ADC_w_rm_mod_reg_u16_imm_u8, 
	// 58
	in_SBB_w_rm_mod_reg_u16_imm_u8, in_SBB_w_rm_mod_reg_u16_imm_u8, in_SBB_w_rm_mod_reg_u16_imm_u8, in_SBB_w_rm_mod_reg_u16_imm_u8, in_SBB_w_rm_mod_reg_u16_imm_u8, in_SBB_w_rm_mod_reg_u16_imm_u8, in_SBB_w_rm_mod_reg_u16_imm_u8, in_SBB_w_rm_mod_reg_u16_imm_u8, 
	// 60
	in_AND_w_rm_mod_reg_u16_imm_u8, in_AND_w_rm_mod_reg_u16_imm_u8, in_AND_w_rm_mod_reg_u16_imm_u8, in_AND_w_rm_mod_reg_u16_imm_u8, in_AND_w_rm_mod_reg_u16_imm_u8, in_AND_w_rm_mod_reg_u16_imm_u8, in_AND_w_rm_mod_reg_u16_imm_u8, in_AND_w_rm_mod_reg_u16_imm_u8, 
	// 68
	in_SUB_w_rm_mod_reg_u16_imm_u8, in_SUB_w_rm_mod_reg_u16_imm_u8, in_SUB_w_rm_mod_reg_u16_imm_u8, in_SUB_w_rm_mod_reg_u16_imm_u8, in_SUB_w_rm_mod_reg_u16_imm_u8, in_SUB_w_rm_mod_reg_u16_imm_u8, in_SUB_w_rm_mod_reg_u16_imm_u8, in_SUB_w_rm_mod_reg_u16_imm_u8, 
	// 70
	in_XOR_w_rm_mod_reg_u16_imm_u8, in_XOR_w_rm_mod_reg_u16_imm_u8, in_XOR_w_rm_mod_reg_u16_imm_u8, in_XOR_w_rm_mod_reg_u16_imm_u8, in_XOR_w_rm_mod_reg_u16_imm_u8, in_XOR_w_rm_mod_reg_u16_imm_u8, in_XOR_w_rm_mod_reg_u16_imm_u8, in_XOR_w_rm_mod_reg_u16_imm_u8, 
	// 78
	in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, 
	// 80
	in_ADD_w_rm_mod_reg_u16_imm_u8, in_ADD_w_rm_mod_reg_u16_imm_u8, in_ADD_w_rm_mod_reg_u16_imm_u8, in_ADD_w_rm_mod_reg_u16_imm_u8, in_ADD_w_rm_mod_reg_u16_imm_u8, in_ADD_w_rm_mod_reg_u16_imm_u8, in_ADD_w_rm_mod_reg_u16_imm_u8, in_ADD_w_rm_mod_reg_u16_imm_u8, 
	// 88
	in_OR_w_rm_mod_reg_u16_imm_u8, in_OR_w_rm_mod_reg_u16_imm_u8, in_OR_w_rm_mod_reg_u16_imm_u8, in_OR_w_rm_mod_reg_u16_imm_u8, in_OR_w_rm_mod_reg_u16_imm_u8, in_OR_w_rm_mod_reg_u16_imm_u8, in_OR_w_rm_mod_reg_u16_imm_u8, in_OR_w_rm_mod_reg_u16_imm_u8, 
	// 90
	in_ADC_w_rm_mod_reg_u16_imm_u8, in_ADC_w_rm_mod_reg_u16_imm_u8, in_ADC_w_rm_mod_reg_u16_imm_u8, in_ADC_w_rm_mod_reg_u16_imm_u8, in_ADC_w_rm_mod_reg_u16_imm_u8, in_ADC_w_rm_mod_reg_u16_imm_u8, in_ADC_w_rm_mod_reg_u16_imm_u8, in_ADC_w_rm_mod_reg_u16_imm_u8, 
	// 98
	in_SBB_w_rm_mod_reg_u16_imm_u8, in_SBB_w_rm_mod_reg_u16_imm_u8, in_SBB_w_rm_mod_reg_u16_imm_u8, in_SBB_w_rm_mod_reg_u16_imm_u8, in_SBB_w_rm_mod_reg_u16_imm_u8, in_SBB_w_rm_mod_reg_u16_imm_u8, in_SBB_w_rm_mod_reg_u16_imm_u8, in_SBB_w_rm_mod_reg_u16_imm_u8, 
	// A0
	in_AND_w_rm_mod_reg_u16_imm_u8, in_AND_w_rm_mod_reg_u16_imm_u8, in_AND_w_rm_mod_reg_u16_imm_u8, in_AND_w_rm_mod_reg_u16_imm_u8, in_AND_w_rm_mod_reg_u16_imm_u8, in_AND_w_rm_mod_reg_u16_imm_u8, in_AND_w_rm_mod_reg_u16_imm_u8, in_AND_w_rm_mod_reg_u16_imm_u8, 
	// A8
	in_SUB_w_rm_mod_reg_u16_imm_u8, in_SUB_w_rm_mod_reg_u16_imm_u8, in_SUB_w_rm_mod_reg_u16_imm_u8, in_SUB_w_rm_mod_reg_u16_imm_u8, in_SUB_w_rm_mod_reg_u16_imm_u8, in_SUB_w_rm_mod_reg_u16_imm_u8, in_SUB_w_rm_mod_reg_u16_imm_u8, in_SUB_w_rm_mod_reg_u16_imm_u8, 
	// B0
	in_XOR_w_rm_mod_reg_u16_imm_u8, in_XOR_w_rm_mod_reg_u16_imm_u8, in_XOR_w_rm_mod_reg_u16_imm_u8, in_XOR_w_rm_mod_reg_u16_imm_u8, in_XOR_w_rm_mod_reg_u16_imm_u8, in_XOR_w_rm_mod_reg_u16_imm_u8, in_XOR_w_rm_mod_reg_u16_imm_u8, in_XOR_w_rm_mod_reg_u16_imm_u8, 
	// B8
	in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, 
	// C0
	in_ADD_w_rm_mod_reg_u16_imm_u8, in_ADD_w_rm_mod_reg_u16_imm_u8, in_ADD_w_rm_mod_reg_u16_imm_u8, in_ADD_w_rm_mod_reg_u16_imm_u8, in_ADD_w_rm_mod_reg_u16_imm_u8, in_ADD_w_rm_mod_reg_u16_imm_u8, in_ADD_w_rm_mod_reg_u16_imm_u8, in_ADD_w_rm_mod_reg_u16_imm_u8, 
	// C8
	in_OR_w_rm_mod_reg_u16_imm_u8, in_OR_w_rm_mod_reg_u16_imm_u8, in_OR_w_rm_mod_reg_u16_imm_u8, in_OR_w_rm_mod_reg_u16_imm_u8, in_OR_w_rm_mod_reg_u16_imm_u8, in_OR_w_rm_mod_reg_u16_imm_u8, in_OR_w_rm_mod_reg_u16_imm_u8, in_OR_w_rm_mod_reg_u16_imm_u8, 
	// D0
	in_ADC_w_rm_mod_reg_u16_imm_u8, in_ADC_w_rm_mod_reg_u16_imm_u8, in_ADC_w_rm_mod_reg_u16_imm_u8, in_ADC_w_rm_mod_reg_u16_imm_u8, in_ADC_w_rm_mod_reg_u16_imm_u8, in_ADC_w_rm_mod_reg_u16_imm_u8, in_ADC_w_rm_mod_reg_u16_imm_u8, in_ADC_w_rm_mod_reg_u16_imm_u8, 
	// D8
	in_SBB_w_rm_mod_reg_u16_imm_u8, in_SBB_w_rm_mod_reg_u16_imm_u8, in_SBB_w_rm_mod_reg_u16_imm_u8, in_SBB_w_rm_mod_reg_u16_imm_u8, in_SBB_w_rm_mod_reg_u16_imm_u8, in_SBB_w_rm_mod_reg_u16_imm_u8, in_SBB_w_rm_mod_reg_u16_imm_u8, in_SBB_w_rm_mod_reg_u16_imm_u8, 
	// E0
	in_AND_w_rm_mod_reg_u16_imm_u8, in_AND_w_rm_mod_reg_u16_imm_u8, in_AND_w_rm_mod_reg_u16_imm_u8, in_AND_w_rm_mod_reg_u16_imm_u8, in_AND_w_rm_mod_reg_u16_imm_u8, in_AND_w_rm_mod_reg_u16_imm_u8, in_AND_w_rm_mod_reg_u16_imm_u8, in_AND_w_rm_mod_reg_u16_imm_u8, 
	// E8
	in_SUB_w_rm_mod_reg_u16_imm_u8, in_SUB_w_rm_mod_reg_u16_imm_u8, in_SUB_w_rm_mod_reg_u16_imm_u8, in_SUB_w_rm_mod_reg_u16_imm_u8, in_SUB_w_rm_mod_reg_u16_imm_u8, in_SUB_w_rm_mod_reg_u16_imm_u8, in_SUB_w_rm_mod_reg_u16_imm_u8, in_SUB_w_rm_mod_reg_u16_imm_u8, 
	// F0
	in_XOR_w_rm_mod_reg_u16_imm_u8, in_XOR_w_rm_mod_reg_u16_imm_u8, in_XOR_w_rm_mod_reg_u16_imm_u8, in_XOR_w_rm_mod_reg_u16_imm_u8, in_XOR_w_rm_mod_reg_u16_imm_u8, in_XOR_w_rm_mod_reg_u16_imm_u8, in_XOR_w_rm_mod_reg_u16_imm_u8, in_XOR_w_rm_mod_reg_u16_imm_u8, 
	// F8
	in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, 
};
const OpState CpuRunnerX86::table_st_w_d_83[] = {
	// 00
	in_ADD_w_rm_mod_reg_u32_imm_u8, in_ADD_w_rm_mod_reg_u32_imm_u8, in_ADD_w_rm_mod_reg_u32_imm_u8, in_ADD_w_rm_mod_reg_u32_imm_u8, in_ADD_w_rm_mod_reg_u32_imm_u8, in_ADD_w_rm_mod_reg_u32_imm_u8, in_ADD_w_rm_mod_reg_u32_imm_u8, in_ADD_w_rm_mod_reg_u32_imm_u8, 
	// 08
	in_OR_w_rm_mod_reg_u32_imm_u8, in_OR_w_rm_mod_reg_u32_imm_u8, in_OR_w_rm_mod_reg_u32_imm_u8, in_OR_w_rm_mod_reg_u32_imm_u8, in_OR_w_rm_mod_reg_u32_imm_u8, in_OR_w_rm_mod_reg_u32_imm_u8, in_OR_w_rm_mod_reg_u32_imm_u8, in_OR_w_rm_mod_reg_u32_imm_u8, 
	// 10
	in_ADC_w_rm_mod_reg_u32_imm_u8, in_ADC_w_rm_mod_reg_u32_imm_u8, in_ADC_w_rm_mod_reg_u32_imm_u8, in_ADC_w_rm_mod_reg_u32_imm_u8, in_ADC_w_rm_mod_reg_u32_imm_u8, in_ADC_w_rm_mod_reg_u32_imm_u8, in_ADC_w_rm_mod_reg_u32_imm_u8, in_ADC_w_rm_mod_reg_u32_imm_u8, 
	// 18
	in_SBB_w_rm_mod_reg_u32_imm_u8, in_SBB_w_rm_mod_reg_u32_imm_u8, in_SBB_w_rm_mod_reg_u32_imm_u8, in_SBB_w_rm_mod_reg_u32_imm_u8, in_SBB_w_rm_mod_reg_u32_imm_u8, in_SBB_w_rm_mod_reg_u32_imm_u8, in_SBB_w_rm_mod_reg_u32_imm_u8, in_SBB_w_rm_mod_reg_u32_imm_u8, 
	// 20
	in_AND_w_rm_mod_reg_u32_imm_u8, in_AND_w_rm_mod_reg_u32_imm_u8, in_AND_w_rm_mod_reg_u32_imm_u8, in_AND_w_rm_mod_reg_u32_imm_u8, in_AND_w_rm_mod_reg_u32_imm_u8, in_AND_w_rm_mod_reg_u32_imm_u8, in_AND_w_rm_mod_reg_u32_imm_u8, in_AND_w_rm_mod_reg_u32_imm_u8, 
	// 28
	in_SUB_w_rm_mod_reg_u32_imm_u8, in_SUB_w_rm_mod_reg_u32_imm_u8, in_SUB_w_rm_mod_reg_u32_imm_u8, in_SUB_w_rm_mod_reg_u32_imm_u8, in_SUB_w_rm_mod_reg_u32_imm_u8, in_SUB_w_rm_mod_reg_u32_imm_u8, in_SUB_w_rm_mod_reg_u32_imm_u8, in_SUB_w_rm_mod_reg_u32_imm_u8, 
	// 30
	in_XOR_w_rm_mod_reg_u32_imm_u8, in_XOR_w_rm_mod_reg_u32_imm_u8, in_XOR_w_rm_mod_reg_u32_imm_u8, in_XOR_w_rm_mod_reg_u32_imm_u8, in_XOR_w_rm_mod_reg_u32_imm_u8, in_XOR_w_rm_mod_reg_u32_imm_u8, in_XOR_w_rm_mod_reg_u32_imm_u8, in_XOR_w_rm_mod_reg_u32_imm_u8, 
	// 38
	in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, 
	// 40
	in_ADD_w_rm_mod_reg_u32_imm_u8, in_ADD_w_rm_mod_reg_u32_imm_u8, in_ADD_w_rm_mod_reg_u32_imm_u8, in_ADD_w_rm_mod_reg_u32_imm_u8, in_ADD_w_rm_mod_reg_u32_imm_u8, in_ADD_w_rm_mod_reg_u32_imm_u8, in_ADD_w_rm_mod_reg_u32_imm_u8, in_ADD_w_rm_mod_reg_u32_imm_u8, 
	// 48
	in_OR_w_rm_mod_reg_u32_imm_u8, in_OR_w_rm_mod_reg_u32_imm_u8, in_OR_w_rm_mod_reg_u32_imm_u8, in_OR_w_rm_mod_reg_u32_imm_u8, in_OR_w_rm_mod_reg_u32_imm_u8, in_OR_w_rm_mod_reg_u32_imm_u8, in_OR_w_rm_mod_reg_u32_imm_u8, in_OR_w_rm_mod_reg_u32_imm_u8, 
	// 50
	in_ADC_w_rm_mod_reg_u32_imm_u8, in_ADC_w_rm_mod_reg_u32_imm_u8, in_ADC_w_rm_mod_reg_u32_imm_u8, in_ADC_w_rm_mod_reg_u32_imm_u8, in_ADC_w_rm_mod_reg_u32_imm_u8, in_ADC_w_rm_mod_reg_u32_imm_u8, in_ADC_w_rm_mod_reg_u32_imm_u8, in_ADC_w_rm_mod_reg_u32_imm_u8, 
	// 58
	in_SBB_w_rm_mod_reg_u32_imm_u8, in_SBB_w_rm_mod_reg_u32_imm_u8, in_SBB_w_rm_mod_reg_u32_imm_u8, in_SBB_w_rm_mod_reg_u32_imm_u8, in_SBB_w_rm_mod_reg_u32_imm_u8, in_SBB_w_rm_mod_reg_u32_imm_u8, in_SBB_w_rm_mod_reg_u32_imm_u8, in_SBB_w_rm_mod_reg_u32_imm_u8, 
	// 60
	in_AND_w_rm_mod_reg_u32_imm_u8, in_AND_w_rm_mod_reg_u32_imm_u8, in_AND_w_rm_mod_reg_u32_imm_u8, in_AND_w_rm_mod_reg_u32_imm_u8, in_AND_w_rm_mod_reg_u32_imm_u8, in_AND_w_rm_mod_reg_u32_imm_u8, in_AND_w_rm_mod_reg_u32_imm_u8, in_AND_w_rm_mod_reg_u32_imm_u8, 
	// 68
	in_SUB_w_rm_mod_reg_u32_imm_u8, in_SUB_w_rm_mod_reg_u32_imm_u8, in_SUB_w_rm_mod_reg_u32_imm_u8, in_SUB_w_rm_mod_reg_u32_imm_u8, in_SUB_w_rm_mod_reg_u32_imm_u8, in_SUB_w_rm_mod_reg_u32_imm_u8, in_SUB_w_rm_mod_reg_u32_imm_u8, in_SUB_w_rm_mod_reg_u32_imm_u8, 
	// 70
	in_XOR_w_rm_mod_reg_u32_imm_u8, in_XOR_w_rm_mod_reg_u32_imm_u8, in_XOR_w_rm_mod_reg_u32_imm_u8, in_XOR_w_rm_mod_reg_u32_imm_u8, in_XOR_w_rm_mod_reg_u32_imm_u8, in_XOR_w_rm_mod_reg_u32_imm_u8, in_XOR_w_rm_mod_reg_u32_imm_u8, in_XOR_w_rm_mod_reg_u32_imm_u8, 
	// 78
	in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, 
	// 80
	in_ADD_w_rm_mod_reg_u32_imm_u8, in_ADD_w_rm_mod_reg_u32_imm_u8, in_ADD_w_rm_mod_reg_u32_imm_u8, in_ADD_w_rm_mod_reg_u32_imm_u8, in_ADD_w_rm_mod_reg_u32_imm_u8, in_ADD_w_rm_mod_reg_u32_imm_u8, in_ADD_w_rm_mod_reg_u32_imm_u8, in_ADD_w_rm_mod_reg_u32_imm_u8, 
	// 88
	in_OR_w_rm_mod_reg_u32_imm_u8, in_OR_w_rm_mod_reg_u32_imm_u8, in_OR_w_rm_mod_reg_u32_imm_u8, in_OR_w_rm_mod_reg_u32_imm_u8, in_OR_w_rm_mod_reg_u32_imm_u8, in_OR_w_rm_mod_reg_u32_imm_u8, in_OR_w_rm_mod_reg_u32_imm_u8, in_OR_w_rm_mod_reg_u32_imm_u8, 
	// 90
	in_ADC_w_rm_mod_reg_u32_imm_u8, in_ADC_w_rm_mod_reg_u32_imm_u8, in_ADC_w_rm_mod_reg_u32_imm_u8, in_ADC_w_rm_mod_reg_u32_imm_u8, in_ADC_w_rm_mod_reg_u32_imm_u8, in_ADC_w_rm_mod_reg_u32_imm_u8, in_ADC_w_rm_mod_reg_u32_imm_u8, in_ADC_w_rm_mod_reg_u32_imm_u8, 
	// 98
	in_SBB_w_rm_mod_reg_u32_imm_u8, in_SBB_w_rm_mod_reg_u32_imm_u8, in_SBB_w_rm_mod_reg_u32_imm_u8, in_SBB_w_rm_mod_reg_u32_imm_u8, in_SBB_w_rm_mod_reg_u32_imm_u8, in_SBB_w_rm_mod_reg_u32_imm_u8, in_SBB_w_rm_mod_reg_u32_imm_u8, in_SBB_w_rm_mod_reg_u32_imm_u8, 
	// A0
	in_AND_w_rm_mod_reg_u32_imm_u8, in_AND_w_rm_mod_reg_u32_imm_u8, in_AND_w_rm_mod_reg_u32_imm_u8, in_AND_w_rm_mod_reg_u32_imm_u8, in_AND_w_rm_mod_reg_u32_imm_u8, in_AND_w_rm_mod_reg_u32_imm_u8, in_AND_w_rm_mod_reg_u32_imm_u8, in_AND_w_rm_mod_reg_u32_imm_u8, 
	// A8
	in_SUB_w_rm_mod_reg_u32_imm_u8, in_SUB_w_rm_mod_reg_u32_imm_u8, in_SUB_w_rm_mod_reg_u32_imm_u8, in_SUB_w_rm_mod_reg_u32_imm_u8, in_SUB_w_rm_mod_reg_u32_imm_u8, in_SUB_w_rm_mod_reg_u32_imm_u8, in_SUB_w_rm_mod_reg_u32_imm_u8, in_SUB_w_rm_mod_reg_u32_imm_u8, 
	// B0
	in_XOR_w_rm_mod_reg_u32_imm_u8, in_XOR_w_rm_mod_reg_u32_imm_u8, in_XOR_w_rm_mod_reg_u32_imm_u8, in_XOR_w_rm_mod_reg_u32_imm_u8, in_XOR_w_rm_mod_reg_u32_imm_u8, in_XOR_w_rm_mod_reg_u32_imm_u8, in_XOR_w_rm_mod_reg_u32_imm_u8, in_XOR_w_rm_mod_reg_u32_imm_u8, 
	// B8
	in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, 
	// C0
	in_ADD_w_rm_mod_reg_u32_imm_u8, in_ADD_w_rm_mod_reg_u32_imm_u8, in_ADD_w_rm_mod_reg_u32_imm_u8, in_ADD_w_rm_mod_reg_u32_imm_u8, in_ADD_w_rm_mod_reg_u32_imm_u8, in_ADD_w_rm_mod_reg_u32_imm_u8, in_ADD_w_rm_mod_reg_u32_imm_u8, in_ADD_w_rm_mod_reg_u32_imm_u8, 
	// C8
	in_OR_w_rm_mod_reg_u32_imm_u8, in_OR_w_rm_mod_reg_u32_imm_u8, in_OR_w_rm_mod_reg_u32_imm_u8, in_OR_w_rm_mod_reg_u32_imm_u8, in_OR_w_rm_mod_reg_u32_imm_u8, in_OR_w_rm_mod_reg_u32_imm_u8, in_OR_w_rm_mod_reg_u32_imm_u8, in_OR_w_rm_mod_reg_u32_imm_u8, 
	// D0
	in_ADC_w_rm_mod_reg_u32_imm_u8, in_ADC_w_rm_mod_reg_u32_imm_u8, in_ADC_w_rm_mod_reg_u32_imm_u8, in_ADC_w_rm_mod_reg_u32_imm_u8, in_ADC_w_rm_mod_reg_u32_imm_u8, in_ADC_w_rm_mod_reg_u32_imm_u8, in_ADC_w_rm_mod_reg_u32_imm_u8, in_ADC_w_rm_mod_reg_u32_imm_u8, 
	// D8
	in_SBB_w_rm_mod_reg_u32_imm_u8, in_SBB_w_rm_mod_reg_u32_imm_u8, in_SBB_w_rm_mod_reg_u32_imm_u8, in_SBB_w_rm_mod_reg_u32_imm_u8, in_SBB_w_rm_mod_reg_u32_imm_u8, in_SBB_w_rm_mod_reg_u32_imm_u8, in_SBB_w_rm_mod_reg_u32_imm_u8, in_SBB_w_rm_mod_reg_u32_imm_u8, 
	// E0
	in_AND_w_rm_mod_reg_u32_imm_u8, in_AND_w_rm_mod_reg_u32_imm_u8, in_AND_w_rm_mod_reg_u32_imm_u8, in_AND_w_rm_mod_reg_u32_imm_u8, in_AND_w_rm_mod_reg_u32_imm_u8, in_AND_w_rm_mod_reg_u32_imm_u8, in_AND_w_rm_mod_reg_u32_imm_u8, in_AND_w_rm_mod_reg_u32_imm_u8, 
	// E8
	in_SUB_w_rm_mod_reg_u32_imm_u8, in_SUB_w_rm_mod_reg_u32_imm_u8, in_SUB_w_rm_mod_reg_u32_imm_u8, in_SUB_w_rm_mod_reg_u32_imm_u8, in_SUB_w_rm_mod_reg_u32_imm_u8, in_SUB_w_rm_mod_reg_u32_imm_u8, in_SUB_w_rm_mod_reg_u32_imm_u8, in_SUB_w_rm_mod_reg_u32_imm_u8, 
	// F0
	in_XOR_w_rm_mod_reg_u32_imm_u8, in_XOR_w_rm_mod_reg_u32_imm_u8, in_XOR_w_rm_mod_reg_u32_imm_u8, in_XOR_w_rm_mod_reg_u32_imm_u8, in_XOR_w_rm_mod_reg_u32_imm_u8, in_XOR_w_rm_mod_reg_u32_imm_u8, in_XOR_w_rm_mod_reg_u32_imm_u8, in_XOR_w_rm_mod_reg_u32_imm_u8, 
	// F8
	in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, in_CMP_w_imm_u8, 
};
const OpState CpuRunnerX86::table_st_d_w_83[] = {
	// 00
	in_ADD_d_rm_mod_reg_u16_imm_u8, in_ADD_d_rm_mod_reg_u16_imm_u8, in_ADD_d_rm_mod_reg_u16_imm_u8, in_ADD_d_rm_mod_reg_u16_imm_u8, in_ADD_d_rm_mod_reg_u16_imm_u8, in_ADD_d_rm_mod_reg_u16_imm_u8, in_ADD_d_rm_mod_reg_u16_imm_u8, in_ADD_d_rm_mod_reg_u16_imm_u8, 
	// 08
	in_OR_d_rm_mod_reg_u16_imm_u8, in_OR_d_rm_mod_reg_u16_imm_u8, in_OR_d_rm_mod_reg_u16_imm_u8, in_OR_d_rm_mod_reg_u16_imm_u8, in_OR_d_rm_mod_reg_u16_imm_u8, in_OR_d_rm_mod_reg_u16_imm_u8, in_OR_d_rm_mod_reg_u16_imm_u8, in_OR_d_rm_mod_reg_u16_imm_u8, 
	// 10
	in_ADC_d_rm_mod_reg_u16_imm_u8, in_ADC_d_rm_mod_reg_u16_imm_u8, in_ADC_d_rm_mod_reg_u16_imm_u8, in_ADC_d_rm_mod_reg_u16_imm_u8, in_ADC_d_rm_mod_reg_u16_imm_u8, in_ADC_d_rm_mod_reg_u16_imm_u8, in_ADC_d_rm_mod_reg_u16_imm_u8, in_ADC_d_rm_mod_reg_u16_imm_u8, 
	// 18
	in_SBB_d_rm_mod_reg_u16_imm_u8, in_SBB_d_rm_mod_reg_u16_imm_u8, in_SBB_d_rm_mod_reg_u16_imm_u8, in_SBB_d_rm_mod_reg_u16_imm_u8, in_SBB_d_rm_mod_reg_u16_imm_u8, in_SBB_d_rm_mod_reg_u16_imm_u8, in_SBB_d_rm_mod_reg_u16_imm_u8, in_SBB_d_rm_mod_reg_u16_imm_u8, 
	// 20
	in_AND_d_rm_mod_reg_u16_imm_u8, in_AND_d_rm_mod_reg_u16_imm_u8, in_AND_d_rm_mod_reg_u16_imm_u8, in_AND_d_rm_mod_reg_u16_imm_u8, in_AND_d_rm_mod_reg_u16_imm_u8, in_AND_d_rm_mod_reg_u16_imm_u8, in_AND_d_rm_mod_reg_u16_imm_u8, in_AND_d_rm_mod_reg_u16_imm_u8, 
	// 28
	in_SUB_d_rm_mod_reg_u16_imm_u8, in_SUB_d_rm_mod_reg_u16_imm_u8, in_SUB_d_rm_mod_reg_u16_imm_u8, in_SUB_d_rm_mod_reg_u16_imm_u8, in_SUB_d_rm_mod_reg_u16_imm_u8, in_SUB_d_rm_mod_reg_u16_imm_u8, in_SUB_d_rm_mod_reg_u16_imm_u8, in_SUB_d_rm_mod_reg_u16_imm_u8, 
	// 30
	in_XOR_d_rm_mod_reg_u16_imm_u8, in_XOR_d_rm_mod_reg_u16_imm_u8, in_XOR_d_rm_mod_reg_u16_imm_u8, in_XOR_d_rm_mod_reg_u16_imm_u8, in_XOR_d_rm_mod_reg_u16_imm_u8, in_XOR_d_rm_mod_reg_u16_imm_u8, in_XOR_d_rm_mod_reg_u16_imm_u8, in_XOR_d_rm_mod_reg_u16_imm_u8, 
	// 38
	in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, 
	// 40
	in_ADD_d_rm_mod_reg_u16_imm_u8, in_ADD_d_rm_mod_reg_u16_imm_u8, in_ADD_d_rm_mod_reg_u16_imm_u8, in_ADD_d_rm_mod_reg_u16_imm_u8, in_ADD_d_rm_mod_reg_u16_imm_u8, in_ADD_d_rm_mod_reg_u16_imm_u8, in_ADD_d_rm_mod_reg_u16_imm_u8, in_ADD_d_rm_mod_reg_u16_imm_u8, 
	// 48
	in_OR_d_rm_mod_reg_u16_imm_u8, in_OR_d_rm_mod_reg_u16_imm_u8, in_OR_d_rm_mod_reg_u16_imm_u8, in_OR_d_rm_mod_reg_u16_imm_u8, in_OR_d_rm_mod_reg_u16_imm_u8, in_OR_d_rm_mod_reg_u16_imm_u8, in_OR_d_rm_mod_reg_u16_imm_u8, in_OR_d_rm_mod_reg_u16_imm_u8, 
	// 50
	in_ADC_d_rm_mod_reg_u16_imm_u8, in_ADC_d_rm_mod_reg_u16_imm_u8, in_ADC_d_rm_mod_reg_u16_imm_u8, in_ADC_d_rm_mod_reg_u16_imm_u8, in_ADC_d_rm_mod_reg_u16_imm_u8, in_ADC_d_rm_mod_reg_u16_imm_u8, in_ADC_d_rm_mod_reg_u16_imm_u8, in_ADC_d_rm_mod_reg_u16_imm_u8, 
	// 58
	in_SBB_d_rm_mod_reg_u16_imm_u8, in_SBB_d_rm_mod_reg_u16_imm_u8, in_SBB_d_rm_mod_reg_u16_imm_u8, in_SBB_d_rm_mod_reg_u16_imm_u8, in_SBB_d_rm_mod_reg_u16_imm_u8, in_SBB_d_rm_mod_reg_u16_imm_u8, in_SBB_d_rm_mod_reg_u16_imm_u8, in_SBB_d_rm_mod_reg_u16_imm_u8, 
	// 60
	in_AND_d_rm_mod_reg_u16_imm_u8, in_AND_d_rm_mod_reg_u16_imm_u8, in_AND_d_rm_mod_reg_u16_imm_u8, in_AND_d_rm_mod_reg_u16_imm_u8, in_AND_d_rm_mod_reg_u16_imm_u8, in_AND_d_rm_mod_reg_u16_imm_u8, in_AND_d_rm_mod_reg_u16_imm_u8, in_AND_d_rm_mod_reg_u16_imm_u8, 
	// 68
	in_SUB_d_rm_mod_reg_u16_imm_u8, in_SUB_d_rm_mod_reg_u16_imm_u8, in_SUB_d_rm_mod_reg_u16_imm_u8, in_SUB_d_rm_mod_reg_u16_imm_u8, in_SUB_d_rm_mod_reg_u16_imm_u8, in_SUB_d_rm_mod_reg_u16_imm_u8, in_SUB_d_rm_mod_reg_u16_imm_u8, in_SUB_d_rm_mod_reg_u16_imm_u8, 
	// 70
	in_XOR_d_rm_mod_reg_u16_imm_u8, in_XOR_d_rm_mod_reg_u16_imm_u8, in_XOR_d_rm_mod_reg_u16_imm_u8, in_XOR_d_rm_mod_reg_u16_imm_u8, in_XOR_d_rm_mod_reg_u16_imm_u8, in_XOR_d_rm_mod_reg_u16_imm_u8, in_XOR_d_rm_mod_reg_u16_imm_u8, in_XOR_d_rm_mod_reg_u16_imm_u8, 
	// 78
	in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, 
	// 80
	in_ADD_d_rm_mod_reg_u16_imm_u8, in_ADD_d_rm_mod_reg_u16_imm_u8, in_ADD_d_rm_mod_reg_u16_imm_u8, in_ADD_d_rm_mod_reg_u16_imm_u8, in_ADD_d_rm_mod_reg_u16_imm_u8, in_ADD_d_rm_mod_reg_u16_imm_u8, in_ADD_d_rm_mod_reg_u16_imm_u8, in_ADD_d_rm_mod_reg_u16_imm_u8, 
	// 88
	in_OR_d_rm_mod_reg_u16_imm_u8, in_OR_d_rm_mod_reg_u16_imm_u8, in_OR_d_rm_mod_reg_u16_imm_u8, in_OR_d_rm_mod_reg_u16_imm_u8, in_OR_d_rm_mod_reg_u16_imm_u8, in_OR_d_rm_mod_reg_u16_imm_u8, in_OR_d_rm_mod_reg_u16_imm_u8, in_OR_d_rm_mod_reg_u16_imm_u8, 
	// 90
	in_ADC_d_rm_mod_reg_u16_imm_u8, in_ADC_d_rm_mod_reg_u16_imm_u8, in_ADC_d_rm_mod_reg_u16_imm_u8, in_ADC_d_rm_mod_reg_u16_imm_u8, in_ADC_d_rm_mod_reg_u16_imm_u8, in_ADC_d_rm_mod_reg_u16_imm_u8, in_ADC_d_rm_mod_reg_u16_imm_u8, in_ADC_d_rm_mod_reg_u16_imm_u8, 
	// 98
	in_SBB_d_rm_mod_reg_u16_imm_u8, in_SBB_d_rm_mod_reg_u16_imm_u8, in_SBB_d_rm_mod_reg_u16_imm_u8, in_SBB_d_rm_mod_reg_u16_imm_u8, in_SBB_d_rm_mod_reg_u16_imm_u8, in_SBB_d_rm_mod_reg_u16_imm_u8, in_SBB_d_rm_mod_reg_u16_imm_u8, in_SBB_d_rm_mod_reg_u16_imm_u8, 
	// A0
	in_AND_d_rm_mod_reg_u16_imm_u8, in_AND_d_rm_mod_reg_u16_imm_u8, in_AND_d_rm_mod_reg_u16_imm_u8, in_AND_d_rm_mod_reg_u16_imm_u8, in_AND_d_rm_mod_reg_u16_imm_u8, in_AND_d_rm_mod_reg_u16_imm_u8, in_AND_d_rm_mod_reg_u16_imm_u8, in_AND_d_rm_mod_reg_u16_imm_u8, 
	// A8
	in_SUB_d_rm_mod_reg_u16_imm_u8, in_SUB_d_rm_mod_reg_u16_imm_u8, in_SUB_d_rm_mod_reg_u16_imm_u8, in_SUB_d_rm_mod_reg_u16_imm_u8, in_SUB_d_rm_mod_reg_u16_imm_u8, in_SUB_d_rm_mod_reg_u16_imm_u8, in_SUB_d_rm_mod_reg_u16_imm_u8, in_SUB_d_rm_mod_reg_u16_imm_u8, 
	// B0
	in_XOR_d_rm_mod_reg_u16_imm_u8, in_XOR_d_rm_mod_reg_u16_imm_u8, in_XOR_d_rm_mod_reg_u16_imm_u8, in_XOR_d_rm_mod_reg_u16_imm_u8, in_XOR_d_rm_mod_reg_u16_imm_u8, in_XOR_d_rm_mod_reg_u16_imm_u8, in_XOR_d_rm_mod_reg_u16_imm_u8, in_XOR_d_rm_mod_reg_u16_imm_u8, 
	// B8
	in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, 
	// C0
	in_ADD_d_rm_mod_reg_u16_imm_u8, in_ADD_d_rm_mod_reg_u16_imm_u8, in_ADD_d_rm_mod_reg_u16_imm_u8, in_ADD_d_rm_mod_reg_u16_imm_u8, in_ADD_d_rm_mod_reg_u16_imm_u8, in_ADD_d_rm_mod_reg_u16_imm_u8, in_ADD_d_rm_mod_reg_u16_imm_u8, in_ADD_d_rm_mod_reg_u16_imm_u8, 
	// C8
	in_OR_d_rm_mod_reg_u16_imm_u8, in_OR_d_rm_mod_reg_u16_imm_u8, in_OR_d_rm_mod_reg_u16_imm_u8, in_OR_d_rm_mod_reg_u16_imm_u8, in_OR_d_rm_mod_reg_u16_imm_u8, in_OR_d_rm_mod_reg_u16_imm_u8, in_OR_d_rm_mod_reg_u16_imm_u8, in_OR_d_rm_mod_reg_u16_imm_u8, 
	// D0
	in_ADC_d_rm_mod_reg_u16_imm_u8, in_ADC_d_rm_mod_reg_u16_imm_u8, in_ADC_d_rm_mod_reg_u16_imm_u8, in_ADC_d_rm_mod_reg_u16_imm_u8, in_ADC_d_rm_mod_reg_u16_imm_u8, in_ADC_d_rm_mod_reg_u16_imm_u8, in_ADC_d_rm_mod_reg_u16_imm_u8, in_ADC_d_rm_mod_reg_u16_imm_u8, 
	// D8
	in_SBB_d_rm_mod_reg_u16_imm_u8, in_SBB_d_rm_mod_reg_u16_imm_u8, in_SBB_d_rm_mod_reg_u16_imm_u8, in_SBB_d_rm_mod_reg_u16_imm_u8, in_SBB_d_rm_mod_reg_u16_imm_u8, in_SBB_d_rm_mod_reg_u16_imm_u8, in_SBB_d_rm_mod_reg_u16_imm_u8, in_SBB_d_rm_mod_reg_u16_imm_u8, 
	// E0
	in_AND_d_rm_mod_reg_u16_imm_u8, in_AND_d_rm_mod_reg_u16_imm_u8, in_AND_d_rm_mod_reg_u16_imm_u8, in_AND_d_rm_mod_reg_u16_imm_u8, in_AND_d_rm_mod_reg_u16_imm_u8, in_AND_d_rm_mod_reg_u16_imm_u8, in_AND_d_rm_mod_reg_u16_imm_u8, in_AND_d_rm_mod_reg_u16_imm_u8, 
	// E8
	in_SUB_d_rm_mod_reg_u16_imm_u8, in_SUB_d_rm_mod_reg_u16_imm_u8, in_SUB_d_rm_mod_reg_u16_imm_u8, in_SUB_d_rm_mod_reg_u16_imm_u8, in_SUB_d_rm_mod_reg_u16_imm_u8, in_SUB_d_rm_mod_reg_u16_imm_u8, in_SUB_d_rm_mod_reg_u16_imm_u8, in_SUB_d_rm_mod_reg_u16_imm_u8, 
	// F0
	in_XOR_d_rm_mod_reg_u16_imm_u8, in_XOR_d_rm_mod_reg_u16_imm_u8, in_XOR_d_rm_mod_reg_u16_imm_u8, in_XOR_d_rm_mod_reg_u16_imm_u8, in_XOR_d_rm_mod_reg_u16_imm_u8, in_XOR_d_rm_mod_reg_u16_imm_u8, in_XOR_d_rm_mod_reg_u16_imm_u8, in_XOR_d_rm_mod_reg_u16_imm_u8, 
	// F8
	in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, 
};
const OpState CpuRunnerX86::table_st_d_d_83[] = {
	// 00
	in_ADD_d_rm_mod_reg_u32_imm_u8, in_ADD_d_rm_mod_reg_u32_imm_u8, in_ADD_d_rm_mod_reg_u32_imm_u8, in_ADD_d_rm_mod_reg_u32_imm_u8, in_ADD_d_rm_mod_reg_u32_imm_u8, in_ADD_d_rm_mod_reg_u32_imm_u8, in_ADD_d_rm_mod_reg_u32_imm_u8, in_ADD_d_rm_mod_reg_u32_imm_u8, 
	// 08
	in_OR_d_rm_mod_reg_u32_imm_u8, in_OR_d_rm_mod_reg_u32_imm_u8, in_OR_d_rm_mod_reg_u32_imm_u8, in_OR_d_rm_mod_reg_u32_imm_u8, in_OR_d_rm_mod_reg_u32_imm_u8, in_OR_d_rm_mod_reg_u32_imm_u8, in_OR_d_rm_mod_reg_u32_imm_u8, in_OR_d_rm_mod_reg_u32_imm_u8, 
	// 10
	in_ADC_d_rm_mod_reg_u32_imm_u8, in_ADC_d_rm_mod_reg_u32_imm_u8, in_ADC_d_rm_mod_reg_u32_imm_u8, in_ADC_d_rm_mod_reg_u32_imm_u8, in_ADC_d_rm_mod_reg_u32_imm_u8, in_ADC_d_rm_mod_reg_u32_imm_u8, in_ADC_d_rm_mod_reg_u32_imm_u8, in_ADC_d_rm_mod_reg_u32_imm_u8, 
	// 18
	in_SBB_d_rm_mod_reg_u32_imm_u8, in_SBB_d_rm_mod_reg_u32_imm_u8, in_SBB_d_rm_mod_reg_u32_imm_u8, in_SBB_d_rm_mod_reg_u32_imm_u8, in_SBB_d_rm_mod_reg_u32_imm_u8, in_SBB_d_rm_mod_reg_u32_imm_u8, in_SBB_d_rm_mod_reg_u32_imm_u8, in_SBB_d_rm_mod_reg_u32_imm_u8, 
	// 20
	in_AND_d_rm_mod_reg_u32_imm_u8, in_AND_d_rm_mod_reg_u32_imm_u8, in_AND_d_rm_mod_reg_u32_imm_u8, in_AND_d_rm_mod_reg_u32_imm_u8, in_AND_d_rm_mod_reg_u32_imm_u8, in_AND_d_rm_mod_reg_u32_imm_u8, in_AND_d_rm_mod_reg_u32_imm_u8, in_AND_d_rm_mod_reg_u32_imm_u8, 
	// 28
	in_SUB_d_rm_mod_reg_u32_imm_u8, in_SUB_d_rm_mod_reg_u32_imm_u8, in_SUB_d_rm_mod_reg_u32_imm_u8, in_SUB_d_rm_mod_reg_u32_imm_u8, in_SUB_d_rm_mod_reg_u32_imm_u8, in_SUB_d_rm_mod_reg_u32_imm_u8, in_SUB_d_rm_mod_reg_u32_imm_u8, in_SUB_d_rm_mod_reg_u32_imm_u8, 
	// 30
	in_XOR_d_rm_mod_reg_u32_imm_u8, in_XOR_d_rm_mod_reg_u32_imm_u8, in_XOR_d_rm_mod_reg_u32_imm_u8, in_XOR_d_rm_mod_reg_u32_imm_u8, in_XOR_d_rm_mod_reg_u32_imm_u8, in_XOR_d_rm_mod_reg_u32_imm_u8, in_XOR_d_rm_mod_reg_u32_imm_u8, in_XOR_d_rm_mod_reg_u32_imm_u8, 
	// 38
	in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, 
	// 40
	in_ADD_d_rm_mod_reg_u32_imm_u8, in_ADD_d_rm_mod_reg_u32_imm_u8, in_ADD_d_rm_mod_reg_u32_imm_u8, in_ADD_d_rm_mod_reg_u32_imm_u8, in_ADD_d_rm_mod_reg_u32_imm_u8, in_ADD_d_rm_mod_reg_u32_imm_u8, in_ADD_d_rm_mod_reg_u32_imm_u8, in_ADD_d_rm_mod_reg_u32_imm_u8, 
	// 48
	in_OR_d_rm_mod_reg_u32_imm_u8, in_OR_d_rm_mod_reg_u32_imm_u8, in_OR_d_rm_mod_reg_u32_imm_u8, in_OR_d_rm_mod_reg_u32_imm_u8, in_OR_d_rm_mod_reg_u32_imm_u8, in_OR_d_rm_mod_reg_u32_imm_u8, in_OR_d_rm_mod_reg_u32_imm_u8, in_OR_d_rm_mod_reg_u32_imm_u8, 
	// 50
	in_ADC_d_rm_mod_reg_u32_imm_u8, in_ADC_d_rm_mod_reg_u32_imm_u8, in_ADC_d_rm_mod_reg_u32_imm_u8, in_ADC_d_rm_mod_reg_u32_imm_u8, in_ADC_d_rm_mod_reg_u32_imm_u8, in_ADC_d_rm_mod_reg_u32_imm_u8, in_ADC_d_rm_mod_reg_u32_imm_u8, in_ADC_d_rm_mod_reg_u32_imm_u8, 
	// 58
	in_SBB_d_rm_mod_reg_u32_imm_u8, in_SBB_d_rm_mod_reg_u32_imm_u8, in_SBB_d_rm_mod_reg_u32_imm_u8, in_SBB_d_rm_mod_reg_u32_imm_u8, in_SBB_d_rm_mod_reg_u32_imm_u8, in_SBB_d_rm_mod_reg_u32_imm_u8, in_SBB_d_rm_mod_reg_u32_imm_u8, in_SBB_d_rm_mod_reg_u32_imm_u8, 
	// 60
	in_AND_d_rm_mod_reg_u32_imm_u8, in_AND_d_rm_mod_reg_u32_imm_u8, in_AND_d_rm_mod_reg_u32_imm_u8, in_AND_d_rm_mod_reg_u32_imm_u8, in_AND_d_rm_mod_reg_u32_imm_u8, in_AND_d_rm_mod_reg_u32_imm_u8, in_AND_d_rm_mod_reg_u32_imm_u8, in_AND_d_rm_mod_reg_u32_imm_u8, 
	// 68
	in_SUB_d_rm_mod_reg_u32_imm_u8, in_SUB_d_rm_mod_reg_u32_imm_u8, in_SUB_d_rm_mod_reg_u32_imm_u8, in_SUB_d_rm_mod_reg_u32_imm_u8, in_SUB_d_rm_mod_reg_u32_imm_u8, in_SUB_d_rm_mod_reg_u32_imm_u8, in_SUB_d_rm_mod_reg_u32_imm_u8, in_SUB_d_rm_mod_reg_u32_imm_u8, 
	// 70
	in_XOR_d_rm_mod_reg_u32_imm_u8, in_XOR_d_rm_mod_reg_u32_imm_u8, in_XOR_d_rm_mod_reg_u32_imm_u8, in_XOR_d_rm_mod_reg_u32_imm_u8, in_XOR_d_rm_mod_reg_u32_imm_u8, in_XOR_d_rm_mod_reg_u32_imm_u8, in_XOR_d_rm_mod_reg_u32_imm_u8, in_XOR_d_rm_mod_reg_u32_imm_u8, 
	// 78
	in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, 
	// 80
	in_ADD_d_rm_mod_reg_u32_imm_u8, in_ADD_d_rm_mod_reg_u32_imm_u8, in_ADD_d_rm_mod_reg_u32_imm_u8, in_ADD_d_rm_mod_reg_u32_imm_u8, in_ADD_d_rm_mod_reg_u32_imm_u8, in_ADD_d_rm_mod_reg_u32_imm_u8, in_ADD_d_rm_mod_reg_u32_imm_u8, in_ADD_d_rm_mod_reg_u32_imm_u8, 
	// 88
	in_OR_d_rm_mod_reg_u32_imm_u8, in_OR_d_rm_mod_reg_u32_imm_u8, in_OR_d_rm_mod_reg_u32_imm_u8, in_OR_d_rm_mod_reg_u32_imm_u8, in_OR_d_rm_mod_reg_u32_imm_u8, in_OR_d_rm_mod_reg_u32_imm_u8, in_OR_d_rm_mod_reg_u32_imm_u8, in_OR_d_rm_mod_reg_u32_imm_u8, 
	// 90
	in_ADC_d_rm_mod_reg_u32_imm_u8, in_ADC_d_rm_mod_reg_u32_imm_u8, in_ADC_d_rm_mod_reg_u32_imm_u8, in_ADC_d_rm_mod_reg_u32_imm_u8, in_ADC_d_rm_mod_reg_u32_imm_u8, in_ADC_d_rm_mod_reg_u32_imm_u8, in_ADC_d_rm_mod_reg_u32_imm_u8, in_ADC_d_rm_mod_reg_u32_imm_u8, 
	// 98
	in_SBB_d_rm_mod_reg_u32_imm_u8, in_SBB_d_rm_mod_reg_u32_imm_u8, in_SBB_d_rm_mod_reg_u32_imm_u8, in_SBB_d_rm_mod_reg_u32_imm_u8, in_SBB_d_rm_mod_reg_u32_imm_u8, in_SBB_d_rm_mod_reg_u32_imm_u8, in_SBB_d_rm_mod_reg_u32_imm_u8, in_SBB_d_rm_mod_reg_u32_imm_u8, 
	// A0
	in_AND_d_rm_mod_reg_u32_imm_u8, in_AND_d_rm_mod_reg_u32_imm_u8, in_AND_d_rm_mod_reg_u32_imm_u8, in_AND_d_rm_mod_reg_u32_imm_u8, in_AND_d_rm_mod_reg_u32_imm_u8, in_AND_d_rm_mod_reg_u32_imm_u8, in_AND_d_rm_mod_reg_u32_imm_u8, in_AND_d_rm_mod_reg_u32_imm_u8, 
	// A8
	in_SUB_d_rm_mod_reg_u32_imm_u8, in_SUB_d_rm_mod_reg_u32_imm_u8, in_SUB_d_rm_mod_reg_u32_imm_u8, in_SUB_d_rm_mod_reg_u32_imm_u8, in_SUB_d_rm_mod_reg_u32_imm_u8, in_SUB_d_rm_mod_reg_u32_imm_u8, in_SUB_d_rm_mod_reg_u32_imm_u8, in_SUB_d_rm_mod_reg_u32_imm_u8, 
	// B0
	in_XOR_d_rm_mod_reg_u32_imm_u8, in_XOR_d_rm_mod_reg_u32_imm_u8, in_XOR_d_rm_mod_reg_u32_imm_u8, in_XOR_d_rm_mod_reg_u32_imm_u8, in_XOR_d_rm_mod_reg_u32_imm_u8, in_XOR_d_rm_mod_reg_u32_imm_u8, in_XOR_d_rm_mod_reg_u32_imm_u8, in_XOR_d_rm_mod_reg_u32_imm_u8, 
	// B8
	in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, 
	// C0
	in_ADD_d_rm_mod_reg_u32_imm_u8, in_ADD_d_rm_mod_reg_u32_imm_u8, in_ADD_d_rm_mod_reg_u32_imm_u8, in_ADD_d_rm_mod_reg_u32_imm_u8, in_ADD_d_rm_mod_reg_u32_imm_u8, in_ADD_d_rm_mod_reg_u32_imm_u8, in_ADD_d_rm_mod_reg_u32_imm_u8, in_ADD_d_rm_mod_reg_u32_imm_u8, 
	// C8
	in_OR_d_rm_mod_reg_u32_imm_u8, in_OR_d_rm_mod_reg_u32_imm_u8, in_OR_d_rm_mod_reg_u32_imm_u8, in_OR_d_rm_mod_reg_u32_imm_u8, in_OR_d_rm_mod_reg_u32_imm_u8, in_OR_d_rm_mod_reg_u32_imm_u8, in_OR_d_rm_mod_reg_u32_imm_u8, in_OR_d_rm_mod_reg_u32_imm_u8, 
	// D0
	in_ADC_d_rm_mod_reg_u32_imm_u8, in_ADC_d_rm_mod_reg_u32_imm_u8, in_ADC_d_rm_mod_reg_u32_imm_u8, in_ADC_d_rm_mod_reg_u32_imm_u8, in_ADC_d_rm_mod_reg_u32_imm_u8, in_ADC_d_rm_mod_reg_u32_imm_u8, in_ADC_d_rm_mod_reg_u32_imm_u8, in_ADC_d_rm_mod_reg_u32_imm_u8, 
	// D8
	in_SBB_d_rm_mod_reg_u32_imm_u8, in_SBB_d_rm_mod_reg_u32_imm_u8, in_SBB_d_rm_mod_reg_u32_imm_u8, in_SBB_d_rm_mod_reg_u32_imm_u8, in_SBB_d_rm_mod_reg_u32_imm_u8, in_SBB_d_rm_mod_reg_u32_imm_u8, in_SBB_d_rm_mod_reg_u32_imm_u8, in_SBB_d_rm_mod_reg_u32_imm_u8, 
	// E0
	in_AND_d_rm_mod_reg_u32_imm_u8, in_AND_d_rm_mod_reg_u32_imm_u8, in_AND_d_rm_mod_reg_u32_imm_u8, in_AND_d_rm_mod_reg_u32_imm_u8, in_AND_d_rm_mod_reg_u32_imm_u8, in_AND_d_rm_mod_reg_u32_imm_u8, in_AND_d_rm_mod_reg_u32_imm_u8, in_AND_d_rm_mod_reg_u32_imm_u8, 
	// E8
	in_SUB_d_rm_mod_reg_u32_imm_u8, in_SUB_d_rm_mod_reg_u32_imm_u8, in_SUB_d_rm_mod_reg_u32_imm_u8, in_SUB_d_rm_mod_reg_u32_imm_u8, in_SUB_d_rm_mod_reg_u32_imm_u8, in_SUB_d_rm_mod_reg_u32_imm_u8, in_SUB_d_rm_mod_reg_u32_imm_u8, in_SUB_d_rm_mod_reg_u32_imm_u8, 
	// F0
	in_XOR_d_rm_mod_reg_u32_imm_u8, in_XOR_d_rm_mod_reg_u32_imm_u8, in_XOR_d_rm_mod_reg_u32_imm_u8, in_XOR_d_rm_mod_reg_u32_imm_u8, in_XOR_d_rm_mod_reg_u32_imm_u8, in_XOR_d_rm_mod_reg_u32_imm_u8, in_XOR_d_rm_mod_reg_u32_imm_u8, in_XOR_d_rm_mod_reg_u32_imm_u8, 
	// F8
	in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, in_CMP_d_imm_u8, 
};
const OpState CpuRunnerX86::table_st_w_w_8F[] = {
	// 00
	in_POP_w_rm_mod_reg_u16, in_POP_w_rm_mod_reg_u16, in_POP_w_rm_mod_reg_u16, in_POP_w_rm_mod_reg_u16, in_POP_w_rm_mod_reg_u16, in_POP_w_rm_mod_reg_u16, in_POP_w_rm_mod_reg_u16, in_POP_w_rm_mod_reg_u16, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_POP_w_rm_mod_reg_u16, in_POP_w_rm_mod_reg_u16, in_POP_w_rm_mod_reg_u16, in_POP_w_rm_mod_reg_u16, in_POP_w_rm_mod_reg_u16, in_POP_w_rm_mod_reg_u16, in_POP_w_rm_mod_reg_u16, in_POP_w_rm_mod_reg_u16, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_POP_w_rm_mod_reg_u16, in_POP_w_rm_mod_reg_u16, in_POP_w_rm_mod_reg_u16, in_POP_w_rm_mod_reg_u16, in_POP_w_rm_mod_reg_u16, in_POP_w_rm_mod_reg_u16, in_POP_w_rm_mod_reg_u16, in_POP_w_rm_mod_reg_u16, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_POP_w_rm_mod_reg_u16, in_POP_w_rm_mod_reg_u16, in_POP_w_rm_mod_reg_u16, in_POP_w_rm_mod_reg_u16, in_POP_w_rm_mod_reg_u16, in_POP_w_rm_mod_reg_u16, in_POP_w_rm_mod_reg_u16, in_POP_w_rm_mod_reg_u16, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_st_w_d_8F[] = {
	// 00
	in_POP_w_rm_mod_reg_u32, in_POP_w_rm_mod_reg_u32, in_POP_w_rm_mod_reg_u32, in_POP_w_rm_mod_reg_u32, in_POP_w_rm_mod_reg_u32, in_POP_w_rm_mod_reg_u32, in_POP_w_rm_mod_reg_u32, in_POP_w_rm_mod_reg_u32, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_POP_w_rm_mod_reg_u32, in_POP_w_rm_mod_reg_u32, in_POP_w_rm_mod_reg_u32, in_POP_w_rm_mod_reg_u32, in_POP_w_rm_mod_reg_u32, in_POP_w_rm_mod_reg_u32, in_POP_w_rm_mod_reg_u32, in_POP_w_rm_mod_reg_u32, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_POP_w_rm_mod_reg_u32, in_POP_w_rm_mod_reg_u32, in_POP_w_rm_mod_reg_u32, in_POP_w_rm_mod_reg_u32, in_POP_w_rm_mod_reg_u32, in_POP_w_rm_mod_reg_u32, in_POP_w_rm_mod_reg_u32, in_POP_w_rm_mod_reg_u32, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_POP_w_rm_mod_reg_u32, in_POP_w_rm_mod_reg_u32, in_POP_w_rm_mod_reg_u32, in_POP_w_rm_mod_reg_u32, in_POP_w_rm_mod_reg_u32, in_POP_w_rm_mod_reg_u32, in_POP_w_rm_mod_reg_u32, in_POP_w_rm_mod_reg_u32, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_st_d_w_8F[] = {
	// 00
	in_POP_d_rm_mod_reg_u16, in_POP_d_rm_mod_reg_u16, in_POP_d_rm_mod_reg_u16, in_POP_d_rm_mod_reg_u16, in_POP_d_rm_mod_reg_u16, in_POP_d_rm_mod_reg_u16, in_POP_d_rm_mod_reg_u16, in_POP_d_rm_mod_reg_u16, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_POP_d_rm_mod_reg_u16, in_POP_d_rm_mod_reg_u16, in_POP_d_rm_mod_reg_u16, in_POP_d_rm_mod_reg_u16, in_POP_d_rm_mod_reg_u16, in_POP_d_rm_mod_reg_u16, in_POP_d_rm_mod_reg_u16, in_POP_d_rm_mod_reg_u16, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_POP_d_rm_mod_reg_u16, in_POP_d_rm_mod_reg_u16, in_POP_d_rm_mod_reg_u16, in_POP_d_rm_mod_reg_u16, in_POP_d_rm_mod_reg_u16, in_POP_d_rm_mod_reg_u16, in_POP_d_rm_mod_reg_u16, in_POP_d_rm_mod_reg_u16, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_POP_d_rm_mod_reg_u16, in_POP_d_rm_mod_reg_u16, in_POP_d_rm_mod_reg_u16, in_POP_d_rm_mod_reg_u16, in_POP_d_rm_mod_reg_u16, in_POP_d_rm_mod_reg_u16, in_POP_d_rm_mod_reg_u16, in_POP_d_rm_mod_reg_u16, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_st_d_d_8F[] = {
	// 00
	in_POP_d_rm_mod_reg_u32, in_POP_d_rm_mod_reg_u32, in_POP_d_rm_mod_reg_u32, in_POP_d_rm_mod_reg_u32, in_POP_d_rm_mod_reg_u32, in_POP_d_rm_mod_reg_u32, in_POP_d_rm_mod_reg_u32, in_POP_d_rm_mod_reg_u32, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_POP_d_rm_mod_reg_u32, in_POP_d_rm_mod_reg_u32, in_POP_d_rm_mod_reg_u32, in_POP_d_rm_mod_reg_u32, in_POP_d_rm_mod_reg_u32, in_POP_d_rm_mod_reg_u32, in_POP_d_rm_mod_reg_u32, in_POP_d_rm_mod_reg_u32, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_POP_d_rm_mod_reg_u32, in_POP_d_rm_mod_reg_u32, in_POP_d_rm_mod_reg_u32, in_POP_d_rm_mod_reg_u32, in_POP_d_rm_mod_reg_u32, in_POP_d_rm_mod_reg_u32, in_POP_d_rm_mod_reg_u32, in_POP_d_rm_mod_reg_u32, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_POP_d_rm_mod_reg_u32, in_POP_d_rm_mod_reg_u32, in_POP_d_rm_mod_reg_u32, in_POP_d_rm_mod_reg_u32, in_POP_d_rm_mod_reg_u32, in_POP_d_rm_mod_reg_u32, in_POP_d_rm_mod_reg_u32, in_POP_d_rm_mod_reg_u32, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_st_w_w_C0[] = {
	// 00
	in_ROL_w_rm_mod_reg_u8_imm_u8, in_ROL_w_rm_mod_reg_u8_imm_u8, in_ROL_w_rm_mod_reg_u8_imm_u8, in_ROL_w_rm_mod_reg_u8_imm_u8, in_ROL_w_rm_mod_reg_u8_imm_u8, in_ROL_w_rm_mod_reg_u8_imm_u8, in_ROL_w_rm_mod_reg_u8_imm_u8, in_ROL_w_rm_mod_reg_u8_imm_u8, 
	// 08
	in_ROR_w_rm_mod_reg_u8_imm_u8, in_ROR_w_rm_mod_reg_u8_imm_u8, in_ROR_w_rm_mod_reg_u8_imm_u8, in_ROR_w_rm_mod_reg_u8_imm_u8, in_ROR_w_rm_mod_reg_u8_imm_u8, in_ROR_w_rm_mod_reg_u8_imm_u8, in_ROR_w_rm_mod_reg_u8_imm_u8, in_ROR_w_rm_mod_reg_u8_imm_u8, 
	// 10
	in_RCL_w_rm_mod_reg_u8_imm_u8, in_RCL_w_rm_mod_reg_u8_imm_u8, in_RCL_w_rm_mod_reg_u8_imm_u8, in_RCL_w_rm_mod_reg_u8_imm_u8, in_RCL_w_rm_mod_reg_u8_imm_u8, in_RCL_w_rm_mod_reg_u8_imm_u8, in_RCL_w_rm_mod_reg_u8_imm_u8, in_RCL_w_rm_mod_reg_u8_imm_u8, 
	// 18
	in_RCR_w_rm_mod_reg_u8_imm_u8, in_RCR_w_rm_mod_reg_u8_imm_u8, in_RCR_w_rm_mod_reg_u8_imm_u8, in_RCR_w_rm_mod_reg_u8_imm_u8, in_RCR_w_rm_mod_reg_u8_imm_u8, in_RCR_w_rm_mod_reg_u8_imm_u8, in_RCR_w_rm_mod_reg_u8_imm_u8, in_RCR_w_rm_mod_reg_u8_imm_u8, 
	// 20
	in_SHL_w_rm_mod_reg_u8_imm_u8, in_SHL_w_rm_mod_reg_u8_imm_u8, in_SHL_w_rm_mod_reg_u8_imm_u8, in_SHL_w_rm_mod_reg_u8_imm_u8, in_SHL_w_rm_mod_reg_u8_imm_u8, in_SHL_w_rm_mod_reg_u8_imm_u8, in_SHL_w_rm_mod_reg_u8_imm_u8, in_SHL_w_rm_mod_reg_u8_imm_u8, 
	// 28
	in_SHR_w_rm_mod_reg_u8_imm_u8, in_SHR_w_rm_mod_reg_u8_imm_u8, in_SHR_w_rm_mod_reg_u8_imm_u8, in_SHR_w_rm_mod_reg_u8_imm_u8, in_SHR_w_rm_mod_reg_u8_imm_u8, in_SHR_w_rm_mod_reg_u8_imm_u8, in_SHR_w_rm_mod_reg_u8_imm_u8, in_SHR_w_rm_mod_reg_u8_imm_u8, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_SAR_w_rm_mod_reg_u8_imm_u8, in_SAR_w_rm_mod_reg_u8_imm_u8, in_SAR_w_rm_mod_reg_u8_imm_u8, in_SAR_w_rm_mod_reg_u8_imm_u8, in_SAR_w_rm_mod_reg_u8_imm_u8, in_SAR_w_rm_mod_reg_u8_imm_u8, in_SAR_w_rm_mod_reg_u8_imm_u8, in_SAR_w_rm_mod_reg_u8_imm_u8, 
	// 40
	in_ROL_w_rm_mod_reg_u8_imm_u8, in_ROL_w_rm_mod_reg_u8_imm_u8, in_ROL_w_rm_mod_reg_u8_imm_u8, in_ROL_w_rm_mod_reg_u8_imm_u8, in_ROL_w_rm_mod_reg_u8_imm_u8, in_ROL_w_rm_mod_reg_u8_imm_u8, in_ROL_w_rm_mod_reg_u8_imm_u8, in_ROL_w_rm_mod_reg_u8_imm_u8, 
	// 48
	in_ROR_w_rm_mod_reg_u8_imm_u8, in_ROR_w_rm_mod_reg_u8_imm_u8, in_ROR_w_rm_mod_reg_u8_imm_u8, in_ROR_w_rm_mod_reg_u8_imm_u8, in_ROR_w_rm_mod_reg_u8_imm_u8, in_ROR_w_rm_mod_reg_u8_imm_u8, in_ROR_w_rm_mod_reg_u8_imm_u8, in_ROR_w_rm_mod_reg_u8_imm_u8, 
	// 50
	in_RCL_w_rm_mod_reg_u8_imm_u8, in_RCL_w_rm_mod_reg_u8_imm_u8, in_RCL_w_rm_mod_reg_u8_imm_u8, in_RCL_w_rm_mod_reg_u8_imm_u8, in_RCL_w_rm_mod_reg_u8_imm_u8, in_RCL_w_rm_mod_reg_u8_imm_u8, in_RCL_w_rm_mod_reg_u8_imm_u8, in_RCL_w_rm_mod_reg_u8_imm_u8, 
	// 58
	in_RCR_w_rm_mod_reg_u8_imm_u8, in_RCR_w_rm_mod_reg_u8_imm_u8, in_RCR_w_rm_mod_reg_u8_imm_u8, in_RCR_w_rm_mod_reg_u8_imm_u8, in_RCR_w_rm_mod_reg_u8_imm_u8, in_RCR_w_rm_mod_reg_u8_imm_u8, in_RCR_w_rm_mod_reg_u8_imm_u8, in_RCR_w_rm_mod_reg_u8_imm_u8, 
	// 60
	in_SHL_w_rm_mod_reg_u8_imm_u8, in_SHL_w_rm_mod_reg_u8_imm_u8, in_SHL_w_rm_mod_reg_u8_imm_u8, in_SHL_w_rm_mod_reg_u8_imm_u8, in_SHL_w_rm_mod_reg_u8_imm_u8, in_SHL_w_rm_mod_reg_u8_imm_u8, in_SHL_w_rm_mod_reg_u8_imm_u8, in_SHL_w_rm_mod_reg_u8_imm_u8, 
	// 68
	in_SHR_w_rm_mod_reg_u8_imm_u8, in_SHR_w_rm_mod_reg_u8_imm_u8, in_SHR_w_rm_mod_reg_u8_imm_u8, in_SHR_w_rm_mod_reg_u8_imm_u8, in_SHR_w_rm_mod_reg_u8_imm_u8, in_SHR_w_rm_mod_reg_u8_imm_u8, in_SHR_w_rm_mod_reg_u8_imm_u8, in_SHR_w_rm_mod_reg_u8_imm_u8, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_SAR_w_rm_mod_reg_u8_imm_u8, in_SAR_w_rm_mod_reg_u8_imm_u8, in_SAR_w_rm_mod_reg_u8_imm_u8, in_SAR_w_rm_mod_reg_u8_imm_u8, in_SAR_w_rm_mod_reg_u8_imm_u8, in_SAR_w_rm_mod_reg_u8_imm_u8, in_SAR_w_rm_mod_reg_u8_imm_u8, in_SAR_w_rm_mod_reg_u8_imm_u8, 
	// 80
	in_ROL_w_rm_mod_reg_u8_imm_u8, in_ROL_w_rm_mod_reg_u8_imm_u8, in_ROL_w_rm_mod_reg_u8_imm_u8, in_ROL_w_rm_mod_reg_u8_imm_u8, in_ROL_w_rm_mod_reg_u8_imm_u8, in_ROL_w_rm_mod_reg_u8_imm_u8, in_ROL_w_rm_mod_reg_u8_imm_u8, in_ROL_w_rm_mod_reg_u8_imm_u8, 
	// 88
	in_ROR_w_rm_mod_reg_u8_imm_u8, in_ROR_w_rm_mod_reg_u8_imm_u8, in_ROR_w_rm_mod_reg_u8_imm_u8, in_ROR_w_rm_mod_reg_u8_imm_u8, in_ROR_w_rm_mod_reg_u8_imm_u8, in_ROR_w_rm_mod_reg_u8_imm_u8, in_ROR_w_rm_mod_reg_u8_imm_u8, in_ROR_w_rm_mod_reg_u8_imm_u8, 
	// 90
	in_RCL_w_rm_mod_reg_u8_imm_u8, in_RCL_w_rm_mod_reg_u8_imm_u8, in_RCL_w_rm_mod_reg_u8_imm_u8, in_RCL_w_rm_mod_reg_u8_imm_u8, in_RCL_w_rm_mod_reg_u8_imm_u8, in_RCL_w_rm_mod_reg_u8_imm_u8, in_RCL_w_rm_mod_reg_u8_imm_u8, in_RCL_w_rm_mod_reg_u8_imm_u8, 
	// 98
	in_RCR_w_rm_mod_reg_u8_imm_u8, in_RCR_w_rm_mod_reg_u8_imm_u8, in_RCR_w_rm_mod_reg_u8_imm_u8, in_RCR_w_rm_mod_reg_u8_imm_u8, in_RCR_w_rm_mod_reg_u8_imm_u8, in_RCR_w_rm_mod_reg_u8_imm_u8, in_RCR_w_rm_mod_reg_u8_imm_u8, in_RCR_w_rm_mod_reg_u8_imm_u8, 
	// A0
	in_SHL_w_rm_mod_reg_u8_imm_u8, in_SHL_w_rm_mod_reg_u8_imm_u8, in_SHL_w_rm_mod_reg_u8_imm_u8, in_SHL_w_rm_mod_reg_u8_imm_u8, in_SHL_w_rm_mod_reg_u8_imm_u8, in_SHL_w_rm_mod_reg_u8_imm_u8, in_SHL_w_rm_mod_reg_u8_imm_u8, in_SHL_w_rm_mod_reg_u8_imm_u8, 
	// A8
	in_SHR_w_rm_mod_reg_u8_imm_u8, in_SHR_w_rm_mod_reg_u8_imm_u8, in_SHR_w_rm_mod_reg_u8_imm_u8, in_SHR_w_rm_mod_reg_u8_imm_u8, in_SHR_w_rm_mod_reg_u8_imm_u8, in_SHR_w_rm_mod_reg_u8_imm_u8, in_SHR_w_rm_mod_reg_u8_imm_u8, in_SHR_w_rm_mod_reg_u8_imm_u8, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_SAR_w_rm_mod_reg_u8_imm_u8, in_SAR_w_rm_mod_reg_u8_imm_u8, in_SAR_w_rm_mod_reg_u8_imm_u8, in_SAR_w_rm_mod_reg_u8_imm_u8, in_SAR_w_rm_mod_reg_u8_imm_u8, in_SAR_w_rm_mod_reg_u8_imm_u8, in_SAR_w_rm_mod_reg_u8_imm_u8, in_SAR_w_rm_mod_reg_u8_imm_u8, 
	// C0
	in_ROL_w_rm_mod_reg_u8_imm_u8, in_ROL_w_rm_mod_reg_u8_imm_u8, in_ROL_w_rm_mod_reg_u8_imm_u8, in_ROL_w_rm_mod_reg_u8_imm_u8, in_ROL_w_rm_mod_reg_u8_imm_u8, in_ROL_w_rm_mod_reg_u8_imm_u8, in_ROL_w_rm_mod_reg_u8_imm_u8, in_ROL_w_rm_mod_reg_u8_imm_u8, 
	// C8
	in_ROR_w_rm_mod_reg_u8_imm_u8, in_ROR_w_rm_mod_reg_u8_imm_u8, in_ROR_w_rm_mod_reg_u8_imm_u8, in_ROR_w_rm_mod_reg_u8_imm_u8, in_ROR_w_rm_mod_reg_u8_imm_u8, in_ROR_w_rm_mod_reg_u8_imm_u8, in_ROR_w_rm_mod_reg_u8_imm_u8, in_ROR_w_rm_mod_reg_u8_imm_u8, 
	// D0
	in_RCL_w_rm_mod_reg_u8_imm_u8, in_RCL_w_rm_mod_reg_u8_imm_u8, in_RCL_w_rm_mod_reg_u8_imm_u8, in_RCL_w_rm_mod_reg_u8_imm_u8, in_RCL_w_rm_mod_reg_u8_imm_u8, in_RCL_w_rm_mod_reg_u8_imm_u8, in_RCL_w_rm_mod_reg_u8_imm_u8, in_RCL_w_rm_mod_reg_u8_imm_u8, 
	// D8
	in_RCR_w_rm_mod_reg_u8_imm_u8, in_RCR_w_rm_mod_reg_u8_imm_u8, in_RCR_w_rm_mod_reg_u8_imm_u8, in_RCR_w_rm_mod_reg_u8_imm_u8, in_RCR_w_rm_mod_reg_u8_imm_u8, in_RCR_w_rm_mod_reg_u8_imm_u8, in_RCR_w_rm_mod_reg_u8_imm_u8, in_RCR_w_rm_mod_reg_u8_imm_u8, 
	// E0
	in_SHL_w_rm_mod_reg_u8_imm_u8, in_SHL_w_rm_mod_reg_u8_imm_u8, in_SHL_w_rm_mod_reg_u8_imm_u8, in_SHL_w_rm_mod_reg_u8_imm_u8, in_SHL_w_rm_mod_reg_u8_imm_u8, in_SHL_w_rm_mod_reg_u8_imm_u8, in_SHL_w_rm_mod_reg_u8_imm_u8, in_SHL_w_rm_mod_reg_u8_imm_u8, 
	// E8
	in_SHR_w_rm_mod_reg_u8_imm_u8, in_SHR_w_rm_mod_reg_u8_imm_u8, in_SHR_w_rm_mod_reg_u8_imm_u8, in_SHR_w_rm_mod_reg_u8_imm_u8, in_SHR_w_rm_mod_reg_u8_imm_u8, in_SHR_w_rm_mod_reg_u8_imm_u8, in_SHR_w_rm_mod_reg_u8_imm_u8, in_SHR_w_rm_mod_reg_u8_imm_u8, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_SAR_w_rm_mod_reg_u8_imm_u8, in_SAR_w_rm_mod_reg_u8_imm_u8, in_SAR_w_rm_mod_reg_u8_imm_u8, in_SAR_w_rm_mod_reg_u8_imm_u8, in_SAR_w_rm_mod_reg_u8_imm_u8, in_SAR_w_rm_mod_reg_u8_imm_u8, in_SAR_w_rm_mod_reg_u8_imm_u8, in_SAR_w_rm_mod_reg_u8_imm_u8, 
};
const OpState CpuRunnerX86::table_st_w_d_C0[] = {
	// 00
	in_ROL_w_rm_mod_reg_u8_imm_u8, in_ROL_w_rm_mod_reg_u8_imm_u8, in_ROL_w_rm_mod_reg_u8_imm_u8, in_ROL_w_rm_mod_reg_u8_imm_u8, in_ROL_w_rm_mod_reg_u8_imm_u8, in_ROL_w_rm_mod_reg_u8_imm_u8, in_ROL_w_rm_mod_reg_u8_imm_u8, in_ROL_w_rm_mod_reg_u8_imm_u8, 
	// 08
	in_ROR_w_rm_mod_reg_u8_imm_u8, in_ROR_w_rm_mod_reg_u8_imm_u8, in_ROR_w_rm_mod_reg_u8_imm_u8, in_ROR_w_rm_mod_reg_u8_imm_u8, in_ROR_w_rm_mod_reg_u8_imm_u8, in_ROR_w_rm_mod_reg_u8_imm_u8, in_ROR_w_rm_mod_reg_u8_imm_u8, in_ROR_w_rm_mod_reg_u8_imm_u8, 
	// 10
	in_RCL_w_rm_mod_reg_u8_imm_u8, in_RCL_w_rm_mod_reg_u8_imm_u8, in_RCL_w_rm_mod_reg_u8_imm_u8, in_RCL_w_rm_mod_reg_u8_imm_u8, in_RCL_w_rm_mod_reg_u8_imm_u8, in_RCL_w_rm_mod_reg_u8_imm_u8, in_RCL_w_rm_mod_reg_u8_imm_u8, in_RCL_w_rm_mod_reg_u8_imm_u8, 
	// 18
	in_RCR_w_rm_mod_reg_u8_imm_u8, in_RCR_w_rm_mod_reg_u8_imm_u8, in_RCR_w_rm_mod_reg_u8_imm_u8, in_RCR_w_rm_mod_reg_u8_imm_u8, in_RCR_w_rm_mod_reg_u8_imm_u8, in_RCR_w_rm_mod_reg_u8_imm_u8, in_RCR_w_rm_mod_reg_u8_imm_u8, in_RCR_w_rm_mod_reg_u8_imm_u8, 
	// 20
	in_SHL_w_rm_mod_reg_u8_imm_u8, in_SHL_w_rm_mod_reg_u8_imm_u8, in_SHL_w_rm_mod_reg_u8_imm_u8, in_SHL_w_rm_mod_reg_u8_imm_u8, in_SHL_w_rm_mod_reg_u8_imm_u8, in_SHL_w_rm_mod_reg_u8_imm_u8, in_SHL_w_rm_mod_reg_u8_imm_u8, in_SHL_w_rm_mod_reg_u8_imm_u8, 
	// 28
	in_SHR_w_rm_mod_reg_u8_imm_u8, in_SHR_w_rm_mod_reg_u8_imm_u8, in_SHR_w_rm_mod_reg_u8_imm_u8, in_SHR_w_rm_mod_reg_u8_imm_u8, in_SHR_w_rm_mod_reg_u8_imm_u8, in_SHR_w_rm_mod_reg_u8_imm_u8, in_SHR_w_rm_mod_reg_u8_imm_u8, in_SHR_w_rm_mod_reg_u8_imm_u8, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_SAR_w_rm_mod_reg_u8_imm_u8, in_SAR_w_rm_mod_reg_u8_imm_u8, in_SAR_w_rm_mod_reg_u8_imm_u8, in_SAR_w_rm_mod_reg_u8_imm_u8, in_SAR_w_rm_mod_reg_u8_imm_u8, in_SAR_w_rm_mod_reg_u8_imm_u8, in_SAR_w_rm_mod_reg_u8_imm_u8, in_SAR_w_rm_mod_reg_u8_imm_u8, 
	// 40
	in_ROL_w_rm_mod_reg_u8_imm_u8, in_ROL_w_rm_mod_reg_u8_imm_u8, in_ROL_w_rm_mod_reg_u8_imm_u8, in_ROL_w_rm_mod_reg_u8_imm_u8, in_ROL_w_rm_mod_reg_u8_imm_u8, in_ROL_w_rm_mod_reg_u8_imm_u8, in_ROL_w_rm_mod_reg_u8_imm_u8, in_ROL_w_rm_mod_reg_u8_imm_u8, 
	// 48
	in_ROR_w_rm_mod_reg_u8_imm_u8, in_ROR_w_rm_mod_reg_u8_imm_u8, in_ROR_w_rm_mod_reg_u8_imm_u8, in_ROR_w_rm_mod_reg_u8_imm_u8, in_ROR_w_rm_mod_reg_u8_imm_u8, in_ROR_w_rm_mod_reg_u8_imm_u8, in_ROR_w_rm_mod_reg_u8_imm_u8, in_ROR_w_rm_mod_reg_u8_imm_u8, 
	// 50
	in_RCL_w_rm_mod_reg_u8_imm_u8, in_RCL_w_rm_mod_reg_u8_imm_u8, in_RCL_w_rm_mod_reg_u8_imm_u8, in_RCL_w_rm_mod_reg_u8_imm_u8, in_RCL_w_rm_mod_reg_u8_imm_u8, in_RCL_w_rm_mod_reg_u8_imm_u8, in_RCL_w_rm_mod_reg_u8_imm_u8, in_RCL_w_rm_mod_reg_u8_imm_u8, 
	// 58
	in_RCR_w_rm_mod_reg_u8_imm_u8, in_RCR_w_rm_mod_reg_u8_imm_u8, in_RCR_w_rm_mod_reg_u8_imm_u8, in_RCR_w_rm_mod_reg_u8_imm_u8, in_RCR_w_rm_mod_reg_u8_imm_u8, in_RCR_w_rm_mod_reg_u8_imm_u8, in_RCR_w_rm_mod_reg_u8_imm_u8, in_RCR_w_rm_mod_reg_u8_imm_u8, 
	// 60
	in_SHL_w_rm_mod_reg_u8_imm_u8, in_SHL_w_rm_mod_reg_u8_imm_u8, in_SHL_w_rm_mod_reg_u8_imm_u8, in_SHL_w_rm_mod_reg_u8_imm_u8, in_SHL_w_rm_mod_reg_u8_imm_u8, in_SHL_w_rm_mod_reg_u8_imm_u8, in_SHL_w_rm_mod_reg_u8_imm_u8, in_SHL_w_rm_mod_reg_u8_imm_u8, 
	// 68
	in_SHR_w_rm_mod_reg_u8_imm_u8, in_SHR_w_rm_mod_reg_u8_imm_u8, in_SHR_w_rm_mod_reg_u8_imm_u8, in_SHR_w_rm_mod_reg_u8_imm_u8, in_SHR_w_rm_mod_reg_u8_imm_u8, in_SHR_w_rm_mod_reg_u8_imm_u8, in_SHR_w_rm_mod_reg_u8_imm_u8, in_SHR_w_rm_mod_reg_u8_imm_u8, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_SAR_w_rm_mod_reg_u8_imm_u8, in_SAR_w_rm_mod_reg_u8_imm_u8, in_SAR_w_rm_mod_reg_u8_imm_u8, in_SAR_w_rm_mod_reg_u8_imm_u8, in_SAR_w_rm_mod_reg_u8_imm_u8, in_SAR_w_rm_mod_reg_u8_imm_u8, in_SAR_w_rm_mod_reg_u8_imm_u8, in_SAR_w_rm_mod_reg_u8_imm_u8, 
	// 80
	in_ROL_w_rm_mod_reg_u8_imm_u8, in_ROL_w_rm_mod_reg_u8_imm_u8, in_ROL_w_rm_mod_reg_u8_imm_u8, in_ROL_w_rm_mod_reg_u8_imm_u8, in_ROL_w_rm_mod_reg_u8_imm_u8, in_ROL_w_rm_mod_reg_u8_imm_u8, in_ROL_w_rm_mod_reg_u8_imm_u8, in_ROL_w_rm_mod_reg_u8_imm_u8, 
	// 88
	in_ROR_w_rm_mod_reg_u8_imm_u8, in_ROR_w_rm_mod_reg_u8_imm_u8, in_ROR_w_rm_mod_reg_u8_imm_u8, in_ROR_w_rm_mod_reg_u8_imm_u8, in_ROR_w_rm_mod_reg_u8_imm_u8, in_ROR_w_rm_mod_reg_u8_imm_u8, in_ROR_w_rm_mod_reg_u8_imm_u8, in_ROR_w_rm_mod_reg_u8_imm_u8, 
	// 90
	in_RCL_w_rm_mod_reg_u8_imm_u8, in_RCL_w_rm_mod_reg_u8_imm_u8, in_RCL_w_rm_mod_reg_u8_imm_u8, in_RCL_w_rm_mod_reg_u8_imm_u8, in_RCL_w_rm_mod_reg_u8_imm_u8, in_RCL_w_rm_mod_reg_u8_imm_u8, in_RCL_w_rm_mod_reg_u8_imm_u8, in_RCL_w_rm_mod_reg_u8_imm_u8, 
	// 98
	in_RCR_w_rm_mod_reg_u8_imm_u8, in_RCR_w_rm_mod_reg_u8_imm_u8, in_RCR_w_rm_mod_reg_u8_imm_u8, in_RCR_w_rm_mod_reg_u8_imm_u8, in_RCR_w_rm_mod_reg_u8_imm_u8, in_RCR_w_rm_mod_reg_u8_imm_u8, in_RCR_w_rm_mod_reg_u8_imm_u8, in_RCR_w_rm_mod_reg_u8_imm_u8, 
	// A0
	in_SHL_w_rm_mod_reg_u8_imm_u8, in_SHL_w_rm_mod_reg_u8_imm_u8, in_SHL_w_rm_mod_reg_u8_imm_u8, in_SHL_w_rm_mod_reg_u8_imm_u8, in_SHL_w_rm_mod_reg_u8_imm_u8, in_SHL_w_rm_mod_reg_u8_imm_u8, in_SHL_w_rm_mod_reg_u8_imm_u8, in_SHL_w_rm_mod_reg_u8_imm_u8, 
	// A8
	in_SHR_w_rm_mod_reg_u8_imm_u8, in_SHR_w_rm_mod_reg_u8_imm_u8, in_SHR_w_rm_mod_reg_u8_imm_u8, in_SHR_w_rm_mod_reg_u8_imm_u8, in_SHR_w_rm_mod_reg_u8_imm_u8, in_SHR_w_rm_mod_reg_u8_imm_u8, in_SHR_w_rm_mod_reg_u8_imm_u8, in_SHR_w_rm_mod_reg_u8_imm_u8, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_SAR_w_rm_mod_reg_u8_imm_u8, in_SAR_w_rm_mod_reg_u8_imm_u8, in_SAR_w_rm_mod_reg_u8_imm_u8, in_SAR_w_rm_mod_reg_u8_imm_u8, in_SAR_w_rm_mod_reg_u8_imm_u8, in_SAR_w_rm_mod_reg_u8_imm_u8, in_SAR_w_rm_mod_reg_u8_imm_u8, in_SAR_w_rm_mod_reg_u8_imm_u8, 
	// C0
	in_ROL_w_rm_mod_reg_u8_imm_u8, in_ROL_w_rm_mod_reg_u8_imm_u8, in_ROL_w_rm_mod_reg_u8_imm_u8, in_ROL_w_rm_mod_reg_u8_imm_u8, in_ROL_w_rm_mod_reg_u8_imm_u8, in_ROL_w_rm_mod_reg_u8_imm_u8, in_ROL_w_rm_mod_reg_u8_imm_u8, in_ROL_w_rm_mod_reg_u8_imm_u8, 
	// C8
	in_ROR_w_rm_mod_reg_u8_imm_u8, in_ROR_w_rm_mod_reg_u8_imm_u8, in_ROR_w_rm_mod_reg_u8_imm_u8, in_ROR_w_rm_mod_reg_u8_imm_u8, in_ROR_w_rm_mod_reg_u8_imm_u8, in_ROR_w_rm_mod_reg_u8_imm_u8, in_ROR_w_rm_mod_reg_u8_imm_u8, in_ROR_w_rm_mod_reg_u8_imm_u8, 
	// D0
	in_RCL_w_rm_mod_reg_u8_imm_u8, in_RCL_w_rm_mod_reg_u8_imm_u8, in_RCL_w_rm_mod_reg_u8_imm_u8, in_RCL_w_rm_mod_reg_u8_imm_u8, in_RCL_w_rm_mod_reg_u8_imm_u8, in_RCL_w_rm_mod_reg_u8_imm_u8, in_RCL_w_rm_mod_reg_u8_imm_u8, in_RCL_w_rm_mod_reg_u8_imm_u8, 
	// D8
	in_RCR_w_rm_mod_reg_u8_imm_u8, in_RCR_w_rm_mod_reg_u8_imm_u8, in_RCR_w_rm_mod_reg_u8_imm_u8, in_RCR_w_rm_mod_reg_u8_imm_u8, in_RCR_w_rm_mod_reg_u8_imm_u8, in_RCR_w_rm_mod_reg_u8_imm_u8, in_RCR_w_rm_mod_reg_u8_imm_u8, in_RCR_w_rm_mod_reg_u8_imm_u8, 
	// E0
	in_SHL_w_rm_mod_reg_u8_imm_u8, in_SHL_w_rm_mod_reg_u8_imm_u8, in_SHL_w_rm_mod_reg_u8_imm_u8, in_SHL_w_rm_mod_reg_u8_imm_u8, in_SHL_w_rm_mod_reg_u8_imm_u8, in_SHL_w_rm_mod_reg_u8_imm_u8, in_SHL_w_rm_mod_reg_u8_imm_u8, in_SHL_w_rm_mod_reg_u8_imm_u8, 
	// E8
	in_SHR_w_rm_mod_reg_u8_imm_u8, in_SHR_w_rm_mod_reg_u8_imm_u8, in_SHR_w_rm_mod_reg_u8_imm_u8, in_SHR_w_rm_mod_reg_u8_imm_u8, in_SHR_w_rm_mod_reg_u8_imm_u8, in_SHR_w_rm_mod_reg_u8_imm_u8, in_SHR_w_rm_mod_reg_u8_imm_u8, in_SHR_w_rm_mod_reg_u8_imm_u8, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_SAR_w_rm_mod_reg_u8_imm_u8, in_SAR_w_rm_mod_reg_u8_imm_u8, in_SAR_w_rm_mod_reg_u8_imm_u8, in_SAR_w_rm_mod_reg_u8_imm_u8, in_SAR_w_rm_mod_reg_u8_imm_u8, in_SAR_w_rm_mod_reg_u8_imm_u8, in_SAR_w_rm_mod_reg_u8_imm_u8, in_SAR_w_rm_mod_reg_u8_imm_u8, 
};
const OpState CpuRunnerX86::table_st_d_w_C0[] = {
	// 00
	in_ROL_d_rm_mod_reg_u8_imm_u8, in_ROL_d_rm_mod_reg_u8_imm_u8, in_ROL_d_rm_mod_reg_u8_imm_u8, in_ROL_d_rm_mod_reg_u8_imm_u8, in_ROL_d_rm_mod_reg_u8_imm_u8, in_ROL_d_rm_mod_reg_u8_imm_u8, in_ROL_d_rm_mod_reg_u8_imm_u8, in_ROL_d_rm_mod_reg_u8_imm_u8, 
	// 08
	in_ROR_d_rm_mod_reg_u8_imm_u8, in_ROR_d_rm_mod_reg_u8_imm_u8, in_ROR_d_rm_mod_reg_u8_imm_u8, in_ROR_d_rm_mod_reg_u8_imm_u8, in_ROR_d_rm_mod_reg_u8_imm_u8, in_ROR_d_rm_mod_reg_u8_imm_u8, in_ROR_d_rm_mod_reg_u8_imm_u8, in_ROR_d_rm_mod_reg_u8_imm_u8, 
	// 10
	in_RCL_d_rm_mod_reg_u8_imm_u8, in_RCL_d_rm_mod_reg_u8_imm_u8, in_RCL_d_rm_mod_reg_u8_imm_u8, in_RCL_d_rm_mod_reg_u8_imm_u8, in_RCL_d_rm_mod_reg_u8_imm_u8, in_RCL_d_rm_mod_reg_u8_imm_u8, in_RCL_d_rm_mod_reg_u8_imm_u8, in_RCL_d_rm_mod_reg_u8_imm_u8, 
	// 18
	in_RCR_d_rm_mod_reg_u8_imm_u8, in_RCR_d_rm_mod_reg_u8_imm_u8, in_RCR_d_rm_mod_reg_u8_imm_u8, in_RCR_d_rm_mod_reg_u8_imm_u8, in_RCR_d_rm_mod_reg_u8_imm_u8, in_RCR_d_rm_mod_reg_u8_imm_u8, in_RCR_d_rm_mod_reg_u8_imm_u8, in_RCR_d_rm_mod_reg_u8_imm_u8, 
	// 20
	in_SHL_d_rm_mod_reg_u8_imm_u8, in_SHL_d_rm_mod_reg_u8_imm_u8, in_SHL_d_rm_mod_reg_u8_imm_u8, in_SHL_d_rm_mod_reg_u8_imm_u8, in_SHL_d_rm_mod_reg_u8_imm_u8, in_SHL_d_rm_mod_reg_u8_imm_u8, in_SHL_d_rm_mod_reg_u8_imm_u8, in_SHL_d_rm_mod_reg_u8_imm_u8, 
	// 28
	in_SHR_d_rm_mod_reg_u8_imm_u8, in_SHR_d_rm_mod_reg_u8_imm_u8, in_SHR_d_rm_mod_reg_u8_imm_u8, in_SHR_d_rm_mod_reg_u8_imm_u8, in_SHR_d_rm_mod_reg_u8_imm_u8, in_SHR_d_rm_mod_reg_u8_imm_u8, in_SHR_d_rm_mod_reg_u8_imm_u8, in_SHR_d_rm_mod_reg_u8_imm_u8, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_SAR_d_rm_mod_reg_u8_imm_u8, in_SAR_d_rm_mod_reg_u8_imm_u8, in_SAR_d_rm_mod_reg_u8_imm_u8, in_SAR_d_rm_mod_reg_u8_imm_u8, in_SAR_d_rm_mod_reg_u8_imm_u8, in_SAR_d_rm_mod_reg_u8_imm_u8, in_SAR_d_rm_mod_reg_u8_imm_u8, in_SAR_d_rm_mod_reg_u8_imm_u8, 
	// 40
	in_ROL_d_rm_mod_reg_u8_imm_u8, in_ROL_d_rm_mod_reg_u8_imm_u8, in_ROL_d_rm_mod_reg_u8_imm_u8, in_ROL_d_rm_mod_reg_u8_imm_u8, in_ROL_d_rm_mod_reg_u8_imm_u8, in_ROL_d_rm_mod_reg_u8_imm_u8, in_ROL_d_rm_mod_reg_u8_imm_u8, in_ROL_d_rm_mod_reg_u8_imm_u8, 
	// 48
	in_ROR_d_rm_mod_reg_u8_imm_u8, in_ROR_d_rm_mod_reg_u8_imm_u8, in_ROR_d_rm_mod_reg_u8_imm_u8, in_ROR_d_rm_mod_reg_u8_imm_u8, in_ROR_d_rm_mod_reg_u8_imm_u8, in_ROR_d_rm_mod_reg_u8_imm_u8, in_ROR_d_rm_mod_reg_u8_imm_u8, in_ROR_d_rm_mod_reg_u8_imm_u8, 
	// 50
	in_RCL_d_rm_mod_reg_u8_imm_u8, in_RCL_d_rm_mod_reg_u8_imm_u8, in_RCL_d_rm_mod_reg_u8_imm_u8, in_RCL_d_rm_mod_reg_u8_imm_u8, in_RCL_d_rm_mod_reg_u8_imm_u8, in_RCL_d_rm_mod_reg_u8_imm_u8, in_RCL_d_rm_mod_reg_u8_imm_u8, in_RCL_d_rm_mod_reg_u8_imm_u8, 
	// 58
	in_RCR_d_rm_mod_reg_u8_imm_u8, in_RCR_d_rm_mod_reg_u8_imm_u8, in_RCR_d_rm_mod_reg_u8_imm_u8, in_RCR_d_rm_mod_reg_u8_imm_u8, in_RCR_d_rm_mod_reg_u8_imm_u8, in_RCR_d_rm_mod_reg_u8_imm_u8, in_RCR_d_rm_mod_reg_u8_imm_u8, in_RCR_d_rm_mod_reg_u8_imm_u8, 
	// 60
	in_SHL_d_rm_mod_reg_u8_imm_u8, in_SHL_d_rm_mod_reg_u8_imm_u8, in_SHL_d_rm_mod_reg_u8_imm_u8, in_SHL_d_rm_mod_reg_u8_imm_u8, in_SHL_d_rm_mod_reg_u8_imm_u8, in_SHL_d_rm_mod_reg_u8_imm_u8, in_SHL_d_rm_mod_reg_u8_imm_u8, in_SHL_d_rm_mod_reg_u8_imm_u8, 
	// 68
	in_SHR_d_rm_mod_reg_u8_imm_u8, in_SHR_d_rm_mod_reg_u8_imm_u8, in_SHR_d_rm_mod_reg_u8_imm_u8, in_SHR_d_rm_mod_reg_u8_imm_u8, in_SHR_d_rm_mod_reg_u8_imm_u8, in_SHR_d_rm_mod_reg_u8_imm_u8, in_SHR_d_rm_mod_reg_u8_imm_u8, in_SHR_d_rm_mod_reg_u8_imm_u8, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_SAR_d_rm_mod_reg_u8_imm_u8, in_SAR_d_rm_mod_reg_u8_imm_u8, in_SAR_d_rm_mod_reg_u8_imm_u8, in_SAR_d_rm_mod_reg_u8_imm_u8, in_SAR_d_rm_mod_reg_u8_imm_u8, in_SAR_d_rm_mod_reg_u8_imm_u8, in_SAR_d_rm_mod_reg_u8_imm_u8, in_SAR_d_rm_mod_reg_u8_imm_u8, 
	// 80
	in_ROL_d_rm_mod_reg_u8_imm_u8, in_ROL_d_rm_mod_reg_u8_imm_u8, in_ROL_d_rm_mod_reg_u8_imm_u8, in_ROL_d_rm_mod_reg_u8_imm_u8, in_ROL_d_rm_mod_reg_u8_imm_u8, in_ROL_d_rm_mod_reg_u8_imm_u8, in_ROL_d_rm_mod_reg_u8_imm_u8, in_ROL_d_rm_mod_reg_u8_imm_u8, 
	// 88
	in_ROR_d_rm_mod_reg_u8_imm_u8, in_ROR_d_rm_mod_reg_u8_imm_u8, in_ROR_d_rm_mod_reg_u8_imm_u8, in_ROR_d_rm_mod_reg_u8_imm_u8, in_ROR_d_rm_mod_reg_u8_imm_u8, in_ROR_d_rm_mod_reg_u8_imm_u8, in_ROR_d_rm_mod_reg_u8_imm_u8, in_ROR_d_rm_mod_reg_u8_imm_u8, 
	// 90
	in_RCL_d_rm_mod_reg_u8_imm_u8, in_RCL_d_rm_mod_reg_u8_imm_u8, in_RCL_d_rm_mod_reg_u8_imm_u8, in_RCL_d_rm_mod_reg_u8_imm_u8, in_RCL_d_rm_mod_reg_u8_imm_u8, in_RCL_d_rm_mod_reg_u8_imm_u8, in_RCL_d_rm_mod_reg_u8_imm_u8, in_RCL_d_rm_mod_reg_u8_imm_u8, 
	// 98
	in_RCR_d_rm_mod_reg_u8_imm_u8, in_RCR_d_rm_mod_reg_u8_imm_u8, in_RCR_d_rm_mod_reg_u8_imm_u8, in_RCR_d_rm_mod_reg_u8_imm_u8, in_RCR_d_rm_mod_reg_u8_imm_u8, in_RCR_d_rm_mod_reg_u8_imm_u8, in_RCR_d_rm_mod_reg_u8_imm_u8, in_RCR_d_rm_mod_reg_u8_imm_u8, 
	// A0
	in_SHL_d_rm_mod_reg_u8_imm_u8, in_SHL_d_rm_mod_reg_u8_imm_u8, in_SHL_d_rm_mod_reg_u8_imm_u8, in_SHL_d_rm_mod_reg_u8_imm_u8, in_SHL_d_rm_mod_reg_u8_imm_u8, in_SHL_d_rm_mod_reg_u8_imm_u8, in_SHL_d_rm_mod_reg_u8_imm_u8, in_SHL_d_rm_mod_reg_u8_imm_u8, 
	// A8
	in_SHR_d_rm_mod_reg_u8_imm_u8, in_SHR_d_rm_mod_reg_u8_imm_u8, in_SHR_d_rm_mod_reg_u8_imm_u8, in_SHR_d_rm_mod_reg_u8_imm_u8, in_SHR_d_rm_mod_reg_u8_imm_u8, in_SHR_d_rm_mod_reg_u8_imm_u8, in_SHR_d_rm_mod_reg_u8_imm_u8, in_SHR_d_rm_mod_reg_u8_imm_u8, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_SAR_d_rm_mod_reg_u8_imm_u8, in_SAR_d_rm_mod_reg_u8_imm_u8, in_SAR_d_rm_mod_reg_u8_imm_u8, in_SAR_d_rm_mod_reg_u8_imm_u8, in_SAR_d_rm_mod_reg_u8_imm_u8, in_SAR_d_rm_mod_reg_u8_imm_u8, in_SAR_d_rm_mod_reg_u8_imm_u8, in_SAR_d_rm_mod_reg_u8_imm_u8, 
	// C0
	in_ROL_d_rm_mod_reg_u8_imm_u8, in_ROL_d_rm_mod_reg_u8_imm_u8, in_ROL_d_rm_mod_reg_u8_imm_u8, in_ROL_d_rm_mod_reg_u8_imm_u8, in_ROL_d_rm_mod_reg_u8_imm_u8, in_ROL_d_rm_mod_reg_u8_imm_u8, in_ROL_d_rm_mod_reg_u8_imm_u8, in_ROL_d_rm_mod_reg_u8_imm_u8, 
	// C8
	in_ROR_d_rm_mod_reg_u8_imm_u8, in_ROR_d_rm_mod_reg_u8_imm_u8, in_ROR_d_rm_mod_reg_u8_imm_u8, in_ROR_d_rm_mod_reg_u8_imm_u8, in_ROR_d_rm_mod_reg_u8_imm_u8, in_ROR_d_rm_mod_reg_u8_imm_u8, in_ROR_d_rm_mod_reg_u8_imm_u8, in_ROR_d_rm_mod_reg_u8_imm_u8, 
	// D0
	in_RCL_d_rm_mod_reg_u8_imm_u8, in_RCL_d_rm_mod_reg_u8_imm_u8, in_RCL_d_rm_mod_reg_u8_imm_u8, in_RCL_d_rm_mod_reg_u8_imm_u8, in_RCL_d_rm_mod_reg_u8_imm_u8, in_RCL_d_rm_mod_reg_u8_imm_u8, in_RCL_d_rm_mod_reg_u8_imm_u8, in_RCL_d_rm_mod_reg_u8_imm_u8, 
	// D8
	in_RCR_d_rm_mod_reg_u8_imm_u8, in_RCR_d_rm_mod_reg_u8_imm_u8, in_RCR_d_rm_mod_reg_u8_imm_u8, in_RCR_d_rm_mod_reg_u8_imm_u8, in_RCR_d_rm_mod_reg_u8_imm_u8, in_RCR_d_rm_mod_reg_u8_imm_u8, in_RCR_d_rm_mod_reg_u8_imm_u8, in_RCR_d_rm_mod_reg_u8_imm_u8, 
	// E0
	in_SHL_d_rm_mod_reg_u8_imm_u8, in_SHL_d_rm_mod_reg_u8_imm_u8, in_SHL_d_rm_mod_reg_u8_imm_u8, in_SHL_d_rm_mod_reg_u8_imm_u8, in_SHL_d_rm_mod_reg_u8_imm_u8, in_SHL_d_rm_mod_reg_u8_imm_u8, in_SHL_d_rm_mod_reg_u8_imm_u8, in_SHL_d_rm_mod_reg_u8_imm_u8, 
	// E8
	in_SHR_d_rm_mod_reg_u8_imm_u8, in_SHR_d_rm_mod_reg_u8_imm_u8, in_SHR_d_rm_mod_reg_u8_imm_u8, in_SHR_d_rm_mod_reg_u8_imm_u8, in_SHR_d_rm_mod_reg_u8_imm_u8, in_SHR_d_rm_mod_reg_u8_imm_u8, in_SHR_d_rm_mod_reg_u8_imm_u8, in_SHR_d_rm_mod_reg_u8_imm_u8, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_SAR_d_rm_mod_reg_u8_imm_u8, in_SAR_d_rm_mod_reg_u8_imm_u8, in_SAR_d_rm_mod_reg_u8_imm_u8, in_SAR_d_rm_mod_reg_u8_imm_u8, in_SAR_d_rm_mod_reg_u8_imm_u8, in_SAR_d_rm_mod_reg_u8_imm_u8, in_SAR_d_rm_mod_reg_u8_imm_u8, in_SAR_d_rm_mod_reg_u8_imm_u8, 
};
const OpState CpuRunnerX86::table_st_d_d_C0[] = {
	// 00
	in_ROL_d_rm_mod_reg_u8_imm_u8, in_ROL_d_rm_mod_reg_u8_imm_u8, in_ROL_d_rm_mod_reg_u8_imm_u8, in_ROL_d_rm_mod_reg_u8_imm_u8, in_ROL_d_rm_mod_reg_u8_imm_u8, in_ROL_d_rm_mod_reg_u8_imm_u8, in_ROL_d_rm_mod_reg_u8_imm_u8, in_ROL_d_rm_mod_reg_u8_imm_u8, 
	// 08
	in_ROR_d_rm_mod_reg_u8_imm_u8, in_ROR_d_rm_mod_reg_u8_imm_u8, in_ROR_d_rm_mod_reg_u8_imm_u8, in_ROR_d_rm_mod_reg_u8_imm_u8, in_ROR_d_rm_mod_reg_u8_imm_u8, in_ROR_d_rm_mod_reg_u8_imm_u8, in_ROR_d_rm_mod_reg_u8_imm_u8, in_ROR_d_rm_mod_reg_u8_imm_u8, 
	// 10
	in_RCL_d_rm_mod_reg_u8_imm_u8, in_RCL_d_rm_mod_reg_u8_imm_u8, in_RCL_d_rm_mod_reg_u8_imm_u8, in_RCL_d_rm_mod_reg_u8_imm_u8, in_RCL_d_rm_mod_reg_u8_imm_u8, in_RCL_d_rm_mod_reg_u8_imm_u8, in_RCL_d_rm_mod_reg_u8_imm_u8, in_RCL_d_rm_mod_reg_u8_imm_u8, 
	// 18
	in_RCR_d_rm_mod_reg_u8_imm_u8, in_RCR_d_rm_mod_reg_u8_imm_u8, in_RCR_d_rm_mod_reg_u8_imm_u8, in_RCR_d_rm_mod_reg_u8_imm_u8, in_RCR_d_rm_mod_reg_u8_imm_u8, in_RCR_d_rm_mod_reg_u8_imm_u8, in_RCR_d_rm_mod_reg_u8_imm_u8, in_RCR_d_rm_mod_reg_u8_imm_u8, 
	// 20
	in_SHL_d_rm_mod_reg_u8_imm_u8, in_SHL_d_rm_mod_reg_u8_imm_u8, in_SHL_d_rm_mod_reg_u8_imm_u8, in_SHL_d_rm_mod_reg_u8_imm_u8, in_SHL_d_rm_mod_reg_u8_imm_u8, in_SHL_d_rm_mod_reg_u8_imm_u8, in_SHL_d_rm_mod_reg_u8_imm_u8, in_SHL_d_rm_mod_reg_u8_imm_u8, 
	// 28
	in_SHR_d_rm_mod_reg_u8_imm_u8, in_SHR_d_rm_mod_reg_u8_imm_u8, in_SHR_d_rm_mod_reg_u8_imm_u8, in_SHR_d_rm_mod_reg_u8_imm_u8, in_SHR_d_rm_mod_reg_u8_imm_u8, in_SHR_d_rm_mod_reg_u8_imm_u8, in_SHR_d_rm_mod_reg_u8_imm_u8, in_SHR_d_rm_mod_reg_u8_imm_u8, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_SAR_d_rm_mod_reg_u8_imm_u8, in_SAR_d_rm_mod_reg_u8_imm_u8, in_SAR_d_rm_mod_reg_u8_imm_u8, in_SAR_d_rm_mod_reg_u8_imm_u8, in_SAR_d_rm_mod_reg_u8_imm_u8, in_SAR_d_rm_mod_reg_u8_imm_u8, in_SAR_d_rm_mod_reg_u8_imm_u8, in_SAR_d_rm_mod_reg_u8_imm_u8, 
	// 40
	in_ROL_d_rm_mod_reg_u8_imm_u8, in_ROL_d_rm_mod_reg_u8_imm_u8, in_ROL_d_rm_mod_reg_u8_imm_u8, in_ROL_d_rm_mod_reg_u8_imm_u8, in_ROL_d_rm_mod_reg_u8_imm_u8, in_ROL_d_rm_mod_reg_u8_imm_u8, in_ROL_d_rm_mod_reg_u8_imm_u8, in_ROL_d_rm_mod_reg_u8_imm_u8, 
	// 48
	in_ROR_d_rm_mod_reg_u8_imm_u8, in_ROR_d_rm_mod_reg_u8_imm_u8, in_ROR_d_rm_mod_reg_u8_imm_u8, in_ROR_d_rm_mod_reg_u8_imm_u8, in_ROR_d_rm_mod_reg_u8_imm_u8, in_ROR_d_rm_mod_reg_u8_imm_u8, in_ROR_d_rm_mod_reg_u8_imm_u8, in_ROR_d_rm_mod_reg_u8_imm_u8, 
	// 50
	in_RCL_d_rm_mod_reg_u8_imm_u8, in_RCL_d_rm_mod_reg_u8_imm_u8, in_RCL_d_rm_mod_reg_u8_imm_u8, in_RCL_d_rm_mod_reg_u8_imm_u8, in_RCL_d_rm_mod_reg_u8_imm_u8, in_RCL_d_rm_mod_reg_u8_imm_u8, in_RCL_d_rm_mod_reg_u8_imm_u8, in_RCL_d_rm_mod_reg_u8_imm_u8, 
	// 58
	in_RCR_d_rm_mod_reg_u8_imm_u8, in_RCR_d_rm_mod_reg_u8_imm_u8, in_RCR_d_rm_mod_reg_u8_imm_u8, in_RCR_d_rm_mod_reg_u8_imm_u8, in_RCR_d_rm_mod_reg_u8_imm_u8, in_RCR_d_rm_mod_reg_u8_imm_u8, in_RCR_d_rm_mod_reg_u8_imm_u8, in_RCR_d_rm_mod_reg_u8_imm_u8, 
	// 60
	in_SHL_d_rm_mod_reg_u8_imm_u8, in_SHL_d_rm_mod_reg_u8_imm_u8, in_SHL_d_rm_mod_reg_u8_imm_u8, in_SHL_d_rm_mod_reg_u8_imm_u8, in_SHL_d_rm_mod_reg_u8_imm_u8, in_SHL_d_rm_mod_reg_u8_imm_u8, in_SHL_d_rm_mod_reg_u8_imm_u8, in_SHL_d_rm_mod_reg_u8_imm_u8, 
	// 68
	in_SHR_d_rm_mod_reg_u8_imm_u8, in_SHR_d_rm_mod_reg_u8_imm_u8, in_SHR_d_rm_mod_reg_u8_imm_u8, in_SHR_d_rm_mod_reg_u8_imm_u8, in_SHR_d_rm_mod_reg_u8_imm_u8, in_SHR_d_rm_mod_reg_u8_imm_u8, in_SHR_d_rm_mod_reg_u8_imm_u8, in_SHR_d_rm_mod_reg_u8_imm_u8, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_SAR_d_rm_mod_reg_u8_imm_u8, in_SAR_d_rm_mod_reg_u8_imm_u8, in_SAR_d_rm_mod_reg_u8_imm_u8, in_SAR_d_rm_mod_reg_u8_imm_u8, in_SAR_d_rm_mod_reg_u8_imm_u8, in_SAR_d_rm_mod_reg_u8_imm_u8, in_SAR_d_rm_mod_reg_u8_imm_u8, in_SAR_d_rm_mod_reg_u8_imm_u8, 
	// 80
	in_ROL_d_rm_mod_reg_u8_imm_u8, in_ROL_d_rm_mod_reg_u8_imm_u8, in_ROL_d_rm_mod_reg_u8_imm_u8, in_ROL_d_rm_mod_reg_u8_imm_u8, in_ROL_d_rm_mod_reg_u8_imm_u8, in_ROL_d_rm_mod_reg_u8_imm_u8, in_ROL_d_rm_mod_reg_u8_imm_u8, in_ROL_d_rm_mod_reg_u8_imm_u8, 
	// 88
	in_ROR_d_rm_mod_reg_u8_imm_u8, in_ROR_d_rm_mod_reg_u8_imm_u8, in_ROR_d_rm_mod_reg_u8_imm_u8, in_ROR_d_rm_mod_reg_u8_imm_u8, in_ROR_d_rm_mod_reg_u8_imm_u8, in_ROR_d_rm_mod_reg_u8_imm_u8, in_ROR_d_rm_mod_reg_u8_imm_u8, in_ROR_d_rm_mod_reg_u8_imm_u8, 
	// 90
	in_RCL_d_rm_mod_reg_u8_imm_u8, in_RCL_d_rm_mod_reg_u8_imm_u8, in_RCL_d_rm_mod_reg_u8_imm_u8, in_RCL_d_rm_mod_reg_u8_imm_u8, in_RCL_d_rm_mod_reg_u8_imm_u8, in_RCL_d_rm_mod_reg_u8_imm_u8, in_RCL_d_rm_mod_reg_u8_imm_u8, in_RCL_d_rm_mod_reg_u8_imm_u8, 
	// 98
	in_RCR_d_rm_mod_reg_u8_imm_u8, in_RCR_d_rm_mod_reg_u8_imm_u8, in_RCR_d_rm_mod_reg_u8_imm_u8, in_RCR_d_rm_mod_reg_u8_imm_u8, in_RCR_d_rm_mod_reg_u8_imm_u8, in_RCR_d_rm_mod_reg_u8_imm_u8, in_RCR_d_rm_mod_reg_u8_imm_u8, in_RCR_d_rm_mod_reg_u8_imm_u8, 
	// A0
	in_SHL_d_rm_mod_reg_u8_imm_u8, in_SHL_d_rm_mod_reg_u8_imm_u8, in_SHL_d_rm_mod_reg_u8_imm_u8, in_SHL_d_rm_mod_reg_u8_imm_u8, in_SHL_d_rm_mod_reg_u8_imm_u8, in_SHL_d_rm_mod_reg_u8_imm_u8, in_SHL_d_rm_mod_reg_u8_imm_u8, in_SHL_d_rm_mod_reg_u8_imm_u8, 
	// A8
	in_SHR_d_rm_mod_reg_u8_imm_u8, in_SHR_d_rm_mod_reg_u8_imm_u8, in_SHR_d_rm_mod_reg_u8_imm_u8, in_SHR_d_rm_mod_reg_u8_imm_u8, in_SHR_d_rm_mod_reg_u8_imm_u8, in_SHR_d_rm_mod_reg_u8_imm_u8, in_SHR_d_rm_mod_reg_u8_imm_u8, in_SHR_d_rm_mod_reg_u8_imm_u8, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_SAR_d_rm_mod_reg_u8_imm_u8, in_SAR_d_rm_mod_reg_u8_imm_u8, in_SAR_d_rm_mod_reg_u8_imm_u8, in_SAR_d_rm_mod_reg_u8_imm_u8, in_SAR_d_rm_mod_reg_u8_imm_u8, in_SAR_d_rm_mod_reg_u8_imm_u8, in_SAR_d_rm_mod_reg_u8_imm_u8, in_SAR_d_rm_mod_reg_u8_imm_u8, 
	// C0
	in_ROL_d_rm_mod_reg_u8_imm_u8, in_ROL_d_rm_mod_reg_u8_imm_u8, in_ROL_d_rm_mod_reg_u8_imm_u8, in_ROL_d_rm_mod_reg_u8_imm_u8, in_ROL_d_rm_mod_reg_u8_imm_u8, in_ROL_d_rm_mod_reg_u8_imm_u8, in_ROL_d_rm_mod_reg_u8_imm_u8, in_ROL_d_rm_mod_reg_u8_imm_u8, 
	// C8
	in_ROR_d_rm_mod_reg_u8_imm_u8, in_ROR_d_rm_mod_reg_u8_imm_u8, in_ROR_d_rm_mod_reg_u8_imm_u8, in_ROR_d_rm_mod_reg_u8_imm_u8, in_ROR_d_rm_mod_reg_u8_imm_u8, in_ROR_d_rm_mod_reg_u8_imm_u8, in_ROR_d_rm_mod_reg_u8_imm_u8, in_ROR_d_rm_mod_reg_u8_imm_u8, 
	// D0
	in_RCL_d_rm_mod_reg_u8_imm_u8, in_RCL_d_rm_mod_reg_u8_imm_u8, in_RCL_d_rm_mod_reg_u8_imm_u8, in_RCL_d_rm_mod_reg_u8_imm_u8, in_RCL_d_rm_mod_reg_u8_imm_u8, in_RCL_d_rm_mod_reg_u8_imm_u8, in_RCL_d_rm_mod_reg_u8_imm_u8, in_RCL_d_rm_mod_reg_u8_imm_u8, 
	// D8
	in_RCR_d_rm_mod_reg_u8_imm_u8, in_RCR_d_rm_mod_reg_u8_imm_u8, in_RCR_d_rm_mod_reg_u8_imm_u8, in_RCR_d_rm_mod_reg_u8_imm_u8, in_RCR_d_rm_mod_reg_u8_imm_u8, in_RCR_d_rm_mod_reg_u8_imm_u8, in_RCR_d_rm_mod_reg_u8_imm_u8, in_RCR_d_rm_mod_reg_u8_imm_u8, 
	// E0
	in_SHL_d_rm_mod_reg_u8_imm_u8, in_SHL_d_rm_mod_reg_u8_imm_u8, in_SHL_d_rm_mod_reg_u8_imm_u8, in_SHL_d_rm_mod_reg_u8_imm_u8, in_SHL_d_rm_mod_reg_u8_imm_u8, in_SHL_d_rm_mod_reg_u8_imm_u8, in_SHL_d_rm_mod_reg_u8_imm_u8, in_SHL_d_rm_mod_reg_u8_imm_u8, 
	// E8
	in_SHR_d_rm_mod_reg_u8_imm_u8, in_SHR_d_rm_mod_reg_u8_imm_u8, in_SHR_d_rm_mod_reg_u8_imm_u8, in_SHR_d_rm_mod_reg_u8_imm_u8, in_SHR_d_rm_mod_reg_u8_imm_u8, in_SHR_d_rm_mod_reg_u8_imm_u8, in_SHR_d_rm_mod_reg_u8_imm_u8, in_SHR_d_rm_mod_reg_u8_imm_u8, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_SAR_d_rm_mod_reg_u8_imm_u8, in_SAR_d_rm_mod_reg_u8_imm_u8, in_SAR_d_rm_mod_reg_u8_imm_u8, in_SAR_d_rm_mod_reg_u8_imm_u8, in_SAR_d_rm_mod_reg_u8_imm_u8, in_SAR_d_rm_mod_reg_u8_imm_u8, in_SAR_d_rm_mod_reg_u8_imm_u8, in_SAR_d_rm_mod_reg_u8_imm_u8, 
};
const OpState CpuRunnerX86::table_st_w_w_C1[] = {
	// 00
	in_ROL_w_rm_mod_reg_u16_imm_u8, in_ROL_w_rm_mod_reg_u16_imm_u8, in_ROL_w_rm_mod_reg_u16_imm_u8, in_ROL_w_rm_mod_reg_u16_imm_u8, in_ROL_w_rm_mod_reg_u16_imm_u8, in_ROL_w_rm_mod_reg_u16_imm_u8, in_ROL_w_rm_mod_reg_u16_imm_u8, in_ROL_w_rm_mod_reg_u16_imm_u8, 
	// 08
	in_ROR_w_rm_mod_reg_u16_imm_u8, in_ROR_w_rm_mod_reg_u16_imm_u8, in_ROR_w_rm_mod_reg_u16_imm_u8, in_ROR_w_rm_mod_reg_u16_imm_u8, in_ROR_w_rm_mod_reg_u16_imm_u8, in_ROR_w_rm_mod_reg_u16_imm_u8, in_ROR_w_rm_mod_reg_u16_imm_u8, in_ROR_w_rm_mod_reg_u16_imm_u8, 
	// 10
	in_RCL_w_rm_mod_reg_u16_imm_u8, in_RCL_w_rm_mod_reg_u16_imm_u8, in_RCL_w_rm_mod_reg_u16_imm_u8, in_RCL_w_rm_mod_reg_u16_imm_u8, in_RCL_w_rm_mod_reg_u16_imm_u8, in_RCL_w_rm_mod_reg_u16_imm_u8, in_RCL_w_rm_mod_reg_u16_imm_u8, in_RCL_w_rm_mod_reg_u16_imm_u8, 
	// 18
	in_RCR_w_rm_mod_reg_u16_imm_u8, in_RCR_w_rm_mod_reg_u16_imm_u8, in_RCR_w_rm_mod_reg_u16_imm_u8, in_RCR_w_rm_mod_reg_u16_imm_u8, in_RCR_w_rm_mod_reg_u16_imm_u8, in_RCR_w_rm_mod_reg_u16_imm_u8, in_RCR_w_rm_mod_reg_u16_imm_u8, in_RCR_w_rm_mod_reg_u16_imm_u8, 
	// 20
	in_SHL_w_rm_mod_reg_u16_imm_u8, in_SHL_w_rm_mod_reg_u16_imm_u8, in_SHL_w_rm_mod_reg_u16_imm_u8, in_SHL_w_rm_mod_reg_u16_imm_u8, in_SHL_w_rm_mod_reg_u16_imm_u8, in_SHL_w_rm_mod_reg_u16_imm_u8, in_SHL_w_rm_mod_reg_u16_imm_u8, in_SHL_w_rm_mod_reg_u16_imm_u8, 
	// 28
	in_SHR_w_rm_mod_reg_u16_imm_u8, in_SHR_w_rm_mod_reg_u16_imm_u8, in_SHR_w_rm_mod_reg_u16_imm_u8, in_SHR_w_rm_mod_reg_u16_imm_u8, in_SHR_w_rm_mod_reg_u16_imm_u8, in_SHR_w_rm_mod_reg_u16_imm_u8, in_SHR_w_rm_mod_reg_u16_imm_u8, in_SHR_w_rm_mod_reg_u16_imm_u8, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_SAR_w_rm_mod_reg_u16_imm_u8, in_SAR_w_rm_mod_reg_u16_imm_u8, in_SAR_w_rm_mod_reg_u16_imm_u8, in_SAR_w_rm_mod_reg_u16_imm_u8, in_SAR_w_rm_mod_reg_u16_imm_u8, in_SAR_w_rm_mod_reg_u16_imm_u8, in_SAR_w_rm_mod_reg_u16_imm_u8, in_SAR_w_rm_mod_reg_u16_imm_u8, 
	// 40
	in_ROL_w_rm_mod_reg_u16_imm_u8, in_ROL_w_rm_mod_reg_u16_imm_u8, in_ROL_w_rm_mod_reg_u16_imm_u8, in_ROL_w_rm_mod_reg_u16_imm_u8, in_ROL_w_rm_mod_reg_u16_imm_u8, in_ROL_w_rm_mod_reg_u16_imm_u8, in_ROL_w_rm_mod_reg_u16_imm_u8, in_ROL_w_rm_mod_reg_u16_imm_u8, 
	// 48
	in_ROR_w_rm_mod_reg_u16_imm_u8, in_ROR_w_rm_mod_reg_u16_imm_u8, in_ROR_w_rm_mod_reg_u16_imm_u8, in_ROR_w_rm_mod_reg_u16_imm_u8, in_ROR_w_rm_mod_reg_u16_imm_u8, in_ROR_w_rm_mod_reg_u16_imm_u8, in_ROR_w_rm_mod_reg_u16_imm_u8, in_ROR_w_rm_mod_reg_u16_imm_u8, 
	// 50
	in_RCL_w_rm_mod_reg_u16_imm_u8, in_RCL_w_rm_mod_reg_u16_imm_u8, in_RCL_w_rm_mod_reg_u16_imm_u8, in_RCL_w_rm_mod_reg_u16_imm_u8, in_RCL_w_rm_mod_reg_u16_imm_u8, in_RCL_w_rm_mod_reg_u16_imm_u8, in_RCL_w_rm_mod_reg_u16_imm_u8, in_RCL_w_rm_mod_reg_u16_imm_u8, 
	// 58
	in_RCR_w_rm_mod_reg_u16_imm_u8, in_RCR_w_rm_mod_reg_u16_imm_u8, in_RCR_w_rm_mod_reg_u16_imm_u8, in_RCR_w_rm_mod_reg_u16_imm_u8, in_RCR_w_rm_mod_reg_u16_imm_u8, in_RCR_w_rm_mod_reg_u16_imm_u8, in_RCR_w_rm_mod_reg_u16_imm_u8, in_RCR_w_rm_mod_reg_u16_imm_u8, 
	// 60
	in_SHL_w_rm_mod_reg_u16_imm_u8, in_SHL_w_rm_mod_reg_u16_imm_u8, in_SHL_w_rm_mod_reg_u16_imm_u8, in_SHL_w_rm_mod_reg_u16_imm_u8, in_SHL_w_rm_mod_reg_u16_imm_u8, in_SHL_w_rm_mod_reg_u16_imm_u8, in_SHL_w_rm_mod_reg_u16_imm_u8, in_SHL_w_rm_mod_reg_u16_imm_u8, 
	// 68
	in_SHR_w_rm_mod_reg_u16_imm_u8, in_SHR_w_rm_mod_reg_u16_imm_u8, in_SHR_w_rm_mod_reg_u16_imm_u8, in_SHR_w_rm_mod_reg_u16_imm_u8, in_SHR_w_rm_mod_reg_u16_imm_u8, in_SHR_w_rm_mod_reg_u16_imm_u8, in_SHR_w_rm_mod_reg_u16_imm_u8, in_SHR_w_rm_mod_reg_u16_imm_u8, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_SAR_w_rm_mod_reg_u16_imm_u8, in_SAR_w_rm_mod_reg_u16_imm_u8, in_SAR_w_rm_mod_reg_u16_imm_u8, in_SAR_w_rm_mod_reg_u16_imm_u8, in_SAR_w_rm_mod_reg_u16_imm_u8, in_SAR_w_rm_mod_reg_u16_imm_u8, in_SAR_w_rm_mod_reg_u16_imm_u8, in_SAR_w_rm_mod_reg_u16_imm_u8, 
	// 80
	in_ROL_w_rm_mod_reg_u16_imm_u8, in_ROL_w_rm_mod_reg_u16_imm_u8, in_ROL_w_rm_mod_reg_u16_imm_u8, in_ROL_w_rm_mod_reg_u16_imm_u8, in_ROL_w_rm_mod_reg_u16_imm_u8, in_ROL_w_rm_mod_reg_u16_imm_u8, in_ROL_w_rm_mod_reg_u16_imm_u8, in_ROL_w_rm_mod_reg_u16_imm_u8, 
	// 88
	in_ROR_w_rm_mod_reg_u16_imm_u8, in_ROR_w_rm_mod_reg_u16_imm_u8, in_ROR_w_rm_mod_reg_u16_imm_u8, in_ROR_w_rm_mod_reg_u16_imm_u8, in_ROR_w_rm_mod_reg_u16_imm_u8, in_ROR_w_rm_mod_reg_u16_imm_u8, in_ROR_w_rm_mod_reg_u16_imm_u8, in_ROR_w_rm_mod_reg_u16_imm_u8, 
	// 90
	in_RCL_w_rm_mod_reg_u16_imm_u8, in_RCL_w_rm_mod_reg_u16_imm_u8, in_RCL_w_rm_mod_reg_u16_imm_u8, in_RCL_w_rm_mod_reg_u16_imm_u8, in_RCL_w_rm_mod_reg_u16_imm_u8, in_RCL_w_rm_mod_reg_u16_imm_u8, in_RCL_w_rm_mod_reg_u16_imm_u8, in_RCL_w_rm_mod_reg_u16_imm_u8, 
	// 98
	in_RCR_w_rm_mod_reg_u16_imm_u8, in_RCR_w_rm_mod_reg_u16_imm_u8, in_RCR_w_rm_mod_reg_u16_imm_u8, in_RCR_w_rm_mod_reg_u16_imm_u8, in_RCR_w_rm_mod_reg_u16_imm_u8, in_RCR_w_rm_mod_reg_u16_imm_u8, in_RCR_w_rm_mod_reg_u16_imm_u8, in_RCR_w_rm_mod_reg_u16_imm_u8, 
	// A0
	in_SHL_w_rm_mod_reg_u16_imm_u8, in_SHL_w_rm_mod_reg_u16_imm_u8, in_SHL_w_rm_mod_reg_u16_imm_u8, in_SHL_w_rm_mod_reg_u16_imm_u8, in_SHL_w_rm_mod_reg_u16_imm_u8, in_SHL_w_rm_mod_reg_u16_imm_u8, in_SHL_w_rm_mod_reg_u16_imm_u8, in_SHL_w_rm_mod_reg_u16_imm_u8, 
	// A8
	in_SHR_w_rm_mod_reg_u16_imm_u8, in_SHR_w_rm_mod_reg_u16_imm_u8, in_SHR_w_rm_mod_reg_u16_imm_u8, in_SHR_w_rm_mod_reg_u16_imm_u8, in_SHR_w_rm_mod_reg_u16_imm_u8, in_SHR_w_rm_mod_reg_u16_imm_u8, in_SHR_w_rm_mod_reg_u16_imm_u8, in_SHR_w_rm_mod_reg_u16_imm_u8, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_SAR_w_rm_mod_reg_u16_imm_u8, in_SAR_w_rm_mod_reg_u16_imm_u8, in_SAR_w_rm_mod_reg_u16_imm_u8, in_SAR_w_rm_mod_reg_u16_imm_u8, in_SAR_w_rm_mod_reg_u16_imm_u8, in_SAR_w_rm_mod_reg_u16_imm_u8, in_SAR_w_rm_mod_reg_u16_imm_u8, in_SAR_w_rm_mod_reg_u16_imm_u8, 
	// C0
	in_ROL_w_rm_mod_reg_u16_imm_u8, in_ROL_w_rm_mod_reg_u16_imm_u8, in_ROL_w_rm_mod_reg_u16_imm_u8, in_ROL_w_rm_mod_reg_u16_imm_u8, in_ROL_w_rm_mod_reg_u16_imm_u8, in_ROL_w_rm_mod_reg_u16_imm_u8, in_ROL_w_rm_mod_reg_u16_imm_u8, in_ROL_w_rm_mod_reg_u16_imm_u8, 
	// C8
	in_ROR_w_rm_mod_reg_u16_imm_u8, in_ROR_w_rm_mod_reg_u16_imm_u8, in_ROR_w_rm_mod_reg_u16_imm_u8, in_ROR_w_rm_mod_reg_u16_imm_u8, in_ROR_w_rm_mod_reg_u16_imm_u8, in_ROR_w_rm_mod_reg_u16_imm_u8, in_ROR_w_rm_mod_reg_u16_imm_u8, in_ROR_w_rm_mod_reg_u16_imm_u8, 
	// D0
	in_RCL_w_rm_mod_reg_u16_imm_u8, in_RCL_w_rm_mod_reg_u16_imm_u8, in_RCL_w_rm_mod_reg_u16_imm_u8, in_RCL_w_rm_mod_reg_u16_imm_u8, in_RCL_w_rm_mod_reg_u16_imm_u8, in_RCL_w_rm_mod_reg_u16_imm_u8, in_RCL_w_rm_mod_reg_u16_imm_u8, in_RCL_w_rm_mod_reg_u16_imm_u8, 
	// D8
	in_RCR_w_rm_mod_reg_u16_imm_u8, in_RCR_w_rm_mod_reg_u16_imm_u8, in_RCR_w_rm_mod_reg_u16_imm_u8, in_RCR_w_rm_mod_reg_u16_imm_u8, in_RCR_w_rm_mod_reg_u16_imm_u8, in_RCR_w_rm_mod_reg_u16_imm_u8, in_RCR_w_rm_mod_reg_u16_imm_u8, in_RCR_w_rm_mod_reg_u16_imm_u8, 
	// E0
	in_SHL_w_rm_mod_reg_u16_imm_u8, in_SHL_w_rm_mod_reg_u16_imm_u8, in_SHL_w_rm_mod_reg_u16_imm_u8, in_SHL_w_rm_mod_reg_u16_imm_u8, in_SHL_w_rm_mod_reg_u16_imm_u8, in_SHL_w_rm_mod_reg_u16_imm_u8, in_SHL_w_rm_mod_reg_u16_imm_u8, in_SHL_w_rm_mod_reg_u16_imm_u8, 
	// E8
	in_SHR_w_rm_mod_reg_u16_imm_u8, in_SHR_w_rm_mod_reg_u16_imm_u8, in_SHR_w_rm_mod_reg_u16_imm_u8, in_SHR_w_rm_mod_reg_u16_imm_u8, in_SHR_w_rm_mod_reg_u16_imm_u8, in_SHR_w_rm_mod_reg_u16_imm_u8, in_SHR_w_rm_mod_reg_u16_imm_u8, in_SHR_w_rm_mod_reg_u16_imm_u8, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_SAR_w_rm_mod_reg_u16_imm_u8, in_SAR_w_rm_mod_reg_u16_imm_u8, in_SAR_w_rm_mod_reg_u16_imm_u8, in_SAR_w_rm_mod_reg_u16_imm_u8, in_SAR_w_rm_mod_reg_u16_imm_u8, in_SAR_w_rm_mod_reg_u16_imm_u8, in_SAR_w_rm_mod_reg_u16_imm_u8, in_SAR_w_rm_mod_reg_u16_imm_u8, 
};
const OpState CpuRunnerX86::table_st_w_d_C1[] = {
	// 00
	in_ROL_w_rm_mod_reg_u32_imm_u8, in_ROL_w_rm_mod_reg_u32_imm_u8, in_ROL_w_rm_mod_reg_u32_imm_u8, in_ROL_w_rm_mod_reg_u32_imm_u8, in_ROL_w_rm_mod_reg_u32_imm_u8, in_ROL_w_rm_mod_reg_u32_imm_u8, in_ROL_w_rm_mod_reg_u32_imm_u8, in_ROL_w_rm_mod_reg_u32_imm_u8, 
	// 08
	in_ROR_w_rm_mod_reg_u32_imm_u8, in_ROR_w_rm_mod_reg_u32_imm_u8, in_ROR_w_rm_mod_reg_u32_imm_u8, in_ROR_w_rm_mod_reg_u32_imm_u8, in_ROR_w_rm_mod_reg_u32_imm_u8, in_ROR_w_rm_mod_reg_u32_imm_u8, in_ROR_w_rm_mod_reg_u32_imm_u8, in_ROR_w_rm_mod_reg_u32_imm_u8, 
	// 10
	in_RCL_w_rm_mod_reg_u32_imm_u8, in_RCL_w_rm_mod_reg_u32_imm_u8, in_RCL_w_rm_mod_reg_u32_imm_u8, in_RCL_w_rm_mod_reg_u32_imm_u8, in_RCL_w_rm_mod_reg_u32_imm_u8, in_RCL_w_rm_mod_reg_u32_imm_u8, in_RCL_w_rm_mod_reg_u32_imm_u8, in_RCL_w_rm_mod_reg_u32_imm_u8, 
	// 18
	in_RCR_w_rm_mod_reg_u32_imm_u8, in_RCR_w_rm_mod_reg_u32_imm_u8, in_RCR_w_rm_mod_reg_u32_imm_u8, in_RCR_w_rm_mod_reg_u32_imm_u8, in_RCR_w_rm_mod_reg_u32_imm_u8, in_RCR_w_rm_mod_reg_u32_imm_u8, in_RCR_w_rm_mod_reg_u32_imm_u8, in_RCR_w_rm_mod_reg_u32_imm_u8, 
	// 20
	in_SHL_w_rm_mod_reg_u32_imm_u8, in_SHL_w_rm_mod_reg_u32_imm_u8, in_SHL_w_rm_mod_reg_u32_imm_u8, in_SHL_w_rm_mod_reg_u32_imm_u8, in_SHL_w_rm_mod_reg_u32_imm_u8, in_SHL_w_rm_mod_reg_u32_imm_u8, in_SHL_w_rm_mod_reg_u32_imm_u8, in_SHL_w_rm_mod_reg_u32_imm_u8, 
	// 28
	in_SHR_w_rm_mod_reg_u32_imm_u8, in_SHR_w_rm_mod_reg_u32_imm_u8, in_SHR_w_rm_mod_reg_u32_imm_u8, in_SHR_w_rm_mod_reg_u32_imm_u8, in_SHR_w_rm_mod_reg_u32_imm_u8, in_SHR_w_rm_mod_reg_u32_imm_u8, in_SHR_w_rm_mod_reg_u32_imm_u8, in_SHR_w_rm_mod_reg_u32_imm_u8, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_SAR_w_rm_mod_reg_u32_imm_u8, in_SAR_w_rm_mod_reg_u32_imm_u8, in_SAR_w_rm_mod_reg_u32_imm_u8, in_SAR_w_rm_mod_reg_u32_imm_u8, in_SAR_w_rm_mod_reg_u32_imm_u8, in_SAR_w_rm_mod_reg_u32_imm_u8, in_SAR_w_rm_mod_reg_u32_imm_u8, in_SAR_w_rm_mod_reg_u32_imm_u8, 
	// 40
	in_ROL_w_rm_mod_reg_u32_imm_u8, in_ROL_w_rm_mod_reg_u32_imm_u8, in_ROL_w_rm_mod_reg_u32_imm_u8, in_ROL_w_rm_mod_reg_u32_imm_u8, in_ROL_w_rm_mod_reg_u32_imm_u8, in_ROL_w_rm_mod_reg_u32_imm_u8, in_ROL_w_rm_mod_reg_u32_imm_u8, in_ROL_w_rm_mod_reg_u32_imm_u8, 
	// 48
	in_ROR_w_rm_mod_reg_u32_imm_u8, in_ROR_w_rm_mod_reg_u32_imm_u8, in_ROR_w_rm_mod_reg_u32_imm_u8, in_ROR_w_rm_mod_reg_u32_imm_u8, in_ROR_w_rm_mod_reg_u32_imm_u8, in_ROR_w_rm_mod_reg_u32_imm_u8, in_ROR_w_rm_mod_reg_u32_imm_u8, in_ROR_w_rm_mod_reg_u32_imm_u8, 
	// 50
	in_RCL_w_rm_mod_reg_u32_imm_u8, in_RCL_w_rm_mod_reg_u32_imm_u8, in_RCL_w_rm_mod_reg_u32_imm_u8, in_RCL_w_rm_mod_reg_u32_imm_u8, in_RCL_w_rm_mod_reg_u32_imm_u8, in_RCL_w_rm_mod_reg_u32_imm_u8, in_RCL_w_rm_mod_reg_u32_imm_u8, in_RCL_w_rm_mod_reg_u32_imm_u8, 
	// 58
	in_RCR_w_rm_mod_reg_u32_imm_u8, in_RCR_w_rm_mod_reg_u32_imm_u8, in_RCR_w_rm_mod_reg_u32_imm_u8, in_RCR_w_rm_mod_reg_u32_imm_u8, in_RCR_w_rm_mod_reg_u32_imm_u8, in_RCR_w_rm_mod_reg_u32_imm_u8, in_RCR_w_rm_mod_reg_u32_imm_u8, in_RCR_w_rm_mod_reg_u32_imm_u8, 
	// 60
	in_SHL_w_rm_mod_reg_u32_imm_u8, in_SHL_w_rm_mod_reg_u32_imm_u8, in_SHL_w_rm_mod_reg_u32_imm_u8, in_SHL_w_rm_mod_reg_u32_imm_u8, in_SHL_w_rm_mod_reg_u32_imm_u8, in_SHL_w_rm_mod_reg_u32_imm_u8, in_SHL_w_rm_mod_reg_u32_imm_u8, in_SHL_w_rm_mod_reg_u32_imm_u8, 
	// 68
	in_SHR_w_rm_mod_reg_u32_imm_u8, in_SHR_w_rm_mod_reg_u32_imm_u8, in_SHR_w_rm_mod_reg_u32_imm_u8, in_SHR_w_rm_mod_reg_u32_imm_u8, in_SHR_w_rm_mod_reg_u32_imm_u8, in_SHR_w_rm_mod_reg_u32_imm_u8, in_SHR_w_rm_mod_reg_u32_imm_u8, in_SHR_w_rm_mod_reg_u32_imm_u8, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_SAR_w_rm_mod_reg_u32_imm_u8, in_SAR_w_rm_mod_reg_u32_imm_u8, in_SAR_w_rm_mod_reg_u32_imm_u8, in_SAR_w_rm_mod_reg_u32_imm_u8, in_SAR_w_rm_mod_reg_u32_imm_u8, in_SAR_w_rm_mod_reg_u32_imm_u8, in_SAR_w_rm_mod_reg_u32_imm_u8, in_SAR_w_rm_mod_reg_u32_imm_u8, 
	// 80
	in_ROL_w_rm_mod_reg_u32_imm_u8, in_ROL_w_rm_mod_reg_u32_imm_u8, in_ROL_w_rm_mod_reg_u32_imm_u8, in_ROL_w_rm_mod_reg_u32_imm_u8, in_ROL_w_rm_mod_reg_u32_imm_u8, in_ROL_w_rm_mod_reg_u32_imm_u8, in_ROL_w_rm_mod_reg_u32_imm_u8, in_ROL_w_rm_mod_reg_u32_imm_u8, 
	// 88
	in_ROR_w_rm_mod_reg_u32_imm_u8, in_ROR_w_rm_mod_reg_u32_imm_u8, in_ROR_w_rm_mod_reg_u32_imm_u8, in_ROR_w_rm_mod_reg_u32_imm_u8, in_ROR_w_rm_mod_reg_u32_imm_u8, in_ROR_w_rm_mod_reg_u32_imm_u8, in_ROR_w_rm_mod_reg_u32_imm_u8, in_ROR_w_rm_mod_reg_u32_imm_u8, 
	// 90
	in_RCL_w_rm_mod_reg_u32_imm_u8, in_RCL_w_rm_mod_reg_u32_imm_u8, in_RCL_w_rm_mod_reg_u32_imm_u8, in_RCL_w_rm_mod_reg_u32_imm_u8, in_RCL_w_rm_mod_reg_u32_imm_u8, in_RCL_w_rm_mod_reg_u32_imm_u8, in_RCL_w_rm_mod_reg_u32_imm_u8, in_RCL_w_rm_mod_reg_u32_imm_u8, 
	// 98
	in_RCR_w_rm_mod_reg_u32_imm_u8, in_RCR_w_rm_mod_reg_u32_imm_u8, in_RCR_w_rm_mod_reg_u32_imm_u8, in_RCR_w_rm_mod_reg_u32_imm_u8, in_RCR_w_rm_mod_reg_u32_imm_u8, in_RCR_w_rm_mod_reg_u32_imm_u8, in_RCR_w_rm_mod_reg_u32_imm_u8, in_RCR_w_rm_mod_reg_u32_imm_u8, 
	// A0
	in_SHL_w_rm_mod_reg_u32_imm_u8, in_SHL_w_rm_mod_reg_u32_imm_u8, in_SHL_w_rm_mod_reg_u32_imm_u8, in_SHL_w_rm_mod_reg_u32_imm_u8, in_SHL_w_rm_mod_reg_u32_imm_u8, in_SHL_w_rm_mod_reg_u32_imm_u8, in_SHL_w_rm_mod_reg_u32_imm_u8, in_SHL_w_rm_mod_reg_u32_imm_u8, 
	// A8
	in_SHR_w_rm_mod_reg_u32_imm_u8, in_SHR_w_rm_mod_reg_u32_imm_u8, in_SHR_w_rm_mod_reg_u32_imm_u8, in_SHR_w_rm_mod_reg_u32_imm_u8, in_SHR_w_rm_mod_reg_u32_imm_u8, in_SHR_w_rm_mod_reg_u32_imm_u8, in_SHR_w_rm_mod_reg_u32_imm_u8, in_SHR_w_rm_mod_reg_u32_imm_u8, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_SAR_w_rm_mod_reg_u32_imm_u8, in_SAR_w_rm_mod_reg_u32_imm_u8, in_SAR_w_rm_mod_reg_u32_imm_u8, in_SAR_w_rm_mod_reg_u32_imm_u8, in_SAR_w_rm_mod_reg_u32_imm_u8, in_SAR_w_rm_mod_reg_u32_imm_u8, in_SAR_w_rm_mod_reg_u32_imm_u8, in_SAR_w_rm_mod_reg_u32_imm_u8, 
	// C0
	in_ROL_w_rm_mod_reg_u32_imm_u8, in_ROL_w_rm_mod_reg_u32_imm_u8, in_ROL_w_rm_mod_reg_u32_imm_u8, in_ROL_w_rm_mod_reg_u32_imm_u8, in_ROL_w_rm_mod_reg_u32_imm_u8, in_ROL_w_rm_mod_reg_u32_imm_u8, in_ROL_w_rm_mod_reg_u32_imm_u8, in_ROL_w_rm_mod_reg_u32_imm_u8, 
	// C8
	in_ROR_w_rm_mod_reg_u32_imm_u8, in_ROR_w_rm_mod_reg_u32_imm_u8, in_ROR_w_rm_mod_reg_u32_imm_u8, in_ROR_w_rm_mod_reg_u32_imm_u8, in_ROR_w_rm_mod_reg_u32_imm_u8, in_ROR_w_rm_mod_reg_u32_imm_u8, in_ROR_w_rm_mod_reg_u32_imm_u8, in_ROR_w_rm_mod_reg_u32_imm_u8, 
	// D0
	in_RCL_w_rm_mod_reg_u32_imm_u8, in_RCL_w_rm_mod_reg_u32_imm_u8, in_RCL_w_rm_mod_reg_u32_imm_u8, in_RCL_w_rm_mod_reg_u32_imm_u8, in_RCL_w_rm_mod_reg_u32_imm_u8, in_RCL_w_rm_mod_reg_u32_imm_u8, in_RCL_w_rm_mod_reg_u32_imm_u8, in_RCL_w_rm_mod_reg_u32_imm_u8, 
	// D8
	in_RCR_w_rm_mod_reg_u32_imm_u8, in_RCR_w_rm_mod_reg_u32_imm_u8, in_RCR_w_rm_mod_reg_u32_imm_u8, in_RCR_w_rm_mod_reg_u32_imm_u8, in_RCR_w_rm_mod_reg_u32_imm_u8, in_RCR_w_rm_mod_reg_u32_imm_u8, in_RCR_w_rm_mod_reg_u32_imm_u8, in_RCR_w_rm_mod_reg_u32_imm_u8, 
	// E0
	in_SHL_w_rm_mod_reg_u32_imm_u8, in_SHL_w_rm_mod_reg_u32_imm_u8, in_SHL_w_rm_mod_reg_u32_imm_u8, in_SHL_w_rm_mod_reg_u32_imm_u8, in_SHL_w_rm_mod_reg_u32_imm_u8, in_SHL_w_rm_mod_reg_u32_imm_u8, in_SHL_w_rm_mod_reg_u32_imm_u8, in_SHL_w_rm_mod_reg_u32_imm_u8, 
	// E8
	in_SHR_w_rm_mod_reg_u32_imm_u8, in_SHR_w_rm_mod_reg_u32_imm_u8, in_SHR_w_rm_mod_reg_u32_imm_u8, in_SHR_w_rm_mod_reg_u32_imm_u8, in_SHR_w_rm_mod_reg_u32_imm_u8, in_SHR_w_rm_mod_reg_u32_imm_u8, in_SHR_w_rm_mod_reg_u32_imm_u8, in_SHR_w_rm_mod_reg_u32_imm_u8, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_SAR_w_rm_mod_reg_u32_imm_u8, in_SAR_w_rm_mod_reg_u32_imm_u8, in_SAR_w_rm_mod_reg_u32_imm_u8, in_SAR_w_rm_mod_reg_u32_imm_u8, in_SAR_w_rm_mod_reg_u32_imm_u8, in_SAR_w_rm_mod_reg_u32_imm_u8, in_SAR_w_rm_mod_reg_u32_imm_u8, in_SAR_w_rm_mod_reg_u32_imm_u8, 
};
const OpState CpuRunnerX86::table_st_d_w_C1[] = {
	// 00
	in_ROL_d_rm_mod_reg_u16_imm_u8, in_ROL_d_rm_mod_reg_u16_imm_u8, in_ROL_d_rm_mod_reg_u16_imm_u8, in_ROL_d_rm_mod_reg_u16_imm_u8, in_ROL_d_rm_mod_reg_u16_imm_u8, in_ROL_d_rm_mod_reg_u16_imm_u8, in_ROL_d_rm_mod_reg_u16_imm_u8, in_ROL_d_rm_mod_reg_u16_imm_u8, 
	// 08
	in_ROR_d_rm_mod_reg_u16_imm_u8, in_ROR_d_rm_mod_reg_u16_imm_u8, in_ROR_d_rm_mod_reg_u16_imm_u8, in_ROR_d_rm_mod_reg_u16_imm_u8, in_ROR_d_rm_mod_reg_u16_imm_u8, in_ROR_d_rm_mod_reg_u16_imm_u8, in_ROR_d_rm_mod_reg_u16_imm_u8, in_ROR_d_rm_mod_reg_u16_imm_u8, 
	// 10
	in_RCL_d_rm_mod_reg_u16_imm_u8, in_RCL_d_rm_mod_reg_u16_imm_u8, in_RCL_d_rm_mod_reg_u16_imm_u8, in_RCL_d_rm_mod_reg_u16_imm_u8, in_RCL_d_rm_mod_reg_u16_imm_u8, in_RCL_d_rm_mod_reg_u16_imm_u8, in_RCL_d_rm_mod_reg_u16_imm_u8, in_RCL_d_rm_mod_reg_u16_imm_u8, 
	// 18
	in_RCR_d_rm_mod_reg_u16_imm_u8, in_RCR_d_rm_mod_reg_u16_imm_u8, in_RCR_d_rm_mod_reg_u16_imm_u8, in_RCR_d_rm_mod_reg_u16_imm_u8, in_RCR_d_rm_mod_reg_u16_imm_u8, in_RCR_d_rm_mod_reg_u16_imm_u8, in_RCR_d_rm_mod_reg_u16_imm_u8, in_RCR_d_rm_mod_reg_u16_imm_u8, 
	// 20
	in_SHL_d_rm_mod_reg_u16_imm_u8, in_SHL_d_rm_mod_reg_u16_imm_u8, in_SHL_d_rm_mod_reg_u16_imm_u8, in_SHL_d_rm_mod_reg_u16_imm_u8, in_SHL_d_rm_mod_reg_u16_imm_u8, in_SHL_d_rm_mod_reg_u16_imm_u8, in_SHL_d_rm_mod_reg_u16_imm_u8, in_SHL_d_rm_mod_reg_u16_imm_u8, 
	// 28
	in_SHR_d_rm_mod_reg_u16_imm_u8, in_SHR_d_rm_mod_reg_u16_imm_u8, in_SHR_d_rm_mod_reg_u16_imm_u8, in_SHR_d_rm_mod_reg_u16_imm_u8, in_SHR_d_rm_mod_reg_u16_imm_u8, in_SHR_d_rm_mod_reg_u16_imm_u8, in_SHR_d_rm_mod_reg_u16_imm_u8, in_SHR_d_rm_mod_reg_u16_imm_u8, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_SAR_d_rm_mod_reg_u16_imm_u8, in_SAR_d_rm_mod_reg_u16_imm_u8, in_SAR_d_rm_mod_reg_u16_imm_u8, in_SAR_d_rm_mod_reg_u16_imm_u8, in_SAR_d_rm_mod_reg_u16_imm_u8, in_SAR_d_rm_mod_reg_u16_imm_u8, in_SAR_d_rm_mod_reg_u16_imm_u8, in_SAR_d_rm_mod_reg_u16_imm_u8, 
	// 40
	in_ROL_d_rm_mod_reg_u16_imm_u8, in_ROL_d_rm_mod_reg_u16_imm_u8, in_ROL_d_rm_mod_reg_u16_imm_u8, in_ROL_d_rm_mod_reg_u16_imm_u8, in_ROL_d_rm_mod_reg_u16_imm_u8, in_ROL_d_rm_mod_reg_u16_imm_u8, in_ROL_d_rm_mod_reg_u16_imm_u8, in_ROL_d_rm_mod_reg_u16_imm_u8, 
	// 48
	in_ROR_d_rm_mod_reg_u16_imm_u8, in_ROR_d_rm_mod_reg_u16_imm_u8, in_ROR_d_rm_mod_reg_u16_imm_u8, in_ROR_d_rm_mod_reg_u16_imm_u8, in_ROR_d_rm_mod_reg_u16_imm_u8, in_ROR_d_rm_mod_reg_u16_imm_u8, in_ROR_d_rm_mod_reg_u16_imm_u8, in_ROR_d_rm_mod_reg_u16_imm_u8, 
	// 50
	in_RCL_d_rm_mod_reg_u16_imm_u8, in_RCL_d_rm_mod_reg_u16_imm_u8, in_RCL_d_rm_mod_reg_u16_imm_u8, in_RCL_d_rm_mod_reg_u16_imm_u8, in_RCL_d_rm_mod_reg_u16_imm_u8, in_RCL_d_rm_mod_reg_u16_imm_u8, in_RCL_d_rm_mod_reg_u16_imm_u8, in_RCL_d_rm_mod_reg_u16_imm_u8, 
	// 58
	in_RCR_d_rm_mod_reg_u16_imm_u8, in_RCR_d_rm_mod_reg_u16_imm_u8, in_RCR_d_rm_mod_reg_u16_imm_u8, in_RCR_d_rm_mod_reg_u16_imm_u8, in_RCR_d_rm_mod_reg_u16_imm_u8, in_RCR_d_rm_mod_reg_u16_imm_u8, in_RCR_d_rm_mod_reg_u16_imm_u8, in_RCR_d_rm_mod_reg_u16_imm_u8, 
	// 60
	in_SHL_d_rm_mod_reg_u16_imm_u8, in_SHL_d_rm_mod_reg_u16_imm_u8, in_SHL_d_rm_mod_reg_u16_imm_u8, in_SHL_d_rm_mod_reg_u16_imm_u8, in_SHL_d_rm_mod_reg_u16_imm_u8, in_SHL_d_rm_mod_reg_u16_imm_u8, in_SHL_d_rm_mod_reg_u16_imm_u8, in_SHL_d_rm_mod_reg_u16_imm_u8, 
	// 68
	in_SHR_d_rm_mod_reg_u16_imm_u8, in_SHR_d_rm_mod_reg_u16_imm_u8, in_SHR_d_rm_mod_reg_u16_imm_u8, in_SHR_d_rm_mod_reg_u16_imm_u8, in_SHR_d_rm_mod_reg_u16_imm_u8, in_SHR_d_rm_mod_reg_u16_imm_u8, in_SHR_d_rm_mod_reg_u16_imm_u8, in_SHR_d_rm_mod_reg_u16_imm_u8, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_SAR_d_rm_mod_reg_u16_imm_u8, in_SAR_d_rm_mod_reg_u16_imm_u8, in_SAR_d_rm_mod_reg_u16_imm_u8, in_SAR_d_rm_mod_reg_u16_imm_u8, in_SAR_d_rm_mod_reg_u16_imm_u8, in_SAR_d_rm_mod_reg_u16_imm_u8, in_SAR_d_rm_mod_reg_u16_imm_u8, in_SAR_d_rm_mod_reg_u16_imm_u8, 
	// 80
	in_ROL_d_rm_mod_reg_u16_imm_u8, in_ROL_d_rm_mod_reg_u16_imm_u8, in_ROL_d_rm_mod_reg_u16_imm_u8, in_ROL_d_rm_mod_reg_u16_imm_u8, in_ROL_d_rm_mod_reg_u16_imm_u8, in_ROL_d_rm_mod_reg_u16_imm_u8, in_ROL_d_rm_mod_reg_u16_imm_u8, in_ROL_d_rm_mod_reg_u16_imm_u8, 
	// 88
	in_ROR_d_rm_mod_reg_u16_imm_u8, in_ROR_d_rm_mod_reg_u16_imm_u8, in_ROR_d_rm_mod_reg_u16_imm_u8, in_ROR_d_rm_mod_reg_u16_imm_u8, in_ROR_d_rm_mod_reg_u16_imm_u8, in_ROR_d_rm_mod_reg_u16_imm_u8, in_ROR_d_rm_mod_reg_u16_imm_u8, in_ROR_d_rm_mod_reg_u16_imm_u8, 
	// 90
	in_RCL_d_rm_mod_reg_u16_imm_u8, in_RCL_d_rm_mod_reg_u16_imm_u8, in_RCL_d_rm_mod_reg_u16_imm_u8, in_RCL_d_rm_mod_reg_u16_imm_u8, in_RCL_d_rm_mod_reg_u16_imm_u8, in_RCL_d_rm_mod_reg_u16_imm_u8, in_RCL_d_rm_mod_reg_u16_imm_u8, in_RCL_d_rm_mod_reg_u16_imm_u8, 
	// 98
	in_RCR_d_rm_mod_reg_u16_imm_u8, in_RCR_d_rm_mod_reg_u16_imm_u8, in_RCR_d_rm_mod_reg_u16_imm_u8, in_RCR_d_rm_mod_reg_u16_imm_u8, in_RCR_d_rm_mod_reg_u16_imm_u8, in_RCR_d_rm_mod_reg_u16_imm_u8, in_RCR_d_rm_mod_reg_u16_imm_u8, in_RCR_d_rm_mod_reg_u16_imm_u8, 
	// A0
	in_SHL_d_rm_mod_reg_u16_imm_u8, in_SHL_d_rm_mod_reg_u16_imm_u8, in_SHL_d_rm_mod_reg_u16_imm_u8, in_SHL_d_rm_mod_reg_u16_imm_u8, in_SHL_d_rm_mod_reg_u16_imm_u8, in_SHL_d_rm_mod_reg_u16_imm_u8, in_SHL_d_rm_mod_reg_u16_imm_u8, in_SHL_d_rm_mod_reg_u16_imm_u8, 
	// A8
	in_SHR_d_rm_mod_reg_u16_imm_u8, in_SHR_d_rm_mod_reg_u16_imm_u8, in_SHR_d_rm_mod_reg_u16_imm_u8, in_SHR_d_rm_mod_reg_u16_imm_u8, in_SHR_d_rm_mod_reg_u16_imm_u8, in_SHR_d_rm_mod_reg_u16_imm_u8, in_SHR_d_rm_mod_reg_u16_imm_u8, in_SHR_d_rm_mod_reg_u16_imm_u8, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_SAR_d_rm_mod_reg_u16_imm_u8, in_SAR_d_rm_mod_reg_u16_imm_u8, in_SAR_d_rm_mod_reg_u16_imm_u8, in_SAR_d_rm_mod_reg_u16_imm_u8, in_SAR_d_rm_mod_reg_u16_imm_u8, in_SAR_d_rm_mod_reg_u16_imm_u8, in_SAR_d_rm_mod_reg_u16_imm_u8, in_SAR_d_rm_mod_reg_u16_imm_u8, 
	// C0
	in_ROL_d_rm_mod_reg_u16_imm_u8, in_ROL_d_rm_mod_reg_u16_imm_u8, in_ROL_d_rm_mod_reg_u16_imm_u8, in_ROL_d_rm_mod_reg_u16_imm_u8, in_ROL_d_rm_mod_reg_u16_imm_u8, in_ROL_d_rm_mod_reg_u16_imm_u8, in_ROL_d_rm_mod_reg_u16_imm_u8, in_ROL_d_rm_mod_reg_u16_imm_u8, 
	// C8
	in_ROR_d_rm_mod_reg_u16_imm_u8, in_ROR_d_rm_mod_reg_u16_imm_u8, in_ROR_d_rm_mod_reg_u16_imm_u8, in_ROR_d_rm_mod_reg_u16_imm_u8, in_ROR_d_rm_mod_reg_u16_imm_u8, in_ROR_d_rm_mod_reg_u16_imm_u8, in_ROR_d_rm_mod_reg_u16_imm_u8, in_ROR_d_rm_mod_reg_u16_imm_u8, 
	// D0
	in_RCL_d_rm_mod_reg_u16_imm_u8, in_RCL_d_rm_mod_reg_u16_imm_u8, in_RCL_d_rm_mod_reg_u16_imm_u8, in_RCL_d_rm_mod_reg_u16_imm_u8, in_RCL_d_rm_mod_reg_u16_imm_u8, in_RCL_d_rm_mod_reg_u16_imm_u8, in_RCL_d_rm_mod_reg_u16_imm_u8, in_RCL_d_rm_mod_reg_u16_imm_u8, 
	// D8
	in_RCR_d_rm_mod_reg_u16_imm_u8, in_RCR_d_rm_mod_reg_u16_imm_u8, in_RCR_d_rm_mod_reg_u16_imm_u8, in_RCR_d_rm_mod_reg_u16_imm_u8, in_RCR_d_rm_mod_reg_u16_imm_u8, in_RCR_d_rm_mod_reg_u16_imm_u8, in_RCR_d_rm_mod_reg_u16_imm_u8, in_RCR_d_rm_mod_reg_u16_imm_u8, 
	// E0
	in_SHL_d_rm_mod_reg_u16_imm_u8, in_SHL_d_rm_mod_reg_u16_imm_u8, in_SHL_d_rm_mod_reg_u16_imm_u8, in_SHL_d_rm_mod_reg_u16_imm_u8, in_SHL_d_rm_mod_reg_u16_imm_u8, in_SHL_d_rm_mod_reg_u16_imm_u8, in_SHL_d_rm_mod_reg_u16_imm_u8, in_SHL_d_rm_mod_reg_u16_imm_u8, 
	// E8
	in_SHR_d_rm_mod_reg_u16_imm_u8, in_SHR_d_rm_mod_reg_u16_imm_u8, in_SHR_d_rm_mod_reg_u16_imm_u8, in_SHR_d_rm_mod_reg_u16_imm_u8, in_SHR_d_rm_mod_reg_u16_imm_u8, in_SHR_d_rm_mod_reg_u16_imm_u8, in_SHR_d_rm_mod_reg_u16_imm_u8, in_SHR_d_rm_mod_reg_u16_imm_u8, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_SAR_d_rm_mod_reg_u16_imm_u8, in_SAR_d_rm_mod_reg_u16_imm_u8, in_SAR_d_rm_mod_reg_u16_imm_u8, in_SAR_d_rm_mod_reg_u16_imm_u8, in_SAR_d_rm_mod_reg_u16_imm_u8, in_SAR_d_rm_mod_reg_u16_imm_u8, in_SAR_d_rm_mod_reg_u16_imm_u8, in_SAR_d_rm_mod_reg_u16_imm_u8, 
};
const OpState CpuRunnerX86::table_st_d_d_C1[] = {
	// 00
	in_ROL_d_rm_mod_reg_u32_imm_u8, in_ROL_d_rm_mod_reg_u32_imm_u8, in_ROL_d_rm_mod_reg_u32_imm_u8, in_ROL_d_rm_mod_reg_u32_imm_u8, in_ROL_d_rm_mod_reg_u32_imm_u8, in_ROL_d_rm_mod_reg_u32_imm_u8, in_ROL_d_rm_mod_reg_u32_imm_u8, in_ROL_d_rm_mod_reg_u32_imm_u8, 
	// 08
	in_ROR_d_rm_mod_reg_u32_imm_u8, in_ROR_d_rm_mod_reg_u32_imm_u8, in_ROR_d_rm_mod_reg_u32_imm_u8, in_ROR_d_rm_mod_reg_u32_imm_u8, in_ROR_d_rm_mod_reg_u32_imm_u8, in_ROR_d_rm_mod_reg_u32_imm_u8, in_ROR_d_rm_mod_reg_u32_imm_u8, in_ROR_d_rm_mod_reg_u32_imm_u8, 
	// 10
	in_RCL_d_rm_mod_reg_u32_imm_u8, in_RCL_d_rm_mod_reg_u32_imm_u8, in_RCL_d_rm_mod_reg_u32_imm_u8, in_RCL_d_rm_mod_reg_u32_imm_u8, in_RCL_d_rm_mod_reg_u32_imm_u8, in_RCL_d_rm_mod_reg_u32_imm_u8, in_RCL_d_rm_mod_reg_u32_imm_u8, in_RCL_d_rm_mod_reg_u32_imm_u8, 
	// 18
	in_RCR_d_rm_mod_reg_u32_imm_u8, in_RCR_d_rm_mod_reg_u32_imm_u8, in_RCR_d_rm_mod_reg_u32_imm_u8, in_RCR_d_rm_mod_reg_u32_imm_u8, in_RCR_d_rm_mod_reg_u32_imm_u8, in_RCR_d_rm_mod_reg_u32_imm_u8, in_RCR_d_rm_mod_reg_u32_imm_u8, in_RCR_d_rm_mod_reg_u32_imm_u8, 
	// 20
	in_SHL_d_rm_mod_reg_u32_imm_u8, in_SHL_d_rm_mod_reg_u32_imm_u8, in_SHL_d_rm_mod_reg_u32_imm_u8, in_SHL_d_rm_mod_reg_u32_imm_u8, in_SHL_d_rm_mod_reg_u32_imm_u8, in_SHL_d_rm_mod_reg_u32_imm_u8, in_SHL_d_rm_mod_reg_u32_imm_u8, in_SHL_d_rm_mod_reg_u32_imm_u8, 
	// 28
	in_SHR_d_rm_mod_reg_u32_imm_u8, in_SHR_d_rm_mod_reg_u32_imm_u8, in_SHR_d_rm_mod_reg_u32_imm_u8, in_SHR_d_rm_mod_reg_u32_imm_u8, in_SHR_d_rm_mod_reg_u32_imm_u8, in_SHR_d_rm_mod_reg_u32_imm_u8, in_SHR_d_rm_mod_reg_u32_imm_u8, in_SHR_d_rm_mod_reg_u32_imm_u8, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_SAR_d_rm_mod_reg_u32_imm_u8, in_SAR_d_rm_mod_reg_u32_imm_u8, in_SAR_d_rm_mod_reg_u32_imm_u8, in_SAR_d_rm_mod_reg_u32_imm_u8, in_SAR_d_rm_mod_reg_u32_imm_u8, in_SAR_d_rm_mod_reg_u32_imm_u8, in_SAR_d_rm_mod_reg_u32_imm_u8, in_SAR_d_rm_mod_reg_u32_imm_u8, 
	// 40
	in_ROL_d_rm_mod_reg_u32_imm_u8, in_ROL_d_rm_mod_reg_u32_imm_u8, in_ROL_d_rm_mod_reg_u32_imm_u8, in_ROL_d_rm_mod_reg_u32_imm_u8, in_ROL_d_rm_mod_reg_u32_imm_u8, in_ROL_d_rm_mod_reg_u32_imm_u8, in_ROL_d_rm_mod_reg_u32_imm_u8, in_ROL_d_rm_mod_reg_u32_imm_u8, 
	// 48
	in_ROR_d_rm_mod_reg_u32_imm_u8, in_ROR_d_rm_mod_reg_u32_imm_u8, in_ROR_d_rm_mod_reg_u32_imm_u8, in_ROR_d_rm_mod_reg_u32_imm_u8, in_ROR_d_rm_mod_reg_u32_imm_u8, in_ROR_d_rm_mod_reg_u32_imm_u8, in_ROR_d_rm_mod_reg_u32_imm_u8, in_ROR_d_rm_mod_reg_u32_imm_u8, 
	// 50
	in_RCL_d_rm_mod_reg_u32_imm_u8, in_RCL_d_rm_mod_reg_u32_imm_u8, in_RCL_d_rm_mod_reg_u32_imm_u8, in_RCL_d_rm_mod_reg_u32_imm_u8, in_RCL_d_rm_mod_reg_u32_imm_u8, in_RCL_d_rm_mod_reg_u32_imm_u8, in_RCL_d_rm_mod_reg_u32_imm_u8, in_RCL_d_rm_mod_reg_u32_imm_u8, 
	// 58
	in_RCR_d_rm_mod_reg_u32_imm_u8, in_RCR_d_rm_mod_reg_u32_imm_u8, in_RCR_d_rm_mod_reg_u32_imm_u8, in_RCR_d_rm_mod_reg_u32_imm_u8, in_RCR_d_rm_mod_reg_u32_imm_u8, in_RCR_d_rm_mod_reg_u32_imm_u8, in_RCR_d_rm_mod_reg_u32_imm_u8, in_RCR_d_rm_mod_reg_u32_imm_u8, 
	// 60
	in_SHL_d_rm_mod_reg_u32_imm_u8, in_SHL_d_rm_mod_reg_u32_imm_u8, in_SHL_d_rm_mod_reg_u32_imm_u8, in_SHL_d_rm_mod_reg_u32_imm_u8, in_SHL_d_rm_mod_reg_u32_imm_u8, in_SHL_d_rm_mod_reg_u32_imm_u8, in_SHL_d_rm_mod_reg_u32_imm_u8, in_SHL_d_rm_mod_reg_u32_imm_u8, 
	// 68
	in_SHR_d_rm_mod_reg_u32_imm_u8, in_SHR_d_rm_mod_reg_u32_imm_u8, in_SHR_d_rm_mod_reg_u32_imm_u8, in_SHR_d_rm_mod_reg_u32_imm_u8, in_SHR_d_rm_mod_reg_u32_imm_u8, in_SHR_d_rm_mod_reg_u32_imm_u8, in_SHR_d_rm_mod_reg_u32_imm_u8, in_SHR_d_rm_mod_reg_u32_imm_u8, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_SAR_d_rm_mod_reg_u32_imm_u8, in_SAR_d_rm_mod_reg_u32_imm_u8, in_SAR_d_rm_mod_reg_u32_imm_u8, in_SAR_d_rm_mod_reg_u32_imm_u8, in_SAR_d_rm_mod_reg_u32_imm_u8, in_SAR_d_rm_mod_reg_u32_imm_u8, in_SAR_d_rm_mod_reg_u32_imm_u8, in_SAR_d_rm_mod_reg_u32_imm_u8, 
	// 80
	in_ROL_d_rm_mod_reg_u32_imm_u8, in_ROL_d_rm_mod_reg_u32_imm_u8, in_ROL_d_rm_mod_reg_u32_imm_u8, in_ROL_d_rm_mod_reg_u32_imm_u8, in_ROL_d_rm_mod_reg_u32_imm_u8, in_ROL_d_rm_mod_reg_u32_imm_u8, in_ROL_d_rm_mod_reg_u32_imm_u8, in_ROL_d_rm_mod_reg_u32_imm_u8, 
	// 88
	in_ROR_d_rm_mod_reg_u32_imm_u8, in_ROR_d_rm_mod_reg_u32_imm_u8, in_ROR_d_rm_mod_reg_u32_imm_u8, in_ROR_d_rm_mod_reg_u32_imm_u8, in_ROR_d_rm_mod_reg_u32_imm_u8, in_ROR_d_rm_mod_reg_u32_imm_u8, in_ROR_d_rm_mod_reg_u32_imm_u8, in_ROR_d_rm_mod_reg_u32_imm_u8, 
	// 90
	in_RCL_d_rm_mod_reg_u32_imm_u8, in_RCL_d_rm_mod_reg_u32_imm_u8, in_RCL_d_rm_mod_reg_u32_imm_u8, in_RCL_d_rm_mod_reg_u32_imm_u8, in_RCL_d_rm_mod_reg_u32_imm_u8, in_RCL_d_rm_mod_reg_u32_imm_u8, in_RCL_d_rm_mod_reg_u32_imm_u8, in_RCL_d_rm_mod_reg_u32_imm_u8, 
	// 98
	in_RCR_d_rm_mod_reg_u32_imm_u8, in_RCR_d_rm_mod_reg_u32_imm_u8, in_RCR_d_rm_mod_reg_u32_imm_u8, in_RCR_d_rm_mod_reg_u32_imm_u8, in_RCR_d_rm_mod_reg_u32_imm_u8, in_RCR_d_rm_mod_reg_u32_imm_u8, in_RCR_d_rm_mod_reg_u32_imm_u8, in_RCR_d_rm_mod_reg_u32_imm_u8, 
	// A0
	in_SHL_d_rm_mod_reg_u32_imm_u8, in_SHL_d_rm_mod_reg_u32_imm_u8, in_SHL_d_rm_mod_reg_u32_imm_u8, in_SHL_d_rm_mod_reg_u32_imm_u8, in_SHL_d_rm_mod_reg_u32_imm_u8, in_SHL_d_rm_mod_reg_u32_imm_u8, in_SHL_d_rm_mod_reg_u32_imm_u8, in_SHL_d_rm_mod_reg_u32_imm_u8, 
	// A8
	in_SHR_d_rm_mod_reg_u32_imm_u8, in_SHR_d_rm_mod_reg_u32_imm_u8, in_SHR_d_rm_mod_reg_u32_imm_u8, in_SHR_d_rm_mod_reg_u32_imm_u8, in_SHR_d_rm_mod_reg_u32_imm_u8, in_SHR_d_rm_mod_reg_u32_imm_u8, in_SHR_d_rm_mod_reg_u32_imm_u8, in_SHR_d_rm_mod_reg_u32_imm_u8, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_SAR_d_rm_mod_reg_u32_imm_u8, in_SAR_d_rm_mod_reg_u32_imm_u8, in_SAR_d_rm_mod_reg_u32_imm_u8, in_SAR_d_rm_mod_reg_u32_imm_u8, in_SAR_d_rm_mod_reg_u32_imm_u8, in_SAR_d_rm_mod_reg_u32_imm_u8, in_SAR_d_rm_mod_reg_u32_imm_u8, in_SAR_d_rm_mod_reg_u32_imm_u8, 
	// C0
	in_ROL_d_rm_mod_reg_u32_imm_u8, in_ROL_d_rm_mod_reg_u32_imm_u8, in_ROL_d_rm_mod_reg_u32_imm_u8, in_ROL_d_rm_mod_reg_u32_imm_u8, in_ROL_d_rm_mod_reg_u32_imm_u8, in_ROL_d_rm_mod_reg_u32_imm_u8, in_ROL_d_rm_mod_reg_u32_imm_u8, in_ROL_d_rm_mod_reg_u32_imm_u8, 
	// C8
	in_ROR_d_rm_mod_reg_u32_imm_u8, in_ROR_d_rm_mod_reg_u32_imm_u8, in_ROR_d_rm_mod_reg_u32_imm_u8, in_ROR_d_rm_mod_reg_u32_imm_u8, in_ROR_d_rm_mod_reg_u32_imm_u8, in_ROR_d_rm_mod_reg_u32_imm_u8, in_ROR_d_rm_mod_reg_u32_imm_u8, in_ROR_d_rm_mod_reg_u32_imm_u8, 
	// D0
	in_RCL_d_rm_mod_reg_u32_imm_u8, in_RCL_d_rm_mod_reg_u32_imm_u8, in_RCL_d_rm_mod_reg_u32_imm_u8, in_RCL_d_rm_mod_reg_u32_imm_u8, in_RCL_d_rm_mod_reg_u32_imm_u8, in_RCL_d_rm_mod_reg_u32_imm_u8, in_RCL_d_rm_mod_reg_u32_imm_u8, in_RCL_d_rm_mod_reg_u32_imm_u8, 
	// D8
	in_RCR_d_rm_mod_reg_u32_imm_u8, in_RCR_d_rm_mod_reg_u32_imm_u8, in_RCR_d_rm_mod_reg_u32_imm_u8, in_RCR_d_rm_mod_reg_u32_imm_u8, in_RCR_d_rm_mod_reg_u32_imm_u8, in_RCR_d_rm_mod_reg_u32_imm_u8, in_RCR_d_rm_mod_reg_u32_imm_u8, in_RCR_d_rm_mod_reg_u32_imm_u8, 
	// E0
	in_SHL_d_rm_mod_reg_u32_imm_u8, in_SHL_d_rm_mod_reg_u32_imm_u8, in_SHL_d_rm_mod_reg_u32_imm_u8, in_SHL_d_rm_mod_reg_u32_imm_u8, in_SHL_d_rm_mod_reg_u32_imm_u8, in_SHL_d_rm_mod_reg_u32_imm_u8, in_SHL_d_rm_mod_reg_u32_imm_u8, in_SHL_d_rm_mod_reg_u32_imm_u8, 
	// E8
	in_SHR_d_rm_mod_reg_u32_imm_u8, in_SHR_d_rm_mod_reg_u32_imm_u8, in_SHR_d_rm_mod_reg_u32_imm_u8, in_SHR_d_rm_mod_reg_u32_imm_u8, in_SHR_d_rm_mod_reg_u32_imm_u8, in_SHR_d_rm_mod_reg_u32_imm_u8, in_SHR_d_rm_mod_reg_u32_imm_u8, in_SHR_d_rm_mod_reg_u32_imm_u8, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_SAR_d_rm_mod_reg_u32_imm_u8, in_SAR_d_rm_mod_reg_u32_imm_u8, in_SAR_d_rm_mod_reg_u32_imm_u8, in_SAR_d_rm_mod_reg_u32_imm_u8, in_SAR_d_rm_mod_reg_u32_imm_u8, in_SAR_d_rm_mod_reg_u32_imm_u8, in_SAR_d_rm_mod_reg_u32_imm_u8, in_SAR_d_rm_mod_reg_u32_imm_u8, 
};
const OpState CpuRunnerX86::table_st_w_w_C6[] = {
	// 00
	in_MOV_w_rm_mod_reg_u8_imm_u8, in_MOV_w_rm_mod_reg_u8_imm_u8, in_MOV_w_rm_mod_reg_u8_imm_u8, in_MOV_w_rm_mod_reg_u8_imm_u8, in_MOV_w_rm_mod_reg_u8_imm_u8, in_MOV_w_rm_mod_reg_u8_imm_u8, in_MOV_w_rm_mod_reg_u8_imm_u8, in_MOV_w_rm_mod_reg_u8_imm_u8, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_MOV_w_rm_mod_reg_u8_imm_u8, in_MOV_w_rm_mod_reg_u8_imm_u8, in_MOV_w_rm_mod_reg_u8_imm_u8, in_MOV_w_rm_mod_reg_u8_imm_u8, in_MOV_w_rm_mod_reg_u8_imm_u8, in_MOV_w_rm_mod_reg_u8_imm_u8, in_MOV_w_rm_mod_reg_u8_imm_u8, in_MOV_w_rm_mod_reg_u8_imm_u8, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_MOV_w_rm_mod_reg_u8_imm_u8, in_MOV_w_rm_mod_reg_u8_imm_u8, in_MOV_w_rm_mod_reg_u8_imm_u8, in_MOV_w_rm_mod_reg_u8_imm_u8, in_MOV_w_rm_mod_reg_u8_imm_u8, in_MOV_w_rm_mod_reg_u8_imm_u8, in_MOV_w_rm_mod_reg_u8_imm_u8, in_MOV_w_rm_mod_reg_u8_imm_u8, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_MOV_w_rm_mod_reg_u8_imm_u8, in_MOV_w_rm_mod_reg_u8_imm_u8, in_MOV_w_rm_mod_reg_u8_imm_u8, in_MOV_w_rm_mod_reg_u8_imm_u8, in_MOV_w_rm_mod_reg_u8_imm_u8, in_MOV_w_rm_mod_reg_u8_imm_u8, in_MOV_w_rm_mod_reg_u8_imm_u8, in_MOV_w_rm_mod_reg_u8_imm_u8, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_st_w_d_C6[] = {
	// 00
	in_MOV_w_rm_mod_reg_u8_imm_u8, in_MOV_w_rm_mod_reg_u8_imm_u8, in_MOV_w_rm_mod_reg_u8_imm_u8, in_MOV_w_rm_mod_reg_u8_imm_u8, in_MOV_w_rm_mod_reg_u8_imm_u8, in_MOV_w_rm_mod_reg_u8_imm_u8, in_MOV_w_rm_mod_reg_u8_imm_u8, in_MOV_w_rm_mod_reg_u8_imm_u8, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_MOV_w_rm_mod_reg_u8_imm_u8, in_MOV_w_rm_mod_reg_u8_imm_u8, in_MOV_w_rm_mod_reg_u8_imm_u8, in_MOV_w_rm_mod_reg_u8_imm_u8, in_MOV_w_rm_mod_reg_u8_imm_u8, in_MOV_w_rm_mod_reg_u8_imm_u8, in_MOV_w_rm_mod_reg_u8_imm_u8, in_MOV_w_rm_mod_reg_u8_imm_u8, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_MOV_w_rm_mod_reg_u8_imm_u8, in_MOV_w_rm_mod_reg_u8_imm_u8, in_MOV_w_rm_mod_reg_u8_imm_u8, in_MOV_w_rm_mod_reg_u8_imm_u8, in_MOV_w_rm_mod_reg_u8_imm_u8, in_MOV_w_rm_mod_reg_u8_imm_u8, in_MOV_w_rm_mod_reg_u8_imm_u8, in_MOV_w_rm_mod_reg_u8_imm_u8, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_MOV_w_rm_mod_reg_u8_imm_u8, in_MOV_w_rm_mod_reg_u8_imm_u8, in_MOV_w_rm_mod_reg_u8_imm_u8, in_MOV_w_rm_mod_reg_u8_imm_u8, in_MOV_w_rm_mod_reg_u8_imm_u8, in_MOV_w_rm_mod_reg_u8_imm_u8, in_MOV_w_rm_mod_reg_u8_imm_u8, in_MOV_w_rm_mod_reg_u8_imm_u8, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_st_d_w_C6[] = {
	// 00
	in_MOV_d_rm_mod_reg_u8_imm_u8, in_MOV_d_rm_mod_reg_u8_imm_u8, in_MOV_d_rm_mod_reg_u8_imm_u8, in_MOV_d_rm_mod_reg_u8_imm_u8, in_MOV_d_rm_mod_reg_u8_imm_u8, in_MOV_d_rm_mod_reg_u8_imm_u8, in_MOV_d_rm_mod_reg_u8_imm_u8, in_MOV_d_rm_mod_reg_u8_imm_u8, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_MOV_d_rm_mod_reg_u8_imm_u8, in_MOV_d_rm_mod_reg_u8_imm_u8, in_MOV_d_rm_mod_reg_u8_imm_u8, in_MOV_d_rm_mod_reg_u8_imm_u8, in_MOV_d_rm_mod_reg_u8_imm_u8, in_MOV_d_rm_mod_reg_u8_imm_u8, in_MOV_d_rm_mod_reg_u8_imm_u8, in_MOV_d_rm_mod_reg_u8_imm_u8, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_MOV_d_rm_mod_reg_u8_imm_u8, in_MOV_d_rm_mod_reg_u8_imm_u8, in_MOV_d_rm_mod_reg_u8_imm_u8, in_MOV_d_rm_mod_reg_u8_imm_u8, in_MOV_d_rm_mod_reg_u8_imm_u8, in_MOV_d_rm_mod_reg_u8_imm_u8, in_MOV_d_rm_mod_reg_u8_imm_u8, in_MOV_d_rm_mod_reg_u8_imm_u8, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_MOV_d_rm_mod_reg_u8_imm_u8, in_MOV_d_rm_mod_reg_u8_imm_u8, in_MOV_d_rm_mod_reg_u8_imm_u8, in_MOV_d_rm_mod_reg_u8_imm_u8, in_MOV_d_rm_mod_reg_u8_imm_u8, in_MOV_d_rm_mod_reg_u8_imm_u8, in_MOV_d_rm_mod_reg_u8_imm_u8, in_MOV_d_rm_mod_reg_u8_imm_u8, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_st_d_d_C6[] = {
	// 00
	in_MOV_d_rm_mod_reg_u8_imm_u8, in_MOV_d_rm_mod_reg_u8_imm_u8, in_MOV_d_rm_mod_reg_u8_imm_u8, in_MOV_d_rm_mod_reg_u8_imm_u8, in_MOV_d_rm_mod_reg_u8_imm_u8, in_MOV_d_rm_mod_reg_u8_imm_u8, in_MOV_d_rm_mod_reg_u8_imm_u8, in_MOV_d_rm_mod_reg_u8_imm_u8, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_MOV_d_rm_mod_reg_u8_imm_u8, in_MOV_d_rm_mod_reg_u8_imm_u8, in_MOV_d_rm_mod_reg_u8_imm_u8, in_MOV_d_rm_mod_reg_u8_imm_u8, in_MOV_d_rm_mod_reg_u8_imm_u8, in_MOV_d_rm_mod_reg_u8_imm_u8, in_MOV_d_rm_mod_reg_u8_imm_u8, in_MOV_d_rm_mod_reg_u8_imm_u8, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_MOV_d_rm_mod_reg_u8_imm_u8, in_MOV_d_rm_mod_reg_u8_imm_u8, in_MOV_d_rm_mod_reg_u8_imm_u8, in_MOV_d_rm_mod_reg_u8_imm_u8, in_MOV_d_rm_mod_reg_u8_imm_u8, in_MOV_d_rm_mod_reg_u8_imm_u8, in_MOV_d_rm_mod_reg_u8_imm_u8, in_MOV_d_rm_mod_reg_u8_imm_u8, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_MOV_d_rm_mod_reg_u8_imm_u8, in_MOV_d_rm_mod_reg_u8_imm_u8, in_MOV_d_rm_mod_reg_u8_imm_u8, in_MOV_d_rm_mod_reg_u8_imm_u8, in_MOV_d_rm_mod_reg_u8_imm_u8, in_MOV_d_rm_mod_reg_u8_imm_u8, in_MOV_d_rm_mod_reg_u8_imm_u8, in_MOV_d_rm_mod_reg_u8_imm_u8, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_st_w_w_C7[] = {
	// 00
	in_MOV_w_rm_mod_reg_u16_imm_i16, in_MOV_w_rm_mod_reg_u16_imm_i16, in_MOV_w_rm_mod_reg_u16_imm_i16, in_MOV_w_rm_mod_reg_u16_imm_i16, in_MOV_w_rm_mod_reg_u16_imm_i16, in_MOV_w_rm_mod_reg_u16_imm_i16, in_MOV_w_rm_mod_reg_u16_imm_i16, in_MOV_w_rm_mod_reg_u16_imm_i16, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_MOV_w_rm_mod_reg_u16_imm_i16, in_MOV_w_rm_mod_reg_u16_imm_i16, in_MOV_w_rm_mod_reg_u16_imm_i16, in_MOV_w_rm_mod_reg_u16_imm_i16, in_MOV_w_rm_mod_reg_u16_imm_i16, in_MOV_w_rm_mod_reg_u16_imm_i16, in_MOV_w_rm_mod_reg_u16_imm_i16, in_MOV_w_rm_mod_reg_u16_imm_i16, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_MOV_w_rm_mod_reg_u16_imm_i16, in_MOV_w_rm_mod_reg_u16_imm_i16, in_MOV_w_rm_mod_reg_u16_imm_i16, in_MOV_w_rm_mod_reg_u16_imm_i16, in_MOV_w_rm_mod_reg_u16_imm_i16, in_MOV_w_rm_mod_reg_u16_imm_i16, in_MOV_w_rm_mod_reg_u16_imm_i16, in_MOV_w_rm_mod_reg_u16_imm_i16, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_MOV_w_rm_mod_reg_u16_imm_i16, in_MOV_w_rm_mod_reg_u16_imm_i16, in_MOV_w_rm_mod_reg_u16_imm_i16, in_MOV_w_rm_mod_reg_u16_imm_i16, in_MOV_w_rm_mod_reg_u16_imm_i16, in_MOV_w_rm_mod_reg_u16_imm_i16, in_MOV_w_rm_mod_reg_u16_imm_i16, in_MOV_w_rm_mod_reg_u16_imm_i16, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_st_w_d_C7[] = {
	// 00
	in_MOV_w_rm_mod_reg_u32_imm_i32, in_MOV_w_rm_mod_reg_u32_imm_i32, in_MOV_w_rm_mod_reg_u32_imm_i32, in_MOV_w_rm_mod_reg_u32_imm_i32, in_MOV_w_rm_mod_reg_u32_imm_i32, in_MOV_w_rm_mod_reg_u32_imm_i32, in_MOV_w_rm_mod_reg_u32_imm_i32, in_MOV_w_rm_mod_reg_u32_imm_i32, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_MOV_w_rm_mod_reg_u32_imm_i32, in_MOV_w_rm_mod_reg_u32_imm_i32, in_MOV_w_rm_mod_reg_u32_imm_i32, in_MOV_w_rm_mod_reg_u32_imm_i32, in_MOV_w_rm_mod_reg_u32_imm_i32, in_MOV_w_rm_mod_reg_u32_imm_i32, in_MOV_w_rm_mod_reg_u32_imm_i32, in_MOV_w_rm_mod_reg_u32_imm_i32, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_MOV_w_rm_mod_reg_u32_imm_i32, in_MOV_w_rm_mod_reg_u32_imm_i32, in_MOV_w_rm_mod_reg_u32_imm_i32, in_MOV_w_rm_mod_reg_u32_imm_i32, in_MOV_w_rm_mod_reg_u32_imm_i32, in_MOV_w_rm_mod_reg_u32_imm_i32, in_MOV_w_rm_mod_reg_u32_imm_i32, in_MOV_w_rm_mod_reg_u32_imm_i32, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_MOV_w_rm_mod_reg_u32_imm_i32, in_MOV_w_rm_mod_reg_u32_imm_i32, in_MOV_w_rm_mod_reg_u32_imm_i32, in_MOV_w_rm_mod_reg_u32_imm_i32, in_MOV_w_rm_mod_reg_u32_imm_i32, in_MOV_w_rm_mod_reg_u32_imm_i32, in_MOV_w_rm_mod_reg_u32_imm_i32, in_MOV_w_rm_mod_reg_u32_imm_i32, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_st_d_w_C7[] = {
	// 00
	in_MOV_d_rm_mod_reg_u16_imm_i16, in_MOV_d_rm_mod_reg_u16_imm_i16, in_MOV_d_rm_mod_reg_u16_imm_i16, in_MOV_d_rm_mod_reg_u16_imm_i16, in_MOV_d_rm_mod_reg_u16_imm_i16, in_MOV_d_rm_mod_reg_u16_imm_i16, in_MOV_d_rm_mod_reg_u16_imm_i16, in_MOV_d_rm_mod_reg_u16_imm_i16, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_MOV_d_rm_mod_reg_u16_imm_i16, in_MOV_d_rm_mod_reg_u16_imm_i16, in_MOV_d_rm_mod_reg_u16_imm_i16, in_MOV_d_rm_mod_reg_u16_imm_i16, in_MOV_d_rm_mod_reg_u16_imm_i16, in_MOV_d_rm_mod_reg_u16_imm_i16, in_MOV_d_rm_mod_reg_u16_imm_i16, in_MOV_d_rm_mod_reg_u16_imm_i16, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_MOV_d_rm_mod_reg_u16_imm_i16, in_MOV_d_rm_mod_reg_u16_imm_i16, in_MOV_d_rm_mod_reg_u16_imm_i16, in_MOV_d_rm_mod_reg_u16_imm_i16, in_MOV_d_rm_mod_reg_u16_imm_i16, in_MOV_d_rm_mod_reg_u16_imm_i16, in_MOV_d_rm_mod_reg_u16_imm_i16, in_MOV_d_rm_mod_reg_u16_imm_i16, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_MOV_d_rm_mod_reg_u16_imm_i16, in_MOV_d_rm_mod_reg_u16_imm_i16, in_MOV_d_rm_mod_reg_u16_imm_i16, in_MOV_d_rm_mod_reg_u16_imm_i16, in_MOV_d_rm_mod_reg_u16_imm_i16, in_MOV_d_rm_mod_reg_u16_imm_i16, in_MOV_d_rm_mod_reg_u16_imm_i16, in_MOV_d_rm_mod_reg_u16_imm_i16, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_st_d_d_C7[] = {
	// 00
	in_MOV_d_rm_mod_reg_u32_imm_i32, in_MOV_d_rm_mod_reg_u32_imm_i32, in_MOV_d_rm_mod_reg_u32_imm_i32, in_MOV_d_rm_mod_reg_u32_imm_i32, in_MOV_d_rm_mod_reg_u32_imm_i32, in_MOV_d_rm_mod_reg_u32_imm_i32, in_MOV_d_rm_mod_reg_u32_imm_i32, in_MOV_d_rm_mod_reg_u32_imm_i32, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_MOV_d_rm_mod_reg_u32_imm_i32, in_MOV_d_rm_mod_reg_u32_imm_i32, in_MOV_d_rm_mod_reg_u32_imm_i32, in_MOV_d_rm_mod_reg_u32_imm_i32, in_MOV_d_rm_mod_reg_u32_imm_i32, in_MOV_d_rm_mod_reg_u32_imm_i32, in_MOV_d_rm_mod_reg_u32_imm_i32, in_MOV_d_rm_mod_reg_u32_imm_i32, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_MOV_d_rm_mod_reg_u32_imm_i32, in_MOV_d_rm_mod_reg_u32_imm_i32, in_MOV_d_rm_mod_reg_u32_imm_i32, in_MOV_d_rm_mod_reg_u32_imm_i32, in_MOV_d_rm_mod_reg_u32_imm_i32, in_MOV_d_rm_mod_reg_u32_imm_i32, in_MOV_d_rm_mod_reg_u32_imm_i32, in_MOV_d_rm_mod_reg_u32_imm_i32, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_MOV_d_rm_mod_reg_u32_imm_i32, in_MOV_d_rm_mod_reg_u32_imm_i32, in_MOV_d_rm_mod_reg_u32_imm_i32, in_MOV_d_rm_mod_reg_u32_imm_i32, in_MOV_d_rm_mod_reg_u32_imm_i32, in_MOV_d_rm_mod_reg_u32_imm_i32, in_MOV_d_rm_mod_reg_u32_imm_i32, in_MOV_d_rm_mod_reg_u32_imm_i32, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_st_w_w_D0[] = {
	// 00
	in_ROL_w_rm_mod_reg_u8, in_ROL_w_rm_mod_reg_u8, in_ROL_w_rm_mod_reg_u8, in_ROL_w_rm_mod_reg_u8, in_ROL_w_rm_mod_reg_u8, in_ROL_w_rm_mod_reg_u8, in_ROL_w_rm_mod_reg_u8, in_ROL_w_rm_mod_reg_u8, 
	// 08
	in_ROR_w_rm_mod_reg_u8, in_ROR_w_rm_mod_reg_u8, in_ROR_w_rm_mod_reg_u8, in_ROR_w_rm_mod_reg_u8, in_ROR_w_rm_mod_reg_u8, in_ROR_w_rm_mod_reg_u8, in_ROR_w_rm_mod_reg_u8, in_ROR_w_rm_mod_reg_u8, 
	// 10
	in_RCL_w_rm_mod_reg_u8, in_RCL_w_rm_mod_reg_u8, in_RCL_w_rm_mod_reg_u8, in_RCL_w_rm_mod_reg_u8, in_RCL_w_rm_mod_reg_u8, in_RCL_w_rm_mod_reg_u8, in_RCL_w_rm_mod_reg_u8, in_RCL_w_rm_mod_reg_u8, 
	// 18
	in_RCR_w_rm_mod_reg_u8, in_RCR_w_rm_mod_reg_u8, in_RCR_w_rm_mod_reg_u8, in_RCR_w_rm_mod_reg_u8, in_RCR_w_rm_mod_reg_u8, in_RCR_w_rm_mod_reg_u8, in_RCR_w_rm_mod_reg_u8, in_RCR_w_rm_mod_reg_u8, 
	// 20
	in_SHL_w_rm_mod_reg_u8, in_SHL_w_rm_mod_reg_u8, in_SHL_w_rm_mod_reg_u8, in_SHL_w_rm_mod_reg_u8, in_SHL_w_rm_mod_reg_u8, in_SHL_w_rm_mod_reg_u8, in_SHL_w_rm_mod_reg_u8, in_SHL_w_rm_mod_reg_u8, 
	// 28
	in_SHR_w_rm_mod_reg_u8, in_SHR_w_rm_mod_reg_u8, in_SHR_w_rm_mod_reg_u8, in_SHR_w_rm_mod_reg_u8, in_SHR_w_rm_mod_reg_u8, in_SHR_w_rm_mod_reg_u8, in_SHR_w_rm_mod_reg_u8, in_SHR_w_rm_mod_reg_u8, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_SAR_w_rm_mod_reg_u8, in_SAR_w_rm_mod_reg_u8, in_SAR_w_rm_mod_reg_u8, in_SAR_w_rm_mod_reg_u8, in_SAR_w_rm_mod_reg_u8, in_SAR_w_rm_mod_reg_u8, in_SAR_w_rm_mod_reg_u8, in_SAR_w_rm_mod_reg_u8, 
	// 40
	in_ROL_w_rm_mod_reg_u8, in_ROL_w_rm_mod_reg_u8, in_ROL_w_rm_mod_reg_u8, in_ROL_w_rm_mod_reg_u8, in_ROL_w_rm_mod_reg_u8, in_ROL_w_rm_mod_reg_u8, in_ROL_w_rm_mod_reg_u8, in_ROL_w_rm_mod_reg_u8, 
	// 48
	in_ROR_w_rm_mod_reg_u8, in_ROR_w_rm_mod_reg_u8, in_ROR_w_rm_mod_reg_u8, in_ROR_w_rm_mod_reg_u8, in_ROR_w_rm_mod_reg_u8, in_ROR_w_rm_mod_reg_u8, in_ROR_w_rm_mod_reg_u8, in_ROR_w_rm_mod_reg_u8, 
	// 50
	in_RCL_w_rm_mod_reg_u8, in_RCL_w_rm_mod_reg_u8, in_RCL_w_rm_mod_reg_u8, in_RCL_w_rm_mod_reg_u8, in_RCL_w_rm_mod_reg_u8, in_RCL_w_rm_mod_reg_u8, in_RCL_w_rm_mod_reg_u8, in_RCL_w_rm_mod_reg_u8, 
	// 58
	in_RCR_w_rm_mod_reg_u8, in_RCR_w_rm_mod_reg_u8, in_RCR_w_rm_mod_reg_u8, in_RCR_w_rm_mod_reg_u8, in_RCR_w_rm_mod_reg_u8, in_RCR_w_rm_mod_reg_u8, in_RCR_w_rm_mod_reg_u8, in_RCR_w_rm_mod_reg_u8, 
	// 60
	in_SHL_w_rm_mod_reg_u8, in_SHL_w_rm_mod_reg_u8, in_SHL_w_rm_mod_reg_u8, in_SHL_w_rm_mod_reg_u8, in_SHL_w_rm_mod_reg_u8, in_SHL_w_rm_mod_reg_u8, in_SHL_w_rm_mod_reg_u8, in_SHL_w_rm_mod_reg_u8, 
	// 68
	in_SHR_w_rm_mod_reg_u8, in_SHR_w_rm_mod_reg_u8, in_SHR_w_rm_mod_reg_u8, in_SHR_w_rm_mod_reg_u8, in_SHR_w_rm_mod_reg_u8, in_SHR_w_rm_mod_reg_u8, in_SHR_w_rm_mod_reg_u8, in_SHR_w_rm_mod_reg_u8, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_SAR_w_rm_mod_reg_u8, in_SAR_w_rm_mod_reg_u8, in_SAR_w_rm_mod_reg_u8, in_SAR_w_rm_mod_reg_u8, in_SAR_w_rm_mod_reg_u8, in_SAR_w_rm_mod_reg_u8, in_SAR_w_rm_mod_reg_u8, in_SAR_w_rm_mod_reg_u8, 
	// 80
	in_ROL_w_rm_mod_reg_u8, in_ROL_w_rm_mod_reg_u8, in_ROL_w_rm_mod_reg_u8, in_ROL_w_rm_mod_reg_u8, in_ROL_w_rm_mod_reg_u8, in_ROL_w_rm_mod_reg_u8, in_ROL_w_rm_mod_reg_u8, in_ROL_w_rm_mod_reg_u8, 
	// 88
	in_ROR_w_rm_mod_reg_u8, in_ROR_w_rm_mod_reg_u8, in_ROR_w_rm_mod_reg_u8, in_ROR_w_rm_mod_reg_u8, in_ROR_w_rm_mod_reg_u8, in_ROR_w_rm_mod_reg_u8, in_ROR_w_rm_mod_reg_u8, in_ROR_w_rm_mod_reg_u8, 
	// 90
	in_RCL_w_rm_mod_reg_u8, in_RCL_w_rm_mod_reg_u8, in_RCL_w_rm_mod_reg_u8, in_RCL_w_rm_mod_reg_u8, in_RCL_w_rm_mod_reg_u8, in_RCL_w_rm_mod_reg_u8, in_RCL_w_rm_mod_reg_u8, in_RCL_w_rm_mod_reg_u8, 
	// 98
	in_RCR_w_rm_mod_reg_u8, in_RCR_w_rm_mod_reg_u8, in_RCR_w_rm_mod_reg_u8, in_RCR_w_rm_mod_reg_u8, in_RCR_w_rm_mod_reg_u8, in_RCR_w_rm_mod_reg_u8, in_RCR_w_rm_mod_reg_u8, in_RCR_w_rm_mod_reg_u8, 
	// A0
	in_SHL_w_rm_mod_reg_u8, in_SHL_w_rm_mod_reg_u8, in_SHL_w_rm_mod_reg_u8, in_SHL_w_rm_mod_reg_u8, in_SHL_w_rm_mod_reg_u8, in_SHL_w_rm_mod_reg_u8, in_SHL_w_rm_mod_reg_u8, in_SHL_w_rm_mod_reg_u8, 
	// A8
	in_SHR_w_rm_mod_reg_u8, in_SHR_w_rm_mod_reg_u8, in_SHR_w_rm_mod_reg_u8, in_SHR_w_rm_mod_reg_u8, in_SHR_w_rm_mod_reg_u8, in_SHR_w_rm_mod_reg_u8, in_SHR_w_rm_mod_reg_u8, in_SHR_w_rm_mod_reg_u8, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_SAR_w_rm_mod_reg_u8, in_SAR_w_rm_mod_reg_u8, in_SAR_w_rm_mod_reg_u8, in_SAR_w_rm_mod_reg_u8, in_SAR_w_rm_mod_reg_u8, in_SAR_w_rm_mod_reg_u8, in_SAR_w_rm_mod_reg_u8, in_SAR_w_rm_mod_reg_u8, 
	// C0
	in_ROL_w_rm_mod_reg_u8, in_ROL_w_rm_mod_reg_u8, in_ROL_w_rm_mod_reg_u8, in_ROL_w_rm_mod_reg_u8, in_ROL_w_rm_mod_reg_u8, in_ROL_w_rm_mod_reg_u8, in_ROL_w_rm_mod_reg_u8, in_ROL_w_rm_mod_reg_u8, 
	// C8
	in_ROR_w_rm_mod_reg_u8, in_ROR_w_rm_mod_reg_u8, in_ROR_w_rm_mod_reg_u8, in_ROR_w_rm_mod_reg_u8, in_ROR_w_rm_mod_reg_u8, in_ROR_w_rm_mod_reg_u8, in_ROR_w_rm_mod_reg_u8, in_ROR_w_rm_mod_reg_u8, 
	// D0
	in_RCL_w_rm_mod_reg_u8, in_RCL_w_rm_mod_reg_u8, in_RCL_w_rm_mod_reg_u8, in_RCL_w_rm_mod_reg_u8, in_RCL_w_rm_mod_reg_u8, in_RCL_w_rm_mod_reg_u8, in_RCL_w_rm_mod_reg_u8, in_RCL_w_rm_mod_reg_u8, 
	// D8
	in_RCR_w_rm_mod_reg_u8, in_RCR_w_rm_mod_reg_u8, in_RCR_w_rm_mod_reg_u8, in_RCR_w_rm_mod_reg_u8, in_RCR_w_rm_mod_reg_u8, in_RCR_w_rm_mod_reg_u8, in_RCR_w_rm_mod_reg_u8, in_RCR_w_rm_mod_reg_u8, 
	// E0
	in_SHL_w_rm_mod_reg_u8, in_SHL_w_rm_mod_reg_u8, in_SHL_w_rm_mod_reg_u8, in_SHL_w_rm_mod_reg_u8, in_SHL_w_rm_mod_reg_u8, in_SHL_w_rm_mod_reg_u8, in_SHL_w_rm_mod_reg_u8, in_SHL_w_rm_mod_reg_u8, 
	// E8
	in_SHR_w_rm_mod_reg_u8, in_SHR_w_rm_mod_reg_u8, in_SHR_w_rm_mod_reg_u8, in_SHR_w_rm_mod_reg_u8, in_SHR_w_rm_mod_reg_u8, in_SHR_w_rm_mod_reg_u8, in_SHR_w_rm_mod_reg_u8, in_SHR_w_rm_mod_reg_u8, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_SAR_w_rm_mod_reg_u8, in_SAR_w_rm_mod_reg_u8, in_SAR_w_rm_mod_reg_u8, in_SAR_w_rm_mod_reg_u8, in_SAR_w_rm_mod_reg_u8, in_SAR_w_rm_mod_reg_u8, in_SAR_w_rm_mod_reg_u8, in_SAR_w_rm_mod_reg_u8, 
};
const OpState CpuRunnerX86::table_st_w_d_D0[] = {
	// 00
	in_ROL_w_rm_mod_reg_u8, in_ROL_w_rm_mod_reg_u8, in_ROL_w_rm_mod_reg_u8, in_ROL_w_rm_mod_reg_u8, in_ROL_w_rm_mod_reg_u8, in_ROL_w_rm_mod_reg_u8, in_ROL_w_rm_mod_reg_u8, in_ROL_w_rm_mod_reg_u8, 
	// 08
	in_ROR_w_rm_mod_reg_u8, in_ROR_w_rm_mod_reg_u8, in_ROR_w_rm_mod_reg_u8, in_ROR_w_rm_mod_reg_u8, in_ROR_w_rm_mod_reg_u8, in_ROR_w_rm_mod_reg_u8, in_ROR_w_rm_mod_reg_u8, in_ROR_w_rm_mod_reg_u8, 
	// 10
	in_RCL_w_rm_mod_reg_u8, in_RCL_w_rm_mod_reg_u8, in_RCL_w_rm_mod_reg_u8, in_RCL_w_rm_mod_reg_u8, in_RCL_w_rm_mod_reg_u8, in_RCL_w_rm_mod_reg_u8, in_RCL_w_rm_mod_reg_u8, in_RCL_w_rm_mod_reg_u8, 
	// 18
	in_RCR_w_rm_mod_reg_u8, in_RCR_w_rm_mod_reg_u8, in_RCR_w_rm_mod_reg_u8, in_RCR_w_rm_mod_reg_u8, in_RCR_w_rm_mod_reg_u8, in_RCR_w_rm_mod_reg_u8, in_RCR_w_rm_mod_reg_u8, in_RCR_w_rm_mod_reg_u8, 
	// 20
	in_SHL_w_rm_mod_reg_u8, in_SHL_w_rm_mod_reg_u8, in_SHL_w_rm_mod_reg_u8, in_SHL_w_rm_mod_reg_u8, in_SHL_w_rm_mod_reg_u8, in_SHL_w_rm_mod_reg_u8, in_SHL_w_rm_mod_reg_u8, in_SHL_w_rm_mod_reg_u8, 
	// 28
	in_SHR_w_rm_mod_reg_u8, in_SHR_w_rm_mod_reg_u8, in_SHR_w_rm_mod_reg_u8, in_SHR_w_rm_mod_reg_u8, in_SHR_w_rm_mod_reg_u8, in_SHR_w_rm_mod_reg_u8, in_SHR_w_rm_mod_reg_u8, in_SHR_w_rm_mod_reg_u8, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_SAR_w_rm_mod_reg_u8, in_SAR_w_rm_mod_reg_u8, in_SAR_w_rm_mod_reg_u8, in_SAR_w_rm_mod_reg_u8, in_SAR_w_rm_mod_reg_u8, in_SAR_w_rm_mod_reg_u8, in_SAR_w_rm_mod_reg_u8, in_SAR_w_rm_mod_reg_u8, 
	// 40
	in_ROL_w_rm_mod_reg_u8, in_ROL_w_rm_mod_reg_u8, in_ROL_w_rm_mod_reg_u8, in_ROL_w_rm_mod_reg_u8, in_ROL_w_rm_mod_reg_u8, in_ROL_w_rm_mod_reg_u8, in_ROL_w_rm_mod_reg_u8, in_ROL_w_rm_mod_reg_u8, 
	// 48
	in_ROR_w_rm_mod_reg_u8, in_ROR_w_rm_mod_reg_u8, in_ROR_w_rm_mod_reg_u8, in_ROR_w_rm_mod_reg_u8, in_ROR_w_rm_mod_reg_u8, in_ROR_w_rm_mod_reg_u8, in_ROR_w_rm_mod_reg_u8, in_ROR_w_rm_mod_reg_u8, 
	// 50
	in_RCL_w_rm_mod_reg_u8, in_RCL_w_rm_mod_reg_u8, in_RCL_w_rm_mod_reg_u8, in_RCL_w_rm_mod_reg_u8, in_RCL_w_rm_mod_reg_u8, in_RCL_w_rm_mod_reg_u8, in_RCL_w_rm_mod_reg_u8, in_RCL_w_rm_mod_reg_u8, 
	// 58
	in_RCR_w_rm_mod_reg_u8, in_RCR_w_rm_mod_reg_u8, in_RCR_w_rm_mod_reg_u8, in_RCR_w_rm_mod_reg_u8, in_RCR_w_rm_mod_reg_u8, in_RCR_w_rm_mod_reg_u8, in_RCR_w_rm_mod_reg_u8, in_RCR_w_rm_mod_reg_u8, 
	// 60
	in_SHL_w_rm_mod_reg_u8, in_SHL_w_rm_mod_reg_u8, in_SHL_w_rm_mod_reg_u8, in_SHL_w_rm_mod_reg_u8, in_SHL_w_rm_mod_reg_u8, in_SHL_w_rm_mod_reg_u8, in_SHL_w_rm_mod_reg_u8, in_SHL_w_rm_mod_reg_u8, 
	// 68
	in_SHR_w_rm_mod_reg_u8, in_SHR_w_rm_mod_reg_u8, in_SHR_w_rm_mod_reg_u8, in_SHR_w_rm_mod_reg_u8, in_SHR_w_rm_mod_reg_u8, in_SHR_w_rm_mod_reg_u8, in_SHR_w_rm_mod_reg_u8, in_SHR_w_rm_mod_reg_u8, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_SAR_w_rm_mod_reg_u8, in_SAR_w_rm_mod_reg_u8, in_SAR_w_rm_mod_reg_u8, in_SAR_w_rm_mod_reg_u8, in_SAR_w_rm_mod_reg_u8, in_SAR_w_rm_mod_reg_u8, in_SAR_w_rm_mod_reg_u8, in_SAR_w_rm_mod_reg_u8, 
	// 80
	in_ROL_w_rm_mod_reg_u8, in_ROL_w_rm_mod_reg_u8, in_ROL_w_rm_mod_reg_u8, in_ROL_w_rm_mod_reg_u8, in_ROL_w_rm_mod_reg_u8, in_ROL_w_rm_mod_reg_u8, in_ROL_w_rm_mod_reg_u8, in_ROL_w_rm_mod_reg_u8, 
	// 88
	in_ROR_w_rm_mod_reg_u8, in_ROR_w_rm_mod_reg_u8, in_ROR_w_rm_mod_reg_u8, in_ROR_w_rm_mod_reg_u8, in_ROR_w_rm_mod_reg_u8, in_ROR_w_rm_mod_reg_u8, in_ROR_w_rm_mod_reg_u8, in_ROR_w_rm_mod_reg_u8, 
	// 90
	in_RCL_w_rm_mod_reg_u8, in_RCL_w_rm_mod_reg_u8, in_RCL_w_rm_mod_reg_u8, in_RCL_w_rm_mod_reg_u8, in_RCL_w_rm_mod_reg_u8, in_RCL_w_rm_mod_reg_u8, in_RCL_w_rm_mod_reg_u8, in_RCL_w_rm_mod_reg_u8, 
	// 98
	in_RCR_w_rm_mod_reg_u8, in_RCR_w_rm_mod_reg_u8, in_RCR_w_rm_mod_reg_u8, in_RCR_w_rm_mod_reg_u8, in_RCR_w_rm_mod_reg_u8, in_RCR_w_rm_mod_reg_u8, in_RCR_w_rm_mod_reg_u8, in_RCR_w_rm_mod_reg_u8, 
	// A0
	in_SHL_w_rm_mod_reg_u8, in_SHL_w_rm_mod_reg_u8, in_SHL_w_rm_mod_reg_u8, in_SHL_w_rm_mod_reg_u8, in_SHL_w_rm_mod_reg_u8, in_SHL_w_rm_mod_reg_u8, in_SHL_w_rm_mod_reg_u8, in_SHL_w_rm_mod_reg_u8, 
	// A8
	in_SHR_w_rm_mod_reg_u8, in_SHR_w_rm_mod_reg_u8, in_SHR_w_rm_mod_reg_u8, in_SHR_w_rm_mod_reg_u8, in_SHR_w_rm_mod_reg_u8, in_SHR_w_rm_mod_reg_u8, in_SHR_w_rm_mod_reg_u8, in_SHR_w_rm_mod_reg_u8, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_SAR_w_rm_mod_reg_u8, in_SAR_w_rm_mod_reg_u8, in_SAR_w_rm_mod_reg_u8, in_SAR_w_rm_mod_reg_u8, in_SAR_w_rm_mod_reg_u8, in_SAR_w_rm_mod_reg_u8, in_SAR_w_rm_mod_reg_u8, in_SAR_w_rm_mod_reg_u8, 
	// C0
	in_ROL_w_rm_mod_reg_u8, in_ROL_w_rm_mod_reg_u8, in_ROL_w_rm_mod_reg_u8, in_ROL_w_rm_mod_reg_u8, in_ROL_w_rm_mod_reg_u8, in_ROL_w_rm_mod_reg_u8, in_ROL_w_rm_mod_reg_u8, in_ROL_w_rm_mod_reg_u8, 
	// C8
	in_ROR_w_rm_mod_reg_u8, in_ROR_w_rm_mod_reg_u8, in_ROR_w_rm_mod_reg_u8, in_ROR_w_rm_mod_reg_u8, in_ROR_w_rm_mod_reg_u8, in_ROR_w_rm_mod_reg_u8, in_ROR_w_rm_mod_reg_u8, in_ROR_w_rm_mod_reg_u8, 
	// D0
	in_RCL_w_rm_mod_reg_u8, in_RCL_w_rm_mod_reg_u8, in_RCL_w_rm_mod_reg_u8, in_RCL_w_rm_mod_reg_u8, in_RCL_w_rm_mod_reg_u8, in_RCL_w_rm_mod_reg_u8, in_RCL_w_rm_mod_reg_u8, in_RCL_w_rm_mod_reg_u8, 
	// D8
	in_RCR_w_rm_mod_reg_u8, in_RCR_w_rm_mod_reg_u8, in_RCR_w_rm_mod_reg_u8, in_RCR_w_rm_mod_reg_u8, in_RCR_w_rm_mod_reg_u8, in_RCR_w_rm_mod_reg_u8, in_RCR_w_rm_mod_reg_u8, in_RCR_w_rm_mod_reg_u8, 
	// E0
	in_SHL_w_rm_mod_reg_u8, in_SHL_w_rm_mod_reg_u8, in_SHL_w_rm_mod_reg_u8, in_SHL_w_rm_mod_reg_u8, in_SHL_w_rm_mod_reg_u8, in_SHL_w_rm_mod_reg_u8, in_SHL_w_rm_mod_reg_u8, in_SHL_w_rm_mod_reg_u8, 
	// E8
	in_SHR_w_rm_mod_reg_u8, in_SHR_w_rm_mod_reg_u8, in_SHR_w_rm_mod_reg_u8, in_SHR_w_rm_mod_reg_u8, in_SHR_w_rm_mod_reg_u8, in_SHR_w_rm_mod_reg_u8, in_SHR_w_rm_mod_reg_u8, in_SHR_w_rm_mod_reg_u8, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_SAR_w_rm_mod_reg_u8, in_SAR_w_rm_mod_reg_u8, in_SAR_w_rm_mod_reg_u8, in_SAR_w_rm_mod_reg_u8, in_SAR_w_rm_mod_reg_u8, in_SAR_w_rm_mod_reg_u8, in_SAR_w_rm_mod_reg_u8, in_SAR_w_rm_mod_reg_u8, 
};
const OpState CpuRunnerX86::table_st_d_w_D0[] = {
	// 00
	in_ROL_d_rm_mod_reg_u8, in_ROL_d_rm_mod_reg_u8, in_ROL_d_rm_mod_reg_u8, in_ROL_d_rm_mod_reg_u8, in_ROL_d_rm_mod_reg_u8, in_ROL_d_rm_mod_reg_u8, in_ROL_d_rm_mod_reg_u8, in_ROL_d_rm_mod_reg_u8, 
	// 08
	in_ROR_d_rm_mod_reg_u8, in_ROR_d_rm_mod_reg_u8, in_ROR_d_rm_mod_reg_u8, in_ROR_d_rm_mod_reg_u8, in_ROR_d_rm_mod_reg_u8, in_ROR_d_rm_mod_reg_u8, in_ROR_d_rm_mod_reg_u8, in_ROR_d_rm_mod_reg_u8, 
	// 10
	in_RCL_d_rm_mod_reg_u8, in_RCL_d_rm_mod_reg_u8, in_RCL_d_rm_mod_reg_u8, in_RCL_d_rm_mod_reg_u8, in_RCL_d_rm_mod_reg_u8, in_RCL_d_rm_mod_reg_u8, in_RCL_d_rm_mod_reg_u8, in_RCL_d_rm_mod_reg_u8, 
	// 18
	in_RCR_d_rm_mod_reg_u8, in_RCR_d_rm_mod_reg_u8, in_RCR_d_rm_mod_reg_u8, in_RCR_d_rm_mod_reg_u8, in_RCR_d_rm_mod_reg_u8, in_RCR_d_rm_mod_reg_u8, in_RCR_d_rm_mod_reg_u8, in_RCR_d_rm_mod_reg_u8, 
	// 20
	in_SHL_d_rm_mod_reg_u8, in_SHL_d_rm_mod_reg_u8, in_SHL_d_rm_mod_reg_u8, in_SHL_d_rm_mod_reg_u8, in_SHL_d_rm_mod_reg_u8, in_SHL_d_rm_mod_reg_u8, in_SHL_d_rm_mod_reg_u8, in_SHL_d_rm_mod_reg_u8, 
	// 28
	in_SHR_d_rm_mod_reg_u8, in_SHR_d_rm_mod_reg_u8, in_SHR_d_rm_mod_reg_u8, in_SHR_d_rm_mod_reg_u8, in_SHR_d_rm_mod_reg_u8, in_SHR_d_rm_mod_reg_u8, in_SHR_d_rm_mod_reg_u8, in_SHR_d_rm_mod_reg_u8, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_SAR_d_rm_mod_reg_u8, in_SAR_d_rm_mod_reg_u8, in_SAR_d_rm_mod_reg_u8, in_SAR_d_rm_mod_reg_u8, in_SAR_d_rm_mod_reg_u8, in_SAR_d_rm_mod_reg_u8, in_SAR_d_rm_mod_reg_u8, in_SAR_d_rm_mod_reg_u8, 
	// 40
	in_ROL_d_rm_mod_reg_u8, in_ROL_d_rm_mod_reg_u8, in_ROL_d_rm_mod_reg_u8, in_ROL_d_rm_mod_reg_u8, in_ROL_d_rm_mod_reg_u8, in_ROL_d_rm_mod_reg_u8, in_ROL_d_rm_mod_reg_u8, in_ROL_d_rm_mod_reg_u8, 
	// 48
	in_ROR_d_rm_mod_reg_u8, in_ROR_d_rm_mod_reg_u8, in_ROR_d_rm_mod_reg_u8, in_ROR_d_rm_mod_reg_u8, in_ROR_d_rm_mod_reg_u8, in_ROR_d_rm_mod_reg_u8, in_ROR_d_rm_mod_reg_u8, in_ROR_d_rm_mod_reg_u8, 
	// 50
	in_RCL_d_rm_mod_reg_u8, in_RCL_d_rm_mod_reg_u8, in_RCL_d_rm_mod_reg_u8, in_RCL_d_rm_mod_reg_u8, in_RCL_d_rm_mod_reg_u8, in_RCL_d_rm_mod_reg_u8, in_RCL_d_rm_mod_reg_u8, in_RCL_d_rm_mod_reg_u8, 
	// 58
	in_RCR_d_rm_mod_reg_u8, in_RCR_d_rm_mod_reg_u8, in_RCR_d_rm_mod_reg_u8, in_RCR_d_rm_mod_reg_u8, in_RCR_d_rm_mod_reg_u8, in_RCR_d_rm_mod_reg_u8, in_RCR_d_rm_mod_reg_u8, in_RCR_d_rm_mod_reg_u8, 
	// 60
	in_SHL_d_rm_mod_reg_u8, in_SHL_d_rm_mod_reg_u8, in_SHL_d_rm_mod_reg_u8, in_SHL_d_rm_mod_reg_u8, in_SHL_d_rm_mod_reg_u8, in_SHL_d_rm_mod_reg_u8, in_SHL_d_rm_mod_reg_u8, in_SHL_d_rm_mod_reg_u8, 
	// 68
	in_SHR_d_rm_mod_reg_u8, in_SHR_d_rm_mod_reg_u8, in_SHR_d_rm_mod_reg_u8, in_SHR_d_rm_mod_reg_u8, in_SHR_d_rm_mod_reg_u8, in_SHR_d_rm_mod_reg_u8, in_SHR_d_rm_mod_reg_u8, in_SHR_d_rm_mod_reg_u8, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_SAR_d_rm_mod_reg_u8, in_SAR_d_rm_mod_reg_u8, in_SAR_d_rm_mod_reg_u8, in_SAR_d_rm_mod_reg_u8, in_SAR_d_rm_mod_reg_u8, in_SAR_d_rm_mod_reg_u8, in_SAR_d_rm_mod_reg_u8, in_SAR_d_rm_mod_reg_u8, 
	// 80
	in_ROL_d_rm_mod_reg_u8, in_ROL_d_rm_mod_reg_u8, in_ROL_d_rm_mod_reg_u8, in_ROL_d_rm_mod_reg_u8, in_ROL_d_rm_mod_reg_u8, in_ROL_d_rm_mod_reg_u8, in_ROL_d_rm_mod_reg_u8, in_ROL_d_rm_mod_reg_u8, 
	// 88
	in_ROR_d_rm_mod_reg_u8, in_ROR_d_rm_mod_reg_u8, in_ROR_d_rm_mod_reg_u8, in_ROR_d_rm_mod_reg_u8, in_ROR_d_rm_mod_reg_u8, in_ROR_d_rm_mod_reg_u8, in_ROR_d_rm_mod_reg_u8, in_ROR_d_rm_mod_reg_u8, 
	// 90
	in_RCL_d_rm_mod_reg_u8, in_RCL_d_rm_mod_reg_u8, in_RCL_d_rm_mod_reg_u8, in_RCL_d_rm_mod_reg_u8, in_RCL_d_rm_mod_reg_u8, in_RCL_d_rm_mod_reg_u8, in_RCL_d_rm_mod_reg_u8, in_RCL_d_rm_mod_reg_u8, 
	// 98
	in_RCR_d_rm_mod_reg_u8, in_RCR_d_rm_mod_reg_u8, in_RCR_d_rm_mod_reg_u8, in_RCR_d_rm_mod_reg_u8, in_RCR_d_rm_mod_reg_u8, in_RCR_d_rm_mod_reg_u8, in_RCR_d_rm_mod_reg_u8, in_RCR_d_rm_mod_reg_u8, 
	// A0
	in_SHL_d_rm_mod_reg_u8, in_SHL_d_rm_mod_reg_u8, in_SHL_d_rm_mod_reg_u8, in_SHL_d_rm_mod_reg_u8, in_SHL_d_rm_mod_reg_u8, in_SHL_d_rm_mod_reg_u8, in_SHL_d_rm_mod_reg_u8, in_SHL_d_rm_mod_reg_u8, 
	// A8
	in_SHR_d_rm_mod_reg_u8, in_SHR_d_rm_mod_reg_u8, in_SHR_d_rm_mod_reg_u8, in_SHR_d_rm_mod_reg_u8, in_SHR_d_rm_mod_reg_u8, in_SHR_d_rm_mod_reg_u8, in_SHR_d_rm_mod_reg_u8, in_SHR_d_rm_mod_reg_u8, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_SAR_d_rm_mod_reg_u8, in_SAR_d_rm_mod_reg_u8, in_SAR_d_rm_mod_reg_u8, in_SAR_d_rm_mod_reg_u8, in_SAR_d_rm_mod_reg_u8, in_SAR_d_rm_mod_reg_u8, in_SAR_d_rm_mod_reg_u8, in_SAR_d_rm_mod_reg_u8, 
	// C0
	in_ROL_d_rm_mod_reg_u8, in_ROL_d_rm_mod_reg_u8, in_ROL_d_rm_mod_reg_u8, in_ROL_d_rm_mod_reg_u8, in_ROL_d_rm_mod_reg_u8, in_ROL_d_rm_mod_reg_u8, in_ROL_d_rm_mod_reg_u8, in_ROL_d_rm_mod_reg_u8, 
	// C8
	in_ROR_d_rm_mod_reg_u8, in_ROR_d_rm_mod_reg_u8, in_ROR_d_rm_mod_reg_u8, in_ROR_d_rm_mod_reg_u8, in_ROR_d_rm_mod_reg_u8, in_ROR_d_rm_mod_reg_u8, in_ROR_d_rm_mod_reg_u8, in_ROR_d_rm_mod_reg_u8, 
	// D0
	in_RCL_d_rm_mod_reg_u8, in_RCL_d_rm_mod_reg_u8, in_RCL_d_rm_mod_reg_u8, in_RCL_d_rm_mod_reg_u8, in_RCL_d_rm_mod_reg_u8, in_RCL_d_rm_mod_reg_u8, in_RCL_d_rm_mod_reg_u8, in_RCL_d_rm_mod_reg_u8, 
	// D8
	in_RCR_d_rm_mod_reg_u8, in_RCR_d_rm_mod_reg_u8, in_RCR_d_rm_mod_reg_u8, in_RCR_d_rm_mod_reg_u8, in_RCR_d_rm_mod_reg_u8, in_RCR_d_rm_mod_reg_u8, in_RCR_d_rm_mod_reg_u8, in_RCR_d_rm_mod_reg_u8, 
	// E0
	in_SHL_d_rm_mod_reg_u8, in_SHL_d_rm_mod_reg_u8, in_SHL_d_rm_mod_reg_u8, in_SHL_d_rm_mod_reg_u8, in_SHL_d_rm_mod_reg_u8, in_SHL_d_rm_mod_reg_u8, in_SHL_d_rm_mod_reg_u8, in_SHL_d_rm_mod_reg_u8, 
	// E8
	in_SHR_d_rm_mod_reg_u8, in_SHR_d_rm_mod_reg_u8, in_SHR_d_rm_mod_reg_u8, in_SHR_d_rm_mod_reg_u8, in_SHR_d_rm_mod_reg_u8, in_SHR_d_rm_mod_reg_u8, in_SHR_d_rm_mod_reg_u8, in_SHR_d_rm_mod_reg_u8, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_SAR_d_rm_mod_reg_u8, in_SAR_d_rm_mod_reg_u8, in_SAR_d_rm_mod_reg_u8, in_SAR_d_rm_mod_reg_u8, in_SAR_d_rm_mod_reg_u8, in_SAR_d_rm_mod_reg_u8, in_SAR_d_rm_mod_reg_u8, in_SAR_d_rm_mod_reg_u8, 
};
const OpState CpuRunnerX86::table_st_d_d_D0[] = {
	// 00
	in_ROL_d_rm_mod_reg_u8, in_ROL_d_rm_mod_reg_u8, in_ROL_d_rm_mod_reg_u8, in_ROL_d_rm_mod_reg_u8, in_ROL_d_rm_mod_reg_u8, in_ROL_d_rm_mod_reg_u8, in_ROL_d_rm_mod_reg_u8, in_ROL_d_rm_mod_reg_u8, 
	// 08
	in_ROR_d_rm_mod_reg_u8, in_ROR_d_rm_mod_reg_u8, in_ROR_d_rm_mod_reg_u8, in_ROR_d_rm_mod_reg_u8, in_ROR_d_rm_mod_reg_u8, in_ROR_d_rm_mod_reg_u8, in_ROR_d_rm_mod_reg_u8, in_ROR_d_rm_mod_reg_u8, 
	// 10
	in_RCL_d_rm_mod_reg_u8, in_RCL_d_rm_mod_reg_u8, in_RCL_d_rm_mod_reg_u8, in_RCL_d_rm_mod_reg_u8, in_RCL_d_rm_mod_reg_u8, in_RCL_d_rm_mod_reg_u8, in_RCL_d_rm_mod_reg_u8, in_RCL_d_rm_mod_reg_u8, 
	// 18
	in_RCR_d_rm_mod_reg_u8, in_RCR_d_rm_mod_reg_u8, in_RCR_d_rm_mod_reg_u8, in_RCR_d_rm_mod_reg_u8, in_RCR_d_rm_mod_reg_u8, in_RCR_d_rm_mod_reg_u8, in_RCR_d_rm_mod_reg_u8, in_RCR_d_rm_mod_reg_u8, 
	// 20
	in_SHL_d_rm_mod_reg_u8, in_SHL_d_rm_mod_reg_u8, in_SHL_d_rm_mod_reg_u8, in_SHL_d_rm_mod_reg_u8, in_SHL_d_rm_mod_reg_u8, in_SHL_d_rm_mod_reg_u8, in_SHL_d_rm_mod_reg_u8, in_SHL_d_rm_mod_reg_u8, 
	// 28
	in_SHR_d_rm_mod_reg_u8, in_SHR_d_rm_mod_reg_u8, in_SHR_d_rm_mod_reg_u8, in_SHR_d_rm_mod_reg_u8, in_SHR_d_rm_mod_reg_u8, in_SHR_d_rm_mod_reg_u8, in_SHR_d_rm_mod_reg_u8, in_SHR_d_rm_mod_reg_u8, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_SAR_d_rm_mod_reg_u8, in_SAR_d_rm_mod_reg_u8, in_SAR_d_rm_mod_reg_u8, in_SAR_d_rm_mod_reg_u8, in_SAR_d_rm_mod_reg_u8, in_SAR_d_rm_mod_reg_u8, in_SAR_d_rm_mod_reg_u8, in_SAR_d_rm_mod_reg_u8, 
	// 40
	in_ROL_d_rm_mod_reg_u8, in_ROL_d_rm_mod_reg_u8, in_ROL_d_rm_mod_reg_u8, in_ROL_d_rm_mod_reg_u8, in_ROL_d_rm_mod_reg_u8, in_ROL_d_rm_mod_reg_u8, in_ROL_d_rm_mod_reg_u8, in_ROL_d_rm_mod_reg_u8, 
	// 48
	in_ROR_d_rm_mod_reg_u8, in_ROR_d_rm_mod_reg_u8, in_ROR_d_rm_mod_reg_u8, in_ROR_d_rm_mod_reg_u8, in_ROR_d_rm_mod_reg_u8, in_ROR_d_rm_mod_reg_u8, in_ROR_d_rm_mod_reg_u8, in_ROR_d_rm_mod_reg_u8, 
	// 50
	in_RCL_d_rm_mod_reg_u8, in_RCL_d_rm_mod_reg_u8, in_RCL_d_rm_mod_reg_u8, in_RCL_d_rm_mod_reg_u8, in_RCL_d_rm_mod_reg_u8, in_RCL_d_rm_mod_reg_u8, in_RCL_d_rm_mod_reg_u8, in_RCL_d_rm_mod_reg_u8, 
	// 58
	in_RCR_d_rm_mod_reg_u8, in_RCR_d_rm_mod_reg_u8, in_RCR_d_rm_mod_reg_u8, in_RCR_d_rm_mod_reg_u8, in_RCR_d_rm_mod_reg_u8, in_RCR_d_rm_mod_reg_u8, in_RCR_d_rm_mod_reg_u8, in_RCR_d_rm_mod_reg_u8, 
	// 60
	in_SHL_d_rm_mod_reg_u8, in_SHL_d_rm_mod_reg_u8, in_SHL_d_rm_mod_reg_u8, in_SHL_d_rm_mod_reg_u8, in_SHL_d_rm_mod_reg_u8, in_SHL_d_rm_mod_reg_u8, in_SHL_d_rm_mod_reg_u8, in_SHL_d_rm_mod_reg_u8, 
	// 68
	in_SHR_d_rm_mod_reg_u8, in_SHR_d_rm_mod_reg_u8, in_SHR_d_rm_mod_reg_u8, in_SHR_d_rm_mod_reg_u8, in_SHR_d_rm_mod_reg_u8, in_SHR_d_rm_mod_reg_u8, in_SHR_d_rm_mod_reg_u8, in_SHR_d_rm_mod_reg_u8, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_SAR_d_rm_mod_reg_u8, in_SAR_d_rm_mod_reg_u8, in_SAR_d_rm_mod_reg_u8, in_SAR_d_rm_mod_reg_u8, in_SAR_d_rm_mod_reg_u8, in_SAR_d_rm_mod_reg_u8, in_SAR_d_rm_mod_reg_u8, in_SAR_d_rm_mod_reg_u8, 
	// 80
	in_ROL_d_rm_mod_reg_u8, in_ROL_d_rm_mod_reg_u8, in_ROL_d_rm_mod_reg_u8, in_ROL_d_rm_mod_reg_u8, in_ROL_d_rm_mod_reg_u8, in_ROL_d_rm_mod_reg_u8, in_ROL_d_rm_mod_reg_u8, in_ROL_d_rm_mod_reg_u8, 
	// 88
	in_ROR_d_rm_mod_reg_u8, in_ROR_d_rm_mod_reg_u8, in_ROR_d_rm_mod_reg_u8, in_ROR_d_rm_mod_reg_u8, in_ROR_d_rm_mod_reg_u8, in_ROR_d_rm_mod_reg_u8, in_ROR_d_rm_mod_reg_u8, in_ROR_d_rm_mod_reg_u8, 
	// 90
	in_RCL_d_rm_mod_reg_u8, in_RCL_d_rm_mod_reg_u8, in_RCL_d_rm_mod_reg_u8, in_RCL_d_rm_mod_reg_u8, in_RCL_d_rm_mod_reg_u8, in_RCL_d_rm_mod_reg_u8, in_RCL_d_rm_mod_reg_u8, in_RCL_d_rm_mod_reg_u8, 
	// 98
	in_RCR_d_rm_mod_reg_u8, in_RCR_d_rm_mod_reg_u8, in_RCR_d_rm_mod_reg_u8, in_RCR_d_rm_mod_reg_u8, in_RCR_d_rm_mod_reg_u8, in_RCR_d_rm_mod_reg_u8, in_RCR_d_rm_mod_reg_u8, in_RCR_d_rm_mod_reg_u8, 
	// A0
	in_SHL_d_rm_mod_reg_u8, in_SHL_d_rm_mod_reg_u8, in_SHL_d_rm_mod_reg_u8, in_SHL_d_rm_mod_reg_u8, in_SHL_d_rm_mod_reg_u8, in_SHL_d_rm_mod_reg_u8, in_SHL_d_rm_mod_reg_u8, in_SHL_d_rm_mod_reg_u8, 
	// A8
	in_SHR_d_rm_mod_reg_u8, in_SHR_d_rm_mod_reg_u8, in_SHR_d_rm_mod_reg_u8, in_SHR_d_rm_mod_reg_u8, in_SHR_d_rm_mod_reg_u8, in_SHR_d_rm_mod_reg_u8, in_SHR_d_rm_mod_reg_u8, in_SHR_d_rm_mod_reg_u8, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_SAR_d_rm_mod_reg_u8, in_SAR_d_rm_mod_reg_u8, in_SAR_d_rm_mod_reg_u8, in_SAR_d_rm_mod_reg_u8, in_SAR_d_rm_mod_reg_u8, in_SAR_d_rm_mod_reg_u8, in_SAR_d_rm_mod_reg_u8, in_SAR_d_rm_mod_reg_u8, 
	// C0
	in_ROL_d_rm_mod_reg_u8, in_ROL_d_rm_mod_reg_u8, in_ROL_d_rm_mod_reg_u8, in_ROL_d_rm_mod_reg_u8, in_ROL_d_rm_mod_reg_u8, in_ROL_d_rm_mod_reg_u8, in_ROL_d_rm_mod_reg_u8, in_ROL_d_rm_mod_reg_u8, 
	// C8
	in_ROR_d_rm_mod_reg_u8, in_ROR_d_rm_mod_reg_u8, in_ROR_d_rm_mod_reg_u8, in_ROR_d_rm_mod_reg_u8, in_ROR_d_rm_mod_reg_u8, in_ROR_d_rm_mod_reg_u8, in_ROR_d_rm_mod_reg_u8, in_ROR_d_rm_mod_reg_u8, 
	// D0
	in_RCL_d_rm_mod_reg_u8, in_RCL_d_rm_mod_reg_u8, in_RCL_d_rm_mod_reg_u8, in_RCL_d_rm_mod_reg_u8, in_RCL_d_rm_mod_reg_u8, in_RCL_d_rm_mod_reg_u8, in_RCL_d_rm_mod_reg_u8, in_RCL_d_rm_mod_reg_u8, 
	// D8
	in_RCR_d_rm_mod_reg_u8, in_RCR_d_rm_mod_reg_u8, in_RCR_d_rm_mod_reg_u8, in_RCR_d_rm_mod_reg_u8, in_RCR_d_rm_mod_reg_u8, in_RCR_d_rm_mod_reg_u8, in_RCR_d_rm_mod_reg_u8, in_RCR_d_rm_mod_reg_u8, 
	// E0
	in_SHL_d_rm_mod_reg_u8, in_SHL_d_rm_mod_reg_u8, in_SHL_d_rm_mod_reg_u8, in_SHL_d_rm_mod_reg_u8, in_SHL_d_rm_mod_reg_u8, in_SHL_d_rm_mod_reg_u8, in_SHL_d_rm_mod_reg_u8, in_SHL_d_rm_mod_reg_u8, 
	// E8
	in_SHR_d_rm_mod_reg_u8, in_SHR_d_rm_mod_reg_u8, in_SHR_d_rm_mod_reg_u8, in_SHR_d_rm_mod_reg_u8, in_SHR_d_rm_mod_reg_u8, in_SHR_d_rm_mod_reg_u8, in_SHR_d_rm_mod_reg_u8, in_SHR_d_rm_mod_reg_u8, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_SAR_d_rm_mod_reg_u8, in_SAR_d_rm_mod_reg_u8, in_SAR_d_rm_mod_reg_u8, in_SAR_d_rm_mod_reg_u8, in_SAR_d_rm_mod_reg_u8, in_SAR_d_rm_mod_reg_u8, in_SAR_d_rm_mod_reg_u8, in_SAR_d_rm_mod_reg_u8, 
};
const OpState CpuRunnerX86::table_st_w_w_D1[] = {
	// 00
	in_ROL_w_rm_mod_reg_u16, in_ROL_w_rm_mod_reg_u16, in_ROL_w_rm_mod_reg_u16, in_ROL_w_rm_mod_reg_u16, in_ROL_w_rm_mod_reg_u16, in_ROL_w_rm_mod_reg_u16, in_ROL_w_rm_mod_reg_u16, in_ROL_w_rm_mod_reg_u16, 
	// 08
	in_ROR_w_rm_mod_reg_u16, in_ROR_w_rm_mod_reg_u16, in_ROR_w_rm_mod_reg_u16, in_ROR_w_rm_mod_reg_u16, in_ROR_w_rm_mod_reg_u16, in_ROR_w_rm_mod_reg_u16, in_ROR_w_rm_mod_reg_u16, in_ROR_w_rm_mod_reg_u16, 
	// 10
	in_RCL_w_rm_mod_reg_u16, in_RCL_w_rm_mod_reg_u16, in_RCL_w_rm_mod_reg_u16, in_RCL_w_rm_mod_reg_u16, in_RCL_w_rm_mod_reg_u16, in_RCL_w_rm_mod_reg_u16, in_RCL_w_rm_mod_reg_u16, in_RCL_w_rm_mod_reg_u16, 
	// 18
	in_RCR_w_rm_mod_reg_u16, in_RCR_w_rm_mod_reg_u16, in_RCR_w_rm_mod_reg_u16, in_RCR_w_rm_mod_reg_u16, in_RCR_w_rm_mod_reg_u16, in_RCR_w_rm_mod_reg_u16, in_RCR_w_rm_mod_reg_u16, in_RCR_w_rm_mod_reg_u16, 
	// 20
	in_SHL_w_rm_mod_reg_u16, in_SHL_w_rm_mod_reg_u16, in_SHL_w_rm_mod_reg_u16, in_SHL_w_rm_mod_reg_u16, in_SHL_w_rm_mod_reg_u16, in_SHL_w_rm_mod_reg_u16, in_SHL_w_rm_mod_reg_u16, in_SHL_w_rm_mod_reg_u16, 
	// 28
	in_SHR_w_rm_mod_reg_u16, in_SHR_w_rm_mod_reg_u16, in_SHR_w_rm_mod_reg_u16, in_SHR_w_rm_mod_reg_u16, in_SHR_w_rm_mod_reg_u16, in_SHR_w_rm_mod_reg_u16, in_SHR_w_rm_mod_reg_u16, in_SHR_w_rm_mod_reg_u16, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_SAR_w_rm_mod_reg_u16, in_SAR_w_rm_mod_reg_u16, in_SAR_w_rm_mod_reg_u16, in_SAR_w_rm_mod_reg_u16, in_SAR_w_rm_mod_reg_u16, in_SAR_w_rm_mod_reg_u16, in_SAR_w_rm_mod_reg_u16, in_SAR_w_rm_mod_reg_u16, 
	// 40
	in_ROL_w_rm_mod_reg_u16, in_ROL_w_rm_mod_reg_u16, in_ROL_w_rm_mod_reg_u16, in_ROL_w_rm_mod_reg_u16, in_ROL_w_rm_mod_reg_u16, in_ROL_w_rm_mod_reg_u16, in_ROL_w_rm_mod_reg_u16, in_ROL_w_rm_mod_reg_u16, 
	// 48
	in_ROR_w_rm_mod_reg_u16, in_ROR_w_rm_mod_reg_u16, in_ROR_w_rm_mod_reg_u16, in_ROR_w_rm_mod_reg_u16, in_ROR_w_rm_mod_reg_u16, in_ROR_w_rm_mod_reg_u16, in_ROR_w_rm_mod_reg_u16, in_ROR_w_rm_mod_reg_u16, 
	// 50
	in_RCL_w_rm_mod_reg_u16, in_RCL_w_rm_mod_reg_u16, in_RCL_w_rm_mod_reg_u16, in_RCL_w_rm_mod_reg_u16, in_RCL_w_rm_mod_reg_u16, in_RCL_w_rm_mod_reg_u16, in_RCL_w_rm_mod_reg_u16, in_RCL_w_rm_mod_reg_u16, 
	// 58
	in_RCR_w_rm_mod_reg_u16, in_RCR_w_rm_mod_reg_u16, in_RCR_w_rm_mod_reg_u16, in_RCR_w_rm_mod_reg_u16, in_RCR_w_rm_mod_reg_u16, in_RCR_w_rm_mod_reg_u16, in_RCR_w_rm_mod_reg_u16, in_RCR_w_rm_mod_reg_u16, 
	// 60
	in_SHL_w_rm_mod_reg_u16, in_SHL_w_rm_mod_reg_u16, in_SHL_w_rm_mod_reg_u16, in_SHL_w_rm_mod_reg_u16, in_SHL_w_rm_mod_reg_u16, in_SHL_w_rm_mod_reg_u16, in_SHL_w_rm_mod_reg_u16, in_SHL_w_rm_mod_reg_u16, 
	// 68
	in_SHR_w_rm_mod_reg_u16, in_SHR_w_rm_mod_reg_u16, in_SHR_w_rm_mod_reg_u16, in_SHR_w_rm_mod_reg_u16, in_SHR_w_rm_mod_reg_u16, in_SHR_w_rm_mod_reg_u16, in_SHR_w_rm_mod_reg_u16, in_SHR_w_rm_mod_reg_u16, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_SAR_w_rm_mod_reg_u16, in_SAR_w_rm_mod_reg_u16, in_SAR_w_rm_mod_reg_u16, in_SAR_w_rm_mod_reg_u16, in_SAR_w_rm_mod_reg_u16, in_SAR_w_rm_mod_reg_u16, in_SAR_w_rm_mod_reg_u16, in_SAR_w_rm_mod_reg_u16, 
	// 80
	in_ROL_w_rm_mod_reg_u16, in_ROL_w_rm_mod_reg_u16, in_ROL_w_rm_mod_reg_u16, in_ROL_w_rm_mod_reg_u16, in_ROL_w_rm_mod_reg_u16, in_ROL_w_rm_mod_reg_u16, in_ROL_w_rm_mod_reg_u16, in_ROL_w_rm_mod_reg_u16, 
	// 88
	in_ROR_w_rm_mod_reg_u16, in_ROR_w_rm_mod_reg_u16, in_ROR_w_rm_mod_reg_u16, in_ROR_w_rm_mod_reg_u16, in_ROR_w_rm_mod_reg_u16, in_ROR_w_rm_mod_reg_u16, in_ROR_w_rm_mod_reg_u16, in_ROR_w_rm_mod_reg_u16, 
	// 90
	in_RCL_w_rm_mod_reg_u16, in_RCL_w_rm_mod_reg_u16, in_RCL_w_rm_mod_reg_u16, in_RCL_w_rm_mod_reg_u16, in_RCL_w_rm_mod_reg_u16, in_RCL_w_rm_mod_reg_u16, in_RCL_w_rm_mod_reg_u16, in_RCL_w_rm_mod_reg_u16, 
	// 98
	in_RCR_w_rm_mod_reg_u16, in_RCR_w_rm_mod_reg_u16, in_RCR_w_rm_mod_reg_u16, in_RCR_w_rm_mod_reg_u16, in_RCR_w_rm_mod_reg_u16, in_RCR_w_rm_mod_reg_u16, in_RCR_w_rm_mod_reg_u16, in_RCR_w_rm_mod_reg_u16, 
	// A0
	in_SHL_w_rm_mod_reg_u16, in_SHL_w_rm_mod_reg_u16, in_SHL_w_rm_mod_reg_u16, in_SHL_w_rm_mod_reg_u16, in_SHL_w_rm_mod_reg_u16, in_SHL_w_rm_mod_reg_u16, in_SHL_w_rm_mod_reg_u16, in_SHL_w_rm_mod_reg_u16, 
	// A8
	in_SHR_w_rm_mod_reg_u16, in_SHR_w_rm_mod_reg_u16, in_SHR_w_rm_mod_reg_u16, in_SHR_w_rm_mod_reg_u16, in_SHR_w_rm_mod_reg_u16, in_SHR_w_rm_mod_reg_u16, in_SHR_w_rm_mod_reg_u16, in_SHR_w_rm_mod_reg_u16, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_SAR_w_rm_mod_reg_u16, in_SAR_w_rm_mod_reg_u16, in_SAR_w_rm_mod_reg_u16, in_SAR_w_rm_mod_reg_u16, in_SAR_w_rm_mod_reg_u16, in_SAR_w_rm_mod_reg_u16, in_SAR_w_rm_mod_reg_u16, in_SAR_w_rm_mod_reg_u16, 
	// C0
	in_ROL_w_rm_mod_reg_u16, in_ROL_w_rm_mod_reg_u16, in_ROL_w_rm_mod_reg_u16, in_ROL_w_rm_mod_reg_u16, in_ROL_w_rm_mod_reg_u16, in_ROL_w_rm_mod_reg_u16, in_ROL_w_rm_mod_reg_u16, in_ROL_w_rm_mod_reg_u16, 
	// C8
	in_ROR_w_rm_mod_reg_u16, in_ROR_w_rm_mod_reg_u16, in_ROR_w_rm_mod_reg_u16, in_ROR_w_rm_mod_reg_u16, in_ROR_w_rm_mod_reg_u16, in_ROR_w_rm_mod_reg_u16, in_ROR_w_rm_mod_reg_u16, in_ROR_w_rm_mod_reg_u16, 
	// D0
	in_RCL_w_rm_mod_reg_u16, in_RCL_w_rm_mod_reg_u16, in_RCL_w_rm_mod_reg_u16, in_RCL_w_rm_mod_reg_u16, in_RCL_w_rm_mod_reg_u16, in_RCL_w_rm_mod_reg_u16, in_RCL_w_rm_mod_reg_u16, in_RCL_w_rm_mod_reg_u16, 
	// D8
	in_RCR_w_rm_mod_reg_u16, in_RCR_w_rm_mod_reg_u16, in_RCR_w_rm_mod_reg_u16, in_RCR_w_rm_mod_reg_u16, in_RCR_w_rm_mod_reg_u16, in_RCR_w_rm_mod_reg_u16, in_RCR_w_rm_mod_reg_u16, in_RCR_w_rm_mod_reg_u16, 
	// E0
	in_SHL_w_rm_mod_reg_u16, in_SHL_w_rm_mod_reg_u16, in_SHL_w_rm_mod_reg_u16, in_SHL_w_rm_mod_reg_u16, in_SHL_w_rm_mod_reg_u16, in_SHL_w_rm_mod_reg_u16, in_SHL_w_rm_mod_reg_u16, in_SHL_w_rm_mod_reg_u16, 
	// E8
	in_SHR_w_rm_mod_reg_u16, in_SHR_w_rm_mod_reg_u16, in_SHR_w_rm_mod_reg_u16, in_SHR_w_rm_mod_reg_u16, in_SHR_w_rm_mod_reg_u16, in_SHR_w_rm_mod_reg_u16, in_SHR_w_rm_mod_reg_u16, in_SHR_w_rm_mod_reg_u16, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_SAR_w_rm_mod_reg_u16, in_SAR_w_rm_mod_reg_u16, in_SAR_w_rm_mod_reg_u16, in_SAR_w_rm_mod_reg_u16, in_SAR_w_rm_mod_reg_u16, in_SAR_w_rm_mod_reg_u16, in_SAR_w_rm_mod_reg_u16, in_SAR_w_rm_mod_reg_u16, 
};
const OpState CpuRunnerX86::table_st_w_d_D1[] = {
	// 00
	in_ROL_w_rm_mod_reg_u32, in_ROL_w_rm_mod_reg_u32, in_ROL_w_rm_mod_reg_u32, in_ROL_w_rm_mod_reg_u32, in_ROL_w_rm_mod_reg_u32, in_ROL_w_rm_mod_reg_u32, in_ROL_w_rm_mod_reg_u32, in_ROL_w_rm_mod_reg_u32, 
	// 08
	in_ROR_w_rm_mod_reg_u32, in_ROR_w_rm_mod_reg_u32, in_ROR_w_rm_mod_reg_u32, in_ROR_w_rm_mod_reg_u32, in_ROR_w_rm_mod_reg_u32, in_ROR_w_rm_mod_reg_u32, in_ROR_w_rm_mod_reg_u32, in_ROR_w_rm_mod_reg_u32, 
	// 10
	in_RCL_w_rm_mod_reg_u32, in_RCL_w_rm_mod_reg_u32, in_RCL_w_rm_mod_reg_u32, in_RCL_w_rm_mod_reg_u32, in_RCL_w_rm_mod_reg_u32, in_RCL_w_rm_mod_reg_u32, in_RCL_w_rm_mod_reg_u32, in_RCL_w_rm_mod_reg_u32, 
	// 18
	in_RCR_w_rm_mod_reg_u32, in_RCR_w_rm_mod_reg_u32, in_RCR_w_rm_mod_reg_u32, in_RCR_w_rm_mod_reg_u32, in_RCR_w_rm_mod_reg_u32, in_RCR_w_rm_mod_reg_u32, in_RCR_w_rm_mod_reg_u32, in_RCR_w_rm_mod_reg_u32, 
	// 20
	in_SHL_w_rm_mod_reg_u32, in_SHL_w_rm_mod_reg_u32, in_SHL_w_rm_mod_reg_u32, in_SHL_w_rm_mod_reg_u32, in_SHL_w_rm_mod_reg_u32, in_SHL_w_rm_mod_reg_u32, in_SHL_w_rm_mod_reg_u32, in_SHL_w_rm_mod_reg_u32, 
	// 28
	in_SHR_w_rm_mod_reg_u32, in_SHR_w_rm_mod_reg_u32, in_SHR_w_rm_mod_reg_u32, in_SHR_w_rm_mod_reg_u32, in_SHR_w_rm_mod_reg_u32, in_SHR_w_rm_mod_reg_u32, in_SHR_w_rm_mod_reg_u32, in_SHR_w_rm_mod_reg_u32, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_SAR_w_rm_mod_reg_u32, in_SAR_w_rm_mod_reg_u32, in_SAR_w_rm_mod_reg_u32, in_SAR_w_rm_mod_reg_u32, in_SAR_w_rm_mod_reg_u32, in_SAR_w_rm_mod_reg_u32, in_SAR_w_rm_mod_reg_u32, in_SAR_w_rm_mod_reg_u32, 
	// 40
	in_ROL_w_rm_mod_reg_u32, in_ROL_w_rm_mod_reg_u32, in_ROL_w_rm_mod_reg_u32, in_ROL_w_rm_mod_reg_u32, in_ROL_w_rm_mod_reg_u32, in_ROL_w_rm_mod_reg_u32, in_ROL_w_rm_mod_reg_u32, in_ROL_w_rm_mod_reg_u32, 
	// 48
	in_ROR_w_rm_mod_reg_u32, in_ROR_w_rm_mod_reg_u32, in_ROR_w_rm_mod_reg_u32, in_ROR_w_rm_mod_reg_u32, in_ROR_w_rm_mod_reg_u32, in_ROR_w_rm_mod_reg_u32, in_ROR_w_rm_mod_reg_u32, in_ROR_w_rm_mod_reg_u32, 
	// 50
	in_RCL_w_rm_mod_reg_u32, in_RCL_w_rm_mod_reg_u32, in_RCL_w_rm_mod_reg_u32, in_RCL_w_rm_mod_reg_u32, in_RCL_w_rm_mod_reg_u32, in_RCL_w_rm_mod_reg_u32, in_RCL_w_rm_mod_reg_u32, in_RCL_w_rm_mod_reg_u32, 
	// 58
	in_RCR_w_rm_mod_reg_u32, in_RCR_w_rm_mod_reg_u32, in_RCR_w_rm_mod_reg_u32, in_RCR_w_rm_mod_reg_u32, in_RCR_w_rm_mod_reg_u32, in_RCR_w_rm_mod_reg_u32, in_RCR_w_rm_mod_reg_u32, in_RCR_w_rm_mod_reg_u32, 
	// 60
	in_SHL_w_rm_mod_reg_u32, in_SHL_w_rm_mod_reg_u32, in_SHL_w_rm_mod_reg_u32, in_SHL_w_rm_mod_reg_u32, in_SHL_w_rm_mod_reg_u32, in_SHL_w_rm_mod_reg_u32, in_SHL_w_rm_mod_reg_u32, in_SHL_w_rm_mod_reg_u32, 
	// 68
	in_SHR_w_rm_mod_reg_u32, in_SHR_w_rm_mod_reg_u32, in_SHR_w_rm_mod_reg_u32, in_SHR_w_rm_mod_reg_u32, in_SHR_w_rm_mod_reg_u32, in_SHR_w_rm_mod_reg_u32, in_SHR_w_rm_mod_reg_u32, in_SHR_w_rm_mod_reg_u32, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_SAR_w_rm_mod_reg_u32, in_SAR_w_rm_mod_reg_u32, in_SAR_w_rm_mod_reg_u32, in_SAR_w_rm_mod_reg_u32, in_SAR_w_rm_mod_reg_u32, in_SAR_w_rm_mod_reg_u32, in_SAR_w_rm_mod_reg_u32, in_SAR_w_rm_mod_reg_u32, 
	// 80
	in_ROL_w_rm_mod_reg_u32, in_ROL_w_rm_mod_reg_u32, in_ROL_w_rm_mod_reg_u32, in_ROL_w_rm_mod_reg_u32, in_ROL_w_rm_mod_reg_u32, in_ROL_w_rm_mod_reg_u32, in_ROL_w_rm_mod_reg_u32, in_ROL_w_rm_mod_reg_u32, 
	// 88
	in_ROR_w_rm_mod_reg_u32, in_ROR_w_rm_mod_reg_u32, in_ROR_w_rm_mod_reg_u32, in_ROR_w_rm_mod_reg_u32, in_ROR_w_rm_mod_reg_u32, in_ROR_w_rm_mod_reg_u32, in_ROR_w_rm_mod_reg_u32, in_ROR_w_rm_mod_reg_u32, 
	// 90
	in_RCL_w_rm_mod_reg_u32, in_RCL_w_rm_mod_reg_u32, in_RCL_w_rm_mod_reg_u32, in_RCL_w_rm_mod_reg_u32, in_RCL_w_rm_mod_reg_u32, in_RCL_w_rm_mod_reg_u32, in_RCL_w_rm_mod_reg_u32, in_RCL_w_rm_mod_reg_u32, 
	// 98
	in_RCR_w_rm_mod_reg_u32, in_RCR_w_rm_mod_reg_u32, in_RCR_w_rm_mod_reg_u32, in_RCR_w_rm_mod_reg_u32, in_RCR_w_rm_mod_reg_u32, in_RCR_w_rm_mod_reg_u32, in_RCR_w_rm_mod_reg_u32, in_RCR_w_rm_mod_reg_u32, 
	// A0
	in_SHL_w_rm_mod_reg_u32, in_SHL_w_rm_mod_reg_u32, in_SHL_w_rm_mod_reg_u32, in_SHL_w_rm_mod_reg_u32, in_SHL_w_rm_mod_reg_u32, in_SHL_w_rm_mod_reg_u32, in_SHL_w_rm_mod_reg_u32, in_SHL_w_rm_mod_reg_u32, 
	// A8
	in_SHR_w_rm_mod_reg_u32, in_SHR_w_rm_mod_reg_u32, in_SHR_w_rm_mod_reg_u32, in_SHR_w_rm_mod_reg_u32, in_SHR_w_rm_mod_reg_u32, in_SHR_w_rm_mod_reg_u32, in_SHR_w_rm_mod_reg_u32, in_SHR_w_rm_mod_reg_u32, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_SAR_w_rm_mod_reg_u32, in_SAR_w_rm_mod_reg_u32, in_SAR_w_rm_mod_reg_u32, in_SAR_w_rm_mod_reg_u32, in_SAR_w_rm_mod_reg_u32, in_SAR_w_rm_mod_reg_u32, in_SAR_w_rm_mod_reg_u32, in_SAR_w_rm_mod_reg_u32, 
	// C0
	in_ROL_w_rm_mod_reg_u32, in_ROL_w_rm_mod_reg_u32, in_ROL_w_rm_mod_reg_u32, in_ROL_w_rm_mod_reg_u32, in_ROL_w_rm_mod_reg_u32, in_ROL_w_rm_mod_reg_u32, in_ROL_w_rm_mod_reg_u32, in_ROL_w_rm_mod_reg_u32, 
	// C8
	in_ROR_w_rm_mod_reg_u32, in_ROR_w_rm_mod_reg_u32, in_ROR_w_rm_mod_reg_u32, in_ROR_w_rm_mod_reg_u32, in_ROR_w_rm_mod_reg_u32, in_ROR_w_rm_mod_reg_u32, in_ROR_w_rm_mod_reg_u32, in_ROR_w_rm_mod_reg_u32, 
	// D0
	in_RCL_w_rm_mod_reg_u32, in_RCL_w_rm_mod_reg_u32, in_RCL_w_rm_mod_reg_u32, in_RCL_w_rm_mod_reg_u32, in_RCL_w_rm_mod_reg_u32, in_RCL_w_rm_mod_reg_u32, in_RCL_w_rm_mod_reg_u32, in_RCL_w_rm_mod_reg_u32, 
	// D8
	in_RCR_w_rm_mod_reg_u32, in_RCR_w_rm_mod_reg_u32, in_RCR_w_rm_mod_reg_u32, in_RCR_w_rm_mod_reg_u32, in_RCR_w_rm_mod_reg_u32, in_RCR_w_rm_mod_reg_u32, in_RCR_w_rm_mod_reg_u32, in_RCR_w_rm_mod_reg_u32, 
	// E0
	in_SHL_w_rm_mod_reg_u32, in_SHL_w_rm_mod_reg_u32, in_SHL_w_rm_mod_reg_u32, in_SHL_w_rm_mod_reg_u32, in_SHL_w_rm_mod_reg_u32, in_SHL_w_rm_mod_reg_u32, in_SHL_w_rm_mod_reg_u32, in_SHL_w_rm_mod_reg_u32, 
	// E8
	in_SHR_w_rm_mod_reg_u32, in_SHR_w_rm_mod_reg_u32, in_SHR_w_rm_mod_reg_u32, in_SHR_w_rm_mod_reg_u32, in_SHR_w_rm_mod_reg_u32, in_SHR_w_rm_mod_reg_u32, in_SHR_w_rm_mod_reg_u32, in_SHR_w_rm_mod_reg_u32, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_SAR_w_rm_mod_reg_u32, in_SAR_w_rm_mod_reg_u32, in_SAR_w_rm_mod_reg_u32, in_SAR_w_rm_mod_reg_u32, in_SAR_w_rm_mod_reg_u32, in_SAR_w_rm_mod_reg_u32, in_SAR_w_rm_mod_reg_u32, in_SAR_w_rm_mod_reg_u32, 
};
const OpState CpuRunnerX86::table_st_d_w_D1[] = {
	// 00
	in_ROL_d_rm_mod_reg_u16, in_ROL_d_rm_mod_reg_u16, in_ROL_d_rm_mod_reg_u16, in_ROL_d_rm_mod_reg_u16, in_ROL_d_rm_mod_reg_u16, in_ROL_d_rm_mod_reg_u16, in_ROL_d_rm_mod_reg_u16, in_ROL_d_rm_mod_reg_u16, 
	// 08
	in_ROR_d_rm_mod_reg_u16, in_ROR_d_rm_mod_reg_u16, in_ROR_d_rm_mod_reg_u16, in_ROR_d_rm_mod_reg_u16, in_ROR_d_rm_mod_reg_u16, in_ROR_d_rm_mod_reg_u16, in_ROR_d_rm_mod_reg_u16, in_ROR_d_rm_mod_reg_u16, 
	// 10
	in_RCL_d_rm_mod_reg_u16, in_RCL_d_rm_mod_reg_u16, in_RCL_d_rm_mod_reg_u16, in_RCL_d_rm_mod_reg_u16, in_RCL_d_rm_mod_reg_u16, in_RCL_d_rm_mod_reg_u16, in_RCL_d_rm_mod_reg_u16, in_RCL_d_rm_mod_reg_u16, 
	// 18
	in_RCR_d_rm_mod_reg_u16, in_RCR_d_rm_mod_reg_u16, in_RCR_d_rm_mod_reg_u16, in_RCR_d_rm_mod_reg_u16, in_RCR_d_rm_mod_reg_u16, in_RCR_d_rm_mod_reg_u16, in_RCR_d_rm_mod_reg_u16, in_RCR_d_rm_mod_reg_u16, 
	// 20
	in_SHL_d_rm_mod_reg_u16, in_SHL_d_rm_mod_reg_u16, in_SHL_d_rm_mod_reg_u16, in_SHL_d_rm_mod_reg_u16, in_SHL_d_rm_mod_reg_u16, in_SHL_d_rm_mod_reg_u16, in_SHL_d_rm_mod_reg_u16, in_SHL_d_rm_mod_reg_u16, 
	// 28
	in_SHR_d_rm_mod_reg_u16, in_SHR_d_rm_mod_reg_u16, in_SHR_d_rm_mod_reg_u16, in_SHR_d_rm_mod_reg_u16, in_SHR_d_rm_mod_reg_u16, in_SHR_d_rm_mod_reg_u16, in_SHR_d_rm_mod_reg_u16, in_SHR_d_rm_mod_reg_u16, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_SAR_d_rm_mod_reg_u16, in_SAR_d_rm_mod_reg_u16, in_SAR_d_rm_mod_reg_u16, in_SAR_d_rm_mod_reg_u16, in_SAR_d_rm_mod_reg_u16, in_SAR_d_rm_mod_reg_u16, in_SAR_d_rm_mod_reg_u16, in_SAR_d_rm_mod_reg_u16, 
	// 40
	in_ROL_d_rm_mod_reg_u16, in_ROL_d_rm_mod_reg_u16, in_ROL_d_rm_mod_reg_u16, in_ROL_d_rm_mod_reg_u16, in_ROL_d_rm_mod_reg_u16, in_ROL_d_rm_mod_reg_u16, in_ROL_d_rm_mod_reg_u16, in_ROL_d_rm_mod_reg_u16, 
	// 48
	in_ROR_d_rm_mod_reg_u16, in_ROR_d_rm_mod_reg_u16, in_ROR_d_rm_mod_reg_u16, in_ROR_d_rm_mod_reg_u16, in_ROR_d_rm_mod_reg_u16, in_ROR_d_rm_mod_reg_u16, in_ROR_d_rm_mod_reg_u16, in_ROR_d_rm_mod_reg_u16, 
	// 50
	in_RCL_d_rm_mod_reg_u16, in_RCL_d_rm_mod_reg_u16, in_RCL_d_rm_mod_reg_u16, in_RCL_d_rm_mod_reg_u16, in_RCL_d_rm_mod_reg_u16, in_RCL_d_rm_mod_reg_u16, in_RCL_d_rm_mod_reg_u16, in_RCL_d_rm_mod_reg_u16, 
	// 58
	in_RCR_d_rm_mod_reg_u16, in_RCR_d_rm_mod_reg_u16, in_RCR_d_rm_mod_reg_u16, in_RCR_d_rm_mod_reg_u16, in_RCR_d_rm_mod_reg_u16, in_RCR_d_rm_mod_reg_u16, in_RCR_d_rm_mod_reg_u16, in_RCR_d_rm_mod_reg_u16, 
	// 60
	in_SHL_d_rm_mod_reg_u16, in_SHL_d_rm_mod_reg_u16, in_SHL_d_rm_mod_reg_u16, in_SHL_d_rm_mod_reg_u16, in_SHL_d_rm_mod_reg_u16, in_SHL_d_rm_mod_reg_u16, in_SHL_d_rm_mod_reg_u16, in_SHL_d_rm_mod_reg_u16, 
	// 68
	in_SHR_d_rm_mod_reg_u16, in_SHR_d_rm_mod_reg_u16, in_SHR_d_rm_mod_reg_u16, in_SHR_d_rm_mod_reg_u16, in_SHR_d_rm_mod_reg_u16, in_SHR_d_rm_mod_reg_u16, in_SHR_d_rm_mod_reg_u16, in_SHR_d_rm_mod_reg_u16, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_SAR_d_rm_mod_reg_u16, in_SAR_d_rm_mod_reg_u16, in_SAR_d_rm_mod_reg_u16, in_SAR_d_rm_mod_reg_u16, in_SAR_d_rm_mod_reg_u16, in_SAR_d_rm_mod_reg_u16, in_SAR_d_rm_mod_reg_u16, in_SAR_d_rm_mod_reg_u16, 
	// 80
	in_ROL_d_rm_mod_reg_u16, in_ROL_d_rm_mod_reg_u16, in_ROL_d_rm_mod_reg_u16, in_ROL_d_rm_mod_reg_u16, in_ROL_d_rm_mod_reg_u16, in_ROL_d_rm_mod_reg_u16, in_ROL_d_rm_mod_reg_u16, in_ROL_d_rm_mod_reg_u16, 
	// 88
	in_ROR_d_rm_mod_reg_u16, in_ROR_d_rm_mod_reg_u16, in_ROR_d_rm_mod_reg_u16, in_ROR_d_rm_mod_reg_u16, in_ROR_d_rm_mod_reg_u16, in_ROR_d_rm_mod_reg_u16, in_ROR_d_rm_mod_reg_u16, in_ROR_d_rm_mod_reg_u16, 
	// 90
	in_RCL_d_rm_mod_reg_u16, in_RCL_d_rm_mod_reg_u16, in_RCL_d_rm_mod_reg_u16, in_RCL_d_rm_mod_reg_u16, in_RCL_d_rm_mod_reg_u16, in_RCL_d_rm_mod_reg_u16, in_RCL_d_rm_mod_reg_u16, in_RCL_d_rm_mod_reg_u16, 
	// 98
	in_RCR_d_rm_mod_reg_u16, in_RCR_d_rm_mod_reg_u16, in_RCR_d_rm_mod_reg_u16, in_RCR_d_rm_mod_reg_u16, in_RCR_d_rm_mod_reg_u16, in_RCR_d_rm_mod_reg_u16, in_RCR_d_rm_mod_reg_u16, in_RCR_d_rm_mod_reg_u16, 
	// A0
	in_SHL_d_rm_mod_reg_u16, in_SHL_d_rm_mod_reg_u16, in_SHL_d_rm_mod_reg_u16, in_SHL_d_rm_mod_reg_u16, in_SHL_d_rm_mod_reg_u16, in_SHL_d_rm_mod_reg_u16, in_SHL_d_rm_mod_reg_u16, in_SHL_d_rm_mod_reg_u16, 
	// A8
	in_SHR_d_rm_mod_reg_u16, in_SHR_d_rm_mod_reg_u16, in_SHR_d_rm_mod_reg_u16, in_SHR_d_rm_mod_reg_u16, in_SHR_d_rm_mod_reg_u16, in_SHR_d_rm_mod_reg_u16, in_SHR_d_rm_mod_reg_u16, in_SHR_d_rm_mod_reg_u16, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_SAR_d_rm_mod_reg_u16, in_SAR_d_rm_mod_reg_u16, in_SAR_d_rm_mod_reg_u16, in_SAR_d_rm_mod_reg_u16, in_SAR_d_rm_mod_reg_u16, in_SAR_d_rm_mod_reg_u16, in_SAR_d_rm_mod_reg_u16, in_SAR_d_rm_mod_reg_u16, 
	// C0
	in_ROL_d_rm_mod_reg_u16, in_ROL_d_rm_mod_reg_u16, in_ROL_d_rm_mod_reg_u16, in_ROL_d_rm_mod_reg_u16, in_ROL_d_rm_mod_reg_u16, in_ROL_d_rm_mod_reg_u16, in_ROL_d_rm_mod_reg_u16, in_ROL_d_rm_mod_reg_u16, 
	// C8
	in_ROR_d_rm_mod_reg_u16, in_ROR_d_rm_mod_reg_u16, in_ROR_d_rm_mod_reg_u16, in_ROR_d_rm_mod_reg_u16, in_ROR_d_rm_mod_reg_u16, in_ROR_d_rm_mod_reg_u16, in_ROR_d_rm_mod_reg_u16, in_ROR_d_rm_mod_reg_u16, 
	// D0
	in_RCL_d_rm_mod_reg_u16, in_RCL_d_rm_mod_reg_u16, in_RCL_d_rm_mod_reg_u16, in_RCL_d_rm_mod_reg_u16, in_RCL_d_rm_mod_reg_u16, in_RCL_d_rm_mod_reg_u16, in_RCL_d_rm_mod_reg_u16, in_RCL_d_rm_mod_reg_u16, 
	// D8
	in_RCR_d_rm_mod_reg_u16, in_RCR_d_rm_mod_reg_u16, in_RCR_d_rm_mod_reg_u16, in_RCR_d_rm_mod_reg_u16, in_RCR_d_rm_mod_reg_u16, in_RCR_d_rm_mod_reg_u16, in_RCR_d_rm_mod_reg_u16, in_RCR_d_rm_mod_reg_u16, 
	// E0
	in_SHL_d_rm_mod_reg_u16, in_SHL_d_rm_mod_reg_u16, in_SHL_d_rm_mod_reg_u16, in_SHL_d_rm_mod_reg_u16, in_SHL_d_rm_mod_reg_u16, in_SHL_d_rm_mod_reg_u16, in_SHL_d_rm_mod_reg_u16, in_SHL_d_rm_mod_reg_u16, 
	// E8
	in_SHR_d_rm_mod_reg_u16, in_SHR_d_rm_mod_reg_u16, in_SHR_d_rm_mod_reg_u16, in_SHR_d_rm_mod_reg_u16, in_SHR_d_rm_mod_reg_u16, in_SHR_d_rm_mod_reg_u16, in_SHR_d_rm_mod_reg_u16, in_SHR_d_rm_mod_reg_u16, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_SAR_d_rm_mod_reg_u16, in_SAR_d_rm_mod_reg_u16, in_SAR_d_rm_mod_reg_u16, in_SAR_d_rm_mod_reg_u16, in_SAR_d_rm_mod_reg_u16, in_SAR_d_rm_mod_reg_u16, in_SAR_d_rm_mod_reg_u16, in_SAR_d_rm_mod_reg_u16, 
};
const OpState CpuRunnerX86::table_st_d_d_D1[] = {
	// 00
	in_ROL_d_rm_mod_reg_u32, in_ROL_d_rm_mod_reg_u32, in_ROL_d_rm_mod_reg_u32, in_ROL_d_rm_mod_reg_u32, in_ROL_d_rm_mod_reg_u32, in_ROL_d_rm_mod_reg_u32, in_ROL_d_rm_mod_reg_u32, in_ROL_d_rm_mod_reg_u32, 
	// 08
	in_ROR_d_rm_mod_reg_u32, in_ROR_d_rm_mod_reg_u32, in_ROR_d_rm_mod_reg_u32, in_ROR_d_rm_mod_reg_u32, in_ROR_d_rm_mod_reg_u32, in_ROR_d_rm_mod_reg_u32, in_ROR_d_rm_mod_reg_u32, in_ROR_d_rm_mod_reg_u32, 
	// 10
	in_RCL_d_rm_mod_reg_u32, in_RCL_d_rm_mod_reg_u32, in_RCL_d_rm_mod_reg_u32, in_RCL_d_rm_mod_reg_u32, in_RCL_d_rm_mod_reg_u32, in_RCL_d_rm_mod_reg_u32, in_RCL_d_rm_mod_reg_u32, in_RCL_d_rm_mod_reg_u32, 
	// 18
	in_RCR_d_rm_mod_reg_u32, in_RCR_d_rm_mod_reg_u32, in_RCR_d_rm_mod_reg_u32, in_RCR_d_rm_mod_reg_u32, in_RCR_d_rm_mod_reg_u32, in_RCR_d_rm_mod_reg_u32, in_RCR_d_rm_mod_reg_u32, in_RCR_d_rm_mod_reg_u32, 
	// 20
	in_SHL_d_rm_mod_reg_u32, in_SHL_d_rm_mod_reg_u32, in_SHL_d_rm_mod_reg_u32, in_SHL_d_rm_mod_reg_u32, in_SHL_d_rm_mod_reg_u32, in_SHL_d_rm_mod_reg_u32, in_SHL_d_rm_mod_reg_u32, in_SHL_d_rm_mod_reg_u32, 
	// 28
	in_SHR_d_rm_mod_reg_u32, in_SHR_d_rm_mod_reg_u32, in_SHR_d_rm_mod_reg_u32, in_SHR_d_rm_mod_reg_u32, in_SHR_d_rm_mod_reg_u32, in_SHR_d_rm_mod_reg_u32, in_SHR_d_rm_mod_reg_u32, in_SHR_d_rm_mod_reg_u32, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_SAR_d_rm_mod_reg_u32, in_SAR_d_rm_mod_reg_u32, in_SAR_d_rm_mod_reg_u32, in_SAR_d_rm_mod_reg_u32, in_SAR_d_rm_mod_reg_u32, in_SAR_d_rm_mod_reg_u32, in_SAR_d_rm_mod_reg_u32, in_SAR_d_rm_mod_reg_u32, 
	// 40
	in_ROL_d_rm_mod_reg_u32, in_ROL_d_rm_mod_reg_u32, in_ROL_d_rm_mod_reg_u32, in_ROL_d_rm_mod_reg_u32, in_ROL_d_rm_mod_reg_u32, in_ROL_d_rm_mod_reg_u32, in_ROL_d_rm_mod_reg_u32, in_ROL_d_rm_mod_reg_u32, 
	// 48
	in_ROR_d_rm_mod_reg_u32, in_ROR_d_rm_mod_reg_u32, in_ROR_d_rm_mod_reg_u32, in_ROR_d_rm_mod_reg_u32, in_ROR_d_rm_mod_reg_u32, in_ROR_d_rm_mod_reg_u32, in_ROR_d_rm_mod_reg_u32, in_ROR_d_rm_mod_reg_u32, 
	// 50
	in_RCL_d_rm_mod_reg_u32, in_RCL_d_rm_mod_reg_u32, in_RCL_d_rm_mod_reg_u32, in_RCL_d_rm_mod_reg_u32, in_RCL_d_rm_mod_reg_u32, in_RCL_d_rm_mod_reg_u32, in_RCL_d_rm_mod_reg_u32, in_RCL_d_rm_mod_reg_u32, 
	// 58
	in_RCR_d_rm_mod_reg_u32, in_RCR_d_rm_mod_reg_u32, in_RCR_d_rm_mod_reg_u32, in_RCR_d_rm_mod_reg_u32, in_RCR_d_rm_mod_reg_u32, in_RCR_d_rm_mod_reg_u32, in_RCR_d_rm_mod_reg_u32, in_RCR_d_rm_mod_reg_u32, 
	// 60
	in_SHL_d_rm_mod_reg_u32, in_SHL_d_rm_mod_reg_u32, in_SHL_d_rm_mod_reg_u32, in_SHL_d_rm_mod_reg_u32, in_SHL_d_rm_mod_reg_u32, in_SHL_d_rm_mod_reg_u32, in_SHL_d_rm_mod_reg_u32, in_SHL_d_rm_mod_reg_u32, 
	// 68
	in_SHR_d_rm_mod_reg_u32, in_SHR_d_rm_mod_reg_u32, in_SHR_d_rm_mod_reg_u32, in_SHR_d_rm_mod_reg_u32, in_SHR_d_rm_mod_reg_u32, in_SHR_d_rm_mod_reg_u32, in_SHR_d_rm_mod_reg_u32, in_SHR_d_rm_mod_reg_u32, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_SAR_d_rm_mod_reg_u32, in_SAR_d_rm_mod_reg_u32, in_SAR_d_rm_mod_reg_u32, in_SAR_d_rm_mod_reg_u32, in_SAR_d_rm_mod_reg_u32, in_SAR_d_rm_mod_reg_u32, in_SAR_d_rm_mod_reg_u32, in_SAR_d_rm_mod_reg_u32, 
	// 80
	in_ROL_d_rm_mod_reg_u32, in_ROL_d_rm_mod_reg_u32, in_ROL_d_rm_mod_reg_u32, in_ROL_d_rm_mod_reg_u32, in_ROL_d_rm_mod_reg_u32, in_ROL_d_rm_mod_reg_u32, in_ROL_d_rm_mod_reg_u32, in_ROL_d_rm_mod_reg_u32, 
	// 88
	in_ROR_d_rm_mod_reg_u32, in_ROR_d_rm_mod_reg_u32, in_ROR_d_rm_mod_reg_u32, in_ROR_d_rm_mod_reg_u32, in_ROR_d_rm_mod_reg_u32, in_ROR_d_rm_mod_reg_u32, in_ROR_d_rm_mod_reg_u32, in_ROR_d_rm_mod_reg_u32, 
	// 90
	in_RCL_d_rm_mod_reg_u32, in_RCL_d_rm_mod_reg_u32, in_RCL_d_rm_mod_reg_u32, in_RCL_d_rm_mod_reg_u32, in_RCL_d_rm_mod_reg_u32, in_RCL_d_rm_mod_reg_u32, in_RCL_d_rm_mod_reg_u32, in_RCL_d_rm_mod_reg_u32, 
	// 98
	in_RCR_d_rm_mod_reg_u32, in_RCR_d_rm_mod_reg_u32, in_RCR_d_rm_mod_reg_u32, in_RCR_d_rm_mod_reg_u32, in_RCR_d_rm_mod_reg_u32, in_RCR_d_rm_mod_reg_u32, in_RCR_d_rm_mod_reg_u32, in_RCR_d_rm_mod_reg_u32, 
	// A0
	in_SHL_d_rm_mod_reg_u32, in_SHL_d_rm_mod_reg_u32, in_SHL_d_rm_mod_reg_u32, in_SHL_d_rm_mod_reg_u32, in_SHL_d_rm_mod_reg_u32, in_SHL_d_rm_mod_reg_u32, in_SHL_d_rm_mod_reg_u32, in_SHL_d_rm_mod_reg_u32, 
	// A8
	in_SHR_d_rm_mod_reg_u32, in_SHR_d_rm_mod_reg_u32, in_SHR_d_rm_mod_reg_u32, in_SHR_d_rm_mod_reg_u32, in_SHR_d_rm_mod_reg_u32, in_SHR_d_rm_mod_reg_u32, in_SHR_d_rm_mod_reg_u32, in_SHR_d_rm_mod_reg_u32, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_SAR_d_rm_mod_reg_u32, in_SAR_d_rm_mod_reg_u32, in_SAR_d_rm_mod_reg_u32, in_SAR_d_rm_mod_reg_u32, in_SAR_d_rm_mod_reg_u32, in_SAR_d_rm_mod_reg_u32, in_SAR_d_rm_mod_reg_u32, in_SAR_d_rm_mod_reg_u32, 
	// C0
	in_ROL_d_rm_mod_reg_u32, in_ROL_d_rm_mod_reg_u32, in_ROL_d_rm_mod_reg_u32, in_ROL_d_rm_mod_reg_u32, in_ROL_d_rm_mod_reg_u32, in_ROL_d_rm_mod_reg_u32, in_ROL_d_rm_mod_reg_u32, in_ROL_d_rm_mod_reg_u32, 
	// C8
	in_ROR_d_rm_mod_reg_u32, in_ROR_d_rm_mod_reg_u32, in_ROR_d_rm_mod_reg_u32, in_ROR_d_rm_mod_reg_u32, in_ROR_d_rm_mod_reg_u32, in_ROR_d_rm_mod_reg_u32, in_ROR_d_rm_mod_reg_u32, in_ROR_d_rm_mod_reg_u32, 
	// D0
	in_RCL_d_rm_mod_reg_u32, in_RCL_d_rm_mod_reg_u32, in_RCL_d_rm_mod_reg_u32, in_RCL_d_rm_mod_reg_u32, in_RCL_d_rm_mod_reg_u32, in_RCL_d_rm_mod_reg_u32, in_RCL_d_rm_mod_reg_u32, in_RCL_d_rm_mod_reg_u32, 
	// D8
	in_RCR_d_rm_mod_reg_u32, in_RCR_d_rm_mod_reg_u32, in_RCR_d_rm_mod_reg_u32, in_RCR_d_rm_mod_reg_u32, in_RCR_d_rm_mod_reg_u32, in_RCR_d_rm_mod_reg_u32, in_RCR_d_rm_mod_reg_u32, in_RCR_d_rm_mod_reg_u32, 
	// E0
	in_SHL_d_rm_mod_reg_u32, in_SHL_d_rm_mod_reg_u32, in_SHL_d_rm_mod_reg_u32, in_SHL_d_rm_mod_reg_u32, in_SHL_d_rm_mod_reg_u32, in_SHL_d_rm_mod_reg_u32, in_SHL_d_rm_mod_reg_u32, in_SHL_d_rm_mod_reg_u32, 
	// E8
	in_SHR_d_rm_mod_reg_u32, in_SHR_d_rm_mod_reg_u32, in_SHR_d_rm_mod_reg_u32, in_SHR_d_rm_mod_reg_u32, in_SHR_d_rm_mod_reg_u32, in_SHR_d_rm_mod_reg_u32, in_SHR_d_rm_mod_reg_u32, in_SHR_d_rm_mod_reg_u32, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_SAR_d_rm_mod_reg_u32, in_SAR_d_rm_mod_reg_u32, in_SAR_d_rm_mod_reg_u32, in_SAR_d_rm_mod_reg_u32, in_SAR_d_rm_mod_reg_u32, in_SAR_d_rm_mod_reg_u32, in_SAR_d_rm_mod_reg_u32, in_SAR_d_rm_mod_reg_u32, 
};
const OpState CpuRunnerX86::table_st_w_w_D2[] = {
	// 00
	in_ROL_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u8_reg_gen_1_u8, 
	// 08
	in_ROR_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u8_reg_gen_1_u8, 
	// 10
	in_RCL_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u8_reg_gen_1_u8, 
	// 18
	in_RCR_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u8_reg_gen_1_u8, 
	// 20
	in_SHL_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u8_reg_gen_1_u8, 
	// 28
	in_SHR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u8_reg_gen_1_u8, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_SAR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u8_reg_gen_1_u8, 
	// 40
	in_ROL_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u8_reg_gen_1_u8, 
	// 48
	in_ROR_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u8_reg_gen_1_u8, 
	// 50
	in_RCL_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u8_reg_gen_1_u8, 
	// 58
	in_RCR_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u8_reg_gen_1_u8, 
	// 60
	in_SHL_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u8_reg_gen_1_u8, 
	// 68
	in_SHR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u8_reg_gen_1_u8, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_SAR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u8_reg_gen_1_u8, 
	// 80
	in_ROL_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u8_reg_gen_1_u8, 
	// 88
	in_ROR_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u8_reg_gen_1_u8, 
	// 90
	in_RCL_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u8_reg_gen_1_u8, 
	// 98
	in_RCR_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u8_reg_gen_1_u8, 
	// A0
	in_SHL_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u8_reg_gen_1_u8, 
	// A8
	in_SHR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u8_reg_gen_1_u8, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_SAR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u8_reg_gen_1_u8, 
	// C0
	in_ROL_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u8_reg_gen_1_u8, 
	// C8
	in_ROR_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u8_reg_gen_1_u8, 
	// D0
	in_RCL_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u8_reg_gen_1_u8, 
	// D8
	in_RCR_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u8_reg_gen_1_u8, 
	// E0
	in_SHL_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u8_reg_gen_1_u8, 
	// E8
	in_SHR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u8_reg_gen_1_u8, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_SAR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u8_reg_gen_1_u8, 
};
const OpState CpuRunnerX86::table_st_w_d_D2[] = {
	// 00
	in_ROL_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u8_reg_gen_1_u8, 
	// 08
	in_ROR_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u8_reg_gen_1_u8, 
	// 10
	in_RCL_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u8_reg_gen_1_u8, 
	// 18
	in_RCR_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u8_reg_gen_1_u8, 
	// 20
	in_SHL_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u8_reg_gen_1_u8, 
	// 28
	in_SHR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u8_reg_gen_1_u8, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_SAR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u8_reg_gen_1_u8, 
	// 40
	in_ROL_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u8_reg_gen_1_u8, 
	// 48
	in_ROR_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u8_reg_gen_1_u8, 
	// 50
	in_RCL_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u8_reg_gen_1_u8, 
	// 58
	in_RCR_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u8_reg_gen_1_u8, 
	// 60
	in_SHL_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u8_reg_gen_1_u8, 
	// 68
	in_SHR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u8_reg_gen_1_u8, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_SAR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u8_reg_gen_1_u8, 
	// 80
	in_ROL_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u8_reg_gen_1_u8, 
	// 88
	in_ROR_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u8_reg_gen_1_u8, 
	// 90
	in_RCL_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u8_reg_gen_1_u8, 
	// 98
	in_RCR_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u8_reg_gen_1_u8, 
	// A0
	in_SHL_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u8_reg_gen_1_u8, 
	// A8
	in_SHR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u8_reg_gen_1_u8, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_SAR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u8_reg_gen_1_u8, 
	// C0
	in_ROL_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u8_reg_gen_1_u8, 
	// C8
	in_ROR_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u8_reg_gen_1_u8, 
	// D0
	in_RCL_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u8_reg_gen_1_u8, 
	// D8
	in_RCR_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u8_reg_gen_1_u8, 
	// E0
	in_SHL_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u8_reg_gen_1_u8, 
	// E8
	in_SHR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u8_reg_gen_1_u8, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_SAR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u8_reg_gen_1_u8, 
};
const OpState CpuRunnerX86::table_st_d_w_D2[] = {
	// 00
	in_ROL_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u8_reg_gen_1_u8, 
	// 08
	in_ROR_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u8_reg_gen_1_u8, 
	// 10
	in_RCL_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u8_reg_gen_1_u8, 
	// 18
	in_RCR_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u8_reg_gen_1_u8, 
	// 20
	in_SHL_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u8_reg_gen_1_u8, 
	// 28
	in_SHR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u8_reg_gen_1_u8, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_SAR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u8_reg_gen_1_u8, 
	// 40
	in_ROL_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u8_reg_gen_1_u8, 
	// 48
	in_ROR_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u8_reg_gen_1_u8, 
	// 50
	in_RCL_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u8_reg_gen_1_u8, 
	// 58
	in_RCR_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u8_reg_gen_1_u8, 
	// 60
	in_SHL_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u8_reg_gen_1_u8, 
	// 68
	in_SHR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u8_reg_gen_1_u8, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_SAR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u8_reg_gen_1_u8, 
	// 80
	in_ROL_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u8_reg_gen_1_u8, 
	// 88
	in_ROR_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u8_reg_gen_1_u8, 
	// 90
	in_RCL_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u8_reg_gen_1_u8, 
	// 98
	in_RCR_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u8_reg_gen_1_u8, 
	// A0
	in_SHL_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u8_reg_gen_1_u8, 
	// A8
	in_SHR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u8_reg_gen_1_u8, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_SAR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u8_reg_gen_1_u8, 
	// C0
	in_ROL_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u8_reg_gen_1_u8, 
	// C8
	in_ROR_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u8_reg_gen_1_u8, 
	// D0
	in_RCL_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u8_reg_gen_1_u8, 
	// D8
	in_RCR_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u8_reg_gen_1_u8, 
	// E0
	in_SHL_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u8_reg_gen_1_u8, 
	// E8
	in_SHR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u8_reg_gen_1_u8, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_SAR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u8_reg_gen_1_u8, 
};
const OpState CpuRunnerX86::table_st_d_d_D2[] = {
	// 00
	in_ROL_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u8_reg_gen_1_u8, 
	// 08
	in_ROR_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u8_reg_gen_1_u8, 
	// 10
	in_RCL_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u8_reg_gen_1_u8, 
	// 18
	in_RCR_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u8_reg_gen_1_u8, 
	// 20
	in_SHL_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u8_reg_gen_1_u8, 
	// 28
	in_SHR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u8_reg_gen_1_u8, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_SAR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u8_reg_gen_1_u8, 
	// 40
	in_ROL_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u8_reg_gen_1_u8, 
	// 48
	in_ROR_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u8_reg_gen_1_u8, 
	// 50
	in_RCL_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u8_reg_gen_1_u8, 
	// 58
	in_RCR_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u8_reg_gen_1_u8, 
	// 60
	in_SHL_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u8_reg_gen_1_u8, 
	// 68
	in_SHR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u8_reg_gen_1_u8, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_SAR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u8_reg_gen_1_u8, 
	// 80
	in_ROL_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u8_reg_gen_1_u8, 
	// 88
	in_ROR_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u8_reg_gen_1_u8, 
	// 90
	in_RCL_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u8_reg_gen_1_u8, 
	// 98
	in_RCR_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u8_reg_gen_1_u8, 
	// A0
	in_SHL_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u8_reg_gen_1_u8, 
	// A8
	in_SHR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u8_reg_gen_1_u8, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_SAR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u8_reg_gen_1_u8, 
	// C0
	in_ROL_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u8_reg_gen_1_u8, 
	// C8
	in_ROR_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u8_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u8_reg_gen_1_u8, 
	// D0
	in_RCL_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u8_reg_gen_1_u8, 
	// D8
	in_RCR_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u8_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u8_reg_gen_1_u8, 
	// E0
	in_SHL_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u8_reg_gen_1_u8, 
	// E8
	in_SHR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u8_reg_gen_1_u8, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_SAR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u8_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u8_reg_gen_1_u8, 
};
const OpState CpuRunnerX86::table_st_w_w_D3[] = {
	// 00
	in_ROL_w_rm_mod_reg_u16_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u16_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u16_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u16_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u16_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u16_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u16_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u16_reg_gen_1_u8, 
	// 08
	in_ROR_w_rm_mod_reg_u16_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u16_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u16_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u16_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u16_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u16_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u16_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u16_reg_gen_1_u8, 
	// 10
	in_RCL_w_rm_mod_reg_u16_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u16_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u16_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u16_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u16_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u16_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u16_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u16_reg_gen_1_u8, 
	// 18
	in_RCR_w_rm_mod_reg_u16_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u16_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u16_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u16_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u16_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u16_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u16_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u16_reg_gen_1_u8, 
	// 20
	in_SHL_w_rm_mod_reg_u16_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u16_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u16_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u16_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u16_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u16_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u16_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u16_reg_gen_1_u8, 
	// 28
	in_SHR_w_rm_mod_reg_u16_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u16_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u16_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u16_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u16_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u16_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u16_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u16_reg_gen_1_u8, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_SAR_w_rm_mod_reg_u16_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u16_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u16_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u16_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u16_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u16_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u16_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u16_reg_gen_1_u8, 
	// 40
	in_ROL_w_rm_mod_reg_u16_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u16_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u16_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u16_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u16_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u16_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u16_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u16_reg_gen_1_u8, 
	// 48
	in_ROR_w_rm_mod_reg_u16_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u16_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u16_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u16_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u16_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u16_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u16_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u16_reg_gen_1_u8, 
	// 50
	in_RCL_w_rm_mod_reg_u16_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u16_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u16_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u16_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u16_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u16_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u16_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u16_reg_gen_1_u8, 
	// 58
	in_RCR_w_rm_mod_reg_u16_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u16_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u16_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u16_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u16_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u16_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u16_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u16_reg_gen_1_u8, 
	// 60
	in_SHL_w_rm_mod_reg_u16_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u16_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u16_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u16_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u16_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u16_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u16_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u16_reg_gen_1_u8, 
	// 68
	in_SHR_w_rm_mod_reg_u16_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u16_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u16_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u16_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u16_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u16_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u16_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u16_reg_gen_1_u8, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_SAR_w_rm_mod_reg_u16_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u16_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u16_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u16_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u16_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u16_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u16_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u16_reg_gen_1_u8, 
	// 80
	in_ROL_w_rm_mod_reg_u16_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u16_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u16_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u16_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u16_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u16_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u16_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u16_reg_gen_1_u8, 
	// 88
	in_ROR_w_rm_mod_reg_u16_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u16_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u16_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u16_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u16_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u16_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u16_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u16_reg_gen_1_u8, 
	// 90
	in_RCL_w_rm_mod_reg_u16_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u16_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u16_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u16_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u16_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u16_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u16_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u16_reg_gen_1_u8, 
	// 98
	in_RCR_w_rm_mod_reg_u16_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u16_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u16_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u16_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u16_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u16_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u16_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u16_reg_gen_1_u8, 
	// A0
	in_SHL_w_rm_mod_reg_u16_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u16_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u16_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u16_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u16_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u16_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u16_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u16_reg_gen_1_u8, 
	// A8
	in_SHR_w_rm_mod_reg_u16_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u16_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u16_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u16_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u16_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u16_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u16_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u16_reg_gen_1_u8, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_SAR_w_rm_mod_reg_u16_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u16_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u16_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u16_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u16_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u16_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u16_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u16_reg_gen_1_u8, 
	// C0
	in_ROL_w_rm_mod_reg_u16_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u16_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u16_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u16_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u16_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u16_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u16_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u16_reg_gen_1_u8, 
	// C8
	in_ROR_w_rm_mod_reg_u16_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u16_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u16_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u16_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u16_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u16_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u16_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u16_reg_gen_1_u8, 
	// D0
	in_RCL_w_rm_mod_reg_u16_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u16_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u16_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u16_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u16_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u16_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u16_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u16_reg_gen_1_u8, 
	// D8
	in_RCR_w_rm_mod_reg_u16_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u16_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u16_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u16_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u16_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u16_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u16_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u16_reg_gen_1_u8, 
	// E0
	in_SHL_w_rm_mod_reg_u16_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u16_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u16_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u16_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u16_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u16_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u16_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u16_reg_gen_1_u8, 
	// E8
	in_SHR_w_rm_mod_reg_u16_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u16_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u16_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u16_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u16_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u16_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u16_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u16_reg_gen_1_u8, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_SAR_w_rm_mod_reg_u16_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u16_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u16_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u16_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u16_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u16_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u16_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u16_reg_gen_1_u8, 
};
const OpState CpuRunnerX86::table_st_w_d_D3[] = {
	// 00
	in_ROL_w_rm_mod_reg_u32_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u32_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u32_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u32_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u32_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u32_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u32_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u32_reg_gen_1_u8, 
	// 08
	in_ROR_w_rm_mod_reg_u32_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u32_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u32_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u32_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u32_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u32_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u32_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u32_reg_gen_1_u8, 
	// 10
	in_RCL_w_rm_mod_reg_u32_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u32_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u32_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u32_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u32_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u32_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u32_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u32_reg_gen_1_u8, 
	// 18
	in_RCR_w_rm_mod_reg_u32_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u32_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u32_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u32_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u32_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u32_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u32_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u32_reg_gen_1_u8, 
	// 20
	in_SHL_w_rm_mod_reg_u32_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u32_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u32_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u32_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u32_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u32_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u32_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u32_reg_gen_1_u8, 
	// 28
	in_SHR_w_rm_mod_reg_u32_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u32_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u32_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u32_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u32_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u32_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u32_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u32_reg_gen_1_u8, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_SAR_w_rm_mod_reg_u32_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u32_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u32_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u32_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u32_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u32_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u32_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u32_reg_gen_1_u8, 
	// 40
	in_ROL_w_rm_mod_reg_u32_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u32_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u32_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u32_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u32_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u32_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u32_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u32_reg_gen_1_u8, 
	// 48
	in_ROR_w_rm_mod_reg_u32_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u32_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u32_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u32_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u32_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u32_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u32_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u32_reg_gen_1_u8, 
	// 50
	in_RCL_w_rm_mod_reg_u32_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u32_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u32_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u32_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u32_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u32_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u32_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u32_reg_gen_1_u8, 
	// 58
	in_RCR_w_rm_mod_reg_u32_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u32_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u32_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u32_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u32_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u32_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u32_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u32_reg_gen_1_u8, 
	// 60
	in_SHL_w_rm_mod_reg_u32_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u32_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u32_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u32_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u32_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u32_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u32_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u32_reg_gen_1_u8, 
	// 68
	in_SHR_w_rm_mod_reg_u32_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u32_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u32_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u32_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u32_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u32_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u32_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u32_reg_gen_1_u8, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_SAR_w_rm_mod_reg_u32_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u32_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u32_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u32_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u32_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u32_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u32_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u32_reg_gen_1_u8, 
	// 80
	in_ROL_w_rm_mod_reg_u32_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u32_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u32_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u32_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u32_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u32_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u32_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u32_reg_gen_1_u8, 
	// 88
	in_ROR_w_rm_mod_reg_u32_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u32_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u32_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u32_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u32_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u32_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u32_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u32_reg_gen_1_u8, 
	// 90
	in_RCL_w_rm_mod_reg_u32_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u32_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u32_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u32_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u32_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u32_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u32_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u32_reg_gen_1_u8, 
	// 98
	in_RCR_w_rm_mod_reg_u32_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u32_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u32_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u32_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u32_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u32_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u32_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u32_reg_gen_1_u8, 
	// A0
	in_SHL_w_rm_mod_reg_u32_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u32_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u32_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u32_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u32_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u32_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u32_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u32_reg_gen_1_u8, 
	// A8
	in_SHR_w_rm_mod_reg_u32_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u32_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u32_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u32_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u32_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u32_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u32_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u32_reg_gen_1_u8, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_SAR_w_rm_mod_reg_u32_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u32_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u32_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u32_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u32_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u32_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u32_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u32_reg_gen_1_u8, 
	// C0
	in_ROL_w_rm_mod_reg_u32_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u32_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u32_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u32_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u32_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u32_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u32_reg_gen_1_u8, in_ROL_w_rm_mod_reg_u32_reg_gen_1_u8, 
	// C8
	in_ROR_w_rm_mod_reg_u32_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u32_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u32_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u32_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u32_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u32_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u32_reg_gen_1_u8, in_ROR_w_rm_mod_reg_u32_reg_gen_1_u8, 
	// D0
	in_RCL_w_rm_mod_reg_u32_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u32_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u32_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u32_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u32_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u32_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u32_reg_gen_1_u8, in_RCL_w_rm_mod_reg_u32_reg_gen_1_u8, 
	// D8
	in_RCR_w_rm_mod_reg_u32_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u32_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u32_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u32_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u32_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u32_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u32_reg_gen_1_u8, in_RCR_w_rm_mod_reg_u32_reg_gen_1_u8, 
	// E0
	in_SHL_w_rm_mod_reg_u32_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u32_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u32_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u32_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u32_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u32_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u32_reg_gen_1_u8, in_SHL_w_rm_mod_reg_u32_reg_gen_1_u8, 
	// E8
	in_SHR_w_rm_mod_reg_u32_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u32_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u32_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u32_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u32_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u32_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u32_reg_gen_1_u8, in_SHR_w_rm_mod_reg_u32_reg_gen_1_u8, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_SAR_w_rm_mod_reg_u32_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u32_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u32_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u32_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u32_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u32_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u32_reg_gen_1_u8, in_SAR_w_rm_mod_reg_u32_reg_gen_1_u8, 
};
const OpState CpuRunnerX86::table_st_d_w_D3[] = {
	// 00
	in_ROL_d_rm_mod_reg_u16_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u16_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u16_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u16_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u16_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u16_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u16_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u16_reg_gen_1_u8, 
	// 08
	in_ROR_d_rm_mod_reg_u16_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u16_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u16_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u16_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u16_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u16_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u16_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u16_reg_gen_1_u8, 
	// 10
	in_RCL_d_rm_mod_reg_u16_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u16_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u16_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u16_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u16_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u16_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u16_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u16_reg_gen_1_u8, 
	// 18
	in_RCR_d_rm_mod_reg_u16_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u16_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u16_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u16_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u16_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u16_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u16_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u16_reg_gen_1_u8, 
	// 20
	in_SHL_d_rm_mod_reg_u16_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u16_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u16_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u16_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u16_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u16_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u16_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u16_reg_gen_1_u8, 
	// 28
	in_SHR_d_rm_mod_reg_u16_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u16_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u16_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u16_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u16_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u16_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u16_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u16_reg_gen_1_u8, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_SAR_d_rm_mod_reg_u16_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u16_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u16_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u16_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u16_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u16_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u16_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u16_reg_gen_1_u8, 
	// 40
	in_ROL_d_rm_mod_reg_u16_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u16_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u16_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u16_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u16_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u16_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u16_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u16_reg_gen_1_u8, 
	// 48
	in_ROR_d_rm_mod_reg_u16_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u16_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u16_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u16_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u16_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u16_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u16_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u16_reg_gen_1_u8, 
	// 50
	in_RCL_d_rm_mod_reg_u16_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u16_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u16_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u16_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u16_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u16_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u16_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u16_reg_gen_1_u8, 
	// 58
	in_RCR_d_rm_mod_reg_u16_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u16_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u16_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u16_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u16_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u16_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u16_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u16_reg_gen_1_u8, 
	// 60
	in_SHL_d_rm_mod_reg_u16_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u16_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u16_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u16_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u16_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u16_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u16_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u16_reg_gen_1_u8, 
	// 68
	in_SHR_d_rm_mod_reg_u16_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u16_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u16_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u16_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u16_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u16_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u16_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u16_reg_gen_1_u8, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_SAR_d_rm_mod_reg_u16_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u16_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u16_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u16_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u16_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u16_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u16_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u16_reg_gen_1_u8, 
	// 80
	in_ROL_d_rm_mod_reg_u16_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u16_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u16_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u16_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u16_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u16_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u16_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u16_reg_gen_1_u8, 
	// 88
	in_ROR_d_rm_mod_reg_u16_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u16_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u16_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u16_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u16_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u16_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u16_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u16_reg_gen_1_u8, 
	// 90
	in_RCL_d_rm_mod_reg_u16_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u16_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u16_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u16_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u16_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u16_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u16_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u16_reg_gen_1_u8, 
	// 98
	in_RCR_d_rm_mod_reg_u16_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u16_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u16_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u16_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u16_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u16_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u16_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u16_reg_gen_1_u8, 
	// A0
	in_SHL_d_rm_mod_reg_u16_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u16_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u16_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u16_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u16_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u16_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u16_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u16_reg_gen_1_u8, 
	// A8
	in_SHR_d_rm_mod_reg_u16_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u16_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u16_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u16_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u16_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u16_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u16_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u16_reg_gen_1_u8, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_SAR_d_rm_mod_reg_u16_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u16_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u16_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u16_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u16_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u16_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u16_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u16_reg_gen_1_u8, 
	// C0
	in_ROL_d_rm_mod_reg_u16_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u16_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u16_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u16_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u16_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u16_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u16_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u16_reg_gen_1_u8, 
	// C8
	in_ROR_d_rm_mod_reg_u16_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u16_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u16_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u16_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u16_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u16_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u16_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u16_reg_gen_1_u8, 
	// D0
	in_RCL_d_rm_mod_reg_u16_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u16_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u16_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u16_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u16_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u16_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u16_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u16_reg_gen_1_u8, 
	// D8
	in_RCR_d_rm_mod_reg_u16_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u16_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u16_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u16_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u16_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u16_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u16_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u16_reg_gen_1_u8, 
	// E0
	in_SHL_d_rm_mod_reg_u16_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u16_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u16_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u16_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u16_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u16_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u16_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u16_reg_gen_1_u8, 
	// E8
	in_SHR_d_rm_mod_reg_u16_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u16_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u16_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u16_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u16_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u16_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u16_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u16_reg_gen_1_u8, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_SAR_d_rm_mod_reg_u16_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u16_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u16_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u16_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u16_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u16_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u16_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u16_reg_gen_1_u8, 
};
const OpState CpuRunnerX86::table_st_d_d_D3[] = {
	// 00
	in_ROL_d_rm_mod_reg_u32_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u32_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u32_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u32_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u32_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u32_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u32_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u32_reg_gen_1_u8, 
	// 08
	in_ROR_d_rm_mod_reg_u32_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u32_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u32_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u32_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u32_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u32_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u32_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u32_reg_gen_1_u8, 
	// 10
	in_RCL_d_rm_mod_reg_u32_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u32_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u32_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u32_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u32_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u32_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u32_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u32_reg_gen_1_u8, 
	// 18
	in_RCR_d_rm_mod_reg_u32_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u32_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u32_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u32_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u32_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u32_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u32_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u32_reg_gen_1_u8, 
	// 20
	in_SHL_d_rm_mod_reg_u32_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u32_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u32_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u32_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u32_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u32_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u32_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u32_reg_gen_1_u8, 
	// 28
	in_SHR_d_rm_mod_reg_u32_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u32_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u32_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u32_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u32_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u32_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u32_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u32_reg_gen_1_u8, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_SAR_d_rm_mod_reg_u32_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u32_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u32_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u32_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u32_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u32_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u32_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u32_reg_gen_1_u8, 
	// 40
	in_ROL_d_rm_mod_reg_u32_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u32_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u32_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u32_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u32_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u32_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u32_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u32_reg_gen_1_u8, 
	// 48
	in_ROR_d_rm_mod_reg_u32_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u32_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u32_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u32_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u32_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u32_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u32_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u32_reg_gen_1_u8, 
	// 50
	in_RCL_d_rm_mod_reg_u32_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u32_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u32_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u32_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u32_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u32_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u32_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u32_reg_gen_1_u8, 
	// 58
	in_RCR_d_rm_mod_reg_u32_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u32_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u32_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u32_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u32_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u32_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u32_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u32_reg_gen_1_u8, 
	// 60
	in_SHL_d_rm_mod_reg_u32_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u32_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u32_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u32_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u32_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u32_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u32_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u32_reg_gen_1_u8, 
	// 68
	in_SHR_d_rm_mod_reg_u32_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u32_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u32_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u32_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u32_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u32_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u32_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u32_reg_gen_1_u8, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_SAR_d_rm_mod_reg_u32_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u32_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u32_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u32_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u32_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u32_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u32_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u32_reg_gen_1_u8, 
	// 80
	in_ROL_d_rm_mod_reg_u32_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u32_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u32_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u32_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u32_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u32_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u32_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u32_reg_gen_1_u8, 
	// 88
	in_ROR_d_rm_mod_reg_u32_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u32_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u32_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u32_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u32_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u32_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u32_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u32_reg_gen_1_u8, 
	// 90
	in_RCL_d_rm_mod_reg_u32_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u32_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u32_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u32_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u32_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u32_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u32_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u32_reg_gen_1_u8, 
	// 98
	in_RCR_d_rm_mod_reg_u32_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u32_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u32_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u32_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u32_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u32_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u32_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u32_reg_gen_1_u8, 
	// A0
	in_SHL_d_rm_mod_reg_u32_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u32_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u32_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u32_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u32_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u32_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u32_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u32_reg_gen_1_u8, 
	// A8
	in_SHR_d_rm_mod_reg_u32_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u32_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u32_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u32_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u32_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u32_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u32_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u32_reg_gen_1_u8, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_SAR_d_rm_mod_reg_u32_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u32_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u32_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u32_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u32_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u32_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u32_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u32_reg_gen_1_u8, 
	// C0
	in_ROL_d_rm_mod_reg_u32_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u32_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u32_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u32_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u32_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u32_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u32_reg_gen_1_u8, in_ROL_d_rm_mod_reg_u32_reg_gen_1_u8, 
	// C8
	in_ROR_d_rm_mod_reg_u32_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u32_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u32_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u32_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u32_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u32_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u32_reg_gen_1_u8, in_ROR_d_rm_mod_reg_u32_reg_gen_1_u8, 
	// D0
	in_RCL_d_rm_mod_reg_u32_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u32_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u32_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u32_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u32_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u32_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u32_reg_gen_1_u8, in_RCL_d_rm_mod_reg_u32_reg_gen_1_u8, 
	// D8
	in_RCR_d_rm_mod_reg_u32_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u32_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u32_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u32_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u32_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u32_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u32_reg_gen_1_u8, in_RCR_d_rm_mod_reg_u32_reg_gen_1_u8, 
	// E0
	in_SHL_d_rm_mod_reg_u32_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u32_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u32_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u32_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u32_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u32_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u32_reg_gen_1_u8, in_SHL_d_rm_mod_reg_u32_reg_gen_1_u8, 
	// E8
	in_SHR_d_rm_mod_reg_u32_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u32_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u32_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u32_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u32_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u32_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u32_reg_gen_1_u8, in_SHR_d_rm_mod_reg_u32_reg_gen_1_u8, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_SAR_d_rm_mod_reg_u32_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u32_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u32_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u32_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u32_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u32_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u32_reg_gen_1_u8, in_SAR_d_rm_mod_reg_u32_reg_gen_1_u8, 
};
const OpState CpuRunnerX86::table_st_w_w_F6[] = {
	// 00
	in_TEST_w_imm_u8, in_TEST_w_imm_u8, in_TEST_w_imm_u8, in_TEST_w_imm_u8, in_TEST_w_imm_u8, in_TEST_w_imm_u8, in_TEST_w_imm_u8, in_TEST_w_imm_u8, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_NOT_w_rm_mod_reg_u8, in_NOT_w_rm_mod_reg_u8, in_NOT_w_rm_mod_reg_u8, in_NOT_w_rm_mod_reg_u8, in_NOT_w_rm_mod_reg_u8, in_NOT_w_rm_mod_reg_u8, in_NOT_w_rm_mod_reg_u8, in_NOT_w_rm_mod_reg_u8, 
	// 18
	in_NEG_w_rm_mod_reg_u8, in_NEG_w_rm_mod_reg_u8, in_NEG_w_rm_mod_reg_u8, in_NEG_w_rm_mod_reg_u8, in_NEG_w_rm_mod_reg_u8, in_NEG_w_rm_mod_reg_u8, in_NEG_w_rm_mod_reg_u8, in_NEG_w_rm_mod_reg_u8, 
	// 20
	in_MUL_w_rm_mod_reg_u8, in_MUL_w_rm_mod_reg_u8, in_MUL_w_rm_mod_reg_u8, in_MUL_w_rm_mod_reg_u8, in_MUL_w_rm_mod_reg_u8, in_MUL_w_rm_mod_reg_u8, in_MUL_w_rm_mod_reg_u8, in_MUL_w_rm_mod_reg_u8, 
	// 28
	in_IMUL_w_rm_mod_reg_u8, in_IMUL_w_rm_mod_reg_u8, in_IMUL_w_rm_mod_reg_u8, in_IMUL_w_rm_mod_reg_u8, in_IMUL_w_rm_mod_reg_u8, in_IMUL_w_rm_mod_reg_u8, in_IMUL_w_rm_mod_reg_u8, in_IMUL_w_rm_mod_reg_u8, 
	// 30
	in_DIV_w_rm_mod_reg_u8, in_DIV_w_rm_mod_reg_u8, in_DIV_w_rm_mod_reg_u8, in_DIV_w_rm_mod_reg_u8, in_DIV_w_rm_mod_reg_u8, in_DIV_w_rm_mod_reg_u8, in_DIV_w_rm_mod_reg_u8, in_DIV_w_rm_mod_reg_u8, 
	// 38
	in_IDIV_w_rm_mod_reg_u8, in_IDIV_w_rm_mod_reg_u8, in_IDIV_w_rm_mod_reg_u8, in_IDIV_w_rm_mod_reg_u8, in_IDIV_w_rm_mod_reg_u8, in_IDIV_w_rm_mod_reg_u8, in_IDIV_w_rm_mod_reg_u8, in_IDIV_w_rm_mod_reg_u8, 
	// 40
	in_TEST_w_imm_u8, in_TEST_w_imm_u8, in_TEST_w_imm_u8, in_TEST_w_imm_u8, in_TEST_w_imm_u8, in_TEST_w_imm_u8, in_TEST_w_imm_u8, in_TEST_w_imm_u8, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_NOT_w_rm_mod_reg_u8, in_NOT_w_rm_mod_reg_u8, in_NOT_w_rm_mod_reg_u8, in_NOT_w_rm_mod_reg_u8, in_NOT_w_rm_mod_reg_u8, in_NOT_w_rm_mod_reg_u8, in_NOT_w_rm_mod_reg_u8, in_NOT_w_rm_mod_reg_u8, 
	// 58
	in_NEG_w_rm_mod_reg_u8, in_NEG_w_rm_mod_reg_u8, in_NEG_w_rm_mod_reg_u8, in_NEG_w_rm_mod_reg_u8, in_NEG_w_rm_mod_reg_u8, in_NEG_w_rm_mod_reg_u8, in_NEG_w_rm_mod_reg_u8, in_NEG_w_rm_mod_reg_u8, 
	// 60
	in_MUL_w_rm_mod_reg_u8, in_MUL_w_rm_mod_reg_u8, in_MUL_w_rm_mod_reg_u8, in_MUL_w_rm_mod_reg_u8, in_MUL_w_rm_mod_reg_u8, in_MUL_w_rm_mod_reg_u8, in_MUL_w_rm_mod_reg_u8, in_MUL_w_rm_mod_reg_u8, 
	// 68
	in_IMUL_w_rm_mod_reg_u8, in_IMUL_w_rm_mod_reg_u8, in_IMUL_w_rm_mod_reg_u8, in_IMUL_w_rm_mod_reg_u8, in_IMUL_w_rm_mod_reg_u8, in_IMUL_w_rm_mod_reg_u8, in_IMUL_w_rm_mod_reg_u8, in_IMUL_w_rm_mod_reg_u8, 
	// 70
	in_DIV_w_rm_mod_reg_u8, in_DIV_w_rm_mod_reg_u8, in_DIV_w_rm_mod_reg_u8, in_DIV_w_rm_mod_reg_u8, in_DIV_w_rm_mod_reg_u8, in_DIV_w_rm_mod_reg_u8, in_DIV_w_rm_mod_reg_u8, in_DIV_w_rm_mod_reg_u8, 
	// 78
	in_IDIV_w_rm_mod_reg_u8, in_IDIV_w_rm_mod_reg_u8, in_IDIV_w_rm_mod_reg_u8, in_IDIV_w_rm_mod_reg_u8, in_IDIV_w_rm_mod_reg_u8, in_IDIV_w_rm_mod_reg_u8, in_IDIV_w_rm_mod_reg_u8, in_IDIV_w_rm_mod_reg_u8, 
	// 80
	in_TEST_w_imm_u8, in_TEST_w_imm_u8, in_TEST_w_imm_u8, in_TEST_w_imm_u8, in_TEST_w_imm_u8, in_TEST_w_imm_u8, in_TEST_w_imm_u8, in_TEST_w_imm_u8, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_NOT_w_rm_mod_reg_u8, in_NOT_w_rm_mod_reg_u8, in_NOT_w_rm_mod_reg_u8, in_NOT_w_rm_mod_reg_u8, in_NOT_w_rm_mod_reg_u8, in_NOT_w_rm_mod_reg_u8, in_NOT_w_rm_mod_reg_u8, in_NOT_w_rm_mod_reg_u8, 
	// 98
	in_NEG_w_rm_mod_reg_u8, in_NEG_w_rm_mod_reg_u8, in_NEG_w_rm_mod_reg_u8, in_NEG_w_rm_mod_reg_u8, in_NEG_w_rm_mod_reg_u8, in_NEG_w_rm_mod_reg_u8, in_NEG_w_rm_mod_reg_u8, in_NEG_w_rm_mod_reg_u8, 
	// A0
	in_MUL_w_rm_mod_reg_u8, in_MUL_w_rm_mod_reg_u8, in_MUL_w_rm_mod_reg_u8, in_MUL_w_rm_mod_reg_u8, in_MUL_w_rm_mod_reg_u8, in_MUL_w_rm_mod_reg_u8, in_MUL_w_rm_mod_reg_u8, in_MUL_w_rm_mod_reg_u8, 
	// A8
	in_IMUL_w_rm_mod_reg_u8, in_IMUL_w_rm_mod_reg_u8, in_IMUL_w_rm_mod_reg_u8, in_IMUL_w_rm_mod_reg_u8, in_IMUL_w_rm_mod_reg_u8, in_IMUL_w_rm_mod_reg_u8, in_IMUL_w_rm_mod_reg_u8, in_IMUL_w_rm_mod_reg_u8, 
	// B0
	in_DIV_w_rm_mod_reg_u8, in_DIV_w_rm_mod_reg_u8, in_DIV_w_rm_mod_reg_u8, in_DIV_w_rm_mod_reg_u8, in_DIV_w_rm_mod_reg_u8, in_DIV_w_rm_mod_reg_u8, in_DIV_w_rm_mod_reg_u8, in_DIV_w_rm_mod_reg_u8, 
	// B8
	in_IDIV_w_rm_mod_reg_u8, in_IDIV_w_rm_mod_reg_u8, in_IDIV_w_rm_mod_reg_u8, in_IDIV_w_rm_mod_reg_u8, in_IDIV_w_rm_mod_reg_u8, in_IDIV_w_rm_mod_reg_u8, in_IDIV_w_rm_mod_reg_u8, in_IDIV_w_rm_mod_reg_u8, 
	// C0
	in_TEST_w_imm_u8, in_TEST_w_imm_u8, in_TEST_w_imm_u8, in_TEST_w_imm_u8, in_TEST_w_imm_u8, in_TEST_w_imm_u8, in_TEST_w_imm_u8, in_TEST_w_imm_u8, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_NOT_w_rm_mod_reg_u8, in_NOT_w_rm_mod_reg_u8, in_NOT_w_rm_mod_reg_u8, in_NOT_w_rm_mod_reg_u8, in_NOT_w_rm_mod_reg_u8, in_NOT_w_rm_mod_reg_u8, in_NOT_w_rm_mod_reg_u8, in_NOT_w_rm_mod_reg_u8, 
	// D8
	in_NEG_w_rm_mod_reg_u8, in_NEG_w_rm_mod_reg_u8, in_NEG_w_rm_mod_reg_u8, in_NEG_w_rm_mod_reg_u8, in_NEG_w_rm_mod_reg_u8, in_NEG_w_rm_mod_reg_u8, in_NEG_w_rm_mod_reg_u8, in_NEG_w_rm_mod_reg_u8, 
	// E0
	in_MUL_w_rm_mod_reg_u8, in_MUL_w_rm_mod_reg_u8, in_MUL_w_rm_mod_reg_u8, in_MUL_w_rm_mod_reg_u8, in_MUL_w_rm_mod_reg_u8, in_MUL_w_rm_mod_reg_u8, in_MUL_w_rm_mod_reg_u8, in_MUL_w_rm_mod_reg_u8, 
	// E8
	in_IMUL_w_rm_mod_reg_u8, in_IMUL_w_rm_mod_reg_u8, in_IMUL_w_rm_mod_reg_u8, in_IMUL_w_rm_mod_reg_u8, in_IMUL_w_rm_mod_reg_u8, in_IMUL_w_rm_mod_reg_u8, in_IMUL_w_rm_mod_reg_u8, in_IMUL_w_rm_mod_reg_u8, 
	// F0
	in_DIV_w_rm_mod_reg_u8, in_DIV_w_rm_mod_reg_u8, in_DIV_w_rm_mod_reg_u8, in_DIV_w_rm_mod_reg_u8, in_DIV_w_rm_mod_reg_u8, in_DIV_w_rm_mod_reg_u8, in_DIV_w_rm_mod_reg_u8, in_DIV_w_rm_mod_reg_u8, 
	// F8
	in_IDIV_w_rm_mod_reg_u8, in_IDIV_w_rm_mod_reg_u8, in_IDIV_w_rm_mod_reg_u8, in_IDIV_w_rm_mod_reg_u8, in_IDIV_w_rm_mod_reg_u8, in_IDIV_w_rm_mod_reg_u8, in_IDIV_w_rm_mod_reg_u8, in_IDIV_w_rm_mod_reg_u8, 
};
const OpState CpuRunnerX86::table_st_w_d_F6[] = {
	// 00
	in_TEST_w_imm_u8, in_TEST_w_imm_u8, in_TEST_w_imm_u8, in_TEST_w_imm_u8, in_TEST_w_imm_u8, in_TEST_w_imm_u8, in_TEST_w_imm_u8, in_TEST_w_imm_u8, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_NOT_w_rm_mod_reg_u8, in_NOT_w_rm_mod_reg_u8, in_NOT_w_rm_mod_reg_u8, in_NOT_w_rm_mod_reg_u8, in_NOT_w_rm_mod_reg_u8, in_NOT_w_rm_mod_reg_u8, in_NOT_w_rm_mod_reg_u8, in_NOT_w_rm_mod_reg_u8, 
	// 18
	in_NEG_w_rm_mod_reg_u8, in_NEG_w_rm_mod_reg_u8, in_NEG_w_rm_mod_reg_u8, in_NEG_w_rm_mod_reg_u8, in_NEG_w_rm_mod_reg_u8, in_NEG_w_rm_mod_reg_u8, in_NEG_w_rm_mod_reg_u8, in_NEG_w_rm_mod_reg_u8, 
	// 20
	in_MUL_w_rm_mod_reg_u8, in_MUL_w_rm_mod_reg_u8, in_MUL_w_rm_mod_reg_u8, in_MUL_w_rm_mod_reg_u8, in_MUL_w_rm_mod_reg_u8, in_MUL_w_rm_mod_reg_u8, in_MUL_w_rm_mod_reg_u8, in_MUL_w_rm_mod_reg_u8, 
	// 28
	in_IMUL_w_rm_mod_reg_u8, in_IMUL_w_rm_mod_reg_u8, in_IMUL_w_rm_mod_reg_u8, in_IMUL_w_rm_mod_reg_u8, in_IMUL_w_rm_mod_reg_u8, in_IMUL_w_rm_mod_reg_u8, in_IMUL_w_rm_mod_reg_u8, in_IMUL_w_rm_mod_reg_u8, 
	// 30
	in_DIV_w_rm_mod_reg_u8, in_DIV_w_rm_mod_reg_u8, in_DIV_w_rm_mod_reg_u8, in_DIV_w_rm_mod_reg_u8, in_DIV_w_rm_mod_reg_u8, in_DIV_w_rm_mod_reg_u8, in_DIV_w_rm_mod_reg_u8, in_DIV_w_rm_mod_reg_u8, 
	// 38
	in_IDIV_w_rm_mod_reg_u8, in_IDIV_w_rm_mod_reg_u8, in_IDIV_w_rm_mod_reg_u8, in_IDIV_w_rm_mod_reg_u8, in_IDIV_w_rm_mod_reg_u8, in_IDIV_w_rm_mod_reg_u8, in_IDIV_w_rm_mod_reg_u8, in_IDIV_w_rm_mod_reg_u8, 
	// 40
	in_TEST_w_imm_u8, in_TEST_w_imm_u8, in_TEST_w_imm_u8, in_TEST_w_imm_u8, in_TEST_w_imm_u8, in_TEST_w_imm_u8, in_TEST_w_imm_u8, in_TEST_w_imm_u8, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_NOT_w_rm_mod_reg_u8, in_NOT_w_rm_mod_reg_u8, in_NOT_w_rm_mod_reg_u8, in_NOT_w_rm_mod_reg_u8, in_NOT_w_rm_mod_reg_u8, in_NOT_w_rm_mod_reg_u8, in_NOT_w_rm_mod_reg_u8, in_NOT_w_rm_mod_reg_u8, 
	// 58
	in_NEG_w_rm_mod_reg_u8, in_NEG_w_rm_mod_reg_u8, in_NEG_w_rm_mod_reg_u8, in_NEG_w_rm_mod_reg_u8, in_NEG_w_rm_mod_reg_u8, in_NEG_w_rm_mod_reg_u8, in_NEG_w_rm_mod_reg_u8, in_NEG_w_rm_mod_reg_u8, 
	// 60
	in_MUL_w_rm_mod_reg_u8, in_MUL_w_rm_mod_reg_u8, in_MUL_w_rm_mod_reg_u8, in_MUL_w_rm_mod_reg_u8, in_MUL_w_rm_mod_reg_u8, in_MUL_w_rm_mod_reg_u8, in_MUL_w_rm_mod_reg_u8, in_MUL_w_rm_mod_reg_u8, 
	// 68
	in_IMUL_w_rm_mod_reg_u8, in_IMUL_w_rm_mod_reg_u8, in_IMUL_w_rm_mod_reg_u8, in_IMUL_w_rm_mod_reg_u8, in_IMUL_w_rm_mod_reg_u8, in_IMUL_w_rm_mod_reg_u8, in_IMUL_w_rm_mod_reg_u8, in_IMUL_w_rm_mod_reg_u8, 
	// 70
	in_DIV_w_rm_mod_reg_u8, in_DIV_w_rm_mod_reg_u8, in_DIV_w_rm_mod_reg_u8, in_DIV_w_rm_mod_reg_u8, in_DIV_w_rm_mod_reg_u8, in_DIV_w_rm_mod_reg_u8, in_DIV_w_rm_mod_reg_u8, in_DIV_w_rm_mod_reg_u8, 
	// 78
	in_IDIV_w_rm_mod_reg_u8, in_IDIV_w_rm_mod_reg_u8, in_IDIV_w_rm_mod_reg_u8, in_IDIV_w_rm_mod_reg_u8, in_IDIV_w_rm_mod_reg_u8, in_IDIV_w_rm_mod_reg_u8, in_IDIV_w_rm_mod_reg_u8, in_IDIV_w_rm_mod_reg_u8, 
	// 80
	in_TEST_w_imm_u8, in_TEST_w_imm_u8, in_TEST_w_imm_u8, in_TEST_w_imm_u8, in_TEST_w_imm_u8, in_TEST_w_imm_u8, in_TEST_w_imm_u8, in_TEST_w_imm_u8, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_NOT_w_rm_mod_reg_u8, in_NOT_w_rm_mod_reg_u8, in_NOT_w_rm_mod_reg_u8, in_NOT_w_rm_mod_reg_u8, in_NOT_w_rm_mod_reg_u8, in_NOT_w_rm_mod_reg_u8, in_NOT_w_rm_mod_reg_u8, in_NOT_w_rm_mod_reg_u8, 
	// 98
	in_NEG_w_rm_mod_reg_u8, in_NEG_w_rm_mod_reg_u8, in_NEG_w_rm_mod_reg_u8, in_NEG_w_rm_mod_reg_u8, in_NEG_w_rm_mod_reg_u8, in_NEG_w_rm_mod_reg_u8, in_NEG_w_rm_mod_reg_u8, in_NEG_w_rm_mod_reg_u8, 
	// A0
	in_MUL_w_rm_mod_reg_u8, in_MUL_w_rm_mod_reg_u8, in_MUL_w_rm_mod_reg_u8, in_MUL_w_rm_mod_reg_u8, in_MUL_w_rm_mod_reg_u8, in_MUL_w_rm_mod_reg_u8, in_MUL_w_rm_mod_reg_u8, in_MUL_w_rm_mod_reg_u8, 
	// A8
	in_IMUL_w_rm_mod_reg_u8, in_IMUL_w_rm_mod_reg_u8, in_IMUL_w_rm_mod_reg_u8, in_IMUL_w_rm_mod_reg_u8, in_IMUL_w_rm_mod_reg_u8, in_IMUL_w_rm_mod_reg_u8, in_IMUL_w_rm_mod_reg_u8, in_IMUL_w_rm_mod_reg_u8, 
	// B0
	in_DIV_w_rm_mod_reg_u8, in_DIV_w_rm_mod_reg_u8, in_DIV_w_rm_mod_reg_u8, in_DIV_w_rm_mod_reg_u8, in_DIV_w_rm_mod_reg_u8, in_DIV_w_rm_mod_reg_u8, in_DIV_w_rm_mod_reg_u8, in_DIV_w_rm_mod_reg_u8, 
	// B8
	in_IDIV_w_rm_mod_reg_u8, in_IDIV_w_rm_mod_reg_u8, in_IDIV_w_rm_mod_reg_u8, in_IDIV_w_rm_mod_reg_u8, in_IDIV_w_rm_mod_reg_u8, in_IDIV_w_rm_mod_reg_u8, in_IDIV_w_rm_mod_reg_u8, in_IDIV_w_rm_mod_reg_u8, 
	// C0
	in_TEST_w_imm_u8, in_TEST_w_imm_u8, in_TEST_w_imm_u8, in_TEST_w_imm_u8, in_TEST_w_imm_u8, in_TEST_w_imm_u8, in_TEST_w_imm_u8, in_TEST_w_imm_u8, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_NOT_w_rm_mod_reg_u8, in_NOT_w_rm_mod_reg_u8, in_NOT_w_rm_mod_reg_u8, in_NOT_w_rm_mod_reg_u8, in_NOT_w_rm_mod_reg_u8, in_NOT_w_rm_mod_reg_u8, in_NOT_w_rm_mod_reg_u8, in_NOT_w_rm_mod_reg_u8, 
	// D8
	in_NEG_w_rm_mod_reg_u8, in_NEG_w_rm_mod_reg_u8, in_NEG_w_rm_mod_reg_u8, in_NEG_w_rm_mod_reg_u8, in_NEG_w_rm_mod_reg_u8, in_NEG_w_rm_mod_reg_u8, in_NEG_w_rm_mod_reg_u8, in_NEG_w_rm_mod_reg_u8, 
	// E0
	in_MUL_w_rm_mod_reg_u8, in_MUL_w_rm_mod_reg_u8, in_MUL_w_rm_mod_reg_u8, in_MUL_w_rm_mod_reg_u8, in_MUL_w_rm_mod_reg_u8, in_MUL_w_rm_mod_reg_u8, in_MUL_w_rm_mod_reg_u8, in_MUL_w_rm_mod_reg_u8, 
	// E8
	in_IMUL_w_rm_mod_reg_u8, in_IMUL_w_rm_mod_reg_u8, in_IMUL_w_rm_mod_reg_u8, in_IMUL_w_rm_mod_reg_u8, in_IMUL_w_rm_mod_reg_u8, in_IMUL_w_rm_mod_reg_u8, in_IMUL_w_rm_mod_reg_u8, in_IMUL_w_rm_mod_reg_u8, 
	// F0
	in_DIV_w_rm_mod_reg_u8, in_DIV_w_rm_mod_reg_u8, in_DIV_w_rm_mod_reg_u8, in_DIV_w_rm_mod_reg_u8, in_DIV_w_rm_mod_reg_u8, in_DIV_w_rm_mod_reg_u8, in_DIV_w_rm_mod_reg_u8, in_DIV_w_rm_mod_reg_u8, 
	// F8
	in_IDIV_w_rm_mod_reg_u8, in_IDIV_w_rm_mod_reg_u8, in_IDIV_w_rm_mod_reg_u8, in_IDIV_w_rm_mod_reg_u8, in_IDIV_w_rm_mod_reg_u8, in_IDIV_w_rm_mod_reg_u8, in_IDIV_w_rm_mod_reg_u8, in_IDIV_w_rm_mod_reg_u8, 
};
const OpState CpuRunnerX86::table_st_d_w_F6[] = {
	// 00
	in_TEST_d_imm_u8, in_TEST_d_imm_u8, in_TEST_d_imm_u8, in_TEST_d_imm_u8, in_TEST_d_imm_u8, in_TEST_d_imm_u8, in_TEST_d_imm_u8, in_TEST_d_imm_u8, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_NOT_d_rm_mod_reg_u8, in_NOT_d_rm_mod_reg_u8, in_NOT_d_rm_mod_reg_u8, in_NOT_d_rm_mod_reg_u8, in_NOT_d_rm_mod_reg_u8, in_NOT_d_rm_mod_reg_u8, in_NOT_d_rm_mod_reg_u8, in_NOT_d_rm_mod_reg_u8, 
	// 18
	in_NEG_d_rm_mod_reg_u8, in_NEG_d_rm_mod_reg_u8, in_NEG_d_rm_mod_reg_u8, in_NEG_d_rm_mod_reg_u8, in_NEG_d_rm_mod_reg_u8, in_NEG_d_rm_mod_reg_u8, in_NEG_d_rm_mod_reg_u8, in_NEG_d_rm_mod_reg_u8, 
	// 20
	in_MUL_d_rm_mod_reg_u8, in_MUL_d_rm_mod_reg_u8, in_MUL_d_rm_mod_reg_u8, in_MUL_d_rm_mod_reg_u8, in_MUL_d_rm_mod_reg_u8, in_MUL_d_rm_mod_reg_u8, in_MUL_d_rm_mod_reg_u8, in_MUL_d_rm_mod_reg_u8, 
	// 28
	in_IMUL_d_rm_mod_reg_u8, in_IMUL_d_rm_mod_reg_u8, in_IMUL_d_rm_mod_reg_u8, in_IMUL_d_rm_mod_reg_u8, in_IMUL_d_rm_mod_reg_u8, in_IMUL_d_rm_mod_reg_u8, in_IMUL_d_rm_mod_reg_u8, in_IMUL_d_rm_mod_reg_u8, 
	// 30
	in_DIV_d_rm_mod_reg_u8, in_DIV_d_rm_mod_reg_u8, in_DIV_d_rm_mod_reg_u8, in_DIV_d_rm_mod_reg_u8, in_DIV_d_rm_mod_reg_u8, in_DIV_d_rm_mod_reg_u8, in_DIV_d_rm_mod_reg_u8, in_DIV_d_rm_mod_reg_u8, 
	// 38
	in_IDIV_d_rm_mod_reg_u8, in_IDIV_d_rm_mod_reg_u8, in_IDIV_d_rm_mod_reg_u8, in_IDIV_d_rm_mod_reg_u8, in_IDIV_d_rm_mod_reg_u8, in_IDIV_d_rm_mod_reg_u8, in_IDIV_d_rm_mod_reg_u8, in_IDIV_d_rm_mod_reg_u8, 
	// 40
	in_TEST_d_imm_u8, in_TEST_d_imm_u8, in_TEST_d_imm_u8, in_TEST_d_imm_u8, in_TEST_d_imm_u8, in_TEST_d_imm_u8, in_TEST_d_imm_u8, in_TEST_d_imm_u8, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_NOT_d_rm_mod_reg_u8, in_NOT_d_rm_mod_reg_u8, in_NOT_d_rm_mod_reg_u8, in_NOT_d_rm_mod_reg_u8, in_NOT_d_rm_mod_reg_u8, in_NOT_d_rm_mod_reg_u8, in_NOT_d_rm_mod_reg_u8, in_NOT_d_rm_mod_reg_u8, 
	// 58
	in_NEG_d_rm_mod_reg_u8, in_NEG_d_rm_mod_reg_u8, in_NEG_d_rm_mod_reg_u8, in_NEG_d_rm_mod_reg_u8, in_NEG_d_rm_mod_reg_u8, in_NEG_d_rm_mod_reg_u8, in_NEG_d_rm_mod_reg_u8, in_NEG_d_rm_mod_reg_u8, 
	// 60
	in_MUL_d_rm_mod_reg_u8, in_MUL_d_rm_mod_reg_u8, in_MUL_d_rm_mod_reg_u8, in_MUL_d_rm_mod_reg_u8, in_MUL_d_rm_mod_reg_u8, in_MUL_d_rm_mod_reg_u8, in_MUL_d_rm_mod_reg_u8, in_MUL_d_rm_mod_reg_u8, 
	// 68
	in_IMUL_d_rm_mod_reg_u8, in_IMUL_d_rm_mod_reg_u8, in_IMUL_d_rm_mod_reg_u8, in_IMUL_d_rm_mod_reg_u8, in_IMUL_d_rm_mod_reg_u8, in_IMUL_d_rm_mod_reg_u8, in_IMUL_d_rm_mod_reg_u8, in_IMUL_d_rm_mod_reg_u8, 
	// 70
	in_DIV_d_rm_mod_reg_u8, in_DIV_d_rm_mod_reg_u8, in_DIV_d_rm_mod_reg_u8, in_DIV_d_rm_mod_reg_u8, in_DIV_d_rm_mod_reg_u8, in_DIV_d_rm_mod_reg_u8, in_DIV_d_rm_mod_reg_u8, in_DIV_d_rm_mod_reg_u8, 
	// 78
	in_IDIV_d_rm_mod_reg_u8, in_IDIV_d_rm_mod_reg_u8, in_IDIV_d_rm_mod_reg_u8, in_IDIV_d_rm_mod_reg_u8, in_IDIV_d_rm_mod_reg_u8, in_IDIV_d_rm_mod_reg_u8, in_IDIV_d_rm_mod_reg_u8, in_IDIV_d_rm_mod_reg_u8, 
	// 80
	in_TEST_d_imm_u8, in_TEST_d_imm_u8, in_TEST_d_imm_u8, in_TEST_d_imm_u8, in_TEST_d_imm_u8, in_TEST_d_imm_u8, in_TEST_d_imm_u8, in_TEST_d_imm_u8, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_NOT_d_rm_mod_reg_u8, in_NOT_d_rm_mod_reg_u8, in_NOT_d_rm_mod_reg_u8, in_NOT_d_rm_mod_reg_u8, in_NOT_d_rm_mod_reg_u8, in_NOT_d_rm_mod_reg_u8, in_NOT_d_rm_mod_reg_u8, in_NOT_d_rm_mod_reg_u8, 
	// 98
	in_NEG_d_rm_mod_reg_u8, in_NEG_d_rm_mod_reg_u8, in_NEG_d_rm_mod_reg_u8, in_NEG_d_rm_mod_reg_u8, in_NEG_d_rm_mod_reg_u8, in_NEG_d_rm_mod_reg_u8, in_NEG_d_rm_mod_reg_u8, in_NEG_d_rm_mod_reg_u8, 
	// A0
	in_MUL_d_rm_mod_reg_u8, in_MUL_d_rm_mod_reg_u8, in_MUL_d_rm_mod_reg_u8, in_MUL_d_rm_mod_reg_u8, in_MUL_d_rm_mod_reg_u8, in_MUL_d_rm_mod_reg_u8, in_MUL_d_rm_mod_reg_u8, in_MUL_d_rm_mod_reg_u8, 
	// A8
	in_IMUL_d_rm_mod_reg_u8, in_IMUL_d_rm_mod_reg_u8, in_IMUL_d_rm_mod_reg_u8, in_IMUL_d_rm_mod_reg_u8, in_IMUL_d_rm_mod_reg_u8, in_IMUL_d_rm_mod_reg_u8, in_IMUL_d_rm_mod_reg_u8, in_IMUL_d_rm_mod_reg_u8, 
	// B0
	in_DIV_d_rm_mod_reg_u8, in_DIV_d_rm_mod_reg_u8, in_DIV_d_rm_mod_reg_u8, in_DIV_d_rm_mod_reg_u8, in_DIV_d_rm_mod_reg_u8, in_DIV_d_rm_mod_reg_u8, in_DIV_d_rm_mod_reg_u8, in_DIV_d_rm_mod_reg_u8, 
	// B8
	in_IDIV_d_rm_mod_reg_u8, in_IDIV_d_rm_mod_reg_u8, in_IDIV_d_rm_mod_reg_u8, in_IDIV_d_rm_mod_reg_u8, in_IDIV_d_rm_mod_reg_u8, in_IDIV_d_rm_mod_reg_u8, in_IDIV_d_rm_mod_reg_u8, in_IDIV_d_rm_mod_reg_u8, 
	// C0
	in_TEST_d_imm_u8, in_TEST_d_imm_u8, in_TEST_d_imm_u8, in_TEST_d_imm_u8, in_TEST_d_imm_u8, in_TEST_d_imm_u8, in_TEST_d_imm_u8, in_TEST_d_imm_u8, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_NOT_d_rm_mod_reg_u8, in_NOT_d_rm_mod_reg_u8, in_NOT_d_rm_mod_reg_u8, in_NOT_d_rm_mod_reg_u8, in_NOT_d_rm_mod_reg_u8, in_NOT_d_rm_mod_reg_u8, in_NOT_d_rm_mod_reg_u8, in_NOT_d_rm_mod_reg_u8, 
	// D8
	in_NEG_d_rm_mod_reg_u8, in_NEG_d_rm_mod_reg_u8, in_NEG_d_rm_mod_reg_u8, in_NEG_d_rm_mod_reg_u8, in_NEG_d_rm_mod_reg_u8, in_NEG_d_rm_mod_reg_u8, in_NEG_d_rm_mod_reg_u8, in_NEG_d_rm_mod_reg_u8, 
	// E0
	in_MUL_d_rm_mod_reg_u8, in_MUL_d_rm_mod_reg_u8, in_MUL_d_rm_mod_reg_u8, in_MUL_d_rm_mod_reg_u8, in_MUL_d_rm_mod_reg_u8, in_MUL_d_rm_mod_reg_u8, in_MUL_d_rm_mod_reg_u8, in_MUL_d_rm_mod_reg_u8, 
	// E8
	in_IMUL_d_rm_mod_reg_u8, in_IMUL_d_rm_mod_reg_u8, in_IMUL_d_rm_mod_reg_u8, in_IMUL_d_rm_mod_reg_u8, in_IMUL_d_rm_mod_reg_u8, in_IMUL_d_rm_mod_reg_u8, in_IMUL_d_rm_mod_reg_u8, in_IMUL_d_rm_mod_reg_u8, 
	// F0
	in_DIV_d_rm_mod_reg_u8, in_DIV_d_rm_mod_reg_u8, in_DIV_d_rm_mod_reg_u8, in_DIV_d_rm_mod_reg_u8, in_DIV_d_rm_mod_reg_u8, in_DIV_d_rm_mod_reg_u8, in_DIV_d_rm_mod_reg_u8, in_DIV_d_rm_mod_reg_u8, 
	// F8
	in_IDIV_d_rm_mod_reg_u8, in_IDIV_d_rm_mod_reg_u8, in_IDIV_d_rm_mod_reg_u8, in_IDIV_d_rm_mod_reg_u8, in_IDIV_d_rm_mod_reg_u8, in_IDIV_d_rm_mod_reg_u8, in_IDIV_d_rm_mod_reg_u8, in_IDIV_d_rm_mod_reg_u8, 
};
const OpState CpuRunnerX86::table_st_d_d_F6[] = {
	// 00
	in_TEST_d_imm_u8, in_TEST_d_imm_u8, in_TEST_d_imm_u8, in_TEST_d_imm_u8, in_TEST_d_imm_u8, in_TEST_d_imm_u8, in_TEST_d_imm_u8, in_TEST_d_imm_u8, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_NOT_d_rm_mod_reg_u8, in_NOT_d_rm_mod_reg_u8, in_NOT_d_rm_mod_reg_u8, in_NOT_d_rm_mod_reg_u8, in_NOT_d_rm_mod_reg_u8, in_NOT_d_rm_mod_reg_u8, in_NOT_d_rm_mod_reg_u8, in_NOT_d_rm_mod_reg_u8, 
	// 18
	in_NEG_d_rm_mod_reg_u8, in_NEG_d_rm_mod_reg_u8, in_NEG_d_rm_mod_reg_u8, in_NEG_d_rm_mod_reg_u8, in_NEG_d_rm_mod_reg_u8, in_NEG_d_rm_mod_reg_u8, in_NEG_d_rm_mod_reg_u8, in_NEG_d_rm_mod_reg_u8, 
	// 20
	in_MUL_d_rm_mod_reg_u8, in_MUL_d_rm_mod_reg_u8, in_MUL_d_rm_mod_reg_u8, in_MUL_d_rm_mod_reg_u8, in_MUL_d_rm_mod_reg_u8, in_MUL_d_rm_mod_reg_u8, in_MUL_d_rm_mod_reg_u8, in_MUL_d_rm_mod_reg_u8, 
	// 28
	in_IMUL_d_rm_mod_reg_u8, in_IMUL_d_rm_mod_reg_u8, in_IMUL_d_rm_mod_reg_u8, in_IMUL_d_rm_mod_reg_u8, in_IMUL_d_rm_mod_reg_u8, in_IMUL_d_rm_mod_reg_u8, in_IMUL_d_rm_mod_reg_u8, in_IMUL_d_rm_mod_reg_u8, 
	// 30
	in_DIV_d_rm_mod_reg_u8, in_DIV_d_rm_mod_reg_u8, in_DIV_d_rm_mod_reg_u8, in_DIV_d_rm_mod_reg_u8, in_DIV_d_rm_mod_reg_u8, in_DIV_d_rm_mod_reg_u8, in_DIV_d_rm_mod_reg_u8, in_DIV_d_rm_mod_reg_u8, 
	// 38
	in_IDIV_d_rm_mod_reg_u8, in_IDIV_d_rm_mod_reg_u8, in_IDIV_d_rm_mod_reg_u8, in_IDIV_d_rm_mod_reg_u8, in_IDIV_d_rm_mod_reg_u8, in_IDIV_d_rm_mod_reg_u8, in_IDIV_d_rm_mod_reg_u8, in_IDIV_d_rm_mod_reg_u8, 
	// 40
	in_TEST_d_imm_u8, in_TEST_d_imm_u8, in_TEST_d_imm_u8, in_TEST_d_imm_u8, in_TEST_d_imm_u8, in_TEST_d_imm_u8, in_TEST_d_imm_u8, in_TEST_d_imm_u8, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_NOT_d_rm_mod_reg_u8, in_NOT_d_rm_mod_reg_u8, in_NOT_d_rm_mod_reg_u8, in_NOT_d_rm_mod_reg_u8, in_NOT_d_rm_mod_reg_u8, in_NOT_d_rm_mod_reg_u8, in_NOT_d_rm_mod_reg_u8, in_NOT_d_rm_mod_reg_u8, 
	// 58
	in_NEG_d_rm_mod_reg_u8, in_NEG_d_rm_mod_reg_u8, in_NEG_d_rm_mod_reg_u8, in_NEG_d_rm_mod_reg_u8, in_NEG_d_rm_mod_reg_u8, in_NEG_d_rm_mod_reg_u8, in_NEG_d_rm_mod_reg_u8, in_NEG_d_rm_mod_reg_u8, 
	// 60
	in_MUL_d_rm_mod_reg_u8, in_MUL_d_rm_mod_reg_u8, in_MUL_d_rm_mod_reg_u8, in_MUL_d_rm_mod_reg_u8, in_MUL_d_rm_mod_reg_u8, in_MUL_d_rm_mod_reg_u8, in_MUL_d_rm_mod_reg_u8, in_MUL_d_rm_mod_reg_u8, 
	// 68
	in_IMUL_d_rm_mod_reg_u8, in_IMUL_d_rm_mod_reg_u8, in_IMUL_d_rm_mod_reg_u8, in_IMUL_d_rm_mod_reg_u8, in_IMUL_d_rm_mod_reg_u8, in_IMUL_d_rm_mod_reg_u8, in_IMUL_d_rm_mod_reg_u8, in_IMUL_d_rm_mod_reg_u8, 
	// 70
	in_DIV_d_rm_mod_reg_u8, in_DIV_d_rm_mod_reg_u8, in_DIV_d_rm_mod_reg_u8, in_DIV_d_rm_mod_reg_u8, in_DIV_d_rm_mod_reg_u8, in_DIV_d_rm_mod_reg_u8, in_DIV_d_rm_mod_reg_u8, in_DIV_d_rm_mod_reg_u8, 
	// 78
	in_IDIV_d_rm_mod_reg_u8, in_IDIV_d_rm_mod_reg_u8, in_IDIV_d_rm_mod_reg_u8, in_IDIV_d_rm_mod_reg_u8, in_IDIV_d_rm_mod_reg_u8, in_IDIV_d_rm_mod_reg_u8, in_IDIV_d_rm_mod_reg_u8, in_IDIV_d_rm_mod_reg_u8, 
	// 80
	in_TEST_d_imm_u8, in_TEST_d_imm_u8, in_TEST_d_imm_u8, in_TEST_d_imm_u8, in_TEST_d_imm_u8, in_TEST_d_imm_u8, in_TEST_d_imm_u8, in_TEST_d_imm_u8, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_NOT_d_rm_mod_reg_u8, in_NOT_d_rm_mod_reg_u8, in_NOT_d_rm_mod_reg_u8, in_NOT_d_rm_mod_reg_u8, in_NOT_d_rm_mod_reg_u8, in_NOT_d_rm_mod_reg_u8, in_NOT_d_rm_mod_reg_u8, in_NOT_d_rm_mod_reg_u8, 
	// 98
	in_NEG_d_rm_mod_reg_u8, in_NEG_d_rm_mod_reg_u8, in_NEG_d_rm_mod_reg_u8, in_NEG_d_rm_mod_reg_u8, in_NEG_d_rm_mod_reg_u8, in_NEG_d_rm_mod_reg_u8, in_NEG_d_rm_mod_reg_u8, in_NEG_d_rm_mod_reg_u8, 
	// A0
	in_MUL_d_rm_mod_reg_u8, in_MUL_d_rm_mod_reg_u8, in_MUL_d_rm_mod_reg_u8, in_MUL_d_rm_mod_reg_u8, in_MUL_d_rm_mod_reg_u8, in_MUL_d_rm_mod_reg_u8, in_MUL_d_rm_mod_reg_u8, in_MUL_d_rm_mod_reg_u8, 
	// A8
	in_IMUL_d_rm_mod_reg_u8, in_IMUL_d_rm_mod_reg_u8, in_IMUL_d_rm_mod_reg_u8, in_IMUL_d_rm_mod_reg_u8, in_IMUL_d_rm_mod_reg_u8, in_IMUL_d_rm_mod_reg_u8, in_IMUL_d_rm_mod_reg_u8, in_IMUL_d_rm_mod_reg_u8, 
	// B0
	in_DIV_d_rm_mod_reg_u8, in_DIV_d_rm_mod_reg_u8, in_DIV_d_rm_mod_reg_u8, in_DIV_d_rm_mod_reg_u8, in_DIV_d_rm_mod_reg_u8, in_DIV_d_rm_mod_reg_u8, in_DIV_d_rm_mod_reg_u8, in_DIV_d_rm_mod_reg_u8, 
	// B8
	in_IDIV_d_rm_mod_reg_u8, in_IDIV_d_rm_mod_reg_u8, in_IDIV_d_rm_mod_reg_u8, in_IDIV_d_rm_mod_reg_u8, in_IDIV_d_rm_mod_reg_u8, in_IDIV_d_rm_mod_reg_u8, in_IDIV_d_rm_mod_reg_u8, in_IDIV_d_rm_mod_reg_u8, 
	// C0
	in_TEST_d_imm_u8, in_TEST_d_imm_u8, in_TEST_d_imm_u8, in_TEST_d_imm_u8, in_TEST_d_imm_u8, in_TEST_d_imm_u8, in_TEST_d_imm_u8, in_TEST_d_imm_u8, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_NOT_d_rm_mod_reg_u8, in_NOT_d_rm_mod_reg_u8, in_NOT_d_rm_mod_reg_u8, in_NOT_d_rm_mod_reg_u8, in_NOT_d_rm_mod_reg_u8, in_NOT_d_rm_mod_reg_u8, in_NOT_d_rm_mod_reg_u8, in_NOT_d_rm_mod_reg_u8, 
	// D8
	in_NEG_d_rm_mod_reg_u8, in_NEG_d_rm_mod_reg_u8, in_NEG_d_rm_mod_reg_u8, in_NEG_d_rm_mod_reg_u8, in_NEG_d_rm_mod_reg_u8, in_NEG_d_rm_mod_reg_u8, in_NEG_d_rm_mod_reg_u8, in_NEG_d_rm_mod_reg_u8, 
	// E0
	in_MUL_d_rm_mod_reg_u8, in_MUL_d_rm_mod_reg_u8, in_MUL_d_rm_mod_reg_u8, in_MUL_d_rm_mod_reg_u8, in_MUL_d_rm_mod_reg_u8, in_MUL_d_rm_mod_reg_u8, in_MUL_d_rm_mod_reg_u8, in_MUL_d_rm_mod_reg_u8, 
	// E8
	in_IMUL_d_rm_mod_reg_u8, in_IMUL_d_rm_mod_reg_u8, in_IMUL_d_rm_mod_reg_u8, in_IMUL_d_rm_mod_reg_u8, in_IMUL_d_rm_mod_reg_u8, in_IMUL_d_rm_mod_reg_u8, in_IMUL_d_rm_mod_reg_u8, in_IMUL_d_rm_mod_reg_u8, 
	// F0
	in_DIV_d_rm_mod_reg_u8, in_DIV_d_rm_mod_reg_u8, in_DIV_d_rm_mod_reg_u8, in_DIV_d_rm_mod_reg_u8, in_DIV_d_rm_mod_reg_u8, in_DIV_d_rm_mod_reg_u8, in_DIV_d_rm_mod_reg_u8, in_DIV_d_rm_mod_reg_u8, 
	// F8
	in_IDIV_d_rm_mod_reg_u8, in_IDIV_d_rm_mod_reg_u8, in_IDIV_d_rm_mod_reg_u8, in_IDIV_d_rm_mod_reg_u8, in_IDIV_d_rm_mod_reg_u8, in_IDIV_d_rm_mod_reg_u8, in_IDIV_d_rm_mod_reg_u8, in_IDIV_d_rm_mod_reg_u8, 
};
const OpState CpuRunnerX86::table_st_w_w_F7[] = {
	// 00
	in_TEST_w_imm_u16, in_TEST_w_imm_u16, in_TEST_w_imm_u16, in_TEST_w_imm_u16, in_TEST_w_imm_u16, in_TEST_w_imm_u16, in_TEST_w_imm_u16, in_TEST_w_imm_u16, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_NOT_w_rm_mod_reg_u16, in_NOT_w_rm_mod_reg_u16, in_NOT_w_rm_mod_reg_u16, in_NOT_w_rm_mod_reg_u16, in_NOT_w_rm_mod_reg_u16, in_NOT_w_rm_mod_reg_u16, in_NOT_w_rm_mod_reg_u16, in_NOT_w_rm_mod_reg_u16, 
	// 18
	in_NEG_w_rm_mod_reg_u16, in_NEG_w_rm_mod_reg_u16, in_NEG_w_rm_mod_reg_u16, in_NEG_w_rm_mod_reg_u16, in_NEG_w_rm_mod_reg_u16, in_NEG_w_rm_mod_reg_u16, in_NEG_w_rm_mod_reg_u16, in_NEG_w_rm_mod_reg_u16, 
	// 20
	in_MUL_w_rm_mod_reg_u16, in_MUL_w_rm_mod_reg_u16, in_MUL_w_rm_mod_reg_u16, in_MUL_w_rm_mod_reg_u16, in_MUL_w_rm_mod_reg_u16, in_MUL_w_rm_mod_reg_u16, in_MUL_w_rm_mod_reg_u16, in_MUL_w_rm_mod_reg_u16, 
	// 28
	in_IMUL_w_rm_mod_reg_u16, in_IMUL_w_rm_mod_reg_u16, in_IMUL_w_rm_mod_reg_u16, in_IMUL_w_rm_mod_reg_u16, in_IMUL_w_rm_mod_reg_u16, in_IMUL_w_rm_mod_reg_u16, in_IMUL_w_rm_mod_reg_u16, in_IMUL_w_rm_mod_reg_u16, 
	// 30
	in_DIV_w_rm_mod_reg_u16, in_DIV_w_rm_mod_reg_u16, in_DIV_w_rm_mod_reg_u16, in_DIV_w_rm_mod_reg_u16, in_DIV_w_rm_mod_reg_u16, in_DIV_w_rm_mod_reg_u16, in_DIV_w_rm_mod_reg_u16, in_DIV_w_rm_mod_reg_u16, 
	// 38
	in_IDIV_w_rm_mod_reg_u16, in_IDIV_w_rm_mod_reg_u16, in_IDIV_w_rm_mod_reg_u16, in_IDIV_w_rm_mod_reg_u16, in_IDIV_w_rm_mod_reg_u16, in_IDIV_w_rm_mod_reg_u16, in_IDIV_w_rm_mod_reg_u16, in_IDIV_w_rm_mod_reg_u16, 
	// 40
	in_TEST_w_imm_u16, in_TEST_w_imm_u16, in_TEST_w_imm_u16, in_TEST_w_imm_u16, in_TEST_w_imm_u16, in_TEST_w_imm_u16, in_TEST_w_imm_u16, in_TEST_w_imm_u16, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_NOT_w_rm_mod_reg_u16, in_NOT_w_rm_mod_reg_u16, in_NOT_w_rm_mod_reg_u16, in_NOT_w_rm_mod_reg_u16, in_NOT_w_rm_mod_reg_u16, in_NOT_w_rm_mod_reg_u16, in_NOT_w_rm_mod_reg_u16, in_NOT_w_rm_mod_reg_u16, 
	// 58
	in_NEG_w_rm_mod_reg_u16, in_NEG_w_rm_mod_reg_u16, in_NEG_w_rm_mod_reg_u16, in_NEG_w_rm_mod_reg_u16, in_NEG_w_rm_mod_reg_u16, in_NEG_w_rm_mod_reg_u16, in_NEG_w_rm_mod_reg_u16, in_NEG_w_rm_mod_reg_u16, 
	// 60
	in_MUL_w_rm_mod_reg_u16, in_MUL_w_rm_mod_reg_u16, in_MUL_w_rm_mod_reg_u16, in_MUL_w_rm_mod_reg_u16, in_MUL_w_rm_mod_reg_u16, in_MUL_w_rm_mod_reg_u16, in_MUL_w_rm_mod_reg_u16, in_MUL_w_rm_mod_reg_u16, 
	// 68
	in_IMUL_w_rm_mod_reg_u16, in_IMUL_w_rm_mod_reg_u16, in_IMUL_w_rm_mod_reg_u16, in_IMUL_w_rm_mod_reg_u16, in_IMUL_w_rm_mod_reg_u16, in_IMUL_w_rm_mod_reg_u16, in_IMUL_w_rm_mod_reg_u16, in_IMUL_w_rm_mod_reg_u16, 
	// 70
	in_DIV_w_rm_mod_reg_u16, in_DIV_w_rm_mod_reg_u16, in_DIV_w_rm_mod_reg_u16, in_DIV_w_rm_mod_reg_u16, in_DIV_w_rm_mod_reg_u16, in_DIV_w_rm_mod_reg_u16, in_DIV_w_rm_mod_reg_u16, in_DIV_w_rm_mod_reg_u16, 
	// 78
	in_IDIV_w_rm_mod_reg_u16, in_IDIV_w_rm_mod_reg_u16, in_IDIV_w_rm_mod_reg_u16, in_IDIV_w_rm_mod_reg_u16, in_IDIV_w_rm_mod_reg_u16, in_IDIV_w_rm_mod_reg_u16, in_IDIV_w_rm_mod_reg_u16, in_IDIV_w_rm_mod_reg_u16, 
	// 80
	in_TEST_w_imm_u16, in_TEST_w_imm_u16, in_TEST_w_imm_u16, in_TEST_w_imm_u16, in_TEST_w_imm_u16, in_TEST_w_imm_u16, in_TEST_w_imm_u16, in_TEST_w_imm_u16, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_NOT_w_rm_mod_reg_u16, in_NOT_w_rm_mod_reg_u16, in_NOT_w_rm_mod_reg_u16, in_NOT_w_rm_mod_reg_u16, in_NOT_w_rm_mod_reg_u16, in_NOT_w_rm_mod_reg_u16, in_NOT_w_rm_mod_reg_u16, in_NOT_w_rm_mod_reg_u16, 
	// 98
	in_NEG_w_rm_mod_reg_u16, in_NEG_w_rm_mod_reg_u16, in_NEG_w_rm_mod_reg_u16, in_NEG_w_rm_mod_reg_u16, in_NEG_w_rm_mod_reg_u16, in_NEG_w_rm_mod_reg_u16, in_NEG_w_rm_mod_reg_u16, in_NEG_w_rm_mod_reg_u16, 
	// A0
	in_MUL_w_rm_mod_reg_u16, in_MUL_w_rm_mod_reg_u16, in_MUL_w_rm_mod_reg_u16, in_MUL_w_rm_mod_reg_u16, in_MUL_w_rm_mod_reg_u16, in_MUL_w_rm_mod_reg_u16, in_MUL_w_rm_mod_reg_u16, in_MUL_w_rm_mod_reg_u16, 
	// A8
	in_IMUL_w_rm_mod_reg_u16, in_IMUL_w_rm_mod_reg_u16, in_IMUL_w_rm_mod_reg_u16, in_IMUL_w_rm_mod_reg_u16, in_IMUL_w_rm_mod_reg_u16, in_IMUL_w_rm_mod_reg_u16, in_IMUL_w_rm_mod_reg_u16, in_IMUL_w_rm_mod_reg_u16, 
	// B0
	in_DIV_w_rm_mod_reg_u16, in_DIV_w_rm_mod_reg_u16, in_DIV_w_rm_mod_reg_u16, in_DIV_w_rm_mod_reg_u16, in_DIV_w_rm_mod_reg_u16, in_DIV_w_rm_mod_reg_u16, in_DIV_w_rm_mod_reg_u16, in_DIV_w_rm_mod_reg_u16, 
	// B8
	in_IDIV_w_rm_mod_reg_u16, in_IDIV_w_rm_mod_reg_u16, in_IDIV_w_rm_mod_reg_u16, in_IDIV_w_rm_mod_reg_u16, in_IDIV_w_rm_mod_reg_u16, in_IDIV_w_rm_mod_reg_u16, in_IDIV_w_rm_mod_reg_u16, in_IDIV_w_rm_mod_reg_u16, 
	// C0
	in_TEST_w_imm_u16, in_TEST_w_imm_u16, in_TEST_w_imm_u16, in_TEST_w_imm_u16, in_TEST_w_imm_u16, in_TEST_w_imm_u16, in_TEST_w_imm_u16, in_TEST_w_imm_u16, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_NOT_w_rm_mod_reg_u16, in_NOT_w_rm_mod_reg_u16, in_NOT_w_rm_mod_reg_u16, in_NOT_w_rm_mod_reg_u16, in_NOT_w_rm_mod_reg_u16, in_NOT_w_rm_mod_reg_u16, in_NOT_w_rm_mod_reg_u16, in_NOT_w_rm_mod_reg_u16, 
	// D8
	in_NEG_w_rm_mod_reg_u16, in_NEG_w_rm_mod_reg_u16, in_NEG_w_rm_mod_reg_u16, in_NEG_w_rm_mod_reg_u16, in_NEG_w_rm_mod_reg_u16, in_NEG_w_rm_mod_reg_u16, in_NEG_w_rm_mod_reg_u16, in_NEG_w_rm_mod_reg_u16, 
	// E0
	in_MUL_w_rm_mod_reg_u16, in_MUL_w_rm_mod_reg_u16, in_MUL_w_rm_mod_reg_u16, in_MUL_w_rm_mod_reg_u16, in_MUL_w_rm_mod_reg_u16, in_MUL_w_rm_mod_reg_u16, in_MUL_w_rm_mod_reg_u16, in_MUL_w_rm_mod_reg_u16, 
	// E8
	in_IMUL_w_rm_mod_reg_u16, in_IMUL_w_rm_mod_reg_u16, in_IMUL_w_rm_mod_reg_u16, in_IMUL_w_rm_mod_reg_u16, in_IMUL_w_rm_mod_reg_u16, in_IMUL_w_rm_mod_reg_u16, in_IMUL_w_rm_mod_reg_u16, in_IMUL_w_rm_mod_reg_u16, 
	// F0
	in_DIV_w_rm_mod_reg_u16, in_DIV_w_rm_mod_reg_u16, in_DIV_w_rm_mod_reg_u16, in_DIV_w_rm_mod_reg_u16, in_DIV_w_rm_mod_reg_u16, in_DIV_w_rm_mod_reg_u16, in_DIV_w_rm_mod_reg_u16, in_DIV_w_rm_mod_reg_u16, 
	// F8
	in_IDIV_w_rm_mod_reg_u16, in_IDIV_w_rm_mod_reg_u16, in_IDIV_w_rm_mod_reg_u16, in_IDIV_w_rm_mod_reg_u16, in_IDIV_w_rm_mod_reg_u16, in_IDIV_w_rm_mod_reg_u16, in_IDIV_w_rm_mod_reg_u16, in_IDIV_w_rm_mod_reg_u16, 
};
const OpState CpuRunnerX86::table_st_w_d_F7[] = {
	// 00
	in_TEST_w_imm_u32, in_TEST_w_imm_u32, in_TEST_w_imm_u32, in_TEST_w_imm_u32, in_TEST_w_imm_u32, in_TEST_w_imm_u32, in_TEST_w_imm_u32, in_TEST_w_imm_u32, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_NOT_w_rm_mod_reg_u32, in_NOT_w_rm_mod_reg_u32, in_NOT_w_rm_mod_reg_u32, in_NOT_w_rm_mod_reg_u32, in_NOT_w_rm_mod_reg_u32, in_NOT_w_rm_mod_reg_u32, in_NOT_w_rm_mod_reg_u32, in_NOT_w_rm_mod_reg_u32, 
	// 18
	in_NEG_w_rm_mod_reg_u32, in_NEG_w_rm_mod_reg_u32, in_NEG_w_rm_mod_reg_u32, in_NEG_w_rm_mod_reg_u32, in_NEG_w_rm_mod_reg_u32, in_NEG_w_rm_mod_reg_u32, in_NEG_w_rm_mod_reg_u32, in_NEG_w_rm_mod_reg_u32, 
	// 20
	in_MUL_w_rm_mod_reg_u32, in_MUL_w_rm_mod_reg_u32, in_MUL_w_rm_mod_reg_u32, in_MUL_w_rm_mod_reg_u32, in_MUL_w_rm_mod_reg_u32, in_MUL_w_rm_mod_reg_u32, in_MUL_w_rm_mod_reg_u32, in_MUL_w_rm_mod_reg_u32, 
	// 28
	in_IMUL_w_rm_mod_reg_u16, in_IMUL_w_rm_mod_reg_u16, in_IMUL_w_rm_mod_reg_u16, in_IMUL_w_rm_mod_reg_u16, in_IMUL_w_rm_mod_reg_u16, in_IMUL_w_rm_mod_reg_u16, in_IMUL_w_rm_mod_reg_u16, in_IMUL_w_rm_mod_reg_u16, 
	// 30
	in_DIV_w_rm_mod_reg_u16, in_DIV_w_rm_mod_reg_u16, in_DIV_w_rm_mod_reg_u16, in_DIV_w_rm_mod_reg_u16, in_DIV_w_rm_mod_reg_u16, in_DIV_w_rm_mod_reg_u16, in_DIV_w_rm_mod_reg_u16, in_DIV_w_rm_mod_reg_u16, 
	// 38
	in_IDIV_w_rm_mod_reg_u16, in_IDIV_w_rm_mod_reg_u16, in_IDIV_w_rm_mod_reg_u16, in_IDIV_w_rm_mod_reg_u16, in_IDIV_w_rm_mod_reg_u16, in_IDIV_w_rm_mod_reg_u16, in_IDIV_w_rm_mod_reg_u16, in_IDIV_w_rm_mod_reg_u16, 
	// 40
	in_TEST_w_imm_u32, in_TEST_w_imm_u32, in_TEST_w_imm_u32, in_TEST_w_imm_u32, in_TEST_w_imm_u32, in_TEST_w_imm_u32, in_TEST_w_imm_u32, in_TEST_w_imm_u32, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_NOT_w_rm_mod_reg_u32, in_NOT_w_rm_mod_reg_u32, in_NOT_w_rm_mod_reg_u32, in_NOT_w_rm_mod_reg_u32, in_NOT_w_rm_mod_reg_u32, in_NOT_w_rm_mod_reg_u32, in_NOT_w_rm_mod_reg_u32, in_NOT_w_rm_mod_reg_u32, 
	// 58
	in_NEG_w_rm_mod_reg_u32, in_NEG_w_rm_mod_reg_u32, in_NEG_w_rm_mod_reg_u32, in_NEG_w_rm_mod_reg_u32, in_NEG_w_rm_mod_reg_u32, in_NEG_w_rm_mod_reg_u32, in_NEG_w_rm_mod_reg_u32, in_NEG_w_rm_mod_reg_u32, 
	// 60
	in_MUL_w_rm_mod_reg_u32, in_MUL_w_rm_mod_reg_u32, in_MUL_w_rm_mod_reg_u32, in_MUL_w_rm_mod_reg_u32, in_MUL_w_rm_mod_reg_u32, in_MUL_w_rm_mod_reg_u32, in_MUL_w_rm_mod_reg_u32, in_MUL_w_rm_mod_reg_u32, 
	// 68
	in_IMUL_w_rm_mod_reg_u16, in_IMUL_w_rm_mod_reg_u16, in_IMUL_w_rm_mod_reg_u16, in_IMUL_w_rm_mod_reg_u16, in_IMUL_w_rm_mod_reg_u16, in_IMUL_w_rm_mod_reg_u16, in_IMUL_w_rm_mod_reg_u16, in_IMUL_w_rm_mod_reg_u16, 
	// 70
	in_DIV_w_rm_mod_reg_u16, in_DIV_w_rm_mod_reg_u16, in_DIV_w_rm_mod_reg_u16, in_DIV_w_rm_mod_reg_u16, in_DIV_w_rm_mod_reg_u16, in_DIV_w_rm_mod_reg_u16, in_DIV_w_rm_mod_reg_u16, in_DIV_w_rm_mod_reg_u16, 
	// 78
	in_IDIV_w_rm_mod_reg_u16, in_IDIV_w_rm_mod_reg_u16, in_IDIV_w_rm_mod_reg_u16, in_IDIV_w_rm_mod_reg_u16, in_IDIV_w_rm_mod_reg_u16, in_IDIV_w_rm_mod_reg_u16, in_IDIV_w_rm_mod_reg_u16, in_IDIV_w_rm_mod_reg_u16, 
	// 80
	in_TEST_w_imm_u32, in_TEST_w_imm_u32, in_TEST_w_imm_u32, in_TEST_w_imm_u32, in_TEST_w_imm_u32, in_TEST_w_imm_u32, in_TEST_w_imm_u32, in_TEST_w_imm_u32, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_NOT_w_rm_mod_reg_u32, in_NOT_w_rm_mod_reg_u32, in_NOT_w_rm_mod_reg_u32, in_NOT_w_rm_mod_reg_u32, in_NOT_w_rm_mod_reg_u32, in_NOT_w_rm_mod_reg_u32, in_NOT_w_rm_mod_reg_u32, in_NOT_w_rm_mod_reg_u32, 
	// 98
	in_NEG_w_rm_mod_reg_u32, in_NEG_w_rm_mod_reg_u32, in_NEG_w_rm_mod_reg_u32, in_NEG_w_rm_mod_reg_u32, in_NEG_w_rm_mod_reg_u32, in_NEG_w_rm_mod_reg_u32, in_NEG_w_rm_mod_reg_u32, in_NEG_w_rm_mod_reg_u32, 
	// A0
	in_MUL_w_rm_mod_reg_u32, in_MUL_w_rm_mod_reg_u32, in_MUL_w_rm_mod_reg_u32, in_MUL_w_rm_mod_reg_u32, in_MUL_w_rm_mod_reg_u32, in_MUL_w_rm_mod_reg_u32, in_MUL_w_rm_mod_reg_u32, in_MUL_w_rm_mod_reg_u32, 
	// A8
	in_IMUL_w_rm_mod_reg_u16, in_IMUL_w_rm_mod_reg_u16, in_IMUL_w_rm_mod_reg_u16, in_IMUL_w_rm_mod_reg_u16, in_IMUL_w_rm_mod_reg_u16, in_IMUL_w_rm_mod_reg_u16, in_IMUL_w_rm_mod_reg_u16, in_IMUL_w_rm_mod_reg_u16, 
	// B0
	in_DIV_w_rm_mod_reg_u16, in_DIV_w_rm_mod_reg_u16, in_DIV_w_rm_mod_reg_u16, in_DIV_w_rm_mod_reg_u16, in_DIV_w_rm_mod_reg_u16, in_DIV_w_rm_mod_reg_u16, in_DIV_w_rm_mod_reg_u16, in_DIV_w_rm_mod_reg_u16, 
	// B8
	in_IDIV_w_rm_mod_reg_u16, in_IDIV_w_rm_mod_reg_u16, in_IDIV_w_rm_mod_reg_u16, in_IDIV_w_rm_mod_reg_u16, in_IDIV_w_rm_mod_reg_u16, in_IDIV_w_rm_mod_reg_u16, in_IDIV_w_rm_mod_reg_u16, in_IDIV_w_rm_mod_reg_u16, 
	// C0
	in_TEST_w_imm_u32, in_TEST_w_imm_u32, in_TEST_w_imm_u32, in_TEST_w_imm_u32, in_TEST_w_imm_u32, in_TEST_w_imm_u32, in_TEST_w_imm_u32, in_TEST_w_imm_u32, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_NOT_w_rm_mod_reg_u32, in_NOT_w_rm_mod_reg_u32, in_NOT_w_rm_mod_reg_u32, in_NOT_w_rm_mod_reg_u32, in_NOT_w_rm_mod_reg_u32, in_NOT_w_rm_mod_reg_u32, in_NOT_w_rm_mod_reg_u32, in_NOT_w_rm_mod_reg_u32, 
	// D8
	in_NEG_w_rm_mod_reg_u32, in_NEG_w_rm_mod_reg_u32, in_NEG_w_rm_mod_reg_u32, in_NEG_w_rm_mod_reg_u32, in_NEG_w_rm_mod_reg_u32, in_NEG_w_rm_mod_reg_u32, in_NEG_w_rm_mod_reg_u32, in_NEG_w_rm_mod_reg_u32, 
	// E0
	in_MUL_w_rm_mod_reg_u32, in_MUL_w_rm_mod_reg_u32, in_MUL_w_rm_mod_reg_u32, in_MUL_w_rm_mod_reg_u32, in_MUL_w_rm_mod_reg_u32, in_MUL_w_rm_mod_reg_u32, in_MUL_w_rm_mod_reg_u32, in_MUL_w_rm_mod_reg_u32, 
	// E8
	in_IMUL_w_rm_mod_reg_u16, in_IMUL_w_rm_mod_reg_u16, in_IMUL_w_rm_mod_reg_u16, in_IMUL_w_rm_mod_reg_u16, in_IMUL_w_rm_mod_reg_u16, in_IMUL_w_rm_mod_reg_u16, in_IMUL_w_rm_mod_reg_u16, in_IMUL_w_rm_mod_reg_u16, 
	// F0
	in_DIV_w_rm_mod_reg_u16, in_DIV_w_rm_mod_reg_u16, in_DIV_w_rm_mod_reg_u16, in_DIV_w_rm_mod_reg_u16, in_DIV_w_rm_mod_reg_u16, in_DIV_w_rm_mod_reg_u16, in_DIV_w_rm_mod_reg_u16, in_DIV_w_rm_mod_reg_u16, 
	// F8
	in_IDIV_w_rm_mod_reg_u16, in_IDIV_w_rm_mod_reg_u16, in_IDIV_w_rm_mod_reg_u16, in_IDIV_w_rm_mod_reg_u16, in_IDIV_w_rm_mod_reg_u16, in_IDIV_w_rm_mod_reg_u16, in_IDIV_w_rm_mod_reg_u16, in_IDIV_w_rm_mod_reg_u16, 
};
const OpState CpuRunnerX86::table_st_d_w_F7[] = {
	// 00
	in_TEST_d_imm_u16, in_TEST_d_imm_u16, in_TEST_d_imm_u16, in_TEST_d_imm_u16, in_TEST_d_imm_u16, in_TEST_d_imm_u16, in_TEST_d_imm_u16, in_TEST_d_imm_u16, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_NOT_d_rm_mod_reg_u16, in_NOT_d_rm_mod_reg_u16, in_NOT_d_rm_mod_reg_u16, in_NOT_d_rm_mod_reg_u16, in_NOT_d_rm_mod_reg_u16, in_NOT_d_rm_mod_reg_u16, in_NOT_d_rm_mod_reg_u16, in_NOT_d_rm_mod_reg_u16, 
	// 18
	in_NEG_d_rm_mod_reg_u16, in_NEG_d_rm_mod_reg_u16, in_NEG_d_rm_mod_reg_u16, in_NEG_d_rm_mod_reg_u16, in_NEG_d_rm_mod_reg_u16, in_NEG_d_rm_mod_reg_u16, in_NEG_d_rm_mod_reg_u16, in_NEG_d_rm_mod_reg_u16, 
	// 20
	in_MUL_d_rm_mod_reg_u16, in_MUL_d_rm_mod_reg_u16, in_MUL_d_rm_mod_reg_u16, in_MUL_d_rm_mod_reg_u16, in_MUL_d_rm_mod_reg_u16, in_MUL_d_rm_mod_reg_u16, in_MUL_d_rm_mod_reg_u16, in_MUL_d_rm_mod_reg_u16, 
	// 28
	in_IMUL_d_rm_mod_reg_u16, in_IMUL_d_rm_mod_reg_u16, in_IMUL_d_rm_mod_reg_u16, in_IMUL_d_rm_mod_reg_u16, in_IMUL_d_rm_mod_reg_u16, in_IMUL_d_rm_mod_reg_u16, in_IMUL_d_rm_mod_reg_u16, in_IMUL_d_rm_mod_reg_u16, 
	// 30
	in_DIV_d_rm_mod_reg_u16, in_DIV_d_rm_mod_reg_u16, in_DIV_d_rm_mod_reg_u16, in_DIV_d_rm_mod_reg_u16, in_DIV_d_rm_mod_reg_u16, in_DIV_d_rm_mod_reg_u16, in_DIV_d_rm_mod_reg_u16, in_DIV_d_rm_mod_reg_u16, 
	// 38
	in_IDIV_d_rm_mod_reg_u16, in_IDIV_d_rm_mod_reg_u16, in_IDIV_d_rm_mod_reg_u16, in_IDIV_d_rm_mod_reg_u16, in_IDIV_d_rm_mod_reg_u16, in_IDIV_d_rm_mod_reg_u16, in_IDIV_d_rm_mod_reg_u16, in_IDIV_d_rm_mod_reg_u16, 
	// 40
	in_TEST_d_imm_u16, in_TEST_d_imm_u16, in_TEST_d_imm_u16, in_TEST_d_imm_u16, in_TEST_d_imm_u16, in_TEST_d_imm_u16, in_TEST_d_imm_u16, in_TEST_d_imm_u16, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_NOT_d_rm_mod_reg_u16, in_NOT_d_rm_mod_reg_u16, in_NOT_d_rm_mod_reg_u16, in_NOT_d_rm_mod_reg_u16, in_NOT_d_rm_mod_reg_u16, in_NOT_d_rm_mod_reg_u16, in_NOT_d_rm_mod_reg_u16, in_NOT_d_rm_mod_reg_u16, 
	// 58
	in_NEG_d_rm_mod_reg_u16, in_NEG_d_rm_mod_reg_u16, in_NEG_d_rm_mod_reg_u16, in_NEG_d_rm_mod_reg_u16, in_NEG_d_rm_mod_reg_u16, in_NEG_d_rm_mod_reg_u16, in_NEG_d_rm_mod_reg_u16, in_NEG_d_rm_mod_reg_u16, 
	// 60
	in_MUL_d_rm_mod_reg_u16, in_MUL_d_rm_mod_reg_u16, in_MUL_d_rm_mod_reg_u16, in_MUL_d_rm_mod_reg_u16, in_MUL_d_rm_mod_reg_u16, in_MUL_d_rm_mod_reg_u16, in_MUL_d_rm_mod_reg_u16, in_MUL_d_rm_mod_reg_u16, 
	// 68
	in_IMUL_d_rm_mod_reg_u16, in_IMUL_d_rm_mod_reg_u16, in_IMUL_d_rm_mod_reg_u16, in_IMUL_d_rm_mod_reg_u16, in_IMUL_d_rm_mod_reg_u16, in_IMUL_d_rm_mod_reg_u16, in_IMUL_d_rm_mod_reg_u16, in_IMUL_d_rm_mod_reg_u16, 
	// 70
	in_DIV_d_rm_mod_reg_u16, in_DIV_d_rm_mod_reg_u16, in_DIV_d_rm_mod_reg_u16, in_DIV_d_rm_mod_reg_u16, in_DIV_d_rm_mod_reg_u16, in_DIV_d_rm_mod_reg_u16, in_DIV_d_rm_mod_reg_u16, in_DIV_d_rm_mod_reg_u16, 
	// 78
	in_IDIV_d_rm_mod_reg_u16, in_IDIV_d_rm_mod_reg_u16, in_IDIV_d_rm_mod_reg_u16, in_IDIV_d_rm_mod_reg_u16, in_IDIV_d_rm_mod_reg_u16, in_IDIV_d_rm_mod_reg_u16, in_IDIV_d_rm_mod_reg_u16, in_IDIV_d_rm_mod_reg_u16, 
	// 80
	in_TEST_d_imm_u16, in_TEST_d_imm_u16, in_TEST_d_imm_u16, in_TEST_d_imm_u16, in_TEST_d_imm_u16, in_TEST_d_imm_u16, in_TEST_d_imm_u16, in_TEST_d_imm_u16, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_NOT_d_rm_mod_reg_u16, in_NOT_d_rm_mod_reg_u16, in_NOT_d_rm_mod_reg_u16, in_NOT_d_rm_mod_reg_u16, in_NOT_d_rm_mod_reg_u16, in_NOT_d_rm_mod_reg_u16, in_NOT_d_rm_mod_reg_u16, in_NOT_d_rm_mod_reg_u16, 
	// 98
	in_NEG_d_rm_mod_reg_u16, in_NEG_d_rm_mod_reg_u16, in_NEG_d_rm_mod_reg_u16, in_NEG_d_rm_mod_reg_u16, in_NEG_d_rm_mod_reg_u16, in_NEG_d_rm_mod_reg_u16, in_NEG_d_rm_mod_reg_u16, in_NEG_d_rm_mod_reg_u16, 
	// A0
	in_MUL_d_rm_mod_reg_u16, in_MUL_d_rm_mod_reg_u16, in_MUL_d_rm_mod_reg_u16, in_MUL_d_rm_mod_reg_u16, in_MUL_d_rm_mod_reg_u16, in_MUL_d_rm_mod_reg_u16, in_MUL_d_rm_mod_reg_u16, in_MUL_d_rm_mod_reg_u16, 
	// A8
	in_IMUL_d_rm_mod_reg_u16, in_IMUL_d_rm_mod_reg_u16, in_IMUL_d_rm_mod_reg_u16, in_IMUL_d_rm_mod_reg_u16, in_IMUL_d_rm_mod_reg_u16, in_IMUL_d_rm_mod_reg_u16, in_IMUL_d_rm_mod_reg_u16, in_IMUL_d_rm_mod_reg_u16, 
	// B0
	in_DIV_d_rm_mod_reg_u16, in_DIV_d_rm_mod_reg_u16, in_DIV_d_rm_mod_reg_u16, in_DIV_d_rm_mod_reg_u16, in_DIV_d_rm_mod_reg_u16, in_DIV_d_rm_mod_reg_u16, in_DIV_d_rm_mod_reg_u16, in_DIV_d_rm_mod_reg_u16, 
	// B8
	in_IDIV_d_rm_mod_reg_u16, in_IDIV_d_rm_mod_reg_u16, in_IDIV_d_rm_mod_reg_u16, in_IDIV_d_rm_mod_reg_u16, in_IDIV_d_rm_mod_reg_u16, in_IDIV_d_rm_mod_reg_u16, in_IDIV_d_rm_mod_reg_u16, in_IDIV_d_rm_mod_reg_u16, 
	// C0
	in_TEST_d_imm_u16, in_TEST_d_imm_u16, in_TEST_d_imm_u16, in_TEST_d_imm_u16, in_TEST_d_imm_u16, in_TEST_d_imm_u16, in_TEST_d_imm_u16, in_TEST_d_imm_u16, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_NOT_d_rm_mod_reg_u16, in_NOT_d_rm_mod_reg_u16, in_NOT_d_rm_mod_reg_u16, in_NOT_d_rm_mod_reg_u16, in_NOT_d_rm_mod_reg_u16, in_NOT_d_rm_mod_reg_u16, in_NOT_d_rm_mod_reg_u16, in_NOT_d_rm_mod_reg_u16, 
	// D8
	in_NEG_d_rm_mod_reg_u16, in_NEG_d_rm_mod_reg_u16, in_NEG_d_rm_mod_reg_u16, in_NEG_d_rm_mod_reg_u16, in_NEG_d_rm_mod_reg_u16, in_NEG_d_rm_mod_reg_u16, in_NEG_d_rm_mod_reg_u16, in_NEG_d_rm_mod_reg_u16, 
	// E0
	in_MUL_d_rm_mod_reg_u16, in_MUL_d_rm_mod_reg_u16, in_MUL_d_rm_mod_reg_u16, in_MUL_d_rm_mod_reg_u16, in_MUL_d_rm_mod_reg_u16, in_MUL_d_rm_mod_reg_u16, in_MUL_d_rm_mod_reg_u16, in_MUL_d_rm_mod_reg_u16, 
	// E8
	in_IMUL_d_rm_mod_reg_u16, in_IMUL_d_rm_mod_reg_u16, in_IMUL_d_rm_mod_reg_u16, in_IMUL_d_rm_mod_reg_u16, in_IMUL_d_rm_mod_reg_u16, in_IMUL_d_rm_mod_reg_u16, in_IMUL_d_rm_mod_reg_u16, in_IMUL_d_rm_mod_reg_u16, 
	// F0
	in_DIV_d_rm_mod_reg_u16, in_DIV_d_rm_mod_reg_u16, in_DIV_d_rm_mod_reg_u16, in_DIV_d_rm_mod_reg_u16, in_DIV_d_rm_mod_reg_u16, in_DIV_d_rm_mod_reg_u16, in_DIV_d_rm_mod_reg_u16, in_DIV_d_rm_mod_reg_u16, 
	// F8
	in_IDIV_d_rm_mod_reg_u16, in_IDIV_d_rm_mod_reg_u16, in_IDIV_d_rm_mod_reg_u16, in_IDIV_d_rm_mod_reg_u16, in_IDIV_d_rm_mod_reg_u16, in_IDIV_d_rm_mod_reg_u16, in_IDIV_d_rm_mod_reg_u16, in_IDIV_d_rm_mod_reg_u16, 
};
const OpState CpuRunnerX86::table_st_d_d_F7[] = {
	// 00
	in_TEST_d_imm_u32, in_TEST_d_imm_u32, in_TEST_d_imm_u32, in_TEST_d_imm_u32, in_TEST_d_imm_u32, in_TEST_d_imm_u32, in_TEST_d_imm_u32, in_TEST_d_imm_u32, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_NOT_d_rm_mod_reg_u32, in_NOT_d_rm_mod_reg_u32, in_NOT_d_rm_mod_reg_u32, in_NOT_d_rm_mod_reg_u32, in_NOT_d_rm_mod_reg_u32, in_NOT_d_rm_mod_reg_u32, in_NOT_d_rm_mod_reg_u32, in_NOT_d_rm_mod_reg_u32, 
	// 18
	in_NEG_d_rm_mod_reg_u32, in_NEG_d_rm_mod_reg_u32, in_NEG_d_rm_mod_reg_u32, in_NEG_d_rm_mod_reg_u32, in_NEG_d_rm_mod_reg_u32, in_NEG_d_rm_mod_reg_u32, in_NEG_d_rm_mod_reg_u32, in_NEG_d_rm_mod_reg_u32, 
	// 20
	in_MUL_d_rm_mod_reg_u32, in_MUL_d_rm_mod_reg_u32, in_MUL_d_rm_mod_reg_u32, in_MUL_d_rm_mod_reg_u32, in_MUL_d_rm_mod_reg_u32, in_MUL_d_rm_mod_reg_u32, in_MUL_d_rm_mod_reg_u32, in_MUL_d_rm_mod_reg_u32, 
	// 28
	in_IMUL_d_rm_mod_reg_u16, in_IMUL_d_rm_mod_reg_u16, in_IMUL_d_rm_mod_reg_u16, in_IMUL_d_rm_mod_reg_u16, in_IMUL_d_rm_mod_reg_u16, in_IMUL_d_rm_mod_reg_u16, in_IMUL_d_rm_mod_reg_u16, in_IMUL_d_rm_mod_reg_u16, 
	// 30
	in_DIV_d_rm_mod_reg_u16, in_DIV_d_rm_mod_reg_u16, in_DIV_d_rm_mod_reg_u16, in_DIV_d_rm_mod_reg_u16, in_DIV_d_rm_mod_reg_u16, in_DIV_d_rm_mod_reg_u16, in_DIV_d_rm_mod_reg_u16, in_DIV_d_rm_mod_reg_u16, 
	// 38
	in_IDIV_d_rm_mod_reg_u16, in_IDIV_d_rm_mod_reg_u16, in_IDIV_d_rm_mod_reg_u16, in_IDIV_d_rm_mod_reg_u16, in_IDIV_d_rm_mod_reg_u16, in_IDIV_d_rm_mod_reg_u16, in_IDIV_d_rm_mod_reg_u16, in_IDIV_d_rm_mod_reg_u16, 
	// 40
	in_TEST_d_imm_u32, in_TEST_d_imm_u32, in_TEST_d_imm_u32, in_TEST_d_imm_u32, in_TEST_d_imm_u32, in_TEST_d_imm_u32, in_TEST_d_imm_u32, in_TEST_d_imm_u32, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_NOT_d_rm_mod_reg_u32, in_NOT_d_rm_mod_reg_u32, in_NOT_d_rm_mod_reg_u32, in_NOT_d_rm_mod_reg_u32, in_NOT_d_rm_mod_reg_u32, in_NOT_d_rm_mod_reg_u32, in_NOT_d_rm_mod_reg_u32, in_NOT_d_rm_mod_reg_u32, 
	// 58
	in_NEG_d_rm_mod_reg_u32, in_NEG_d_rm_mod_reg_u32, in_NEG_d_rm_mod_reg_u32, in_NEG_d_rm_mod_reg_u32, in_NEG_d_rm_mod_reg_u32, in_NEG_d_rm_mod_reg_u32, in_NEG_d_rm_mod_reg_u32, in_NEG_d_rm_mod_reg_u32, 
	// 60
	in_MUL_d_rm_mod_reg_u32, in_MUL_d_rm_mod_reg_u32, in_MUL_d_rm_mod_reg_u32, in_MUL_d_rm_mod_reg_u32, in_MUL_d_rm_mod_reg_u32, in_MUL_d_rm_mod_reg_u32, in_MUL_d_rm_mod_reg_u32, in_MUL_d_rm_mod_reg_u32, 
	// 68
	in_IMUL_d_rm_mod_reg_u16, in_IMUL_d_rm_mod_reg_u16, in_IMUL_d_rm_mod_reg_u16, in_IMUL_d_rm_mod_reg_u16, in_IMUL_d_rm_mod_reg_u16, in_IMUL_d_rm_mod_reg_u16, in_IMUL_d_rm_mod_reg_u16, in_IMUL_d_rm_mod_reg_u16, 
	// 70
	in_DIV_d_rm_mod_reg_u16, in_DIV_d_rm_mod_reg_u16, in_DIV_d_rm_mod_reg_u16, in_DIV_d_rm_mod_reg_u16, in_DIV_d_rm_mod_reg_u16, in_DIV_d_rm_mod_reg_u16, in_DIV_d_rm_mod_reg_u16, in_DIV_d_rm_mod_reg_u16, 
	// 78
	in_IDIV_d_rm_mod_reg_u16, in_IDIV_d_rm_mod_reg_u16, in_IDIV_d_rm_mod_reg_u16, in_IDIV_d_rm_mod_reg_u16, in_IDIV_d_rm_mod_reg_u16, in_IDIV_d_rm_mod_reg_u16, in_IDIV_d_rm_mod_reg_u16, in_IDIV_d_rm_mod_reg_u16, 
	// 80
	in_TEST_d_imm_u32, in_TEST_d_imm_u32, in_TEST_d_imm_u32, in_TEST_d_imm_u32, in_TEST_d_imm_u32, in_TEST_d_imm_u32, in_TEST_d_imm_u32, in_TEST_d_imm_u32, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_NOT_d_rm_mod_reg_u32, in_NOT_d_rm_mod_reg_u32, in_NOT_d_rm_mod_reg_u32, in_NOT_d_rm_mod_reg_u32, in_NOT_d_rm_mod_reg_u32, in_NOT_d_rm_mod_reg_u32, in_NOT_d_rm_mod_reg_u32, in_NOT_d_rm_mod_reg_u32, 
	// 98
	in_NEG_d_rm_mod_reg_u32, in_NEG_d_rm_mod_reg_u32, in_NEG_d_rm_mod_reg_u32, in_NEG_d_rm_mod_reg_u32, in_NEG_d_rm_mod_reg_u32, in_NEG_d_rm_mod_reg_u32, in_NEG_d_rm_mod_reg_u32, in_NEG_d_rm_mod_reg_u32, 
	// A0
	in_MUL_d_rm_mod_reg_u32, in_MUL_d_rm_mod_reg_u32, in_MUL_d_rm_mod_reg_u32, in_MUL_d_rm_mod_reg_u32, in_MUL_d_rm_mod_reg_u32, in_MUL_d_rm_mod_reg_u32, in_MUL_d_rm_mod_reg_u32, in_MUL_d_rm_mod_reg_u32, 
	// A8
	in_IMUL_d_rm_mod_reg_u16, in_IMUL_d_rm_mod_reg_u16, in_IMUL_d_rm_mod_reg_u16, in_IMUL_d_rm_mod_reg_u16, in_IMUL_d_rm_mod_reg_u16, in_IMUL_d_rm_mod_reg_u16, in_IMUL_d_rm_mod_reg_u16, in_IMUL_d_rm_mod_reg_u16, 
	// B0
	in_DIV_d_rm_mod_reg_u16, in_DIV_d_rm_mod_reg_u16, in_DIV_d_rm_mod_reg_u16, in_DIV_d_rm_mod_reg_u16, in_DIV_d_rm_mod_reg_u16, in_DIV_d_rm_mod_reg_u16, in_DIV_d_rm_mod_reg_u16, in_DIV_d_rm_mod_reg_u16, 
	// B8
	in_IDIV_d_rm_mod_reg_u16, in_IDIV_d_rm_mod_reg_u16, in_IDIV_d_rm_mod_reg_u16, in_IDIV_d_rm_mod_reg_u16, in_IDIV_d_rm_mod_reg_u16, in_IDIV_d_rm_mod_reg_u16, in_IDIV_d_rm_mod_reg_u16, in_IDIV_d_rm_mod_reg_u16, 
	// C0
	in_TEST_d_imm_u32, in_TEST_d_imm_u32, in_TEST_d_imm_u32, in_TEST_d_imm_u32, in_TEST_d_imm_u32, in_TEST_d_imm_u32, in_TEST_d_imm_u32, in_TEST_d_imm_u32, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_NOT_d_rm_mod_reg_u32, in_NOT_d_rm_mod_reg_u32, in_NOT_d_rm_mod_reg_u32, in_NOT_d_rm_mod_reg_u32, in_NOT_d_rm_mod_reg_u32, in_NOT_d_rm_mod_reg_u32, in_NOT_d_rm_mod_reg_u32, in_NOT_d_rm_mod_reg_u32, 
	// D8
	in_NEG_d_rm_mod_reg_u32, in_NEG_d_rm_mod_reg_u32, in_NEG_d_rm_mod_reg_u32, in_NEG_d_rm_mod_reg_u32, in_NEG_d_rm_mod_reg_u32, in_NEG_d_rm_mod_reg_u32, in_NEG_d_rm_mod_reg_u32, in_NEG_d_rm_mod_reg_u32, 
	// E0
	in_MUL_d_rm_mod_reg_u32, in_MUL_d_rm_mod_reg_u32, in_MUL_d_rm_mod_reg_u32, in_MUL_d_rm_mod_reg_u32, in_MUL_d_rm_mod_reg_u32, in_MUL_d_rm_mod_reg_u32, in_MUL_d_rm_mod_reg_u32, in_MUL_d_rm_mod_reg_u32, 
	// E8
	in_IMUL_d_rm_mod_reg_u16, in_IMUL_d_rm_mod_reg_u16, in_IMUL_d_rm_mod_reg_u16, in_IMUL_d_rm_mod_reg_u16, in_IMUL_d_rm_mod_reg_u16, in_IMUL_d_rm_mod_reg_u16, in_IMUL_d_rm_mod_reg_u16, in_IMUL_d_rm_mod_reg_u16, 
	// F0
	in_DIV_d_rm_mod_reg_u16, in_DIV_d_rm_mod_reg_u16, in_DIV_d_rm_mod_reg_u16, in_DIV_d_rm_mod_reg_u16, in_DIV_d_rm_mod_reg_u16, in_DIV_d_rm_mod_reg_u16, in_DIV_d_rm_mod_reg_u16, in_DIV_d_rm_mod_reg_u16, 
	// F8
	in_IDIV_d_rm_mod_reg_u16, in_IDIV_d_rm_mod_reg_u16, in_IDIV_d_rm_mod_reg_u16, in_IDIV_d_rm_mod_reg_u16, in_IDIV_d_rm_mod_reg_u16, in_IDIV_d_rm_mod_reg_u16, in_IDIV_d_rm_mod_reg_u16, in_IDIV_d_rm_mod_reg_u16, 
};
const OpState CpuRunnerX86::table_st_w_w_FE[] = {
	// 00
	in_INC_w_rm_mod_reg_u8, in_INC_w_rm_mod_reg_u8, in_INC_w_rm_mod_reg_u8, in_INC_w_rm_mod_reg_u8, in_INC_w_rm_mod_reg_u8, in_INC_w_rm_mod_reg_u8, in_INC_w_rm_mod_reg_u8, in_INC_w_rm_mod_reg_u8, 
	// 08
	in_DEC_w_rm_mod_reg_u8, in_DEC_w_rm_mod_reg_u8, in_DEC_w_rm_mod_reg_u8, in_DEC_w_rm_mod_reg_u8, in_DEC_w_rm_mod_reg_u8, in_DEC_w_rm_mod_reg_u8, in_DEC_w_rm_mod_reg_u8, in_DEC_w_rm_mod_reg_u8, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_INC_w_rm_mod_reg_u8, in_INC_w_rm_mod_reg_u8, in_INC_w_rm_mod_reg_u8, in_INC_w_rm_mod_reg_u8, in_INC_w_rm_mod_reg_u8, in_INC_w_rm_mod_reg_u8, in_INC_w_rm_mod_reg_u8, in_INC_w_rm_mod_reg_u8, 
	// 48
	in_DEC_w_rm_mod_reg_u8, in_DEC_w_rm_mod_reg_u8, in_DEC_w_rm_mod_reg_u8, in_DEC_w_rm_mod_reg_u8, in_DEC_w_rm_mod_reg_u8, in_DEC_w_rm_mod_reg_u8, in_DEC_w_rm_mod_reg_u8, in_DEC_w_rm_mod_reg_u8, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_INC_w_rm_mod_reg_u8, in_INC_w_rm_mod_reg_u8, in_INC_w_rm_mod_reg_u8, in_INC_w_rm_mod_reg_u8, in_INC_w_rm_mod_reg_u8, in_INC_w_rm_mod_reg_u8, in_INC_w_rm_mod_reg_u8, in_INC_w_rm_mod_reg_u8, 
	// 88
	in_DEC_w_rm_mod_reg_u8, in_DEC_w_rm_mod_reg_u8, in_DEC_w_rm_mod_reg_u8, in_DEC_w_rm_mod_reg_u8, in_DEC_w_rm_mod_reg_u8, in_DEC_w_rm_mod_reg_u8, in_DEC_w_rm_mod_reg_u8, in_DEC_w_rm_mod_reg_u8, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_INC_w_rm_mod_reg_u8, in_INC_w_rm_mod_reg_u8, in_INC_w_rm_mod_reg_u8, in_INC_w_rm_mod_reg_u8, in_INC_w_rm_mod_reg_u8, in_INC_w_rm_mod_reg_u8, in_INC_w_rm_mod_reg_u8, in_INC_w_rm_mod_reg_u8, 
	// C8
	in_DEC_w_rm_mod_reg_u8, in_DEC_w_rm_mod_reg_u8, in_DEC_w_rm_mod_reg_u8, in_DEC_w_rm_mod_reg_u8, in_DEC_w_rm_mod_reg_u8, in_DEC_w_rm_mod_reg_u8, in_DEC_w_rm_mod_reg_u8, in_DEC_w_rm_mod_reg_u8, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_st_w_d_FE[] = {
	// 00
	in_INC_w_rm_mod_reg_u8, in_INC_w_rm_mod_reg_u8, in_INC_w_rm_mod_reg_u8, in_INC_w_rm_mod_reg_u8, in_INC_w_rm_mod_reg_u8, in_INC_w_rm_mod_reg_u8, in_INC_w_rm_mod_reg_u8, in_INC_w_rm_mod_reg_u8, 
	// 08
	in_DEC_w_rm_mod_reg_u8, in_DEC_w_rm_mod_reg_u8, in_DEC_w_rm_mod_reg_u8, in_DEC_w_rm_mod_reg_u8, in_DEC_w_rm_mod_reg_u8, in_DEC_w_rm_mod_reg_u8, in_DEC_w_rm_mod_reg_u8, in_DEC_w_rm_mod_reg_u8, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_INC_w_rm_mod_reg_u8, in_INC_w_rm_mod_reg_u8, in_INC_w_rm_mod_reg_u8, in_INC_w_rm_mod_reg_u8, in_INC_w_rm_mod_reg_u8, in_INC_w_rm_mod_reg_u8, in_INC_w_rm_mod_reg_u8, in_INC_w_rm_mod_reg_u8, 
	// 48
	in_DEC_w_rm_mod_reg_u8, in_DEC_w_rm_mod_reg_u8, in_DEC_w_rm_mod_reg_u8, in_DEC_w_rm_mod_reg_u8, in_DEC_w_rm_mod_reg_u8, in_DEC_w_rm_mod_reg_u8, in_DEC_w_rm_mod_reg_u8, in_DEC_w_rm_mod_reg_u8, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_INC_w_rm_mod_reg_u8, in_INC_w_rm_mod_reg_u8, in_INC_w_rm_mod_reg_u8, in_INC_w_rm_mod_reg_u8, in_INC_w_rm_mod_reg_u8, in_INC_w_rm_mod_reg_u8, in_INC_w_rm_mod_reg_u8, in_INC_w_rm_mod_reg_u8, 
	// 88
	in_DEC_w_rm_mod_reg_u8, in_DEC_w_rm_mod_reg_u8, in_DEC_w_rm_mod_reg_u8, in_DEC_w_rm_mod_reg_u8, in_DEC_w_rm_mod_reg_u8, in_DEC_w_rm_mod_reg_u8, in_DEC_w_rm_mod_reg_u8, in_DEC_w_rm_mod_reg_u8, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_INC_w_rm_mod_reg_u8, in_INC_w_rm_mod_reg_u8, in_INC_w_rm_mod_reg_u8, in_INC_w_rm_mod_reg_u8, in_INC_w_rm_mod_reg_u8, in_INC_w_rm_mod_reg_u8, in_INC_w_rm_mod_reg_u8, in_INC_w_rm_mod_reg_u8, 
	// C8
	in_DEC_w_rm_mod_reg_u8, in_DEC_w_rm_mod_reg_u8, in_DEC_w_rm_mod_reg_u8, in_DEC_w_rm_mod_reg_u8, in_DEC_w_rm_mod_reg_u8, in_DEC_w_rm_mod_reg_u8, in_DEC_w_rm_mod_reg_u8, in_DEC_w_rm_mod_reg_u8, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_st_d_w_FE[] = {
	// 00
	in_INC_d_rm_mod_reg_u8, in_INC_d_rm_mod_reg_u8, in_INC_d_rm_mod_reg_u8, in_INC_d_rm_mod_reg_u8, in_INC_d_rm_mod_reg_u8, in_INC_d_rm_mod_reg_u8, in_INC_d_rm_mod_reg_u8, in_INC_d_rm_mod_reg_u8, 
	// 08
	in_DEC_d_rm_mod_reg_u8, in_DEC_d_rm_mod_reg_u8, in_DEC_d_rm_mod_reg_u8, in_DEC_d_rm_mod_reg_u8, in_DEC_d_rm_mod_reg_u8, in_DEC_d_rm_mod_reg_u8, in_DEC_d_rm_mod_reg_u8, in_DEC_d_rm_mod_reg_u8, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_INC_d_rm_mod_reg_u8, in_INC_d_rm_mod_reg_u8, in_INC_d_rm_mod_reg_u8, in_INC_d_rm_mod_reg_u8, in_INC_d_rm_mod_reg_u8, in_INC_d_rm_mod_reg_u8, in_INC_d_rm_mod_reg_u8, in_INC_d_rm_mod_reg_u8, 
	// 48
	in_DEC_d_rm_mod_reg_u8, in_DEC_d_rm_mod_reg_u8, in_DEC_d_rm_mod_reg_u8, in_DEC_d_rm_mod_reg_u8, in_DEC_d_rm_mod_reg_u8, in_DEC_d_rm_mod_reg_u8, in_DEC_d_rm_mod_reg_u8, in_DEC_d_rm_mod_reg_u8, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_INC_d_rm_mod_reg_u8, in_INC_d_rm_mod_reg_u8, in_INC_d_rm_mod_reg_u8, in_INC_d_rm_mod_reg_u8, in_INC_d_rm_mod_reg_u8, in_INC_d_rm_mod_reg_u8, in_INC_d_rm_mod_reg_u8, in_INC_d_rm_mod_reg_u8, 
	// 88
	in_DEC_d_rm_mod_reg_u8, in_DEC_d_rm_mod_reg_u8, in_DEC_d_rm_mod_reg_u8, in_DEC_d_rm_mod_reg_u8, in_DEC_d_rm_mod_reg_u8, in_DEC_d_rm_mod_reg_u8, in_DEC_d_rm_mod_reg_u8, in_DEC_d_rm_mod_reg_u8, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_INC_d_rm_mod_reg_u8, in_INC_d_rm_mod_reg_u8, in_INC_d_rm_mod_reg_u8, in_INC_d_rm_mod_reg_u8, in_INC_d_rm_mod_reg_u8, in_INC_d_rm_mod_reg_u8, in_INC_d_rm_mod_reg_u8, in_INC_d_rm_mod_reg_u8, 
	// C8
	in_DEC_d_rm_mod_reg_u8, in_DEC_d_rm_mod_reg_u8, in_DEC_d_rm_mod_reg_u8, in_DEC_d_rm_mod_reg_u8, in_DEC_d_rm_mod_reg_u8, in_DEC_d_rm_mod_reg_u8, in_DEC_d_rm_mod_reg_u8, in_DEC_d_rm_mod_reg_u8, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_st_d_d_FE[] = {
	// 00
	in_INC_d_rm_mod_reg_u8, in_INC_d_rm_mod_reg_u8, in_INC_d_rm_mod_reg_u8, in_INC_d_rm_mod_reg_u8, in_INC_d_rm_mod_reg_u8, in_INC_d_rm_mod_reg_u8, in_INC_d_rm_mod_reg_u8, in_INC_d_rm_mod_reg_u8, 
	// 08
	in_DEC_d_rm_mod_reg_u8, in_DEC_d_rm_mod_reg_u8, in_DEC_d_rm_mod_reg_u8, in_DEC_d_rm_mod_reg_u8, in_DEC_d_rm_mod_reg_u8, in_DEC_d_rm_mod_reg_u8, in_DEC_d_rm_mod_reg_u8, in_DEC_d_rm_mod_reg_u8, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_INC_d_rm_mod_reg_u8, in_INC_d_rm_mod_reg_u8, in_INC_d_rm_mod_reg_u8, in_INC_d_rm_mod_reg_u8, in_INC_d_rm_mod_reg_u8, in_INC_d_rm_mod_reg_u8, in_INC_d_rm_mod_reg_u8, in_INC_d_rm_mod_reg_u8, 
	// 48
	in_DEC_d_rm_mod_reg_u8, in_DEC_d_rm_mod_reg_u8, in_DEC_d_rm_mod_reg_u8, in_DEC_d_rm_mod_reg_u8, in_DEC_d_rm_mod_reg_u8, in_DEC_d_rm_mod_reg_u8, in_DEC_d_rm_mod_reg_u8, in_DEC_d_rm_mod_reg_u8, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_INC_d_rm_mod_reg_u8, in_INC_d_rm_mod_reg_u8, in_INC_d_rm_mod_reg_u8, in_INC_d_rm_mod_reg_u8, in_INC_d_rm_mod_reg_u8, in_INC_d_rm_mod_reg_u8, in_INC_d_rm_mod_reg_u8, in_INC_d_rm_mod_reg_u8, 
	// 88
	in_DEC_d_rm_mod_reg_u8, in_DEC_d_rm_mod_reg_u8, in_DEC_d_rm_mod_reg_u8, in_DEC_d_rm_mod_reg_u8, in_DEC_d_rm_mod_reg_u8, in_DEC_d_rm_mod_reg_u8, in_DEC_d_rm_mod_reg_u8, in_DEC_d_rm_mod_reg_u8, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_INC_d_rm_mod_reg_u8, in_INC_d_rm_mod_reg_u8, in_INC_d_rm_mod_reg_u8, in_INC_d_rm_mod_reg_u8, in_INC_d_rm_mod_reg_u8, in_INC_d_rm_mod_reg_u8, in_INC_d_rm_mod_reg_u8, in_INC_d_rm_mod_reg_u8, 
	// C8
	in_DEC_d_rm_mod_reg_u8, in_DEC_d_rm_mod_reg_u8, in_DEC_d_rm_mod_reg_u8, in_DEC_d_rm_mod_reg_u8, in_DEC_d_rm_mod_reg_u8, in_DEC_d_rm_mod_reg_u8, in_DEC_d_rm_mod_reg_u8, in_DEC_d_rm_mod_reg_u8, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_st_w_w_FF[] = {
	// 00
	in_INC_w_rm_mod_reg_u16, in_INC_w_rm_mod_reg_u16, in_INC_w_rm_mod_reg_u16, in_INC_w_rm_mod_reg_u16, in_INC_w_rm_mod_reg_u16, in_INC_w_rm_mod_reg_u16, in_INC_w_rm_mod_reg_u16, in_INC_w_rm_mod_reg_u16, 
	// 08
	in_DEC_w_rm_mod_reg_u16, in_DEC_w_rm_mod_reg_u16, in_DEC_w_rm_mod_reg_u16, in_DEC_w_rm_mod_reg_u16, in_DEC_w_rm_mod_reg_u16, in_DEC_w_rm_mod_reg_u16, in_DEC_w_rm_mod_reg_u16, in_DEC_w_rm_mod_reg_u16, 
	// 10
	in_CALL_w_rm_mod_reg_u16, in_CALL_w_rm_mod_reg_u16, in_CALL_w_rm_mod_reg_u16, in_CALL_w_rm_mod_reg_u16, in_CALL_w_rm_mod_reg_u16, in_CALL_w_rm_mod_reg_u16, in_CALL_w_rm_mod_reg_u16, in_CALL_w_rm_mod_reg_u16, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_JMP_w_rm_mod_reg_u16, in_JMP_w_rm_mod_reg_u16, in_JMP_w_rm_mod_reg_u16, in_JMP_w_rm_mod_reg_u16, in_JMP_w_rm_mod_reg_u16, in_JMP_w_rm_mod_reg_u16, in_JMP_w_rm_mod_reg_u16, in_JMP_w_rm_mod_reg_u16, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_PUSH_w_rm_mod_reg_u16, in_PUSH_w_rm_mod_reg_u16, in_PUSH_w_rm_mod_reg_u16, in_PUSH_w_rm_mod_reg_u16, in_PUSH_w_rm_mod_reg_u16, in_PUSH_w_rm_mod_reg_u16, in_PUSH_w_rm_mod_reg_u16, in_PUSH_w_rm_mod_reg_u16, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_INC_w_rm_mod_reg_u16, in_INC_w_rm_mod_reg_u16, in_INC_w_rm_mod_reg_u16, in_INC_w_rm_mod_reg_u16, in_INC_w_rm_mod_reg_u16, in_INC_w_rm_mod_reg_u16, in_INC_w_rm_mod_reg_u16, in_INC_w_rm_mod_reg_u16, 
	// 48
	in_DEC_w_rm_mod_reg_u16, in_DEC_w_rm_mod_reg_u16, in_DEC_w_rm_mod_reg_u16, in_DEC_w_rm_mod_reg_u16, in_DEC_w_rm_mod_reg_u16, in_DEC_w_rm_mod_reg_u16, in_DEC_w_rm_mod_reg_u16, in_DEC_w_rm_mod_reg_u16, 
	// 50
	in_CALL_w_rm_mod_reg_u16, in_CALL_w_rm_mod_reg_u16, in_CALL_w_rm_mod_reg_u16, in_CALL_w_rm_mod_reg_u16, in_CALL_w_rm_mod_reg_u16, in_CALL_w_rm_mod_reg_u16, in_CALL_w_rm_mod_reg_u16, in_CALL_w_rm_mod_reg_u16, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_JMP_w_rm_mod_reg_u16, in_JMP_w_rm_mod_reg_u16, in_JMP_w_rm_mod_reg_u16, in_JMP_w_rm_mod_reg_u16, in_JMP_w_rm_mod_reg_u16, in_JMP_w_rm_mod_reg_u16, in_JMP_w_rm_mod_reg_u16, in_JMP_w_rm_mod_reg_u16, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_PUSH_w_rm_mod_reg_u16, in_PUSH_w_rm_mod_reg_u16, in_PUSH_w_rm_mod_reg_u16, in_PUSH_w_rm_mod_reg_u16, in_PUSH_w_rm_mod_reg_u16, in_PUSH_w_rm_mod_reg_u16, in_PUSH_w_rm_mod_reg_u16, in_PUSH_w_rm_mod_reg_u16, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_INC_w_rm_mod_reg_u16, in_INC_w_rm_mod_reg_u16, in_INC_w_rm_mod_reg_u16, in_INC_w_rm_mod_reg_u16, in_INC_w_rm_mod_reg_u16, in_INC_w_rm_mod_reg_u16, in_INC_w_rm_mod_reg_u16, in_INC_w_rm_mod_reg_u16, 
	// 88
	in_DEC_w_rm_mod_reg_u16, in_DEC_w_rm_mod_reg_u16, in_DEC_w_rm_mod_reg_u16, in_DEC_w_rm_mod_reg_u16, in_DEC_w_rm_mod_reg_u16, in_DEC_w_rm_mod_reg_u16, in_DEC_w_rm_mod_reg_u16, in_DEC_w_rm_mod_reg_u16, 
	// 90
	in_CALL_w_rm_mod_reg_u16, in_CALL_w_rm_mod_reg_u16, in_CALL_w_rm_mod_reg_u16, in_CALL_w_rm_mod_reg_u16, in_CALL_w_rm_mod_reg_u16, in_CALL_w_rm_mod_reg_u16, in_CALL_w_rm_mod_reg_u16, in_CALL_w_rm_mod_reg_u16, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_JMP_w_rm_mod_reg_u16, in_JMP_w_rm_mod_reg_u16, in_JMP_w_rm_mod_reg_u16, in_JMP_w_rm_mod_reg_u16, in_JMP_w_rm_mod_reg_u16, in_JMP_w_rm_mod_reg_u16, in_JMP_w_rm_mod_reg_u16, in_JMP_w_rm_mod_reg_u16, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_PUSH_w_rm_mod_reg_u16, in_PUSH_w_rm_mod_reg_u16, in_PUSH_w_rm_mod_reg_u16, in_PUSH_w_rm_mod_reg_u16, in_PUSH_w_rm_mod_reg_u16, in_PUSH_w_rm_mod_reg_u16, in_PUSH_w_rm_mod_reg_u16, in_PUSH_w_rm_mod_reg_u16, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_INC_w_rm_mod_reg_u16, in_INC_w_rm_mod_reg_u16, in_INC_w_rm_mod_reg_u16, in_INC_w_rm_mod_reg_u16, in_INC_w_rm_mod_reg_u16, in_INC_w_rm_mod_reg_u16, in_INC_w_rm_mod_reg_u16, in_INC_w_rm_mod_reg_u16, 
	// C8
	in_DEC_w_rm_mod_reg_u16, in_DEC_w_rm_mod_reg_u16, in_DEC_w_rm_mod_reg_u16, in_DEC_w_rm_mod_reg_u16, in_DEC_w_rm_mod_reg_u16, in_DEC_w_rm_mod_reg_u16, in_DEC_w_rm_mod_reg_u16, in_DEC_w_rm_mod_reg_u16, 
	// D0
	in_CALL_w_rm_mod_reg_u16, in_CALL_w_rm_mod_reg_u16, in_CALL_w_rm_mod_reg_u16, in_CALL_w_rm_mod_reg_u16, in_CALL_w_rm_mod_reg_u16, in_CALL_w_rm_mod_reg_u16, in_CALL_w_rm_mod_reg_u16, in_CALL_w_rm_mod_reg_u16, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_JMP_w_rm_mod_reg_u16, in_JMP_w_rm_mod_reg_u16, in_JMP_w_rm_mod_reg_u16, in_JMP_w_rm_mod_reg_u16, in_JMP_w_rm_mod_reg_u16, in_JMP_w_rm_mod_reg_u16, in_JMP_w_rm_mod_reg_u16, in_JMP_w_rm_mod_reg_u16, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_PUSH_w_rm_mod_reg_u16, in_PUSH_w_rm_mod_reg_u16, in_PUSH_w_rm_mod_reg_u16, in_PUSH_w_rm_mod_reg_u16, in_PUSH_w_rm_mod_reg_u16, in_PUSH_w_rm_mod_reg_u16, in_PUSH_w_rm_mod_reg_u16, in_PUSH_w_rm_mod_reg_u16, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_st_w_d_FF[] = {
	// 00
	in_INC_w_rm_mod_reg_u32, in_INC_w_rm_mod_reg_u32, in_INC_w_rm_mod_reg_u32, in_INC_w_rm_mod_reg_u32, in_INC_w_rm_mod_reg_u32, in_INC_w_rm_mod_reg_u32, in_INC_w_rm_mod_reg_u32, in_INC_w_rm_mod_reg_u32, 
	// 08
	in_DEC_w_rm_mod_reg_u32, in_DEC_w_rm_mod_reg_u32, in_DEC_w_rm_mod_reg_u32, in_DEC_w_rm_mod_reg_u32, in_DEC_w_rm_mod_reg_u32, in_DEC_w_rm_mod_reg_u32, in_DEC_w_rm_mod_reg_u32, in_DEC_w_rm_mod_reg_u32, 
	// 10
	in_CALL_w_rm_mod_reg_u16, in_CALL_w_rm_mod_reg_u16, in_CALL_w_rm_mod_reg_u16, in_CALL_w_rm_mod_reg_u16, in_CALL_w_rm_mod_reg_u16, in_CALL_w_rm_mod_reg_u16, in_CALL_w_rm_mod_reg_u16, in_CALL_w_rm_mod_reg_u16, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_JMP_w_rm_mod_reg_u16, in_JMP_w_rm_mod_reg_u16, in_JMP_w_rm_mod_reg_u16, in_JMP_w_rm_mod_reg_u16, in_JMP_w_rm_mod_reg_u16, in_JMP_w_rm_mod_reg_u16, in_JMP_w_rm_mod_reg_u16, in_JMP_w_rm_mod_reg_u16, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_PUSH_w_rm_mod_reg_u16, in_PUSH_w_rm_mod_reg_u16, in_PUSH_w_rm_mod_reg_u16, in_PUSH_w_rm_mod_reg_u16, in_PUSH_w_rm_mod_reg_u16, in_PUSH_w_rm_mod_reg_u16, in_PUSH_w_rm_mod_reg_u16, in_PUSH_w_rm_mod_reg_u16, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_INC_w_rm_mod_reg_u32, in_INC_w_rm_mod_reg_u32, in_INC_w_rm_mod_reg_u32, in_INC_w_rm_mod_reg_u32, in_INC_w_rm_mod_reg_u32, in_INC_w_rm_mod_reg_u32, in_INC_w_rm_mod_reg_u32, in_INC_w_rm_mod_reg_u32, 
	// 48
	in_DEC_w_rm_mod_reg_u32, in_DEC_w_rm_mod_reg_u32, in_DEC_w_rm_mod_reg_u32, in_DEC_w_rm_mod_reg_u32, in_DEC_w_rm_mod_reg_u32, in_DEC_w_rm_mod_reg_u32, in_DEC_w_rm_mod_reg_u32, in_DEC_w_rm_mod_reg_u32, 
	// 50
	in_CALL_w_rm_mod_reg_u16, in_CALL_w_rm_mod_reg_u16, in_CALL_w_rm_mod_reg_u16, in_CALL_w_rm_mod_reg_u16, in_CALL_w_rm_mod_reg_u16, in_CALL_w_rm_mod_reg_u16, in_CALL_w_rm_mod_reg_u16, in_CALL_w_rm_mod_reg_u16, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_JMP_w_rm_mod_reg_u16, in_JMP_w_rm_mod_reg_u16, in_JMP_w_rm_mod_reg_u16, in_JMP_w_rm_mod_reg_u16, in_JMP_w_rm_mod_reg_u16, in_JMP_w_rm_mod_reg_u16, in_JMP_w_rm_mod_reg_u16, in_JMP_w_rm_mod_reg_u16, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_PUSH_w_rm_mod_reg_u16, in_PUSH_w_rm_mod_reg_u16, in_PUSH_w_rm_mod_reg_u16, in_PUSH_w_rm_mod_reg_u16, in_PUSH_w_rm_mod_reg_u16, in_PUSH_w_rm_mod_reg_u16, in_PUSH_w_rm_mod_reg_u16, in_PUSH_w_rm_mod_reg_u16, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_INC_w_rm_mod_reg_u32, in_INC_w_rm_mod_reg_u32, in_INC_w_rm_mod_reg_u32, in_INC_w_rm_mod_reg_u32, in_INC_w_rm_mod_reg_u32, in_INC_w_rm_mod_reg_u32, in_INC_w_rm_mod_reg_u32, in_INC_w_rm_mod_reg_u32, 
	// 88
	in_DEC_w_rm_mod_reg_u32, in_DEC_w_rm_mod_reg_u32, in_DEC_w_rm_mod_reg_u32, in_DEC_w_rm_mod_reg_u32, in_DEC_w_rm_mod_reg_u32, in_DEC_w_rm_mod_reg_u32, in_DEC_w_rm_mod_reg_u32, in_DEC_w_rm_mod_reg_u32, 
	// 90
	in_CALL_w_rm_mod_reg_u16, in_CALL_w_rm_mod_reg_u16, in_CALL_w_rm_mod_reg_u16, in_CALL_w_rm_mod_reg_u16, in_CALL_w_rm_mod_reg_u16, in_CALL_w_rm_mod_reg_u16, in_CALL_w_rm_mod_reg_u16, in_CALL_w_rm_mod_reg_u16, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_JMP_w_rm_mod_reg_u16, in_JMP_w_rm_mod_reg_u16, in_JMP_w_rm_mod_reg_u16, in_JMP_w_rm_mod_reg_u16, in_JMP_w_rm_mod_reg_u16, in_JMP_w_rm_mod_reg_u16, in_JMP_w_rm_mod_reg_u16, in_JMP_w_rm_mod_reg_u16, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_PUSH_w_rm_mod_reg_u16, in_PUSH_w_rm_mod_reg_u16, in_PUSH_w_rm_mod_reg_u16, in_PUSH_w_rm_mod_reg_u16, in_PUSH_w_rm_mod_reg_u16, in_PUSH_w_rm_mod_reg_u16, in_PUSH_w_rm_mod_reg_u16, in_PUSH_w_rm_mod_reg_u16, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_INC_w_rm_mod_reg_u32, in_INC_w_rm_mod_reg_u32, in_INC_w_rm_mod_reg_u32, in_INC_w_rm_mod_reg_u32, in_INC_w_rm_mod_reg_u32, in_INC_w_rm_mod_reg_u32, in_INC_w_rm_mod_reg_u32, in_INC_w_rm_mod_reg_u32, 
	// C8
	in_DEC_w_rm_mod_reg_u32, in_DEC_w_rm_mod_reg_u32, in_DEC_w_rm_mod_reg_u32, in_DEC_w_rm_mod_reg_u32, in_DEC_w_rm_mod_reg_u32, in_DEC_w_rm_mod_reg_u32, in_DEC_w_rm_mod_reg_u32, in_DEC_w_rm_mod_reg_u32, 
	// D0
	in_CALL_w_rm_mod_reg_u16, in_CALL_w_rm_mod_reg_u16, in_CALL_w_rm_mod_reg_u16, in_CALL_w_rm_mod_reg_u16, in_CALL_w_rm_mod_reg_u16, in_CALL_w_rm_mod_reg_u16, in_CALL_w_rm_mod_reg_u16, in_CALL_w_rm_mod_reg_u16, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_JMP_w_rm_mod_reg_u16, in_JMP_w_rm_mod_reg_u16, in_JMP_w_rm_mod_reg_u16, in_JMP_w_rm_mod_reg_u16, in_JMP_w_rm_mod_reg_u16, in_JMP_w_rm_mod_reg_u16, in_JMP_w_rm_mod_reg_u16, in_JMP_w_rm_mod_reg_u16, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_PUSH_w_rm_mod_reg_u16, in_PUSH_w_rm_mod_reg_u16, in_PUSH_w_rm_mod_reg_u16, in_PUSH_w_rm_mod_reg_u16, in_PUSH_w_rm_mod_reg_u16, in_PUSH_w_rm_mod_reg_u16, in_PUSH_w_rm_mod_reg_u16, in_PUSH_w_rm_mod_reg_u16, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_st_d_w_FF[] = {
	// 00
	in_INC_d_rm_mod_reg_u16, in_INC_d_rm_mod_reg_u16, in_INC_d_rm_mod_reg_u16, in_INC_d_rm_mod_reg_u16, in_INC_d_rm_mod_reg_u16, in_INC_d_rm_mod_reg_u16, in_INC_d_rm_mod_reg_u16, in_INC_d_rm_mod_reg_u16, 
	// 08
	in_DEC_d_rm_mod_reg_u16, in_DEC_d_rm_mod_reg_u16, in_DEC_d_rm_mod_reg_u16, in_DEC_d_rm_mod_reg_u16, in_DEC_d_rm_mod_reg_u16, in_DEC_d_rm_mod_reg_u16, in_DEC_d_rm_mod_reg_u16, in_DEC_d_rm_mod_reg_u16, 
	// 10
	in_CALL_d_rm_mod_reg_u16, in_CALL_d_rm_mod_reg_u16, in_CALL_d_rm_mod_reg_u16, in_CALL_d_rm_mod_reg_u16, in_CALL_d_rm_mod_reg_u16, in_CALL_d_rm_mod_reg_u16, in_CALL_d_rm_mod_reg_u16, in_CALL_d_rm_mod_reg_u16, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_JMP_d_rm_mod_reg_u16, in_JMP_d_rm_mod_reg_u16, in_JMP_d_rm_mod_reg_u16, in_JMP_d_rm_mod_reg_u16, in_JMP_d_rm_mod_reg_u16, in_JMP_d_rm_mod_reg_u16, in_JMP_d_rm_mod_reg_u16, in_JMP_d_rm_mod_reg_u16, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_PUSH_d_rm_mod_reg_u16, in_PUSH_d_rm_mod_reg_u16, in_PUSH_d_rm_mod_reg_u16, in_PUSH_d_rm_mod_reg_u16, in_PUSH_d_rm_mod_reg_u16, in_PUSH_d_rm_mod_reg_u16, in_PUSH_d_rm_mod_reg_u16, in_PUSH_d_rm_mod_reg_u16, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_INC_d_rm_mod_reg_u16, in_INC_d_rm_mod_reg_u16, in_INC_d_rm_mod_reg_u16, in_INC_d_rm_mod_reg_u16, in_INC_d_rm_mod_reg_u16, in_INC_d_rm_mod_reg_u16, in_INC_d_rm_mod_reg_u16, in_INC_d_rm_mod_reg_u16, 
	// 48
	in_DEC_d_rm_mod_reg_u16, in_DEC_d_rm_mod_reg_u16, in_DEC_d_rm_mod_reg_u16, in_DEC_d_rm_mod_reg_u16, in_DEC_d_rm_mod_reg_u16, in_DEC_d_rm_mod_reg_u16, in_DEC_d_rm_mod_reg_u16, in_DEC_d_rm_mod_reg_u16, 
	// 50
	in_CALL_d_rm_mod_reg_u16, in_CALL_d_rm_mod_reg_u16, in_CALL_d_rm_mod_reg_u16, in_CALL_d_rm_mod_reg_u16, in_CALL_d_rm_mod_reg_u16, in_CALL_d_rm_mod_reg_u16, in_CALL_d_rm_mod_reg_u16, in_CALL_d_rm_mod_reg_u16, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_JMP_d_rm_mod_reg_u16, in_JMP_d_rm_mod_reg_u16, in_JMP_d_rm_mod_reg_u16, in_JMP_d_rm_mod_reg_u16, in_JMP_d_rm_mod_reg_u16, in_JMP_d_rm_mod_reg_u16, in_JMP_d_rm_mod_reg_u16, in_JMP_d_rm_mod_reg_u16, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_PUSH_d_rm_mod_reg_u16, in_PUSH_d_rm_mod_reg_u16, in_PUSH_d_rm_mod_reg_u16, in_PUSH_d_rm_mod_reg_u16, in_PUSH_d_rm_mod_reg_u16, in_PUSH_d_rm_mod_reg_u16, in_PUSH_d_rm_mod_reg_u16, in_PUSH_d_rm_mod_reg_u16, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_INC_d_rm_mod_reg_u16, in_INC_d_rm_mod_reg_u16, in_INC_d_rm_mod_reg_u16, in_INC_d_rm_mod_reg_u16, in_INC_d_rm_mod_reg_u16, in_INC_d_rm_mod_reg_u16, in_INC_d_rm_mod_reg_u16, in_INC_d_rm_mod_reg_u16, 
	// 88
	in_DEC_d_rm_mod_reg_u16, in_DEC_d_rm_mod_reg_u16, in_DEC_d_rm_mod_reg_u16, in_DEC_d_rm_mod_reg_u16, in_DEC_d_rm_mod_reg_u16, in_DEC_d_rm_mod_reg_u16, in_DEC_d_rm_mod_reg_u16, in_DEC_d_rm_mod_reg_u16, 
	// 90
	in_CALL_d_rm_mod_reg_u16, in_CALL_d_rm_mod_reg_u16, in_CALL_d_rm_mod_reg_u16, in_CALL_d_rm_mod_reg_u16, in_CALL_d_rm_mod_reg_u16, in_CALL_d_rm_mod_reg_u16, in_CALL_d_rm_mod_reg_u16, in_CALL_d_rm_mod_reg_u16, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_JMP_d_rm_mod_reg_u16, in_JMP_d_rm_mod_reg_u16, in_JMP_d_rm_mod_reg_u16, in_JMP_d_rm_mod_reg_u16, in_JMP_d_rm_mod_reg_u16, in_JMP_d_rm_mod_reg_u16, in_JMP_d_rm_mod_reg_u16, in_JMP_d_rm_mod_reg_u16, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_PUSH_d_rm_mod_reg_u16, in_PUSH_d_rm_mod_reg_u16, in_PUSH_d_rm_mod_reg_u16, in_PUSH_d_rm_mod_reg_u16, in_PUSH_d_rm_mod_reg_u16, in_PUSH_d_rm_mod_reg_u16, in_PUSH_d_rm_mod_reg_u16, in_PUSH_d_rm_mod_reg_u16, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_INC_d_rm_mod_reg_u16, in_INC_d_rm_mod_reg_u16, in_INC_d_rm_mod_reg_u16, in_INC_d_rm_mod_reg_u16, in_INC_d_rm_mod_reg_u16, in_INC_d_rm_mod_reg_u16, in_INC_d_rm_mod_reg_u16, in_INC_d_rm_mod_reg_u16, 
	// C8
	in_DEC_d_rm_mod_reg_u16, in_DEC_d_rm_mod_reg_u16, in_DEC_d_rm_mod_reg_u16, in_DEC_d_rm_mod_reg_u16, in_DEC_d_rm_mod_reg_u16, in_DEC_d_rm_mod_reg_u16, in_DEC_d_rm_mod_reg_u16, in_DEC_d_rm_mod_reg_u16, 
	// D0
	in_CALL_d_rm_mod_reg_u16, in_CALL_d_rm_mod_reg_u16, in_CALL_d_rm_mod_reg_u16, in_CALL_d_rm_mod_reg_u16, in_CALL_d_rm_mod_reg_u16, in_CALL_d_rm_mod_reg_u16, in_CALL_d_rm_mod_reg_u16, in_CALL_d_rm_mod_reg_u16, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_JMP_d_rm_mod_reg_u16, in_JMP_d_rm_mod_reg_u16, in_JMP_d_rm_mod_reg_u16, in_JMP_d_rm_mod_reg_u16, in_JMP_d_rm_mod_reg_u16, in_JMP_d_rm_mod_reg_u16, in_JMP_d_rm_mod_reg_u16, in_JMP_d_rm_mod_reg_u16, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_PUSH_d_rm_mod_reg_u16, in_PUSH_d_rm_mod_reg_u16, in_PUSH_d_rm_mod_reg_u16, in_PUSH_d_rm_mod_reg_u16, in_PUSH_d_rm_mod_reg_u16, in_PUSH_d_rm_mod_reg_u16, in_PUSH_d_rm_mod_reg_u16, in_PUSH_d_rm_mod_reg_u16, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_st_d_d_FF[] = {
	// 00
	in_INC_d_rm_mod_reg_u32, in_INC_d_rm_mod_reg_u32, in_INC_d_rm_mod_reg_u32, in_INC_d_rm_mod_reg_u32, in_INC_d_rm_mod_reg_u32, in_INC_d_rm_mod_reg_u32, in_INC_d_rm_mod_reg_u32, in_INC_d_rm_mod_reg_u32, 
	// 08
	in_DEC_d_rm_mod_reg_u32, in_DEC_d_rm_mod_reg_u32, in_DEC_d_rm_mod_reg_u32, in_DEC_d_rm_mod_reg_u32, in_DEC_d_rm_mod_reg_u32, in_DEC_d_rm_mod_reg_u32, in_DEC_d_rm_mod_reg_u32, in_DEC_d_rm_mod_reg_u32, 
	// 10
	in_CALL_d_rm_mod_reg_u16, in_CALL_d_rm_mod_reg_u16, in_CALL_d_rm_mod_reg_u16, in_CALL_d_rm_mod_reg_u16, in_CALL_d_rm_mod_reg_u16, in_CALL_d_rm_mod_reg_u16, in_CALL_d_rm_mod_reg_u16, in_CALL_d_rm_mod_reg_u16, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_JMP_d_rm_mod_reg_u16, in_JMP_d_rm_mod_reg_u16, in_JMP_d_rm_mod_reg_u16, in_JMP_d_rm_mod_reg_u16, in_JMP_d_rm_mod_reg_u16, in_JMP_d_rm_mod_reg_u16, in_JMP_d_rm_mod_reg_u16, in_JMP_d_rm_mod_reg_u16, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_PUSH_d_rm_mod_reg_u16, in_PUSH_d_rm_mod_reg_u16, in_PUSH_d_rm_mod_reg_u16, in_PUSH_d_rm_mod_reg_u16, in_PUSH_d_rm_mod_reg_u16, in_PUSH_d_rm_mod_reg_u16, in_PUSH_d_rm_mod_reg_u16, in_PUSH_d_rm_mod_reg_u16, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_INC_d_rm_mod_reg_u32, in_INC_d_rm_mod_reg_u32, in_INC_d_rm_mod_reg_u32, in_INC_d_rm_mod_reg_u32, in_INC_d_rm_mod_reg_u32, in_INC_d_rm_mod_reg_u32, in_INC_d_rm_mod_reg_u32, in_INC_d_rm_mod_reg_u32, 
	// 48
	in_DEC_d_rm_mod_reg_u32, in_DEC_d_rm_mod_reg_u32, in_DEC_d_rm_mod_reg_u32, in_DEC_d_rm_mod_reg_u32, in_DEC_d_rm_mod_reg_u32, in_DEC_d_rm_mod_reg_u32, in_DEC_d_rm_mod_reg_u32, in_DEC_d_rm_mod_reg_u32, 
	// 50
	in_CALL_d_rm_mod_reg_u16, in_CALL_d_rm_mod_reg_u16, in_CALL_d_rm_mod_reg_u16, in_CALL_d_rm_mod_reg_u16, in_CALL_d_rm_mod_reg_u16, in_CALL_d_rm_mod_reg_u16, in_CALL_d_rm_mod_reg_u16, in_CALL_d_rm_mod_reg_u16, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_JMP_d_rm_mod_reg_u16, in_JMP_d_rm_mod_reg_u16, in_JMP_d_rm_mod_reg_u16, in_JMP_d_rm_mod_reg_u16, in_JMP_d_rm_mod_reg_u16, in_JMP_d_rm_mod_reg_u16, in_JMP_d_rm_mod_reg_u16, in_JMP_d_rm_mod_reg_u16, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_PUSH_d_rm_mod_reg_u16, in_PUSH_d_rm_mod_reg_u16, in_PUSH_d_rm_mod_reg_u16, in_PUSH_d_rm_mod_reg_u16, in_PUSH_d_rm_mod_reg_u16, in_PUSH_d_rm_mod_reg_u16, in_PUSH_d_rm_mod_reg_u16, in_PUSH_d_rm_mod_reg_u16, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_INC_d_rm_mod_reg_u32, in_INC_d_rm_mod_reg_u32, in_INC_d_rm_mod_reg_u32, in_INC_d_rm_mod_reg_u32, in_INC_d_rm_mod_reg_u32, in_INC_d_rm_mod_reg_u32, in_INC_d_rm_mod_reg_u32, in_INC_d_rm_mod_reg_u32, 
	// 88
	in_DEC_d_rm_mod_reg_u32, in_DEC_d_rm_mod_reg_u32, in_DEC_d_rm_mod_reg_u32, in_DEC_d_rm_mod_reg_u32, in_DEC_d_rm_mod_reg_u32, in_DEC_d_rm_mod_reg_u32, in_DEC_d_rm_mod_reg_u32, in_DEC_d_rm_mod_reg_u32, 
	// 90
	in_CALL_d_rm_mod_reg_u16, in_CALL_d_rm_mod_reg_u16, in_CALL_d_rm_mod_reg_u16, in_CALL_d_rm_mod_reg_u16, in_CALL_d_rm_mod_reg_u16, in_CALL_d_rm_mod_reg_u16, in_CALL_d_rm_mod_reg_u16, in_CALL_d_rm_mod_reg_u16, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_JMP_d_rm_mod_reg_u16, in_JMP_d_rm_mod_reg_u16, in_JMP_d_rm_mod_reg_u16, in_JMP_d_rm_mod_reg_u16, in_JMP_d_rm_mod_reg_u16, in_JMP_d_rm_mod_reg_u16, in_JMP_d_rm_mod_reg_u16, in_JMP_d_rm_mod_reg_u16, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_PUSH_d_rm_mod_reg_u16, in_PUSH_d_rm_mod_reg_u16, in_PUSH_d_rm_mod_reg_u16, in_PUSH_d_rm_mod_reg_u16, in_PUSH_d_rm_mod_reg_u16, in_PUSH_d_rm_mod_reg_u16, in_PUSH_d_rm_mod_reg_u16, in_PUSH_d_rm_mod_reg_u16, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_INC_d_rm_mod_reg_u32, in_INC_d_rm_mod_reg_u32, in_INC_d_rm_mod_reg_u32, in_INC_d_rm_mod_reg_u32, in_INC_d_rm_mod_reg_u32, in_INC_d_rm_mod_reg_u32, in_INC_d_rm_mod_reg_u32, in_INC_d_rm_mod_reg_u32, 
	// C8
	in_DEC_d_rm_mod_reg_u32, in_DEC_d_rm_mod_reg_u32, in_DEC_d_rm_mod_reg_u32, in_DEC_d_rm_mod_reg_u32, in_DEC_d_rm_mod_reg_u32, in_DEC_d_rm_mod_reg_u32, in_DEC_d_rm_mod_reg_u32, in_DEC_d_rm_mod_reg_u32, 
	// D0
	in_CALL_d_rm_mod_reg_u16, in_CALL_d_rm_mod_reg_u16, in_CALL_d_rm_mod_reg_u16, in_CALL_d_rm_mod_reg_u16, in_CALL_d_rm_mod_reg_u16, in_CALL_d_rm_mod_reg_u16, in_CALL_d_rm_mod_reg_u16, in_CALL_d_rm_mod_reg_u16, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_JMP_d_rm_mod_reg_u16, in_JMP_d_rm_mod_reg_u16, in_JMP_d_rm_mod_reg_u16, in_JMP_d_rm_mod_reg_u16, in_JMP_d_rm_mod_reg_u16, in_JMP_d_rm_mod_reg_u16, in_JMP_d_rm_mod_reg_u16, in_JMP_d_rm_mod_reg_u16, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_PUSH_d_rm_mod_reg_u16, in_PUSH_d_rm_mod_reg_u16, in_PUSH_d_rm_mod_reg_u16, in_PUSH_d_rm_mod_reg_u16, in_PUSH_d_rm_mod_reg_u16, in_PUSH_d_rm_mod_reg_u16, in_PUSH_d_rm_mod_reg_u16, in_PUSH_d_rm_mod_reg_u16, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_st_w_w_0F[] = {
	// 00
	st_w_w_0F_00, st_w_w_0F_01, in_LAR_w_rm_reg_reg_u16_rm_mem_u16, in_LSL_w_rm_reg_reg_u16_rm_mem_u16, in_illegal, in_illegal, in_CLTS, in_LOADALL, 
	// 08
	in_INVD, in_WBINVD, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_MOVSD_w_rm_reg_xmm_d128_rm_mod_xmm_d128, in_MOVSD_w_rm_mod_xmm_d128_rm_reg_xmm_d128, in_MOVSLDUP_w_rm_reg_xmm_u64_rm_mod_xmm_u64, in_MOVLPD_w_rm_mem_u64_rm_reg_xmm_u64, in_UNPCKLPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128, in_UNPCKHPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128, in_MOVSHDUP_w_rm_reg_xmm_u64_rm_mod_xmm_u64, in_MOVHPD_w_rm_mem_u64_rm_reg_xmm_u64, 
	// 18
	st_w_w_0F_18, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, st_w_w_0F_1F, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_MOVAPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128, in_MOVAPD_w_rm_mod_xmm_d128_rm_reg_xmm_d128, in_CVTSI2SD_w_rm_reg_xmm_d128_rm_mod_reg_u32, in_MOVNTPD_w_rm_mem_d128_rm_reg_xmm_d128, in_CVTTSD2SI_w_rm_reg_reg_u32_rm_mod_xmm_d128, in_CVTSD2SI_w_rm_reg_reg_u32_rm_mod_xmm_d128, in_UCOMISD_w_rm_mod_xmm_d128, in_COMISD_w_rm_mod_xmm_d128, 
	// 30
	in_WRMSR, in_RDTSC, in_RDMSR, in_RDPMC, in_SYSENTER, in_illegal, in_illegal, in_illegal, 
	// 38
	st_w_w_0F_38, in_illegal, st_w_w_0F_3A, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_MOVMSKPD_w_rm_reg_reg_u32_rm_rm_xmm_d128, in_SQRTSD_w_rm_reg_xmm_d128_rm_mod_xmm_d128, in_RSQRTSS_w_rm_reg_xmm_f128_rm_mod_xmm_f128, in_RCPSS_w_rm_reg_xmm_f128_rm_mod_xmm_f128, in_ANDPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128, in_ANDNPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128, in_ORPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128, in_XORPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128, 
	// 58
	in_ADDSD_w_rm_reg_xmm_d128_rm_mod_xmm_d128, in_MULSD_w_rm_reg_xmm_d128_rm_mod_xmm_d128, in_CVTSD2SS_w_rm_reg_xmm_f128_rm_mod_xmm_d128, in_CVTTPS2DQ_w_rm_reg_xmm_u128_rm_mod_xmm_f128, in_SUBSD_w_rm_reg_xmm_d128_rm_mod_xmm_d128, in_MINSD_w_rm_reg_xmm_d128_rm_mod_xmm_d128, in_DIVSD_w_rm_reg_xmm_d128_rm_mod_xmm_d128, in_MAXSD_w_rm_reg_xmm_d128_rm_mod_xmm_d128, 
	// 60
	in_PUNPCKLBW_w_rm_reg_mmx_u64_rm_mod_mmx_u32, in_PUNPCKLWD_w_rm_reg_mmx_u64_rm_mod_mmx_u32, in_PUNPCKLDQ_w_rm_reg_mmx_u64_rm_mod_mmx_u32, in_PACKSSWB_w_rm_reg_mmx_u64_rm_mod_mmx_u32, in_PCMPGTB_w_rm_reg_mmx_u64_rm_mod_mmx_u32, in_PCMPGTW_w_rm_reg_mmx_u64_rm_mod_mmx_u32, in_PCMPGTD_w_rm_reg_mmx_u64_rm_mod_mmx_u32, in_PACKUSWB_w_rm_reg_mmx_u64_rm_mod_mmx_u64, 
	// 68
	in_PUNPCKHBW_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PUNPCKHWD_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PUNPCKHDQ_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PACKSSDW_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PUNPCKLQDQ_w_rm_reg_xmm_u128_rm_mod_xmm_u128, in_PUNPCKHQDQ_w_rm_reg_xmm_u128_rm_mod_xmm_u128, in_MOVD_w_rm_reg_mmx_u64_rm_mod_reg_u32, in_MOVDQU_w_rm_reg_xmm_u128_rm_mod_xmm_u128, 
	// 70
	in_PSHUFD_w_rm_reg_xmm_u128_imm_u8, st_w_w_0F_71, st_w_w_0F_72, st_w_w_0F_73, in_PCMPEQB_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PCMPEQW_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PCMPEQD_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_EMMS, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_HADDPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128, in_HSUBPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128, in_MOVQ_w_rm_reg_xmm_u64_rm_mod_xmm_u64, in_MOVDQU_w_rm_mod_xmm_u128_rm_reg_xmm_u128, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_PUSH_reg_seg_4_u16, in_POP_reg_seg_4_u16, in_CPUID, in_BT_w_rm_reg_reg_u16, in_SHLD_w_rm_mod_reg_u16_imm_u8, in_SHLD_w_rm_mod_reg_u16_reg_gen_1_u8, in_illegal, in_illegal, 
	// A8
	in_PUSH_reg_seg_5_u16, in_POP_reg_seg_5_u16, in_RSM, in_BTS_w_rm_mod_reg_u16_rm_reg_reg_u16, in_SHRD_w_rm_mod_reg_u16_imm_u8, in_SHRD_w_rm_mod_reg_u16_reg_gen_1_u8, st_w_w_0F_AE, in_IMUL_w_rm_reg_reg_u16_rm_mod_reg_u16, 
	// B0
	in_illegal, in_illegal, in_illegal, in_BTR_w_rm_mod_reg_u16_rm_reg_reg_u16, in_illegal, in_illegal, in_MOVZX_w_rm_reg_reg_u16_rm_mod_reg_u8, in_MOVZX_w_rm_reg_reg_u16_rm_mod_reg_u16, 
	// B8
	in_POPCNT_w_rm_reg_reg_u16_rm_mod_reg_u16, in_illegal, st_w_w_0F_BA, in_BTC_w_rm_mod_reg_u16_rm_reg_reg_u16, in_illegal, in_illegal, in_MOVSX_w_rm_reg_reg_u16_rm_mod_reg_u8, in_MOVSX_w_rm_reg_reg_u16_rm_mod_reg_u16, 
	// C0
	in_XADD_w_rm_reg_reg_u8, in_XADD_w_rm_reg_reg_u16, in_CMPSD_w_rm_reg_xmm_d128_imm_u8, in_MOVNTI_w_rm_mem_u32_rm_reg_reg_u32, in_PINSRW_w_rm_reg_mmx_u64_imm_u8, in_PEXTRW_w_rm_reg_reg_u32_imm_u8, in_SHUFPD_w_rm_reg_xmm_d128_imm_u8, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_ADDSUBPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128, in_PSRLW_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PSRLD_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PSRLQ_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PADDQ_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PMULLW_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_MOVDQ2Q_w_rm_reg_mmx_u64_rm_rm_xmm_u64, in_PMOVMSKB_w_rm_reg_reg_u32_rm_rm_mmx_u64, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_PAVGB_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PSRAW_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PSRAD_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PAVGW_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PMULHUW_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PMULHW_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_CVTDQ2PD_w_rm_reg_xmm_d128_rm_mod_xmm_u128, in_MOVNTDQ_w_rm_mem_u128_rm_reg_xmm_u128, 
	// E8
	in_PSUBSB_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PSUBSW_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PMINSW_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_POR_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PADDSB_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PADDSW_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PMAXSW_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PXOR_w_rm_reg_mmx_u64_rm_mod_mmx_u64, 
	// F0
	in_LDDQU_w_rm_reg_xmm_u128_rm_mem_u128, in_PSLLW_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PSLLD_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PSLLQ_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PMULUDQ_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PMADDWD_w_rm_reg_mmx_u64_rm_mod_mmx_u32, in_PSADBW_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_MASKMOVDQU_w_rm_rm_xmm_u128, 
	// F8
	in_PSUBB_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PSUBW_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PSUBD_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PSUBQ_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PADDB_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PADDW_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PADDD_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_illegal, 
};
const OpState CpuRunnerX86::table_st_w_w_0F_00[] = {
	// 00
	in_SLDT_w_rm_mem_u16, in_SLDT_w_rm_mem_u16, in_SLDT_w_rm_mem_u16, in_SLDT_w_rm_mem_u16, in_SLDT_w_rm_mem_u16, in_SLDT_w_rm_mem_u16, in_SLDT_w_rm_mem_u16, in_SLDT_w_rm_mem_u16, 
	// 08
	in_STR_w_rm_mem_u16, in_STR_w_rm_mem_u16, in_STR_w_rm_mem_u16, in_STR_w_rm_mem_u16, in_STR_w_rm_mem_u16, in_STR_w_rm_mem_u16, in_STR_w_rm_mem_u16, in_STR_w_rm_mem_u16, 
	// 10
	in_LLDT_w_rm_mod_reg_u16, in_LLDT_w_rm_mod_reg_u16, in_LLDT_w_rm_mod_reg_u16, in_LLDT_w_rm_mod_reg_u16, in_LLDT_w_rm_mod_reg_u16, in_LLDT_w_rm_mod_reg_u16, in_LLDT_w_rm_mod_reg_u16, in_LLDT_w_rm_mod_reg_u16, 
	// 18
	in_LTR_w_rm_mod_reg_u16, in_LTR_w_rm_mod_reg_u16, in_LTR_w_rm_mod_reg_u16, in_LTR_w_rm_mod_reg_u16, in_LTR_w_rm_mod_reg_u16, in_LTR_w_rm_mod_reg_u16, in_LTR_w_rm_mod_reg_u16, in_LTR_w_rm_mod_reg_u16, 
	// 20
	in_VERR_w_rm_mod_reg_u16, in_VERR_w_rm_mod_reg_u16, in_VERR_w_rm_mod_reg_u16, in_VERR_w_rm_mod_reg_u16, in_VERR_w_rm_mod_reg_u16, in_VERR_w_rm_mod_reg_u16, in_VERR_w_rm_mod_reg_u16, in_VERR_w_rm_mod_reg_u16, 
	// 28
	in_VERW_w_rm_mod_reg_u16, in_VERW_w_rm_mod_reg_u16, in_VERW_w_rm_mod_reg_u16, in_VERW_w_rm_mod_reg_u16, in_VERW_w_rm_mod_reg_u16, in_VERW_w_rm_mod_reg_u16, in_VERW_w_rm_mod_reg_u16, in_VERW_w_rm_mod_reg_u16, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_SLDT_w_rm_mem_u16, in_SLDT_w_rm_mem_u16, in_SLDT_w_rm_mem_u16, in_SLDT_w_rm_mem_u16, in_SLDT_w_rm_mem_u16, in_SLDT_w_rm_mem_u16, in_SLDT_w_rm_mem_u16, in_SLDT_w_rm_mem_u16, 
	// 48
	in_STR_w_rm_mem_u16, in_STR_w_rm_mem_u16, in_STR_w_rm_mem_u16, in_STR_w_rm_mem_u16, in_STR_w_rm_mem_u16, in_STR_w_rm_mem_u16, in_STR_w_rm_mem_u16, in_STR_w_rm_mem_u16, 
	// 50
	in_LLDT_w_rm_mod_reg_u16, in_LLDT_w_rm_mod_reg_u16, in_LLDT_w_rm_mod_reg_u16, in_LLDT_w_rm_mod_reg_u16, in_LLDT_w_rm_mod_reg_u16, in_LLDT_w_rm_mod_reg_u16, in_LLDT_w_rm_mod_reg_u16, in_LLDT_w_rm_mod_reg_u16, 
	// 58
	in_LTR_w_rm_mod_reg_u16, in_LTR_w_rm_mod_reg_u16, in_LTR_w_rm_mod_reg_u16, in_LTR_w_rm_mod_reg_u16, in_LTR_w_rm_mod_reg_u16, in_LTR_w_rm_mod_reg_u16, in_LTR_w_rm_mod_reg_u16, in_LTR_w_rm_mod_reg_u16, 
	// 60
	in_VERR_w_rm_mod_reg_u16, in_VERR_w_rm_mod_reg_u16, in_VERR_w_rm_mod_reg_u16, in_VERR_w_rm_mod_reg_u16, in_VERR_w_rm_mod_reg_u16, in_VERR_w_rm_mod_reg_u16, in_VERR_w_rm_mod_reg_u16, in_VERR_w_rm_mod_reg_u16, 
	// 68
	in_VERW_w_rm_mod_reg_u16, in_VERW_w_rm_mod_reg_u16, in_VERW_w_rm_mod_reg_u16, in_VERW_w_rm_mod_reg_u16, in_VERW_w_rm_mod_reg_u16, in_VERW_w_rm_mod_reg_u16, in_VERW_w_rm_mod_reg_u16, in_VERW_w_rm_mod_reg_u16, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_SLDT_w_rm_mem_u16, in_SLDT_w_rm_mem_u16, in_SLDT_w_rm_mem_u16, in_SLDT_w_rm_mem_u16, in_SLDT_w_rm_mem_u16, in_SLDT_w_rm_mem_u16, in_SLDT_w_rm_mem_u16, in_SLDT_w_rm_mem_u16, 
	// 88
	in_STR_w_rm_mem_u16, in_STR_w_rm_mem_u16, in_STR_w_rm_mem_u16, in_STR_w_rm_mem_u16, in_STR_w_rm_mem_u16, in_STR_w_rm_mem_u16, in_STR_w_rm_mem_u16, in_STR_w_rm_mem_u16, 
	// 90
	in_LLDT_w_rm_mod_reg_u16, in_LLDT_w_rm_mod_reg_u16, in_LLDT_w_rm_mod_reg_u16, in_LLDT_w_rm_mod_reg_u16, in_LLDT_w_rm_mod_reg_u16, in_LLDT_w_rm_mod_reg_u16, in_LLDT_w_rm_mod_reg_u16, in_LLDT_w_rm_mod_reg_u16, 
	// 98
	in_LTR_w_rm_mod_reg_u16, in_LTR_w_rm_mod_reg_u16, in_LTR_w_rm_mod_reg_u16, in_LTR_w_rm_mod_reg_u16, in_LTR_w_rm_mod_reg_u16, in_LTR_w_rm_mod_reg_u16, in_LTR_w_rm_mod_reg_u16, in_LTR_w_rm_mod_reg_u16, 
	// A0
	in_VERR_w_rm_mod_reg_u16, in_VERR_w_rm_mod_reg_u16, in_VERR_w_rm_mod_reg_u16, in_VERR_w_rm_mod_reg_u16, in_VERR_w_rm_mod_reg_u16, in_VERR_w_rm_mod_reg_u16, in_VERR_w_rm_mod_reg_u16, in_VERR_w_rm_mod_reg_u16, 
	// A8
	in_VERW_w_rm_mod_reg_u16, in_VERW_w_rm_mod_reg_u16, in_VERW_w_rm_mod_reg_u16, in_VERW_w_rm_mod_reg_u16, in_VERW_w_rm_mod_reg_u16, in_VERW_w_rm_mod_reg_u16, in_VERW_w_rm_mod_reg_u16, in_VERW_w_rm_mod_reg_u16, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_LLDT_w_rm_mod_reg_u16, in_LLDT_w_rm_mod_reg_u16, in_LLDT_w_rm_mod_reg_u16, in_LLDT_w_rm_mod_reg_u16, in_LLDT_w_rm_mod_reg_u16, in_LLDT_w_rm_mod_reg_u16, in_LLDT_w_rm_mod_reg_u16, in_LLDT_w_rm_mod_reg_u16, 
	// D8
	in_LTR_w_rm_mod_reg_u16, in_LTR_w_rm_mod_reg_u16, in_LTR_w_rm_mod_reg_u16, in_LTR_w_rm_mod_reg_u16, in_LTR_w_rm_mod_reg_u16, in_LTR_w_rm_mod_reg_u16, in_LTR_w_rm_mod_reg_u16, in_LTR_w_rm_mod_reg_u16, 
	// E0
	in_VERR_w_rm_mod_reg_u16, in_VERR_w_rm_mod_reg_u16, in_VERR_w_rm_mod_reg_u16, in_VERR_w_rm_mod_reg_u16, in_VERR_w_rm_mod_reg_u16, in_VERR_w_rm_mod_reg_u16, in_VERR_w_rm_mod_reg_u16, in_VERR_w_rm_mod_reg_u16, 
	// E8
	in_VERW_w_rm_mod_reg_u16, in_VERW_w_rm_mod_reg_u16, in_VERW_w_rm_mod_reg_u16, in_VERW_w_rm_mod_reg_u16, in_VERW_w_rm_mod_reg_u16, in_VERW_w_rm_mod_reg_u16, in_VERW_w_rm_mod_reg_u16, in_VERW_w_rm_mod_reg_u16, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_st_w_d_0F[] = {
	// 00
	st_w_d_0F_00, st_w_d_0F_01, in_LAR_w_rm_reg_reg_u16_rm_mem_u16, in_LSL_w_rm_reg_reg_u16_rm_mem_u16, in_illegal, in_illegal, in_CLTS, in_LOADALL, 
	// 08
	in_INVD, in_WBINVD, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_MOVSD_w_rm_reg_xmm_d128_rm_mod_xmm_d128, in_MOVSD_w_rm_mod_xmm_d128_rm_reg_xmm_d128, in_MOVSLDUP_w_rm_reg_xmm_u64_rm_mod_xmm_u64, in_MOVLPD_w_rm_mem_u64_rm_reg_xmm_u64, in_UNPCKLPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128, in_UNPCKHPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128, in_MOVSHDUP_w_rm_reg_xmm_u64_rm_mod_xmm_u64, in_MOVHPD_w_rm_mem_u64_rm_reg_xmm_u64, 
	// 18
	st_w_d_0F_18, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, st_w_d_0F_1F, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_MOVAPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128, in_MOVAPD_w_rm_mod_xmm_d128_rm_reg_xmm_d128, in_CVTSI2SD_w_rm_reg_xmm_d128_rm_mod_reg_u32, in_MOVNTPD_w_rm_mem_d128_rm_reg_xmm_d128, in_CVTTSD2SI_w_rm_reg_reg_u32_rm_mod_xmm_d128, in_CVTSD2SI_w_rm_reg_reg_u32_rm_mod_xmm_d128, in_UCOMISD_w_rm_mod_xmm_d128, in_COMISD_w_rm_mod_xmm_d128, 
	// 30
	in_WRMSR, in_RDTSC, in_RDMSR, in_RDPMC, in_SYSENTER, in_illegal, in_illegal, in_illegal, 
	// 38
	st_w_d_0F_38, in_illegal, st_w_d_0F_3A, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_MOVMSKPD_w_rm_reg_reg_u32_rm_rm_xmm_d128, in_SQRTSD_w_rm_reg_xmm_d128_rm_mod_xmm_d128, in_RSQRTSS_w_rm_reg_xmm_f128_rm_mod_xmm_f128, in_RCPSS_w_rm_reg_xmm_f128_rm_mod_xmm_f128, in_ANDPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128, in_ANDNPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128, in_ORPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128, in_XORPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128, 
	// 58
	in_ADDSD_w_rm_reg_xmm_d128_rm_mod_xmm_d128, in_MULSD_w_rm_reg_xmm_d128_rm_mod_xmm_d128, in_CVTSD2SS_w_rm_reg_xmm_f128_rm_mod_xmm_d128, in_CVTTPS2DQ_w_rm_reg_xmm_u128_rm_mod_xmm_f128, in_SUBSD_w_rm_reg_xmm_d128_rm_mod_xmm_d128, in_MINSD_w_rm_reg_xmm_d128_rm_mod_xmm_d128, in_DIVSD_w_rm_reg_xmm_d128_rm_mod_xmm_d128, in_MAXSD_w_rm_reg_xmm_d128_rm_mod_xmm_d128, 
	// 60
	in_PUNPCKLBW_w_rm_reg_mmx_u64_rm_mod_mmx_u32, in_PUNPCKLWD_w_rm_reg_mmx_u64_rm_mod_mmx_u32, in_PUNPCKLDQ_w_rm_reg_mmx_u64_rm_mod_mmx_u32, in_PACKSSWB_w_rm_reg_mmx_u64_rm_mod_mmx_u32, in_PCMPGTB_w_rm_reg_mmx_u64_rm_mod_mmx_u32, in_PCMPGTW_w_rm_reg_mmx_u64_rm_mod_mmx_u32, in_PCMPGTD_w_rm_reg_mmx_u64_rm_mod_mmx_u32, in_PACKUSWB_w_rm_reg_mmx_u64_rm_mod_mmx_u64, 
	// 68
	in_PUNPCKHBW_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PUNPCKHWD_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PUNPCKHDQ_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PACKSSDW_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PUNPCKLQDQ_w_rm_reg_xmm_u128_rm_mod_xmm_u128, in_PUNPCKHQDQ_w_rm_reg_xmm_u128_rm_mod_xmm_u128, in_MOVD_w_rm_reg_mmx_u64_rm_mod_reg_u32, in_MOVDQU_w_rm_reg_xmm_u128_rm_mod_xmm_u128, 
	// 70
	in_PSHUFD_w_rm_reg_xmm_u128_imm_u8, st_w_d_0F_71, st_w_d_0F_72, st_w_d_0F_73, in_PCMPEQB_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PCMPEQW_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PCMPEQD_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_EMMS, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_HADDPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128, in_HSUBPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128, in_MOVQ_w_rm_reg_xmm_u64_rm_mod_xmm_u64, in_MOVDQU_w_rm_mod_xmm_u128_rm_reg_xmm_u128, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_PUSH_reg_seg_4_u16, in_POP_reg_seg_4_u16, in_CPUID, in_BT_w_rm_reg_reg_u16, in_SHLD_w_rm_mod_reg_u16_imm_u8, in_SHLD_w_rm_mod_reg_u16_reg_gen_1_u8, in_illegal, in_illegal, 
	// A8
	in_PUSH_reg_seg_5_u16, in_POP_reg_seg_5_u16, in_RSM, in_BTS_w_rm_mod_reg_u16_rm_reg_reg_u16, in_SHRD_w_rm_mod_reg_u16_imm_u8, in_SHRD_w_rm_mod_reg_u16_reg_gen_1_u8, st_w_d_0F_AE, in_IMUL_w_rm_reg_reg_u32_rm_mod_reg_u32, 
	// B0
	in_illegal, in_illegal, in_illegal, in_BTR_w_rm_mod_reg_u16_rm_reg_reg_u16, in_illegal, in_illegal, in_MOVZX_w_rm_reg_reg_u16_rm_mod_reg_u8, in_MOVZX_w_rm_reg_reg_u32_rm_mod_reg_u16, 
	// B8
	in_POPCNT_w_rm_reg_reg_u16_rm_mod_reg_u16, in_illegal, st_w_d_0F_BA, in_BTC_w_rm_mod_reg_u16_rm_reg_reg_u16, in_illegal, in_illegal, in_MOVSX_w_rm_reg_reg_u16_rm_mod_reg_u8, in_MOVSX_w_rm_reg_reg_u32_rm_mod_reg_u16, 
	// C0
	in_XADD_w_rm_reg_reg_u8, in_XADD_w_rm_reg_reg_u32, in_CMPSD_w_rm_reg_xmm_d128_imm_u8, in_MOVNTI_w_rm_mem_u32_rm_reg_reg_u32, in_PINSRW_w_rm_reg_mmx_u64_imm_u8, in_PEXTRW_w_rm_reg_reg_u32_imm_u8, in_SHUFPD_w_rm_reg_xmm_d128_imm_u8, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_ADDSUBPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128, in_PSRLW_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PSRLD_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PSRLQ_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PADDQ_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PMULLW_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_MOVDQ2Q_w_rm_reg_mmx_u64_rm_rm_xmm_u64, in_PMOVMSKB_w_rm_reg_reg_u32_rm_rm_mmx_u64, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_PAVGB_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PSRAW_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PSRAD_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PAVGW_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PMULHUW_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PMULHW_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_CVTDQ2PD_w_rm_reg_xmm_d128_rm_mod_xmm_u128, in_MOVNTDQ_w_rm_mem_u128_rm_reg_xmm_u128, 
	// E8
	in_PSUBSB_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PSUBSW_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PMINSW_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_POR_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PADDSB_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PADDSW_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PMAXSW_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PXOR_w_rm_reg_mmx_u64_rm_mod_mmx_u64, 
	// F0
	in_LDDQU_w_rm_reg_xmm_u128_rm_mem_u128, in_PSLLW_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PSLLD_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PSLLQ_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PMULUDQ_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PMADDWD_w_rm_reg_mmx_u64_rm_mod_mmx_u32, in_PSADBW_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_MASKMOVDQU_w_rm_rm_xmm_u128, 
	// F8
	in_PSUBB_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PSUBW_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PSUBD_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PSUBQ_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PADDB_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PADDW_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PADDD_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_illegal, 
};
const OpState CpuRunnerX86::table_st_w_d_0F_00[] = {
	// 00
	in_SLDT_w_rm_mem_u16, in_SLDT_w_rm_mem_u16, in_SLDT_w_rm_mem_u16, in_SLDT_w_rm_mem_u16, in_SLDT_w_rm_mem_u16, in_SLDT_w_rm_mem_u16, in_SLDT_w_rm_mem_u16, in_SLDT_w_rm_mem_u16, 
	// 08
	in_STR_w_rm_mem_u16, in_STR_w_rm_mem_u16, in_STR_w_rm_mem_u16, in_STR_w_rm_mem_u16, in_STR_w_rm_mem_u16, in_STR_w_rm_mem_u16, in_STR_w_rm_mem_u16, in_STR_w_rm_mem_u16, 
	// 10
	in_LLDT_w_rm_mod_reg_u16, in_LLDT_w_rm_mod_reg_u16, in_LLDT_w_rm_mod_reg_u16, in_LLDT_w_rm_mod_reg_u16, in_LLDT_w_rm_mod_reg_u16, in_LLDT_w_rm_mod_reg_u16, in_LLDT_w_rm_mod_reg_u16, in_LLDT_w_rm_mod_reg_u16, 
	// 18
	in_LTR_w_rm_mod_reg_u16, in_LTR_w_rm_mod_reg_u16, in_LTR_w_rm_mod_reg_u16, in_LTR_w_rm_mod_reg_u16, in_LTR_w_rm_mod_reg_u16, in_LTR_w_rm_mod_reg_u16, in_LTR_w_rm_mod_reg_u16, in_LTR_w_rm_mod_reg_u16, 
	// 20
	in_VERR_w_rm_mod_reg_u16, in_VERR_w_rm_mod_reg_u16, in_VERR_w_rm_mod_reg_u16, in_VERR_w_rm_mod_reg_u16, in_VERR_w_rm_mod_reg_u16, in_VERR_w_rm_mod_reg_u16, in_VERR_w_rm_mod_reg_u16, in_VERR_w_rm_mod_reg_u16, 
	// 28
	in_VERW_w_rm_mod_reg_u16, in_VERW_w_rm_mod_reg_u16, in_VERW_w_rm_mod_reg_u16, in_VERW_w_rm_mod_reg_u16, in_VERW_w_rm_mod_reg_u16, in_VERW_w_rm_mod_reg_u16, in_VERW_w_rm_mod_reg_u16, in_VERW_w_rm_mod_reg_u16, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_SLDT_w_rm_mem_u16, in_SLDT_w_rm_mem_u16, in_SLDT_w_rm_mem_u16, in_SLDT_w_rm_mem_u16, in_SLDT_w_rm_mem_u16, in_SLDT_w_rm_mem_u16, in_SLDT_w_rm_mem_u16, in_SLDT_w_rm_mem_u16, 
	// 48
	in_STR_w_rm_mem_u16, in_STR_w_rm_mem_u16, in_STR_w_rm_mem_u16, in_STR_w_rm_mem_u16, in_STR_w_rm_mem_u16, in_STR_w_rm_mem_u16, in_STR_w_rm_mem_u16, in_STR_w_rm_mem_u16, 
	// 50
	in_LLDT_w_rm_mod_reg_u16, in_LLDT_w_rm_mod_reg_u16, in_LLDT_w_rm_mod_reg_u16, in_LLDT_w_rm_mod_reg_u16, in_LLDT_w_rm_mod_reg_u16, in_LLDT_w_rm_mod_reg_u16, in_LLDT_w_rm_mod_reg_u16, in_LLDT_w_rm_mod_reg_u16, 
	// 58
	in_LTR_w_rm_mod_reg_u16, in_LTR_w_rm_mod_reg_u16, in_LTR_w_rm_mod_reg_u16, in_LTR_w_rm_mod_reg_u16, in_LTR_w_rm_mod_reg_u16, in_LTR_w_rm_mod_reg_u16, in_LTR_w_rm_mod_reg_u16, in_LTR_w_rm_mod_reg_u16, 
	// 60
	in_VERR_w_rm_mod_reg_u16, in_VERR_w_rm_mod_reg_u16, in_VERR_w_rm_mod_reg_u16, in_VERR_w_rm_mod_reg_u16, in_VERR_w_rm_mod_reg_u16, in_VERR_w_rm_mod_reg_u16, in_VERR_w_rm_mod_reg_u16, in_VERR_w_rm_mod_reg_u16, 
	// 68
	in_VERW_w_rm_mod_reg_u16, in_VERW_w_rm_mod_reg_u16, in_VERW_w_rm_mod_reg_u16, in_VERW_w_rm_mod_reg_u16, in_VERW_w_rm_mod_reg_u16, in_VERW_w_rm_mod_reg_u16, in_VERW_w_rm_mod_reg_u16, in_VERW_w_rm_mod_reg_u16, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_SLDT_w_rm_mem_u16, in_SLDT_w_rm_mem_u16, in_SLDT_w_rm_mem_u16, in_SLDT_w_rm_mem_u16, in_SLDT_w_rm_mem_u16, in_SLDT_w_rm_mem_u16, in_SLDT_w_rm_mem_u16, in_SLDT_w_rm_mem_u16, 
	// 88
	in_STR_w_rm_mem_u16, in_STR_w_rm_mem_u16, in_STR_w_rm_mem_u16, in_STR_w_rm_mem_u16, in_STR_w_rm_mem_u16, in_STR_w_rm_mem_u16, in_STR_w_rm_mem_u16, in_STR_w_rm_mem_u16, 
	// 90
	in_LLDT_w_rm_mod_reg_u16, in_LLDT_w_rm_mod_reg_u16, in_LLDT_w_rm_mod_reg_u16, in_LLDT_w_rm_mod_reg_u16, in_LLDT_w_rm_mod_reg_u16, in_LLDT_w_rm_mod_reg_u16, in_LLDT_w_rm_mod_reg_u16, in_LLDT_w_rm_mod_reg_u16, 
	// 98
	in_LTR_w_rm_mod_reg_u16, in_LTR_w_rm_mod_reg_u16, in_LTR_w_rm_mod_reg_u16, in_LTR_w_rm_mod_reg_u16, in_LTR_w_rm_mod_reg_u16, in_LTR_w_rm_mod_reg_u16, in_LTR_w_rm_mod_reg_u16, in_LTR_w_rm_mod_reg_u16, 
	// A0
	in_VERR_w_rm_mod_reg_u16, in_VERR_w_rm_mod_reg_u16, in_VERR_w_rm_mod_reg_u16, in_VERR_w_rm_mod_reg_u16, in_VERR_w_rm_mod_reg_u16, in_VERR_w_rm_mod_reg_u16, in_VERR_w_rm_mod_reg_u16, in_VERR_w_rm_mod_reg_u16, 
	// A8
	in_VERW_w_rm_mod_reg_u16, in_VERW_w_rm_mod_reg_u16, in_VERW_w_rm_mod_reg_u16, in_VERW_w_rm_mod_reg_u16, in_VERW_w_rm_mod_reg_u16, in_VERW_w_rm_mod_reg_u16, in_VERW_w_rm_mod_reg_u16, in_VERW_w_rm_mod_reg_u16, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_LLDT_w_rm_mod_reg_u16, in_LLDT_w_rm_mod_reg_u16, in_LLDT_w_rm_mod_reg_u16, in_LLDT_w_rm_mod_reg_u16, in_LLDT_w_rm_mod_reg_u16, in_LLDT_w_rm_mod_reg_u16, in_LLDT_w_rm_mod_reg_u16, in_LLDT_w_rm_mod_reg_u16, 
	// D8
	in_LTR_w_rm_mod_reg_u16, in_LTR_w_rm_mod_reg_u16, in_LTR_w_rm_mod_reg_u16, in_LTR_w_rm_mod_reg_u16, in_LTR_w_rm_mod_reg_u16, in_LTR_w_rm_mod_reg_u16, in_LTR_w_rm_mod_reg_u16, in_LTR_w_rm_mod_reg_u16, 
	// E0
	in_VERR_w_rm_mod_reg_u16, in_VERR_w_rm_mod_reg_u16, in_VERR_w_rm_mod_reg_u16, in_VERR_w_rm_mod_reg_u16, in_VERR_w_rm_mod_reg_u16, in_VERR_w_rm_mod_reg_u16, in_VERR_w_rm_mod_reg_u16, in_VERR_w_rm_mod_reg_u16, 
	// E8
	in_VERW_w_rm_mod_reg_u16, in_VERW_w_rm_mod_reg_u16, in_VERW_w_rm_mod_reg_u16, in_VERW_w_rm_mod_reg_u16, in_VERW_w_rm_mod_reg_u16, in_VERW_w_rm_mod_reg_u16, in_VERW_w_rm_mod_reg_u16, in_VERW_w_rm_mod_reg_u16, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_st_d_w_0F[] = {
	// 00
	st_d_w_0F_00, st_d_w_0F_01, in_LAR_d_rm_reg_reg_u16_rm_mem_u16, in_LSL_d_rm_reg_reg_u16_rm_mem_u16, in_illegal, in_illegal, in_CLTS, in_LOADALL, 
	// 08
	in_INVD, in_WBINVD, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_MOVSD_d_rm_reg_xmm_d128_rm_mod_xmm_d128, in_MOVSD_d_rm_mod_xmm_d128_rm_reg_xmm_d128, in_MOVSLDUP_d_rm_reg_xmm_u64_rm_mod_xmm_u64, in_MOVLPD_d_rm_mem_u64_rm_reg_xmm_u64, in_UNPCKLPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128, in_UNPCKHPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128, in_MOVSHDUP_d_rm_reg_xmm_u64_rm_mod_xmm_u64, in_MOVHPD_d_rm_mem_u64_rm_reg_xmm_u64, 
	// 18
	st_d_w_0F_18, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, st_d_w_0F_1F, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_MOVAPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128, in_MOVAPD_d_rm_mod_xmm_d128_rm_reg_xmm_d128, in_CVTSI2SD_d_rm_reg_xmm_d128_rm_mod_reg_u32, in_MOVNTPD_d_rm_mem_d128_rm_reg_xmm_d128, in_CVTTSD2SI_d_rm_reg_reg_u32_rm_mod_xmm_d128, in_CVTSD2SI_d_rm_reg_reg_u32_rm_mod_xmm_d128, in_UCOMISD_d_rm_mod_xmm_d128, in_COMISD_d_rm_mod_xmm_d128, 
	// 30
	in_WRMSR, in_RDTSC, in_RDMSR, in_RDPMC, in_SYSENTER, in_illegal, in_illegal, in_illegal, 
	// 38
	st_d_w_0F_38, in_illegal, st_d_w_0F_3A, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_MOVMSKPD_d_rm_reg_reg_u32_rm_rm_xmm_d128, in_SQRTSD_d_rm_reg_xmm_d128_rm_mod_xmm_d128, in_RSQRTSS_d_rm_reg_xmm_f128_rm_mod_xmm_f128, in_RCPSS_d_rm_reg_xmm_f128_rm_mod_xmm_f128, in_ANDPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128, in_ANDNPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128, in_ORPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128, in_XORPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128, 
	// 58
	in_ADDSD_d_rm_reg_xmm_d128_rm_mod_xmm_d128, in_MULSD_d_rm_reg_xmm_d128_rm_mod_xmm_d128, in_CVTSD2SS_d_rm_reg_xmm_f128_rm_mod_xmm_d128, in_CVTTPS2DQ_d_rm_reg_xmm_u128_rm_mod_xmm_f128, in_SUBSD_d_rm_reg_xmm_d128_rm_mod_xmm_d128, in_MINSD_d_rm_reg_xmm_d128_rm_mod_xmm_d128, in_DIVSD_d_rm_reg_xmm_d128_rm_mod_xmm_d128, in_MAXSD_d_rm_reg_xmm_d128_rm_mod_xmm_d128, 
	// 60
	in_PUNPCKLBW_d_rm_reg_mmx_u64_rm_mod_mmx_u32, in_PUNPCKLWD_d_rm_reg_mmx_u64_rm_mod_mmx_u32, in_PUNPCKLDQ_d_rm_reg_mmx_u64_rm_mod_mmx_u32, in_PACKSSWB_d_rm_reg_mmx_u64_rm_mod_mmx_u32, in_PCMPGTB_d_rm_reg_mmx_u64_rm_mod_mmx_u32, in_PCMPGTW_d_rm_reg_mmx_u64_rm_mod_mmx_u32, in_PCMPGTD_d_rm_reg_mmx_u64_rm_mod_mmx_u32, in_PACKUSWB_d_rm_reg_mmx_u64_rm_mod_mmx_u64, 
	// 68
	in_PUNPCKHBW_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PUNPCKHWD_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PUNPCKHDQ_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PACKSSDW_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PUNPCKLQDQ_d_rm_reg_xmm_u128_rm_mod_xmm_u128, in_PUNPCKHQDQ_d_rm_reg_xmm_u128_rm_mod_xmm_u128, in_MOVD_d_rm_reg_mmx_u64_rm_mod_reg_u32, in_MOVDQU_d_rm_reg_xmm_u128_rm_mod_xmm_u128, 
	// 70
	in_PSHUFD_d_rm_reg_xmm_u128_imm_u8, st_d_w_0F_71, st_d_w_0F_72, st_d_w_0F_73, in_PCMPEQB_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PCMPEQW_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PCMPEQD_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_EMMS, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_HADDPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128, in_HSUBPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128, in_MOVQ_d_rm_reg_xmm_u64_rm_mod_xmm_u64, in_MOVDQU_d_rm_mod_xmm_u128_rm_reg_xmm_u128, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_PUSH_reg_seg_4_u16, in_POP_reg_seg_4_u16, in_CPUID, in_BT_d_rm_reg_reg_u16, in_SHLD_d_rm_mod_reg_u16_imm_u8, in_SHLD_d_rm_mod_reg_u16_reg_gen_1_u8, in_illegal, in_illegal, 
	// A8
	in_PUSH_reg_seg_5_u16, in_POP_reg_seg_5_u16, in_RSM, in_BTS_d_rm_mod_reg_u16_rm_reg_reg_u16, in_SHRD_d_rm_mod_reg_u16_imm_u8, in_SHRD_d_rm_mod_reg_u16_reg_gen_1_u8, st_d_w_0F_AE, in_IMUL_d_rm_reg_reg_u16_rm_mod_reg_u16, 
	// B0
	in_illegal, in_illegal, in_illegal, in_BTR_d_rm_mod_reg_u16_rm_reg_reg_u16, in_illegal, in_illegal, in_MOVZX_d_rm_reg_reg_u16_rm_mod_reg_u8, in_MOVZX_d_rm_reg_reg_u16_rm_mod_reg_u16, 
	// B8
	in_POPCNT_d_rm_reg_reg_u16_rm_mod_reg_u16, in_illegal, st_d_w_0F_BA, in_BTC_d_rm_mod_reg_u16_rm_reg_reg_u16, in_illegal, in_illegal, in_MOVSX_d_rm_reg_reg_u16_rm_mod_reg_u8, in_MOVSX_d_rm_reg_reg_u16_rm_mod_reg_u16, 
	// C0
	in_XADD_d_rm_reg_reg_u8, in_XADD_d_rm_reg_reg_u16, in_CMPSD_d_rm_reg_xmm_d128_imm_u8, in_MOVNTI_d_rm_mem_u32_rm_reg_reg_u32, in_PINSRW_d_rm_reg_mmx_u64_imm_u8, in_PEXTRW_d_rm_reg_reg_u32_imm_u8, in_SHUFPD_d_rm_reg_xmm_d128_imm_u8, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_ADDSUBPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128, in_PSRLW_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PSRLD_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PSRLQ_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PADDQ_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PMULLW_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_MOVDQ2Q_d_rm_reg_mmx_u64_rm_rm_xmm_u64, in_PMOVMSKB_d_rm_reg_reg_u32_rm_rm_mmx_u64, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_PAVGB_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PSRAW_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PSRAD_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PAVGW_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PMULHUW_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PMULHW_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_CVTDQ2PD_d_rm_reg_xmm_d128_rm_mod_xmm_u128, in_MOVNTDQ_d_rm_mem_u128_rm_reg_xmm_u128, 
	// E8
	in_PSUBSB_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PSUBSW_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PMINSW_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_POR_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PADDSB_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PADDSW_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PMAXSW_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PXOR_d_rm_reg_mmx_u64_rm_mod_mmx_u64, 
	// F0
	in_LDDQU_d_rm_reg_xmm_u128_rm_mem_u128, in_PSLLW_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PSLLD_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PSLLQ_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PMULUDQ_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PMADDWD_d_rm_reg_mmx_u64_rm_mod_mmx_u32, in_PSADBW_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_MASKMOVDQU_d_rm_rm_xmm_u128, 
	// F8
	in_PSUBB_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PSUBW_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PSUBD_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PSUBQ_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PADDB_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PADDW_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PADDD_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_illegal, 
};
const OpState CpuRunnerX86::table_st_d_w_0F_00[] = {
	// 00
	in_SLDT_d_rm_mem_u16, in_SLDT_d_rm_mem_u16, in_SLDT_d_rm_mem_u16, in_SLDT_d_rm_mem_u16, in_SLDT_d_rm_mem_u16, in_SLDT_d_rm_mem_u16, in_SLDT_d_rm_mem_u16, in_SLDT_d_rm_mem_u16, 
	// 08
	in_STR_d_rm_mem_u16, in_STR_d_rm_mem_u16, in_STR_d_rm_mem_u16, in_STR_d_rm_mem_u16, in_STR_d_rm_mem_u16, in_STR_d_rm_mem_u16, in_STR_d_rm_mem_u16, in_STR_d_rm_mem_u16, 
	// 10
	in_LLDT_d_rm_mod_reg_u16, in_LLDT_d_rm_mod_reg_u16, in_LLDT_d_rm_mod_reg_u16, in_LLDT_d_rm_mod_reg_u16, in_LLDT_d_rm_mod_reg_u16, in_LLDT_d_rm_mod_reg_u16, in_LLDT_d_rm_mod_reg_u16, in_LLDT_d_rm_mod_reg_u16, 
	// 18
	in_LTR_d_rm_mod_reg_u16, in_LTR_d_rm_mod_reg_u16, in_LTR_d_rm_mod_reg_u16, in_LTR_d_rm_mod_reg_u16, in_LTR_d_rm_mod_reg_u16, in_LTR_d_rm_mod_reg_u16, in_LTR_d_rm_mod_reg_u16, in_LTR_d_rm_mod_reg_u16, 
	// 20
	in_VERR_d_rm_mod_reg_u16, in_VERR_d_rm_mod_reg_u16, in_VERR_d_rm_mod_reg_u16, in_VERR_d_rm_mod_reg_u16, in_VERR_d_rm_mod_reg_u16, in_VERR_d_rm_mod_reg_u16, in_VERR_d_rm_mod_reg_u16, in_VERR_d_rm_mod_reg_u16, 
	// 28
	in_VERW_d_rm_mod_reg_u16, in_VERW_d_rm_mod_reg_u16, in_VERW_d_rm_mod_reg_u16, in_VERW_d_rm_mod_reg_u16, in_VERW_d_rm_mod_reg_u16, in_VERW_d_rm_mod_reg_u16, in_VERW_d_rm_mod_reg_u16, in_VERW_d_rm_mod_reg_u16, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_SLDT_d_rm_mem_u16, in_SLDT_d_rm_mem_u16, in_SLDT_d_rm_mem_u16, in_SLDT_d_rm_mem_u16, in_SLDT_d_rm_mem_u16, in_SLDT_d_rm_mem_u16, in_SLDT_d_rm_mem_u16, in_SLDT_d_rm_mem_u16, 
	// 48
	in_STR_d_rm_mem_u16, in_STR_d_rm_mem_u16, in_STR_d_rm_mem_u16, in_STR_d_rm_mem_u16, in_STR_d_rm_mem_u16, in_STR_d_rm_mem_u16, in_STR_d_rm_mem_u16, in_STR_d_rm_mem_u16, 
	// 50
	in_LLDT_d_rm_mod_reg_u16, in_LLDT_d_rm_mod_reg_u16, in_LLDT_d_rm_mod_reg_u16, in_LLDT_d_rm_mod_reg_u16, in_LLDT_d_rm_mod_reg_u16, in_LLDT_d_rm_mod_reg_u16, in_LLDT_d_rm_mod_reg_u16, in_LLDT_d_rm_mod_reg_u16, 
	// 58
	in_LTR_d_rm_mod_reg_u16, in_LTR_d_rm_mod_reg_u16, in_LTR_d_rm_mod_reg_u16, in_LTR_d_rm_mod_reg_u16, in_LTR_d_rm_mod_reg_u16, in_LTR_d_rm_mod_reg_u16, in_LTR_d_rm_mod_reg_u16, in_LTR_d_rm_mod_reg_u16, 
	// 60
	in_VERR_d_rm_mod_reg_u16, in_VERR_d_rm_mod_reg_u16, in_VERR_d_rm_mod_reg_u16, in_VERR_d_rm_mod_reg_u16, in_VERR_d_rm_mod_reg_u16, in_VERR_d_rm_mod_reg_u16, in_VERR_d_rm_mod_reg_u16, in_VERR_d_rm_mod_reg_u16, 
	// 68
	in_VERW_d_rm_mod_reg_u16, in_VERW_d_rm_mod_reg_u16, in_VERW_d_rm_mod_reg_u16, in_VERW_d_rm_mod_reg_u16, in_VERW_d_rm_mod_reg_u16, in_VERW_d_rm_mod_reg_u16, in_VERW_d_rm_mod_reg_u16, in_VERW_d_rm_mod_reg_u16, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_SLDT_d_rm_mem_u16, in_SLDT_d_rm_mem_u16, in_SLDT_d_rm_mem_u16, in_SLDT_d_rm_mem_u16, in_SLDT_d_rm_mem_u16, in_SLDT_d_rm_mem_u16, in_SLDT_d_rm_mem_u16, in_SLDT_d_rm_mem_u16, 
	// 88
	in_STR_d_rm_mem_u16, in_STR_d_rm_mem_u16, in_STR_d_rm_mem_u16, in_STR_d_rm_mem_u16, in_STR_d_rm_mem_u16, in_STR_d_rm_mem_u16, in_STR_d_rm_mem_u16, in_STR_d_rm_mem_u16, 
	// 90
	in_LLDT_d_rm_mod_reg_u16, in_LLDT_d_rm_mod_reg_u16, in_LLDT_d_rm_mod_reg_u16, in_LLDT_d_rm_mod_reg_u16, in_LLDT_d_rm_mod_reg_u16, in_LLDT_d_rm_mod_reg_u16, in_LLDT_d_rm_mod_reg_u16, in_LLDT_d_rm_mod_reg_u16, 
	// 98
	in_LTR_d_rm_mod_reg_u16, in_LTR_d_rm_mod_reg_u16, in_LTR_d_rm_mod_reg_u16, in_LTR_d_rm_mod_reg_u16, in_LTR_d_rm_mod_reg_u16, in_LTR_d_rm_mod_reg_u16, in_LTR_d_rm_mod_reg_u16, in_LTR_d_rm_mod_reg_u16, 
	// A0
	in_VERR_d_rm_mod_reg_u16, in_VERR_d_rm_mod_reg_u16, in_VERR_d_rm_mod_reg_u16, in_VERR_d_rm_mod_reg_u16, in_VERR_d_rm_mod_reg_u16, in_VERR_d_rm_mod_reg_u16, in_VERR_d_rm_mod_reg_u16, in_VERR_d_rm_mod_reg_u16, 
	// A8
	in_VERW_d_rm_mod_reg_u16, in_VERW_d_rm_mod_reg_u16, in_VERW_d_rm_mod_reg_u16, in_VERW_d_rm_mod_reg_u16, in_VERW_d_rm_mod_reg_u16, in_VERW_d_rm_mod_reg_u16, in_VERW_d_rm_mod_reg_u16, in_VERW_d_rm_mod_reg_u16, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_LLDT_d_rm_mod_reg_u16, in_LLDT_d_rm_mod_reg_u16, in_LLDT_d_rm_mod_reg_u16, in_LLDT_d_rm_mod_reg_u16, in_LLDT_d_rm_mod_reg_u16, in_LLDT_d_rm_mod_reg_u16, in_LLDT_d_rm_mod_reg_u16, in_LLDT_d_rm_mod_reg_u16, 
	// D8
	in_LTR_d_rm_mod_reg_u16, in_LTR_d_rm_mod_reg_u16, in_LTR_d_rm_mod_reg_u16, in_LTR_d_rm_mod_reg_u16, in_LTR_d_rm_mod_reg_u16, in_LTR_d_rm_mod_reg_u16, in_LTR_d_rm_mod_reg_u16, in_LTR_d_rm_mod_reg_u16, 
	// E0
	in_VERR_d_rm_mod_reg_u16, in_VERR_d_rm_mod_reg_u16, in_VERR_d_rm_mod_reg_u16, in_VERR_d_rm_mod_reg_u16, in_VERR_d_rm_mod_reg_u16, in_VERR_d_rm_mod_reg_u16, in_VERR_d_rm_mod_reg_u16, in_VERR_d_rm_mod_reg_u16, 
	// E8
	in_VERW_d_rm_mod_reg_u16, in_VERW_d_rm_mod_reg_u16, in_VERW_d_rm_mod_reg_u16, in_VERW_d_rm_mod_reg_u16, in_VERW_d_rm_mod_reg_u16, in_VERW_d_rm_mod_reg_u16, in_VERW_d_rm_mod_reg_u16, in_VERW_d_rm_mod_reg_u16, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_st_d_d_0F[] = {
	// 00
	st_d_d_0F_00, st_d_d_0F_01, in_LAR_d_rm_reg_reg_u16_rm_mem_u16, in_LSL_d_rm_reg_reg_u16_rm_mem_u16, in_illegal, in_illegal, in_CLTS, in_LOADALL, 
	// 08
	in_INVD, in_WBINVD, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_MOVSD_d_rm_reg_xmm_d128_rm_mod_xmm_d128, in_MOVSD_d_rm_mod_xmm_d128_rm_reg_xmm_d128, in_MOVSLDUP_d_rm_reg_xmm_u64_rm_mod_xmm_u64, in_MOVLPD_d_rm_mem_u64_rm_reg_xmm_u64, in_UNPCKLPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128, in_UNPCKHPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128, in_MOVSHDUP_d_rm_reg_xmm_u64_rm_mod_xmm_u64, in_MOVHPD_d_rm_mem_u64_rm_reg_xmm_u64, 
	// 18
	st_d_d_0F_18, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, st_d_d_0F_1F, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_MOVAPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128, in_MOVAPD_d_rm_mod_xmm_d128_rm_reg_xmm_d128, in_CVTSI2SD_d_rm_reg_xmm_d128_rm_mod_reg_u32, in_MOVNTPD_d_rm_mem_d128_rm_reg_xmm_d128, in_CVTTSD2SI_d_rm_reg_reg_u32_rm_mod_xmm_d128, in_CVTSD2SI_d_rm_reg_reg_u32_rm_mod_xmm_d128, in_UCOMISD_d_rm_mod_xmm_d128, in_COMISD_d_rm_mod_xmm_d128, 
	// 30
	in_WRMSR, in_RDTSC, in_RDMSR, in_RDPMC, in_SYSENTER, in_illegal, in_illegal, in_illegal, 
	// 38
	st_d_d_0F_38, in_illegal, st_d_d_0F_3A, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_MOVMSKPD_d_rm_reg_reg_u32_rm_rm_xmm_d128, in_SQRTSD_d_rm_reg_xmm_d128_rm_mod_xmm_d128, in_RSQRTSS_d_rm_reg_xmm_f128_rm_mod_xmm_f128, in_RCPSS_d_rm_reg_xmm_f128_rm_mod_xmm_f128, in_ANDPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128, in_ANDNPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128, in_ORPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128, in_XORPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128, 
	// 58
	in_ADDSD_d_rm_reg_xmm_d128_rm_mod_xmm_d128, in_MULSD_d_rm_reg_xmm_d128_rm_mod_xmm_d128, in_CVTSD2SS_d_rm_reg_xmm_f128_rm_mod_xmm_d128, in_CVTTPS2DQ_d_rm_reg_xmm_u128_rm_mod_xmm_f128, in_SUBSD_d_rm_reg_xmm_d128_rm_mod_xmm_d128, in_MINSD_d_rm_reg_xmm_d128_rm_mod_xmm_d128, in_DIVSD_d_rm_reg_xmm_d128_rm_mod_xmm_d128, in_MAXSD_d_rm_reg_xmm_d128_rm_mod_xmm_d128, 
	// 60
	in_PUNPCKLBW_d_rm_reg_mmx_u64_rm_mod_mmx_u32, in_PUNPCKLWD_d_rm_reg_mmx_u64_rm_mod_mmx_u32, in_PUNPCKLDQ_d_rm_reg_mmx_u64_rm_mod_mmx_u32, in_PACKSSWB_d_rm_reg_mmx_u64_rm_mod_mmx_u32, in_PCMPGTB_d_rm_reg_mmx_u64_rm_mod_mmx_u32, in_PCMPGTW_d_rm_reg_mmx_u64_rm_mod_mmx_u32, in_PCMPGTD_d_rm_reg_mmx_u64_rm_mod_mmx_u32, in_PACKUSWB_d_rm_reg_mmx_u64_rm_mod_mmx_u64, 
	// 68
	in_PUNPCKHBW_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PUNPCKHWD_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PUNPCKHDQ_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PACKSSDW_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PUNPCKLQDQ_d_rm_reg_xmm_u128_rm_mod_xmm_u128, in_PUNPCKHQDQ_d_rm_reg_xmm_u128_rm_mod_xmm_u128, in_MOVD_d_rm_reg_mmx_u64_rm_mod_reg_u32, in_MOVDQU_d_rm_reg_xmm_u128_rm_mod_xmm_u128, 
	// 70
	in_PSHUFD_d_rm_reg_xmm_u128_imm_u8, st_d_d_0F_71, st_d_d_0F_72, st_d_d_0F_73, in_PCMPEQB_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PCMPEQW_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PCMPEQD_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_EMMS, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_HADDPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128, in_HSUBPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128, in_MOVQ_d_rm_reg_xmm_u64_rm_mod_xmm_u64, in_MOVDQU_d_rm_mod_xmm_u128_rm_reg_xmm_u128, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_PUSH_reg_seg_4_u16, in_POP_reg_seg_4_u16, in_CPUID, in_BT_d_rm_reg_reg_u16, in_SHLD_d_rm_mod_reg_u16_imm_u8, in_SHLD_d_rm_mod_reg_u16_reg_gen_1_u8, in_illegal, in_illegal, 
	// A8
	in_PUSH_reg_seg_5_u16, in_POP_reg_seg_5_u16, in_RSM, in_BTS_d_rm_mod_reg_u16_rm_reg_reg_u16, in_SHRD_d_rm_mod_reg_u16_imm_u8, in_SHRD_d_rm_mod_reg_u16_reg_gen_1_u8, st_d_d_0F_AE, in_IMUL_d_rm_reg_reg_u32_rm_mod_reg_u32, 
	// B0
	in_illegal, in_illegal, in_illegal, in_BTR_d_rm_mod_reg_u16_rm_reg_reg_u16, in_illegal, in_illegal, in_MOVZX_d_rm_reg_reg_u16_rm_mod_reg_u8, in_MOVZX_d_rm_reg_reg_u32_rm_mod_reg_u16, 
	// B8
	in_POPCNT_d_rm_reg_reg_u16_rm_mod_reg_u16, in_illegal, st_d_d_0F_BA, in_BTC_d_rm_mod_reg_u16_rm_reg_reg_u16, in_illegal, in_illegal, in_MOVSX_d_rm_reg_reg_u16_rm_mod_reg_u8, in_MOVSX_d_rm_reg_reg_u32_rm_mod_reg_u16, 
	// C0
	in_XADD_d_rm_reg_reg_u8, in_XADD_d_rm_reg_reg_u32, in_CMPSD_d_rm_reg_xmm_d128_imm_u8, in_MOVNTI_d_rm_mem_u32_rm_reg_reg_u32, in_PINSRW_d_rm_reg_mmx_u64_imm_u8, in_PEXTRW_d_rm_reg_reg_u32_imm_u8, in_SHUFPD_d_rm_reg_xmm_d128_imm_u8, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_ADDSUBPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128, in_PSRLW_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PSRLD_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PSRLQ_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PADDQ_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PMULLW_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_MOVDQ2Q_d_rm_reg_mmx_u64_rm_rm_xmm_u64, in_PMOVMSKB_d_rm_reg_reg_u32_rm_rm_mmx_u64, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_PAVGB_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PSRAW_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PSRAD_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PAVGW_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PMULHUW_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PMULHW_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_CVTDQ2PD_d_rm_reg_xmm_d128_rm_mod_xmm_u128, in_MOVNTDQ_d_rm_mem_u128_rm_reg_xmm_u128, 
	// E8
	in_PSUBSB_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PSUBSW_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PMINSW_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_POR_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PADDSB_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PADDSW_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PMAXSW_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PXOR_d_rm_reg_mmx_u64_rm_mod_mmx_u64, 
	// F0
	in_LDDQU_d_rm_reg_xmm_u128_rm_mem_u128, in_PSLLW_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PSLLD_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PSLLQ_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PMULUDQ_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PMADDWD_d_rm_reg_mmx_u64_rm_mod_mmx_u32, in_PSADBW_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_MASKMOVDQU_d_rm_rm_xmm_u128, 
	// F8
	in_PSUBB_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PSUBW_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PSUBD_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PSUBQ_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PADDB_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PADDW_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PADDD_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_illegal, 
};
const OpState CpuRunnerX86::table_st_d_d_0F_00[] = {
	// 00
	in_SLDT_d_rm_mem_u16, in_SLDT_d_rm_mem_u16, in_SLDT_d_rm_mem_u16, in_SLDT_d_rm_mem_u16, in_SLDT_d_rm_mem_u16, in_SLDT_d_rm_mem_u16, in_SLDT_d_rm_mem_u16, in_SLDT_d_rm_mem_u16, 
	// 08
	in_STR_d_rm_mem_u16, in_STR_d_rm_mem_u16, in_STR_d_rm_mem_u16, in_STR_d_rm_mem_u16, in_STR_d_rm_mem_u16, in_STR_d_rm_mem_u16, in_STR_d_rm_mem_u16, in_STR_d_rm_mem_u16, 
	// 10
	in_LLDT_d_rm_mod_reg_u16, in_LLDT_d_rm_mod_reg_u16, in_LLDT_d_rm_mod_reg_u16, in_LLDT_d_rm_mod_reg_u16, in_LLDT_d_rm_mod_reg_u16, in_LLDT_d_rm_mod_reg_u16, in_LLDT_d_rm_mod_reg_u16, in_LLDT_d_rm_mod_reg_u16, 
	// 18
	in_LTR_d_rm_mod_reg_u16, in_LTR_d_rm_mod_reg_u16, in_LTR_d_rm_mod_reg_u16, in_LTR_d_rm_mod_reg_u16, in_LTR_d_rm_mod_reg_u16, in_LTR_d_rm_mod_reg_u16, in_LTR_d_rm_mod_reg_u16, in_LTR_d_rm_mod_reg_u16, 
	// 20
	in_VERR_d_rm_mod_reg_u16, in_VERR_d_rm_mod_reg_u16, in_VERR_d_rm_mod_reg_u16, in_VERR_d_rm_mod_reg_u16, in_VERR_d_rm_mod_reg_u16, in_VERR_d_rm_mod_reg_u16, in_VERR_d_rm_mod_reg_u16, in_VERR_d_rm_mod_reg_u16, 
	// 28
	in_VERW_d_rm_mod_reg_u16, in_VERW_d_rm_mod_reg_u16, in_VERW_d_rm_mod_reg_u16, in_VERW_d_rm_mod_reg_u16, in_VERW_d_rm_mod_reg_u16, in_VERW_d_rm_mod_reg_u16, in_VERW_d_rm_mod_reg_u16, in_VERW_d_rm_mod_reg_u16, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_SLDT_d_rm_mem_u16, in_SLDT_d_rm_mem_u16, in_SLDT_d_rm_mem_u16, in_SLDT_d_rm_mem_u16, in_SLDT_d_rm_mem_u16, in_SLDT_d_rm_mem_u16, in_SLDT_d_rm_mem_u16, in_SLDT_d_rm_mem_u16, 
	// 48
	in_STR_d_rm_mem_u16, in_STR_d_rm_mem_u16, in_STR_d_rm_mem_u16, in_STR_d_rm_mem_u16, in_STR_d_rm_mem_u16, in_STR_d_rm_mem_u16, in_STR_d_rm_mem_u16, in_STR_d_rm_mem_u16, 
	// 50
	in_LLDT_d_rm_mod_reg_u16, in_LLDT_d_rm_mod_reg_u16, in_LLDT_d_rm_mod_reg_u16, in_LLDT_d_rm_mod_reg_u16, in_LLDT_d_rm_mod_reg_u16, in_LLDT_d_rm_mod_reg_u16, in_LLDT_d_rm_mod_reg_u16, in_LLDT_d_rm_mod_reg_u16, 
	// 58
	in_LTR_d_rm_mod_reg_u16, in_LTR_d_rm_mod_reg_u16, in_LTR_d_rm_mod_reg_u16, in_LTR_d_rm_mod_reg_u16, in_LTR_d_rm_mod_reg_u16, in_LTR_d_rm_mod_reg_u16, in_LTR_d_rm_mod_reg_u16, in_LTR_d_rm_mod_reg_u16, 
	// 60
	in_VERR_d_rm_mod_reg_u16, in_VERR_d_rm_mod_reg_u16, in_VERR_d_rm_mod_reg_u16, in_VERR_d_rm_mod_reg_u16, in_VERR_d_rm_mod_reg_u16, in_VERR_d_rm_mod_reg_u16, in_VERR_d_rm_mod_reg_u16, in_VERR_d_rm_mod_reg_u16, 
	// 68
	in_VERW_d_rm_mod_reg_u16, in_VERW_d_rm_mod_reg_u16, in_VERW_d_rm_mod_reg_u16, in_VERW_d_rm_mod_reg_u16, in_VERW_d_rm_mod_reg_u16, in_VERW_d_rm_mod_reg_u16, in_VERW_d_rm_mod_reg_u16, in_VERW_d_rm_mod_reg_u16, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_SLDT_d_rm_mem_u16, in_SLDT_d_rm_mem_u16, in_SLDT_d_rm_mem_u16, in_SLDT_d_rm_mem_u16, in_SLDT_d_rm_mem_u16, in_SLDT_d_rm_mem_u16, in_SLDT_d_rm_mem_u16, in_SLDT_d_rm_mem_u16, 
	// 88
	in_STR_d_rm_mem_u16, in_STR_d_rm_mem_u16, in_STR_d_rm_mem_u16, in_STR_d_rm_mem_u16, in_STR_d_rm_mem_u16, in_STR_d_rm_mem_u16, in_STR_d_rm_mem_u16, in_STR_d_rm_mem_u16, 
	// 90
	in_LLDT_d_rm_mod_reg_u16, in_LLDT_d_rm_mod_reg_u16, in_LLDT_d_rm_mod_reg_u16, in_LLDT_d_rm_mod_reg_u16, in_LLDT_d_rm_mod_reg_u16, in_LLDT_d_rm_mod_reg_u16, in_LLDT_d_rm_mod_reg_u16, in_LLDT_d_rm_mod_reg_u16, 
	// 98
	in_LTR_d_rm_mod_reg_u16, in_LTR_d_rm_mod_reg_u16, in_LTR_d_rm_mod_reg_u16, in_LTR_d_rm_mod_reg_u16, in_LTR_d_rm_mod_reg_u16, in_LTR_d_rm_mod_reg_u16, in_LTR_d_rm_mod_reg_u16, in_LTR_d_rm_mod_reg_u16, 
	// A0
	in_VERR_d_rm_mod_reg_u16, in_VERR_d_rm_mod_reg_u16, in_VERR_d_rm_mod_reg_u16, in_VERR_d_rm_mod_reg_u16, in_VERR_d_rm_mod_reg_u16, in_VERR_d_rm_mod_reg_u16, in_VERR_d_rm_mod_reg_u16, in_VERR_d_rm_mod_reg_u16, 
	// A8
	in_VERW_d_rm_mod_reg_u16, in_VERW_d_rm_mod_reg_u16, in_VERW_d_rm_mod_reg_u16, in_VERW_d_rm_mod_reg_u16, in_VERW_d_rm_mod_reg_u16, in_VERW_d_rm_mod_reg_u16, in_VERW_d_rm_mod_reg_u16, in_VERW_d_rm_mod_reg_u16, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_LLDT_d_rm_mod_reg_u16, in_LLDT_d_rm_mod_reg_u16, in_LLDT_d_rm_mod_reg_u16, in_LLDT_d_rm_mod_reg_u16, in_LLDT_d_rm_mod_reg_u16, in_LLDT_d_rm_mod_reg_u16, in_LLDT_d_rm_mod_reg_u16, in_LLDT_d_rm_mod_reg_u16, 
	// D8
	in_LTR_d_rm_mod_reg_u16, in_LTR_d_rm_mod_reg_u16, in_LTR_d_rm_mod_reg_u16, in_LTR_d_rm_mod_reg_u16, in_LTR_d_rm_mod_reg_u16, in_LTR_d_rm_mod_reg_u16, in_LTR_d_rm_mod_reg_u16, in_LTR_d_rm_mod_reg_u16, 
	// E0
	in_VERR_d_rm_mod_reg_u16, in_VERR_d_rm_mod_reg_u16, in_VERR_d_rm_mod_reg_u16, in_VERR_d_rm_mod_reg_u16, in_VERR_d_rm_mod_reg_u16, in_VERR_d_rm_mod_reg_u16, in_VERR_d_rm_mod_reg_u16, in_VERR_d_rm_mod_reg_u16, 
	// E8
	in_VERW_d_rm_mod_reg_u16, in_VERW_d_rm_mod_reg_u16, in_VERW_d_rm_mod_reg_u16, in_VERW_d_rm_mod_reg_u16, in_VERW_d_rm_mod_reg_u16, in_VERW_d_rm_mod_reg_u16, in_VERW_d_rm_mod_reg_u16, in_VERW_d_rm_mod_reg_u16, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_st_w_w_0F_01[] = {
	// 00
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_LMSW_w_rm_mod_reg_u16, in_LMSW_w_rm_mod_reg_u16, in_LMSW_w_rm_mod_reg_u16, in_LMSW_w_rm_mod_reg_u16, in_LMSW_w_rm_mod_reg_u16, in_LMSW_w_rm_mod_reg_u16, in_LMSW_w_rm_mod_reg_u16, in_LMSW_w_rm_mod_reg_u16, 
	// 38
	in_INVLPG, in_INVLPG, in_INVLPG, in_INVLPG, in_INVLPG, in_INVLPG, in_INVLPG, in_INVLPG, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_LMSW_w_rm_mod_reg_u16, in_LMSW_w_rm_mod_reg_u16, in_LMSW_w_rm_mod_reg_u16, in_LMSW_w_rm_mod_reg_u16, in_LMSW_w_rm_mod_reg_u16, in_LMSW_w_rm_mod_reg_u16, in_LMSW_w_rm_mod_reg_u16, in_LMSW_w_rm_mod_reg_u16, 
	// 78
	in_INVLPG, in_INVLPG, in_INVLPG, in_INVLPG, in_INVLPG, in_INVLPG, in_INVLPG, in_INVLPG, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_LMSW_w_rm_mod_reg_u16, in_LMSW_w_rm_mod_reg_u16, in_LMSW_w_rm_mod_reg_u16, in_LMSW_w_rm_mod_reg_u16, in_LMSW_w_rm_mod_reg_u16, in_LMSW_w_rm_mod_reg_u16, in_LMSW_w_rm_mod_reg_u16, in_LMSW_w_rm_mod_reg_u16, 
	// B8
	in_INVLPG, in_INVLPG, in_INVLPG, in_INVLPG, in_INVLPG, in_INVLPG, in_INVLPG, in_INVLPG, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_MONITOR_w, in_MWAIT, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_XGETBV, in_XSETBV, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_LMSW_w_rm_mod_reg_u16, in_LMSW_w_rm_mod_reg_u16, in_LMSW_w_rm_mod_reg_u16, in_LMSW_w_rm_mod_reg_u16, in_LMSW_w_rm_mod_reg_u16, in_LMSW_w_rm_mod_reg_u16, in_LMSW_w_rm_mod_reg_u16, in_LMSW_w_rm_mod_reg_u16, 
	// F8
	in_INVLPG, in_RDTSCP, in_INVLPG, in_INVLPG, in_INVLPG, in_INVLPG, in_INVLPG, in_INVLPG, 
};
const OpState CpuRunnerX86::table_st_w_d_0F_01[] = {
	// 00
	in_SGDT_w_rm_mem_x48, in_SGDT_w_rm_mem_x48, in_SGDT_w_rm_mem_x48, in_SGDT_w_rm_mem_x48, in_SGDT_w_rm_mem_x48, in_SGDT_w_rm_mem_x48, in_SGDT_w_rm_mem_x48, in_SGDT_w_rm_mem_x48, 
	// 08
	in_SIDT_w_rm_mem_x48, in_SIDT_w_rm_mem_x48, in_SIDT_w_rm_mem_x48, in_SIDT_w_rm_mem_x48, in_SIDT_w_rm_mem_x48, in_SIDT_w_rm_mem_x48, in_SIDT_w_rm_mem_x48, in_SIDT_w_rm_mem_x48, 
	// 10
	in_LGDT_w_rm_mem_x48, in_LGDT_w_rm_mem_x48, in_LGDT_w_rm_mem_x48, in_LGDT_w_rm_mem_x48, in_LGDT_w_rm_mem_x48, in_LGDT_w_rm_mem_x48, in_LGDT_w_rm_mem_x48, in_LGDT_w_rm_mem_x48, 
	// 18
	in_LIDT_w_rm_mem_x48, in_LIDT_w_rm_mem_x48, in_LIDT_w_rm_mem_x48, in_LIDT_w_rm_mem_x48, in_LIDT_w_rm_mem_x48, in_LIDT_w_rm_mem_x48, in_LIDT_w_rm_mem_x48, in_LIDT_w_rm_mem_x48, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_LMSW_w_rm_mod_reg_u16, in_LMSW_w_rm_mod_reg_u16, in_LMSW_w_rm_mod_reg_u16, in_LMSW_w_rm_mod_reg_u16, in_LMSW_w_rm_mod_reg_u16, in_LMSW_w_rm_mod_reg_u16, in_LMSW_w_rm_mod_reg_u16, in_LMSW_w_rm_mod_reg_u16, 
	// 38
	in_INVLPG, in_INVLPG, in_INVLPG, in_INVLPG, in_INVLPG, in_INVLPG, in_INVLPG, in_INVLPG, 
	// 40
	in_SGDT_w_rm_mem_x48, in_SGDT_w_rm_mem_x48, in_SGDT_w_rm_mem_x48, in_SGDT_w_rm_mem_x48, in_SGDT_w_rm_mem_x48, in_SGDT_w_rm_mem_x48, in_SGDT_w_rm_mem_x48, in_SGDT_w_rm_mem_x48, 
	// 48
	in_SIDT_w_rm_mem_x48, in_SIDT_w_rm_mem_x48, in_SIDT_w_rm_mem_x48, in_SIDT_w_rm_mem_x48, in_SIDT_w_rm_mem_x48, in_SIDT_w_rm_mem_x48, in_SIDT_w_rm_mem_x48, in_SIDT_w_rm_mem_x48, 
	// 50
	in_LGDT_w_rm_mem_x48, in_LGDT_w_rm_mem_x48, in_LGDT_w_rm_mem_x48, in_LGDT_w_rm_mem_x48, in_LGDT_w_rm_mem_x48, in_LGDT_w_rm_mem_x48, in_LGDT_w_rm_mem_x48, in_LGDT_w_rm_mem_x48, 
	// 58
	in_LIDT_w_rm_mem_x48, in_LIDT_w_rm_mem_x48, in_LIDT_w_rm_mem_x48, in_LIDT_w_rm_mem_x48, in_LIDT_w_rm_mem_x48, in_LIDT_w_rm_mem_x48, in_LIDT_w_rm_mem_x48, in_LIDT_w_rm_mem_x48, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_LMSW_w_rm_mod_reg_u16, in_LMSW_w_rm_mod_reg_u16, in_LMSW_w_rm_mod_reg_u16, in_LMSW_w_rm_mod_reg_u16, in_LMSW_w_rm_mod_reg_u16, in_LMSW_w_rm_mod_reg_u16, in_LMSW_w_rm_mod_reg_u16, in_LMSW_w_rm_mod_reg_u16, 
	// 78
	in_INVLPG, in_INVLPG, in_INVLPG, in_INVLPG, in_INVLPG, in_INVLPG, in_INVLPG, in_INVLPG, 
	// 80
	in_SGDT_w_rm_mem_x48, in_SGDT_w_rm_mem_x48, in_SGDT_w_rm_mem_x48, in_SGDT_w_rm_mem_x48, in_SGDT_w_rm_mem_x48, in_SGDT_w_rm_mem_x48, in_SGDT_w_rm_mem_x48, in_SGDT_w_rm_mem_x48, 
	// 88
	in_SIDT_w_rm_mem_x48, in_SIDT_w_rm_mem_x48, in_SIDT_w_rm_mem_x48, in_SIDT_w_rm_mem_x48, in_SIDT_w_rm_mem_x48, in_SIDT_w_rm_mem_x48, in_SIDT_w_rm_mem_x48, in_SIDT_w_rm_mem_x48, 
	// 90
	in_LGDT_w_rm_mem_x48, in_LGDT_w_rm_mem_x48, in_LGDT_w_rm_mem_x48, in_LGDT_w_rm_mem_x48, in_LGDT_w_rm_mem_x48, in_LGDT_w_rm_mem_x48, in_LGDT_w_rm_mem_x48, in_LGDT_w_rm_mem_x48, 
	// 98
	in_LIDT_w_rm_mem_x48, in_LIDT_w_rm_mem_x48, in_LIDT_w_rm_mem_x48, in_LIDT_w_rm_mem_x48, in_LIDT_w_rm_mem_x48, in_LIDT_w_rm_mem_x48, in_LIDT_w_rm_mem_x48, in_LIDT_w_rm_mem_x48, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_LMSW_w_rm_mod_reg_u16, in_LMSW_w_rm_mod_reg_u16, in_LMSW_w_rm_mod_reg_u16, in_LMSW_w_rm_mod_reg_u16, in_LMSW_w_rm_mod_reg_u16, in_LMSW_w_rm_mod_reg_u16, in_LMSW_w_rm_mod_reg_u16, in_LMSW_w_rm_mod_reg_u16, 
	// B8
	in_INVLPG, in_INVLPG, in_INVLPG, in_INVLPG, in_INVLPG, in_INVLPG, in_INVLPG, in_INVLPG, 
	// C0
	in_SGDT_w_rm_mem_x48, in_SGDT_w_rm_mem_x48, in_SGDT_w_rm_mem_x48, in_SGDT_w_rm_mem_x48, in_SGDT_w_rm_mem_x48, in_SGDT_w_rm_mem_x48, in_SGDT_w_rm_mem_x48, in_SGDT_w_rm_mem_x48, 
	// C8
	in_MONITOR_w, in_MWAIT, in_SIDT_w_rm_mem_x48, in_SIDT_w_rm_mem_x48, in_SIDT_w_rm_mem_x48, in_SIDT_w_rm_mem_x48, in_SIDT_w_rm_mem_x48, in_SIDT_w_rm_mem_x48, 
	// D0
	in_XGETBV, in_XSETBV, in_LGDT_w_rm_mem_x48, in_LGDT_w_rm_mem_x48, in_LGDT_w_rm_mem_x48, in_LGDT_w_rm_mem_x48, in_LGDT_w_rm_mem_x48, in_LGDT_w_rm_mem_x48, 
	// D8
	in_LIDT_w_rm_mem_x48, in_LIDT_w_rm_mem_x48, in_LIDT_w_rm_mem_x48, in_LIDT_w_rm_mem_x48, in_LIDT_w_rm_mem_x48, in_LIDT_w_rm_mem_x48, in_LIDT_w_rm_mem_x48, in_LIDT_w_rm_mem_x48, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_LMSW_w_rm_mod_reg_u16, in_LMSW_w_rm_mod_reg_u16, in_LMSW_w_rm_mod_reg_u16, in_LMSW_w_rm_mod_reg_u16, in_LMSW_w_rm_mod_reg_u16, in_LMSW_w_rm_mod_reg_u16, in_LMSW_w_rm_mod_reg_u16, in_LMSW_w_rm_mod_reg_u16, 
	// F8
	in_INVLPG, in_RDTSCP, in_INVLPG, in_INVLPG, in_INVLPG, in_INVLPG, in_INVLPG, in_INVLPG, 
};
const OpState CpuRunnerX86::table_st_d_w_0F_01[] = {
	// 00
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_LMSW_d_rm_mod_reg_u16, in_LMSW_d_rm_mod_reg_u16, in_LMSW_d_rm_mod_reg_u16, in_LMSW_d_rm_mod_reg_u16, in_LMSW_d_rm_mod_reg_u16, in_LMSW_d_rm_mod_reg_u16, in_LMSW_d_rm_mod_reg_u16, in_LMSW_d_rm_mod_reg_u16, 
	// 38
	in_INVLPG, in_INVLPG, in_INVLPG, in_INVLPG, in_INVLPG, in_INVLPG, in_INVLPG, in_INVLPG, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_LMSW_d_rm_mod_reg_u16, in_LMSW_d_rm_mod_reg_u16, in_LMSW_d_rm_mod_reg_u16, in_LMSW_d_rm_mod_reg_u16, in_LMSW_d_rm_mod_reg_u16, in_LMSW_d_rm_mod_reg_u16, in_LMSW_d_rm_mod_reg_u16, in_LMSW_d_rm_mod_reg_u16, 
	// 78
	in_INVLPG, in_INVLPG, in_INVLPG, in_INVLPG, in_INVLPG, in_INVLPG, in_INVLPG, in_INVLPG, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_LMSW_d_rm_mod_reg_u16, in_LMSW_d_rm_mod_reg_u16, in_LMSW_d_rm_mod_reg_u16, in_LMSW_d_rm_mod_reg_u16, in_LMSW_d_rm_mod_reg_u16, in_LMSW_d_rm_mod_reg_u16, in_LMSW_d_rm_mod_reg_u16, in_LMSW_d_rm_mod_reg_u16, 
	// B8
	in_INVLPG, in_INVLPG, in_INVLPG, in_INVLPG, in_INVLPG, in_INVLPG, in_INVLPG, in_INVLPG, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_MONITOR_d, in_MWAIT, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_XGETBV, in_XSETBV, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_LMSW_d_rm_mod_reg_u16, in_LMSW_d_rm_mod_reg_u16, in_LMSW_d_rm_mod_reg_u16, in_LMSW_d_rm_mod_reg_u16, in_LMSW_d_rm_mod_reg_u16, in_LMSW_d_rm_mod_reg_u16, in_LMSW_d_rm_mod_reg_u16, in_LMSW_d_rm_mod_reg_u16, 
	// F8
	in_INVLPG, in_RDTSCP, in_INVLPG, in_INVLPG, in_INVLPG, in_INVLPG, in_INVLPG, in_INVLPG, 
};
const OpState CpuRunnerX86::table_st_d_d_0F_01[] = {
	// 00
	in_SGDT_d_rm_mem_x48, in_SGDT_d_rm_mem_x48, in_SGDT_d_rm_mem_x48, in_SGDT_d_rm_mem_x48, in_SGDT_d_rm_mem_x48, in_SGDT_d_rm_mem_x48, in_SGDT_d_rm_mem_x48, in_SGDT_d_rm_mem_x48, 
	// 08
	in_SIDT_d_rm_mem_x48, in_SIDT_d_rm_mem_x48, in_SIDT_d_rm_mem_x48, in_SIDT_d_rm_mem_x48, in_SIDT_d_rm_mem_x48, in_SIDT_d_rm_mem_x48, in_SIDT_d_rm_mem_x48, in_SIDT_d_rm_mem_x48, 
	// 10
	in_LGDT_d_rm_mem_x48, in_LGDT_d_rm_mem_x48, in_LGDT_d_rm_mem_x48, in_LGDT_d_rm_mem_x48, in_LGDT_d_rm_mem_x48, in_LGDT_d_rm_mem_x48, in_LGDT_d_rm_mem_x48, in_LGDT_d_rm_mem_x48, 
	// 18
	in_LIDT_d_rm_mem_x48, in_LIDT_d_rm_mem_x48, in_LIDT_d_rm_mem_x48, in_LIDT_d_rm_mem_x48, in_LIDT_d_rm_mem_x48, in_LIDT_d_rm_mem_x48, in_LIDT_d_rm_mem_x48, in_LIDT_d_rm_mem_x48, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_LMSW_d_rm_mod_reg_u16, in_LMSW_d_rm_mod_reg_u16, in_LMSW_d_rm_mod_reg_u16, in_LMSW_d_rm_mod_reg_u16, in_LMSW_d_rm_mod_reg_u16, in_LMSW_d_rm_mod_reg_u16, in_LMSW_d_rm_mod_reg_u16, in_LMSW_d_rm_mod_reg_u16, 
	// 38
	in_INVLPG, in_INVLPG, in_INVLPG, in_INVLPG, in_INVLPG, in_INVLPG, in_INVLPG, in_INVLPG, 
	// 40
	in_SGDT_d_rm_mem_x48, in_SGDT_d_rm_mem_x48, in_SGDT_d_rm_mem_x48, in_SGDT_d_rm_mem_x48, in_SGDT_d_rm_mem_x48, in_SGDT_d_rm_mem_x48, in_SGDT_d_rm_mem_x48, in_SGDT_d_rm_mem_x48, 
	// 48
	in_SIDT_d_rm_mem_x48, in_SIDT_d_rm_mem_x48, in_SIDT_d_rm_mem_x48, in_SIDT_d_rm_mem_x48, in_SIDT_d_rm_mem_x48, in_SIDT_d_rm_mem_x48, in_SIDT_d_rm_mem_x48, in_SIDT_d_rm_mem_x48, 
	// 50
	in_LGDT_d_rm_mem_x48, in_LGDT_d_rm_mem_x48, in_LGDT_d_rm_mem_x48, in_LGDT_d_rm_mem_x48, in_LGDT_d_rm_mem_x48, in_LGDT_d_rm_mem_x48, in_LGDT_d_rm_mem_x48, in_LGDT_d_rm_mem_x48, 
	// 58
	in_LIDT_d_rm_mem_x48, in_LIDT_d_rm_mem_x48, in_LIDT_d_rm_mem_x48, in_LIDT_d_rm_mem_x48, in_LIDT_d_rm_mem_x48, in_LIDT_d_rm_mem_x48, in_LIDT_d_rm_mem_x48, in_LIDT_d_rm_mem_x48, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_LMSW_d_rm_mod_reg_u16, in_LMSW_d_rm_mod_reg_u16, in_LMSW_d_rm_mod_reg_u16, in_LMSW_d_rm_mod_reg_u16, in_LMSW_d_rm_mod_reg_u16, in_LMSW_d_rm_mod_reg_u16, in_LMSW_d_rm_mod_reg_u16, in_LMSW_d_rm_mod_reg_u16, 
	// 78
	in_INVLPG, in_INVLPG, in_INVLPG, in_INVLPG, in_INVLPG, in_INVLPG, in_INVLPG, in_INVLPG, 
	// 80
	in_SGDT_d_rm_mem_x48, in_SGDT_d_rm_mem_x48, in_SGDT_d_rm_mem_x48, in_SGDT_d_rm_mem_x48, in_SGDT_d_rm_mem_x48, in_SGDT_d_rm_mem_x48, in_SGDT_d_rm_mem_x48, in_SGDT_d_rm_mem_x48, 
	// 88
	in_SIDT_d_rm_mem_x48, in_SIDT_d_rm_mem_x48, in_SIDT_d_rm_mem_x48, in_SIDT_d_rm_mem_x48, in_SIDT_d_rm_mem_x48, in_SIDT_d_rm_mem_x48, in_SIDT_d_rm_mem_x48, in_SIDT_d_rm_mem_x48, 
	// 90
	in_LGDT_d_rm_mem_x48, in_LGDT_d_rm_mem_x48, in_LGDT_d_rm_mem_x48, in_LGDT_d_rm_mem_x48, in_LGDT_d_rm_mem_x48, in_LGDT_d_rm_mem_x48, in_LGDT_d_rm_mem_x48, in_LGDT_d_rm_mem_x48, 
	// 98
	in_LIDT_d_rm_mem_x48, in_LIDT_d_rm_mem_x48, in_LIDT_d_rm_mem_x48, in_LIDT_d_rm_mem_x48, in_LIDT_d_rm_mem_x48, in_LIDT_d_rm_mem_x48, in_LIDT_d_rm_mem_x48, in_LIDT_d_rm_mem_x48, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_LMSW_d_rm_mod_reg_u16, in_LMSW_d_rm_mod_reg_u16, in_LMSW_d_rm_mod_reg_u16, in_LMSW_d_rm_mod_reg_u16, in_LMSW_d_rm_mod_reg_u16, in_LMSW_d_rm_mod_reg_u16, in_LMSW_d_rm_mod_reg_u16, in_LMSW_d_rm_mod_reg_u16, 
	// B8
	in_INVLPG, in_INVLPG, in_INVLPG, in_INVLPG, in_INVLPG, in_INVLPG, in_INVLPG, in_INVLPG, 
	// C0
	in_SGDT_d_rm_mem_x48, in_SGDT_d_rm_mem_x48, in_SGDT_d_rm_mem_x48, in_SGDT_d_rm_mem_x48, in_SGDT_d_rm_mem_x48, in_SGDT_d_rm_mem_x48, in_SGDT_d_rm_mem_x48, in_SGDT_d_rm_mem_x48, 
	// C8
	in_MONITOR_d, in_MWAIT, in_SIDT_d_rm_mem_x48, in_SIDT_d_rm_mem_x48, in_SIDT_d_rm_mem_x48, in_SIDT_d_rm_mem_x48, in_SIDT_d_rm_mem_x48, in_SIDT_d_rm_mem_x48, 
	// D0
	in_XGETBV, in_XSETBV, in_LGDT_d_rm_mem_x48, in_LGDT_d_rm_mem_x48, in_LGDT_d_rm_mem_x48, in_LGDT_d_rm_mem_x48, in_LGDT_d_rm_mem_x48, in_LGDT_d_rm_mem_x48, 
	// D8
	in_LIDT_d_rm_mem_x48, in_LIDT_d_rm_mem_x48, in_LIDT_d_rm_mem_x48, in_LIDT_d_rm_mem_x48, in_LIDT_d_rm_mem_x48, in_LIDT_d_rm_mem_x48, in_LIDT_d_rm_mem_x48, in_LIDT_d_rm_mem_x48, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_LMSW_d_rm_mod_reg_u16, in_LMSW_d_rm_mod_reg_u16, in_LMSW_d_rm_mod_reg_u16, in_LMSW_d_rm_mod_reg_u16, in_LMSW_d_rm_mod_reg_u16, in_LMSW_d_rm_mod_reg_u16, in_LMSW_d_rm_mod_reg_u16, in_LMSW_d_rm_mod_reg_u16, 
	// F8
	in_INVLPG, in_RDTSCP, in_INVLPG, in_INVLPG, in_INVLPG, in_INVLPG, in_INVLPG, in_INVLPG, 
};
const OpState CpuRunnerX86::table_st_w_w_0F_18[] = {
	// 00
	in_PREFETCHNTA_w_rm_mem_u8, in_PREFETCHNTA_w_rm_mem_u8, in_PREFETCHNTA_w_rm_mem_u8, in_PREFETCHNTA_w_rm_mem_u8, in_PREFETCHNTA_w_rm_mem_u8, in_PREFETCHNTA_w_rm_mem_u8, in_PREFETCHNTA_w_rm_mem_u8, in_PREFETCHNTA_w_rm_mem_u8, 
	// 08
	in_PREFETCHT0_w_rm_mem_u8, in_PREFETCHT0_w_rm_mem_u8, in_PREFETCHT0_w_rm_mem_u8, in_PREFETCHT0_w_rm_mem_u8, in_PREFETCHT0_w_rm_mem_u8, in_PREFETCHT0_w_rm_mem_u8, in_PREFETCHT0_w_rm_mem_u8, in_PREFETCHT0_w_rm_mem_u8, 
	// 10
	in_PREFETCHT1_w_rm_mem_u8, in_PREFETCHT1_w_rm_mem_u8, in_PREFETCHT1_w_rm_mem_u8, in_PREFETCHT1_w_rm_mem_u8, in_PREFETCHT1_w_rm_mem_u8, in_PREFETCHT1_w_rm_mem_u8, in_PREFETCHT1_w_rm_mem_u8, in_PREFETCHT1_w_rm_mem_u8, 
	// 18
	in_PREFETCHT2_w_rm_mem_u8, in_PREFETCHT2_w_rm_mem_u8, in_PREFETCHT2_w_rm_mem_u8, in_PREFETCHT2_w_rm_mem_u8, in_PREFETCHT2_w_rm_mem_u8, in_PREFETCHT2_w_rm_mem_u8, in_PREFETCHT2_w_rm_mem_u8, in_PREFETCHT2_w_rm_mem_u8, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_PREFETCHNTA_w_rm_mem_u8, in_PREFETCHNTA_w_rm_mem_u8, in_PREFETCHNTA_w_rm_mem_u8, in_PREFETCHNTA_w_rm_mem_u8, in_PREFETCHNTA_w_rm_mem_u8, in_PREFETCHNTA_w_rm_mem_u8, in_PREFETCHNTA_w_rm_mem_u8, in_PREFETCHNTA_w_rm_mem_u8, 
	// 48
	in_PREFETCHT0_w_rm_mem_u8, in_PREFETCHT0_w_rm_mem_u8, in_PREFETCHT0_w_rm_mem_u8, in_PREFETCHT0_w_rm_mem_u8, in_PREFETCHT0_w_rm_mem_u8, in_PREFETCHT0_w_rm_mem_u8, in_PREFETCHT0_w_rm_mem_u8, in_PREFETCHT0_w_rm_mem_u8, 
	// 50
	in_PREFETCHT1_w_rm_mem_u8, in_PREFETCHT1_w_rm_mem_u8, in_PREFETCHT1_w_rm_mem_u8, in_PREFETCHT1_w_rm_mem_u8, in_PREFETCHT1_w_rm_mem_u8, in_PREFETCHT1_w_rm_mem_u8, in_PREFETCHT1_w_rm_mem_u8, in_PREFETCHT1_w_rm_mem_u8, 
	// 58
	in_PREFETCHT2_w_rm_mem_u8, in_PREFETCHT2_w_rm_mem_u8, in_PREFETCHT2_w_rm_mem_u8, in_PREFETCHT2_w_rm_mem_u8, in_PREFETCHT2_w_rm_mem_u8, in_PREFETCHT2_w_rm_mem_u8, in_PREFETCHT2_w_rm_mem_u8, in_PREFETCHT2_w_rm_mem_u8, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_PREFETCHNTA_w_rm_mem_u8, in_PREFETCHNTA_w_rm_mem_u8, in_PREFETCHNTA_w_rm_mem_u8, in_PREFETCHNTA_w_rm_mem_u8, in_PREFETCHNTA_w_rm_mem_u8, in_PREFETCHNTA_w_rm_mem_u8, in_PREFETCHNTA_w_rm_mem_u8, in_PREFETCHNTA_w_rm_mem_u8, 
	// 88
	in_PREFETCHT0_w_rm_mem_u8, in_PREFETCHT0_w_rm_mem_u8, in_PREFETCHT0_w_rm_mem_u8, in_PREFETCHT0_w_rm_mem_u8, in_PREFETCHT0_w_rm_mem_u8, in_PREFETCHT0_w_rm_mem_u8, in_PREFETCHT0_w_rm_mem_u8, in_PREFETCHT0_w_rm_mem_u8, 
	// 90
	in_PREFETCHT1_w_rm_mem_u8, in_PREFETCHT1_w_rm_mem_u8, in_PREFETCHT1_w_rm_mem_u8, in_PREFETCHT1_w_rm_mem_u8, in_PREFETCHT1_w_rm_mem_u8, in_PREFETCHT1_w_rm_mem_u8, in_PREFETCHT1_w_rm_mem_u8, in_PREFETCHT1_w_rm_mem_u8, 
	// 98
	in_PREFETCHT2_w_rm_mem_u8, in_PREFETCHT2_w_rm_mem_u8, in_PREFETCHT2_w_rm_mem_u8, in_PREFETCHT2_w_rm_mem_u8, in_PREFETCHT2_w_rm_mem_u8, in_PREFETCHT2_w_rm_mem_u8, in_PREFETCHT2_w_rm_mem_u8, in_PREFETCHT2_w_rm_mem_u8, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_PREFETCHNTA_w_rm_mem_u8, in_PREFETCHNTA_w_rm_mem_u8, in_PREFETCHNTA_w_rm_mem_u8, in_PREFETCHNTA_w_rm_mem_u8, in_PREFETCHNTA_w_rm_mem_u8, in_PREFETCHNTA_w_rm_mem_u8, in_PREFETCHNTA_w_rm_mem_u8, in_PREFETCHNTA_w_rm_mem_u8, 
	// C8
	in_PREFETCHT0_w_rm_mem_u8, in_PREFETCHT0_w_rm_mem_u8, in_PREFETCHT0_w_rm_mem_u8, in_PREFETCHT0_w_rm_mem_u8, in_PREFETCHT0_w_rm_mem_u8, in_PREFETCHT0_w_rm_mem_u8, in_PREFETCHT0_w_rm_mem_u8, in_PREFETCHT0_w_rm_mem_u8, 
	// D0
	in_PREFETCHT1_w_rm_mem_u8, in_PREFETCHT1_w_rm_mem_u8, in_PREFETCHT1_w_rm_mem_u8, in_PREFETCHT1_w_rm_mem_u8, in_PREFETCHT1_w_rm_mem_u8, in_PREFETCHT1_w_rm_mem_u8, in_PREFETCHT1_w_rm_mem_u8, in_PREFETCHT1_w_rm_mem_u8, 
	// D8
	in_PREFETCHT2_w_rm_mem_u8, in_PREFETCHT2_w_rm_mem_u8, in_PREFETCHT2_w_rm_mem_u8, in_PREFETCHT2_w_rm_mem_u8, in_PREFETCHT2_w_rm_mem_u8, in_PREFETCHT2_w_rm_mem_u8, in_PREFETCHT2_w_rm_mem_u8, in_PREFETCHT2_w_rm_mem_u8, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_st_w_d_0F_18[] = {
	// 00
	in_PREFETCHNTA_w_rm_mem_u8, in_PREFETCHNTA_w_rm_mem_u8, in_PREFETCHNTA_w_rm_mem_u8, in_PREFETCHNTA_w_rm_mem_u8, in_PREFETCHNTA_w_rm_mem_u8, in_PREFETCHNTA_w_rm_mem_u8, in_PREFETCHNTA_w_rm_mem_u8, in_PREFETCHNTA_w_rm_mem_u8, 
	// 08
	in_PREFETCHT0_w_rm_mem_u8, in_PREFETCHT0_w_rm_mem_u8, in_PREFETCHT0_w_rm_mem_u8, in_PREFETCHT0_w_rm_mem_u8, in_PREFETCHT0_w_rm_mem_u8, in_PREFETCHT0_w_rm_mem_u8, in_PREFETCHT0_w_rm_mem_u8, in_PREFETCHT0_w_rm_mem_u8, 
	// 10
	in_PREFETCHT1_w_rm_mem_u8, in_PREFETCHT1_w_rm_mem_u8, in_PREFETCHT1_w_rm_mem_u8, in_PREFETCHT1_w_rm_mem_u8, in_PREFETCHT1_w_rm_mem_u8, in_PREFETCHT1_w_rm_mem_u8, in_PREFETCHT1_w_rm_mem_u8, in_PREFETCHT1_w_rm_mem_u8, 
	// 18
	in_PREFETCHT2_w_rm_mem_u8, in_PREFETCHT2_w_rm_mem_u8, in_PREFETCHT2_w_rm_mem_u8, in_PREFETCHT2_w_rm_mem_u8, in_PREFETCHT2_w_rm_mem_u8, in_PREFETCHT2_w_rm_mem_u8, in_PREFETCHT2_w_rm_mem_u8, in_PREFETCHT2_w_rm_mem_u8, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_PREFETCHNTA_w_rm_mem_u8, in_PREFETCHNTA_w_rm_mem_u8, in_PREFETCHNTA_w_rm_mem_u8, in_PREFETCHNTA_w_rm_mem_u8, in_PREFETCHNTA_w_rm_mem_u8, in_PREFETCHNTA_w_rm_mem_u8, in_PREFETCHNTA_w_rm_mem_u8, in_PREFETCHNTA_w_rm_mem_u8, 
	// 48
	in_PREFETCHT0_w_rm_mem_u8, in_PREFETCHT0_w_rm_mem_u8, in_PREFETCHT0_w_rm_mem_u8, in_PREFETCHT0_w_rm_mem_u8, in_PREFETCHT0_w_rm_mem_u8, in_PREFETCHT0_w_rm_mem_u8, in_PREFETCHT0_w_rm_mem_u8, in_PREFETCHT0_w_rm_mem_u8, 
	// 50
	in_PREFETCHT1_w_rm_mem_u8, in_PREFETCHT1_w_rm_mem_u8, in_PREFETCHT1_w_rm_mem_u8, in_PREFETCHT1_w_rm_mem_u8, in_PREFETCHT1_w_rm_mem_u8, in_PREFETCHT1_w_rm_mem_u8, in_PREFETCHT1_w_rm_mem_u8, in_PREFETCHT1_w_rm_mem_u8, 
	// 58
	in_PREFETCHT2_w_rm_mem_u8, in_PREFETCHT2_w_rm_mem_u8, in_PREFETCHT2_w_rm_mem_u8, in_PREFETCHT2_w_rm_mem_u8, in_PREFETCHT2_w_rm_mem_u8, in_PREFETCHT2_w_rm_mem_u8, in_PREFETCHT2_w_rm_mem_u8, in_PREFETCHT2_w_rm_mem_u8, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_PREFETCHNTA_w_rm_mem_u8, in_PREFETCHNTA_w_rm_mem_u8, in_PREFETCHNTA_w_rm_mem_u8, in_PREFETCHNTA_w_rm_mem_u8, in_PREFETCHNTA_w_rm_mem_u8, in_PREFETCHNTA_w_rm_mem_u8, in_PREFETCHNTA_w_rm_mem_u8, in_PREFETCHNTA_w_rm_mem_u8, 
	// 88
	in_PREFETCHT0_w_rm_mem_u8, in_PREFETCHT0_w_rm_mem_u8, in_PREFETCHT0_w_rm_mem_u8, in_PREFETCHT0_w_rm_mem_u8, in_PREFETCHT0_w_rm_mem_u8, in_PREFETCHT0_w_rm_mem_u8, in_PREFETCHT0_w_rm_mem_u8, in_PREFETCHT0_w_rm_mem_u8, 
	// 90
	in_PREFETCHT1_w_rm_mem_u8, in_PREFETCHT1_w_rm_mem_u8, in_PREFETCHT1_w_rm_mem_u8, in_PREFETCHT1_w_rm_mem_u8, in_PREFETCHT1_w_rm_mem_u8, in_PREFETCHT1_w_rm_mem_u8, in_PREFETCHT1_w_rm_mem_u8, in_PREFETCHT1_w_rm_mem_u8, 
	// 98
	in_PREFETCHT2_w_rm_mem_u8, in_PREFETCHT2_w_rm_mem_u8, in_PREFETCHT2_w_rm_mem_u8, in_PREFETCHT2_w_rm_mem_u8, in_PREFETCHT2_w_rm_mem_u8, in_PREFETCHT2_w_rm_mem_u8, in_PREFETCHT2_w_rm_mem_u8, in_PREFETCHT2_w_rm_mem_u8, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_PREFETCHNTA_w_rm_mem_u8, in_PREFETCHNTA_w_rm_mem_u8, in_PREFETCHNTA_w_rm_mem_u8, in_PREFETCHNTA_w_rm_mem_u8, in_PREFETCHNTA_w_rm_mem_u8, in_PREFETCHNTA_w_rm_mem_u8, in_PREFETCHNTA_w_rm_mem_u8, in_PREFETCHNTA_w_rm_mem_u8, 
	// C8
	in_PREFETCHT0_w_rm_mem_u8, in_PREFETCHT0_w_rm_mem_u8, in_PREFETCHT0_w_rm_mem_u8, in_PREFETCHT0_w_rm_mem_u8, in_PREFETCHT0_w_rm_mem_u8, in_PREFETCHT0_w_rm_mem_u8, in_PREFETCHT0_w_rm_mem_u8, in_PREFETCHT0_w_rm_mem_u8, 
	// D0
	in_PREFETCHT1_w_rm_mem_u8, in_PREFETCHT1_w_rm_mem_u8, in_PREFETCHT1_w_rm_mem_u8, in_PREFETCHT1_w_rm_mem_u8, in_PREFETCHT1_w_rm_mem_u8, in_PREFETCHT1_w_rm_mem_u8, in_PREFETCHT1_w_rm_mem_u8, in_PREFETCHT1_w_rm_mem_u8, 
	// D8
	in_PREFETCHT2_w_rm_mem_u8, in_PREFETCHT2_w_rm_mem_u8, in_PREFETCHT2_w_rm_mem_u8, in_PREFETCHT2_w_rm_mem_u8, in_PREFETCHT2_w_rm_mem_u8, in_PREFETCHT2_w_rm_mem_u8, in_PREFETCHT2_w_rm_mem_u8, in_PREFETCHT2_w_rm_mem_u8, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_st_d_w_0F_18[] = {
	// 00
	in_PREFETCHNTA_d_rm_mem_u8, in_PREFETCHNTA_d_rm_mem_u8, in_PREFETCHNTA_d_rm_mem_u8, in_PREFETCHNTA_d_rm_mem_u8, in_PREFETCHNTA_d_rm_mem_u8, in_PREFETCHNTA_d_rm_mem_u8, in_PREFETCHNTA_d_rm_mem_u8, in_PREFETCHNTA_d_rm_mem_u8, 
	// 08
	in_PREFETCHT0_d_rm_mem_u8, in_PREFETCHT0_d_rm_mem_u8, in_PREFETCHT0_d_rm_mem_u8, in_PREFETCHT0_d_rm_mem_u8, in_PREFETCHT0_d_rm_mem_u8, in_PREFETCHT0_d_rm_mem_u8, in_PREFETCHT0_d_rm_mem_u8, in_PREFETCHT0_d_rm_mem_u8, 
	// 10
	in_PREFETCHT1_d_rm_mem_u8, in_PREFETCHT1_d_rm_mem_u8, in_PREFETCHT1_d_rm_mem_u8, in_PREFETCHT1_d_rm_mem_u8, in_PREFETCHT1_d_rm_mem_u8, in_PREFETCHT1_d_rm_mem_u8, in_PREFETCHT1_d_rm_mem_u8, in_PREFETCHT1_d_rm_mem_u8, 
	// 18
	in_PREFETCHT2_d_rm_mem_u8, in_PREFETCHT2_d_rm_mem_u8, in_PREFETCHT2_d_rm_mem_u8, in_PREFETCHT2_d_rm_mem_u8, in_PREFETCHT2_d_rm_mem_u8, in_PREFETCHT2_d_rm_mem_u8, in_PREFETCHT2_d_rm_mem_u8, in_PREFETCHT2_d_rm_mem_u8, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_PREFETCHNTA_d_rm_mem_u8, in_PREFETCHNTA_d_rm_mem_u8, in_PREFETCHNTA_d_rm_mem_u8, in_PREFETCHNTA_d_rm_mem_u8, in_PREFETCHNTA_d_rm_mem_u8, in_PREFETCHNTA_d_rm_mem_u8, in_PREFETCHNTA_d_rm_mem_u8, in_PREFETCHNTA_d_rm_mem_u8, 
	// 48
	in_PREFETCHT0_d_rm_mem_u8, in_PREFETCHT0_d_rm_mem_u8, in_PREFETCHT0_d_rm_mem_u8, in_PREFETCHT0_d_rm_mem_u8, in_PREFETCHT0_d_rm_mem_u8, in_PREFETCHT0_d_rm_mem_u8, in_PREFETCHT0_d_rm_mem_u8, in_PREFETCHT0_d_rm_mem_u8, 
	// 50
	in_PREFETCHT1_d_rm_mem_u8, in_PREFETCHT1_d_rm_mem_u8, in_PREFETCHT1_d_rm_mem_u8, in_PREFETCHT1_d_rm_mem_u8, in_PREFETCHT1_d_rm_mem_u8, in_PREFETCHT1_d_rm_mem_u8, in_PREFETCHT1_d_rm_mem_u8, in_PREFETCHT1_d_rm_mem_u8, 
	// 58
	in_PREFETCHT2_d_rm_mem_u8, in_PREFETCHT2_d_rm_mem_u8, in_PREFETCHT2_d_rm_mem_u8, in_PREFETCHT2_d_rm_mem_u8, in_PREFETCHT2_d_rm_mem_u8, in_PREFETCHT2_d_rm_mem_u8, in_PREFETCHT2_d_rm_mem_u8, in_PREFETCHT2_d_rm_mem_u8, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_PREFETCHNTA_d_rm_mem_u8, in_PREFETCHNTA_d_rm_mem_u8, in_PREFETCHNTA_d_rm_mem_u8, in_PREFETCHNTA_d_rm_mem_u8, in_PREFETCHNTA_d_rm_mem_u8, in_PREFETCHNTA_d_rm_mem_u8, in_PREFETCHNTA_d_rm_mem_u8, in_PREFETCHNTA_d_rm_mem_u8, 
	// 88
	in_PREFETCHT0_d_rm_mem_u8, in_PREFETCHT0_d_rm_mem_u8, in_PREFETCHT0_d_rm_mem_u8, in_PREFETCHT0_d_rm_mem_u8, in_PREFETCHT0_d_rm_mem_u8, in_PREFETCHT0_d_rm_mem_u8, in_PREFETCHT0_d_rm_mem_u8, in_PREFETCHT0_d_rm_mem_u8, 
	// 90
	in_PREFETCHT1_d_rm_mem_u8, in_PREFETCHT1_d_rm_mem_u8, in_PREFETCHT1_d_rm_mem_u8, in_PREFETCHT1_d_rm_mem_u8, in_PREFETCHT1_d_rm_mem_u8, in_PREFETCHT1_d_rm_mem_u8, in_PREFETCHT1_d_rm_mem_u8, in_PREFETCHT1_d_rm_mem_u8, 
	// 98
	in_PREFETCHT2_d_rm_mem_u8, in_PREFETCHT2_d_rm_mem_u8, in_PREFETCHT2_d_rm_mem_u8, in_PREFETCHT2_d_rm_mem_u8, in_PREFETCHT2_d_rm_mem_u8, in_PREFETCHT2_d_rm_mem_u8, in_PREFETCHT2_d_rm_mem_u8, in_PREFETCHT2_d_rm_mem_u8, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_PREFETCHNTA_d_rm_mem_u8, in_PREFETCHNTA_d_rm_mem_u8, in_PREFETCHNTA_d_rm_mem_u8, in_PREFETCHNTA_d_rm_mem_u8, in_PREFETCHNTA_d_rm_mem_u8, in_PREFETCHNTA_d_rm_mem_u8, in_PREFETCHNTA_d_rm_mem_u8, in_PREFETCHNTA_d_rm_mem_u8, 
	// C8
	in_PREFETCHT0_d_rm_mem_u8, in_PREFETCHT0_d_rm_mem_u8, in_PREFETCHT0_d_rm_mem_u8, in_PREFETCHT0_d_rm_mem_u8, in_PREFETCHT0_d_rm_mem_u8, in_PREFETCHT0_d_rm_mem_u8, in_PREFETCHT0_d_rm_mem_u8, in_PREFETCHT0_d_rm_mem_u8, 
	// D0
	in_PREFETCHT1_d_rm_mem_u8, in_PREFETCHT1_d_rm_mem_u8, in_PREFETCHT1_d_rm_mem_u8, in_PREFETCHT1_d_rm_mem_u8, in_PREFETCHT1_d_rm_mem_u8, in_PREFETCHT1_d_rm_mem_u8, in_PREFETCHT1_d_rm_mem_u8, in_PREFETCHT1_d_rm_mem_u8, 
	// D8
	in_PREFETCHT2_d_rm_mem_u8, in_PREFETCHT2_d_rm_mem_u8, in_PREFETCHT2_d_rm_mem_u8, in_PREFETCHT2_d_rm_mem_u8, in_PREFETCHT2_d_rm_mem_u8, in_PREFETCHT2_d_rm_mem_u8, in_PREFETCHT2_d_rm_mem_u8, in_PREFETCHT2_d_rm_mem_u8, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_st_d_d_0F_18[] = {
	// 00
	in_PREFETCHNTA_d_rm_mem_u8, in_PREFETCHNTA_d_rm_mem_u8, in_PREFETCHNTA_d_rm_mem_u8, in_PREFETCHNTA_d_rm_mem_u8, in_PREFETCHNTA_d_rm_mem_u8, in_PREFETCHNTA_d_rm_mem_u8, in_PREFETCHNTA_d_rm_mem_u8, in_PREFETCHNTA_d_rm_mem_u8, 
	// 08
	in_PREFETCHT0_d_rm_mem_u8, in_PREFETCHT0_d_rm_mem_u8, in_PREFETCHT0_d_rm_mem_u8, in_PREFETCHT0_d_rm_mem_u8, in_PREFETCHT0_d_rm_mem_u8, in_PREFETCHT0_d_rm_mem_u8, in_PREFETCHT0_d_rm_mem_u8, in_PREFETCHT0_d_rm_mem_u8, 
	// 10
	in_PREFETCHT1_d_rm_mem_u8, in_PREFETCHT1_d_rm_mem_u8, in_PREFETCHT1_d_rm_mem_u8, in_PREFETCHT1_d_rm_mem_u8, in_PREFETCHT1_d_rm_mem_u8, in_PREFETCHT1_d_rm_mem_u8, in_PREFETCHT1_d_rm_mem_u8, in_PREFETCHT1_d_rm_mem_u8, 
	// 18
	in_PREFETCHT2_d_rm_mem_u8, in_PREFETCHT2_d_rm_mem_u8, in_PREFETCHT2_d_rm_mem_u8, in_PREFETCHT2_d_rm_mem_u8, in_PREFETCHT2_d_rm_mem_u8, in_PREFETCHT2_d_rm_mem_u8, in_PREFETCHT2_d_rm_mem_u8, in_PREFETCHT2_d_rm_mem_u8, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_PREFETCHNTA_d_rm_mem_u8, in_PREFETCHNTA_d_rm_mem_u8, in_PREFETCHNTA_d_rm_mem_u8, in_PREFETCHNTA_d_rm_mem_u8, in_PREFETCHNTA_d_rm_mem_u8, in_PREFETCHNTA_d_rm_mem_u8, in_PREFETCHNTA_d_rm_mem_u8, in_PREFETCHNTA_d_rm_mem_u8, 
	// 48
	in_PREFETCHT0_d_rm_mem_u8, in_PREFETCHT0_d_rm_mem_u8, in_PREFETCHT0_d_rm_mem_u8, in_PREFETCHT0_d_rm_mem_u8, in_PREFETCHT0_d_rm_mem_u8, in_PREFETCHT0_d_rm_mem_u8, in_PREFETCHT0_d_rm_mem_u8, in_PREFETCHT0_d_rm_mem_u8, 
	// 50
	in_PREFETCHT1_d_rm_mem_u8, in_PREFETCHT1_d_rm_mem_u8, in_PREFETCHT1_d_rm_mem_u8, in_PREFETCHT1_d_rm_mem_u8, in_PREFETCHT1_d_rm_mem_u8, in_PREFETCHT1_d_rm_mem_u8, in_PREFETCHT1_d_rm_mem_u8, in_PREFETCHT1_d_rm_mem_u8, 
	// 58
	in_PREFETCHT2_d_rm_mem_u8, in_PREFETCHT2_d_rm_mem_u8, in_PREFETCHT2_d_rm_mem_u8, in_PREFETCHT2_d_rm_mem_u8, in_PREFETCHT2_d_rm_mem_u8, in_PREFETCHT2_d_rm_mem_u8, in_PREFETCHT2_d_rm_mem_u8, in_PREFETCHT2_d_rm_mem_u8, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_PREFETCHNTA_d_rm_mem_u8, in_PREFETCHNTA_d_rm_mem_u8, in_PREFETCHNTA_d_rm_mem_u8, in_PREFETCHNTA_d_rm_mem_u8, in_PREFETCHNTA_d_rm_mem_u8, in_PREFETCHNTA_d_rm_mem_u8, in_PREFETCHNTA_d_rm_mem_u8, in_PREFETCHNTA_d_rm_mem_u8, 
	// 88
	in_PREFETCHT0_d_rm_mem_u8, in_PREFETCHT0_d_rm_mem_u8, in_PREFETCHT0_d_rm_mem_u8, in_PREFETCHT0_d_rm_mem_u8, in_PREFETCHT0_d_rm_mem_u8, in_PREFETCHT0_d_rm_mem_u8, in_PREFETCHT0_d_rm_mem_u8, in_PREFETCHT0_d_rm_mem_u8, 
	// 90
	in_PREFETCHT1_d_rm_mem_u8, in_PREFETCHT1_d_rm_mem_u8, in_PREFETCHT1_d_rm_mem_u8, in_PREFETCHT1_d_rm_mem_u8, in_PREFETCHT1_d_rm_mem_u8, in_PREFETCHT1_d_rm_mem_u8, in_PREFETCHT1_d_rm_mem_u8, in_PREFETCHT1_d_rm_mem_u8, 
	// 98
	in_PREFETCHT2_d_rm_mem_u8, in_PREFETCHT2_d_rm_mem_u8, in_PREFETCHT2_d_rm_mem_u8, in_PREFETCHT2_d_rm_mem_u8, in_PREFETCHT2_d_rm_mem_u8, in_PREFETCHT2_d_rm_mem_u8, in_PREFETCHT2_d_rm_mem_u8, in_PREFETCHT2_d_rm_mem_u8, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_PREFETCHNTA_d_rm_mem_u8, in_PREFETCHNTA_d_rm_mem_u8, in_PREFETCHNTA_d_rm_mem_u8, in_PREFETCHNTA_d_rm_mem_u8, in_PREFETCHNTA_d_rm_mem_u8, in_PREFETCHNTA_d_rm_mem_u8, in_PREFETCHNTA_d_rm_mem_u8, in_PREFETCHNTA_d_rm_mem_u8, 
	// C8
	in_PREFETCHT0_d_rm_mem_u8, in_PREFETCHT0_d_rm_mem_u8, in_PREFETCHT0_d_rm_mem_u8, in_PREFETCHT0_d_rm_mem_u8, in_PREFETCHT0_d_rm_mem_u8, in_PREFETCHT0_d_rm_mem_u8, in_PREFETCHT0_d_rm_mem_u8, in_PREFETCHT0_d_rm_mem_u8, 
	// D0
	in_PREFETCHT1_d_rm_mem_u8, in_PREFETCHT1_d_rm_mem_u8, in_PREFETCHT1_d_rm_mem_u8, in_PREFETCHT1_d_rm_mem_u8, in_PREFETCHT1_d_rm_mem_u8, in_PREFETCHT1_d_rm_mem_u8, in_PREFETCHT1_d_rm_mem_u8, in_PREFETCHT1_d_rm_mem_u8, 
	// D8
	in_PREFETCHT2_d_rm_mem_u8, in_PREFETCHT2_d_rm_mem_u8, in_PREFETCHT2_d_rm_mem_u8, in_PREFETCHT2_d_rm_mem_u8, in_PREFETCHT2_d_rm_mem_u8, in_PREFETCHT2_d_rm_mem_u8, in_PREFETCHT2_d_rm_mem_u8, in_PREFETCHT2_d_rm_mem_u8, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_st_w_w_0F_1F[] = {
	// 00
	in_NOP_w_rm_mod_reg_u16, in_NOP_w_rm_mod_reg_u16, in_NOP_w_rm_mod_reg_u16, in_NOP_w_rm_mod_reg_u16, in_NOP_w_rm_mod_reg_u16, in_NOP_w_rm_mod_reg_u16, in_NOP_w_rm_mod_reg_u16, in_NOP_w_rm_mod_reg_u16, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_NOP_w_rm_mod_reg_u16, in_NOP_w_rm_mod_reg_u16, in_NOP_w_rm_mod_reg_u16, in_NOP_w_rm_mod_reg_u16, in_NOP_w_rm_mod_reg_u16, in_NOP_w_rm_mod_reg_u16, in_NOP_w_rm_mod_reg_u16, in_NOP_w_rm_mod_reg_u16, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_NOP_w_rm_mod_reg_u16, in_NOP_w_rm_mod_reg_u16, in_NOP_w_rm_mod_reg_u16, in_NOP_w_rm_mod_reg_u16, in_NOP_w_rm_mod_reg_u16, in_NOP_w_rm_mod_reg_u16, in_NOP_w_rm_mod_reg_u16, in_NOP_w_rm_mod_reg_u16, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_NOP_w_rm_mod_reg_u16, in_NOP_w_rm_mod_reg_u16, in_NOP_w_rm_mod_reg_u16, in_NOP_w_rm_mod_reg_u16, in_NOP_w_rm_mod_reg_u16, in_NOP_w_rm_mod_reg_u16, in_NOP_w_rm_mod_reg_u16, in_NOP_w_rm_mod_reg_u16, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_st_w_d_0F_1F[] = {
	// 00
	in_NOP_w_rm_mod_reg_u16, in_NOP_w_rm_mod_reg_u16, in_NOP_w_rm_mod_reg_u16, in_NOP_w_rm_mod_reg_u16, in_NOP_w_rm_mod_reg_u16, in_NOP_w_rm_mod_reg_u16, in_NOP_w_rm_mod_reg_u16, in_NOP_w_rm_mod_reg_u16, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_NOP_w_rm_mod_reg_u16, in_NOP_w_rm_mod_reg_u16, in_NOP_w_rm_mod_reg_u16, in_NOP_w_rm_mod_reg_u16, in_NOP_w_rm_mod_reg_u16, in_NOP_w_rm_mod_reg_u16, in_NOP_w_rm_mod_reg_u16, in_NOP_w_rm_mod_reg_u16, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_NOP_w_rm_mod_reg_u16, in_NOP_w_rm_mod_reg_u16, in_NOP_w_rm_mod_reg_u16, in_NOP_w_rm_mod_reg_u16, in_NOP_w_rm_mod_reg_u16, in_NOP_w_rm_mod_reg_u16, in_NOP_w_rm_mod_reg_u16, in_NOP_w_rm_mod_reg_u16, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_NOP_w_rm_mod_reg_u16, in_NOP_w_rm_mod_reg_u16, in_NOP_w_rm_mod_reg_u16, in_NOP_w_rm_mod_reg_u16, in_NOP_w_rm_mod_reg_u16, in_NOP_w_rm_mod_reg_u16, in_NOP_w_rm_mod_reg_u16, in_NOP_w_rm_mod_reg_u16, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_st_d_w_0F_1F[] = {
	// 00
	in_NOP_d_rm_mod_reg_u16, in_NOP_d_rm_mod_reg_u16, in_NOP_d_rm_mod_reg_u16, in_NOP_d_rm_mod_reg_u16, in_NOP_d_rm_mod_reg_u16, in_NOP_d_rm_mod_reg_u16, in_NOP_d_rm_mod_reg_u16, in_NOP_d_rm_mod_reg_u16, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_NOP_d_rm_mod_reg_u16, in_NOP_d_rm_mod_reg_u16, in_NOP_d_rm_mod_reg_u16, in_NOP_d_rm_mod_reg_u16, in_NOP_d_rm_mod_reg_u16, in_NOP_d_rm_mod_reg_u16, in_NOP_d_rm_mod_reg_u16, in_NOP_d_rm_mod_reg_u16, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_NOP_d_rm_mod_reg_u16, in_NOP_d_rm_mod_reg_u16, in_NOP_d_rm_mod_reg_u16, in_NOP_d_rm_mod_reg_u16, in_NOP_d_rm_mod_reg_u16, in_NOP_d_rm_mod_reg_u16, in_NOP_d_rm_mod_reg_u16, in_NOP_d_rm_mod_reg_u16, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_NOP_d_rm_mod_reg_u16, in_NOP_d_rm_mod_reg_u16, in_NOP_d_rm_mod_reg_u16, in_NOP_d_rm_mod_reg_u16, in_NOP_d_rm_mod_reg_u16, in_NOP_d_rm_mod_reg_u16, in_NOP_d_rm_mod_reg_u16, in_NOP_d_rm_mod_reg_u16, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_st_d_d_0F_1F[] = {
	// 00
	in_NOP_d_rm_mod_reg_u16, in_NOP_d_rm_mod_reg_u16, in_NOP_d_rm_mod_reg_u16, in_NOP_d_rm_mod_reg_u16, in_NOP_d_rm_mod_reg_u16, in_NOP_d_rm_mod_reg_u16, in_NOP_d_rm_mod_reg_u16, in_NOP_d_rm_mod_reg_u16, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_NOP_d_rm_mod_reg_u16, in_NOP_d_rm_mod_reg_u16, in_NOP_d_rm_mod_reg_u16, in_NOP_d_rm_mod_reg_u16, in_NOP_d_rm_mod_reg_u16, in_NOP_d_rm_mod_reg_u16, in_NOP_d_rm_mod_reg_u16, in_NOP_d_rm_mod_reg_u16, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_NOP_d_rm_mod_reg_u16, in_NOP_d_rm_mod_reg_u16, in_NOP_d_rm_mod_reg_u16, in_NOP_d_rm_mod_reg_u16, in_NOP_d_rm_mod_reg_u16, in_NOP_d_rm_mod_reg_u16, in_NOP_d_rm_mod_reg_u16, in_NOP_d_rm_mod_reg_u16, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_NOP_d_rm_mod_reg_u16, in_NOP_d_rm_mod_reg_u16, in_NOP_d_rm_mod_reg_u16, in_NOP_d_rm_mod_reg_u16, in_NOP_d_rm_mod_reg_u16, in_NOP_d_rm_mod_reg_u16, in_NOP_d_rm_mod_reg_u16, in_NOP_d_rm_mod_reg_u16, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_st_w_w_0F_38[] = {
	// 00
	in_PSHUFB_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PHADDW_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PHADDD_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PHADDSW_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PMADDUBSW_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PHSUBW_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PHSUBD_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PHSUBSW_w_rm_reg_mmx_u64_rm_mod_mmx_u64, 
	// 08
	in_PSIGNB_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PSIGNW_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PSIGND_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PMULHRSW_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_PABSB_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PABSW_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PABSD_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_MOVBE_w_rm_reg_reg_u16_rm_mem_u16, in_MOVBE_w_rm_mem_u16_rm_reg_reg_u16, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_st_w_d_0F_38[] = {
	// 00
	in_PSHUFB_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PHADDW_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PHADDD_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PHADDSW_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PMADDUBSW_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PHSUBW_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PHSUBD_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PHSUBSW_w_rm_reg_mmx_u64_rm_mod_mmx_u64, 
	// 08
	in_PSIGNB_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PSIGNW_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PSIGND_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PMULHRSW_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_PABSB_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PABSW_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PABSD_w_rm_reg_mmx_u64_rm_mod_mmx_u64, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_MOVBE_w_rm_reg_reg_u16_rm_mem_u16, in_MOVBE_w_rm_mem_u16_rm_reg_reg_u16, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_st_d_w_0F_38[] = {
	// 00
	in_PSHUFB_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PHADDW_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PHADDD_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PHADDSW_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PMADDUBSW_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PHSUBW_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PHSUBD_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PHSUBSW_d_rm_reg_mmx_u64_rm_mod_mmx_u64, 
	// 08
	in_PSIGNB_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PSIGNW_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PSIGND_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PMULHRSW_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_PABSB_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PABSW_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PABSD_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_MOVBE_d_rm_reg_reg_u16_rm_mem_u16, in_MOVBE_d_rm_mem_u16_rm_reg_reg_u16, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_st_d_d_0F_38[] = {
	// 00
	in_PSHUFB_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PHADDW_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PHADDD_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PHADDSW_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PMADDUBSW_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PHSUBW_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PHSUBD_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PHSUBSW_d_rm_reg_mmx_u64_rm_mod_mmx_u64, 
	// 08
	in_PSIGNB_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PSIGNW_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PSIGND_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PMULHRSW_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_PABSB_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PABSW_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_PABSD_d_rm_reg_mmx_u64_rm_mod_mmx_u64, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_MOVBE_d_rm_reg_reg_u16_rm_mem_u16, in_MOVBE_d_rm_mem_u16_rm_reg_reg_u16, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_st_w_w_0F_3A[] = {
	// 00
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_PALIGNR_w_rm_reg_mmx_u64_rm_mod_mmx_u64, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_st_w_d_0F_3A[] = {
	// 00
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_PALIGNR_w_rm_reg_mmx_u64_rm_mod_mmx_u64, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_st_d_w_0F_3A[] = {
	// 00
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_PALIGNR_d_rm_reg_mmx_u64_rm_mod_mmx_u64, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_st_d_d_0F_3A[] = {
	// 00
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_PALIGNR_d_rm_reg_mmx_u64_rm_mod_mmx_u64, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_st_w_w_0F_71[] = {
	// 00
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_PSRLW_w_rm_rm_mmx_u64_imm_u8, in_PSRLW_w_rm_rm_mmx_u64_imm_u8, in_PSRLW_w_rm_rm_mmx_u64_imm_u8, in_PSRLW_w_rm_rm_mmx_u64_imm_u8, in_PSRLW_w_rm_rm_mmx_u64_imm_u8, in_PSRLW_w_rm_rm_mmx_u64_imm_u8, in_PSRLW_w_rm_rm_mmx_u64_imm_u8, in_PSRLW_w_rm_rm_mmx_u64_imm_u8, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_PSRAW_w_rm_rm_mmx_u64_imm_u8, in_PSRAW_w_rm_rm_mmx_u64_imm_u8, in_PSRAW_w_rm_rm_mmx_u64_imm_u8, in_PSRAW_w_rm_rm_mmx_u64_imm_u8, in_PSRAW_w_rm_rm_mmx_u64_imm_u8, in_PSRAW_w_rm_rm_mmx_u64_imm_u8, in_PSRAW_w_rm_rm_mmx_u64_imm_u8, in_PSRAW_w_rm_rm_mmx_u64_imm_u8, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_PSLLW_w_rm_rm_mmx_u64_imm_u8, in_PSLLW_w_rm_rm_mmx_u64_imm_u8, in_PSLLW_w_rm_rm_mmx_u64_imm_u8, in_PSLLW_w_rm_rm_mmx_u64_imm_u8, in_PSLLW_w_rm_rm_mmx_u64_imm_u8, in_PSLLW_w_rm_rm_mmx_u64_imm_u8, in_PSLLW_w_rm_rm_mmx_u64_imm_u8, in_PSLLW_w_rm_rm_mmx_u64_imm_u8, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_PSRLW_w_rm_rm_mmx_u64_imm_u8, in_PSRLW_w_rm_rm_mmx_u64_imm_u8, in_PSRLW_w_rm_rm_mmx_u64_imm_u8, in_PSRLW_w_rm_rm_mmx_u64_imm_u8, in_PSRLW_w_rm_rm_mmx_u64_imm_u8, in_PSRLW_w_rm_rm_mmx_u64_imm_u8, in_PSRLW_w_rm_rm_mmx_u64_imm_u8, in_PSRLW_w_rm_rm_mmx_u64_imm_u8, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_PSRAW_w_rm_rm_mmx_u64_imm_u8, in_PSRAW_w_rm_rm_mmx_u64_imm_u8, in_PSRAW_w_rm_rm_mmx_u64_imm_u8, in_PSRAW_w_rm_rm_mmx_u64_imm_u8, in_PSRAW_w_rm_rm_mmx_u64_imm_u8, in_PSRAW_w_rm_rm_mmx_u64_imm_u8, in_PSRAW_w_rm_rm_mmx_u64_imm_u8, in_PSRAW_w_rm_rm_mmx_u64_imm_u8, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_PSLLW_w_rm_rm_mmx_u64_imm_u8, in_PSLLW_w_rm_rm_mmx_u64_imm_u8, in_PSLLW_w_rm_rm_mmx_u64_imm_u8, in_PSLLW_w_rm_rm_mmx_u64_imm_u8, in_PSLLW_w_rm_rm_mmx_u64_imm_u8, in_PSLLW_w_rm_rm_mmx_u64_imm_u8, in_PSLLW_w_rm_rm_mmx_u64_imm_u8, in_PSLLW_w_rm_rm_mmx_u64_imm_u8, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_PSRLW_w_rm_rm_mmx_u64_imm_u8, in_PSRLW_w_rm_rm_mmx_u64_imm_u8, in_PSRLW_w_rm_rm_mmx_u64_imm_u8, in_PSRLW_w_rm_rm_mmx_u64_imm_u8, in_PSRLW_w_rm_rm_mmx_u64_imm_u8, in_PSRLW_w_rm_rm_mmx_u64_imm_u8, in_PSRLW_w_rm_rm_mmx_u64_imm_u8, in_PSRLW_w_rm_rm_mmx_u64_imm_u8, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_PSRAW_w_rm_rm_mmx_u64_imm_u8, in_PSRAW_w_rm_rm_mmx_u64_imm_u8, in_PSRAW_w_rm_rm_mmx_u64_imm_u8, in_PSRAW_w_rm_rm_mmx_u64_imm_u8, in_PSRAW_w_rm_rm_mmx_u64_imm_u8, in_PSRAW_w_rm_rm_mmx_u64_imm_u8, in_PSRAW_w_rm_rm_mmx_u64_imm_u8, in_PSRAW_w_rm_rm_mmx_u64_imm_u8, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_PSLLW_w_rm_rm_mmx_u64_imm_u8, in_PSLLW_w_rm_rm_mmx_u64_imm_u8, in_PSLLW_w_rm_rm_mmx_u64_imm_u8, in_PSLLW_w_rm_rm_mmx_u64_imm_u8, in_PSLLW_w_rm_rm_mmx_u64_imm_u8, in_PSLLW_w_rm_rm_mmx_u64_imm_u8, in_PSLLW_w_rm_rm_mmx_u64_imm_u8, in_PSLLW_w_rm_rm_mmx_u64_imm_u8, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_PSRLW_w_rm_rm_mmx_u64_imm_u8, in_PSRLW_w_rm_rm_mmx_u64_imm_u8, in_PSRLW_w_rm_rm_mmx_u64_imm_u8, in_PSRLW_w_rm_rm_mmx_u64_imm_u8, in_PSRLW_w_rm_rm_mmx_u64_imm_u8, in_PSRLW_w_rm_rm_mmx_u64_imm_u8, in_PSRLW_w_rm_rm_mmx_u64_imm_u8, in_PSRLW_w_rm_rm_mmx_u64_imm_u8, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_PSRAW_w_rm_rm_mmx_u64_imm_u8, in_PSRAW_w_rm_rm_mmx_u64_imm_u8, in_PSRAW_w_rm_rm_mmx_u64_imm_u8, in_PSRAW_w_rm_rm_mmx_u64_imm_u8, in_PSRAW_w_rm_rm_mmx_u64_imm_u8, in_PSRAW_w_rm_rm_mmx_u64_imm_u8, in_PSRAW_w_rm_rm_mmx_u64_imm_u8, in_PSRAW_w_rm_rm_mmx_u64_imm_u8, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_PSLLW_w_rm_rm_mmx_u64_imm_u8, in_PSLLW_w_rm_rm_mmx_u64_imm_u8, in_PSLLW_w_rm_rm_mmx_u64_imm_u8, in_PSLLW_w_rm_rm_mmx_u64_imm_u8, in_PSLLW_w_rm_rm_mmx_u64_imm_u8, in_PSLLW_w_rm_rm_mmx_u64_imm_u8, in_PSLLW_w_rm_rm_mmx_u64_imm_u8, in_PSLLW_w_rm_rm_mmx_u64_imm_u8, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_st_w_d_0F_71[] = {
	// 00
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_PSRLW_w_rm_rm_mmx_u64_imm_u8, in_PSRLW_w_rm_rm_mmx_u64_imm_u8, in_PSRLW_w_rm_rm_mmx_u64_imm_u8, in_PSRLW_w_rm_rm_mmx_u64_imm_u8, in_PSRLW_w_rm_rm_mmx_u64_imm_u8, in_PSRLW_w_rm_rm_mmx_u64_imm_u8, in_PSRLW_w_rm_rm_mmx_u64_imm_u8, in_PSRLW_w_rm_rm_mmx_u64_imm_u8, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_PSRAW_w_rm_rm_mmx_u64_imm_u8, in_PSRAW_w_rm_rm_mmx_u64_imm_u8, in_PSRAW_w_rm_rm_mmx_u64_imm_u8, in_PSRAW_w_rm_rm_mmx_u64_imm_u8, in_PSRAW_w_rm_rm_mmx_u64_imm_u8, in_PSRAW_w_rm_rm_mmx_u64_imm_u8, in_PSRAW_w_rm_rm_mmx_u64_imm_u8, in_PSRAW_w_rm_rm_mmx_u64_imm_u8, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_PSLLW_w_rm_rm_mmx_u64_imm_u8, in_PSLLW_w_rm_rm_mmx_u64_imm_u8, in_PSLLW_w_rm_rm_mmx_u64_imm_u8, in_PSLLW_w_rm_rm_mmx_u64_imm_u8, in_PSLLW_w_rm_rm_mmx_u64_imm_u8, in_PSLLW_w_rm_rm_mmx_u64_imm_u8, in_PSLLW_w_rm_rm_mmx_u64_imm_u8, in_PSLLW_w_rm_rm_mmx_u64_imm_u8, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_PSRLW_w_rm_rm_mmx_u64_imm_u8, in_PSRLW_w_rm_rm_mmx_u64_imm_u8, in_PSRLW_w_rm_rm_mmx_u64_imm_u8, in_PSRLW_w_rm_rm_mmx_u64_imm_u8, in_PSRLW_w_rm_rm_mmx_u64_imm_u8, in_PSRLW_w_rm_rm_mmx_u64_imm_u8, in_PSRLW_w_rm_rm_mmx_u64_imm_u8, in_PSRLW_w_rm_rm_mmx_u64_imm_u8, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_PSRAW_w_rm_rm_mmx_u64_imm_u8, in_PSRAW_w_rm_rm_mmx_u64_imm_u8, in_PSRAW_w_rm_rm_mmx_u64_imm_u8, in_PSRAW_w_rm_rm_mmx_u64_imm_u8, in_PSRAW_w_rm_rm_mmx_u64_imm_u8, in_PSRAW_w_rm_rm_mmx_u64_imm_u8, in_PSRAW_w_rm_rm_mmx_u64_imm_u8, in_PSRAW_w_rm_rm_mmx_u64_imm_u8, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_PSLLW_w_rm_rm_mmx_u64_imm_u8, in_PSLLW_w_rm_rm_mmx_u64_imm_u8, in_PSLLW_w_rm_rm_mmx_u64_imm_u8, in_PSLLW_w_rm_rm_mmx_u64_imm_u8, in_PSLLW_w_rm_rm_mmx_u64_imm_u8, in_PSLLW_w_rm_rm_mmx_u64_imm_u8, in_PSLLW_w_rm_rm_mmx_u64_imm_u8, in_PSLLW_w_rm_rm_mmx_u64_imm_u8, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_PSRLW_w_rm_rm_mmx_u64_imm_u8, in_PSRLW_w_rm_rm_mmx_u64_imm_u8, in_PSRLW_w_rm_rm_mmx_u64_imm_u8, in_PSRLW_w_rm_rm_mmx_u64_imm_u8, in_PSRLW_w_rm_rm_mmx_u64_imm_u8, in_PSRLW_w_rm_rm_mmx_u64_imm_u8, in_PSRLW_w_rm_rm_mmx_u64_imm_u8, in_PSRLW_w_rm_rm_mmx_u64_imm_u8, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_PSRAW_w_rm_rm_mmx_u64_imm_u8, in_PSRAW_w_rm_rm_mmx_u64_imm_u8, in_PSRAW_w_rm_rm_mmx_u64_imm_u8, in_PSRAW_w_rm_rm_mmx_u64_imm_u8, in_PSRAW_w_rm_rm_mmx_u64_imm_u8, in_PSRAW_w_rm_rm_mmx_u64_imm_u8, in_PSRAW_w_rm_rm_mmx_u64_imm_u8, in_PSRAW_w_rm_rm_mmx_u64_imm_u8, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_PSLLW_w_rm_rm_mmx_u64_imm_u8, in_PSLLW_w_rm_rm_mmx_u64_imm_u8, in_PSLLW_w_rm_rm_mmx_u64_imm_u8, in_PSLLW_w_rm_rm_mmx_u64_imm_u8, in_PSLLW_w_rm_rm_mmx_u64_imm_u8, in_PSLLW_w_rm_rm_mmx_u64_imm_u8, in_PSLLW_w_rm_rm_mmx_u64_imm_u8, in_PSLLW_w_rm_rm_mmx_u64_imm_u8, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_PSRLW_w_rm_rm_mmx_u64_imm_u8, in_PSRLW_w_rm_rm_mmx_u64_imm_u8, in_PSRLW_w_rm_rm_mmx_u64_imm_u8, in_PSRLW_w_rm_rm_mmx_u64_imm_u8, in_PSRLW_w_rm_rm_mmx_u64_imm_u8, in_PSRLW_w_rm_rm_mmx_u64_imm_u8, in_PSRLW_w_rm_rm_mmx_u64_imm_u8, in_PSRLW_w_rm_rm_mmx_u64_imm_u8, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_PSRAW_w_rm_rm_mmx_u64_imm_u8, in_PSRAW_w_rm_rm_mmx_u64_imm_u8, in_PSRAW_w_rm_rm_mmx_u64_imm_u8, in_PSRAW_w_rm_rm_mmx_u64_imm_u8, in_PSRAW_w_rm_rm_mmx_u64_imm_u8, in_PSRAW_w_rm_rm_mmx_u64_imm_u8, in_PSRAW_w_rm_rm_mmx_u64_imm_u8, in_PSRAW_w_rm_rm_mmx_u64_imm_u8, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_PSLLW_w_rm_rm_mmx_u64_imm_u8, in_PSLLW_w_rm_rm_mmx_u64_imm_u8, in_PSLLW_w_rm_rm_mmx_u64_imm_u8, in_PSLLW_w_rm_rm_mmx_u64_imm_u8, in_PSLLW_w_rm_rm_mmx_u64_imm_u8, in_PSLLW_w_rm_rm_mmx_u64_imm_u8, in_PSLLW_w_rm_rm_mmx_u64_imm_u8, in_PSLLW_w_rm_rm_mmx_u64_imm_u8, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_st_d_w_0F_71[] = {
	// 00
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_PSRLW_d_rm_rm_mmx_u64_imm_u8, in_PSRLW_d_rm_rm_mmx_u64_imm_u8, in_PSRLW_d_rm_rm_mmx_u64_imm_u8, in_PSRLW_d_rm_rm_mmx_u64_imm_u8, in_PSRLW_d_rm_rm_mmx_u64_imm_u8, in_PSRLW_d_rm_rm_mmx_u64_imm_u8, in_PSRLW_d_rm_rm_mmx_u64_imm_u8, in_PSRLW_d_rm_rm_mmx_u64_imm_u8, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_PSRAW_d_rm_rm_mmx_u64_imm_u8, in_PSRAW_d_rm_rm_mmx_u64_imm_u8, in_PSRAW_d_rm_rm_mmx_u64_imm_u8, in_PSRAW_d_rm_rm_mmx_u64_imm_u8, in_PSRAW_d_rm_rm_mmx_u64_imm_u8, in_PSRAW_d_rm_rm_mmx_u64_imm_u8, in_PSRAW_d_rm_rm_mmx_u64_imm_u8, in_PSRAW_d_rm_rm_mmx_u64_imm_u8, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_PSLLW_d_rm_rm_mmx_u64_imm_u8, in_PSLLW_d_rm_rm_mmx_u64_imm_u8, in_PSLLW_d_rm_rm_mmx_u64_imm_u8, in_PSLLW_d_rm_rm_mmx_u64_imm_u8, in_PSLLW_d_rm_rm_mmx_u64_imm_u8, in_PSLLW_d_rm_rm_mmx_u64_imm_u8, in_PSLLW_d_rm_rm_mmx_u64_imm_u8, in_PSLLW_d_rm_rm_mmx_u64_imm_u8, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_PSRLW_d_rm_rm_mmx_u64_imm_u8, in_PSRLW_d_rm_rm_mmx_u64_imm_u8, in_PSRLW_d_rm_rm_mmx_u64_imm_u8, in_PSRLW_d_rm_rm_mmx_u64_imm_u8, in_PSRLW_d_rm_rm_mmx_u64_imm_u8, in_PSRLW_d_rm_rm_mmx_u64_imm_u8, in_PSRLW_d_rm_rm_mmx_u64_imm_u8, in_PSRLW_d_rm_rm_mmx_u64_imm_u8, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_PSRAW_d_rm_rm_mmx_u64_imm_u8, in_PSRAW_d_rm_rm_mmx_u64_imm_u8, in_PSRAW_d_rm_rm_mmx_u64_imm_u8, in_PSRAW_d_rm_rm_mmx_u64_imm_u8, in_PSRAW_d_rm_rm_mmx_u64_imm_u8, in_PSRAW_d_rm_rm_mmx_u64_imm_u8, in_PSRAW_d_rm_rm_mmx_u64_imm_u8, in_PSRAW_d_rm_rm_mmx_u64_imm_u8, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_PSLLW_d_rm_rm_mmx_u64_imm_u8, in_PSLLW_d_rm_rm_mmx_u64_imm_u8, in_PSLLW_d_rm_rm_mmx_u64_imm_u8, in_PSLLW_d_rm_rm_mmx_u64_imm_u8, in_PSLLW_d_rm_rm_mmx_u64_imm_u8, in_PSLLW_d_rm_rm_mmx_u64_imm_u8, in_PSLLW_d_rm_rm_mmx_u64_imm_u8, in_PSLLW_d_rm_rm_mmx_u64_imm_u8, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_PSRLW_d_rm_rm_mmx_u64_imm_u8, in_PSRLW_d_rm_rm_mmx_u64_imm_u8, in_PSRLW_d_rm_rm_mmx_u64_imm_u8, in_PSRLW_d_rm_rm_mmx_u64_imm_u8, in_PSRLW_d_rm_rm_mmx_u64_imm_u8, in_PSRLW_d_rm_rm_mmx_u64_imm_u8, in_PSRLW_d_rm_rm_mmx_u64_imm_u8, in_PSRLW_d_rm_rm_mmx_u64_imm_u8, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_PSRAW_d_rm_rm_mmx_u64_imm_u8, in_PSRAW_d_rm_rm_mmx_u64_imm_u8, in_PSRAW_d_rm_rm_mmx_u64_imm_u8, in_PSRAW_d_rm_rm_mmx_u64_imm_u8, in_PSRAW_d_rm_rm_mmx_u64_imm_u8, in_PSRAW_d_rm_rm_mmx_u64_imm_u8, in_PSRAW_d_rm_rm_mmx_u64_imm_u8, in_PSRAW_d_rm_rm_mmx_u64_imm_u8, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_PSLLW_d_rm_rm_mmx_u64_imm_u8, in_PSLLW_d_rm_rm_mmx_u64_imm_u8, in_PSLLW_d_rm_rm_mmx_u64_imm_u8, in_PSLLW_d_rm_rm_mmx_u64_imm_u8, in_PSLLW_d_rm_rm_mmx_u64_imm_u8, in_PSLLW_d_rm_rm_mmx_u64_imm_u8, in_PSLLW_d_rm_rm_mmx_u64_imm_u8, in_PSLLW_d_rm_rm_mmx_u64_imm_u8, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_PSRLW_d_rm_rm_mmx_u64_imm_u8, in_PSRLW_d_rm_rm_mmx_u64_imm_u8, in_PSRLW_d_rm_rm_mmx_u64_imm_u8, in_PSRLW_d_rm_rm_mmx_u64_imm_u8, in_PSRLW_d_rm_rm_mmx_u64_imm_u8, in_PSRLW_d_rm_rm_mmx_u64_imm_u8, in_PSRLW_d_rm_rm_mmx_u64_imm_u8, in_PSRLW_d_rm_rm_mmx_u64_imm_u8, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_PSRAW_d_rm_rm_mmx_u64_imm_u8, in_PSRAW_d_rm_rm_mmx_u64_imm_u8, in_PSRAW_d_rm_rm_mmx_u64_imm_u8, in_PSRAW_d_rm_rm_mmx_u64_imm_u8, in_PSRAW_d_rm_rm_mmx_u64_imm_u8, in_PSRAW_d_rm_rm_mmx_u64_imm_u8, in_PSRAW_d_rm_rm_mmx_u64_imm_u8, in_PSRAW_d_rm_rm_mmx_u64_imm_u8, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_PSLLW_d_rm_rm_mmx_u64_imm_u8, in_PSLLW_d_rm_rm_mmx_u64_imm_u8, in_PSLLW_d_rm_rm_mmx_u64_imm_u8, in_PSLLW_d_rm_rm_mmx_u64_imm_u8, in_PSLLW_d_rm_rm_mmx_u64_imm_u8, in_PSLLW_d_rm_rm_mmx_u64_imm_u8, in_PSLLW_d_rm_rm_mmx_u64_imm_u8, in_PSLLW_d_rm_rm_mmx_u64_imm_u8, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_st_d_d_0F_71[] = {
	// 00
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_PSRLW_d_rm_rm_mmx_u64_imm_u8, in_PSRLW_d_rm_rm_mmx_u64_imm_u8, in_PSRLW_d_rm_rm_mmx_u64_imm_u8, in_PSRLW_d_rm_rm_mmx_u64_imm_u8, in_PSRLW_d_rm_rm_mmx_u64_imm_u8, in_PSRLW_d_rm_rm_mmx_u64_imm_u8, in_PSRLW_d_rm_rm_mmx_u64_imm_u8, in_PSRLW_d_rm_rm_mmx_u64_imm_u8, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_PSRAW_d_rm_rm_mmx_u64_imm_u8, in_PSRAW_d_rm_rm_mmx_u64_imm_u8, in_PSRAW_d_rm_rm_mmx_u64_imm_u8, in_PSRAW_d_rm_rm_mmx_u64_imm_u8, in_PSRAW_d_rm_rm_mmx_u64_imm_u8, in_PSRAW_d_rm_rm_mmx_u64_imm_u8, in_PSRAW_d_rm_rm_mmx_u64_imm_u8, in_PSRAW_d_rm_rm_mmx_u64_imm_u8, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_PSLLW_d_rm_rm_mmx_u64_imm_u8, in_PSLLW_d_rm_rm_mmx_u64_imm_u8, in_PSLLW_d_rm_rm_mmx_u64_imm_u8, in_PSLLW_d_rm_rm_mmx_u64_imm_u8, in_PSLLW_d_rm_rm_mmx_u64_imm_u8, in_PSLLW_d_rm_rm_mmx_u64_imm_u8, in_PSLLW_d_rm_rm_mmx_u64_imm_u8, in_PSLLW_d_rm_rm_mmx_u64_imm_u8, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_PSRLW_d_rm_rm_mmx_u64_imm_u8, in_PSRLW_d_rm_rm_mmx_u64_imm_u8, in_PSRLW_d_rm_rm_mmx_u64_imm_u8, in_PSRLW_d_rm_rm_mmx_u64_imm_u8, in_PSRLW_d_rm_rm_mmx_u64_imm_u8, in_PSRLW_d_rm_rm_mmx_u64_imm_u8, in_PSRLW_d_rm_rm_mmx_u64_imm_u8, in_PSRLW_d_rm_rm_mmx_u64_imm_u8, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_PSRAW_d_rm_rm_mmx_u64_imm_u8, in_PSRAW_d_rm_rm_mmx_u64_imm_u8, in_PSRAW_d_rm_rm_mmx_u64_imm_u8, in_PSRAW_d_rm_rm_mmx_u64_imm_u8, in_PSRAW_d_rm_rm_mmx_u64_imm_u8, in_PSRAW_d_rm_rm_mmx_u64_imm_u8, in_PSRAW_d_rm_rm_mmx_u64_imm_u8, in_PSRAW_d_rm_rm_mmx_u64_imm_u8, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_PSLLW_d_rm_rm_mmx_u64_imm_u8, in_PSLLW_d_rm_rm_mmx_u64_imm_u8, in_PSLLW_d_rm_rm_mmx_u64_imm_u8, in_PSLLW_d_rm_rm_mmx_u64_imm_u8, in_PSLLW_d_rm_rm_mmx_u64_imm_u8, in_PSLLW_d_rm_rm_mmx_u64_imm_u8, in_PSLLW_d_rm_rm_mmx_u64_imm_u8, in_PSLLW_d_rm_rm_mmx_u64_imm_u8, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_PSRLW_d_rm_rm_mmx_u64_imm_u8, in_PSRLW_d_rm_rm_mmx_u64_imm_u8, in_PSRLW_d_rm_rm_mmx_u64_imm_u8, in_PSRLW_d_rm_rm_mmx_u64_imm_u8, in_PSRLW_d_rm_rm_mmx_u64_imm_u8, in_PSRLW_d_rm_rm_mmx_u64_imm_u8, in_PSRLW_d_rm_rm_mmx_u64_imm_u8, in_PSRLW_d_rm_rm_mmx_u64_imm_u8, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_PSRAW_d_rm_rm_mmx_u64_imm_u8, in_PSRAW_d_rm_rm_mmx_u64_imm_u8, in_PSRAW_d_rm_rm_mmx_u64_imm_u8, in_PSRAW_d_rm_rm_mmx_u64_imm_u8, in_PSRAW_d_rm_rm_mmx_u64_imm_u8, in_PSRAW_d_rm_rm_mmx_u64_imm_u8, in_PSRAW_d_rm_rm_mmx_u64_imm_u8, in_PSRAW_d_rm_rm_mmx_u64_imm_u8, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_PSLLW_d_rm_rm_mmx_u64_imm_u8, in_PSLLW_d_rm_rm_mmx_u64_imm_u8, in_PSLLW_d_rm_rm_mmx_u64_imm_u8, in_PSLLW_d_rm_rm_mmx_u64_imm_u8, in_PSLLW_d_rm_rm_mmx_u64_imm_u8, in_PSLLW_d_rm_rm_mmx_u64_imm_u8, in_PSLLW_d_rm_rm_mmx_u64_imm_u8, in_PSLLW_d_rm_rm_mmx_u64_imm_u8, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_PSRLW_d_rm_rm_mmx_u64_imm_u8, in_PSRLW_d_rm_rm_mmx_u64_imm_u8, in_PSRLW_d_rm_rm_mmx_u64_imm_u8, in_PSRLW_d_rm_rm_mmx_u64_imm_u8, in_PSRLW_d_rm_rm_mmx_u64_imm_u8, in_PSRLW_d_rm_rm_mmx_u64_imm_u8, in_PSRLW_d_rm_rm_mmx_u64_imm_u8, in_PSRLW_d_rm_rm_mmx_u64_imm_u8, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_PSRAW_d_rm_rm_mmx_u64_imm_u8, in_PSRAW_d_rm_rm_mmx_u64_imm_u8, in_PSRAW_d_rm_rm_mmx_u64_imm_u8, in_PSRAW_d_rm_rm_mmx_u64_imm_u8, in_PSRAW_d_rm_rm_mmx_u64_imm_u8, in_PSRAW_d_rm_rm_mmx_u64_imm_u8, in_PSRAW_d_rm_rm_mmx_u64_imm_u8, in_PSRAW_d_rm_rm_mmx_u64_imm_u8, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_PSLLW_d_rm_rm_mmx_u64_imm_u8, in_PSLLW_d_rm_rm_mmx_u64_imm_u8, in_PSLLW_d_rm_rm_mmx_u64_imm_u8, in_PSLLW_d_rm_rm_mmx_u64_imm_u8, in_PSLLW_d_rm_rm_mmx_u64_imm_u8, in_PSLLW_d_rm_rm_mmx_u64_imm_u8, in_PSLLW_d_rm_rm_mmx_u64_imm_u8, in_PSLLW_d_rm_rm_mmx_u64_imm_u8, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_st_w_w_0F_72[] = {
	// 00
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_PSRLD_w_rm_rm_mmx_u64_imm_u8, in_PSRLD_w_rm_rm_mmx_u64_imm_u8, in_PSRLD_w_rm_rm_mmx_u64_imm_u8, in_PSRLD_w_rm_rm_mmx_u64_imm_u8, in_PSRLD_w_rm_rm_mmx_u64_imm_u8, in_PSRLD_w_rm_rm_mmx_u64_imm_u8, in_PSRLD_w_rm_rm_mmx_u64_imm_u8, in_PSRLD_w_rm_rm_mmx_u64_imm_u8, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_PSRAD_w_rm_rm_mmx_u64_imm_u8, in_PSRAD_w_rm_rm_mmx_u64_imm_u8, in_PSRAD_w_rm_rm_mmx_u64_imm_u8, in_PSRAD_w_rm_rm_mmx_u64_imm_u8, in_PSRAD_w_rm_rm_mmx_u64_imm_u8, in_PSRAD_w_rm_rm_mmx_u64_imm_u8, in_PSRAD_w_rm_rm_mmx_u64_imm_u8, in_PSRAD_w_rm_rm_mmx_u64_imm_u8, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_PSLLD_w_rm_rm_mmx_u64_imm_u8, in_PSLLD_w_rm_rm_mmx_u64_imm_u8, in_PSLLD_w_rm_rm_mmx_u64_imm_u8, in_PSLLD_w_rm_rm_mmx_u64_imm_u8, in_PSLLD_w_rm_rm_mmx_u64_imm_u8, in_PSLLD_w_rm_rm_mmx_u64_imm_u8, in_PSLLD_w_rm_rm_mmx_u64_imm_u8, in_PSLLD_w_rm_rm_mmx_u64_imm_u8, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_PSRLD_w_rm_rm_mmx_u64_imm_u8, in_PSRLD_w_rm_rm_mmx_u64_imm_u8, in_PSRLD_w_rm_rm_mmx_u64_imm_u8, in_PSRLD_w_rm_rm_mmx_u64_imm_u8, in_PSRLD_w_rm_rm_mmx_u64_imm_u8, in_PSRLD_w_rm_rm_mmx_u64_imm_u8, in_PSRLD_w_rm_rm_mmx_u64_imm_u8, in_PSRLD_w_rm_rm_mmx_u64_imm_u8, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_PSRAD_w_rm_rm_mmx_u64_imm_u8, in_PSRAD_w_rm_rm_mmx_u64_imm_u8, in_PSRAD_w_rm_rm_mmx_u64_imm_u8, in_PSRAD_w_rm_rm_mmx_u64_imm_u8, in_PSRAD_w_rm_rm_mmx_u64_imm_u8, in_PSRAD_w_rm_rm_mmx_u64_imm_u8, in_PSRAD_w_rm_rm_mmx_u64_imm_u8, in_PSRAD_w_rm_rm_mmx_u64_imm_u8, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_PSLLD_w_rm_rm_mmx_u64_imm_u8, in_PSLLD_w_rm_rm_mmx_u64_imm_u8, in_PSLLD_w_rm_rm_mmx_u64_imm_u8, in_PSLLD_w_rm_rm_mmx_u64_imm_u8, in_PSLLD_w_rm_rm_mmx_u64_imm_u8, in_PSLLD_w_rm_rm_mmx_u64_imm_u8, in_PSLLD_w_rm_rm_mmx_u64_imm_u8, in_PSLLD_w_rm_rm_mmx_u64_imm_u8, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_PSRLD_w_rm_rm_mmx_u64_imm_u8, in_PSRLD_w_rm_rm_mmx_u64_imm_u8, in_PSRLD_w_rm_rm_mmx_u64_imm_u8, in_PSRLD_w_rm_rm_mmx_u64_imm_u8, in_PSRLD_w_rm_rm_mmx_u64_imm_u8, in_PSRLD_w_rm_rm_mmx_u64_imm_u8, in_PSRLD_w_rm_rm_mmx_u64_imm_u8, in_PSRLD_w_rm_rm_mmx_u64_imm_u8, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_PSRAD_w_rm_rm_mmx_u64_imm_u8, in_PSRAD_w_rm_rm_mmx_u64_imm_u8, in_PSRAD_w_rm_rm_mmx_u64_imm_u8, in_PSRAD_w_rm_rm_mmx_u64_imm_u8, in_PSRAD_w_rm_rm_mmx_u64_imm_u8, in_PSRAD_w_rm_rm_mmx_u64_imm_u8, in_PSRAD_w_rm_rm_mmx_u64_imm_u8, in_PSRAD_w_rm_rm_mmx_u64_imm_u8, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_PSLLD_w_rm_rm_mmx_u64_imm_u8, in_PSLLD_w_rm_rm_mmx_u64_imm_u8, in_PSLLD_w_rm_rm_mmx_u64_imm_u8, in_PSLLD_w_rm_rm_mmx_u64_imm_u8, in_PSLLD_w_rm_rm_mmx_u64_imm_u8, in_PSLLD_w_rm_rm_mmx_u64_imm_u8, in_PSLLD_w_rm_rm_mmx_u64_imm_u8, in_PSLLD_w_rm_rm_mmx_u64_imm_u8, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_PSRLD_w_rm_rm_mmx_u64_imm_u8, in_PSRLD_w_rm_rm_mmx_u64_imm_u8, in_PSRLD_w_rm_rm_mmx_u64_imm_u8, in_PSRLD_w_rm_rm_mmx_u64_imm_u8, in_PSRLD_w_rm_rm_mmx_u64_imm_u8, in_PSRLD_w_rm_rm_mmx_u64_imm_u8, in_PSRLD_w_rm_rm_mmx_u64_imm_u8, in_PSRLD_w_rm_rm_mmx_u64_imm_u8, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_PSRAD_w_rm_rm_mmx_u64_imm_u8, in_PSRAD_w_rm_rm_mmx_u64_imm_u8, in_PSRAD_w_rm_rm_mmx_u64_imm_u8, in_PSRAD_w_rm_rm_mmx_u64_imm_u8, in_PSRAD_w_rm_rm_mmx_u64_imm_u8, in_PSRAD_w_rm_rm_mmx_u64_imm_u8, in_PSRAD_w_rm_rm_mmx_u64_imm_u8, in_PSRAD_w_rm_rm_mmx_u64_imm_u8, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_PSLLD_w_rm_rm_mmx_u64_imm_u8, in_PSLLD_w_rm_rm_mmx_u64_imm_u8, in_PSLLD_w_rm_rm_mmx_u64_imm_u8, in_PSLLD_w_rm_rm_mmx_u64_imm_u8, in_PSLLD_w_rm_rm_mmx_u64_imm_u8, in_PSLLD_w_rm_rm_mmx_u64_imm_u8, in_PSLLD_w_rm_rm_mmx_u64_imm_u8, in_PSLLD_w_rm_rm_mmx_u64_imm_u8, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_st_w_d_0F_72[] = {
	// 00
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_PSRLD_w_rm_rm_mmx_u64_imm_u8, in_PSRLD_w_rm_rm_mmx_u64_imm_u8, in_PSRLD_w_rm_rm_mmx_u64_imm_u8, in_PSRLD_w_rm_rm_mmx_u64_imm_u8, in_PSRLD_w_rm_rm_mmx_u64_imm_u8, in_PSRLD_w_rm_rm_mmx_u64_imm_u8, in_PSRLD_w_rm_rm_mmx_u64_imm_u8, in_PSRLD_w_rm_rm_mmx_u64_imm_u8, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_PSRAD_w_rm_rm_mmx_u64_imm_u8, in_PSRAD_w_rm_rm_mmx_u64_imm_u8, in_PSRAD_w_rm_rm_mmx_u64_imm_u8, in_PSRAD_w_rm_rm_mmx_u64_imm_u8, in_PSRAD_w_rm_rm_mmx_u64_imm_u8, in_PSRAD_w_rm_rm_mmx_u64_imm_u8, in_PSRAD_w_rm_rm_mmx_u64_imm_u8, in_PSRAD_w_rm_rm_mmx_u64_imm_u8, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_PSLLD_w_rm_rm_mmx_u64_imm_u8, in_PSLLD_w_rm_rm_mmx_u64_imm_u8, in_PSLLD_w_rm_rm_mmx_u64_imm_u8, in_PSLLD_w_rm_rm_mmx_u64_imm_u8, in_PSLLD_w_rm_rm_mmx_u64_imm_u8, in_PSLLD_w_rm_rm_mmx_u64_imm_u8, in_PSLLD_w_rm_rm_mmx_u64_imm_u8, in_PSLLD_w_rm_rm_mmx_u64_imm_u8, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_PSRLD_w_rm_rm_mmx_u64_imm_u8, in_PSRLD_w_rm_rm_mmx_u64_imm_u8, in_PSRLD_w_rm_rm_mmx_u64_imm_u8, in_PSRLD_w_rm_rm_mmx_u64_imm_u8, in_PSRLD_w_rm_rm_mmx_u64_imm_u8, in_PSRLD_w_rm_rm_mmx_u64_imm_u8, in_PSRLD_w_rm_rm_mmx_u64_imm_u8, in_PSRLD_w_rm_rm_mmx_u64_imm_u8, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_PSRAD_w_rm_rm_mmx_u64_imm_u8, in_PSRAD_w_rm_rm_mmx_u64_imm_u8, in_PSRAD_w_rm_rm_mmx_u64_imm_u8, in_PSRAD_w_rm_rm_mmx_u64_imm_u8, in_PSRAD_w_rm_rm_mmx_u64_imm_u8, in_PSRAD_w_rm_rm_mmx_u64_imm_u8, in_PSRAD_w_rm_rm_mmx_u64_imm_u8, in_PSRAD_w_rm_rm_mmx_u64_imm_u8, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_PSLLD_w_rm_rm_mmx_u64_imm_u8, in_PSLLD_w_rm_rm_mmx_u64_imm_u8, in_PSLLD_w_rm_rm_mmx_u64_imm_u8, in_PSLLD_w_rm_rm_mmx_u64_imm_u8, in_PSLLD_w_rm_rm_mmx_u64_imm_u8, in_PSLLD_w_rm_rm_mmx_u64_imm_u8, in_PSLLD_w_rm_rm_mmx_u64_imm_u8, in_PSLLD_w_rm_rm_mmx_u64_imm_u8, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_PSRLD_w_rm_rm_mmx_u64_imm_u8, in_PSRLD_w_rm_rm_mmx_u64_imm_u8, in_PSRLD_w_rm_rm_mmx_u64_imm_u8, in_PSRLD_w_rm_rm_mmx_u64_imm_u8, in_PSRLD_w_rm_rm_mmx_u64_imm_u8, in_PSRLD_w_rm_rm_mmx_u64_imm_u8, in_PSRLD_w_rm_rm_mmx_u64_imm_u8, in_PSRLD_w_rm_rm_mmx_u64_imm_u8, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_PSRAD_w_rm_rm_mmx_u64_imm_u8, in_PSRAD_w_rm_rm_mmx_u64_imm_u8, in_PSRAD_w_rm_rm_mmx_u64_imm_u8, in_PSRAD_w_rm_rm_mmx_u64_imm_u8, in_PSRAD_w_rm_rm_mmx_u64_imm_u8, in_PSRAD_w_rm_rm_mmx_u64_imm_u8, in_PSRAD_w_rm_rm_mmx_u64_imm_u8, in_PSRAD_w_rm_rm_mmx_u64_imm_u8, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_PSLLD_w_rm_rm_mmx_u64_imm_u8, in_PSLLD_w_rm_rm_mmx_u64_imm_u8, in_PSLLD_w_rm_rm_mmx_u64_imm_u8, in_PSLLD_w_rm_rm_mmx_u64_imm_u8, in_PSLLD_w_rm_rm_mmx_u64_imm_u8, in_PSLLD_w_rm_rm_mmx_u64_imm_u8, in_PSLLD_w_rm_rm_mmx_u64_imm_u8, in_PSLLD_w_rm_rm_mmx_u64_imm_u8, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_PSRLD_w_rm_rm_mmx_u64_imm_u8, in_PSRLD_w_rm_rm_mmx_u64_imm_u8, in_PSRLD_w_rm_rm_mmx_u64_imm_u8, in_PSRLD_w_rm_rm_mmx_u64_imm_u8, in_PSRLD_w_rm_rm_mmx_u64_imm_u8, in_PSRLD_w_rm_rm_mmx_u64_imm_u8, in_PSRLD_w_rm_rm_mmx_u64_imm_u8, in_PSRLD_w_rm_rm_mmx_u64_imm_u8, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_PSRAD_w_rm_rm_mmx_u64_imm_u8, in_PSRAD_w_rm_rm_mmx_u64_imm_u8, in_PSRAD_w_rm_rm_mmx_u64_imm_u8, in_PSRAD_w_rm_rm_mmx_u64_imm_u8, in_PSRAD_w_rm_rm_mmx_u64_imm_u8, in_PSRAD_w_rm_rm_mmx_u64_imm_u8, in_PSRAD_w_rm_rm_mmx_u64_imm_u8, in_PSRAD_w_rm_rm_mmx_u64_imm_u8, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_PSLLD_w_rm_rm_mmx_u64_imm_u8, in_PSLLD_w_rm_rm_mmx_u64_imm_u8, in_PSLLD_w_rm_rm_mmx_u64_imm_u8, in_PSLLD_w_rm_rm_mmx_u64_imm_u8, in_PSLLD_w_rm_rm_mmx_u64_imm_u8, in_PSLLD_w_rm_rm_mmx_u64_imm_u8, in_PSLLD_w_rm_rm_mmx_u64_imm_u8, in_PSLLD_w_rm_rm_mmx_u64_imm_u8, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_st_d_w_0F_72[] = {
	// 00
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_PSRLD_d_rm_rm_mmx_u64_imm_u8, in_PSRLD_d_rm_rm_mmx_u64_imm_u8, in_PSRLD_d_rm_rm_mmx_u64_imm_u8, in_PSRLD_d_rm_rm_mmx_u64_imm_u8, in_PSRLD_d_rm_rm_mmx_u64_imm_u8, in_PSRLD_d_rm_rm_mmx_u64_imm_u8, in_PSRLD_d_rm_rm_mmx_u64_imm_u8, in_PSRLD_d_rm_rm_mmx_u64_imm_u8, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_PSRAD_d_rm_rm_mmx_u64_imm_u8, in_PSRAD_d_rm_rm_mmx_u64_imm_u8, in_PSRAD_d_rm_rm_mmx_u64_imm_u8, in_PSRAD_d_rm_rm_mmx_u64_imm_u8, in_PSRAD_d_rm_rm_mmx_u64_imm_u8, in_PSRAD_d_rm_rm_mmx_u64_imm_u8, in_PSRAD_d_rm_rm_mmx_u64_imm_u8, in_PSRAD_d_rm_rm_mmx_u64_imm_u8, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_PSLLD_d_rm_rm_mmx_u64_imm_u8, in_PSLLD_d_rm_rm_mmx_u64_imm_u8, in_PSLLD_d_rm_rm_mmx_u64_imm_u8, in_PSLLD_d_rm_rm_mmx_u64_imm_u8, in_PSLLD_d_rm_rm_mmx_u64_imm_u8, in_PSLLD_d_rm_rm_mmx_u64_imm_u8, in_PSLLD_d_rm_rm_mmx_u64_imm_u8, in_PSLLD_d_rm_rm_mmx_u64_imm_u8, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_PSRLD_d_rm_rm_mmx_u64_imm_u8, in_PSRLD_d_rm_rm_mmx_u64_imm_u8, in_PSRLD_d_rm_rm_mmx_u64_imm_u8, in_PSRLD_d_rm_rm_mmx_u64_imm_u8, in_PSRLD_d_rm_rm_mmx_u64_imm_u8, in_PSRLD_d_rm_rm_mmx_u64_imm_u8, in_PSRLD_d_rm_rm_mmx_u64_imm_u8, in_PSRLD_d_rm_rm_mmx_u64_imm_u8, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_PSRAD_d_rm_rm_mmx_u64_imm_u8, in_PSRAD_d_rm_rm_mmx_u64_imm_u8, in_PSRAD_d_rm_rm_mmx_u64_imm_u8, in_PSRAD_d_rm_rm_mmx_u64_imm_u8, in_PSRAD_d_rm_rm_mmx_u64_imm_u8, in_PSRAD_d_rm_rm_mmx_u64_imm_u8, in_PSRAD_d_rm_rm_mmx_u64_imm_u8, in_PSRAD_d_rm_rm_mmx_u64_imm_u8, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_PSLLD_d_rm_rm_mmx_u64_imm_u8, in_PSLLD_d_rm_rm_mmx_u64_imm_u8, in_PSLLD_d_rm_rm_mmx_u64_imm_u8, in_PSLLD_d_rm_rm_mmx_u64_imm_u8, in_PSLLD_d_rm_rm_mmx_u64_imm_u8, in_PSLLD_d_rm_rm_mmx_u64_imm_u8, in_PSLLD_d_rm_rm_mmx_u64_imm_u8, in_PSLLD_d_rm_rm_mmx_u64_imm_u8, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_PSRLD_d_rm_rm_mmx_u64_imm_u8, in_PSRLD_d_rm_rm_mmx_u64_imm_u8, in_PSRLD_d_rm_rm_mmx_u64_imm_u8, in_PSRLD_d_rm_rm_mmx_u64_imm_u8, in_PSRLD_d_rm_rm_mmx_u64_imm_u8, in_PSRLD_d_rm_rm_mmx_u64_imm_u8, in_PSRLD_d_rm_rm_mmx_u64_imm_u8, in_PSRLD_d_rm_rm_mmx_u64_imm_u8, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_PSRAD_d_rm_rm_mmx_u64_imm_u8, in_PSRAD_d_rm_rm_mmx_u64_imm_u8, in_PSRAD_d_rm_rm_mmx_u64_imm_u8, in_PSRAD_d_rm_rm_mmx_u64_imm_u8, in_PSRAD_d_rm_rm_mmx_u64_imm_u8, in_PSRAD_d_rm_rm_mmx_u64_imm_u8, in_PSRAD_d_rm_rm_mmx_u64_imm_u8, in_PSRAD_d_rm_rm_mmx_u64_imm_u8, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_PSLLD_d_rm_rm_mmx_u64_imm_u8, in_PSLLD_d_rm_rm_mmx_u64_imm_u8, in_PSLLD_d_rm_rm_mmx_u64_imm_u8, in_PSLLD_d_rm_rm_mmx_u64_imm_u8, in_PSLLD_d_rm_rm_mmx_u64_imm_u8, in_PSLLD_d_rm_rm_mmx_u64_imm_u8, in_PSLLD_d_rm_rm_mmx_u64_imm_u8, in_PSLLD_d_rm_rm_mmx_u64_imm_u8, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_PSRLD_d_rm_rm_mmx_u64_imm_u8, in_PSRLD_d_rm_rm_mmx_u64_imm_u8, in_PSRLD_d_rm_rm_mmx_u64_imm_u8, in_PSRLD_d_rm_rm_mmx_u64_imm_u8, in_PSRLD_d_rm_rm_mmx_u64_imm_u8, in_PSRLD_d_rm_rm_mmx_u64_imm_u8, in_PSRLD_d_rm_rm_mmx_u64_imm_u8, in_PSRLD_d_rm_rm_mmx_u64_imm_u8, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_PSRAD_d_rm_rm_mmx_u64_imm_u8, in_PSRAD_d_rm_rm_mmx_u64_imm_u8, in_PSRAD_d_rm_rm_mmx_u64_imm_u8, in_PSRAD_d_rm_rm_mmx_u64_imm_u8, in_PSRAD_d_rm_rm_mmx_u64_imm_u8, in_PSRAD_d_rm_rm_mmx_u64_imm_u8, in_PSRAD_d_rm_rm_mmx_u64_imm_u8, in_PSRAD_d_rm_rm_mmx_u64_imm_u8, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_PSLLD_d_rm_rm_mmx_u64_imm_u8, in_PSLLD_d_rm_rm_mmx_u64_imm_u8, in_PSLLD_d_rm_rm_mmx_u64_imm_u8, in_PSLLD_d_rm_rm_mmx_u64_imm_u8, in_PSLLD_d_rm_rm_mmx_u64_imm_u8, in_PSLLD_d_rm_rm_mmx_u64_imm_u8, in_PSLLD_d_rm_rm_mmx_u64_imm_u8, in_PSLLD_d_rm_rm_mmx_u64_imm_u8, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_st_d_d_0F_72[] = {
	// 00
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_PSRLD_d_rm_rm_mmx_u64_imm_u8, in_PSRLD_d_rm_rm_mmx_u64_imm_u8, in_PSRLD_d_rm_rm_mmx_u64_imm_u8, in_PSRLD_d_rm_rm_mmx_u64_imm_u8, in_PSRLD_d_rm_rm_mmx_u64_imm_u8, in_PSRLD_d_rm_rm_mmx_u64_imm_u8, in_PSRLD_d_rm_rm_mmx_u64_imm_u8, in_PSRLD_d_rm_rm_mmx_u64_imm_u8, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_PSRAD_d_rm_rm_mmx_u64_imm_u8, in_PSRAD_d_rm_rm_mmx_u64_imm_u8, in_PSRAD_d_rm_rm_mmx_u64_imm_u8, in_PSRAD_d_rm_rm_mmx_u64_imm_u8, in_PSRAD_d_rm_rm_mmx_u64_imm_u8, in_PSRAD_d_rm_rm_mmx_u64_imm_u8, in_PSRAD_d_rm_rm_mmx_u64_imm_u8, in_PSRAD_d_rm_rm_mmx_u64_imm_u8, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_PSLLD_d_rm_rm_mmx_u64_imm_u8, in_PSLLD_d_rm_rm_mmx_u64_imm_u8, in_PSLLD_d_rm_rm_mmx_u64_imm_u8, in_PSLLD_d_rm_rm_mmx_u64_imm_u8, in_PSLLD_d_rm_rm_mmx_u64_imm_u8, in_PSLLD_d_rm_rm_mmx_u64_imm_u8, in_PSLLD_d_rm_rm_mmx_u64_imm_u8, in_PSLLD_d_rm_rm_mmx_u64_imm_u8, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_PSRLD_d_rm_rm_mmx_u64_imm_u8, in_PSRLD_d_rm_rm_mmx_u64_imm_u8, in_PSRLD_d_rm_rm_mmx_u64_imm_u8, in_PSRLD_d_rm_rm_mmx_u64_imm_u8, in_PSRLD_d_rm_rm_mmx_u64_imm_u8, in_PSRLD_d_rm_rm_mmx_u64_imm_u8, in_PSRLD_d_rm_rm_mmx_u64_imm_u8, in_PSRLD_d_rm_rm_mmx_u64_imm_u8, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_PSRAD_d_rm_rm_mmx_u64_imm_u8, in_PSRAD_d_rm_rm_mmx_u64_imm_u8, in_PSRAD_d_rm_rm_mmx_u64_imm_u8, in_PSRAD_d_rm_rm_mmx_u64_imm_u8, in_PSRAD_d_rm_rm_mmx_u64_imm_u8, in_PSRAD_d_rm_rm_mmx_u64_imm_u8, in_PSRAD_d_rm_rm_mmx_u64_imm_u8, in_PSRAD_d_rm_rm_mmx_u64_imm_u8, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_PSLLD_d_rm_rm_mmx_u64_imm_u8, in_PSLLD_d_rm_rm_mmx_u64_imm_u8, in_PSLLD_d_rm_rm_mmx_u64_imm_u8, in_PSLLD_d_rm_rm_mmx_u64_imm_u8, in_PSLLD_d_rm_rm_mmx_u64_imm_u8, in_PSLLD_d_rm_rm_mmx_u64_imm_u8, in_PSLLD_d_rm_rm_mmx_u64_imm_u8, in_PSLLD_d_rm_rm_mmx_u64_imm_u8, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_PSRLD_d_rm_rm_mmx_u64_imm_u8, in_PSRLD_d_rm_rm_mmx_u64_imm_u8, in_PSRLD_d_rm_rm_mmx_u64_imm_u8, in_PSRLD_d_rm_rm_mmx_u64_imm_u8, in_PSRLD_d_rm_rm_mmx_u64_imm_u8, in_PSRLD_d_rm_rm_mmx_u64_imm_u8, in_PSRLD_d_rm_rm_mmx_u64_imm_u8, in_PSRLD_d_rm_rm_mmx_u64_imm_u8, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_PSRAD_d_rm_rm_mmx_u64_imm_u8, in_PSRAD_d_rm_rm_mmx_u64_imm_u8, in_PSRAD_d_rm_rm_mmx_u64_imm_u8, in_PSRAD_d_rm_rm_mmx_u64_imm_u8, in_PSRAD_d_rm_rm_mmx_u64_imm_u8, in_PSRAD_d_rm_rm_mmx_u64_imm_u8, in_PSRAD_d_rm_rm_mmx_u64_imm_u8, in_PSRAD_d_rm_rm_mmx_u64_imm_u8, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_PSLLD_d_rm_rm_mmx_u64_imm_u8, in_PSLLD_d_rm_rm_mmx_u64_imm_u8, in_PSLLD_d_rm_rm_mmx_u64_imm_u8, in_PSLLD_d_rm_rm_mmx_u64_imm_u8, in_PSLLD_d_rm_rm_mmx_u64_imm_u8, in_PSLLD_d_rm_rm_mmx_u64_imm_u8, in_PSLLD_d_rm_rm_mmx_u64_imm_u8, in_PSLLD_d_rm_rm_mmx_u64_imm_u8, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_PSRLD_d_rm_rm_mmx_u64_imm_u8, in_PSRLD_d_rm_rm_mmx_u64_imm_u8, in_PSRLD_d_rm_rm_mmx_u64_imm_u8, in_PSRLD_d_rm_rm_mmx_u64_imm_u8, in_PSRLD_d_rm_rm_mmx_u64_imm_u8, in_PSRLD_d_rm_rm_mmx_u64_imm_u8, in_PSRLD_d_rm_rm_mmx_u64_imm_u8, in_PSRLD_d_rm_rm_mmx_u64_imm_u8, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_PSRAD_d_rm_rm_mmx_u64_imm_u8, in_PSRAD_d_rm_rm_mmx_u64_imm_u8, in_PSRAD_d_rm_rm_mmx_u64_imm_u8, in_PSRAD_d_rm_rm_mmx_u64_imm_u8, in_PSRAD_d_rm_rm_mmx_u64_imm_u8, in_PSRAD_d_rm_rm_mmx_u64_imm_u8, in_PSRAD_d_rm_rm_mmx_u64_imm_u8, in_PSRAD_d_rm_rm_mmx_u64_imm_u8, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_PSLLD_d_rm_rm_mmx_u64_imm_u8, in_PSLLD_d_rm_rm_mmx_u64_imm_u8, in_PSLLD_d_rm_rm_mmx_u64_imm_u8, in_PSLLD_d_rm_rm_mmx_u64_imm_u8, in_PSLLD_d_rm_rm_mmx_u64_imm_u8, in_PSLLD_d_rm_rm_mmx_u64_imm_u8, in_PSLLD_d_rm_rm_mmx_u64_imm_u8, in_PSLLD_d_rm_rm_mmx_u64_imm_u8, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_st_w_w_0F_73[] = {
	// 00
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_PSRLQ_w_rm_rm_mmx_u64_imm_u8, in_PSRLQ_w_rm_rm_mmx_u64_imm_u8, in_PSRLQ_w_rm_rm_mmx_u64_imm_u8, in_PSRLQ_w_rm_rm_mmx_u64_imm_u8, in_PSRLQ_w_rm_rm_mmx_u64_imm_u8, in_PSRLQ_w_rm_rm_mmx_u64_imm_u8, in_PSRLQ_w_rm_rm_mmx_u64_imm_u8, in_PSRLQ_w_rm_rm_mmx_u64_imm_u8, 
	// 18
	in_PSRLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_w_rm_rm_xmm_u128_imm_u8, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_PSLLQ_w_rm_rm_mmx_u64_imm_u8, in_PSLLQ_w_rm_rm_mmx_u64_imm_u8, in_PSLLQ_w_rm_rm_mmx_u64_imm_u8, in_PSLLQ_w_rm_rm_mmx_u64_imm_u8, in_PSLLQ_w_rm_rm_mmx_u64_imm_u8, in_PSLLQ_w_rm_rm_mmx_u64_imm_u8, in_PSLLQ_w_rm_rm_mmx_u64_imm_u8, in_PSLLQ_w_rm_rm_mmx_u64_imm_u8, 
	// 38
	in_PSLLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_w_rm_rm_xmm_u128_imm_u8, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_PSRLQ_w_rm_rm_mmx_u64_imm_u8, in_PSRLQ_w_rm_rm_mmx_u64_imm_u8, in_PSRLQ_w_rm_rm_mmx_u64_imm_u8, in_PSRLQ_w_rm_rm_mmx_u64_imm_u8, in_PSRLQ_w_rm_rm_mmx_u64_imm_u8, in_PSRLQ_w_rm_rm_mmx_u64_imm_u8, in_PSRLQ_w_rm_rm_mmx_u64_imm_u8, in_PSRLQ_w_rm_rm_mmx_u64_imm_u8, 
	// 58
	in_PSRLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_w_rm_rm_xmm_u128_imm_u8, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_PSLLQ_w_rm_rm_mmx_u64_imm_u8, in_PSLLQ_w_rm_rm_mmx_u64_imm_u8, in_PSLLQ_w_rm_rm_mmx_u64_imm_u8, in_PSLLQ_w_rm_rm_mmx_u64_imm_u8, in_PSLLQ_w_rm_rm_mmx_u64_imm_u8, in_PSLLQ_w_rm_rm_mmx_u64_imm_u8, in_PSLLQ_w_rm_rm_mmx_u64_imm_u8, in_PSLLQ_w_rm_rm_mmx_u64_imm_u8, 
	// 78
	in_PSLLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_w_rm_rm_xmm_u128_imm_u8, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_PSRLQ_w_rm_rm_mmx_u64_imm_u8, in_PSRLQ_w_rm_rm_mmx_u64_imm_u8, in_PSRLQ_w_rm_rm_mmx_u64_imm_u8, in_PSRLQ_w_rm_rm_mmx_u64_imm_u8, in_PSRLQ_w_rm_rm_mmx_u64_imm_u8, in_PSRLQ_w_rm_rm_mmx_u64_imm_u8, in_PSRLQ_w_rm_rm_mmx_u64_imm_u8, in_PSRLQ_w_rm_rm_mmx_u64_imm_u8, 
	// 98
	in_PSRLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_w_rm_rm_xmm_u128_imm_u8, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_PSLLQ_w_rm_rm_mmx_u64_imm_u8, in_PSLLQ_w_rm_rm_mmx_u64_imm_u8, in_PSLLQ_w_rm_rm_mmx_u64_imm_u8, in_PSLLQ_w_rm_rm_mmx_u64_imm_u8, in_PSLLQ_w_rm_rm_mmx_u64_imm_u8, in_PSLLQ_w_rm_rm_mmx_u64_imm_u8, in_PSLLQ_w_rm_rm_mmx_u64_imm_u8, in_PSLLQ_w_rm_rm_mmx_u64_imm_u8, 
	// B8
	in_PSLLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_w_rm_rm_xmm_u128_imm_u8, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_PSRLQ_w_rm_rm_mmx_u64_imm_u8, in_PSRLQ_w_rm_rm_mmx_u64_imm_u8, in_PSRLQ_w_rm_rm_mmx_u64_imm_u8, in_PSRLQ_w_rm_rm_mmx_u64_imm_u8, in_PSRLQ_w_rm_rm_mmx_u64_imm_u8, in_PSRLQ_w_rm_rm_mmx_u64_imm_u8, in_PSRLQ_w_rm_rm_mmx_u64_imm_u8, in_PSRLQ_w_rm_rm_mmx_u64_imm_u8, 
	// D8
	in_PSRLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_w_rm_rm_xmm_u128_imm_u8, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_PSLLQ_w_rm_rm_mmx_u64_imm_u8, in_PSLLQ_w_rm_rm_mmx_u64_imm_u8, in_PSLLQ_w_rm_rm_mmx_u64_imm_u8, in_PSLLQ_w_rm_rm_mmx_u64_imm_u8, in_PSLLQ_w_rm_rm_mmx_u64_imm_u8, in_PSLLQ_w_rm_rm_mmx_u64_imm_u8, in_PSLLQ_w_rm_rm_mmx_u64_imm_u8, in_PSLLQ_w_rm_rm_mmx_u64_imm_u8, 
	// F8
	in_PSLLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_w_rm_rm_xmm_u128_imm_u8, 
};
const OpState CpuRunnerX86::table_st_w_d_0F_73[] = {
	// 00
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_PSRLQ_w_rm_rm_mmx_u64_imm_u8, in_PSRLQ_w_rm_rm_mmx_u64_imm_u8, in_PSRLQ_w_rm_rm_mmx_u64_imm_u8, in_PSRLQ_w_rm_rm_mmx_u64_imm_u8, in_PSRLQ_w_rm_rm_mmx_u64_imm_u8, in_PSRLQ_w_rm_rm_mmx_u64_imm_u8, in_PSRLQ_w_rm_rm_mmx_u64_imm_u8, in_PSRLQ_w_rm_rm_mmx_u64_imm_u8, 
	// 18
	in_PSRLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_w_rm_rm_xmm_u128_imm_u8, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_PSLLQ_w_rm_rm_mmx_u64_imm_u8, in_PSLLQ_w_rm_rm_mmx_u64_imm_u8, in_PSLLQ_w_rm_rm_mmx_u64_imm_u8, in_PSLLQ_w_rm_rm_mmx_u64_imm_u8, in_PSLLQ_w_rm_rm_mmx_u64_imm_u8, in_PSLLQ_w_rm_rm_mmx_u64_imm_u8, in_PSLLQ_w_rm_rm_mmx_u64_imm_u8, in_PSLLQ_w_rm_rm_mmx_u64_imm_u8, 
	// 38
	in_PSLLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_w_rm_rm_xmm_u128_imm_u8, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_PSRLQ_w_rm_rm_mmx_u64_imm_u8, in_PSRLQ_w_rm_rm_mmx_u64_imm_u8, in_PSRLQ_w_rm_rm_mmx_u64_imm_u8, in_PSRLQ_w_rm_rm_mmx_u64_imm_u8, in_PSRLQ_w_rm_rm_mmx_u64_imm_u8, in_PSRLQ_w_rm_rm_mmx_u64_imm_u8, in_PSRLQ_w_rm_rm_mmx_u64_imm_u8, in_PSRLQ_w_rm_rm_mmx_u64_imm_u8, 
	// 58
	in_PSRLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_w_rm_rm_xmm_u128_imm_u8, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_PSLLQ_w_rm_rm_mmx_u64_imm_u8, in_PSLLQ_w_rm_rm_mmx_u64_imm_u8, in_PSLLQ_w_rm_rm_mmx_u64_imm_u8, in_PSLLQ_w_rm_rm_mmx_u64_imm_u8, in_PSLLQ_w_rm_rm_mmx_u64_imm_u8, in_PSLLQ_w_rm_rm_mmx_u64_imm_u8, in_PSLLQ_w_rm_rm_mmx_u64_imm_u8, in_PSLLQ_w_rm_rm_mmx_u64_imm_u8, 
	// 78
	in_PSLLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_w_rm_rm_xmm_u128_imm_u8, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_PSRLQ_w_rm_rm_mmx_u64_imm_u8, in_PSRLQ_w_rm_rm_mmx_u64_imm_u8, in_PSRLQ_w_rm_rm_mmx_u64_imm_u8, in_PSRLQ_w_rm_rm_mmx_u64_imm_u8, in_PSRLQ_w_rm_rm_mmx_u64_imm_u8, in_PSRLQ_w_rm_rm_mmx_u64_imm_u8, in_PSRLQ_w_rm_rm_mmx_u64_imm_u8, in_PSRLQ_w_rm_rm_mmx_u64_imm_u8, 
	// 98
	in_PSRLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_w_rm_rm_xmm_u128_imm_u8, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_PSLLQ_w_rm_rm_mmx_u64_imm_u8, in_PSLLQ_w_rm_rm_mmx_u64_imm_u8, in_PSLLQ_w_rm_rm_mmx_u64_imm_u8, in_PSLLQ_w_rm_rm_mmx_u64_imm_u8, in_PSLLQ_w_rm_rm_mmx_u64_imm_u8, in_PSLLQ_w_rm_rm_mmx_u64_imm_u8, in_PSLLQ_w_rm_rm_mmx_u64_imm_u8, in_PSLLQ_w_rm_rm_mmx_u64_imm_u8, 
	// B8
	in_PSLLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_w_rm_rm_xmm_u128_imm_u8, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_PSRLQ_w_rm_rm_mmx_u64_imm_u8, in_PSRLQ_w_rm_rm_mmx_u64_imm_u8, in_PSRLQ_w_rm_rm_mmx_u64_imm_u8, in_PSRLQ_w_rm_rm_mmx_u64_imm_u8, in_PSRLQ_w_rm_rm_mmx_u64_imm_u8, in_PSRLQ_w_rm_rm_mmx_u64_imm_u8, in_PSRLQ_w_rm_rm_mmx_u64_imm_u8, in_PSRLQ_w_rm_rm_mmx_u64_imm_u8, 
	// D8
	in_PSRLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_w_rm_rm_xmm_u128_imm_u8, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_PSLLQ_w_rm_rm_mmx_u64_imm_u8, in_PSLLQ_w_rm_rm_mmx_u64_imm_u8, in_PSLLQ_w_rm_rm_mmx_u64_imm_u8, in_PSLLQ_w_rm_rm_mmx_u64_imm_u8, in_PSLLQ_w_rm_rm_mmx_u64_imm_u8, in_PSLLQ_w_rm_rm_mmx_u64_imm_u8, in_PSLLQ_w_rm_rm_mmx_u64_imm_u8, in_PSLLQ_w_rm_rm_mmx_u64_imm_u8, 
	// F8
	in_PSLLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_w_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_w_rm_rm_xmm_u128_imm_u8, 
};
const OpState CpuRunnerX86::table_st_d_w_0F_73[] = {
	// 00
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_PSRLQ_d_rm_rm_mmx_u64_imm_u8, in_PSRLQ_d_rm_rm_mmx_u64_imm_u8, in_PSRLQ_d_rm_rm_mmx_u64_imm_u8, in_PSRLQ_d_rm_rm_mmx_u64_imm_u8, in_PSRLQ_d_rm_rm_mmx_u64_imm_u8, in_PSRLQ_d_rm_rm_mmx_u64_imm_u8, in_PSRLQ_d_rm_rm_mmx_u64_imm_u8, in_PSRLQ_d_rm_rm_mmx_u64_imm_u8, 
	// 18
	in_PSRLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_d_rm_rm_xmm_u128_imm_u8, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_PSLLQ_d_rm_rm_mmx_u64_imm_u8, in_PSLLQ_d_rm_rm_mmx_u64_imm_u8, in_PSLLQ_d_rm_rm_mmx_u64_imm_u8, in_PSLLQ_d_rm_rm_mmx_u64_imm_u8, in_PSLLQ_d_rm_rm_mmx_u64_imm_u8, in_PSLLQ_d_rm_rm_mmx_u64_imm_u8, in_PSLLQ_d_rm_rm_mmx_u64_imm_u8, in_PSLLQ_d_rm_rm_mmx_u64_imm_u8, 
	// 38
	in_PSLLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_d_rm_rm_xmm_u128_imm_u8, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_PSRLQ_d_rm_rm_mmx_u64_imm_u8, in_PSRLQ_d_rm_rm_mmx_u64_imm_u8, in_PSRLQ_d_rm_rm_mmx_u64_imm_u8, in_PSRLQ_d_rm_rm_mmx_u64_imm_u8, in_PSRLQ_d_rm_rm_mmx_u64_imm_u8, in_PSRLQ_d_rm_rm_mmx_u64_imm_u8, in_PSRLQ_d_rm_rm_mmx_u64_imm_u8, in_PSRLQ_d_rm_rm_mmx_u64_imm_u8, 
	// 58
	in_PSRLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_d_rm_rm_xmm_u128_imm_u8, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_PSLLQ_d_rm_rm_mmx_u64_imm_u8, in_PSLLQ_d_rm_rm_mmx_u64_imm_u8, in_PSLLQ_d_rm_rm_mmx_u64_imm_u8, in_PSLLQ_d_rm_rm_mmx_u64_imm_u8, in_PSLLQ_d_rm_rm_mmx_u64_imm_u8, in_PSLLQ_d_rm_rm_mmx_u64_imm_u8, in_PSLLQ_d_rm_rm_mmx_u64_imm_u8, in_PSLLQ_d_rm_rm_mmx_u64_imm_u8, 
	// 78
	in_PSLLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_d_rm_rm_xmm_u128_imm_u8, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_PSRLQ_d_rm_rm_mmx_u64_imm_u8, in_PSRLQ_d_rm_rm_mmx_u64_imm_u8, in_PSRLQ_d_rm_rm_mmx_u64_imm_u8, in_PSRLQ_d_rm_rm_mmx_u64_imm_u8, in_PSRLQ_d_rm_rm_mmx_u64_imm_u8, in_PSRLQ_d_rm_rm_mmx_u64_imm_u8, in_PSRLQ_d_rm_rm_mmx_u64_imm_u8, in_PSRLQ_d_rm_rm_mmx_u64_imm_u8, 
	// 98
	in_PSRLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_d_rm_rm_xmm_u128_imm_u8, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_PSLLQ_d_rm_rm_mmx_u64_imm_u8, in_PSLLQ_d_rm_rm_mmx_u64_imm_u8, in_PSLLQ_d_rm_rm_mmx_u64_imm_u8, in_PSLLQ_d_rm_rm_mmx_u64_imm_u8, in_PSLLQ_d_rm_rm_mmx_u64_imm_u8, in_PSLLQ_d_rm_rm_mmx_u64_imm_u8, in_PSLLQ_d_rm_rm_mmx_u64_imm_u8, in_PSLLQ_d_rm_rm_mmx_u64_imm_u8, 
	// B8
	in_PSLLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_d_rm_rm_xmm_u128_imm_u8, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_PSRLQ_d_rm_rm_mmx_u64_imm_u8, in_PSRLQ_d_rm_rm_mmx_u64_imm_u8, in_PSRLQ_d_rm_rm_mmx_u64_imm_u8, in_PSRLQ_d_rm_rm_mmx_u64_imm_u8, in_PSRLQ_d_rm_rm_mmx_u64_imm_u8, in_PSRLQ_d_rm_rm_mmx_u64_imm_u8, in_PSRLQ_d_rm_rm_mmx_u64_imm_u8, in_PSRLQ_d_rm_rm_mmx_u64_imm_u8, 
	// D8
	in_PSRLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_d_rm_rm_xmm_u128_imm_u8, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_PSLLQ_d_rm_rm_mmx_u64_imm_u8, in_PSLLQ_d_rm_rm_mmx_u64_imm_u8, in_PSLLQ_d_rm_rm_mmx_u64_imm_u8, in_PSLLQ_d_rm_rm_mmx_u64_imm_u8, in_PSLLQ_d_rm_rm_mmx_u64_imm_u8, in_PSLLQ_d_rm_rm_mmx_u64_imm_u8, in_PSLLQ_d_rm_rm_mmx_u64_imm_u8, in_PSLLQ_d_rm_rm_mmx_u64_imm_u8, 
	// F8
	in_PSLLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_d_rm_rm_xmm_u128_imm_u8, 
};
const OpState CpuRunnerX86::table_st_d_d_0F_73[] = {
	// 00
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_PSRLQ_d_rm_rm_mmx_u64_imm_u8, in_PSRLQ_d_rm_rm_mmx_u64_imm_u8, in_PSRLQ_d_rm_rm_mmx_u64_imm_u8, in_PSRLQ_d_rm_rm_mmx_u64_imm_u8, in_PSRLQ_d_rm_rm_mmx_u64_imm_u8, in_PSRLQ_d_rm_rm_mmx_u64_imm_u8, in_PSRLQ_d_rm_rm_mmx_u64_imm_u8, in_PSRLQ_d_rm_rm_mmx_u64_imm_u8, 
	// 18
	in_PSRLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_d_rm_rm_xmm_u128_imm_u8, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_PSLLQ_d_rm_rm_mmx_u64_imm_u8, in_PSLLQ_d_rm_rm_mmx_u64_imm_u8, in_PSLLQ_d_rm_rm_mmx_u64_imm_u8, in_PSLLQ_d_rm_rm_mmx_u64_imm_u8, in_PSLLQ_d_rm_rm_mmx_u64_imm_u8, in_PSLLQ_d_rm_rm_mmx_u64_imm_u8, in_PSLLQ_d_rm_rm_mmx_u64_imm_u8, in_PSLLQ_d_rm_rm_mmx_u64_imm_u8, 
	// 38
	in_PSLLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_d_rm_rm_xmm_u128_imm_u8, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_PSRLQ_d_rm_rm_mmx_u64_imm_u8, in_PSRLQ_d_rm_rm_mmx_u64_imm_u8, in_PSRLQ_d_rm_rm_mmx_u64_imm_u8, in_PSRLQ_d_rm_rm_mmx_u64_imm_u8, in_PSRLQ_d_rm_rm_mmx_u64_imm_u8, in_PSRLQ_d_rm_rm_mmx_u64_imm_u8, in_PSRLQ_d_rm_rm_mmx_u64_imm_u8, in_PSRLQ_d_rm_rm_mmx_u64_imm_u8, 
	// 58
	in_PSRLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_d_rm_rm_xmm_u128_imm_u8, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_PSLLQ_d_rm_rm_mmx_u64_imm_u8, in_PSLLQ_d_rm_rm_mmx_u64_imm_u8, in_PSLLQ_d_rm_rm_mmx_u64_imm_u8, in_PSLLQ_d_rm_rm_mmx_u64_imm_u8, in_PSLLQ_d_rm_rm_mmx_u64_imm_u8, in_PSLLQ_d_rm_rm_mmx_u64_imm_u8, in_PSLLQ_d_rm_rm_mmx_u64_imm_u8, in_PSLLQ_d_rm_rm_mmx_u64_imm_u8, 
	// 78
	in_PSLLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_d_rm_rm_xmm_u128_imm_u8, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_PSRLQ_d_rm_rm_mmx_u64_imm_u8, in_PSRLQ_d_rm_rm_mmx_u64_imm_u8, in_PSRLQ_d_rm_rm_mmx_u64_imm_u8, in_PSRLQ_d_rm_rm_mmx_u64_imm_u8, in_PSRLQ_d_rm_rm_mmx_u64_imm_u8, in_PSRLQ_d_rm_rm_mmx_u64_imm_u8, in_PSRLQ_d_rm_rm_mmx_u64_imm_u8, in_PSRLQ_d_rm_rm_mmx_u64_imm_u8, 
	// 98
	in_PSRLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_d_rm_rm_xmm_u128_imm_u8, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_PSLLQ_d_rm_rm_mmx_u64_imm_u8, in_PSLLQ_d_rm_rm_mmx_u64_imm_u8, in_PSLLQ_d_rm_rm_mmx_u64_imm_u8, in_PSLLQ_d_rm_rm_mmx_u64_imm_u8, in_PSLLQ_d_rm_rm_mmx_u64_imm_u8, in_PSLLQ_d_rm_rm_mmx_u64_imm_u8, in_PSLLQ_d_rm_rm_mmx_u64_imm_u8, in_PSLLQ_d_rm_rm_mmx_u64_imm_u8, 
	// B8
	in_PSLLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_d_rm_rm_xmm_u128_imm_u8, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_PSRLQ_d_rm_rm_mmx_u64_imm_u8, in_PSRLQ_d_rm_rm_mmx_u64_imm_u8, in_PSRLQ_d_rm_rm_mmx_u64_imm_u8, in_PSRLQ_d_rm_rm_mmx_u64_imm_u8, in_PSRLQ_d_rm_rm_mmx_u64_imm_u8, in_PSRLQ_d_rm_rm_mmx_u64_imm_u8, in_PSRLQ_d_rm_rm_mmx_u64_imm_u8, in_PSRLQ_d_rm_rm_mmx_u64_imm_u8, 
	// D8
	in_PSRLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSRLDQ_d_rm_rm_xmm_u128_imm_u8, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_PSLLQ_d_rm_rm_mmx_u64_imm_u8, in_PSLLQ_d_rm_rm_mmx_u64_imm_u8, in_PSLLQ_d_rm_rm_mmx_u64_imm_u8, in_PSLLQ_d_rm_rm_mmx_u64_imm_u8, in_PSLLQ_d_rm_rm_mmx_u64_imm_u8, in_PSLLQ_d_rm_rm_mmx_u64_imm_u8, in_PSLLQ_d_rm_rm_mmx_u64_imm_u8, in_PSLLQ_d_rm_rm_mmx_u64_imm_u8, 
	// F8
	in_PSLLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_d_rm_rm_xmm_u128_imm_u8, in_PSLLDQ_d_rm_rm_xmm_u128_imm_u8, 
};
const OpState CpuRunnerX86::table_st_w_w_0F_AE[] = {
	// 00
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_LDMXCSR_w_rm_mem_u32, in_LDMXCSR_w_rm_mem_u32, in_LDMXCSR_w_rm_mem_u32, in_LDMXCSR_w_rm_mem_u32, in_LDMXCSR_w_rm_mem_u32, in_LDMXCSR_w_rm_mem_u32, in_LDMXCSR_w_rm_mem_u32, in_LDMXCSR_w_rm_mem_u32, 
	// 18
	in_STMXCSR_w_rm_mem_u32, in_STMXCSR_w_rm_mem_u32, in_STMXCSR_w_rm_mem_u32, in_STMXCSR_w_rm_mem_u32, in_STMXCSR_w_rm_mem_u32, in_STMXCSR_w_rm_mem_u32, in_STMXCSR_w_rm_mem_u32, in_STMXCSR_w_rm_mem_u32, 
	// 20
	in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, 
	// 28
	in_XRSTOR, in_XRSTOR, in_XRSTOR, in_XRSTOR, in_XRSTOR, in_XRSTOR, in_XRSTOR, in_XRSTOR, 
	// 30
	in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, 
	// 38
	in_CLFLUSH_w_rm_mem_u8, in_CLFLUSH_w_rm_mem_u8, in_CLFLUSH_w_rm_mem_u8, in_CLFLUSH_w_rm_mem_u8, in_CLFLUSH_w_rm_mem_u8, in_CLFLUSH_w_rm_mem_u8, in_CLFLUSH_w_rm_mem_u8, in_CLFLUSH_w_rm_mem_u8, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_LDMXCSR_w_rm_mem_u32, in_LDMXCSR_w_rm_mem_u32, in_LDMXCSR_w_rm_mem_u32, in_LDMXCSR_w_rm_mem_u32, in_LDMXCSR_w_rm_mem_u32, in_LDMXCSR_w_rm_mem_u32, in_LDMXCSR_w_rm_mem_u32, in_LDMXCSR_w_rm_mem_u32, 
	// 58
	in_STMXCSR_w_rm_mem_u32, in_STMXCSR_w_rm_mem_u32, in_STMXCSR_w_rm_mem_u32, in_STMXCSR_w_rm_mem_u32, in_STMXCSR_w_rm_mem_u32, in_STMXCSR_w_rm_mem_u32, in_STMXCSR_w_rm_mem_u32, in_STMXCSR_w_rm_mem_u32, 
	// 60
	in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, 
	// 68
	in_XRSTOR, in_XRSTOR, in_XRSTOR, in_XRSTOR, in_XRSTOR, in_XRSTOR, in_XRSTOR, in_XRSTOR, 
	// 70
	in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, 
	// 78
	in_CLFLUSH_w_rm_mem_u8, in_CLFLUSH_w_rm_mem_u8, in_CLFLUSH_w_rm_mem_u8, in_CLFLUSH_w_rm_mem_u8, in_CLFLUSH_w_rm_mem_u8, in_CLFLUSH_w_rm_mem_u8, in_CLFLUSH_w_rm_mem_u8, in_CLFLUSH_w_rm_mem_u8, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_LDMXCSR_w_rm_mem_u32, in_LDMXCSR_w_rm_mem_u32, in_LDMXCSR_w_rm_mem_u32, in_LDMXCSR_w_rm_mem_u32, in_LDMXCSR_w_rm_mem_u32, in_LDMXCSR_w_rm_mem_u32, in_LDMXCSR_w_rm_mem_u32, in_LDMXCSR_w_rm_mem_u32, 
	// 98
	in_STMXCSR_w_rm_mem_u32, in_STMXCSR_w_rm_mem_u32, in_STMXCSR_w_rm_mem_u32, in_STMXCSR_w_rm_mem_u32, in_STMXCSR_w_rm_mem_u32, in_STMXCSR_w_rm_mem_u32, in_STMXCSR_w_rm_mem_u32, in_STMXCSR_w_rm_mem_u32, 
	// A0
	in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, 
	// A8
	in_XRSTOR, in_XRSTOR, in_XRSTOR, in_XRSTOR, in_XRSTOR, in_XRSTOR, in_XRSTOR, in_XRSTOR, 
	// B0
	in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, 
	// B8
	in_CLFLUSH_w_rm_mem_u8, in_CLFLUSH_w_rm_mem_u8, in_CLFLUSH_w_rm_mem_u8, in_CLFLUSH_w_rm_mem_u8, in_CLFLUSH_w_rm_mem_u8, in_CLFLUSH_w_rm_mem_u8, in_CLFLUSH_w_rm_mem_u8, in_CLFLUSH_w_rm_mem_u8, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_LDMXCSR_w_rm_mem_u32, in_LDMXCSR_w_rm_mem_u32, in_LDMXCSR_w_rm_mem_u32, in_LDMXCSR_w_rm_mem_u32, in_LDMXCSR_w_rm_mem_u32, in_LDMXCSR_w_rm_mem_u32, in_LDMXCSR_w_rm_mem_u32, in_LDMXCSR_w_rm_mem_u32, 
	// D8
	in_STMXCSR_w_rm_mem_u32, in_STMXCSR_w_rm_mem_u32, in_STMXCSR_w_rm_mem_u32, in_STMXCSR_w_rm_mem_u32, in_STMXCSR_w_rm_mem_u32, in_STMXCSR_w_rm_mem_u32, in_STMXCSR_w_rm_mem_u32, in_STMXCSR_w_rm_mem_u32, 
	// E0
	in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, 
	// E8
	in_LFENCE, in_LFENCE, in_LFENCE, in_LFENCE, in_LFENCE, in_LFENCE, in_LFENCE, in_LFENCE, 
	// F0
	in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, 
	// F8
	in_SFENCE, in_SFENCE, in_SFENCE, in_SFENCE, in_SFENCE, in_SFENCE, in_SFENCE, in_SFENCE, 
};
const OpState CpuRunnerX86::table_st_w_d_0F_AE[] = {
	// 00
	in_FXSAVE_w, in_FXSAVE_w, in_FXSAVE_w, in_FXSAVE_w, in_FXSAVE_w, in_FXSAVE_w, in_FXSAVE_w, in_FXSAVE_w, 
	// 08
	in_FXRSTOR_w, in_FXRSTOR_w, in_FXRSTOR_w, in_FXRSTOR_w, in_FXRSTOR_w, in_FXRSTOR_w, in_FXRSTOR_w, in_FXRSTOR_w, 
	// 10
	in_LDMXCSR_w_rm_mem_u32, in_LDMXCSR_w_rm_mem_u32, in_LDMXCSR_w_rm_mem_u32, in_LDMXCSR_w_rm_mem_u32, in_LDMXCSR_w_rm_mem_u32, in_LDMXCSR_w_rm_mem_u32, in_LDMXCSR_w_rm_mem_u32, in_LDMXCSR_w_rm_mem_u32, 
	// 18
	in_STMXCSR_w_rm_mem_u32, in_STMXCSR_w_rm_mem_u32, in_STMXCSR_w_rm_mem_u32, in_STMXCSR_w_rm_mem_u32, in_STMXCSR_w_rm_mem_u32, in_STMXCSR_w_rm_mem_u32, in_STMXCSR_w_rm_mem_u32, in_STMXCSR_w_rm_mem_u32, 
	// 20
	in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, 
	// 28
	in_XRSTOR, in_XRSTOR, in_XRSTOR, in_XRSTOR, in_XRSTOR, in_XRSTOR, in_XRSTOR, in_XRSTOR, 
	// 30
	in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, 
	// 38
	in_CLFLUSH_w_rm_mem_u8, in_CLFLUSH_w_rm_mem_u8, in_CLFLUSH_w_rm_mem_u8, in_CLFLUSH_w_rm_mem_u8, in_CLFLUSH_w_rm_mem_u8, in_CLFLUSH_w_rm_mem_u8, in_CLFLUSH_w_rm_mem_u8, in_CLFLUSH_w_rm_mem_u8, 
	// 40
	in_FXSAVE_w, in_FXSAVE_w, in_FXSAVE_w, in_FXSAVE_w, in_FXSAVE_w, in_FXSAVE_w, in_FXSAVE_w, in_FXSAVE_w, 
	// 48
	in_FXRSTOR_w, in_FXRSTOR_w, in_FXRSTOR_w, in_FXRSTOR_w, in_FXRSTOR_w, in_FXRSTOR_w, in_FXRSTOR_w, in_FXRSTOR_w, 
	// 50
	in_LDMXCSR_w_rm_mem_u32, in_LDMXCSR_w_rm_mem_u32, in_LDMXCSR_w_rm_mem_u32, in_LDMXCSR_w_rm_mem_u32, in_LDMXCSR_w_rm_mem_u32, in_LDMXCSR_w_rm_mem_u32, in_LDMXCSR_w_rm_mem_u32, in_LDMXCSR_w_rm_mem_u32, 
	// 58
	in_STMXCSR_w_rm_mem_u32, in_STMXCSR_w_rm_mem_u32, in_STMXCSR_w_rm_mem_u32, in_STMXCSR_w_rm_mem_u32, in_STMXCSR_w_rm_mem_u32, in_STMXCSR_w_rm_mem_u32, in_STMXCSR_w_rm_mem_u32, in_STMXCSR_w_rm_mem_u32, 
	// 60
	in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, 
	// 68
	in_XRSTOR, in_XRSTOR, in_XRSTOR, in_XRSTOR, in_XRSTOR, in_XRSTOR, in_XRSTOR, in_XRSTOR, 
	// 70
	in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, 
	// 78
	in_CLFLUSH_w_rm_mem_u8, in_CLFLUSH_w_rm_mem_u8, in_CLFLUSH_w_rm_mem_u8, in_CLFLUSH_w_rm_mem_u8, in_CLFLUSH_w_rm_mem_u8, in_CLFLUSH_w_rm_mem_u8, in_CLFLUSH_w_rm_mem_u8, in_CLFLUSH_w_rm_mem_u8, 
	// 80
	in_FXSAVE_w, in_FXSAVE_w, in_FXSAVE_w, in_FXSAVE_w, in_FXSAVE_w, in_FXSAVE_w, in_FXSAVE_w, in_FXSAVE_w, 
	// 88
	in_FXRSTOR_w, in_FXRSTOR_w, in_FXRSTOR_w, in_FXRSTOR_w, in_FXRSTOR_w, in_FXRSTOR_w, in_FXRSTOR_w, in_FXRSTOR_w, 
	// 90
	in_LDMXCSR_w_rm_mem_u32, in_LDMXCSR_w_rm_mem_u32, in_LDMXCSR_w_rm_mem_u32, in_LDMXCSR_w_rm_mem_u32, in_LDMXCSR_w_rm_mem_u32, in_LDMXCSR_w_rm_mem_u32, in_LDMXCSR_w_rm_mem_u32, in_LDMXCSR_w_rm_mem_u32, 
	// 98
	in_STMXCSR_w_rm_mem_u32, in_STMXCSR_w_rm_mem_u32, in_STMXCSR_w_rm_mem_u32, in_STMXCSR_w_rm_mem_u32, in_STMXCSR_w_rm_mem_u32, in_STMXCSR_w_rm_mem_u32, in_STMXCSR_w_rm_mem_u32, in_STMXCSR_w_rm_mem_u32, 
	// A0
	in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, 
	// A8
	in_XRSTOR, in_XRSTOR, in_XRSTOR, in_XRSTOR, in_XRSTOR, in_XRSTOR, in_XRSTOR, in_XRSTOR, 
	// B0
	in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, 
	// B8
	in_CLFLUSH_w_rm_mem_u8, in_CLFLUSH_w_rm_mem_u8, in_CLFLUSH_w_rm_mem_u8, in_CLFLUSH_w_rm_mem_u8, in_CLFLUSH_w_rm_mem_u8, in_CLFLUSH_w_rm_mem_u8, in_CLFLUSH_w_rm_mem_u8, in_CLFLUSH_w_rm_mem_u8, 
	// C0
	in_FXSAVE_w, in_FXSAVE_w, in_FXSAVE_w, in_FXSAVE_w, in_FXSAVE_w, in_FXSAVE_w, in_FXSAVE_w, in_FXSAVE_w, 
	// C8
	in_FXRSTOR_w, in_FXRSTOR_w, in_FXRSTOR_w, in_FXRSTOR_w, in_FXRSTOR_w, in_FXRSTOR_w, in_FXRSTOR_w, in_FXRSTOR_w, 
	// D0
	in_LDMXCSR_w_rm_mem_u32, in_LDMXCSR_w_rm_mem_u32, in_LDMXCSR_w_rm_mem_u32, in_LDMXCSR_w_rm_mem_u32, in_LDMXCSR_w_rm_mem_u32, in_LDMXCSR_w_rm_mem_u32, in_LDMXCSR_w_rm_mem_u32, in_LDMXCSR_w_rm_mem_u32, 
	// D8
	in_STMXCSR_w_rm_mem_u32, in_STMXCSR_w_rm_mem_u32, in_STMXCSR_w_rm_mem_u32, in_STMXCSR_w_rm_mem_u32, in_STMXCSR_w_rm_mem_u32, in_STMXCSR_w_rm_mem_u32, in_STMXCSR_w_rm_mem_u32, in_STMXCSR_w_rm_mem_u32, 
	// E0
	in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, 
	// E8
	in_LFENCE, in_LFENCE, in_LFENCE, in_LFENCE, in_LFENCE, in_LFENCE, in_LFENCE, in_LFENCE, 
	// F0
	in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, 
	// F8
	in_SFENCE, in_SFENCE, in_SFENCE, in_SFENCE, in_SFENCE, in_SFENCE, in_SFENCE, in_SFENCE, 
};
const OpState CpuRunnerX86::table_st_d_w_0F_AE[] = {
	// 00
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_LDMXCSR_d_rm_mem_u32, in_LDMXCSR_d_rm_mem_u32, in_LDMXCSR_d_rm_mem_u32, in_LDMXCSR_d_rm_mem_u32, in_LDMXCSR_d_rm_mem_u32, in_LDMXCSR_d_rm_mem_u32, in_LDMXCSR_d_rm_mem_u32, in_LDMXCSR_d_rm_mem_u32, 
	// 18
	in_STMXCSR_d_rm_mem_u32, in_STMXCSR_d_rm_mem_u32, in_STMXCSR_d_rm_mem_u32, in_STMXCSR_d_rm_mem_u32, in_STMXCSR_d_rm_mem_u32, in_STMXCSR_d_rm_mem_u32, in_STMXCSR_d_rm_mem_u32, in_STMXCSR_d_rm_mem_u32, 
	// 20
	in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, 
	// 28
	in_XRSTOR, in_XRSTOR, in_XRSTOR, in_XRSTOR, in_XRSTOR, in_XRSTOR, in_XRSTOR, in_XRSTOR, 
	// 30
	in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, 
	// 38
	in_CLFLUSH_d_rm_mem_u8, in_CLFLUSH_d_rm_mem_u8, in_CLFLUSH_d_rm_mem_u8, in_CLFLUSH_d_rm_mem_u8, in_CLFLUSH_d_rm_mem_u8, in_CLFLUSH_d_rm_mem_u8, in_CLFLUSH_d_rm_mem_u8, in_CLFLUSH_d_rm_mem_u8, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_LDMXCSR_d_rm_mem_u32, in_LDMXCSR_d_rm_mem_u32, in_LDMXCSR_d_rm_mem_u32, in_LDMXCSR_d_rm_mem_u32, in_LDMXCSR_d_rm_mem_u32, in_LDMXCSR_d_rm_mem_u32, in_LDMXCSR_d_rm_mem_u32, in_LDMXCSR_d_rm_mem_u32, 
	// 58
	in_STMXCSR_d_rm_mem_u32, in_STMXCSR_d_rm_mem_u32, in_STMXCSR_d_rm_mem_u32, in_STMXCSR_d_rm_mem_u32, in_STMXCSR_d_rm_mem_u32, in_STMXCSR_d_rm_mem_u32, in_STMXCSR_d_rm_mem_u32, in_STMXCSR_d_rm_mem_u32, 
	// 60
	in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, 
	// 68
	in_XRSTOR, in_XRSTOR, in_XRSTOR, in_XRSTOR, in_XRSTOR, in_XRSTOR, in_XRSTOR, in_XRSTOR, 
	// 70
	in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, 
	// 78
	in_CLFLUSH_d_rm_mem_u8, in_CLFLUSH_d_rm_mem_u8, in_CLFLUSH_d_rm_mem_u8, in_CLFLUSH_d_rm_mem_u8, in_CLFLUSH_d_rm_mem_u8, in_CLFLUSH_d_rm_mem_u8, in_CLFLUSH_d_rm_mem_u8, in_CLFLUSH_d_rm_mem_u8, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_LDMXCSR_d_rm_mem_u32, in_LDMXCSR_d_rm_mem_u32, in_LDMXCSR_d_rm_mem_u32, in_LDMXCSR_d_rm_mem_u32, in_LDMXCSR_d_rm_mem_u32, in_LDMXCSR_d_rm_mem_u32, in_LDMXCSR_d_rm_mem_u32, in_LDMXCSR_d_rm_mem_u32, 
	// 98
	in_STMXCSR_d_rm_mem_u32, in_STMXCSR_d_rm_mem_u32, in_STMXCSR_d_rm_mem_u32, in_STMXCSR_d_rm_mem_u32, in_STMXCSR_d_rm_mem_u32, in_STMXCSR_d_rm_mem_u32, in_STMXCSR_d_rm_mem_u32, in_STMXCSR_d_rm_mem_u32, 
	// A0
	in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, 
	// A8
	in_XRSTOR, in_XRSTOR, in_XRSTOR, in_XRSTOR, in_XRSTOR, in_XRSTOR, in_XRSTOR, in_XRSTOR, 
	// B0
	in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, 
	// B8
	in_CLFLUSH_d_rm_mem_u8, in_CLFLUSH_d_rm_mem_u8, in_CLFLUSH_d_rm_mem_u8, in_CLFLUSH_d_rm_mem_u8, in_CLFLUSH_d_rm_mem_u8, in_CLFLUSH_d_rm_mem_u8, in_CLFLUSH_d_rm_mem_u8, in_CLFLUSH_d_rm_mem_u8, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_LDMXCSR_d_rm_mem_u32, in_LDMXCSR_d_rm_mem_u32, in_LDMXCSR_d_rm_mem_u32, in_LDMXCSR_d_rm_mem_u32, in_LDMXCSR_d_rm_mem_u32, in_LDMXCSR_d_rm_mem_u32, in_LDMXCSR_d_rm_mem_u32, in_LDMXCSR_d_rm_mem_u32, 
	// D8
	in_STMXCSR_d_rm_mem_u32, in_STMXCSR_d_rm_mem_u32, in_STMXCSR_d_rm_mem_u32, in_STMXCSR_d_rm_mem_u32, in_STMXCSR_d_rm_mem_u32, in_STMXCSR_d_rm_mem_u32, in_STMXCSR_d_rm_mem_u32, in_STMXCSR_d_rm_mem_u32, 
	// E0
	in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, 
	// E8
	in_LFENCE, in_LFENCE, in_LFENCE, in_LFENCE, in_LFENCE, in_LFENCE, in_LFENCE, in_LFENCE, 
	// F0
	in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, 
	// F8
	in_SFENCE, in_SFENCE, in_SFENCE, in_SFENCE, in_SFENCE, in_SFENCE, in_SFENCE, in_SFENCE, 
};
const OpState CpuRunnerX86::table_st_d_d_0F_AE[] = {
	// 00
	in_FXSAVE_d, in_FXSAVE_d, in_FXSAVE_d, in_FXSAVE_d, in_FXSAVE_d, in_FXSAVE_d, in_FXSAVE_d, in_FXSAVE_d, 
	// 08
	in_FXRSTOR_d, in_FXRSTOR_d, in_FXRSTOR_d, in_FXRSTOR_d, in_FXRSTOR_d, in_FXRSTOR_d, in_FXRSTOR_d, in_FXRSTOR_d, 
	// 10
	in_LDMXCSR_d_rm_mem_u32, in_LDMXCSR_d_rm_mem_u32, in_LDMXCSR_d_rm_mem_u32, in_LDMXCSR_d_rm_mem_u32, in_LDMXCSR_d_rm_mem_u32, in_LDMXCSR_d_rm_mem_u32, in_LDMXCSR_d_rm_mem_u32, in_LDMXCSR_d_rm_mem_u32, 
	// 18
	in_STMXCSR_d_rm_mem_u32, in_STMXCSR_d_rm_mem_u32, in_STMXCSR_d_rm_mem_u32, in_STMXCSR_d_rm_mem_u32, in_STMXCSR_d_rm_mem_u32, in_STMXCSR_d_rm_mem_u32, in_STMXCSR_d_rm_mem_u32, in_STMXCSR_d_rm_mem_u32, 
	// 20
	in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, 
	// 28
	in_XRSTOR, in_XRSTOR, in_XRSTOR, in_XRSTOR, in_XRSTOR, in_XRSTOR, in_XRSTOR, in_XRSTOR, 
	// 30
	in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, 
	// 38
	in_CLFLUSH_d_rm_mem_u8, in_CLFLUSH_d_rm_mem_u8, in_CLFLUSH_d_rm_mem_u8, in_CLFLUSH_d_rm_mem_u8, in_CLFLUSH_d_rm_mem_u8, in_CLFLUSH_d_rm_mem_u8, in_CLFLUSH_d_rm_mem_u8, in_CLFLUSH_d_rm_mem_u8, 
	// 40
	in_FXSAVE_d, in_FXSAVE_d, in_FXSAVE_d, in_FXSAVE_d, in_FXSAVE_d, in_FXSAVE_d, in_FXSAVE_d, in_FXSAVE_d, 
	// 48
	in_FXRSTOR_d, in_FXRSTOR_d, in_FXRSTOR_d, in_FXRSTOR_d, in_FXRSTOR_d, in_FXRSTOR_d, in_FXRSTOR_d, in_FXRSTOR_d, 
	// 50
	in_LDMXCSR_d_rm_mem_u32, in_LDMXCSR_d_rm_mem_u32, in_LDMXCSR_d_rm_mem_u32, in_LDMXCSR_d_rm_mem_u32, in_LDMXCSR_d_rm_mem_u32, in_LDMXCSR_d_rm_mem_u32, in_LDMXCSR_d_rm_mem_u32, in_LDMXCSR_d_rm_mem_u32, 
	// 58
	in_STMXCSR_d_rm_mem_u32, in_STMXCSR_d_rm_mem_u32, in_STMXCSR_d_rm_mem_u32, in_STMXCSR_d_rm_mem_u32, in_STMXCSR_d_rm_mem_u32, in_STMXCSR_d_rm_mem_u32, in_STMXCSR_d_rm_mem_u32, in_STMXCSR_d_rm_mem_u32, 
	// 60
	in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, 
	// 68
	in_XRSTOR, in_XRSTOR, in_XRSTOR, in_XRSTOR, in_XRSTOR, in_XRSTOR, in_XRSTOR, in_XRSTOR, 
	// 70
	in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, 
	// 78
	in_CLFLUSH_d_rm_mem_u8, in_CLFLUSH_d_rm_mem_u8, in_CLFLUSH_d_rm_mem_u8, in_CLFLUSH_d_rm_mem_u8, in_CLFLUSH_d_rm_mem_u8, in_CLFLUSH_d_rm_mem_u8, in_CLFLUSH_d_rm_mem_u8, in_CLFLUSH_d_rm_mem_u8, 
	// 80
	in_FXSAVE_d, in_FXSAVE_d, in_FXSAVE_d, in_FXSAVE_d, in_FXSAVE_d, in_FXSAVE_d, in_FXSAVE_d, in_FXSAVE_d, 
	// 88
	in_FXRSTOR_d, in_FXRSTOR_d, in_FXRSTOR_d, in_FXRSTOR_d, in_FXRSTOR_d, in_FXRSTOR_d, in_FXRSTOR_d, in_FXRSTOR_d, 
	// 90
	in_LDMXCSR_d_rm_mem_u32, in_LDMXCSR_d_rm_mem_u32, in_LDMXCSR_d_rm_mem_u32, in_LDMXCSR_d_rm_mem_u32, in_LDMXCSR_d_rm_mem_u32, in_LDMXCSR_d_rm_mem_u32, in_LDMXCSR_d_rm_mem_u32, in_LDMXCSR_d_rm_mem_u32, 
	// 98
	in_STMXCSR_d_rm_mem_u32, in_STMXCSR_d_rm_mem_u32, in_STMXCSR_d_rm_mem_u32, in_STMXCSR_d_rm_mem_u32, in_STMXCSR_d_rm_mem_u32, in_STMXCSR_d_rm_mem_u32, in_STMXCSR_d_rm_mem_u32, in_STMXCSR_d_rm_mem_u32, 
	// A0
	in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, 
	// A8
	in_XRSTOR, in_XRSTOR, in_XRSTOR, in_XRSTOR, in_XRSTOR, in_XRSTOR, in_XRSTOR, in_XRSTOR, 
	// B0
	in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, 
	// B8
	in_CLFLUSH_d_rm_mem_u8, in_CLFLUSH_d_rm_mem_u8, in_CLFLUSH_d_rm_mem_u8, in_CLFLUSH_d_rm_mem_u8, in_CLFLUSH_d_rm_mem_u8, in_CLFLUSH_d_rm_mem_u8, in_CLFLUSH_d_rm_mem_u8, in_CLFLUSH_d_rm_mem_u8, 
	// C0
	in_FXSAVE_d, in_FXSAVE_d, in_FXSAVE_d, in_FXSAVE_d, in_FXSAVE_d, in_FXSAVE_d, in_FXSAVE_d, in_FXSAVE_d, 
	// C8
	in_FXRSTOR_d, in_FXRSTOR_d, in_FXRSTOR_d, in_FXRSTOR_d, in_FXRSTOR_d, in_FXRSTOR_d, in_FXRSTOR_d, in_FXRSTOR_d, 
	// D0
	in_LDMXCSR_d_rm_mem_u32, in_LDMXCSR_d_rm_mem_u32, in_LDMXCSR_d_rm_mem_u32, in_LDMXCSR_d_rm_mem_u32, in_LDMXCSR_d_rm_mem_u32, in_LDMXCSR_d_rm_mem_u32, in_LDMXCSR_d_rm_mem_u32, in_LDMXCSR_d_rm_mem_u32, 
	// D8
	in_STMXCSR_d_rm_mem_u32, in_STMXCSR_d_rm_mem_u32, in_STMXCSR_d_rm_mem_u32, in_STMXCSR_d_rm_mem_u32, in_STMXCSR_d_rm_mem_u32, in_STMXCSR_d_rm_mem_u32, in_STMXCSR_d_rm_mem_u32, in_STMXCSR_d_rm_mem_u32, 
	// E0
	in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, in_XSAVE, 
	// E8
	in_LFENCE, in_LFENCE, in_LFENCE, in_LFENCE, in_LFENCE, in_LFENCE, in_LFENCE, in_LFENCE, 
	// F0
	in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, in_MFENCE, 
	// F8
	in_SFENCE, in_SFENCE, in_SFENCE, in_SFENCE, in_SFENCE, in_SFENCE, in_SFENCE, in_SFENCE, 
};
const OpState CpuRunnerX86::table_st_w_w_0F_BA[] = {
	// 00
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_BT_w_imm_u8, in_BT_w_imm_u8, in_BT_w_imm_u8, in_BT_w_imm_u8, in_BT_w_imm_u8, in_BT_w_imm_u8, in_BT_w_imm_u8, in_BT_w_imm_u8, 
	// 28
	in_BTS_w_rm_mod_reg_u16_imm_u8, in_BTS_w_rm_mod_reg_u16_imm_u8, in_BTS_w_rm_mod_reg_u16_imm_u8, in_BTS_w_rm_mod_reg_u16_imm_u8, in_BTS_w_rm_mod_reg_u16_imm_u8, in_BTS_w_rm_mod_reg_u16_imm_u8, in_BTS_w_rm_mod_reg_u16_imm_u8, in_BTS_w_rm_mod_reg_u16_imm_u8, 
	// 30
	in_BTR_w_rm_mod_reg_u16_imm_u8, in_BTR_w_rm_mod_reg_u16_imm_u8, in_BTR_w_rm_mod_reg_u16_imm_u8, in_BTR_w_rm_mod_reg_u16_imm_u8, in_BTR_w_rm_mod_reg_u16_imm_u8, in_BTR_w_rm_mod_reg_u16_imm_u8, in_BTR_w_rm_mod_reg_u16_imm_u8, in_BTR_w_rm_mod_reg_u16_imm_u8, 
	// 38
	in_BTC_w_rm_mod_reg_u16_imm_u8, in_BTC_w_rm_mod_reg_u16_imm_u8, in_BTC_w_rm_mod_reg_u16_imm_u8, in_BTC_w_rm_mod_reg_u16_imm_u8, in_BTC_w_rm_mod_reg_u16_imm_u8, in_BTC_w_rm_mod_reg_u16_imm_u8, in_BTC_w_rm_mod_reg_u16_imm_u8, in_BTC_w_rm_mod_reg_u16_imm_u8, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_BT_w_imm_u8, in_BT_w_imm_u8, in_BT_w_imm_u8, in_BT_w_imm_u8, in_BT_w_imm_u8, in_BT_w_imm_u8, in_BT_w_imm_u8, in_BT_w_imm_u8, 
	// 68
	in_BTS_w_rm_mod_reg_u16_imm_u8, in_BTS_w_rm_mod_reg_u16_imm_u8, in_BTS_w_rm_mod_reg_u16_imm_u8, in_BTS_w_rm_mod_reg_u16_imm_u8, in_BTS_w_rm_mod_reg_u16_imm_u8, in_BTS_w_rm_mod_reg_u16_imm_u8, in_BTS_w_rm_mod_reg_u16_imm_u8, in_BTS_w_rm_mod_reg_u16_imm_u8, 
	// 70
	in_BTR_w_rm_mod_reg_u16_imm_u8, in_BTR_w_rm_mod_reg_u16_imm_u8, in_BTR_w_rm_mod_reg_u16_imm_u8, in_BTR_w_rm_mod_reg_u16_imm_u8, in_BTR_w_rm_mod_reg_u16_imm_u8, in_BTR_w_rm_mod_reg_u16_imm_u8, in_BTR_w_rm_mod_reg_u16_imm_u8, in_BTR_w_rm_mod_reg_u16_imm_u8, 
	// 78
	in_BTC_w_rm_mod_reg_u16_imm_u8, in_BTC_w_rm_mod_reg_u16_imm_u8, in_BTC_w_rm_mod_reg_u16_imm_u8, in_BTC_w_rm_mod_reg_u16_imm_u8, in_BTC_w_rm_mod_reg_u16_imm_u8, in_BTC_w_rm_mod_reg_u16_imm_u8, in_BTC_w_rm_mod_reg_u16_imm_u8, in_BTC_w_rm_mod_reg_u16_imm_u8, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_BT_w_imm_u8, in_BT_w_imm_u8, in_BT_w_imm_u8, in_BT_w_imm_u8, in_BT_w_imm_u8, in_BT_w_imm_u8, in_BT_w_imm_u8, in_BT_w_imm_u8, 
	// A8
	in_BTS_w_rm_mod_reg_u16_imm_u8, in_BTS_w_rm_mod_reg_u16_imm_u8, in_BTS_w_rm_mod_reg_u16_imm_u8, in_BTS_w_rm_mod_reg_u16_imm_u8, in_BTS_w_rm_mod_reg_u16_imm_u8, in_BTS_w_rm_mod_reg_u16_imm_u8, in_BTS_w_rm_mod_reg_u16_imm_u8, in_BTS_w_rm_mod_reg_u16_imm_u8, 
	// B0
	in_BTR_w_rm_mod_reg_u16_imm_u8, in_BTR_w_rm_mod_reg_u16_imm_u8, in_BTR_w_rm_mod_reg_u16_imm_u8, in_BTR_w_rm_mod_reg_u16_imm_u8, in_BTR_w_rm_mod_reg_u16_imm_u8, in_BTR_w_rm_mod_reg_u16_imm_u8, in_BTR_w_rm_mod_reg_u16_imm_u8, in_BTR_w_rm_mod_reg_u16_imm_u8, 
	// B8
	in_BTC_w_rm_mod_reg_u16_imm_u8, in_BTC_w_rm_mod_reg_u16_imm_u8, in_BTC_w_rm_mod_reg_u16_imm_u8, in_BTC_w_rm_mod_reg_u16_imm_u8, in_BTC_w_rm_mod_reg_u16_imm_u8, in_BTC_w_rm_mod_reg_u16_imm_u8, in_BTC_w_rm_mod_reg_u16_imm_u8, in_BTC_w_rm_mod_reg_u16_imm_u8, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_BT_w_imm_u8, in_BT_w_imm_u8, in_BT_w_imm_u8, in_BT_w_imm_u8, in_BT_w_imm_u8, in_BT_w_imm_u8, in_BT_w_imm_u8, in_BT_w_imm_u8, 
	// E8
	in_BTS_w_rm_mod_reg_u16_imm_u8, in_BTS_w_rm_mod_reg_u16_imm_u8, in_BTS_w_rm_mod_reg_u16_imm_u8, in_BTS_w_rm_mod_reg_u16_imm_u8, in_BTS_w_rm_mod_reg_u16_imm_u8, in_BTS_w_rm_mod_reg_u16_imm_u8, in_BTS_w_rm_mod_reg_u16_imm_u8, in_BTS_w_rm_mod_reg_u16_imm_u8, 
	// F0
	in_BTR_w_rm_mod_reg_u16_imm_u8, in_BTR_w_rm_mod_reg_u16_imm_u8, in_BTR_w_rm_mod_reg_u16_imm_u8, in_BTR_w_rm_mod_reg_u16_imm_u8, in_BTR_w_rm_mod_reg_u16_imm_u8, in_BTR_w_rm_mod_reg_u16_imm_u8, in_BTR_w_rm_mod_reg_u16_imm_u8, in_BTR_w_rm_mod_reg_u16_imm_u8, 
	// F8
	in_BTC_w_rm_mod_reg_u16_imm_u8, in_BTC_w_rm_mod_reg_u16_imm_u8, in_BTC_w_rm_mod_reg_u16_imm_u8, in_BTC_w_rm_mod_reg_u16_imm_u8, in_BTC_w_rm_mod_reg_u16_imm_u8, in_BTC_w_rm_mod_reg_u16_imm_u8, in_BTC_w_rm_mod_reg_u16_imm_u8, in_BTC_w_rm_mod_reg_u16_imm_u8, 
};
const OpState CpuRunnerX86::table_st_w_d_0F_BA[] = {
	// 00
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_BT_w_imm_u8, in_BT_w_imm_u8, in_BT_w_imm_u8, in_BT_w_imm_u8, in_BT_w_imm_u8, in_BT_w_imm_u8, in_BT_w_imm_u8, in_BT_w_imm_u8, 
	// 28
	in_BTS_w_rm_mod_reg_u16_imm_u8, in_BTS_w_rm_mod_reg_u16_imm_u8, in_BTS_w_rm_mod_reg_u16_imm_u8, in_BTS_w_rm_mod_reg_u16_imm_u8, in_BTS_w_rm_mod_reg_u16_imm_u8, in_BTS_w_rm_mod_reg_u16_imm_u8, in_BTS_w_rm_mod_reg_u16_imm_u8, in_BTS_w_rm_mod_reg_u16_imm_u8, 
	// 30
	in_BTR_w_rm_mod_reg_u16_imm_u8, in_BTR_w_rm_mod_reg_u16_imm_u8, in_BTR_w_rm_mod_reg_u16_imm_u8, in_BTR_w_rm_mod_reg_u16_imm_u8, in_BTR_w_rm_mod_reg_u16_imm_u8, in_BTR_w_rm_mod_reg_u16_imm_u8, in_BTR_w_rm_mod_reg_u16_imm_u8, in_BTR_w_rm_mod_reg_u16_imm_u8, 
	// 38
	in_BTC_w_rm_mod_reg_u16_imm_u8, in_BTC_w_rm_mod_reg_u16_imm_u8, in_BTC_w_rm_mod_reg_u16_imm_u8, in_BTC_w_rm_mod_reg_u16_imm_u8, in_BTC_w_rm_mod_reg_u16_imm_u8, in_BTC_w_rm_mod_reg_u16_imm_u8, in_BTC_w_rm_mod_reg_u16_imm_u8, in_BTC_w_rm_mod_reg_u16_imm_u8, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_BT_w_imm_u8, in_BT_w_imm_u8, in_BT_w_imm_u8, in_BT_w_imm_u8, in_BT_w_imm_u8, in_BT_w_imm_u8, in_BT_w_imm_u8, in_BT_w_imm_u8, 
	// 68
	in_BTS_w_rm_mod_reg_u16_imm_u8, in_BTS_w_rm_mod_reg_u16_imm_u8, in_BTS_w_rm_mod_reg_u16_imm_u8, in_BTS_w_rm_mod_reg_u16_imm_u8, in_BTS_w_rm_mod_reg_u16_imm_u8, in_BTS_w_rm_mod_reg_u16_imm_u8, in_BTS_w_rm_mod_reg_u16_imm_u8, in_BTS_w_rm_mod_reg_u16_imm_u8, 
	// 70
	in_BTR_w_rm_mod_reg_u16_imm_u8, in_BTR_w_rm_mod_reg_u16_imm_u8, in_BTR_w_rm_mod_reg_u16_imm_u8, in_BTR_w_rm_mod_reg_u16_imm_u8, in_BTR_w_rm_mod_reg_u16_imm_u8, in_BTR_w_rm_mod_reg_u16_imm_u8, in_BTR_w_rm_mod_reg_u16_imm_u8, in_BTR_w_rm_mod_reg_u16_imm_u8, 
	// 78
	in_BTC_w_rm_mod_reg_u16_imm_u8, in_BTC_w_rm_mod_reg_u16_imm_u8, in_BTC_w_rm_mod_reg_u16_imm_u8, in_BTC_w_rm_mod_reg_u16_imm_u8, in_BTC_w_rm_mod_reg_u16_imm_u8, in_BTC_w_rm_mod_reg_u16_imm_u8, in_BTC_w_rm_mod_reg_u16_imm_u8, in_BTC_w_rm_mod_reg_u16_imm_u8, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_BT_w_imm_u8, in_BT_w_imm_u8, in_BT_w_imm_u8, in_BT_w_imm_u8, in_BT_w_imm_u8, in_BT_w_imm_u8, in_BT_w_imm_u8, in_BT_w_imm_u8, 
	// A8
	in_BTS_w_rm_mod_reg_u16_imm_u8, in_BTS_w_rm_mod_reg_u16_imm_u8, in_BTS_w_rm_mod_reg_u16_imm_u8, in_BTS_w_rm_mod_reg_u16_imm_u8, in_BTS_w_rm_mod_reg_u16_imm_u8, in_BTS_w_rm_mod_reg_u16_imm_u8, in_BTS_w_rm_mod_reg_u16_imm_u8, in_BTS_w_rm_mod_reg_u16_imm_u8, 
	// B0
	in_BTR_w_rm_mod_reg_u16_imm_u8, in_BTR_w_rm_mod_reg_u16_imm_u8, in_BTR_w_rm_mod_reg_u16_imm_u8, in_BTR_w_rm_mod_reg_u16_imm_u8, in_BTR_w_rm_mod_reg_u16_imm_u8, in_BTR_w_rm_mod_reg_u16_imm_u8, in_BTR_w_rm_mod_reg_u16_imm_u8, in_BTR_w_rm_mod_reg_u16_imm_u8, 
	// B8
	in_BTC_w_rm_mod_reg_u16_imm_u8, in_BTC_w_rm_mod_reg_u16_imm_u8, in_BTC_w_rm_mod_reg_u16_imm_u8, in_BTC_w_rm_mod_reg_u16_imm_u8, in_BTC_w_rm_mod_reg_u16_imm_u8, in_BTC_w_rm_mod_reg_u16_imm_u8, in_BTC_w_rm_mod_reg_u16_imm_u8, in_BTC_w_rm_mod_reg_u16_imm_u8, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_BT_w_imm_u8, in_BT_w_imm_u8, in_BT_w_imm_u8, in_BT_w_imm_u8, in_BT_w_imm_u8, in_BT_w_imm_u8, in_BT_w_imm_u8, in_BT_w_imm_u8, 
	// E8
	in_BTS_w_rm_mod_reg_u16_imm_u8, in_BTS_w_rm_mod_reg_u16_imm_u8, in_BTS_w_rm_mod_reg_u16_imm_u8, in_BTS_w_rm_mod_reg_u16_imm_u8, in_BTS_w_rm_mod_reg_u16_imm_u8, in_BTS_w_rm_mod_reg_u16_imm_u8, in_BTS_w_rm_mod_reg_u16_imm_u8, in_BTS_w_rm_mod_reg_u16_imm_u8, 
	// F0
	in_BTR_w_rm_mod_reg_u16_imm_u8, in_BTR_w_rm_mod_reg_u16_imm_u8, in_BTR_w_rm_mod_reg_u16_imm_u8, in_BTR_w_rm_mod_reg_u16_imm_u8, in_BTR_w_rm_mod_reg_u16_imm_u8, in_BTR_w_rm_mod_reg_u16_imm_u8, in_BTR_w_rm_mod_reg_u16_imm_u8, in_BTR_w_rm_mod_reg_u16_imm_u8, 
	// F8
	in_BTC_w_rm_mod_reg_u16_imm_u8, in_BTC_w_rm_mod_reg_u16_imm_u8, in_BTC_w_rm_mod_reg_u16_imm_u8, in_BTC_w_rm_mod_reg_u16_imm_u8, in_BTC_w_rm_mod_reg_u16_imm_u8, in_BTC_w_rm_mod_reg_u16_imm_u8, in_BTC_w_rm_mod_reg_u16_imm_u8, in_BTC_w_rm_mod_reg_u16_imm_u8, 
};
const OpState CpuRunnerX86::table_st_d_w_0F_BA[] = {
	// 00
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_BT_d_imm_u8, in_BT_d_imm_u8, in_BT_d_imm_u8, in_BT_d_imm_u8, in_BT_d_imm_u8, in_BT_d_imm_u8, in_BT_d_imm_u8, in_BT_d_imm_u8, 
	// 28
	in_BTS_d_rm_mod_reg_u16_imm_u8, in_BTS_d_rm_mod_reg_u16_imm_u8, in_BTS_d_rm_mod_reg_u16_imm_u8, in_BTS_d_rm_mod_reg_u16_imm_u8, in_BTS_d_rm_mod_reg_u16_imm_u8, in_BTS_d_rm_mod_reg_u16_imm_u8, in_BTS_d_rm_mod_reg_u16_imm_u8, in_BTS_d_rm_mod_reg_u16_imm_u8, 
	// 30
	in_BTR_d_rm_mod_reg_u16_imm_u8, in_BTR_d_rm_mod_reg_u16_imm_u8, in_BTR_d_rm_mod_reg_u16_imm_u8, in_BTR_d_rm_mod_reg_u16_imm_u8, in_BTR_d_rm_mod_reg_u16_imm_u8, in_BTR_d_rm_mod_reg_u16_imm_u8, in_BTR_d_rm_mod_reg_u16_imm_u8, in_BTR_d_rm_mod_reg_u16_imm_u8, 
	// 38
	in_BTC_d_rm_mod_reg_u16_imm_u8, in_BTC_d_rm_mod_reg_u16_imm_u8, in_BTC_d_rm_mod_reg_u16_imm_u8, in_BTC_d_rm_mod_reg_u16_imm_u8, in_BTC_d_rm_mod_reg_u16_imm_u8, in_BTC_d_rm_mod_reg_u16_imm_u8, in_BTC_d_rm_mod_reg_u16_imm_u8, in_BTC_d_rm_mod_reg_u16_imm_u8, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_BT_d_imm_u8, in_BT_d_imm_u8, in_BT_d_imm_u8, in_BT_d_imm_u8, in_BT_d_imm_u8, in_BT_d_imm_u8, in_BT_d_imm_u8, in_BT_d_imm_u8, 
	// 68
	in_BTS_d_rm_mod_reg_u16_imm_u8, in_BTS_d_rm_mod_reg_u16_imm_u8, in_BTS_d_rm_mod_reg_u16_imm_u8, in_BTS_d_rm_mod_reg_u16_imm_u8, in_BTS_d_rm_mod_reg_u16_imm_u8, in_BTS_d_rm_mod_reg_u16_imm_u8, in_BTS_d_rm_mod_reg_u16_imm_u8, in_BTS_d_rm_mod_reg_u16_imm_u8, 
	// 70
	in_BTR_d_rm_mod_reg_u16_imm_u8, in_BTR_d_rm_mod_reg_u16_imm_u8, in_BTR_d_rm_mod_reg_u16_imm_u8, in_BTR_d_rm_mod_reg_u16_imm_u8, in_BTR_d_rm_mod_reg_u16_imm_u8, in_BTR_d_rm_mod_reg_u16_imm_u8, in_BTR_d_rm_mod_reg_u16_imm_u8, in_BTR_d_rm_mod_reg_u16_imm_u8, 
	// 78
	in_BTC_d_rm_mod_reg_u16_imm_u8, in_BTC_d_rm_mod_reg_u16_imm_u8, in_BTC_d_rm_mod_reg_u16_imm_u8, in_BTC_d_rm_mod_reg_u16_imm_u8, in_BTC_d_rm_mod_reg_u16_imm_u8, in_BTC_d_rm_mod_reg_u16_imm_u8, in_BTC_d_rm_mod_reg_u16_imm_u8, in_BTC_d_rm_mod_reg_u16_imm_u8, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_BT_d_imm_u8, in_BT_d_imm_u8, in_BT_d_imm_u8, in_BT_d_imm_u8, in_BT_d_imm_u8, in_BT_d_imm_u8, in_BT_d_imm_u8, in_BT_d_imm_u8, 
	// A8
	in_BTS_d_rm_mod_reg_u16_imm_u8, in_BTS_d_rm_mod_reg_u16_imm_u8, in_BTS_d_rm_mod_reg_u16_imm_u8, in_BTS_d_rm_mod_reg_u16_imm_u8, in_BTS_d_rm_mod_reg_u16_imm_u8, in_BTS_d_rm_mod_reg_u16_imm_u8, in_BTS_d_rm_mod_reg_u16_imm_u8, in_BTS_d_rm_mod_reg_u16_imm_u8, 
	// B0
	in_BTR_d_rm_mod_reg_u16_imm_u8, in_BTR_d_rm_mod_reg_u16_imm_u8, in_BTR_d_rm_mod_reg_u16_imm_u8, in_BTR_d_rm_mod_reg_u16_imm_u8, in_BTR_d_rm_mod_reg_u16_imm_u8, in_BTR_d_rm_mod_reg_u16_imm_u8, in_BTR_d_rm_mod_reg_u16_imm_u8, in_BTR_d_rm_mod_reg_u16_imm_u8, 
	// B8
	in_BTC_d_rm_mod_reg_u16_imm_u8, in_BTC_d_rm_mod_reg_u16_imm_u8, in_BTC_d_rm_mod_reg_u16_imm_u8, in_BTC_d_rm_mod_reg_u16_imm_u8, in_BTC_d_rm_mod_reg_u16_imm_u8, in_BTC_d_rm_mod_reg_u16_imm_u8, in_BTC_d_rm_mod_reg_u16_imm_u8, in_BTC_d_rm_mod_reg_u16_imm_u8, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_BT_d_imm_u8, in_BT_d_imm_u8, in_BT_d_imm_u8, in_BT_d_imm_u8, in_BT_d_imm_u8, in_BT_d_imm_u8, in_BT_d_imm_u8, in_BT_d_imm_u8, 
	// E8
	in_BTS_d_rm_mod_reg_u16_imm_u8, in_BTS_d_rm_mod_reg_u16_imm_u8, in_BTS_d_rm_mod_reg_u16_imm_u8, in_BTS_d_rm_mod_reg_u16_imm_u8, in_BTS_d_rm_mod_reg_u16_imm_u8, in_BTS_d_rm_mod_reg_u16_imm_u8, in_BTS_d_rm_mod_reg_u16_imm_u8, in_BTS_d_rm_mod_reg_u16_imm_u8, 
	// F0
	in_BTR_d_rm_mod_reg_u16_imm_u8, in_BTR_d_rm_mod_reg_u16_imm_u8, in_BTR_d_rm_mod_reg_u16_imm_u8, in_BTR_d_rm_mod_reg_u16_imm_u8, in_BTR_d_rm_mod_reg_u16_imm_u8, in_BTR_d_rm_mod_reg_u16_imm_u8, in_BTR_d_rm_mod_reg_u16_imm_u8, in_BTR_d_rm_mod_reg_u16_imm_u8, 
	// F8
	in_BTC_d_rm_mod_reg_u16_imm_u8, in_BTC_d_rm_mod_reg_u16_imm_u8, in_BTC_d_rm_mod_reg_u16_imm_u8, in_BTC_d_rm_mod_reg_u16_imm_u8, in_BTC_d_rm_mod_reg_u16_imm_u8, in_BTC_d_rm_mod_reg_u16_imm_u8, in_BTC_d_rm_mod_reg_u16_imm_u8, in_BTC_d_rm_mod_reg_u16_imm_u8, 
};
const OpState CpuRunnerX86::table_st_d_d_0F_BA[] = {
	// 00
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_BT_d_imm_u8, in_BT_d_imm_u8, in_BT_d_imm_u8, in_BT_d_imm_u8, in_BT_d_imm_u8, in_BT_d_imm_u8, in_BT_d_imm_u8, in_BT_d_imm_u8, 
	// 28
	in_BTS_d_rm_mod_reg_u16_imm_u8, in_BTS_d_rm_mod_reg_u16_imm_u8, in_BTS_d_rm_mod_reg_u16_imm_u8, in_BTS_d_rm_mod_reg_u16_imm_u8, in_BTS_d_rm_mod_reg_u16_imm_u8, in_BTS_d_rm_mod_reg_u16_imm_u8, in_BTS_d_rm_mod_reg_u16_imm_u8, in_BTS_d_rm_mod_reg_u16_imm_u8, 
	// 30
	in_BTR_d_rm_mod_reg_u16_imm_u8, in_BTR_d_rm_mod_reg_u16_imm_u8, in_BTR_d_rm_mod_reg_u16_imm_u8, in_BTR_d_rm_mod_reg_u16_imm_u8, in_BTR_d_rm_mod_reg_u16_imm_u8, in_BTR_d_rm_mod_reg_u16_imm_u8, in_BTR_d_rm_mod_reg_u16_imm_u8, in_BTR_d_rm_mod_reg_u16_imm_u8, 
	// 38
	in_BTC_d_rm_mod_reg_u16_imm_u8, in_BTC_d_rm_mod_reg_u16_imm_u8, in_BTC_d_rm_mod_reg_u16_imm_u8, in_BTC_d_rm_mod_reg_u16_imm_u8, in_BTC_d_rm_mod_reg_u16_imm_u8, in_BTC_d_rm_mod_reg_u16_imm_u8, in_BTC_d_rm_mod_reg_u16_imm_u8, in_BTC_d_rm_mod_reg_u16_imm_u8, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_BT_d_imm_u8, in_BT_d_imm_u8, in_BT_d_imm_u8, in_BT_d_imm_u8, in_BT_d_imm_u8, in_BT_d_imm_u8, in_BT_d_imm_u8, in_BT_d_imm_u8, 
	// 68
	in_BTS_d_rm_mod_reg_u16_imm_u8, in_BTS_d_rm_mod_reg_u16_imm_u8, in_BTS_d_rm_mod_reg_u16_imm_u8, in_BTS_d_rm_mod_reg_u16_imm_u8, in_BTS_d_rm_mod_reg_u16_imm_u8, in_BTS_d_rm_mod_reg_u16_imm_u8, in_BTS_d_rm_mod_reg_u16_imm_u8, in_BTS_d_rm_mod_reg_u16_imm_u8, 
	// 70
	in_BTR_d_rm_mod_reg_u16_imm_u8, in_BTR_d_rm_mod_reg_u16_imm_u8, in_BTR_d_rm_mod_reg_u16_imm_u8, in_BTR_d_rm_mod_reg_u16_imm_u8, in_BTR_d_rm_mod_reg_u16_imm_u8, in_BTR_d_rm_mod_reg_u16_imm_u8, in_BTR_d_rm_mod_reg_u16_imm_u8, in_BTR_d_rm_mod_reg_u16_imm_u8, 
	// 78
	in_BTC_d_rm_mod_reg_u16_imm_u8, in_BTC_d_rm_mod_reg_u16_imm_u8, in_BTC_d_rm_mod_reg_u16_imm_u8, in_BTC_d_rm_mod_reg_u16_imm_u8, in_BTC_d_rm_mod_reg_u16_imm_u8, in_BTC_d_rm_mod_reg_u16_imm_u8, in_BTC_d_rm_mod_reg_u16_imm_u8, in_BTC_d_rm_mod_reg_u16_imm_u8, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_BT_d_imm_u8, in_BT_d_imm_u8, in_BT_d_imm_u8, in_BT_d_imm_u8, in_BT_d_imm_u8, in_BT_d_imm_u8, in_BT_d_imm_u8, in_BT_d_imm_u8, 
	// A8
	in_BTS_d_rm_mod_reg_u16_imm_u8, in_BTS_d_rm_mod_reg_u16_imm_u8, in_BTS_d_rm_mod_reg_u16_imm_u8, in_BTS_d_rm_mod_reg_u16_imm_u8, in_BTS_d_rm_mod_reg_u16_imm_u8, in_BTS_d_rm_mod_reg_u16_imm_u8, in_BTS_d_rm_mod_reg_u16_imm_u8, in_BTS_d_rm_mod_reg_u16_imm_u8, 
	// B0
	in_BTR_d_rm_mod_reg_u16_imm_u8, in_BTR_d_rm_mod_reg_u16_imm_u8, in_BTR_d_rm_mod_reg_u16_imm_u8, in_BTR_d_rm_mod_reg_u16_imm_u8, in_BTR_d_rm_mod_reg_u16_imm_u8, in_BTR_d_rm_mod_reg_u16_imm_u8, in_BTR_d_rm_mod_reg_u16_imm_u8, in_BTR_d_rm_mod_reg_u16_imm_u8, 
	// B8
	in_BTC_d_rm_mod_reg_u16_imm_u8, in_BTC_d_rm_mod_reg_u16_imm_u8, in_BTC_d_rm_mod_reg_u16_imm_u8, in_BTC_d_rm_mod_reg_u16_imm_u8, in_BTC_d_rm_mod_reg_u16_imm_u8, in_BTC_d_rm_mod_reg_u16_imm_u8, in_BTC_d_rm_mod_reg_u16_imm_u8, in_BTC_d_rm_mod_reg_u16_imm_u8, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_BT_d_imm_u8, in_BT_d_imm_u8, in_BT_d_imm_u8, in_BT_d_imm_u8, in_BT_d_imm_u8, in_BT_d_imm_u8, in_BT_d_imm_u8, in_BT_d_imm_u8, 
	// E8
	in_BTS_d_rm_mod_reg_u16_imm_u8, in_BTS_d_rm_mod_reg_u16_imm_u8, in_BTS_d_rm_mod_reg_u16_imm_u8, in_BTS_d_rm_mod_reg_u16_imm_u8, in_BTS_d_rm_mod_reg_u16_imm_u8, in_BTS_d_rm_mod_reg_u16_imm_u8, in_BTS_d_rm_mod_reg_u16_imm_u8, in_BTS_d_rm_mod_reg_u16_imm_u8, 
	// F0
	in_BTR_d_rm_mod_reg_u16_imm_u8, in_BTR_d_rm_mod_reg_u16_imm_u8, in_BTR_d_rm_mod_reg_u16_imm_u8, in_BTR_d_rm_mod_reg_u16_imm_u8, in_BTR_d_rm_mod_reg_u16_imm_u8, in_BTR_d_rm_mod_reg_u16_imm_u8, in_BTR_d_rm_mod_reg_u16_imm_u8, in_BTR_d_rm_mod_reg_u16_imm_u8, 
	// F8
	in_BTC_d_rm_mod_reg_u16_imm_u8, in_BTC_d_rm_mod_reg_u16_imm_u8, in_BTC_d_rm_mod_reg_u16_imm_u8, in_BTC_d_rm_mod_reg_u16_imm_u8, in_BTC_d_rm_mod_reg_u16_imm_u8, in_BTC_d_rm_mod_reg_u16_imm_u8, in_BTC_d_rm_mod_reg_u16_imm_u8, in_BTC_d_rm_mod_reg_u16_imm_u8, 
};
const OpState CpuRunnerX86::table_pr_w_d_F2[] = {
	// 00
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_pr_w_d_F3[] = {
	// 00
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_pr_w_d_26[] = {
	// 00
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_pr_w_d_2E[] = {
	// 00
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_pr_w_d_36[] = {
	// 00
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_pr_w_d_3E[] = {
	// 00
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_pr_w_d_64[] = {
	// 00
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_pr_w_d_65[] = {
	// 00
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_pr_d_d_F0[] = {
	// 00
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_pr_w_w_F2[] = {
	// 00
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_pr_w_w_F3[] = {
	// 00
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_pr_w_w_26[] = {
	// 00
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_pr_w_w_2E[] = {
	// 00
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_pr_w_w_36[] = {
	// 00
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_pr_w_w_3E[] = {
	// 00
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_pr_w_w_64[] = {
	// 00
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_pr_w_w_65[] = {
	// 00
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_pr_d_w_F0[] = {
	// 00
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_pr_d_d_F2[] = {
	// 00
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_pr_d_d_F3[] = {
	// 00
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_pr_d_d_26[] = {
	// 00
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_pr_d_d_2E[] = {
	// 00
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_pr_d_d_36[] = {
	// 00
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_pr_d_d_3E[] = {
	// 00
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_pr_d_d_64[] = {
	// 00
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_pr_d_d_65[] = {
	// 00
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_pr_w_d_F0[] = {
	// 00
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_pr_d_w_F2[] = {
	// 00
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_pr_d_w_F3[] = {
	// 00
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_pr_d_w_26[] = {
	// 00
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_pr_d_w_2E[] = {
	// 00
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_pr_d_w_36[] = {
	// 00
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_pr_d_w_3E[] = {
	// 00
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_pr_d_w_64[] = {
	// 00
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_pr_d_w_65[] = {
	// 00
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};
const OpState CpuRunnerX86::table_pr_w_w_F0[] = {
	// 00
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 08
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 10
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 18
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 20
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 28
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 30
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 38
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 40
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 48
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 50
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 58
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 60
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 68
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 70
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 78
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 80
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 88
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 90
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// 98
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// A8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// B8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// C8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// D8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// E8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F0
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
	// F8
	in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, in_illegal, 
};

const OpState* const CpuRunnerX86::AllStateTable[] = {
	CpuRunnerX86::table_st_w_w,
	CpuRunnerX86::table_st_w_d,
	CpuRunnerX86::table_st_d_w,
	CpuRunnerX86::table_st_d_d,
	CpuRunnerX86::table_st_w_w_66,
	CpuRunnerX86::table_st_w_w_F2,
	CpuRunnerX86::table_st_w_w_F3,
	CpuRunnerX86::table_st_w_d_66,
	CpuRunnerX86::table_st_w_d_F2,
	CpuRunnerX86::table_st_w_d_F3,
	CpuRunnerX86::table_st_d_w_66,
	CpuRunnerX86::table_st_d_w_F2,
	CpuRunnerX86::table_st_d_w_F3,
	CpuRunnerX86::table_st_d_d_66,
	CpuRunnerX86::table_st_d_d_F2,
	CpuRunnerX86::table_st_d_d_F3,
	CpuRunnerX86::table_st_w_w_82,
	CpuRunnerX86::table_st_w_d_82,
	CpuRunnerX86::table_st_d_w_82,
	CpuRunnerX86::table_st_d_d_82,
	CpuRunnerX86::table_st_w_w_81,
	CpuRunnerX86::table_st_w_d_81,
	CpuRunnerX86::table_st_d_w_81,
	CpuRunnerX86::table_st_d_d_81,
	CpuRunnerX86::table_st_w_w_83,
	CpuRunnerX86::table_st_w_d_83,
	CpuRunnerX86::table_st_d_w_83,
	CpuRunnerX86::table_st_d_d_83,
	CpuRunnerX86::table_st_w_w_8F,
	CpuRunnerX86::table_st_w_d_8F,
	CpuRunnerX86::table_st_d_w_8F,
	CpuRunnerX86::table_st_d_d_8F,
	CpuRunnerX86::table_st_w_w_C0,
	CpuRunnerX86::table_st_w_d_C0,
	CpuRunnerX86::table_st_d_w_C0,
	CpuRunnerX86::table_st_d_d_C0,
	CpuRunnerX86::table_st_w_w_C1,
	CpuRunnerX86::table_st_w_d_C1,
	CpuRunnerX86::table_st_d_w_C1,
	CpuRunnerX86::table_st_d_d_C1,
	CpuRunnerX86::table_st_w_w_C6,
	CpuRunnerX86::table_st_w_d_C6,
	CpuRunnerX86::table_st_d_w_C6,
	CpuRunnerX86::table_st_d_d_C6,
	CpuRunnerX86::table_st_w_w_C7,
	CpuRunnerX86::table_st_w_d_C7,
	CpuRunnerX86::table_st_d_w_C7,
	CpuRunnerX86::table_st_d_d_C7,
	CpuRunnerX86::table_st_w_w_D0,
	CpuRunnerX86::table_st_w_d_D0,
	CpuRunnerX86::table_st_d_w_D0,
	CpuRunnerX86::table_st_d_d_D0,
	CpuRunnerX86::table_st_w_w_D1,
	CpuRunnerX86::table_st_w_d_D1,
	CpuRunnerX86::table_st_d_w_D1,
	CpuRunnerX86::table_st_d_d_D1,
	CpuRunnerX86::table_st_w_w_D2,
	CpuRunnerX86::table_st_w_d_D2,
	CpuRunnerX86::table_st_d_w_D2,
	CpuRunnerX86::table_st_d_d_D2,
	CpuRunnerX86::table_st_w_w_D3,
	CpuRunnerX86::table_st_w_d_D3,
	CpuRunnerX86::table_st_d_w_D3,
	CpuRunnerX86::table_st_d_d_D3,
	CpuRunnerX86::table_st_w_w_F6,
	CpuRunnerX86::table_st_w_d_F6,
	CpuRunnerX86::table_st_d_w_F6,
	CpuRunnerX86::table_st_d_d_F6,
	CpuRunnerX86::table_st_w_w_F7,
	CpuRunnerX86::table_st_w_d_F7,
	CpuRunnerX86::table_st_d_w_F7,
	CpuRunnerX86::table_st_d_d_F7,
	CpuRunnerX86::table_st_w_w_FE,
	CpuRunnerX86::table_st_w_d_FE,
	CpuRunnerX86::table_st_d_w_FE,
	CpuRunnerX86::table_st_d_d_FE,
	CpuRunnerX86::table_st_w_w_FF,
	CpuRunnerX86::table_st_w_d_FF,
	CpuRunnerX86::table_st_d_w_FF,
	CpuRunnerX86::table_st_d_d_FF,
	CpuRunnerX86::table_st_w_w_0F,
	CpuRunnerX86::table_st_w_w_0F_00,
	CpuRunnerX86::table_st_w_d_0F,
	CpuRunnerX86::table_st_w_d_0F_00,
	CpuRunnerX86::table_st_d_w_0F,
	CpuRunnerX86::table_st_d_w_0F_00,
	CpuRunnerX86::table_st_d_d_0F,
	CpuRunnerX86::table_st_d_d_0F_00,
	CpuRunnerX86::table_st_w_w_0F_01,
	CpuRunnerX86::table_st_w_d_0F_01,
	CpuRunnerX86::table_st_d_w_0F_01,
	CpuRunnerX86::table_st_d_d_0F_01,
	CpuRunnerX86::table_st_w_w_0F_18,
	CpuRunnerX86::table_st_w_d_0F_18,
	CpuRunnerX86::table_st_d_w_0F_18,
	CpuRunnerX86::table_st_d_d_0F_18,
	CpuRunnerX86::table_st_w_w_0F_1F,
	CpuRunnerX86::table_st_w_d_0F_1F,
	CpuRunnerX86::table_st_d_w_0F_1F,
	CpuRunnerX86::table_st_d_d_0F_1F,
	CpuRunnerX86::table_st_w_w_0F_38,
	CpuRunnerX86::table_st_w_d_0F_38,
	CpuRunnerX86::table_st_d_w_0F_38,
	CpuRunnerX86::table_st_d_d_0F_38,
	CpuRunnerX86::table_st_w_w_0F_3A,
	CpuRunnerX86::table_st_w_d_0F_3A,
	CpuRunnerX86::table_st_d_w_0F_3A,
	CpuRunnerX86::table_st_d_d_0F_3A,
	CpuRunnerX86::table_st_w_w_0F_71,
	CpuRunnerX86::table_st_w_d_0F_71,
	CpuRunnerX86::table_st_d_w_0F_71,
	CpuRunnerX86::table_st_d_d_0F_71,
	CpuRunnerX86::table_st_w_w_0F_72,
	CpuRunnerX86::table_st_w_d_0F_72,
	CpuRunnerX86::table_st_d_w_0F_72,
	CpuRunnerX86::table_st_d_d_0F_72,
	CpuRunnerX86::table_st_w_w_0F_73,
	CpuRunnerX86::table_st_w_d_0F_73,
	CpuRunnerX86::table_st_d_w_0F_73,
	CpuRunnerX86::table_st_d_d_0F_73,
	CpuRunnerX86::table_st_w_w_0F_AE,
	CpuRunnerX86::table_st_w_d_0F_AE,
	CpuRunnerX86::table_st_d_w_0F_AE,
	CpuRunnerX86::table_st_d_d_0F_AE,
	CpuRunnerX86::table_st_w_w_0F_BA,
	CpuRunnerX86::table_st_w_d_0F_BA,
	CpuRunnerX86::table_st_d_w_0F_BA,
	CpuRunnerX86::table_st_d_d_0F_BA,
	CpuRunnerX86::table_pr_w_d_F2,
	CpuRunnerX86::table_pr_w_d_F3,
	CpuRunnerX86::table_pr_w_d_26,
	CpuRunnerX86::table_pr_w_d_2E,
	CpuRunnerX86::table_pr_w_d_36,
	CpuRunnerX86::table_pr_w_d_3E,
	CpuRunnerX86::table_pr_w_d_64,
	CpuRunnerX86::table_pr_w_d_65,
	CpuRunnerX86::table_pr_d_d_F0,
	CpuRunnerX86::table_pr_w_w_F2,
	CpuRunnerX86::table_pr_w_w_F3,
	CpuRunnerX86::table_pr_w_w_26,
	CpuRunnerX86::table_pr_w_w_2E,
	CpuRunnerX86::table_pr_w_w_36,
	CpuRunnerX86::table_pr_w_w_3E,
	CpuRunnerX86::table_pr_w_w_64,
	CpuRunnerX86::table_pr_w_w_65,
	CpuRunnerX86::table_pr_d_w_F0,
	CpuRunnerX86::table_pr_d_d_F2,
	CpuRunnerX86::table_pr_d_d_F3,
	CpuRunnerX86::table_pr_d_d_26,
	CpuRunnerX86::table_pr_d_d_2E,
	CpuRunnerX86::table_pr_d_d_36,
	CpuRunnerX86::table_pr_d_d_3E,
	CpuRunnerX86::table_pr_d_d_64,
	CpuRunnerX86::table_pr_d_d_65,
	CpuRunnerX86::table_pr_w_d_F0,
	CpuRunnerX86::table_pr_d_w_F2,
	CpuRunnerX86::table_pr_d_w_F3,
	CpuRunnerX86::table_pr_d_w_26,
	CpuRunnerX86::table_pr_d_w_2E,
	CpuRunnerX86::table_pr_d_w_36,
	CpuRunnerX86::table_pr_d_w_3E,
	CpuRunnerX86::table_pr_d_w_64,
	CpuRunnerX86::table_pr_d_w_65,
	CpuRunnerX86::table_pr_w_w_F0,
};

bool CpuRunnerX86::Parse(PhysPt &cseip) {
	OpState state = mInitState;
	Bit8u insb = 0;
	do {
		insb = Fetchb(cseip);
		const OpState* table = AllStateTable[state];
		state = table[insb];

		switch(state) {
		// REP/REPZ/REPNZ prefix
		case pr_w_d_F2:
			state = handler_pr_w_d_F2();
			break;
		// REP/REPZ/REPNZ prefix
		case pr_w_d_F3:
			state = handler_pr_w_d_F3();
			break;
		// Segment override prefix
		case pr_w_d_26:
			state = handler_pr_w_d_26();
			break;
		// Segment override prefix
		case pr_w_d_2E:
			state = handler_pr_w_d_2E();
			break;
		// Segment override prefix
		case pr_w_d_36:
			state = handler_pr_w_d_36();
			break;
		// Segment override prefix
		case pr_w_d_3E:
			state = handler_pr_w_d_3E();
			break;
		// Segment override prefix
		case pr_w_d_64:
			state = handler_pr_w_d_64();
			break;
		// Segment override prefix
		case pr_w_d_65:
			state = handler_pr_w_d_65();
			break;
		// Lock prefix
		case pr_d_d_F0:
			state = handler_pr_d_d_F0();
			break;
		// REP/REPZ/REPNZ prefix
		case pr_w_w_F2:
			state = handler_pr_w_w_F2();
			break;
		// REP/REPZ/REPNZ prefix
		case pr_w_w_F3:
			state = handler_pr_w_w_F3();
			break;
		// Segment override prefix
		case pr_w_w_26:
			state = handler_pr_w_w_26();
			break;
		// Segment override prefix
		case pr_w_w_2E:
			state = handler_pr_w_w_2E();
			break;
		// Segment override prefix
		case pr_w_w_36:
			state = handler_pr_w_w_36();
			break;
		// Segment override prefix
		case pr_w_w_3E:
			state = handler_pr_w_w_3E();
			break;
		// Segment override prefix
		case pr_w_w_64:
			state = handler_pr_w_w_64();
			break;
		// Segment override prefix
		case pr_w_w_65:
			state = handler_pr_w_w_65();
			break;
		// Lock prefix
		case pr_d_w_F0:
			state = handler_pr_d_w_F0();
			break;
		// REP/REPZ/REPNZ prefix
		case pr_d_d_F2:
			state = handler_pr_d_d_F2();
			break;
		// REP/REPZ/REPNZ prefix
		case pr_d_d_F3:
			state = handler_pr_d_d_F3();
			break;
		// Segment override prefix
		case pr_d_d_26:
			state = handler_pr_d_d_26();
			break;
		// Segment override prefix
		case pr_d_d_2E:
			state = handler_pr_d_d_2E();
			break;
		// Segment override prefix
		case pr_d_d_36:
			state = handler_pr_d_d_36();
			break;
		// Segment override prefix
		case pr_d_d_3E:
			state = handler_pr_d_d_3E();
			break;
		// Segment override prefix
		case pr_d_d_64:
			state = handler_pr_d_d_64();
			break;
		// Segment override prefix
		case pr_d_d_65:
			state = handler_pr_d_d_65();
			break;
		// Lock prefix
		case pr_w_d_F0:
			state = handler_pr_w_d_F0();
			break;
		// REP/REPZ/REPNZ prefix
		case pr_d_w_F2:
			state = handler_pr_d_w_F2();
			break;
		// REP/REPZ/REPNZ prefix
		case pr_d_w_F3:
			state = handler_pr_d_w_F3();
			break;
		// Segment override prefix
		case pr_d_w_26:
			state = handler_pr_d_w_26();
			break;
		// Segment override prefix
		case pr_d_w_2E:
			state = handler_pr_d_w_2E();
			break;
		// Segment override prefix
		case pr_d_w_36:
			state = handler_pr_d_w_36();
			break;
		// Segment override prefix
		case pr_d_w_3E:
			state = handler_pr_d_w_3E();
			break;
		// Segment override prefix
		case pr_d_w_64:
			state = handler_pr_d_w_64();
			break;
		// Segment override prefix
		case pr_d_w_65:
			state = handler_pr_d_w_65();
			break;
		// Lock prefix
		case pr_w_w_F0:
			state = handler_pr_w_w_F0();
			break;

		default:
			break;
		}
	} while(state < in_illegal);

	switch(state) {
	case in_ADD_w_rm_mod_reg_u8_rm_reg_reg_u8:
		return handler_ADD_w_rm_mod_reg_u8_rm_reg_reg_u8(insb, cseip);
	case in_ADD_d_rm_mod_reg_u8_rm_reg_reg_u8:
		return handler_ADD_d_rm_mod_reg_u8_rm_reg_reg_u8(insb, cseip);
	case in_ADD_w_rm_mod_reg_u16_rm_reg_reg_u16:
		return handler_ADD_w_rm_mod_reg_u16_rm_reg_reg_u16(insb, cseip);
	case in_ADD_w_rm_mod_reg_u32_rm_reg_reg_u32:
		return handler_ADD_w_rm_mod_reg_u32_rm_reg_reg_u32(insb, cseip);
	case in_ADD_d_rm_mod_reg_u16_rm_reg_reg_u16:
		return handler_ADD_d_rm_mod_reg_u16_rm_reg_reg_u16(insb, cseip);
	case in_ADD_d_rm_mod_reg_u32_rm_reg_reg_u32:
		return handler_ADD_d_rm_mod_reg_u32_rm_reg_reg_u32(insb, cseip);
	case in_ADD_w_rm_reg_reg_u8_rm_mod_reg_u8:
		return handler_ADD_w_rm_reg_reg_u8_rm_mod_reg_u8(insb, cseip);
	case in_ADD_d_rm_reg_reg_u8_rm_mod_reg_u8:
		return handler_ADD_d_rm_reg_reg_u8_rm_mod_reg_u8(insb, cseip);
	case in_ADD_w_rm_reg_reg_u16_rm_mod_reg_u16:
		return handler_ADD_w_rm_reg_reg_u16_rm_mod_reg_u16(insb, cseip);
	case in_ADD_w_rm_reg_reg_u32_rm_mod_reg_u32:
		return handler_ADD_w_rm_reg_reg_u32_rm_mod_reg_u32(insb, cseip);
	case in_ADD_d_rm_reg_reg_u16_rm_mod_reg_u16:
		return handler_ADD_d_rm_reg_reg_u16_rm_mod_reg_u16(insb, cseip);
	case in_ADD_d_rm_reg_reg_u32_rm_mod_reg_u32:
		return handler_ADD_d_rm_reg_reg_u32_rm_mod_reg_u32(insb, cseip);
	case in_ADD_reg_gen_u8_imm_u8:
		return handler_ADD_reg_gen_u8_imm_u8(insb, cseip);
	case in_ADD_reg_gen_u16_imm_i16:
		return handler_ADD_reg_gen_u16_imm_i16(insb, cseip);
	case in_ADD_reg_gen_u32_imm_i32:
		return handler_ADD_reg_gen_u32_imm_i32(insb, cseip);
	case in_PUSH_reg_seg_u16:
		return handler_PUSH_reg_seg_u16(insb, cseip);
	case in_POP_reg_seg_u16:
		return handler_POP_reg_seg_u16(insb, cseip);
	case in_OR_w_rm_mod_reg_u8_rm_reg_reg_u8:
		return handler_OR_w_rm_mod_reg_u8_rm_reg_reg_u8(insb, cseip);
	case in_OR_d_rm_mod_reg_u8_rm_reg_reg_u8:
		return handler_OR_d_rm_mod_reg_u8_rm_reg_reg_u8(insb, cseip);
	case in_OR_w_rm_mod_reg_u16_rm_reg_reg_u16:
		return handler_OR_w_rm_mod_reg_u16_rm_reg_reg_u16(insb, cseip);
	case in_OR_w_rm_mod_reg_u32_rm_reg_reg_u32:
		return handler_OR_w_rm_mod_reg_u32_rm_reg_reg_u32(insb, cseip);
	case in_OR_d_rm_mod_reg_u16_rm_reg_reg_u16:
		return handler_OR_d_rm_mod_reg_u16_rm_reg_reg_u16(insb, cseip);
	case in_OR_d_rm_mod_reg_u32_rm_reg_reg_u32:
		return handler_OR_d_rm_mod_reg_u32_rm_reg_reg_u32(insb, cseip);
	case in_OR_w_rm_reg_reg_u8_rm_mod_reg_u8:
		return handler_OR_w_rm_reg_reg_u8_rm_mod_reg_u8(insb, cseip);
	case in_OR_d_rm_reg_reg_u8_rm_mod_reg_u8:
		return handler_OR_d_rm_reg_reg_u8_rm_mod_reg_u8(insb, cseip);
	case in_OR_w_rm_reg_reg_u16_rm_mod_reg_u16:
		return handler_OR_w_rm_reg_reg_u16_rm_mod_reg_u16(insb, cseip);
	case in_OR_w_rm_reg_reg_u32_rm_mod_reg_u32:
		return handler_OR_w_rm_reg_reg_u32_rm_mod_reg_u32(insb, cseip);
	case in_OR_d_rm_reg_reg_u16_rm_mod_reg_u16:
		return handler_OR_d_rm_reg_reg_u16_rm_mod_reg_u16(insb, cseip);
	case in_OR_d_rm_reg_reg_u32_rm_mod_reg_u32:
		return handler_OR_d_rm_reg_reg_u32_rm_mod_reg_u32(insb, cseip);
	case in_OR_reg_gen_u8_imm_u8:
		return handler_OR_reg_gen_u8_imm_u8(insb, cseip);
	case in_OR_reg_gen_u16_imm_i16:
		return handler_OR_reg_gen_u16_imm_i16(insb, cseip);
	case in_OR_reg_gen_u32_imm_i32:
		return handler_OR_reg_gen_u32_imm_i32(insb, cseip);
	case in_PUSH_reg_seg_1_u16:
		return handler_PUSH_reg_seg_1_u16(insb, cseip);
	case in_ADC_w_rm_mod_reg_u8_rm_reg_reg_u8:
		return handler_ADC_w_rm_mod_reg_u8_rm_reg_reg_u8(insb, cseip);
	case in_ADC_d_rm_mod_reg_u8_rm_reg_reg_u8:
		return handler_ADC_d_rm_mod_reg_u8_rm_reg_reg_u8(insb, cseip);
	case in_ADC_w_rm_mod_reg_u16_rm_reg_reg_u16:
		return handler_ADC_w_rm_mod_reg_u16_rm_reg_reg_u16(insb, cseip);
	case in_ADC_w_rm_mod_reg_u32_rm_reg_reg_u32:
		return handler_ADC_w_rm_mod_reg_u32_rm_reg_reg_u32(insb, cseip);
	case in_ADC_d_rm_mod_reg_u16_rm_reg_reg_u16:
		return handler_ADC_d_rm_mod_reg_u16_rm_reg_reg_u16(insb, cseip);
	case in_ADC_d_rm_mod_reg_u32_rm_reg_reg_u32:
		return handler_ADC_d_rm_mod_reg_u32_rm_reg_reg_u32(insb, cseip);
	case in_ADC_w_rm_reg_reg_u8_rm_mod_reg_u8:
		return handler_ADC_w_rm_reg_reg_u8_rm_mod_reg_u8(insb, cseip);
	case in_ADC_d_rm_reg_reg_u8_rm_mod_reg_u8:
		return handler_ADC_d_rm_reg_reg_u8_rm_mod_reg_u8(insb, cseip);
	case in_ADC_w_rm_reg_reg_u16_rm_mod_reg_u16:
		return handler_ADC_w_rm_reg_reg_u16_rm_mod_reg_u16(insb, cseip);
	case in_ADC_w_rm_reg_reg_u32_rm_mod_reg_u32:
		return handler_ADC_w_rm_reg_reg_u32_rm_mod_reg_u32(insb, cseip);
	case in_ADC_d_rm_reg_reg_u16_rm_mod_reg_u16:
		return handler_ADC_d_rm_reg_reg_u16_rm_mod_reg_u16(insb, cseip);
	case in_ADC_d_rm_reg_reg_u32_rm_mod_reg_u32:
		return handler_ADC_d_rm_reg_reg_u32_rm_mod_reg_u32(insb, cseip);
	case in_ADC_reg_gen_u8_imm_u8:
		return handler_ADC_reg_gen_u8_imm_u8(insb, cseip);
	case in_ADC_reg_gen_u16_imm_i16:
		return handler_ADC_reg_gen_u16_imm_i16(insb, cseip);
	case in_ADC_reg_gen_u32_imm_i32:
		return handler_ADC_reg_gen_u32_imm_i32(insb, cseip);
	case in_PUSH_reg_seg_2_u16:
		return handler_PUSH_reg_seg_2_u16(insb, cseip);
	case in_POP_reg_seg_2_u16:
		return handler_POP_reg_seg_2_u16(insb, cseip);
	case in_SBB_w_rm_mod_reg_u8_rm_reg_reg_u8:
		return handler_SBB_w_rm_mod_reg_u8_rm_reg_reg_u8(insb, cseip);
	case in_SBB_d_rm_mod_reg_u8_rm_reg_reg_u8:
		return handler_SBB_d_rm_mod_reg_u8_rm_reg_reg_u8(insb, cseip);
	case in_SBB_w_rm_mod_reg_u16_rm_reg_reg_u16:
		return handler_SBB_w_rm_mod_reg_u16_rm_reg_reg_u16(insb, cseip);
	case in_SBB_w_rm_mod_reg_u32_rm_reg_reg_u32:
		return handler_SBB_w_rm_mod_reg_u32_rm_reg_reg_u32(insb, cseip);
	case in_SBB_d_rm_mod_reg_u16_rm_reg_reg_u16:
		return handler_SBB_d_rm_mod_reg_u16_rm_reg_reg_u16(insb, cseip);
	case in_SBB_d_rm_mod_reg_u32_rm_reg_reg_u32:
		return handler_SBB_d_rm_mod_reg_u32_rm_reg_reg_u32(insb, cseip);
	case in_SBB_w_rm_reg_reg_u8_rm_mod_reg_u8:
		return handler_SBB_w_rm_reg_reg_u8_rm_mod_reg_u8(insb, cseip);
	case in_SBB_d_rm_reg_reg_u8_rm_mod_reg_u8:
		return handler_SBB_d_rm_reg_reg_u8_rm_mod_reg_u8(insb, cseip);
	case in_SBB_w_rm_reg_reg_u16_rm_mod_reg_u16:
		return handler_SBB_w_rm_reg_reg_u16_rm_mod_reg_u16(insb, cseip);
	case in_SBB_w_rm_reg_reg_u32_rm_mod_reg_u32:
		return handler_SBB_w_rm_reg_reg_u32_rm_mod_reg_u32(insb, cseip);
	case in_SBB_d_rm_reg_reg_u16_rm_mod_reg_u16:
		return handler_SBB_d_rm_reg_reg_u16_rm_mod_reg_u16(insb, cseip);
	case in_SBB_d_rm_reg_reg_u32_rm_mod_reg_u32:
		return handler_SBB_d_rm_reg_reg_u32_rm_mod_reg_u32(insb, cseip);
	case in_SBB_reg_gen_u8_imm_u8:
		return handler_SBB_reg_gen_u8_imm_u8(insb, cseip);
	case in_SBB_reg_gen_u16_imm_i16:
		return handler_SBB_reg_gen_u16_imm_i16(insb, cseip);
	case in_SBB_reg_gen_u32_imm_i32:
		return handler_SBB_reg_gen_u32_imm_i32(insb, cseip);
	case in_PUSH_reg_seg_3_u16:
		return handler_PUSH_reg_seg_3_u16(insb, cseip);
	case in_POP_reg_seg_3_u16:
		return handler_POP_reg_seg_3_u16(insb, cseip);
	case in_AND_w_rm_mod_reg_u8_rm_reg_reg_u8:
		return handler_AND_w_rm_mod_reg_u8_rm_reg_reg_u8(insb, cseip);
	case in_AND_d_rm_mod_reg_u8_rm_reg_reg_u8:
		return handler_AND_d_rm_mod_reg_u8_rm_reg_reg_u8(insb, cseip);
	case in_AND_w_rm_mod_reg_u16_rm_reg_reg_u16:
		return handler_AND_w_rm_mod_reg_u16_rm_reg_reg_u16(insb, cseip);
	case in_AND_w_rm_mod_reg_u32_rm_reg_reg_u32:
		return handler_AND_w_rm_mod_reg_u32_rm_reg_reg_u32(insb, cseip);
	case in_AND_d_rm_mod_reg_u16_rm_reg_reg_u16:
		return handler_AND_d_rm_mod_reg_u16_rm_reg_reg_u16(insb, cseip);
	case in_AND_d_rm_mod_reg_u32_rm_reg_reg_u32:
		return handler_AND_d_rm_mod_reg_u32_rm_reg_reg_u32(insb, cseip);
	case in_AND_w_rm_reg_reg_u8_rm_mod_reg_u8:
		return handler_AND_w_rm_reg_reg_u8_rm_mod_reg_u8(insb, cseip);
	case in_AND_d_rm_reg_reg_u8_rm_mod_reg_u8:
		return handler_AND_d_rm_reg_reg_u8_rm_mod_reg_u8(insb, cseip);
	case in_AND_w_rm_reg_reg_u16_rm_mod_reg_u16:
		return handler_AND_w_rm_reg_reg_u16_rm_mod_reg_u16(insb, cseip);
	case in_AND_w_rm_reg_reg_u32_rm_mod_reg_u32:
		return handler_AND_w_rm_reg_reg_u32_rm_mod_reg_u32(insb, cseip);
	case in_AND_d_rm_reg_reg_u16_rm_mod_reg_u16:
		return handler_AND_d_rm_reg_reg_u16_rm_mod_reg_u16(insb, cseip);
	case in_AND_d_rm_reg_reg_u32_rm_mod_reg_u32:
		return handler_AND_d_rm_reg_reg_u32_rm_mod_reg_u32(insb, cseip);
	case in_AND_reg_gen_u8_imm_u8:
		return handler_AND_reg_gen_u8_imm_u8(insb, cseip);
	case in_AND_reg_gen_u16_imm_i16:
		return handler_AND_reg_gen_u16_imm_i16(insb, cseip);
	case in_AND_reg_gen_u32_imm_i32:
		return handler_AND_reg_gen_u32_imm_i32(insb, cseip);
	case in_DAA:
		return handler_DAA(insb, cseip);
	case in_SUB_w_rm_mod_reg_u8_rm_reg_reg_u8:
		return handler_SUB_w_rm_mod_reg_u8_rm_reg_reg_u8(insb, cseip);
	case in_SUB_d_rm_mod_reg_u8_rm_reg_reg_u8:
		return handler_SUB_d_rm_mod_reg_u8_rm_reg_reg_u8(insb, cseip);
	case in_SUB_w_rm_mod_reg_u16_rm_reg_reg_u16:
		return handler_SUB_w_rm_mod_reg_u16_rm_reg_reg_u16(insb, cseip);
	case in_SUB_w_rm_mod_reg_u32_rm_reg_reg_u32:
		return handler_SUB_w_rm_mod_reg_u32_rm_reg_reg_u32(insb, cseip);
	case in_SUB_d_rm_mod_reg_u16_rm_reg_reg_u16:
		return handler_SUB_d_rm_mod_reg_u16_rm_reg_reg_u16(insb, cseip);
	case in_SUB_d_rm_mod_reg_u32_rm_reg_reg_u32:
		return handler_SUB_d_rm_mod_reg_u32_rm_reg_reg_u32(insb, cseip);
	case in_SUB_w_rm_reg_reg_u8_rm_mod_reg_u8:
		return handler_SUB_w_rm_reg_reg_u8_rm_mod_reg_u8(insb, cseip);
	case in_SUB_d_rm_reg_reg_u8_rm_mod_reg_u8:
		return handler_SUB_d_rm_reg_reg_u8_rm_mod_reg_u8(insb, cseip);
	case in_SUB_w_rm_reg_reg_u16_rm_mod_reg_u16:
		return handler_SUB_w_rm_reg_reg_u16_rm_mod_reg_u16(insb, cseip);
	case in_SUB_w_rm_reg_reg_u32_rm_mod_reg_u32:
		return handler_SUB_w_rm_reg_reg_u32_rm_mod_reg_u32(insb, cseip);
	case in_SUB_d_rm_reg_reg_u16_rm_mod_reg_u16:
		return handler_SUB_d_rm_reg_reg_u16_rm_mod_reg_u16(insb, cseip);
	case in_SUB_d_rm_reg_reg_u32_rm_mod_reg_u32:
		return handler_SUB_d_rm_reg_reg_u32_rm_mod_reg_u32(insb, cseip);
	case in_SUB_reg_gen_u8_imm_u8:
		return handler_SUB_reg_gen_u8_imm_u8(insb, cseip);
	case in_SUB_reg_gen_u16_imm_i16:
		return handler_SUB_reg_gen_u16_imm_i16(insb, cseip);
	case in_SUB_reg_gen_u32_imm_i32:
		return handler_SUB_reg_gen_u32_imm_i32(insb, cseip);
	case in_DAS:
		return handler_DAS(insb, cseip);
	case in_XOR_w_rm_mod_reg_u8_rm_reg_reg_u8:
		return handler_XOR_w_rm_mod_reg_u8_rm_reg_reg_u8(insb, cseip);
	case in_XOR_d_rm_mod_reg_u8_rm_reg_reg_u8:
		return handler_XOR_d_rm_mod_reg_u8_rm_reg_reg_u8(insb, cseip);
	case in_XOR_w_rm_mod_reg_u16_rm_reg_reg_u16:
		return handler_XOR_w_rm_mod_reg_u16_rm_reg_reg_u16(insb, cseip);
	case in_XOR_w_rm_mod_reg_u32_rm_reg_reg_u32:
		return handler_XOR_w_rm_mod_reg_u32_rm_reg_reg_u32(insb, cseip);
	case in_XOR_d_rm_mod_reg_u16_rm_reg_reg_u16:
		return handler_XOR_d_rm_mod_reg_u16_rm_reg_reg_u16(insb, cseip);
	case in_XOR_d_rm_mod_reg_u32_rm_reg_reg_u32:
		return handler_XOR_d_rm_mod_reg_u32_rm_reg_reg_u32(insb, cseip);
	case in_XOR_w_rm_reg_reg_u8_rm_mod_reg_u8:
		return handler_XOR_w_rm_reg_reg_u8_rm_mod_reg_u8(insb, cseip);
	case in_XOR_d_rm_reg_reg_u8_rm_mod_reg_u8:
		return handler_XOR_d_rm_reg_reg_u8_rm_mod_reg_u8(insb, cseip);
	case in_XOR_w_rm_reg_reg_u16_rm_mod_reg_u16:
		return handler_XOR_w_rm_reg_reg_u16_rm_mod_reg_u16(insb, cseip);
	case in_XOR_w_rm_reg_reg_u32_rm_mod_reg_u32:
		return handler_XOR_w_rm_reg_reg_u32_rm_mod_reg_u32(insb, cseip);
	case in_XOR_d_rm_reg_reg_u16_rm_mod_reg_u16:
		return handler_XOR_d_rm_reg_reg_u16_rm_mod_reg_u16(insb, cseip);
	case in_XOR_d_rm_reg_reg_u32_rm_mod_reg_u32:
		return handler_XOR_d_rm_reg_reg_u32_rm_mod_reg_u32(insb, cseip);
	case in_XOR_reg_gen_u8_imm_u8:
		return handler_XOR_reg_gen_u8_imm_u8(insb, cseip);
	case in_XOR_reg_gen_u16_imm_i16:
		return handler_XOR_reg_gen_u16_imm_i16(insb, cseip);
	case in_XOR_reg_gen_u32_imm_i32:
		return handler_XOR_reg_gen_u32_imm_i32(insb, cseip);
	case in_AAA:
		return handler_AAA(insb, cseip);
	case in_CMP_w_rm_reg_reg_u8:
		return handler_CMP_w_rm_reg_reg_u8(insb, cseip);
	case in_CMP_d_rm_reg_reg_u8:
		return handler_CMP_d_rm_reg_reg_u8(insb, cseip);
	case in_CMP_w_rm_reg_reg_u16:
		return handler_CMP_w_rm_reg_reg_u16(insb, cseip);
	case in_CMP_w_rm_reg_reg_u32:
		return handler_CMP_w_rm_reg_reg_u32(insb, cseip);
	case in_CMP_d_rm_reg_reg_u16:
		return handler_CMP_d_rm_reg_reg_u16(insb, cseip);
	case in_CMP_d_rm_reg_reg_u32:
		return handler_CMP_d_rm_reg_reg_u32(insb, cseip);
	case in_CMP_w_rm_mod_reg_u8:
		return handler_CMP_w_rm_mod_reg_u8(insb, cseip);
	case in_CMP_d_rm_mod_reg_u8:
		return handler_CMP_d_rm_mod_reg_u8(insb, cseip);
	case in_CMP_w_rm_mod_reg_u16:
		return handler_CMP_w_rm_mod_reg_u16(insb, cseip);
	case in_CMP_w_rm_mod_reg_u32:
		return handler_CMP_w_rm_mod_reg_u32(insb, cseip);
	case in_CMP_d_rm_mod_reg_u16:
		return handler_CMP_d_rm_mod_reg_u16(insb, cseip);
	case in_CMP_d_rm_mod_reg_u32:
		return handler_CMP_d_rm_mod_reg_u32(insb, cseip);
	case in_CMP_imm_u8:
		return handler_CMP_imm_u8(insb, cseip);
	case in_CMP_imm_i16:
		return handler_CMP_imm_i16(insb, cseip);
	case in_CMP_imm_i32:
		return handler_CMP_imm_i32(insb, cseip);
	case in_AAS:
		return handler_AAS(insb, cseip);
	case in_INC_reg_reg_u16:
		return handler_INC_reg_reg_u16(insb, cseip);
	case in_DEC_reg_reg_u16:
		return handler_DEC_reg_reg_u16(insb, cseip);
	case in_PUSH_reg_reg_u16:
		return handler_PUSH_reg_reg_u16(insb, cseip);
	case in_POP_reg_reg_u16:
		return handler_POP_reg_reg_u16(insb, cseip);
	case in_PUSHA:
		return handler_PUSHA(insb, cseip);
	case in_POPA:
		return handler_POPA(insb, cseip);
	case in_BOUND_w_rm_mem_u16:
		return handler_BOUND_w_rm_mem_u16(insb, cseip);
	case in_BOUND_d_rm_mem_u16:
		return handler_BOUND_d_rm_mem_u16(insb, cseip);
	case in_ARPL_w_rm_reg_reg_u16:
		return handler_ARPL_w_rm_reg_reg_u16(insb, cseip);
	case in_ARPL_d_rm_reg_reg_u16:
		return handler_ARPL_d_rm_reg_reg_u16(insb, cseip);
	case in_PUSH_imm_i16:
		return handler_PUSH_imm_i16(insb, cseip);
	case in_IMUL_w_rm_reg_reg_u16_imm_i16:
		return handler_IMUL_w_rm_reg_reg_u16_imm_i16(insb, cseip);
	case in_IMUL_d_rm_reg_reg_u16_imm_i16:
		return handler_IMUL_d_rm_reg_reg_u16_imm_i16(insb, cseip);
	case in_PUSH_imm_i8:
		return handler_PUSH_imm_i8(insb, cseip);
	case in_IMUL_w_rm_reg_reg_u16_imm_u8:
		return handler_IMUL_w_rm_reg_reg_u16_imm_u8(insb, cseip);
	case in_IMUL_d_rm_reg_reg_u16_imm_u8:
		return handler_IMUL_d_rm_reg_reg_u16_imm_u8(insb, cseip);
	case in_INS_w_mem_reg_7_u8_reg_gen_2_u16:
		return handler_INS_w_mem_reg_7_u8_reg_gen_2_u16(insb, cseip);
	case in_INS_d_mem_reg_7_u8_reg_gen_2_u16:
		return handler_INS_d_mem_reg_7_u8_reg_gen_2_u16(insb, cseip);
	case in_INS_w_mem_reg_7_u16_reg_gen_2_u16:
		return handler_INS_w_mem_reg_7_u16_reg_gen_2_u16(insb, cseip);
	case in_INS_d_mem_reg_7_u16_reg_gen_2_u16:
		return handler_INS_d_mem_reg_7_u16_reg_gen_2_u16(insb, cseip);
	case in_INS_w_mem_reg_7_u32_reg_gen_2_u16:
		return handler_INS_w_mem_reg_7_u32_reg_gen_2_u16(insb, cseip);
	case in_INS_d_mem_reg_7_u32_reg_gen_2_u16:
		return handler_INS_d_mem_reg_7_u32_reg_gen_2_u16(insb, cseip);
	case in_OUTS_w_reg_gen_2_u16_mem_reg_6_u8:
		return handler_OUTS_w_reg_gen_2_u16_mem_reg_6_u8(insb, cseip);
	case in_OUTS_d_reg_gen_2_u16_mem_reg_6_u8:
		return handler_OUTS_d_reg_gen_2_u16_mem_reg_6_u8(insb, cseip);
	case in_OUTS_w_reg_gen_2_u16_mem_reg_6_u16:
		return handler_OUTS_w_reg_gen_2_u16_mem_reg_6_u16(insb, cseip);
	case in_OUTS_d_reg_gen_2_u16_mem_reg_6_u16:
		return handler_OUTS_d_reg_gen_2_u16_mem_reg_6_u16(insb, cseip);
	case in_OUTS_w_reg_gen_2_u16_mem_reg_6_u32:
		return handler_OUTS_w_reg_gen_2_u16_mem_reg_6_u32(insb, cseip);
	case in_OUTS_d_reg_gen_2_u16_mem_reg_6_u32:
		return handler_OUTS_d_reg_gen_2_u16_mem_reg_6_u32(insb, cseip);
	case in_JO_w_mem_imm_J_u8:
		return handler_JO_w_mem_imm_J_u8(insb, cseip);
	case in_JO_d_mem_imm_J_u8:
		return handler_JO_d_mem_imm_J_u8(insb, cseip);
	case in_JNO_w_mem_imm_J_u8:
		return handler_JNO_w_mem_imm_J_u8(insb, cseip);
	case in_JNO_d_mem_imm_J_u8:
		return handler_JNO_d_mem_imm_J_u8(insb, cseip);
	case in_JB_w_mem_imm_J_u8:
		return handler_JB_w_mem_imm_J_u8(insb, cseip);
	case in_JB_d_mem_imm_J_u8:
		return handler_JB_d_mem_imm_J_u8(insb, cseip);
	case in_JNB_w_mem_imm_J_u8:
		return handler_JNB_w_mem_imm_J_u8(insb, cseip);
	case in_JNB_d_mem_imm_J_u8:
		return handler_JNB_d_mem_imm_J_u8(insb, cseip);
	case in_JZ_w_mem_imm_J_u8:
		return handler_JZ_w_mem_imm_J_u8(insb, cseip);
	case in_JZ_d_mem_imm_J_u8:
		return handler_JZ_d_mem_imm_J_u8(insb, cseip);
	case in_JNZ_w_mem_imm_J_u8:
		return handler_JNZ_w_mem_imm_J_u8(insb, cseip);
	case in_JNZ_d_mem_imm_J_u8:
		return handler_JNZ_d_mem_imm_J_u8(insb, cseip);
	case in_JBE_w_mem_imm_J_u8:
		return handler_JBE_w_mem_imm_J_u8(insb, cseip);
	case in_JBE_d_mem_imm_J_u8:
		return handler_JBE_d_mem_imm_J_u8(insb, cseip);
	case in_JNBE_w_mem_imm_J_u8:
		return handler_JNBE_w_mem_imm_J_u8(insb, cseip);
	case in_JNBE_d_mem_imm_J_u8:
		return handler_JNBE_d_mem_imm_J_u8(insb, cseip);
	case in_JS_w_mem_imm_J_u8:
		return handler_JS_w_mem_imm_J_u8(insb, cseip);
	case in_JS_d_mem_imm_J_u8:
		return handler_JS_d_mem_imm_J_u8(insb, cseip);
	case in_JNS_w_mem_imm_J_u8:
		return handler_JNS_w_mem_imm_J_u8(insb, cseip);
	case in_JNS_d_mem_imm_J_u8:
		return handler_JNS_d_mem_imm_J_u8(insb, cseip);
	case in_JP_w_mem_imm_J_u8:
		return handler_JP_w_mem_imm_J_u8(insb, cseip);
	case in_JP_d_mem_imm_J_u8:
		return handler_JP_d_mem_imm_J_u8(insb, cseip);
	case in_JNP_w_mem_imm_J_u8:
		return handler_JNP_w_mem_imm_J_u8(insb, cseip);
	case in_JNP_d_mem_imm_J_u8:
		return handler_JNP_d_mem_imm_J_u8(insb, cseip);
	case in_JL_w_mem_imm_J_u8:
		return handler_JL_w_mem_imm_J_u8(insb, cseip);
	case in_JL_d_mem_imm_J_u8:
		return handler_JL_d_mem_imm_J_u8(insb, cseip);
	case in_JNL_w_mem_imm_J_u8:
		return handler_JNL_w_mem_imm_J_u8(insb, cseip);
	case in_JNL_d_mem_imm_J_u8:
		return handler_JNL_d_mem_imm_J_u8(insb, cseip);
	case in_JLE_w_mem_imm_J_u8:
		return handler_JLE_w_mem_imm_J_u8(insb, cseip);
	case in_JLE_d_mem_imm_J_u8:
		return handler_JLE_d_mem_imm_J_u8(insb, cseip);
	case in_JNLE_w_mem_imm_J_u8:
		return handler_JNLE_w_mem_imm_J_u8(insb, cseip);
	case in_JNLE_d_mem_imm_J_u8:
		return handler_JNLE_d_mem_imm_J_u8(insb, cseip);
	case in_ADD_w_rm_mod_reg_u8_imm_u8:
		return handler_ADD_w_rm_mod_reg_u8_imm_u8(insb, cseip);
	case in_ADD_d_rm_mod_reg_u8_imm_u8:
		return handler_ADD_d_rm_mod_reg_u8_imm_u8(insb, cseip);
	case in_OR_w_rm_mod_reg_u8_imm_u8:
		return handler_OR_w_rm_mod_reg_u8_imm_u8(insb, cseip);
	case in_OR_d_rm_mod_reg_u8_imm_u8:
		return handler_OR_d_rm_mod_reg_u8_imm_u8(insb, cseip);
	case in_ADC_w_rm_mod_reg_u8_imm_u8:
		return handler_ADC_w_rm_mod_reg_u8_imm_u8(insb, cseip);
	case in_ADC_d_rm_mod_reg_u8_imm_u8:
		return handler_ADC_d_rm_mod_reg_u8_imm_u8(insb, cseip);
	case in_SBB_w_rm_mod_reg_u8_imm_u8:
		return handler_SBB_w_rm_mod_reg_u8_imm_u8(insb, cseip);
	case in_SBB_d_rm_mod_reg_u8_imm_u8:
		return handler_SBB_d_rm_mod_reg_u8_imm_u8(insb, cseip);
	case in_AND_w_rm_mod_reg_u8_imm_u8:
		return handler_AND_w_rm_mod_reg_u8_imm_u8(insb, cseip);
	case in_AND_d_rm_mod_reg_u8_imm_u8:
		return handler_AND_d_rm_mod_reg_u8_imm_u8(insb, cseip);
	case in_SUB_w_rm_mod_reg_u8_imm_u8:
		return handler_SUB_w_rm_mod_reg_u8_imm_u8(insb, cseip);
	case in_SUB_d_rm_mod_reg_u8_imm_u8:
		return handler_SUB_d_rm_mod_reg_u8_imm_u8(insb, cseip);
	case in_XOR_w_rm_mod_reg_u8_imm_u8:
		return handler_XOR_w_rm_mod_reg_u8_imm_u8(insb, cseip);
	case in_XOR_d_rm_mod_reg_u8_imm_u8:
		return handler_XOR_d_rm_mod_reg_u8_imm_u8(insb, cseip);
	case in_CMP_w_imm_u8:
		return handler_CMP_w_imm_u8(insb, cseip);
	case in_CMP_d_imm_u8:
		return handler_CMP_d_imm_u8(insb, cseip);
	case in_ADD_w_rm_mod_reg_u16_imm_i16:
		return handler_ADD_w_rm_mod_reg_u16_imm_i16(insb, cseip);
	case in_ADD_w_rm_mod_reg_u32_imm_i32:
		return handler_ADD_w_rm_mod_reg_u32_imm_i32(insb, cseip);
	case in_ADD_d_rm_mod_reg_u16_imm_i16:
		return handler_ADD_d_rm_mod_reg_u16_imm_i16(insb, cseip);
	case in_ADD_d_rm_mod_reg_u32_imm_i32:
		return handler_ADD_d_rm_mod_reg_u32_imm_i32(insb, cseip);
	case in_OR_w_rm_mod_reg_u16_imm_i16:
		return handler_OR_w_rm_mod_reg_u16_imm_i16(insb, cseip);
	case in_OR_w_rm_mod_reg_u32_imm_i32:
		return handler_OR_w_rm_mod_reg_u32_imm_i32(insb, cseip);
	case in_OR_d_rm_mod_reg_u16_imm_i16:
		return handler_OR_d_rm_mod_reg_u16_imm_i16(insb, cseip);
	case in_OR_d_rm_mod_reg_u32_imm_i32:
		return handler_OR_d_rm_mod_reg_u32_imm_i32(insb, cseip);
	case in_ADC_w_rm_mod_reg_u16_imm_i16:
		return handler_ADC_w_rm_mod_reg_u16_imm_i16(insb, cseip);
	case in_ADC_w_rm_mod_reg_u32_imm_i32:
		return handler_ADC_w_rm_mod_reg_u32_imm_i32(insb, cseip);
	case in_ADC_d_rm_mod_reg_u16_imm_i16:
		return handler_ADC_d_rm_mod_reg_u16_imm_i16(insb, cseip);
	case in_ADC_d_rm_mod_reg_u32_imm_i32:
		return handler_ADC_d_rm_mod_reg_u32_imm_i32(insb, cseip);
	case in_SBB_w_rm_mod_reg_u16_imm_i16:
		return handler_SBB_w_rm_mod_reg_u16_imm_i16(insb, cseip);
	case in_SBB_w_rm_mod_reg_u32_imm_i32:
		return handler_SBB_w_rm_mod_reg_u32_imm_i32(insb, cseip);
	case in_SBB_d_rm_mod_reg_u16_imm_i16:
		return handler_SBB_d_rm_mod_reg_u16_imm_i16(insb, cseip);
	case in_SBB_d_rm_mod_reg_u32_imm_i32:
		return handler_SBB_d_rm_mod_reg_u32_imm_i32(insb, cseip);
	case in_AND_w_rm_mod_reg_u16_imm_i16:
		return handler_AND_w_rm_mod_reg_u16_imm_i16(insb, cseip);
	case in_AND_w_rm_mod_reg_u32_imm_i32:
		return handler_AND_w_rm_mod_reg_u32_imm_i32(insb, cseip);
	case in_AND_d_rm_mod_reg_u16_imm_i16:
		return handler_AND_d_rm_mod_reg_u16_imm_i16(insb, cseip);
	case in_AND_d_rm_mod_reg_u32_imm_i32:
		return handler_AND_d_rm_mod_reg_u32_imm_i32(insb, cseip);
	case in_SUB_w_rm_mod_reg_u16_imm_i16:
		return handler_SUB_w_rm_mod_reg_u16_imm_i16(insb, cseip);
	case in_SUB_w_rm_mod_reg_u32_imm_i32:
		return handler_SUB_w_rm_mod_reg_u32_imm_i32(insb, cseip);
	case in_SUB_d_rm_mod_reg_u16_imm_i16:
		return handler_SUB_d_rm_mod_reg_u16_imm_i16(insb, cseip);
	case in_SUB_d_rm_mod_reg_u32_imm_i32:
		return handler_SUB_d_rm_mod_reg_u32_imm_i32(insb, cseip);
	case in_XOR_w_rm_mod_reg_u16_imm_i16:
		return handler_XOR_w_rm_mod_reg_u16_imm_i16(insb, cseip);
	case in_XOR_w_rm_mod_reg_u32_imm_i32:
		return handler_XOR_w_rm_mod_reg_u32_imm_i32(insb, cseip);
	case in_XOR_d_rm_mod_reg_u16_imm_i16:
		return handler_XOR_d_rm_mod_reg_u16_imm_i16(insb, cseip);
	case in_XOR_d_rm_mod_reg_u32_imm_i32:
		return handler_XOR_d_rm_mod_reg_u32_imm_i32(insb, cseip);
	case in_CMP_w_imm_i16:
		return handler_CMP_w_imm_i16(insb, cseip);
	case in_CMP_w_imm_i32:
		return handler_CMP_w_imm_i32(insb, cseip);
	case in_CMP_d_imm_i16:
		return handler_CMP_d_imm_i16(insb, cseip);
	case in_CMP_d_imm_i32:
		return handler_CMP_d_imm_i32(insb, cseip);
	case in_ADD_w_rm_mod_reg_u16_imm_u8:
		return handler_ADD_w_rm_mod_reg_u16_imm_u8(insb, cseip);
	case in_ADD_w_rm_mod_reg_u32_imm_u8:
		return handler_ADD_w_rm_mod_reg_u32_imm_u8(insb, cseip);
	case in_ADD_d_rm_mod_reg_u16_imm_u8:
		return handler_ADD_d_rm_mod_reg_u16_imm_u8(insb, cseip);
	case in_ADD_d_rm_mod_reg_u32_imm_u8:
		return handler_ADD_d_rm_mod_reg_u32_imm_u8(insb, cseip);
	case in_OR_w_rm_mod_reg_u16_imm_u8:
		return handler_OR_w_rm_mod_reg_u16_imm_u8(insb, cseip);
	case in_OR_w_rm_mod_reg_u32_imm_u8:
		return handler_OR_w_rm_mod_reg_u32_imm_u8(insb, cseip);
	case in_OR_d_rm_mod_reg_u16_imm_u8:
		return handler_OR_d_rm_mod_reg_u16_imm_u8(insb, cseip);
	case in_OR_d_rm_mod_reg_u32_imm_u8:
		return handler_OR_d_rm_mod_reg_u32_imm_u8(insb, cseip);
	case in_ADC_w_rm_mod_reg_u16_imm_u8:
		return handler_ADC_w_rm_mod_reg_u16_imm_u8(insb, cseip);
	case in_ADC_w_rm_mod_reg_u32_imm_u8:
		return handler_ADC_w_rm_mod_reg_u32_imm_u8(insb, cseip);
	case in_ADC_d_rm_mod_reg_u16_imm_u8:
		return handler_ADC_d_rm_mod_reg_u16_imm_u8(insb, cseip);
	case in_ADC_d_rm_mod_reg_u32_imm_u8:
		return handler_ADC_d_rm_mod_reg_u32_imm_u8(insb, cseip);
	case in_SBB_w_rm_mod_reg_u16_imm_u8:
		return handler_SBB_w_rm_mod_reg_u16_imm_u8(insb, cseip);
	case in_SBB_w_rm_mod_reg_u32_imm_u8:
		return handler_SBB_w_rm_mod_reg_u32_imm_u8(insb, cseip);
	case in_SBB_d_rm_mod_reg_u16_imm_u8:
		return handler_SBB_d_rm_mod_reg_u16_imm_u8(insb, cseip);
	case in_SBB_d_rm_mod_reg_u32_imm_u8:
		return handler_SBB_d_rm_mod_reg_u32_imm_u8(insb, cseip);
	case in_AND_w_rm_mod_reg_u16_imm_u8:
		return handler_AND_w_rm_mod_reg_u16_imm_u8(insb, cseip);
	case in_AND_w_rm_mod_reg_u32_imm_u8:
		return handler_AND_w_rm_mod_reg_u32_imm_u8(insb, cseip);
	case in_AND_d_rm_mod_reg_u16_imm_u8:
		return handler_AND_d_rm_mod_reg_u16_imm_u8(insb, cseip);
	case in_AND_d_rm_mod_reg_u32_imm_u8:
		return handler_AND_d_rm_mod_reg_u32_imm_u8(insb, cseip);
	case in_SUB_w_rm_mod_reg_u16_imm_u8:
		return handler_SUB_w_rm_mod_reg_u16_imm_u8(insb, cseip);
	case in_SUB_w_rm_mod_reg_u32_imm_u8:
		return handler_SUB_w_rm_mod_reg_u32_imm_u8(insb, cseip);
	case in_SUB_d_rm_mod_reg_u16_imm_u8:
		return handler_SUB_d_rm_mod_reg_u16_imm_u8(insb, cseip);
	case in_SUB_d_rm_mod_reg_u32_imm_u8:
		return handler_SUB_d_rm_mod_reg_u32_imm_u8(insb, cseip);
	case in_XOR_w_rm_mod_reg_u16_imm_u8:
		return handler_XOR_w_rm_mod_reg_u16_imm_u8(insb, cseip);
	case in_XOR_w_rm_mod_reg_u32_imm_u8:
		return handler_XOR_w_rm_mod_reg_u32_imm_u8(insb, cseip);
	case in_XOR_d_rm_mod_reg_u16_imm_u8:
		return handler_XOR_d_rm_mod_reg_u16_imm_u8(insb, cseip);
	case in_XOR_d_rm_mod_reg_u32_imm_u8:
		return handler_XOR_d_rm_mod_reg_u32_imm_u8(insb, cseip);
	case in_TEST_w_rm_reg_reg_u8:
		return handler_TEST_w_rm_reg_reg_u8(insb, cseip);
	case in_TEST_d_rm_reg_reg_u8:
		return handler_TEST_d_rm_reg_reg_u8(insb, cseip);
	case in_TEST_w_rm_reg_reg_u16:
		return handler_TEST_w_rm_reg_reg_u16(insb, cseip);
	case in_TEST_w_rm_reg_reg_u32:
		return handler_TEST_w_rm_reg_reg_u32(insb, cseip);
	case in_TEST_d_rm_reg_reg_u16:
		return handler_TEST_d_rm_reg_reg_u16(insb, cseip);
	case in_TEST_d_rm_reg_reg_u32:
		return handler_TEST_d_rm_reg_reg_u32(insb, cseip);
	case in_XCHG_w_rm_mod_reg_u8:
		return handler_XCHG_w_rm_mod_reg_u8(insb, cseip);
	case in_XCHG_d_rm_mod_reg_u8:
		return handler_XCHG_d_rm_mod_reg_u8(insb, cseip);
	case in_XCHG_w_rm_mod_reg_u16:
		return handler_XCHG_w_rm_mod_reg_u16(insb, cseip);
	case in_XCHG_w_rm_mod_reg_u32:
		return handler_XCHG_w_rm_mod_reg_u32(insb, cseip);
	case in_XCHG_d_rm_mod_reg_u16:
		return handler_XCHG_d_rm_mod_reg_u16(insb, cseip);
	case in_XCHG_d_rm_mod_reg_u32:
		return handler_XCHG_d_rm_mod_reg_u32(insb, cseip);
	case in_MOV_w_rm_mod_reg_u8_rm_reg_reg_u8:
		return handler_MOV_w_rm_mod_reg_u8_rm_reg_reg_u8(insb, cseip);
	case in_MOV_d_rm_mod_reg_u8_rm_reg_reg_u8:
		return handler_MOV_d_rm_mod_reg_u8_rm_reg_reg_u8(insb, cseip);
	case in_MOV_w_rm_mod_reg_u16_rm_reg_reg_u16:
		return handler_MOV_w_rm_mod_reg_u16_rm_reg_reg_u16(insb, cseip);
	case in_MOV_w_rm_mod_reg_u32_rm_reg_reg_u32:
		return handler_MOV_w_rm_mod_reg_u32_rm_reg_reg_u32(insb, cseip);
	case in_MOV_d_rm_mod_reg_u16_rm_reg_reg_u16:
		return handler_MOV_d_rm_mod_reg_u16_rm_reg_reg_u16(insb, cseip);
	case in_MOV_d_rm_mod_reg_u32_rm_reg_reg_u32:
		return handler_MOV_d_rm_mod_reg_u32_rm_reg_reg_u32(insb, cseip);
	case in_MOV_w_rm_reg_reg_u8_rm_mod_reg_u8:
		return handler_MOV_w_rm_reg_reg_u8_rm_mod_reg_u8(insb, cseip);
	case in_MOV_d_rm_reg_reg_u8_rm_mod_reg_u8:
		return handler_MOV_d_rm_reg_reg_u8_rm_mod_reg_u8(insb, cseip);
	case in_MOV_w_rm_reg_reg_u16_rm_mod_reg_u16:
		return handler_MOV_w_rm_reg_reg_u16_rm_mod_reg_u16(insb, cseip);
	case in_MOV_d_rm_reg_reg_u16_rm_mod_reg_u16:
		return handler_MOV_d_rm_reg_reg_u16_rm_mod_reg_u16(insb, cseip);
	case in_MOV_w_rm_mem_u16_rm_reg_seg_u16:
		return handler_MOV_w_rm_mem_u16_rm_reg_seg_u16(insb, cseip);
	case in_MOV_d_rm_mem_u16_rm_reg_seg_u16:
		return handler_MOV_d_rm_mem_u16_rm_reg_seg_u16(insb, cseip);
	case in_LEA_rm_reg_reg_u16:
		return handler_LEA_rm_reg_reg_u16(insb, cseip);
	case in_MOV_w_rm_reg_seg_u16_rm_mod_reg_u16:
		return handler_MOV_w_rm_reg_seg_u16_rm_mod_reg_u16(insb, cseip);
	case in_MOV_d_rm_reg_seg_u16_rm_mod_reg_u16:
		return handler_MOV_d_rm_reg_seg_u16_rm_mod_reg_u16(insb, cseip);
	case in_POP_w_rm_mod_reg_u16:
		return handler_POP_w_rm_mod_reg_u16(insb, cseip);
	case in_POP_w_rm_mod_reg_u32:
		return handler_POP_w_rm_mod_reg_u32(insb, cseip);
	case in_POP_d_rm_mod_reg_u16:
		return handler_POP_d_rm_mod_reg_u16(insb, cseip);
	case in_POP_d_rm_mod_reg_u32:
		return handler_POP_d_rm_mod_reg_u32(insb, cseip);
	case in_XCHG_reg_gen_u16:
		return handler_XCHG_reg_gen_u16(insb, cseip);
	case in_PAUSE:
		return handler_PAUSE(insb, cseip);
	case in_CBW:
		return handler_CBW(insb, cseip);
	case in_CWDE:
		return handler_CWDE(insb, cseip);
	case in_CWD:
		return handler_CWD(insb, cseip);
	case in_CDQ:
		return handler_CDQ(insb, cseip);
	case in_CALLF_w_mem_imm_p32:
		return handler_CALLF_w_mem_imm_p32(insb, cseip);
	case in_CALLF_d_mem_imm_p32:
		return handler_CALLF_d_mem_imm_p32(insb, cseip);
	case in_FWAIT:
		return handler_FWAIT(insb, cseip);
	case in_PUSHF:
		return handler_PUSHF(insb, cseip);
	case in_POPF:
		return handler_POPF(insb, cseip);
	case in_MOV_w_reg_gen_u8_mem_imm_O_u8:
		return handler_MOV_w_reg_gen_u8_mem_imm_O_u8(insb, cseip);
	case in_MOV_d_reg_gen_u8_mem_imm_O_u8:
		return handler_MOV_d_reg_gen_u8_mem_imm_O_u8(insb, cseip);
	case in_MOV_w_reg_gen_u16_mem_imm_O_u16:
		return handler_MOV_w_reg_gen_u16_mem_imm_O_u16(insb, cseip);
	case in_MOV_w_reg_gen_u32_mem_imm_O_u32:
		return handler_MOV_w_reg_gen_u32_mem_imm_O_u32(insb, cseip);
	case in_MOV_d_reg_gen_u16_mem_imm_O_u16:
		return handler_MOV_d_reg_gen_u16_mem_imm_O_u16(insb, cseip);
	case in_MOV_d_reg_gen_u32_mem_imm_O_u32:
		return handler_MOV_d_reg_gen_u32_mem_imm_O_u32(insb, cseip);
	case in_MOV_w_mem_imm_O_u8_reg_gen_u8:
		return handler_MOV_w_mem_imm_O_u8_reg_gen_u8(insb, cseip);
	case in_MOV_d_mem_imm_O_u8_reg_gen_u8:
		return handler_MOV_d_mem_imm_O_u8_reg_gen_u8(insb, cseip);
	case in_MOV_w_mem_imm_O_u16_reg_gen_u16:
		return handler_MOV_w_mem_imm_O_u16_reg_gen_u16(insb, cseip);
	case in_MOV_w_mem_imm_O_u32_reg_gen_u32:
		return handler_MOV_w_mem_imm_O_u32_reg_gen_u32(insb, cseip);
	case in_MOV_d_mem_imm_O_u16_reg_gen_u16:
		return handler_MOV_d_mem_imm_O_u16_reg_gen_u16(insb, cseip);
	case in_MOV_d_mem_imm_O_u32_reg_gen_u32:
		return handler_MOV_d_mem_imm_O_u32_reg_gen_u32(insb, cseip);
	case in_MOVS_w_mem_reg_7_u8_mem_reg_6_u8:
		return handler_MOVS_w_mem_reg_7_u8_mem_reg_6_u8(insb, cseip);
	case in_MOVS_d_mem_reg_7_u8_mem_reg_6_u8:
		return handler_MOVS_d_mem_reg_7_u8_mem_reg_6_u8(insb, cseip);
	case in_MOVS_w_mem_reg_7_u16_mem_reg_6_u16:
		return handler_MOVS_w_mem_reg_7_u16_mem_reg_6_u16(insb, cseip);
	case in_MOVS_d_mem_reg_7_u16_mem_reg_6_u16:
		return handler_MOVS_d_mem_reg_7_u16_mem_reg_6_u16(insb, cseip);
	case in_MOVS_w_mem_reg_7_u32_mem_reg_6_u32:
		return handler_MOVS_w_mem_reg_7_u32_mem_reg_6_u32(insb, cseip);
	case in_MOVS_d_mem_reg_7_u32_mem_reg_6_u32:
		return handler_MOVS_d_mem_reg_7_u32_mem_reg_6_u32(insb, cseip);
	case in_CMPS_w_mem_reg_6_u8:
		return handler_CMPS_w_mem_reg_6_u8(insb, cseip);
	case in_CMPS_d_mem_reg_6_u8:
		return handler_CMPS_d_mem_reg_6_u8(insb, cseip);
	case in_CMPS_w_mem_reg_6_u16:
		return handler_CMPS_w_mem_reg_6_u16(insb, cseip);
	case in_CMPS_d_mem_reg_6_u16:
		return handler_CMPS_d_mem_reg_6_u16(insb, cseip);
	case in_CMPS_w_mem_reg_6_u32:
		return handler_CMPS_w_mem_reg_6_u32(insb, cseip);
	case in_CMPS_d_mem_reg_6_u32:
		return handler_CMPS_d_mem_reg_6_u32(insb, cseip);
	case in_TEST_imm_u8:
		return handler_TEST_imm_u8(insb, cseip);
	case in_TEST_imm_i16:
		return handler_TEST_imm_i16(insb, cseip);
	case in_TEST_imm_i32:
		return handler_TEST_imm_i32(insb, cseip);
	case in_STOS_w_mem_reg_7_u8:
		return handler_STOS_w_mem_reg_7_u8(insb, cseip);
	case in_STOS_d_mem_reg_7_u8:
		return handler_STOS_d_mem_reg_7_u8(insb, cseip);
	case in_STOS_w_mem_reg_7_u16:
		return handler_STOS_w_mem_reg_7_u16(insb, cseip);
	case in_STOS_d_mem_reg_7_u16:
		return handler_STOS_d_mem_reg_7_u16(insb, cseip);
	case in_STOS_w_mem_reg_7_u32:
		return handler_STOS_w_mem_reg_7_u32(insb, cseip);
	case in_STOS_d_mem_reg_7_u32:
		return handler_STOS_d_mem_reg_7_u32(insb, cseip);
	case in_LODS_w_mem_reg_6_u8:
		return handler_LODS_w_mem_reg_6_u8(insb, cseip);
	case in_LODS_d_mem_reg_6_u8:
		return handler_LODS_d_mem_reg_6_u8(insb, cseip);
	case in_LODS_w_mem_reg_6_u16:
		return handler_LODS_w_mem_reg_6_u16(insb, cseip);
	case in_LODS_d_mem_reg_6_u16:
		return handler_LODS_d_mem_reg_6_u16(insb, cseip);
	case in_LODS_w_mem_reg_6_u32:
		return handler_LODS_w_mem_reg_6_u32(insb, cseip);
	case in_LODS_d_mem_reg_6_u32:
		return handler_LODS_d_mem_reg_6_u32(insb, cseip);
	case in_SCAS_w_mem_reg_7_u8:
		return handler_SCAS_w_mem_reg_7_u8(insb, cseip);
	case in_SCAS_d_mem_reg_7_u8:
		return handler_SCAS_d_mem_reg_7_u8(insb, cseip);
	case in_SCAS_w_mem_reg_7_u16:
		return handler_SCAS_w_mem_reg_7_u16(insb, cseip);
	case in_SCAS_d_mem_reg_7_u16:
		return handler_SCAS_d_mem_reg_7_u16(insb, cseip);
	case in_SCAS_w_mem_reg_7_u32:
		return handler_SCAS_w_mem_reg_7_u32(insb, cseip);
	case in_SCAS_d_mem_reg_7_u32:
		return handler_SCAS_d_mem_reg_7_u32(insb, cseip);
	case in_MOV_reg_reg_u8_imm_u8:
		return handler_MOV_reg_reg_u8_imm_u8(insb, cseip);
	case in_MOV_reg_reg_u16_imm_u16:
		return handler_MOV_reg_reg_u16_imm_u16(insb, cseip);
	case in_ROL_w_rm_mod_reg_u8_imm_u8:
		return handler_ROL_w_rm_mod_reg_u8_imm_u8(insb, cseip);
	case in_ROL_d_rm_mod_reg_u8_imm_u8:
		return handler_ROL_d_rm_mod_reg_u8_imm_u8(insb, cseip);
	case in_ROR_w_rm_mod_reg_u8_imm_u8:
		return handler_ROR_w_rm_mod_reg_u8_imm_u8(insb, cseip);
	case in_ROR_d_rm_mod_reg_u8_imm_u8:
		return handler_ROR_d_rm_mod_reg_u8_imm_u8(insb, cseip);
	case in_RCL_w_rm_mod_reg_u8_imm_u8:
		return handler_RCL_w_rm_mod_reg_u8_imm_u8(insb, cseip);
	case in_RCL_d_rm_mod_reg_u8_imm_u8:
		return handler_RCL_d_rm_mod_reg_u8_imm_u8(insb, cseip);
	case in_RCR_w_rm_mod_reg_u8_imm_u8:
		return handler_RCR_w_rm_mod_reg_u8_imm_u8(insb, cseip);
	case in_RCR_d_rm_mod_reg_u8_imm_u8:
		return handler_RCR_d_rm_mod_reg_u8_imm_u8(insb, cseip);
	case in_SHL_w_rm_mod_reg_u8_imm_u8:
		return handler_SHL_w_rm_mod_reg_u8_imm_u8(insb, cseip);
	case in_SHL_d_rm_mod_reg_u8_imm_u8:
		return handler_SHL_d_rm_mod_reg_u8_imm_u8(insb, cseip);
	case in_SHR_w_rm_mod_reg_u8_imm_u8:
		return handler_SHR_w_rm_mod_reg_u8_imm_u8(insb, cseip);
	case in_SHR_d_rm_mod_reg_u8_imm_u8:
		return handler_SHR_d_rm_mod_reg_u8_imm_u8(insb, cseip);
	case in_SAR_w_rm_mod_reg_u8_imm_u8:
		return handler_SAR_w_rm_mod_reg_u8_imm_u8(insb, cseip);
	case in_SAR_d_rm_mod_reg_u8_imm_u8:
		return handler_SAR_d_rm_mod_reg_u8_imm_u8(insb, cseip);
	case in_ROL_w_rm_mod_reg_u16_imm_u8:
		return handler_ROL_w_rm_mod_reg_u16_imm_u8(insb, cseip);
	case in_ROL_w_rm_mod_reg_u32_imm_u8:
		return handler_ROL_w_rm_mod_reg_u32_imm_u8(insb, cseip);
	case in_ROL_d_rm_mod_reg_u16_imm_u8:
		return handler_ROL_d_rm_mod_reg_u16_imm_u8(insb, cseip);
	case in_ROL_d_rm_mod_reg_u32_imm_u8:
		return handler_ROL_d_rm_mod_reg_u32_imm_u8(insb, cseip);
	case in_ROR_w_rm_mod_reg_u16_imm_u8:
		return handler_ROR_w_rm_mod_reg_u16_imm_u8(insb, cseip);
	case in_ROR_w_rm_mod_reg_u32_imm_u8:
		return handler_ROR_w_rm_mod_reg_u32_imm_u8(insb, cseip);
	case in_ROR_d_rm_mod_reg_u16_imm_u8:
		return handler_ROR_d_rm_mod_reg_u16_imm_u8(insb, cseip);
	case in_ROR_d_rm_mod_reg_u32_imm_u8:
		return handler_ROR_d_rm_mod_reg_u32_imm_u8(insb, cseip);
	case in_RCL_w_rm_mod_reg_u16_imm_u8:
		return handler_RCL_w_rm_mod_reg_u16_imm_u8(insb, cseip);
	case in_RCL_w_rm_mod_reg_u32_imm_u8:
		return handler_RCL_w_rm_mod_reg_u32_imm_u8(insb, cseip);
	case in_RCL_d_rm_mod_reg_u16_imm_u8:
		return handler_RCL_d_rm_mod_reg_u16_imm_u8(insb, cseip);
	case in_RCL_d_rm_mod_reg_u32_imm_u8:
		return handler_RCL_d_rm_mod_reg_u32_imm_u8(insb, cseip);
	case in_RCR_w_rm_mod_reg_u16_imm_u8:
		return handler_RCR_w_rm_mod_reg_u16_imm_u8(insb, cseip);
	case in_RCR_w_rm_mod_reg_u32_imm_u8:
		return handler_RCR_w_rm_mod_reg_u32_imm_u8(insb, cseip);
	case in_RCR_d_rm_mod_reg_u16_imm_u8:
		return handler_RCR_d_rm_mod_reg_u16_imm_u8(insb, cseip);
	case in_RCR_d_rm_mod_reg_u32_imm_u8:
		return handler_RCR_d_rm_mod_reg_u32_imm_u8(insb, cseip);
	case in_SHL_w_rm_mod_reg_u16_imm_u8:
		return handler_SHL_w_rm_mod_reg_u16_imm_u8(insb, cseip);
	case in_SHL_w_rm_mod_reg_u32_imm_u8:
		return handler_SHL_w_rm_mod_reg_u32_imm_u8(insb, cseip);
	case in_SHL_d_rm_mod_reg_u16_imm_u8:
		return handler_SHL_d_rm_mod_reg_u16_imm_u8(insb, cseip);
	case in_SHL_d_rm_mod_reg_u32_imm_u8:
		return handler_SHL_d_rm_mod_reg_u32_imm_u8(insb, cseip);
	case in_SHR_w_rm_mod_reg_u16_imm_u8:
		return handler_SHR_w_rm_mod_reg_u16_imm_u8(insb, cseip);
	case in_SHR_w_rm_mod_reg_u32_imm_u8:
		return handler_SHR_w_rm_mod_reg_u32_imm_u8(insb, cseip);
	case in_SHR_d_rm_mod_reg_u16_imm_u8:
		return handler_SHR_d_rm_mod_reg_u16_imm_u8(insb, cseip);
	case in_SHR_d_rm_mod_reg_u32_imm_u8:
		return handler_SHR_d_rm_mod_reg_u32_imm_u8(insb, cseip);
	case in_SAR_w_rm_mod_reg_u16_imm_u8:
		return handler_SAR_w_rm_mod_reg_u16_imm_u8(insb, cseip);
	case in_SAR_w_rm_mod_reg_u32_imm_u8:
		return handler_SAR_w_rm_mod_reg_u32_imm_u8(insb, cseip);
	case in_SAR_d_rm_mod_reg_u16_imm_u8:
		return handler_SAR_d_rm_mod_reg_u16_imm_u8(insb, cseip);
	case in_SAR_d_rm_mod_reg_u32_imm_u8:
		return handler_SAR_d_rm_mod_reg_u32_imm_u8(insb, cseip);
	case in_RETN_imm_u16:
		return handler_RETN_imm_u16(insb, cseip);
	case in_RETN:
		return handler_RETN(insb, cseip);
	case in_LES_w_rm_reg_reg_u16_rm_mem_p32:
		return handler_LES_w_rm_reg_reg_u16_rm_mem_p32(insb, cseip);
	case in_LES_d_rm_reg_reg_u16_rm_mem_p32:
		return handler_LES_d_rm_reg_reg_u16_rm_mem_p32(insb, cseip);
	case in_LDS_w_rm_reg_reg_u16_rm_mem_p32:
		return handler_LDS_w_rm_reg_reg_u16_rm_mem_p32(insb, cseip);
	case in_LDS_d_rm_reg_reg_u16_rm_mem_p32:
		return handler_LDS_d_rm_reg_reg_u16_rm_mem_p32(insb, cseip);
	case in_MOV_w_rm_mod_reg_u8_imm_u8:
		return handler_MOV_w_rm_mod_reg_u8_imm_u8(insb, cseip);
	case in_MOV_d_rm_mod_reg_u8_imm_u8:
		return handler_MOV_d_rm_mod_reg_u8_imm_u8(insb, cseip);
	case in_MOV_w_rm_mod_reg_u16_imm_i16:
		return handler_MOV_w_rm_mod_reg_u16_imm_i16(insb, cseip);
	case in_MOV_w_rm_mod_reg_u32_imm_i32:
		return handler_MOV_w_rm_mod_reg_u32_imm_i32(insb, cseip);
	case in_MOV_d_rm_mod_reg_u16_imm_i16:
		return handler_MOV_d_rm_mod_reg_u16_imm_i16(insb, cseip);
	case in_MOV_d_rm_mod_reg_u32_imm_i32:
		return handler_MOV_d_rm_mod_reg_u32_imm_i32(insb, cseip);
	case in_ENTER_imm_u8:
		return handler_ENTER_imm_u8(insb, cseip);
	case in_LEAVE:
		return handler_LEAVE(insb, cseip);
	case in_RETF_imm_u16:
		return handler_RETF_imm_u16(insb, cseip);
	case in_RETF:
		return handler_RETF(insb, cseip);
	case in_INT:
		return handler_INT(insb, cseip);
	case in_INT_imm_u8:
		return handler_INT_imm_u8(insb, cseip);
	case in_INTO:
		return handler_INTO(insb, cseip);
	case in_IRET:
		return handler_IRET(insb, cseip);
	case in_ROL_w_rm_mod_reg_u8:
		return handler_ROL_w_rm_mod_reg_u8(insb, cseip);
	case in_ROL_d_rm_mod_reg_u8:
		return handler_ROL_d_rm_mod_reg_u8(insb, cseip);
	case in_ROR_w_rm_mod_reg_u8:
		return handler_ROR_w_rm_mod_reg_u8(insb, cseip);
	case in_ROR_d_rm_mod_reg_u8:
		return handler_ROR_d_rm_mod_reg_u8(insb, cseip);
	case in_RCL_w_rm_mod_reg_u8:
		return handler_RCL_w_rm_mod_reg_u8(insb, cseip);
	case in_RCL_d_rm_mod_reg_u8:
		return handler_RCL_d_rm_mod_reg_u8(insb, cseip);
	case in_RCR_w_rm_mod_reg_u8:
		return handler_RCR_w_rm_mod_reg_u8(insb, cseip);
	case in_RCR_d_rm_mod_reg_u8:
		return handler_RCR_d_rm_mod_reg_u8(insb, cseip);
	case in_SHL_w_rm_mod_reg_u8:
		return handler_SHL_w_rm_mod_reg_u8(insb, cseip);
	case in_SHL_d_rm_mod_reg_u8:
		return handler_SHL_d_rm_mod_reg_u8(insb, cseip);
	case in_SHR_w_rm_mod_reg_u8:
		return handler_SHR_w_rm_mod_reg_u8(insb, cseip);
	case in_SHR_d_rm_mod_reg_u8:
		return handler_SHR_d_rm_mod_reg_u8(insb, cseip);
	case in_SAR_w_rm_mod_reg_u8:
		return handler_SAR_w_rm_mod_reg_u8(insb, cseip);
	case in_SAR_d_rm_mod_reg_u8:
		return handler_SAR_d_rm_mod_reg_u8(insb, cseip);
	case in_ROL_w_rm_mod_reg_u16:
		return handler_ROL_w_rm_mod_reg_u16(insb, cseip);
	case in_ROL_w_rm_mod_reg_u32:
		return handler_ROL_w_rm_mod_reg_u32(insb, cseip);
	case in_ROL_d_rm_mod_reg_u16:
		return handler_ROL_d_rm_mod_reg_u16(insb, cseip);
	case in_ROL_d_rm_mod_reg_u32:
		return handler_ROL_d_rm_mod_reg_u32(insb, cseip);
	case in_ROR_w_rm_mod_reg_u16:
		return handler_ROR_w_rm_mod_reg_u16(insb, cseip);
	case in_ROR_w_rm_mod_reg_u32:
		return handler_ROR_w_rm_mod_reg_u32(insb, cseip);
	case in_ROR_d_rm_mod_reg_u16:
		return handler_ROR_d_rm_mod_reg_u16(insb, cseip);
	case in_ROR_d_rm_mod_reg_u32:
		return handler_ROR_d_rm_mod_reg_u32(insb, cseip);
	case in_RCL_w_rm_mod_reg_u16:
		return handler_RCL_w_rm_mod_reg_u16(insb, cseip);
	case in_RCL_w_rm_mod_reg_u32:
		return handler_RCL_w_rm_mod_reg_u32(insb, cseip);
	case in_RCL_d_rm_mod_reg_u16:
		return handler_RCL_d_rm_mod_reg_u16(insb, cseip);
	case in_RCL_d_rm_mod_reg_u32:
		return handler_RCL_d_rm_mod_reg_u32(insb, cseip);
	case in_RCR_w_rm_mod_reg_u16:
		return handler_RCR_w_rm_mod_reg_u16(insb, cseip);
	case in_RCR_w_rm_mod_reg_u32:
		return handler_RCR_w_rm_mod_reg_u32(insb, cseip);
	case in_RCR_d_rm_mod_reg_u16:
		return handler_RCR_d_rm_mod_reg_u16(insb, cseip);
	case in_RCR_d_rm_mod_reg_u32:
		return handler_RCR_d_rm_mod_reg_u32(insb, cseip);
	case in_SHL_w_rm_mod_reg_u16:
		return handler_SHL_w_rm_mod_reg_u16(insb, cseip);
	case in_SHL_w_rm_mod_reg_u32:
		return handler_SHL_w_rm_mod_reg_u32(insb, cseip);
	case in_SHL_d_rm_mod_reg_u16:
		return handler_SHL_d_rm_mod_reg_u16(insb, cseip);
	case in_SHL_d_rm_mod_reg_u32:
		return handler_SHL_d_rm_mod_reg_u32(insb, cseip);
	case in_SHR_w_rm_mod_reg_u16:
		return handler_SHR_w_rm_mod_reg_u16(insb, cseip);
	case in_SHR_w_rm_mod_reg_u32:
		return handler_SHR_w_rm_mod_reg_u32(insb, cseip);
	case in_SHR_d_rm_mod_reg_u16:
		return handler_SHR_d_rm_mod_reg_u16(insb, cseip);
	case in_SHR_d_rm_mod_reg_u32:
		return handler_SHR_d_rm_mod_reg_u32(insb, cseip);
	case in_SAR_w_rm_mod_reg_u16:
		return handler_SAR_w_rm_mod_reg_u16(insb, cseip);
	case in_SAR_w_rm_mod_reg_u32:
		return handler_SAR_w_rm_mod_reg_u32(insb, cseip);
	case in_SAR_d_rm_mod_reg_u16:
		return handler_SAR_d_rm_mod_reg_u16(insb, cseip);
	case in_SAR_d_rm_mod_reg_u32:
		return handler_SAR_d_rm_mod_reg_u32(insb, cseip);
	case in_ROL_w_rm_mod_reg_u8_reg_gen_1_u8:
		return handler_ROL_w_rm_mod_reg_u8_reg_gen_1_u8(insb, cseip);
	case in_ROL_d_rm_mod_reg_u8_reg_gen_1_u8:
		return handler_ROL_d_rm_mod_reg_u8_reg_gen_1_u8(insb, cseip);
	case in_ROR_w_rm_mod_reg_u8_reg_gen_1_u8:
		return handler_ROR_w_rm_mod_reg_u8_reg_gen_1_u8(insb, cseip);
	case in_ROR_d_rm_mod_reg_u8_reg_gen_1_u8:
		return handler_ROR_d_rm_mod_reg_u8_reg_gen_1_u8(insb, cseip);
	case in_RCL_w_rm_mod_reg_u8_reg_gen_1_u8:
		return handler_RCL_w_rm_mod_reg_u8_reg_gen_1_u8(insb, cseip);
	case in_RCL_d_rm_mod_reg_u8_reg_gen_1_u8:
		return handler_RCL_d_rm_mod_reg_u8_reg_gen_1_u8(insb, cseip);
	case in_RCR_w_rm_mod_reg_u8_reg_gen_1_u8:
		return handler_RCR_w_rm_mod_reg_u8_reg_gen_1_u8(insb, cseip);
	case in_RCR_d_rm_mod_reg_u8_reg_gen_1_u8:
		return handler_RCR_d_rm_mod_reg_u8_reg_gen_1_u8(insb, cseip);
	case in_SHL_w_rm_mod_reg_u8_reg_gen_1_u8:
		return handler_SHL_w_rm_mod_reg_u8_reg_gen_1_u8(insb, cseip);
	case in_SHL_d_rm_mod_reg_u8_reg_gen_1_u8:
		return handler_SHL_d_rm_mod_reg_u8_reg_gen_1_u8(insb, cseip);
	case in_SHR_w_rm_mod_reg_u8_reg_gen_1_u8:
		return handler_SHR_w_rm_mod_reg_u8_reg_gen_1_u8(insb, cseip);
	case in_SHR_d_rm_mod_reg_u8_reg_gen_1_u8:
		return handler_SHR_d_rm_mod_reg_u8_reg_gen_1_u8(insb, cseip);
	case in_SAR_w_rm_mod_reg_u8_reg_gen_1_u8:
		return handler_SAR_w_rm_mod_reg_u8_reg_gen_1_u8(insb, cseip);
	case in_SAR_d_rm_mod_reg_u8_reg_gen_1_u8:
		return handler_SAR_d_rm_mod_reg_u8_reg_gen_1_u8(insb, cseip);
	case in_ROL_w_rm_mod_reg_u16_reg_gen_1_u8:
		return handler_ROL_w_rm_mod_reg_u16_reg_gen_1_u8(insb, cseip);
	case in_ROL_w_rm_mod_reg_u32_reg_gen_1_u8:
		return handler_ROL_w_rm_mod_reg_u32_reg_gen_1_u8(insb, cseip);
	case in_ROL_d_rm_mod_reg_u16_reg_gen_1_u8:
		return handler_ROL_d_rm_mod_reg_u16_reg_gen_1_u8(insb, cseip);
	case in_ROL_d_rm_mod_reg_u32_reg_gen_1_u8:
		return handler_ROL_d_rm_mod_reg_u32_reg_gen_1_u8(insb, cseip);
	case in_ROR_w_rm_mod_reg_u16_reg_gen_1_u8:
		return handler_ROR_w_rm_mod_reg_u16_reg_gen_1_u8(insb, cseip);
	case in_ROR_w_rm_mod_reg_u32_reg_gen_1_u8:
		return handler_ROR_w_rm_mod_reg_u32_reg_gen_1_u8(insb, cseip);
	case in_ROR_d_rm_mod_reg_u16_reg_gen_1_u8:
		return handler_ROR_d_rm_mod_reg_u16_reg_gen_1_u8(insb, cseip);
	case in_ROR_d_rm_mod_reg_u32_reg_gen_1_u8:
		return handler_ROR_d_rm_mod_reg_u32_reg_gen_1_u8(insb, cseip);
	case in_RCL_w_rm_mod_reg_u16_reg_gen_1_u8:
		return handler_RCL_w_rm_mod_reg_u16_reg_gen_1_u8(insb, cseip);
	case in_RCL_w_rm_mod_reg_u32_reg_gen_1_u8:
		return handler_RCL_w_rm_mod_reg_u32_reg_gen_1_u8(insb, cseip);
	case in_RCL_d_rm_mod_reg_u16_reg_gen_1_u8:
		return handler_RCL_d_rm_mod_reg_u16_reg_gen_1_u8(insb, cseip);
	case in_RCL_d_rm_mod_reg_u32_reg_gen_1_u8:
		return handler_RCL_d_rm_mod_reg_u32_reg_gen_1_u8(insb, cseip);
	case in_RCR_w_rm_mod_reg_u16_reg_gen_1_u8:
		return handler_RCR_w_rm_mod_reg_u16_reg_gen_1_u8(insb, cseip);
	case in_RCR_w_rm_mod_reg_u32_reg_gen_1_u8:
		return handler_RCR_w_rm_mod_reg_u32_reg_gen_1_u8(insb, cseip);
	case in_RCR_d_rm_mod_reg_u16_reg_gen_1_u8:
		return handler_RCR_d_rm_mod_reg_u16_reg_gen_1_u8(insb, cseip);
	case in_RCR_d_rm_mod_reg_u32_reg_gen_1_u8:
		return handler_RCR_d_rm_mod_reg_u32_reg_gen_1_u8(insb, cseip);
	case in_SHL_w_rm_mod_reg_u16_reg_gen_1_u8:
		return handler_SHL_w_rm_mod_reg_u16_reg_gen_1_u8(insb, cseip);
	case in_SHL_w_rm_mod_reg_u32_reg_gen_1_u8:
		return handler_SHL_w_rm_mod_reg_u32_reg_gen_1_u8(insb, cseip);
	case in_SHL_d_rm_mod_reg_u16_reg_gen_1_u8:
		return handler_SHL_d_rm_mod_reg_u16_reg_gen_1_u8(insb, cseip);
	case in_SHL_d_rm_mod_reg_u32_reg_gen_1_u8:
		return handler_SHL_d_rm_mod_reg_u32_reg_gen_1_u8(insb, cseip);
	case in_SHR_w_rm_mod_reg_u16_reg_gen_1_u8:
		return handler_SHR_w_rm_mod_reg_u16_reg_gen_1_u8(insb, cseip);
	case in_SHR_w_rm_mod_reg_u32_reg_gen_1_u8:
		return handler_SHR_w_rm_mod_reg_u32_reg_gen_1_u8(insb, cseip);
	case in_SHR_d_rm_mod_reg_u16_reg_gen_1_u8:
		return handler_SHR_d_rm_mod_reg_u16_reg_gen_1_u8(insb, cseip);
	case in_SHR_d_rm_mod_reg_u32_reg_gen_1_u8:
		return handler_SHR_d_rm_mod_reg_u32_reg_gen_1_u8(insb, cseip);
	case in_SAR_w_rm_mod_reg_u16_reg_gen_1_u8:
		return handler_SAR_w_rm_mod_reg_u16_reg_gen_1_u8(insb, cseip);
	case in_SAR_w_rm_mod_reg_u32_reg_gen_1_u8:
		return handler_SAR_w_rm_mod_reg_u32_reg_gen_1_u8(insb, cseip);
	case in_SAR_d_rm_mod_reg_u16_reg_gen_1_u8:
		return handler_SAR_d_rm_mod_reg_u16_reg_gen_1_u8(insb, cseip);
	case in_SAR_d_rm_mod_reg_u32_reg_gen_1_u8:
		return handler_SAR_d_rm_mod_reg_u32_reg_gen_1_u8(insb, cseip);
	case in_AMX_imm_u8:
		return handler_AMX_imm_u8(insb, cseip);
	case in_ADX_imm_u8:
		return handler_ADX_imm_u8(insb, cseip);
	case in_XLAT_w_mem_reg_3_u8:
		return handler_XLAT_w_mem_reg_3_u8(insb, cseip);
	case in_XLAT_d_mem_reg_3_u8:
		return handler_XLAT_d_mem_reg_3_u8(insb, cseip);
	case in_LOOPNZ_w_mem_imm_J_u8:
		return handler_LOOPNZ_w_mem_imm_J_u8(insb, cseip);
	case in_LOOPNZ_d_mem_imm_J_u8:
		return handler_LOOPNZ_d_mem_imm_J_u8(insb, cseip);
	case in_LOOPZ_w_mem_imm_J_u8:
		return handler_LOOPZ_w_mem_imm_J_u8(insb, cseip);
	case in_LOOPZ_d_mem_imm_J_u8:
		return handler_LOOPZ_d_mem_imm_J_u8(insb, cseip);
	case in_LOOP_w_mem_imm_J_u8:
		return handler_LOOP_w_mem_imm_J_u8(insb, cseip);
	case in_LOOP_d_mem_imm_J_u8:
		return handler_LOOP_d_mem_imm_J_u8(insb, cseip);
	case in_JCXZ_w_mem_imm_J_u8:
		return handler_JCXZ_w_mem_imm_J_u8(insb, cseip);
	case in_JCXZ_d_mem_imm_J_u8:
		return handler_JCXZ_d_mem_imm_J_u8(insb, cseip);
	case in_IN_reg_gen_u8_imm_u8:
		return handler_IN_reg_gen_u8_imm_u8(insb, cseip);
	case in_IN_reg_gen_u16_imm_u8:
		return handler_IN_reg_gen_u16_imm_u8(insb, cseip);
	case in_IN_reg_gen_u32_imm_u8:
		return handler_IN_reg_gen_u32_imm_u8(insb, cseip);
	case in_OUT_imm_u8_reg_gen_u8:
		return handler_OUT_imm_u8_reg_gen_u8(insb, cseip);
	case in_OUT_imm_u8_reg_gen_u16:
		return handler_OUT_imm_u8_reg_gen_u16(insb, cseip);
	case in_OUT_imm_u8_reg_gen_u32:
		return handler_OUT_imm_u8_reg_gen_u32(insb, cseip);
	case in_JMPF_w_mem_imm_p32:
		return handler_JMPF_w_mem_imm_p32(insb, cseip);
	case in_JMPF_d_mem_imm_p32:
		return handler_JMPF_d_mem_imm_p32(insb, cseip);
	case in_JMP_w_mem_imm_J_u8:
		return handler_JMP_w_mem_imm_J_u8(insb, cseip);
	case in_JMP_d_mem_imm_J_u8:
		return handler_JMP_d_mem_imm_J_u8(insb, cseip);
	case in_IN_reg_gen_u8_reg_gen_2_u16:
		return handler_IN_reg_gen_u8_reg_gen_2_u16(insb, cseip);
	case in_IN_reg_gen_u16_reg_gen_2_u16:
		return handler_IN_reg_gen_u16_reg_gen_2_u16(insb, cseip);
	case in_IN_reg_gen_u32_reg_gen_2_u16:
		return handler_IN_reg_gen_u32_reg_gen_2_u16(insb, cseip);
	case in_OUT_reg_gen_2_u16_reg_gen_u8:
		return handler_OUT_reg_gen_2_u16_reg_gen_u8(insb, cseip);
	case in_OUT_reg_gen_2_u16_reg_gen_u16:
		return handler_OUT_reg_gen_2_u16_reg_gen_u16(insb, cseip);
	case in_OUT_reg_gen_2_u16_reg_gen_u32:
		return handler_OUT_reg_gen_2_u16_reg_gen_u32(insb, cseip);
	case in_HLT:
		return handler_HLT(insb, cseip);
	case in_CMC:
		return handler_CMC(insb, cseip);
	case in_TEST_w_imm_u8:
		return handler_TEST_w_imm_u8(insb, cseip);
	case in_TEST_d_imm_u8:
		return handler_TEST_d_imm_u8(insb, cseip);
	case in_NOT_w_rm_mod_reg_u8:
		return handler_NOT_w_rm_mod_reg_u8(insb, cseip);
	case in_NOT_d_rm_mod_reg_u8:
		return handler_NOT_d_rm_mod_reg_u8(insb, cseip);
	case in_NEG_w_rm_mod_reg_u8:
		return handler_NEG_w_rm_mod_reg_u8(insb, cseip);
	case in_NEG_d_rm_mod_reg_u8:
		return handler_NEG_d_rm_mod_reg_u8(insb, cseip);
	case in_MUL_w_rm_mod_reg_u8:
		return handler_MUL_w_rm_mod_reg_u8(insb, cseip);
	case in_MUL_d_rm_mod_reg_u8:
		return handler_MUL_d_rm_mod_reg_u8(insb, cseip);
	case in_IMUL_w_rm_mod_reg_u8:
		return handler_IMUL_w_rm_mod_reg_u8(insb, cseip);
	case in_IMUL_d_rm_mod_reg_u8:
		return handler_IMUL_d_rm_mod_reg_u8(insb, cseip);
	case in_DIV_w_rm_mod_reg_u8:
		return handler_DIV_w_rm_mod_reg_u8(insb, cseip);
	case in_DIV_d_rm_mod_reg_u8:
		return handler_DIV_d_rm_mod_reg_u8(insb, cseip);
	case in_IDIV_w_rm_mod_reg_u8:
		return handler_IDIV_w_rm_mod_reg_u8(insb, cseip);
	case in_IDIV_d_rm_mod_reg_u8:
		return handler_IDIV_d_rm_mod_reg_u8(insb, cseip);
	case in_TEST_w_imm_u16:
		return handler_TEST_w_imm_u16(insb, cseip);
	case in_TEST_w_imm_u32:
		return handler_TEST_w_imm_u32(insb, cseip);
	case in_TEST_d_imm_u16:
		return handler_TEST_d_imm_u16(insb, cseip);
	case in_TEST_d_imm_u32:
		return handler_TEST_d_imm_u32(insb, cseip);
	case in_NOT_w_rm_mod_reg_u16:
		return handler_NOT_w_rm_mod_reg_u16(insb, cseip);
	case in_NOT_w_rm_mod_reg_u32:
		return handler_NOT_w_rm_mod_reg_u32(insb, cseip);
	case in_NOT_d_rm_mod_reg_u16:
		return handler_NOT_d_rm_mod_reg_u16(insb, cseip);
	case in_NOT_d_rm_mod_reg_u32:
		return handler_NOT_d_rm_mod_reg_u32(insb, cseip);
	case in_NEG_w_rm_mod_reg_u16:
		return handler_NEG_w_rm_mod_reg_u16(insb, cseip);
	case in_NEG_w_rm_mod_reg_u32:
		return handler_NEG_w_rm_mod_reg_u32(insb, cseip);
	case in_NEG_d_rm_mod_reg_u16:
		return handler_NEG_d_rm_mod_reg_u16(insb, cseip);
	case in_NEG_d_rm_mod_reg_u32:
		return handler_NEG_d_rm_mod_reg_u32(insb, cseip);
	case in_MUL_w_rm_mod_reg_u16:
		return handler_MUL_w_rm_mod_reg_u16(insb, cseip);
	case in_MUL_w_rm_mod_reg_u32:
		return handler_MUL_w_rm_mod_reg_u32(insb, cseip);
	case in_MUL_d_rm_mod_reg_u16:
		return handler_MUL_d_rm_mod_reg_u16(insb, cseip);
	case in_MUL_d_rm_mod_reg_u32:
		return handler_MUL_d_rm_mod_reg_u32(insb, cseip);
	case in_IMUL_w_rm_mod_reg_u16:
		return handler_IMUL_w_rm_mod_reg_u16(insb, cseip);
	case in_IMUL_d_rm_mod_reg_u16:
		return handler_IMUL_d_rm_mod_reg_u16(insb, cseip);
	case in_DIV_w_rm_mod_reg_u16:
		return handler_DIV_w_rm_mod_reg_u16(insb, cseip);
	case in_DIV_d_rm_mod_reg_u16:
		return handler_DIV_d_rm_mod_reg_u16(insb, cseip);
	case in_IDIV_w_rm_mod_reg_u16:
		return handler_IDIV_w_rm_mod_reg_u16(insb, cseip);
	case in_IDIV_d_rm_mod_reg_u16:
		return handler_IDIV_d_rm_mod_reg_u16(insb, cseip);
	case in_CLC:
		return handler_CLC(insb, cseip);
	case in_STC:
		return handler_STC(insb, cseip);
	case in_CLI:
		return handler_CLI(insb, cseip);
	case in_STI:
		return handler_STI(insb, cseip);
	case in_CLD:
		return handler_CLD(insb, cseip);
	case in_STD:
		return handler_STD(insb, cseip);
	case in_INC_w_rm_mod_reg_u8:
		return handler_INC_w_rm_mod_reg_u8(insb, cseip);
	case in_INC_d_rm_mod_reg_u8:
		return handler_INC_d_rm_mod_reg_u8(insb, cseip);
	case in_DEC_w_rm_mod_reg_u8:
		return handler_DEC_w_rm_mod_reg_u8(insb, cseip);
	case in_DEC_d_rm_mod_reg_u8:
		return handler_DEC_d_rm_mod_reg_u8(insb, cseip);
	case in_INC_w_rm_mod_reg_u16:
		return handler_INC_w_rm_mod_reg_u16(insb, cseip);
	case in_INC_w_rm_mod_reg_u32:
		return handler_INC_w_rm_mod_reg_u32(insb, cseip);
	case in_INC_d_rm_mod_reg_u16:
		return handler_INC_d_rm_mod_reg_u16(insb, cseip);
	case in_INC_d_rm_mod_reg_u32:
		return handler_INC_d_rm_mod_reg_u32(insb, cseip);
	case in_DEC_w_rm_mod_reg_u16:
		return handler_DEC_w_rm_mod_reg_u16(insb, cseip);
	case in_DEC_w_rm_mod_reg_u32:
		return handler_DEC_w_rm_mod_reg_u32(insb, cseip);
	case in_DEC_d_rm_mod_reg_u16:
		return handler_DEC_d_rm_mod_reg_u16(insb, cseip);
	case in_DEC_d_rm_mod_reg_u32:
		return handler_DEC_d_rm_mod_reg_u32(insb, cseip);
	case in_CALL_w_rm_mod_reg_u16:
		return handler_CALL_w_rm_mod_reg_u16(insb, cseip);
	case in_CALL_d_rm_mod_reg_u16:
		return handler_CALL_d_rm_mod_reg_u16(insb, cseip);
	case in_JMP_w_rm_mod_reg_u16:
		return handler_JMP_w_rm_mod_reg_u16(insb, cseip);
	case in_JMP_d_rm_mod_reg_u16:
		return handler_JMP_d_rm_mod_reg_u16(insb, cseip);
	case in_PUSH_w_rm_mod_reg_u16:
		return handler_PUSH_w_rm_mod_reg_u16(insb, cseip);
	case in_PUSH_d_rm_mod_reg_u16:
		return handler_PUSH_d_rm_mod_reg_u16(insb, cseip);
	case in_SLDT_w_rm_mem_u16:
		return handler_SLDT_w_rm_mem_u16(insb, cseip);
	case in_SLDT_d_rm_mem_u16:
		return handler_SLDT_d_rm_mem_u16(insb, cseip);
	case in_STR_w_rm_mem_u16:
		return handler_STR_w_rm_mem_u16(insb, cseip);
	case in_STR_d_rm_mem_u16:
		return handler_STR_d_rm_mem_u16(insb, cseip);
	case in_LLDT_w_rm_mod_reg_u16:
		return handler_LLDT_w_rm_mod_reg_u16(insb, cseip);
	case in_LLDT_d_rm_mod_reg_u16:
		return handler_LLDT_d_rm_mod_reg_u16(insb, cseip);
	case in_LTR_w_rm_mod_reg_u16:
		return handler_LTR_w_rm_mod_reg_u16(insb, cseip);
	case in_LTR_d_rm_mod_reg_u16:
		return handler_LTR_d_rm_mod_reg_u16(insb, cseip);
	case in_VERR_w_rm_mod_reg_u16:
		return handler_VERR_w_rm_mod_reg_u16(insb, cseip);
	case in_VERR_d_rm_mod_reg_u16:
		return handler_VERR_d_rm_mod_reg_u16(insb, cseip);
	case in_VERW_w_rm_mod_reg_u16:
		return handler_VERW_w_rm_mod_reg_u16(insb, cseip);
	case in_VERW_d_rm_mod_reg_u16:
		return handler_VERW_d_rm_mod_reg_u16(insb, cseip);
	case in_SGDT_w_rm_mem_x48:
		return handler_SGDT_w_rm_mem_x48(insb, cseip);
	case in_SGDT_d_rm_mem_x48:
		return handler_SGDT_d_rm_mem_x48(insb, cseip);
	case in_SIDT_w_rm_mem_x48:
		return handler_SIDT_w_rm_mem_x48(insb, cseip);
	case in_SIDT_d_rm_mem_x48:
		return handler_SIDT_d_rm_mem_x48(insb, cseip);
	case in_MONITOR_w:
		return handler_MONITOR_w(insb, cseip);
	case in_MONITOR_d:
		return handler_MONITOR_d(insb, cseip);
	case in_MWAIT:
		return handler_MWAIT(insb, cseip);
	case in_LGDT_w_rm_mem_x48:
		return handler_LGDT_w_rm_mem_x48(insb, cseip);
	case in_LGDT_d_rm_mem_x48:
		return handler_LGDT_d_rm_mem_x48(insb, cseip);
	case in_XGETBV:
		return handler_XGETBV(insb, cseip);
	case in_XSETBV:
		return handler_XSETBV(insb, cseip);
	case in_LIDT_w_rm_mem_x48:
		return handler_LIDT_w_rm_mem_x48(insb, cseip);
	case in_LIDT_d_rm_mem_x48:
		return handler_LIDT_d_rm_mem_x48(insb, cseip);
	case in_LMSW_w_rm_mod_reg_u16:
		return handler_LMSW_w_rm_mod_reg_u16(insb, cseip);
	case in_LMSW_d_rm_mod_reg_u16:
		return handler_LMSW_d_rm_mod_reg_u16(insb, cseip);
	case in_INVLPG:
		return handler_INVLPG(insb, cseip);
	case in_RDTSCP:
		return handler_RDTSCP(insb, cseip);
	case in_LAR_w_rm_reg_reg_u16_rm_mem_u16:
		return handler_LAR_w_rm_reg_reg_u16_rm_mem_u16(insb, cseip);
	case in_LAR_d_rm_reg_reg_u16_rm_mem_u16:
		return handler_LAR_d_rm_reg_reg_u16_rm_mem_u16(insb, cseip);
	case in_LSL_w_rm_reg_reg_u16_rm_mem_u16:
		return handler_LSL_w_rm_reg_reg_u16_rm_mem_u16(insb, cseip);
	case in_LSL_d_rm_reg_reg_u16_rm_mem_u16:
		return handler_LSL_d_rm_reg_reg_u16_rm_mem_u16(insb, cseip);
	case in_LOADALL:
		return handler_LOADALL(insb, cseip);
	case in_CLTS:
		return handler_CLTS(insb, cseip);
	case in_INVD:
		return handler_INVD(insb, cseip);
	case in_WBINVD:
		return handler_WBINVD(insb, cseip);
	case in_MOVUPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128:
		return handler_MOVUPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128(insb, cseip);
	case in_MOVUPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128:
		return handler_MOVUPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128(insb, cseip);
	case in_MOVSS_w_rm_reg_xmm_f128_rm_mod_xmm_f128:
		return handler_MOVSS_w_rm_reg_xmm_f128_rm_mod_xmm_f128(insb, cseip);
	case in_MOVSS_d_rm_reg_xmm_f128_rm_mod_xmm_f128:
		return handler_MOVSS_d_rm_reg_xmm_f128_rm_mod_xmm_f128(insb, cseip);
	case in_MOVUPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128:
		return handler_MOVUPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128(insb, cseip);
	case in_MOVUPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128:
		return handler_MOVUPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128(insb, cseip);
	case in_MOVSD_w_rm_reg_xmm_d128_rm_mod_xmm_d128:
		return handler_MOVSD_w_rm_reg_xmm_d128_rm_mod_xmm_d128(insb, cseip);
	case in_MOVSD_d_rm_reg_xmm_d128_rm_mod_xmm_d128:
		return handler_MOVSD_d_rm_reg_xmm_d128_rm_mod_xmm_d128(insb, cseip);
	case in_MOVUPS_w_rm_mod_xmm_f128_rm_reg_xmm_f128:
		return handler_MOVUPS_w_rm_mod_xmm_f128_rm_reg_xmm_f128(insb, cseip);
	case in_MOVUPS_d_rm_mod_xmm_f128_rm_reg_xmm_f128:
		return handler_MOVUPS_d_rm_mod_xmm_f128_rm_reg_xmm_f128(insb, cseip);
	case in_MOVSS_w_rm_mod_xmm_f128_rm_reg_xmm_f128:
		return handler_MOVSS_w_rm_mod_xmm_f128_rm_reg_xmm_f128(insb, cseip);
	case in_MOVSS_d_rm_mod_xmm_f128_rm_reg_xmm_f128:
		return handler_MOVSS_d_rm_mod_xmm_f128_rm_reg_xmm_f128(insb, cseip);
	case in_MOVUPD_w_rm_mod_xmm_d128_rm_reg_xmm_d128:
		return handler_MOVUPD_w_rm_mod_xmm_d128_rm_reg_xmm_d128(insb, cseip);
	case in_MOVUPD_d_rm_mod_xmm_d128_rm_reg_xmm_d128:
		return handler_MOVUPD_d_rm_mod_xmm_d128_rm_reg_xmm_d128(insb, cseip);
	case in_MOVSD_w_rm_mod_xmm_d128_rm_reg_xmm_d128:
		return handler_MOVSD_w_rm_mod_xmm_d128_rm_reg_xmm_d128(insb, cseip);
	case in_MOVSD_d_rm_mod_xmm_d128_rm_reg_xmm_d128:
		return handler_MOVSD_d_rm_mod_xmm_d128_rm_reg_xmm_d128(insb, cseip);
	case in_MOVHLPS_w_rm_reg_xmm_u64_rm_rm_xmm_u64:
		return handler_MOVHLPS_w_rm_reg_xmm_u64_rm_rm_xmm_u64(insb, cseip);
	case in_MOVHLPS_d_rm_reg_xmm_u64_rm_rm_xmm_u64:
		return handler_MOVHLPS_d_rm_reg_xmm_u64_rm_rm_xmm_u64(insb, cseip);
	case in_MOVLPS_w_rm_reg_xmm_u64_rm_mem_u64:
		return handler_MOVLPS_w_rm_reg_xmm_u64_rm_mem_u64(insb, cseip);
	case in_MOVLPS_d_rm_reg_xmm_u64_rm_mem_u64:
		return handler_MOVLPS_d_rm_reg_xmm_u64_rm_mem_u64(insb, cseip);
	case in_MOVLPD_w_rm_reg_xmm_u64_rm_mem_u64:
		return handler_MOVLPD_w_rm_reg_xmm_u64_rm_mem_u64(insb, cseip);
	case in_MOVLPD_d_rm_reg_xmm_u64_rm_mem_u64:
		return handler_MOVLPD_d_rm_reg_xmm_u64_rm_mem_u64(insb, cseip);
	case in_MOVDDUP_w_rm_reg_xmm_u64_rm_mod_xmm_u64:
		return handler_MOVDDUP_w_rm_reg_xmm_u64_rm_mod_xmm_u64(insb, cseip);
	case in_MOVDDUP_d_rm_reg_xmm_u64_rm_mod_xmm_u64:
		return handler_MOVDDUP_d_rm_reg_xmm_u64_rm_mod_xmm_u64(insb, cseip);
	case in_MOVSLDUP_w_rm_reg_xmm_u64_rm_mod_xmm_u64:
		return handler_MOVSLDUP_w_rm_reg_xmm_u64_rm_mod_xmm_u64(insb, cseip);
	case in_MOVSLDUP_d_rm_reg_xmm_u64_rm_mod_xmm_u64:
		return handler_MOVSLDUP_d_rm_reg_xmm_u64_rm_mod_xmm_u64(insb, cseip);
	case in_MOVLPS_w_rm_mem_u64_rm_reg_xmm_u64:
		return handler_MOVLPS_w_rm_mem_u64_rm_reg_xmm_u64(insb, cseip);
	case in_MOVLPS_d_rm_mem_u64_rm_reg_xmm_u64:
		return handler_MOVLPS_d_rm_mem_u64_rm_reg_xmm_u64(insb, cseip);
	case in_MOVLPD_w_rm_mem_u64_rm_reg_xmm_u64:
		return handler_MOVLPD_w_rm_mem_u64_rm_reg_xmm_u64(insb, cseip);
	case in_MOVLPD_d_rm_mem_u64_rm_reg_xmm_u64:
		return handler_MOVLPD_d_rm_mem_u64_rm_reg_xmm_u64(insb, cseip);
	case in_UNPCKLPS_w_rm_reg_xmm_f128_rm_mod_xmm_u64:
		return handler_UNPCKLPS_w_rm_reg_xmm_f128_rm_mod_xmm_u64(insb, cseip);
	case in_UNPCKLPS_d_rm_reg_xmm_f128_rm_mod_xmm_u64:
		return handler_UNPCKLPS_d_rm_reg_xmm_f128_rm_mod_xmm_u64(insb, cseip);
	case in_UNPCKLPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128:
		return handler_UNPCKLPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128(insb, cseip);
	case in_UNPCKLPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128:
		return handler_UNPCKLPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128(insb, cseip);
	case in_UNPCKHPS_w_rm_reg_xmm_f128_rm_mod_xmm_u64:
		return handler_UNPCKHPS_w_rm_reg_xmm_f128_rm_mod_xmm_u64(insb, cseip);
	case in_UNPCKHPS_d_rm_reg_xmm_f128_rm_mod_xmm_u64:
		return handler_UNPCKHPS_d_rm_reg_xmm_f128_rm_mod_xmm_u64(insb, cseip);
	case in_UNPCKHPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128:
		return handler_UNPCKHPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128(insb, cseip);
	case in_UNPCKHPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128:
		return handler_UNPCKHPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128(insb, cseip);
	case in_MOVLHPS_w_rm_reg_xmm_u64_rm_rm_xmm_u64:
		return handler_MOVLHPS_w_rm_reg_xmm_u64_rm_rm_xmm_u64(insb, cseip);
	case in_MOVLHPS_d_rm_reg_xmm_u64_rm_rm_xmm_u64:
		return handler_MOVLHPS_d_rm_reg_xmm_u64_rm_rm_xmm_u64(insb, cseip);
	case in_MOVHPS_w_rm_reg_xmm_u64_rm_mem_u64:
		return handler_MOVHPS_w_rm_reg_xmm_u64_rm_mem_u64(insb, cseip);
	case in_MOVHPS_d_rm_reg_xmm_u64_rm_mem_u64:
		return handler_MOVHPS_d_rm_reg_xmm_u64_rm_mem_u64(insb, cseip);
	case in_MOVHPD_w_rm_reg_xmm_u64_rm_mem_u64:
		return handler_MOVHPD_w_rm_reg_xmm_u64_rm_mem_u64(insb, cseip);
	case in_MOVHPD_d_rm_reg_xmm_u64_rm_mem_u64:
		return handler_MOVHPD_d_rm_reg_xmm_u64_rm_mem_u64(insb, cseip);
	case in_MOVSHDUP_w_rm_reg_xmm_u64_rm_mod_xmm_u64:
		return handler_MOVSHDUP_w_rm_reg_xmm_u64_rm_mod_xmm_u64(insb, cseip);
	case in_MOVSHDUP_d_rm_reg_xmm_u64_rm_mod_xmm_u64:
		return handler_MOVSHDUP_d_rm_reg_xmm_u64_rm_mod_xmm_u64(insb, cseip);
	case in_MOVHPS_w_rm_mem_u64_rm_reg_xmm_u64:
		return handler_MOVHPS_w_rm_mem_u64_rm_reg_xmm_u64(insb, cseip);
	case in_MOVHPS_d_rm_mem_u64_rm_reg_xmm_u64:
		return handler_MOVHPS_d_rm_mem_u64_rm_reg_xmm_u64(insb, cseip);
	case in_MOVHPD_w_rm_mem_u64_rm_reg_xmm_u64:
		return handler_MOVHPD_w_rm_mem_u64_rm_reg_xmm_u64(insb, cseip);
	case in_MOVHPD_d_rm_mem_u64_rm_reg_xmm_u64:
		return handler_MOVHPD_d_rm_mem_u64_rm_reg_xmm_u64(insb, cseip);
	case in_PREFETCHNTA_w_rm_mem_u8:
		return handler_PREFETCHNTA_w_rm_mem_u8(insb, cseip);
	case in_PREFETCHNTA_d_rm_mem_u8:
		return handler_PREFETCHNTA_d_rm_mem_u8(insb, cseip);
	case in_PREFETCHT0_w_rm_mem_u8:
		return handler_PREFETCHT0_w_rm_mem_u8(insb, cseip);
	case in_PREFETCHT0_d_rm_mem_u8:
		return handler_PREFETCHT0_d_rm_mem_u8(insb, cseip);
	case in_PREFETCHT1_w_rm_mem_u8:
		return handler_PREFETCHT1_w_rm_mem_u8(insb, cseip);
	case in_PREFETCHT1_d_rm_mem_u8:
		return handler_PREFETCHT1_d_rm_mem_u8(insb, cseip);
	case in_PREFETCHT2_w_rm_mem_u8:
		return handler_PREFETCHT2_w_rm_mem_u8(insb, cseip);
	case in_PREFETCHT2_d_rm_mem_u8:
		return handler_PREFETCHT2_d_rm_mem_u8(insb, cseip);
	case in_NOP_w_rm_mod_reg_u16:
		return handler_NOP_w_rm_mod_reg_u16(insb, cseip);
	case in_NOP_d_rm_mod_reg_u16:
		return handler_NOP_d_rm_mod_reg_u16(insb, cseip);
	case in_MOVAPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128:
		return handler_MOVAPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128(insb, cseip);
	case in_MOVAPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128:
		return handler_MOVAPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128(insb, cseip);
	case in_MOVAPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128:
		return handler_MOVAPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128(insb, cseip);
	case in_MOVAPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128:
		return handler_MOVAPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128(insb, cseip);
	case in_MOVAPS_w_rm_mod_xmm_f128_rm_reg_xmm_f128:
		return handler_MOVAPS_w_rm_mod_xmm_f128_rm_reg_xmm_f128(insb, cseip);
	case in_MOVAPS_d_rm_mod_xmm_f128_rm_reg_xmm_f128:
		return handler_MOVAPS_d_rm_mod_xmm_f128_rm_reg_xmm_f128(insb, cseip);
	case in_MOVAPD_w_rm_mod_xmm_d128_rm_reg_xmm_d128:
		return handler_MOVAPD_w_rm_mod_xmm_d128_rm_reg_xmm_d128(insb, cseip);
	case in_MOVAPD_d_rm_mod_xmm_d128_rm_reg_xmm_d128:
		return handler_MOVAPD_d_rm_mod_xmm_d128_rm_reg_xmm_d128(insb, cseip);
	case in_CVTPI2PS_w_rm_reg_xmm_f128_rm_mod_mmx_u64:
		return handler_CVTPI2PS_w_rm_reg_xmm_f128_rm_mod_mmx_u64(insb, cseip);
	case in_CVTPI2PS_d_rm_reg_xmm_f128_rm_mod_mmx_u64:
		return handler_CVTPI2PS_d_rm_reg_xmm_f128_rm_mod_mmx_u64(insb, cseip);
	case in_CVTSI2SS_w_rm_reg_xmm_f128_rm_mod_reg_u32:
		return handler_CVTSI2SS_w_rm_reg_xmm_f128_rm_mod_reg_u32(insb, cseip);
	case in_CVTSI2SS_d_rm_reg_xmm_f128_rm_mod_reg_u32:
		return handler_CVTSI2SS_d_rm_reg_xmm_f128_rm_mod_reg_u32(insb, cseip);
	case in_CVTPI2PD_w_rm_reg_xmm_d128_rm_mod_mmx_u64:
		return handler_CVTPI2PD_w_rm_reg_xmm_d128_rm_mod_mmx_u64(insb, cseip);
	case in_CVTPI2PD_d_rm_reg_xmm_d128_rm_mod_mmx_u64:
		return handler_CVTPI2PD_d_rm_reg_xmm_d128_rm_mod_mmx_u64(insb, cseip);
	case in_CVTSI2SD_w_rm_reg_xmm_d128_rm_mod_reg_u32:
		return handler_CVTSI2SD_w_rm_reg_xmm_d128_rm_mod_reg_u32(insb, cseip);
	case in_CVTSI2SD_d_rm_reg_xmm_d128_rm_mod_reg_u32:
		return handler_CVTSI2SD_d_rm_reg_xmm_d128_rm_mod_reg_u32(insb, cseip);
	case in_MOVNTPS_w_rm_mem_f128_rm_reg_xmm_f128:
		return handler_MOVNTPS_w_rm_mem_f128_rm_reg_xmm_f128(insb, cseip);
	case in_MOVNTPS_d_rm_mem_f128_rm_reg_xmm_f128:
		return handler_MOVNTPS_d_rm_mem_f128_rm_reg_xmm_f128(insb, cseip);
	case in_MOVNTPD_w_rm_mem_d128_rm_reg_xmm_d128:
		return handler_MOVNTPD_w_rm_mem_d128_rm_reg_xmm_d128(insb, cseip);
	case in_MOVNTPD_d_rm_mem_d128_rm_reg_xmm_d128:
		return handler_MOVNTPD_d_rm_mem_d128_rm_reg_xmm_d128(insb, cseip);
	case in_CVTTPS2PI_w_rm_reg_mmx_u64_rm_mod_xmm_f64:
		return handler_CVTTPS2PI_w_rm_reg_mmx_u64_rm_mod_xmm_f64(insb, cseip);
	case in_CVTTPS2PI_d_rm_reg_mmx_u64_rm_mod_xmm_f64:
		return handler_CVTTPS2PI_d_rm_reg_mmx_u64_rm_mod_xmm_f64(insb, cseip);
	case in_CVTTSS2SI_w_rm_reg_reg_u32_rm_mod_xmm_f128:
		return handler_CVTTSS2SI_w_rm_reg_reg_u32_rm_mod_xmm_f128(insb, cseip);
	case in_CVTTSS2SI_d_rm_reg_reg_u32_rm_mod_xmm_f128:
		return handler_CVTTSS2SI_d_rm_reg_reg_u32_rm_mod_xmm_f128(insb, cseip);
	case in_CVTTPD2PI_w_rm_reg_mmx_u64_rm_mod_xmm_d128:
		return handler_CVTTPD2PI_w_rm_reg_mmx_u64_rm_mod_xmm_d128(insb, cseip);
	case in_CVTTPD2PI_d_rm_reg_mmx_u64_rm_mod_xmm_d128:
		return handler_CVTTPD2PI_d_rm_reg_mmx_u64_rm_mod_xmm_d128(insb, cseip);
	case in_CVTTSD2SI_w_rm_reg_reg_u32_rm_mod_xmm_d128:
		return handler_CVTTSD2SI_w_rm_reg_reg_u32_rm_mod_xmm_d128(insb, cseip);
	case in_CVTTSD2SI_d_rm_reg_reg_u32_rm_mod_xmm_d128:
		return handler_CVTTSD2SI_d_rm_reg_reg_u32_rm_mod_xmm_d128(insb, cseip);
	case in_CVTPS2PI_w_rm_reg_mmx_u64_rm_mod_xmm_f64:
		return handler_CVTPS2PI_w_rm_reg_mmx_u64_rm_mod_xmm_f64(insb, cseip);
	case in_CVTPS2PI_d_rm_reg_mmx_u64_rm_mod_xmm_f64:
		return handler_CVTPS2PI_d_rm_reg_mmx_u64_rm_mod_xmm_f64(insb, cseip);
	case in_CVTSS2SI_w_rm_reg_reg_u32_rm_mod_xmm_f128:
		return handler_CVTSS2SI_w_rm_reg_reg_u32_rm_mod_xmm_f128(insb, cseip);
	case in_CVTSS2SI_d_rm_reg_reg_u32_rm_mod_xmm_f128:
		return handler_CVTSS2SI_d_rm_reg_reg_u32_rm_mod_xmm_f128(insb, cseip);
	case in_CVTPD2PI_w_rm_reg_mmx_u64_rm_mod_xmm_d128:
		return handler_CVTPD2PI_w_rm_reg_mmx_u64_rm_mod_xmm_d128(insb, cseip);
	case in_CVTPD2PI_d_rm_reg_mmx_u64_rm_mod_xmm_d128:
		return handler_CVTPD2PI_d_rm_reg_mmx_u64_rm_mod_xmm_d128(insb, cseip);
	case in_CVTSD2SI_w_rm_reg_reg_u32_rm_mod_xmm_d128:
		return handler_CVTSD2SI_w_rm_reg_reg_u32_rm_mod_xmm_d128(insb, cseip);
	case in_CVTSD2SI_d_rm_reg_reg_u32_rm_mod_xmm_d128:
		return handler_CVTSD2SI_d_rm_reg_reg_u32_rm_mod_xmm_d128(insb, cseip);
	case in_UCOMISS_w_rm_mod_xmm_f128:
		return handler_UCOMISS_w_rm_mod_xmm_f128(insb, cseip);
	case in_UCOMISS_d_rm_mod_xmm_f128:
		return handler_UCOMISS_d_rm_mod_xmm_f128(insb, cseip);
	case in_UCOMISD_w_rm_mod_xmm_d128:
		return handler_UCOMISD_w_rm_mod_xmm_d128(insb, cseip);
	case in_UCOMISD_d_rm_mod_xmm_d128:
		return handler_UCOMISD_d_rm_mod_xmm_d128(insb, cseip);
	case in_COMISS_w_rm_mod_xmm_f128:
		return handler_COMISS_w_rm_mod_xmm_f128(insb, cseip);
	case in_COMISS_d_rm_mod_xmm_f128:
		return handler_COMISS_d_rm_mod_xmm_f128(insb, cseip);
	case in_COMISD_w_rm_mod_xmm_d128:
		return handler_COMISD_w_rm_mod_xmm_d128(insb, cseip);
	case in_COMISD_d_rm_mod_xmm_d128:
		return handler_COMISD_d_rm_mod_xmm_d128(insb, cseip);
	case in_WRMSR:
		return handler_WRMSR(insb, cseip);
	case in_RDTSC:
		return handler_RDTSC(insb, cseip);
	case in_RDMSR:
		return handler_RDMSR(insb, cseip);
	case in_RDPMC:
		return handler_RDPMC(insb, cseip);
	case in_SYSENTER:
		return handler_SYSENTER(insb, cseip);
	case in_PSHUFB_w_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PSHUFB_w_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PSHUFB_d_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PSHUFB_d_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PHADDW_w_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PHADDW_w_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PHADDW_d_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PHADDW_d_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PHADDD_w_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PHADDD_w_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PHADDD_d_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PHADDD_d_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PHADDSW_w_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PHADDSW_w_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PHADDSW_d_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PHADDSW_d_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PMADDUBSW_w_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PMADDUBSW_w_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PMADDUBSW_d_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PMADDUBSW_d_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PHSUBW_w_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PHSUBW_w_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PHSUBW_d_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PHSUBW_d_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PHSUBD_w_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PHSUBD_w_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PHSUBD_d_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PHSUBD_d_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PHSUBSW_w_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PHSUBSW_w_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PHSUBSW_d_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PHSUBSW_d_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PSIGNB_w_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PSIGNB_w_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PSIGNB_d_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PSIGNB_d_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PSIGNW_w_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PSIGNW_w_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PSIGNW_d_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PSIGNW_d_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PSIGND_w_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PSIGND_w_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PSIGND_d_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PSIGND_d_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PMULHRSW_w_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PMULHRSW_w_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PMULHRSW_d_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PMULHRSW_d_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PABSB_w_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PABSB_w_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PABSB_d_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PABSB_d_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PABSW_w_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PABSW_w_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PABSW_d_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PABSW_d_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PABSD_w_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PABSD_w_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PABSD_d_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PABSD_d_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_MOVBE_w_rm_reg_reg_u16_rm_mem_u16:
		return handler_MOVBE_w_rm_reg_reg_u16_rm_mem_u16(insb, cseip);
	case in_MOVBE_d_rm_reg_reg_u16_rm_mem_u16:
		return handler_MOVBE_d_rm_reg_reg_u16_rm_mem_u16(insb, cseip);
	case in_MOVBE_w_rm_mem_u16_rm_reg_reg_u16:
		return handler_MOVBE_w_rm_mem_u16_rm_reg_reg_u16(insb, cseip);
	case in_MOVBE_d_rm_mem_u16_rm_reg_reg_u16:
		return handler_MOVBE_d_rm_mem_u16_rm_reg_reg_u16(insb, cseip);
	case in_PALIGNR_w_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PALIGNR_w_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PALIGNR_d_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PALIGNR_d_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_MOVMSKPS_w_rm_reg_reg_u32_rm_rm_xmm_f128:
		return handler_MOVMSKPS_w_rm_reg_reg_u32_rm_rm_xmm_f128(insb, cseip);
	case in_MOVMSKPS_d_rm_reg_reg_u32_rm_rm_xmm_f128:
		return handler_MOVMSKPS_d_rm_reg_reg_u32_rm_rm_xmm_f128(insb, cseip);
	case in_MOVMSKPD_w_rm_reg_reg_u32_rm_rm_xmm_d128:
		return handler_MOVMSKPD_w_rm_reg_reg_u32_rm_rm_xmm_d128(insb, cseip);
	case in_MOVMSKPD_d_rm_reg_reg_u32_rm_rm_xmm_d128:
		return handler_MOVMSKPD_d_rm_reg_reg_u32_rm_rm_xmm_d128(insb, cseip);
	case in_SQRTPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128:
		return handler_SQRTPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128(insb, cseip);
	case in_SQRTPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128:
		return handler_SQRTPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128(insb, cseip);
	case in_SQRTSS_w_rm_reg_xmm_f128_rm_mod_xmm_f128:
		return handler_SQRTSS_w_rm_reg_xmm_f128_rm_mod_xmm_f128(insb, cseip);
	case in_SQRTSS_d_rm_reg_xmm_f128_rm_mod_xmm_f128:
		return handler_SQRTSS_d_rm_reg_xmm_f128_rm_mod_xmm_f128(insb, cseip);
	case in_SQRTPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128:
		return handler_SQRTPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128(insb, cseip);
	case in_SQRTPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128:
		return handler_SQRTPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128(insb, cseip);
	case in_SQRTSD_w_rm_reg_xmm_d128_rm_mod_xmm_d128:
		return handler_SQRTSD_w_rm_reg_xmm_d128_rm_mod_xmm_d128(insb, cseip);
	case in_SQRTSD_d_rm_reg_xmm_d128_rm_mod_xmm_d128:
		return handler_SQRTSD_d_rm_reg_xmm_d128_rm_mod_xmm_d128(insb, cseip);
	case in_RSQRTPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128:
		return handler_RSQRTPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128(insb, cseip);
	case in_RSQRTPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128:
		return handler_RSQRTPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128(insb, cseip);
	case in_RSQRTSS_w_rm_reg_xmm_f128_rm_mod_xmm_f128:
		return handler_RSQRTSS_w_rm_reg_xmm_f128_rm_mod_xmm_f128(insb, cseip);
	case in_RSQRTSS_d_rm_reg_xmm_f128_rm_mod_xmm_f128:
		return handler_RSQRTSS_d_rm_reg_xmm_f128_rm_mod_xmm_f128(insb, cseip);
	case in_RCPPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128:
		return handler_RCPPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128(insb, cseip);
	case in_RCPPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128:
		return handler_RCPPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128(insb, cseip);
	case in_RCPSS_w_rm_reg_xmm_f128_rm_mod_xmm_f128:
		return handler_RCPSS_w_rm_reg_xmm_f128_rm_mod_xmm_f128(insb, cseip);
	case in_RCPSS_d_rm_reg_xmm_f128_rm_mod_xmm_f128:
		return handler_RCPSS_d_rm_reg_xmm_f128_rm_mod_xmm_f128(insb, cseip);
	case in_ANDPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128:
		return handler_ANDPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128(insb, cseip);
	case in_ANDPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128:
		return handler_ANDPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128(insb, cseip);
	case in_ANDPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128:
		return handler_ANDPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128(insb, cseip);
	case in_ANDPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128:
		return handler_ANDPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128(insb, cseip);
	case in_ANDNPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128:
		return handler_ANDNPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128(insb, cseip);
	case in_ANDNPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128:
		return handler_ANDNPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128(insb, cseip);
	case in_ANDNPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128:
		return handler_ANDNPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128(insb, cseip);
	case in_ANDNPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128:
		return handler_ANDNPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128(insb, cseip);
	case in_ORPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128:
		return handler_ORPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128(insb, cseip);
	case in_ORPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128:
		return handler_ORPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128(insb, cseip);
	case in_ORPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128:
		return handler_ORPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128(insb, cseip);
	case in_ORPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128:
		return handler_ORPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128(insb, cseip);
	case in_XORPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128:
		return handler_XORPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128(insb, cseip);
	case in_XORPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128:
		return handler_XORPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128(insb, cseip);
	case in_XORPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128:
		return handler_XORPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128(insb, cseip);
	case in_XORPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128:
		return handler_XORPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128(insb, cseip);
	case in_ADDPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128:
		return handler_ADDPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128(insb, cseip);
	case in_ADDPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128:
		return handler_ADDPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128(insb, cseip);
	case in_ADDSS_w_rm_reg_xmm_f128_rm_mod_xmm_f128:
		return handler_ADDSS_w_rm_reg_xmm_f128_rm_mod_xmm_f128(insb, cseip);
	case in_ADDSS_d_rm_reg_xmm_f128_rm_mod_xmm_f128:
		return handler_ADDSS_d_rm_reg_xmm_f128_rm_mod_xmm_f128(insb, cseip);
	case in_ADDPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128:
		return handler_ADDPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128(insb, cseip);
	case in_ADDPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128:
		return handler_ADDPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128(insb, cseip);
	case in_ADDSD_w_rm_reg_xmm_d128_rm_mod_xmm_d128:
		return handler_ADDSD_w_rm_reg_xmm_d128_rm_mod_xmm_d128(insb, cseip);
	case in_ADDSD_d_rm_reg_xmm_d128_rm_mod_xmm_d128:
		return handler_ADDSD_d_rm_reg_xmm_d128_rm_mod_xmm_d128(insb, cseip);
	case in_MULPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128:
		return handler_MULPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128(insb, cseip);
	case in_MULPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128:
		return handler_MULPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128(insb, cseip);
	case in_MULSS_w_rm_reg_xmm_f128_rm_mod_xmm_f128:
		return handler_MULSS_w_rm_reg_xmm_f128_rm_mod_xmm_f128(insb, cseip);
	case in_MULSS_d_rm_reg_xmm_f128_rm_mod_xmm_f128:
		return handler_MULSS_d_rm_reg_xmm_f128_rm_mod_xmm_f128(insb, cseip);
	case in_MULPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128:
		return handler_MULPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128(insb, cseip);
	case in_MULPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128:
		return handler_MULPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128(insb, cseip);
	case in_MULSD_w_rm_reg_xmm_d128_rm_mod_xmm_d128:
		return handler_MULSD_w_rm_reg_xmm_d128_rm_mod_xmm_d128(insb, cseip);
	case in_MULSD_d_rm_reg_xmm_d128_rm_mod_xmm_d128:
		return handler_MULSD_d_rm_reg_xmm_d128_rm_mod_xmm_d128(insb, cseip);
	case in_CVTPS2PD_w_rm_reg_xmm_d128_rm_mod_xmm_f128:
		return handler_CVTPS2PD_w_rm_reg_xmm_d128_rm_mod_xmm_f128(insb, cseip);
	case in_CVTPS2PD_d_rm_reg_xmm_d128_rm_mod_xmm_f128:
		return handler_CVTPS2PD_d_rm_reg_xmm_d128_rm_mod_xmm_f128(insb, cseip);
	case in_CVTPD2PS_w_rm_reg_xmm_f128_rm_mod_xmm_d128:
		return handler_CVTPD2PS_w_rm_reg_xmm_f128_rm_mod_xmm_d128(insb, cseip);
	case in_CVTPD2PS_d_rm_reg_xmm_f128_rm_mod_xmm_d128:
		return handler_CVTPD2PS_d_rm_reg_xmm_f128_rm_mod_xmm_d128(insb, cseip);
	case in_CVTSS2SD_w_rm_reg_xmm_d128_rm_mod_xmm_f128:
		return handler_CVTSS2SD_w_rm_reg_xmm_d128_rm_mod_xmm_f128(insb, cseip);
	case in_CVTSS2SD_d_rm_reg_xmm_d128_rm_mod_xmm_f128:
		return handler_CVTSS2SD_d_rm_reg_xmm_d128_rm_mod_xmm_f128(insb, cseip);
	case in_CVTSD2SS_w_rm_reg_xmm_f128_rm_mod_xmm_d128:
		return handler_CVTSD2SS_w_rm_reg_xmm_f128_rm_mod_xmm_d128(insb, cseip);
	case in_CVTSD2SS_d_rm_reg_xmm_f128_rm_mod_xmm_d128:
		return handler_CVTSD2SS_d_rm_reg_xmm_f128_rm_mod_xmm_d128(insb, cseip);
	case in_CVTDQ2PS_w_rm_reg_xmm_f128_rm_mod_xmm_u128:
		return handler_CVTDQ2PS_w_rm_reg_xmm_f128_rm_mod_xmm_u128(insb, cseip);
	case in_CVTDQ2PS_d_rm_reg_xmm_f128_rm_mod_xmm_u128:
		return handler_CVTDQ2PS_d_rm_reg_xmm_f128_rm_mod_xmm_u128(insb, cseip);
	case in_CVTPS2DQ_w_rm_reg_xmm_u128_rm_mod_xmm_f128:
		return handler_CVTPS2DQ_w_rm_reg_xmm_u128_rm_mod_xmm_f128(insb, cseip);
	case in_CVTPS2DQ_d_rm_reg_xmm_u128_rm_mod_xmm_f128:
		return handler_CVTPS2DQ_d_rm_reg_xmm_u128_rm_mod_xmm_f128(insb, cseip);
	case in_CVTTPS2DQ_w_rm_reg_xmm_u128_rm_mod_xmm_f128:
		return handler_CVTTPS2DQ_w_rm_reg_xmm_u128_rm_mod_xmm_f128(insb, cseip);
	case in_CVTTPS2DQ_d_rm_reg_xmm_u128_rm_mod_xmm_f128:
		return handler_CVTTPS2DQ_d_rm_reg_xmm_u128_rm_mod_xmm_f128(insb, cseip);
	case in_SUBPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128:
		return handler_SUBPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128(insb, cseip);
	case in_SUBPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128:
		return handler_SUBPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128(insb, cseip);
	case in_SUBSS_w_rm_reg_xmm_f128_rm_mod_xmm_f128:
		return handler_SUBSS_w_rm_reg_xmm_f128_rm_mod_xmm_f128(insb, cseip);
	case in_SUBSS_d_rm_reg_xmm_f128_rm_mod_xmm_f128:
		return handler_SUBSS_d_rm_reg_xmm_f128_rm_mod_xmm_f128(insb, cseip);
	case in_SUBPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128:
		return handler_SUBPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128(insb, cseip);
	case in_SUBPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128:
		return handler_SUBPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128(insb, cseip);
	case in_SUBSD_w_rm_reg_xmm_d128_rm_mod_xmm_d128:
		return handler_SUBSD_w_rm_reg_xmm_d128_rm_mod_xmm_d128(insb, cseip);
	case in_SUBSD_d_rm_reg_xmm_d128_rm_mod_xmm_d128:
		return handler_SUBSD_d_rm_reg_xmm_d128_rm_mod_xmm_d128(insb, cseip);
	case in_MINPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128:
		return handler_MINPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128(insb, cseip);
	case in_MINPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128:
		return handler_MINPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128(insb, cseip);
	case in_MINSS_w_rm_reg_xmm_f128_rm_mod_xmm_f128:
		return handler_MINSS_w_rm_reg_xmm_f128_rm_mod_xmm_f128(insb, cseip);
	case in_MINSS_d_rm_reg_xmm_f128_rm_mod_xmm_f128:
		return handler_MINSS_d_rm_reg_xmm_f128_rm_mod_xmm_f128(insb, cseip);
	case in_MINPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128:
		return handler_MINPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128(insb, cseip);
	case in_MINPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128:
		return handler_MINPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128(insb, cseip);
	case in_MINSD_w_rm_reg_xmm_d128_rm_mod_xmm_d128:
		return handler_MINSD_w_rm_reg_xmm_d128_rm_mod_xmm_d128(insb, cseip);
	case in_MINSD_d_rm_reg_xmm_d128_rm_mod_xmm_d128:
		return handler_MINSD_d_rm_reg_xmm_d128_rm_mod_xmm_d128(insb, cseip);
	case in_DIVPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128:
		return handler_DIVPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128(insb, cseip);
	case in_DIVPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128:
		return handler_DIVPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128(insb, cseip);
	case in_DIVSS_w_rm_reg_xmm_f128_rm_mod_xmm_f128:
		return handler_DIVSS_w_rm_reg_xmm_f128_rm_mod_xmm_f128(insb, cseip);
	case in_DIVSS_d_rm_reg_xmm_f128_rm_mod_xmm_f128:
		return handler_DIVSS_d_rm_reg_xmm_f128_rm_mod_xmm_f128(insb, cseip);
	case in_DIVPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128:
		return handler_DIVPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128(insb, cseip);
	case in_DIVPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128:
		return handler_DIVPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128(insb, cseip);
	case in_DIVSD_w_rm_reg_xmm_d128_rm_mod_xmm_d128:
		return handler_DIVSD_w_rm_reg_xmm_d128_rm_mod_xmm_d128(insb, cseip);
	case in_DIVSD_d_rm_reg_xmm_d128_rm_mod_xmm_d128:
		return handler_DIVSD_d_rm_reg_xmm_d128_rm_mod_xmm_d128(insb, cseip);
	case in_MAXPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128:
		return handler_MAXPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128(insb, cseip);
	case in_MAXPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128:
		return handler_MAXPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128(insb, cseip);
	case in_MAXSS_w_rm_reg_xmm_f128_rm_mod_xmm_f128:
		return handler_MAXSS_w_rm_reg_xmm_f128_rm_mod_xmm_f128(insb, cseip);
	case in_MAXSS_d_rm_reg_xmm_f128_rm_mod_xmm_f128:
		return handler_MAXSS_d_rm_reg_xmm_f128_rm_mod_xmm_f128(insb, cseip);
	case in_MAXPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128:
		return handler_MAXPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128(insb, cseip);
	case in_MAXPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128:
		return handler_MAXPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128(insb, cseip);
	case in_MAXSD_w_rm_reg_xmm_d128_rm_mod_xmm_d128:
		return handler_MAXSD_w_rm_reg_xmm_d128_rm_mod_xmm_d128(insb, cseip);
	case in_MAXSD_d_rm_reg_xmm_d128_rm_mod_xmm_d128:
		return handler_MAXSD_d_rm_reg_xmm_d128_rm_mod_xmm_d128(insb, cseip);
	case in_PUNPCKLBW_w_rm_reg_mmx_u64_rm_mod_mmx_u32:
		return handler_PUNPCKLBW_w_rm_reg_mmx_u64_rm_mod_mmx_u32(insb, cseip);
	case in_PUNPCKLBW_d_rm_reg_mmx_u64_rm_mod_mmx_u32:
		return handler_PUNPCKLBW_d_rm_reg_mmx_u64_rm_mod_mmx_u32(insb, cseip);
	case in_PUNPCKLWD_w_rm_reg_mmx_u64_rm_mod_mmx_u32:
		return handler_PUNPCKLWD_w_rm_reg_mmx_u64_rm_mod_mmx_u32(insb, cseip);
	case in_PUNPCKLWD_d_rm_reg_mmx_u64_rm_mod_mmx_u32:
		return handler_PUNPCKLWD_d_rm_reg_mmx_u64_rm_mod_mmx_u32(insb, cseip);
	case in_PUNPCKLDQ_w_rm_reg_mmx_u64_rm_mod_mmx_u32:
		return handler_PUNPCKLDQ_w_rm_reg_mmx_u64_rm_mod_mmx_u32(insb, cseip);
	case in_PUNPCKLDQ_d_rm_reg_mmx_u64_rm_mod_mmx_u32:
		return handler_PUNPCKLDQ_d_rm_reg_mmx_u64_rm_mod_mmx_u32(insb, cseip);
	case in_PACKSSWB_w_rm_reg_mmx_u64_rm_mod_mmx_u32:
		return handler_PACKSSWB_w_rm_reg_mmx_u64_rm_mod_mmx_u32(insb, cseip);
	case in_PACKSSWB_d_rm_reg_mmx_u64_rm_mod_mmx_u32:
		return handler_PACKSSWB_d_rm_reg_mmx_u64_rm_mod_mmx_u32(insb, cseip);
	case in_PCMPGTB_w_rm_reg_mmx_u64_rm_mod_mmx_u32:
		return handler_PCMPGTB_w_rm_reg_mmx_u64_rm_mod_mmx_u32(insb, cseip);
	case in_PCMPGTB_d_rm_reg_mmx_u64_rm_mod_mmx_u32:
		return handler_PCMPGTB_d_rm_reg_mmx_u64_rm_mod_mmx_u32(insb, cseip);
	case in_PCMPGTW_w_rm_reg_mmx_u64_rm_mod_mmx_u32:
		return handler_PCMPGTW_w_rm_reg_mmx_u64_rm_mod_mmx_u32(insb, cseip);
	case in_PCMPGTW_d_rm_reg_mmx_u64_rm_mod_mmx_u32:
		return handler_PCMPGTW_d_rm_reg_mmx_u64_rm_mod_mmx_u32(insb, cseip);
	case in_PCMPGTD_w_rm_reg_mmx_u64_rm_mod_mmx_u32:
		return handler_PCMPGTD_w_rm_reg_mmx_u64_rm_mod_mmx_u32(insb, cseip);
	case in_PCMPGTD_d_rm_reg_mmx_u64_rm_mod_mmx_u32:
		return handler_PCMPGTD_d_rm_reg_mmx_u64_rm_mod_mmx_u32(insb, cseip);
	case in_PACKUSWB_w_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PACKUSWB_w_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PACKUSWB_d_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PACKUSWB_d_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PUNPCKHBW_w_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PUNPCKHBW_w_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PUNPCKHBW_d_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PUNPCKHBW_d_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PUNPCKHWD_w_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PUNPCKHWD_w_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PUNPCKHWD_d_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PUNPCKHWD_d_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PUNPCKHDQ_w_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PUNPCKHDQ_w_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PUNPCKHDQ_d_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PUNPCKHDQ_d_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PACKSSDW_w_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PACKSSDW_w_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PACKSSDW_d_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PACKSSDW_d_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PUNPCKLQDQ_w_rm_reg_xmm_u128_rm_mod_xmm_u128:
		return handler_PUNPCKLQDQ_w_rm_reg_xmm_u128_rm_mod_xmm_u128(insb, cseip);
	case in_PUNPCKLQDQ_d_rm_reg_xmm_u128_rm_mod_xmm_u128:
		return handler_PUNPCKLQDQ_d_rm_reg_xmm_u128_rm_mod_xmm_u128(insb, cseip);
	case in_PUNPCKHQDQ_w_rm_reg_xmm_u128_rm_mod_xmm_u128:
		return handler_PUNPCKHQDQ_w_rm_reg_xmm_u128_rm_mod_xmm_u128(insb, cseip);
	case in_PUNPCKHQDQ_d_rm_reg_xmm_u128_rm_mod_xmm_u128:
		return handler_PUNPCKHQDQ_d_rm_reg_xmm_u128_rm_mod_xmm_u128(insb, cseip);
	case in_MOVD_w_rm_reg_mmx_u64_rm_mod_reg_u32:
		return handler_MOVD_w_rm_reg_mmx_u64_rm_mod_reg_u32(insb, cseip);
	case in_MOVD_d_rm_reg_mmx_u64_rm_mod_reg_u32:
		return handler_MOVD_d_rm_reg_mmx_u64_rm_mod_reg_u32(insb, cseip);
	case in_MOVQ_w_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_MOVQ_w_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_MOVQ_d_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_MOVQ_d_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_MOVDQA_w_rm_reg_xmm_u128_rm_mod_xmm_u128:
		return handler_MOVDQA_w_rm_reg_xmm_u128_rm_mod_xmm_u128(insb, cseip);
	case in_MOVDQA_d_rm_reg_xmm_u128_rm_mod_xmm_u128:
		return handler_MOVDQA_d_rm_reg_xmm_u128_rm_mod_xmm_u128(insb, cseip);
	case in_MOVDQU_w_rm_reg_xmm_u128_rm_mod_xmm_u128:
		return handler_MOVDQU_w_rm_reg_xmm_u128_rm_mod_xmm_u128(insb, cseip);
	case in_MOVDQU_d_rm_reg_xmm_u128_rm_mod_xmm_u128:
		return handler_MOVDQU_d_rm_reg_xmm_u128_rm_mod_xmm_u128(insb, cseip);
	case in_PSHUFW_w_rm_reg_mmx_u64_imm_u8:
		return handler_PSHUFW_w_rm_reg_mmx_u64_imm_u8(insb, cseip);
	case in_PSHUFW_d_rm_reg_mmx_u64_imm_u8:
		return handler_PSHUFW_d_rm_reg_mmx_u64_imm_u8(insb, cseip);
	case in_PSHUFLW_w_rm_reg_xmm_u128_imm_u8:
		return handler_PSHUFLW_w_rm_reg_xmm_u128_imm_u8(insb, cseip);
	case in_PSHUFLW_d_rm_reg_xmm_u128_imm_u8:
		return handler_PSHUFLW_d_rm_reg_xmm_u128_imm_u8(insb, cseip);
	case in_PSHUFHW_w_rm_reg_xmm_u128_imm_u8:
		return handler_PSHUFHW_w_rm_reg_xmm_u128_imm_u8(insb, cseip);
	case in_PSHUFHW_d_rm_reg_xmm_u128_imm_u8:
		return handler_PSHUFHW_d_rm_reg_xmm_u128_imm_u8(insb, cseip);
	case in_PSHUFD_w_rm_reg_xmm_u128_imm_u8:
		return handler_PSHUFD_w_rm_reg_xmm_u128_imm_u8(insb, cseip);
	case in_PSHUFD_d_rm_reg_xmm_u128_imm_u8:
		return handler_PSHUFD_d_rm_reg_xmm_u128_imm_u8(insb, cseip);
	case in_PSRLW_w_rm_rm_mmx_u64_imm_u8:
		return handler_PSRLW_w_rm_rm_mmx_u64_imm_u8(insb, cseip);
	case in_PSRLW_d_rm_rm_mmx_u64_imm_u8:
		return handler_PSRLW_d_rm_rm_mmx_u64_imm_u8(insb, cseip);
	case in_PSRAW_w_rm_rm_mmx_u64_imm_u8:
		return handler_PSRAW_w_rm_rm_mmx_u64_imm_u8(insb, cseip);
	case in_PSRAW_d_rm_rm_mmx_u64_imm_u8:
		return handler_PSRAW_d_rm_rm_mmx_u64_imm_u8(insb, cseip);
	case in_PSLLW_w_rm_rm_mmx_u64_imm_u8:
		return handler_PSLLW_w_rm_rm_mmx_u64_imm_u8(insb, cseip);
	case in_PSLLW_d_rm_rm_mmx_u64_imm_u8:
		return handler_PSLLW_d_rm_rm_mmx_u64_imm_u8(insb, cseip);
	case in_PSRLD_w_rm_rm_mmx_u64_imm_u8:
		return handler_PSRLD_w_rm_rm_mmx_u64_imm_u8(insb, cseip);
	case in_PSRLD_d_rm_rm_mmx_u64_imm_u8:
		return handler_PSRLD_d_rm_rm_mmx_u64_imm_u8(insb, cseip);
	case in_PSRAD_w_rm_rm_mmx_u64_imm_u8:
		return handler_PSRAD_w_rm_rm_mmx_u64_imm_u8(insb, cseip);
	case in_PSRAD_d_rm_rm_mmx_u64_imm_u8:
		return handler_PSRAD_d_rm_rm_mmx_u64_imm_u8(insb, cseip);
	case in_PSLLD_w_rm_rm_mmx_u64_imm_u8:
		return handler_PSLLD_w_rm_rm_mmx_u64_imm_u8(insb, cseip);
	case in_PSLLD_d_rm_rm_mmx_u64_imm_u8:
		return handler_PSLLD_d_rm_rm_mmx_u64_imm_u8(insb, cseip);
	case in_PSRLQ_w_rm_rm_mmx_u64_imm_u8:
		return handler_PSRLQ_w_rm_rm_mmx_u64_imm_u8(insb, cseip);
	case in_PSRLQ_d_rm_rm_mmx_u64_imm_u8:
		return handler_PSRLQ_d_rm_rm_mmx_u64_imm_u8(insb, cseip);
	case in_PSRLDQ_w_rm_rm_xmm_u128_imm_u8:
		return handler_PSRLDQ_w_rm_rm_xmm_u128_imm_u8(insb, cseip);
	case in_PSRLDQ_d_rm_rm_xmm_u128_imm_u8:
		return handler_PSRLDQ_d_rm_rm_xmm_u128_imm_u8(insb, cseip);
	case in_PSLLQ_w_rm_rm_mmx_u64_imm_u8:
		return handler_PSLLQ_w_rm_rm_mmx_u64_imm_u8(insb, cseip);
	case in_PSLLQ_d_rm_rm_mmx_u64_imm_u8:
		return handler_PSLLQ_d_rm_rm_mmx_u64_imm_u8(insb, cseip);
	case in_PSLLDQ_w_rm_rm_xmm_u128_imm_u8:
		return handler_PSLLDQ_w_rm_rm_xmm_u128_imm_u8(insb, cseip);
	case in_PSLLDQ_d_rm_rm_xmm_u128_imm_u8:
		return handler_PSLLDQ_d_rm_rm_xmm_u128_imm_u8(insb, cseip);
	case in_PCMPEQB_w_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PCMPEQB_w_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PCMPEQB_d_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PCMPEQB_d_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PCMPEQW_w_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PCMPEQW_w_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PCMPEQW_d_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PCMPEQW_d_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PCMPEQD_w_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PCMPEQD_w_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PCMPEQD_d_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PCMPEQD_d_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_EMMS:
		return handler_EMMS(insb, cseip);
	case in_HADDPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128:
		return handler_HADDPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128(insb, cseip);
	case in_HADDPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128:
		return handler_HADDPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128(insb, cseip);
	case in_HADDPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128:
		return handler_HADDPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128(insb, cseip);
	case in_HADDPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128:
		return handler_HADDPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128(insb, cseip);
	case in_HSUBPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128:
		return handler_HSUBPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128(insb, cseip);
	case in_HSUBPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128:
		return handler_HSUBPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128(insb, cseip);
	case in_HSUBPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128:
		return handler_HSUBPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128(insb, cseip);
	case in_HSUBPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128:
		return handler_HSUBPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128(insb, cseip);
	case in_MOVD_w_rm_mod_reg_u32_rm_reg_mmx_u64:
		return handler_MOVD_w_rm_mod_reg_u32_rm_reg_mmx_u64(insb, cseip);
	case in_MOVD_d_rm_mod_reg_u32_rm_reg_mmx_u64:
		return handler_MOVD_d_rm_mod_reg_u32_rm_reg_mmx_u64(insb, cseip);
	case in_MOVQ_w_rm_reg_xmm_u64_rm_mod_xmm_u64:
		return handler_MOVQ_w_rm_reg_xmm_u64_rm_mod_xmm_u64(insb, cseip);
	case in_MOVQ_d_rm_reg_xmm_u64_rm_mod_xmm_u64:
		return handler_MOVQ_d_rm_reg_xmm_u64_rm_mod_xmm_u64(insb, cseip);
	case in_MOVQ_w_rm_mod_mmx_u64_rm_reg_mmx_u64:
		return handler_MOVQ_w_rm_mod_mmx_u64_rm_reg_mmx_u64(insb, cseip);
	case in_MOVQ_d_rm_mod_mmx_u64_rm_reg_mmx_u64:
		return handler_MOVQ_d_rm_mod_mmx_u64_rm_reg_mmx_u64(insb, cseip);
	case in_MOVDQA_w_rm_mod_xmm_u128_rm_reg_xmm_u128:
		return handler_MOVDQA_w_rm_mod_xmm_u128_rm_reg_xmm_u128(insb, cseip);
	case in_MOVDQA_d_rm_mod_xmm_u128_rm_reg_xmm_u128:
		return handler_MOVDQA_d_rm_mod_xmm_u128_rm_reg_xmm_u128(insb, cseip);
	case in_MOVDQU_w_rm_mod_xmm_u128_rm_reg_xmm_u128:
		return handler_MOVDQU_w_rm_mod_xmm_u128_rm_reg_xmm_u128(insb, cseip);
	case in_MOVDQU_d_rm_mod_xmm_u128_rm_reg_xmm_u128:
		return handler_MOVDQU_d_rm_mod_xmm_u128_rm_reg_xmm_u128(insb, cseip);
	case in_PUSH_reg_seg_4_u16:
		return handler_PUSH_reg_seg_4_u16(insb, cseip);
	case in_POP_reg_seg_4_u16:
		return handler_POP_reg_seg_4_u16(insb, cseip);
	case in_CPUID:
		return handler_CPUID(insb, cseip);
	case in_BT_w_rm_reg_reg_u16:
		return handler_BT_w_rm_reg_reg_u16(insb, cseip);
	case in_BT_d_rm_reg_reg_u16:
		return handler_BT_d_rm_reg_reg_u16(insb, cseip);
	case in_SHLD_w_rm_mod_reg_u16_imm_u8:
		return handler_SHLD_w_rm_mod_reg_u16_imm_u8(insb, cseip);
	case in_SHLD_d_rm_mod_reg_u16_imm_u8:
		return handler_SHLD_d_rm_mod_reg_u16_imm_u8(insb, cseip);
	case in_SHLD_w_rm_mod_reg_u16_reg_gen_1_u8:
		return handler_SHLD_w_rm_mod_reg_u16_reg_gen_1_u8(insb, cseip);
	case in_SHLD_d_rm_mod_reg_u16_reg_gen_1_u8:
		return handler_SHLD_d_rm_mod_reg_u16_reg_gen_1_u8(insb, cseip);
	case in_PUSH_reg_seg_5_u16:
		return handler_PUSH_reg_seg_5_u16(insb, cseip);
	case in_POP_reg_seg_5_u16:
		return handler_POP_reg_seg_5_u16(insb, cseip);
	case in_RSM:
		return handler_RSM(insb, cseip);
	case in_BTS_w_rm_mod_reg_u16_rm_reg_reg_u16:
		return handler_BTS_w_rm_mod_reg_u16_rm_reg_reg_u16(insb, cseip);
	case in_BTS_d_rm_mod_reg_u16_rm_reg_reg_u16:
		return handler_BTS_d_rm_mod_reg_u16_rm_reg_reg_u16(insb, cseip);
	case in_SHRD_w_rm_mod_reg_u16_imm_u8:
		return handler_SHRD_w_rm_mod_reg_u16_imm_u8(insb, cseip);
	case in_SHRD_d_rm_mod_reg_u16_imm_u8:
		return handler_SHRD_d_rm_mod_reg_u16_imm_u8(insb, cseip);
	case in_SHRD_w_rm_mod_reg_u16_reg_gen_1_u8:
		return handler_SHRD_w_rm_mod_reg_u16_reg_gen_1_u8(insb, cseip);
	case in_SHRD_d_rm_mod_reg_u16_reg_gen_1_u8:
		return handler_SHRD_d_rm_mod_reg_u16_reg_gen_1_u8(insb, cseip);
	case in_FXSAVE_w:
		return handler_FXSAVE_w(insb, cseip);
	case in_FXSAVE_d:
		return handler_FXSAVE_d(insb, cseip);
	case in_FXRSTOR_w:
		return handler_FXRSTOR_w(insb, cseip);
	case in_FXRSTOR_d:
		return handler_FXRSTOR_d(insb, cseip);
	case in_LDMXCSR_w_rm_mem_u32:
		return handler_LDMXCSR_w_rm_mem_u32(insb, cseip);
	case in_LDMXCSR_d_rm_mem_u32:
		return handler_LDMXCSR_d_rm_mem_u32(insb, cseip);
	case in_STMXCSR_w_rm_mem_u32:
		return handler_STMXCSR_w_rm_mem_u32(insb, cseip);
	case in_STMXCSR_d_rm_mem_u32:
		return handler_STMXCSR_d_rm_mem_u32(insb, cseip);
	case in_XSAVE:
		return handler_XSAVE(insb, cseip);
	case in_LFENCE:
		return handler_LFENCE(insb, cseip);
	case in_XRSTOR:
		return handler_XRSTOR(insb, cseip);
	case in_MFENCE:
		return handler_MFENCE(insb, cseip);
	case in_SFENCE:
		return handler_SFENCE(insb, cseip);
	case in_CLFLUSH_w_rm_mem_u8:
		return handler_CLFLUSH_w_rm_mem_u8(insb, cseip);
	case in_CLFLUSH_d_rm_mem_u8:
		return handler_CLFLUSH_d_rm_mem_u8(insb, cseip);
	case in_IMUL_w_rm_reg_reg_u16_rm_mod_reg_u16:
		return handler_IMUL_w_rm_reg_reg_u16_rm_mod_reg_u16(insb, cseip);
	case in_IMUL_w_rm_reg_reg_u32_rm_mod_reg_u32:
		return handler_IMUL_w_rm_reg_reg_u32_rm_mod_reg_u32(insb, cseip);
	case in_IMUL_d_rm_reg_reg_u16_rm_mod_reg_u16:
		return handler_IMUL_d_rm_reg_reg_u16_rm_mod_reg_u16(insb, cseip);
	case in_IMUL_d_rm_reg_reg_u32_rm_mod_reg_u32:
		return handler_IMUL_d_rm_reg_reg_u32_rm_mod_reg_u32(insb, cseip);
	case in_BTR_w_rm_mod_reg_u16_rm_reg_reg_u16:
		return handler_BTR_w_rm_mod_reg_u16_rm_reg_reg_u16(insb, cseip);
	case in_BTR_d_rm_mod_reg_u16_rm_reg_reg_u16:
		return handler_BTR_d_rm_mod_reg_u16_rm_reg_reg_u16(insb, cseip);
	case in_MOVZX_w_rm_reg_reg_u16_rm_mod_reg_u8:
		return handler_MOVZX_w_rm_reg_reg_u16_rm_mod_reg_u8(insb, cseip);
	case in_MOVZX_d_rm_reg_reg_u16_rm_mod_reg_u8:
		return handler_MOVZX_d_rm_reg_reg_u16_rm_mod_reg_u8(insb, cseip);
	case in_MOVZX_w_rm_reg_reg_u16_rm_mod_reg_u16:
		return handler_MOVZX_w_rm_reg_reg_u16_rm_mod_reg_u16(insb, cseip);
	case in_MOVZX_w_rm_reg_reg_u32_rm_mod_reg_u16:
		return handler_MOVZX_w_rm_reg_reg_u32_rm_mod_reg_u16(insb, cseip);
	case in_MOVZX_d_rm_reg_reg_u16_rm_mod_reg_u16:
		return handler_MOVZX_d_rm_reg_reg_u16_rm_mod_reg_u16(insb, cseip);
	case in_MOVZX_d_rm_reg_reg_u32_rm_mod_reg_u16:
		return handler_MOVZX_d_rm_reg_reg_u32_rm_mod_reg_u16(insb, cseip);
	case in_POPCNT_w_rm_reg_reg_u16_rm_mod_reg_u16:
		return handler_POPCNT_w_rm_reg_reg_u16_rm_mod_reg_u16(insb, cseip);
	case in_POPCNT_d_rm_reg_reg_u16_rm_mod_reg_u16:
		return handler_POPCNT_d_rm_reg_reg_u16_rm_mod_reg_u16(insb, cseip);
	case in_BT_w_imm_u8:
		return handler_BT_w_imm_u8(insb, cseip);
	case in_BT_d_imm_u8:
		return handler_BT_d_imm_u8(insb, cseip);
	case in_BTS_w_rm_mod_reg_u16_imm_u8:
		return handler_BTS_w_rm_mod_reg_u16_imm_u8(insb, cseip);
	case in_BTS_d_rm_mod_reg_u16_imm_u8:
		return handler_BTS_d_rm_mod_reg_u16_imm_u8(insb, cseip);
	case in_BTR_w_rm_mod_reg_u16_imm_u8:
		return handler_BTR_w_rm_mod_reg_u16_imm_u8(insb, cseip);
	case in_BTR_d_rm_mod_reg_u16_imm_u8:
		return handler_BTR_d_rm_mod_reg_u16_imm_u8(insb, cseip);
	case in_BTC_w_rm_mod_reg_u16_imm_u8:
		return handler_BTC_w_rm_mod_reg_u16_imm_u8(insb, cseip);
	case in_BTC_d_rm_mod_reg_u16_imm_u8:
		return handler_BTC_d_rm_mod_reg_u16_imm_u8(insb, cseip);
	case in_BTC_w_rm_mod_reg_u16_rm_reg_reg_u16:
		return handler_BTC_w_rm_mod_reg_u16_rm_reg_reg_u16(insb, cseip);
	case in_BTC_d_rm_mod_reg_u16_rm_reg_reg_u16:
		return handler_BTC_d_rm_mod_reg_u16_rm_reg_reg_u16(insb, cseip);
	case in_MOVSX_w_rm_reg_reg_u16_rm_mod_reg_u8:
		return handler_MOVSX_w_rm_reg_reg_u16_rm_mod_reg_u8(insb, cseip);
	case in_MOVSX_d_rm_reg_reg_u16_rm_mod_reg_u8:
		return handler_MOVSX_d_rm_reg_reg_u16_rm_mod_reg_u8(insb, cseip);
	case in_MOVSX_w_rm_reg_reg_u16_rm_mod_reg_u16:
		return handler_MOVSX_w_rm_reg_reg_u16_rm_mod_reg_u16(insb, cseip);
	case in_MOVSX_w_rm_reg_reg_u32_rm_mod_reg_u16:
		return handler_MOVSX_w_rm_reg_reg_u32_rm_mod_reg_u16(insb, cseip);
	case in_MOVSX_d_rm_reg_reg_u16_rm_mod_reg_u16:
		return handler_MOVSX_d_rm_reg_reg_u16_rm_mod_reg_u16(insb, cseip);
	case in_MOVSX_d_rm_reg_reg_u32_rm_mod_reg_u16:
		return handler_MOVSX_d_rm_reg_reg_u32_rm_mod_reg_u16(insb, cseip);
	case in_XADD_w_rm_reg_reg_u8:
		return handler_XADD_w_rm_reg_reg_u8(insb, cseip);
	case in_XADD_d_rm_reg_reg_u8:
		return handler_XADD_d_rm_reg_reg_u8(insb, cseip);
	case in_XADD_w_rm_reg_reg_u16:
		return handler_XADD_w_rm_reg_reg_u16(insb, cseip);
	case in_XADD_w_rm_reg_reg_u32:
		return handler_XADD_w_rm_reg_reg_u32(insb, cseip);
	case in_XADD_d_rm_reg_reg_u16:
		return handler_XADD_d_rm_reg_reg_u16(insb, cseip);
	case in_XADD_d_rm_reg_reg_u32:
		return handler_XADD_d_rm_reg_reg_u32(insb, cseip);
	case in_CMPPS_w_rm_reg_xmm_f128_imm_u8:
		return handler_CMPPS_w_rm_reg_xmm_f128_imm_u8(insb, cseip);
	case in_CMPPS_d_rm_reg_xmm_f128_imm_u8:
		return handler_CMPPS_d_rm_reg_xmm_f128_imm_u8(insb, cseip);
	case in_CMPSS_w_rm_reg_xmm_f128_imm_u8:
		return handler_CMPSS_w_rm_reg_xmm_f128_imm_u8(insb, cseip);
	case in_CMPSS_d_rm_reg_xmm_f128_imm_u8:
		return handler_CMPSS_d_rm_reg_xmm_f128_imm_u8(insb, cseip);
	case in_CMPPD_w_rm_reg_xmm_d128_imm_u8:
		return handler_CMPPD_w_rm_reg_xmm_d128_imm_u8(insb, cseip);
	case in_CMPPD_d_rm_reg_xmm_d128_imm_u8:
		return handler_CMPPD_d_rm_reg_xmm_d128_imm_u8(insb, cseip);
	case in_CMPSD_w_rm_reg_xmm_d128_imm_u8:
		return handler_CMPSD_w_rm_reg_xmm_d128_imm_u8(insb, cseip);
	case in_CMPSD_d_rm_reg_xmm_d128_imm_u8:
		return handler_CMPSD_d_rm_reg_xmm_d128_imm_u8(insb, cseip);
	case in_MOVNTI_w_rm_mem_u32_rm_reg_reg_u32:
		return handler_MOVNTI_w_rm_mem_u32_rm_reg_reg_u32(insb, cseip);
	case in_MOVNTI_d_rm_mem_u32_rm_reg_reg_u32:
		return handler_MOVNTI_d_rm_mem_u32_rm_reg_reg_u32(insb, cseip);
	case in_PINSRW_w_rm_reg_mmx_u64_imm_u8:
		return handler_PINSRW_w_rm_reg_mmx_u64_imm_u8(insb, cseip);
	case in_PINSRW_d_rm_reg_mmx_u64_imm_u8:
		return handler_PINSRW_d_rm_reg_mmx_u64_imm_u8(insb, cseip);
	case in_PEXTRW_w_rm_reg_reg_u32_imm_u8:
		return handler_PEXTRW_w_rm_reg_reg_u32_imm_u8(insb, cseip);
	case in_PEXTRW_d_rm_reg_reg_u32_imm_u8:
		return handler_PEXTRW_d_rm_reg_reg_u32_imm_u8(insb, cseip);
	case in_SHUFPS_w_rm_reg_xmm_f128_imm_u8:
		return handler_SHUFPS_w_rm_reg_xmm_f128_imm_u8(insb, cseip);
	case in_SHUFPS_d_rm_reg_xmm_f128_imm_u8:
		return handler_SHUFPS_d_rm_reg_xmm_f128_imm_u8(insb, cseip);
	case in_SHUFPD_w_rm_reg_xmm_d128_imm_u8:
		return handler_SHUFPD_w_rm_reg_xmm_d128_imm_u8(insb, cseip);
	case in_SHUFPD_d_rm_reg_xmm_d128_imm_u8:
		return handler_SHUFPD_d_rm_reg_xmm_d128_imm_u8(insb, cseip);
	case in_ADDSUBPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128:
		return handler_ADDSUBPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128(insb, cseip);
	case in_ADDSUBPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128:
		return handler_ADDSUBPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128(insb, cseip);
	case in_ADDSUBPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128:
		return handler_ADDSUBPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128(insb, cseip);
	case in_ADDSUBPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128:
		return handler_ADDSUBPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128(insb, cseip);
	case in_PSRLW_w_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PSRLW_w_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PSRLW_d_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PSRLW_d_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PSRLD_w_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PSRLD_w_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PSRLD_d_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PSRLD_d_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PSRLQ_w_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PSRLQ_w_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PSRLQ_d_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PSRLQ_d_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PADDQ_w_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PADDQ_w_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PADDQ_d_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PADDQ_d_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PMULLW_w_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PMULLW_w_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PMULLW_d_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PMULLW_d_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_MOVQ_w_rm_mod_xmm_u64_rm_reg_xmm_u64:
		return handler_MOVQ_w_rm_mod_xmm_u64_rm_reg_xmm_u64(insb, cseip);
	case in_MOVQ_d_rm_mod_xmm_u64_rm_reg_xmm_u64:
		return handler_MOVQ_d_rm_mod_xmm_u64_rm_reg_xmm_u64(insb, cseip);
	case in_MOVDQ2Q_w_rm_reg_mmx_u64_rm_rm_xmm_u64:
		return handler_MOVDQ2Q_w_rm_reg_mmx_u64_rm_rm_xmm_u64(insb, cseip);
	case in_MOVDQ2Q_d_rm_reg_mmx_u64_rm_rm_xmm_u64:
		return handler_MOVDQ2Q_d_rm_reg_mmx_u64_rm_rm_xmm_u64(insb, cseip);
	case in_PMOVMSKB_w_rm_reg_reg_u32_rm_rm_mmx_u64:
		return handler_PMOVMSKB_w_rm_reg_reg_u32_rm_rm_mmx_u64(insb, cseip);
	case in_PMOVMSKB_d_rm_reg_reg_u32_rm_rm_mmx_u64:
		return handler_PMOVMSKB_d_rm_reg_reg_u32_rm_rm_mmx_u64(insb, cseip);
	case in_PAVGB_w_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PAVGB_w_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PAVGB_d_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PAVGB_d_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PSRAW_w_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PSRAW_w_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PSRAW_d_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PSRAW_d_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PSRAD_w_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PSRAD_w_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PSRAD_d_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PSRAD_d_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PAVGW_w_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PAVGW_w_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PAVGW_d_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PAVGW_d_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PMULHUW_w_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PMULHUW_w_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PMULHUW_d_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PMULHUW_d_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PMULHW_w_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PMULHW_w_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PMULHW_d_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PMULHW_d_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_CVTPD2DQ_w_rm_reg_xmm_u128_rm_mod_xmm_d128:
		return handler_CVTPD2DQ_w_rm_reg_xmm_u128_rm_mod_xmm_d128(insb, cseip);
	case in_CVTPD2DQ_d_rm_reg_xmm_u128_rm_mod_xmm_d128:
		return handler_CVTPD2DQ_d_rm_reg_xmm_u128_rm_mod_xmm_d128(insb, cseip);
	case in_CVTTPD2DQ_w_rm_reg_xmm_u128_rm_mod_xmm_d128:
		return handler_CVTTPD2DQ_w_rm_reg_xmm_u128_rm_mod_xmm_d128(insb, cseip);
	case in_CVTTPD2DQ_d_rm_reg_xmm_u128_rm_mod_xmm_d128:
		return handler_CVTTPD2DQ_d_rm_reg_xmm_u128_rm_mod_xmm_d128(insb, cseip);
	case in_CVTDQ2PD_w_rm_reg_xmm_d128_rm_mod_xmm_u128:
		return handler_CVTDQ2PD_w_rm_reg_xmm_d128_rm_mod_xmm_u128(insb, cseip);
	case in_CVTDQ2PD_d_rm_reg_xmm_d128_rm_mod_xmm_u128:
		return handler_CVTDQ2PD_d_rm_reg_xmm_d128_rm_mod_xmm_u128(insb, cseip);
	case in_MOVNTQ_w_rm_mem_u64_rm_reg_mmx_u64:
		return handler_MOVNTQ_w_rm_mem_u64_rm_reg_mmx_u64(insb, cseip);
	case in_MOVNTQ_d_rm_mem_u64_rm_reg_mmx_u64:
		return handler_MOVNTQ_d_rm_mem_u64_rm_reg_mmx_u64(insb, cseip);
	case in_MOVNTDQ_w_rm_mem_u128_rm_reg_xmm_u128:
		return handler_MOVNTDQ_w_rm_mem_u128_rm_reg_xmm_u128(insb, cseip);
	case in_MOVNTDQ_d_rm_mem_u128_rm_reg_xmm_u128:
		return handler_MOVNTDQ_d_rm_mem_u128_rm_reg_xmm_u128(insb, cseip);
	case in_PSUBSB_w_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PSUBSB_w_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PSUBSB_d_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PSUBSB_d_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PSUBSW_w_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PSUBSW_w_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PSUBSW_d_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PSUBSW_d_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PMINSW_w_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PMINSW_w_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PMINSW_d_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PMINSW_d_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_POR_w_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_POR_w_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_POR_d_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_POR_d_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PADDSB_w_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PADDSB_w_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PADDSB_d_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PADDSB_d_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PADDSW_w_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PADDSW_w_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PADDSW_d_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PADDSW_d_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PMAXSW_w_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PMAXSW_w_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PMAXSW_d_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PMAXSW_d_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PXOR_w_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PXOR_w_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PXOR_d_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PXOR_d_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_LDDQU_w_rm_reg_xmm_u128_rm_mem_u128:
		return handler_LDDQU_w_rm_reg_xmm_u128_rm_mem_u128(insb, cseip);
	case in_LDDQU_d_rm_reg_xmm_u128_rm_mem_u128:
		return handler_LDDQU_d_rm_reg_xmm_u128_rm_mem_u128(insb, cseip);
	case in_PSLLW_w_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PSLLW_w_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PSLLW_d_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PSLLW_d_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PSLLD_w_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PSLLD_w_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PSLLD_d_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PSLLD_d_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PSLLQ_w_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PSLLQ_w_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PSLLQ_d_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PSLLQ_d_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PMULUDQ_w_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PMULUDQ_w_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PMULUDQ_d_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PMULUDQ_d_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PMADDWD_w_rm_reg_mmx_u64_rm_mod_mmx_u32:
		return handler_PMADDWD_w_rm_reg_mmx_u64_rm_mod_mmx_u32(insb, cseip);
	case in_PMADDWD_d_rm_reg_mmx_u64_rm_mod_mmx_u32:
		return handler_PMADDWD_d_rm_reg_mmx_u64_rm_mod_mmx_u32(insb, cseip);
	case in_PSADBW_w_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PSADBW_w_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PSADBW_d_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PSADBW_d_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_MASKMOVDQU_w_rm_rm_xmm_u128:
		return handler_MASKMOVDQU_w_rm_rm_xmm_u128(insb, cseip);
	case in_MASKMOVDQU_d_rm_rm_xmm_u128:
		return handler_MASKMOVDQU_d_rm_rm_xmm_u128(insb, cseip);
	case in_PSUBB_w_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PSUBB_w_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PSUBB_d_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PSUBB_d_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PSUBW_w_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PSUBW_w_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PSUBW_d_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PSUBW_d_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PSUBD_w_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PSUBD_w_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PSUBD_d_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PSUBD_d_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PSUBQ_w_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PSUBQ_w_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PSUBQ_d_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PSUBQ_d_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PADDB_w_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PADDB_w_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PADDB_d_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PADDB_d_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PADDW_w_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PADDW_w_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PADDW_d_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PADDW_d_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PADDD_w_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PADDD_w_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	case in_PADDD_d_rm_reg_mmx_u64_rm_mod_mmx_u64:
		return handler_PADDD_d_rm_reg_mmx_u64_rm_mod_mmx_u64(insb, cseip);
	default:
		break;
	}
	return false;
}
}
