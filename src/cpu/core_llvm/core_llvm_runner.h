#ifndef PROJECT_CORE_LLVM_H
#define PROJECT_CORE_LLVM_H
#include "core_llvm_common.h"
namespace core_llvm {
class addr_d {
public:
};

class addr_w {
public:
};

template<typename T>class t_rm_reg_xmm {
public:
	T& GetSource() {}
	T& GetTarget() {}
};

template<typename T>class t_rm_reg_seg {
public:
	T& GetSource() {}
	T& GetTarget() {}
};

template<typename T>class t_rm_mem {
public:
	T& GetSource() {}
	T& GetTarget() {}
};

template<typename T>class t_reg_gen_2 {
public:
	T& GetSource() {}
	T& GetTarget() {}
};

template<typename T>class t_reg_seg_3 {
public:
	T& GetSource() {}
	T& GetTarget() {}
};

template<typename T>class t_reg_seg_1 {
public:
	T& GetSource() {}
	T& GetTarget() {}
};

template<typename T>class t_reg_seg_2 {
public:
	T& GetSource() {}
	T& GetTarget() {}
};

template<typename T>class t_rm_reg_reg {
public:
	T& GetSource() {}
	T& GetTarget() {}
};

template<typename T>class t_rm_reg_mmx {
public:
	T& GetSource() {}
	T& GetTarget() {}
};

template<typename T>class t_mem_imm_J {
public:
	T& GetSource() {}
	T& GetTarget() {}
};

template<typename T>class t_mem_reg_7 {
public:
	T& GetSource() {}
	T& GetTarget() {}
};

template<typename T>class t_rm_rm_xmm {
public:
	T& GetSource() {}
	T& GetTarget() {}
};

template<typename T>class t_reg_gen {
public:
	T& GetSource() {}
	T& GetTarget() {}
};

template<typename T>class t_rm_mod_mmx {
public:
	T& GetSource() {}
	T& GetTarget() {}
};

template<typename T>class t_reg_reg {
public:
	T& GetSource() {}
	T& GetTarget() {}
};

template<typename T>class t_reg_seg_5 {
public:
	T& GetSource() {}
	T& GetTarget() {}
};

template<typename T>class t_mem_reg_3 {
public:
	T& GetSource() {}
	T& GetTarget() {}
};

template<typename T>class t_rm_mod_reg {
public:
	T& GetSource() {}
	T& GetTarget() {}
};

template<typename T>class t_reg_seg_4 {
public:
	T& GetSource() {}
	T& GetTarget() {}
};

template<typename T>class t_imm {
public:
	T& GetSource() {}
	T& GetTarget() {}
};

template<typename T>class t_mem_reg_6 {
public:
	T& GetSource() {}
	T& GetTarget() {}
};

template<typename T>class t_rm_rm_mmx {
public:
	T& GetSource() {}
	T& GetTarget() {}
};

template<typename T>class t_rm_mod_xmm {
public:
	T& GetSource() {}
	T& GetTarget() {}
};

template<typename T>class t_mem_imm_O {
public:
	T& GetSource() {}
	T& GetTarget() {}
};

template<typename T>class t_reg_seg {
public:
	T& GetSource() {}
	T& GetTarget() {}
};

template<typename T>class t_mem_imm {
public:
	T& GetSource() {}
	T& GetTarget() {}
};

template<typename T>class t_reg_gen_1 {
public:
	T& GetSource() {}
	T& GetTarget() {}
};

typedef int t_u32;

typedef int t_i8;

typedef int t_f64;

typedef int t_x48;

typedef int t_u16;

typedef int t_i16;

typedef int t_p32;

typedef int t_d128;

typedef int t_u128;

typedef int t_u64;

typedef int t_u8;

typedef int t_i32;

typedef int t_f128;

enum OpState {
	st_w_w,
	st_w_d,
	st_d_w,
	st_d_d,
	st_w_w_66,
	st_w_w_F2,
	st_w_w_F3,
	st_w_d_66,
	st_w_d_F2,
	st_w_d_F3,
	st_d_w_66,
	st_d_w_F2,
	st_d_w_F3,
	st_d_d_66,
	st_d_d_F2,
	st_d_d_F3,
	st_w_w_82,
	st_w_d_82,
	st_d_w_82,
	st_d_d_82,
	st_w_w_81,
	st_w_d_81,
	st_d_w_81,
	st_d_d_81,
	st_w_w_83,
	st_w_d_83,
	st_d_w_83,
	st_d_d_83,
	st_w_w_8F,
	st_w_d_8F,
	st_d_w_8F,
	st_d_d_8F,
	st_w_w_C0,
	st_w_d_C0,
	st_d_w_C0,
	st_d_d_C0,
	st_w_w_C1,
	st_w_d_C1,
	st_d_w_C1,
	st_d_d_C1,
	st_w_w_C6,
	st_w_d_C6,
	st_d_w_C6,
	st_d_d_C6,
	st_w_w_C7,
	st_w_d_C7,
	st_d_w_C7,
	st_d_d_C7,
	st_w_w_D0,
	st_w_d_D0,
	st_d_w_D0,
	st_d_d_D0,
	st_w_w_D1,
	st_w_d_D1,
	st_d_w_D1,
	st_d_d_D1,
	st_w_w_D2,
	st_w_d_D2,
	st_d_w_D2,
	st_d_d_D2,
	st_w_w_D3,
	st_w_d_D3,
	st_d_w_D3,
	st_d_d_D3,
	st_w_w_F6,
	st_w_d_F6,
	st_d_w_F6,
	st_d_d_F6,
	st_w_w_F7,
	st_w_d_F7,
	st_d_w_F7,
	st_d_d_F7,
	st_w_w_FE,
	st_w_d_FE,
	st_d_w_FE,
	st_d_d_FE,
	st_w_w_FF,
	st_w_d_FF,
	st_d_w_FF,
	st_d_d_FF,
	st_w_w_0F,
	st_w_w_0F_00,
	st_w_d_0F,
	st_w_d_0F_00,
	st_d_w_0F,
	st_d_w_0F_00,
	st_d_d_0F,
	st_d_d_0F_00,
	st_w_w_0F_01,
	st_w_d_0F_01,
	st_d_w_0F_01,
	st_d_d_0F_01,
	st_w_w_0F_18,
	st_w_d_0F_18,
	st_d_w_0F_18,
	st_d_d_0F_18,
	st_w_w_0F_1F,
	st_w_d_0F_1F,
	st_d_w_0F_1F,
	st_d_d_0F_1F,
	st_w_w_0F_38,
	st_w_d_0F_38,
	st_d_w_0F_38,
	st_d_d_0F_38,
	st_w_w_0F_3A,
	st_w_d_0F_3A,
	st_d_w_0F_3A,
	st_d_d_0F_3A,
	st_w_w_0F_71,
	st_w_d_0F_71,
	st_d_w_0F_71,
	st_d_d_0F_71,
	st_w_w_0F_72,
	st_w_d_0F_72,
	st_d_w_0F_72,
	st_d_d_0F_72,
	st_w_w_0F_73,
	st_w_d_0F_73,
	st_d_w_0F_73,
	st_d_d_0F_73,
	st_w_w_0F_AE,
	st_w_d_0F_AE,
	st_d_w_0F_AE,
	st_d_d_0F_AE,
	st_w_w_0F_BA,
	st_w_d_0F_BA,
	st_d_w_0F_BA,
	st_d_d_0F_BA,
	pr_w_d_F2,
	pr_w_d_F3,
	pr_w_d_26,
	pr_w_d_2E,
	pr_w_d_36,
	pr_w_d_3E,
	pr_w_d_64,
	pr_w_d_65,
	pr_d_d_F0,
	pr_w_w_F2,
	pr_w_w_F3,
	pr_w_w_26,
	pr_w_w_2E,
	pr_w_w_36,
	pr_w_w_3E,
	pr_w_w_64,
	pr_w_w_65,
	pr_d_w_F0,
	pr_d_d_F2,
	pr_d_d_F3,
	pr_d_d_26,
	pr_d_d_2E,
	pr_d_d_36,
	pr_d_d_3E,
	pr_d_d_64,
	pr_d_d_65,
	pr_w_d_F0,
	pr_d_w_F2,
	pr_d_w_F3,
	pr_d_w_26,
	pr_d_w_2E,
	pr_d_w_36,
	pr_d_w_3E,
	pr_d_w_64,
	pr_d_w_65,
	pr_w_w_F0,
	in_illegal = 0x1000,
	in_ADD_w_rm_mod_reg_u8_rm_reg_reg_u8,
	in_ADD_d_rm_mod_reg_u8_rm_reg_reg_u8,
	in_ADD_w_rm_mod_reg_u16_rm_reg_reg_u16,
	in_ADD_w_rm_mod_reg_u32_rm_reg_reg_u32,
	in_ADD_d_rm_mod_reg_u16_rm_reg_reg_u16,
	in_ADD_d_rm_mod_reg_u32_rm_reg_reg_u32,
	in_ADD_w_rm_reg_reg_u8_rm_mod_reg_u8,
	in_ADD_d_rm_reg_reg_u8_rm_mod_reg_u8,
	in_ADD_w_rm_reg_reg_u16_rm_mod_reg_u16,
	in_ADD_w_rm_reg_reg_u32_rm_mod_reg_u32,
	in_ADD_d_rm_reg_reg_u16_rm_mod_reg_u16,
	in_ADD_d_rm_reg_reg_u32_rm_mod_reg_u32,
	in_ADD_reg_gen_u8_imm_u8,
	in_ADD_reg_gen_u16_imm_i16,
	in_ADD_reg_gen_u32_imm_i32,
	in_PUSH_reg_seg_u16,
	in_POP_reg_seg_u16,
	in_OR_w_rm_mod_reg_u8_rm_reg_reg_u8,
	in_OR_d_rm_mod_reg_u8_rm_reg_reg_u8,
	in_OR_w_rm_mod_reg_u16_rm_reg_reg_u16,
	in_OR_w_rm_mod_reg_u32_rm_reg_reg_u32,
	in_OR_d_rm_mod_reg_u16_rm_reg_reg_u16,
	in_OR_d_rm_mod_reg_u32_rm_reg_reg_u32,
	in_OR_w_rm_reg_reg_u8_rm_mod_reg_u8,
	in_OR_d_rm_reg_reg_u8_rm_mod_reg_u8,
	in_OR_w_rm_reg_reg_u16_rm_mod_reg_u16,
	in_OR_w_rm_reg_reg_u32_rm_mod_reg_u32,
	in_OR_d_rm_reg_reg_u16_rm_mod_reg_u16,
	in_OR_d_rm_reg_reg_u32_rm_mod_reg_u32,
	in_OR_reg_gen_u8_imm_u8,
	in_OR_reg_gen_u16_imm_i16,
	in_OR_reg_gen_u32_imm_i32,
	in_PUSH_reg_seg_1_u16,
	in_ADC_w_rm_mod_reg_u8_rm_reg_reg_u8,
	in_ADC_d_rm_mod_reg_u8_rm_reg_reg_u8,
	in_ADC_w_rm_mod_reg_u16_rm_reg_reg_u16,
	in_ADC_w_rm_mod_reg_u32_rm_reg_reg_u32,
	in_ADC_d_rm_mod_reg_u16_rm_reg_reg_u16,
	in_ADC_d_rm_mod_reg_u32_rm_reg_reg_u32,
	in_ADC_w_rm_reg_reg_u8_rm_mod_reg_u8,
	in_ADC_d_rm_reg_reg_u8_rm_mod_reg_u8,
	in_ADC_w_rm_reg_reg_u16_rm_mod_reg_u16,
	in_ADC_w_rm_reg_reg_u32_rm_mod_reg_u32,
	in_ADC_d_rm_reg_reg_u16_rm_mod_reg_u16,
	in_ADC_d_rm_reg_reg_u32_rm_mod_reg_u32,
	in_ADC_reg_gen_u8_imm_u8,
	in_ADC_reg_gen_u16_imm_i16,
	in_ADC_reg_gen_u32_imm_i32,
	in_PUSH_reg_seg_2_u16,
	in_POP_reg_seg_2_u16,
	in_SBB_w_rm_mod_reg_u8_rm_reg_reg_u8,
	in_SBB_d_rm_mod_reg_u8_rm_reg_reg_u8,
	in_SBB_w_rm_mod_reg_u16_rm_reg_reg_u16,
	in_SBB_w_rm_mod_reg_u32_rm_reg_reg_u32,
	in_SBB_d_rm_mod_reg_u16_rm_reg_reg_u16,
	in_SBB_d_rm_mod_reg_u32_rm_reg_reg_u32,
	in_SBB_w_rm_reg_reg_u8_rm_mod_reg_u8,
	in_SBB_d_rm_reg_reg_u8_rm_mod_reg_u8,
	in_SBB_w_rm_reg_reg_u16_rm_mod_reg_u16,
	in_SBB_w_rm_reg_reg_u32_rm_mod_reg_u32,
	in_SBB_d_rm_reg_reg_u16_rm_mod_reg_u16,
	in_SBB_d_rm_reg_reg_u32_rm_mod_reg_u32,
	in_SBB_reg_gen_u8_imm_u8,
	in_SBB_reg_gen_u16_imm_i16,
	in_SBB_reg_gen_u32_imm_i32,
	in_PUSH_reg_seg_3_u16,
	in_POP_reg_seg_3_u16,
	in_AND_w_rm_mod_reg_u8_rm_reg_reg_u8,
	in_AND_d_rm_mod_reg_u8_rm_reg_reg_u8,
	in_AND_w_rm_mod_reg_u16_rm_reg_reg_u16,
	in_AND_w_rm_mod_reg_u32_rm_reg_reg_u32,
	in_AND_d_rm_mod_reg_u16_rm_reg_reg_u16,
	in_AND_d_rm_mod_reg_u32_rm_reg_reg_u32,
	in_AND_w_rm_reg_reg_u8_rm_mod_reg_u8,
	in_AND_d_rm_reg_reg_u8_rm_mod_reg_u8,
	in_AND_w_rm_reg_reg_u16_rm_mod_reg_u16,
	in_AND_w_rm_reg_reg_u32_rm_mod_reg_u32,
	in_AND_d_rm_reg_reg_u16_rm_mod_reg_u16,
	in_AND_d_rm_reg_reg_u32_rm_mod_reg_u32,
	in_AND_reg_gen_u8_imm_u8,
	in_AND_reg_gen_u16_imm_i16,
	in_AND_reg_gen_u32_imm_i32,
	in_DAA,
	in_SUB_w_rm_mod_reg_u8_rm_reg_reg_u8,
	in_SUB_d_rm_mod_reg_u8_rm_reg_reg_u8,
	in_SUB_w_rm_mod_reg_u16_rm_reg_reg_u16,
	in_SUB_w_rm_mod_reg_u32_rm_reg_reg_u32,
	in_SUB_d_rm_mod_reg_u16_rm_reg_reg_u16,
	in_SUB_d_rm_mod_reg_u32_rm_reg_reg_u32,
	in_SUB_w_rm_reg_reg_u8_rm_mod_reg_u8,
	in_SUB_d_rm_reg_reg_u8_rm_mod_reg_u8,
	in_SUB_w_rm_reg_reg_u16_rm_mod_reg_u16,
	in_SUB_w_rm_reg_reg_u32_rm_mod_reg_u32,
	in_SUB_d_rm_reg_reg_u16_rm_mod_reg_u16,
	in_SUB_d_rm_reg_reg_u32_rm_mod_reg_u32,
	in_SUB_reg_gen_u8_imm_u8,
	in_SUB_reg_gen_u16_imm_i16,
	in_SUB_reg_gen_u32_imm_i32,
	in_DAS,
	in_XOR_w_rm_mod_reg_u8_rm_reg_reg_u8,
	in_XOR_d_rm_mod_reg_u8_rm_reg_reg_u8,
	in_XOR_w_rm_mod_reg_u16_rm_reg_reg_u16,
	in_XOR_w_rm_mod_reg_u32_rm_reg_reg_u32,
	in_XOR_d_rm_mod_reg_u16_rm_reg_reg_u16,
	in_XOR_d_rm_mod_reg_u32_rm_reg_reg_u32,
	in_XOR_w_rm_reg_reg_u8_rm_mod_reg_u8,
	in_XOR_d_rm_reg_reg_u8_rm_mod_reg_u8,
	in_XOR_w_rm_reg_reg_u16_rm_mod_reg_u16,
	in_XOR_w_rm_reg_reg_u32_rm_mod_reg_u32,
	in_XOR_d_rm_reg_reg_u16_rm_mod_reg_u16,
	in_XOR_d_rm_reg_reg_u32_rm_mod_reg_u32,
	in_XOR_reg_gen_u8_imm_u8,
	in_XOR_reg_gen_u16_imm_i16,
	in_XOR_reg_gen_u32_imm_i32,
	in_AAA,
	in_CMP_w_rm_reg_reg_u8,
	in_CMP_d_rm_reg_reg_u8,
	in_CMP_w_rm_reg_reg_u16,
	in_CMP_w_rm_reg_reg_u32,
	in_CMP_d_rm_reg_reg_u16,
	in_CMP_d_rm_reg_reg_u32,
	in_CMP_w_rm_mod_reg_u8,
	in_CMP_d_rm_mod_reg_u8,
	in_CMP_w_rm_mod_reg_u16,
	in_CMP_w_rm_mod_reg_u32,
	in_CMP_d_rm_mod_reg_u16,
	in_CMP_d_rm_mod_reg_u32,
	in_CMP_imm_u8,
	in_CMP_imm_i16,
	in_CMP_imm_i32,
	in_AAS,
	in_INC_reg_reg_u16,
	in_DEC_reg_reg_u16,
	in_PUSH_reg_reg_u16,
	in_POP_reg_reg_u16,
	in_PUSHA,
	in_POPA,
	in_BOUND_w_rm_mem_u16,
	in_BOUND_d_rm_mem_u16,
	in_ARPL_w_rm_reg_reg_u16,
	in_ARPL_d_rm_reg_reg_u16,
	in_PUSH_imm_i16,
	in_IMUL_w_rm_reg_reg_u16_imm_i16,
	in_IMUL_d_rm_reg_reg_u16_imm_i16,
	in_PUSH_imm_i8,
	in_IMUL_w_rm_reg_reg_u16_imm_u8,
	in_IMUL_d_rm_reg_reg_u16_imm_u8,
	in_INS_w_mem_reg_7_u8_reg_gen_2_u16,
	in_INS_d_mem_reg_7_u8_reg_gen_2_u16,
	in_INS_w_mem_reg_7_u16_reg_gen_2_u16,
	in_INS_d_mem_reg_7_u16_reg_gen_2_u16,
	in_INS_w_mem_reg_7_u32_reg_gen_2_u16,
	in_INS_d_mem_reg_7_u32_reg_gen_2_u16,
	in_OUTS_w_reg_gen_2_u16_mem_reg_6_u8,
	in_OUTS_d_reg_gen_2_u16_mem_reg_6_u8,
	in_OUTS_w_reg_gen_2_u16_mem_reg_6_u16,
	in_OUTS_d_reg_gen_2_u16_mem_reg_6_u16,
	in_OUTS_w_reg_gen_2_u16_mem_reg_6_u32,
	in_OUTS_d_reg_gen_2_u16_mem_reg_6_u32,
	in_JO_w_mem_imm_J_u8,
	in_JO_d_mem_imm_J_u8,
	in_JNO_w_mem_imm_J_u8,
	in_JNO_d_mem_imm_J_u8,
	in_JB_w_mem_imm_J_u8,
	in_JB_d_mem_imm_J_u8,
	in_JNB_w_mem_imm_J_u8,
	in_JNB_d_mem_imm_J_u8,
	in_JZ_w_mem_imm_J_u8,
	in_JZ_d_mem_imm_J_u8,
	in_JNZ_w_mem_imm_J_u8,
	in_JNZ_d_mem_imm_J_u8,
	in_JBE_w_mem_imm_J_u8,
	in_JBE_d_mem_imm_J_u8,
	in_JNBE_w_mem_imm_J_u8,
	in_JNBE_d_mem_imm_J_u8,
	in_JS_w_mem_imm_J_u8,
	in_JS_d_mem_imm_J_u8,
	in_JNS_w_mem_imm_J_u8,
	in_JNS_d_mem_imm_J_u8,
	in_JP_w_mem_imm_J_u8,
	in_JP_d_mem_imm_J_u8,
	in_JNP_w_mem_imm_J_u8,
	in_JNP_d_mem_imm_J_u8,
	in_JL_w_mem_imm_J_u8,
	in_JL_d_mem_imm_J_u8,
	in_JNL_w_mem_imm_J_u8,
	in_JNL_d_mem_imm_J_u8,
	in_JLE_w_mem_imm_J_u8,
	in_JLE_d_mem_imm_J_u8,
	in_JNLE_w_mem_imm_J_u8,
	in_JNLE_d_mem_imm_J_u8,
	in_ADD_w_rm_mod_reg_u8_imm_u8,
	in_ADD_d_rm_mod_reg_u8_imm_u8,
	in_OR_w_rm_mod_reg_u8_imm_u8,
	in_OR_d_rm_mod_reg_u8_imm_u8,
	in_ADC_w_rm_mod_reg_u8_imm_u8,
	in_ADC_d_rm_mod_reg_u8_imm_u8,
	in_SBB_w_rm_mod_reg_u8_imm_u8,
	in_SBB_d_rm_mod_reg_u8_imm_u8,
	in_AND_w_rm_mod_reg_u8_imm_u8,
	in_AND_d_rm_mod_reg_u8_imm_u8,
	in_SUB_w_rm_mod_reg_u8_imm_u8,
	in_SUB_d_rm_mod_reg_u8_imm_u8,
	in_XOR_w_rm_mod_reg_u8_imm_u8,
	in_XOR_d_rm_mod_reg_u8_imm_u8,
	in_CMP_w_imm_u8,
	in_CMP_d_imm_u8,
	in_ADD_w_rm_mod_reg_u16_imm_i16,
	in_ADD_w_rm_mod_reg_u32_imm_i32,
	in_ADD_d_rm_mod_reg_u16_imm_i16,
	in_ADD_d_rm_mod_reg_u32_imm_i32,
	in_OR_w_rm_mod_reg_u16_imm_i16,
	in_OR_w_rm_mod_reg_u32_imm_i32,
	in_OR_d_rm_mod_reg_u16_imm_i16,
	in_OR_d_rm_mod_reg_u32_imm_i32,
	in_ADC_w_rm_mod_reg_u16_imm_i16,
	in_ADC_w_rm_mod_reg_u32_imm_i32,
	in_ADC_d_rm_mod_reg_u16_imm_i16,
	in_ADC_d_rm_mod_reg_u32_imm_i32,
	in_SBB_w_rm_mod_reg_u16_imm_i16,
	in_SBB_w_rm_mod_reg_u32_imm_i32,
	in_SBB_d_rm_mod_reg_u16_imm_i16,
	in_SBB_d_rm_mod_reg_u32_imm_i32,
	in_AND_w_rm_mod_reg_u16_imm_i16,
	in_AND_w_rm_mod_reg_u32_imm_i32,
	in_AND_d_rm_mod_reg_u16_imm_i16,
	in_AND_d_rm_mod_reg_u32_imm_i32,
	in_SUB_w_rm_mod_reg_u16_imm_i16,
	in_SUB_w_rm_mod_reg_u32_imm_i32,
	in_SUB_d_rm_mod_reg_u16_imm_i16,
	in_SUB_d_rm_mod_reg_u32_imm_i32,
	in_XOR_w_rm_mod_reg_u16_imm_i16,
	in_XOR_w_rm_mod_reg_u32_imm_i32,
	in_XOR_d_rm_mod_reg_u16_imm_i16,
	in_XOR_d_rm_mod_reg_u32_imm_i32,
	in_CMP_w_imm_i16,
	in_CMP_w_imm_i32,
	in_CMP_d_imm_i16,
	in_CMP_d_imm_i32,
	in_ADD_w_rm_mod_reg_u16_imm_u8,
	in_ADD_w_rm_mod_reg_u32_imm_u8,
	in_ADD_d_rm_mod_reg_u16_imm_u8,
	in_ADD_d_rm_mod_reg_u32_imm_u8,
	in_OR_w_rm_mod_reg_u16_imm_u8,
	in_OR_w_rm_mod_reg_u32_imm_u8,
	in_OR_d_rm_mod_reg_u16_imm_u8,
	in_OR_d_rm_mod_reg_u32_imm_u8,
	in_ADC_w_rm_mod_reg_u16_imm_u8,
	in_ADC_w_rm_mod_reg_u32_imm_u8,
	in_ADC_d_rm_mod_reg_u16_imm_u8,
	in_ADC_d_rm_mod_reg_u32_imm_u8,
	in_SBB_w_rm_mod_reg_u16_imm_u8,
	in_SBB_w_rm_mod_reg_u32_imm_u8,
	in_SBB_d_rm_mod_reg_u16_imm_u8,
	in_SBB_d_rm_mod_reg_u32_imm_u8,
	in_AND_w_rm_mod_reg_u16_imm_u8,
	in_AND_w_rm_mod_reg_u32_imm_u8,
	in_AND_d_rm_mod_reg_u16_imm_u8,
	in_AND_d_rm_mod_reg_u32_imm_u8,
	in_SUB_w_rm_mod_reg_u16_imm_u8,
	in_SUB_w_rm_mod_reg_u32_imm_u8,
	in_SUB_d_rm_mod_reg_u16_imm_u8,
	in_SUB_d_rm_mod_reg_u32_imm_u8,
	in_XOR_w_rm_mod_reg_u16_imm_u8,
	in_XOR_w_rm_mod_reg_u32_imm_u8,
	in_XOR_d_rm_mod_reg_u16_imm_u8,
	in_XOR_d_rm_mod_reg_u32_imm_u8,
	in_TEST_w_rm_reg_reg_u8,
	in_TEST_d_rm_reg_reg_u8,
	in_TEST_w_rm_reg_reg_u16,
	in_TEST_w_rm_reg_reg_u32,
	in_TEST_d_rm_reg_reg_u16,
	in_TEST_d_rm_reg_reg_u32,
	in_XCHG_w_rm_mod_reg_u8,
	in_XCHG_d_rm_mod_reg_u8,
	in_XCHG_w_rm_mod_reg_u16,
	in_XCHG_w_rm_mod_reg_u32,
	in_XCHG_d_rm_mod_reg_u16,
	in_XCHG_d_rm_mod_reg_u32,
	in_MOV_w_rm_mod_reg_u8_rm_reg_reg_u8,
	in_MOV_d_rm_mod_reg_u8_rm_reg_reg_u8,
	in_MOV_w_rm_mod_reg_u16_rm_reg_reg_u16,
	in_MOV_w_rm_mod_reg_u32_rm_reg_reg_u32,
	in_MOV_d_rm_mod_reg_u16_rm_reg_reg_u16,
	in_MOV_d_rm_mod_reg_u32_rm_reg_reg_u32,
	in_MOV_w_rm_reg_reg_u8_rm_mod_reg_u8,
	in_MOV_d_rm_reg_reg_u8_rm_mod_reg_u8,
	in_MOV_w_rm_reg_reg_u16_rm_mod_reg_u16,
	in_MOV_d_rm_reg_reg_u16_rm_mod_reg_u16,
	in_MOV_w_rm_mem_u16_rm_reg_seg_u16,
	in_MOV_d_rm_mem_u16_rm_reg_seg_u16,
	in_LEA_rm_reg_reg_u16,
	in_MOV_w_rm_reg_seg_u16_rm_mod_reg_u16,
	in_MOV_d_rm_reg_seg_u16_rm_mod_reg_u16,
	in_POP_w_rm_mod_reg_u16,
	in_POP_w_rm_mod_reg_u32,
	in_POP_d_rm_mod_reg_u16,
	in_POP_d_rm_mod_reg_u32,
	in_XCHG_reg_gen_u16,
	in_PAUSE,
	in_CBW,
	in_CWDE,
	in_CWD,
	in_CDQ,
	in_CALLF_w_mem_imm_p32,
	in_CALLF_d_mem_imm_p32,
	in_FWAIT,
	in_PUSHF,
	in_POPF,
	in_MOV_w_reg_gen_u8_mem_imm_O_u8,
	in_MOV_d_reg_gen_u8_mem_imm_O_u8,
	in_MOV_w_reg_gen_u16_mem_imm_O_u16,
	in_MOV_w_reg_gen_u32_mem_imm_O_u32,
	in_MOV_d_reg_gen_u16_mem_imm_O_u16,
	in_MOV_d_reg_gen_u32_mem_imm_O_u32,
	in_MOV_w_mem_imm_O_u8_reg_gen_u8,
	in_MOV_d_mem_imm_O_u8_reg_gen_u8,
	in_MOV_w_mem_imm_O_u16_reg_gen_u16,
	in_MOV_w_mem_imm_O_u32_reg_gen_u32,
	in_MOV_d_mem_imm_O_u16_reg_gen_u16,
	in_MOV_d_mem_imm_O_u32_reg_gen_u32,
	in_MOVS_w_mem_reg_7_u8_mem_reg_6_u8,
	in_MOVS_d_mem_reg_7_u8_mem_reg_6_u8,
	in_MOVS_w_mem_reg_7_u16_mem_reg_6_u16,
	in_MOVS_d_mem_reg_7_u16_mem_reg_6_u16,
	in_MOVS_w_mem_reg_7_u32_mem_reg_6_u32,
	in_MOVS_d_mem_reg_7_u32_mem_reg_6_u32,
	in_CMPS_w_mem_reg_6_u8,
	in_CMPS_d_mem_reg_6_u8,
	in_CMPS_w_mem_reg_6_u16,
	in_CMPS_d_mem_reg_6_u16,
	in_CMPS_w_mem_reg_6_u32,
	in_CMPS_d_mem_reg_6_u32,
	in_TEST_imm_u8,
	in_TEST_imm_i16,
	in_TEST_imm_i32,
	in_STOS_w_mem_reg_7_u8,
	in_STOS_d_mem_reg_7_u8,
	in_STOS_w_mem_reg_7_u16,
	in_STOS_d_mem_reg_7_u16,
	in_STOS_w_mem_reg_7_u32,
	in_STOS_d_mem_reg_7_u32,
	in_LODS_w_mem_reg_6_u8,
	in_LODS_d_mem_reg_6_u8,
	in_LODS_w_mem_reg_6_u16,
	in_LODS_d_mem_reg_6_u16,
	in_LODS_w_mem_reg_6_u32,
	in_LODS_d_mem_reg_6_u32,
	in_SCAS_w_mem_reg_7_u8,
	in_SCAS_d_mem_reg_7_u8,
	in_SCAS_w_mem_reg_7_u16,
	in_SCAS_d_mem_reg_7_u16,
	in_SCAS_w_mem_reg_7_u32,
	in_SCAS_d_mem_reg_7_u32,
	in_MOV_reg_reg_u8_imm_u8,
	in_MOV_reg_reg_u16_imm_u16,
	in_ROL_w_rm_mod_reg_u8_imm_u8,
	in_ROL_d_rm_mod_reg_u8_imm_u8,
	in_ROR_w_rm_mod_reg_u8_imm_u8,
	in_ROR_d_rm_mod_reg_u8_imm_u8,
	in_RCL_w_rm_mod_reg_u8_imm_u8,
	in_RCL_d_rm_mod_reg_u8_imm_u8,
	in_RCR_w_rm_mod_reg_u8_imm_u8,
	in_RCR_d_rm_mod_reg_u8_imm_u8,
	in_SHL_w_rm_mod_reg_u8_imm_u8,
	in_SHL_d_rm_mod_reg_u8_imm_u8,
	in_SHR_w_rm_mod_reg_u8_imm_u8,
	in_SHR_d_rm_mod_reg_u8_imm_u8,
	in_SAR_w_rm_mod_reg_u8_imm_u8,
	in_SAR_d_rm_mod_reg_u8_imm_u8,
	in_ROL_w_rm_mod_reg_u16_imm_u8,
	in_ROL_w_rm_mod_reg_u32_imm_u8,
	in_ROL_d_rm_mod_reg_u16_imm_u8,
	in_ROL_d_rm_mod_reg_u32_imm_u8,
	in_ROR_w_rm_mod_reg_u16_imm_u8,
	in_ROR_w_rm_mod_reg_u32_imm_u8,
	in_ROR_d_rm_mod_reg_u16_imm_u8,
	in_ROR_d_rm_mod_reg_u32_imm_u8,
	in_RCL_w_rm_mod_reg_u16_imm_u8,
	in_RCL_w_rm_mod_reg_u32_imm_u8,
	in_RCL_d_rm_mod_reg_u16_imm_u8,
	in_RCL_d_rm_mod_reg_u32_imm_u8,
	in_RCR_w_rm_mod_reg_u16_imm_u8,
	in_RCR_w_rm_mod_reg_u32_imm_u8,
	in_RCR_d_rm_mod_reg_u16_imm_u8,
	in_RCR_d_rm_mod_reg_u32_imm_u8,
	in_SHL_w_rm_mod_reg_u16_imm_u8,
	in_SHL_w_rm_mod_reg_u32_imm_u8,
	in_SHL_d_rm_mod_reg_u16_imm_u8,
	in_SHL_d_rm_mod_reg_u32_imm_u8,
	in_SHR_w_rm_mod_reg_u16_imm_u8,
	in_SHR_w_rm_mod_reg_u32_imm_u8,
	in_SHR_d_rm_mod_reg_u16_imm_u8,
	in_SHR_d_rm_mod_reg_u32_imm_u8,
	in_SAR_w_rm_mod_reg_u16_imm_u8,
	in_SAR_w_rm_mod_reg_u32_imm_u8,
	in_SAR_d_rm_mod_reg_u16_imm_u8,
	in_SAR_d_rm_mod_reg_u32_imm_u8,
	in_RETN_imm_u16,
	in_RETN,
	in_LES_w_rm_reg_reg_u16_rm_mem_p32,
	in_LES_d_rm_reg_reg_u16_rm_mem_p32,
	in_LDS_w_rm_reg_reg_u16_rm_mem_p32,
	in_LDS_d_rm_reg_reg_u16_rm_mem_p32,
	in_MOV_w_rm_mod_reg_u8_imm_u8,
	in_MOV_d_rm_mod_reg_u8_imm_u8,
	in_MOV_w_rm_mod_reg_u16_imm_i16,
	in_MOV_w_rm_mod_reg_u32_imm_i32,
	in_MOV_d_rm_mod_reg_u16_imm_i16,
	in_MOV_d_rm_mod_reg_u32_imm_i32,
	in_ENTER_imm_u8,
	in_LEAVE,
	in_RETF_imm_u16,
	in_RETF,
	in_INT,
	in_INT_imm_u8,
	in_INTO,
	in_IRET,
	in_ROL_w_rm_mod_reg_u8,
	in_ROL_d_rm_mod_reg_u8,
	in_ROR_w_rm_mod_reg_u8,
	in_ROR_d_rm_mod_reg_u8,
	in_RCL_w_rm_mod_reg_u8,
	in_RCL_d_rm_mod_reg_u8,
	in_RCR_w_rm_mod_reg_u8,
	in_RCR_d_rm_mod_reg_u8,
	in_SHL_w_rm_mod_reg_u8,
	in_SHL_d_rm_mod_reg_u8,
	in_SHR_w_rm_mod_reg_u8,
	in_SHR_d_rm_mod_reg_u8,
	in_SAR_w_rm_mod_reg_u8,
	in_SAR_d_rm_mod_reg_u8,
	in_ROL_w_rm_mod_reg_u16,
	in_ROL_w_rm_mod_reg_u32,
	in_ROL_d_rm_mod_reg_u16,
	in_ROL_d_rm_mod_reg_u32,
	in_ROR_w_rm_mod_reg_u16,
	in_ROR_w_rm_mod_reg_u32,
	in_ROR_d_rm_mod_reg_u16,
	in_ROR_d_rm_mod_reg_u32,
	in_RCL_w_rm_mod_reg_u16,
	in_RCL_w_rm_mod_reg_u32,
	in_RCL_d_rm_mod_reg_u16,
	in_RCL_d_rm_mod_reg_u32,
	in_RCR_w_rm_mod_reg_u16,
	in_RCR_w_rm_mod_reg_u32,
	in_RCR_d_rm_mod_reg_u16,
	in_RCR_d_rm_mod_reg_u32,
	in_SHL_w_rm_mod_reg_u16,
	in_SHL_w_rm_mod_reg_u32,
	in_SHL_d_rm_mod_reg_u16,
	in_SHL_d_rm_mod_reg_u32,
	in_SHR_w_rm_mod_reg_u16,
	in_SHR_w_rm_mod_reg_u32,
	in_SHR_d_rm_mod_reg_u16,
	in_SHR_d_rm_mod_reg_u32,
	in_SAR_w_rm_mod_reg_u16,
	in_SAR_w_rm_mod_reg_u32,
	in_SAR_d_rm_mod_reg_u16,
	in_SAR_d_rm_mod_reg_u32,
	in_ROL_w_rm_mod_reg_u8_reg_gen_1_u8,
	in_ROL_d_rm_mod_reg_u8_reg_gen_1_u8,
	in_ROR_w_rm_mod_reg_u8_reg_gen_1_u8,
	in_ROR_d_rm_mod_reg_u8_reg_gen_1_u8,
	in_RCL_w_rm_mod_reg_u8_reg_gen_1_u8,
	in_RCL_d_rm_mod_reg_u8_reg_gen_1_u8,
	in_RCR_w_rm_mod_reg_u8_reg_gen_1_u8,
	in_RCR_d_rm_mod_reg_u8_reg_gen_1_u8,
	in_SHL_w_rm_mod_reg_u8_reg_gen_1_u8,
	in_SHL_d_rm_mod_reg_u8_reg_gen_1_u8,
	in_SHR_w_rm_mod_reg_u8_reg_gen_1_u8,
	in_SHR_d_rm_mod_reg_u8_reg_gen_1_u8,
	in_SAR_w_rm_mod_reg_u8_reg_gen_1_u8,
	in_SAR_d_rm_mod_reg_u8_reg_gen_1_u8,
	in_ROL_w_rm_mod_reg_u16_reg_gen_1_u8,
	in_ROL_w_rm_mod_reg_u32_reg_gen_1_u8,
	in_ROL_d_rm_mod_reg_u16_reg_gen_1_u8,
	in_ROL_d_rm_mod_reg_u32_reg_gen_1_u8,
	in_ROR_w_rm_mod_reg_u16_reg_gen_1_u8,
	in_ROR_w_rm_mod_reg_u32_reg_gen_1_u8,
	in_ROR_d_rm_mod_reg_u16_reg_gen_1_u8,
	in_ROR_d_rm_mod_reg_u32_reg_gen_1_u8,
	in_RCL_w_rm_mod_reg_u16_reg_gen_1_u8,
	in_RCL_w_rm_mod_reg_u32_reg_gen_1_u8,
	in_RCL_d_rm_mod_reg_u16_reg_gen_1_u8,
	in_RCL_d_rm_mod_reg_u32_reg_gen_1_u8,
	in_RCR_w_rm_mod_reg_u16_reg_gen_1_u8,
	in_RCR_w_rm_mod_reg_u32_reg_gen_1_u8,
	in_RCR_d_rm_mod_reg_u16_reg_gen_1_u8,
	in_RCR_d_rm_mod_reg_u32_reg_gen_1_u8,
	in_SHL_w_rm_mod_reg_u16_reg_gen_1_u8,
	in_SHL_w_rm_mod_reg_u32_reg_gen_1_u8,
	in_SHL_d_rm_mod_reg_u16_reg_gen_1_u8,
	in_SHL_d_rm_mod_reg_u32_reg_gen_1_u8,
	in_SHR_w_rm_mod_reg_u16_reg_gen_1_u8,
	in_SHR_w_rm_mod_reg_u32_reg_gen_1_u8,
	in_SHR_d_rm_mod_reg_u16_reg_gen_1_u8,
	in_SHR_d_rm_mod_reg_u32_reg_gen_1_u8,
	in_SAR_w_rm_mod_reg_u16_reg_gen_1_u8,
	in_SAR_w_rm_mod_reg_u32_reg_gen_1_u8,
	in_SAR_d_rm_mod_reg_u16_reg_gen_1_u8,
	in_SAR_d_rm_mod_reg_u32_reg_gen_1_u8,
	in_AMX_imm_u8,
	in_ADX_imm_u8,
	in_XLAT_w_mem_reg_3_u8,
	in_XLAT_d_mem_reg_3_u8,
	in_LOOPNZ_w_mem_imm_J_u8,
	in_LOOPNZ_d_mem_imm_J_u8,
	in_LOOPZ_w_mem_imm_J_u8,
	in_LOOPZ_d_mem_imm_J_u8,
	in_LOOP_w_mem_imm_J_u8,
	in_LOOP_d_mem_imm_J_u8,
	in_JCXZ_w_mem_imm_J_u8,
	in_JCXZ_d_mem_imm_J_u8,
	in_IN_reg_gen_u8_imm_u8,
	in_IN_reg_gen_u16_imm_u8,
	in_IN_reg_gen_u32_imm_u8,
	in_OUT_imm_u8_reg_gen_u8,
	in_OUT_imm_u8_reg_gen_u16,
	in_OUT_imm_u8_reg_gen_u32,
	in_JMPF_w_mem_imm_p32,
	in_JMPF_d_mem_imm_p32,
	in_JMP_w_mem_imm_J_u8,
	in_JMP_d_mem_imm_J_u8,
	in_IN_reg_gen_u8_reg_gen_2_u16,
	in_IN_reg_gen_u16_reg_gen_2_u16,
	in_IN_reg_gen_u32_reg_gen_2_u16,
	in_OUT_reg_gen_2_u16_reg_gen_u8,
	in_OUT_reg_gen_2_u16_reg_gen_u16,
	in_OUT_reg_gen_2_u16_reg_gen_u32,
	in_HLT,
	in_CMC,
	in_TEST_w_imm_u8,
	in_TEST_d_imm_u8,
	in_NOT_w_rm_mod_reg_u8,
	in_NOT_d_rm_mod_reg_u8,
	in_NEG_w_rm_mod_reg_u8,
	in_NEG_d_rm_mod_reg_u8,
	in_MUL_w_rm_mod_reg_u8,
	in_MUL_d_rm_mod_reg_u8,
	in_IMUL_w_rm_mod_reg_u8,
	in_IMUL_d_rm_mod_reg_u8,
	in_DIV_w_rm_mod_reg_u8,
	in_DIV_d_rm_mod_reg_u8,
	in_IDIV_w_rm_mod_reg_u8,
	in_IDIV_d_rm_mod_reg_u8,
	in_TEST_w_imm_u16,
	in_TEST_w_imm_u32,
	in_TEST_d_imm_u16,
	in_TEST_d_imm_u32,
	in_NOT_w_rm_mod_reg_u16,
	in_NOT_w_rm_mod_reg_u32,
	in_NOT_d_rm_mod_reg_u16,
	in_NOT_d_rm_mod_reg_u32,
	in_NEG_w_rm_mod_reg_u16,
	in_NEG_w_rm_mod_reg_u32,
	in_NEG_d_rm_mod_reg_u16,
	in_NEG_d_rm_mod_reg_u32,
	in_MUL_w_rm_mod_reg_u16,
	in_MUL_w_rm_mod_reg_u32,
	in_MUL_d_rm_mod_reg_u16,
	in_MUL_d_rm_mod_reg_u32,
	in_IMUL_w_rm_mod_reg_u16,
	in_IMUL_d_rm_mod_reg_u16,
	in_DIV_w_rm_mod_reg_u16,
	in_DIV_d_rm_mod_reg_u16,
	in_IDIV_w_rm_mod_reg_u16,
	in_IDIV_d_rm_mod_reg_u16,
	in_CLC,
	in_STC,
	in_CLI,
	in_STI,
	in_CLD,
	in_STD,
	in_INC_w_rm_mod_reg_u8,
	in_INC_d_rm_mod_reg_u8,
	in_DEC_w_rm_mod_reg_u8,
	in_DEC_d_rm_mod_reg_u8,
	in_INC_w_rm_mod_reg_u16,
	in_INC_w_rm_mod_reg_u32,
	in_INC_d_rm_mod_reg_u16,
	in_INC_d_rm_mod_reg_u32,
	in_DEC_w_rm_mod_reg_u16,
	in_DEC_w_rm_mod_reg_u32,
	in_DEC_d_rm_mod_reg_u16,
	in_DEC_d_rm_mod_reg_u32,
	in_CALL_w_rm_mod_reg_u16,
	in_CALL_d_rm_mod_reg_u16,
	in_JMP_w_rm_mod_reg_u16,
	in_JMP_d_rm_mod_reg_u16,
	in_PUSH_w_rm_mod_reg_u16,
	in_PUSH_d_rm_mod_reg_u16,
	in_SLDT_w_rm_mem_u16,
	in_SLDT_d_rm_mem_u16,
	in_STR_w_rm_mem_u16,
	in_STR_d_rm_mem_u16,
	in_LLDT_w_rm_mod_reg_u16,
	in_LLDT_d_rm_mod_reg_u16,
	in_LTR_w_rm_mod_reg_u16,
	in_LTR_d_rm_mod_reg_u16,
	in_VERR_w_rm_mod_reg_u16,
	in_VERR_d_rm_mod_reg_u16,
	in_VERW_w_rm_mod_reg_u16,
	in_VERW_d_rm_mod_reg_u16,
	in_SGDT_w_rm_mem_x48,
	in_SGDT_d_rm_mem_x48,
	in_SIDT_w_rm_mem_x48,
	in_SIDT_d_rm_mem_x48,
	in_MONITOR_w,
	in_MONITOR_d,
	in_MWAIT,
	in_LGDT_w_rm_mem_x48,
	in_LGDT_d_rm_mem_x48,
	in_XGETBV,
	in_XSETBV,
	in_LIDT_w_rm_mem_x48,
	in_LIDT_d_rm_mem_x48,
	in_LMSW_w_rm_mod_reg_u16,
	in_LMSW_d_rm_mod_reg_u16,
	in_INVLPG,
	in_RDTSCP,
	in_LAR_w_rm_reg_reg_u16_rm_mem_u16,
	in_LAR_d_rm_reg_reg_u16_rm_mem_u16,
	in_LSL_w_rm_reg_reg_u16_rm_mem_u16,
	in_LSL_d_rm_reg_reg_u16_rm_mem_u16,
	in_LOADALL,
	in_CLTS,
	in_INVD,
	in_WBINVD,
	in_MOVUPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128,
	in_MOVUPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128,
	in_MOVSS_w_rm_reg_xmm_f128_rm_mod_xmm_f128,
	in_MOVSS_d_rm_reg_xmm_f128_rm_mod_xmm_f128,
	in_MOVUPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128,
	in_MOVUPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128,
	in_MOVSD_w_rm_reg_xmm_d128_rm_mod_xmm_d128,
	in_MOVSD_d_rm_reg_xmm_d128_rm_mod_xmm_d128,
	in_MOVUPS_w_rm_mod_xmm_f128_rm_reg_xmm_f128,
	in_MOVUPS_d_rm_mod_xmm_f128_rm_reg_xmm_f128,
	in_MOVSS_w_rm_mod_xmm_f128_rm_reg_xmm_f128,
	in_MOVSS_d_rm_mod_xmm_f128_rm_reg_xmm_f128,
	in_MOVUPD_w_rm_mod_xmm_d128_rm_reg_xmm_d128,
	in_MOVUPD_d_rm_mod_xmm_d128_rm_reg_xmm_d128,
	in_MOVSD_w_rm_mod_xmm_d128_rm_reg_xmm_d128,
	in_MOVSD_d_rm_mod_xmm_d128_rm_reg_xmm_d128,
	in_MOVHLPS_w_rm_reg_xmm_u64_rm_rm_xmm_u64,
	in_MOVHLPS_d_rm_reg_xmm_u64_rm_rm_xmm_u64,
	in_MOVLPS_w_rm_reg_xmm_u64_rm_mem_u64,
	in_MOVLPS_d_rm_reg_xmm_u64_rm_mem_u64,
	in_MOVLPD_w_rm_reg_xmm_u64_rm_mem_u64,
	in_MOVLPD_d_rm_reg_xmm_u64_rm_mem_u64,
	in_MOVDDUP_w_rm_reg_xmm_u64_rm_mod_xmm_u64,
	in_MOVDDUP_d_rm_reg_xmm_u64_rm_mod_xmm_u64,
	in_MOVSLDUP_w_rm_reg_xmm_u64_rm_mod_xmm_u64,
	in_MOVSLDUP_d_rm_reg_xmm_u64_rm_mod_xmm_u64,
	in_MOVLPS_w_rm_mem_u64_rm_reg_xmm_u64,
	in_MOVLPS_d_rm_mem_u64_rm_reg_xmm_u64,
	in_MOVLPD_w_rm_mem_u64_rm_reg_xmm_u64,
	in_MOVLPD_d_rm_mem_u64_rm_reg_xmm_u64,
	in_UNPCKLPS_w_rm_reg_xmm_f128_rm_mod_xmm_u64,
	in_UNPCKLPS_d_rm_reg_xmm_f128_rm_mod_xmm_u64,
	in_UNPCKLPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128,
	in_UNPCKLPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128,
	in_UNPCKHPS_w_rm_reg_xmm_f128_rm_mod_xmm_u64,
	in_UNPCKHPS_d_rm_reg_xmm_f128_rm_mod_xmm_u64,
	in_UNPCKHPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128,
	in_UNPCKHPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128,
	in_MOVLHPS_w_rm_reg_xmm_u64_rm_rm_xmm_u64,
	in_MOVLHPS_d_rm_reg_xmm_u64_rm_rm_xmm_u64,
	in_MOVHPS_w_rm_reg_xmm_u64_rm_mem_u64,
	in_MOVHPS_d_rm_reg_xmm_u64_rm_mem_u64,
	in_MOVHPD_w_rm_reg_xmm_u64_rm_mem_u64,
	in_MOVHPD_d_rm_reg_xmm_u64_rm_mem_u64,
	in_MOVSHDUP_w_rm_reg_xmm_u64_rm_mod_xmm_u64,
	in_MOVSHDUP_d_rm_reg_xmm_u64_rm_mod_xmm_u64,
	in_MOVHPS_w_rm_mem_u64_rm_reg_xmm_u64,
	in_MOVHPS_d_rm_mem_u64_rm_reg_xmm_u64,
	in_MOVHPD_w_rm_mem_u64_rm_reg_xmm_u64,
	in_MOVHPD_d_rm_mem_u64_rm_reg_xmm_u64,
	in_PREFETCHNTA_w_rm_mem_u8,
	in_PREFETCHNTA_d_rm_mem_u8,
	in_PREFETCHT0_w_rm_mem_u8,
	in_PREFETCHT0_d_rm_mem_u8,
	in_PREFETCHT1_w_rm_mem_u8,
	in_PREFETCHT1_d_rm_mem_u8,
	in_PREFETCHT2_w_rm_mem_u8,
	in_PREFETCHT2_d_rm_mem_u8,
	in_NOP_w_rm_mod_reg_u16,
	in_NOP_d_rm_mod_reg_u16,
	in_MOVAPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128,
	in_MOVAPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128,
	in_MOVAPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128,
	in_MOVAPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128,
	in_MOVAPS_w_rm_mod_xmm_f128_rm_reg_xmm_f128,
	in_MOVAPS_d_rm_mod_xmm_f128_rm_reg_xmm_f128,
	in_MOVAPD_w_rm_mod_xmm_d128_rm_reg_xmm_d128,
	in_MOVAPD_d_rm_mod_xmm_d128_rm_reg_xmm_d128,
	in_CVTPI2PS_w_rm_reg_xmm_f128_rm_mod_mmx_u64,
	in_CVTPI2PS_d_rm_reg_xmm_f128_rm_mod_mmx_u64,
	in_CVTSI2SS_w_rm_reg_xmm_f128_rm_mod_reg_u32,
	in_CVTSI2SS_d_rm_reg_xmm_f128_rm_mod_reg_u32,
	in_CVTPI2PD_w_rm_reg_xmm_d128_rm_mod_mmx_u64,
	in_CVTPI2PD_d_rm_reg_xmm_d128_rm_mod_mmx_u64,
	in_CVTSI2SD_w_rm_reg_xmm_d128_rm_mod_reg_u32,
	in_CVTSI2SD_d_rm_reg_xmm_d128_rm_mod_reg_u32,
	in_MOVNTPS_w_rm_mem_f128_rm_reg_xmm_f128,
	in_MOVNTPS_d_rm_mem_f128_rm_reg_xmm_f128,
	in_MOVNTPD_w_rm_mem_d128_rm_reg_xmm_d128,
	in_MOVNTPD_d_rm_mem_d128_rm_reg_xmm_d128,
	in_CVTTPS2PI_w_rm_reg_mmx_u64_rm_mod_xmm_f64,
	in_CVTTPS2PI_d_rm_reg_mmx_u64_rm_mod_xmm_f64,
	in_CVTTSS2SI_w_rm_reg_reg_u32_rm_mod_xmm_f128,
	in_CVTTSS2SI_d_rm_reg_reg_u32_rm_mod_xmm_f128,
	in_CVTTPD2PI_w_rm_reg_mmx_u64_rm_mod_xmm_d128,
	in_CVTTPD2PI_d_rm_reg_mmx_u64_rm_mod_xmm_d128,
	in_CVTTSD2SI_w_rm_reg_reg_u32_rm_mod_xmm_d128,
	in_CVTTSD2SI_d_rm_reg_reg_u32_rm_mod_xmm_d128,
	in_CVTPS2PI_w_rm_reg_mmx_u64_rm_mod_xmm_f64,
	in_CVTPS2PI_d_rm_reg_mmx_u64_rm_mod_xmm_f64,
	in_CVTSS2SI_w_rm_reg_reg_u32_rm_mod_xmm_f128,
	in_CVTSS2SI_d_rm_reg_reg_u32_rm_mod_xmm_f128,
	in_CVTPD2PI_w_rm_reg_mmx_u64_rm_mod_xmm_d128,
	in_CVTPD2PI_d_rm_reg_mmx_u64_rm_mod_xmm_d128,
	in_CVTSD2SI_w_rm_reg_reg_u32_rm_mod_xmm_d128,
	in_CVTSD2SI_d_rm_reg_reg_u32_rm_mod_xmm_d128,
	in_UCOMISS_w_rm_mod_xmm_f128,
	in_UCOMISS_d_rm_mod_xmm_f128,
	in_UCOMISD_w_rm_mod_xmm_d128,
	in_UCOMISD_d_rm_mod_xmm_d128,
	in_COMISS_w_rm_mod_xmm_f128,
	in_COMISS_d_rm_mod_xmm_f128,
	in_COMISD_w_rm_mod_xmm_d128,
	in_COMISD_d_rm_mod_xmm_d128,
	in_WRMSR,
	in_RDTSC,
	in_RDMSR,
	in_RDPMC,
	in_SYSENTER,
	in_PSHUFB_w_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PSHUFB_d_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PHADDW_w_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PHADDW_d_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PHADDD_w_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PHADDD_d_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PHADDSW_w_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PHADDSW_d_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PMADDUBSW_w_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PMADDUBSW_d_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PHSUBW_w_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PHSUBW_d_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PHSUBD_w_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PHSUBD_d_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PHSUBSW_w_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PHSUBSW_d_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PSIGNB_w_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PSIGNB_d_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PSIGNW_w_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PSIGNW_d_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PSIGND_w_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PSIGND_d_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PMULHRSW_w_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PMULHRSW_d_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PABSB_w_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PABSB_d_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PABSW_w_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PABSW_d_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PABSD_w_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PABSD_d_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_MOVBE_w_rm_reg_reg_u16_rm_mem_u16,
	in_MOVBE_d_rm_reg_reg_u16_rm_mem_u16,
	in_MOVBE_w_rm_mem_u16_rm_reg_reg_u16,
	in_MOVBE_d_rm_mem_u16_rm_reg_reg_u16,
	in_PALIGNR_w_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PALIGNR_d_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_MOVMSKPS_w_rm_reg_reg_u32_rm_rm_xmm_f128,
	in_MOVMSKPS_d_rm_reg_reg_u32_rm_rm_xmm_f128,
	in_MOVMSKPD_w_rm_reg_reg_u32_rm_rm_xmm_d128,
	in_MOVMSKPD_d_rm_reg_reg_u32_rm_rm_xmm_d128,
	in_SQRTPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128,
	in_SQRTPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128,
	in_SQRTSS_w_rm_reg_xmm_f128_rm_mod_xmm_f128,
	in_SQRTSS_d_rm_reg_xmm_f128_rm_mod_xmm_f128,
	in_SQRTPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128,
	in_SQRTPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128,
	in_SQRTSD_w_rm_reg_xmm_d128_rm_mod_xmm_d128,
	in_SQRTSD_d_rm_reg_xmm_d128_rm_mod_xmm_d128,
	in_RSQRTPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128,
	in_RSQRTPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128,
	in_RSQRTSS_w_rm_reg_xmm_f128_rm_mod_xmm_f128,
	in_RSQRTSS_d_rm_reg_xmm_f128_rm_mod_xmm_f128,
	in_RCPPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128,
	in_RCPPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128,
	in_RCPSS_w_rm_reg_xmm_f128_rm_mod_xmm_f128,
	in_RCPSS_d_rm_reg_xmm_f128_rm_mod_xmm_f128,
	in_ANDPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128,
	in_ANDPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128,
	in_ANDPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128,
	in_ANDPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128,
	in_ANDNPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128,
	in_ANDNPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128,
	in_ANDNPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128,
	in_ANDNPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128,
	in_ORPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128,
	in_ORPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128,
	in_ORPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128,
	in_ORPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128,
	in_XORPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128,
	in_XORPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128,
	in_XORPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128,
	in_XORPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128,
	in_ADDPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128,
	in_ADDPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128,
	in_ADDSS_w_rm_reg_xmm_f128_rm_mod_xmm_f128,
	in_ADDSS_d_rm_reg_xmm_f128_rm_mod_xmm_f128,
	in_ADDPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128,
	in_ADDPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128,
	in_ADDSD_w_rm_reg_xmm_d128_rm_mod_xmm_d128,
	in_ADDSD_d_rm_reg_xmm_d128_rm_mod_xmm_d128,
	in_MULPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128,
	in_MULPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128,
	in_MULSS_w_rm_reg_xmm_f128_rm_mod_xmm_f128,
	in_MULSS_d_rm_reg_xmm_f128_rm_mod_xmm_f128,
	in_MULPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128,
	in_MULPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128,
	in_MULSD_w_rm_reg_xmm_d128_rm_mod_xmm_d128,
	in_MULSD_d_rm_reg_xmm_d128_rm_mod_xmm_d128,
	in_CVTPS2PD_w_rm_reg_xmm_d128_rm_mod_xmm_f128,
	in_CVTPS2PD_d_rm_reg_xmm_d128_rm_mod_xmm_f128,
	in_CVTPD2PS_w_rm_reg_xmm_f128_rm_mod_xmm_d128,
	in_CVTPD2PS_d_rm_reg_xmm_f128_rm_mod_xmm_d128,
	in_CVTSS2SD_w_rm_reg_xmm_d128_rm_mod_xmm_f128,
	in_CVTSS2SD_d_rm_reg_xmm_d128_rm_mod_xmm_f128,
	in_CVTSD2SS_w_rm_reg_xmm_f128_rm_mod_xmm_d128,
	in_CVTSD2SS_d_rm_reg_xmm_f128_rm_mod_xmm_d128,
	in_CVTDQ2PS_w_rm_reg_xmm_f128_rm_mod_xmm_u128,
	in_CVTDQ2PS_d_rm_reg_xmm_f128_rm_mod_xmm_u128,
	in_CVTPS2DQ_w_rm_reg_xmm_u128_rm_mod_xmm_f128,
	in_CVTPS2DQ_d_rm_reg_xmm_u128_rm_mod_xmm_f128,
	in_CVTTPS2DQ_w_rm_reg_xmm_u128_rm_mod_xmm_f128,
	in_CVTTPS2DQ_d_rm_reg_xmm_u128_rm_mod_xmm_f128,
	in_SUBPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128,
	in_SUBPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128,
	in_SUBSS_w_rm_reg_xmm_f128_rm_mod_xmm_f128,
	in_SUBSS_d_rm_reg_xmm_f128_rm_mod_xmm_f128,
	in_SUBPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128,
	in_SUBPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128,
	in_SUBSD_w_rm_reg_xmm_d128_rm_mod_xmm_d128,
	in_SUBSD_d_rm_reg_xmm_d128_rm_mod_xmm_d128,
	in_MINPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128,
	in_MINPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128,
	in_MINSS_w_rm_reg_xmm_f128_rm_mod_xmm_f128,
	in_MINSS_d_rm_reg_xmm_f128_rm_mod_xmm_f128,
	in_MINPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128,
	in_MINPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128,
	in_MINSD_w_rm_reg_xmm_d128_rm_mod_xmm_d128,
	in_MINSD_d_rm_reg_xmm_d128_rm_mod_xmm_d128,
	in_DIVPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128,
	in_DIVPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128,
	in_DIVSS_w_rm_reg_xmm_f128_rm_mod_xmm_f128,
	in_DIVSS_d_rm_reg_xmm_f128_rm_mod_xmm_f128,
	in_DIVPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128,
	in_DIVPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128,
	in_DIVSD_w_rm_reg_xmm_d128_rm_mod_xmm_d128,
	in_DIVSD_d_rm_reg_xmm_d128_rm_mod_xmm_d128,
	in_MAXPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128,
	in_MAXPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128,
	in_MAXSS_w_rm_reg_xmm_f128_rm_mod_xmm_f128,
	in_MAXSS_d_rm_reg_xmm_f128_rm_mod_xmm_f128,
	in_MAXPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128,
	in_MAXPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128,
	in_MAXSD_w_rm_reg_xmm_d128_rm_mod_xmm_d128,
	in_MAXSD_d_rm_reg_xmm_d128_rm_mod_xmm_d128,
	in_PUNPCKLBW_w_rm_reg_mmx_u64_rm_mod_mmx_u32,
	in_PUNPCKLBW_d_rm_reg_mmx_u64_rm_mod_mmx_u32,
	in_PUNPCKLWD_w_rm_reg_mmx_u64_rm_mod_mmx_u32,
	in_PUNPCKLWD_d_rm_reg_mmx_u64_rm_mod_mmx_u32,
	in_PUNPCKLDQ_w_rm_reg_mmx_u64_rm_mod_mmx_u32,
	in_PUNPCKLDQ_d_rm_reg_mmx_u64_rm_mod_mmx_u32,
	in_PACKSSWB_w_rm_reg_mmx_u64_rm_mod_mmx_u32,
	in_PACKSSWB_d_rm_reg_mmx_u64_rm_mod_mmx_u32,
	in_PCMPGTB_w_rm_reg_mmx_u64_rm_mod_mmx_u32,
	in_PCMPGTB_d_rm_reg_mmx_u64_rm_mod_mmx_u32,
	in_PCMPGTW_w_rm_reg_mmx_u64_rm_mod_mmx_u32,
	in_PCMPGTW_d_rm_reg_mmx_u64_rm_mod_mmx_u32,
	in_PCMPGTD_w_rm_reg_mmx_u64_rm_mod_mmx_u32,
	in_PCMPGTD_d_rm_reg_mmx_u64_rm_mod_mmx_u32,
	in_PACKUSWB_w_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PACKUSWB_d_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PUNPCKHBW_w_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PUNPCKHBW_d_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PUNPCKHWD_w_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PUNPCKHWD_d_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PUNPCKHDQ_w_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PUNPCKHDQ_d_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PACKSSDW_w_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PACKSSDW_d_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PUNPCKLQDQ_w_rm_reg_xmm_u128_rm_mod_xmm_u128,
	in_PUNPCKLQDQ_d_rm_reg_xmm_u128_rm_mod_xmm_u128,
	in_PUNPCKHQDQ_w_rm_reg_xmm_u128_rm_mod_xmm_u128,
	in_PUNPCKHQDQ_d_rm_reg_xmm_u128_rm_mod_xmm_u128,
	in_MOVD_w_rm_reg_mmx_u64_rm_mod_reg_u32,
	in_MOVD_d_rm_reg_mmx_u64_rm_mod_reg_u32,
	in_MOVQ_w_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_MOVQ_d_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_MOVDQA_w_rm_reg_xmm_u128_rm_mod_xmm_u128,
	in_MOVDQA_d_rm_reg_xmm_u128_rm_mod_xmm_u128,
	in_MOVDQU_w_rm_reg_xmm_u128_rm_mod_xmm_u128,
	in_MOVDQU_d_rm_reg_xmm_u128_rm_mod_xmm_u128,
	in_PSHUFW_w_rm_reg_mmx_u64_imm_u8,
	in_PSHUFW_d_rm_reg_mmx_u64_imm_u8,
	in_PSHUFLW_w_rm_reg_xmm_u128_imm_u8,
	in_PSHUFLW_d_rm_reg_xmm_u128_imm_u8,
	in_PSHUFHW_w_rm_reg_xmm_u128_imm_u8,
	in_PSHUFHW_d_rm_reg_xmm_u128_imm_u8,
	in_PSHUFD_w_rm_reg_xmm_u128_imm_u8,
	in_PSHUFD_d_rm_reg_xmm_u128_imm_u8,
	in_PSRLW_w_rm_rm_mmx_u64_imm_u8,
	in_PSRLW_d_rm_rm_mmx_u64_imm_u8,
	in_PSRAW_w_rm_rm_mmx_u64_imm_u8,
	in_PSRAW_d_rm_rm_mmx_u64_imm_u8,
	in_PSLLW_w_rm_rm_mmx_u64_imm_u8,
	in_PSLLW_d_rm_rm_mmx_u64_imm_u8,
	in_PSRLD_w_rm_rm_mmx_u64_imm_u8,
	in_PSRLD_d_rm_rm_mmx_u64_imm_u8,
	in_PSRAD_w_rm_rm_mmx_u64_imm_u8,
	in_PSRAD_d_rm_rm_mmx_u64_imm_u8,
	in_PSLLD_w_rm_rm_mmx_u64_imm_u8,
	in_PSLLD_d_rm_rm_mmx_u64_imm_u8,
	in_PSRLQ_w_rm_rm_mmx_u64_imm_u8,
	in_PSRLQ_d_rm_rm_mmx_u64_imm_u8,
	in_PSRLDQ_w_rm_rm_xmm_u128_imm_u8,
	in_PSRLDQ_d_rm_rm_xmm_u128_imm_u8,
	in_PSLLQ_w_rm_rm_mmx_u64_imm_u8,
	in_PSLLQ_d_rm_rm_mmx_u64_imm_u8,
	in_PSLLDQ_w_rm_rm_xmm_u128_imm_u8,
	in_PSLLDQ_d_rm_rm_xmm_u128_imm_u8,
	in_PCMPEQB_w_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PCMPEQB_d_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PCMPEQW_w_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PCMPEQW_d_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PCMPEQD_w_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PCMPEQD_d_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_EMMS,
	in_HADDPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128,
	in_HADDPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128,
	in_HADDPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128,
	in_HADDPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128,
	in_HSUBPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128,
	in_HSUBPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128,
	in_HSUBPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128,
	in_HSUBPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128,
	in_MOVD_w_rm_mod_reg_u32_rm_reg_mmx_u64,
	in_MOVD_d_rm_mod_reg_u32_rm_reg_mmx_u64,
	in_MOVQ_w_rm_reg_xmm_u64_rm_mod_xmm_u64,
	in_MOVQ_d_rm_reg_xmm_u64_rm_mod_xmm_u64,
	in_MOVQ_w_rm_mod_mmx_u64_rm_reg_mmx_u64,
	in_MOVQ_d_rm_mod_mmx_u64_rm_reg_mmx_u64,
	in_MOVDQA_w_rm_mod_xmm_u128_rm_reg_xmm_u128,
	in_MOVDQA_d_rm_mod_xmm_u128_rm_reg_xmm_u128,
	in_MOVDQU_w_rm_mod_xmm_u128_rm_reg_xmm_u128,
	in_MOVDQU_d_rm_mod_xmm_u128_rm_reg_xmm_u128,
	in_PUSH_reg_seg_4_u16,
	in_POP_reg_seg_4_u16,
	in_CPUID,
	in_BT_w_rm_reg_reg_u16,
	in_BT_d_rm_reg_reg_u16,
	in_SHLD_w_rm_mod_reg_u16_imm_u8,
	in_SHLD_d_rm_mod_reg_u16_imm_u8,
	in_SHLD_w_rm_mod_reg_u16_reg_gen_1_u8,
	in_SHLD_d_rm_mod_reg_u16_reg_gen_1_u8,
	in_PUSH_reg_seg_5_u16,
	in_POP_reg_seg_5_u16,
	in_RSM,
	in_BTS_w_rm_mod_reg_u16_rm_reg_reg_u16,
	in_BTS_d_rm_mod_reg_u16_rm_reg_reg_u16,
	in_SHRD_w_rm_mod_reg_u16_imm_u8,
	in_SHRD_d_rm_mod_reg_u16_imm_u8,
	in_SHRD_w_rm_mod_reg_u16_reg_gen_1_u8,
	in_SHRD_d_rm_mod_reg_u16_reg_gen_1_u8,
	in_FXSAVE_w,
	in_FXSAVE_d,
	in_FXRSTOR_w,
	in_FXRSTOR_d,
	in_LDMXCSR_w_rm_mem_u32,
	in_LDMXCSR_d_rm_mem_u32,
	in_STMXCSR_w_rm_mem_u32,
	in_STMXCSR_d_rm_mem_u32,
	in_XSAVE,
	in_LFENCE,
	in_XRSTOR,
	in_MFENCE,
	in_SFENCE,
	in_CLFLUSH_w_rm_mem_u8,
	in_CLFLUSH_d_rm_mem_u8,
	in_IMUL_w_rm_reg_reg_u16_rm_mod_reg_u16,
	in_IMUL_w_rm_reg_reg_u32_rm_mod_reg_u32,
	in_IMUL_d_rm_reg_reg_u16_rm_mod_reg_u16,
	in_IMUL_d_rm_reg_reg_u32_rm_mod_reg_u32,
	in_BTR_w_rm_mod_reg_u16_rm_reg_reg_u16,
	in_BTR_d_rm_mod_reg_u16_rm_reg_reg_u16,
	in_MOVZX_w_rm_reg_reg_u16_rm_mod_reg_u8,
	in_MOVZX_d_rm_reg_reg_u16_rm_mod_reg_u8,
	in_MOVZX_w_rm_reg_reg_u16_rm_mod_reg_u16,
	in_MOVZX_w_rm_reg_reg_u32_rm_mod_reg_u16,
	in_MOVZX_d_rm_reg_reg_u16_rm_mod_reg_u16,
	in_MOVZX_d_rm_reg_reg_u32_rm_mod_reg_u16,
	in_POPCNT_w_rm_reg_reg_u16_rm_mod_reg_u16,
	in_POPCNT_d_rm_reg_reg_u16_rm_mod_reg_u16,
	in_BT_w_imm_u8,
	in_BT_d_imm_u8,
	in_BTS_w_rm_mod_reg_u16_imm_u8,
	in_BTS_d_rm_mod_reg_u16_imm_u8,
	in_BTR_w_rm_mod_reg_u16_imm_u8,
	in_BTR_d_rm_mod_reg_u16_imm_u8,
	in_BTC_w_rm_mod_reg_u16_imm_u8,
	in_BTC_d_rm_mod_reg_u16_imm_u8,
	in_BTC_w_rm_mod_reg_u16_rm_reg_reg_u16,
	in_BTC_d_rm_mod_reg_u16_rm_reg_reg_u16,
	in_MOVSX_w_rm_reg_reg_u16_rm_mod_reg_u8,
	in_MOVSX_d_rm_reg_reg_u16_rm_mod_reg_u8,
	in_MOVSX_w_rm_reg_reg_u16_rm_mod_reg_u16,
	in_MOVSX_w_rm_reg_reg_u32_rm_mod_reg_u16,
	in_MOVSX_d_rm_reg_reg_u16_rm_mod_reg_u16,
	in_MOVSX_d_rm_reg_reg_u32_rm_mod_reg_u16,
	in_XADD_w_rm_reg_reg_u8,
	in_XADD_d_rm_reg_reg_u8,
	in_XADD_w_rm_reg_reg_u16,
	in_XADD_w_rm_reg_reg_u32,
	in_XADD_d_rm_reg_reg_u16,
	in_XADD_d_rm_reg_reg_u32,
	in_CMPPS_w_rm_reg_xmm_f128_imm_u8,
	in_CMPPS_d_rm_reg_xmm_f128_imm_u8,
	in_CMPSS_w_rm_reg_xmm_f128_imm_u8,
	in_CMPSS_d_rm_reg_xmm_f128_imm_u8,
	in_CMPPD_w_rm_reg_xmm_d128_imm_u8,
	in_CMPPD_d_rm_reg_xmm_d128_imm_u8,
	in_CMPSD_w_rm_reg_xmm_d128_imm_u8,
	in_CMPSD_d_rm_reg_xmm_d128_imm_u8,
	in_MOVNTI_w_rm_mem_u32_rm_reg_reg_u32,
	in_MOVNTI_d_rm_mem_u32_rm_reg_reg_u32,
	in_PINSRW_w_rm_reg_mmx_u64_imm_u8,
	in_PINSRW_d_rm_reg_mmx_u64_imm_u8,
	in_PEXTRW_w_rm_reg_reg_u32_imm_u8,
	in_PEXTRW_d_rm_reg_reg_u32_imm_u8,
	in_SHUFPS_w_rm_reg_xmm_f128_imm_u8,
	in_SHUFPS_d_rm_reg_xmm_f128_imm_u8,
	in_SHUFPD_w_rm_reg_xmm_d128_imm_u8,
	in_SHUFPD_d_rm_reg_xmm_d128_imm_u8,
	in_ADDSUBPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128,
	in_ADDSUBPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128,
	in_ADDSUBPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128,
	in_ADDSUBPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128,
	in_PSRLW_w_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PSRLW_d_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PSRLD_w_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PSRLD_d_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PSRLQ_w_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PSRLQ_d_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PADDQ_w_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PADDQ_d_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PMULLW_w_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PMULLW_d_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_MOVQ_w_rm_mod_xmm_u64_rm_reg_xmm_u64,
	in_MOVQ_d_rm_mod_xmm_u64_rm_reg_xmm_u64,
	in_MOVDQ2Q_w_rm_reg_mmx_u64_rm_rm_xmm_u64,
	in_MOVDQ2Q_d_rm_reg_mmx_u64_rm_rm_xmm_u64,
	in_PMOVMSKB_w_rm_reg_reg_u32_rm_rm_mmx_u64,
	in_PMOVMSKB_d_rm_reg_reg_u32_rm_rm_mmx_u64,
	in_PAVGB_w_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PAVGB_d_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PSRAW_w_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PSRAW_d_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PSRAD_w_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PSRAD_d_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PAVGW_w_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PAVGW_d_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PMULHUW_w_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PMULHUW_d_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PMULHW_w_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PMULHW_d_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_CVTPD2DQ_w_rm_reg_xmm_u128_rm_mod_xmm_d128,
	in_CVTPD2DQ_d_rm_reg_xmm_u128_rm_mod_xmm_d128,
	in_CVTTPD2DQ_w_rm_reg_xmm_u128_rm_mod_xmm_d128,
	in_CVTTPD2DQ_d_rm_reg_xmm_u128_rm_mod_xmm_d128,
	in_CVTDQ2PD_w_rm_reg_xmm_d128_rm_mod_xmm_u128,
	in_CVTDQ2PD_d_rm_reg_xmm_d128_rm_mod_xmm_u128,
	in_MOVNTQ_w_rm_mem_u64_rm_reg_mmx_u64,
	in_MOVNTQ_d_rm_mem_u64_rm_reg_mmx_u64,
	in_MOVNTDQ_w_rm_mem_u128_rm_reg_xmm_u128,
	in_MOVNTDQ_d_rm_mem_u128_rm_reg_xmm_u128,
	in_PSUBSB_w_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PSUBSB_d_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PSUBSW_w_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PSUBSW_d_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PMINSW_w_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PMINSW_d_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_POR_w_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_POR_d_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PADDSB_w_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PADDSB_d_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PADDSW_w_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PADDSW_d_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PMAXSW_w_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PMAXSW_d_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PXOR_w_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PXOR_d_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_LDDQU_w_rm_reg_xmm_u128_rm_mem_u128,
	in_LDDQU_d_rm_reg_xmm_u128_rm_mem_u128,
	in_PSLLW_w_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PSLLW_d_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PSLLD_w_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PSLLD_d_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PSLLQ_w_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PSLLQ_d_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PMULUDQ_w_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PMULUDQ_d_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PMADDWD_w_rm_reg_mmx_u64_rm_mod_mmx_u32,
	in_PMADDWD_d_rm_reg_mmx_u64_rm_mod_mmx_u32,
	in_PSADBW_w_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PSADBW_d_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_MASKMOVDQU_w_rm_rm_xmm_u128,
	in_MASKMOVDQU_d_rm_rm_xmm_u128,
	in_PSUBB_w_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PSUBB_d_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PSUBW_w_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PSUBW_d_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PSUBD_w_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PSUBD_d_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PSUBQ_w_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PSUBQ_d_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PADDB_w_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PADDB_d_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PADDW_w_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PADDW_d_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PADDD_w_rm_reg_mmx_u64_rm_mod_mmx_u64,
	in_PADDD_d_rm_reg_mmx_u64_rm_mod_mmx_u64,
};
struct CpuRunnerX86 {
	OpState mInitState;

	static const OpState table_st_w_w[];
	static const OpState table_st_w_d[];
	static const OpState table_st_d_w[];
	static const OpState table_st_d_d[];
	static const OpState table_st_w_w_66[];
	static const OpState table_st_w_w_F2[];
	static const OpState table_st_w_w_F3[];
	static const OpState table_st_w_d_66[];
	static const OpState table_st_w_d_F2[];
	static const OpState table_st_w_d_F3[];
	static const OpState table_st_d_w_66[];
	static const OpState table_st_d_w_F2[];
	static const OpState table_st_d_w_F3[];
	static const OpState table_st_d_d_66[];
	static const OpState table_st_d_d_F2[];
	static const OpState table_st_d_d_F3[];
	static const OpState table_st_w_w_82[];
	static const OpState table_st_w_d_82[];
	static const OpState table_st_d_w_82[];
	static const OpState table_st_d_d_82[];
	static const OpState table_st_w_w_81[];
	static const OpState table_st_w_d_81[];
	static const OpState table_st_d_w_81[];
	static const OpState table_st_d_d_81[];
	static const OpState table_st_w_w_83[];
	static const OpState table_st_w_d_83[];
	static const OpState table_st_d_w_83[];
	static const OpState table_st_d_d_83[];
	static const OpState table_st_w_w_8F[];
	static const OpState table_st_w_d_8F[];
	static const OpState table_st_d_w_8F[];
	static const OpState table_st_d_d_8F[];
	static const OpState table_st_w_w_C0[];
	static const OpState table_st_w_d_C0[];
	static const OpState table_st_d_w_C0[];
	static const OpState table_st_d_d_C0[];
	static const OpState table_st_w_w_C1[];
	static const OpState table_st_w_d_C1[];
	static const OpState table_st_d_w_C1[];
	static const OpState table_st_d_d_C1[];
	static const OpState table_st_w_w_C6[];
	static const OpState table_st_w_d_C6[];
	static const OpState table_st_d_w_C6[];
	static const OpState table_st_d_d_C6[];
	static const OpState table_st_w_w_C7[];
	static const OpState table_st_w_d_C7[];
	static const OpState table_st_d_w_C7[];
	static const OpState table_st_d_d_C7[];
	static const OpState table_st_w_w_D0[];
	static const OpState table_st_w_d_D0[];
	static const OpState table_st_d_w_D0[];
	static const OpState table_st_d_d_D0[];
	static const OpState table_st_w_w_D1[];
	static const OpState table_st_w_d_D1[];
	static const OpState table_st_d_w_D1[];
	static const OpState table_st_d_d_D1[];
	static const OpState table_st_w_w_D2[];
	static const OpState table_st_w_d_D2[];
	static const OpState table_st_d_w_D2[];
	static const OpState table_st_d_d_D2[];
	static const OpState table_st_w_w_D3[];
	static const OpState table_st_w_d_D3[];
	static const OpState table_st_d_w_D3[];
	static const OpState table_st_d_d_D3[];
	static const OpState table_st_w_w_F6[];
	static const OpState table_st_w_d_F6[];
	static const OpState table_st_d_w_F6[];
	static const OpState table_st_d_d_F6[];
	static const OpState table_st_w_w_F7[];
	static const OpState table_st_w_d_F7[];
	static const OpState table_st_d_w_F7[];
	static const OpState table_st_d_d_F7[];
	static const OpState table_st_w_w_FE[];
	static const OpState table_st_w_d_FE[];
	static const OpState table_st_d_w_FE[];
	static const OpState table_st_d_d_FE[];
	static const OpState table_st_w_w_FF[];
	static const OpState table_st_w_d_FF[];
	static const OpState table_st_d_w_FF[];
	static const OpState table_st_d_d_FF[];
	static const OpState table_st_w_w_0F[];
	static const OpState table_st_w_w_0F_00[];
	static const OpState table_st_w_d_0F[];
	static const OpState table_st_w_d_0F_00[];
	static const OpState table_st_d_w_0F[];
	static const OpState table_st_d_w_0F_00[];
	static const OpState table_st_d_d_0F[];
	static const OpState table_st_d_d_0F_00[];
	static const OpState table_st_w_w_0F_01[];
	static const OpState table_st_w_d_0F_01[];
	static const OpState table_st_d_w_0F_01[];
	static const OpState table_st_d_d_0F_01[];
	static const OpState table_st_w_w_0F_18[];
	static const OpState table_st_w_d_0F_18[];
	static const OpState table_st_d_w_0F_18[];
	static const OpState table_st_d_d_0F_18[];
	static const OpState table_st_w_w_0F_1F[];
	static const OpState table_st_w_d_0F_1F[];
	static const OpState table_st_d_w_0F_1F[];
	static const OpState table_st_d_d_0F_1F[];
	static const OpState table_st_w_w_0F_38[];
	static const OpState table_st_w_d_0F_38[];
	static const OpState table_st_d_w_0F_38[];
	static const OpState table_st_d_d_0F_38[];
	static const OpState table_st_w_w_0F_3A[];
	static const OpState table_st_w_d_0F_3A[];
	static const OpState table_st_d_w_0F_3A[];
	static const OpState table_st_d_d_0F_3A[];
	static const OpState table_st_w_w_0F_71[];
	static const OpState table_st_w_d_0F_71[];
	static const OpState table_st_d_w_0F_71[];
	static const OpState table_st_d_d_0F_71[];
	static const OpState table_st_w_w_0F_72[];
	static const OpState table_st_w_d_0F_72[];
	static const OpState table_st_d_w_0F_72[];
	static const OpState table_st_d_d_0F_72[];
	static const OpState table_st_w_w_0F_73[];
	static const OpState table_st_w_d_0F_73[];
	static const OpState table_st_d_w_0F_73[];
	static const OpState table_st_d_d_0F_73[];
	static const OpState table_st_w_w_0F_AE[];
	static const OpState table_st_w_d_0F_AE[];
	static const OpState table_st_d_w_0F_AE[];
	static const OpState table_st_d_d_0F_AE[];
	static const OpState table_st_w_w_0F_BA[];
	static const OpState table_st_w_d_0F_BA[];
	static const OpState table_st_d_w_0F_BA[];
	static const OpState table_st_d_d_0F_BA[];
	static const OpState table_pr_w_d_F2[];
	static const OpState table_pr_w_d_F3[];
	static const OpState table_pr_w_d_26[];
	static const OpState table_pr_w_d_2E[];
	static const OpState table_pr_w_d_36[];
	static const OpState table_pr_w_d_3E[];
	static const OpState table_pr_w_d_64[];
	static const OpState table_pr_w_d_65[];
	static const OpState table_pr_d_d_F0[];
	static const OpState table_pr_w_w_F2[];
	static const OpState table_pr_w_w_F3[];
	static const OpState table_pr_w_w_26[];
	static const OpState table_pr_w_w_2E[];
	static const OpState table_pr_w_w_36[];
	static const OpState table_pr_w_w_3E[];
	static const OpState table_pr_w_w_64[];
	static const OpState table_pr_w_w_65[];
	static const OpState table_pr_d_w_F0[];
	static const OpState table_pr_d_d_F2[];
	static const OpState table_pr_d_d_F3[];
	static const OpState table_pr_d_d_26[];
	static const OpState table_pr_d_d_2E[];
	static const OpState table_pr_d_d_36[];
	static const OpState table_pr_d_d_3E[];
	static const OpState table_pr_d_d_64[];
	static const OpState table_pr_d_d_65[];
	static const OpState table_pr_w_d_F0[];
	static const OpState table_pr_d_w_F2[];
	static const OpState table_pr_d_w_F3[];
	static const OpState table_pr_d_w_26[];
	static const OpState table_pr_d_w_2E[];
	static const OpState table_pr_d_w_36[];
	static const OpState table_pr_d_w_3E[];
	static const OpState table_pr_d_w_64[];
	static const OpState table_pr_d_w_65[];
	static const OpState table_pr_w_w_F0[];
	static const OpState* const AllStateTable[];

	static inline OpState handler_pr_w_d_F2() {
		// TODO
		return st_w_d_F2;
	};

	static inline OpState handler_pr_w_d_F3() {
		// TODO
		return st_w_d_F3;
	};

	static inline OpState handler_pr_w_d_26() {
		// TODO
		return st_w_d;
	};

	static inline OpState handler_pr_w_d_2E() {
		// TODO
		return st_w_d;
	};

	static inline OpState handler_pr_w_d_36() {
		// TODO
		return st_w_d;
	};

	static inline OpState handler_pr_w_d_3E() {
		// TODO
		return st_w_d;
	};

	static inline OpState handler_pr_w_d_64() {
		// TODO
		return st_w_d;
	};

	static inline OpState handler_pr_w_d_65() {
		// TODO
		return st_w_d;
	};

	static inline OpState handler_pr_d_d_F0() {
		// TODO
		return st_d_d;
	};

	static inline OpState handler_pr_w_w_F2() {
		// TODO
		return st_w_w_F2;
	};

	static inline OpState handler_pr_w_w_F3() {
		// TODO
		return st_w_w_F3;
	};

	static inline OpState handler_pr_w_w_26() {
		// TODO
		return st_w_w;
	};

	static inline OpState handler_pr_w_w_2E() {
		// TODO
		return st_w_w;
	};

	static inline OpState handler_pr_w_w_36() {
		// TODO
		return st_w_w;
	};

	static inline OpState handler_pr_w_w_3E() {
		// TODO
		return st_w_w;
	};

	static inline OpState handler_pr_w_w_64() {
		// TODO
		return st_w_w;
	};

	static inline OpState handler_pr_w_w_65() {
		// TODO
		return st_w_w;
	};

	static inline OpState handler_pr_d_w_F0() {
		// TODO
		return st_d_w;
	};

	static inline OpState handler_pr_d_d_F2() {
		// TODO
		return st_d_d_F2;
	};

	static inline OpState handler_pr_d_d_F3() {
		// TODO
		return st_d_d_F3;
	};

	static inline OpState handler_pr_d_d_26() {
		// TODO
		return st_d_d;
	};

	static inline OpState handler_pr_d_d_2E() {
		// TODO
		return st_d_d;
	};

	static inline OpState handler_pr_d_d_36() {
		// TODO
		return st_d_d;
	};

	static inline OpState handler_pr_d_d_3E() {
		// TODO
		return st_d_d;
	};

	static inline OpState handler_pr_d_d_64() {
		// TODO
		return st_d_d;
	};

	static inline OpState handler_pr_d_d_65() {
		// TODO
		return st_d_d;
	};

	static inline OpState handler_pr_w_d_F0() {
		// TODO
		return st_w_d;
	};

	static inline OpState handler_pr_d_w_F2() {
		// TODO
		return st_d_w_F2;
	};

	static inline OpState handler_pr_d_w_F3() {
		// TODO
		return st_d_w_F3;
	};

	static inline OpState handler_pr_d_w_26() {
		// TODO
		return st_d_w;
	};

	static inline OpState handler_pr_d_w_2E() {
		// TODO
		return st_d_w;
	};

	static inline OpState handler_pr_d_w_36() {
		// TODO
		return st_d_w;
	};

	static inline OpState handler_pr_d_w_3E() {
		// TODO
		return st_d_w;
	};

	static inline OpState handler_pr_d_w_64() {
		// TODO
		return st_d_w;
	};

	static inline OpState handler_pr_d_w_65() {
		// TODO
		return st_d_w;
	};

	static inline OpState handler_pr_w_w_F0() {
		// TODO
		return st_w_w;
	};
	bool Parse(PhysPt &cseip);
};

/* ADD(()_[0]) : Add */
inline bool handler_ADD_w_rm_mod_reg_u8_rm_reg_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ADD(()_[0]) : Add */
inline bool handler_ADD_d_rm_mod_reg_u8_rm_reg_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ADD(()_[1]) : Add */
inline bool handler_ADD_w_rm_mod_reg_u16_rm_reg_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ADD(()_[1]) : Add */
inline bool handler_ADD_w_rm_mod_reg_u32_rm_reg_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ADD(()_[1]) : Add */
inline bool handler_ADD_d_rm_mod_reg_u16_rm_reg_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ADD(()_[1]) : Add */
inline bool handler_ADD_d_rm_mod_reg_u32_rm_reg_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ADD(()_[2]) : Add */
inline bool handler_ADD_w_rm_reg_reg_u8_rm_mod_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ADD(()_[2]) : Add */
inline bool handler_ADD_d_rm_reg_reg_u8_rm_mod_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ADD(()_[3]) : Add */
inline bool handler_ADD_w_rm_reg_reg_u16_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ADD(()_[3]) : Add */
inline bool handler_ADD_w_rm_reg_reg_u32_rm_mod_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ADD(()_[3]) : Add */
inline bool handler_ADD_d_rm_reg_reg_u16_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ADD(()_[3]) : Add */
inline bool handler_ADD_d_rm_reg_reg_u32_rm_mod_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ADD(()_[4]) : Add */
inline bool handler_ADD_reg_gen_u8_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ADD(()_[5]) : Add */
inline bool handler_ADD_reg_gen_u16_imm_i16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ADD(()_[5]) : Add */
inline bool handler_ADD_reg_gen_u32_imm_i32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PUSH(()_[6]) : Push Word, Doubleword or Quadword Onto the Stack */
inline bool handler_PUSH_reg_seg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* POP(()_[7]) : Pop a Value from the Stack */
inline bool handler_POP_reg_seg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* OR(()_[8]) : Logical Inclusive OR */
inline bool handler_OR_w_rm_mod_reg_u8_rm_reg_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* OR(()_[8]) : Logical Inclusive OR */
inline bool handler_OR_d_rm_mod_reg_u8_rm_reg_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* OR(()_[9]) : Logical Inclusive OR */
inline bool handler_OR_w_rm_mod_reg_u16_rm_reg_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* OR(()_[9]) : Logical Inclusive OR */
inline bool handler_OR_w_rm_mod_reg_u32_rm_reg_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* OR(()_[9]) : Logical Inclusive OR */
inline bool handler_OR_d_rm_mod_reg_u16_rm_reg_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* OR(()_[9]) : Logical Inclusive OR */
inline bool handler_OR_d_rm_mod_reg_u32_rm_reg_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* OR(()_[10]) : Logical Inclusive OR */
inline bool handler_OR_w_rm_reg_reg_u8_rm_mod_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* OR(()_[10]) : Logical Inclusive OR */
inline bool handler_OR_d_rm_reg_reg_u8_rm_mod_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* OR(()_[11]) : Logical Inclusive OR */
inline bool handler_OR_w_rm_reg_reg_u16_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* OR(()_[11]) : Logical Inclusive OR */
inline bool handler_OR_w_rm_reg_reg_u32_rm_mod_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* OR(()_[11]) : Logical Inclusive OR */
inline bool handler_OR_d_rm_reg_reg_u16_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* OR(()_[11]) : Logical Inclusive OR */
inline bool handler_OR_d_rm_reg_reg_u32_rm_mod_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* OR(()_[12]) : Logical Inclusive OR */
inline bool handler_OR_reg_gen_u8_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* OR(()_[13]) : Logical Inclusive OR */
inline bool handler_OR_reg_gen_u16_imm_i16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* OR(()_[13]) : Logical Inclusive OR */
inline bool handler_OR_reg_gen_u32_imm_i32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PUSH(()_[14]) : Push Word, Doubleword or Quadword Onto the Stack */
inline bool handler_PUSH_reg_seg_1_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ADC(()_[16]) : Add with Carry */
inline bool handler_ADC_w_rm_mod_reg_u8_rm_reg_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ADC(()_[16]) : Add with Carry */
inline bool handler_ADC_d_rm_mod_reg_u8_rm_reg_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ADC(()_[17]) : Add with Carry */
inline bool handler_ADC_w_rm_mod_reg_u16_rm_reg_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ADC(()_[17]) : Add with Carry */
inline bool handler_ADC_w_rm_mod_reg_u32_rm_reg_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ADC(()_[17]) : Add with Carry */
inline bool handler_ADC_d_rm_mod_reg_u16_rm_reg_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ADC(()_[17]) : Add with Carry */
inline bool handler_ADC_d_rm_mod_reg_u32_rm_reg_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ADC(()_[18]) : Add with Carry */
inline bool handler_ADC_w_rm_reg_reg_u8_rm_mod_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ADC(()_[18]) : Add with Carry */
inline bool handler_ADC_d_rm_reg_reg_u8_rm_mod_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ADC(()_[19]) : Add with Carry */
inline bool handler_ADC_w_rm_reg_reg_u16_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ADC(()_[19]) : Add with Carry */
inline bool handler_ADC_w_rm_reg_reg_u32_rm_mod_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ADC(()_[19]) : Add with Carry */
inline bool handler_ADC_d_rm_reg_reg_u16_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ADC(()_[19]) : Add with Carry */
inline bool handler_ADC_d_rm_reg_reg_u32_rm_mod_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ADC(()_[20]) : Add with Carry */
inline bool handler_ADC_reg_gen_u8_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ADC(()_[21]) : Add with Carry */
inline bool handler_ADC_reg_gen_u16_imm_i16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ADC(()_[21]) : Add with Carry */
inline bool handler_ADC_reg_gen_u32_imm_i32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PUSH(()_[22]) : Push Word, Doubleword or Quadword Onto the Stack */
inline bool handler_PUSH_reg_seg_2_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* POP(()_[23]) : Pop a Value from the Stack */
inline bool handler_POP_reg_seg_2_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SBB(()_[24]) : Integer Subtraction with Borrow */
inline bool handler_SBB_w_rm_mod_reg_u8_rm_reg_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SBB(()_[24]) : Integer Subtraction with Borrow */
inline bool handler_SBB_d_rm_mod_reg_u8_rm_reg_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SBB(()_[25]) : Integer Subtraction with Borrow */
inline bool handler_SBB_w_rm_mod_reg_u16_rm_reg_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SBB(()_[25]) : Integer Subtraction with Borrow */
inline bool handler_SBB_w_rm_mod_reg_u32_rm_reg_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SBB(()_[25]) : Integer Subtraction with Borrow */
inline bool handler_SBB_d_rm_mod_reg_u16_rm_reg_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SBB(()_[25]) : Integer Subtraction with Borrow */
inline bool handler_SBB_d_rm_mod_reg_u32_rm_reg_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SBB(()_[26]) : Integer Subtraction with Borrow */
inline bool handler_SBB_w_rm_reg_reg_u8_rm_mod_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SBB(()_[26]) : Integer Subtraction with Borrow */
inline bool handler_SBB_d_rm_reg_reg_u8_rm_mod_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SBB(()_[27]) : Integer Subtraction with Borrow */
inline bool handler_SBB_w_rm_reg_reg_u16_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SBB(()_[27]) : Integer Subtraction with Borrow */
inline bool handler_SBB_w_rm_reg_reg_u32_rm_mod_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SBB(()_[27]) : Integer Subtraction with Borrow */
inline bool handler_SBB_d_rm_reg_reg_u16_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SBB(()_[27]) : Integer Subtraction with Borrow */
inline bool handler_SBB_d_rm_reg_reg_u32_rm_mod_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SBB(()_[28]) : Integer Subtraction with Borrow */
inline bool handler_SBB_reg_gen_u8_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SBB(()_[29]) : Integer Subtraction with Borrow */
inline bool handler_SBB_reg_gen_u16_imm_i16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SBB(()_[29]) : Integer Subtraction with Borrow */
inline bool handler_SBB_reg_gen_u32_imm_i32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PUSH(()_[30]) : Push Word, Doubleword or Quadword Onto the Stack */
inline bool handler_PUSH_reg_seg_3_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* POP(()_[31]) : Pop a Value from the Stack */
inline bool handler_POP_reg_seg_3_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* AND(()_[32]) : Logical AND */
inline bool handler_AND_w_rm_mod_reg_u8_rm_reg_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* AND(()_[32]) : Logical AND */
inline bool handler_AND_d_rm_mod_reg_u8_rm_reg_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* AND(()_[33]) : Logical AND */
inline bool handler_AND_w_rm_mod_reg_u16_rm_reg_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* AND(()_[33]) : Logical AND */
inline bool handler_AND_w_rm_mod_reg_u32_rm_reg_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* AND(()_[33]) : Logical AND */
inline bool handler_AND_d_rm_mod_reg_u16_rm_reg_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* AND(()_[33]) : Logical AND */
inline bool handler_AND_d_rm_mod_reg_u32_rm_reg_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* AND(()_[34]) : Logical AND */
inline bool handler_AND_w_rm_reg_reg_u8_rm_mod_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* AND(()_[34]) : Logical AND */
inline bool handler_AND_d_rm_reg_reg_u8_rm_mod_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* AND(()_[35]) : Logical AND */
inline bool handler_AND_w_rm_reg_reg_u16_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* AND(()_[35]) : Logical AND */
inline bool handler_AND_w_rm_reg_reg_u32_rm_mod_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* AND(()_[35]) : Logical AND */
inline bool handler_AND_d_rm_reg_reg_u16_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* AND(()_[35]) : Logical AND */
inline bool handler_AND_d_rm_reg_reg_u32_rm_mod_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* AND(()_[36]) : Logical AND */
inline bool handler_AND_reg_gen_u8_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* AND(()_[37]) : Logical AND */
inline bool handler_AND_reg_gen_u16_imm_i16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* AND(()_[37]) : Logical AND */
inline bool handler_AND_reg_gen_u32_imm_i32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* DAA(()_[39]) : Decimal Adjust AL after Addition */
inline bool handler_DAA(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SUB(()_[40]) : Subtract */
inline bool handler_SUB_w_rm_mod_reg_u8_rm_reg_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SUB(()_[40]) : Subtract */
inline bool handler_SUB_d_rm_mod_reg_u8_rm_reg_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SUB(()_[41]) : Subtract */
inline bool handler_SUB_w_rm_mod_reg_u16_rm_reg_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SUB(()_[41]) : Subtract */
inline bool handler_SUB_w_rm_mod_reg_u32_rm_reg_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SUB(()_[41]) : Subtract */
inline bool handler_SUB_d_rm_mod_reg_u16_rm_reg_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SUB(()_[41]) : Subtract */
inline bool handler_SUB_d_rm_mod_reg_u32_rm_reg_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SUB(()_[42]) : Subtract */
inline bool handler_SUB_w_rm_reg_reg_u8_rm_mod_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SUB(()_[42]) : Subtract */
inline bool handler_SUB_d_rm_reg_reg_u8_rm_mod_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SUB(()_[43]) : Subtract */
inline bool handler_SUB_w_rm_reg_reg_u16_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SUB(()_[43]) : Subtract */
inline bool handler_SUB_w_rm_reg_reg_u32_rm_mod_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SUB(()_[43]) : Subtract */
inline bool handler_SUB_d_rm_reg_reg_u16_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SUB(()_[43]) : Subtract */
inline bool handler_SUB_d_rm_reg_reg_u32_rm_mod_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SUB(()_[44]) : Subtract */
inline bool handler_SUB_reg_gen_u8_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SUB(()_[45]) : Subtract */
inline bool handler_SUB_reg_gen_u16_imm_i16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SUB(()_[45]) : Subtract */
inline bool handler_SUB_reg_gen_u32_imm_i32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* DAS(()_[47]) : Decimal Adjust AL after Subtraction */
inline bool handler_DAS(Bit8u last, PhysPt &cseip) {
	return true;
}

/* XOR(()_[48]) : Logical Exclusive OR */
inline bool handler_XOR_w_rm_mod_reg_u8_rm_reg_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* XOR(()_[48]) : Logical Exclusive OR */
inline bool handler_XOR_d_rm_mod_reg_u8_rm_reg_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* XOR(()_[49]) : Logical Exclusive OR */
inline bool handler_XOR_w_rm_mod_reg_u16_rm_reg_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* XOR(()_[49]) : Logical Exclusive OR */
inline bool handler_XOR_w_rm_mod_reg_u32_rm_reg_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* XOR(()_[49]) : Logical Exclusive OR */
inline bool handler_XOR_d_rm_mod_reg_u16_rm_reg_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* XOR(()_[49]) : Logical Exclusive OR */
inline bool handler_XOR_d_rm_mod_reg_u32_rm_reg_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* XOR(()_[50]) : Logical Exclusive OR */
inline bool handler_XOR_w_rm_reg_reg_u8_rm_mod_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* XOR(()_[50]) : Logical Exclusive OR */
inline bool handler_XOR_d_rm_reg_reg_u8_rm_mod_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* XOR(()_[51]) : Logical Exclusive OR */
inline bool handler_XOR_w_rm_reg_reg_u16_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* XOR(()_[51]) : Logical Exclusive OR */
inline bool handler_XOR_w_rm_reg_reg_u32_rm_mod_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* XOR(()_[51]) : Logical Exclusive OR */
inline bool handler_XOR_d_rm_reg_reg_u16_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* XOR(()_[51]) : Logical Exclusive OR */
inline bool handler_XOR_d_rm_reg_reg_u32_rm_mod_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* XOR(()_[52]) : Logical Exclusive OR */
inline bool handler_XOR_reg_gen_u8_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* XOR(()_[53]) : Logical Exclusive OR */
inline bool handler_XOR_reg_gen_u16_imm_i16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* XOR(()_[53]) : Logical Exclusive OR */
inline bool handler_XOR_reg_gen_u32_imm_i32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* AAA(()_[55]) : ASCII Adjust After Addition */
inline bool handler_AAA(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CMP(()_[56]) : Compare Two Operands */
inline bool handler_CMP_w_rm_reg_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CMP(()_[56]) : Compare Two Operands */
inline bool handler_CMP_d_rm_reg_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CMP(()_[57]) : Compare Two Operands */
inline bool handler_CMP_w_rm_reg_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CMP(()_[57]) : Compare Two Operands */
inline bool handler_CMP_w_rm_reg_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CMP(()_[57]) : Compare Two Operands */
inline bool handler_CMP_d_rm_reg_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CMP(()_[57]) : Compare Two Operands */
inline bool handler_CMP_d_rm_reg_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CMP(()_[58]) : Compare Two Operands */
inline bool handler_CMP_w_rm_mod_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CMP(()_[58]) : Compare Two Operands */
inline bool handler_CMP_d_rm_mod_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CMP(()_[59]) : Compare Two Operands */
inline bool handler_CMP_w_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CMP(()_[59]) : Compare Two Operands */
inline bool handler_CMP_w_rm_mod_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CMP(()_[59]) : Compare Two Operands */
inline bool handler_CMP_d_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CMP(()_[59]) : Compare Two Operands */
inline bool handler_CMP_d_rm_mod_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CMP(()_[60]) : Compare Two Operands */
inline bool handler_CMP_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CMP(()_[61]) : Compare Two Operands */
inline bool handler_CMP_imm_i16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CMP(()_[61]) : Compare Two Operands */
inline bool handler_CMP_imm_i32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* AAS(()_[63]) : ASCII Adjust AL After Subtraction */
inline bool handler_AAS(Bit8u last, PhysPt &cseip) {
	return true;
}

/* INC(()_[64]) : Increment by 1 */
inline bool handler_INC_reg_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* DEC(()_[72]) : Decrement by 1 */
inline bool handler_DEC_reg_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PUSH(()_[80]) : Push Word, Doubleword or Quadword Onto the Stack */
inline bool handler_PUSH_reg_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* POP(()_[88]) : Pop a Value from the Stack */
inline bool handler_POP_reg_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PUSHA(()_[96]) : Push All General-Purpose Registers */
inline bool handler_PUSHA(Bit8u last, PhysPt &cseip) {
	return true;
}

/* POPA(()_[97]) : Pop All General-Purpose Registers */
inline bool handler_POPA(Bit8u last, PhysPt &cseip) {
	return true;
}

/* BOUND(()_[98]) : Check Array Index Against Bounds */
inline bool handler_BOUND_w_rm_mem_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* BOUND(()_[98]) : Check Array Index Against Bounds */
inline bool handler_BOUND_d_rm_mem_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ARPL(()_[99]) : Adjust RPL Field of Segment Selector */
inline bool handler_ARPL_w_rm_reg_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ARPL(()_[99]) : Adjust RPL Field of Segment Selector */
inline bool handler_ARPL_d_rm_reg_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PUSH(()_[104]) : Push Word, Doubleword or Quadword Onto the Stack */
inline bool handler_PUSH_imm_i16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* IMUL(()_[105]) : Signed Multiply */
inline bool handler_IMUL_w_rm_reg_reg_u16_imm_i16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* IMUL(()_[105]) : Signed Multiply */
inline bool handler_IMUL_d_rm_reg_reg_u16_imm_i16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PUSH(()_[106]) : Push Word, Doubleword or Quadword Onto the Stack */
inline bool handler_PUSH_imm_i8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* IMUL(()_[107]) : Signed Multiply */
inline bool handler_IMUL_w_rm_reg_reg_u16_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* IMUL(()_[107]) : Signed Multiply */
inline bool handler_IMUL_d_rm_reg_reg_u16_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* INS(()_[108]) : Input from Port to String */
inline bool handler_INS_w_mem_reg_7_u8_reg_gen_2_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* INS(()_[108]) : Input from Port to String */
inline bool handler_INS_d_mem_reg_7_u8_reg_gen_2_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* INS(()_[109]) : Input from Port to String */
inline bool handler_INS_w_mem_reg_7_u16_reg_gen_2_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* INS(()_[109]) : Input from Port to String */
inline bool handler_INS_d_mem_reg_7_u16_reg_gen_2_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* INS(()_[109]) : Input from Port to String */
inline bool handler_INS_w_mem_reg_7_u32_reg_gen_2_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* INS(()_[109]) : Input from Port to String */
inline bool handler_INS_d_mem_reg_7_u32_reg_gen_2_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* OUTS(()_[110]) : Output String to Port */
inline bool handler_OUTS_w_reg_gen_2_u16_mem_reg_6_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* OUTS(()_[110]) : Output String to Port */
inline bool handler_OUTS_d_reg_gen_2_u16_mem_reg_6_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* OUTS(()_[111]) : Output String to Port */
inline bool handler_OUTS_w_reg_gen_2_u16_mem_reg_6_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* OUTS(()_[111]) : Output String to Port */
inline bool handler_OUTS_d_reg_gen_2_u16_mem_reg_6_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* OUTS(()_[111]) : Output String to Port */
inline bool handler_OUTS_w_reg_gen_2_u16_mem_reg_6_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* OUTS(()_[111]) : Output String to Port */
inline bool handler_OUTS_d_reg_gen_2_u16_mem_reg_6_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* JO(()_[112]) : Jump short if overflow (OF=1) */
inline bool handler_JO_w_mem_imm_J_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* JO(()_[112]) : Jump short if overflow (OF=1) */
inline bool handler_JO_d_mem_imm_J_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* JNO(()_[113]) : Jump short if not overflow (OF=0) */
inline bool handler_JNO_w_mem_imm_J_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* JNO(()_[113]) : Jump short if not overflow (OF=0) */
inline bool handler_JNO_d_mem_imm_J_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* JB(()_[114]) : Jump short if below/not above or equal/carry (CF=1) */
inline bool handler_JB_w_mem_imm_J_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* JB(()_[114]) : Jump short if below/not above or equal/carry (CF=1) */
inline bool handler_JB_d_mem_imm_J_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* JNB(()_[115]) : Jump short if not below/above or equal/not carry (CF=0) */
inline bool handler_JNB_w_mem_imm_J_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* JNB(()_[115]) : Jump short if not below/above or equal/not carry (CF=0) */
inline bool handler_JNB_d_mem_imm_J_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* JZ(()_[116]) : Jump short if zero/equal (ZF=0) */
inline bool handler_JZ_w_mem_imm_J_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* JZ(()_[116]) : Jump short if zero/equal (ZF=0) */
inline bool handler_JZ_d_mem_imm_J_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* JNZ(()_[117]) : Jump short if not zero/not equal (ZF=1) */
inline bool handler_JNZ_w_mem_imm_J_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* JNZ(()_[117]) : Jump short if not zero/not equal (ZF=1) */
inline bool handler_JNZ_d_mem_imm_J_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* JBE(()_[118]) : Jump short if below or equal/not above (CF=1 AND ZF=1) */
inline bool handler_JBE_w_mem_imm_J_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* JBE(()_[118]) : Jump short if below or equal/not above (CF=1 AND ZF=1) */
inline bool handler_JBE_d_mem_imm_J_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* JNBE(()_[119]) : Jump short if not below or equal/above (CF=0 AND ZF=0) */
inline bool handler_JNBE_w_mem_imm_J_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* JNBE(()_[119]) : Jump short if not below or equal/above (CF=0 AND ZF=0) */
inline bool handler_JNBE_d_mem_imm_J_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* JS(()_[120]) : Jump short if sign (SF=1) */
inline bool handler_JS_w_mem_imm_J_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* JS(()_[120]) : Jump short if sign (SF=1) */
inline bool handler_JS_d_mem_imm_J_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* JNS(()_[121]) : Jump short if not sign (SF=0) */
inline bool handler_JNS_w_mem_imm_J_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* JNS(()_[121]) : Jump short if not sign (SF=0) */
inline bool handler_JNS_d_mem_imm_J_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* JP(()_[122]) : Jump short if parity/parity even (PF=1) */
inline bool handler_JP_w_mem_imm_J_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* JP(()_[122]) : Jump short if parity/parity even (PF=1) */
inline bool handler_JP_d_mem_imm_J_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* JNP(()_[123]) : Jump short if not parity/parity odd */
inline bool handler_JNP_w_mem_imm_J_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* JNP(()_[123]) : Jump short if not parity/parity odd */
inline bool handler_JNP_d_mem_imm_J_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* JL(()_[124]) : Jump short if less/not greater (SF!=OF) */
inline bool handler_JL_w_mem_imm_J_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* JL(()_[124]) : Jump short if less/not greater (SF!=OF) */
inline bool handler_JL_d_mem_imm_J_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* JNL(()_[125]) : Jump short if not less/greater or equal (SF=OF) */
inline bool handler_JNL_w_mem_imm_J_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* JNL(()_[125]) : Jump short if not less/greater or equal (SF=OF) */
inline bool handler_JNL_d_mem_imm_J_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* JLE(()_[126]) : Jump short if less or equal/not greater ((ZF=1) OR (SF!=OF)) */
inline bool handler_JLE_w_mem_imm_J_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* JLE(()_[126]) : Jump short if less or equal/not greater ((ZF=1) OR (SF!=OF)) */
inline bool handler_JLE_d_mem_imm_J_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* JNLE(()_[127]) : Jump short if not less nor equal/greater ((ZF=0) AND (SF=OF)) */
inline bool handler_JNLE_w_mem_imm_J_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* JNLE(()_[127]) : Jump short if not less nor equal/greater ((ZF=0) AND (SF=OF)) */
inline bool handler_JNLE_d_mem_imm_J_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ADD(()_[130]) : Add */
inline bool handler_ADD_w_rm_mod_reg_u8_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ADD(()_[130]) : Add */
inline bool handler_ADD_d_rm_mod_reg_u8_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* OR(()_[130]) : Logical Inclusive OR */
inline bool handler_OR_w_rm_mod_reg_u8_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* OR(()_[130]) : Logical Inclusive OR */
inline bool handler_OR_d_rm_mod_reg_u8_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ADC(()_[130]) : Add with Carry */
inline bool handler_ADC_w_rm_mod_reg_u8_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ADC(()_[130]) : Add with Carry */
inline bool handler_ADC_d_rm_mod_reg_u8_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SBB(()_[130]) : Integer Subtraction with Borrow */
inline bool handler_SBB_w_rm_mod_reg_u8_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SBB(()_[130]) : Integer Subtraction with Borrow */
inline bool handler_SBB_d_rm_mod_reg_u8_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* AND(()_[130]) : Logical AND */
inline bool handler_AND_w_rm_mod_reg_u8_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* AND(()_[130]) : Logical AND */
inline bool handler_AND_d_rm_mod_reg_u8_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SUB(()_[130]) : Subtract */
inline bool handler_SUB_w_rm_mod_reg_u8_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SUB(()_[130]) : Subtract */
inline bool handler_SUB_d_rm_mod_reg_u8_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* XOR(()_[130]) : Logical Exclusive OR */
inline bool handler_XOR_w_rm_mod_reg_u8_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* XOR(()_[130]) : Logical Exclusive OR */
inline bool handler_XOR_d_rm_mod_reg_u8_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CMP(()_[130]) : Compare Two Operands */
inline bool handler_CMP_w_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CMP(()_[130]) : Compare Two Operands */
inline bool handler_CMP_d_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ADD(()_[129]) : Add */
inline bool handler_ADD_w_rm_mod_reg_u16_imm_i16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ADD(()_[129]) : Add */
inline bool handler_ADD_w_rm_mod_reg_u32_imm_i32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ADD(()_[129]) : Add */
inline bool handler_ADD_d_rm_mod_reg_u16_imm_i16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ADD(()_[129]) : Add */
inline bool handler_ADD_d_rm_mod_reg_u32_imm_i32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* OR(()_[129]) : Logical Inclusive OR */
inline bool handler_OR_w_rm_mod_reg_u16_imm_i16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* OR(()_[129]) : Logical Inclusive OR */
inline bool handler_OR_w_rm_mod_reg_u32_imm_i32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* OR(()_[129]) : Logical Inclusive OR */
inline bool handler_OR_d_rm_mod_reg_u16_imm_i16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* OR(()_[129]) : Logical Inclusive OR */
inline bool handler_OR_d_rm_mod_reg_u32_imm_i32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ADC(()_[129]) : Add with Carry */
inline bool handler_ADC_w_rm_mod_reg_u16_imm_i16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ADC(()_[129]) : Add with Carry */
inline bool handler_ADC_w_rm_mod_reg_u32_imm_i32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ADC(()_[129]) : Add with Carry */
inline bool handler_ADC_d_rm_mod_reg_u16_imm_i16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ADC(()_[129]) : Add with Carry */
inline bool handler_ADC_d_rm_mod_reg_u32_imm_i32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SBB(()_[129]) : Integer Subtraction with Borrow */
inline bool handler_SBB_w_rm_mod_reg_u16_imm_i16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SBB(()_[129]) : Integer Subtraction with Borrow */
inline bool handler_SBB_w_rm_mod_reg_u32_imm_i32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SBB(()_[129]) : Integer Subtraction with Borrow */
inline bool handler_SBB_d_rm_mod_reg_u16_imm_i16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SBB(()_[129]) : Integer Subtraction with Borrow */
inline bool handler_SBB_d_rm_mod_reg_u32_imm_i32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* AND(()_[129]) : Logical AND */
inline bool handler_AND_w_rm_mod_reg_u16_imm_i16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* AND(()_[129]) : Logical AND */
inline bool handler_AND_w_rm_mod_reg_u32_imm_i32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* AND(()_[129]) : Logical AND */
inline bool handler_AND_d_rm_mod_reg_u16_imm_i16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* AND(()_[129]) : Logical AND */
inline bool handler_AND_d_rm_mod_reg_u32_imm_i32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SUB(()_[129]) : Subtract */
inline bool handler_SUB_w_rm_mod_reg_u16_imm_i16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SUB(()_[129]) : Subtract */
inline bool handler_SUB_w_rm_mod_reg_u32_imm_i32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SUB(()_[129]) : Subtract */
inline bool handler_SUB_d_rm_mod_reg_u16_imm_i16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SUB(()_[129]) : Subtract */
inline bool handler_SUB_d_rm_mod_reg_u32_imm_i32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* XOR(()_[129]) : Logical Exclusive OR */
inline bool handler_XOR_w_rm_mod_reg_u16_imm_i16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* XOR(()_[129]) : Logical Exclusive OR */
inline bool handler_XOR_w_rm_mod_reg_u32_imm_i32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* XOR(()_[129]) : Logical Exclusive OR */
inline bool handler_XOR_d_rm_mod_reg_u16_imm_i16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* XOR(()_[129]) : Logical Exclusive OR */
inline bool handler_XOR_d_rm_mod_reg_u32_imm_i32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CMP(()_[129]) : Compare Two Operands */
inline bool handler_CMP_w_imm_i16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CMP(()_[129]) : Compare Two Operands */
inline bool handler_CMP_w_imm_i32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CMP(()_[129]) : Compare Two Operands */
inline bool handler_CMP_d_imm_i16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CMP(()_[129]) : Compare Two Operands */
inline bool handler_CMP_d_imm_i32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ADD(()_[131]) : Add */
inline bool handler_ADD_w_rm_mod_reg_u16_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ADD(()_[131]) : Add */
inline bool handler_ADD_w_rm_mod_reg_u32_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ADD(()_[131]) : Add */
inline bool handler_ADD_d_rm_mod_reg_u16_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ADD(()_[131]) : Add */
inline bool handler_ADD_d_rm_mod_reg_u32_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* OR(()_[131]) : Logical Inclusive OR */
inline bool handler_OR_w_rm_mod_reg_u16_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* OR(()_[131]) : Logical Inclusive OR */
inline bool handler_OR_w_rm_mod_reg_u32_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* OR(()_[131]) : Logical Inclusive OR */
inline bool handler_OR_d_rm_mod_reg_u16_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* OR(()_[131]) : Logical Inclusive OR */
inline bool handler_OR_d_rm_mod_reg_u32_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ADC(()_[131]) : Add with Carry */
inline bool handler_ADC_w_rm_mod_reg_u16_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ADC(()_[131]) : Add with Carry */
inline bool handler_ADC_w_rm_mod_reg_u32_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ADC(()_[131]) : Add with Carry */
inline bool handler_ADC_d_rm_mod_reg_u16_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ADC(()_[131]) : Add with Carry */
inline bool handler_ADC_d_rm_mod_reg_u32_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SBB(()_[131]) : Integer Subtraction with Borrow */
inline bool handler_SBB_w_rm_mod_reg_u16_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SBB(()_[131]) : Integer Subtraction with Borrow */
inline bool handler_SBB_w_rm_mod_reg_u32_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SBB(()_[131]) : Integer Subtraction with Borrow */
inline bool handler_SBB_d_rm_mod_reg_u16_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SBB(()_[131]) : Integer Subtraction with Borrow */
inline bool handler_SBB_d_rm_mod_reg_u32_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* AND(()_[131]) : Logical AND */
inline bool handler_AND_w_rm_mod_reg_u16_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* AND(()_[131]) : Logical AND */
inline bool handler_AND_w_rm_mod_reg_u32_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* AND(()_[131]) : Logical AND */
inline bool handler_AND_d_rm_mod_reg_u16_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* AND(()_[131]) : Logical AND */
inline bool handler_AND_d_rm_mod_reg_u32_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SUB(()_[131]) : Subtract */
inline bool handler_SUB_w_rm_mod_reg_u16_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SUB(()_[131]) : Subtract */
inline bool handler_SUB_w_rm_mod_reg_u32_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SUB(()_[131]) : Subtract */
inline bool handler_SUB_d_rm_mod_reg_u16_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SUB(()_[131]) : Subtract */
inline bool handler_SUB_d_rm_mod_reg_u32_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* XOR(()_[131]) : Logical Exclusive OR */
inline bool handler_XOR_w_rm_mod_reg_u16_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* XOR(()_[131]) : Logical Exclusive OR */
inline bool handler_XOR_w_rm_mod_reg_u32_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* XOR(()_[131]) : Logical Exclusive OR */
inline bool handler_XOR_d_rm_mod_reg_u16_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* XOR(()_[131]) : Logical Exclusive OR */
inline bool handler_XOR_d_rm_mod_reg_u32_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* TEST(()_[132]) : Logical Compare */
inline bool handler_TEST_w_rm_reg_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* TEST(()_[132]) : Logical Compare */
inline bool handler_TEST_d_rm_reg_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* TEST(()_[133]) : Logical Compare */
inline bool handler_TEST_w_rm_reg_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* TEST(()_[133]) : Logical Compare */
inline bool handler_TEST_w_rm_reg_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* TEST(()_[133]) : Logical Compare */
inline bool handler_TEST_d_rm_reg_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* TEST(()_[133]) : Logical Compare */
inline bool handler_TEST_d_rm_reg_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* XCHG(()_[134]) : Exchange Register/Memory with Register */
inline bool handler_XCHG_w_rm_mod_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* XCHG(()_[134]) : Exchange Register/Memory with Register */
inline bool handler_XCHG_d_rm_mod_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* XCHG(()_[135]) : Exchange Register/Memory with Register */
inline bool handler_XCHG_w_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* XCHG(()_[135]) : Exchange Register/Memory with Register */
inline bool handler_XCHG_w_rm_mod_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* XCHG(()_[135]) : Exchange Register/Memory with Register */
inline bool handler_XCHG_d_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* XCHG(()_[135]) : Exchange Register/Memory with Register */
inline bool handler_XCHG_d_rm_mod_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOV(()_[136]) : Move */
inline bool handler_MOV_w_rm_mod_reg_u8_rm_reg_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOV(()_[136]) : Move */
inline bool handler_MOV_d_rm_mod_reg_u8_rm_reg_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOV(()_[137]) : Move */
inline bool handler_MOV_w_rm_mod_reg_u16_rm_reg_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOV(()_[137]) : Move */
inline bool handler_MOV_w_rm_mod_reg_u32_rm_reg_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOV(()_[137]) : Move */
inline bool handler_MOV_d_rm_mod_reg_u16_rm_reg_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOV(()_[137]) : Move */
inline bool handler_MOV_d_rm_mod_reg_u32_rm_reg_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOV(()_[138]) : Move */
inline bool handler_MOV_w_rm_reg_reg_u8_rm_mod_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOV(()_[138]) : Move */
inline bool handler_MOV_d_rm_reg_reg_u8_rm_mod_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOV(()_[139]) : Move */
inline bool handler_MOV_w_rm_reg_reg_u16_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOV(()_[139]) : Move */
inline bool handler_MOV_d_rm_reg_reg_u16_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOV(()_[140]) : Move */
inline bool handler_MOV_w_rm_mem_u16_rm_reg_seg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOV(()_[140]) : Move */
inline bool handler_MOV_d_rm_mem_u16_rm_reg_seg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* LEA(()_[141]) : Load Effective Address */
inline bool handler_LEA_rm_reg_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOV(()_[142]) : Move */
inline bool handler_MOV_w_rm_reg_seg_u16_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOV(()_[142]) : Move */
inline bool handler_MOV_d_rm_reg_seg_u16_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* POP(()_[143]) : Pop a Value from the Stack */
inline bool handler_POP_w_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* POP(()_[143]) : Pop a Value from the Stack */
inline bool handler_POP_w_rm_mod_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* POP(()_[143]) : Pop a Value from the Stack */
inline bool handler_POP_d_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* POP(()_[143]) : Pop a Value from the Stack */
inline bool handler_POP_d_rm_mod_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* XCHG(()_[144]) : Exchange Register/Memory with Register */
inline bool handler_XCHG_reg_gen_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PAUSE((243,)_[144]) : Spin Loop Hint */
inline bool handler_PAUSE(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CBW(()_[152]) : Convert Byte to Word */
inline bool handler_CBW(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CWDE(()_[152]) : Convert Word to Doubleword */
inline bool handler_CWDE(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CWD(()_[153]) : Convert Word to Doubleword */
inline bool handler_CWD(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CDQ(()_[153]) : Convert Doubleword to Quadword */
inline bool handler_CDQ(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CALLF(()_[154]) : Call Procedure */
inline bool handler_CALLF_w_mem_imm_p32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CALLF(()_[154]) : Call Procedure */
inline bool handler_CALLF_d_mem_imm_p32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* FWAIT(()_[155]) : Check pending unmasked floating-point exceptions */
inline bool handler_FWAIT(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PUSHF(()_[156]) : Push FLAGS Register onto the Stack */
inline bool handler_PUSHF(Bit8u last, PhysPt &cseip) {
	return true;
}

/* POPF(()_[157]) : Pop Stack into FLAGS Register */
inline bool handler_POPF(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOV(()_[160]) : Move */
inline bool handler_MOV_w_reg_gen_u8_mem_imm_O_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOV(()_[160]) : Move */
inline bool handler_MOV_d_reg_gen_u8_mem_imm_O_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOV(()_[161]) : Move */
inline bool handler_MOV_w_reg_gen_u16_mem_imm_O_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOV(()_[161]) : Move */
inline bool handler_MOV_w_reg_gen_u32_mem_imm_O_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOV(()_[161]) : Move */
inline bool handler_MOV_d_reg_gen_u16_mem_imm_O_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOV(()_[161]) : Move */
inline bool handler_MOV_d_reg_gen_u32_mem_imm_O_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOV(()_[162]) : Move */
inline bool handler_MOV_w_mem_imm_O_u8_reg_gen_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOV(()_[162]) : Move */
inline bool handler_MOV_d_mem_imm_O_u8_reg_gen_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOV(()_[163]) : Move */
inline bool handler_MOV_w_mem_imm_O_u16_reg_gen_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOV(()_[163]) : Move */
inline bool handler_MOV_w_mem_imm_O_u32_reg_gen_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOV(()_[163]) : Move */
inline bool handler_MOV_d_mem_imm_O_u16_reg_gen_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOV(()_[163]) : Move */
inline bool handler_MOV_d_mem_imm_O_u32_reg_gen_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVS(()_[164]) : Move Data from String to String */
inline bool handler_MOVS_w_mem_reg_7_u8_mem_reg_6_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVS(()_[164]) : Move Data from String to String */
inline bool handler_MOVS_d_mem_reg_7_u8_mem_reg_6_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVS(()_[165]) : Move Data from String to String */
inline bool handler_MOVS_w_mem_reg_7_u16_mem_reg_6_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVS(()_[165]) : Move Data from String to String */
inline bool handler_MOVS_d_mem_reg_7_u16_mem_reg_6_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVS(()_[165]) : Move Data from String to String */
inline bool handler_MOVS_w_mem_reg_7_u32_mem_reg_6_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVS(()_[165]) : Move Data from String to String */
inline bool handler_MOVS_d_mem_reg_7_u32_mem_reg_6_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CMPS(()_[166]) : Compare String Operands */
inline bool handler_CMPS_w_mem_reg_6_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CMPS(()_[166]) : Compare String Operands */
inline bool handler_CMPS_d_mem_reg_6_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CMPS(()_[167]) : Compare String Operands */
inline bool handler_CMPS_w_mem_reg_6_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CMPS(()_[167]) : Compare String Operands */
inline bool handler_CMPS_d_mem_reg_6_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CMPS(()_[167]) : Compare String Operands */
inline bool handler_CMPS_w_mem_reg_6_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CMPS(()_[167]) : Compare String Operands */
inline bool handler_CMPS_d_mem_reg_6_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* TEST(()_[168]) : Logical Compare */
inline bool handler_TEST_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* TEST(()_[169]) : Logical Compare */
inline bool handler_TEST_imm_i16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* TEST(()_[169]) : Logical Compare */
inline bool handler_TEST_imm_i32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* STOS(()_[170]) : Store String */
inline bool handler_STOS_w_mem_reg_7_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* STOS(()_[170]) : Store String */
inline bool handler_STOS_d_mem_reg_7_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* STOS(()_[171]) : Store String */
inline bool handler_STOS_w_mem_reg_7_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* STOS(()_[171]) : Store String */
inline bool handler_STOS_d_mem_reg_7_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* STOS(()_[171]) : Store String */
inline bool handler_STOS_w_mem_reg_7_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* STOS(()_[171]) : Store String */
inline bool handler_STOS_d_mem_reg_7_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* LODS(()_[172]) : Load String */
inline bool handler_LODS_w_mem_reg_6_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* LODS(()_[172]) : Load String */
inline bool handler_LODS_d_mem_reg_6_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* LODS(()_[173]) : Load String */
inline bool handler_LODS_w_mem_reg_6_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* LODS(()_[173]) : Load String */
inline bool handler_LODS_d_mem_reg_6_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* LODS(()_[173]) : Load String */
inline bool handler_LODS_w_mem_reg_6_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* LODS(()_[173]) : Load String */
inline bool handler_LODS_d_mem_reg_6_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SCAS(()_[174]) : Scan String */
inline bool handler_SCAS_w_mem_reg_7_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SCAS(()_[174]) : Scan String */
inline bool handler_SCAS_d_mem_reg_7_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SCAS(()_[175]) : Scan String */
inline bool handler_SCAS_w_mem_reg_7_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SCAS(()_[175]) : Scan String */
inline bool handler_SCAS_d_mem_reg_7_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SCAS(()_[175]) : Scan String */
inline bool handler_SCAS_w_mem_reg_7_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SCAS(()_[175]) : Scan String */
inline bool handler_SCAS_d_mem_reg_7_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOV(()_[176]) : Move */
inline bool handler_MOV_reg_reg_u8_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOV(()_[184]) : Move */
inline bool handler_MOV_reg_reg_u16_imm_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ROL(()_[192]) : Rotate */
inline bool handler_ROL_w_rm_mod_reg_u8_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ROL(()_[192]) : Rotate */
inline bool handler_ROL_d_rm_mod_reg_u8_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ROR(()_[192]) : Rotate */
inline bool handler_ROR_w_rm_mod_reg_u8_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ROR(()_[192]) : Rotate */
inline bool handler_ROR_d_rm_mod_reg_u8_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* RCL(()_[192]) : Rotate */
inline bool handler_RCL_w_rm_mod_reg_u8_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* RCL(()_[192]) : Rotate */
inline bool handler_RCL_d_rm_mod_reg_u8_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* RCR(()_[192]) : Rotate */
inline bool handler_RCR_w_rm_mod_reg_u8_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* RCR(()_[192]) : Rotate */
inline bool handler_RCR_d_rm_mod_reg_u8_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SHL(()_[192]) : Shift */
inline bool handler_SHL_w_rm_mod_reg_u8_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SHL(()_[192]) : Shift */
inline bool handler_SHL_d_rm_mod_reg_u8_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SHR(()_[192]) : Shift */
inline bool handler_SHR_w_rm_mod_reg_u8_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SHR(()_[192]) : Shift */
inline bool handler_SHR_d_rm_mod_reg_u8_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SAR(()_[192]) : Shift */
inline bool handler_SAR_w_rm_mod_reg_u8_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SAR(()_[192]) : Shift */
inline bool handler_SAR_d_rm_mod_reg_u8_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ROL(()_[193]) : Rotate */
inline bool handler_ROL_w_rm_mod_reg_u16_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ROL(()_[193]) : Rotate */
inline bool handler_ROL_w_rm_mod_reg_u32_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ROL(()_[193]) : Rotate */
inline bool handler_ROL_d_rm_mod_reg_u16_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ROL(()_[193]) : Rotate */
inline bool handler_ROL_d_rm_mod_reg_u32_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ROR(()_[193]) : Rotate */
inline bool handler_ROR_w_rm_mod_reg_u16_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ROR(()_[193]) : Rotate */
inline bool handler_ROR_w_rm_mod_reg_u32_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ROR(()_[193]) : Rotate */
inline bool handler_ROR_d_rm_mod_reg_u16_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ROR(()_[193]) : Rotate */
inline bool handler_ROR_d_rm_mod_reg_u32_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* RCL(()_[193]) : Rotate */
inline bool handler_RCL_w_rm_mod_reg_u16_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* RCL(()_[193]) : Rotate */
inline bool handler_RCL_w_rm_mod_reg_u32_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* RCL(()_[193]) : Rotate */
inline bool handler_RCL_d_rm_mod_reg_u16_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* RCL(()_[193]) : Rotate */
inline bool handler_RCL_d_rm_mod_reg_u32_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* RCR(()_[193]) : Rotate */
inline bool handler_RCR_w_rm_mod_reg_u16_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* RCR(()_[193]) : Rotate */
inline bool handler_RCR_w_rm_mod_reg_u32_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* RCR(()_[193]) : Rotate */
inline bool handler_RCR_d_rm_mod_reg_u16_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* RCR(()_[193]) : Rotate */
inline bool handler_RCR_d_rm_mod_reg_u32_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SHL(()_[193]) : Shift */
inline bool handler_SHL_w_rm_mod_reg_u16_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SHL(()_[193]) : Shift */
inline bool handler_SHL_w_rm_mod_reg_u32_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SHL(()_[193]) : Shift */
inline bool handler_SHL_d_rm_mod_reg_u16_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SHL(()_[193]) : Shift */
inline bool handler_SHL_d_rm_mod_reg_u32_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SHR(()_[193]) : Shift */
inline bool handler_SHR_w_rm_mod_reg_u16_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SHR(()_[193]) : Shift */
inline bool handler_SHR_w_rm_mod_reg_u32_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SHR(()_[193]) : Shift */
inline bool handler_SHR_d_rm_mod_reg_u16_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SHR(()_[193]) : Shift */
inline bool handler_SHR_d_rm_mod_reg_u32_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SAR(()_[193]) : Shift */
inline bool handler_SAR_w_rm_mod_reg_u16_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SAR(()_[193]) : Shift */
inline bool handler_SAR_w_rm_mod_reg_u32_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SAR(()_[193]) : Shift */
inline bool handler_SAR_d_rm_mod_reg_u16_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SAR(()_[193]) : Shift */
inline bool handler_SAR_d_rm_mod_reg_u32_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* RETN(()_[194]) : Return from procedure */
inline bool handler_RETN_imm_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* RETN(()_[195]) : Return from procedure */
inline bool handler_RETN(Bit8u last, PhysPt &cseip) {
	return true;
}

/* LES(()_[196]) : Load Far Pointer */
inline bool handler_LES_w_rm_reg_reg_u16_rm_mem_p32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* LES(()_[196]) : Load Far Pointer */
inline bool handler_LES_d_rm_reg_reg_u16_rm_mem_p32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* LDS(()_[197]) : Load Far Pointer */
inline bool handler_LDS_w_rm_reg_reg_u16_rm_mem_p32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* LDS(()_[197]) : Load Far Pointer */
inline bool handler_LDS_d_rm_reg_reg_u16_rm_mem_p32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOV(()_[198]) : Move */
inline bool handler_MOV_w_rm_mod_reg_u8_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOV(()_[198]) : Move */
inline bool handler_MOV_d_rm_mod_reg_u8_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOV(()_[199]) : Move */
inline bool handler_MOV_w_rm_mod_reg_u16_imm_i16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOV(()_[199]) : Move */
inline bool handler_MOV_w_rm_mod_reg_u32_imm_i32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOV(()_[199]) : Move */
inline bool handler_MOV_d_rm_mod_reg_u16_imm_i16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOV(()_[199]) : Move */
inline bool handler_MOV_d_rm_mod_reg_u32_imm_i32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ENTER(()_[200]) : Make Stack Frame for Procedure Parameters */
inline bool handler_ENTER_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* LEAVE(()_[201]) : High Level Procedure Exit */
inline bool handler_LEAVE(Bit8u last, PhysPt &cseip) {
	return true;
}

/* RETF(()_[202]) : Return from procedure */
inline bool handler_RETF_imm_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* RETF(()_[203]) : Return from procedure */
inline bool handler_RETF(Bit8u last, PhysPt &cseip) {
	return true;
}

/* INT(()_[204]) : Call to Interrupt Procedure */
inline bool handler_INT(Bit8u last, PhysPt &cseip) {
	return true;
}

/* INT(()_[205]) : Call to Interrupt Procedure */
inline bool handler_INT_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* INTO(()_[206]) : Call to Interrupt Procedure */
inline bool handler_INTO(Bit8u last, PhysPt &cseip) {
	return true;
}

/* IRET(()_[207]) : Interrupt Return */
inline bool handler_IRET(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ROL(()_[208]) : Rotate */
inline bool handler_ROL_w_rm_mod_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ROL(()_[208]) : Rotate */
inline bool handler_ROL_d_rm_mod_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ROR(()_[208]) : Rotate */
inline bool handler_ROR_w_rm_mod_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ROR(()_[208]) : Rotate */
inline bool handler_ROR_d_rm_mod_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* RCL(()_[208]) : Rotate */
inline bool handler_RCL_w_rm_mod_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* RCL(()_[208]) : Rotate */
inline bool handler_RCL_d_rm_mod_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* RCR(()_[208]) : Rotate */
inline bool handler_RCR_w_rm_mod_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* RCR(()_[208]) : Rotate */
inline bool handler_RCR_d_rm_mod_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SHL(()_[208]) : Shift */
inline bool handler_SHL_w_rm_mod_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SHL(()_[208]) : Shift */
inline bool handler_SHL_d_rm_mod_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SHR(()_[208]) : Shift */
inline bool handler_SHR_w_rm_mod_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SHR(()_[208]) : Shift */
inline bool handler_SHR_d_rm_mod_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SAR(()_[208]) : Shift */
inline bool handler_SAR_w_rm_mod_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SAR(()_[208]) : Shift */
inline bool handler_SAR_d_rm_mod_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ROL(()_[209]) : Rotate */
inline bool handler_ROL_w_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ROL(()_[209]) : Rotate */
inline bool handler_ROL_w_rm_mod_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ROL(()_[209]) : Rotate */
inline bool handler_ROL_d_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ROL(()_[209]) : Rotate */
inline bool handler_ROL_d_rm_mod_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ROR(()_[209]) : Rotate */
inline bool handler_ROR_w_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ROR(()_[209]) : Rotate */
inline bool handler_ROR_w_rm_mod_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ROR(()_[209]) : Rotate */
inline bool handler_ROR_d_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ROR(()_[209]) : Rotate */
inline bool handler_ROR_d_rm_mod_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* RCL(()_[209]) : Rotate */
inline bool handler_RCL_w_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* RCL(()_[209]) : Rotate */
inline bool handler_RCL_w_rm_mod_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* RCL(()_[209]) : Rotate */
inline bool handler_RCL_d_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* RCL(()_[209]) : Rotate */
inline bool handler_RCL_d_rm_mod_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* RCR(()_[209]) : Rotate */
inline bool handler_RCR_w_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* RCR(()_[209]) : Rotate */
inline bool handler_RCR_w_rm_mod_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* RCR(()_[209]) : Rotate */
inline bool handler_RCR_d_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* RCR(()_[209]) : Rotate */
inline bool handler_RCR_d_rm_mod_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SHL(()_[209]) : Shift */
inline bool handler_SHL_w_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SHL(()_[209]) : Shift */
inline bool handler_SHL_w_rm_mod_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SHL(()_[209]) : Shift */
inline bool handler_SHL_d_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SHL(()_[209]) : Shift */
inline bool handler_SHL_d_rm_mod_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SHR(()_[209]) : Shift */
inline bool handler_SHR_w_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SHR(()_[209]) : Shift */
inline bool handler_SHR_w_rm_mod_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SHR(()_[209]) : Shift */
inline bool handler_SHR_d_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SHR(()_[209]) : Shift */
inline bool handler_SHR_d_rm_mod_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SAR(()_[209]) : Shift */
inline bool handler_SAR_w_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SAR(()_[209]) : Shift */
inline bool handler_SAR_w_rm_mod_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SAR(()_[209]) : Shift */
inline bool handler_SAR_d_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SAR(()_[209]) : Shift */
inline bool handler_SAR_d_rm_mod_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ROL(()_[210]) : Rotate */
inline bool handler_ROL_w_rm_mod_reg_u8_reg_gen_1_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ROL(()_[210]) : Rotate */
inline bool handler_ROL_d_rm_mod_reg_u8_reg_gen_1_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ROR(()_[210]) : Rotate */
inline bool handler_ROR_w_rm_mod_reg_u8_reg_gen_1_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ROR(()_[210]) : Rotate */
inline bool handler_ROR_d_rm_mod_reg_u8_reg_gen_1_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* RCL(()_[210]) : Rotate */
inline bool handler_RCL_w_rm_mod_reg_u8_reg_gen_1_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* RCL(()_[210]) : Rotate */
inline bool handler_RCL_d_rm_mod_reg_u8_reg_gen_1_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* RCR(()_[210]) : Rotate */
inline bool handler_RCR_w_rm_mod_reg_u8_reg_gen_1_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* RCR(()_[210]) : Rotate */
inline bool handler_RCR_d_rm_mod_reg_u8_reg_gen_1_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SHL(()_[210]) : Shift */
inline bool handler_SHL_w_rm_mod_reg_u8_reg_gen_1_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SHL(()_[210]) : Shift */
inline bool handler_SHL_d_rm_mod_reg_u8_reg_gen_1_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SHR(()_[210]) : Shift */
inline bool handler_SHR_w_rm_mod_reg_u8_reg_gen_1_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SHR(()_[210]) : Shift */
inline bool handler_SHR_d_rm_mod_reg_u8_reg_gen_1_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SAR(()_[210]) : Shift */
inline bool handler_SAR_w_rm_mod_reg_u8_reg_gen_1_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SAR(()_[210]) : Shift */
inline bool handler_SAR_d_rm_mod_reg_u8_reg_gen_1_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ROL(()_[211]) : Rotate */
inline bool handler_ROL_w_rm_mod_reg_u16_reg_gen_1_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ROL(()_[211]) : Rotate */
inline bool handler_ROL_w_rm_mod_reg_u32_reg_gen_1_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ROL(()_[211]) : Rotate */
inline bool handler_ROL_d_rm_mod_reg_u16_reg_gen_1_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ROL(()_[211]) : Rotate */
inline bool handler_ROL_d_rm_mod_reg_u32_reg_gen_1_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ROR(()_[211]) : Rotate */
inline bool handler_ROR_w_rm_mod_reg_u16_reg_gen_1_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ROR(()_[211]) : Rotate */
inline bool handler_ROR_w_rm_mod_reg_u32_reg_gen_1_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ROR(()_[211]) : Rotate */
inline bool handler_ROR_d_rm_mod_reg_u16_reg_gen_1_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ROR(()_[211]) : Rotate */
inline bool handler_ROR_d_rm_mod_reg_u32_reg_gen_1_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* RCL(()_[211]) : Rotate */
inline bool handler_RCL_w_rm_mod_reg_u16_reg_gen_1_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* RCL(()_[211]) : Rotate */
inline bool handler_RCL_w_rm_mod_reg_u32_reg_gen_1_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* RCL(()_[211]) : Rotate */
inline bool handler_RCL_d_rm_mod_reg_u16_reg_gen_1_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* RCL(()_[211]) : Rotate */
inline bool handler_RCL_d_rm_mod_reg_u32_reg_gen_1_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* RCR(()_[211]) : Rotate */
inline bool handler_RCR_w_rm_mod_reg_u16_reg_gen_1_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* RCR(()_[211]) : Rotate */
inline bool handler_RCR_w_rm_mod_reg_u32_reg_gen_1_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* RCR(()_[211]) : Rotate */
inline bool handler_RCR_d_rm_mod_reg_u16_reg_gen_1_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* RCR(()_[211]) : Rotate */
inline bool handler_RCR_d_rm_mod_reg_u32_reg_gen_1_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SHL(()_[211]) : Shift */
inline bool handler_SHL_w_rm_mod_reg_u16_reg_gen_1_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SHL(()_[211]) : Shift */
inline bool handler_SHL_w_rm_mod_reg_u32_reg_gen_1_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SHL(()_[211]) : Shift */
inline bool handler_SHL_d_rm_mod_reg_u16_reg_gen_1_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SHL(()_[211]) : Shift */
inline bool handler_SHL_d_rm_mod_reg_u32_reg_gen_1_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SHR(()_[211]) : Shift */
inline bool handler_SHR_w_rm_mod_reg_u16_reg_gen_1_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SHR(()_[211]) : Shift */
inline bool handler_SHR_w_rm_mod_reg_u32_reg_gen_1_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SHR(()_[211]) : Shift */
inline bool handler_SHR_d_rm_mod_reg_u16_reg_gen_1_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SHR(()_[211]) : Shift */
inline bool handler_SHR_d_rm_mod_reg_u32_reg_gen_1_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SAR(()_[211]) : Shift */
inline bool handler_SAR_w_rm_mod_reg_u16_reg_gen_1_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SAR(()_[211]) : Shift */
inline bool handler_SAR_w_rm_mod_reg_u32_reg_gen_1_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SAR(()_[211]) : Shift */
inline bool handler_SAR_d_rm_mod_reg_u16_reg_gen_1_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SAR(()_[211]) : Shift */
inline bool handler_SAR_d_rm_mod_reg_u32_reg_gen_1_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* AMX(()_[212]) : Adjust AX After Multiply */
inline bool handler_AMX_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ADX(()_[213]) : Adjust AX Before Division */
inline bool handler_ADX_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* XLAT(()_[215]) : Table Look-up Translation */
inline bool handler_XLAT_w_mem_reg_3_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* XLAT(()_[215]) : Table Look-up Translation */
inline bool handler_XLAT_d_mem_reg_3_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* LOOPNZ(()_[224]) : Decrement count; Jump short if count!=0 and ZF=0 */
inline bool handler_LOOPNZ_w_mem_imm_J_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* LOOPNZ(()_[224]) : Decrement count; Jump short if count!=0 and ZF=0 */
inline bool handler_LOOPNZ_d_mem_imm_J_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* LOOPZ(()_[225]) : Decrement count; Jump short if count!=0 and ZF=1 */
inline bool handler_LOOPZ_w_mem_imm_J_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* LOOPZ(()_[225]) : Decrement count; Jump short if count!=0 and ZF=1 */
inline bool handler_LOOPZ_d_mem_imm_J_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* LOOP(()_[226]) : Decrement count; Jump short if count!=0 */
inline bool handler_LOOP_w_mem_imm_J_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* LOOP(()_[226]) : Decrement count; Jump short if count!=0 */
inline bool handler_LOOP_d_mem_imm_J_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* JCXZ(()_[227]) : Jump short if eCX register is 0 */
inline bool handler_JCXZ_w_mem_imm_J_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* JCXZ(()_[227]) : Jump short if eCX register is 0 */
inline bool handler_JCXZ_d_mem_imm_J_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* IN(()_[228]) : Input from Port */
inline bool handler_IN_reg_gen_u8_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* IN(()_[229]) : Input from Port */
inline bool handler_IN_reg_gen_u16_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* IN(()_[229]) : Input from Port */
inline bool handler_IN_reg_gen_u32_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* OUT(()_[230]) : Output to Port */
inline bool handler_OUT_imm_u8_reg_gen_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* OUT(()_[231]) : Output to Port */
inline bool handler_OUT_imm_u8_reg_gen_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* OUT(()_[231]) : Output to Port */
inline bool handler_OUT_imm_u8_reg_gen_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* JMPF(()_[234]) : Jump */
inline bool handler_JMPF_w_mem_imm_p32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* JMPF(()_[234]) : Jump */
inline bool handler_JMPF_d_mem_imm_p32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* JMP(()_[235]) : Jump */
inline bool handler_JMP_w_mem_imm_J_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* JMP(()_[235]) : Jump */
inline bool handler_JMP_d_mem_imm_J_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* IN(()_[236]) : Input from Port */
inline bool handler_IN_reg_gen_u8_reg_gen_2_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* IN(()_[237]) : Input from Port */
inline bool handler_IN_reg_gen_u16_reg_gen_2_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* IN(()_[237]) : Input from Port */
inline bool handler_IN_reg_gen_u32_reg_gen_2_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* OUT(()_[238]) : Output to Port */
inline bool handler_OUT_reg_gen_2_u16_reg_gen_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* OUT(()_[239]) : Output to Port */
inline bool handler_OUT_reg_gen_2_u16_reg_gen_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* OUT(()_[239]) : Output to Port */
inline bool handler_OUT_reg_gen_2_u16_reg_gen_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* HLT(()_[244]) : Halt */
inline bool handler_HLT(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CMC(()_[245]) : Complement Carry Flag */
inline bool handler_CMC(Bit8u last, PhysPt &cseip) {
	return true;
}

/* TEST(()_[246]) : Logical Compare */
inline bool handler_TEST_w_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* TEST(()_[246]) : Logical Compare */
inline bool handler_TEST_d_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* NOT(()_[246]) : One's Complement Negation */
inline bool handler_NOT_w_rm_mod_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* NOT(()_[246]) : One's Complement Negation */
inline bool handler_NOT_d_rm_mod_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* NEG(()_[246]) : Two's Complement Negation */
inline bool handler_NEG_w_rm_mod_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* NEG(()_[246]) : Two's Complement Negation */
inline bool handler_NEG_d_rm_mod_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MUL(()_[246]) : Unsigned Multiply */
inline bool handler_MUL_w_rm_mod_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MUL(()_[246]) : Unsigned Multiply */
inline bool handler_MUL_d_rm_mod_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* IMUL(()_[246]) : Signed Multiply */
inline bool handler_IMUL_w_rm_mod_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* IMUL(()_[246]) : Signed Multiply */
inline bool handler_IMUL_d_rm_mod_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* DIV(()_[246]) : Unsigned Divide */
inline bool handler_DIV_w_rm_mod_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* DIV(()_[246]) : Unsigned Divide */
inline bool handler_DIV_d_rm_mod_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* IDIV(()_[246]) : Signed Divide */
inline bool handler_IDIV_w_rm_mod_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* IDIV(()_[246]) : Signed Divide */
inline bool handler_IDIV_d_rm_mod_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* TEST(()_[247]) : Logical Compare */
inline bool handler_TEST_w_imm_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* TEST(()_[247]) : Logical Compare */
inline bool handler_TEST_w_imm_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* TEST(()_[247]) : Logical Compare */
inline bool handler_TEST_d_imm_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* TEST(()_[247]) : Logical Compare */
inline bool handler_TEST_d_imm_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* NOT(()_[247]) : One's Complement Negation */
inline bool handler_NOT_w_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* NOT(()_[247]) : One's Complement Negation */
inline bool handler_NOT_w_rm_mod_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* NOT(()_[247]) : One's Complement Negation */
inline bool handler_NOT_d_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* NOT(()_[247]) : One's Complement Negation */
inline bool handler_NOT_d_rm_mod_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* NEG(()_[247]) : Two's Complement Negation */
inline bool handler_NEG_w_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* NEG(()_[247]) : Two's Complement Negation */
inline bool handler_NEG_w_rm_mod_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* NEG(()_[247]) : Two's Complement Negation */
inline bool handler_NEG_d_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* NEG(()_[247]) : Two's Complement Negation */
inline bool handler_NEG_d_rm_mod_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MUL(()_[247]) : Unsigned Multiply */
inline bool handler_MUL_w_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MUL(()_[247]) : Unsigned Multiply */
inline bool handler_MUL_w_rm_mod_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MUL(()_[247]) : Unsigned Multiply */
inline bool handler_MUL_d_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MUL(()_[247]) : Unsigned Multiply */
inline bool handler_MUL_d_rm_mod_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* IMUL(()_[247]) : Signed Multiply */
inline bool handler_IMUL_w_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* IMUL(()_[247]) : Signed Multiply */
inline bool handler_IMUL_d_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* DIV(()_[247]) : Unsigned Divide */
inline bool handler_DIV_w_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* DIV(()_[247]) : Unsigned Divide */
inline bool handler_DIV_d_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* IDIV(()_[247]) : Signed Divide */
inline bool handler_IDIV_w_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* IDIV(()_[247]) : Signed Divide */
inline bool handler_IDIV_d_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CLC(()_[248]) : Clear Carry Flag */
inline bool handler_CLC(Bit8u last, PhysPt &cseip) {
	return true;
}

/* STC(()_[249]) : Set Carry Flag */
inline bool handler_STC(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CLI(()_[250]) : Clear Interrupt Flag */
inline bool handler_CLI(Bit8u last, PhysPt &cseip) {
	return true;
}

/* STI(()_[251]) : Set Interrupt Flag */
inline bool handler_STI(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CLD(()_[252]) : Clear Direction Flag */
inline bool handler_CLD(Bit8u last, PhysPt &cseip) {
	return true;
}

/* STD(()_[253]) : Set Direction Flag */
inline bool handler_STD(Bit8u last, PhysPt &cseip) {
	return true;
}

/* INC(()_[254]) : Increment by 1 */
inline bool handler_INC_w_rm_mod_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* INC(()_[254]) : Increment by 1 */
inline bool handler_INC_d_rm_mod_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* DEC(()_[254]) : Decrement by 1 */
inline bool handler_DEC_w_rm_mod_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* DEC(()_[254]) : Decrement by 1 */
inline bool handler_DEC_d_rm_mod_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* INC(()_[255]) : Increment by 1 */
inline bool handler_INC_w_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* INC(()_[255]) : Increment by 1 */
inline bool handler_INC_w_rm_mod_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* INC(()_[255]) : Increment by 1 */
inline bool handler_INC_d_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* INC(()_[255]) : Increment by 1 */
inline bool handler_INC_d_rm_mod_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* DEC(()_[255]) : Decrement by 1 */
inline bool handler_DEC_w_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* DEC(()_[255]) : Decrement by 1 */
inline bool handler_DEC_w_rm_mod_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* DEC(()_[255]) : Decrement by 1 */
inline bool handler_DEC_d_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* DEC(()_[255]) : Decrement by 1 */
inline bool handler_DEC_d_rm_mod_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CALL(()_[255]) : Call Procedure */
inline bool handler_CALL_w_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CALL(()_[255]) : Call Procedure */
inline bool handler_CALL_d_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* JMP(()_[255]) : Jump */
inline bool handler_JMP_w_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* JMP(()_[255]) : Jump */
inline bool handler_JMP_d_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PUSH(()_[255]) : Push Word, Doubleword or Quadword Onto the Stack */
inline bool handler_PUSH_w_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PUSH(()_[255]) : Push Word, Doubleword or Quadword Onto the Stack */
inline bool handler_PUSH_d_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SLDT(()_[15, 0]) : Store Local Descriptor Table Register */
inline bool handler_SLDT_w_rm_mem_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SLDT(()_[15, 0]) : Store Local Descriptor Table Register */
inline bool handler_SLDT_d_rm_mem_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* STR(()_[15, 0]) : Store Task Register */
inline bool handler_STR_w_rm_mem_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* STR(()_[15, 0]) : Store Task Register */
inline bool handler_STR_d_rm_mem_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* LLDT(()_[15, 0]) : Load Local Descriptor Table Register */
inline bool handler_LLDT_w_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* LLDT(()_[15, 0]) : Load Local Descriptor Table Register */
inline bool handler_LLDT_d_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* LTR(()_[15, 0]) : Load Task Register */
inline bool handler_LTR_w_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* LTR(()_[15, 0]) : Load Task Register */
inline bool handler_LTR_d_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* VERR(()_[15, 0]) : Verify a Segment for Reading */
inline bool handler_VERR_w_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* VERR(()_[15, 0]) : Verify a Segment for Reading */
inline bool handler_VERR_d_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* VERW(()_[15, 0]) : Verify a Segment for Writing */
inline bool handler_VERW_w_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* VERW(()_[15, 0]) : Verify a Segment for Writing */
inline bool handler_VERW_d_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SGDT(()_[15, 1]) : Store Global Descriptor Table Register */
inline bool handler_SGDT_w_rm_mem_x48(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SGDT(()_[15, 1]) : Store Global Descriptor Table Register */
inline bool handler_SGDT_d_rm_mem_x48(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SIDT(()_[15, 1]) : Store Interrupt Descriptor Table Register */
inline bool handler_SIDT_w_rm_mem_x48(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SIDT(()_[15, 1]) : Store Interrupt Descriptor Table Register */
inline bool handler_SIDT_d_rm_mem_x48(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MONITOR(()_[15, 1, 200]) : Set Up Monitor Address */
inline bool handler_MONITOR_w(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MONITOR(()_[15, 1, 200]) : Set Up Monitor Address */
inline bool handler_MONITOR_d(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MWAIT(()_[15, 1, 201]) : Monitor Wait */
inline bool handler_MWAIT(Bit8u last, PhysPt &cseip) {
	return true;
}

/* LGDT(()_[15, 1]) : Load Global Descriptor Table Register */
inline bool handler_LGDT_w_rm_mem_x48(Bit8u last, PhysPt &cseip) {
	return true;
}

/* LGDT(()_[15, 1]) : Load Global Descriptor Table Register */
inline bool handler_LGDT_d_rm_mem_x48(Bit8u last, PhysPt &cseip) {
	return true;
}

/* XGETBV(()_[15, 1, 208]) : Get Value of Extended Control Register */
inline bool handler_XGETBV(Bit8u last, PhysPt &cseip) {
	return true;
}

/* XSETBV(()_[15, 1, 209]) : Set Extended Control Register */
inline bool handler_XSETBV(Bit8u last, PhysPt &cseip) {
	return true;
}

/* LIDT(()_[15, 1]) : Load Interrupt Descriptor Table Register */
inline bool handler_LIDT_w_rm_mem_x48(Bit8u last, PhysPt &cseip) {
	return true;
}

/* LIDT(()_[15, 1]) : Load Interrupt Descriptor Table Register */
inline bool handler_LIDT_d_rm_mem_x48(Bit8u last, PhysPt &cseip) {
	return true;
}

/* LMSW(()_[15, 1]) : Load Machine Status Word */
inline bool handler_LMSW_w_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* LMSW(()_[15, 1]) : Load Machine Status Word */
inline bool handler_LMSW_d_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* INVLPG(()_[15, 1]) : Invalidate TLB Entry */
inline bool handler_INVLPG(Bit8u last, PhysPt &cseip) {
	return true;
}

/* RDTSCP(()_[15, 1, 249]) : Read Time-Stamp Counter and Processor ID */
inline bool handler_RDTSCP(Bit8u last, PhysPt &cseip) {
	return true;
}

/* LAR(()_[15, 2]) : Load Access Rights Byte */
inline bool handler_LAR_w_rm_reg_reg_u16_rm_mem_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* LAR(()_[15, 2]) : Load Access Rights Byte */
inline bool handler_LAR_d_rm_reg_reg_u16_rm_mem_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* LSL(()_[15, 3]) : Load Segment Limit */
inline bool handler_LSL_w_rm_reg_reg_u16_rm_mem_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* LSL(()_[15, 3]) : Load Segment Limit */
inline bool handler_LSL_d_rm_reg_reg_u16_rm_mem_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* LOADALL(()_[15, 7]) : Load All of the CPU Registers */
inline bool handler_LOADALL(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CLTS(()_[15, 6]) : Clear Task-Switched Flag in CR0 */
inline bool handler_CLTS(Bit8u last, PhysPt &cseip) {
	return true;
}

/* INVD(()_[15, 8]) : Invalidate Internal Caches */
inline bool handler_INVD(Bit8u last, PhysPt &cseip) {
	return true;
}

/* WBINVD(()_[15, 9]) : Write Back and Invalidate Cache */
inline bool handler_WBINVD(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVUPS(()_[15, 16]) : Move Unaligned Packed Single-FP Values */
inline bool handler_MOVUPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVUPS(()_[15, 16]) : Move Unaligned Packed Single-FP Values */
inline bool handler_MOVUPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVSS((243,)_[15, 16]) : Move Scalar Single-FP Values */
inline bool handler_MOVSS_w_rm_reg_xmm_f128_rm_mod_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVSS((243,)_[15, 16]) : Move Scalar Single-FP Values */
inline bool handler_MOVSS_d_rm_reg_xmm_f128_rm_mod_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVUPD((102,)_[15, 16]) : Move Unaligned Packed Double-FP Value */
inline bool handler_MOVUPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVUPD((102,)_[15, 16]) : Move Unaligned Packed Double-FP Value */
inline bool handler_MOVUPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVSD((242,)_[15, 16]) : Move Scalar Double-FP Value */
inline bool handler_MOVSD_w_rm_reg_xmm_d128_rm_mod_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVSD((242,)_[15, 16]) : Move Scalar Double-FP Value */
inline bool handler_MOVSD_d_rm_reg_xmm_d128_rm_mod_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVUPS(()_[15, 17]) : Move Unaligned Packed Single-FP Values */
inline bool handler_MOVUPS_w_rm_mod_xmm_f128_rm_reg_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVUPS(()_[15, 17]) : Move Unaligned Packed Single-FP Values */
inline bool handler_MOVUPS_d_rm_mod_xmm_f128_rm_reg_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVSS((243,)_[15, 17]) : Move Scalar Single-FP Values */
inline bool handler_MOVSS_w_rm_mod_xmm_f128_rm_reg_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVSS((243,)_[15, 17]) : Move Scalar Single-FP Values */
inline bool handler_MOVSS_d_rm_mod_xmm_f128_rm_reg_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVUPD((102,)_[15, 17]) : Move Unaligned Packed Double-FP Values */
inline bool handler_MOVUPD_w_rm_mod_xmm_d128_rm_reg_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVUPD((102,)_[15, 17]) : Move Unaligned Packed Double-FP Values */
inline bool handler_MOVUPD_d_rm_mod_xmm_d128_rm_reg_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVSD((242,)_[15, 17]) : Move Scalar Double-FP Value */
inline bool handler_MOVSD_w_rm_mod_xmm_d128_rm_reg_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVSD((242,)_[15, 17]) : Move Scalar Double-FP Value */
inline bool handler_MOVSD_d_rm_mod_xmm_d128_rm_reg_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVHLPS(()_[15, 18]) : Move Packed Single-FP Values High to Low */
inline bool handler_MOVHLPS_w_rm_reg_xmm_u64_rm_rm_xmm_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVHLPS(()_[15, 18]) : Move Packed Single-FP Values High to Low */
inline bool handler_MOVHLPS_d_rm_reg_xmm_u64_rm_rm_xmm_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVLPS(()_[15, 18]) : Move Low Packed Single-FP Values */
inline bool handler_MOVLPS_w_rm_reg_xmm_u64_rm_mem_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVLPS(()_[15, 18]) : Move Low Packed Single-FP Values */
inline bool handler_MOVLPS_d_rm_reg_xmm_u64_rm_mem_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVLPD((102,)_[15, 18]) : Move Low Packed Double-FP Value */
inline bool handler_MOVLPD_w_rm_reg_xmm_u64_rm_mem_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVLPD((102,)_[15, 18]) : Move Low Packed Double-FP Value */
inline bool handler_MOVLPD_d_rm_reg_xmm_u64_rm_mem_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVDDUP((242,)_[15, 18]) : Move One Double-FP and Duplicate */
inline bool handler_MOVDDUP_w_rm_reg_xmm_u64_rm_mod_xmm_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVDDUP((242,)_[15, 18]) : Move One Double-FP and Duplicate */
inline bool handler_MOVDDUP_d_rm_reg_xmm_u64_rm_mod_xmm_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVSLDUP((243,)_[15, 18]) : Move Packed Single-FP Low and Duplicate */
inline bool handler_MOVSLDUP_w_rm_reg_xmm_u64_rm_mod_xmm_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVSLDUP((243,)_[15, 18]) : Move Packed Single-FP Low and Duplicate */
inline bool handler_MOVSLDUP_d_rm_reg_xmm_u64_rm_mod_xmm_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVLPS(()_[15, 19]) : Move Low Packed Single-FP Values */
inline bool handler_MOVLPS_w_rm_mem_u64_rm_reg_xmm_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVLPS(()_[15, 19]) : Move Low Packed Single-FP Values */
inline bool handler_MOVLPS_d_rm_mem_u64_rm_reg_xmm_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVLPD((102,)_[15, 19]) : Move Low Packed Double-FP Value */
inline bool handler_MOVLPD_w_rm_mem_u64_rm_reg_xmm_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVLPD((102,)_[15, 19]) : Move Low Packed Double-FP Value */
inline bool handler_MOVLPD_d_rm_mem_u64_rm_reg_xmm_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* UNPCKLPS(()_[15, 20]) : Unpack and Interleave Low Packed Single-FP Values */
inline bool handler_UNPCKLPS_w_rm_reg_xmm_f128_rm_mod_xmm_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* UNPCKLPS(()_[15, 20]) : Unpack and Interleave Low Packed Single-FP Values */
inline bool handler_UNPCKLPS_d_rm_reg_xmm_f128_rm_mod_xmm_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* UNPCKLPD((102,)_[15, 20]) : Unpack and Interleave Low Packed Double-FP Values */
inline bool handler_UNPCKLPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* UNPCKLPD((102,)_[15, 20]) : Unpack and Interleave Low Packed Double-FP Values */
inline bool handler_UNPCKLPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* UNPCKHPS(()_[15, 21]) : Unpack and Interleave High Packed Single-FP Values */
inline bool handler_UNPCKHPS_w_rm_reg_xmm_f128_rm_mod_xmm_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* UNPCKHPS(()_[15, 21]) : Unpack and Interleave High Packed Single-FP Values */
inline bool handler_UNPCKHPS_d_rm_reg_xmm_f128_rm_mod_xmm_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* UNPCKHPD((102,)_[15, 21]) : Unpack and Interleave High Packed Double-FP Values */
inline bool handler_UNPCKHPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* UNPCKHPD((102,)_[15, 21]) : Unpack and Interleave High Packed Double-FP Values */
inline bool handler_UNPCKHPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVLHPS(()_[15, 22]) : Move Packed Single-FP Values Low to High */
inline bool handler_MOVLHPS_w_rm_reg_xmm_u64_rm_rm_xmm_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVLHPS(()_[15, 22]) : Move Packed Single-FP Values Low to High */
inline bool handler_MOVLHPS_d_rm_reg_xmm_u64_rm_rm_xmm_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVHPS(()_[15, 22]) : Move High Packed Single-FP Values */
inline bool handler_MOVHPS_w_rm_reg_xmm_u64_rm_mem_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVHPS(()_[15, 22]) : Move High Packed Single-FP Values */
inline bool handler_MOVHPS_d_rm_reg_xmm_u64_rm_mem_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVHPD((102,)_[15, 22]) : Move High Packed Double-FP Value */
inline bool handler_MOVHPD_w_rm_reg_xmm_u64_rm_mem_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVHPD((102,)_[15, 22]) : Move High Packed Double-FP Value */
inline bool handler_MOVHPD_d_rm_reg_xmm_u64_rm_mem_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVSHDUP((243,)_[15, 22]) : Move Packed Single-FP High and Duplicate */
inline bool handler_MOVSHDUP_w_rm_reg_xmm_u64_rm_mod_xmm_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVSHDUP((243,)_[15, 22]) : Move Packed Single-FP High and Duplicate */
inline bool handler_MOVSHDUP_d_rm_reg_xmm_u64_rm_mod_xmm_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVHPS(()_[15, 23]) : Move High Packed Single-FP Values */
inline bool handler_MOVHPS_w_rm_mem_u64_rm_reg_xmm_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVHPS(()_[15, 23]) : Move High Packed Single-FP Values */
inline bool handler_MOVHPS_d_rm_mem_u64_rm_reg_xmm_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVHPD((102,)_[15, 23]) : Move High Packed Double-FP Value */
inline bool handler_MOVHPD_w_rm_mem_u64_rm_reg_xmm_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVHPD((102,)_[15, 23]) : Move High Packed Double-FP Value */
inline bool handler_MOVHPD_d_rm_mem_u64_rm_reg_xmm_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PREFETCHNTA(()_[15, 24]) : Prefetch Data Into Caches */
inline bool handler_PREFETCHNTA_w_rm_mem_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PREFETCHNTA(()_[15, 24]) : Prefetch Data Into Caches */
inline bool handler_PREFETCHNTA_d_rm_mem_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PREFETCHT0(()_[15, 24]) : Prefetch Data Into Caches */
inline bool handler_PREFETCHT0_w_rm_mem_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PREFETCHT0(()_[15, 24]) : Prefetch Data Into Caches */
inline bool handler_PREFETCHT0_d_rm_mem_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PREFETCHT1(()_[15, 24]) : Prefetch Data Into Caches */
inline bool handler_PREFETCHT1_w_rm_mem_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PREFETCHT1(()_[15, 24]) : Prefetch Data Into Caches */
inline bool handler_PREFETCHT1_d_rm_mem_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PREFETCHT2(()_[15, 24]) : Prefetch Data Into Caches */
inline bool handler_PREFETCHT2_w_rm_mem_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PREFETCHT2(()_[15, 24]) : Prefetch Data Into Caches */
inline bool handler_PREFETCHT2_d_rm_mem_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* NOP(()_[15, 31]) : No Operation */
inline bool handler_NOP_w_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* NOP(()_[15, 31]) : No Operation */
inline bool handler_NOP_d_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVAPS(()_[15, 40]) : Move Aligned Packed Single-FP Values */
inline bool handler_MOVAPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVAPS(()_[15, 40]) : Move Aligned Packed Single-FP Values */
inline bool handler_MOVAPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVAPD((102,)_[15, 40]) : Move Aligned Packed Double-FP Values */
inline bool handler_MOVAPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVAPD((102,)_[15, 40]) : Move Aligned Packed Double-FP Values */
inline bool handler_MOVAPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVAPS(()_[15, 41]) : Move Aligned Packed Single-FP Values */
inline bool handler_MOVAPS_w_rm_mod_xmm_f128_rm_reg_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVAPS(()_[15, 41]) : Move Aligned Packed Single-FP Values */
inline bool handler_MOVAPS_d_rm_mod_xmm_f128_rm_reg_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVAPD((102,)_[15, 41]) : Move Aligned Packed Double-FP Values */
inline bool handler_MOVAPD_w_rm_mod_xmm_d128_rm_reg_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVAPD((102,)_[15, 41]) : Move Aligned Packed Double-FP Values */
inline bool handler_MOVAPD_d_rm_mod_xmm_d128_rm_reg_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CVTPI2PS(()_[15, 42]) : 
            Convert Packed DW Integers to  */
inline bool handler_CVTPI2PS_w_rm_reg_xmm_f128_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CVTPI2PS(()_[15, 42]) : 
            Convert Packed DW Integers to  */
inline bool handler_CVTPI2PS_d_rm_reg_xmm_f128_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CVTSI2SS((243,)_[15, 42]) : Convert DW Integer to Scalar Single-FP Value */
inline bool handler_CVTSI2SS_w_rm_reg_xmm_f128_rm_mod_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CVTSI2SS((243,)_[15, 42]) : Convert DW Integer to Scalar Single-FP Value */
inline bool handler_CVTSI2SS_d_rm_reg_xmm_f128_rm_mod_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CVTPI2PD((102,)_[15, 42]) : 
            Convert Packed DW Integers to  */
inline bool handler_CVTPI2PD_w_rm_reg_xmm_d128_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CVTPI2PD((102,)_[15, 42]) : 
            Convert Packed DW Integers to  */
inline bool handler_CVTPI2PD_d_rm_reg_xmm_d128_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CVTSI2SD((242,)_[15, 42]) : Convert DW Integer to Scalar Double-FP Value */
inline bool handler_CVTSI2SD_w_rm_reg_xmm_d128_rm_mod_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CVTSI2SD((242,)_[15, 42]) : Convert DW Integer to Scalar Double-FP Value */
inline bool handler_CVTSI2SD_d_rm_reg_xmm_d128_rm_mod_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVNTPS(()_[15, 43]) : Store Packed Single-FP Values Using Non-Temporal Hint */
inline bool handler_MOVNTPS_w_rm_mem_f128_rm_reg_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVNTPS(()_[15, 43]) : Store Packed Single-FP Values Using Non-Temporal Hint */
inline bool handler_MOVNTPS_d_rm_mem_f128_rm_reg_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVNTPD((102,)_[15, 43]) : Store Packed Double-FP Values Using Non-Temporal Hint */
inline bool handler_MOVNTPD_w_rm_mem_d128_rm_reg_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVNTPD((102,)_[15, 43]) : Store Packed Double-FP Values Using Non-Temporal Hint */
inline bool handler_MOVNTPD_d_rm_mem_d128_rm_reg_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CVTTPS2PI(()_[15, 44]) : 
            Convert with Trunc. Packed Single-FP Values to  */
inline bool handler_CVTTPS2PI_w_rm_reg_mmx_u64_rm_mod_xmm_f64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CVTTPS2PI(()_[15, 44]) : 
            Convert with Trunc. Packed Single-FP Values to  */
inline bool handler_CVTTPS2PI_d_rm_reg_mmx_u64_rm_mod_xmm_f64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CVTTSS2SI((243,)_[15, 44]) : Convert with Trunc. Scalar Single-FP Value to DW Integer */
inline bool handler_CVTTSS2SI_w_rm_reg_reg_u32_rm_mod_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CVTTSS2SI((243,)_[15, 44]) : Convert with Trunc. Scalar Single-FP Value to DW Integer */
inline bool handler_CVTTSS2SI_d_rm_reg_reg_u32_rm_mod_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CVTTPD2PI((102,)_[15, 44]) : 
            Convert with Trunc. Packed Double-FP Values to  */
inline bool handler_CVTTPD2PI_w_rm_reg_mmx_u64_rm_mod_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CVTTPD2PI((102,)_[15, 44]) : 
            Convert with Trunc. Packed Double-FP Values to  */
inline bool handler_CVTTPD2PI_d_rm_reg_mmx_u64_rm_mod_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CVTTSD2SI((242,)_[15, 44]) : Conv. with Trunc. Scalar Double-FP Value to Signed DW Int */
inline bool handler_CVTTSD2SI_w_rm_reg_reg_u32_rm_mod_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CVTTSD2SI((242,)_[15, 44]) : Conv. with Trunc. Scalar Double-FP Value to Signed DW Int */
inline bool handler_CVTTSD2SI_d_rm_reg_reg_u32_rm_mod_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CVTPS2PI(()_[15, 45]) : 
            Convert Packed Single-FP Values to  */
inline bool handler_CVTPS2PI_w_rm_reg_mmx_u64_rm_mod_xmm_f64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CVTPS2PI(()_[15, 45]) : 
            Convert Packed Single-FP Values to  */
inline bool handler_CVTPS2PI_d_rm_reg_mmx_u64_rm_mod_xmm_f64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CVTSS2SI((243,)_[15, 45]) : Convert Scalar Single-FP Value to DW Integer */
inline bool handler_CVTSS2SI_w_rm_reg_reg_u32_rm_mod_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CVTSS2SI((243,)_[15, 45]) : Convert Scalar Single-FP Value to DW Integer */
inline bool handler_CVTSS2SI_d_rm_reg_reg_u32_rm_mod_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CVTPD2PI((102,)_[15, 45]) : 
            Convert Packed Double-FP Values to  */
inline bool handler_CVTPD2PI_w_rm_reg_mmx_u64_rm_mod_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CVTPD2PI((102,)_[15, 45]) : 
            Convert Packed Double-FP Values to  */
inline bool handler_CVTPD2PI_d_rm_reg_mmx_u64_rm_mod_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CVTSD2SI((242,)_[15, 45]) : Convert Scalar Double-FP Value to DW Integer */
inline bool handler_CVTSD2SI_w_rm_reg_reg_u32_rm_mod_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CVTSD2SI((242,)_[15, 45]) : Convert Scalar Double-FP Value to DW Integer */
inline bool handler_CVTSD2SI_d_rm_reg_reg_u32_rm_mod_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* UCOMISS(()_[15, 46]) : Unordered Compare Scalar Single-FP Values and Set EFLAGS */
inline bool handler_UCOMISS_w_rm_mod_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* UCOMISS(()_[15, 46]) : Unordered Compare Scalar Single-FP Values and Set EFLAGS */
inline bool handler_UCOMISS_d_rm_mod_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* UCOMISD((102,)_[15, 46]) : Unordered Compare Scalar Double-FP Values and Set EFLAGS */
inline bool handler_UCOMISD_w_rm_mod_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* UCOMISD((102,)_[15, 46]) : Unordered Compare Scalar Double-FP Values and Set EFLAGS */
inline bool handler_UCOMISD_d_rm_mod_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* COMISS(()_[15, 47]) : Compare Scalar Ordered Single-FP Values and Set EFLAGS */
inline bool handler_COMISS_w_rm_mod_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* COMISS(()_[15, 47]) : Compare Scalar Ordered Single-FP Values and Set EFLAGS */
inline bool handler_COMISS_d_rm_mod_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* COMISD((102,)_[15, 47]) : Compare Scalar Ordered Double-FP Values and Set EFLAGS */
inline bool handler_COMISD_w_rm_mod_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* COMISD((102,)_[15, 47]) : Compare Scalar Ordered Double-FP Values and Set EFLAGS */
inline bool handler_COMISD_d_rm_mod_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* WRMSR(()_[15, 48]) : Write to Model Specific Register */
inline bool handler_WRMSR(Bit8u last, PhysPt &cseip) {
	return true;
}

/* RDTSC(()_[15, 49]) : Read Time-Stamp Counter */
inline bool handler_RDTSC(Bit8u last, PhysPt &cseip) {
	return true;
}

/* RDMSR(()_[15, 50]) : Read from Model Specific Register */
inline bool handler_RDMSR(Bit8u last, PhysPt &cseip) {
	return true;
}

/* RDPMC(()_[15, 51]) : Read Performance-Monitoring Counters */
inline bool handler_RDPMC(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SYSENTER(()_[15, 52]) : Fast System Call */
inline bool handler_SYSENTER(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PSHUFB(()_[15, 56, 0]) : Packed Shuffle Bytes */
inline bool handler_PSHUFB_w_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PSHUFB(()_[15, 56, 0]) : Packed Shuffle Bytes */
inline bool handler_PSHUFB_d_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PHADDW(()_[15, 56, 1]) : Packed Horizontal Add */
inline bool handler_PHADDW_w_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PHADDW(()_[15, 56, 1]) : Packed Horizontal Add */
inline bool handler_PHADDW_d_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PHADDD(()_[15, 56, 2]) : Packed Horizontal Add */
inline bool handler_PHADDD_w_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PHADDD(()_[15, 56, 2]) : Packed Horizontal Add */
inline bool handler_PHADDD_d_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PHADDSW(()_[15, 56, 3]) : Packed Horizontal Add and Saturate */
inline bool handler_PHADDSW_w_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PHADDSW(()_[15, 56, 3]) : Packed Horizontal Add and Saturate */
inline bool handler_PHADDSW_d_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PMADDUBSW(()_[15, 56, 4]) : Multiply and Add Packed Signed and Unsigned Bytes */
inline bool handler_PMADDUBSW_w_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PMADDUBSW(()_[15, 56, 4]) : Multiply and Add Packed Signed and Unsigned Bytes */
inline bool handler_PMADDUBSW_d_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PHSUBW(()_[15, 56, 5]) : Packed Horizontal Subtract */
inline bool handler_PHSUBW_w_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PHSUBW(()_[15, 56, 5]) : Packed Horizontal Subtract */
inline bool handler_PHSUBW_d_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PHSUBD(()_[15, 56, 6]) : Packed Horizontal Subtract */
inline bool handler_PHSUBD_w_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PHSUBD(()_[15, 56, 6]) : Packed Horizontal Subtract */
inline bool handler_PHSUBD_d_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PHSUBSW(()_[15, 56, 7]) : Packed Horizontal Subtract and Saturate */
inline bool handler_PHSUBSW_w_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PHSUBSW(()_[15, 56, 7]) : Packed Horizontal Subtract and Saturate */
inline bool handler_PHSUBSW_d_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PSIGNB(()_[15, 56, 8]) : Packed SIGN */
inline bool handler_PSIGNB_w_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PSIGNB(()_[15, 56, 8]) : Packed SIGN */
inline bool handler_PSIGNB_d_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PSIGNW(()_[15, 56, 9]) : Packed SIGN */
inline bool handler_PSIGNW_w_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PSIGNW(()_[15, 56, 9]) : Packed SIGN */
inline bool handler_PSIGNW_d_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PSIGND(()_[15, 56, 10]) : Packed SIGN */
inline bool handler_PSIGND_w_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PSIGND(()_[15, 56, 10]) : Packed SIGN */
inline bool handler_PSIGND_d_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PMULHRSW(()_[15, 56, 11]) : Packed Multiply High with Round and Scale */
inline bool handler_PMULHRSW_w_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PMULHRSW(()_[15, 56, 11]) : Packed Multiply High with Round and Scale */
inline bool handler_PMULHRSW_d_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PABSB(()_[15, 56, 28]) : Packed Absolute Value */
inline bool handler_PABSB_w_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PABSB(()_[15, 56, 28]) : Packed Absolute Value */
inline bool handler_PABSB_d_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PABSW(()_[15, 56, 29]) : Packed Absolute Value */
inline bool handler_PABSW_w_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PABSW(()_[15, 56, 29]) : Packed Absolute Value */
inline bool handler_PABSW_d_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PABSD(()_[15, 56, 30]) : Packed Absolute Value */
inline bool handler_PABSD_w_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PABSD(()_[15, 56, 30]) : Packed Absolute Value */
inline bool handler_PABSD_d_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVBE(()_[15, 56, 240]) : Move Data After Swapping Bytes */
inline bool handler_MOVBE_w_rm_reg_reg_u16_rm_mem_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVBE(()_[15, 56, 240]) : Move Data After Swapping Bytes */
inline bool handler_MOVBE_d_rm_reg_reg_u16_rm_mem_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVBE(()_[15, 56, 241]) : Move Data After Swapping Bytes */
inline bool handler_MOVBE_w_rm_mem_u16_rm_reg_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVBE(()_[15, 56, 241]) : Move Data After Swapping Bytes */
inline bool handler_MOVBE_d_rm_mem_u16_rm_reg_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PALIGNR(()_[15, 58, 15]) : Packed Align Right */
inline bool handler_PALIGNR_w_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PALIGNR(()_[15, 58, 15]) : Packed Align Right */
inline bool handler_PALIGNR_d_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVMSKPS(()_[15, 80]) : Extract Packed Single-FP Sign Mask */
inline bool handler_MOVMSKPS_w_rm_reg_reg_u32_rm_rm_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVMSKPS(()_[15, 80]) : Extract Packed Single-FP Sign Mask */
inline bool handler_MOVMSKPS_d_rm_reg_reg_u32_rm_rm_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVMSKPD((102,)_[15, 80]) : Extract Packed Double-FP Sign Mask */
inline bool handler_MOVMSKPD_w_rm_reg_reg_u32_rm_rm_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVMSKPD((102,)_[15, 80]) : Extract Packed Double-FP Sign Mask */
inline bool handler_MOVMSKPD_d_rm_reg_reg_u32_rm_rm_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SQRTPS(()_[15, 81]) : Compute Square Roots of Packed Single-FP Values */
inline bool handler_SQRTPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SQRTPS(()_[15, 81]) : Compute Square Roots of Packed Single-FP Values */
inline bool handler_SQRTPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SQRTSS((243,)_[15, 81]) : Compute Square Root of Scalar Single-FP Value */
inline bool handler_SQRTSS_w_rm_reg_xmm_f128_rm_mod_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SQRTSS((243,)_[15, 81]) : Compute Square Root of Scalar Single-FP Value */
inline bool handler_SQRTSS_d_rm_reg_xmm_f128_rm_mod_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SQRTPD((102,)_[15, 81]) : Compute Square Roots of Packed Double-FP Values */
inline bool handler_SQRTPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SQRTPD((102,)_[15, 81]) : Compute Square Roots of Packed Double-FP Values */
inline bool handler_SQRTPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SQRTSD((242,)_[15, 81]) : Compute Square Root of Scalar Double-FP Value */
inline bool handler_SQRTSD_w_rm_reg_xmm_d128_rm_mod_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SQRTSD((242,)_[15, 81]) : Compute Square Root of Scalar Double-FP Value */
inline bool handler_SQRTSD_d_rm_reg_xmm_d128_rm_mod_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* RSQRTPS(()_[15, 82]) : Compute Recipr. of Square Roots of Packed Single-FP Values */
inline bool handler_RSQRTPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* RSQRTPS(()_[15, 82]) : Compute Recipr. of Square Roots of Packed Single-FP Values */
inline bool handler_RSQRTPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* RSQRTSS((243,)_[15, 82]) : Compute Recipr. of Square Root of Scalar Single-FP Value */
inline bool handler_RSQRTSS_w_rm_reg_xmm_f128_rm_mod_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* RSQRTSS((243,)_[15, 82]) : Compute Recipr. of Square Root of Scalar Single-FP Value */
inline bool handler_RSQRTSS_d_rm_reg_xmm_f128_rm_mod_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* RCPPS(()_[15, 83]) : Compute Reciprocals of Packed Single-FP Values */
inline bool handler_RCPPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* RCPPS(()_[15, 83]) : Compute Reciprocals of Packed Single-FP Values */
inline bool handler_RCPPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* RCPSS((243,)_[15, 83]) : Compute Reciprocal of Scalar Single-FP Values */
inline bool handler_RCPSS_w_rm_reg_xmm_f128_rm_mod_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* RCPSS((243,)_[15, 83]) : Compute Reciprocal of Scalar Single-FP Values */
inline bool handler_RCPSS_d_rm_reg_xmm_f128_rm_mod_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ANDPS(()_[15, 84]) : Bitwise Logical AND of Packed Single-FP Values */
inline bool handler_ANDPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ANDPS(()_[15, 84]) : Bitwise Logical AND of Packed Single-FP Values */
inline bool handler_ANDPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ANDPD((102,)_[15, 84]) : Bitwise Logical AND of Packed Double-FP Values */
inline bool handler_ANDPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ANDPD((102,)_[15, 84]) : Bitwise Logical AND of Packed Double-FP Values */
inline bool handler_ANDPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ANDNPS(()_[15, 85]) : Bitwise Logical AND NOT of Packed Single-FP Values */
inline bool handler_ANDNPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ANDNPS(()_[15, 85]) : Bitwise Logical AND NOT of Packed Single-FP Values */
inline bool handler_ANDNPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ANDNPD((102,)_[15, 85]) : Bitwise Logical AND NOT of Packed Double-FP Values */
inline bool handler_ANDNPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ANDNPD((102,)_[15, 85]) : Bitwise Logical AND NOT of Packed Double-FP Values */
inline bool handler_ANDNPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ORPS(()_[15, 86]) : Bitwise Logical OR of Single-FP Values */
inline bool handler_ORPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ORPS(()_[15, 86]) : Bitwise Logical OR of Single-FP Values */
inline bool handler_ORPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ORPD((102,)_[15, 86]) : Bitwise Logical OR of Double-FP Values */
inline bool handler_ORPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ORPD((102,)_[15, 86]) : Bitwise Logical OR of Double-FP Values */
inline bool handler_ORPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* XORPS(()_[15, 87]) : Bitwise Logical XOR for Single-FP Values */
inline bool handler_XORPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* XORPS(()_[15, 87]) : Bitwise Logical XOR for Single-FP Values */
inline bool handler_XORPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* XORPD((102,)_[15, 87]) : Bitwise Logical XOR for Double-FP Values */
inline bool handler_XORPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* XORPD((102,)_[15, 87]) : Bitwise Logical XOR for Double-FP Values */
inline bool handler_XORPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ADDPS(()_[15, 88]) : Add Packed Single-FP Values */
inline bool handler_ADDPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ADDPS(()_[15, 88]) : Add Packed Single-FP Values */
inline bool handler_ADDPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ADDSS((243,)_[15, 88]) : Add Scalar Single-FP Values */
inline bool handler_ADDSS_w_rm_reg_xmm_f128_rm_mod_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ADDSS((243,)_[15, 88]) : Add Scalar Single-FP Values */
inline bool handler_ADDSS_d_rm_reg_xmm_f128_rm_mod_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ADDPD((102,)_[15, 88]) : Add Packed Double-FP Values */
inline bool handler_ADDPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ADDPD((102,)_[15, 88]) : Add Packed Double-FP Values */
inline bool handler_ADDPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ADDSD((242,)_[15, 88]) : Add Scalar Double-FP Values */
inline bool handler_ADDSD_w_rm_reg_xmm_d128_rm_mod_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ADDSD((242,)_[15, 88]) : Add Scalar Double-FP Values */
inline bool handler_ADDSD_d_rm_reg_xmm_d128_rm_mod_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MULPS(()_[15, 89]) : Multiply Packed Single-FP Values */
inline bool handler_MULPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MULPS(()_[15, 89]) : Multiply Packed Single-FP Values */
inline bool handler_MULPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MULSS((243,)_[15, 89]) : Multiply Scalar Single-FP Value */
inline bool handler_MULSS_w_rm_reg_xmm_f128_rm_mod_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MULSS((243,)_[15, 89]) : Multiply Scalar Single-FP Value */
inline bool handler_MULSS_d_rm_reg_xmm_f128_rm_mod_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MULPD((102,)_[15, 89]) : Multiply Packed Double-FP Values */
inline bool handler_MULPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MULPD((102,)_[15, 89]) : Multiply Packed Double-FP Values */
inline bool handler_MULPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MULSD((242,)_[15, 89]) : Multiply Scalar Double-FP Values */
inline bool handler_MULSD_w_rm_reg_xmm_d128_rm_mod_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MULSD((242,)_[15, 89]) : Multiply Scalar Double-FP Values */
inline bool handler_MULSD_d_rm_reg_xmm_d128_rm_mod_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CVTPS2PD(()_[15, 90]) : 
            Convert Packed Single-FP Values to  */
inline bool handler_CVTPS2PD_w_rm_reg_xmm_d128_rm_mod_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CVTPS2PD(()_[15, 90]) : 
            Convert Packed Single-FP Values to  */
inline bool handler_CVTPS2PD_d_rm_reg_xmm_d128_rm_mod_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CVTPD2PS((102,)_[15, 90]) : 
            Convert Packed Double-FP Values to  */
inline bool handler_CVTPD2PS_w_rm_reg_xmm_f128_rm_mod_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CVTPD2PS((102,)_[15, 90]) : 
            Convert Packed Double-FP Values to  */
inline bool handler_CVTPD2PS_d_rm_reg_xmm_f128_rm_mod_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CVTSS2SD((243,)_[15, 90]) : Convert Scalar Single-FP Value to Scalar Double-FP Value  */
inline bool handler_CVTSS2SD_w_rm_reg_xmm_d128_rm_mod_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CVTSS2SD((243,)_[15, 90]) : Convert Scalar Single-FP Value to Scalar Double-FP Value  */
inline bool handler_CVTSS2SD_d_rm_reg_xmm_d128_rm_mod_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CVTSD2SS((242,)_[15, 90]) : Convert Scalar Double-FP Value to Scalar Single-FP Value */
inline bool handler_CVTSD2SS_w_rm_reg_xmm_f128_rm_mod_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CVTSD2SS((242,)_[15, 90]) : Convert Scalar Double-FP Value to Scalar Single-FP Value */
inline bool handler_CVTSD2SS_d_rm_reg_xmm_f128_rm_mod_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CVTDQ2PS(()_[15, 91]) : 
            Convert Packed DW Integers to  */
inline bool handler_CVTDQ2PS_w_rm_reg_xmm_f128_rm_mod_xmm_u128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CVTDQ2PS(()_[15, 91]) : 
            Convert Packed DW Integers to  */
inline bool handler_CVTDQ2PS_d_rm_reg_xmm_f128_rm_mod_xmm_u128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CVTPS2DQ((102,)_[15, 91]) : 
            Convert Packed Single-FP Values to  */
inline bool handler_CVTPS2DQ_w_rm_reg_xmm_u128_rm_mod_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CVTPS2DQ((102,)_[15, 91]) : 
            Convert Packed Single-FP Values to  */
inline bool handler_CVTPS2DQ_d_rm_reg_xmm_u128_rm_mod_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CVTTPS2DQ((243,)_[15, 91]) : 
            Convert with Trunc. Packed Single-FP Values to  */
inline bool handler_CVTTPS2DQ_w_rm_reg_xmm_u128_rm_mod_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CVTTPS2DQ((243,)_[15, 91]) : 
            Convert with Trunc. Packed Single-FP Values to  */
inline bool handler_CVTTPS2DQ_d_rm_reg_xmm_u128_rm_mod_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SUBPS(()_[15, 92]) : Subtract Packed Single-FP Values */
inline bool handler_SUBPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SUBPS(()_[15, 92]) : Subtract Packed Single-FP Values */
inline bool handler_SUBPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SUBSS((243,)_[15, 92]) : Subtract Scalar Single-FP Values */
inline bool handler_SUBSS_w_rm_reg_xmm_f128_rm_mod_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SUBSS((243,)_[15, 92]) : Subtract Scalar Single-FP Values */
inline bool handler_SUBSS_d_rm_reg_xmm_f128_rm_mod_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SUBPD((102,)_[15, 92]) : Subtract Packed Double-FP Values */
inline bool handler_SUBPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SUBPD((102,)_[15, 92]) : Subtract Packed Double-FP Values */
inline bool handler_SUBPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SUBSD((242,)_[15, 92]) : Subtract Scalar Double-FP Values */
inline bool handler_SUBSD_w_rm_reg_xmm_d128_rm_mod_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SUBSD((242,)_[15, 92]) : Subtract Scalar Double-FP Values */
inline bool handler_SUBSD_d_rm_reg_xmm_d128_rm_mod_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MINPS(()_[15, 93]) : Return Minimum Packed Single-FP Values */
inline bool handler_MINPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MINPS(()_[15, 93]) : Return Minimum Packed Single-FP Values */
inline bool handler_MINPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MINSS((243,)_[15, 93]) : Return Minimum Scalar Single-FP Value */
inline bool handler_MINSS_w_rm_reg_xmm_f128_rm_mod_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MINSS((243,)_[15, 93]) : Return Minimum Scalar Single-FP Value */
inline bool handler_MINSS_d_rm_reg_xmm_f128_rm_mod_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MINPD((102,)_[15, 93]) : Return Minimum Packed Double-FP Values */
inline bool handler_MINPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MINPD((102,)_[15, 93]) : Return Minimum Packed Double-FP Values */
inline bool handler_MINPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MINSD((242,)_[15, 93]) : Return Minimum Scalar Double-FP Value */
inline bool handler_MINSD_w_rm_reg_xmm_d128_rm_mod_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MINSD((242,)_[15, 93]) : Return Minimum Scalar Double-FP Value */
inline bool handler_MINSD_d_rm_reg_xmm_d128_rm_mod_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* DIVPS(()_[15, 94]) : Divide Packed Single-FP Values */
inline bool handler_DIVPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* DIVPS(()_[15, 94]) : Divide Packed Single-FP Values */
inline bool handler_DIVPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* DIVSS((243,)_[15, 94]) : Divide Scalar Single-FP Values */
inline bool handler_DIVSS_w_rm_reg_xmm_f128_rm_mod_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* DIVSS((243,)_[15, 94]) : Divide Scalar Single-FP Values */
inline bool handler_DIVSS_d_rm_reg_xmm_f128_rm_mod_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* DIVPD((102,)_[15, 94]) : Divide Packed Double-FP Values */
inline bool handler_DIVPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* DIVPD((102,)_[15, 94]) : Divide Packed Double-FP Values */
inline bool handler_DIVPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* DIVSD((242,)_[15, 94]) : Divide Scalar Double-FP Values */
inline bool handler_DIVSD_w_rm_reg_xmm_d128_rm_mod_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* DIVSD((242,)_[15, 94]) : Divide Scalar Double-FP Values */
inline bool handler_DIVSD_d_rm_reg_xmm_d128_rm_mod_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MAXPS(()_[15, 95]) : Return Maximum Packed Single-FP Values */
inline bool handler_MAXPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MAXPS(()_[15, 95]) : Return Maximum Packed Single-FP Values */
inline bool handler_MAXPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MAXSS((243,)_[15, 95]) : Return Maximum Scalar Single-FP Value */
inline bool handler_MAXSS_w_rm_reg_xmm_f128_rm_mod_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MAXSS((243,)_[15, 95]) : Return Maximum Scalar Single-FP Value */
inline bool handler_MAXSS_d_rm_reg_xmm_f128_rm_mod_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MAXPD((102,)_[15, 95]) : Return Maximum Packed Double-FP Values */
inline bool handler_MAXPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MAXPD((102,)_[15, 95]) : Return Maximum Packed Double-FP Values */
inline bool handler_MAXPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MAXSD((242,)_[15, 95]) : Return Maximum Scalar Double-FP Value */
inline bool handler_MAXSD_w_rm_reg_xmm_d128_rm_mod_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MAXSD((242,)_[15, 95]) : Return Maximum Scalar Double-FP Value */
inline bool handler_MAXSD_d_rm_reg_xmm_d128_rm_mod_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PUNPCKLBW(()_[15, 96]) : Unpack Low Data */
inline bool handler_PUNPCKLBW_w_rm_reg_mmx_u64_rm_mod_mmx_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PUNPCKLBW(()_[15, 96]) : Unpack Low Data */
inline bool handler_PUNPCKLBW_d_rm_reg_mmx_u64_rm_mod_mmx_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PUNPCKLWD(()_[15, 97]) : Unpack Low Data */
inline bool handler_PUNPCKLWD_w_rm_reg_mmx_u64_rm_mod_mmx_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PUNPCKLWD(()_[15, 97]) : Unpack Low Data */
inline bool handler_PUNPCKLWD_d_rm_reg_mmx_u64_rm_mod_mmx_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PUNPCKLDQ(()_[15, 98]) : Unpack Low Data */
inline bool handler_PUNPCKLDQ_w_rm_reg_mmx_u64_rm_mod_mmx_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PUNPCKLDQ(()_[15, 98]) : Unpack Low Data */
inline bool handler_PUNPCKLDQ_d_rm_reg_mmx_u64_rm_mod_mmx_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PACKSSWB(()_[15, 99]) : Pack with Signed Saturation */
inline bool handler_PACKSSWB_w_rm_reg_mmx_u64_rm_mod_mmx_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PACKSSWB(()_[15, 99]) : Pack with Signed Saturation */
inline bool handler_PACKSSWB_d_rm_reg_mmx_u64_rm_mod_mmx_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PCMPGTB(()_[15, 100]) : Compare Packed Signed Integers for Greater Than */
inline bool handler_PCMPGTB_w_rm_reg_mmx_u64_rm_mod_mmx_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PCMPGTB(()_[15, 100]) : Compare Packed Signed Integers for Greater Than */
inline bool handler_PCMPGTB_d_rm_reg_mmx_u64_rm_mod_mmx_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PCMPGTW(()_[15, 101]) : Compare Packed Signed Integers for Greater Than */
inline bool handler_PCMPGTW_w_rm_reg_mmx_u64_rm_mod_mmx_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PCMPGTW(()_[15, 101]) : Compare Packed Signed Integers for Greater Than */
inline bool handler_PCMPGTW_d_rm_reg_mmx_u64_rm_mod_mmx_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PCMPGTD(()_[15, 102]) : Compare Packed Signed Integers for Greater Than */
inline bool handler_PCMPGTD_w_rm_reg_mmx_u64_rm_mod_mmx_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PCMPGTD(()_[15, 102]) : Compare Packed Signed Integers for Greater Than */
inline bool handler_PCMPGTD_d_rm_reg_mmx_u64_rm_mod_mmx_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PACKUSWB(()_[15, 103]) : Pack with Unsigned Saturation */
inline bool handler_PACKUSWB_w_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PACKUSWB(()_[15, 103]) : Pack with Unsigned Saturation */
inline bool handler_PACKUSWB_d_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PUNPCKHBW(()_[15, 104]) : Unpack High Data */
inline bool handler_PUNPCKHBW_w_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PUNPCKHBW(()_[15, 104]) : Unpack High Data */
inline bool handler_PUNPCKHBW_d_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PUNPCKHWD(()_[15, 105]) : Unpack High Data */
inline bool handler_PUNPCKHWD_w_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PUNPCKHWD(()_[15, 105]) : Unpack High Data */
inline bool handler_PUNPCKHWD_d_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PUNPCKHDQ(()_[15, 106]) : Unpack High Data */
inline bool handler_PUNPCKHDQ_w_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PUNPCKHDQ(()_[15, 106]) : Unpack High Data */
inline bool handler_PUNPCKHDQ_d_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PACKSSDW(()_[15, 107]) : Pack with Signed Saturation */
inline bool handler_PACKSSDW_w_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PACKSSDW(()_[15, 107]) : Pack with Signed Saturation */
inline bool handler_PACKSSDW_d_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PUNPCKLQDQ((102,)_[15, 108]) : Unpack Low Data */
inline bool handler_PUNPCKLQDQ_w_rm_reg_xmm_u128_rm_mod_xmm_u128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PUNPCKLQDQ((102,)_[15, 108]) : Unpack Low Data */
inline bool handler_PUNPCKLQDQ_d_rm_reg_xmm_u128_rm_mod_xmm_u128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PUNPCKHQDQ((102,)_[15, 109]) : Unpack High Data */
inline bool handler_PUNPCKHQDQ_w_rm_reg_xmm_u128_rm_mod_xmm_u128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PUNPCKHQDQ((102,)_[15, 109]) : Unpack High Data */
inline bool handler_PUNPCKHQDQ_d_rm_reg_xmm_u128_rm_mod_xmm_u128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVD(()_[15, 110]) : Move Doubleword */
inline bool handler_MOVD_w_rm_reg_mmx_u64_rm_mod_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVD(()_[15, 110]) : Move Doubleword */
inline bool handler_MOVD_d_rm_reg_mmx_u64_rm_mod_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVQ(()_[15, 111]) : Move Quadword */
inline bool handler_MOVQ_w_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVQ(()_[15, 111]) : Move Quadword */
inline bool handler_MOVQ_d_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVDQA((102,)_[15, 111]) : Move Aligned Double Quadword */
inline bool handler_MOVDQA_w_rm_reg_xmm_u128_rm_mod_xmm_u128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVDQA((102,)_[15, 111]) : Move Aligned Double Quadword */
inline bool handler_MOVDQA_d_rm_reg_xmm_u128_rm_mod_xmm_u128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVDQU((243,)_[15, 111]) : Move Unaligned Double Quadword */
inline bool handler_MOVDQU_w_rm_reg_xmm_u128_rm_mod_xmm_u128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVDQU((243,)_[15, 111]) : Move Unaligned Double Quadword */
inline bool handler_MOVDQU_d_rm_reg_xmm_u128_rm_mod_xmm_u128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PSHUFW(()_[15, 112]) : Shuffle Packed Words */
inline bool handler_PSHUFW_w_rm_reg_mmx_u64_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PSHUFW(()_[15, 112]) : Shuffle Packed Words */
inline bool handler_PSHUFW_d_rm_reg_mmx_u64_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PSHUFLW((242,)_[15, 112]) : Shuffle Packed Low Words */
inline bool handler_PSHUFLW_w_rm_reg_xmm_u128_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PSHUFLW((242,)_[15, 112]) : Shuffle Packed Low Words */
inline bool handler_PSHUFLW_d_rm_reg_xmm_u128_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PSHUFHW((243,)_[15, 112]) : Shuffle Packed High Words */
inline bool handler_PSHUFHW_w_rm_reg_xmm_u128_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PSHUFHW((243,)_[15, 112]) : Shuffle Packed High Words */
inline bool handler_PSHUFHW_d_rm_reg_xmm_u128_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PSHUFD((102,)_[15, 112]) : Shuffle Packed Doublewords */
inline bool handler_PSHUFD_w_rm_reg_xmm_u128_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PSHUFD((102,)_[15, 112]) : Shuffle Packed Doublewords */
inline bool handler_PSHUFD_d_rm_reg_xmm_u128_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PSRLW(()_[15, 113]) : Shift Packed Data Right Logical */
inline bool handler_PSRLW_w_rm_rm_mmx_u64_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PSRLW(()_[15, 113]) : Shift Packed Data Right Logical */
inline bool handler_PSRLW_d_rm_rm_mmx_u64_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PSRAW(()_[15, 113]) : Shift Packed Data Right Arithmetic */
inline bool handler_PSRAW_w_rm_rm_mmx_u64_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PSRAW(()_[15, 113]) : Shift Packed Data Right Arithmetic */
inline bool handler_PSRAW_d_rm_rm_mmx_u64_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PSLLW(()_[15, 113]) : Shift Packed Data Left Logical */
inline bool handler_PSLLW_w_rm_rm_mmx_u64_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PSLLW(()_[15, 113]) : Shift Packed Data Left Logical */
inline bool handler_PSLLW_d_rm_rm_mmx_u64_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PSRLD(()_[15, 114]) : Shift Double Quadword Right Logical */
inline bool handler_PSRLD_w_rm_rm_mmx_u64_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PSRLD(()_[15, 114]) : Shift Double Quadword Right Logical */
inline bool handler_PSRLD_d_rm_rm_mmx_u64_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PSRAD(()_[15, 114]) : Shift Packed Data Right Arithmetic */
inline bool handler_PSRAD_w_rm_rm_mmx_u64_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PSRAD(()_[15, 114]) : Shift Packed Data Right Arithmetic */
inline bool handler_PSRAD_d_rm_rm_mmx_u64_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PSLLD(()_[15, 114]) : Shift Packed Data Left Logical */
inline bool handler_PSLLD_w_rm_rm_mmx_u64_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PSLLD(()_[15, 114]) : Shift Packed Data Left Logical */
inline bool handler_PSLLD_d_rm_rm_mmx_u64_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PSRLQ(()_[15, 115]) : Shift Packed Data Right Logical */
inline bool handler_PSRLQ_w_rm_rm_mmx_u64_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PSRLQ(()_[15, 115]) : Shift Packed Data Right Logical */
inline bool handler_PSRLQ_d_rm_rm_mmx_u64_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PSRLDQ((102,)_[15, 115]) : Shift Double Quadword Right Logical */
inline bool handler_PSRLDQ_w_rm_rm_xmm_u128_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PSRLDQ((102,)_[15, 115]) : Shift Double Quadword Right Logical */
inline bool handler_PSRLDQ_d_rm_rm_xmm_u128_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PSLLQ(()_[15, 115]) : Shift Packed Data Left Logical */
inline bool handler_PSLLQ_w_rm_rm_mmx_u64_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PSLLQ(()_[15, 115]) : Shift Packed Data Left Logical */
inline bool handler_PSLLQ_d_rm_rm_mmx_u64_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PSLLDQ((102,)_[15, 115]) : Shift Double Quadword Left Logical */
inline bool handler_PSLLDQ_w_rm_rm_xmm_u128_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PSLLDQ((102,)_[15, 115]) : Shift Double Quadword Left Logical */
inline bool handler_PSLLDQ_d_rm_rm_xmm_u128_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PCMPEQB(()_[15, 116]) : Compare Packed Data for Equal */
inline bool handler_PCMPEQB_w_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PCMPEQB(()_[15, 116]) : Compare Packed Data for Equal */
inline bool handler_PCMPEQB_d_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PCMPEQW(()_[15, 117]) : Compare Packed Data for Equal */
inline bool handler_PCMPEQW_w_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PCMPEQW(()_[15, 117]) : Compare Packed Data for Equal */
inline bool handler_PCMPEQW_d_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PCMPEQD(()_[15, 118]) : Compare Packed Data for Equal */
inline bool handler_PCMPEQD_w_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PCMPEQD(()_[15, 118]) : Compare Packed Data for Equal */
inline bool handler_PCMPEQD_d_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* EMMS(()_[15, 119]) : Empty MMX Technology State */
inline bool handler_EMMS(Bit8u last, PhysPt &cseip) {
	return true;
}

/* HADDPD((102,)_[15, 124]) : Packed Double-FP Horizontal Add */
inline bool handler_HADDPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* HADDPD((102,)_[15, 124]) : Packed Double-FP Horizontal Add */
inline bool handler_HADDPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* HADDPS((242,)_[15, 124]) : Packed Single-FP Horizontal Add */
inline bool handler_HADDPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* HADDPS((242,)_[15, 124]) : Packed Single-FP Horizontal Add */
inline bool handler_HADDPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* HSUBPD((102,)_[15, 125]) : Packed Double-FP Horizontal Subtract */
inline bool handler_HSUBPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* HSUBPD((102,)_[15, 125]) : Packed Double-FP Horizontal Subtract */
inline bool handler_HSUBPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* HSUBPS((242,)_[15, 125]) : Packed Single-FP Horizontal Subtract */
inline bool handler_HSUBPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* HSUBPS((242,)_[15, 125]) : Packed Single-FP Horizontal Subtract */
inline bool handler_HSUBPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVD(()_[15, 126]) : Move Doubleword */
inline bool handler_MOVD_w_rm_mod_reg_u32_rm_reg_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVD(()_[15, 126]) : Move Doubleword */
inline bool handler_MOVD_d_rm_mod_reg_u32_rm_reg_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVQ((243,)_[15, 126]) : Move Quadword */
inline bool handler_MOVQ_w_rm_reg_xmm_u64_rm_mod_xmm_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVQ((243,)_[15, 126]) : Move Quadword */
inline bool handler_MOVQ_d_rm_reg_xmm_u64_rm_mod_xmm_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVQ(()_[15, 127]) : Move Quadword */
inline bool handler_MOVQ_w_rm_mod_mmx_u64_rm_reg_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVQ(()_[15, 127]) : Move Quadword */
inline bool handler_MOVQ_d_rm_mod_mmx_u64_rm_reg_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVDQA((102,)_[15, 127]) : Move Aligned Double Quadword */
inline bool handler_MOVDQA_w_rm_mod_xmm_u128_rm_reg_xmm_u128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVDQA((102,)_[15, 127]) : Move Aligned Double Quadword */
inline bool handler_MOVDQA_d_rm_mod_xmm_u128_rm_reg_xmm_u128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVDQU((243,)_[15, 127]) : Move Unaligned Double Quadword */
inline bool handler_MOVDQU_w_rm_mod_xmm_u128_rm_reg_xmm_u128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVDQU((243,)_[15, 127]) : Move Unaligned Double Quadword */
inline bool handler_MOVDQU_d_rm_mod_xmm_u128_rm_reg_xmm_u128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PUSH(()_[15, 160]) : Push Word, Doubleword or Quadword Onto the Stack */
inline bool handler_PUSH_reg_seg_4_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* POP(()_[15, 161]) : Pop a Value from the Stack */
inline bool handler_POP_reg_seg_4_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CPUID(()_[15, 162]) : CPU Identification */
inline bool handler_CPUID(Bit8u last, PhysPt &cseip) {
	return true;
}

/* BT(()_[15, 163]) : Bit Test */
inline bool handler_BT_w_rm_reg_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* BT(()_[15, 163]) : Bit Test */
inline bool handler_BT_d_rm_reg_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SHLD(()_[15, 164]) : Double Precision Shift Left */
inline bool handler_SHLD_w_rm_mod_reg_u16_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SHLD(()_[15, 164]) : Double Precision Shift Left */
inline bool handler_SHLD_d_rm_mod_reg_u16_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SHLD(()_[15, 165]) : Double Precision Shift Left */
inline bool handler_SHLD_w_rm_mod_reg_u16_reg_gen_1_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SHLD(()_[15, 165]) : Double Precision Shift Left */
inline bool handler_SHLD_d_rm_mod_reg_u16_reg_gen_1_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PUSH(()_[15, 168]) : Push Word, Doubleword or Quadword Onto the Stack */
inline bool handler_PUSH_reg_seg_5_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* POP(()_[15, 169]) : Pop a Value from the Stack */
inline bool handler_POP_reg_seg_5_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* RSM(()_[15, 170]) : Resume from System Management Mode */
inline bool handler_RSM(Bit8u last, PhysPt &cseip) {
	return true;
}

/* BTS(()_[15, 171]) : Bit Test and Set */
inline bool handler_BTS_w_rm_mod_reg_u16_rm_reg_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* BTS(()_[15, 171]) : Bit Test and Set */
inline bool handler_BTS_d_rm_mod_reg_u16_rm_reg_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SHRD(()_[15, 172]) : Double Precision Shift Right */
inline bool handler_SHRD_w_rm_mod_reg_u16_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SHRD(()_[15, 172]) : Double Precision Shift Right */
inline bool handler_SHRD_d_rm_mod_reg_u16_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SHRD(()_[15, 173]) : Double Precision Shift Right */
inline bool handler_SHRD_w_rm_mod_reg_u16_reg_gen_1_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SHRD(()_[15, 173]) : Double Precision Shift Right */
inline bool handler_SHRD_d_rm_mod_reg_u16_reg_gen_1_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* FXSAVE(()_[15, 174]) : Save x87 FPU, MMX, XMM, and MXCSR State */
inline bool handler_FXSAVE_w(Bit8u last, PhysPt &cseip) {
	return true;
}

/* FXSAVE(()_[15, 174]) : Save x87 FPU, MMX, XMM, and MXCSR State */
inline bool handler_FXSAVE_d(Bit8u last, PhysPt &cseip) {
	return true;
}

/* FXRSTOR(()_[15, 174]) : Restore x87 FPU, MMX, XMM, and MXCSR State */
inline bool handler_FXRSTOR_w(Bit8u last, PhysPt &cseip) {
	return true;
}

/* FXRSTOR(()_[15, 174]) : Restore x87 FPU, MMX, XMM, and MXCSR State */
inline bool handler_FXRSTOR_d(Bit8u last, PhysPt &cseip) {
	return true;
}

/* LDMXCSR(()_[15, 174]) : Load MXCSR Register */
inline bool handler_LDMXCSR_w_rm_mem_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* LDMXCSR(()_[15, 174]) : Load MXCSR Register */
inline bool handler_LDMXCSR_d_rm_mem_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* STMXCSR(()_[15, 174]) : Store MXCSR Register State */
inline bool handler_STMXCSR_w_rm_mem_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* STMXCSR(()_[15, 174]) : Store MXCSR Register State */
inline bool handler_STMXCSR_d_rm_mem_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* XSAVE(()_[15, 174]) : Save Processor Extended States */
inline bool handler_XSAVE(Bit8u last, PhysPt &cseip) {
	return true;
}

/* LFENCE(()_[15, 174]) : Load Fence */
inline bool handler_LFENCE(Bit8u last, PhysPt &cseip) {
	return true;
}

/* XRSTOR(()_[15, 174]) : Restore Processor Extended States */
inline bool handler_XRSTOR(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MFENCE(()_[15, 174]) : Memory Fence */
inline bool handler_MFENCE(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SFENCE(()_[15, 174]) : Store Fence */
inline bool handler_SFENCE(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CLFLUSH(()_[15, 174]) : Flush Cache Line */
inline bool handler_CLFLUSH_w_rm_mem_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CLFLUSH(()_[15, 174]) : Flush Cache Line */
inline bool handler_CLFLUSH_d_rm_mem_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* IMUL(()_[15, 175]) : Signed Multiply */
inline bool handler_IMUL_w_rm_reg_reg_u16_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* IMUL(()_[15, 175]) : Signed Multiply */
inline bool handler_IMUL_w_rm_reg_reg_u32_rm_mod_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* IMUL(()_[15, 175]) : Signed Multiply */
inline bool handler_IMUL_d_rm_reg_reg_u16_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* IMUL(()_[15, 175]) : Signed Multiply */
inline bool handler_IMUL_d_rm_reg_reg_u32_rm_mod_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* BTR(()_[15, 179]) : Bit Test and Reset */
inline bool handler_BTR_w_rm_mod_reg_u16_rm_reg_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* BTR(()_[15, 179]) : Bit Test and Reset */
inline bool handler_BTR_d_rm_mod_reg_u16_rm_reg_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVZX(()_[15, 182]) : Move with Zero-Extend */
inline bool handler_MOVZX_w_rm_reg_reg_u16_rm_mod_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVZX(()_[15, 182]) : Move with Zero-Extend */
inline bool handler_MOVZX_d_rm_reg_reg_u16_rm_mod_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVZX(()_[15, 183]) : Move with Zero-Extend */
inline bool handler_MOVZX_w_rm_reg_reg_u16_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVZX(()_[15, 183]) : Move with Zero-Extend */
inline bool handler_MOVZX_w_rm_reg_reg_u32_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVZX(()_[15, 183]) : Move with Zero-Extend */
inline bool handler_MOVZX_d_rm_reg_reg_u16_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVZX(()_[15, 183]) : Move with Zero-Extend */
inline bool handler_MOVZX_d_rm_reg_reg_u32_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* POPCNT((243,)_[15, 184]) : Bit Population Count */
inline bool handler_POPCNT_w_rm_reg_reg_u16_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* POPCNT((243,)_[15, 184]) : Bit Population Count */
inline bool handler_POPCNT_d_rm_reg_reg_u16_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* BT(()_[15, 186]) : Bit Test */
inline bool handler_BT_w_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* BT(()_[15, 186]) : Bit Test */
inline bool handler_BT_d_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* BTS(()_[15, 186]) : Bit Test and Set */
inline bool handler_BTS_w_rm_mod_reg_u16_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* BTS(()_[15, 186]) : Bit Test and Set */
inline bool handler_BTS_d_rm_mod_reg_u16_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* BTR(()_[15, 186]) : Bit Test and Reset */
inline bool handler_BTR_w_rm_mod_reg_u16_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* BTR(()_[15, 186]) : Bit Test and Reset */
inline bool handler_BTR_d_rm_mod_reg_u16_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* BTC(()_[15, 186]) : Bit Test and Complement */
inline bool handler_BTC_w_rm_mod_reg_u16_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* BTC(()_[15, 186]) : Bit Test and Complement */
inline bool handler_BTC_d_rm_mod_reg_u16_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* BTC(()_[15, 187]) : Bit Test and Complement */
inline bool handler_BTC_w_rm_mod_reg_u16_rm_reg_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* BTC(()_[15, 187]) : Bit Test and Complement */
inline bool handler_BTC_d_rm_mod_reg_u16_rm_reg_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVSX(()_[15, 190]) : Move with Sign-Extension */
inline bool handler_MOVSX_w_rm_reg_reg_u16_rm_mod_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVSX(()_[15, 190]) : Move with Sign-Extension */
inline bool handler_MOVSX_d_rm_reg_reg_u16_rm_mod_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVSX(()_[15, 191]) : Move with Sign-Extension */
inline bool handler_MOVSX_w_rm_reg_reg_u16_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVSX(()_[15, 191]) : Move with Sign-Extension */
inline bool handler_MOVSX_w_rm_reg_reg_u32_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVSX(()_[15, 191]) : Move with Sign-Extension */
inline bool handler_MOVSX_d_rm_reg_reg_u16_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVSX(()_[15, 191]) : Move with Sign-Extension */
inline bool handler_MOVSX_d_rm_reg_reg_u32_rm_mod_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* XADD(()_[15, 192]) : Exchange and Add */
inline bool handler_XADD_w_rm_reg_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* XADD(()_[15, 192]) : Exchange and Add */
inline bool handler_XADD_d_rm_reg_reg_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* XADD(()_[15, 193]) : Exchange and Add */
inline bool handler_XADD_w_rm_reg_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* XADD(()_[15, 193]) : Exchange and Add */
inline bool handler_XADD_w_rm_reg_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* XADD(()_[15, 193]) : Exchange and Add */
inline bool handler_XADD_d_rm_reg_reg_u16(Bit8u last, PhysPt &cseip) {
	return true;
}

/* XADD(()_[15, 193]) : Exchange and Add */
inline bool handler_XADD_d_rm_reg_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CMPPS(()_[15, 194]) : Compare Packed Single-FP Values */
inline bool handler_CMPPS_w_rm_reg_xmm_f128_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CMPPS(()_[15, 194]) : Compare Packed Single-FP Values */
inline bool handler_CMPPS_d_rm_reg_xmm_f128_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CMPSS((243,)_[15, 194]) : Compare Scalar Single-FP Values */
inline bool handler_CMPSS_w_rm_reg_xmm_f128_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CMPSS((243,)_[15, 194]) : Compare Scalar Single-FP Values */
inline bool handler_CMPSS_d_rm_reg_xmm_f128_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CMPPD((102,)_[15, 194]) : Compare Packed Double-FP Values */
inline bool handler_CMPPD_w_rm_reg_xmm_d128_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CMPPD((102,)_[15, 194]) : Compare Packed Double-FP Values */
inline bool handler_CMPPD_d_rm_reg_xmm_d128_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CMPSD((242,)_[15, 194]) : Compare Scalar Double-FP Values */
inline bool handler_CMPSD_w_rm_reg_xmm_d128_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CMPSD((242,)_[15, 194]) : Compare Scalar Double-FP Values */
inline bool handler_CMPSD_d_rm_reg_xmm_d128_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVNTI(()_[15, 195]) : Store Doubleword Using Non-Temporal Hint */
inline bool handler_MOVNTI_w_rm_mem_u32_rm_reg_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVNTI(()_[15, 195]) : Store Doubleword Using Non-Temporal Hint */
inline bool handler_MOVNTI_d_rm_mem_u32_rm_reg_reg_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PINSRW(()_[15, 196]) : Insert Word */
inline bool handler_PINSRW_w_rm_reg_mmx_u64_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PINSRW(()_[15, 196]) : Insert Word */
inline bool handler_PINSRW_d_rm_reg_mmx_u64_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PEXTRW(()_[15, 197]) : Extract Word */
inline bool handler_PEXTRW_w_rm_reg_reg_u32_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PEXTRW(()_[15, 197]) : Extract Word */
inline bool handler_PEXTRW_d_rm_reg_reg_u32_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SHUFPS(()_[15, 198]) : Shuffle Packed Single-FP Values */
inline bool handler_SHUFPS_w_rm_reg_xmm_f128_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SHUFPS(()_[15, 198]) : Shuffle Packed Single-FP Values */
inline bool handler_SHUFPS_d_rm_reg_xmm_f128_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SHUFPD((102,)_[15, 198]) : Shuffle Packed Double-FP Values */
inline bool handler_SHUFPD_w_rm_reg_xmm_d128_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* SHUFPD((102,)_[15, 198]) : Shuffle Packed Double-FP Values */
inline bool handler_SHUFPD_d_rm_reg_xmm_d128_imm_u8(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ADDSUBPD((102,)_[15, 208]) : Packed Double-FP Add/Subtract */
inline bool handler_ADDSUBPD_w_rm_reg_xmm_d128_rm_mod_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ADDSUBPD((102,)_[15, 208]) : Packed Double-FP Add/Subtract */
inline bool handler_ADDSUBPD_d_rm_reg_xmm_d128_rm_mod_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ADDSUBPS((242,)_[15, 208]) : Packed Single-FP Add/Subtract */
inline bool handler_ADDSUBPS_w_rm_reg_xmm_f128_rm_mod_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* ADDSUBPS((242,)_[15, 208]) : Packed Single-FP Add/Subtract */
inline bool handler_ADDSUBPS_d_rm_reg_xmm_f128_rm_mod_xmm_f128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PSRLW(()_[15, 209]) : Shift Packed Data Right Logical */
inline bool handler_PSRLW_w_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PSRLW(()_[15, 209]) : Shift Packed Data Right Logical */
inline bool handler_PSRLW_d_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PSRLD(()_[15, 210]) : Shift Packed Data Right Logical */
inline bool handler_PSRLD_w_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PSRLD(()_[15, 210]) : Shift Packed Data Right Logical */
inline bool handler_PSRLD_d_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PSRLQ(()_[15, 211]) : Shift Packed Data Right Logical */
inline bool handler_PSRLQ_w_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PSRLQ(()_[15, 211]) : Shift Packed Data Right Logical */
inline bool handler_PSRLQ_d_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PADDQ(()_[15, 212]) : Add Packed Quadword Integers */
inline bool handler_PADDQ_w_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PADDQ(()_[15, 212]) : Add Packed Quadword Integers */
inline bool handler_PADDQ_d_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PMULLW(()_[15, 213]) : Multiply Packed Signed Integers and Store Low Result */
inline bool handler_PMULLW_w_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PMULLW(()_[15, 213]) : Multiply Packed Signed Integers and Store Low Result */
inline bool handler_PMULLW_d_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVQ((102,)_[15, 214]) : Move Quadword */
inline bool handler_MOVQ_w_rm_mod_xmm_u64_rm_reg_xmm_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVQ((102,)_[15, 214]) : Move Quadword */
inline bool handler_MOVQ_d_rm_mod_xmm_u64_rm_reg_xmm_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVDQ2Q((242,)_[15, 214]) : Move Quadword from XMM to MMX Technology Register */
inline bool handler_MOVDQ2Q_w_rm_reg_mmx_u64_rm_rm_xmm_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVDQ2Q((242,)_[15, 214]) : Move Quadword from XMM to MMX Technology Register */
inline bool handler_MOVDQ2Q_d_rm_reg_mmx_u64_rm_rm_xmm_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PMOVMSKB(()_[15, 215]) : Move Byte Mask */
inline bool handler_PMOVMSKB_w_rm_reg_reg_u32_rm_rm_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PMOVMSKB(()_[15, 215]) : Move Byte Mask */
inline bool handler_PMOVMSKB_d_rm_reg_reg_u32_rm_rm_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PAVGB(()_[15, 224]) : Average Packed Integers */
inline bool handler_PAVGB_w_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PAVGB(()_[15, 224]) : Average Packed Integers */
inline bool handler_PAVGB_d_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PSRAW(()_[15, 225]) : Shift Packed Data Right Arithmetic */
inline bool handler_PSRAW_w_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PSRAW(()_[15, 225]) : Shift Packed Data Right Arithmetic */
inline bool handler_PSRAW_d_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PSRAD(()_[15, 226]) : Shift Packed Data Right Arithmetic */
inline bool handler_PSRAD_w_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PSRAD(()_[15, 226]) : Shift Packed Data Right Arithmetic */
inline bool handler_PSRAD_d_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PAVGW(()_[15, 227]) : Average Packed Integers */
inline bool handler_PAVGW_w_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PAVGW(()_[15, 227]) : Average Packed Integers */
inline bool handler_PAVGW_d_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PMULHUW(()_[15, 228]) : Multiply Packed Unsigned Integers and Store High Result */
inline bool handler_PMULHUW_w_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PMULHUW(()_[15, 228]) : Multiply Packed Unsigned Integers and Store High Result */
inline bool handler_PMULHUW_d_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PMULHW(()_[15, 229]) : Multiply Packed Signed Integers and Store High Result */
inline bool handler_PMULHW_w_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PMULHW(()_[15, 229]) : Multiply Packed Signed Integers and Store High Result */
inline bool handler_PMULHW_d_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CVTPD2DQ((242,)_[15, 230]) : 
            Convert Packed Double-FP Values to  */
inline bool handler_CVTPD2DQ_w_rm_reg_xmm_u128_rm_mod_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CVTPD2DQ((242,)_[15, 230]) : 
            Convert Packed Double-FP Values to  */
inline bool handler_CVTPD2DQ_d_rm_reg_xmm_u128_rm_mod_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CVTTPD2DQ((102,)_[15, 230]) : 
            Convert with Trunc. Packed Double-FP Values to  */
inline bool handler_CVTTPD2DQ_w_rm_reg_xmm_u128_rm_mod_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CVTTPD2DQ((102,)_[15, 230]) : 
            Convert with Trunc. Packed Double-FP Values to  */
inline bool handler_CVTTPD2DQ_d_rm_reg_xmm_u128_rm_mod_xmm_d128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CVTDQ2PD((243,)_[15, 230]) : 
            Convert Packed DW Integers to  */
inline bool handler_CVTDQ2PD_w_rm_reg_xmm_d128_rm_mod_xmm_u128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* CVTDQ2PD((243,)_[15, 230]) : 
            Convert Packed DW Integers to  */
inline bool handler_CVTDQ2PD_d_rm_reg_xmm_d128_rm_mod_xmm_u128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVNTQ(()_[15, 231]) : Store of Quadword Using Non-Temporal Hint */
inline bool handler_MOVNTQ_w_rm_mem_u64_rm_reg_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVNTQ(()_[15, 231]) : Store of Quadword Using Non-Temporal Hint */
inline bool handler_MOVNTQ_d_rm_mem_u64_rm_reg_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVNTDQ((102,)_[15, 231]) : Store Double Quadword Using Non-Temporal Hint */
inline bool handler_MOVNTDQ_w_rm_mem_u128_rm_reg_xmm_u128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MOVNTDQ((102,)_[15, 231]) : Store Double Quadword Using Non-Temporal Hint */
inline bool handler_MOVNTDQ_d_rm_mem_u128_rm_reg_xmm_u128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PSUBSB(()_[15, 232]) : Subtract Packed Signed Integers with Signed Saturation */
inline bool handler_PSUBSB_w_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PSUBSB(()_[15, 232]) : Subtract Packed Signed Integers with Signed Saturation */
inline bool handler_PSUBSB_d_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PSUBSW(()_[15, 233]) : Subtract Packed Signed Integers with Signed Saturation */
inline bool handler_PSUBSW_w_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PSUBSW(()_[15, 233]) : Subtract Packed Signed Integers with Signed Saturation */
inline bool handler_PSUBSW_d_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PMINSW(()_[15, 234]) : Minimum of Packed Signed Word Integers */
inline bool handler_PMINSW_w_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PMINSW(()_[15, 234]) : Minimum of Packed Signed Word Integers */
inline bool handler_PMINSW_d_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* POR(()_[15, 235]) : Bitwise Logical OR */
inline bool handler_POR_w_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* POR(()_[15, 235]) : Bitwise Logical OR */
inline bool handler_POR_d_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PADDSB(()_[15, 236]) : Add Packed Signed Integers with Signed Saturation */
inline bool handler_PADDSB_w_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PADDSB(()_[15, 236]) : Add Packed Signed Integers with Signed Saturation */
inline bool handler_PADDSB_d_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PADDSW(()_[15, 237]) : Add Packed Signed Integers with Signed Saturation */
inline bool handler_PADDSW_w_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PADDSW(()_[15, 237]) : Add Packed Signed Integers with Signed Saturation */
inline bool handler_PADDSW_d_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PMAXSW(()_[15, 238]) : Maximum of Packed Signed Word Integers */
inline bool handler_PMAXSW_w_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PMAXSW(()_[15, 238]) : Maximum of Packed Signed Word Integers */
inline bool handler_PMAXSW_d_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PXOR(()_[15, 239]) : Logical Exclusive OR */
inline bool handler_PXOR_w_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PXOR(()_[15, 239]) : Logical Exclusive OR */
inline bool handler_PXOR_d_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* LDDQU((242,)_[15, 240]) : Load Unaligned Integer 128 Bits */
inline bool handler_LDDQU_w_rm_reg_xmm_u128_rm_mem_u128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* LDDQU((242,)_[15, 240]) : Load Unaligned Integer 128 Bits */
inline bool handler_LDDQU_d_rm_reg_xmm_u128_rm_mem_u128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PSLLW(()_[15, 241]) : Shift Packed Data Left Logical */
inline bool handler_PSLLW_w_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PSLLW(()_[15, 241]) : Shift Packed Data Left Logical */
inline bool handler_PSLLW_d_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PSLLD(()_[15, 242]) : Shift Packed Data Left Logical */
inline bool handler_PSLLD_w_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PSLLD(()_[15, 242]) : Shift Packed Data Left Logical */
inline bool handler_PSLLD_d_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PSLLQ(()_[15, 243]) : Shift Packed Data Left Logical */
inline bool handler_PSLLQ_w_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PSLLQ(()_[15, 243]) : Shift Packed Data Left Logical */
inline bool handler_PSLLQ_d_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PMULUDQ(()_[15, 244]) : Multiply Packed Unsigned DW Integers */
inline bool handler_PMULUDQ_w_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PMULUDQ(()_[15, 244]) : Multiply Packed Unsigned DW Integers */
inline bool handler_PMULUDQ_d_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PMADDWD(()_[15, 245]) : Multiply and Add Packed Integers */
inline bool handler_PMADDWD_w_rm_reg_mmx_u64_rm_mod_mmx_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PMADDWD(()_[15, 245]) : Multiply and Add Packed Integers */
inline bool handler_PMADDWD_d_rm_reg_mmx_u64_rm_mod_mmx_u32(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PSADBW(()_[15, 246]) : Compute Sum of Absolute Differences */
inline bool handler_PSADBW_w_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PSADBW(()_[15, 246]) : Compute Sum of Absolute Differences */
inline bool handler_PSADBW_d_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MASKMOVDQU((102,)_[15, 247]) : Store Selected Bytes of Double Quadword */
inline bool handler_MASKMOVDQU_w_rm_rm_xmm_u128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* MASKMOVDQU((102,)_[15, 247]) : Store Selected Bytes of Double Quadword */
inline bool handler_MASKMOVDQU_d_rm_rm_xmm_u128(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PSUBB(()_[15, 248]) : Subtract Packed Integers */
inline bool handler_PSUBB_w_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PSUBB(()_[15, 248]) : Subtract Packed Integers */
inline bool handler_PSUBB_d_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PSUBW(()_[15, 249]) : Subtract Packed Integers */
inline bool handler_PSUBW_w_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PSUBW(()_[15, 249]) : Subtract Packed Integers */
inline bool handler_PSUBW_d_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PSUBD(()_[15, 250]) : Subtract Packed Integers */
inline bool handler_PSUBD_w_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PSUBD(()_[15, 250]) : Subtract Packed Integers */
inline bool handler_PSUBD_d_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PSUBQ(()_[15, 251]) : Subtract Packed Quadword Integers */
inline bool handler_PSUBQ_w_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PSUBQ(()_[15, 251]) : Subtract Packed Quadword Integers */
inline bool handler_PSUBQ_d_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PADDB(()_[15, 252]) : Add Packed Integers */
inline bool handler_PADDB_w_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PADDB(()_[15, 252]) : Add Packed Integers */
inline bool handler_PADDB_d_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PADDW(()_[15, 253]) : Add Packed Integers */
inline bool handler_PADDW_w_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PADDW(()_[15, 253]) : Add Packed Integers */
inline bool handler_PADDW_d_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PADDD(()_[15, 254]) : Add Packed Integers */
inline bool handler_PADDD_w_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}

/* PADDD(()_[15, 254]) : Add Packed Integers */
inline bool handler_PADDD_d_rm_reg_mmx_u64_rm_mod_mmx_u64(Bit8u last, PhysPt &cseip) {
	return true;
}
}
#endif //PROJECT_CORE_LLVM_H
