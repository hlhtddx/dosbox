
    #ifndef PROJECT_CORE_LLVM_PARSE_H
    #define PROJECT_CORE_LLVM_PARSE_H
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
    
enum OpState {
	ST,
	ST_0f,
	ST_0f_00,
	ST_0f_01,
	ST_0f_18,
	ST_0f_1f,
	ST_0f_38,
	ST_0f_3a,
	ST_0f_71,
	ST_0f_72,
	ST_0f_73,
	ST_0f_90,
	ST_0f_91,
	ST_0f_92,
	ST_0f_93,
	ST_0f_94,
	ST_0f_95,
	ST_0f_96,
	ST_0f_97,
	ST_0f_98,
	ST_0f_99,
	ST_0f_9a,
	ST_0f_9b,
	ST_0f_9c,
	ST_0f_9d,
	ST_0f_9e,
	ST_0f_9f,
	ST_0f_ae,
	ST_0f_ba,
	ST_0f_c7,
	ST_66,
	ST_66_0f,
	ST_66_0f_38,
	ST_66_0f_3a,
	ST_66_0f_71,
	ST_66_0f_72,
	ST_66_0f_73,
	ST_66_0f_c7,
	ST_80,
	ST_81,
	ST_82,
	ST_83,
	ST_8f,
	ST_c0,
	ST_c1,
	ST_c6,
	ST_c7,
	ST_d0,
	ST_d1,
	ST_d2,
	ST_d3,
	ST_f2,
	ST_f2_0f,
	ST_f2_0f_38,
	ST_f3,
	ST_f3_0f,
	ST_f3_0f_c7,
	ST_f6,
	ST_f7,
	ST_fe,
	ST_ff,
	PR_26,
	PR_2e,
	PR_36,
	PR_3e,
	PR_64,
	PR_65,
	PR_67,
	PR_f0,
	I_ILLEGAL = 0x1000,
	I_AAA,
	I_AAD,
	I_AAM,
	I_AAS,
	I_ADC_Eb_Gb,
	I_ADC_Eb_Ib,
	I_ADC_Evqp_Gvqp,
	I_ADC_Evqp_Ibs,
	I_ADC_Evqp_Ivds,
	I_ADC_Gb_Eb,
	I_ADC_Gvqp_Evqp,
	I_ADC_acc_AL_Ib,
	I_ADC_acc_eAX_Ivds,
	I_ADDPD_Vpd_Wpd,
	I_ADDPS_Vps_Wps,
	I_ADDSD_Vsd_Wsd,
	I_ADDSS_Vss_Wss,
	I_ADDSUBPD_Vpd_Wpd,
	I_ADDSUBPS_Vps_Wps,
	I_ADD_Eb_Gb,
	I_ADD_Eb_Ib,
	I_ADD_Evqp_Gvqp,
	I_ADD_Evqp_Ibs,
	I_ADD_Evqp_Ivds,
	I_ADD_Gb_Eb,
	I_ADD_Gvqp_Evqp,
	I_ADD_acc_AL_Ib,
	I_ADD_acc_eAX_Ivds,
	I_ADX_Ib,
	I_AMX_Ib,
	I_ANDNPD_Vpd_Wpd,
	I_ANDNPS_Vps_Wps,
	I_ANDPD_Vpd_Wpd,
	I_ANDPS_Vps_Wps,
	I_AND_Eb_Gb,
	I_AND_Eb_Ib,
	I_AND_Evqp_Gvqp,
	I_AND_Evqp_Ibs,
	I_AND_Evqp_Ivds,
	I_AND_Gb_Eb,
	I_AND_Gvqp_Evqp,
	I_AND_acc_AL_Ib,
	I_AND_acc_eAX_Ivds,
	I_ARPL_Ew_Gw,
	I_BLENDPD_Vpd_Wpd_Ib,
	I_BLENDPS_Vps_Wps_Ib,
	I_BLENDVPD_Vpd_Wpd,
	I_BLENDVPS_Vps_Wps,
	I_BOUND_Gv_Ma,
	I_BSF_Gvqp_Evqp,
	I_BSR_Gvqp_Evqp,
	I_BSWAP_eAX,
	I_BSWAP_eBP,
	I_BSWAP_eBX,
	I_BSWAP_eCX,
	I_BSWAP_eDI,
	I_BSWAP_eDX,
	I_BSWAP_eSI,
	I_BSWAP_eSP,
	I_BTC_Evqp_Gvqp,
	I_BTC_Evqp_Ib,
	I_BTR_Evqp_Gvqp,
	I_BTR_Evqp_Ib,
	I_BTS_Evqp_Gvqp,
	I_BTS_Evqp_Ib,
	I_BT_Evqp_Gvqp,
	I_BT_Evqp_Ib,
	I_CALLF_Ap,
	I_CALLF_Mptp,
	I_CALL_Ev,
	I_CALL_Jvds,
	I_CBW,
	I_CDQ,
	I_CLC,
	I_CLD,
	I_CLFLUSH_Mb,
	I_CLI,
	I_CLTS,
	I_CMC,
	I_CMOVBE_Gvqp_Evqp,
	I_CMOVB_Gvqp_Evqp,
	I_CMOVLE_Gvqp_Evqp,
	I_CMOVL_Gvqp_Evqp,
	I_CMOVNBE_Gvqp_Evqp,
	I_CMOVNB_Gvqp_Evqp,
	I_CMOVNLE_Gvqp_Evqp,
	I_CMOVNL_Gvqp_Evqp,
	I_CMOVNO_Gvqp_Evqp,
	I_CMOVNP_Gvqp_Evqp,
	I_CMOVNS_Gvqp_Evqp,
	I_CMOVNZ_Gvqp_Evqp,
	I_CMOVO_Gvqp_Evqp,
	I_CMOVP_Gvqp_Evqp,
	I_CMOVS_Gvqp_Evqp,
	I_CMOVZ_Gvqp_Evqp,
	I_CMPPD_Vpd_Wpd_Ib,
	I_CMPPS_Vps_Wps_Ib,
	I_CMPSD_Vsd_Wsd_Ib,
	I_CMPSS_Vss_Wss_Ib,
	I_CMPS_Yb_Xb,
	I_CMPS_Yv_Xv,
	I_CMPS_Yw_Xw,
	I_CMPXCHG8B_Mq,
	I_CMPXCHG_Eb_Gb,
	I_CMPXCHG_Evqp_Gvqp,
	I_CMP_Eb_Gb,
	I_CMP_Eb_Ib,
	I_CMP_Evqp_Gvqp,
	I_CMP_Evqp_Ibs,
	I_CMP_Evqp_Ivds,
	I_CMP_Gb_Eb,
	I_CMP_Gvqp_Evqp,
	I_CMP_acc_AL_Ib,
	I_CMP_acc_eAX_Ivds,
	I_COMISD_Vsd_Wsd,
	I_COMISS_Vss_Wss,
	I_CPUID_serial,
	I_CRC32_Gdqp_Eb,
	I_CRC32_Gdqp_Evqp,
	I_CVTDQ2PD_Vpd_Wdq,
	I_CVTDQ2PS_Vps_Wdq,
	I_CVTPD2DQ_Vdq_Wpd,
	I_CVTPD2PI_Ppi_Wpd,
	I_CVTPD2PS_Vps_Wpd,
	I_CVTPI2PD_Vpd_Qpi,
	I_CVTPI2PS_Vps_Qpi,
	I_CVTPS2DQ_Vdq_Wps,
	I_CVTPS2PD_Vpd_Wps,
	I_CVTPS2PI_Ppi_Wpsq,
	I_CVTSD2SI_Gdqp_Wsd,
	I_CVTSD2SS_Vss_Wsd,
	I_CVTSI2SD_Vsd_Edqp,
	I_CVTSI2SS_Vss_Edqp,
	I_CVTSS2SD_Vsd_Wss,
	I_CVTSS2SI_Gdqp_Wss,
	I_CVTTPD2DQ_Vdq_Wpd,
	I_CVTTPD2PI_Ppi_Wpd,
	I_CVTTPS2DQ_Vdq_Wps,
	I_CVTTPS2PI_Ppi_Wpsq,
	I_CVTTSD2SI_Gdqp_Wsd,
	I_CVTTSS2SI_Gdqp_Wss,
	I_CWD,
	I_CWDE,
	I_DAA,
	I_DAS,
	I_DEC_Eb,
	I_DEC_Evqp,
	I_DEC_eAX,
	I_DEC_eBP,
	I_DEC_eBX,
	I_DEC_eCX,
	I_DEC_eDI,
	I_DEC_eDX,
	I_DEC_eSI,
	I_DEC_eSP,
	I_DIVPD_Vpd_Wpd,
	I_DIVPS_Vps_Wps,
	I_DIVSD_Vsd_Wsd,
	I_DIVSS_Vss_Wss,
	I_DIV_Eb,
	I_DIV_Evqp,
	I_DPPD_Vpd_Wpd,
	I_DPPS_Vps_Wps,
	I_EMMS,
	I_ENTER_Iw_Ib,
	I_EXTRACTPS_Ed_Vdq_Ib,
	I_FWAIT,
	I_FXRSTOR_Mstx,
	I_FXSAVE_Mstx,
	I_GETSEC,
	I_HADDPD_Vpd_Wpd,
	I_HADDPS_Vps_Wps,
	I_HLT,
	I_HSUBPD_Vpd_Wpd,
	I_HSUBPS_Vps_Wps,
	I_IDIV_Eb,
	I_IDIV_Evqp,
	I_IMUL_Eb,
	I_IMUL_Evqp,
	I_IMUL_Gvqp_Evqp,
	I_IMUL_Gvqp_Evqp_Ibs,
	I_IMUL_Gvqp_Evqp_Ivds,
	I_INC_Eb,
	I_INC_Evqp,
	I_INC_eAX,
	I_INC_eBP,
	I_INC_eBX,
	I_INC_eCX,
	I_INC_eDI,
	I_INC_eDX,
	I_INC_eSI,
	I_INC_eSP,
	I_INSERTPS_Vps_Ups_Ib,
	I_INS_Yb_DX,
	I_INS_Yv_DX,
	I_INS_Yw_DX,
	I_INTO,
	I_INT_I,
	I_INT_Ib,
	I_INVD_serial,
	I_INVEPT_Gd_Mdq,
	I_INVLPG_serial_M,
	I_INVVPID_Gd_Mdq,
	I_IN_AL_DX,
	I_IN_AL_Ib,
	I_IN_eAX_DX,
	I_IN_eAX_Ib,
	I_IRET,
	I_IRETD,
	I_JBE_Jbs,
	I_JBE_Jvds,
	I_JB_Jbs,
	I_JB_Jvds,
	I_JCXZ_Jbs,
	I_JLE_Jbs,
	I_JLE_Jvds,
	I_JL_Jbs,
	I_JL_Jvds,
	I_JMPF_Ap,
	I_JMPF_Mptp,
	I_JMP_Ev,
	I_JMP_Jbs,
	I_JMP_Jvds,
	I_JNBE_Jbs,
	I_JNBE_Jvds,
	I_JNB_Jbs,
	I_JNB_Jvds,
	I_JNLE_Jbs,
	I_JNLE_Jvds,
	I_JNL_Jbs,
	I_JNL_Jvds,
	I_JNO_Jbs,
	I_JNO_Jvds,
	I_JNP_Jbs,
	I_JNP_Jvds,
	I_JNS_Jbs,
	I_JNS_Jvds,
	I_JNZ_Jbs,
	I_JNZ_Jvds,
	I_JO_Jbs,
	I_JO_Jvds,
	I_JP_Jbs,
	I_JP_Jvds,
	I_JS_Jbs,
	I_JS_Jvds,
	I_JZ_Jbs,
	I_JZ_Jvds,
	I_LAHF,
	I_LAR_Gvqp_Mw,
	I_LDDQU_Vdq_Mdq,
	I_LDMXCSR_Md,
	I_LDS_Gv_Mp,
	I_LEAVE,
	I_LEA_Gvqp_M,
	I_LES_Gv_Mp,
	I_LFENCE,
	I_LFS_Gvqp_Mptp,
	I_LGDT_serial_Ms,
	I_LGS_Gvqp_Mptp,
	I_LIDT_serial_Ms,
	I_LLDT_serial_Ew,
	I_LMSW_serial_Ew,
	I_LODS_Xb,
	I_LODS_Xv,
	I_LODS_Xw,
	I_LOOPNZ_Jbs,
	I_LOOPZ_Jbs,
	I_LOOP_Jbs,
	I_LSL_Gvqp_Mw,
	I_LSS_Gvqp_Mptp,
	I_LTR_serial_Ew,
	I_MASKMOVDQU_Vdq_Udq,
	I_MASKMOVQ_Pq_Nq,
	I_MAXPD_Vpd_Wpd,
	I_MAXPS_Vps_Wps,
	I_MAXSD_Vsd_Wsd,
	I_MAXSS_Vss_Wss,
	I_MFENCE,
	I_MINPD_Vpd_Wpd,
	I_MINPS_Vps_Wps,
	I_MINSD_Vsd_Wsd,
	I_MINSS_Vss_Wss,
	I_MONITOR,
	I_MOVAPD_Vpd_Wpd,
	I_MOVAPD_Wpd_Vpd,
	I_MOVAPS_Vps_Wps,
	I_MOVAPS_Wps_Vps,
	I_MOVBE_Gvqp_Mvqp,
	I_MOVBE_Mvqp_Gvqp,
	I_MOVDDUP_Vq_Wq,
	I_MOVDQ2Q_Pq_Uq,
	I_MOVDQA_Vdq_Wdq,
	I_MOVDQA_Wdq_Vdq,
	I_MOVDQU_Vdq_Wdq,
	I_MOVDQU_Wdq_Vdq,
	I_MOVD_Ed_Pq,
	I_MOVD_Ed_Vdq,
	I_MOVD_Pq_Ed,
	I_MOVD_Vdq_Ed,
	I_MOVHLPS_Vq_Uq,
	I_MOVHPD_Mq_Vq,
	I_MOVHPD_Vq_Mq,
	I_MOVHPS_Mq_Vq,
	I_MOVHPS_Vq_Mq,
	I_MOVLHPS_Vq_Uq,
	I_MOVLPD_Mq_Vq,
	I_MOVLPD_Vq_Mq,
	I_MOVLPS_Mq_Vq,
	I_MOVLPS_Vq_Mq,
	I_MOVMSKPD_Gdqp_Upd,
	I_MOVMSKPS_Gdqp_Ups,
	I_MOVNTDQA_Vdq_Mdq,
	I_MOVNTDQ_Mdq_Vdq,
	I_MOVNTI_Mdqp_Gdqp,
	I_MOVNTPD_Mpd_Vpd,
	I_MOVNTPS_Mps_Vps,
	I_MOVNTQ_Mq_Pq,
	I_MOVQ2DQ_Vdq_Nq,
	I_MOVQ_Pq_Qq,
	I_MOVQ_Qq_Pq,
	I_MOVQ_Vq_Wq,
	I_MOVQ_Wq_Vq,
	I_MOVSD_Vsd_Wsd,
	I_MOVSD_Wsd_Vsd,
	I_MOVSHDUP_Vq_Wq,
	I_MOVSLDUP_Vq_Wq,
	I_MOVSS_Vss_Wss,
	I_MOVSS_Wss_Vss,
	I_MOVSX_Gvqp_Eb,
	I_MOVSX_Gvqp_Ew,
	I_MOVS_Yb_Xb,
	I_MOVS_Yv_Xv,
	I_MOVS_Yw_Xw,
	I_MOVUPD_Vpd_Wpd,
	I_MOVUPD_Wpd_Vpd,
	I_MOVUPS_Vps_Wps,
	I_MOVUPS_Wps_Vps,
	I_MOVZX_Gvqp_Eb,
	I_MOVZX_Gvqp_Ew,
	I_MOV_AH_Ib,
	I_MOV_AL_Ib,
	I_MOV_AL_Ob,
	I_MOV_BH_Ib,
	I_MOV_BL_Ib,
	I_MOV_CH_Ib,
	I_MOV_CL_Ib,
	I_MOV_DH_Ib,
	I_MOV_DL_Ib,
	I_MOV_Eb_Gb,
	I_MOV_Eb_Ib,
	I_MOV_Evqp_Gvqp,
	I_MOV_Evqp_Ivds,
	I_MOV_Gb_Eb,
	I_MOV_Gvqp_Evqp,
	I_MOV_Mw_Sw,
	I_MOV_Ob_AL,
	I_MOV_Ovqp_eAX,
	I_MOV_Sw_Ew,
	I_MOV_eAX_Ivqp,
	I_MOV_eAX_Ovqp,
	I_MOV_eBP_Ivqp,
	I_MOV_eBX_Ivqp,
	I_MOV_eCX_Ivqp,
	I_MOV_eDI_Ivqp,
	I_MOV_eDX_Ivqp,
	I_MOV_eSI_Ivqp,
	I_MOV_eSP_Ivqp,
	I_MPSADBW_Vdq_Wdq_Ib,
	I_MULPD_Vpd_Wpd,
	I_MULPS_Vps_Wps,
	I_MULSD_Vsd_Wsd,
	I_MULSS_Vss_Wss,
	I_MUL_Eb,
	I_MUL_Evqp,
	I_MWAIT,
	I_NEG_Eb,
	I_NEG_Evqp,
	I_NOP,
	I_NOP_Ev,
	I_NOP_nop,
	I_NOT_Eb,
	I_NOT_Evqp,
	I_ORPD_Vpd_Wpd,
	I_ORPS_Vps_Wps,
	I_OR_Eb_Gb,
	I_OR_Eb_Ib,
	I_OR_Evqp_Gvqp,
	I_OR_Evqp_Ibs,
	I_OR_Evqp_Ivds,
	I_OR_Gb_Eb,
	I_OR_Gvqp_Evqp,
	I_OR_acc_AL_Ib,
	I_OR_acc_eAX_Ivds,
	I_OUTS_DX_Xb,
	I_OUTS_DX_Xv,
	I_OUTS_DX_Xw,
	I_OUT_DX_AL,
	I_OUT_DX_eAX,
	I_OUT_Ib_AL,
	I_OUT_Ib_eAX,
	I_PABSB_Pq_Qq,
	I_PABSB_Vdq_Wdq,
	I_PABSD_Pq_Qq,
	I_PABSD_Vdq_Wdq,
	I_PABSW_Pq_Qq,
	I_PABSW_Vdq_Wdq,
	I_PACKSSDW_Pq_Qq,
	I_PACKSSDW_Vdq_Wdq,
	I_PACKSSWB_Pq_Qd,
	I_PACKSSWB_Vdq_Wdq,
	I_PACKUSDW_Vdq_Wdq,
	I_PACKUSWB_Pq_Qq,
	I_PACKUSWB_Vdq_Wdq,
	I_PADDB_Pq_Qq,
	I_PADDB_Vdq_Wdq,
	I_PADDD_Pq_Qq,
	I_PADDD_Vdq_Wdq,
	I_PADDQ_Pq_Qq,
	I_PADDQ_Vdq_Wdq,
	I_PADDSB_Pq_Qq,
	I_PADDSB_Vdq_Wdq,
	I_PADDSW_Pq_Qq,
	I_PADDSW_Vdq_Wdq,
	I_PADDW_Pq_Qq,
	I_PADDW_Vdq_Wdq,
	I_PALIGNR_Pq_Qq,
	I_PALIGNR_Vdq_Wdq,
	I_PAUSE,
	I_PAVGB_Pq_Qq,
	I_PAVGB_Vdq_Wdq,
	I_PAVGW_Pq_Qq,
	I_PAVGW_Vdq_Wdq,
	I_PBLENDVB_Vdq_Wdq,
	I_PBLENDW_Vdq_Wdq_Ib,
	I_PCMPEQB_Pq_Qq,
	I_PCMPEQB_Vdq_Wdq,
	I_PCMPEQD_Pq_Qq,
	I_PCMPEQD_Vdq_Wdq,
	I_PCMPEQQ_Vdq_Wdq,
	I_PCMPEQW_Pq_Qq,
	I_PCMPEQW_Vdq_Wdq,
	I_PCMPESTRI_Vdq_Wdq_Ib,
	I_PCMPESTRM_Vdq_Wdq_Ib,
	I_PCMPGTB_Pq_Qd,
	I_PCMPGTB_Vdq_Wdq,
	I_PCMPGTD_Pq_Qd,
	I_PCMPGTD_Vdq_Wdq,
	I_PCMPGTQ_Vdq_Wdq,
	I_PCMPGTW_Pq_Qd,
	I_PCMPGTW_Vdq_Wdq,
	I_PCMPISTRI_Vdq_Wdq_Ib,
	I_PCMPISTRM_Vdq_Wdq_Ib,
	I_PEXTRB_Mb_Vdq_Ib,
	I_PEXTRD_Ed_Vdq_Ib,
	I_PEXTRW_Gdqp_Nq_Ib,
	I_PEXTRW_Gdqp_Udq_Ib,
	I_PEXTRW_Mw_Vdq_Ib,
	I_PHADDD_Pq_Qq,
	I_PHADDD_Vdq_Wdq,
	I_PHADDSW_Pq_Qq,
	I_PHADDSW_Vdq_Wdq,
	I_PHADDW_Pq_Qq,
	I_PHADDW_Vdq_Wdq,
	I_PHMINPOSUW_Vdq_Wdq,
	I_PHSUBD_Pq_Qq,
	I_PHSUBD_Vdq_Wdq,
	I_PHSUBSW_Pq_Qq,
	I_PHSUBSW_Vdq_Wdq,
	I_PHSUBW_Pq_Qq,
	I_PHSUBW_Vdq_Wdq,
	I_PINSRB_Vdq_Mb_Ib,
	I_PINSRD_Vdq_Ed_Ib,
	I_PINSRW_Pq_Rdqp_Ib,
	I_PINSRW_Vdq_Rdqp_Ib,
	I_PMADDUBSW_Pq_Qq,
	I_PMADDUBSW_Vdq_Wdq,
	I_PMADDWD_Pq_Qd,
	I_PMADDWD_Vdq_Wdq,
	I_PMAXSB_Vdq_Wdq,
	I_PMAXSD_Vdq_Wdq,
	I_PMAXSW_Pq_Qq,
	I_PMAXSW_Vdq_Wdq,
	I_PMAXUD_Vdq_Wdq,
	I_PMAXUW_Vdq_Wdq,
	I_PMINSB_Vdq_Wdq,
	I_PMINSD_Vdq_Wdq,
	I_PMINSW_Pq_Qq,
	I_PMINSW_Vdq_Wdq,
	I_PMINUD_Vdq_Wdq,
	I_PMINUW_Vdq_Wdq,
	I_PMOVMSKB_Gdqp_Nq,
	I_PMOVMSKB_Gdqp_Udq,
	I_PMOVSXBD_Vdq_Md,
	I_PMOVSXBQ_Vdq_Mw,
	I_PMOVSXBW_Vdq_Mq,
	I_PMOVSXDQ_Vdq_Mq,
	I_PMOVSXWD_Vdq_Mq,
	I_PMOVSXWQ_Vdq_Md,
	I_PMOVZXBD_Vdq_Md,
	I_PMOVZXBQ_Vdq_Mw,
	I_PMOVZXBW_Vdq_Mq,
	I_PMOVZXDQ_Vdq_Mq,
	I_PMOVZXWD_Vdq_Mq,
	I_PMOVZXWQ_Vdq_Md,
	I_PMULDQ_Vdq_Wdq,
	I_PMULHRSW_Pq_Qq,
	I_PMULHRSW_Vdq_Wdq,
	I_PMULHUW_Pq_Qq,
	I_PMULHUW_Vdq_Wdq,
	I_PMULHW_Pq_Qq,
	I_PMULHW_Vdq_Wdq,
	I_PMULLD_Vdq_Wdq,
	I_PMULLW_Pq_Qq,
	I_PMULLW_Vdq_Wdq,
	I_PMULUDQ_Pq_Qq,
	I_PMULUDQ_Vdq_Wdq,
	I_POPA,
	I_POPAD,
	I_POPCNT_Gvqp_Evqp,
	I_POPF,
	I_POPFD,
	I_POP_DS,
	I_POP_ES,
	I_POP_Ev,
	I_POP_FS,
	I_POP_GS,
	I_POP_delaysint_SS,
	I_POP_eAX,
	I_POP_eBP,
	I_POP_eBX,
	I_POP_eCX,
	I_POP_eDI,
	I_POP_eDX,
	I_POP_eSI,
	I_POP_eSP,
	I_POR_Pq_Qq,
	I_POR_Vdq_Wdq,
	I_PREFETCHNTA_Mb,
	I_PREFETCHT0_Mb,
	I_PREFETCHT1_Mb,
	I_PREFETCHT2_Mb,
	I_PSADBW_Pq_Qq,
	I_PSADBW_Vdq_Wdq,
	I_PSHUFB_Pq_Qq,
	I_PSHUFB_Vdq_Wdq,
	I_PSHUFD_Vdq_Wdq_Ib,
	I_PSHUFHW_Vdq_Wdq_Ib,
	I_PSHUFLW_Vdq_Wdq_Ib,
	I_PSHUFW_Pq_Qq_Ib,
	I_PSIGNB_Pq_Qq,
	I_PSIGNB_Vdq_Wdq,
	I_PSIGND_Pq_Qq,
	I_PSIGND_Vdq_Wdq,
	I_PSIGNW_Pq_Qq,
	I_PSIGNW_Vdq_Wdq,
	I_PSLLDQ_Udq_Ib,
	I_PSLLD_Nq_Ib,
	I_PSLLD_Pq_Qq,
	I_PSLLD_Udq_Ib,
	I_PSLLD_Vdq_Wdq,
	I_PSLLQ_Nq_Ib,
	I_PSLLQ_Pq_Qq,
	I_PSLLQ_Udq_Ib,
	I_PSLLQ_Vdq_Wdq,
	I_PSLLW_Nq_Ib,
	I_PSLLW_Pq_Qq,
	I_PSLLW_Udq_Ib,
	I_PSLLW_Vdq_Wdq,
	I_PSRAD_Nq_Ib,
	I_PSRAD_Pq_Qq,
	I_PSRAD_Udq_Ib,
	I_PSRAD_Vdq_Wdq,
	I_PSRAW_Nq_Ib,
	I_PSRAW_Pq_Qq,
	I_PSRAW_Udq_Ib,
	I_PSRAW_Vdq_Wdq,
	I_PSRLDQ_Udq_Ib,
	I_PSRLD_Nq_Ib,
	I_PSRLD_Pq_Qq,
	I_PSRLD_Udq_Ib,
	I_PSRLD_Vdq_Wdq,
	I_PSRLQ_Nq_Ib,
	I_PSRLQ_Pq_Qq,
	I_PSRLQ_Udq_Ib,
	I_PSRLQ_Vdq_Wdq,
	I_PSRLW_Nq_Ib,
	I_PSRLW_Pq_Qq,
	I_PSRLW_Udq_Ib,
	I_PSRLW_Vdq_Wdq,
	I_PSUBB_Pq_Qq,
	I_PSUBB_Vdq_Wdq,
	I_PSUBD_Pq_Qq,
	I_PSUBD_Vdq_Wdq,
	I_PSUBQ_Pq_Qq,
	I_PSUBQ_Vdq_Wdq,
	I_PSUBSB_Pq_Qq,
	I_PSUBSB_Vdq_Wdq,
	I_PSUBSW_Pq_Qq,
	I_PSUBSW_Vdq_Wdq,
	I_PSUBW_Pq_Qq,
	I_PSUBW_Vdq_Wdq,
	I_PTEST_Vdq_Wdq,
	I_PUNPCKHBW_Pq_Qq,
	I_PUNPCKHBW_Vdq_Wdq,
	I_PUNPCKHDQ_Pq_Qq,
	I_PUNPCKHDQ_Vdq_Wdq,
	I_PUNPCKHQDQ_Vdq_Wdq,
	I_PUNPCKHWD_Pq_Qq,
	I_PUNPCKHWD_Vdq_Wdq,
	I_PUNPCKLBW_Pq_Qd,
	I_PUNPCKLBW_Vdq_Wdq,
	I_PUNPCKLDQ_Pq_Qd,
	I_PUNPCKLDQ_Vdq_Wdq,
	I_PUNPCKLQDQ_Vdq_Wdq,
	I_PUNPCKLWD_Pq_Qd,
	I_PUNPCKLWD_Vdq_Wdq,
	I_PUSHA,
	I_PUSHAD,
	I_PUSHF,
	I_PUSHFD,
	I_PUSH_CS,
	I_PUSH_DS,
	I_PUSH_ES,
	I_PUSH_Ev,
	I_PUSH_FS,
	I_PUSH_GS,
	I_PUSH_Ibss,
	I_PUSH_Ivs,
	I_PUSH_SS,
	I_PUSH_eAX,
	I_PUSH_eBP,
	I_PUSH_eBX,
	I_PUSH_eCX,
	I_PUSH_eDI,
	I_PUSH_eDX,
	I_PUSH_eSI,
	I_PUSH_eSP,
	I_PXOR_Pq_Qq,
	I_PXOR_Vdq_Wdq,
	I_RCL_Eb_CL,
	I_RCL_Eb_I,
	I_RCL_Eb_Ib,
	I_RCL_Evqp_CL,
	I_RCL_Evqp_I,
	I_RCL_Evqp_Ib,
	I_RCPPS_Vps_Wps,
	I_RCPSS_Vss_Wss,
	I_RCR_Eb_CL,
	I_RCR_Eb_I,
	I_RCR_Eb_Ib,
	I_RCR_Evqp_CL,
	I_RCR_Evqp_I,
	I_RCR_Evqp_Ib,
	I_RDMSR,
	I_RDPMC,
	I_RDTSC,
	I_RDTSCP_serial,
	I_RETF,
	I_RETF_Iw,
	I_RETN,
	I_RETN_Iw,
	I_ROL_Eb_CL,
	I_ROL_Eb_I,
	I_ROL_Eb_Ib,
	I_ROL_Evqp_CL,
	I_ROL_Evqp_I,
	I_ROL_Evqp_Ib,
	I_ROR_Eb_CL,
	I_ROR_Eb_I,
	I_ROR_Eb_Ib,
	I_ROR_Evqp_CL,
	I_ROR_Evqp_I,
	I_ROR_Evqp_Ib,
	I_ROUNDPD_Vps_Wpd_Ib,
	I_ROUNDPS_Vps_Wps_Ib,
	I_ROUNDSD_Vsd_Wsd_Ib,
	I_ROUNDSS_Vss_Wss_Ib,
	I_RSM,
	I_RSQRTPS_Vps_Wps,
	I_RSQRTSS_Vss_Wss,
	I_SAHF,
	I_SAR_Eb_CL,
	I_SAR_Eb_I,
	I_SAR_Eb_Ib,
	I_SAR_Evqp_CL,
	I_SAR_Evqp_I,
	I_SAR_Evqp_Ib,
	I_SBB_Eb_Gb,
	I_SBB_Eb_Ib,
	I_SBB_Evqp_Gvqp,
	I_SBB_Evqp_Ibs,
	I_SBB_Evqp_Ivds,
	I_SBB_Gb_Eb,
	I_SBB_Gvqp_Evqp,
	I_SBB_acc_AL_Ib,
	I_SBB_acc_eAX_Ivds,
	I_SCAS_Yb,
	I_SCAS_Yv,
	I_SCAS_Yw,
	I_SETBE_Eb,
	I_SETB_Eb,
	I_SETLE_Eb,
	I_SETL_Eb,
	I_SETNBE_Eb,
	I_SETNB_Eb,
	I_SETNLE_Eb,
	I_SETNL_Eb,
	I_SETNO_Eb,
	I_SETNP_Eb,
	I_SETNS_Eb,
	I_SETNZ_Eb,
	I_SETO_Eb,
	I_SETP_Eb,
	I_SETS_Eb,
	I_SETZ_Eb,
	I_SFENCE,
	I_SGDT_Ms,
	I_SHLD_Evqp_Gvqp_CL,
	I_SHLD_Evqp_Gvqp_Ib,
	I_SHL_Eb_CL,
	I_SHL_Eb_I,
	I_SHL_Eb_Ib,
	I_SHL_Evqp_CL,
	I_SHL_Evqp_I,
	I_SHL_Evqp_Ib,
	I_SHRD_Evqp_Gvqp_CL,
	I_SHRD_Evqp_Gvqp_Ib,
	I_SHR_Eb_CL,
	I_SHR_Eb_I,
	I_SHR_Eb_Ib,
	I_SHR_Evqp_CL,
	I_SHR_Evqp_I,
	I_SHR_Evqp_Ib,
	I_SHUFPD_Vpd_Wpd_Ib,
	I_SHUFPS_Vps_Wps_Ib,
	I_SIDT_Ms,
	I_SLDT_Mw,
	I_SMSW_Mw,
	I_SQRTPD_Vpd_Wpd,
	I_SQRTPS_Vps_Wps,
	I_SQRTSD_Vsd_Wsd,
	I_SQRTSS_Vss_Wss,
	I_STC,
	I_STD,
	I_STI_delaysint_cond,
	I_STMXCSR_Md,
	I_STOS_Yb,
	I_STOS_Yv,
	I_STOS_Yw,
	I_STR_Mw,
	I_SUBPD_Vpd_Wpd,
	I_SUBPS_Vps_Wps,
	I_SUBSD_Vsd_Wsd,
	I_SUBSS_Vss_Wss,
	I_SUB_Eb_Gb,
	I_SUB_Eb_Ib,
	I_SUB_Evqp_Gvqp,
	I_SUB_Evqp_Ibs,
	I_SUB_Evqp_Ivds,
	I_SUB_Gb_Eb,
	I_SUB_Gvqp_Evqp,
	I_SUB_acc_AL_Ib,
	I_SUB_acc_eAX_Ivds,
	I_SYSENTER,
	I_SYSEXIT,
	I_TEST_Eb_Gb,
	I_TEST_Eb_Ib,
	I_TEST_Evqp_Gvqp,
	I_TEST_Evqp_Ivqp,
	I_TEST_acc_AL_Ib,
	I_TEST_acc_eAX_Ivds,
	I_UCOMISD_Vsd_Wsd,
	I_UCOMISS_Vss_Wss,
	I_UNPCKHPD_Vpd_Wpd,
	I_UNPCKHPS_Vps_Wq,
	I_UNPCKLPD_Vpd_Wpd,
	I_UNPCKLPS_Vps_Wq,
	I_VERR_Ew,
	I_VERW_Ew,
	I_VMCALL,
	I_VMCLEAR_Mq,
	I_VMLAUNCH,
	I_VMPTRLD_Mq,
	I_VMPTRST_Mq,
	I_VMREAD_Ed_Gd,
	I_VMRESUME,
	I_VMWRITE_Gd_Ed,
	I_VMXOFF,
	I_VMXON_Mq,
	I_WBINVD_serial,
	I_WRMSR_serial,
	I_XADD_Eb_Gb,
	I_XADD_Evqp_Gvqp,
	I_XCHG_Gb_Eb,
	I_XCHG_Gvqp_Evqp,
	I_XCHG_acc_eAX_eAX,
	I_XCHG_acc_eBP_eAX,
	I_XCHG_acc_eBX_eAX,
	I_XCHG_acc_eCX_eAX,
	I_XCHG_acc_eDI_eAX,
	I_XCHG_acc_eDX_eAX,
	I_XCHG_acc_eSI_eAX,
	I_XCHG_acc_eSP_eAX,
	I_XGETBV,
	I_XLAT_BBb,
	I_XORPD_Vpd_Wpd,
	I_XORPS_Vps_Wps,
	I_XOR_Eb_Gb,
	I_XOR_Eb_Ib,
	I_XOR_Evqp_Gvqp,
	I_XOR_Evqp_Ibs,
	I_XOR_Evqp_Ivds,
	I_XOR_Gb_Eb,
	I_XOR_Gvqp_Evqp,
	I_XOR_acc_AL_Ib,
	I_XOR_acc_eAX_Ivds,
	I_XRSTOR_M,
	I_XSAVE_M,
	I_XSETBV,
};
class CpuRunnerX86 {
private:
static const OpState table[];
static const OpState table_0f[];
static const OpState table_0f_00[];
static const OpState table_0f_01[];
static const OpState table_0f_18[];
static const OpState table_0f_1f[];
static const OpState table_0f_38[];
static const OpState table_0f_3a[];
static const OpState table_0f_71[];
static const OpState table_0f_72[];
static const OpState table_0f_73[];
static const OpState table_0f_90[];
static const OpState table_0f_91[];
static const OpState table_0f_92[];
static const OpState table_0f_93[];
static const OpState table_0f_94[];
static const OpState table_0f_95[];
static const OpState table_0f_96[];
static const OpState table_0f_97[];
static const OpState table_0f_98[];
static const OpState table_0f_99[];
static const OpState table_0f_9a[];
static const OpState table_0f_9b[];
static const OpState table_0f_9c[];
static const OpState table_0f_9d[];
static const OpState table_0f_9e[];
static const OpState table_0f_9f[];
static const OpState table_0f_ae[];
static const OpState table_0f_ba[];
static const OpState table_0f_c7[];
static const OpState table_66[];
static const OpState table_66_0f[];
static const OpState table_66_0f_38[];
static const OpState table_66_0f_3a[];
static const OpState table_66_0f_71[];
static const OpState table_66_0f_72[];
static const OpState table_66_0f_73[];
static const OpState table_66_0f_c7[];
static const OpState table_80[];
static const OpState table_81[];
static const OpState table_82[];
static const OpState table_83[];
static const OpState table_8f[];
static const OpState table_c0[];
static const OpState table_c1[];
static const OpState table_c6[];
static const OpState table_c7[];
static const OpState table_d0[];
static const OpState table_d1[];
static const OpState table_d2[];
static const OpState table_d3[];
static const OpState table_f2[];
static const OpState table_f2_0f[];
static const OpState table_f2_0f_38[];
static const OpState table_f3[];
static const OpState table_f3_0f[];
static const OpState table_f3_0f_c7[];
static const OpState table_f6[];
static const OpState table_f7[];
static const OpState table_fe[];
static const OpState table_ff[];
static const OpState* const TableState[];


/* _37:AAA ASCII Adjust After Addition */
inline void Handle_AAA(Bit8u last, PhysPt &cseip) {
};


/* _d5_0a:AAD ASCII Adjust AX Before Division */
inline void Handle_AAD(Bit8u last, PhysPt &cseip) {
};


/* _d4_0a:AAM ASCII Adjust AX After Multiply */
inline void Handle_AAM(Bit8u last, PhysPt &cseip) {
};


/* _3f:AAS ASCII Adjust AL After Subtraction */
inline void Handle_AAS(Bit8u last, PhysPt &cseip) {
};


/* _10:ADC Add with Carry */
inline void Handle_ADC_Eb_Gb(Bit8u last, PhysPt &cseip) {
};


/* _82:ADC Add with Carry */
inline void Handle_ADC_Eb_Ib(Bit8u last, PhysPt &cseip) {
};


/* _11:ADC Add with Carry */
inline void Handle_ADC_Evqp_Gvqp(Bit8u last, PhysPt &cseip) {
};


/* _83:ADC Add with Carry */
inline void Handle_ADC_Evqp_Ibs(Bit8u last, PhysPt &cseip) {
};


/* _81:ADC Add with Carry */
inline void Handle_ADC_Evqp_Ivds(Bit8u last, PhysPt &cseip) {
};


/* _12:ADC Add with Carry */
inline void Handle_ADC_Gb_Eb(Bit8u last, PhysPt &cseip) {
};


/* _13:ADC Add with Carry */
inline void Handle_ADC_Gvqp_Evqp(Bit8u last, PhysPt &cseip) {
};


/* _14:ADC Add with Carry */
inline void Handle_ADC_acc_AL_Ib(Bit8u last, PhysPt &cseip) {
};


/* _15:ADC Add with Carry */
inline void Handle_ADC_acc_eAX_Ivds(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_58:ADDPD Add Packed Double-FP Values */
inline void Handle_ADDPD_Vpd_Wpd(Bit8u last, PhysPt &cseip) {
};


/* _0f_58:ADDPS Add Packed Single-FP Values */
inline void Handle_ADDPS_Vps_Wps(Bit8u last, PhysPt &cseip) {
};


/* _f2_0f_58:ADDSD Add Scalar Double-FP Values */
inline void Handle_ADDSD_Vsd_Wsd(Bit8u last, PhysPt &cseip) {
};


/* _f3_0f_58:ADDSS Add Scalar Single-FP Values */
inline void Handle_ADDSS_Vss_Wss(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_d0:ADDSUBPD Packed Double-FP Add/Subtract */
inline void Handle_ADDSUBPD_Vpd_Wpd(Bit8u last, PhysPt &cseip) {
};


/* _f2_0f_d0:ADDSUBPS Packed Single-FP Add/Subtract */
inline void Handle_ADDSUBPS_Vps_Wps(Bit8u last, PhysPt &cseip) {
};


/* _00:ADD Add */
inline void Handle_ADD_Eb_Gb(Bit8u last, PhysPt &cseip) {
};


/* _82:ADD Add */
inline void Handle_ADD_Eb_Ib(Bit8u last, PhysPt &cseip) {
};


/* _01:ADD Add */
inline void Handle_ADD_Evqp_Gvqp(Bit8u last, PhysPt &cseip) {
};


/* _83:ADD Add */
inline void Handle_ADD_Evqp_Ibs(Bit8u last, PhysPt &cseip) {
};


/* _81:ADD Add */
inline void Handle_ADD_Evqp_Ivds(Bit8u last, PhysPt &cseip) {
};


/* _02:ADD Add */
inline void Handle_ADD_Gb_Eb(Bit8u last, PhysPt &cseip) {
};


/* _03:ADD Add */
inline void Handle_ADD_Gvqp_Evqp(Bit8u last, PhysPt &cseip) {
};


/* _04:ADD Add */
inline void Handle_ADD_acc_AL_Ib(Bit8u last, PhysPt &cseip) {
};


/* _05:ADD Add */
inline void Handle_ADD_acc_eAX_Ivds(Bit8u last, PhysPt &cseip) {
};


/* _d5:ADX Adjust AX Before Division */
inline void Handle_ADX_Ib(Bit8u last, PhysPt &cseip) {
};


/* _d4:AMX Adjust AX After Multiply */
inline void Handle_AMX_Ib(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_55:ANDNPD Bitwise Logical AND NOT of Packed Double-FP Values */
inline void Handle_ANDNPD_Vpd_Wpd(Bit8u last, PhysPt &cseip) {
};


/* _0f_55:ANDNPS Bitwise Logical AND NOT of Packed Single-FP Values */
inline void Handle_ANDNPS_Vps_Wps(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_54:ANDPD Bitwise Logical AND of Packed Double-FP Values */
inline void Handle_ANDPD_Vpd_Wpd(Bit8u last, PhysPt &cseip) {
};


/* _0f_54:ANDPS Bitwise Logical AND of Packed Single-FP Values */
inline void Handle_ANDPS_Vps_Wps(Bit8u last, PhysPt &cseip) {
};


/* _20:AND Logical AND */
inline void Handle_AND_Eb_Gb(Bit8u last, PhysPt &cseip) {
};


/* _82:AND Logical AND */
inline void Handle_AND_Eb_Ib(Bit8u last, PhysPt &cseip) {
};


/* _21:AND Logical AND */
inline void Handle_AND_Evqp_Gvqp(Bit8u last, PhysPt &cseip) {
};


/* _83:AND Logical AND */
inline void Handle_AND_Evqp_Ibs(Bit8u last, PhysPt &cseip) {
};


/* _81:AND Logical AND */
inline void Handle_AND_Evqp_Ivds(Bit8u last, PhysPt &cseip) {
};


/* _22:AND Logical AND */
inline void Handle_AND_Gb_Eb(Bit8u last, PhysPt &cseip) {
};


/* _23:AND Logical AND */
inline void Handle_AND_Gvqp_Evqp(Bit8u last, PhysPt &cseip) {
};


/* _24:AND Logical AND */
inline void Handle_AND_acc_AL_Ib(Bit8u last, PhysPt &cseip) {
};


/* _25:AND Logical AND */
inline void Handle_AND_acc_eAX_Ivds(Bit8u last, PhysPt &cseip) {
};


/* _63:ARPL Adjust RPL Field of Segment Selector */
inline void Handle_ARPL_Ew_Gw(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_3a_0d:BLENDPD Blend Packed Double-FP Values */
inline void Handle_BLENDPD_Vpd_Wpd_Ib(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_3a_0c:BLENDPS Blend Packed Single-FP Values */
inline void Handle_BLENDPS_Vps_Wps_Ib(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_38_15:BLENDVPD Variable Blend Packed Double-FP Values */
inline void Handle_BLENDVPD_Vpd_Wpd(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_38_14:BLENDVPS Variable Blend Packed Single-FP Values */
inline void Handle_BLENDVPS_Vps_Wps(Bit8u last, PhysPt &cseip) {
};


/* _62:BOUND Check Array Index Against Bounds */
inline void Handle_BOUND_Gv_Ma(Bit8u last, PhysPt &cseip) {
};


/* _0f_bc:BSF Bit Scan Forward */
inline void Handle_BSF_Gvqp_Evqp(Bit8u last, PhysPt &cseip) {
};


/* _0f_bd:BSR Bit Scan Reverse */
inline void Handle_BSR_Gvqp_Evqp(Bit8u last, PhysPt &cseip) {
};


/* _0f_c8:BSWAP Byte Swap */
inline void Handle_BSWAP_eAX(Bit8u last, PhysPt &cseip) {
};


/* _0f_cd:BSWAP Byte Swap */
inline void Handle_BSWAP_eBP(Bit8u last, PhysPt &cseip) {
};


/* _0f_cb:BSWAP Byte Swap */
inline void Handle_BSWAP_eBX(Bit8u last, PhysPt &cseip) {
};


/* _0f_c9:BSWAP Byte Swap */
inline void Handle_BSWAP_eCX(Bit8u last, PhysPt &cseip) {
};


/* _0f_cf:BSWAP Byte Swap */
inline void Handle_BSWAP_eDI(Bit8u last, PhysPt &cseip) {
};


/* _0f_ca:BSWAP Byte Swap */
inline void Handle_BSWAP_eDX(Bit8u last, PhysPt &cseip) {
};


/* _0f_ce:BSWAP Byte Swap */
inline void Handle_BSWAP_eSI(Bit8u last, PhysPt &cseip) {
};


/* _0f_cc:BSWAP Byte Swap */
inline void Handle_BSWAP_eSP(Bit8u last, PhysPt &cseip) {
};


/* _0f_bb:BTC Bit Test and Complement */
inline void Handle_BTC_Evqp_Gvqp(Bit8u last, PhysPt &cseip) {
};


/* _0f_ba:BTC Bit Test and Complement */
inline void Handle_BTC_Evqp_Ib(Bit8u last, PhysPt &cseip) {
};


/* _0f_b3:BTR Bit Test and Reset */
inline void Handle_BTR_Evqp_Gvqp(Bit8u last, PhysPt &cseip) {
};


/* _0f_ba:BTR Bit Test and Reset */
inline void Handle_BTR_Evqp_Ib(Bit8u last, PhysPt &cseip) {
};


/* _0f_ab:BTS Bit Test and Set */
inline void Handle_BTS_Evqp_Gvqp(Bit8u last, PhysPt &cseip) {
};


/* _0f_ba:BTS Bit Test and Set */
inline void Handle_BTS_Evqp_Ib(Bit8u last, PhysPt &cseip) {
};


/* _0f_a3:BT Bit Test */
inline void Handle_BT_Evqp_Gvqp(Bit8u last, PhysPt &cseip) {
};


/* _0f_ba:BT Bit Test */
inline void Handle_BT_Evqp_Ib(Bit8u last, PhysPt &cseip) {
};


/* _9a:CALLF Call Procedure */
inline void Handle_CALLF_Ap(Bit8u last, PhysPt &cseip) {
};


/* _ff:CALLF Call Procedure */
inline void Handle_CALLF_Mptp(Bit8u last, PhysPt &cseip) {
};


/* _ff:CALL Call Procedure */
inline void Handle_CALL_Ev(Bit8u last, PhysPt &cseip) {
};


/* _e8:CALL Call Procedure */
inline void Handle_CALL_Jvds(Bit8u last, PhysPt &cseip) {
};


/* _98:CBW Convert Byte to Word */
inline void Handle_CBW(Bit8u last, PhysPt &cseip) {
};


/* _99:CDQ Convert Doubleword to Quadword */
inline void Handle_CDQ(Bit8u last, PhysPt &cseip) {
};


/* _f8:CLC Clear Carry Flag */
inline void Handle_CLC(Bit8u last, PhysPt &cseip) {
};


/* _fc:CLD Clear Direction Flag */
inline void Handle_CLD(Bit8u last, PhysPt &cseip) {
};


/* _0f_ae:CLFLUSH Flush Cache Line */
inline void Handle_CLFLUSH_Mb(Bit8u last, PhysPt &cseip) {
};


/* _fa:CLI Clear Interrupt Flag */
inline void Handle_CLI(Bit8u last, PhysPt &cseip) {
};


/* _0f_06:CLTS Clear Task-Switched Flag in CR0 */
inline void Handle_CLTS(Bit8u last, PhysPt &cseip) {
};


/* _f5:CMC Complement Carry Flag */
inline void Handle_CMC(Bit8u last, PhysPt &cseip) {
};


/* _0f_46:CMOVBE Conditional Move - below or equal/not above (CF=1 AND ZF=1) */
inline void Handle_CMOVBE_Gvqp_Evqp(Bit8u last, PhysPt &cseip) {
};


/* _0f_42:CMOVB Conditional Move - below/not above or equal/carry (CF=1) */
inline void Handle_CMOVB_Gvqp_Evqp(Bit8u last, PhysPt &cseip) {
};


/* _0f_4e:CMOVLE Conditional Move - less or equal/not greater ((ZF=1) OR (SF!=OF)) */
inline void Handle_CMOVLE_Gvqp_Evqp(Bit8u last, PhysPt &cseip) {
};


/* _0f_4c:CMOVL Conditional Move - less/not greater (SF!=OF) */
inline void Handle_CMOVL_Gvqp_Evqp(Bit8u last, PhysPt &cseip) {
};


/* _0f_47:CMOVNBE Conditional Move - not below or equal/above (CF=0 AND ZF=0) */
inline void Handle_CMOVNBE_Gvqp_Evqp(Bit8u last, PhysPt &cseip) {
};


/* _0f_43:CMOVNB Conditional Move - not below/above or equal/not carry (CF=0) */
inline void Handle_CMOVNB_Gvqp_Evqp(Bit8u last, PhysPt &cseip) {
};


/* _0f_4f:CMOVNLE Conditional Move - not less nor equal/greater ((ZF=0) AND (SF=OF)) */
inline void Handle_CMOVNLE_Gvqp_Evqp(Bit8u last, PhysPt &cseip) {
};


/* _0f_4d:CMOVNL Conditional Move - not less/greater or equal (SF=OF) */
inline void Handle_CMOVNL_Gvqp_Evqp(Bit8u last, PhysPt &cseip) {
};


/* _0f_41:CMOVNO Conditional Move - not overflow (OF=0) */
inline void Handle_CMOVNO_Gvqp_Evqp(Bit8u last, PhysPt &cseip) {
};


/* _0f_4b:CMOVNP Conditional Move - not parity/parity odd */
inline void Handle_CMOVNP_Gvqp_Evqp(Bit8u last, PhysPt &cseip) {
};


/* _0f_49:CMOVNS Conditional Move - not sign (SF=0) */
inline void Handle_CMOVNS_Gvqp_Evqp(Bit8u last, PhysPt &cseip) {
};


/* _0f_45:CMOVNZ Conditional Move - not zero/not equal (ZF=1) */
inline void Handle_CMOVNZ_Gvqp_Evqp(Bit8u last, PhysPt &cseip) {
};


/* _0f_40:CMOVO Conditional Move - overflow (OF=1) */
inline void Handle_CMOVO_Gvqp_Evqp(Bit8u last, PhysPt &cseip) {
};


/* _0f_4a:CMOVP Conditional Move - parity/parity even (PF=1) */
inline void Handle_CMOVP_Gvqp_Evqp(Bit8u last, PhysPt &cseip) {
};


/* _0f_48:CMOVS Conditional Move - sign (SF=1) */
inline void Handle_CMOVS_Gvqp_Evqp(Bit8u last, PhysPt &cseip) {
};


/* _0f_44:CMOVZ Conditional Move - zero/equal (ZF=0) */
inline void Handle_CMOVZ_Gvqp_Evqp(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_c2:CMPPD Compare Packed Double-FP Values */
inline void Handle_CMPPD_Vpd_Wpd_Ib(Bit8u last, PhysPt &cseip) {
};


/* _0f_c2:CMPPS Compare Packed Single-FP Values */
inline void Handle_CMPPS_Vps_Wps_Ib(Bit8u last, PhysPt &cseip) {
};


/* _f2_0f_c2:CMPSD Compare Scalar Double-FP Values */
inline void Handle_CMPSD_Vsd_Wsd_Ib(Bit8u last, PhysPt &cseip) {
};


/* _f3_0f_c2:CMPSS Compare Scalar Single-FP Values */
inline void Handle_CMPSS_Vss_Wss_Ib(Bit8u last, PhysPt &cseip) {
};


/* _a6:CMPS Compare String Operands */
inline void Handle_CMPS_Yb_Xb(Bit8u last, PhysPt &cseip) {
};


/* _a7:CMPS Compare String Operands */
inline void Handle_CMPS_Yv_Xv(Bit8u last, PhysPt &cseip) {
};


/* _a7:CMPS Compare String Operands */
inline void Handle_CMPS_Yw_Xw(Bit8u last, PhysPt &cseip) {
};


/* _0f_c7:CMPXCHG8B Compare and Exchange Bytes */
inline void Handle_CMPXCHG8B_Mq(Bit8u last, PhysPt &cseip) {
};


/* _0f_b0:CMPXCHG Compare and Exchange */
inline void Handle_CMPXCHG_Eb_Gb(Bit8u last, PhysPt &cseip) {
};


/* _0f_b1:CMPXCHG Compare and Exchange */
inline void Handle_CMPXCHG_Evqp_Gvqp(Bit8u last, PhysPt &cseip) {
};


/* _38:CMP Compare Two Operands */
inline void Handle_CMP_Eb_Gb(Bit8u last, PhysPt &cseip) {
};


/* _82:CMP Compare Two Operands */
inline void Handle_CMP_Eb_Ib(Bit8u last, PhysPt &cseip) {
};


/* _39:CMP Compare Two Operands */
inline void Handle_CMP_Evqp_Gvqp(Bit8u last, PhysPt &cseip) {
};


/* _83:CMP Compare Two Operands */
inline void Handle_CMP_Evqp_Ibs(Bit8u last, PhysPt &cseip) {
};


/* _81:CMP Compare Two Operands */
inline void Handle_CMP_Evqp_Ivds(Bit8u last, PhysPt &cseip) {
};


/* _3a:CMP Compare Two Operands */
inline void Handle_CMP_Gb_Eb(Bit8u last, PhysPt &cseip) {
};


/* _3b:CMP Compare Two Operands */
inline void Handle_CMP_Gvqp_Evqp(Bit8u last, PhysPt &cseip) {
};


/* _3c:CMP Compare Two Operands */
inline void Handle_CMP_acc_AL_Ib(Bit8u last, PhysPt &cseip) {
};


/* _3d:CMP Compare Two Operands */
inline void Handle_CMP_acc_eAX_Ivds(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_2f:COMISD Compare Scalar Ordered Double-FP Values and Set EFLAGS */
inline void Handle_COMISD_Vsd_Wsd(Bit8u last, PhysPt &cseip) {
};


/* _0f_2f:COMISS Compare Scalar Ordered Single-FP Values and Set EFLAGS */
inline void Handle_COMISS_Vss_Wss(Bit8u last, PhysPt &cseip) {
};


/* _0f_a2:CPUID CPU Identification */
inline void Handle_CPUID_serial(Bit8u last, PhysPt &cseip) {
};


/* _f2_0f_38_f0:CRC32 Accumulate CRC32 Value */
inline void Handle_CRC32_Gdqp_Eb(Bit8u last, PhysPt &cseip) {
};


/* _f2_0f_38_f1:CRC32 Accumulate CRC32 Value */
inline void Handle_CRC32_Gdqp_Evqp(Bit8u last, PhysPt &cseip) {
};


/* _f3_0f_e6:CVTDQ2PD 
            Convert Packed DW Integers to  */
inline void Handle_CVTDQ2PD_Vpd_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _0f_5b:CVTDQ2PS 
            Convert Packed DW Integers to  */
inline void Handle_CVTDQ2PS_Vps_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _f2_0f_e6:CVTPD2DQ 
            Convert Packed Double-FP Values to  */
inline void Handle_CVTPD2DQ_Vdq_Wpd(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_2d:CVTPD2PI 
            Convert Packed Double-FP Values to  */
inline void Handle_CVTPD2PI_Ppi_Wpd(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_5a:CVTPD2PS 
            Convert Packed Double-FP Values to  */
inline void Handle_CVTPD2PS_Vps_Wpd(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_2a:CVTPI2PD 
            Convert Packed DW Integers to  */
inline void Handle_CVTPI2PD_Vpd_Qpi(Bit8u last, PhysPt &cseip) {
};


/* _0f_2a:CVTPI2PS 
            Convert Packed DW Integers to  */
inline void Handle_CVTPI2PS_Vps_Qpi(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_5b:CVTPS2DQ 
            Convert Packed Single-FP Values to  */
inline void Handle_CVTPS2DQ_Vdq_Wps(Bit8u last, PhysPt &cseip) {
};


/* _0f_5a:CVTPS2PD 
            Convert Packed Single-FP Values to  */
inline void Handle_CVTPS2PD_Vpd_Wps(Bit8u last, PhysPt &cseip) {
};


/* _0f_2d:CVTPS2PI 
            Convert Packed Single-FP Values to  */
inline void Handle_CVTPS2PI_Ppi_Wpsq(Bit8u last, PhysPt &cseip) {
};


/* _f2_0f_2d:CVTSD2SI Convert Scalar Double-FP Value to DW Integer */
inline void Handle_CVTSD2SI_Gdqp_Wsd(Bit8u last, PhysPt &cseip) {
};


/* _f2_0f_5a:CVTSD2SS Convert Scalar Double-FP Value to Scalar Single-FP Value */
inline void Handle_CVTSD2SS_Vss_Wsd(Bit8u last, PhysPt &cseip) {
};


/* _f2_0f_2a:CVTSI2SD Convert DW Integer to Scalar Double-FP Value */
inline void Handle_CVTSI2SD_Vsd_Edqp(Bit8u last, PhysPt &cseip) {
};


/* _f3_0f_2a:CVTSI2SS Convert DW Integer to Scalar Single-FP Value */
inline void Handle_CVTSI2SS_Vss_Edqp(Bit8u last, PhysPt &cseip) {
};


/* _f3_0f_5a:CVTSS2SD Convert Scalar Single-FP Value to Scalar Double-FP Value  */
inline void Handle_CVTSS2SD_Vsd_Wss(Bit8u last, PhysPt &cseip) {
};


/* _f3_0f_2d:CVTSS2SI Convert Scalar Single-FP Value to DW Integer */
inline void Handle_CVTSS2SI_Gdqp_Wss(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_e6:CVTTPD2DQ 
            Convert with Trunc. Packed Double-FP Values to  */
inline void Handle_CVTTPD2DQ_Vdq_Wpd(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_2c:CVTTPD2PI 
            Convert with Trunc. Packed Double-FP Values to  */
inline void Handle_CVTTPD2PI_Ppi_Wpd(Bit8u last, PhysPt &cseip) {
};


/* _f3_0f_5b:CVTTPS2DQ 
            Convert with Trunc. Packed Single-FP Values to  */
inline void Handle_CVTTPS2DQ_Vdq_Wps(Bit8u last, PhysPt &cseip) {
};


/* _0f_2c:CVTTPS2PI 
            Convert with Trunc. Packed Single-FP Values to  */
inline void Handle_CVTTPS2PI_Ppi_Wpsq(Bit8u last, PhysPt &cseip) {
};


/* _f2_0f_2c:CVTTSD2SI Conv. with Trunc. Scalar Double-FP Value to Signed DW Int */
inline void Handle_CVTTSD2SI_Gdqp_Wsd(Bit8u last, PhysPt &cseip) {
};


/* _f3_0f_2c:CVTTSS2SI Convert with Trunc. Scalar Single-FP Value to DW Integer */
inline void Handle_CVTTSS2SI_Gdqp_Wss(Bit8u last, PhysPt &cseip) {
};


/* _99:CWD Convert Word to Doubleword */
inline void Handle_CWD(Bit8u last, PhysPt &cseip) {
};


/* _98:CWDE Convert Word to Doubleword */
inline void Handle_CWDE(Bit8u last, PhysPt &cseip) {
};


/* _27:DAA Decimal Adjust AL after Addition */
inline void Handle_DAA(Bit8u last, PhysPt &cseip) {
};


/* _2f:DAS Decimal Adjust AL after Subtraction */
inline void Handle_DAS(Bit8u last, PhysPt &cseip) {
};


/* _fe:DEC Decrement by 1 */
inline void Handle_DEC_Eb(Bit8u last, PhysPt &cseip) {
};


/* _ff:DEC Decrement by 1 */
inline void Handle_DEC_Evqp(Bit8u last, PhysPt &cseip) {
};


/* _48:DEC Decrement by 1 */
inline void Handle_DEC_eAX(Bit8u last, PhysPt &cseip) {
};


/* _4d:DEC Decrement by 1 */
inline void Handle_DEC_eBP(Bit8u last, PhysPt &cseip) {
};


/* _4b:DEC Decrement by 1 */
inline void Handle_DEC_eBX(Bit8u last, PhysPt &cseip) {
};


/* _49:DEC Decrement by 1 */
inline void Handle_DEC_eCX(Bit8u last, PhysPt &cseip) {
};


/* _4f:DEC Decrement by 1 */
inline void Handle_DEC_eDI(Bit8u last, PhysPt &cseip) {
};


/* _4a:DEC Decrement by 1 */
inline void Handle_DEC_eDX(Bit8u last, PhysPt &cseip) {
};


/* _4e:DEC Decrement by 1 */
inline void Handle_DEC_eSI(Bit8u last, PhysPt &cseip) {
};


/* _4c:DEC Decrement by 1 */
inline void Handle_DEC_eSP(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_5e:DIVPD Divide Packed Double-FP Values */
inline void Handle_DIVPD_Vpd_Wpd(Bit8u last, PhysPt &cseip) {
};


/* _0f_5e:DIVPS Divide Packed Single-FP Values */
inline void Handle_DIVPS_Vps_Wps(Bit8u last, PhysPt &cseip) {
};


/* _f2_0f_5e:DIVSD Divide Scalar Double-FP Values */
inline void Handle_DIVSD_Vsd_Wsd(Bit8u last, PhysPt &cseip) {
};


/* _f3_0f_5e:DIVSS Divide Scalar Single-FP Values */
inline void Handle_DIVSS_Vss_Wss(Bit8u last, PhysPt &cseip) {
};


/* _f6:DIV Unsigned Divide */
inline void Handle_DIV_Eb(Bit8u last, PhysPt &cseip) {
};


/* _f7:DIV Unsigned Divide */
inline void Handle_DIV_Evqp(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_3a_41:DPPD Dot Product of Packed Double-FP Values */
inline void Handle_DPPD_Vpd_Wpd(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_3a_40:DPPS Dot Product of Packed Single-FP Values */
inline void Handle_DPPS_Vps_Wps(Bit8u last, PhysPt &cseip) {
};


/* _0f_77:EMMS Empty MMX Technology State */
inline void Handle_EMMS(Bit8u last, PhysPt &cseip) {
};


/* _c8:ENTER Make Stack Frame for Procedure Parameters */
inline void Handle_ENTER_Iw_Ib(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_3a_17:EXTRACTPS Extract Packed Single-FP Value */
inline void Handle_EXTRACTPS_Ed_Vdq_Ib(Bit8u last, PhysPt &cseip) {
};


/* _9b:FWAIT Check pending unmasked floating-point exceptions */
inline void Handle_FWAIT(Bit8u last, PhysPt &cseip) {
};


/* _0f_ae:FXRSTOR Restore x87 FPU, MMX, XMM, and MXCSR State */
inline void Handle_FXRSTOR_Mstx(Bit8u last, PhysPt &cseip) {
};


/* _0f_ae:FXSAVE Save x87 FPU, MMX, XMM, and MXCSR State */
inline void Handle_FXSAVE_Mstx(Bit8u last, PhysPt &cseip) {
};


/* _0f_37:GETSEC GETSEC Leaf Functions */
inline void Handle_GETSEC(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_7c:HADDPD Packed Double-FP Horizontal Add */
inline void Handle_HADDPD_Vpd_Wpd(Bit8u last, PhysPt &cseip) {
};


/* _f2_0f_7c:HADDPS Packed Single-FP Horizontal Add */
inline void Handle_HADDPS_Vps_Wps(Bit8u last, PhysPt &cseip) {
};


/* _f4:HLT Halt */
inline void Handle_HLT(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_7d:HSUBPD Packed Double-FP Horizontal Subtract */
inline void Handle_HSUBPD_Vpd_Wpd(Bit8u last, PhysPt &cseip) {
};


/* _f2_0f_7d:HSUBPS Packed Single-FP Horizontal Subtract */
inline void Handle_HSUBPS_Vps_Wps(Bit8u last, PhysPt &cseip) {
};


/* _f6:IDIV Signed Divide */
inline void Handle_IDIV_Eb(Bit8u last, PhysPt &cseip) {
};


/* _f7:IDIV Signed Divide */
inline void Handle_IDIV_Evqp(Bit8u last, PhysPt &cseip) {
};


/* _f6:IMUL Signed Multiply */
inline void Handle_IMUL_Eb(Bit8u last, PhysPt &cseip) {
};


/* _f7:IMUL Signed Multiply */
inline void Handle_IMUL_Evqp(Bit8u last, PhysPt &cseip) {
};


/* _0f_af:IMUL Signed Multiply */
inline void Handle_IMUL_Gvqp_Evqp(Bit8u last, PhysPt &cseip) {
};


/* _6b:IMUL Signed Multiply */
inline void Handle_IMUL_Gvqp_Evqp_Ibs(Bit8u last, PhysPt &cseip) {
};


/* _69:IMUL Signed Multiply */
inline void Handle_IMUL_Gvqp_Evqp_Ivds(Bit8u last, PhysPt &cseip) {
};


/* _fe:INC Increment by 1 */
inline void Handle_INC_Eb(Bit8u last, PhysPt &cseip) {
};


/* _ff:INC Increment by 1 */
inline void Handle_INC_Evqp(Bit8u last, PhysPt &cseip) {
};


/* _40:INC Increment by 1 */
inline void Handle_INC_eAX(Bit8u last, PhysPt &cseip) {
};


/* _45:INC Increment by 1 */
inline void Handle_INC_eBP(Bit8u last, PhysPt &cseip) {
};


/* _43:INC Increment by 1 */
inline void Handle_INC_eBX(Bit8u last, PhysPt &cseip) {
};


/* _41:INC Increment by 1 */
inline void Handle_INC_eCX(Bit8u last, PhysPt &cseip) {
};


/* _47:INC Increment by 1 */
inline void Handle_INC_eDI(Bit8u last, PhysPt &cseip) {
};


/* _42:INC Increment by 1 */
inline void Handle_INC_eDX(Bit8u last, PhysPt &cseip) {
};


/* _46:INC Increment by 1 */
inline void Handle_INC_eSI(Bit8u last, PhysPt &cseip) {
};


/* _44:INC Increment by 1 */
inline void Handle_INC_eSP(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_3a_21:INSERTPS Insert Packed Single-FP Value */
inline void Handle_INSERTPS_Vps_Ups_Ib(Bit8u last, PhysPt &cseip) {
};


/* _6c:INS Input from Port to String */
inline void Handle_INS_Yb_DX(Bit8u last, PhysPt &cseip) {
};


/* _6d:INS Input from Port to String */
inline void Handle_INS_Yv_DX(Bit8u last, PhysPt &cseip) {
};


/* _6d:INS Input from Port to String */
inline void Handle_INS_Yw_DX(Bit8u last, PhysPt &cseip) {
};


/* _ce:INTO Call to Interrupt Procedure */
inline void Handle_INTO(Bit8u last, PhysPt &cseip) {
};


/* _cc:INT Call to Interrupt Procedure */
inline void Handle_INT_I(Bit8u last, PhysPt &cseip) {
};


/* _cd:INT Call to Interrupt Procedure */
inline void Handle_INT_Ib(Bit8u last, PhysPt &cseip) {
};


/* _0f_08:INVD Invalidate Internal Caches */
inline void Handle_INVD_serial(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_38_80:INVEPT Invalidate Translations Derived from EPT */
inline void Handle_INVEPT_Gd_Mdq(Bit8u last, PhysPt &cseip) {
};


/* _0f_01:INVLPG Invalidate TLB Entry */
inline void Handle_INVLPG_serial_M(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_38_81:INVVPID Invalidate Translations Based on VPID */
inline void Handle_INVVPID_Gd_Mdq(Bit8u last, PhysPt &cseip) {
};


/* _ec:IN Input from Port */
inline void Handle_IN_AL_DX(Bit8u last, PhysPt &cseip) {
};


/* _e4:IN Input from Port */
inline void Handle_IN_AL_Ib(Bit8u last, PhysPt &cseip) {
};


/* _ed:IN Input from Port */
inline void Handle_IN_eAX_DX(Bit8u last, PhysPt &cseip) {
};


/* _e5:IN Input from Port */
inline void Handle_IN_eAX_Ib(Bit8u last, PhysPt &cseip) {
};


/* _cf:IRET Interrupt Return */
inline void Handle_IRET(Bit8u last, PhysPt &cseip) {
};


/* _cf:IRETD Interrupt Return */
inline void Handle_IRETD(Bit8u last, PhysPt &cseip) {
};


/* _76:JBE Jump short if below or equal/not above (CF=1 AND ZF=1) */
inline void Handle_JBE_Jbs(Bit8u last, PhysPt &cseip) {
};


/* _0f_86:JBE Jump short if below or equal/not above (CF=1 AND ZF=1) */
inline void Handle_JBE_Jvds(Bit8u last, PhysPt &cseip) {
};


/* _72:JB Jump short if below/not above or equal/carry (CF=1) */
inline void Handle_JB_Jbs(Bit8u last, PhysPt &cseip) {
};


/* _0f_82:JB Jump short if below/not above or equal/carry (CF=1) */
inline void Handle_JB_Jvds(Bit8u last, PhysPt &cseip) {
};


/* _e3:JCXZ Jump short if eCX register is 0 */
inline void Handle_JCXZ_Jbs(Bit8u last, PhysPt &cseip) {
};


/* _7e:JLE Jump short if less or equal/not greater ((ZF=1) OR (SF!=OF)) */
inline void Handle_JLE_Jbs(Bit8u last, PhysPt &cseip) {
};


/* _0f_8e:JLE Jump short if less or equal/not greater ((ZF=1) OR (SF!=OF)) */
inline void Handle_JLE_Jvds(Bit8u last, PhysPt &cseip) {
};


/* _7c:JL Jump short if less/not greater (SF!=OF) */
inline void Handle_JL_Jbs(Bit8u last, PhysPt &cseip) {
};


/* _0f_8c:JL Jump short if less/not greater (SF!=OF) */
inline void Handle_JL_Jvds(Bit8u last, PhysPt &cseip) {
};


/* _ea:JMPF Jump */
inline void Handle_JMPF_Ap(Bit8u last, PhysPt &cseip) {
};


/* _ff:JMPF Jump */
inline void Handle_JMPF_Mptp(Bit8u last, PhysPt &cseip) {
};


/* _ff:JMP Jump */
inline void Handle_JMP_Ev(Bit8u last, PhysPt &cseip) {
};


/* _eb:JMP Jump */
inline void Handle_JMP_Jbs(Bit8u last, PhysPt &cseip) {
};


/* _e9:JMP Jump */
inline void Handle_JMP_Jvds(Bit8u last, PhysPt &cseip) {
};


/* _77:JNBE Jump short if not below or equal/above (CF=0 AND ZF=0) */
inline void Handle_JNBE_Jbs(Bit8u last, PhysPt &cseip) {
};


/* _0f_87:JNBE Jump short if not below or equal/above (CF=0 AND ZF=0) */
inline void Handle_JNBE_Jvds(Bit8u last, PhysPt &cseip) {
};


/* _73:JNB Jump short if not below/above or equal/not carry (CF=0) */
inline void Handle_JNB_Jbs(Bit8u last, PhysPt &cseip) {
};


/* _0f_83:JNB Jump short if not below/above or equal/not carry (CF=0) */
inline void Handle_JNB_Jvds(Bit8u last, PhysPt &cseip) {
};


/* _7f:JNLE Jump short if not less nor equal/greater ((ZF=0) AND (SF=OF)) */
inline void Handle_JNLE_Jbs(Bit8u last, PhysPt &cseip) {
};


/* _0f_8f:JNLE Jump short if not less nor equal/greater ((ZF=0) AND (SF=OF)) */
inline void Handle_JNLE_Jvds(Bit8u last, PhysPt &cseip) {
};


/* _7d:JNL Jump short if not less/greater or equal (SF=OF) */
inline void Handle_JNL_Jbs(Bit8u last, PhysPt &cseip) {
};


/* _0f_8d:JNL Jump short if not less/greater or equal (SF=OF) */
inline void Handle_JNL_Jvds(Bit8u last, PhysPt &cseip) {
};


/* _71:JNO Jump short if not overflow (OF=0) */
inline void Handle_JNO_Jbs(Bit8u last, PhysPt &cseip) {
};


/* _0f_81:JNO Jump short if not overflow (OF=0) */
inline void Handle_JNO_Jvds(Bit8u last, PhysPt &cseip) {
};


/* _7b:JNP Jump short if not parity/parity odd */
inline void Handle_JNP_Jbs(Bit8u last, PhysPt &cseip) {
};


/* _0f_8b:JNP Jump short if not parity/parity odd */
inline void Handle_JNP_Jvds(Bit8u last, PhysPt &cseip) {
};


/* _79:JNS Jump short if not sign (SF=0) */
inline void Handle_JNS_Jbs(Bit8u last, PhysPt &cseip) {
};


/* _0f_89:JNS Jump short if not sign (SF=0) */
inline void Handle_JNS_Jvds(Bit8u last, PhysPt &cseip) {
};


/* _75:JNZ Jump short if not zero/not equal (ZF=1) */
inline void Handle_JNZ_Jbs(Bit8u last, PhysPt &cseip) {
};


/* _0f_85:JNZ Jump short if not zero/not equal (ZF=1) */
inline void Handle_JNZ_Jvds(Bit8u last, PhysPt &cseip) {
};


/* _70:JO Jump short if overflow (OF=1) */
inline void Handle_JO_Jbs(Bit8u last, PhysPt &cseip) {
};


/* _0f_80:JO Jump short if overflow (OF=1) */
inline void Handle_JO_Jvds(Bit8u last, PhysPt &cseip) {
};


/* _7a:JP Jump short if parity/parity even (PF=1) */
inline void Handle_JP_Jbs(Bit8u last, PhysPt &cseip) {
};


/* _0f_8a:JP Jump short if parity/parity even (PF=1) */
inline void Handle_JP_Jvds(Bit8u last, PhysPt &cseip) {
};


/* _78:JS Jump short if sign (SF=1) */
inline void Handle_JS_Jbs(Bit8u last, PhysPt &cseip) {
};


/* _0f_88:JS Jump short if sign (SF=1) */
inline void Handle_JS_Jvds(Bit8u last, PhysPt &cseip) {
};


/* _74:JZ Jump short if zero/equal (ZF=0) */
inline void Handle_JZ_Jbs(Bit8u last, PhysPt &cseip) {
};


/* _0f_84:JZ Jump short if zero/equal (ZF=0) */
inline void Handle_JZ_Jvds(Bit8u last, PhysPt &cseip) {
};


/* _9f:LAHF Load Status Flags into AH Register */
inline void Handle_LAHF(Bit8u last, PhysPt &cseip) {
};


/* _0f_02:LAR Load Access Rights Byte */
inline void Handle_LAR_Gvqp_Mw(Bit8u last, PhysPt &cseip) {
};


/* _f2_0f_f0:LDDQU Load Unaligned Integer 128 Bits */
inline void Handle_LDDQU_Vdq_Mdq(Bit8u last, PhysPt &cseip) {
};


/* _0f_ae:LDMXCSR Load MXCSR Register */
inline void Handle_LDMXCSR_Md(Bit8u last, PhysPt &cseip) {
};


/* _c5:LDS Load Far Pointer */
inline void Handle_LDS_Gv_Mp(Bit8u last, PhysPt &cseip) {
};


/* _c9:LEAVE High Level Procedure Exit */
inline void Handle_LEAVE(Bit8u last, PhysPt &cseip) {
};


/* _8d:LEA Load Effective Address */
inline void Handle_LEA_Gvqp_M(Bit8u last, PhysPt &cseip) {
};


/* _c4:LES Load Far Pointer */
inline void Handle_LES_Gv_Mp(Bit8u last, PhysPt &cseip) {
};


/* _0f_ae:LFENCE Load Fence */
inline void Handle_LFENCE(Bit8u last, PhysPt &cseip) {
};


/* _0f_b4:LFS Load Far Pointer */
inline void Handle_LFS_Gvqp_Mptp(Bit8u last, PhysPt &cseip) {
};


/* _0f_01:LGDT Load Global Descriptor Table Register */
inline void Handle_LGDT_serial_Ms(Bit8u last, PhysPt &cseip) {
};


/* _0f_b5:LGS Load Far Pointer */
inline void Handle_LGS_Gvqp_Mptp(Bit8u last, PhysPt &cseip) {
};


/* _0f_01:LIDT Load Interrupt Descriptor Table Register */
inline void Handle_LIDT_serial_Ms(Bit8u last, PhysPt &cseip) {
};


/* _0f_00:LLDT Load Local Descriptor Table Register */
inline void Handle_LLDT_serial_Ew(Bit8u last, PhysPt &cseip) {
};


/* _0f_01:LMSW Load Machine Status Word */
inline void Handle_LMSW_serial_Ew(Bit8u last, PhysPt &cseip) {
};


/* _ac:LODS Load String */
inline void Handle_LODS_Xb(Bit8u last, PhysPt &cseip) {
};


/* _ad:LODS Load String */
inline void Handle_LODS_Xv(Bit8u last, PhysPt &cseip) {
};


/* _ad:LODS Load String */
inline void Handle_LODS_Xw(Bit8u last, PhysPt &cseip) {
};


/* _e0:LOOPNZ Decrement count; Jump short if count!=0 and ZF=0 */
inline void Handle_LOOPNZ_Jbs(Bit8u last, PhysPt &cseip) {
};


/* _e1:LOOPZ Decrement count; Jump short if count!=0 and ZF=1 */
inline void Handle_LOOPZ_Jbs(Bit8u last, PhysPt &cseip) {
};


/* _e2:LOOP Decrement count; Jump short if count!=0 */
inline void Handle_LOOP_Jbs(Bit8u last, PhysPt &cseip) {
};


/* _0f_03:LSL Load Segment Limit */
inline void Handle_LSL_Gvqp_Mw(Bit8u last, PhysPt &cseip) {
};


/* _0f_b2:LSS Load Far Pointer */
inline void Handle_LSS_Gvqp_Mptp(Bit8u last, PhysPt &cseip) {
};


/* _0f_00:LTR Load Task Register */
inline void Handle_LTR_serial_Ew(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_f7:MASKMOVDQU Store Selected Bytes of Double Quadword */
inline void Handle_MASKMOVDQU_Vdq_Udq(Bit8u last, PhysPt &cseip) {
};


/* _0f_f7:MASKMOVQ Store Selected Bytes of Quadword */
inline void Handle_MASKMOVQ_Pq_Nq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_5f:MAXPD Return Maximum Packed Double-FP Values */
inline void Handle_MAXPD_Vpd_Wpd(Bit8u last, PhysPt &cseip) {
};


/* _0f_5f:MAXPS Return Maximum Packed Single-FP Values */
inline void Handle_MAXPS_Vps_Wps(Bit8u last, PhysPt &cseip) {
};


/* _f2_0f_5f:MAXSD Return Maximum Scalar Double-FP Value */
inline void Handle_MAXSD_Vsd_Wsd(Bit8u last, PhysPt &cseip) {
};


/* _f3_0f_5f:MAXSS Return Maximum Scalar Single-FP Value */
inline void Handle_MAXSS_Vss_Wss(Bit8u last, PhysPt &cseip) {
};


/* _0f_ae:MFENCE Memory Fence */
inline void Handle_MFENCE(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_5d:MINPD Return Minimum Packed Double-FP Values */
inline void Handle_MINPD_Vpd_Wpd(Bit8u last, PhysPt &cseip) {
};


/* _0f_5d:MINPS Return Minimum Packed Single-FP Values */
inline void Handle_MINPS_Vps_Wps(Bit8u last, PhysPt &cseip) {
};


/* _f2_0f_5d:MINSD Return Minimum Scalar Double-FP Value */
inline void Handle_MINSD_Vsd_Wsd(Bit8u last, PhysPt &cseip) {
};


/* _f3_0f_5d:MINSS Return Minimum Scalar Single-FP Value */
inline void Handle_MINSS_Vss_Wss(Bit8u last, PhysPt &cseip) {
};


/* _0f_01_c8:MONITOR Set Up Monitor Address */
inline void Handle_MONITOR(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_28:MOVAPD Move Aligned Packed Double-FP Values */
inline void Handle_MOVAPD_Vpd_Wpd(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_29:MOVAPD Move Aligned Packed Double-FP Values */
inline void Handle_MOVAPD_Wpd_Vpd(Bit8u last, PhysPt &cseip) {
};


/* _0f_28:MOVAPS Move Aligned Packed Single-FP Values */
inline void Handle_MOVAPS_Vps_Wps(Bit8u last, PhysPt &cseip) {
};


/* _0f_29:MOVAPS Move Aligned Packed Single-FP Values */
inline void Handle_MOVAPS_Wps_Vps(Bit8u last, PhysPt &cseip) {
};


/* _0f_38_f0:MOVBE Move Data After Swapping Bytes */
inline void Handle_MOVBE_Gvqp_Mvqp(Bit8u last, PhysPt &cseip) {
};


/* _0f_38_f1:MOVBE Move Data After Swapping Bytes */
inline void Handle_MOVBE_Mvqp_Gvqp(Bit8u last, PhysPt &cseip) {
};


/* _f2_0f_12:MOVDDUP Move One Double-FP and Duplicate */
inline void Handle_MOVDDUP_Vq_Wq(Bit8u last, PhysPt &cseip) {
};


/* _f2_0f_d6:MOVDQ2Q Move Quadword from XMM to MMX Technology Register */
inline void Handle_MOVDQ2Q_Pq_Uq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_6f:MOVDQA Move Aligned Double Quadword */
inline void Handle_MOVDQA_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_7f:MOVDQA Move Aligned Double Quadword */
inline void Handle_MOVDQA_Wdq_Vdq(Bit8u last, PhysPt &cseip) {
};


/* _f3_0f_6f:MOVDQU Move Unaligned Double Quadword */
inline void Handle_MOVDQU_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _f3_0f_7f:MOVDQU Move Unaligned Double Quadword */
inline void Handle_MOVDQU_Wdq_Vdq(Bit8u last, PhysPt &cseip) {
};


/* _0f_7e:MOVD Move Doubleword */
inline void Handle_MOVD_Ed_Pq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_7e:MOVD Move Doubleword */
inline void Handle_MOVD_Ed_Vdq(Bit8u last, PhysPt &cseip) {
};


/* _0f_6e:MOVD Move Doubleword */
inline void Handle_MOVD_Pq_Ed(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_6e:MOVD Move Doubleword */
inline void Handle_MOVD_Vdq_Ed(Bit8u last, PhysPt &cseip) {
};


/* _0f_12:MOVHLPS Move Packed Single-FP Values High to Low */
inline void Handle_MOVHLPS_Vq_Uq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_17:MOVHPD Move High Packed Double-FP Value */
inline void Handle_MOVHPD_Mq_Vq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_16:MOVHPD Move High Packed Double-FP Value */
inline void Handle_MOVHPD_Vq_Mq(Bit8u last, PhysPt &cseip) {
};


/* _0f_17:MOVHPS Move High Packed Single-FP Values */
inline void Handle_MOVHPS_Mq_Vq(Bit8u last, PhysPt &cseip) {
};


/* _0f_16:MOVHPS Move High Packed Single-FP Values */
inline void Handle_MOVHPS_Vq_Mq(Bit8u last, PhysPt &cseip) {
};


/* _0f_16:MOVLHPS Move Packed Single-FP Values Low to High */
inline void Handle_MOVLHPS_Vq_Uq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_13:MOVLPD Move Low Packed Double-FP Value */
inline void Handle_MOVLPD_Mq_Vq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_12:MOVLPD Move Low Packed Double-FP Value */
inline void Handle_MOVLPD_Vq_Mq(Bit8u last, PhysPt &cseip) {
};


/* _0f_13:MOVLPS Move Low Packed Single-FP Values */
inline void Handle_MOVLPS_Mq_Vq(Bit8u last, PhysPt &cseip) {
};


/* _0f_12:MOVLPS Move Low Packed Single-FP Values */
inline void Handle_MOVLPS_Vq_Mq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_50:MOVMSKPD Extract Packed Double-FP Sign Mask */
inline void Handle_MOVMSKPD_Gdqp_Upd(Bit8u last, PhysPt &cseip) {
};


/* _0f_50:MOVMSKPS Extract Packed Single-FP Sign Mask */
inline void Handle_MOVMSKPS_Gdqp_Ups(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_38_2a:MOVNTDQA Load Double Quadword Non-Temporal Aligned Hint */
inline void Handle_MOVNTDQA_Vdq_Mdq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_e7:MOVNTDQ Store Double Quadword Using Non-Temporal Hint */
inline void Handle_MOVNTDQ_Mdq_Vdq(Bit8u last, PhysPt &cseip) {
};


/* _0f_c3:MOVNTI Store Doubleword Using Non-Temporal Hint */
inline void Handle_MOVNTI_Mdqp_Gdqp(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_2b:MOVNTPD Store Packed Double-FP Values Using Non-Temporal Hint */
inline void Handle_MOVNTPD_Mpd_Vpd(Bit8u last, PhysPt &cseip) {
};


/* _0f_2b:MOVNTPS Store Packed Single-FP Values Using Non-Temporal Hint */
inline void Handle_MOVNTPS_Mps_Vps(Bit8u last, PhysPt &cseip) {
};


/* _0f_e7:MOVNTQ Store of Quadword Using Non-Temporal Hint */
inline void Handle_MOVNTQ_Mq_Pq(Bit8u last, PhysPt &cseip) {
};


/* _f3_0f_d6:MOVQ2DQ Move Quadword from MMX Technology to XMM Register */
inline void Handle_MOVQ2DQ_Vdq_Nq(Bit8u last, PhysPt &cseip) {
};


/* _0f_6f:MOVQ Move Quadword */
inline void Handle_MOVQ_Pq_Qq(Bit8u last, PhysPt &cseip) {
};


/* _0f_7f:MOVQ Move Quadword */
inline void Handle_MOVQ_Qq_Pq(Bit8u last, PhysPt &cseip) {
};


/* _f3_0f_7e:MOVQ Move Quadword */
inline void Handle_MOVQ_Vq_Wq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_d6:MOVQ Move Quadword */
inline void Handle_MOVQ_Wq_Vq(Bit8u last, PhysPt &cseip) {
};


/* _f2_0f_10:MOVSD Move Scalar Double-FP Value */
inline void Handle_MOVSD_Vsd_Wsd(Bit8u last, PhysPt &cseip) {
};


/* _f2_0f_11:MOVSD Move Scalar Double-FP Value */
inline void Handle_MOVSD_Wsd_Vsd(Bit8u last, PhysPt &cseip) {
};


/* _f3_0f_16:MOVSHDUP Move Packed Single-FP High and Duplicate */
inline void Handle_MOVSHDUP_Vq_Wq(Bit8u last, PhysPt &cseip) {
};


/* _f3_0f_12:MOVSLDUP Move Packed Single-FP Low and Duplicate */
inline void Handle_MOVSLDUP_Vq_Wq(Bit8u last, PhysPt &cseip) {
};


/* _f3_0f_10:MOVSS Move Scalar Single-FP Values */
inline void Handle_MOVSS_Vss_Wss(Bit8u last, PhysPt &cseip) {
};


/* _f3_0f_11:MOVSS Move Scalar Single-FP Values */
inline void Handle_MOVSS_Wss_Vss(Bit8u last, PhysPt &cseip) {
};


/* _0f_be:MOVSX Move with Sign-Extension */
inline void Handle_MOVSX_Gvqp_Eb(Bit8u last, PhysPt &cseip) {
};


/* _0f_bf:MOVSX Move with Sign-Extension */
inline void Handle_MOVSX_Gvqp_Ew(Bit8u last, PhysPt &cseip) {
};


/* _a4:MOVS Move Data from String to String */
inline void Handle_MOVS_Yb_Xb(Bit8u last, PhysPt &cseip) {
};


/* _a5:MOVS Move Data from String to String */
inline void Handle_MOVS_Yv_Xv(Bit8u last, PhysPt &cseip) {
};


/* _a5:MOVS Move Data from String to String */
inline void Handle_MOVS_Yw_Xw(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_10:MOVUPD Move Unaligned Packed Double-FP Value */
inline void Handle_MOVUPD_Vpd_Wpd(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_11:MOVUPD Move Unaligned Packed Double-FP Values */
inline void Handle_MOVUPD_Wpd_Vpd(Bit8u last, PhysPt &cseip) {
};


/* _0f_10:MOVUPS Move Unaligned Packed Single-FP Values */
inline void Handle_MOVUPS_Vps_Wps(Bit8u last, PhysPt &cseip) {
};


/* _0f_11:MOVUPS Move Unaligned Packed Single-FP Values */
inline void Handle_MOVUPS_Wps_Vps(Bit8u last, PhysPt &cseip) {
};


/* _0f_b6:MOVZX Move with Zero-Extend */
inline void Handle_MOVZX_Gvqp_Eb(Bit8u last, PhysPt &cseip) {
};


/* _0f_b7:MOVZX Move with Zero-Extend */
inline void Handle_MOVZX_Gvqp_Ew(Bit8u last, PhysPt &cseip) {
};


/* _b4:MOV Move */
inline void Handle_MOV_AH_Ib(Bit8u last, PhysPt &cseip) {
};


/* _b0:MOV Move */
inline void Handle_MOV_AL_Ib(Bit8u last, PhysPt &cseip) {
};


/* _a0:MOV Move */
inline void Handle_MOV_AL_Ob(Bit8u last, PhysPt &cseip) {
};


/* _b7:MOV Move */
inline void Handle_MOV_BH_Ib(Bit8u last, PhysPt &cseip) {
};


/* _b3:MOV Move */
inline void Handle_MOV_BL_Ib(Bit8u last, PhysPt &cseip) {
};


/* _b5:MOV Move */
inline void Handle_MOV_CH_Ib(Bit8u last, PhysPt &cseip) {
};


/* _b1:MOV Move */
inline void Handle_MOV_CL_Ib(Bit8u last, PhysPt &cseip) {
};


/* _b6:MOV Move */
inline void Handle_MOV_DH_Ib(Bit8u last, PhysPt &cseip) {
};


/* _b2:MOV Move */
inline void Handle_MOV_DL_Ib(Bit8u last, PhysPt &cseip) {
};


/* _88:MOV Move */
inline void Handle_MOV_Eb_Gb(Bit8u last, PhysPt &cseip) {
};


/* _c6:MOV Move */
inline void Handle_MOV_Eb_Ib(Bit8u last, PhysPt &cseip) {
};


/* _89:MOV Move */
inline void Handle_MOV_Evqp_Gvqp(Bit8u last, PhysPt &cseip) {
};


/* _c7:MOV Move */
inline void Handle_MOV_Evqp_Ivds(Bit8u last, PhysPt &cseip) {
};


/* _8a:MOV Move */
inline void Handle_MOV_Gb_Eb(Bit8u last, PhysPt &cseip) {
};


/* _8b:MOV Move */
inline void Handle_MOV_Gvqp_Evqp(Bit8u last, PhysPt &cseip) {
};


/* _8c:MOV Move */
inline void Handle_MOV_Mw_Sw(Bit8u last, PhysPt &cseip) {
};


/* _a2:MOV Move */
inline void Handle_MOV_Ob_AL(Bit8u last, PhysPt &cseip) {
};


/* _a3:MOV Move */
inline void Handle_MOV_Ovqp_eAX(Bit8u last, PhysPt &cseip) {
};


/* _8e:MOV Move */
inline void Handle_MOV_Sw_Ew(Bit8u last, PhysPt &cseip) {
};


/* _b8:MOV Move */
inline void Handle_MOV_eAX_Ivqp(Bit8u last, PhysPt &cseip) {
};


/* _a1:MOV Move */
inline void Handle_MOV_eAX_Ovqp(Bit8u last, PhysPt &cseip) {
};


/* _bd:MOV Move */
inline void Handle_MOV_eBP_Ivqp(Bit8u last, PhysPt &cseip) {
};


/* _bb:MOV Move */
inline void Handle_MOV_eBX_Ivqp(Bit8u last, PhysPt &cseip) {
};


/* _b9:MOV Move */
inline void Handle_MOV_eCX_Ivqp(Bit8u last, PhysPt &cseip) {
};


/* _bf:MOV Move */
inline void Handle_MOV_eDI_Ivqp(Bit8u last, PhysPt &cseip) {
};


/* _ba:MOV Move */
inline void Handle_MOV_eDX_Ivqp(Bit8u last, PhysPt &cseip) {
};


/* _be:MOV Move */
inline void Handle_MOV_eSI_Ivqp(Bit8u last, PhysPt &cseip) {
};


/* _bc:MOV Move */
inline void Handle_MOV_eSP_Ivqp(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_3a_42:MPSADBW Compute Multiple Packed Sums of Absolute Difference */
inline void Handle_MPSADBW_Vdq_Wdq_Ib(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_59:MULPD Multiply Packed Double-FP Values */
inline void Handle_MULPD_Vpd_Wpd(Bit8u last, PhysPt &cseip) {
};


/* _0f_59:MULPS Multiply Packed Single-FP Values */
inline void Handle_MULPS_Vps_Wps(Bit8u last, PhysPt &cseip) {
};


/* _f2_0f_59:MULSD Multiply Scalar Double-FP Values */
inline void Handle_MULSD_Vsd_Wsd(Bit8u last, PhysPt &cseip) {
};


/* _f3_0f_59:MULSS Multiply Scalar Single-FP Value */
inline void Handle_MULSS_Vss_Wss(Bit8u last, PhysPt &cseip) {
};


/* _f6:MUL Unsigned Multiply */
inline void Handle_MUL_Eb(Bit8u last, PhysPt &cseip) {
};


/* _f7:MUL Unsigned Multiply */
inline void Handle_MUL_Evqp(Bit8u last, PhysPt &cseip) {
};


/* _0f_01_c9:MWAIT Monitor Wait */
inline void Handle_MWAIT(Bit8u last, PhysPt &cseip) {
};


/* _f6:NEG Two's Complement Negation */
inline void Handle_NEG_Eb(Bit8u last, PhysPt &cseip) {
};


/* _f7:NEG Two's Complement Negation */
inline void Handle_NEG_Evqp(Bit8u last, PhysPt &cseip) {
};


/* _90:NOP No Operation */
inline void Handle_NOP(Bit8u last, PhysPt &cseip) {
};


/* _0f_1f:NOP No Operation */
inline void Handle_NOP_Ev(Bit8u last, PhysPt &cseip) {
};


/* _f3_90:NOP No Operation */
inline void Handle_NOP_nop(Bit8u last, PhysPt &cseip) {
};


/* _f6:NOT One's Complement Negation */
inline void Handle_NOT_Eb(Bit8u last, PhysPt &cseip) {
};


/* _f7:NOT One's Complement Negation */
inline void Handle_NOT_Evqp(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_56:ORPD Bitwise Logical OR of Double-FP Values */
inline void Handle_ORPD_Vpd_Wpd(Bit8u last, PhysPt &cseip) {
};


/* _0f_56:ORPS Bitwise Logical OR of Single-FP Values */
inline void Handle_ORPS_Vps_Wps(Bit8u last, PhysPt &cseip) {
};


/* _08:OR Logical Inclusive OR */
inline void Handle_OR_Eb_Gb(Bit8u last, PhysPt &cseip) {
};


/* _82:OR Logical Inclusive OR */
inline void Handle_OR_Eb_Ib(Bit8u last, PhysPt &cseip) {
};


/* _09:OR Logical Inclusive OR */
inline void Handle_OR_Evqp_Gvqp(Bit8u last, PhysPt &cseip) {
};


/* _83:OR Logical Inclusive OR */
inline void Handle_OR_Evqp_Ibs(Bit8u last, PhysPt &cseip) {
};


/* _81:OR Logical Inclusive OR */
inline void Handle_OR_Evqp_Ivds(Bit8u last, PhysPt &cseip) {
};


/* _0a:OR Logical Inclusive OR */
inline void Handle_OR_Gb_Eb(Bit8u last, PhysPt &cseip) {
};


/* _0b:OR Logical Inclusive OR */
inline void Handle_OR_Gvqp_Evqp(Bit8u last, PhysPt &cseip) {
};


/* _0c:OR Logical Inclusive OR */
inline void Handle_OR_acc_AL_Ib(Bit8u last, PhysPt &cseip) {
};


/* _0d:OR Logical Inclusive OR */
inline void Handle_OR_acc_eAX_Ivds(Bit8u last, PhysPt &cseip) {
};


/* _6e:OUTS Output String to Port */
inline void Handle_OUTS_DX_Xb(Bit8u last, PhysPt &cseip) {
};


/* _6f:OUTS Output String to Port */
inline void Handle_OUTS_DX_Xv(Bit8u last, PhysPt &cseip) {
};


/* _6f:OUTS Output String to Port */
inline void Handle_OUTS_DX_Xw(Bit8u last, PhysPt &cseip) {
};


/* _ee:OUT Output to Port */
inline void Handle_OUT_DX_AL(Bit8u last, PhysPt &cseip) {
};


/* _ef:OUT Output to Port */
inline void Handle_OUT_DX_eAX(Bit8u last, PhysPt &cseip) {
};


/* _e6:OUT Output to Port */
inline void Handle_OUT_Ib_AL(Bit8u last, PhysPt &cseip) {
};


/* _e7:OUT Output to Port */
inline void Handle_OUT_Ib_eAX(Bit8u last, PhysPt &cseip) {
};


/* _0f_38_1c:PABSB Packed Absolute Value */
inline void Handle_PABSB_Pq_Qq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_38_1c:PABSB Packed Absolute Value */
inline void Handle_PABSB_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _0f_38_1e:PABSD Packed Absolute Value */
inline void Handle_PABSD_Pq_Qq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_38_1e:PABSD Packed Absolute Value */
inline void Handle_PABSD_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _0f_38_1d:PABSW Packed Absolute Value */
inline void Handle_PABSW_Pq_Qq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_38_1d:PABSW Packed Absolute Value */
inline void Handle_PABSW_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _0f_6b:PACKSSDW Pack with Signed Saturation */
inline void Handle_PACKSSDW_Pq_Qq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_6b:PACKSSDW Pack with Signed Saturation */
inline void Handle_PACKSSDW_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _0f_63:PACKSSWB Pack with Signed Saturation */
inline void Handle_PACKSSWB_Pq_Qd(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_63:PACKSSWB Pack with Signed Saturation */
inline void Handle_PACKSSWB_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_38_2b:PACKUSDW Pack with Unsigned Saturation */
inline void Handle_PACKUSDW_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _0f_67:PACKUSWB Pack with Unsigned Saturation */
inline void Handle_PACKUSWB_Pq_Qq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_67:PACKUSWB Pack with Unsigned Saturation */
inline void Handle_PACKUSWB_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _0f_fc:PADDB Add Packed Integers */
inline void Handle_PADDB_Pq_Qq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_fc:PADDB Add Packed Integers */
inline void Handle_PADDB_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _0f_fe:PADDD Add Packed Integers */
inline void Handle_PADDD_Pq_Qq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_fe:PADDD Add Packed Integers */
inline void Handle_PADDD_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _0f_d4:PADDQ Add Packed Quadword Integers */
inline void Handle_PADDQ_Pq_Qq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_d4:PADDQ Add Packed Quadword Integers */
inline void Handle_PADDQ_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _0f_ec:PADDSB Add Packed Signed Integers with Signed Saturation */
inline void Handle_PADDSB_Pq_Qq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_ec:PADDSB Add Packed Signed Integers with Signed Saturation */
inline void Handle_PADDSB_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _0f_ed:PADDSW Add Packed Signed Integers with Signed Saturation */
inline void Handle_PADDSW_Pq_Qq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_ed:PADDSW Add Packed Signed Integers with Signed Saturation */
inline void Handle_PADDSW_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _0f_fd:PADDW Add Packed Integers */
inline void Handle_PADDW_Pq_Qq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_fd:PADDW Add Packed Integers */
inline void Handle_PADDW_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _0f_3a_0f:PALIGNR Packed Align Right */
inline void Handle_PALIGNR_Pq_Qq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_3a_0f:PALIGNR Packed Align Right */
inline void Handle_PALIGNR_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _f3_90:PAUSE Spin Loop Hint */
inline void Handle_PAUSE(Bit8u last, PhysPt &cseip) {
};


/* _0f_e0:PAVGB Average Packed Integers */
inline void Handle_PAVGB_Pq_Qq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_e0:PAVGB Average Packed Integers */
inline void Handle_PAVGB_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _0f_e3:PAVGW Average Packed Integers */
inline void Handle_PAVGW_Pq_Qq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_e3:PAVGW Average Packed Integers */
inline void Handle_PAVGW_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_38_10:PBLENDVB Variable Blend Packed Bytes */
inline void Handle_PBLENDVB_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_3a_0e:PBLENDW Blend Packed Words */
inline void Handle_PBLENDW_Vdq_Wdq_Ib(Bit8u last, PhysPt &cseip) {
};


/* _0f_74:PCMPEQB Compare Packed Data for Equal */
inline void Handle_PCMPEQB_Pq_Qq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_74:PCMPEQB Compare Packed Data for Equal */
inline void Handle_PCMPEQB_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _0f_76:PCMPEQD Compare Packed Data for Equal */
inline void Handle_PCMPEQD_Pq_Qq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_76:PCMPEQD Compare Packed Data for Equal */
inline void Handle_PCMPEQD_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_38_29:PCMPEQQ Compare Packed Qword Data for Equal */
inline void Handle_PCMPEQQ_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _0f_75:PCMPEQW Compare Packed Data for Equal */
inline void Handle_PCMPEQW_Pq_Qq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_75:PCMPEQW Compare Packed Data for Equal */
inline void Handle_PCMPEQW_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_3a_61:PCMPESTRI Packed Compare Explicit Length Strings, Return Index */
inline void Handle_PCMPESTRI_Vdq_Wdq_Ib(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_3a_60:PCMPESTRM Packed Compare Explicit Length Strings, Return Mask */
inline void Handle_PCMPESTRM_Vdq_Wdq_Ib(Bit8u last, PhysPt &cseip) {
};


/* _0f_64:PCMPGTB Compare Packed Signed Integers for Greater Than */
inline void Handle_PCMPGTB_Pq_Qd(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_64:PCMPGTB Compare Packed Signed Integers for Greater Than */
inline void Handle_PCMPGTB_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _0f_66:PCMPGTD Compare Packed Signed Integers for Greater Than */
inline void Handle_PCMPGTD_Pq_Qd(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_66:PCMPGTD Compare Packed Signed Integers for Greater Than */
inline void Handle_PCMPGTD_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_38_37:PCMPGTQ Compare Packed Qword Data for Greater Than */
inline void Handle_PCMPGTQ_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _0f_65:PCMPGTW Compare Packed Signed Integers for Greater Than */
inline void Handle_PCMPGTW_Pq_Qd(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_65:PCMPGTW Compare Packed Signed Integers for Greater Than */
inline void Handle_PCMPGTW_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_3a_63:PCMPISTRI Packed Compare Implicit Length Strings, Return Index */
inline void Handle_PCMPISTRI_Vdq_Wdq_Ib(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_3a_62:PCMPISTRM Packed Compare Implicit Length Strings, Return Mask */
inline void Handle_PCMPISTRM_Vdq_Wdq_Ib(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_3a_14:PEXTRB Extract Byte */
inline void Handle_PEXTRB_Mb_Vdq_Ib(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_3a_16:PEXTRD Extract Dword/Qword */
inline void Handle_PEXTRD_Ed_Vdq_Ib(Bit8u last, PhysPt &cseip) {
};


/* _0f_c5:PEXTRW Extract Word */
inline void Handle_PEXTRW_Gdqp_Nq_Ib(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_c5:PEXTRW Extract Word */
inline void Handle_PEXTRW_Gdqp_Udq_Ib(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_3a_15:PEXTRW Extract Word */
inline void Handle_PEXTRW_Mw_Vdq_Ib(Bit8u last, PhysPt &cseip) {
};


/* _0f_38_02:PHADDD Packed Horizontal Add */
inline void Handle_PHADDD_Pq_Qq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_38_02:PHADDD Packed Horizontal Add */
inline void Handle_PHADDD_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _0f_38_03:PHADDSW Packed Horizontal Add and Saturate */
inline void Handle_PHADDSW_Pq_Qq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_38_03:PHADDSW Packed Horizontal Add and Saturate */
inline void Handle_PHADDSW_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _0f_38_01:PHADDW Packed Horizontal Add */
inline void Handle_PHADDW_Pq_Qq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_38_01:PHADDW Packed Horizontal Add */
inline void Handle_PHADDW_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_38_41:PHMINPOSUW Packed Horizontal Word Minimum */
inline void Handle_PHMINPOSUW_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _0f_38_06:PHSUBD Packed Horizontal Subtract */
inline void Handle_PHSUBD_Pq_Qq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_38_06:PHSUBD Packed Horizontal Subtract */
inline void Handle_PHSUBD_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _0f_38_07:PHSUBSW Packed Horizontal Subtract and Saturate */
inline void Handle_PHSUBSW_Pq_Qq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_38_07:PHSUBSW Packed Horizontal Subtract and Saturate */
inline void Handle_PHSUBSW_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _0f_38_05:PHSUBW Packed Horizontal Subtract */
inline void Handle_PHSUBW_Pq_Qq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_38_05:PHSUBW Packed Horizontal Subtract */
inline void Handle_PHSUBW_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_3a_20:PINSRB Insert Byte */
inline void Handle_PINSRB_Vdq_Mb_Ib(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_3a_22:PINSRD Insert Dword/Qword */
inline void Handle_PINSRD_Vdq_Ed_Ib(Bit8u last, PhysPt &cseip) {
};


/* _0f_c4:PINSRW Insert Word */
inline void Handle_PINSRW_Pq_Rdqp_Ib(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_c4:PINSRW Insert Word */
inline void Handle_PINSRW_Vdq_Rdqp_Ib(Bit8u last, PhysPt &cseip) {
};


/* _0f_38_04:PMADDUBSW Multiply and Add Packed Signed and Unsigned Bytes */
inline void Handle_PMADDUBSW_Pq_Qq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_38_04:PMADDUBSW Multiply and Add Packed Signed and Unsigned Bytes */
inline void Handle_PMADDUBSW_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _0f_f5:PMADDWD Multiply and Add Packed Integers */
inline void Handle_PMADDWD_Pq_Qd(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_f5:PMADDWD Multiply and Add Packed Integers */
inline void Handle_PMADDWD_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_38_3c:PMAXSB Maximum of Packed Signed Byte Integers */
inline void Handle_PMAXSB_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_38_3d:PMAXSD Maximum of Packed Signed Dword Integers */
inline void Handle_PMAXSD_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _0f_ee:PMAXSW Maximum of Packed Signed Word Integers */
inline void Handle_PMAXSW_Pq_Qq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_ee:PMAXSW Maximum of Packed Signed Word Integers */
inline void Handle_PMAXSW_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_38_3f:PMAXUD Maximum of Packed Unsigned Dword Integers */
inline void Handle_PMAXUD_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_38_3e:PMAXUW Maximum of Packed Unsigned Word Integers */
inline void Handle_PMAXUW_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_38_38:PMINSB Minimum of Packed Signed Byte Integers */
inline void Handle_PMINSB_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_38_39:PMINSD Minimum of Packed Signed Dword Integers */
inline void Handle_PMINSD_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _0f_ea:PMINSW Minimum of Packed Signed Word Integers */
inline void Handle_PMINSW_Pq_Qq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_ea:PMINSW Minimum of Packed Signed Word Integers */
inline void Handle_PMINSW_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_38_3b:PMINUD Minimum of Packed Unsigned Dword Integers */
inline void Handle_PMINUD_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_38_3a:PMINUW Minimum of Packed Unsigned Word Integers */
inline void Handle_PMINUW_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _0f_d7:PMOVMSKB Move Byte Mask */
inline void Handle_PMOVMSKB_Gdqp_Nq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_d7:PMOVMSKB Move Byte Mask */
inline void Handle_PMOVMSKB_Gdqp_Udq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_38_21:PMOVSXBD Packed Move with Sign Extend */
inline void Handle_PMOVSXBD_Vdq_Md(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_38_22:PMOVSXBQ Packed Move with Sign Extend */
inline void Handle_PMOVSXBQ_Vdq_Mw(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_38_20:PMOVSXBW Packed Move with Sign Extend */
inline void Handle_PMOVSXBW_Vdq_Mq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_38_25:PMOVSXDQ Packed Move with Sign Extend */
inline void Handle_PMOVSXDQ_Vdq_Mq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_38_23:PMOVSXWD Packed Move with Sign Extend */
inline void Handle_PMOVSXWD_Vdq_Mq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_38_24:PMOVSXWQ Packed Move with Sign Extend */
inline void Handle_PMOVSXWQ_Vdq_Md(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_38_31:PMOVZXBD Packed Move with Zero Extend */
inline void Handle_PMOVZXBD_Vdq_Md(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_38_32:PMOVZXBQ Packed Move with Zero Extend */
inline void Handle_PMOVZXBQ_Vdq_Mw(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_38_30:PMOVZXBW Packed Move with Zero Extend */
inline void Handle_PMOVZXBW_Vdq_Mq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_38_35:PMOVZXDQ Packed Move with Zero Extend */
inline void Handle_PMOVZXDQ_Vdq_Mq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_38_33:PMOVZXWD Packed Move with Zero Extend */
inline void Handle_PMOVZXWD_Vdq_Mq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_38_34:PMOVZXWQ Packed Move with Zero Extend */
inline void Handle_PMOVZXWQ_Vdq_Md(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_38_28:PMULDQ Multiply Packed Signed Dword Integers */
inline void Handle_PMULDQ_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _0f_38_0b:PMULHRSW Packed Multiply High with Round and Scale */
inline void Handle_PMULHRSW_Pq_Qq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_38_0b:PMULHRSW Packed Multiply High with Round and Scale */
inline void Handle_PMULHRSW_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _0f_e4:PMULHUW Multiply Packed Unsigned Integers and Store High Result */
inline void Handle_PMULHUW_Pq_Qq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_e4:PMULHUW Multiply Packed Unsigned Integers and Store High Result */
inline void Handle_PMULHUW_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _0f_e5:PMULHW Multiply Packed Signed Integers and Store High Result */
inline void Handle_PMULHW_Pq_Qq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_e5:PMULHW Multiply Packed Signed Integers and Store High Result */
inline void Handle_PMULHW_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_38_40:PMULLD Multiply Packed Signed Dword Integers and Store Low Result */
inline void Handle_PMULLD_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _0f_d5:PMULLW Multiply Packed Signed Integers and Store Low Result */
inline void Handle_PMULLW_Pq_Qq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_d5:PMULLW Multiply Packed Signed Integers and Store Low Result */
inline void Handle_PMULLW_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _0f_f4:PMULUDQ Multiply Packed Unsigned DW Integers */
inline void Handle_PMULUDQ_Pq_Qq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_f4:PMULUDQ Multiply Packed Unsigned DW Integers */
inline void Handle_PMULUDQ_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _61:POPA Pop All General-Purpose Registers */
inline void Handle_POPA(Bit8u last, PhysPt &cseip) {
};


/* _61:POPAD Pop All General-Purpose Registers */
inline void Handle_POPAD(Bit8u last, PhysPt &cseip) {
};


/* _f3_0f_b8:POPCNT Bit Population Count */
inline void Handle_POPCNT_Gvqp_Evqp(Bit8u last, PhysPt &cseip) {
};


/* _9d:POPF Pop Stack into FLAGS Register */
inline void Handle_POPF(Bit8u last, PhysPt &cseip) {
};


/* _9d:POPFD Pop Stack into eFLAGS Register */
inline void Handle_POPFD(Bit8u last, PhysPt &cseip) {
};


/* _1f:POP Pop a Value from the Stack */
inline void Handle_POP_DS(Bit8u last, PhysPt &cseip) {
};


/* _07:POP Pop a Value from the Stack */
inline void Handle_POP_ES(Bit8u last, PhysPt &cseip) {
};


/* _8f:POP Pop a Value from the Stack */
inline void Handle_POP_Ev(Bit8u last, PhysPt &cseip) {
};


/* _0f_a1:POP Pop a Value from the Stack */
inline void Handle_POP_FS(Bit8u last, PhysPt &cseip) {
};


/* _0f_a9:POP Pop a Value from the Stack */
inline void Handle_POP_GS(Bit8u last, PhysPt &cseip) {
};


/* _17:POP Pop a Value from the Stack */
inline void Handle_POP_delaysint_SS(Bit8u last, PhysPt &cseip) {
};


/* _58:POP Pop a Value from the Stack */
inline void Handle_POP_eAX(Bit8u last, PhysPt &cseip) {
};


/* _5d:POP Pop a Value from the Stack */
inline void Handle_POP_eBP(Bit8u last, PhysPt &cseip) {
};


/* _5b:POP Pop a Value from the Stack */
inline void Handle_POP_eBX(Bit8u last, PhysPt &cseip) {
};


/* _59:POP Pop a Value from the Stack */
inline void Handle_POP_eCX(Bit8u last, PhysPt &cseip) {
};


/* _5f:POP Pop a Value from the Stack */
inline void Handle_POP_eDI(Bit8u last, PhysPt &cseip) {
};


/* _5a:POP Pop a Value from the Stack */
inline void Handle_POP_eDX(Bit8u last, PhysPt &cseip) {
};


/* _5e:POP Pop a Value from the Stack */
inline void Handle_POP_eSI(Bit8u last, PhysPt &cseip) {
};


/* _5c:POP Pop a Value from the Stack */
inline void Handle_POP_eSP(Bit8u last, PhysPt &cseip) {
};


/* _0f_eb:POR Bitwise Logical OR */
inline void Handle_POR_Pq_Qq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_eb:POR Bitwise Logical OR */
inline void Handle_POR_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _0f_18:PREFETCHNTA Prefetch Data Into Caches */
inline void Handle_PREFETCHNTA_Mb(Bit8u last, PhysPt &cseip) {
};


/* _0f_18:PREFETCHT0 Prefetch Data Into Caches */
inline void Handle_PREFETCHT0_Mb(Bit8u last, PhysPt &cseip) {
};


/* _0f_18:PREFETCHT1 Prefetch Data Into Caches */
inline void Handle_PREFETCHT1_Mb(Bit8u last, PhysPt &cseip) {
};


/* _0f_18:PREFETCHT2 Prefetch Data Into Caches */
inline void Handle_PREFETCHT2_Mb(Bit8u last, PhysPt &cseip) {
};


/* _0f_f6:PSADBW Compute Sum of Absolute Differences */
inline void Handle_PSADBW_Pq_Qq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_f6:PSADBW Compute Sum of Absolute Differences */
inline void Handle_PSADBW_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _0f_38_00:PSHUFB Packed Shuffle Bytes */
inline void Handle_PSHUFB_Pq_Qq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_38_00:PSHUFB Packed Shuffle Bytes */
inline void Handle_PSHUFB_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_70:PSHUFD Shuffle Packed Doublewords */
inline void Handle_PSHUFD_Vdq_Wdq_Ib(Bit8u last, PhysPt &cseip) {
};


/* _f3_0f_70:PSHUFHW Shuffle Packed High Words */
inline void Handle_PSHUFHW_Vdq_Wdq_Ib(Bit8u last, PhysPt &cseip) {
};


/* _f2_0f_70:PSHUFLW Shuffle Packed Low Words */
inline void Handle_PSHUFLW_Vdq_Wdq_Ib(Bit8u last, PhysPt &cseip) {
};


/* _0f_70:PSHUFW Shuffle Packed Words */
inline void Handle_PSHUFW_Pq_Qq_Ib(Bit8u last, PhysPt &cseip) {
};


/* _0f_38_08:PSIGNB Packed SIGN */
inline void Handle_PSIGNB_Pq_Qq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_38_08:PSIGNB Packed SIGN */
inline void Handle_PSIGNB_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _0f_38_0a:PSIGND Packed SIGN */
inline void Handle_PSIGND_Pq_Qq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_38_0a:PSIGND Packed SIGN */
inline void Handle_PSIGND_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _0f_38_09:PSIGNW Packed SIGN */
inline void Handle_PSIGNW_Pq_Qq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_38_09:PSIGNW Packed SIGN */
inline void Handle_PSIGNW_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_73:PSLLDQ Shift Double Quadword Left Logical */
inline void Handle_PSLLDQ_Udq_Ib(Bit8u last, PhysPt &cseip) {
};


/* _0f_72:PSLLD Shift Packed Data Left Logical */
inline void Handle_PSLLD_Nq_Ib(Bit8u last, PhysPt &cseip) {
};


/* _0f_f2:PSLLD Shift Packed Data Left Logical */
inline void Handle_PSLLD_Pq_Qq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_72:PSLLD Shift Packed Data Left Logical */
inline void Handle_PSLLD_Udq_Ib(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_f2:PSLLD Shift Packed Data Left Logical */
inline void Handle_PSLLD_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _0f_73:PSLLQ Shift Packed Data Left Logical */
inline void Handle_PSLLQ_Nq_Ib(Bit8u last, PhysPt &cseip) {
};


/* _0f_f3:PSLLQ Shift Packed Data Left Logical */
inline void Handle_PSLLQ_Pq_Qq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_73:PSLLQ Shift Packed Data Left Logical */
inline void Handle_PSLLQ_Udq_Ib(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_f3:PSLLQ Shift Packed Data Left Logical */
inline void Handle_PSLLQ_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _0f_71:PSLLW Shift Packed Data Left Logical */
inline void Handle_PSLLW_Nq_Ib(Bit8u last, PhysPt &cseip) {
};


/* _0f_f1:PSLLW Shift Packed Data Left Logical */
inline void Handle_PSLLW_Pq_Qq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_71:PSLLW Shift Packed Data Left Logical */
inline void Handle_PSLLW_Udq_Ib(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_f1:PSLLW Shift Packed Data Left Logical */
inline void Handle_PSLLW_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _0f_72:PSRAD Shift Packed Data Right Arithmetic */
inline void Handle_PSRAD_Nq_Ib(Bit8u last, PhysPt &cseip) {
};


/* _0f_e2:PSRAD Shift Packed Data Right Arithmetic */
inline void Handle_PSRAD_Pq_Qq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_72:PSRAD Shift Packed Data Right Arithmetic */
inline void Handle_PSRAD_Udq_Ib(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_e2:PSRAD Shift Packed Data Right Arithmetic */
inline void Handle_PSRAD_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _0f_71:PSRAW Shift Packed Data Right Arithmetic */
inline void Handle_PSRAW_Nq_Ib(Bit8u last, PhysPt &cseip) {
};


/* _0f_e1:PSRAW Shift Packed Data Right Arithmetic */
inline void Handle_PSRAW_Pq_Qq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_71:PSRAW Shift Packed Data Right Arithmetic */
inline void Handle_PSRAW_Udq_Ib(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_e1:PSRAW Shift Packed Data Right Arithmetic */
inline void Handle_PSRAW_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_73:PSRLDQ Shift Double Quadword Right Logical */
inline void Handle_PSRLDQ_Udq_Ib(Bit8u last, PhysPt &cseip) {
};


/* _0f_72:PSRLD Shift Double Quadword Right Logical */
inline void Handle_PSRLD_Nq_Ib(Bit8u last, PhysPt &cseip) {
};


/* _0f_d2:PSRLD Shift Packed Data Right Logical */
inline void Handle_PSRLD_Pq_Qq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_72:PSRLD Shift Double Quadword Right Logical */
inline void Handle_PSRLD_Udq_Ib(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_d2:PSRLD Shift Packed Data Right Logical */
inline void Handle_PSRLD_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _0f_73:PSRLQ Shift Packed Data Right Logical */
inline void Handle_PSRLQ_Nq_Ib(Bit8u last, PhysPt &cseip) {
};


/* _0f_d3:PSRLQ Shift Packed Data Right Logical */
inline void Handle_PSRLQ_Pq_Qq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_73:PSRLQ Shift Packed Data Right Logical */
inline void Handle_PSRLQ_Udq_Ib(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_d3:PSRLQ Shift Packed Data Right Logical */
inline void Handle_PSRLQ_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _0f_71:PSRLW Shift Packed Data Right Logical */
inline void Handle_PSRLW_Nq_Ib(Bit8u last, PhysPt &cseip) {
};


/* _0f_d1:PSRLW Shift Packed Data Right Logical */
inline void Handle_PSRLW_Pq_Qq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_71:PSRLW Shift Packed Data Right Logical */
inline void Handle_PSRLW_Udq_Ib(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_d1:PSRLW Shift Packed Data Right Logical */
inline void Handle_PSRLW_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _0f_f8:PSUBB Subtract Packed Integers */
inline void Handle_PSUBB_Pq_Qq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_f8:PSUBB Subtract Packed Integers */
inline void Handle_PSUBB_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _0f_fa:PSUBD Subtract Packed Integers */
inline void Handle_PSUBD_Pq_Qq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_fa:PSUBD Subtract Packed Integers */
inline void Handle_PSUBD_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _0f_fb:PSUBQ Subtract Packed Quadword Integers */
inline void Handle_PSUBQ_Pq_Qq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_fb:PSUBQ Subtract Packed Quadword Integers */
inline void Handle_PSUBQ_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _0f_e8:PSUBSB Subtract Packed Signed Integers with Signed Saturation */
inline void Handle_PSUBSB_Pq_Qq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_e8:PSUBSB Subtract Packed Signed Integers with Signed Saturation */
inline void Handle_PSUBSB_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _0f_e9:PSUBSW Subtract Packed Signed Integers with Signed Saturation */
inline void Handle_PSUBSW_Pq_Qq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_e9:PSUBSW Subtract Packed Signed Integers with Signed Saturation */
inline void Handle_PSUBSW_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _0f_f9:PSUBW Subtract Packed Integers */
inline void Handle_PSUBW_Pq_Qq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_f9:PSUBW Subtract Packed Integers */
inline void Handle_PSUBW_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_38_17:PTEST Logical Compare */
inline void Handle_PTEST_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _0f_68:PUNPCKHBW Unpack High Data */
inline void Handle_PUNPCKHBW_Pq_Qq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_68:PUNPCKHBW Unpack High Data */
inline void Handle_PUNPCKHBW_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _0f_6a:PUNPCKHDQ Unpack High Data */
inline void Handle_PUNPCKHDQ_Pq_Qq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_6a:PUNPCKHDQ Unpack High Data */
inline void Handle_PUNPCKHDQ_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_6d:PUNPCKHQDQ Unpack High Data */
inline void Handle_PUNPCKHQDQ_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _0f_69:PUNPCKHWD Unpack High Data */
inline void Handle_PUNPCKHWD_Pq_Qq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_69:PUNPCKHWD Unpack High Data */
inline void Handle_PUNPCKHWD_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _0f_60:PUNPCKLBW Unpack Low Data */
inline void Handle_PUNPCKLBW_Pq_Qd(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_60:PUNPCKLBW Unpack Low Data */
inline void Handle_PUNPCKLBW_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _0f_62:PUNPCKLDQ Unpack Low Data */
inline void Handle_PUNPCKLDQ_Pq_Qd(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_62:PUNPCKLDQ Unpack Low Data */
inline void Handle_PUNPCKLDQ_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_6c:PUNPCKLQDQ Unpack Low Data */
inline void Handle_PUNPCKLQDQ_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _0f_61:PUNPCKLWD Unpack Low Data */
inline void Handle_PUNPCKLWD_Pq_Qd(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_61:PUNPCKLWD Unpack Low Data */
inline void Handle_PUNPCKLWD_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _60:PUSHA Push All General-Purpose Registers */
inline void Handle_PUSHA(Bit8u last, PhysPt &cseip) {
};


/* _60:PUSHAD Push All General-Purpose Registers */
inline void Handle_PUSHAD(Bit8u last, PhysPt &cseip) {
};


/* _9c:PUSHF Push FLAGS Register onto the Stack */
inline void Handle_PUSHF(Bit8u last, PhysPt &cseip) {
};


/* _9c:PUSHFD Push eFLAGS Register onto the Stack */
inline void Handle_PUSHFD(Bit8u last, PhysPt &cseip) {
};


/* _0e:PUSH Push Word, Doubleword or Quadword Onto the Stack */
inline void Handle_PUSH_CS(Bit8u last, PhysPt &cseip) {
};


/* _1e:PUSH Push Word, Doubleword or Quadword Onto the Stack */
inline void Handle_PUSH_DS(Bit8u last, PhysPt &cseip) {
};


/* _06:PUSH Push Word, Doubleword or Quadword Onto the Stack */
inline void Handle_PUSH_ES(Bit8u last, PhysPt &cseip) {
};


/* _ff:PUSH Push Word, Doubleword or Quadword Onto the Stack */
inline void Handle_PUSH_Ev(Bit8u last, PhysPt &cseip) {
};


/* _0f_a0:PUSH Push Word, Doubleword or Quadword Onto the Stack */
inline void Handle_PUSH_FS(Bit8u last, PhysPt &cseip) {
};


/* _0f_a8:PUSH Push Word, Doubleword or Quadword Onto the Stack */
inline void Handle_PUSH_GS(Bit8u last, PhysPt &cseip) {
};


/* _6a:PUSH Push Word, Doubleword or Quadword Onto the Stack */
inline void Handle_PUSH_Ibss(Bit8u last, PhysPt &cseip) {
};


/* _68:PUSH Push Word, Doubleword or Quadword Onto the Stack */
inline void Handle_PUSH_Ivs(Bit8u last, PhysPt &cseip) {
};


/* _16:PUSH Push Word, Doubleword or Quadword Onto the Stack */
inline void Handle_PUSH_SS(Bit8u last, PhysPt &cseip) {
};


/* _50:PUSH Push Word, Doubleword or Quadword Onto the Stack */
inline void Handle_PUSH_eAX(Bit8u last, PhysPt &cseip) {
};


/* _55:PUSH Push Word, Doubleword or Quadword Onto the Stack */
inline void Handle_PUSH_eBP(Bit8u last, PhysPt &cseip) {
};


/* _53:PUSH Push Word, Doubleword or Quadword Onto the Stack */
inline void Handle_PUSH_eBX(Bit8u last, PhysPt &cseip) {
};


/* _51:PUSH Push Word, Doubleword or Quadword Onto the Stack */
inline void Handle_PUSH_eCX(Bit8u last, PhysPt &cseip) {
};


/* _57:PUSH Push Word, Doubleword or Quadword Onto the Stack */
inline void Handle_PUSH_eDI(Bit8u last, PhysPt &cseip) {
};


/* _52:PUSH Push Word, Doubleword or Quadword Onto the Stack */
inline void Handle_PUSH_eDX(Bit8u last, PhysPt &cseip) {
};


/* _56:PUSH Push Word, Doubleword or Quadword Onto the Stack */
inline void Handle_PUSH_eSI(Bit8u last, PhysPt &cseip) {
};


/* _54:PUSH Push Word, Doubleword or Quadword Onto the Stack */
inline void Handle_PUSH_eSP(Bit8u last, PhysPt &cseip) {
};


/* _0f_ef:PXOR Logical Exclusive OR */
inline void Handle_PXOR_Pq_Qq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_ef:PXOR Logical Exclusive OR */
inline void Handle_PXOR_Vdq_Wdq(Bit8u last, PhysPt &cseip) {
};


/* _d2:RCL Rotate */
inline void Handle_RCL_Eb_CL(Bit8u last, PhysPt &cseip) {
};


/* _d0:RCL Rotate */
inline void Handle_RCL_Eb_I(Bit8u last, PhysPt &cseip) {
};


/* _c0:RCL Rotate */
inline void Handle_RCL_Eb_Ib(Bit8u last, PhysPt &cseip) {
};


/* _d3:RCL Rotate */
inline void Handle_RCL_Evqp_CL(Bit8u last, PhysPt &cseip) {
};


/* _d1:RCL Rotate */
inline void Handle_RCL_Evqp_I(Bit8u last, PhysPt &cseip) {
};


/* _c1:RCL Rotate */
inline void Handle_RCL_Evqp_Ib(Bit8u last, PhysPt &cseip) {
};


/* _0f_53:RCPPS Compute Reciprocals of Packed Single-FP Values */
inline void Handle_RCPPS_Vps_Wps(Bit8u last, PhysPt &cseip) {
};


/* _f3_0f_53:RCPSS Compute Reciprocal of Scalar Single-FP Values */
inline void Handle_RCPSS_Vss_Wss(Bit8u last, PhysPt &cseip) {
};


/* _d2:RCR Rotate */
inline void Handle_RCR_Eb_CL(Bit8u last, PhysPt &cseip) {
};


/* _d0:RCR Rotate */
inline void Handle_RCR_Eb_I(Bit8u last, PhysPt &cseip) {
};


/* _c0:RCR Rotate */
inline void Handle_RCR_Eb_Ib(Bit8u last, PhysPt &cseip) {
};


/* _d3:RCR Rotate */
inline void Handle_RCR_Evqp_CL(Bit8u last, PhysPt &cseip) {
};


/* _d1:RCR Rotate */
inline void Handle_RCR_Evqp_I(Bit8u last, PhysPt &cseip) {
};


/* _c1:RCR Rotate */
inline void Handle_RCR_Evqp_Ib(Bit8u last, PhysPt &cseip) {
};


/* _0f_32:RDMSR Read from Model Specific Register */
inline void Handle_RDMSR(Bit8u last, PhysPt &cseip) {
};


/* _0f_33:RDPMC Read Performance-Monitoring Counters */
inline void Handle_RDPMC(Bit8u last, PhysPt &cseip) {
};


/* _0f_31:RDTSC Read Time-Stamp Counter */
inline void Handle_RDTSC(Bit8u last, PhysPt &cseip) {
};


/* _0f_01_f9:RDTSCP Read Time-Stamp Counter and Processor ID */
inline void Handle_RDTSCP_serial(Bit8u last, PhysPt &cseip) {
};


/* _cb:RETF Return from procedure */
inline void Handle_RETF(Bit8u last, PhysPt &cseip) {
};


/* _ca:RETF Return from procedure */
inline void Handle_RETF_Iw(Bit8u last, PhysPt &cseip) {
};


/* _c3:RETN Return from procedure */
inline void Handle_RETN(Bit8u last, PhysPt &cseip) {
};


/* _c2:RETN Return from procedure */
inline void Handle_RETN_Iw(Bit8u last, PhysPt &cseip) {
};


/* _d2:ROL Rotate */
inline void Handle_ROL_Eb_CL(Bit8u last, PhysPt &cseip) {
};


/* _d0:ROL Rotate */
inline void Handle_ROL_Eb_I(Bit8u last, PhysPt &cseip) {
};


/* _c0:ROL Rotate */
inline void Handle_ROL_Eb_Ib(Bit8u last, PhysPt &cseip) {
};


/* _d3:ROL Rotate */
inline void Handle_ROL_Evqp_CL(Bit8u last, PhysPt &cseip) {
};


/* _d1:ROL Rotate */
inline void Handle_ROL_Evqp_I(Bit8u last, PhysPt &cseip) {
};


/* _c1:ROL Rotate */
inline void Handle_ROL_Evqp_Ib(Bit8u last, PhysPt &cseip) {
};


/* _d2:ROR Rotate */
inline void Handle_ROR_Eb_CL(Bit8u last, PhysPt &cseip) {
};


/* _d0:ROR Rotate */
inline void Handle_ROR_Eb_I(Bit8u last, PhysPt &cseip) {
};


/* _c0:ROR Rotate */
inline void Handle_ROR_Eb_Ib(Bit8u last, PhysPt &cseip) {
};


/* _d3:ROR Rotate */
inline void Handle_ROR_Evqp_CL(Bit8u last, PhysPt &cseip) {
};


/* _d1:ROR Rotate */
inline void Handle_ROR_Evqp_I(Bit8u last, PhysPt &cseip) {
};


/* _c1:ROR Rotate */
inline void Handle_ROR_Evqp_Ib(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_3a_09:ROUNDPD Round Packed Double-FP Values */
inline void Handle_ROUNDPD_Vps_Wpd_Ib(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_3a_08:ROUNDPS Round Packed Single-FP Values */
inline void Handle_ROUNDPS_Vps_Wps_Ib(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_3a_0b:ROUNDSD Round Scalar Double-FP Values */
inline void Handle_ROUNDSD_Vsd_Wsd_Ib(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_3a_0a:ROUNDSS Round Scalar Single-FP Values */
inline void Handle_ROUNDSS_Vss_Wss_Ib(Bit8u last, PhysPt &cseip) {
};


/* _0f_aa:RSM Resume from System Management Mode */
inline void Handle_RSM(Bit8u last, PhysPt &cseip) {
};


/* _0f_52:RSQRTPS Compute Recipr. of Square Roots of Packed Single-FP Values */
inline void Handle_RSQRTPS_Vps_Wps(Bit8u last, PhysPt &cseip) {
};


/* _f3_0f_52:RSQRTSS Compute Recipr. of Square Root of Scalar Single-FP Value */
inline void Handle_RSQRTSS_Vss_Wss(Bit8u last, PhysPt &cseip) {
};


/* _9e:SAHF Store AH into Flags */
inline void Handle_SAHF(Bit8u last, PhysPt &cseip) {
};


/* _d2:SAR Shift */
inline void Handle_SAR_Eb_CL(Bit8u last, PhysPt &cseip) {
};


/* _d0:SAR Shift */
inline void Handle_SAR_Eb_I(Bit8u last, PhysPt &cseip) {
};


/* _c0:SAR Shift */
inline void Handle_SAR_Eb_Ib(Bit8u last, PhysPt &cseip) {
};


/* _d3:SAR Shift */
inline void Handle_SAR_Evqp_CL(Bit8u last, PhysPt &cseip) {
};


/* _d1:SAR Shift */
inline void Handle_SAR_Evqp_I(Bit8u last, PhysPt &cseip) {
};


/* _c1:SAR Shift */
inline void Handle_SAR_Evqp_Ib(Bit8u last, PhysPt &cseip) {
};


/* _18:SBB Integer Subtraction with Borrow */
inline void Handle_SBB_Eb_Gb(Bit8u last, PhysPt &cseip) {
};


/* _82:SBB Integer Subtraction with Borrow */
inline void Handle_SBB_Eb_Ib(Bit8u last, PhysPt &cseip) {
};


/* _19:SBB Integer Subtraction with Borrow */
inline void Handle_SBB_Evqp_Gvqp(Bit8u last, PhysPt &cseip) {
};


/* _83:SBB Integer Subtraction with Borrow */
inline void Handle_SBB_Evqp_Ibs(Bit8u last, PhysPt &cseip) {
};


/* _81:SBB Integer Subtraction with Borrow */
inline void Handle_SBB_Evqp_Ivds(Bit8u last, PhysPt &cseip) {
};


/* _1a:SBB Integer Subtraction with Borrow */
inline void Handle_SBB_Gb_Eb(Bit8u last, PhysPt &cseip) {
};


/* _1b:SBB Integer Subtraction with Borrow */
inline void Handle_SBB_Gvqp_Evqp(Bit8u last, PhysPt &cseip) {
};


/* _1c:SBB Integer Subtraction with Borrow */
inline void Handle_SBB_acc_AL_Ib(Bit8u last, PhysPt &cseip) {
};


/* _1d:SBB Integer Subtraction with Borrow */
inline void Handle_SBB_acc_eAX_Ivds(Bit8u last, PhysPt &cseip) {
};


/* _ae:SCAS Scan String */
inline void Handle_SCAS_Yb(Bit8u last, PhysPt &cseip) {
};


/* _af:SCAS Scan String */
inline void Handle_SCAS_Yv(Bit8u last, PhysPt &cseip) {
};


/* _af:SCAS Scan String */
inline void Handle_SCAS_Yw(Bit8u last, PhysPt &cseip) {
};


/* _0f_96:SETBE Set Byte on Condition - below or equal/not above (CF=1 AND ZF=1) */
inline void Handle_SETBE_Eb(Bit8u last, PhysPt &cseip) {
};


/* _0f_92:SETB Set Byte on Condition - below/not above or equal/carry (CF=1) */
inline void Handle_SETB_Eb(Bit8u last, PhysPt &cseip) {
};


/* _0f_9e:SETLE Set Byte on Condition - less or equal/not greater ((ZF=1) OR (SF!=OF)) */
inline void Handle_SETLE_Eb(Bit8u last, PhysPt &cseip) {
};


/* _0f_9c:SETL Set Byte on Condition - less/not greater (SF!=OF) */
inline void Handle_SETL_Eb(Bit8u last, PhysPt &cseip) {
};


/* _0f_97:SETNBE Set Byte on Condition - not below or equal/above (CF=0 AND ZF=0) */
inline void Handle_SETNBE_Eb(Bit8u last, PhysPt &cseip) {
};


/* _0f_93:SETNB Set Byte on Condition - not below/above or equal/not carry (CF=0) */
inline void Handle_SETNB_Eb(Bit8u last, PhysPt &cseip) {
};


/* _0f_9f:SETNLE Set Byte on Condition - not less nor equal/greater ((ZF=0) AND (SF=OF)) */
inline void Handle_SETNLE_Eb(Bit8u last, PhysPt &cseip) {
};


/* _0f_9d:SETNL Set Byte on Condition - not less/greater or equal (SF=OF) */
inline void Handle_SETNL_Eb(Bit8u last, PhysPt &cseip) {
};


/* _0f_91:SETNO Set Byte on Condition - not overflow (OF=0) */
inline void Handle_SETNO_Eb(Bit8u last, PhysPt &cseip) {
};


/* _0f_9b:SETNP Set Byte on Condition - not parity/parity odd */
inline void Handle_SETNP_Eb(Bit8u last, PhysPt &cseip) {
};


/* _0f_99:SETNS Set Byte on Condition - not sign (SF=0) */
inline void Handle_SETNS_Eb(Bit8u last, PhysPt &cseip) {
};


/* _0f_95:SETNZ Set Byte on Condition - not zero/not equal (ZF=1) */
inline void Handle_SETNZ_Eb(Bit8u last, PhysPt &cseip) {
};


/* _0f_90:SETO Set Byte on Condition - overflow (OF=1) */
inline void Handle_SETO_Eb(Bit8u last, PhysPt &cseip) {
};


/* _0f_9a:SETP Set Byte on Condition - parity/parity even (PF=1) */
inline void Handle_SETP_Eb(Bit8u last, PhysPt &cseip) {
};


/* _0f_98:SETS Set Byte on Condition - sign (SF=1) */
inline void Handle_SETS_Eb(Bit8u last, PhysPt &cseip) {
};


/* _0f_94:SETZ Set Byte on Condition - zero/equal (ZF=0) */
inline void Handle_SETZ_Eb(Bit8u last, PhysPt &cseip) {
};


/* _0f_ae:SFENCE Store Fence */
inline void Handle_SFENCE(Bit8u last, PhysPt &cseip) {
};


/* _0f_01:SGDT Store Global Descriptor Table Register */
inline void Handle_SGDT_Ms(Bit8u last, PhysPt &cseip) {
};


/* _0f_a5:SHLD Double Precision Shift Left */
inline void Handle_SHLD_Evqp_Gvqp_CL(Bit8u last, PhysPt &cseip) {
};


/* _0f_a4:SHLD Double Precision Shift Left */
inline void Handle_SHLD_Evqp_Gvqp_Ib(Bit8u last, PhysPt &cseip) {
};


/* _d2:SHL Shift */
inline void Handle_SHL_Eb_CL(Bit8u last, PhysPt &cseip) {
};


/* _d0:SHL Shift */
inline void Handle_SHL_Eb_I(Bit8u last, PhysPt &cseip) {
};


/* _c0:SHL Shift */
inline void Handle_SHL_Eb_Ib(Bit8u last, PhysPt &cseip) {
};


/* _d3:SHL Shift */
inline void Handle_SHL_Evqp_CL(Bit8u last, PhysPt &cseip) {
};


/* _d1:SHL Shift */
inline void Handle_SHL_Evqp_I(Bit8u last, PhysPt &cseip) {
};


/* _c1:SHL Shift */
inline void Handle_SHL_Evqp_Ib(Bit8u last, PhysPt &cseip) {
};


/* _0f_ad:SHRD Double Precision Shift Right */
inline void Handle_SHRD_Evqp_Gvqp_CL(Bit8u last, PhysPt &cseip) {
};


/* _0f_ac:SHRD Double Precision Shift Right */
inline void Handle_SHRD_Evqp_Gvqp_Ib(Bit8u last, PhysPt &cseip) {
};


/* _d2:SHR Shift */
inline void Handle_SHR_Eb_CL(Bit8u last, PhysPt &cseip) {
};


/* _d0:SHR Shift */
inline void Handle_SHR_Eb_I(Bit8u last, PhysPt &cseip) {
};


/* _c0:SHR Shift */
inline void Handle_SHR_Eb_Ib(Bit8u last, PhysPt &cseip) {
};


/* _d3:SHR Shift */
inline void Handle_SHR_Evqp_CL(Bit8u last, PhysPt &cseip) {
};


/* _d1:SHR Shift */
inline void Handle_SHR_Evqp_I(Bit8u last, PhysPt &cseip) {
};


/* _c1:SHR Shift */
inline void Handle_SHR_Evqp_Ib(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_c6:SHUFPD Shuffle Packed Double-FP Values */
inline void Handle_SHUFPD_Vpd_Wpd_Ib(Bit8u last, PhysPt &cseip) {
};


/* _0f_c6:SHUFPS Shuffle Packed Single-FP Values */
inline void Handle_SHUFPS_Vps_Wps_Ib(Bit8u last, PhysPt &cseip) {
};


/* _0f_01:SIDT Store Interrupt Descriptor Table Register */
inline void Handle_SIDT_Ms(Bit8u last, PhysPt &cseip) {
};


/* _0f_00:SLDT Store Local Descriptor Table Register */
inline void Handle_SLDT_Mw(Bit8u last, PhysPt &cseip) {
};


/* _0f_01:SMSW Store Machine Status Word */
inline void Handle_SMSW_Mw(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_51:SQRTPD Compute Square Roots of Packed Double-FP Values */
inline void Handle_SQRTPD_Vpd_Wpd(Bit8u last, PhysPt &cseip) {
};


/* _0f_51:SQRTPS Compute Square Roots of Packed Single-FP Values */
inline void Handle_SQRTPS_Vps_Wps(Bit8u last, PhysPt &cseip) {
};


/* _f2_0f_51:SQRTSD Compute Square Root of Scalar Double-FP Value */
inline void Handle_SQRTSD_Vsd_Wsd(Bit8u last, PhysPt &cseip) {
};


/* _f3_0f_51:SQRTSS Compute Square Root of Scalar Single-FP Value */
inline void Handle_SQRTSS_Vss_Wss(Bit8u last, PhysPt &cseip) {
};


/* _f9:STC Set Carry Flag */
inline void Handle_STC(Bit8u last, PhysPt &cseip) {
};


/* _fd:STD Set Direction Flag */
inline void Handle_STD(Bit8u last, PhysPt &cseip) {
};


/* _fb:STI Set Interrupt Flag */
inline void Handle_STI_delaysint_cond(Bit8u last, PhysPt &cseip) {
};


/* _0f_ae:STMXCSR Store MXCSR Register State */
inline void Handle_STMXCSR_Md(Bit8u last, PhysPt &cseip) {
};


/* _aa:STOS Store String */
inline void Handle_STOS_Yb(Bit8u last, PhysPt &cseip) {
};


/* _ab:STOS Store String */
inline void Handle_STOS_Yv(Bit8u last, PhysPt &cseip) {
};


/* _ab:STOS Store String */
inline void Handle_STOS_Yw(Bit8u last, PhysPt &cseip) {
};


/* _0f_00:STR Store Task Register */
inline void Handle_STR_Mw(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_5c:SUBPD Subtract Packed Double-FP Values */
inline void Handle_SUBPD_Vpd_Wpd(Bit8u last, PhysPt &cseip) {
};


/* _0f_5c:SUBPS Subtract Packed Single-FP Values */
inline void Handle_SUBPS_Vps_Wps(Bit8u last, PhysPt &cseip) {
};


/* _f2_0f_5c:SUBSD Subtract Scalar Double-FP Values */
inline void Handle_SUBSD_Vsd_Wsd(Bit8u last, PhysPt &cseip) {
};


/* _f3_0f_5c:SUBSS Subtract Scalar Single-FP Values */
inline void Handle_SUBSS_Vss_Wss(Bit8u last, PhysPt &cseip) {
};


/* _28:SUB Subtract */
inline void Handle_SUB_Eb_Gb(Bit8u last, PhysPt &cseip) {
};


/* _82:SUB Subtract */
inline void Handle_SUB_Eb_Ib(Bit8u last, PhysPt &cseip) {
};


/* _29:SUB Subtract */
inline void Handle_SUB_Evqp_Gvqp(Bit8u last, PhysPt &cseip) {
};


/* _83:SUB Subtract */
inline void Handle_SUB_Evqp_Ibs(Bit8u last, PhysPt &cseip) {
};


/* _81:SUB Subtract */
inline void Handle_SUB_Evqp_Ivds(Bit8u last, PhysPt &cseip) {
};


/* _2a:SUB Subtract */
inline void Handle_SUB_Gb_Eb(Bit8u last, PhysPt &cseip) {
};


/* _2b:SUB Subtract */
inline void Handle_SUB_Gvqp_Evqp(Bit8u last, PhysPt &cseip) {
};


/* _2c:SUB Subtract */
inline void Handle_SUB_acc_AL_Ib(Bit8u last, PhysPt &cseip) {
};


/* _2d:SUB Subtract */
inline void Handle_SUB_acc_eAX_Ivds(Bit8u last, PhysPt &cseip) {
};


/* _0f_34:SYSENTER Fast System Call */
inline void Handle_SYSENTER(Bit8u last, PhysPt &cseip) {
};


/* _0f_35:SYSEXIT Fast Return from Fast System Call */
inline void Handle_SYSEXIT(Bit8u last, PhysPt &cseip) {
};


/* _84:TEST Logical Compare */
inline void Handle_TEST_Eb_Gb(Bit8u last, PhysPt &cseip) {
};


/* _f6:TEST Logical Compare */
inline void Handle_TEST_Eb_Ib(Bit8u last, PhysPt &cseip) {
};


/* _85:TEST Logical Compare */
inline void Handle_TEST_Evqp_Gvqp(Bit8u last, PhysPt &cseip) {
};


/* _f7:TEST Logical Compare */
inline void Handle_TEST_Evqp_Ivqp(Bit8u last, PhysPt &cseip) {
};


/* _a8:TEST Logical Compare */
inline void Handle_TEST_acc_AL_Ib(Bit8u last, PhysPt &cseip) {
};


/* _a9:TEST Logical Compare */
inline void Handle_TEST_acc_eAX_Ivds(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_2e:UCOMISD Unordered Compare Scalar Double-FP Values and Set EFLAGS */
inline void Handle_UCOMISD_Vsd_Wsd(Bit8u last, PhysPt &cseip) {
};


/* _0f_2e:UCOMISS Unordered Compare Scalar Single-FP Values and Set EFLAGS */
inline void Handle_UCOMISS_Vss_Wss(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_15:UNPCKHPD Unpack and Interleave High Packed Double-FP Values */
inline void Handle_UNPCKHPD_Vpd_Wpd(Bit8u last, PhysPt &cseip) {
};


/* _0f_15:UNPCKHPS Unpack and Interleave High Packed Single-FP Values */
inline void Handle_UNPCKHPS_Vps_Wq(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_14:UNPCKLPD Unpack and Interleave Low Packed Double-FP Values */
inline void Handle_UNPCKLPD_Vpd_Wpd(Bit8u last, PhysPt &cseip) {
};


/* _0f_14:UNPCKLPS Unpack and Interleave Low Packed Single-FP Values */
inline void Handle_UNPCKLPS_Vps_Wq(Bit8u last, PhysPt &cseip) {
};


/* _0f_00:VERR Verify a Segment for Reading */
inline void Handle_VERR_Ew(Bit8u last, PhysPt &cseip) {
};


/* _0f_00:VERW Verify a Segment for Writing */
inline void Handle_VERW_Ew(Bit8u last, PhysPt &cseip) {
};


/* _0f_01_c1:VMCALL Call to VM Monitor */
inline void Handle_VMCALL(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_c7:VMCLEAR Clear Virtual-Machine Control Structure */
inline void Handle_VMCLEAR_Mq(Bit8u last, PhysPt &cseip) {
};


/* _0f_01_c2:VMLAUNCH Launch Virtual Machine */
inline void Handle_VMLAUNCH(Bit8u last, PhysPt &cseip) {
};


/* _0f_c7:VMPTRLD Load Pointer to Virtual-Machine Control Structure */
inline void Handle_VMPTRLD_Mq(Bit8u last, PhysPt &cseip) {
};


/* _0f_c7:VMPTRST Store Pointer to Virtual-Machine Control Structure */
inline void Handle_VMPTRST_Mq(Bit8u last, PhysPt &cseip) {
};


/* _0f_78:VMREAD Read Field from Virtual-Machine Control Structure */
inline void Handle_VMREAD_Ed_Gd(Bit8u last, PhysPt &cseip) {
};


/* _0f_01_c3:VMRESUME Resume Virtual Machine */
inline void Handle_VMRESUME(Bit8u last, PhysPt &cseip) {
};


/* _0f_79:VMWRITE Write Field to Virtual-Machine Control Structure */
inline void Handle_VMWRITE_Gd_Ed(Bit8u last, PhysPt &cseip) {
};


/* _0f_01_c4:VMXOFF Leave VMX Operation */
inline void Handle_VMXOFF(Bit8u last, PhysPt &cseip) {
};


/* _f3_0f_c7:VMXON Enter VMX Operation */
inline void Handle_VMXON_Mq(Bit8u last, PhysPt &cseip) {
};


/* _0f_09:WBINVD Write Back and Invalidate Cache */
inline void Handle_WBINVD_serial(Bit8u last, PhysPt &cseip) {
};


/* _0f_30:WRMSR Write to Model Specific Register */
inline void Handle_WRMSR_serial(Bit8u last, PhysPt &cseip) {
};


/* _0f_c0:XADD Exchange and Add */
inline void Handle_XADD_Eb_Gb(Bit8u last, PhysPt &cseip) {
};


/* _0f_c1:XADD Exchange and Add */
inline void Handle_XADD_Evqp_Gvqp(Bit8u last, PhysPt &cseip) {
};


/* _86:XCHG Exchange Register/Memory with Register */
inline void Handle_XCHG_Gb_Eb(Bit8u last, PhysPt &cseip) {
};


/* _87:XCHG Exchange Register/Memory with Register */
inline void Handle_XCHG_Gvqp_Evqp(Bit8u last, PhysPt &cseip) {
};


/* _90:XCHG Exchange Register/Memory with Register */
inline void Handle_XCHG_acc_eAX_eAX(Bit8u last, PhysPt &cseip) {
};


/* _95:XCHG Exchange Register/Memory with Register */
inline void Handle_XCHG_acc_eBP_eAX(Bit8u last, PhysPt &cseip) {
};


/* _93:XCHG Exchange Register/Memory with Register */
inline void Handle_XCHG_acc_eBX_eAX(Bit8u last, PhysPt &cseip) {
};


/* _91:XCHG Exchange Register/Memory with Register */
inline void Handle_XCHG_acc_eCX_eAX(Bit8u last, PhysPt &cseip) {
};


/* _97:XCHG Exchange Register/Memory with Register */
inline void Handle_XCHG_acc_eDI_eAX(Bit8u last, PhysPt &cseip) {
};


/* _92:XCHG Exchange Register/Memory with Register */
inline void Handle_XCHG_acc_eDX_eAX(Bit8u last, PhysPt &cseip) {
};


/* _96:XCHG Exchange Register/Memory with Register */
inline void Handle_XCHG_acc_eSI_eAX(Bit8u last, PhysPt &cseip) {
};


/* _94:XCHG Exchange Register/Memory with Register */
inline void Handle_XCHG_acc_eSP_eAX(Bit8u last, PhysPt &cseip) {
};


/* _0f_01_d0:XGETBV Get Value of Extended Control Register */
inline void Handle_XGETBV(Bit8u last, PhysPt &cseip) {
};


/* _d7:XLAT Table Look-up Translation */
inline void Handle_XLAT_BBb(Bit8u last, PhysPt &cseip) {
};


/* _66_0f_57:XORPD Bitwise Logical XOR for Double-FP Values */
inline void Handle_XORPD_Vpd_Wpd(Bit8u last, PhysPt &cseip) {
};


/* _0f_57:XORPS Bitwise Logical XOR for Single-FP Values */
inline void Handle_XORPS_Vps_Wps(Bit8u last, PhysPt &cseip) {
};


/* _30:XOR Logical Exclusive OR */
inline void Handle_XOR_Eb_Gb(Bit8u last, PhysPt &cseip) {
};


/* _82:XOR Logical Exclusive OR */
inline void Handle_XOR_Eb_Ib(Bit8u last, PhysPt &cseip) {
};


/* _31:XOR Logical Exclusive OR */
inline void Handle_XOR_Evqp_Gvqp(Bit8u last, PhysPt &cseip) {
};


/* _83:XOR Logical Exclusive OR */
inline void Handle_XOR_Evqp_Ibs(Bit8u last, PhysPt &cseip) {
};


/* _81:XOR Logical Exclusive OR */
inline void Handle_XOR_Evqp_Ivds(Bit8u last, PhysPt &cseip) {
};


/* _32:XOR Logical Exclusive OR */
inline void Handle_XOR_Gb_Eb(Bit8u last, PhysPt &cseip) {
};


/* _33:XOR Logical Exclusive OR */
inline void Handle_XOR_Gvqp_Evqp(Bit8u last, PhysPt &cseip) {
};


/* _34:XOR Logical Exclusive OR */
inline void Handle_XOR_acc_AL_Ib(Bit8u last, PhysPt &cseip) {
};


/* _35:XOR Logical Exclusive OR */
inline void Handle_XOR_acc_eAX_Ivds(Bit8u last, PhysPt &cseip) {
};


/* _0f_ae:XRSTOR Restore Processor Extended States */
inline void Handle_XRSTOR_M(Bit8u last, PhysPt &cseip) {
};


/* _0f_ae:XSAVE Save Processor Extended States */
inline void Handle_XSAVE_M(Bit8u last, PhysPt &cseip) {
};


/* _0f_01_d1:XSETBV Set Extended Control Register */
inline void Handle_XSETBV(Bit8u last, PhysPt &cseip) {
};

static inline void Handle_Prefix_26(OpState& state) {
};

static inline void Handle_Prefix_2e(OpState& state) {
};

static inline void Handle_Prefix_36(OpState& state) {
};

static inline void Handle_Prefix_3e(OpState& state) {
};

static inline void Handle_Prefix_64(OpState& state) {
};

static inline void Handle_Prefix_65(OpState& state) {
};

static inline void Handle_Prefix_66(OpState& state) {
};

static inline void Handle_Prefix_67(OpState& state) {
};

static inline void Handle_Prefix_f0(OpState& state) {
};

static inline void Handle_Prefix_f2(OpState& state) {
};

static inline void Handle_Prefix_f3(OpState& state) {
};
public:
bool Parse(PhysPt &cseip);
};
const OpState CpuRunnerX86::table[] = {
	// 00
	I_ADD_Eb_Gb, I_ADD_Evqp_Gvqp, I_ADD_Gb_Eb, I_ADD_Gvqp_Evqp, I_ADD_acc_AL_Ib, I_ADD_acc_eAX_Ivds, I_PUSH_ES, I_POP_ES, 
	// 08
	I_OR_Eb_Gb, I_OR_Evqp_Gvqp, I_OR_Gb_Eb, I_OR_Gvqp_Evqp, I_OR_acc_AL_Ib, I_OR_acc_eAX_Ivds, I_PUSH_CS, ST_0f, 
	// 10
	I_ADC_Eb_Gb, I_ADC_Evqp_Gvqp, I_ADC_Gb_Eb, I_ADC_Gvqp_Evqp, I_ADC_acc_AL_Ib, I_ADC_acc_eAX_Ivds, I_PUSH_SS, I_POP_delaysint_SS, 
	// 18
	I_SBB_Eb_Gb, I_SBB_Evqp_Gvqp, I_SBB_Gb_Eb, I_SBB_Gvqp_Evqp, I_SBB_acc_AL_Ib, I_SBB_acc_eAX_Ivds, I_PUSH_DS, I_POP_DS, 
	// 20
	I_AND_Eb_Gb, I_AND_Evqp_Gvqp, I_AND_Gb_Eb, I_AND_Gvqp_Evqp, I_AND_acc_AL_Ib, I_AND_acc_eAX_Ivds, PR_26, I_DAA, 
	// 28
	I_SUB_Eb_Gb, I_SUB_Evqp_Gvqp, I_SUB_Gb_Eb, I_SUB_Gvqp_Evqp, I_SUB_acc_AL_Ib, I_SUB_acc_eAX_Ivds, PR_2e, I_DAS, 
	// 30
	I_XOR_Eb_Gb, I_XOR_Evqp_Gvqp, I_XOR_Gb_Eb, I_XOR_Gvqp_Evqp, I_XOR_acc_AL_Ib, I_XOR_acc_eAX_Ivds, PR_36, I_AAA, 
	// 38
	I_CMP_Eb_Gb, I_CMP_Evqp_Gvqp, I_CMP_Gb_Eb, I_CMP_Gvqp_Evqp, I_CMP_acc_AL_Ib, I_CMP_acc_eAX_Ivds, PR_3e, I_AAS, 
	// 40
	I_INC_eAX, I_INC_eCX, I_INC_eDX, I_INC_eBX, I_INC_eSP, I_INC_eBP, I_INC_eSI, I_INC_eDI, 
	// 48
	I_DEC_eAX, I_DEC_eCX, I_DEC_eDX, I_DEC_eBX, I_DEC_eSP, I_DEC_eBP, I_DEC_eSI, I_DEC_eDI, 
	// 50
	I_PUSH_eAX, I_PUSH_eCX, I_PUSH_eDX, I_PUSH_eBX, I_PUSH_eSP, I_PUSH_eBP, I_PUSH_eSI, I_PUSH_eDI, 
	// 58
	I_POP_eAX, I_POP_eCX, I_POP_eDX, I_POP_eBX, I_POP_eSP, I_POP_eBP, I_POP_eSI, I_POP_eDI, 
	// 60
	I_PUSHA, I_POPA, I_BOUND_Gv_Ma, I_ARPL_Ew_Gw, PR_64, PR_65, ST_66, PR_67, 
	// 68
	I_PUSH_Ivs, I_IMUL_Gvqp_Evqp_Ivds, I_PUSH_Ibss, I_IMUL_Gvqp_Evqp_Ibs, I_INS_Yb_DX, I_INS_Yw_DX, I_OUTS_DX_Xb, I_OUTS_DX_Xw, 
	// 70
	I_JO_Jbs, I_JNO_Jbs, I_JB_Jbs, I_JNB_Jbs, I_JZ_Jbs, I_JNZ_Jbs, I_JBE_Jbs, I_JNBE_Jbs, 
	// 78
	I_JS_Jbs, I_JNS_Jbs, I_JP_Jbs, I_JNP_Jbs, I_JL_Jbs, I_JNL_Jbs, I_JLE_Jbs, I_JNLE_Jbs, 
	// 80
	ST_80, ST_81, ST_82, ST_83, I_TEST_Eb_Gb, I_TEST_Evqp_Gvqp, I_XCHG_Gb_Eb, I_XCHG_Gvqp_Evqp, 
	// 88
	I_MOV_Eb_Gb, I_MOV_Evqp_Gvqp, I_MOV_Gb_Eb, I_MOV_Gvqp_Evqp, I_MOV_Mw_Sw, I_LEA_Gvqp_M, I_MOV_Sw_Ew, ST_8f, 
	// 90
	I_XCHG_acc_eAX_eAX, I_XCHG_acc_eCX_eAX, I_XCHG_acc_eDX_eAX, I_XCHG_acc_eBX_eAX, I_XCHG_acc_eSP_eAX, I_XCHG_acc_eBP_eAX, I_XCHG_acc_eSI_eAX, I_XCHG_acc_eDI_eAX, 
	// 98
	I_CBW, I_CWD, I_CALLF_Ap, I_FWAIT, I_PUSHF, I_POPF, I_SAHF, I_LAHF, 
	// A0
	I_MOV_AL_Ob, I_MOV_eAX_Ovqp, I_MOV_Ob_AL, I_MOV_Ovqp_eAX, I_MOVS_Yb_Xb, I_MOVS_Yw_Xw, I_CMPS_Yb_Xb, I_CMPS_Yw_Xw, 
	// A8
	I_TEST_acc_AL_Ib, I_TEST_acc_eAX_Ivds, I_STOS_Yb, I_STOS_Yw, I_LODS_Xb, I_LODS_Xw, I_SCAS_Yb, I_SCAS_Yw, 
	// B0
	I_MOV_AL_Ib, I_MOV_CL_Ib, I_MOV_DL_Ib, I_MOV_BL_Ib, I_MOV_AH_Ib, I_MOV_CH_Ib, I_MOV_DH_Ib, I_MOV_BH_Ib, 
	// B8
	I_MOV_eAX_Ivqp, I_MOV_eCX_Ivqp, I_MOV_eDX_Ivqp, I_MOV_eBX_Ivqp, I_MOV_eSP_Ivqp, I_MOV_eBP_Ivqp, I_MOV_eSI_Ivqp, I_MOV_eDI_Ivqp, 
	// C0
	ST_c0, ST_c1, I_RETN_Iw, I_RETN, I_LES_Gv_Mp, I_LDS_Gv_Mp, ST_c6, ST_c7, 
	// C8
	I_ENTER_Iw_Ib, I_LEAVE, I_RETF_Iw, I_RETF, I_INT_I, I_INT_Ib, I_INTO, I_IRET, 
	// D0
	ST_d0, ST_d1, ST_d2, ST_d3, I_AMX_Ib, I_ADX_Ib, I_ILLEGAL, I_XLAT_BBb, 
	// D8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E0
	I_LOOPNZ_Jbs, I_LOOPZ_Jbs, I_LOOP_Jbs, I_JCXZ_Jbs, I_IN_AL_Ib, I_IN_eAX_Ib, I_OUT_Ib_AL, I_OUT_Ib_eAX, 
	// E8
	I_CALL_Jvds, I_JMP_Jvds, I_JMPF_Ap, I_JMP_Jbs, I_IN_AL_DX, I_IN_eAX_DX, I_OUT_DX_AL, I_OUT_DX_eAX, 
	// F0
	PR_f0, I_ILLEGAL, ST_f2, ST_f3, I_HLT, I_CMC, ST_f6, ST_f7, 
	// F8
	I_CLC, I_STC, I_CLI, I_STI_delaysint_cond, I_CLD, I_STD, ST_fe, ST_ff, 
};
const OpState CpuRunnerX86::table_0f[] = {
	// 00
	ST_0f_00, ST_0f_01, I_LAR_Gvqp_Mw, I_LSL_Gvqp_Mw, I_ILLEGAL, I_ILLEGAL, I_CLTS, I_ILLEGAL, 
	// 08
	I_INVD_serial, I_WBINVD_serial, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 10
	I_MOVUPS_Vps_Wps, I_MOVUPS_Wps_Vps, I_MOVHLPS_Vq_Uq, I_MOVLPS_Mq_Vq, I_UNPCKLPS_Vps_Wq, I_UNPCKHPS_Vps_Wq, I_MOVLHPS_Vq_Uq, I_MOVHPS_Mq_Vq, 
	// 18
	ST_0f_18, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, ST_0f_1f, 
	// 20
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 28
	I_MOVAPS_Vps_Wps, I_MOVAPS_Wps_Vps, I_CVTPI2PS_Vps_Qpi, I_MOVNTPS_Mps_Vps, I_CVTTPS2PI_Ppi_Wpsq, I_CVTPS2PI_Ppi_Wpsq, I_UCOMISS_Vss_Wss, I_COMISS_Vss_Wss, 
	// 30
	I_WRMSR_serial, I_RDTSC, I_RDMSR, I_RDPMC, I_SYSENTER, I_SYSEXIT, I_ILLEGAL, I_GETSEC, 
	// 38
	ST_0f_38, I_ILLEGAL, ST_0f_3a, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 40
	I_CMOVO_Gvqp_Evqp, I_CMOVNO_Gvqp_Evqp, I_CMOVB_Gvqp_Evqp, I_CMOVNB_Gvqp_Evqp, I_CMOVZ_Gvqp_Evqp, I_CMOVNZ_Gvqp_Evqp, I_CMOVBE_Gvqp_Evqp, I_CMOVNBE_Gvqp_Evqp, 
	// 48
	I_CMOVS_Gvqp_Evqp, I_CMOVNS_Gvqp_Evqp, I_CMOVP_Gvqp_Evqp, I_CMOVNP_Gvqp_Evqp, I_CMOVL_Gvqp_Evqp, I_CMOVNL_Gvqp_Evqp, I_CMOVLE_Gvqp_Evqp, I_CMOVNLE_Gvqp_Evqp, 
	// 50
	I_MOVMSKPS_Gdqp_Ups, I_SQRTPS_Vps_Wps, I_RSQRTPS_Vps_Wps, I_RCPPS_Vps_Wps, I_ANDPS_Vps_Wps, I_ANDNPS_Vps_Wps, I_ORPS_Vps_Wps, I_XORPS_Vps_Wps, 
	// 58
	I_ADDPS_Vps_Wps, I_MULPS_Vps_Wps, I_CVTPS2PD_Vpd_Wps, I_CVTDQ2PS_Vps_Wdq, I_SUBPS_Vps_Wps, I_MINPS_Vps_Wps, I_DIVPS_Vps_Wps, I_MAXPS_Vps_Wps, 
	// 60
	I_PUNPCKLBW_Pq_Qd, I_PUNPCKLWD_Pq_Qd, I_PUNPCKLDQ_Pq_Qd, I_PACKSSWB_Pq_Qd, I_PCMPGTB_Pq_Qd, I_PCMPGTW_Pq_Qd, I_PCMPGTD_Pq_Qd, I_PACKUSWB_Pq_Qq, 
	// 68
	I_PUNPCKHBW_Pq_Qq, I_PUNPCKHWD_Pq_Qq, I_PUNPCKHDQ_Pq_Qq, I_PACKSSDW_Pq_Qq, I_ILLEGAL, I_ILLEGAL, I_MOVD_Pq_Ed, I_MOVQ_Pq_Qq, 
	// 70
	I_PSHUFW_Pq_Qq_Ib, ST_0f_71, ST_0f_72, ST_0f_73, I_PCMPEQB_Pq_Qq, I_PCMPEQW_Pq_Qq, I_PCMPEQD_Pq_Qq, I_EMMS, 
	// 78
	I_VMREAD_Ed_Gd, I_VMWRITE_Gd_Ed, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_MOVD_Ed_Pq, I_MOVQ_Qq_Pq, 
	// 80
	I_JO_Jvds, I_JNO_Jvds, I_JB_Jvds, I_JNB_Jvds, I_JZ_Jvds, I_JNZ_Jvds, I_JBE_Jvds, I_JNBE_Jvds, 
	// 88
	I_JS_Jvds, I_JNS_Jvds, I_JP_Jvds, I_JNP_Jvds, I_JL_Jvds, I_JNL_Jvds, I_JLE_Jvds, I_JNLE_Jvds, 
	// 90
	ST_0f_90, ST_0f_91, ST_0f_92, ST_0f_93, ST_0f_94, ST_0f_95, ST_0f_96, ST_0f_97, 
	// 98
	ST_0f_98, ST_0f_99, ST_0f_9a, ST_0f_9b, ST_0f_9c, ST_0f_9d, ST_0f_9e, ST_0f_9f, 
	// A0
	I_PUSH_FS, I_POP_FS, I_CPUID_serial, I_BT_Evqp_Gvqp, I_SHLD_Evqp_Gvqp_Ib, I_SHLD_Evqp_Gvqp_CL, I_ILLEGAL, I_ILLEGAL, 
	// A8
	I_PUSH_GS, I_POP_GS, I_RSM, I_BTS_Evqp_Gvqp, I_SHRD_Evqp_Gvqp_Ib, I_SHRD_Evqp_Gvqp_CL, ST_0f_ae, I_IMUL_Gvqp_Evqp, 
	// B0
	I_CMPXCHG_Eb_Gb, I_CMPXCHG_Evqp_Gvqp, I_LSS_Gvqp_Mptp, I_BTR_Evqp_Gvqp, I_LFS_Gvqp_Mptp, I_LGS_Gvqp_Mptp, I_MOVZX_Gvqp_Eb, I_MOVZX_Gvqp_Ew, 
	// B8
	I_ILLEGAL, I_ILLEGAL, ST_0f_ba, I_BTC_Evqp_Gvqp, I_BSF_Gvqp_Evqp, I_BSR_Gvqp_Evqp, I_MOVSX_Gvqp_Eb, I_MOVSX_Gvqp_Ew, 
	// C0
	I_XADD_Eb_Gb, I_XADD_Evqp_Gvqp, I_CMPPS_Vps_Wps_Ib, I_MOVNTI_Mdqp_Gdqp, I_PINSRW_Pq_Rdqp_Ib, I_PEXTRW_Gdqp_Nq_Ib, I_SHUFPS_Vps_Wps_Ib, ST_0f_c7, 
	// C8
	I_BSWAP_eAX, I_BSWAP_eCX, I_BSWAP_eDX, I_BSWAP_eBX, I_BSWAP_eSP, I_BSWAP_eBP, I_BSWAP_eSI, I_BSWAP_eDI, 
	// D0
	I_ILLEGAL, I_PSRLW_Pq_Qq, I_PSRLD_Pq_Qq, I_PSRLQ_Pq_Qq, I_PADDQ_Pq_Qq, I_PMULLW_Pq_Qq, I_ILLEGAL, I_PMOVMSKB_Gdqp_Nq, 
	// D8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E0
	I_PAVGB_Pq_Qq, I_PSRAW_Pq_Qq, I_PSRAD_Pq_Qq, I_PAVGW_Pq_Qq, I_PMULHUW_Pq_Qq, I_PMULHW_Pq_Qq, I_ILLEGAL, I_MOVNTQ_Mq_Pq, 
	// E8
	I_PSUBSB_Pq_Qq, I_PSUBSW_Pq_Qq, I_PMINSW_Pq_Qq, I_POR_Pq_Qq, I_PADDSB_Pq_Qq, I_PADDSW_Pq_Qq, I_PMAXSW_Pq_Qq, I_PXOR_Pq_Qq, 
	// F0
	I_ILLEGAL, I_PSLLW_Pq_Qq, I_PSLLD_Pq_Qq, I_PSLLQ_Pq_Qq, I_PMULUDQ_Pq_Qq, I_PMADDWD_Pq_Qd, I_PSADBW_Pq_Qq, I_MASKMOVQ_Pq_Nq, 
	// F8
	I_PSUBB_Pq_Qq, I_PSUBW_Pq_Qq, I_PSUBD_Pq_Qq, I_PSUBQ_Pq_Qq, I_PADDB_Pq_Qq, I_PADDW_Pq_Qq, I_PADDD_Pq_Qq, I_ILLEGAL, 
};
const OpState CpuRunnerX86::table_0f_00[] = {
	// 00
	I_SLDT_Mw, I_SLDT_Mw, I_SLDT_Mw, I_SLDT_Mw, I_SLDT_Mw, I_SLDT_Mw, I_SLDT_Mw, I_SLDT_Mw, 
	// 08
	I_STR_Mw, I_STR_Mw, I_STR_Mw, I_STR_Mw, I_STR_Mw, I_STR_Mw, I_STR_Mw, I_STR_Mw, 
	// 10
	I_LLDT_serial_Ew, I_LLDT_serial_Ew, I_LLDT_serial_Ew, I_LLDT_serial_Ew, I_LLDT_serial_Ew, I_LLDT_serial_Ew, I_LLDT_serial_Ew, I_LLDT_serial_Ew, 
	// 18
	I_LTR_serial_Ew, I_LTR_serial_Ew, I_LTR_serial_Ew, I_LTR_serial_Ew, I_LTR_serial_Ew, I_LTR_serial_Ew, I_LTR_serial_Ew, I_LTR_serial_Ew, 
	// 20
	I_VERR_Ew, I_VERR_Ew, I_VERR_Ew, I_VERR_Ew, I_VERR_Ew, I_VERR_Ew, I_VERR_Ew, I_VERR_Ew, 
	// 28
	I_VERW_Ew, I_VERW_Ew, I_VERW_Ew, I_VERW_Ew, I_VERW_Ew, I_VERW_Ew, I_VERW_Ew, I_VERW_Ew, 
	// 30
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 38
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 40
	I_SLDT_Mw, I_SLDT_Mw, I_SLDT_Mw, I_SLDT_Mw, I_SLDT_Mw, I_SLDT_Mw, I_SLDT_Mw, I_SLDT_Mw, 
	// 48
	I_STR_Mw, I_STR_Mw, I_STR_Mw, I_STR_Mw, I_STR_Mw, I_STR_Mw, I_STR_Mw, I_STR_Mw, 
	// 50
	I_LLDT_serial_Ew, I_LLDT_serial_Ew, I_LLDT_serial_Ew, I_LLDT_serial_Ew, I_LLDT_serial_Ew, I_LLDT_serial_Ew, I_LLDT_serial_Ew, I_LLDT_serial_Ew, 
	// 58
	I_LTR_serial_Ew, I_LTR_serial_Ew, I_LTR_serial_Ew, I_LTR_serial_Ew, I_LTR_serial_Ew, I_LTR_serial_Ew, I_LTR_serial_Ew, I_LTR_serial_Ew, 
	// 60
	I_VERR_Ew, I_VERR_Ew, I_VERR_Ew, I_VERR_Ew, I_VERR_Ew, I_VERR_Ew, I_VERR_Ew, I_VERR_Ew, 
	// 68
	I_VERW_Ew, I_VERW_Ew, I_VERW_Ew, I_VERW_Ew, I_VERW_Ew, I_VERW_Ew, I_VERW_Ew, I_VERW_Ew, 
	// 70
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 78
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 80
	I_SLDT_Mw, I_SLDT_Mw, I_SLDT_Mw, I_SLDT_Mw, I_SLDT_Mw, I_SLDT_Mw, I_SLDT_Mw, I_SLDT_Mw, 
	// 88
	I_STR_Mw, I_STR_Mw, I_STR_Mw, I_STR_Mw, I_STR_Mw, I_STR_Mw, I_STR_Mw, I_STR_Mw, 
	// 90
	I_LLDT_serial_Ew, I_LLDT_serial_Ew, I_LLDT_serial_Ew, I_LLDT_serial_Ew, I_LLDT_serial_Ew, I_LLDT_serial_Ew, I_LLDT_serial_Ew, I_LLDT_serial_Ew, 
	// 98
	I_LTR_serial_Ew, I_LTR_serial_Ew, I_LTR_serial_Ew, I_LTR_serial_Ew, I_LTR_serial_Ew, I_LTR_serial_Ew, I_LTR_serial_Ew, I_LTR_serial_Ew, 
	// A0
	I_VERR_Ew, I_VERR_Ew, I_VERR_Ew, I_VERR_Ew, I_VERR_Ew, I_VERR_Ew, I_VERR_Ew, I_VERR_Ew, 
	// A8
	I_VERW_Ew, I_VERW_Ew, I_VERW_Ew, I_VERW_Ew, I_VERW_Ew, I_VERW_Ew, I_VERW_Ew, I_VERW_Ew, 
	// B0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// C0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// C8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D0
	I_LLDT_serial_Ew, I_LLDT_serial_Ew, I_LLDT_serial_Ew, I_LLDT_serial_Ew, I_LLDT_serial_Ew, I_LLDT_serial_Ew, I_LLDT_serial_Ew, I_LLDT_serial_Ew, 
	// D8
	I_LTR_serial_Ew, I_LTR_serial_Ew, I_LTR_serial_Ew, I_LTR_serial_Ew, I_LTR_serial_Ew, I_LTR_serial_Ew, I_LTR_serial_Ew, I_LTR_serial_Ew, 
	// E0
	I_VERR_Ew, I_VERR_Ew, I_VERR_Ew, I_VERR_Ew, I_VERR_Ew, I_VERR_Ew, I_VERR_Ew, I_VERR_Ew, 
	// E8
	I_VERW_Ew, I_VERW_Ew, I_VERW_Ew, I_VERW_Ew, I_VERW_Ew, I_VERW_Ew, I_VERW_Ew, I_VERW_Ew, 
	// F0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
};
const OpState CpuRunnerX86::table_0f_01[] = {
	// 00
	I_SGDT_Ms, I_SGDT_Ms, I_SGDT_Ms, I_SGDT_Ms, I_SGDT_Ms, I_SGDT_Ms, I_SGDT_Ms, I_SGDT_Ms, 
	// 08
	I_SIDT_Ms, I_SIDT_Ms, I_SIDT_Ms, I_SIDT_Ms, I_SIDT_Ms, I_SIDT_Ms, I_SIDT_Ms, I_SIDT_Ms, 
	// 10
	I_LGDT_serial_Ms, I_LGDT_serial_Ms, I_LGDT_serial_Ms, I_LGDT_serial_Ms, I_LGDT_serial_Ms, I_LGDT_serial_Ms, I_LGDT_serial_Ms, I_LGDT_serial_Ms, 
	// 18
	I_LIDT_serial_Ms, I_LIDT_serial_Ms, I_LIDT_serial_Ms, I_LIDT_serial_Ms, I_LIDT_serial_Ms, I_LIDT_serial_Ms, I_LIDT_serial_Ms, I_LIDT_serial_Ms, 
	// 20
	I_SMSW_Mw, I_SMSW_Mw, I_SMSW_Mw, I_SMSW_Mw, I_SMSW_Mw, I_SMSW_Mw, I_SMSW_Mw, I_SMSW_Mw, 
	// 28
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 30
	I_LMSW_serial_Ew, I_LMSW_serial_Ew, I_LMSW_serial_Ew, I_LMSW_serial_Ew, I_LMSW_serial_Ew, I_LMSW_serial_Ew, I_LMSW_serial_Ew, I_LMSW_serial_Ew, 
	// 38
	I_INVLPG_serial_M, I_INVLPG_serial_M, I_INVLPG_serial_M, I_INVLPG_serial_M, I_INVLPG_serial_M, I_INVLPG_serial_M, I_INVLPG_serial_M, I_INVLPG_serial_M, 
	// 40
	I_SGDT_Ms, I_SGDT_Ms, I_SGDT_Ms, I_SGDT_Ms, I_SGDT_Ms, I_SGDT_Ms, I_SGDT_Ms, I_SGDT_Ms, 
	// 48
	I_SIDT_Ms, I_SIDT_Ms, I_SIDT_Ms, I_SIDT_Ms, I_SIDT_Ms, I_SIDT_Ms, I_SIDT_Ms, I_SIDT_Ms, 
	// 50
	I_LGDT_serial_Ms, I_LGDT_serial_Ms, I_LGDT_serial_Ms, I_LGDT_serial_Ms, I_LGDT_serial_Ms, I_LGDT_serial_Ms, I_LGDT_serial_Ms, I_LGDT_serial_Ms, 
	// 58
	I_LIDT_serial_Ms, I_LIDT_serial_Ms, I_LIDT_serial_Ms, I_LIDT_serial_Ms, I_LIDT_serial_Ms, I_LIDT_serial_Ms, I_LIDT_serial_Ms, I_LIDT_serial_Ms, 
	// 60
	I_SMSW_Mw, I_SMSW_Mw, I_SMSW_Mw, I_SMSW_Mw, I_SMSW_Mw, I_SMSW_Mw, I_SMSW_Mw, I_SMSW_Mw, 
	// 68
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 70
	I_LMSW_serial_Ew, I_LMSW_serial_Ew, I_LMSW_serial_Ew, I_LMSW_serial_Ew, I_LMSW_serial_Ew, I_LMSW_serial_Ew, I_LMSW_serial_Ew, I_LMSW_serial_Ew, 
	// 78
	I_INVLPG_serial_M, I_INVLPG_serial_M, I_INVLPG_serial_M, I_INVLPG_serial_M, I_INVLPG_serial_M, I_INVLPG_serial_M, I_INVLPG_serial_M, I_INVLPG_serial_M, 
	// 80
	I_SGDT_Ms, I_SGDT_Ms, I_SGDT_Ms, I_SGDT_Ms, I_SGDT_Ms, I_SGDT_Ms, I_SGDT_Ms, I_SGDT_Ms, 
	// 88
	I_SIDT_Ms, I_SIDT_Ms, I_SIDT_Ms, I_SIDT_Ms, I_SIDT_Ms, I_SIDT_Ms, I_SIDT_Ms, I_SIDT_Ms, 
	// 90
	I_LGDT_serial_Ms, I_LGDT_serial_Ms, I_LGDT_serial_Ms, I_LGDT_serial_Ms, I_LGDT_serial_Ms, I_LGDT_serial_Ms, I_LGDT_serial_Ms, I_LGDT_serial_Ms, 
	// 98
	I_LIDT_serial_Ms, I_LIDT_serial_Ms, I_LIDT_serial_Ms, I_LIDT_serial_Ms, I_LIDT_serial_Ms, I_LIDT_serial_Ms, I_LIDT_serial_Ms, I_LIDT_serial_Ms, 
	// A0
	I_SMSW_Mw, I_SMSW_Mw, I_SMSW_Mw, I_SMSW_Mw, I_SMSW_Mw, I_SMSW_Mw, I_SMSW_Mw, I_SMSW_Mw, 
	// A8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B0
	I_LMSW_serial_Ew, I_LMSW_serial_Ew, I_LMSW_serial_Ew, I_LMSW_serial_Ew, I_LMSW_serial_Ew, I_LMSW_serial_Ew, I_LMSW_serial_Ew, I_LMSW_serial_Ew, 
	// B8
	I_INVLPG_serial_M, I_INVLPG_serial_M, I_INVLPG_serial_M, I_INVLPG_serial_M, I_INVLPG_serial_M, I_INVLPG_serial_M, I_INVLPG_serial_M, I_INVLPG_serial_M, 
	// C0
	I_ILLEGAL, I_VMCALL, I_VMLAUNCH, I_VMRESUME, I_VMXOFF, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// C8
	I_MONITOR, I_MWAIT, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D0
	I_XGETBV, I_XSETBV, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F0
	I_LMSW_serial_Ew, I_LMSW_serial_Ew, I_LMSW_serial_Ew, I_LMSW_serial_Ew, I_LMSW_serial_Ew, I_LMSW_serial_Ew, I_LMSW_serial_Ew, I_LMSW_serial_Ew, 
	// F8
	I_ILLEGAL, I_RDTSCP_serial, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
};
const OpState CpuRunnerX86::table_0f_18[] = {
	// 00
	I_PREFETCHNTA_Mb, I_PREFETCHNTA_Mb, I_PREFETCHNTA_Mb, I_PREFETCHNTA_Mb, I_PREFETCHNTA_Mb, I_PREFETCHNTA_Mb, I_PREFETCHNTA_Mb, I_PREFETCHNTA_Mb, 
	// 08
	I_PREFETCHT0_Mb, I_PREFETCHT0_Mb, I_PREFETCHT0_Mb, I_PREFETCHT0_Mb, I_PREFETCHT0_Mb, I_PREFETCHT0_Mb, I_PREFETCHT0_Mb, I_PREFETCHT0_Mb, 
	// 10
	I_PREFETCHT1_Mb, I_PREFETCHT1_Mb, I_PREFETCHT1_Mb, I_PREFETCHT1_Mb, I_PREFETCHT1_Mb, I_PREFETCHT1_Mb, I_PREFETCHT1_Mb, I_PREFETCHT1_Mb, 
	// 18
	I_PREFETCHT2_Mb, I_PREFETCHT2_Mb, I_PREFETCHT2_Mb, I_PREFETCHT2_Mb, I_PREFETCHT2_Mb, I_PREFETCHT2_Mb, I_PREFETCHT2_Mb, I_PREFETCHT2_Mb, 
	// 20
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 28
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 30
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 38
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 40
	I_PREFETCHNTA_Mb, I_PREFETCHNTA_Mb, I_PREFETCHNTA_Mb, I_PREFETCHNTA_Mb, I_PREFETCHNTA_Mb, I_PREFETCHNTA_Mb, I_PREFETCHNTA_Mb, I_PREFETCHNTA_Mb, 
	// 48
	I_PREFETCHT0_Mb, I_PREFETCHT0_Mb, I_PREFETCHT0_Mb, I_PREFETCHT0_Mb, I_PREFETCHT0_Mb, I_PREFETCHT0_Mb, I_PREFETCHT0_Mb, I_PREFETCHT0_Mb, 
	// 50
	I_PREFETCHT1_Mb, I_PREFETCHT1_Mb, I_PREFETCHT1_Mb, I_PREFETCHT1_Mb, I_PREFETCHT1_Mb, I_PREFETCHT1_Mb, I_PREFETCHT1_Mb, I_PREFETCHT1_Mb, 
	// 58
	I_PREFETCHT2_Mb, I_PREFETCHT2_Mb, I_PREFETCHT2_Mb, I_PREFETCHT2_Mb, I_PREFETCHT2_Mb, I_PREFETCHT2_Mb, I_PREFETCHT2_Mb, I_PREFETCHT2_Mb, 
	// 60
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 68
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 70
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 78
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 80
	I_PREFETCHNTA_Mb, I_PREFETCHNTA_Mb, I_PREFETCHNTA_Mb, I_PREFETCHNTA_Mb, I_PREFETCHNTA_Mb, I_PREFETCHNTA_Mb, I_PREFETCHNTA_Mb, I_PREFETCHNTA_Mb, 
	// 88
	I_PREFETCHT0_Mb, I_PREFETCHT0_Mb, I_PREFETCHT0_Mb, I_PREFETCHT0_Mb, I_PREFETCHT0_Mb, I_PREFETCHT0_Mb, I_PREFETCHT0_Mb, I_PREFETCHT0_Mb, 
	// 90
	I_PREFETCHT1_Mb, I_PREFETCHT1_Mb, I_PREFETCHT1_Mb, I_PREFETCHT1_Mb, I_PREFETCHT1_Mb, I_PREFETCHT1_Mb, I_PREFETCHT1_Mb, I_PREFETCHT1_Mb, 
	// 98
	I_PREFETCHT2_Mb, I_PREFETCHT2_Mb, I_PREFETCHT2_Mb, I_PREFETCHT2_Mb, I_PREFETCHT2_Mb, I_PREFETCHT2_Mb, I_PREFETCHT2_Mb, I_PREFETCHT2_Mb, 
	// A0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// A8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// C0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// C8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
};
const OpState CpuRunnerX86::table_0f_1f[] = {
	// 00
	I_NOP_Ev, I_NOP_Ev, I_NOP_Ev, I_NOP_Ev, I_NOP_Ev, I_NOP_Ev, I_NOP_Ev, I_NOP_Ev, 
	// 08
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 10
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 18
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 20
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 28
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 30
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 38
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 40
	I_NOP_Ev, I_NOP_Ev, I_NOP_Ev, I_NOP_Ev, I_NOP_Ev, I_NOP_Ev, I_NOP_Ev, I_NOP_Ev, 
	// 48
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 50
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 58
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 60
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 68
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 70
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 78
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 80
	I_NOP_Ev, I_NOP_Ev, I_NOP_Ev, I_NOP_Ev, I_NOP_Ev, I_NOP_Ev, I_NOP_Ev, I_NOP_Ev, 
	// 88
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 90
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 98
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// A0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// A8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// C0
	I_NOP_Ev, I_NOP_Ev, I_NOP_Ev, I_NOP_Ev, I_NOP_Ev, I_NOP_Ev, I_NOP_Ev, I_NOP_Ev, 
	// C8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
};
const OpState CpuRunnerX86::table_0f_38[] = {
	// 00
	I_PSHUFB_Pq_Qq, I_PHADDW_Pq_Qq, I_PHADDD_Pq_Qq, I_PHADDSW_Pq_Qq, I_PMADDUBSW_Pq_Qq, I_PHSUBW_Pq_Qq, I_PHSUBD_Pq_Qq, I_PHSUBSW_Pq_Qq, 
	// 08
	I_PSIGNB_Pq_Qq, I_PSIGNW_Pq_Qq, I_PSIGND_Pq_Qq, I_PMULHRSW_Pq_Qq, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 10
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 18
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_PABSB_Pq_Qq, I_PABSW_Pq_Qq, I_PABSD_Pq_Qq, I_ILLEGAL, 
	// 20
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 28
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 30
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 38
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 40
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 48
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 50
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 58
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 60
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 68
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 70
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 78
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 80
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 88
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 90
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 98
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// A0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// A8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// C0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// C8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F0
	I_MOVBE_Gvqp_Mvqp, I_MOVBE_Mvqp_Gvqp, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
};
const OpState CpuRunnerX86::table_0f_3a[] = {
	// 00
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 08
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_PALIGNR_Pq_Qq, 
	// 10
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 18
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 20
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 28
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 30
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 38
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 40
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 48
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 50
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 58
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 60
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 68
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 70
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 78
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 80
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 88
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 90
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 98
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// A0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// A8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// C0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// C8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
};
const OpState CpuRunnerX86::table_0f_71[] = {
	// 00
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 08
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 10
	I_PSRLW_Nq_Ib, I_PSRLW_Nq_Ib, I_PSRLW_Nq_Ib, I_PSRLW_Nq_Ib, I_PSRLW_Nq_Ib, I_PSRLW_Nq_Ib, I_PSRLW_Nq_Ib, I_PSRLW_Nq_Ib, 
	// 18
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 20
	I_PSRAW_Nq_Ib, I_PSRAW_Nq_Ib, I_PSRAW_Nq_Ib, I_PSRAW_Nq_Ib, I_PSRAW_Nq_Ib, I_PSRAW_Nq_Ib, I_PSRAW_Nq_Ib, I_PSRAW_Nq_Ib, 
	// 28
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 30
	I_PSLLW_Nq_Ib, I_PSLLW_Nq_Ib, I_PSLLW_Nq_Ib, I_PSLLW_Nq_Ib, I_PSLLW_Nq_Ib, I_PSLLW_Nq_Ib, I_PSLLW_Nq_Ib, I_PSLLW_Nq_Ib, 
	// 38
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 40
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 48
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 50
	I_PSRLW_Nq_Ib, I_PSRLW_Nq_Ib, I_PSRLW_Nq_Ib, I_PSRLW_Nq_Ib, I_PSRLW_Nq_Ib, I_PSRLW_Nq_Ib, I_PSRLW_Nq_Ib, I_PSRLW_Nq_Ib, 
	// 58
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 60
	I_PSRAW_Nq_Ib, I_PSRAW_Nq_Ib, I_PSRAW_Nq_Ib, I_PSRAW_Nq_Ib, I_PSRAW_Nq_Ib, I_PSRAW_Nq_Ib, I_PSRAW_Nq_Ib, I_PSRAW_Nq_Ib, 
	// 68
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 70
	I_PSLLW_Nq_Ib, I_PSLLW_Nq_Ib, I_PSLLW_Nq_Ib, I_PSLLW_Nq_Ib, I_PSLLW_Nq_Ib, I_PSLLW_Nq_Ib, I_PSLLW_Nq_Ib, I_PSLLW_Nq_Ib, 
	// 78
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 80
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 88
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 90
	I_PSRLW_Nq_Ib, I_PSRLW_Nq_Ib, I_PSRLW_Nq_Ib, I_PSRLW_Nq_Ib, I_PSRLW_Nq_Ib, I_PSRLW_Nq_Ib, I_PSRLW_Nq_Ib, I_PSRLW_Nq_Ib, 
	// 98
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// A0
	I_PSRAW_Nq_Ib, I_PSRAW_Nq_Ib, I_PSRAW_Nq_Ib, I_PSRAW_Nq_Ib, I_PSRAW_Nq_Ib, I_PSRAW_Nq_Ib, I_PSRAW_Nq_Ib, I_PSRAW_Nq_Ib, 
	// A8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B0
	I_PSLLW_Nq_Ib, I_PSLLW_Nq_Ib, I_PSLLW_Nq_Ib, I_PSLLW_Nq_Ib, I_PSLLW_Nq_Ib, I_PSLLW_Nq_Ib, I_PSLLW_Nq_Ib, I_PSLLW_Nq_Ib, 
	// B8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// C0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// C8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D0
	I_PSRLW_Nq_Ib, I_PSRLW_Nq_Ib, I_PSRLW_Nq_Ib, I_PSRLW_Nq_Ib, I_PSRLW_Nq_Ib, I_PSRLW_Nq_Ib, I_PSRLW_Nq_Ib, I_PSRLW_Nq_Ib, 
	// D8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E0
	I_PSRAW_Nq_Ib, I_PSRAW_Nq_Ib, I_PSRAW_Nq_Ib, I_PSRAW_Nq_Ib, I_PSRAW_Nq_Ib, I_PSRAW_Nq_Ib, I_PSRAW_Nq_Ib, I_PSRAW_Nq_Ib, 
	// E8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F0
	I_PSLLW_Nq_Ib, I_PSLLW_Nq_Ib, I_PSLLW_Nq_Ib, I_PSLLW_Nq_Ib, I_PSLLW_Nq_Ib, I_PSLLW_Nq_Ib, I_PSLLW_Nq_Ib, I_PSLLW_Nq_Ib, 
	// F8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
};
const OpState CpuRunnerX86::table_0f_72[] = {
	// 00
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 08
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 10
	I_PSRLD_Nq_Ib, I_PSRLD_Nq_Ib, I_PSRLD_Nq_Ib, I_PSRLD_Nq_Ib, I_PSRLD_Nq_Ib, I_PSRLD_Nq_Ib, I_PSRLD_Nq_Ib, I_PSRLD_Nq_Ib, 
	// 18
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 20
	I_PSRAD_Nq_Ib, I_PSRAD_Nq_Ib, I_PSRAD_Nq_Ib, I_PSRAD_Nq_Ib, I_PSRAD_Nq_Ib, I_PSRAD_Nq_Ib, I_PSRAD_Nq_Ib, I_PSRAD_Nq_Ib, 
	// 28
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 30
	I_PSLLD_Nq_Ib, I_PSLLD_Nq_Ib, I_PSLLD_Nq_Ib, I_PSLLD_Nq_Ib, I_PSLLD_Nq_Ib, I_PSLLD_Nq_Ib, I_PSLLD_Nq_Ib, I_PSLLD_Nq_Ib, 
	// 38
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 40
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 48
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 50
	I_PSRLD_Nq_Ib, I_PSRLD_Nq_Ib, I_PSRLD_Nq_Ib, I_PSRLD_Nq_Ib, I_PSRLD_Nq_Ib, I_PSRLD_Nq_Ib, I_PSRLD_Nq_Ib, I_PSRLD_Nq_Ib, 
	// 58
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 60
	I_PSRAD_Nq_Ib, I_PSRAD_Nq_Ib, I_PSRAD_Nq_Ib, I_PSRAD_Nq_Ib, I_PSRAD_Nq_Ib, I_PSRAD_Nq_Ib, I_PSRAD_Nq_Ib, I_PSRAD_Nq_Ib, 
	// 68
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 70
	I_PSLLD_Nq_Ib, I_PSLLD_Nq_Ib, I_PSLLD_Nq_Ib, I_PSLLD_Nq_Ib, I_PSLLD_Nq_Ib, I_PSLLD_Nq_Ib, I_PSLLD_Nq_Ib, I_PSLLD_Nq_Ib, 
	// 78
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 80
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 88
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 90
	I_PSRLD_Nq_Ib, I_PSRLD_Nq_Ib, I_PSRLD_Nq_Ib, I_PSRLD_Nq_Ib, I_PSRLD_Nq_Ib, I_PSRLD_Nq_Ib, I_PSRLD_Nq_Ib, I_PSRLD_Nq_Ib, 
	// 98
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// A0
	I_PSRAD_Nq_Ib, I_PSRAD_Nq_Ib, I_PSRAD_Nq_Ib, I_PSRAD_Nq_Ib, I_PSRAD_Nq_Ib, I_PSRAD_Nq_Ib, I_PSRAD_Nq_Ib, I_PSRAD_Nq_Ib, 
	// A8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B0
	I_PSLLD_Nq_Ib, I_PSLLD_Nq_Ib, I_PSLLD_Nq_Ib, I_PSLLD_Nq_Ib, I_PSLLD_Nq_Ib, I_PSLLD_Nq_Ib, I_PSLLD_Nq_Ib, I_PSLLD_Nq_Ib, 
	// B8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// C0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// C8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D0
	I_PSRLD_Nq_Ib, I_PSRLD_Nq_Ib, I_PSRLD_Nq_Ib, I_PSRLD_Nq_Ib, I_PSRLD_Nq_Ib, I_PSRLD_Nq_Ib, I_PSRLD_Nq_Ib, I_PSRLD_Nq_Ib, 
	// D8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E0
	I_PSRAD_Nq_Ib, I_PSRAD_Nq_Ib, I_PSRAD_Nq_Ib, I_PSRAD_Nq_Ib, I_PSRAD_Nq_Ib, I_PSRAD_Nq_Ib, I_PSRAD_Nq_Ib, I_PSRAD_Nq_Ib, 
	// E8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F0
	I_PSLLD_Nq_Ib, I_PSLLD_Nq_Ib, I_PSLLD_Nq_Ib, I_PSLLD_Nq_Ib, I_PSLLD_Nq_Ib, I_PSLLD_Nq_Ib, I_PSLLD_Nq_Ib, I_PSLLD_Nq_Ib, 
	// F8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
};
const OpState CpuRunnerX86::table_0f_73[] = {
	// 00
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 08
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 10
	I_PSRLQ_Nq_Ib, I_PSRLQ_Nq_Ib, I_PSRLQ_Nq_Ib, I_PSRLQ_Nq_Ib, I_PSRLQ_Nq_Ib, I_PSRLQ_Nq_Ib, I_PSRLQ_Nq_Ib, I_PSRLQ_Nq_Ib, 
	// 18
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 20
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 28
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 30
	I_PSLLQ_Nq_Ib, I_PSLLQ_Nq_Ib, I_PSLLQ_Nq_Ib, I_PSLLQ_Nq_Ib, I_PSLLQ_Nq_Ib, I_PSLLQ_Nq_Ib, I_PSLLQ_Nq_Ib, I_PSLLQ_Nq_Ib, 
	// 38
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 40
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 48
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 50
	I_PSRLQ_Nq_Ib, I_PSRLQ_Nq_Ib, I_PSRLQ_Nq_Ib, I_PSRLQ_Nq_Ib, I_PSRLQ_Nq_Ib, I_PSRLQ_Nq_Ib, I_PSRLQ_Nq_Ib, I_PSRLQ_Nq_Ib, 
	// 58
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 60
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 68
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 70
	I_PSLLQ_Nq_Ib, I_PSLLQ_Nq_Ib, I_PSLLQ_Nq_Ib, I_PSLLQ_Nq_Ib, I_PSLLQ_Nq_Ib, I_PSLLQ_Nq_Ib, I_PSLLQ_Nq_Ib, I_PSLLQ_Nq_Ib, 
	// 78
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 80
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 88
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 90
	I_PSRLQ_Nq_Ib, I_PSRLQ_Nq_Ib, I_PSRLQ_Nq_Ib, I_PSRLQ_Nq_Ib, I_PSRLQ_Nq_Ib, I_PSRLQ_Nq_Ib, I_PSRLQ_Nq_Ib, I_PSRLQ_Nq_Ib, 
	// 98
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// A0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// A8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B0
	I_PSLLQ_Nq_Ib, I_PSLLQ_Nq_Ib, I_PSLLQ_Nq_Ib, I_PSLLQ_Nq_Ib, I_PSLLQ_Nq_Ib, I_PSLLQ_Nq_Ib, I_PSLLQ_Nq_Ib, I_PSLLQ_Nq_Ib, 
	// B8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// C0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// C8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D0
	I_PSRLQ_Nq_Ib, I_PSRLQ_Nq_Ib, I_PSRLQ_Nq_Ib, I_PSRLQ_Nq_Ib, I_PSRLQ_Nq_Ib, I_PSRLQ_Nq_Ib, I_PSRLQ_Nq_Ib, I_PSRLQ_Nq_Ib, 
	// D8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F0
	I_PSLLQ_Nq_Ib, I_PSLLQ_Nq_Ib, I_PSLLQ_Nq_Ib, I_PSLLQ_Nq_Ib, I_PSLLQ_Nq_Ib, I_PSLLQ_Nq_Ib, I_PSLLQ_Nq_Ib, I_PSLLQ_Nq_Ib, 
	// F8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
};
const OpState CpuRunnerX86::table_0f_90[] = {
	// 00
	I_SETO_Eb, I_SETO_Eb, I_SETO_Eb, I_SETO_Eb, I_SETO_Eb, I_SETO_Eb, I_SETO_Eb, I_SETO_Eb, 
	// 08
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 10
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 18
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 20
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 28
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 30
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 38
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 40
	I_SETO_Eb, I_SETO_Eb, I_SETO_Eb, I_SETO_Eb, I_SETO_Eb, I_SETO_Eb, I_SETO_Eb, I_SETO_Eb, 
	// 48
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 50
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 58
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 60
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 68
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 70
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 78
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 80
	I_SETO_Eb, I_SETO_Eb, I_SETO_Eb, I_SETO_Eb, I_SETO_Eb, I_SETO_Eb, I_SETO_Eb, I_SETO_Eb, 
	// 88
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 90
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 98
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// A0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// A8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// C0
	I_SETO_Eb, I_SETO_Eb, I_SETO_Eb, I_SETO_Eb, I_SETO_Eb, I_SETO_Eb, I_SETO_Eb, I_SETO_Eb, 
	// C8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
};
const OpState CpuRunnerX86::table_0f_91[] = {
	// 00
	I_SETNO_Eb, I_SETNO_Eb, I_SETNO_Eb, I_SETNO_Eb, I_SETNO_Eb, I_SETNO_Eb, I_SETNO_Eb, I_SETNO_Eb, 
	// 08
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 10
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 18
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 20
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 28
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 30
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 38
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 40
	I_SETNO_Eb, I_SETNO_Eb, I_SETNO_Eb, I_SETNO_Eb, I_SETNO_Eb, I_SETNO_Eb, I_SETNO_Eb, I_SETNO_Eb, 
	// 48
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 50
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 58
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 60
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 68
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 70
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 78
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 80
	I_SETNO_Eb, I_SETNO_Eb, I_SETNO_Eb, I_SETNO_Eb, I_SETNO_Eb, I_SETNO_Eb, I_SETNO_Eb, I_SETNO_Eb, 
	// 88
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 90
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 98
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// A0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// A8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// C0
	I_SETNO_Eb, I_SETNO_Eb, I_SETNO_Eb, I_SETNO_Eb, I_SETNO_Eb, I_SETNO_Eb, I_SETNO_Eb, I_SETNO_Eb, 
	// C8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
};
const OpState CpuRunnerX86::table_0f_92[] = {
	// 00
	I_SETB_Eb, I_SETB_Eb, I_SETB_Eb, I_SETB_Eb, I_SETB_Eb, I_SETB_Eb, I_SETB_Eb, I_SETB_Eb, 
	// 08
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 10
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 18
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 20
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 28
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 30
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 38
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 40
	I_SETB_Eb, I_SETB_Eb, I_SETB_Eb, I_SETB_Eb, I_SETB_Eb, I_SETB_Eb, I_SETB_Eb, I_SETB_Eb, 
	// 48
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 50
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 58
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 60
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 68
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 70
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 78
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 80
	I_SETB_Eb, I_SETB_Eb, I_SETB_Eb, I_SETB_Eb, I_SETB_Eb, I_SETB_Eb, I_SETB_Eb, I_SETB_Eb, 
	// 88
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 90
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 98
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// A0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// A8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// C0
	I_SETB_Eb, I_SETB_Eb, I_SETB_Eb, I_SETB_Eb, I_SETB_Eb, I_SETB_Eb, I_SETB_Eb, I_SETB_Eb, 
	// C8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
};
const OpState CpuRunnerX86::table_0f_93[] = {
	// 00
	I_SETNB_Eb, I_SETNB_Eb, I_SETNB_Eb, I_SETNB_Eb, I_SETNB_Eb, I_SETNB_Eb, I_SETNB_Eb, I_SETNB_Eb, 
	// 08
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 10
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 18
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 20
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 28
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 30
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 38
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 40
	I_SETNB_Eb, I_SETNB_Eb, I_SETNB_Eb, I_SETNB_Eb, I_SETNB_Eb, I_SETNB_Eb, I_SETNB_Eb, I_SETNB_Eb, 
	// 48
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 50
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 58
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 60
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 68
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 70
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 78
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 80
	I_SETNB_Eb, I_SETNB_Eb, I_SETNB_Eb, I_SETNB_Eb, I_SETNB_Eb, I_SETNB_Eb, I_SETNB_Eb, I_SETNB_Eb, 
	// 88
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 90
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 98
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// A0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// A8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// C0
	I_SETNB_Eb, I_SETNB_Eb, I_SETNB_Eb, I_SETNB_Eb, I_SETNB_Eb, I_SETNB_Eb, I_SETNB_Eb, I_SETNB_Eb, 
	// C8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
};
const OpState CpuRunnerX86::table_0f_94[] = {
	// 00
	I_SETZ_Eb, I_SETZ_Eb, I_SETZ_Eb, I_SETZ_Eb, I_SETZ_Eb, I_SETZ_Eb, I_SETZ_Eb, I_SETZ_Eb, 
	// 08
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 10
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 18
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 20
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 28
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 30
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 38
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 40
	I_SETZ_Eb, I_SETZ_Eb, I_SETZ_Eb, I_SETZ_Eb, I_SETZ_Eb, I_SETZ_Eb, I_SETZ_Eb, I_SETZ_Eb, 
	// 48
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 50
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 58
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 60
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 68
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 70
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 78
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 80
	I_SETZ_Eb, I_SETZ_Eb, I_SETZ_Eb, I_SETZ_Eb, I_SETZ_Eb, I_SETZ_Eb, I_SETZ_Eb, I_SETZ_Eb, 
	// 88
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 90
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 98
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// A0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// A8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// C0
	I_SETZ_Eb, I_SETZ_Eb, I_SETZ_Eb, I_SETZ_Eb, I_SETZ_Eb, I_SETZ_Eb, I_SETZ_Eb, I_SETZ_Eb, 
	// C8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
};
const OpState CpuRunnerX86::table_0f_95[] = {
	// 00
	I_SETNZ_Eb, I_SETNZ_Eb, I_SETNZ_Eb, I_SETNZ_Eb, I_SETNZ_Eb, I_SETNZ_Eb, I_SETNZ_Eb, I_SETNZ_Eb, 
	// 08
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 10
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 18
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 20
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 28
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 30
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 38
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 40
	I_SETNZ_Eb, I_SETNZ_Eb, I_SETNZ_Eb, I_SETNZ_Eb, I_SETNZ_Eb, I_SETNZ_Eb, I_SETNZ_Eb, I_SETNZ_Eb, 
	// 48
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 50
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 58
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 60
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 68
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 70
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 78
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 80
	I_SETNZ_Eb, I_SETNZ_Eb, I_SETNZ_Eb, I_SETNZ_Eb, I_SETNZ_Eb, I_SETNZ_Eb, I_SETNZ_Eb, I_SETNZ_Eb, 
	// 88
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 90
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 98
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// A0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// A8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// C0
	I_SETNZ_Eb, I_SETNZ_Eb, I_SETNZ_Eb, I_SETNZ_Eb, I_SETNZ_Eb, I_SETNZ_Eb, I_SETNZ_Eb, I_SETNZ_Eb, 
	// C8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
};
const OpState CpuRunnerX86::table_0f_96[] = {
	// 00
	I_SETBE_Eb, I_SETBE_Eb, I_SETBE_Eb, I_SETBE_Eb, I_SETBE_Eb, I_SETBE_Eb, I_SETBE_Eb, I_SETBE_Eb, 
	// 08
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 10
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 18
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 20
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 28
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 30
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 38
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 40
	I_SETBE_Eb, I_SETBE_Eb, I_SETBE_Eb, I_SETBE_Eb, I_SETBE_Eb, I_SETBE_Eb, I_SETBE_Eb, I_SETBE_Eb, 
	// 48
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 50
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 58
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 60
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 68
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 70
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 78
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 80
	I_SETBE_Eb, I_SETBE_Eb, I_SETBE_Eb, I_SETBE_Eb, I_SETBE_Eb, I_SETBE_Eb, I_SETBE_Eb, I_SETBE_Eb, 
	// 88
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 90
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 98
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// A0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// A8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// C0
	I_SETBE_Eb, I_SETBE_Eb, I_SETBE_Eb, I_SETBE_Eb, I_SETBE_Eb, I_SETBE_Eb, I_SETBE_Eb, I_SETBE_Eb, 
	// C8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
};
const OpState CpuRunnerX86::table_0f_97[] = {
	// 00
	I_SETNBE_Eb, I_SETNBE_Eb, I_SETNBE_Eb, I_SETNBE_Eb, I_SETNBE_Eb, I_SETNBE_Eb, I_SETNBE_Eb, I_SETNBE_Eb, 
	// 08
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 10
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 18
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 20
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 28
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 30
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 38
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 40
	I_SETNBE_Eb, I_SETNBE_Eb, I_SETNBE_Eb, I_SETNBE_Eb, I_SETNBE_Eb, I_SETNBE_Eb, I_SETNBE_Eb, I_SETNBE_Eb, 
	// 48
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 50
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 58
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 60
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 68
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 70
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 78
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 80
	I_SETNBE_Eb, I_SETNBE_Eb, I_SETNBE_Eb, I_SETNBE_Eb, I_SETNBE_Eb, I_SETNBE_Eb, I_SETNBE_Eb, I_SETNBE_Eb, 
	// 88
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 90
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 98
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// A0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// A8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// C0
	I_SETNBE_Eb, I_SETNBE_Eb, I_SETNBE_Eb, I_SETNBE_Eb, I_SETNBE_Eb, I_SETNBE_Eb, I_SETNBE_Eb, I_SETNBE_Eb, 
	// C8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
};
const OpState CpuRunnerX86::table_0f_98[] = {
	// 00
	I_SETS_Eb, I_SETS_Eb, I_SETS_Eb, I_SETS_Eb, I_SETS_Eb, I_SETS_Eb, I_SETS_Eb, I_SETS_Eb, 
	// 08
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 10
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 18
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 20
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 28
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 30
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 38
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 40
	I_SETS_Eb, I_SETS_Eb, I_SETS_Eb, I_SETS_Eb, I_SETS_Eb, I_SETS_Eb, I_SETS_Eb, I_SETS_Eb, 
	// 48
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 50
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 58
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 60
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 68
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 70
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 78
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 80
	I_SETS_Eb, I_SETS_Eb, I_SETS_Eb, I_SETS_Eb, I_SETS_Eb, I_SETS_Eb, I_SETS_Eb, I_SETS_Eb, 
	// 88
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 90
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 98
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// A0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// A8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// C0
	I_SETS_Eb, I_SETS_Eb, I_SETS_Eb, I_SETS_Eb, I_SETS_Eb, I_SETS_Eb, I_SETS_Eb, I_SETS_Eb, 
	// C8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
};
const OpState CpuRunnerX86::table_0f_99[] = {
	// 00
	I_SETNS_Eb, I_SETNS_Eb, I_SETNS_Eb, I_SETNS_Eb, I_SETNS_Eb, I_SETNS_Eb, I_SETNS_Eb, I_SETNS_Eb, 
	// 08
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 10
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 18
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 20
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 28
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 30
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 38
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 40
	I_SETNS_Eb, I_SETNS_Eb, I_SETNS_Eb, I_SETNS_Eb, I_SETNS_Eb, I_SETNS_Eb, I_SETNS_Eb, I_SETNS_Eb, 
	// 48
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 50
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 58
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 60
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 68
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 70
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 78
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 80
	I_SETNS_Eb, I_SETNS_Eb, I_SETNS_Eb, I_SETNS_Eb, I_SETNS_Eb, I_SETNS_Eb, I_SETNS_Eb, I_SETNS_Eb, 
	// 88
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 90
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 98
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// A0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// A8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// C0
	I_SETNS_Eb, I_SETNS_Eb, I_SETNS_Eb, I_SETNS_Eb, I_SETNS_Eb, I_SETNS_Eb, I_SETNS_Eb, I_SETNS_Eb, 
	// C8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
};
const OpState CpuRunnerX86::table_0f_9a[] = {
	// 00
	I_SETP_Eb, I_SETP_Eb, I_SETP_Eb, I_SETP_Eb, I_SETP_Eb, I_SETP_Eb, I_SETP_Eb, I_SETP_Eb, 
	// 08
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 10
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 18
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 20
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 28
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 30
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 38
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 40
	I_SETP_Eb, I_SETP_Eb, I_SETP_Eb, I_SETP_Eb, I_SETP_Eb, I_SETP_Eb, I_SETP_Eb, I_SETP_Eb, 
	// 48
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 50
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 58
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 60
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 68
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 70
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 78
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 80
	I_SETP_Eb, I_SETP_Eb, I_SETP_Eb, I_SETP_Eb, I_SETP_Eb, I_SETP_Eb, I_SETP_Eb, I_SETP_Eb, 
	// 88
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 90
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 98
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// A0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// A8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// C0
	I_SETP_Eb, I_SETP_Eb, I_SETP_Eb, I_SETP_Eb, I_SETP_Eb, I_SETP_Eb, I_SETP_Eb, I_SETP_Eb, 
	// C8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
};
const OpState CpuRunnerX86::table_0f_9b[] = {
	// 00
	I_SETNP_Eb, I_SETNP_Eb, I_SETNP_Eb, I_SETNP_Eb, I_SETNP_Eb, I_SETNP_Eb, I_SETNP_Eb, I_SETNP_Eb, 
	// 08
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 10
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 18
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 20
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 28
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 30
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 38
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 40
	I_SETNP_Eb, I_SETNP_Eb, I_SETNP_Eb, I_SETNP_Eb, I_SETNP_Eb, I_SETNP_Eb, I_SETNP_Eb, I_SETNP_Eb, 
	// 48
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 50
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 58
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 60
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 68
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 70
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 78
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 80
	I_SETNP_Eb, I_SETNP_Eb, I_SETNP_Eb, I_SETNP_Eb, I_SETNP_Eb, I_SETNP_Eb, I_SETNP_Eb, I_SETNP_Eb, 
	// 88
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 90
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 98
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// A0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// A8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// C0
	I_SETNP_Eb, I_SETNP_Eb, I_SETNP_Eb, I_SETNP_Eb, I_SETNP_Eb, I_SETNP_Eb, I_SETNP_Eb, I_SETNP_Eb, 
	// C8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
};
const OpState CpuRunnerX86::table_0f_9c[] = {
	// 00
	I_SETL_Eb, I_SETL_Eb, I_SETL_Eb, I_SETL_Eb, I_SETL_Eb, I_SETL_Eb, I_SETL_Eb, I_SETL_Eb, 
	// 08
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 10
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 18
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 20
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 28
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 30
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 38
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 40
	I_SETL_Eb, I_SETL_Eb, I_SETL_Eb, I_SETL_Eb, I_SETL_Eb, I_SETL_Eb, I_SETL_Eb, I_SETL_Eb, 
	// 48
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 50
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 58
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 60
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 68
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 70
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 78
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 80
	I_SETL_Eb, I_SETL_Eb, I_SETL_Eb, I_SETL_Eb, I_SETL_Eb, I_SETL_Eb, I_SETL_Eb, I_SETL_Eb, 
	// 88
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 90
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 98
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// A0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// A8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// C0
	I_SETL_Eb, I_SETL_Eb, I_SETL_Eb, I_SETL_Eb, I_SETL_Eb, I_SETL_Eb, I_SETL_Eb, I_SETL_Eb, 
	// C8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
};
const OpState CpuRunnerX86::table_0f_9d[] = {
	// 00
	I_SETNL_Eb, I_SETNL_Eb, I_SETNL_Eb, I_SETNL_Eb, I_SETNL_Eb, I_SETNL_Eb, I_SETNL_Eb, I_SETNL_Eb, 
	// 08
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 10
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 18
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 20
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 28
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 30
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 38
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 40
	I_SETNL_Eb, I_SETNL_Eb, I_SETNL_Eb, I_SETNL_Eb, I_SETNL_Eb, I_SETNL_Eb, I_SETNL_Eb, I_SETNL_Eb, 
	// 48
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 50
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 58
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 60
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 68
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 70
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 78
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 80
	I_SETNL_Eb, I_SETNL_Eb, I_SETNL_Eb, I_SETNL_Eb, I_SETNL_Eb, I_SETNL_Eb, I_SETNL_Eb, I_SETNL_Eb, 
	// 88
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 90
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 98
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// A0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// A8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// C0
	I_SETNL_Eb, I_SETNL_Eb, I_SETNL_Eb, I_SETNL_Eb, I_SETNL_Eb, I_SETNL_Eb, I_SETNL_Eb, I_SETNL_Eb, 
	// C8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
};
const OpState CpuRunnerX86::table_0f_9e[] = {
	// 00
	I_SETLE_Eb, I_SETLE_Eb, I_SETLE_Eb, I_SETLE_Eb, I_SETLE_Eb, I_SETLE_Eb, I_SETLE_Eb, I_SETLE_Eb, 
	// 08
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 10
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 18
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 20
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 28
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 30
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 38
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 40
	I_SETLE_Eb, I_SETLE_Eb, I_SETLE_Eb, I_SETLE_Eb, I_SETLE_Eb, I_SETLE_Eb, I_SETLE_Eb, I_SETLE_Eb, 
	// 48
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 50
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 58
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 60
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 68
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 70
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 78
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 80
	I_SETLE_Eb, I_SETLE_Eb, I_SETLE_Eb, I_SETLE_Eb, I_SETLE_Eb, I_SETLE_Eb, I_SETLE_Eb, I_SETLE_Eb, 
	// 88
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 90
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 98
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// A0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// A8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// C0
	I_SETLE_Eb, I_SETLE_Eb, I_SETLE_Eb, I_SETLE_Eb, I_SETLE_Eb, I_SETLE_Eb, I_SETLE_Eb, I_SETLE_Eb, 
	// C8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
};
const OpState CpuRunnerX86::table_0f_9f[] = {
	// 00
	I_SETNLE_Eb, I_SETNLE_Eb, I_SETNLE_Eb, I_SETNLE_Eb, I_SETNLE_Eb, I_SETNLE_Eb, I_SETNLE_Eb, I_SETNLE_Eb, 
	// 08
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 10
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 18
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 20
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 28
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 30
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 38
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 40
	I_SETNLE_Eb, I_SETNLE_Eb, I_SETNLE_Eb, I_SETNLE_Eb, I_SETNLE_Eb, I_SETNLE_Eb, I_SETNLE_Eb, I_SETNLE_Eb, 
	// 48
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 50
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 58
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 60
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 68
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 70
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 78
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 80
	I_SETNLE_Eb, I_SETNLE_Eb, I_SETNLE_Eb, I_SETNLE_Eb, I_SETNLE_Eb, I_SETNLE_Eb, I_SETNLE_Eb, I_SETNLE_Eb, 
	// 88
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 90
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 98
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// A0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// A8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// C0
	I_SETNLE_Eb, I_SETNLE_Eb, I_SETNLE_Eb, I_SETNLE_Eb, I_SETNLE_Eb, I_SETNLE_Eb, I_SETNLE_Eb, I_SETNLE_Eb, 
	// C8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
};
const OpState CpuRunnerX86::table_0f_ae[] = {
	// 00
	I_FXSAVE_Mstx, I_FXSAVE_Mstx, I_FXSAVE_Mstx, I_FXSAVE_Mstx, I_FXSAVE_Mstx, I_FXSAVE_Mstx, I_FXSAVE_Mstx, I_FXSAVE_Mstx, 
	// 08
	I_FXRSTOR_Mstx, I_FXRSTOR_Mstx, I_FXRSTOR_Mstx, I_FXRSTOR_Mstx, I_FXRSTOR_Mstx, I_FXRSTOR_Mstx, I_FXRSTOR_Mstx, I_FXRSTOR_Mstx, 
	// 10
	I_LDMXCSR_Md, I_LDMXCSR_Md, I_LDMXCSR_Md, I_LDMXCSR_Md, I_LDMXCSR_Md, I_LDMXCSR_Md, I_LDMXCSR_Md, I_LDMXCSR_Md, 
	// 18
	I_STMXCSR_Md, I_STMXCSR_Md, I_STMXCSR_Md, I_STMXCSR_Md, I_STMXCSR_Md, I_STMXCSR_Md, I_STMXCSR_Md, I_STMXCSR_Md, 
	// 20
	I_XSAVE_M, I_XSAVE_M, I_XSAVE_M, I_XSAVE_M, I_XSAVE_M, I_XSAVE_M, I_XSAVE_M, I_XSAVE_M, 
	// 28
	I_XRSTOR_M, I_XRSTOR_M, I_XRSTOR_M, I_XRSTOR_M, I_XRSTOR_M, I_XRSTOR_M, I_XRSTOR_M, I_XRSTOR_M, 
	// 30
	I_MFENCE, I_MFENCE, I_MFENCE, I_MFENCE, I_MFENCE, I_MFENCE, I_MFENCE, I_MFENCE, 
	// 38
	I_CLFLUSH_Mb, I_CLFLUSH_Mb, I_CLFLUSH_Mb, I_CLFLUSH_Mb, I_CLFLUSH_Mb, I_CLFLUSH_Mb, I_CLFLUSH_Mb, I_CLFLUSH_Mb, 
	// 40
	I_FXSAVE_Mstx, I_FXSAVE_Mstx, I_FXSAVE_Mstx, I_FXSAVE_Mstx, I_FXSAVE_Mstx, I_FXSAVE_Mstx, I_FXSAVE_Mstx, I_FXSAVE_Mstx, 
	// 48
	I_FXRSTOR_Mstx, I_FXRSTOR_Mstx, I_FXRSTOR_Mstx, I_FXRSTOR_Mstx, I_FXRSTOR_Mstx, I_FXRSTOR_Mstx, I_FXRSTOR_Mstx, I_FXRSTOR_Mstx, 
	// 50
	I_LDMXCSR_Md, I_LDMXCSR_Md, I_LDMXCSR_Md, I_LDMXCSR_Md, I_LDMXCSR_Md, I_LDMXCSR_Md, I_LDMXCSR_Md, I_LDMXCSR_Md, 
	// 58
	I_STMXCSR_Md, I_STMXCSR_Md, I_STMXCSR_Md, I_STMXCSR_Md, I_STMXCSR_Md, I_STMXCSR_Md, I_STMXCSR_Md, I_STMXCSR_Md, 
	// 60
	I_XSAVE_M, I_XSAVE_M, I_XSAVE_M, I_XSAVE_M, I_XSAVE_M, I_XSAVE_M, I_XSAVE_M, I_XSAVE_M, 
	// 68
	I_XRSTOR_M, I_XRSTOR_M, I_XRSTOR_M, I_XRSTOR_M, I_XRSTOR_M, I_XRSTOR_M, I_XRSTOR_M, I_XRSTOR_M, 
	// 70
	I_MFENCE, I_MFENCE, I_MFENCE, I_MFENCE, I_MFENCE, I_MFENCE, I_MFENCE, I_MFENCE, 
	// 78
	I_CLFLUSH_Mb, I_CLFLUSH_Mb, I_CLFLUSH_Mb, I_CLFLUSH_Mb, I_CLFLUSH_Mb, I_CLFLUSH_Mb, I_CLFLUSH_Mb, I_CLFLUSH_Mb, 
	// 80
	I_FXSAVE_Mstx, I_FXSAVE_Mstx, I_FXSAVE_Mstx, I_FXSAVE_Mstx, I_FXSAVE_Mstx, I_FXSAVE_Mstx, I_FXSAVE_Mstx, I_FXSAVE_Mstx, 
	// 88
	I_FXRSTOR_Mstx, I_FXRSTOR_Mstx, I_FXRSTOR_Mstx, I_FXRSTOR_Mstx, I_FXRSTOR_Mstx, I_FXRSTOR_Mstx, I_FXRSTOR_Mstx, I_FXRSTOR_Mstx, 
	// 90
	I_LDMXCSR_Md, I_LDMXCSR_Md, I_LDMXCSR_Md, I_LDMXCSR_Md, I_LDMXCSR_Md, I_LDMXCSR_Md, I_LDMXCSR_Md, I_LDMXCSR_Md, 
	// 98
	I_STMXCSR_Md, I_STMXCSR_Md, I_STMXCSR_Md, I_STMXCSR_Md, I_STMXCSR_Md, I_STMXCSR_Md, I_STMXCSR_Md, I_STMXCSR_Md, 
	// A0
	I_XSAVE_M, I_XSAVE_M, I_XSAVE_M, I_XSAVE_M, I_XSAVE_M, I_XSAVE_M, I_XSAVE_M, I_XSAVE_M, 
	// A8
	I_XRSTOR_M, I_XRSTOR_M, I_XRSTOR_M, I_XRSTOR_M, I_XRSTOR_M, I_XRSTOR_M, I_XRSTOR_M, I_XRSTOR_M, 
	// B0
	I_MFENCE, I_MFENCE, I_MFENCE, I_MFENCE, I_MFENCE, I_MFENCE, I_MFENCE, I_MFENCE, 
	// B8
	I_CLFLUSH_Mb, I_CLFLUSH_Mb, I_CLFLUSH_Mb, I_CLFLUSH_Mb, I_CLFLUSH_Mb, I_CLFLUSH_Mb, I_CLFLUSH_Mb, I_CLFLUSH_Mb, 
	// C0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// C8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E8
	I_LFENCE, I_LFENCE, I_LFENCE, I_LFENCE, I_LFENCE, I_LFENCE, I_LFENCE, I_LFENCE, 
	// F0
	I_MFENCE, I_MFENCE, I_MFENCE, I_MFENCE, I_MFENCE, I_MFENCE, I_MFENCE, I_MFENCE, 
	// F8
	I_SFENCE, I_SFENCE, I_SFENCE, I_SFENCE, I_SFENCE, I_SFENCE, I_SFENCE, I_SFENCE, 
};
const OpState CpuRunnerX86::table_0f_ba[] = {
	// 00
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 08
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 10
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 18
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 20
	I_BT_Evqp_Ib, I_BT_Evqp_Ib, I_BT_Evqp_Ib, I_BT_Evqp_Ib, I_BT_Evqp_Ib, I_BT_Evqp_Ib, I_BT_Evqp_Ib, I_BT_Evqp_Ib, 
	// 28
	I_BTS_Evqp_Ib, I_BTS_Evqp_Ib, I_BTS_Evqp_Ib, I_BTS_Evqp_Ib, I_BTS_Evqp_Ib, I_BTS_Evqp_Ib, I_BTS_Evqp_Ib, I_BTS_Evqp_Ib, 
	// 30
	I_BTR_Evqp_Ib, I_BTR_Evqp_Ib, I_BTR_Evqp_Ib, I_BTR_Evqp_Ib, I_BTR_Evqp_Ib, I_BTR_Evqp_Ib, I_BTR_Evqp_Ib, I_BTR_Evqp_Ib, 
	// 38
	I_BTC_Evqp_Ib, I_BTC_Evqp_Ib, I_BTC_Evqp_Ib, I_BTC_Evqp_Ib, I_BTC_Evqp_Ib, I_BTC_Evqp_Ib, I_BTC_Evqp_Ib, I_BTC_Evqp_Ib, 
	// 40
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 48
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 50
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 58
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 60
	I_BT_Evqp_Ib, I_BT_Evqp_Ib, I_BT_Evqp_Ib, I_BT_Evqp_Ib, I_BT_Evqp_Ib, I_BT_Evqp_Ib, I_BT_Evqp_Ib, I_BT_Evqp_Ib, 
	// 68
	I_BTS_Evqp_Ib, I_BTS_Evqp_Ib, I_BTS_Evqp_Ib, I_BTS_Evqp_Ib, I_BTS_Evqp_Ib, I_BTS_Evqp_Ib, I_BTS_Evqp_Ib, I_BTS_Evqp_Ib, 
	// 70
	I_BTR_Evqp_Ib, I_BTR_Evqp_Ib, I_BTR_Evqp_Ib, I_BTR_Evqp_Ib, I_BTR_Evqp_Ib, I_BTR_Evqp_Ib, I_BTR_Evqp_Ib, I_BTR_Evqp_Ib, 
	// 78
	I_BTC_Evqp_Ib, I_BTC_Evqp_Ib, I_BTC_Evqp_Ib, I_BTC_Evqp_Ib, I_BTC_Evqp_Ib, I_BTC_Evqp_Ib, I_BTC_Evqp_Ib, I_BTC_Evqp_Ib, 
	// 80
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 88
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 90
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 98
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// A0
	I_BT_Evqp_Ib, I_BT_Evqp_Ib, I_BT_Evqp_Ib, I_BT_Evqp_Ib, I_BT_Evqp_Ib, I_BT_Evqp_Ib, I_BT_Evqp_Ib, I_BT_Evqp_Ib, 
	// A8
	I_BTS_Evqp_Ib, I_BTS_Evqp_Ib, I_BTS_Evqp_Ib, I_BTS_Evqp_Ib, I_BTS_Evqp_Ib, I_BTS_Evqp_Ib, I_BTS_Evqp_Ib, I_BTS_Evqp_Ib, 
	// B0
	I_BTR_Evqp_Ib, I_BTR_Evqp_Ib, I_BTR_Evqp_Ib, I_BTR_Evqp_Ib, I_BTR_Evqp_Ib, I_BTR_Evqp_Ib, I_BTR_Evqp_Ib, I_BTR_Evqp_Ib, 
	// B8
	I_BTC_Evqp_Ib, I_BTC_Evqp_Ib, I_BTC_Evqp_Ib, I_BTC_Evqp_Ib, I_BTC_Evqp_Ib, I_BTC_Evqp_Ib, I_BTC_Evqp_Ib, I_BTC_Evqp_Ib, 
	// C0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// C8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E0
	I_BT_Evqp_Ib, I_BT_Evqp_Ib, I_BT_Evqp_Ib, I_BT_Evqp_Ib, I_BT_Evqp_Ib, I_BT_Evqp_Ib, I_BT_Evqp_Ib, I_BT_Evqp_Ib, 
	// E8
	I_BTS_Evqp_Ib, I_BTS_Evqp_Ib, I_BTS_Evqp_Ib, I_BTS_Evqp_Ib, I_BTS_Evqp_Ib, I_BTS_Evqp_Ib, I_BTS_Evqp_Ib, I_BTS_Evqp_Ib, 
	// F0
	I_BTR_Evqp_Ib, I_BTR_Evqp_Ib, I_BTR_Evqp_Ib, I_BTR_Evqp_Ib, I_BTR_Evqp_Ib, I_BTR_Evqp_Ib, I_BTR_Evqp_Ib, I_BTR_Evqp_Ib, 
	// F8
	I_BTC_Evqp_Ib, I_BTC_Evqp_Ib, I_BTC_Evqp_Ib, I_BTC_Evqp_Ib, I_BTC_Evqp_Ib, I_BTC_Evqp_Ib, I_BTC_Evqp_Ib, I_BTC_Evqp_Ib, 
};
const OpState CpuRunnerX86::table_0f_c7[] = {
	// 00
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 08
	I_CMPXCHG8B_Mq, I_CMPXCHG8B_Mq, I_CMPXCHG8B_Mq, I_CMPXCHG8B_Mq, I_CMPXCHG8B_Mq, I_CMPXCHG8B_Mq, I_CMPXCHG8B_Mq, I_CMPXCHG8B_Mq, 
	// 10
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 18
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 20
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 28
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 30
	I_VMPTRLD_Mq, I_VMPTRLD_Mq, I_VMPTRLD_Mq, I_VMPTRLD_Mq, I_VMPTRLD_Mq, I_VMPTRLD_Mq, I_VMPTRLD_Mq, I_VMPTRLD_Mq, 
	// 38
	I_VMPTRST_Mq, I_VMPTRST_Mq, I_VMPTRST_Mq, I_VMPTRST_Mq, I_VMPTRST_Mq, I_VMPTRST_Mq, I_VMPTRST_Mq, I_VMPTRST_Mq, 
	// 40
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 48
	I_CMPXCHG8B_Mq, I_CMPXCHG8B_Mq, I_CMPXCHG8B_Mq, I_CMPXCHG8B_Mq, I_CMPXCHG8B_Mq, I_CMPXCHG8B_Mq, I_CMPXCHG8B_Mq, I_CMPXCHG8B_Mq, 
	// 50
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 58
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 60
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 68
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 70
	I_VMPTRLD_Mq, I_VMPTRLD_Mq, I_VMPTRLD_Mq, I_VMPTRLD_Mq, I_VMPTRLD_Mq, I_VMPTRLD_Mq, I_VMPTRLD_Mq, I_VMPTRLD_Mq, 
	// 78
	I_VMPTRST_Mq, I_VMPTRST_Mq, I_VMPTRST_Mq, I_VMPTRST_Mq, I_VMPTRST_Mq, I_VMPTRST_Mq, I_VMPTRST_Mq, I_VMPTRST_Mq, 
	// 80
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 88
	I_CMPXCHG8B_Mq, I_CMPXCHG8B_Mq, I_CMPXCHG8B_Mq, I_CMPXCHG8B_Mq, I_CMPXCHG8B_Mq, I_CMPXCHG8B_Mq, I_CMPXCHG8B_Mq, I_CMPXCHG8B_Mq, 
	// 90
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 98
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// A0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// A8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B0
	I_VMPTRLD_Mq, I_VMPTRLD_Mq, I_VMPTRLD_Mq, I_VMPTRLD_Mq, I_VMPTRLD_Mq, I_VMPTRLD_Mq, I_VMPTRLD_Mq, I_VMPTRLD_Mq, 
	// B8
	I_VMPTRST_Mq, I_VMPTRST_Mq, I_VMPTRST_Mq, I_VMPTRST_Mq, I_VMPTRST_Mq, I_VMPTRST_Mq, I_VMPTRST_Mq, I_VMPTRST_Mq, 
	// C0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// C8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
};
const OpState CpuRunnerX86::table_66[] = {
	// 00
	I_ADD_Eb_Gb, I_ADD_Evqp_Gvqp, I_ADD_Gb_Eb, I_ADD_Gvqp_Evqp, I_ADD_acc_AL_Ib, I_ADD_acc_eAX_Ivds, I_PUSH_ES, I_POP_ES, 
	// 08
	I_OR_Eb_Gb, I_OR_Evqp_Gvqp, I_OR_Gb_Eb, I_OR_Gvqp_Evqp, I_OR_acc_AL_Ib, I_OR_acc_eAX_Ivds, I_PUSH_CS, ST_66_0f, 
	// 10
	I_ADC_Eb_Gb, I_ADC_Evqp_Gvqp, I_ADC_Gb_Eb, I_ADC_Gvqp_Evqp, I_ADC_acc_AL_Ib, I_ADC_acc_eAX_Ivds, I_PUSH_SS, I_POP_delaysint_SS, 
	// 18
	I_SBB_Eb_Gb, I_SBB_Evqp_Gvqp, I_SBB_Gb_Eb, I_SBB_Gvqp_Evqp, I_SBB_acc_AL_Ib, I_SBB_acc_eAX_Ivds, I_PUSH_DS, I_POP_DS, 
	// 20
	I_AND_Eb_Gb, I_AND_Evqp_Gvqp, I_AND_Gb_Eb, I_AND_Gvqp_Evqp, I_AND_acc_AL_Ib, I_AND_acc_eAX_Ivds, PR_26, I_DAA, 
	// 28
	I_SUB_Eb_Gb, I_SUB_Evqp_Gvqp, I_SUB_Gb_Eb, I_SUB_Gvqp_Evqp, I_SUB_acc_AL_Ib, I_SUB_acc_eAX_Ivds, PR_2e, I_DAS, 
	// 30
	I_XOR_Eb_Gb, I_XOR_Evqp_Gvqp, I_XOR_Gb_Eb, I_XOR_Gvqp_Evqp, I_XOR_acc_AL_Ib, I_XOR_acc_eAX_Ivds, PR_36, I_AAA, 
	// 38
	I_CMP_Eb_Gb, I_CMP_Evqp_Gvqp, I_CMP_Gb_Eb, I_CMP_Gvqp_Evqp, I_CMP_acc_AL_Ib, I_CMP_acc_eAX_Ivds, PR_3e, I_AAS, 
	// 40
	I_INC_eAX, I_INC_eCX, I_INC_eDX, I_INC_eBX, I_INC_eSP, I_INC_eBP, I_INC_eSI, I_INC_eDI, 
	// 48
	I_DEC_eAX, I_DEC_eCX, I_DEC_eDX, I_DEC_eBX, I_DEC_eSP, I_DEC_eBP, I_DEC_eSI, I_DEC_eDI, 
	// 50
	I_PUSH_eAX, I_PUSH_eCX, I_PUSH_eDX, I_PUSH_eBX, I_PUSH_eSP, I_PUSH_eBP, I_PUSH_eSI, I_PUSH_eDI, 
	// 58
	I_POP_eAX, I_POP_eCX, I_POP_eDX, I_POP_eBX, I_POP_eSP, I_POP_eBP, I_POP_eSI, I_POP_eDI, 
	// 60
	I_PUSHA, I_POPA, I_BOUND_Gv_Ma, I_ARPL_Ew_Gw, PR_64, PR_65, I_ILLEGAL, PR_67, 
	// 68
	I_PUSH_Ivs, I_IMUL_Gvqp_Evqp_Ivds, I_PUSH_Ibss, I_IMUL_Gvqp_Evqp_Ibs, I_INS_Yb_DX, I_INS_Yw_DX, I_OUTS_DX_Xb, I_OUTS_DX_Xw, 
	// 70
	I_JO_Jbs, I_JNO_Jbs, I_JB_Jbs, I_JNB_Jbs, I_JZ_Jbs, I_JNZ_Jbs, I_JBE_Jbs, I_JNBE_Jbs, 
	// 78
	I_JS_Jbs, I_JNS_Jbs, I_JP_Jbs, I_JNP_Jbs, I_JL_Jbs, I_JNL_Jbs, I_JLE_Jbs, I_JNLE_Jbs, 
	// 80
	ST_80, ST_81, ST_82, ST_83, I_TEST_Eb_Gb, I_TEST_Evqp_Gvqp, I_XCHG_Gb_Eb, I_XCHG_Gvqp_Evqp, 
	// 88
	I_MOV_Eb_Gb, I_MOV_Evqp_Gvqp, I_MOV_Gb_Eb, I_MOV_Gvqp_Evqp, I_MOV_Mw_Sw, I_LEA_Gvqp_M, I_MOV_Sw_Ew, ST_8f, 
	// 90
	I_XCHG_acc_eAX_eAX, I_XCHG_acc_eCX_eAX, I_XCHG_acc_eDX_eAX, I_XCHG_acc_eBX_eAX, I_XCHG_acc_eSP_eAX, I_XCHG_acc_eBP_eAX, I_XCHG_acc_eSI_eAX, I_XCHG_acc_eDI_eAX, 
	// 98
	I_CBW, I_CWD, I_CALLF_Ap, I_FWAIT, I_PUSHF, I_POPF, I_SAHF, I_LAHF, 
	// A0
	I_MOV_AL_Ob, I_MOV_eAX_Ovqp, I_MOV_Ob_AL, I_MOV_Ovqp_eAX, I_MOVS_Yb_Xb, I_MOVS_Yw_Xw, I_CMPS_Yb_Xb, I_CMPS_Yw_Xw, 
	// A8
	I_TEST_acc_AL_Ib, I_TEST_acc_eAX_Ivds, I_STOS_Yb, I_STOS_Yw, I_LODS_Xb, I_LODS_Xw, I_SCAS_Yb, I_SCAS_Yw, 
	// B0
	I_MOV_AL_Ib, I_MOV_CL_Ib, I_MOV_DL_Ib, I_MOV_BL_Ib, I_MOV_AH_Ib, I_MOV_CH_Ib, I_MOV_DH_Ib, I_MOV_BH_Ib, 
	// B8
	I_MOV_eAX_Ivqp, I_MOV_eCX_Ivqp, I_MOV_eDX_Ivqp, I_MOV_eBX_Ivqp, I_MOV_eSP_Ivqp, I_MOV_eBP_Ivqp, I_MOV_eSI_Ivqp, I_MOV_eDI_Ivqp, 
	// C0
	ST_c0, ST_c1, I_RETN_Iw, I_RETN, I_LES_Gv_Mp, I_LDS_Gv_Mp, ST_c6, ST_c7, 
	// C8
	I_ENTER_Iw_Ib, I_LEAVE, I_RETF_Iw, I_RETF, I_INT_I, I_INT_Ib, I_INTO, I_IRET, 
	// D0
	ST_d0, ST_d1, ST_d2, ST_d3, I_AMX_Ib, I_ADX_Ib, I_ILLEGAL, I_XLAT_BBb, 
	// D8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E0
	I_LOOPNZ_Jbs, I_LOOPZ_Jbs, I_LOOP_Jbs, I_JCXZ_Jbs, I_IN_AL_Ib, I_IN_eAX_Ib, I_OUT_Ib_AL, I_OUT_Ib_eAX, 
	// E8
	I_CALL_Jvds, I_JMP_Jvds, I_JMPF_Ap, I_JMP_Jbs, I_IN_AL_DX, I_IN_eAX_DX, I_OUT_DX_AL, I_OUT_DX_eAX, 
	// F0
	PR_f0, I_ILLEGAL, ST_f2, ST_f3, I_HLT, I_CMC, ST_f6, ST_f7, 
	// F8
	I_CLC, I_STC, I_CLI, I_STI_delaysint_cond, I_CLD, I_STD, ST_fe, ST_ff, 
};
const OpState CpuRunnerX86::table_66_0f[] = {
	// 00
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 08
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 10
	I_MOVUPD_Vpd_Wpd, I_MOVUPD_Wpd_Vpd, I_MOVLPD_Vq_Mq, I_MOVLPD_Mq_Vq, I_UNPCKLPD_Vpd_Wpd, I_UNPCKHPD_Vpd_Wpd, I_MOVHPD_Vq_Mq, I_MOVHPD_Mq_Vq, 
	// 18
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 20
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 28
	I_MOVAPD_Vpd_Wpd, I_MOVAPD_Wpd_Vpd, I_CVTPI2PD_Vpd_Qpi, I_MOVNTPD_Mpd_Vpd, I_CVTTPD2PI_Ppi_Wpd, I_CVTPD2PI_Ppi_Wpd, I_UCOMISD_Vsd_Wsd, I_COMISD_Vsd_Wsd, 
	// 30
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 38
	ST_66_0f_38, I_ILLEGAL, ST_66_0f_3a, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 40
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 48
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 50
	I_MOVMSKPD_Gdqp_Upd, I_SQRTPD_Vpd_Wpd, I_ILLEGAL, I_ILLEGAL, I_ANDPD_Vpd_Wpd, I_ANDNPD_Vpd_Wpd, I_ORPD_Vpd_Wpd, I_XORPD_Vpd_Wpd, 
	// 58
	I_ADDPD_Vpd_Wpd, I_MULPD_Vpd_Wpd, I_CVTPD2PS_Vps_Wpd, I_CVTPS2DQ_Vdq_Wps, I_SUBPD_Vpd_Wpd, I_MINPD_Vpd_Wpd, I_DIVPD_Vpd_Wpd, I_MAXPD_Vpd_Wpd, 
	// 60
	I_PUNPCKLBW_Vdq_Wdq, I_PUNPCKLWD_Vdq_Wdq, I_PUNPCKLDQ_Vdq_Wdq, I_PACKSSWB_Vdq_Wdq, I_PCMPGTB_Vdq_Wdq, I_PCMPGTW_Vdq_Wdq, I_PCMPGTD_Vdq_Wdq, I_PACKUSWB_Vdq_Wdq, 
	// 68
	I_PUNPCKHBW_Vdq_Wdq, I_PUNPCKHWD_Vdq_Wdq, I_PUNPCKHDQ_Vdq_Wdq, I_PACKSSDW_Vdq_Wdq, I_PUNPCKLQDQ_Vdq_Wdq, I_PUNPCKHQDQ_Vdq_Wdq, I_MOVD_Vdq_Ed, I_MOVDQA_Vdq_Wdq, 
	// 70
	I_PSHUFD_Vdq_Wdq_Ib, ST_66_0f_71, ST_66_0f_72, ST_66_0f_73, I_PCMPEQB_Vdq_Wdq, I_PCMPEQW_Vdq_Wdq, I_PCMPEQD_Vdq_Wdq, I_ILLEGAL, 
	// 78
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_HADDPD_Vpd_Wpd, I_HSUBPD_Vpd_Wpd, I_MOVD_Ed_Vdq, I_MOVDQA_Wdq_Vdq, 
	// 80
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 88
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 90
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 98
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// A0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// A8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// C0
	I_ILLEGAL, I_ILLEGAL, I_CMPPD_Vpd_Wpd_Ib, I_ILLEGAL, I_PINSRW_Vdq_Rdqp_Ib, I_PEXTRW_Gdqp_Udq_Ib, I_SHUFPD_Vpd_Wpd_Ib, ST_66_0f_c7, 
	// C8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D0
	I_ADDSUBPD_Vpd_Wpd, I_PSRLW_Vdq_Wdq, I_PSRLD_Vdq_Wdq, I_PSRLQ_Vdq_Wdq, I_PADDQ_Vdq_Wdq, I_PMULLW_Vdq_Wdq, I_MOVQ_Wq_Vq, I_PMOVMSKB_Gdqp_Udq, 
	// D8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E0
	I_PAVGB_Vdq_Wdq, I_PSRAW_Vdq_Wdq, I_PSRAD_Vdq_Wdq, I_PAVGW_Vdq_Wdq, I_PMULHUW_Vdq_Wdq, I_PMULHW_Vdq_Wdq, I_CVTTPD2DQ_Vdq_Wpd, I_MOVNTDQ_Mdq_Vdq, 
	// E8
	I_PSUBSB_Vdq_Wdq, I_PSUBSW_Vdq_Wdq, I_PMINSW_Vdq_Wdq, I_POR_Vdq_Wdq, I_PADDSB_Vdq_Wdq, I_PADDSW_Vdq_Wdq, I_PMAXSW_Vdq_Wdq, I_PXOR_Vdq_Wdq, 
	// F0
	I_ILLEGAL, I_PSLLW_Vdq_Wdq, I_PSLLD_Vdq_Wdq, I_PSLLQ_Vdq_Wdq, I_PMULUDQ_Vdq_Wdq, I_PMADDWD_Vdq_Wdq, I_PSADBW_Vdq_Wdq, I_MASKMOVDQU_Vdq_Udq, 
	// F8
	I_PSUBB_Vdq_Wdq, I_PSUBW_Vdq_Wdq, I_PSUBD_Vdq_Wdq, I_PSUBQ_Vdq_Wdq, I_PADDB_Vdq_Wdq, I_PADDW_Vdq_Wdq, I_PADDD_Vdq_Wdq, I_ILLEGAL, 
};
const OpState CpuRunnerX86::table_66_0f_38[] = {
	// 00
	I_PSHUFB_Vdq_Wdq, I_PHADDW_Vdq_Wdq, I_PHADDD_Vdq_Wdq, I_PHADDSW_Vdq_Wdq, I_PMADDUBSW_Vdq_Wdq, I_PHSUBW_Vdq_Wdq, I_PHSUBD_Vdq_Wdq, I_PHSUBSW_Vdq_Wdq, 
	// 08
	I_PSIGNB_Vdq_Wdq, I_PSIGNW_Vdq_Wdq, I_PSIGND_Vdq_Wdq, I_PMULHRSW_Vdq_Wdq, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 10
	I_PBLENDVB_Vdq_Wdq, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_BLENDVPS_Vps_Wps, I_BLENDVPD_Vpd_Wpd, I_ILLEGAL, I_PTEST_Vdq_Wdq, 
	// 18
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_PABSB_Vdq_Wdq, I_PABSW_Vdq_Wdq, I_PABSD_Vdq_Wdq, I_ILLEGAL, 
	// 20
	I_PMOVSXBW_Vdq_Mq, I_PMOVSXBD_Vdq_Md, I_PMOVSXBQ_Vdq_Mw, I_PMOVSXWD_Vdq_Mq, I_PMOVSXWQ_Vdq_Md, I_PMOVSXDQ_Vdq_Mq, I_ILLEGAL, I_ILLEGAL, 
	// 28
	I_PMULDQ_Vdq_Wdq, I_PCMPEQQ_Vdq_Wdq, I_MOVNTDQA_Vdq_Mdq, I_PACKUSDW_Vdq_Wdq, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 30
	I_PMOVZXBW_Vdq_Mq, I_PMOVZXBD_Vdq_Md, I_PMOVZXBQ_Vdq_Mw, I_PMOVZXWD_Vdq_Mq, I_PMOVZXWQ_Vdq_Md, I_PMOVZXDQ_Vdq_Mq, I_ILLEGAL, I_PCMPGTQ_Vdq_Wdq, 
	// 38
	I_PMINSB_Vdq_Wdq, I_PMINSD_Vdq_Wdq, I_PMINUW_Vdq_Wdq, I_PMINUD_Vdq_Wdq, I_PMAXSB_Vdq_Wdq, I_PMAXSD_Vdq_Wdq, I_PMAXUW_Vdq_Wdq, I_PMAXUD_Vdq_Wdq, 
	// 40
	I_PMULLD_Vdq_Wdq, I_PHMINPOSUW_Vdq_Wdq, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 48
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 50
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 58
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 60
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 68
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 70
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 78
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 80
	I_INVEPT_Gd_Mdq, I_INVVPID_Gd_Mdq, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 88
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 90
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 98
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// A0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// A8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// C0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// C8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
};
const OpState CpuRunnerX86::table_66_0f_3a[] = {
	// 00
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 08
	I_ROUNDPS_Vps_Wps_Ib, I_ROUNDPD_Vps_Wpd_Ib, I_ROUNDSS_Vss_Wss_Ib, I_ROUNDSD_Vsd_Wsd_Ib, I_BLENDPS_Vps_Wps_Ib, I_BLENDPD_Vpd_Wpd_Ib, I_PBLENDW_Vdq_Wdq_Ib, I_PALIGNR_Vdq_Wdq, 
	// 10
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_PEXTRB_Mb_Vdq_Ib, I_PEXTRW_Mw_Vdq_Ib, I_PEXTRD_Ed_Vdq_Ib, I_EXTRACTPS_Ed_Vdq_Ib, 
	// 18
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 20
	I_PINSRB_Vdq_Mb_Ib, I_INSERTPS_Vps_Ups_Ib, I_PINSRD_Vdq_Ed_Ib, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 28
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 30
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 38
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 40
	I_DPPS_Vps_Wps, I_DPPD_Vpd_Wpd, I_MPSADBW_Vdq_Wdq_Ib, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 48
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 50
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 58
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 60
	I_PCMPESTRM_Vdq_Wdq_Ib, I_PCMPESTRI_Vdq_Wdq_Ib, I_PCMPISTRM_Vdq_Wdq_Ib, I_PCMPISTRI_Vdq_Wdq_Ib, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 68
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 70
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 78
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 80
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 88
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 90
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 98
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// A0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// A8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// C0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// C8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
};
const OpState CpuRunnerX86::table_66_0f_71[] = {
	// 00
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 08
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 10
	I_PSRLW_Udq_Ib, I_PSRLW_Udq_Ib, I_PSRLW_Udq_Ib, I_PSRLW_Udq_Ib, I_PSRLW_Udq_Ib, I_PSRLW_Udq_Ib, I_PSRLW_Udq_Ib, I_PSRLW_Udq_Ib, 
	// 18
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 20
	I_PSRAW_Udq_Ib, I_PSRAW_Udq_Ib, I_PSRAW_Udq_Ib, I_PSRAW_Udq_Ib, I_PSRAW_Udq_Ib, I_PSRAW_Udq_Ib, I_PSRAW_Udq_Ib, I_PSRAW_Udq_Ib, 
	// 28
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 30
	I_PSLLW_Udq_Ib, I_PSLLW_Udq_Ib, I_PSLLW_Udq_Ib, I_PSLLW_Udq_Ib, I_PSLLW_Udq_Ib, I_PSLLW_Udq_Ib, I_PSLLW_Udq_Ib, I_PSLLW_Udq_Ib, 
	// 38
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 40
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 48
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 50
	I_PSRLW_Udq_Ib, I_PSRLW_Udq_Ib, I_PSRLW_Udq_Ib, I_PSRLW_Udq_Ib, I_PSRLW_Udq_Ib, I_PSRLW_Udq_Ib, I_PSRLW_Udq_Ib, I_PSRLW_Udq_Ib, 
	// 58
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 60
	I_PSRAW_Udq_Ib, I_PSRAW_Udq_Ib, I_PSRAW_Udq_Ib, I_PSRAW_Udq_Ib, I_PSRAW_Udq_Ib, I_PSRAW_Udq_Ib, I_PSRAW_Udq_Ib, I_PSRAW_Udq_Ib, 
	// 68
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 70
	I_PSLLW_Udq_Ib, I_PSLLW_Udq_Ib, I_PSLLW_Udq_Ib, I_PSLLW_Udq_Ib, I_PSLLW_Udq_Ib, I_PSLLW_Udq_Ib, I_PSLLW_Udq_Ib, I_PSLLW_Udq_Ib, 
	// 78
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 80
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 88
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 90
	I_PSRLW_Udq_Ib, I_PSRLW_Udq_Ib, I_PSRLW_Udq_Ib, I_PSRLW_Udq_Ib, I_PSRLW_Udq_Ib, I_PSRLW_Udq_Ib, I_PSRLW_Udq_Ib, I_PSRLW_Udq_Ib, 
	// 98
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// A0
	I_PSRAW_Udq_Ib, I_PSRAW_Udq_Ib, I_PSRAW_Udq_Ib, I_PSRAW_Udq_Ib, I_PSRAW_Udq_Ib, I_PSRAW_Udq_Ib, I_PSRAW_Udq_Ib, I_PSRAW_Udq_Ib, 
	// A8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B0
	I_PSLLW_Udq_Ib, I_PSLLW_Udq_Ib, I_PSLLW_Udq_Ib, I_PSLLW_Udq_Ib, I_PSLLW_Udq_Ib, I_PSLLW_Udq_Ib, I_PSLLW_Udq_Ib, I_PSLLW_Udq_Ib, 
	// B8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// C0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// C8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D0
	I_PSRLW_Udq_Ib, I_PSRLW_Udq_Ib, I_PSRLW_Udq_Ib, I_PSRLW_Udq_Ib, I_PSRLW_Udq_Ib, I_PSRLW_Udq_Ib, I_PSRLW_Udq_Ib, I_PSRLW_Udq_Ib, 
	// D8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E0
	I_PSRAW_Udq_Ib, I_PSRAW_Udq_Ib, I_PSRAW_Udq_Ib, I_PSRAW_Udq_Ib, I_PSRAW_Udq_Ib, I_PSRAW_Udq_Ib, I_PSRAW_Udq_Ib, I_PSRAW_Udq_Ib, 
	// E8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F0
	I_PSLLW_Udq_Ib, I_PSLLW_Udq_Ib, I_PSLLW_Udq_Ib, I_PSLLW_Udq_Ib, I_PSLLW_Udq_Ib, I_PSLLW_Udq_Ib, I_PSLLW_Udq_Ib, I_PSLLW_Udq_Ib, 
	// F8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
};
const OpState CpuRunnerX86::table_66_0f_72[] = {
	// 00
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 08
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 10
	I_PSRLD_Udq_Ib, I_PSRLD_Udq_Ib, I_PSRLD_Udq_Ib, I_PSRLD_Udq_Ib, I_PSRLD_Udq_Ib, I_PSRLD_Udq_Ib, I_PSRLD_Udq_Ib, I_PSRLD_Udq_Ib, 
	// 18
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 20
	I_PSRAD_Udq_Ib, I_PSRAD_Udq_Ib, I_PSRAD_Udq_Ib, I_PSRAD_Udq_Ib, I_PSRAD_Udq_Ib, I_PSRAD_Udq_Ib, I_PSRAD_Udq_Ib, I_PSRAD_Udq_Ib, 
	// 28
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 30
	I_PSLLD_Udq_Ib, I_PSLLD_Udq_Ib, I_PSLLD_Udq_Ib, I_PSLLD_Udq_Ib, I_PSLLD_Udq_Ib, I_PSLLD_Udq_Ib, I_PSLLD_Udq_Ib, I_PSLLD_Udq_Ib, 
	// 38
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 40
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 48
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 50
	I_PSRLD_Udq_Ib, I_PSRLD_Udq_Ib, I_PSRLD_Udq_Ib, I_PSRLD_Udq_Ib, I_PSRLD_Udq_Ib, I_PSRLD_Udq_Ib, I_PSRLD_Udq_Ib, I_PSRLD_Udq_Ib, 
	// 58
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 60
	I_PSRAD_Udq_Ib, I_PSRAD_Udq_Ib, I_PSRAD_Udq_Ib, I_PSRAD_Udq_Ib, I_PSRAD_Udq_Ib, I_PSRAD_Udq_Ib, I_PSRAD_Udq_Ib, I_PSRAD_Udq_Ib, 
	// 68
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 70
	I_PSLLD_Udq_Ib, I_PSLLD_Udq_Ib, I_PSLLD_Udq_Ib, I_PSLLD_Udq_Ib, I_PSLLD_Udq_Ib, I_PSLLD_Udq_Ib, I_PSLLD_Udq_Ib, I_PSLLD_Udq_Ib, 
	// 78
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 80
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 88
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 90
	I_PSRLD_Udq_Ib, I_PSRLD_Udq_Ib, I_PSRLD_Udq_Ib, I_PSRLD_Udq_Ib, I_PSRLD_Udq_Ib, I_PSRLD_Udq_Ib, I_PSRLD_Udq_Ib, I_PSRLD_Udq_Ib, 
	// 98
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// A0
	I_PSRAD_Udq_Ib, I_PSRAD_Udq_Ib, I_PSRAD_Udq_Ib, I_PSRAD_Udq_Ib, I_PSRAD_Udq_Ib, I_PSRAD_Udq_Ib, I_PSRAD_Udq_Ib, I_PSRAD_Udq_Ib, 
	// A8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B0
	I_PSLLD_Udq_Ib, I_PSLLD_Udq_Ib, I_PSLLD_Udq_Ib, I_PSLLD_Udq_Ib, I_PSLLD_Udq_Ib, I_PSLLD_Udq_Ib, I_PSLLD_Udq_Ib, I_PSLLD_Udq_Ib, 
	// B8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// C0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// C8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D0
	I_PSRLD_Udq_Ib, I_PSRLD_Udq_Ib, I_PSRLD_Udq_Ib, I_PSRLD_Udq_Ib, I_PSRLD_Udq_Ib, I_PSRLD_Udq_Ib, I_PSRLD_Udq_Ib, I_PSRLD_Udq_Ib, 
	// D8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E0
	I_PSRAD_Udq_Ib, I_PSRAD_Udq_Ib, I_PSRAD_Udq_Ib, I_PSRAD_Udq_Ib, I_PSRAD_Udq_Ib, I_PSRAD_Udq_Ib, I_PSRAD_Udq_Ib, I_PSRAD_Udq_Ib, 
	// E8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F0
	I_PSLLD_Udq_Ib, I_PSLLD_Udq_Ib, I_PSLLD_Udq_Ib, I_PSLLD_Udq_Ib, I_PSLLD_Udq_Ib, I_PSLLD_Udq_Ib, I_PSLLD_Udq_Ib, I_PSLLD_Udq_Ib, 
	// F8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
};
const OpState CpuRunnerX86::table_66_0f_73[] = {
	// 00
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 08
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 10
	I_PSRLQ_Udq_Ib, I_PSRLQ_Udq_Ib, I_PSRLQ_Udq_Ib, I_PSRLQ_Udq_Ib, I_PSRLQ_Udq_Ib, I_PSRLQ_Udq_Ib, I_PSRLQ_Udq_Ib, I_PSRLQ_Udq_Ib, 
	// 18
	I_PSRLDQ_Udq_Ib, I_PSRLDQ_Udq_Ib, I_PSRLDQ_Udq_Ib, I_PSRLDQ_Udq_Ib, I_PSRLDQ_Udq_Ib, I_PSRLDQ_Udq_Ib, I_PSRLDQ_Udq_Ib, I_PSRLDQ_Udq_Ib, 
	// 20
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 28
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 30
	I_PSLLQ_Udq_Ib, I_PSLLQ_Udq_Ib, I_PSLLQ_Udq_Ib, I_PSLLQ_Udq_Ib, I_PSLLQ_Udq_Ib, I_PSLLQ_Udq_Ib, I_PSLLQ_Udq_Ib, I_PSLLQ_Udq_Ib, 
	// 38
	I_PSLLDQ_Udq_Ib, I_PSLLDQ_Udq_Ib, I_PSLLDQ_Udq_Ib, I_PSLLDQ_Udq_Ib, I_PSLLDQ_Udq_Ib, I_PSLLDQ_Udq_Ib, I_PSLLDQ_Udq_Ib, I_PSLLDQ_Udq_Ib, 
	// 40
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 48
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 50
	I_PSRLQ_Udq_Ib, I_PSRLQ_Udq_Ib, I_PSRLQ_Udq_Ib, I_PSRLQ_Udq_Ib, I_PSRLQ_Udq_Ib, I_PSRLQ_Udq_Ib, I_PSRLQ_Udq_Ib, I_PSRLQ_Udq_Ib, 
	// 58
	I_PSRLDQ_Udq_Ib, I_PSRLDQ_Udq_Ib, I_PSRLDQ_Udq_Ib, I_PSRLDQ_Udq_Ib, I_PSRLDQ_Udq_Ib, I_PSRLDQ_Udq_Ib, I_PSRLDQ_Udq_Ib, I_PSRLDQ_Udq_Ib, 
	// 60
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 68
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 70
	I_PSLLQ_Udq_Ib, I_PSLLQ_Udq_Ib, I_PSLLQ_Udq_Ib, I_PSLLQ_Udq_Ib, I_PSLLQ_Udq_Ib, I_PSLLQ_Udq_Ib, I_PSLLQ_Udq_Ib, I_PSLLQ_Udq_Ib, 
	// 78
	I_PSLLDQ_Udq_Ib, I_PSLLDQ_Udq_Ib, I_PSLLDQ_Udq_Ib, I_PSLLDQ_Udq_Ib, I_PSLLDQ_Udq_Ib, I_PSLLDQ_Udq_Ib, I_PSLLDQ_Udq_Ib, I_PSLLDQ_Udq_Ib, 
	// 80
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 88
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 90
	I_PSRLQ_Udq_Ib, I_PSRLQ_Udq_Ib, I_PSRLQ_Udq_Ib, I_PSRLQ_Udq_Ib, I_PSRLQ_Udq_Ib, I_PSRLQ_Udq_Ib, I_PSRLQ_Udq_Ib, I_PSRLQ_Udq_Ib, 
	// 98
	I_PSRLDQ_Udq_Ib, I_PSRLDQ_Udq_Ib, I_PSRLDQ_Udq_Ib, I_PSRLDQ_Udq_Ib, I_PSRLDQ_Udq_Ib, I_PSRLDQ_Udq_Ib, I_PSRLDQ_Udq_Ib, I_PSRLDQ_Udq_Ib, 
	// A0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// A8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B0
	I_PSLLQ_Udq_Ib, I_PSLLQ_Udq_Ib, I_PSLLQ_Udq_Ib, I_PSLLQ_Udq_Ib, I_PSLLQ_Udq_Ib, I_PSLLQ_Udq_Ib, I_PSLLQ_Udq_Ib, I_PSLLQ_Udq_Ib, 
	// B8
	I_PSLLDQ_Udq_Ib, I_PSLLDQ_Udq_Ib, I_PSLLDQ_Udq_Ib, I_PSLLDQ_Udq_Ib, I_PSLLDQ_Udq_Ib, I_PSLLDQ_Udq_Ib, I_PSLLDQ_Udq_Ib, I_PSLLDQ_Udq_Ib, 
	// C0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// C8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D0
	I_PSRLQ_Udq_Ib, I_PSRLQ_Udq_Ib, I_PSRLQ_Udq_Ib, I_PSRLQ_Udq_Ib, I_PSRLQ_Udq_Ib, I_PSRLQ_Udq_Ib, I_PSRLQ_Udq_Ib, I_PSRLQ_Udq_Ib, 
	// D8
	I_PSRLDQ_Udq_Ib, I_PSRLDQ_Udq_Ib, I_PSRLDQ_Udq_Ib, I_PSRLDQ_Udq_Ib, I_PSRLDQ_Udq_Ib, I_PSRLDQ_Udq_Ib, I_PSRLDQ_Udq_Ib, I_PSRLDQ_Udq_Ib, 
	// E0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F0
	I_PSLLQ_Udq_Ib, I_PSLLQ_Udq_Ib, I_PSLLQ_Udq_Ib, I_PSLLQ_Udq_Ib, I_PSLLQ_Udq_Ib, I_PSLLQ_Udq_Ib, I_PSLLQ_Udq_Ib, I_PSLLQ_Udq_Ib, 
	// F8
	I_PSLLDQ_Udq_Ib, I_PSLLDQ_Udq_Ib, I_PSLLDQ_Udq_Ib, I_PSLLDQ_Udq_Ib, I_PSLLDQ_Udq_Ib, I_PSLLDQ_Udq_Ib, I_PSLLDQ_Udq_Ib, I_PSLLDQ_Udq_Ib, 
};
const OpState CpuRunnerX86::table_66_0f_c7[] = {
	// 00
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 08
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 10
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 18
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 20
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 28
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 30
	I_VMCLEAR_Mq, I_VMCLEAR_Mq, I_VMCLEAR_Mq, I_VMCLEAR_Mq, I_VMCLEAR_Mq, I_VMCLEAR_Mq, I_VMCLEAR_Mq, I_VMCLEAR_Mq, 
	// 38
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 40
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 48
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 50
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 58
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 60
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 68
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 70
	I_VMCLEAR_Mq, I_VMCLEAR_Mq, I_VMCLEAR_Mq, I_VMCLEAR_Mq, I_VMCLEAR_Mq, I_VMCLEAR_Mq, I_VMCLEAR_Mq, I_VMCLEAR_Mq, 
	// 78
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 80
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 88
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 90
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 98
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// A0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// A8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B0
	I_VMCLEAR_Mq, I_VMCLEAR_Mq, I_VMCLEAR_Mq, I_VMCLEAR_Mq, I_VMCLEAR_Mq, I_VMCLEAR_Mq, I_VMCLEAR_Mq, I_VMCLEAR_Mq, 
	// B8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// C0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// C8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
};
const OpState CpuRunnerX86::table_80[] = {
	// 00
	I_ADD_Eb_Ib, I_ADD_Eb_Ib, I_ADD_Eb_Ib, I_ADD_Eb_Ib, I_ADD_Eb_Ib, I_ADD_Eb_Ib, I_ADD_Eb_Ib, I_ADD_Eb_Ib, 
	// 08
	I_OR_Eb_Ib, I_OR_Eb_Ib, I_OR_Eb_Ib, I_OR_Eb_Ib, I_OR_Eb_Ib, I_OR_Eb_Ib, I_OR_Eb_Ib, I_OR_Eb_Ib, 
	// 10
	I_ADC_Eb_Ib, I_ADC_Eb_Ib, I_ADC_Eb_Ib, I_ADC_Eb_Ib, I_ADC_Eb_Ib, I_ADC_Eb_Ib, I_ADC_Eb_Ib, I_ADC_Eb_Ib, 
	// 18
	I_SBB_Eb_Ib, I_SBB_Eb_Ib, I_SBB_Eb_Ib, I_SBB_Eb_Ib, I_SBB_Eb_Ib, I_SBB_Eb_Ib, I_SBB_Eb_Ib, I_SBB_Eb_Ib, 
	// 20
	I_AND_Eb_Ib, I_AND_Eb_Ib, I_AND_Eb_Ib, I_AND_Eb_Ib, I_AND_Eb_Ib, I_AND_Eb_Ib, I_AND_Eb_Ib, I_AND_Eb_Ib, 
	// 28
	I_SUB_Eb_Ib, I_SUB_Eb_Ib, I_SUB_Eb_Ib, I_SUB_Eb_Ib, I_SUB_Eb_Ib, I_SUB_Eb_Ib, I_SUB_Eb_Ib, I_SUB_Eb_Ib, 
	// 30
	I_XOR_Eb_Ib, I_XOR_Eb_Ib, I_XOR_Eb_Ib, I_XOR_Eb_Ib, I_XOR_Eb_Ib, I_XOR_Eb_Ib, I_XOR_Eb_Ib, I_XOR_Eb_Ib, 
	// 38
	I_CMP_Eb_Ib, I_CMP_Eb_Ib, I_CMP_Eb_Ib, I_CMP_Eb_Ib, I_CMP_Eb_Ib, I_CMP_Eb_Ib, I_CMP_Eb_Ib, I_CMP_Eb_Ib, 
	// 40
	I_ADD_Eb_Ib, I_ADD_Eb_Ib, I_ADD_Eb_Ib, I_ADD_Eb_Ib, I_ADD_Eb_Ib, I_ADD_Eb_Ib, I_ADD_Eb_Ib, I_ADD_Eb_Ib, 
	// 48
	I_OR_Eb_Ib, I_OR_Eb_Ib, I_OR_Eb_Ib, I_OR_Eb_Ib, I_OR_Eb_Ib, I_OR_Eb_Ib, I_OR_Eb_Ib, I_OR_Eb_Ib, 
	// 50
	I_ADC_Eb_Ib, I_ADC_Eb_Ib, I_ADC_Eb_Ib, I_ADC_Eb_Ib, I_ADC_Eb_Ib, I_ADC_Eb_Ib, I_ADC_Eb_Ib, I_ADC_Eb_Ib, 
	// 58
	I_SBB_Eb_Ib, I_SBB_Eb_Ib, I_SBB_Eb_Ib, I_SBB_Eb_Ib, I_SBB_Eb_Ib, I_SBB_Eb_Ib, I_SBB_Eb_Ib, I_SBB_Eb_Ib, 
	// 60
	I_AND_Eb_Ib, I_AND_Eb_Ib, I_AND_Eb_Ib, I_AND_Eb_Ib, I_AND_Eb_Ib, I_AND_Eb_Ib, I_AND_Eb_Ib, I_AND_Eb_Ib, 
	// 68
	I_SUB_Eb_Ib, I_SUB_Eb_Ib, I_SUB_Eb_Ib, I_SUB_Eb_Ib, I_SUB_Eb_Ib, I_SUB_Eb_Ib, I_SUB_Eb_Ib, I_SUB_Eb_Ib, 
	// 70
	I_XOR_Eb_Ib, I_XOR_Eb_Ib, I_XOR_Eb_Ib, I_XOR_Eb_Ib, I_XOR_Eb_Ib, I_XOR_Eb_Ib, I_XOR_Eb_Ib, I_XOR_Eb_Ib, 
	// 78
	I_CMP_Eb_Ib, I_CMP_Eb_Ib, I_CMP_Eb_Ib, I_CMP_Eb_Ib, I_CMP_Eb_Ib, I_CMP_Eb_Ib, I_CMP_Eb_Ib, I_CMP_Eb_Ib, 
	// 80
	I_ADD_Eb_Ib, I_ADD_Eb_Ib, I_ADD_Eb_Ib, I_ADD_Eb_Ib, I_ADD_Eb_Ib, I_ADD_Eb_Ib, I_ADD_Eb_Ib, I_ADD_Eb_Ib, 
	// 88
	I_OR_Eb_Ib, I_OR_Eb_Ib, I_OR_Eb_Ib, I_OR_Eb_Ib, I_OR_Eb_Ib, I_OR_Eb_Ib, I_OR_Eb_Ib, I_OR_Eb_Ib, 
	// 90
	I_ADC_Eb_Ib, I_ADC_Eb_Ib, I_ADC_Eb_Ib, I_ADC_Eb_Ib, I_ADC_Eb_Ib, I_ADC_Eb_Ib, I_ADC_Eb_Ib, I_ADC_Eb_Ib, 
	// 98
	I_SBB_Eb_Ib, I_SBB_Eb_Ib, I_SBB_Eb_Ib, I_SBB_Eb_Ib, I_SBB_Eb_Ib, I_SBB_Eb_Ib, I_SBB_Eb_Ib, I_SBB_Eb_Ib, 
	// A0
	I_AND_Eb_Ib, I_AND_Eb_Ib, I_AND_Eb_Ib, I_AND_Eb_Ib, I_AND_Eb_Ib, I_AND_Eb_Ib, I_AND_Eb_Ib, I_AND_Eb_Ib, 
	// A8
	I_SUB_Eb_Ib, I_SUB_Eb_Ib, I_SUB_Eb_Ib, I_SUB_Eb_Ib, I_SUB_Eb_Ib, I_SUB_Eb_Ib, I_SUB_Eb_Ib, I_SUB_Eb_Ib, 
	// B0
	I_XOR_Eb_Ib, I_XOR_Eb_Ib, I_XOR_Eb_Ib, I_XOR_Eb_Ib, I_XOR_Eb_Ib, I_XOR_Eb_Ib, I_XOR_Eb_Ib, I_XOR_Eb_Ib, 
	// B8
	I_CMP_Eb_Ib, I_CMP_Eb_Ib, I_CMP_Eb_Ib, I_CMP_Eb_Ib, I_CMP_Eb_Ib, I_CMP_Eb_Ib, I_CMP_Eb_Ib, I_CMP_Eb_Ib, 
	// C0
	I_ADD_Eb_Ib, I_ADD_Eb_Ib, I_ADD_Eb_Ib, I_ADD_Eb_Ib, I_ADD_Eb_Ib, I_ADD_Eb_Ib, I_ADD_Eb_Ib, I_ADD_Eb_Ib, 
	// C8
	I_OR_Eb_Ib, I_OR_Eb_Ib, I_OR_Eb_Ib, I_OR_Eb_Ib, I_OR_Eb_Ib, I_OR_Eb_Ib, I_OR_Eb_Ib, I_OR_Eb_Ib, 
	// D0
	I_ADC_Eb_Ib, I_ADC_Eb_Ib, I_ADC_Eb_Ib, I_ADC_Eb_Ib, I_ADC_Eb_Ib, I_ADC_Eb_Ib, I_ADC_Eb_Ib, I_ADC_Eb_Ib, 
	// D8
	I_SBB_Eb_Ib, I_SBB_Eb_Ib, I_SBB_Eb_Ib, I_SBB_Eb_Ib, I_SBB_Eb_Ib, I_SBB_Eb_Ib, I_SBB_Eb_Ib, I_SBB_Eb_Ib, 
	// E0
	I_AND_Eb_Ib, I_AND_Eb_Ib, I_AND_Eb_Ib, I_AND_Eb_Ib, I_AND_Eb_Ib, I_AND_Eb_Ib, I_AND_Eb_Ib, I_AND_Eb_Ib, 
	// E8
	I_SUB_Eb_Ib, I_SUB_Eb_Ib, I_SUB_Eb_Ib, I_SUB_Eb_Ib, I_SUB_Eb_Ib, I_SUB_Eb_Ib, I_SUB_Eb_Ib, I_SUB_Eb_Ib, 
	// F0
	I_XOR_Eb_Ib, I_XOR_Eb_Ib, I_XOR_Eb_Ib, I_XOR_Eb_Ib, I_XOR_Eb_Ib, I_XOR_Eb_Ib, I_XOR_Eb_Ib, I_XOR_Eb_Ib, 
	// F8
	I_CMP_Eb_Ib, I_CMP_Eb_Ib, I_CMP_Eb_Ib, I_CMP_Eb_Ib, I_CMP_Eb_Ib, I_CMP_Eb_Ib, I_CMP_Eb_Ib, I_CMP_Eb_Ib, 
};
const OpState CpuRunnerX86::table_81[] = {
	// 00
	I_ADD_Evqp_Ivds, I_ADD_Evqp_Ivds, I_ADD_Evqp_Ivds, I_ADD_Evqp_Ivds, I_ADD_Evqp_Ivds, I_ADD_Evqp_Ivds, I_ADD_Evqp_Ivds, I_ADD_Evqp_Ivds, 
	// 08
	I_OR_Evqp_Ivds, I_OR_Evqp_Ivds, I_OR_Evqp_Ivds, I_OR_Evqp_Ivds, I_OR_Evqp_Ivds, I_OR_Evqp_Ivds, I_OR_Evqp_Ivds, I_OR_Evqp_Ivds, 
	// 10
	I_ADC_Evqp_Ivds, I_ADC_Evqp_Ivds, I_ADC_Evqp_Ivds, I_ADC_Evqp_Ivds, I_ADC_Evqp_Ivds, I_ADC_Evqp_Ivds, I_ADC_Evqp_Ivds, I_ADC_Evqp_Ivds, 
	// 18
	I_SBB_Evqp_Ivds, I_SBB_Evqp_Ivds, I_SBB_Evqp_Ivds, I_SBB_Evqp_Ivds, I_SBB_Evqp_Ivds, I_SBB_Evqp_Ivds, I_SBB_Evqp_Ivds, I_SBB_Evqp_Ivds, 
	// 20
	I_AND_Evqp_Ivds, I_AND_Evqp_Ivds, I_AND_Evqp_Ivds, I_AND_Evqp_Ivds, I_AND_Evqp_Ivds, I_AND_Evqp_Ivds, I_AND_Evqp_Ivds, I_AND_Evqp_Ivds, 
	// 28
	I_SUB_Evqp_Ivds, I_SUB_Evqp_Ivds, I_SUB_Evqp_Ivds, I_SUB_Evqp_Ivds, I_SUB_Evqp_Ivds, I_SUB_Evqp_Ivds, I_SUB_Evqp_Ivds, I_SUB_Evqp_Ivds, 
	// 30
	I_XOR_Evqp_Ivds, I_XOR_Evqp_Ivds, I_XOR_Evqp_Ivds, I_XOR_Evqp_Ivds, I_XOR_Evqp_Ivds, I_XOR_Evqp_Ivds, I_XOR_Evqp_Ivds, I_XOR_Evqp_Ivds, 
	// 38
	I_CMP_Evqp_Ivds, I_CMP_Evqp_Ivds, I_CMP_Evqp_Ivds, I_CMP_Evqp_Ivds, I_CMP_Evqp_Ivds, I_CMP_Evqp_Ivds, I_CMP_Evqp_Ivds, I_CMP_Evqp_Ivds, 
	// 40
	I_ADD_Evqp_Ivds, I_ADD_Evqp_Ivds, I_ADD_Evqp_Ivds, I_ADD_Evqp_Ivds, I_ADD_Evqp_Ivds, I_ADD_Evqp_Ivds, I_ADD_Evqp_Ivds, I_ADD_Evqp_Ivds, 
	// 48
	I_OR_Evqp_Ivds, I_OR_Evqp_Ivds, I_OR_Evqp_Ivds, I_OR_Evqp_Ivds, I_OR_Evqp_Ivds, I_OR_Evqp_Ivds, I_OR_Evqp_Ivds, I_OR_Evqp_Ivds, 
	// 50
	I_ADC_Evqp_Ivds, I_ADC_Evqp_Ivds, I_ADC_Evqp_Ivds, I_ADC_Evqp_Ivds, I_ADC_Evqp_Ivds, I_ADC_Evqp_Ivds, I_ADC_Evqp_Ivds, I_ADC_Evqp_Ivds, 
	// 58
	I_SBB_Evqp_Ivds, I_SBB_Evqp_Ivds, I_SBB_Evqp_Ivds, I_SBB_Evqp_Ivds, I_SBB_Evqp_Ivds, I_SBB_Evqp_Ivds, I_SBB_Evqp_Ivds, I_SBB_Evqp_Ivds, 
	// 60
	I_AND_Evqp_Ivds, I_AND_Evqp_Ivds, I_AND_Evqp_Ivds, I_AND_Evqp_Ivds, I_AND_Evqp_Ivds, I_AND_Evqp_Ivds, I_AND_Evqp_Ivds, I_AND_Evqp_Ivds, 
	// 68
	I_SUB_Evqp_Ivds, I_SUB_Evqp_Ivds, I_SUB_Evqp_Ivds, I_SUB_Evqp_Ivds, I_SUB_Evqp_Ivds, I_SUB_Evqp_Ivds, I_SUB_Evqp_Ivds, I_SUB_Evqp_Ivds, 
	// 70
	I_XOR_Evqp_Ivds, I_XOR_Evqp_Ivds, I_XOR_Evqp_Ivds, I_XOR_Evqp_Ivds, I_XOR_Evqp_Ivds, I_XOR_Evqp_Ivds, I_XOR_Evqp_Ivds, I_XOR_Evqp_Ivds, 
	// 78
	I_CMP_Evqp_Ivds, I_CMP_Evqp_Ivds, I_CMP_Evqp_Ivds, I_CMP_Evqp_Ivds, I_CMP_Evqp_Ivds, I_CMP_Evqp_Ivds, I_CMP_Evqp_Ivds, I_CMP_Evqp_Ivds, 
	// 80
	I_ADD_Evqp_Ivds, I_ADD_Evqp_Ivds, I_ADD_Evqp_Ivds, I_ADD_Evqp_Ivds, I_ADD_Evqp_Ivds, I_ADD_Evqp_Ivds, I_ADD_Evqp_Ivds, I_ADD_Evqp_Ivds, 
	// 88
	I_OR_Evqp_Ivds, I_OR_Evqp_Ivds, I_OR_Evqp_Ivds, I_OR_Evqp_Ivds, I_OR_Evqp_Ivds, I_OR_Evqp_Ivds, I_OR_Evqp_Ivds, I_OR_Evqp_Ivds, 
	// 90
	I_ADC_Evqp_Ivds, I_ADC_Evqp_Ivds, I_ADC_Evqp_Ivds, I_ADC_Evqp_Ivds, I_ADC_Evqp_Ivds, I_ADC_Evqp_Ivds, I_ADC_Evqp_Ivds, I_ADC_Evqp_Ivds, 
	// 98
	I_SBB_Evqp_Ivds, I_SBB_Evqp_Ivds, I_SBB_Evqp_Ivds, I_SBB_Evqp_Ivds, I_SBB_Evqp_Ivds, I_SBB_Evqp_Ivds, I_SBB_Evqp_Ivds, I_SBB_Evqp_Ivds, 
	// A0
	I_AND_Evqp_Ivds, I_AND_Evqp_Ivds, I_AND_Evqp_Ivds, I_AND_Evqp_Ivds, I_AND_Evqp_Ivds, I_AND_Evqp_Ivds, I_AND_Evqp_Ivds, I_AND_Evqp_Ivds, 
	// A8
	I_SUB_Evqp_Ivds, I_SUB_Evqp_Ivds, I_SUB_Evqp_Ivds, I_SUB_Evqp_Ivds, I_SUB_Evqp_Ivds, I_SUB_Evqp_Ivds, I_SUB_Evqp_Ivds, I_SUB_Evqp_Ivds, 
	// B0
	I_XOR_Evqp_Ivds, I_XOR_Evqp_Ivds, I_XOR_Evqp_Ivds, I_XOR_Evqp_Ivds, I_XOR_Evqp_Ivds, I_XOR_Evqp_Ivds, I_XOR_Evqp_Ivds, I_XOR_Evqp_Ivds, 
	// B8
	I_CMP_Evqp_Ivds, I_CMP_Evqp_Ivds, I_CMP_Evqp_Ivds, I_CMP_Evqp_Ivds, I_CMP_Evqp_Ivds, I_CMP_Evqp_Ivds, I_CMP_Evqp_Ivds, I_CMP_Evqp_Ivds, 
	// C0
	I_ADD_Evqp_Ivds, I_ADD_Evqp_Ivds, I_ADD_Evqp_Ivds, I_ADD_Evqp_Ivds, I_ADD_Evqp_Ivds, I_ADD_Evqp_Ivds, I_ADD_Evqp_Ivds, I_ADD_Evqp_Ivds, 
	// C8
	I_OR_Evqp_Ivds, I_OR_Evqp_Ivds, I_OR_Evqp_Ivds, I_OR_Evqp_Ivds, I_OR_Evqp_Ivds, I_OR_Evqp_Ivds, I_OR_Evqp_Ivds, I_OR_Evqp_Ivds, 
	// D0
	I_ADC_Evqp_Ivds, I_ADC_Evqp_Ivds, I_ADC_Evqp_Ivds, I_ADC_Evqp_Ivds, I_ADC_Evqp_Ivds, I_ADC_Evqp_Ivds, I_ADC_Evqp_Ivds, I_ADC_Evqp_Ivds, 
	// D8
	I_SBB_Evqp_Ivds, I_SBB_Evqp_Ivds, I_SBB_Evqp_Ivds, I_SBB_Evqp_Ivds, I_SBB_Evqp_Ivds, I_SBB_Evqp_Ivds, I_SBB_Evqp_Ivds, I_SBB_Evqp_Ivds, 
	// E0
	I_AND_Evqp_Ivds, I_AND_Evqp_Ivds, I_AND_Evqp_Ivds, I_AND_Evqp_Ivds, I_AND_Evqp_Ivds, I_AND_Evqp_Ivds, I_AND_Evqp_Ivds, I_AND_Evqp_Ivds, 
	// E8
	I_SUB_Evqp_Ivds, I_SUB_Evqp_Ivds, I_SUB_Evqp_Ivds, I_SUB_Evqp_Ivds, I_SUB_Evqp_Ivds, I_SUB_Evqp_Ivds, I_SUB_Evqp_Ivds, I_SUB_Evqp_Ivds, 
	// F0
	I_XOR_Evqp_Ivds, I_XOR_Evqp_Ivds, I_XOR_Evqp_Ivds, I_XOR_Evqp_Ivds, I_XOR_Evqp_Ivds, I_XOR_Evqp_Ivds, I_XOR_Evqp_Ivds, I_XOR_Evqp_Ivds, 
	// F8
	I_CMP_Evqp_Ivds, I_CMP_Evqp_Ivds, I_CMP_Evqp_Ivds, I_CMP_Evqp_Ivds, I_CMP_Evqp_Ivds, I_CMP_Evqp_Ivds, I_CMP_Evqp_Ivds, I_CMP_Evqp_Ivds, 
};
const OpState CpuRunnerX86::table_82[] = {
	// 00
	I_ADD_Eb_Ib, I_ADD_Eb_Ib, I_ADD_Eb_Ib, I_ADD_Eb_Ib, I_ADD_Eb_Ib, I_ADD_Eb_Ib, I_ADD_Eb_Ib, I_ADD_Eb_Ib, 
	// 08
	I_OR_Eb_Ib, I_OR_Eb_Ib, I_OR_Eb_Ib, I_OR_Eb_Ib, I_OR_Eb_Ib, I_OR_Eb_Ib, I_OR_Eb_Ib, I_OR_Eb_Ib, 
	// 10
	I_ADC_Eb_Ib, I_ADC_Eb_Ib, I_ADC_Eb_Ib, I_ADC_Eb_Ib, I_ADC_Eb_Ib, I_ADC_Eb_Ib, I_ADC_Eb_Ib, I_ADC_Eb_Ib, 
	// 18
	I_SBB_Eb_Ib, I_SBB_Eb_Ib, I_SBB_Eb_Ib, I_SBB_Eb_Ib, I_SBB_Eb_Ib, I_SBB_Eb_Ib, I_SBB_Eb_Ib, I_SBB_Eb_Ib, 
	// 20
	I_AND_Eb_Ib, I_AND_Eb_Ib, I_AND_Eb_Ib, I_AND_Eb_Ib, I_AND_Eb_Ib, I_AND_Eb_Ib, I_AND_Eb_Ib, I_AND_Eb_Ib, 
	// 28
	I_SUB_Eb_Ib, I_SUB_Eb_Ib, I_SUB_Eb_Ib, I_SUB_Eb_Ib, I_SUB_Eb_Ib, I_SUB_Eb_Ib, I_SUB_Eb_Ib, I_SUB_Eb_Ib, 
	// 30
	I_XOR_Eb_Ib, I_XOR_Eb_Ib, I_XOR_Eb_Ib, I_XOR_Eb_Ib, I_XOR_Eb_Ib, I_XOR_Eb_Ib, I_XOR_Eb_Ib, I_XOR_Eb_Ib, 
	// 38
	I_CMP_Eb_Ib, I_CMP_Eb_Ib, I_CMP_Eb_Ib, I_CMP_Eb_Ib, I_CMP_Eb_Ib, I_CMP_Eb_Ib, I_CMP_Eb_Ib, I_CMP_Eb_Ib, 
	// 40
	I_ADD_Eb_Ib, I_ADD_Eb_Ib, I_ADD_Eb_Ib, I_ADD_Eb_Ib, I_ADD_Eb_Ib, I_ADD_Eb_Ib, I_ADD_Eb_Ib, I_ADD_Eb_Ib, 
	// 48
	I_OR_Eb_Ib, I_OR_Eb_Ib, I_OR_Eb_Ib, I_OR_Eb_Ib, I_OR_Eb_Ib, I_OR_Eb_Ib, I_OR_Eb_Ib, I_OR_Eb_Ib, 
	// 50
	I_ADC_Eb_Ib, I_ADC_Eb_Ib, I_ADC_Eb_Ib, I_ADC_Eb_Ib, I_ADC_Eb_Ib, I_ADC_Eb_Ib, I_ADC_Eb_Ib, I_ADC_Eb_Ib, 
	// 58
	I_SBB_Eb_Ib, I_SBB_Eb_Ib, I_SBB_Eb_Ib, I_SBB_Eb_Ib, I_SBB_Eb_Ib, I_SBB_Eb_Ib, I_SBB_Eb_Ib, I_SBB_Eb_Ib, 
	// 60
	I_AND_Eb_Ib, I_AND_Eb_Ib, I_AND_Eb_Ib, I_AND_Eb_Ib, I_AND_Eb_Ib, I_AND_Eb_Ib, I_AND_Eb_Ib, I_AND_Eb_Ib, 
	// 68
	I_SUB_Eb_Ib, I_SUB_Eb_Ib, I_SUB_Eb_Ib, I_SUB_Eb_Ib, I_SUB_Eb_Ib, I_SUB_Eb_Ib, I_SUB_Eb_Ib, I_SUB_Eb_Ib, 
	// 70
	I_XOR_Eb_Ib, I_XOR_Eb_Ib, I_XOR_Eb_Ib, I_XOR_Eb_Ib, I_XOR_Eb_Ib, I_XOR_Eb_Ib, I_XOR_Eb_Ib, I_XOR_Eb_Ib, 
	// 78
	I_CMP_Eb_Ib, I_CMP_Eb_Ib, I_CMP_Eb_Ib, I_CMP_Eb_Ib, I_CMP_Eb_Ib, I_CMP_Eb_Ib, I_CMP_Eb_Ib, I_CMP_Eb_Ib, 
	// 80
	I_ADD_Eb_Ib, I_ADD_Eb_Ib, I_ADD_Eb_Ib, I_ADD_Eb_Ib, I_ADD_Eb_Ib, I_ADD_Eb_Ib, I_ADD_Eb_Ib, I_ADD_Eb_Ib, 
	// 88
	I_OR_Eb_Ib, I_OR_Eb_Ib, I_OR_Eb_Ib, I_OR_Eb_Ib, I_OR_Eb_Ib, I_OR_Eb_Ib, I_OR_Eb_Ib, I_OR_Eb_Ib, 
	// 90
	I_ADC_Eb_Ib, I_ADC_Eb_Ib, I_ADC_Eb_Ib, I_ADC_Eb_Ib, I_ADC_Eb_Ib, I_ADC_Eb_Ib, I_ADC_Eb_Ib, I_ADC_Eb_Ib, 
	// 98
	I_SBB_Eb_Ib, I_SBB_Eb_Ib, I_SBB_Eb_Ib, I_SBB_Eb_Ib, I_SBB_Eb_Ib, I_SBB_Eb_Ib, I_SBB_Eb_Ib, I_SBB_Eb_Ib, 
	// A0
	I_AND_Eb_Ib, I_AND_Eb_Ib, I_AND_Eb_Ib, I_AND_Eb_Ib, I_AND_Eb_Ib, I_AND_Eb_Ib, I_AND_Eb_Ib, I_AND_Eb_Ib, 
	// A8
	I_SUB_Eb_Ib, I_SUB_Eb_Ib, I_SUB_Eb_Ib, I_SUB_Eb_Ib, I_SUB_Eb_Ib, I_SUB_Eb_Ib, I_SUB_Eb_Ib, I_SUB_Eb_Ib, 
	// B0
	I_XOR_Eb_Ib, I_XOR_Eb_Ib, I_XOR_Eb_Ib, I_XOR_Eb_Ib, I_XOR_Eb_Ib, I_XOR_Eb_Ib, I_XOR_Eb_Ib, I_XOR_Eb_Ib, 
	// B8
	I_CMP_Eb_Ib, I_CMP_Eb_Ib, I_CMP_Eb_Ib, I_CMP_Eb_Ib, I_CMP_Eb_Ib, I_CMP_Eb_Ib, I_CMP_Eb_Ib, I_CMP_Eb_Ib, 
	// C0
	I_ADD_Eb_Ib, I_ADD_Eb_Ib, I_ADD_Eb_Ib, I_ADD_Eb_Ib, I_ADD_Eb_Ib, I_ADD_Eb_Ib, I_ADD_Eb_Ib, I_ADD_Eb_Ib, 
	// C8
	I_OR_Eb_Ib, I_OR_Eb_Ib, I_OR_Eb_Ib, I_OR_Eb_Ib, I_OR_Eb_Ib, I_OR_Eb_Ib, I_OR_Eb_Ib, I_OR_Eb_Ib, 
	// D0
	I_ADC_Eb_Ib, I_ADC_Eb_Ib, I_ADC_Eb_Ib, I_ADC_Eb_Ib, I_ADC_Eb_Ib, I_ADC_Eb_Ib, I_ADC_Eb_Ib, I_ADC_Eb_Ib, 
	// D8
	I_SBB_Eb_Ib, I_SBB_Eb_Ib, I_SBB_Eb_Ib, I_SBB_Eb_Ib, I_SBB_Eb_Ib, I_SBB_Eb_Ib, I_SBB_Eb_Ib, I_SBB_Eb_Ib, 
	// E0
	I_AND_Eb_Ib, I_AND_Eb_Ib, I_AND_Eb_Ib, I_AND_Eb_Ib, I_AND_Eb_Ib, I_AND_Eb_Ib, I_AND_Eb_Ib, I_AND_Eb_Ib, 
	// E8
	I_SUB_Eb_Ib, I_SUB_Eb_Ib, I_SUB_Eb_Ib, I_SUB_Eb_Ib, I_SUB_Eb_Ib, I_SUB_Eb_Ib, I_SUB_Eb_Ib, I_SUB_Eb_Ib, 
	// F0
	I_XOR_Eb_Ib, I_XOR_Eb_Ib, I_XOR_Eb_Ib, I_XOR_Eb_Ib, I_XOR_Eb_Ib, I_XOR_Eb_Ib, I_XOR_Eb_Ib, I_XOR_Eb_Ib, 
	// F8
	I_CMP_Eb_Ib, I_CMP_Eb_Ib, I_CMP_Eb_Ib, I_CMP_Eb_Ib, I_CMP_Eb_Ib, I_CMP_Eb_Ib, I_CMP_Eb_Ib, I_CMP_Eb_Ib, 
};
const OpState CpuRunnerX86::table_83[] = {
	// 00
	I_ADD_Evqp_Ibs, I_ADD_Evqp_Ibs, I_ADD_Evqp_Ibs, I_ADD_Evqp_Ibs, I_ADD_Evqp_Ibs, I_ADD_Evqp_Ibs, I_ADD_Evqp_Ibs, I_ADD_Evqp_Ibs, 
	// 08
	I_OR_Evqp_Ibs, I_OR_Evqp_Ibs, I_OR_Evqp_Ibs, I_OR_Evqp_Ibs, I_OR_Evqp_Ibs, I_OR_Evqp_Ibs, I_OR_Evqp_Ibs, I_OR_Evqp_Ibs, 
	// 10
	I_ADC_Evqp_Ibs, I_ADC_Evqp_Ibs, I_ADC_Evqp_Ibs, I_ADC_Evqp_Ibs, I_ADC_Evqp_Ibs, I_ADC_Evqp_Ibs, I_ADC_Evqp_Ibs, I_ADC_Evqp_Ibs, 
	// 18
	I_SBB_Evqp_Ibs, I_SBB_Evqp_Ibs, I_SBB_Evqp_Ibs, I_SBB_Evqp_Ibs, I_SBB_Evqp_Ibs, I_SBB_Evqp_Ibs, I_SBB_Evqp_Ibs, I_SBB_Evqp_Ibs, 
	// 20
	I_AND_Evqp_Ibs, I_AND_Evqp_Ibs, I_AND_Evqp_Ibs, I_AND_Evqp_Ibs, I_AND_Evqp_Ibs, I_AND_Evqp_Ibs, I_AND_Evqp_Ibs, I_AND_Evqp_Ibs, 
	// 28
	I_SUB_Evqp_Ibs, I_SUB_Evqp_Ibs, I_SUB_Evqp_Ibs, I_SUB_Evqp_Ibs, I_SUB_Evqp_Ibs, I_SUB_Evqp_Ibs, I_SUB_Evqp_Ibs, I_SUB_Evqp_Ibs, 
	// 30
	I_XOR_Evqp_Ibs, I_XOR_Evqp_Ibs, I_XOR_Evqp_Ibs, I_XOR_Evqp_Ibs, I_XOR_Evqp_Ibs, I_XOR_Evqp_Ibs, I_XOR_Evqp_Ibs, I_XOR_Evqp_Ibs, 
	// 38
	I_CMP_Evqp_Ibs, I_CMP_Evqp_Ibs, I_CMP_Evqp_Ibs, I_CMP_Evqp_Ibs, I_CMP_Evqp_Ibs, I_CMP_Evqp_Ibs, I_CMP_Evqp_Ibs, I_CMP_Evqp_Ibs, 
	// 40
	I_ADD_Evqp_Ibs, I_ADD_Evqp_Ibs, I_ADD_Evqp_Ibs, I_ADD_Evqp_Ibs, I_ADD_Evqp_Ibs, I_ADD_Evqp_Ibs, I_ADD_Evqp_Ibs, I_ADD_Evqp_Ibs, 
	// 48
	I_OR_Evqp_Ibs, I_OR_Evqp_Ibs, I_OR_Evqp_Ibs, I_OR_Evqp_Ibs, I_OR_Evqp_Ibs, I_OR_Evqp_Ibs, I_OR_Evqp_Ibs, I_OR_Evqp_Ibs, 
	// 50
	I_ADC_Evqp_Ibs, I_ADC_Evqp_Ibs, I_ADC_Evqp_Ibs, I_ADC_Evqp_Ibs, I_ADC_Evqp_Ibs, I_ADC_Evqp_Ibs, I_ADC_Evqp_Ibs, I_ADC_Evqp_Ibs, 
	// 58
	I_SBB_Evqp_Ibs, I_SBB_Evqp_Ibs, I_SBB_Evqp_Ibs, I_SBB_Evqp_Ibs, I_SBB_Evqp_Ibs, I_SBB_Evqp_Ibs, I_SBB_Evqp_Ibs, I_SBB_Evqp_Ibs, 
	// 60
	I_AND_Evqp_Ibs, I_AND_Evqp_Ibs, I_AND_Evqp_Ibs, I_AND_Evqp_Ibs, I_AND_Evqp_Ibs, I_AND_Evqp_Ibs, I_AND_Evqp_Ibs, I_AND_Evqp_Ibs, 
	// 68
	I_SUB_Evqp_Ibs, I_SUB_Evqp_Ibs, I_SUB_Evqp_Ibs, I_SUB_Evqp_Ibs, I_SUB_Evqp_Ibs, I_SUB_Evqp_Ibs, I_SUB_Evqp_Ibs, I_SUB_Evqp_Ibs, 
	// 70
	I_XOR_Evqp_Ibs, I_XOR_Evqp_Ibs, I_XOR_Evqp_Ibs, I_XOR_Evqp_Ibs, I_XOR_Evqp_Ibs, I_XOR_Evqp_Ibs, I_XOR_Evqp_Ibs, I_XOR_Evqp_Ibs, 
	// 78
	I_CMP_Evqp_Ibs, I_CMP_Evqp_Ibs, I_CMP_Evqp_Ibs, I_CMP_Evqp_Ibs, I_CMP_Evqp_Ibs, I_CMP_Evqp_Ibs, I_CMP_Evqp_Ibs, I_CMP_Evqp_Ibs, 
	// 80
	I_ADD_Evqp_Ibs, I_ADD_Evqp_Ibs, I_ADD_Evqp_Ibs, I_ADD_Evqp_Ibs, I_ADD_Evqp_Ibs, I_ADD_Evqp_Ibs, I_ADD_Evqp_Ibs, I_ADD_Evqp_Ibs, 
	// 88
	I_OR_Evqp_Ibs, I_OR_Evqp_Ibs, I_OR_Evqp_Ibs, I_OR_Evqp_Ibs, I_OR_Evqp_Ibs, I_OR_Evqp_Ibs, I_OR_Evqp_Ibs, I_OR_Evqp_Ibs, 
	// 90
	I_ADC_Evqp_Ibs, I_ADC_Evqp_Ibs, I_ADC_Evqp_Ibs, I_ADC_Evqp_Ibs, I_ADC_Evqp_Ibs, I_ADC_Evqp_Ibs, I_ADC_Evqp_Ibs, I_ADC_Evqp_Ibs, 
	// 98
	I_SBB_Evqp_Ibs, I_SBB_Evqp_Ibs, I_SBB_Evqp_Ibs, I_SBB_Evqp_Ibs, I_SBB_Evqp_Ibs, I_SBB_Evqp_Ibs, I_SBB_Evqp_Ibs, I_SBB_Evqp_Ibs, 
	// A0
	I_AND_Evqp_Ibs, I_AND_Evqp_Ibs, I_AND_Evqp_Ibs, I_AND_Evqp_Ibs, I_AND_Evqp_Ibs, I_AND_Evqp_Ibs, I_AND_Evqp_Ibs, I_AND_Evqp_Ibs, 
	// A8
	I_SUB_Evqp_Ibs, I_SUB_Evqp_Ibs, I_SUB_Evqp_Ibs, I_SUB_Evqp_Ibs, I_SUB_Evqp_Ibs, I_SUB_Evqp_Ibs, I_SUB_Evqp_Ibs, I_SUB_Evqp_Ibs, 
	// B0
	I_XOR_Evqp_Ibs, I_XOR_Evqp_Ibs, I_XOR_Evqp_Ibs, I_XOR_Evqp_Ibs, I_XOR_Evqp_Ibs, I_XOR_Evqp_Ibs, I_XOR_Evqp_Ibs, I_XOR_Evqp_Ibs, 
	// B8
	I_CMP_Evqp_Ibs, I_CMP_Evqp_Ibs, I_CMP_Evqp_Ibs, I_CMP_Evqp_Ibs, I_CMP_Evqp_Ibs, I_CMP_Evqp_Ibs, I_CMP_Evqp_Ibs, I_CMP_Evqp_Ibs, 
	// C0
	I_ADD_Evqp_Ibs, I_ADD_Evqp_Ibs, I_ADD_Evqp_Ibs, I_ADD_Evqp_Ibs, I_ADD_Evqp_Ibs, I_ADD_Evqp_Ibs, I_ADD_Evqp_Ibs, I_ADD_Evqp_Ibs, 
	// C8
	I_OR_Evqp_Ibs, I_OR_Evqp_Ibs, I_OR_Evqp_Ibs, I_OR_Evqp_Ibs, I_OR_Evqp_Ibs, I_OR_Evqp_Ibs, I_OR_Evqp_Ibs, I_OR_Evqp_Ibs, 
	// D0
	I_ADC_Evqp_Ibs, I_ADC_Evqp_Ibs, I_ADC_Evqp_Ibs, I_ADC_Evqp_Ibs, I_ADC_Evqp_Ibs, I_ADC_Evqp_Ibs, I_ADC_Evqp_Ibs, I_ADC_Evqp_Ibs, 
	// D8
	I_SBB_Evqp_Ibs, I_SBB_Evqp_Ibs, I_SBB_Evqp_Ibs, I_SBB_Evqp_Ibs, I_SBB_Evqp_Ibs, I_SBB_Evqp_Ibs, I_SBB_Evqp_Ibs, I_SBB_Evqp_Ibs, 
	// E0
	I_AND_Evqp_Ibs, I_AND_Evqp_Ibs, I_AND_Evqp_Ibs, I_AND_Evqp_Ibs, I_AND_Evqp_Ibs, I_AND_Evqp_Ibs, I_AND_Evqp_Ibs, I_AND_Evqp_Ibs, 
	// E8
	I_SUB_Evqp_Ibs, I_SUB_Evqp_Ibs, I_SUB_Evqp_Ibs, I_SUB_Evqp_Ibs, I_SUB_Evqp_Ibs, I_SUB_Evqp_Ibs, I_SUB_Evqp_Ibs, I_SUB_Evqp_Ibs, 
	// F0
	I_XOR_Evqp_Ibs, I_XOR_Evqp_Ibs, I_XOR_Evqp_Ibs, I_XOR_Evqp_Ibs, I_XOR_Evqp_Ibs, I_XOR_Evqp_Ibs, I_XOR_Evqp_Ibs, I_XOR_Evqp_Ibs, 
	// F8
	I_CMP_Evqp_Ibs, I_CMP_Evqp_Ibs, I_CMP_Evqp_Ibs, I_CMP_Evqp_Ibs, I_CMP_Evqp_Ibs, I_CMP_Evqp_Ibs, I_CMP_Evqp_Ibs, I_CMP_Evqp_Ibs, 
};
const OpState CpuRunnerX86::table_8f[] = {
	// 00
	I_POP_Ev, I_POP_Ev, I_POP_Ev, I_POP_Ev, I_POP_Ev, I_POP_Ev, I_POP_Ev, I_POP_Ev, 
	// 08
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 10
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 18
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 20
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 28
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 30
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 38
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 40
	I_POP_Ev, I_POP_Ev, I_POP_Ev, I_POP_Ev, I_POP_Ev, I_POP_Ev, I_POP_Ev, I_POP_Ev, 
	// 48
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 50
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 58
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 60
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 68
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 70
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 78
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 80
	I_POP_Ev, I_POP_Ev, I_POP_Ev, I_POP_Ev, I_POP_Ev, I_POP_Ev, I_POP_Ev, I_POP_Ev, 
	// 88
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 90
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 98
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// A0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// A8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// C0
	I_POP_Ev, I_POP_Ev, I_POP_Ev, I_POP_Ev, I_POP_Ev, I_POP_Ev, I_POP_Ev, I_POP_Ev, 
	// C8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
};
const OpState CpuRunnerX86::table_c0[] = {
	// 00
	I_ROL_Eb_Ib, I_ROL_Eb_Ib, I_ROL_Eb_Ib, I_ROL_Eb_Ib, I_ROL_Eb_Ib, I_ROL_Eb_Ib, I_ROL_Eb_Ib, I_ROL_Eb_Ib, 
	// 08
	I_ROR_Eb_Ib, I_ROR_Eb_Ib, I_ROR_Eb_Ib, I_ROR_Eb_Ib, I_ROR_Eb_Ib, I_ROR_Eb_Ib, I_ROR_Eb_Ib, I_ROR_Eb_Ib, 
	// 10
	I_RCL_Eb_Ib, I_RCL_Eb_Ib, I_RCL_Eb_Ib, I_RCL_Eb_Ib, I_RCL_Eb_Ib, I_RCL_Eb_Ib, I_RCL_Eb_Ib, I_RCL_Eb_Ib, 
	// 18
	I_RCR_Eb_Ib, I_RCR_Eb_Ib, I_RCR_Eb_Ib, I_RCR_Eb_Ib, I_RCR_Eb_Ib, I_RCR_Eb_Ib, I_RCR_Eb_Ib, I_RCR_Eb_Ib, 
	// 20
	I_SHL_Eb_Ib, I_SHL_Eb_Ib, I_SHL_Eb_Ib, I_SHL_Eb_Ib, I_SHL_Eb_Ib, I_SHL_Eb_Ib, I_SHL_Eb_Ib, I_SHL_Eb_Ib, 
	// 28
	I_SHR_Eb_Ib, I_SHR_Eb_Ib, I_SHR_Eb_Ib, I_SHR_Eb_Ib, I_SHR_Eb_Ib, I_SHR_Eb_Ib, I_SHR_Eb_Ib, I_SHR_Eb_Ib, 
	// 30
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 38
	I_SAR_Eb_Ib, I_SAR_Eb_Ib, I_SAR_Eb_Ib, I_SAR_Eb_Ib, I_SAR_Eb_Ib, I_SAR_Eb_Ib, I_SAR_Eb_Ib, I_SAR_Eb_Ib, 
	// 40
	I_ROL_Eb_Ib, I_ROL_Eb_Ib, I_ROL_Eb_Ib, I_ROL_Eb_Ib, I_ROL_Eb_Ib, I_ROL_Eb_Ib, I_ROL_Eb_Ib, I_ROL_Eb_Ib, 
	// 48
	I_ROR_Eb_Ib, I_ROR_Eb_Ib, I_ROR_Eb_Ib, I_ROR_Eb_Ib, I_ROR_Eb_Ib, I_ROR_Eb_Ib, I_ROR_Eb_Ib, I_ROR_Eb_Ib, 
	// 50
	I_RCL_Eb_Ib, I_RCL_Eb_Ib, I_RCL_Eb_Ib, I_RCL_Eb_Ib, I_RCL_Eb_Ib, I_RCL_Eb_Ib, I_RCL_Eb_Ib, I_RCL_Eb_Ib, 
	// 58
	I_RCR_Eb_Ib, I_RCR_Eb_Ib, I_RCR_Eb_Ib, I_RCR_Eb_Ib, I_RCR_Eb_Ib, I_RCR_Eb_Ib, I_RCR_Eb_Ib, I_RCR_Eb_Ib, 
	// 60
	I_SHL_Eb_Ib, I_SHL_Eb_Ib, I_SHL_Eb_Ib, I_SHL_Eb_Ib, I_SHL_Eb_Ib, I_SHL_Eb_Ib, I_SHL_Eb_Ib, I_SHL_Eb_Ib, 
	// 68
	I_SHR_Eb_Ib, I_SHR_Eb_Ib, I_SHR_Eb_Ib, I_SHR_Eb_Ib, I_SHR_Eb_Ib, I_SHR_Eb_Ib, I_SHR_Eb_Ib, I_SHR_Eb_Ib, 
	// 70
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 78
	I_SAR_Eb_Ib, I_SAR_Eb_Ib, I_SAR_Eb_Ib, I_SAR_Eb_Ib, I_SAR_Eb_Ib, I_SAR_Eb_Ib, I_SAR_Eb_Ib, I_SAR_Eb_Ib, 
	// 80
	I_ROL_Eb_Ib, I_ROL_Eb_Ib, I_ROL_Eb_Ib, I_ROL_Eb_Ib, I_ROL_Eb_Ib, I_ROL_Eb_Ib, I_ROL_Eb_Ib, I_ROL_Eb_Ib, 
	// 88
	I_ROR_Eb_Ib, I_ROR_Eb_Ib, I_ROR_Eb_Ib, I_ROR_Eb_Ib, I_ROR_Eb_Ib, I_ROR_Eb_Ib, I_ROR_Eb_Ib, I_ROR_Eb_Ib, 
	// 90
	I_RCL_Eb_Ib, I_RCL_Eb_Ib, I_RCL_Eb_Ib, I_RCL_Eb_Ib, I_RCL_Eb_Ib, I_RCL_Eb_Ib, I_RCL_Eb_Ib, I_RCL_Eb_Ib, 
	// 98
	I_RCR_Eb_Ib, I_RCR_Eb_Ib, I_RCR_Eb_Ib, I_RCR_Eb_Ib, I_RCR_Eb_Ib, I_RCR_Eb_Ib, I_RCR_Eb_Ib, I_RCR_Eb_Ib, 
	// A0
	I_SHL_Eb_Ib, I_SHL_Eb_Ib, I_SHL_Eb_Ib, I_SHL_Eb_Ib, I_SHL_Eb_Ib, I_SHL_Eb_Ib, I_SHL_Eb_Ib, I_SHL_Eb_Ib, 
	// A8
	I_SHR_Eb_Ib, I_SHR_Eb_Ib, I_SHR_Eb_Ib, I_SHR_Eb_Ib, I_SHR_Eb_Ib, I_SHR_Eb_Ib, I_SHR_Eb_Ib, I_SHR_Eb_Ib, 
	// B0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B8
	I_SAR_Eb_Ib, I_SAR_Eb_Ib, I_SAR_Eb_Ib, I_SAR_Eb_Ib, I_SAR_Eb_Ib, I_SAR_Eb_Ib, I_SAR_Eb_Ib, I_SAR_Eb_Ib, 
	// C0
	I_ROL_Eb_Ib, I_ROL_Eb_Ib, I_ROL_Eb_Ib, I_ROL_Eb_Ib, I_ROL_Eb_Ib, I_ROL_Eb_Ib, I_ROL_Eb_Ib, I_ROL_Eb_Ib, 
	// C8
	I_ROR_Eb_Ib, I_ROR_Eb_Ib, I_ROR_Eb_Ib, I_ROR_Eb_Ib, I_ROR_Eb_Ib, I_ROR_Eb_Ib, I_ROR_Eb_Ib, I_ROR_Eb_Ib, 
	// D0
	I_RCL_Eb_Ib, I_RCL_Eb_Ib, I_RCL_Eb_Ib, I_RCL_Eb_Ib, I_RCL_Eb_Ib, I_RCL_Eb_Ib, I_RCL_Eb_Ib, I_RCL_Eb_Ib, 
	// D8
	I_RCR_Eb_Ib, I_RCR_Eb_Ib, I_RCR_Eb_Ib, I_RCR_Eb_Ib, I_RCR_Eb_Ib, I_RCR_Eb_Ib, I_RCR_Eb_Ib, I_RCR_Eb_Ib, 
	// E0
	I_SHL_Eb_Ib, I_SHL_Eb_Ib, I_SHL_Eb_Ib, I_SHL_Eb_Ib, I_SHL_Eb_Ib, I_SHL_Eb_Ib, I_SHL_Eb_Ib, I_SHL_Eb_Ib, 
	// E8
	I_SHR_Eb_Ib, I_SHR_Eb_Ib, I_SHR_Eb_Ib, I_SHR_Eb_Ib, I_SHR_Eb_Ib, I_SHR_Eb_Ib, I_SHR_Eb_Ib, I_SHR_Eb_Ib, 
	// F0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F8
	I_SAR_Eb_Ib, I_SAR_Eb_Ib, I_SAR_Eb_Ib, I_SAR_Eb_Ib, I_SAR_Eb_Ib, I_SAR_Eb_Ib, I_SAR_Eb_Ib, I_SAR_Eb_Ib, 
};
const OpState CpuRunnerX86::table_c1[] = {
	// 00
	I_ROL_Evqp_Ib, I_ROL_Evqp_Ib, I_ROL_Evqp_Ib, I_ROL_Evqp_Ib, I_ROL_Evqp_Ib, I_ROL_Evqp_Ib, I_ROL_Evqp_Ib, I_ROL_Evqp_Ib, 
	// 08
	I_ROR_Evqp_Ib, I_ROR_Evqp_Ib, I_ROR_Evqp_Ib, I_ROR_Evqp_Ib, I_ROR_Evqp_Ib, I_ROR_Evqp_Ib, I_ROR_Evqp_Ib, I_ROR_Evqp_Ib, 
	// 10
	I_RCL_Evqp_Ib, I_RCL_Evqp_Ib, I_RCL_Evqp_Ib, I_RCL_Evqp_Ib, I_RCL_Evqp_Ib, I_RCL_Evqp_Ib, I_RCL_Evqp_Ib, I_RCL_Evqp_Ib, 
	// 18
	I_RCR_Evqp_Ib, I_RCR_Evqp_Ib, I_RCR_Evqp_Ib, I_RCR_Evqp_Ib, I_RCR_Evqp_Ib, I_RCR_Evqp_Ib, I_RCR_Evqp_Ib, I_RCR_Evqp_Ib, 
	// 20
	I_SHL_Evqp_Ib, I_SHL_Evqp_Ib, I_SHL_Evqp_Ib, I_SHL_Evqp_Ib, I_SHL_Evqp_Ib, I_SHL_Evqp_Ib, I_SHL_Evqp_Ib, I_SHL_Evqp_Ib, 
	// 28
	I_SHR_Evqp_Ib, I_SHR_Evqp_Ib, I_SHR_Evqp_Ib, I_SHR_Evqp_Ib, I_SHR_Evqp_Ib, I_SHR_Evqp_Ib, I_SHR_Evqp_Ib, I_SHR_Evqp_Ib, 
	// 30
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 38
	I_SAR_Evqp_Ib, I_SAR_Evqp_Ib, I_SAR_Evqp_Ib, I_SAR_Evqp_Ib, I_SAR_Evqp_Ib, I_SAR_Evqp_Ib, I_SAR_Evqp_Ib, I_SAR_Evqp_Ib, 
	// 40
	I_ROL_Evqp_Ib, I_ROL_Evqp_Ib, I_ROL_Evqp_Ib, I_ROL_Evqp_Ib, I_ROL_Evqp_Ib, I_ROL_Evqp_Ib, I_ROL_Evqp_Ib, I_ROL_Evqp_Ib, 
	// 48
	I_ROR_Evqp_Ib, I_ROR_Evqp_Ib, I_ROR_Evqp_Ib, I_ROR_Evqp_Ib, I_ROR_Evqp_Ib, I_ROR_Evqp_Ib, I_ROR_Evqp_Ib, I_ROR_Evqp_Ib, 
	// 50
	I_RCL_Evqp_Ib, I_RCL_Evqp_Ib, I_RCL_Evqp_Ib, I_RCL_Evqp_Ib, I_RCL_Evqp_Ib, I_RCL_Evqp_Ib, I_RCL_Evqp_Ib, I_RCL_Evqp_Ib, 
	// 58
	I_RCR_Evqp_Ib, I_RCR_Evqp_Ib, I_RCR_Evqp_Ib, I_RCR_Evqp_Ib, I_RCR_Evqp_Ib, I_RCR_Evqp_Ib, I_RCR_Evqp_Ib, I_RCR_Evqp_Ib, 
	// 60
	I_SHL_Evqp_Ib, I_SHL_Evqp_Ib, I_SHL_Evqp_Ib, I_SHL_Evqp_Ib, I_SHL_Evqp_Ib, I_SHL_Evqp_Ib, I_SHL_Evqp_Ib, I_SHL_Evqp_Ib, 
	// 68
	I_SHR_Evqp_Ib, I_SHR_Evqp_Ib, I_SHR_Evqp_Ib, I_SHR_Evqp_Ib, I_SHR_Evqp_Ib, I_SHR_Evqp_Ib, I_SHR_Evqp_Ib, I_SHR_Evqp_Ib, 
	// 70
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 78
	I_SAR_Evqp_Ib, I_SAR_Evqp_Ib, I_SAR_Evqp_Ib, I_SAR_Evqp_Ib, I_SAR_Evqp_Ib, I_SAR_Evqp_Ib, I_SAR_Evqp_Ib, I_SAR_Evqp_Ib, 
	// 80
	I_ROL_Evqp_Ib, I_ROL_Evqp_Ib, I_ROL_Evqp_Ib, I_ROL_Evqp_Ib, I_ROL_Evqp_Ib, I_ROL_Evqp_Ib, I_ROL_Evqp_Ib, I_ROL_Evqp_Ib, 
	// 88
	I_ROR_Evqp_Ib, I_ROR_Evqp_Ib, I_ROR_Evqp_Ib, I_ROR_Evqp_Ib, I_ROR_Evqp_Ib, I_ROR_Evqp_Ib, I_ROR_Evqp_Ib, I_ROR_Evqp_Ib, 
	// 90
	I_RCL_Evqp_Ib, I_RCL_Evqp_Ib, I_RCL_Evqp_Ib, I_RCL_Evqp_Ib, I_RCL_Evqp_Ib, I_RCL_Evqp_Ib, I_RCL_Evqp_Ib, I_RCL_Evqp_Ib, 
	// 98
	I_RCR_Evqp_Ib, I_RCR_Evqp_Ib, I_RCR_Evqp_Ib, I_RCR_Evqp_Ib, I_RCR_Evqp_Ib, I_RCR_Evqp_Ib, I_RCR_Evqp_Ib, I_RCR_Evqp_Ib, 
	// A0
	I_SHL_Evqp_Ib, I_SHL_Evqp_Ib, I_SHL_Evqp_Ib, I_SHL_Evqp_Ib, I_SHL_Evqp_Ib, I_SHL_Evqp_Ib, I_SHL_Evqp_Ib, I_SHL_Evqp_Ib, 
	// A8
	I_SHR_Evqp_Ib, I_SHR_Evqp_Ib, I_SHR_Evqp_Ib, I_SHR_Evqp_Ib, I_SHR_Evqp_Ib, I_SHR_Evqp_Ib, I_SHR_Evqp_Ib, I_SHR_Evqp_Ib, 
	// B0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B8
	I_SAR_Evqp_Ib, I_SAR_Evqp_Ib, I_SAR_Evqp_Ib, I_SAR_Evqp_Ib, I_SAR_Evqp_Ib, I_SAR_Evqp_Ib, I_SAR_Evqp_Ib, I_SAR_Evqp_Ib, 
	// C0
	I_ROL_Evqp_Ib, I_ROL_Evqp_Ib, I_ROL_Evqp_Ib, I_ROL_Evqp_Ib, I_ROL_Evqp_Ib, I_ROL_Evqp_Ib, I_ROL_Evqp_Ib, I_ROL_Evqp_Ib, 
	// C8
	I_ROR_Evqp_Ib, I_ROR_Evqp_Ib, I_ROR_Evqp_Ib, I_ROR_Evqp_Ib, I_ROR_Evqp_Ib, I_ROR_Evqp_Ib, I_ROR_Evqp_Ib, I_ROR_Evqp_Ib, 
	// D0
	I_RCL_Evqp_Ib, I_RCL_Evqp_Ib, I_RCL_Evqp_Ib, I_RCL_Evqp_Ib, I_RCL_Evqp_Ib, I_RCL_Evqp_Ib, I_RCL_Evqp_Ib, I_RCL_Evqp_Ib, 
	// D8
	I_RCR_Evqp_Ib, I_RCR_Evqp_Ib, I_RCR_Evqp_Ib, I_RCR_Evqp_Ib, I_RCR_Evqp_Ib, I_RCR_Evqp_Ib, I_RCR_Evqp_Ib, I_RCR_Evqp_Ib, 
	// E0
	I_SHL_Evqp_Ib, I_SHL_Evqp_Ib, I_SHL_Evqp_Ib, I_SHL_Evqp_Ib, I_SHL_Evqp_Ib, I_SHL_Evqp_Ib, I_SHL_Evqp_Ib, I_SHL_Evqp_Ib, 
	// E8
	I_SHR_Evqp_Ib, I_SHR_Evqp_Ib, I_SHR_Evqp_Ib, I_SHR_Evqp_Ib, I_SHR_Evqp_Ib, I_SHR_Evqp_Ib, I_SHR_Evqp_Ib, I_SHR_Evqp_Ib, 
	// F0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F8
	I_SAR_Evqp_Ib, I_SAR_Evqp_Ib, I_SAR_Evqp_Ib, I_SAR_Evqp_Ib, I_SAR_Evqp_Ib, I_SAR_Evqp_Ib, I_SAR_Evqp_Ib, I_SAR_Evqp_Ib, 
};
const OpState CpuRunnerX86::table_c6[] = {
	// 00
	I_MOV_Eb_Ib, I_MOV_Eb_Ib, I_MOV_Eb_Ib, I_MOV_Eb_Ib, I_MOV_Eb_Ib, I_MOV_Eb_Ib, I_MOV_Eb_Ib, I_MOV_Eb_Ib, 
	// 08
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 10
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 18
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 20
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 28
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 30
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 38
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 40
	I_MOV_Eb_Ib, I_MOV_Eb_Ib, I_MOV_Eb_Ib, I_MOV_Eb_Ib, I_MOV_Eb_Ib, I_MOV_Eb_Ib, I_MOV_Eb_Ib, I_MOV_Eb_Ib, 
	// 48
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 50
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 58
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 60
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 68
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 70
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 78
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 80
	I_MOV_Eb_Ib, I_MOV_Eb_Ib, I_MOV_Eb_Ib, I_MOV_Eb_Ib, I_MOV_Eb_Ib, I_MOV_Eb_Ib, I_MOV_Eb_Ib, I_MOV_Eb_Ib, 
	// 88
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 90
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 98
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// A0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// A8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// C0
	I_MOV_Eb_Ib, I_MOV_Eb_Ib, I_MOV_Eb_Ib, I_MOV_Eb_Ib, I_MOV_Eb_Ib, I_MOV_Eb_Ib, I_MOV_Eb_Ib, I_MOV_Eb_Ib, 
	// C8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
};
const OpState CpuRunnerX86::table_c7[] = {
	// 00
	I_MOV_Evqp_Ivds, I_MOV_Evqp_Ivds, I_MOV_Evqp_Ivds, I_MOV_Evqp_Ivds, I_MOV_Evqp_Ivds, I_MOV_Evqp_Ivds, I_MOV_Evqp_Ivds, I_MOV_Evqp_Ivds, 
	// 08
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 10
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 18
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 20
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 28
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 30
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 38
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 40
	I_MOV_Evqp_Ivds, I_MOV_Evqp_Ivds, I_MOV_Evqp_Ivds, I_MOV_Evqp_Ivds, I_MOV_Evqp_Ivds, I_MOV_Evqp_Ivds, I_MOV_Evqp_Ivds, I_MOV_Evqp_Ivds, 
	// 48
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 50
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 58
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 60
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 68
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 70
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 78
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 80
	I_MOV_Evqp_Ivds, I_MOV_Evqp_Ivds, I_MOV_Evqp_Ivds, I_MOV_Evqp_Ivds, I_MOV_Evqp_Ivds, I_MOV_Evqp_Ivds, I_MOV_Evqp_Ivds, I_MOV_Evqp_Ivds, 
	// 88
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 90
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 98
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// A0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// A8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// C0
	I_MOV_Evqp_Ivds, I_MOV_Evqp_Ivds, I_MOV_Evqp_Ivds, I_MOV_Evqp_Ivds, I_MOV_Evqp_Ivds, I_MOV_Evqp_Ivds, I_MOV_Evqp_Ivds, I_MOV_Evqp_Ivds, 
	// C8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
};
const OpState CpuRunnerX86::table_d0[] = {
	// 00
	I_ROL_Eb_I, I_ROL_Eb_I, I_ROL_Eb_I, I_ROL_Eb_I, I_ROL_Eb_I, I_ROL_Eb_I, I_ROL_Eb_I, I_ROL_Eb_I, 
	// 08
	I_ROR_Eb_I, I_ROR_Eb_I, I_ROR_Eb_I, I_ROR_Eb_I, I_ROR_Eb_I, I_ROR_Eb_I, I_ROR_Eb_I, I_ROR_Eb_I, 
	// 10
	I_RCL_Eb_I, I_RCL_Eb_I, I_RCL_Eb_I, I_RCL_Eb_I, I_RCL_Eb_I, I_RCL_Eb_I, I_RCL_Eb_I, I_RCL_Eb_I, 
	// 18
	I_RCR_Eb_I, I_RCR_Eb_I, I_RCR_Eb_I, I_RCR_Eb_I, I_RCR_Eb_I, I_RCR_Eb_I, I_RCR_Eb_I, I_RCR_Eb_I, 
	// 20
	I_SHL_Eb_I, I_SHL_Eb_I, I_SHL_Eb_I, I_SHL_Eb_I, I_SHL_Eb_I, I_SHL_Eb_I, I_SHL_Eb_I, I_SHL_Eb_I, 
	// 28
	I_SHR_Eb_I, I_SHR_Eb_I, I_SHR_Eb_I, I_SHR_Eb_I, I_SHR_Eb_I, I_SHR_Eb_I, I_SHR_Eb_I, I_SHR_Eb_I, 
	// 30
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 38
	I_SAR_Eb_I, I_SAR_Eb_I, I_SAR_Eb_I, I_SAR_Eb_I, I_SAR_Eb_I, I_SAR_Eb_I, I_SAR_Eb_I, I_SAR_Eb_I, 
	// 40
	I_ROL_Eb_I, I_ROL_Eb_I, I_ROL_Eb_I, I_ROL_Eb_I, I_ROL_Eb_I, I_ROL_Eb_I, I_ROL_Eb_I, I_ROL_Eb_I, 
	// 48
	I_ROR_Eb_I, I_ROR_Eb_I, I_ROR_Eb_I, I_ROR_Eb_I, I_ROR_Eb_I, I_ROR_Eb_I, I_ROR_Eb_I, I_ROR_Eb_I, 
	// 50
	I_RCL_Eb_I, I_RCL_Eb_I, I_RCL_Eb_I, I_RCL_Eb_I, I_RCL_Eb_I, I_RCL_Eb_I, I_RCL_Eb_I, I_RCL_Eb_I, 
	// 58
	I_RCR_Eb_I, I_RCR_Eb_I, I_RCR_Eb_I, I_RCR_Eb_I, I_RCR_Eb_I, I_RCR_Eb_I, I_RCR_Eb_I, I_RCR_Eb_I, 
	// 60
	I_SHL_Eb_I, I_SHL_Eb_I, I_SHL_Eb_I, I_SHL_Eb_I, I_SHL_Eb_I, I_SHL_Eb_I, I_SHL_Eb_I, I_SHL_Eb_I, 
	// 68
	I_SHR_Eb_I, I_SHR_Eb_I, I_SHR_Eb_I, I_SHR_Eb_I, I_SHR_Eb_I, I_SHR_Eb_I, I_SHR_Eb_I, I_SHR_Eb_I, 
	// 70
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 78
	I_SAR_Eb_I, I_SAR_Eb_I, I_SAR_Eb_I, I_SAR_Eb_I, I_SAR_Eb_I, I_SAR_Eb_I, I_SAR_Eb_I, I_SAR_Eb_I, 
	// 80
	I_ROL_Eb_I, I_ROL_Eb_I, I_ROL_Eb_I, I_ROL_Eb_I, I_ROL_Eb_I, I_ROL_Eb_I, I_ROL_Eb_I, I_ROL_Eb_I, 
	// 88
	I_ROR_Eb_I, I_ROR_Eb_I, I_ROR_Eb_I, I_ROR_Eb_I, I_ROR_Eb_I, I_ROR_Eb_I, I_ROR_Eb_I, I_ROR_Eb_I, 
	// 90
	I_RCL_Eb_I, I_RCL_Eb_I, I_RCL_Eb_I, I_RCL_Eb_I, I_RCL_Eb_I, I_RCL_Eb_I, I_RCL_Eb_I, I_RCL_Eb_I, 
	// 98
	I_RCR_Eb_I, I_RCR_Eb_I, I_RCR_Eb_I, I_RCR_Eb_I, I_RCR_Eb_I, I_RCR_Eb_I, I_RCR_Eb_I, I_RCR_Eb_I, 
	// A0
	I_SHL_Eb_I, I_SHL_Eb_I, I_SHL_Eb_I, I_SHL_Eb_I, I_SHL_Eb_I, I_SHL_Eb_I, I_SHL_Eb_I, I_SHL_Eb_I, 
	// A8
	I_SHR_Eb_I, I_SHR_Eb_I, I_SHR_Eb_I, I_SHR_Eb_I, I_SHR_Eb_I, I_SHR_Eb_I, I_SHR_Eb_I, I_SHR_Eb_I, 
	// B0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B8
	I_SAR_Eb_I, I_SAR_Eb_I, I_SAR_Eb_I, I_SAR_Eb_I, I_SAR_Eb_I, I_SAR_Eb_I, I_SAR_Eb_I, I_SAR_Eb_I, 
	// C0
	I_ROL_Eb_I, I_ROL_Eb_I, I_ROL_Eb_I, I_ROL_Eb_I, I_ROL_Eb_I, I_ROL_Eb_I, I_ROL_Eb_I, I_ROL_Eb_I, 
	// C8
	I_ROR_Eb_I, I_ROR_Eb_I, I_ROR_Eb_I, I_ROR_Eb_I, I_ROR_Eb_I, I_ROR_Eb_I, I_ROR_Eb_I, I_ROR_Eb_I, 
	// D0
	I_RCL_Eb_I, I_RCL_Eb_I, I_RCL_Eb_I, I_RCL_Eb_I, I_RCL_Eb_I, I_RCL_Eb_I, I_RCL_Eb_I, I_RCL_Eb_I, 
	// D8
	I_RCR_Eb_I, I_RCR_Eb_I, I_RCR_Eb_I, I_RCR_Eb_I, I_RCR_Eb_I, I_RCR_Eb_I, I_RCR_Eb_I, I_RCR_Eb_I, 
	// E0
	I_SHL_Eb_I, I_SHL_Eb_I, I_SHL_Eb_I, I_SHL_Eb_I, I_SHL_Eb_I, I_SHL_Eb_I, I_SHL_Eb_I, I_SHL_Eb_I, 
	// E8
	I_SHR_Eb_I, I_SHR_Eb_I, I_SHR_Eb_I, I_SHR_Eb_I, I_SHR_Eb_I, I_SHR_Eb_I, I_SHR_Eb_I, I_SHR_Eb_I, 
	// F0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F8
	I_SAR_Eb_I, I_SAR_Eb_I, I_SAR_Eb_I, I_SAR_Eb_I, I_SAR_Eb_I, I_SAR_Eb_I, I_SAR_Eb_I, I_SAR_Eb_I, 
};
const OpState CpuRunnerX86::table_d1[] = {
	// 00
	I_ROL_Evqp_I, I_ROL_Evqp_I, I_ROL_Evqp_I, I_ROL_Evqp_I, I_ROL_Evqp_I, I_ROL_Evqp_I, I_ROL_Evqp_I, I_ROL_Evqp_I, 
	// 08
	I_ROR_Evqp_I, I_ROR_Evqp_I, I_ROR_Evqp_I, I_ROR_Evqp_I, I_ROR_Evqp_I, I_ROR_Evqp_I, I_ROR_Evqp_I, I_ROR_Evqp_I, 
	// 10
	I_RCL_Evqp_I, I_RCL_Evqp_I, I_RCL_Evqp_I, I_RCL_Evqp_I, I_RCL_Evqp_I, I_RCL_Evqp_I, I_RCL_Evqp_I, I_RCL_Evqp_I, 
	// 18
	I_RCR_Evqp_I, I_RCR_Evqp_I, I_RCR_Evqp_I, I_RCR_Evqp_I, I_RCR_Evqp_I, I_RCR_Evqp_I, I_RCR_Evqp_I, I_RCR_Evqp_I, 
	// 20
	I_SHL_Evqp_I, I_SHL_Evqp_I, I_SHL_Evqp_I, I_SHL_Evqp_I, I_SHL_Evqp_I, I_SHL_Evqp_I, I_SHL_Evqp_I, I_SHL_Evqp_I, 
	// 28
	I_SHR_Evqp_I, I_SHR_Evqp_I, I_SHR_Evqp_I, I_SHR_Evqp_I, I_SHR_Evqp_I, I_SHR_Evqp_I, I_SHR_Evqp_I, I_SHR_Evqp_I, 
	// 30
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 38
	I_SAR_Evqp_I, I_SAR_Evqp_I, I_SAR_Evqp_I, I_SAR_Evqp_I, I_SAR_Evqp_I, I_SAR_Evqp_I, I_SAR_Evqp_I, I_SAR_Evqp_I, 
	// 40
	I_ROL_Evqp_I, I_ROL_Evqp_I, I_ROL_Evqp_I, I_ROL_Evqp_I, I_ROL_Evqp_I, I_ROL_Evqp_I, I_ROL_Evqp_I, I_ROL_Evqp_I, 
	// 48
	I_ROR_Evqp_I, I_ROR_Evqp_I, I_ROR_Evqp_I, I_ROR_Evqp_I, I_ROR_Evqp_I, I_ROR_Evqp_I, I_ROR_Evqp_I, I_ROR_Evqp_I, 
	// 50
	I_RCL_Evqp_I, I_RCL_Evqp_I, I_RCL_Evqp_I, I_RCL_Evqp_I, I_RCL_Evqp_I, I_RCL_Evqp_I, I_RCL_Evqp_I, I_RCL_Evqp_I, 
	// 58
	I_RCR_Evqp_I, I_RCR_Evqp_I, I_RCR_Evqp_I, I_RCR_Evqp_I, I_RCR_Evqp_I, I_RCR_Evqp_I, I_RCR_Evqp_I, I_RCR_Evqp_I, 
	// 60
	I_SHL_Evqp_I, I_SHL_Evqp_I, I_SHL_Evqp_I, I_SHL_Evqp_I, I_SHL_Evqp_I, I_SHL_Evqp_I, I_SHL_Evqp_I, I_SHL_Evqp_I, 
	// 68
	I_SHR_Evqp_I, I_SHR_Evqp_I, I_SHR_Evqp_I, I_SHR_Evqp_I, I_SHR_Evqp_I, I_SHR_Evqp_I, I_SHR_Evqp_I, I_SHR_Evqp_I, 
	// 70
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 78
	I_SAR_Evqp_I, I_SAR_Evqp_I, I_SAR_Evqp_I, I_SAR_Evqp_I, I_SAR_Evqp_I, I_SAR_Evqp_I, I_SAR_Evqp_I, I_SAR_Evqp_I, 
	// 80
	I_ROL_Evqp_I, I_ROL_Evqp_I, I_ROL_Evqp_I, I_ROL_Evqp_I, I_ROL_Evqp_I, I_ROL_Evqp_I, I_ROL_Evqp_I, I_ROL_Evqp_I, 
	// 88
	I_ROR_Evqp_I, I_ROR_Evqp_I, I_ROR_Evqp_I, I_ROR_Evqp_I, I_ROR_Evqp_I, I_ROR_Evqp_I, I_ROR_Evqp_I, I_ROR_Evqp_I, 
	// 90
	I_RCL_Evqp_I, I_RCL_Evqp_I, I_RCL_Evqp_I, I_RCL_Evqp_I, I_RCL_Evqp_I, I_RCL_Evqp_I, I_RCL_Evqp_I, I_RCL_Evqp_I, 
	// 98
	I_RCR_Evqp_I, I_RCR_Evqp_I, I_RCR_Evqp_I, I_RCR_Evqp_I, I_RCR_Evqp_I, I_RCR_Evqp_I, I_RCR_Evqp_I, I_RCR_Evqp_I, 
	// A0
	I_SHL_Evqp_I, I_SHL_Evqp_I, I_SHL_Evqp_I, I_SHL_Evqp_I, I_SHL_Evqp_I, I_SHL_Evqp_I, I_SHL_Evqp_I, I_SHL_Evqp_I, 
	// A8
	I_SHR_Evqp_I, I_SHR_Evqp_I, I_SHR_Evqp_I, I_SHR_Evqp_I, I_SHR_Evqp_I, I_SHR_Evqp_I, I_SHR_Evqp_I, I_SHR_Evqp_I, 
	// B0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B8
	I_SAR_Evqp_I, I_SAR_Evqp_I, I_SAR_Evqp_I, I_SAR_Evqp_I, I_SAR_Evqp_I, I_SAR_Evqp_I, I_SAR_Evqp_I, I_SAR_Evqp_I, 
	// C0
	I_ROL_Evqp_I, I_ROL_Evqp_I, I_ROL_Evqp_I, I_ROL_Evqp_I, I_ROL_Evqp_I, I_ROL_Evqp_I, I_ROL_Evqp_I, I_ROL_Evqp_I, 
	// C8
	I_ROR_Evqp_I, I_ROR_Evqp_I, I_ROR_Evqp_I, I_ROR_Evqp_I, I_ROR_Evqp_I, I_ROR_Evqp_I, I_ROR_Evqp_I, I_ROR_Evqp_I, 
	// D0
	I_RCL_Evqp_I, I_RCL_Evqp_I, I_RCL_Evqp_I, I_RCL_Evqp_I, I_RCL_Evqp_I, I_RCL_Evqp_I, I_RCL_Evqp_I, I_RCL_Evqp_I, 
	// D8
	I_RCR_Evqp_I, I_RCR_Evqp_I, I_RCR_Evqp_I, I_RCR_Evqp_I, I_RCR_Evqp_I, I_RCR_Evqp_I, I_RCR_Evqp_I, I_RCR_Evqp_I, 
	// E0
	I_SHL_Evqp_I, I_SHL_Evqp_I, I_SHL_Evqp_I, I_SHL_Evqp_I, I_SHL_Evqp_I, I_SHL_Evqp_I, I_SHL_Evqp_I, I_SHL_Evqp_I, 
	// E8
	I_SHR_Evqp_I, I_SHR_Evqp_I, I_SHR_Evqp_I, I_SHR_Evqp_I, I_SHR_Evqp_I, I_SHR_Evqp_I, I_SHR_Evqp_I, I_SHR_Evqp_I, 
	// F0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F8
	I_SAR_Evqp_I, I_SAR_Evqp_I, I_SAR_Evqp_I, I_SAR_Evqp_I, I_SAR_Evqp_I, I_SAR_Evqp_I, I_SAR_Evqp_I, I_SAR_Evqp_I, 
};
const OpState CpuRunnerX86::table_d2[] = {
	// 00
	I_ROL_Eb_CL, I_ROL_Eb_CL, I_ROL_Eb_CL, I_ROL_Eb_CL, I_ROL_Eb_CL, I_ROL_Eb_CL, I_ROL_Eb_CL, I_ROL_Eb_CL, 
	// 08
	I_ROR_Eb_CL, I_ROR_Eb_CL, I_ROR_Eb_CL, I_ROR_Eb_CL, I_ROR_Eb_CL, I_ROR_Eb_CL, I_ROR_Eb_CL, I_ROR_Eb_CL, 
	// 10
	I_RCL_Eb_CL, I_RCL_Eb_CL, I_RCL_Eb_CL, I_RCL_Eb_CL, I_RCL_Eb_CL, I_RCL_Eb_CL, I_RCL_Eb_CL, I_RCL_Eb_CL, 
	// 18
	I_RCR_Eb_CL, I_RCR_Eb_CL, I_RCR_Eb_CL, I_RCR_Eb_CL, I_RCR_Eb_CL, I_RCR_Eb_CL, I_RCR_Eb_CL, I_RCR_Eb_CL, 
	// 20
	I_SHL_Eb_CL, I_SHL_Eb_CL, I_SHL_Eb_CL, I_SHL_Eb_CL, I_SHL_Eb_CL, I_SHL_Eb_CL, I_SHL_Eb_CL, I_SHL_Eb_CL, 
	// 28
	I_SHR_Eb_CL, I_SHR_Eb_CL, I_SHR_Eb_CL, I_SHR_Eb_CL, I_SHR_Eb_CL, I_SHR_Eb_CL, I_SHR_Eb_CL, I_SHR_Eb_CL, 
	// 30
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 38
	I_SAR_Eb_CL, I_SAR_Eb_CL, I_SAR_Eb_CL, I_SAR_Eb_CL, I_SAR_Eb_CL, I_SAR_Eb_CL, I_SAR_Eb_CL, I_SAR_Eb_CL, 
	// 40
	I_ROL_Eb_CL, I_ROL_Eb_CL, I_ROL_Eb_CL, I_ROL_Eb_CL, I_ROL_Eb_CL, I_ROL_Eb_CL, I_ROL_Eb_CL, I_ROL_Eb_CL, 
	// 48
	I_ROR_Eb_CL, I_ROR_Eb_CL, I_ROR_Eb_CL, I_ROR_Eb_CL, I_ROR_Eb_CL, I_ROR_Eb_CL, I_ROR_Eb_CL, I_ROR_Eb_CL, 
	// 50
	I_RCL_Eb_CL, I_RCL_Eb_CL, I_RCL_Eb_CL, I_RCL_Eb_CL, I_RCL_Eb_CL, I_RCL_Eb_CL, I_RCL_Eb_CL, I_RCL_Eb_CL, 
	// 58
	I_RCR_Eb_CL, I_RCR_Eb_CL, I_RCR_Eb_CL, I_RCR_Eb_CL, I_RCR_Eb_CL, I_RCR_Eb_CL, I_RCR_Eb_CL, I_RCR_Eb_CL, 
	// 60
	I_SHL_Eb_CL, I_SHL_Eb_CL, I_SHL_Eb_CL, I_SHL_Eb_CL, I_SHL_Eb_CL, I_SHL_Eb_CL, I_SHL_Eb_CL, I_SHL_Eb_CL, 
	// 68
	I_SHR_Eb_CL, I_SHR_Eb_CL, I_SHR_Eb_CL, I_SHR_Eb_CL, I_SHR_Eb_CL, I_SHR_Eb_CL, I_SHR_Eb_CL, I_SHR_Eb_CL, 
	// 70
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 78
	I_SAR_Eb_CL, I_SAR_Eb_CL, I_SAR_Eb_CL, I_SAR_Eb_CL, I_SAR_Eb_CL, I_SAR_Eb_CL, I_SAR_Eb_CL, I_SAR_Eb_CL, 
	// 80
	I_ROL_Eb_CL, I_ROL_Eb_CL, I_ROL_Eb_CL, I_ROL_Eb_CL, I_ROL_Eb_CL, I_ROL_Eb_CL, I_ROL_Eb_CL, I_ROL_Eb_CL, 
	// 88
	I_ROR_Eb_CL, I_ROR_Eb_CL, I_ROR_Eb_CL, I_ROR_Eb_CL, I_ROR_Eb_CL, I_ROR_Eb_CL, I_ROR_Eb_CL, I_ROR_Eb_CL, 
	// 90
	I_RCL_Eb_CL, I_RCL_Eb_CL, I_RCL_Eb_CL, I_RCL_Eb_CL, I_RCL_Eb_CL, I_RCL_Eb_CL, I_RCL_Eb_CL, I_RCL_Eb_CL, 
	// 98
	I_RCR_Eb_CL, I_RCR_Eb_CL, I_RCR_Eb_CL, I_RCR_Eb_CL, I_RCR_Eb_CL, I_RCR_Eb_CL, I_RCR_Eb_CL, I_RCR_Eb_CL, 
	// A0
	I_SHL_Eb_CL, I_SHL_Eb_CL, I_SHL_Eb_CL, I_SHL_Eb_CL, I_SHL_Eb_CL, I_SHL_Eb_CL, I_SHL_Eb_CL, I_SHL_Eb_CL, 
	// A8
	I_SHR_Eb_CL, I_SHR_Eb_CL, I_SHR_Eb_CL, I_SHR_Eb_CL, I_SHR_Eb_CL, I_SHR_Eb_CL, I_SHR_Eb_CL, I_SHR_Eb_CL, 
	// B0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B8
	I_SAR_Eb_CL, I_SAR_Eb_CL, I_SAR_Eb_CL, I_SAR_Eb_CL, I_SAR_Eb_CL, I_SAR_Eb_CL, I_SAR_Eb_CL, I_SAR_Eb_CL, 
	// C0
	I_ROL_Eb_CL, I_ROL_Eb_CL, I_ROL_Eb_CL, I_ROL_Eb_CL, I_ROL_Eb_CL, I_ROL_Eb_CL, I_ROL_Eb_CL, I_ROL_Eb_CL, 
	// C8
	I_ROR_Eb_CL, I_ROR_Eb_CL, I_ROR_Eb_CL, I_ROR_Eb_CL, I_ROR_Eb_CL, I_ROR_Eb_CL, I_ROR_Eb_CL, I_ROR_Eb_CL, 
	// D0
	I_RCL_Eb_CL, I_RCL_Eb_CL, I_RCL_Eb_CL, I_RCL_Eb_CL, I_RCL_Eb_CL, I_RCL_Eb_CL, I_RCL_Eb_CL, I_RCL_Eb_CL, 
	// D8
	I_RCR_Eb_CL, I_RCR_Eb_CL, I_RCR_Eb_CL, I_RCR_Eb_CL, I_RCR_Eb_CL, I_RCR_Eb_CL, I_RCR_Eb_CL, I_RCR_Eb_CL, 
	// E0
	I_SHL_Eb_CL, I_SHL_Eb_CL, I_SHL_Eb_CL, I_SHL_Eb_CL, I_SHL_Eb_CL, I_SHL_Eb_CL, I_SHL_Eb_CL, I_SHL_Eb_CL, 
	// E8
	I_SHR_Eb_CL, I_SHR_Eb_CL, I_SHR_Eb_CL, I_SHR_Eb_CL, I_SHR_Eb_CL, I_SHR_Eb_CL, I_SHR_Eb_CL, I_SHR_Eb_CL, 
	// F0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F8
	I_SAR_Eb_CL, I_SAR_Eb_CL, I_SAR_Eb_CL, I_SAR_Eb_CL, I_SAR_Eb_CL, I_SAR_Eb_CL, I_SAR_Eb_CL, I_SAR_Eb_CL, 
};
const OpState CpuRunnerX86::table_d3[] = {
	// 00
	I_ROL_Evqp_CL, I_ROL_Evqp_CL, I_ROL_Evqp_CL, I_ROL_Evqp_CL, I_ROL_Evqp_CL, I_ROL_Evqp_CL, I_ROL_Evqp_CL, I_ROL_Evqp_CL, 
	// 08
	I_ROR_Evqp_CL, I_ROR_Evqp_CL, I_ROR_Evqp_CL, I_ROR_Evqp_CL, I_ROR_Evqp_CL, I_ROR_Evqp_CL, I_ROR_Evqp_CL, I_ROR_Evqp_CL, 
	// 10
	I_RCL_Evqp_CL, I_RCL_Evqp_CL, I_RCL_Evqp_CL, I_RCL_Evqp_CL, I_RCL_Evqp_CL, I_RCL_Evqp_CL, I_RCL_Evqp_CL, I_RCL_Evqp_CL, 
	// 18
	I_RCR_Evqp_CL, I_RCR_Evqp_CL, I_RCR_Evqp_CL, I_RCR_Evqp_CL, I_RCR_Evqp_CL, I_RCR_Evqp_CL, I_RCR_Evqp_CL, I_RCR_Evqp_CL, 
	// 20
	I_SHL_Evqp_CL, I_SHL_Evqp_CL, I_SHL_Evqp_CL, I_SHL_Evqp_CL, I_SHL_Evqp_CL, I_SHL_Evqp_CL, I_SHL_Evqp_CL, I_SHL_Evqp_CL, 
	// 28
	I_SHR_Evqp_CL, I_SHR_Evqp_CL, I_SHR_Evqp_CL, I_SHR_Evqp_CL, I_SHR_Evqp_CL, I_SHR_Evqp_CL, I_SHR_Evqp_CL, I_SHR_Evqp_CL, 
	// 30
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 38
	I_SAR_Evqp_CL, I_SAR_Evqp_CL, I_SAR_Evqp_CL, I_SAR_Evqp_CL, I_SAR_Evqp_CL, I_SAR_Evqp_CL, I_SAR_Evqp_CL, I_SAR_Evqp_CL, 
	// 40
	I_ROL_Evqp_CL, I_ROL_Evqp_CL, I_ROL_Evqp_CL, I_ROL_Evqp_CL, I_ROL_Evqp_CL, I_ROL_Evqp_CL, I_ROL_Evqp_CL, I_ROL_Evqp_CL, 
	// 48
	I_ROR_Evqp_CL, I_ROR_Evqp_CL, I_ROR_Evqp_CL, I_ROR_Evqp_CL, I_ROR_Evqp_CL, I_ROR_Evqp_CL, I_ROR_Evqp_CL, I_ROR_Evqp_CL, 
	// 50
	I_RCL_Evqp_CL, I_RCL_Evqp_CL, I_RCL_Evqp_CL, I_RCL_Evqp_CL, I_RCL_Evqp_CL, I_RCL_Evqp_CL, I_RCL_Evqp_CL, I_RCL_Evqp_CL, 
	// 58
	I_RCR_Evqp_CL, I_RCR_Evqp_CL, I_RCR_Evqp_CL, I_RCR_Evqp_CL, I_RCR_Evqp_CL, I_RCR_Evqp_CL, I_RCR_Evqp_CL, I_RCR_Evqp_CL, 
	// 60
	I_SHL_Evqp_CL, I_SHL_Evqp_CL, I_SHL_Evqp_CL, I_SHL_Evqp_CL, I_SHL_Evqp_CL, I_SHL_Evqp_CL, I_SHL_Evqp_CL, I_SHL_Evqp_CL, 
	// 68
	I_SHR_Evqp_CL, I_SHR_Evqp_CL, I_SHR_Evqp_CL, I_SHR_Evqp_CL, I_SHR_Evqp_CL, I_SHR_Evqp_CL, I_SHR_Evqp_CL, I_SHR_Evqp_CL, 
	// 70
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 78
	I_SAR_Evqp_CL, I_SAR_Evqp_CL, I_SAR_Evqp_CL, I_SAR_Evqp_CL, I_SAR_Evqp_CL, I_SAR_Evqp_CL, I_SAR_Evqp_CL, I_SAR_Evqp_CL, 
	// 80
	I_ROL_Evqp_CL, I_ROL_Evqp_CL, I_ROL_Evqp_CL, I_ROL_Evqp_CL, I_ROL_Evqp_CL, I_ROL_Evqp_CL, I_ROL_Evqp_CL, I_ROL_Evqp_CL, 
	// 88
	I_ROR_Evqp_CL, I_ROR_Evqp_CL, I_ROR_Evqp_CL, I_ROR_Evqp_CL, I_ROR_Evqp_CL, I_ROR_Evqp_CL, I_ROR_Evqp_CL, I_ROR_Evqp_CL, 
	// 90
	I_RCL_Evqp_CL, I_RCL_Evqp_CL, I_RCL_Evqp_CL, I_RCL_Evqp_CL, I_RCL_Evqp_CL, I_RCL_Evqp_CL, I_RCL_Evqp_CL, I_RCL_Evqp_CL, 
	// 98
	I_RCR_Evqp_CL, I_RCR_Evqp_CL, I_RCR_Evqp_CL, I_RCR_Evqp_CL, I_RCR_Evqp_CL, I_RCR_Evqp_CL, I_RCR_Evqp_CL, I_RCR_Evqp_CL, 
	// A0
	I_SHL_Evqp_CL, I_SHL_Evqp_CL, I_SHL_Evqp_CL, I_SHL_Evqp_CL, I_SHL_Evqp_CL, I_SHL_Evqp_CL, I_SHL_Evqp_CL, I_SHL_Evqp_CL, 
	// A8
	I_SHR_Evqp_CL, I_SHR_Evqp_CL, I_SHR_Evqp_CL, I_SHR_Evqp_CL, I_SHR_Evqp_CL, I_SHR_Evqp_CL, I_SHR_Evqp_CL, I_SHR_Evqp_CL, 
	// B0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B8
	I_SAR_Evqp_CL, I_SAR_Evqp_CL, I_SAR_Evqp_CL, I_SAR_Evqp_CL, I_SAR_Evqp_CL, I_SAR_Evqp_CL, I_SAR_Evqp_CL, I_SAR_Evqp_CL, 
	// C0
	I_ROL_Evqp_CL, I_ROL_Evqp_CL, I_ROL_Evqp_CL, I_ROL_Evqp_CL, I_ROL_Evqp_CL, I_ROL_Evqp_CL, I_ROL_Evqp_CL, I_ROL_Evqp_CL, 
	// C8
	I_ROR_Evqp_CL, I_ROR_Evqp_CL, I_ROR_Evqp_CL, I_ROR_Evqp_CL, I_ROR_Evqp_CL, I_ROR_Evqp_CL, I_ROR_Evqp_CL, I_ROR_Evqp_CL, 
	// D0
	I_RCL_Evqp_CL, I_RCL_Evqp_CL, I_RCL_Evqp_CL, I_RCL_Evqp_CL, I_RCL_Evqp_CL, I_RCL_Evqp_CL, I_RCL_Evqp_CL, I_RCL_Evqp_CL, 
	// D8
	I_RCR_Evqp_CL, I_RCR_Evqp_CL, I_RCR_Evqp_CL, I_RCR_Evqp_CL, I_RCR_Evqp_CL, I_RCR_Evqp_CL, I_RCR_Evqp_CL, I_RCR_Evqp_CL, 
	// E0
	I_SHL_Evqp_CL, I_SHL_Evqp_CL, I_SHL_Evqp_CL, I_SHL_Evqp_CL, I_SHL_Evqp_CL, I_SHL_Evqp_CL, I_SHL_Evqp_CL, I_SHL_Evqp_CL, 
	// E8
	I_SHR_Evqp_CL, I_SHR_Evqp_CL, I_SHR_Evqp_CL, I_SHR_Evqp_CL, I_SHR_Evqp_CL, I_SHR_Evqp_CL, I_SHR_Evqp_CL, I_SHR_Evqp_CL, 
	// F0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F8
	I_SAR_Evqp_CL, I_SAR_Evqp_CL, I_SAR_Evqp_CL, I_SAR_Evqp_CL, I_SAR_Evqp_CL, I_SAR_Evqp_CL, I_SAR_Evqp_CL, I_SAR_Evqp_CL, 
};
const OpState CpuRunnerX86::table_f2[] = {
	// 00
	I_ADD_Eb_Gb, I_ADD_Evqp_Gvqp, I_ADD_Gb_Eb, I_ADD_Gvqp_Evqp, I_ADD_acc_AL_Ib, I_ADD_acc_eAX_Ivds, I_PUSH_ES, I_POP_ES, 
	// 08
	I_OR_Eb_Gb, I_OR_Evqp_Gvqp, I_OR_Gb_Eb, I_OR_Gvqp_Evqp, I_OR_acc_AL_Ib, I_OR_acc_eAX_Ivds, I_PUSH_CS, ST_f2_0f, 
	// 10
	I_ADC_Eb_Gb, I_ADC_Evqp_Gvqp, I_ADC_Gb_Eb, I_ADC_Gvqp_Evqp, I_ADC_acc_AL_Ib, I_ADC_acc_eAX_Ivds, I_PUSH_SS, I_POP_delaysint_SS, 
	// 18
	I_SBB_Eb_Gb, I_SBB_Evqp_Gvqp, I_SBB_Gb_Eb, I_SBB_Gvqp_Evqp, I_SBB_acc_AL_Ib, I_SBB_acc_eAX_Ivds, I_PUSH_DS, I_POP_DS, 
	// 20
	I_AND_Eb_Gb, I_AND_Evqp_Gvqp, I_AND_Gb_Eb, I_AND_Gvqp_Evqp, I_AND_acc_AL_Ib, I_AND_acc_eAX_Ivds, PR_26, I_DAA, 
	// 28
	I_SUB_Eb_Gb, I_SUB_Evqp_Gvqp, I_SUB_Gb_Eb, I_SUB_Gvqp_Evqp, I_SUB_acc_AL_Ib, I_SUB_acc_eAX_Ivds, PR_2e, I_DAS, 
	// 30
	I_XOR_Eb_Gb, I_XOR_Evqp_Gvqp, I_XOR_Gb_Eb, I_XOR_Gvqp_Evqp, I_XOR_acc_AL_Ib, I_XOR_acc_eAX_Ivds, PR_36, I_AAA, 
	// 38
	I_CMP_Eb_Gb, I_CMP_Evqp_Gvqp, I_CMP_Gb_Eb, I_CMP_Gvqp_Evqp, I_CMP_acc_AL_Ib, I_CMP_acc_eAX_Ivds, PR_3e, I_AAS, 
	// 40
	I_INC_eAX, I_INC_eCX, I_INC_eDX, I_INC_eBX, I_INC_eSP, I_INC_eBP, I_INC_eSI, I_INC_eDI, 
	// 48
	I_DEC_eAX, I_DEC_eCX, I_DEC_eDX, I_DEC_eBX, I_DEC_eSP, I_DEC_eBP, I_DEC_eSI, I_DEC_eDI, 
	// 50
	I_PUSH_eAX, I_PUSH_eCX, I_PUSH_eDX, I_PUSH_eBX, I_PUSH_eSP, I_PUSH_eBP, I_PUSH_eSI, I_PUSH_eDI, 
	// 58
	I_POP_eAX, I_POP_eCX, I_POP_eDX, I_POP_eBX, I_POP_eSP, I_POP_eBP, I_POP_eSI, I_POP_eDI, 
	// 60
	I_PUSHA, I_POPA, I_BOUND_Gv_Ma, I_ARPL_Ew_Gw, PR_64, PR_65, ST_66, PR_67, 
	// 68
	I_PUSH_Ivs, I_IMUL_Gvqp_Evqp_Ivds, I_PUSH_Ibss, I_IMUL_Gvqp_Evqp_Ibs, I_INS_Yb_DX, I_INS_Yw_DX, I_OUTS_DX_Xb, I_OUTS_DX_Xw, 
	// 70
	I_JO_Jbs, I_JNO_Jbs, I_JB_Jbs, I_JNB_Jbs, I_JZ_Jbs, I_JNZ_Jbs, I_JBE_Jbs, I_JNBE_Jbs, 
	// 78
	I_JS_Jbs, I_JNS_Jbs, I_JP_Jbs, I_JNP_Jbs, I_JL_Jbs, I_JNL_Jbs, I_JLE_Jbs, I_JNLE_Jbs, 
	// 80
	ST_80, ST_81, ST_82, ST_83, I_TEST_Eb_Gb, I_TEST_Evqp_Gvqp, I_XCHG_Gb_Eb, I_XCHG_Gvqp_Evqp, 
	// 88
	I_MOV_Eb_Gb, I_MOV_Evqp_Gvqp, I_MOV_Gb_Eb, I_MOV_Gvqp_Evqp, I_MOV_Mw_Sw, I_LEA_Gvqp_M, I_MOV_Sw_Ew, ST_8f, 
	// 90
	I_XCHG_acc_eAX_eAX, I_XCHG_acc_eCX_eAX, I_XCHG_acc_eDX_eAX, I_XCHG_acc_eBX_eAX, I_XCHG_acc_eSP_eAX, I_XCHG_acc_eBP_eAX, I_XCHG_acc_eSI_eAX, I_XCHG_acc_eDI_eAX, 
	// 98
	I_CBW, I_CWD, I_CALLF_Ap, I_FWAIT, I_PUSHF, I_POPF, I_SAHF, I_LAHF, 
	// A0
	I_MOV_AL_Ob, I_MOV_eAX_Ovqp, I_MOV_Ob_AL, I_MOV_Ovqp_eAX, I_MOVS_Yb_Xb, I_MOVS_Yw_Xw, I_CMPS_Yb_Xb, I_CMPS_Yw_Xw, 
	// A8
	I_TEST_acc_AL_Ib, I_TEST_acc_eAX_Ivds, I_STOS_Yb, I_STOS_Yw, I_LODS_Xb, I_LODS_Xw, I_SCAS_Yb, I_SCAS_Yw, 
	// B0
	I_MOV_AL_Ib, I_MOV_CL_Ib, I_MOV_DL_Ib, I_MOV_BL_Ib, I_MOV_AH_Ib, I_MOV_CH_Ib, I_MOV_DH_Ib, I_MOV_BH_Ib, 
	// B8
	I_MOV_eAX_Ivqp, I_MOV_eCX_Ivqp, I_MOV_eDX_Ivqp, I_MOV_eBX_Ivqp, I_MOV_eSP_Ivqp, I_MOV_eBP_Ivqp, I_MOV_eSI_Ivqp, I_MOV_eDI_Ivqp, 
	// C0
	ST_c0, ST_c1, I_RETN_Iw, I_RETN, I_LES_Gv_Mp, I_LDS_Gv_Mp, ST_c6, ST_c7, 
	// C8
	I_ENTER_Iw_Ib, I_LEAVE, I_RETF_Iw, I_RETF, I_INT_I, I_INT_Ib, I_INTO, I_IRET, 
	// D0
	ST_d0, ST_d1, ST_d2, ST_d3, I_AMX_Ib, I_ADX_Ib, I_ILLEGAL, I_XLAT_BBb, 
	// D8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E0
	I_LOOPNZ_Jbs, I_LOOPZ_Jbs, I_LOOP_Jbs, I_JCXZ_Jbs, I_IN_AL_Ib, I_IN_eAX_Ib, I_OUT_Ib_AL, I_OUT_Ib_eAX, 
	// E8
	I_CALL_Jvds, I_JMP_Jvds, I_JMPF_Ap, I_JMP_Jbs, I_IN_AL_DX, I_IN_eAX_DX, I_OUT_DX_AL, I_OUT_DX_eAX, 
	// F0
	PR_f0, I_ILLEGAL, I_ILLEGAL, ST_f3, I_HLT, I_CMC, ST_f6, ST_f7, 
	// F8
	I_CLC, I_STC, I_CLI, I_STI_delaysint_cond, I_CLD, I_STD, ST_fe, ST_ff, 
};
const OpState CpuRunnerX86::table_f2_0f[] = {
	// 00
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 08
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 10
	I_MOVSD_Vsd_Wsd, I_MOVSD_Wsd_Vsd, I_MOVDDUP_Vq_Wq, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 18
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 20
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 28
	I_ILLEGAL, I_ILLEGAL, I_CVTSI2SD_Vsd_Edqp, I_ILLEGAL, I_CVTTSD2SI_Gdqp_Wsd, I_CVTSD2SI_Gdqp_Wsd, I_ILLEGAL, I_ILLEGAL, 
	// 30
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 38
	ST_f2_0f_38, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 40
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 48
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 50
	I_ILLEGAL, I_SQRTSD_Vsd_Wsd, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 58
	I_ADDSD_Vsd_Wsd, I_MULSD_Vsd_Wsd, I_CVTSD2SS_Vss_Wsd, I_ILLEGAL, I_SUBSD_Vsd_Wsd, I_MINSD_Vsd_Wsd, I_DIVSD_Vsd_Wsd, I_MAXSD_Vsd_Wsd, 
	// 60
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 68
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 70
	I_PSHUFLW_Vdq_Wdq_Ib, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 78
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_HADDPS_Vps_Wps, I_HSUBPS_Vps_Wps, I_ILLEGAL, I_ILLEGAL, 
	// 80
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 88
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 90
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 98
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// A0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// A8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// C0
	I_ILLEGAL, I_ILLEGAL, I_CMPSD_Vsd_Wsd_Ib, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// C8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D0
	I_ADDSUBPS_Vps_Wps, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_MOVDQ2Q_Pq_Uq, I_ILLEGAL, 
	// D8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_CVTPD2DQ_Vdq_Wpd, I_ILLEGAL, 
	// E8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F0
	I_LDDQU_Vdq_Mdq, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
};
const OpState CpuRunnerX86::table_f2_0f_38[] = {
	// 00
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 08
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 10
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 18
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 20
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 28
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 30
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 38
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 40
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 48
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 50
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 58
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 60
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 68
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 70
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 78
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 80
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 88
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 90
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 98
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// A0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// A8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// C0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// C8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F0
	I_CRC32_Gdqp_Eb, I_CRC32_Gdqp_Evqp, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
};
const OpState CpuRunnerX86::table_f3[] = {
	// 00
	I_ADD_Eb_Gb, I_ADD_Evqp_Gvqp, I_ADD_Gb_Eb, I_ADD_Gvqp_Evqp, I_ADD_acc_AL_Ib, I_ADD_acc_eAX_Ivds, I_PUSH_ES, I_POP_ES, 
	// 08
	I_OR_Eb_Gb, I_OR_Evqp_Gvqp, I_OR_Gb_Eb, I_OR_Gvqp_Evqp, I_OR_acc_AL_Ib, I_OR_acc_eAX_Ivds, I_PUSH_CS, ST_f3_0f, 
	// 10
	I_ADC_Eb_Gb, I_ADC_Evqp_Gvqp, I_ADC_Gb_Eb, I_ADC_Gvqp_Evqp, I_ADC_acc_AL_Ib, I_ADC_acc_eAX_Ivds, I_PUSH_SS, I_POP_delaysint_SS, 
	// 18
	I_SBB_Eb_Gb, I_SBB_Evqp_Gvqp, I_SBB_Gb_Eb, I_SBB_Gvqp_Evqp, I_SBB_acc_AL_Ib, I_SBB_acc_eAX_Ivds, I_PUSH_DS, I_POP_DS, 
	// 20
	I_AND_Eb_Gb, I_AND_Evqp_Gvqp, I_AND_Gb_Eb, I_AND_Gvqp_Evqp, I_AND_acc_AL_Ib, I_AND_acc_eAX_Ivds, PR_26, I_DAA, 
	// 28
	I_SUB_Eb_Gb, I_SUB_Evqp_Gvqp, I_SUB_Gb_Eb, I_SUB_Gvqp_Evqp, I_SUB_acc_AL_Ib, I_SUB_acc_eAX_Ivds, PR_2e, I_DAS, 
	// 30
	I_XOR_Eb_Gb, I_XOR_Evqp_Gvqp, I_XOR_Gb_Eb, I_XOR_Gvqp_Evqp, I_XOR_acc_AL_Ib, I_XOR_acc_eAX_Ivds, PR_36, I_AAA, 
	// 38
	I_CMP_Eb_Gb, I_CMP_Evqp_Gvqp, I_CMP_Gb_Eb, I_CMP_Gvqp_Evqp, I_CMP_acc_AL_Ib, I_CMP_acc_eAX_Ivds, PR_3e, I_AAS, 
	// 40
	I_INC_eAX, I_INC_eCX, I_INC_eDX, I_INC_eBX, I_INC_eSP, I_INC_eBP, I_INC_eSI, I_INC_eDI, 
	// 48
	I_DEC_eAX, I_DEC_eCX, I_DEC_eDX, I_DEC_eBX, I_DEC_eSP, I_DEC_eBP, I_DEC_eSI, I_DEC_eDI, 
	// 50
	I_PUSH_eAX, I_PUSH_eCX, I_PUSH_eDX, I_PUSH_eBX, I_PUSH_eSP, I_PUSH_eBP, I_PUSH_eSI, I_PUSH_eDI, 
	// 58
	I_POP_eAX, I_POP_eCX, I_POP_eDX, I_POP_eBX, I_POP_eSP, I_POP_eBP, I_POP_eSI, I_POP_eDI, 
	// 60
	I_PUSHA, I_POPA, I_BOUND_Gv_Ma, I_ARPL_Ew_Gw, PR_64, PR_65, ST_66, PR_67, 
	// 68
	I_PUSH_Ivs, I_IMUL_Gvqp_Evqp_Ivds, I_PUSH_Ibss, I_IMUL_Gvqp_Evqp_Ibs, I_INS_Yb_DX, I_INS_Yw_DX, I_OUTS_DX_Xb, I_OUTS_DX_Xw, 
	// 70
	I_JO_Jbs, I_JNO_Jbs, I_JB_Jbs, I_JNB_Jbs, I_JZ_Jbs, I_JNZ_Jbs, I_JBE_Jbs, I_JNBE_Jbs, 
	// 78
	I_JS_Jbs, I_JNS_Jbs, I_JP_Jbs, I_JNP_Jbs, I_JL_Jbs, I_JNL_Jbs, I_JLE_Jbs, I_JNLE_Jbs, 
	// 80
	ST_80, ST_81, ST_82, ST_83, I_TEST_Eb_Gb, I_TEST_Evqp_Gvqp, I_XCHG_Gb_Eb, I_XCHG_Gvqp_Evqp, 
	// 88
	I_MOV_Eb_Gb, I_MOV_Evqp_Gvqp, I_MOV_Gb_Eb, I_MOV_Gvqp_Evqp, I_MOV_Mw_Sw, I_LEA_Gvqp_M, I_MOV_Sw_Ew, ST_8f, 
	// 90
	I_NOP_nop, I_XCHG_acc_eCX_eAX, I_XCHG_acc_eDX_eAX, I_XCHG_acc_eBX_eAX, I_XCHG_acc_eSP_eAX, I_XCHG_acc_eBP_eAX, I_XCHG_acc_eSI_eAX, I_XCHG_acc_eDI_eAX, 
	// 98
	I_CBW, I_CWD, I_CALLF_Ap, I_FWAIT, I_PUSHF, I_POPF, I_SAHF, I_LAHF, 
	// A0
	I_MOV_AL_Ob, I_MOV_eAX_Ovqp, I_MOV_Ob_AL, I_MOV_Ovqp_eAX, I_MOVS_Yb_Xb, I_MOVS_Yw_Xw, I_CMPS_Yb_Xb, I_CMPS_Yw_Xw, 
	// A8
	I_TEST_acc_AL_Ib, I_TEST_acc_eAX_Ivds, I_STOS_Yb, I_STOS_Yw, I_LODS_Xb, I_LODS_Xw, I_SCAS_Yb, I_SCAS_Yw, 
	// B0
	I_MOV_AL_Ib, I_MOV_CL_Ib, I_MOV_DL_Ib, I_MOV_BL_Ib, I_MOV_AH_Ib, I_MOV_CH_Ib, I_MOV_DH_Ib, I_MOV_BH_Ib, 
	// B8
	I_MOV_eAX_Ivqp, I_MOV_eCX_Ivqp, I_MOV_eDX_Ivqp, I_MOV_eBX_Ivqp, I_MOV_eSP_Ivqp, I_MOV_eBP_Ivqp, I_MOV_eSI_Ivqp, I_MOV_eDI_Ivqp, 
	// C0
	ST_c0, ST_c1, I_RETN_Iw, I_RETN, I_LES_Gv_Mp, I_LDS_Gv_Mp, ST_c6, ST_c7, 
	// C8
	I_ENTER_Iw_Ib, I_LEAVE, I_RETF_Iw, I_RETF, I_INT_I, I_INT_Ib, I_INTO, I_IRET, 
	// D0
	ST_d0, ST_d1, ST_d2, ST_d3, I_AMX_Ib, I_ADX_Ib, I_ILLEGAL, I_XLAT_BBb, 
	// D8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E0
	I_LOOPNZ_Jbs, I_LOOPZ_Jbs, I_LOOP_Jbs, I_JCXZ_Jbs, I_IN_AL_Ib, I_IN_eAX_Ib, I_OUT_Ib_AL, I_OUT_Ib_eAX, 
	// E8
	I_CALL_Jvds, I_JMP_Jvds, I_JMPF_Ap, I_JMP_Jbs, I_IN_AL_DX, I_IN_eAX_DX, I_OUT_DX_AL, I_OUT_DX_eAX, 
	// F0
	PR_f0, I_ILLEGAL, ST_f2, I_ILLEGAL, I_HLT, I_CMC, ST_f6, ST_f7, 
	// F8
	I_CLC, I_STC, I_CLI, I_STI_delaysint_cond, I_CLD, I_STD, ST_fe, ST_ff, 
};
const OpState CpuRunnerX86::table_f3_0f[] = {
	// 00
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 08
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 10
	I_MOVSS_Vss_Wss, I_MOVSS_Wss_Vss, I_MOVSLDUP_Vq_Wq, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_MOVSHDUP_Vq_Wq, I_ILLEGAL, 
	// 18
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 20
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 28
	I_ILLEGAL, I_ILLEGAL, I_CVTSI2SS_Vss_Edqp, I_ILLEGAL, I_CVTTSS2SI_Gdqp_Wss, I_CVTSS2SI_Gdqp_Wss, I_ILLEGAL, I_ILLEGAL, 
	// 30
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 38
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 40
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 48
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 50
	I_ILLEGAL, I_SQRTSS_Vss_Wss, I_RSQRTSS_Vss_Wss, I_RCPSS_Vss_Wss, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 58
	I_ADDSS_Vss_Wss, I_MULSS_Vss_Wss, I_CVTSS2SD_Vsd_Wss, I_CVTTPS2DQ_Vdq_Wps, I_SUBSS_Vss_Wss, I_MINSS_Vss_Wss, I_DIVSS_Vss_Wss, I_MAXSS_Vss_Wss, 
	// 60
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 68
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_MOVDQU_Vdq_Wdq, 
	// 70
	I_PSHUFHW_Vdq_Wdq_Ib, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 78
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_MOVQ_Vq_Wq, I_MOVDQU_Wdq_Vdq, 
	// 80
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 88
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 90
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 98
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// A0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// A8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B8
	I_POPCNT_Gvqp_Evqp, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// C0
	I_ILLEGAL, I_ILLEGAL, I_CMPSS_Vss_Wss_Ib, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, ST_f3_0f_c7, 
	// C8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_MOVQ2DQ_Vdq_Nq, I_ILLEGAL, 
	// D8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_CVTDQ2PD_Vpd_Wdq, I_ILLEGAL, 
	// E8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
};
const OpState CpuRunnerX86::table_f3_0f_c7[] = {
	// 00
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 08
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 10
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 18
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 20
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 28
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 30
	I_VMXON_Mq, I_VMXON_Mq, I_VMXON_Mq, I_VMXON_Mq, I_VMXON_Mq, I_VMXON_Mq, I_VMXON_Mq, I_VMXON_Mq, 
	// 38
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 40
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 48
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 50
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 58
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 60
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 68
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 70
	I_VMXON_Mq, I_VMXON_Mq, I_VMXON_Mq, I_VMXON_Mq, I_VMXON_Mq, I_VMXON_Mq, I_VMXON_Mq, I_VMXON_Mq, 
	// 78
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 80
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 88
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 90
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 98
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// A0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// A8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B0
	I_VMXON_Mq, I_VMXON_Mq, I_VMXON_Mq, I_VMXON_Mq, I_VMXON_Mq, I_VMXON_Mq, I_VMXON_Mq, I_VMXON_Mq, 
	// B8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// C0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// C8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
};
const OpState CpuRunnerX86::table_f6[] = {
	// 00
	I_TEST_Eb_Ib, I_TEST_Eb_Ib, I_TEST_Eb_Ib, I_TEST_Eb_Ib, I_TEST_Eb_Ib, I_TEST_Eb_Ib, I_TEST_Eb_Ib, I_TEST_Eb_Ib, 
	// 08
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 10
	I_NOT_Eb, I_NOT_Eb, I_NOT_Eb, I_NOT_Eb, I_NOT_Eb, I_NOT_Eb, I_NOT_Eb, I_NOT_Eb, 
	// 18
	I_NEG_Eb, I_NEG_Eb, I_NEG_Eb, I_NEG_Eb, I_NEG_Eb, I_NEG_Eb, I_NEG_Eb, I_NEG_Eb, 
	// 20
	I_MUL_Eb, I_MUL_Eb, I_MUL_Eb, I_MUL_Eb, I_MUL_Eb, I_MUL_Eb, I_MUL_Eb, I_MUL_Eb, 
	// 28
	I_IMUL_Eb, I_IMUL_Eb, I_IMUL_Eb, I_IMUL_Eb, I_IMUL_Eb, I_IMUL_Eb, I_IMUL_Eb, I_IMUL_Eb, 
	// 30
	I_DIV_Eb, I_DIV_Eb, I_DIV_Eb, I_DIV_Eb, I_DIV_Eb, I_DIV_Eb, I_DIV_Eb, I_DIV_Eb, 
	// 38
	I_IDIV_Eb, I_IDIV_Eb, I_IDIV_Eb, I_IDIV_Eb, I_IDIV_Eb, I_IDIV_Eb, I_IDIV_Eb, I_IDIV_Eb, 
	// 40
	I_TEST_Eb_Ib, I_TEST_Eb_Ib, I_TEST_Eb_Ib, I_TEST_Eb_Ib, I_TEST_Eb_Ib, I_TEST_Eb_Ib, I_TEST_Eb_Ib, I_TEST_Eb_Ib, 
	// 48
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 50
	I_NOT_Eb, I_NOT_Eb, I_NOT_Eb, I_NOT_Eb, I_NOT_Eb, I_NOT_Eb, I_NOT_Eb, I_NOT_Eb, 
	// 58
	I_NEG_Eb, I_NEG_Eb, I_NEG_Eb, I_NEG_Eb, I_NEG_Eb, I_NEG_Eb, I_NEG_Eb, I_NEG_Eb, 
	// 60
	I_MUL_Eb, I_MUL_Eb, I_MUL_Eb, I_MUL_Eb, I_MUL_Eb, I_MUL_Eb, I_MUL_Eb, I_MUL_Eb, 
	// 68
	I_IMUL_Eb, I_IMUL_Eb, I_IMUL_Eb, I_IMUL_Eb, I_IMUL_Eb, I_IMUL_Eb, I_IMUL_Eb, I_IMUL_Eb, 
	// 70
	I_DIV_Eb, I_DIV_Eb, I_DIV_Eb, I_DIV_Eb, I_DIV_Eb, I_DIV_Eb, I_DIV_Eb, I_DIV_Eb, 
	// 78
	I_IDIV_Eb, I_IDIV_Eb, I_IDIV_Eb, I_IDIV_Eb, I_IDIV_Eb, I_IDIV_Eb, I_IDIV_Eb, I_IDIV_Eb, 
	// 80
	I_TEST_Eb_Ib, I_TEST_Eb_Ib, I_TEST_Eb_Ib, I_TEST_Eb_Ib, I_TEST_Eb_Ib, I_TEST_Eb_Ib, I_TEST_Eb_Ib, I_TEST_Eb_Ib, 
	// 88
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 90
	I_NOT_Eb, I_NOT_Eb, I_NOT_Eb, I_NOT_Eb, I_NOT_Eb, I_NOT_Eb, I_NOT_Eb, I_NOT_Eb, 
	// 98
	I_NEG_Eb, I_NEG_Eb, I_NEG_Eb, I_NEG_Eb, I_NEG_Eb, I_NEG_Eb, I_NEG_Eb, I_NEG_Eb, 
	// A0
	I_MUL_Eb, I_MUL_Eb, I_MUL_Eb, I_MUL_Eb, I_MUL_Eb, I_MUL_Eb, I_MUL_Eb, I_MUL_Eb, 
	// A8
	I_IMUL_Eb, I_IMUL_Eb, I_IMUL_Eb, I_IMUL_Eb, I_IMUL_Eb, I_IMUL_Eb, I_IMUL_Eb, I_IMUL_Eb, 
	// B0
	I_DIV_Eb, I_DIV_Eb, I_DIV_Eb, I_DIV_Eb, I_DIV_Eb, I_DIV_Eb, I_DIV_Eb, I_DIV_Eb, 
	// B8
	I_IDIV_Eb, I_IDIV_Eb, I_IDIV_Eb, I_IDIV_Eb, I_IDIV_Eb, I_IDIV_Eb, I_IDIV_Eb, I_IDIV_Eb, 
	// C0
	I_TEST_Eb_Ib, I_TEST_Eb_Ib, I_TEST_Eb_Ib, I_TEST_Eb_Ib, I_TEST_Eb_Ib, I_TEST_Eb_Ib, I_TEST_Eb_Ib, I_TEST_Eb_Ib, 
	// C8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D0
	I_NOT_Eb, I_NOT_Eb, I_NOT_Eb, I_NOT_Eb, I_NOT_Eb, I_NOT_Eb, I_NOT_Eb, I_NOT_Eb, 
	// D8
	I_NEG_Eb, I_NEG_Eb, I_NEG_Eb, I_NEG_Eb, I_NEG_Eb, I_NEG_Eb, I_NEG_Eb, I_NEG_Eb, 
	// E0
	I_MUL_Eb, I_MUL_Eb, I_MUL_Eb, I_MUL_Eb, I_MUL_Eb, I_MUL_Eb, I_MUL_Eb, I_MUL_Eb, 
	// E8
	I_IMUL_Eb, I_IMUL_Eb, I_IMUL_Eb, I_IMUL_Eb, I_IMUL_Eb, I_IMUL_Eb, I_IMUL_Eb, I_IMUL_Eb, 
	// F0
	I_DIV_Eb, I_DIV_Eb, I_DIV_Eb, I_DIV_Eb, I_DIV_Eb, I_DIV_Eb, I_DIV_Eb, I_DIV_Eb, 
	// F8
	I_IDIV_Eb, I_IDIV_Eb, I_IDIV_Eb, I_IDIV_Eb, I_IDIV_Eb, I_IDIV_Eb, I_IDIV_Eb, I_IDIV_Eb, 
};
const OpState CpuRunnerX86::table_f7[] = {
	// 00
	I_TEST_Evqp_Ivqp, I_TEST_Evqp_Ivqp, I_TEST_Evqp_Ivqp, I_TEST_Evqp_Ivqp, I_TEST_Evqp_Ivqp, I_TEST_Evqp_Ivqp, I_TEST_Evqp_Ivqp, I_TEST_Evqp_Ivqp, 
	// 08
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 10
	I_NOT_Evqp, I_NOT_Evqp, I_NOT_Evqp, I_NOT_Evqp, I_NOT_Evqp, I_NOT_Evqp, I_NOT_Evqp, I_NOT_Evqp, 
	// 18
	I_NEG_Evqp, I_NEG_Evqp, I_NEG_Evqp, I_NEG_Evqp, I_NEG_Evqp, I_NEG_Evqp, I_NEG_Evqp, I_NEG_Evqp, 
	// 20
	I_MUL_Evqp, I_MUL_Evqp, I_MUL_Evqp, I_MUL_Evqp, I_MUL_Evqp, I_MUL_Evqp, I_MUL_Evqp, I_MUL_Evqp, 
	// 28
	I_IMUL_Evqp, I_IMUL_Evqp, I_IMUL_Evqp, I_IMUL_Evqp, I_IMUL_Evqp, I_IMUL_Evqp, I_IMUL_Evqp, I_IMUL_Evqp, 
	// 30
	I_DIV_Evqp, I_DIV_Evqp, I_DIV_Evqp, I_DIV_Evqp, I_DIV_Evqp, I_DIV_Evqp, I_DIV_Evqp, I_DIV_Evqp, 
	// 38
	I_IDIV_Evqp, I_IDIV_Evqp, I_IDIV_Evqp, I_IDIV_Evqp, I_IDIV_Evqp, I_IDIV_Evqp, I_IDIV_Evqp, I_IDIV_Evqp, 
	// 40
	I_TEST_Evqp_Ivqp, I_TEST_Evqp_Ivqp, I_TEST_Evqp_Ivqp, I_TEST_Evqp_Ivqp, I_TEST_Evqp_Ivqp, I_TEST_Evqp_Ivqp, I_TEST_Evqp_Ivqp, I_TEST_Evqp_Ivqp, 
	// 48
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 50
	I_NOT_Evqp, I_NOT_Evqp, I_NOT_Evqp, I_NOT_Evqp, I_NOT_Evqp, I_NOT_Evqp, I_NOT_Evqp, I_NOT_Evqp, 
	// 58
	I_NEG_Evqp, I_NEG_Evqp, I_NEG_Evqp, I_NEG_Evqp, I_NEG_Evqp, I_NEG_Evqp, I_NEG_Evqp, I_NEG_Evqp, 
	// 60
	I_MUL_Evqp, I_MUL_Evqp, I_MUL_Evqp, I_MUL_Evqp, I_MUL_Evqp, I_MUL_Evqp, I_MUL_Evqp, I_MUL_Evqp, 
	// 68
	I_IMUL_Evqp, I_IMUL_Evqp, I_IMUL_Evqp, I_IMUL_Evqp, I_IMUL_Evqp, I_IMUL_Evqp, I_IMUL_Evqp, I_IMUL_Evqp, 
	// 70
	I_DIV_Evqp, I_DIV_Evqp, I_DIV_Evqp, I_DIV_Evqp, I_DIV_Evqp, I_DIV_Evqp, I_DIV_Evqp, I_DIV_Evqp, 
	// 78
	I_IDIV_Evqp, I_IDIV_Evqp, I_IDIV_Evqp, I_IDIV_Evqp, I_IDIV_Evqp, I_IDIV_Evqp, I_IDIV_Evqp, I_IDIV_Evqp, 
	// 80
	I_TEST_Evqp_Ivqp, I_TEST_Evqp_Ivqp, I_TEST_Evqp_Ivqp, I_TEST_Evqp_Ivqp, I_TEST_Evqp_Ivqp, I_TEST_Evqp_Ivqp, I_TEST_Evqp_Ivqp, I_TEST_Evqp_Ivqp, 
	// 88
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 90
	I_NOT_Evqp, I_NOT_Evqp, I_NOT_Evqp, I_NOT_Evqp, I_NOT_Evqp, I_NOT_Evqp, I_NOT_Evqp, I_NOT_Evqp, 
	// 98
	I_NEG_Evqp, I_NEG_Evqp, I_NEG_Evqp, I_NEG_Evqp, I_NEG_Evqp, I_NEG_Evqp, I_NEG_Evqp, I_NEG_Evqp, 
	// A0
	I_MUL_Evqp, I_MUL_Evqp, I_MUL_Evqp, I_MUL_Evqp, I_MUL_Evqp, I_MUL_Evqp, I_MUL_Evqp, I_MUL_Evqp, 
	// A8
	I_IMUL_Evqp, I_IMUL_Evqp, I_IMUL_Evqp, I_IMUL_Evqp, I_IMUL_Evqp, I_IMUL_Evqp, I_IMUL_Evqp, I_IMUL_Evqp, 
	// B0
	I_DIV_Evqp, I_DIV_Evqp, I_DIV_Evqp, I_DIV_Evqp, I_DIV_Evqp, I_DIV_Evqp, I_DIV_Evqp, I_DIV_Evqp, 
	// B8
	I_IDIV_Evqp, I_IDIV_Evqp, I_IDIV_Evqp, I_IDIV_Evqp, I_IDIV_Evqp, I_IDIV_Evqp, I_IDIV_Evqp, I_IDIV_Evqp, 
	// C0
	I_TEST_Evqp_Ivqp, I_TEST_Evqp_Ivqp, I_TEST_Evqp_Ivqp, I_TEST_Evqp_Ivqp, I_TEST_Evqp_Ivqp, I_TEST_Evqp_Ivqp, I_TEST_Evqp_Ivqp, I_TEST_Evqp_Ivqp, 
	// C8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D0
	I_NOT_Evqp, I_NOT_Evqp, I_NOT_Evqp, I_NOT_Evqp, I_NOT_Evqp, I_NOT_Evqp, I_NOT_Evqp, I_NOT_Evqp, 
	// D8
	I_NEG_Evqp, I_NEG_Evqp, I_NEG_Evqp, I_NEG_Evqp, I_NEG_Evqp, I_NEG_Evqp, I_NEG_Evqp, I_NEG_Evqp, 
	// E0
	I_MUL_Evqp, I_MUL_Evqp, I_MUL_Evqp, I_MUL_Evqp, I_MUL_Evqp, I_MUL_Evqp, I_MUL_Evqp, I_MUL_Evqp, 
	// E8
	I_IMUL_Evqp, I_IMUL_Evqp, I_IMUL_Evqp, I_IMUL_Evqp, I_IMUL_Evqp, I_IMUL_Evqp, I_IMUL_Evqp, I_IMUL_Evqp, 
	// F0
	I_DIV_Evqp, I_DIV_Evqp, I_DIV_Evqp, I_DIV_Evqp, I_DIV_Evqp, I_DIV_Evqp, I_DIV_Evqp, I_DIV_Evqp, 
	// F8
	I_IDIV_Evqp, I_IDIV_Evqp, I_IDIV_Evqp, I_IDIV_Evqp, I_IDIV_Evqp, I_IDIV_Evqp, I_IDIV_Evqp, I_IDIV_Evqp, 
};
const OpState CpuRunnerX86::table_fe[] = {
	// 00
	I_INC_Eb, I_INC_Eb, I_INC_Eb, I_INC_Eb, I_INC_Eb, I_INC_Eb, I_INC_Eb, I_INC_Eb, 
	// 08
	I_DEC_Eb, I_DEC_Eb, I_DEC_Eb, I_DEC_Eb, I_DEC_Eb, I_DEC_Eb, I_DEC_Eb, I_DEC_Eb, 
	// 10
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 18
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 20
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 28
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 30
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 38
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 40
	I_INC_Eb, I_INC_Eb, I_INC_Eb, I_INC_Eb, I_INC_Eb, I_INC_Eb, I_INC_Eb, I_INC_Eb, 
	// 48
	I_DEC_Eb, I_DEC_Eb, I_DEC_Eb, I_DEC_Eb, I_DEC_Eb, I_DEC_Eb, I_DEC_Eb, I_DEC_Eb, 
	// 50
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 58
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 60
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 68
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 70
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 78
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 80
	I_INC_Eb, I_INC_Eb, I_INC_Eb, I_INC_Eb, I_INC_Eb, I_INC_Eb, I_INC_Eb, I_INC_Eb, 
	// 88
	I_DEC_Eb, I_DEC_Eb, I_DEC_Eb, I_DEC_Eb, I_DEC_Eb, I_DEC_Eb, I_DEC_Eb, I_DEC_Eb, 
	// 90
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 98
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// A0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// A8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// B8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// C0
	I_INC_Eb, I_INC_Eb, I_INC_Eb, I_INC_Eb, I_INC_Eb, I_INC_Eb, I_INC_Eb, I_INC_Eb, 
	// C8
	I_DEC_Eb, I_DEC_Eb, I_DEC_Eb, I_DEC_Eb, I_DEC_Eb, I_DEC_Eb, I_DEC_Eb, I_DEC_Eb, 
	// D0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// D8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F0
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
};
const OpState CpuRunnerX86::table_ff[] = {
	// 00
	I_INC_Evqp, I_INC_Evqp, I_INC_Evqp, I_INC_Evqp, I_INC_Evqp, I_INC_Evqp, I_INC_Evqp, I_INC_Evqp, 
	// 08
	I_DEC_Evqp, I_DEC_Evqp, I_DEC_Evqp, I_DEC_Evqp, I_DEC_Evqp, I_DEC_Evqp, I_DEC_Evqp, I_DEC_Evqp, 
	// 10
	I_CALL_Ev, I_CALL_Ev, I_CALL_Ev, I_CALL_Ev, I_CALL_Ev, I_CALL_Ev, I_CALL_Ev, I_CALL_Ev, 
	// 18
	I_CALLF_Mptp, I_CALLF_Mptp, I_CALLF_Mptp, I_CALLF_Mptp, I_CALLF_Mptp, I_CALLF_Mptp, I_CALLF_Mptp, I_CALLF_Mptp, 
	// 20
	I_JMP_Ev, I_JMP_Ev, I_JMP_Ev, I_JMP_Ev, I_JMP_Ev, I_JMP_Ev, I_JMP_Ev, I_JMP_Ev, 
	// 28
	I_JMPF_Mptp, I_JMPF_Mptp, I_JMPF_Mptp, I_JMPF_Mptp, I_JMPF_Mptp, I_JMPF_Mptp, I_JMPF_Mptp, I_JMPF_Mptp, 
	// 30
	I_PUSH_Ev, I_PUSH_Ev, I_PUSH_Ev, I_PUSH_Ev, I_PUSH_Ev, I_PUSH_Ev, I_PUSH_Ev, I_PUSH_Ev, 
	// 38
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 40
	I_INC_Evqp, I_INC_Evqp, I_INC_Evqp, I_INC_Evqp, I_INC_Evqp, I_INC_Evqp, I_INC_Evqp, I_INC_Evqp, 
	// 48
	I_DEC_Evqp, I_DEC_Evqp, I_DEC_Evqp, I_DEC_Evqp, I_DEC_Evqp, I_DEC_Evqp, I_DEC_Evqp, I_DEC_Evqp, 
	// 50
	I_CALL_Ev, I_CALL_Ev, I_CALL_Ev, I_CALL_Ev, I_CALL_Ev, I_CALL_Ev, I_CALL_Ev, I_CALL_Ev, 
	// 58
	I_CALLF_Mptp, I_CALLF_Mptp, I_CALLF_Mptp, I_CALLF_Mptp, I_CALLF_Mptp, I_CALLF_Mptp, I_CALLF_Mptp, I_CALLF_Mptp, 
	// 60
	I_JMP_Ev, I_JMP_Ev, I_JMP_Ev, I_JMP_Ev, I_JMP_Ev, I_JMP_Ev, I_JMP_Ev, I_JMP_Ev, 
	// 68
	I_JMPF_Mptp, I_JMPF_Mptp, I_JMPF_Mptp, I_JMPF_Mptp, I_JMPF_Mptp, I_JMPF_Mptp, I_JMPF_Mptp, I_JMPF_Mptp, 
	// 70
	I_PUSH_Ev, I_PUSH_Ev, I_PUSH_Ev, I_PUSH_Ev, I_PUSH_Ev, I_PUSH_Ev, I_PUSH_Ev, I_PUSH_Ev, 
	// 78
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// 80
	I_INC_Evqp, I_INC_Evqp, I_INC_Evqp, I_INC_Evqp, I_INC_Evqp, I_INC_Evqp, I_INC_Evqp, I_INC_Evqp, 
	// 88
	I_DEC_Evqp, I_DEC_Evqp, I_DEC_Evqp, I_DEC_Evqp, I_DEC_Evqp, I_DEC_Evqp, I_DEC_Evqp, I_DEC_Evqp, 
	// 90
	I_CALL_Ev, I_CALL_Ev, I_CALL_Ev, I_CALL_Ev, I_CALL_Ev, I_CALL_Ev, I_CALL_Ev, I_CALL_Ev, 
	// 98
	I_CALLF_Mptp, I_CALLF_Mptp, I_CALLF_Mptp, I_CALLF_Mptp, I_CALLF_Mptp, I_CALLF_Mptp, I_CALLF_Mptp, I_CALLF_Mptp, 
	// A0
	I_JMP_Ev, I_JMP_Ev, I_JMP_Ev, I_JMP_Ev, I_JMP_Ev, I_JMP_Ev, I_JMP_Ev, I_JMP_Ev, 
	// A8
	I_JMPF_Mptp, I_JMPF_Mptp, I_JMPF_Mptp, I_JMPF_Mptp, I_JMPF_Mptp, I_JMPF_Mptp, I_JMPF_Mptp, I_JMPF_Mptp, 
	// B0
	I_PUSH_Ev, I_PUSH_Ev, I_PUSH_Ev, I_PUSH_Ev, I_PUSH_Ev, I_PUSH_Ev, I_PUSH_Ev, I_PUSH_Ev, 
	// B8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// C0
	I_INC_Evqp, I_INC_Evqp, I_INC_Evqp, I_INC_Evqp, I_INC_Evqp, I_INC_Evqp, I_INC_Evqp, I_INC_Evqp, 
	// C8
	I_DEC_Evqp, I_DEC_Evqp, I_DEC_Evqp, I_DEC_Evqp, I_DEC_Evqp, I_DEC_Evqp, I_DEC_Evqp, I_DEC_Evqp, 
	// D0
	I_CALL_Ev, I_CALL_Ev, I_CALL_Ev, I_CALL_Ev, I_CALL_Ev, I_CALL_Ev, I_CALL_Ev, I_CALL_Ev, 
	// D8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// E0
	I_JMP_Ev, I_JMP_Ev, I_JMP_Ev, I_JMP_Ev, I_JMP_Ev, I_JMP_Ev, I_JMP_Ev, I_JMP_Ev, 
	// E8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
	// F0
	I_PUSH_Ev, I_PUSH_Ev, I_PUSH_Ev, I_PUSH_Ev, I_PUSH_Ev, I_PUSH_Ev, I_PUSH_Ev, I_PUSH_Ev, 
	// F8
	I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, I_ILLEGAL, 
};

const OpState* const CpuRunnerX86::TableState[] = {
	CpuRunnerX86::table,
	CpuRunnerX86::table_0f,
	CpuRunnerX86::table_0f_00,
	CpuRunnerX86::table_0f_01,
	CpuRunnerX86::table_0f_18,
	CpuRunnerX86::table_0f_1f,
	CpuRunnerX86::table_0f_38,
	CpuRunnerX86::table_0f_3a,
	CpuRunnerX86::table_0f_71,
	CpuRunnerX86::table_0f_72,
	CpuRunnerX86::table_0f_73,
	CpuRunnerX86::table_0f_90,
	CpuRunnerX86::table_0f_91,
	CpuRunnerX86::table_0f_92,
	CpuRunnerX86::table_0f_93,
	CpuRunnerX86::table_0f_94,
	CpuRunnerX86::table_0f_95,
	CpuRunnerX86::table_0f_96,
	CpuRunnerX86::table_0f_97,
	CpuRunnerX86::table_0f_98,
	CpuRunnerX86::table_0f_99,
	CpuRunnerX86::table_0f_9a,
	CpuRunnerX86::table_0f_9b,
	CpuRunnerX86::table_0f_9c,
	CpuRunnerX86::table_0f_9d,
	CpuRunnerX86::table_0f_9e,
	CpuRunnerX86::table_0f_9f,
	CpuRunnerX86::table_0f_ae,
	CpuRunnerX86::table_0f_ba,
	CpuRunnerX86::table_0f_c7,
	CpuRunnerX86::table_66,
	CpuRunnerX86::table_66_0f,
	CpuRunnerX86::table_66_0f_38,
	CpuRunnerX86::table_66_0f_3a,
	CpuRunnerX86::table_66_0f_71,
	CpuRunnerX86::table_66_0f_72,
	CpuRunnerX86::table_66_0f_73,
	CpuRunnerX86::table_66_0f_c7,
	CpuRunnerX86::table_80,
	CpuRunnerX86::table_81,
	CpuRunnerX86::table_82,
	CpuRunnerX86::table_83,
	CpuRunnerX86::table_8f,
	CpuRunnerX86::table_c0,
	CpuRunnerX86::table_c1,
	CpuRunnerX86::table_c6,
	CpuRunnerX86::table_c7,
	CpuRunnerX86::table_d0,
	CpuRunnerX86::table_d1,
	CpuRunnerX86::table_d2,
	CpuRunnerX86::table_d3,
	CpuRunnerX86::table_f2,
	CpuRunnerX86::table_f2_0f,
	CpuRunnerX86::table_f2_0f_38,
	CpuRunnerX86::table_f3,
	CpuRunnerX86::table_f3_0f,
	CpuRunnerX86::table_f3_0f_c7,
	CpuRunnerX86::table_f6,
	CpuRunnerX86::table_f7,
	CpuRunnerX86::table_fe,
	CpuRunnerX86::table_ff,
	CpuRunnerX86::table,
	CpuRunnerX86::table,
	CpuRunnerX86::table,
	CpuRunnerX86::table,
	CpuRunnerX86::table,
	CpuRunnerX86::table,
	CpuRunnerX86::table,
	CpuRunnerX86::table,
};

bool CpuRunnerX86::Parse(PhysPt &cseip) {
    OpState state = ST;
    Bit8u insb = 0;
    while(state < I_ILLEGAL) {
        insb = Fetchb(cseip);
	    const OpState* table = TableState[ST];
        state = table[insb];

        switch(state) {

        case PR_26:
            Handle_Prefix_26(state);
            break;

        case PR_2e:
            Handle_Prefix_2e(state);
            break;

        case PR_36:
            Handle_Prefix_36(state);
            break;

        case PR_3e:
            Handle_Prefix_3e(state);
            break;

        case PR_64:
            Handle_Prefix_64(state);
            break;

        case PR_65:
            Handle_Prefix_65(state);
            break;

        case PR_67:
            Handle_Prefix_67(state);
            break;

        case PR_f0:
            Handle_Prefix_f0(state);
            break;

        default:
            break;
        }
    }
    switch(state) {

    case I_AAA:
        Handle_AAA(insb, cseip);
        break;

    case I_AAD:
        Handle_AAD(insb, cseip);
        break;

    case I_AAM:
        Handle_AAM(insb, cseip);
        break;

    case I_AAS:
        Handle_AAS(insb, cseip);
        break;

    case I_ADC_Eb_Gb:
        Handle_ADC_Eb_Gb(insb, cseip);
        break;

    case I_ADC_Eb_Ib:
        Handle_ADC_Eb_Ib(insb, cseip);
        break;

    case I_ADC_Evqp_Gvqp:
        Handle_ADC_Evqp_Gvqp(insb, cseip);
        break;

    case I_ADC_Evqp_Ibs:
        Handle_ADC_Evqp_Ibs(insb, cseip);
        break;

    case I_ADC_Evqp_Ivds:
        Handle_ADC_Evqp_Ivds(insb, cseip);
        break;

    case I_ADC_Gb_Eb:
        Handle_ADC_Gb_Eb(insb, cseip);
        break;

    case I_ADC_Gvqp_Evqp:
        Handle_ADC_Gvqp_Evqp(insb, cseip);
        break;

    case I_ADC_acc_AL_Ib:
        Handle_ADC_acc_AL_Ib(insb, cseip);
        break;

    case I_ADC_acc_eAX_Ivds:
        Handle_ADC_acc_eAX_Ivds(insb, cseip);
        break;

    case I_ADDPD_Vpd_Wpd:
        Handle_ADDPD_Vpd_Wpd(insb, cseip);
        break;

    case I_ADDPS_Vps_Wps:
        Handle_ADDPS_Vps_Wps(insb, cseip);
        break;

    case I_ADDSD_Vsd_Wsd:
        Handle_ADDSD_Vsd_Wsd(insb, cseip);
        break;

    case I_ADDSS_Vss_Wss:
        Handle_ADDSS_Vss_Wss(insb, cseip);
        break;

    case I_ADDSUBPD_Vpd_Wpd:
        Handle_ADDSUBPD_Vpd_Wpd(insb, cseip);
        break;

    case I_ADDSUBPS_Vps_Wps:
        Handle_ADDSUBPS_Vps_Wps(insb, cseip);
        break;

    case I_ADD_Eb_Gb:
        Handle_ADD_Eb_Gb(insb, cseip);
        break;

    case I_ADD_Eb_Ib:
        Handle_ADD_Eb_Ib(insb, cseip);
        break;

    case I_ADD_Evqp_Gvqp:
        Handle_ADD_Evqp_Gvqp(insb, cseip);
        break;

    case I_ADD_Evqp_Ibs:
        Handle_ADD_Evqp_Ibs(insb, cseip);
        break;

    case I_ADD_Evqp_Ivds:
        Handle_ADD_Evqp_Ivds(insb, cseip);
        break;

    case I_ADD_Gb_Eb:
        Handle_ADD_Gb_Eb(insb, cseip);
        break;

    case I_ADD_Gvqp_Evqp:
        Handle_ADD_Gvqp_Evqp(insb, cseip);
        break;

    case I_ADD_acc_AL_Ib:
        Handle_ADD_acc_AL_Ib(insb, cseip);
        break;

    case I_ADD_acc_eAX_Ivds:
        Handle_ADD_acc_eAX_Ivds(insb, cseip);
        break;

    case I_ADX_Ib:
        Handle_ADX_Ib(insb, cseip);
        break;

    case I_AMX_Ib:
        Handle_AMX_Ib(insb, cseip);
        break;

    case I_ANDNPD_Vpd_Wpd:
        Handle_ANDNPD_Vpd_Wpd(insb, cseip);
        break;

    case I_ANDNPS_Vps_Wps:
        Handle_ANDNPS_Vps_Wps(insb, cseip);
        break;

    case I_ANDPD_Vpd_Wpd:
        Handle_ANDPD_Vpd_Wpd(insb, cseip);
        break;

    case I_ANDPS_Vps_Wps:
        Handle_ANDPS_Vps_Wps(insb, cseip);
        break;

    case I_AND_Eb_Gb:
        Handle_AND_Eb_Gb(insb, cseip);
        break;

    case I_AND_Eb_Ib:
        Handle_AND_Eb_Ib(insb, cseip);
        break;

    case I_AND_Evqp_Gvqp:
        Handle_AND_Evqp_Gvqp(insb, cseip);
        break;

    case I_AND_Evqp_Ibs:
        Handle_AND_Evqp_Ibs(insb, cseip);
        break;

    case I_AND_Evqp_Ivds:
        Handle_AND_Evqp_Ivds(insb, cseip);
        break;

    case I_AND_Gb_Eb:
        Handle_AND_Gb_Eb(insb, cseip);
        break;

    case I_AND_Gvqp_Evqp:
        Handle_AND_Gvqp_Evqp(insb, cseip);
        break;

    case I_AND_acc_AL_Ib:
        Handle_AND_acc_AL_Ib(insb, cseip);
        break;

    case I_AND_acc_eAX_Ivds:
        Handle_AND_acc_eAX_Ivds(insb, cseip);
        break;

    case I_ARPL_Ew_Gw:
        Handle_ARPL_Ew_Gw(insb, cseip);
        break;

    case I_BLENDPD_Vpd_Wpd_Ib:
        Handle_BLENDPD_Vpd_Wpd_Ib(insb, cseip);
        break;

    case I_BLENDPS_Vps_Wps_Ib:
        Handle_BLENDPS_Vps_Wps_Ib(insb, cseip);
        break;

    case I_BLENDVPD_Vpd_Wpd:
        Handle_BLENDVPD_Vpd_Wpd(insb, cseip);
        break;

    case I_BLENDVPS_Vps_Wps:
        Handle_BLENDVPS_Vps_Wps(insb, cseip);
        break;

    case I_BOUND_Gv_Ma:
        Handle_BOUND_Gv_Ma(insb, cseip);
        break;

    case I_BSF_Gvqp_Evqp:
        Handle_BSF_Gvqp_Evqp(insb, cseip);
        break;

    case I_BSR_Gvqp_Evqp:
        Handle_BSR_Gvqp_Evqp(insb, cseip);
        break;

    case I_BSWAP_eAX:
        Handle_BSWAP_eAX(insb, cseip);
        break;

    case I_BSWAP_eBP:
        Handle_BSWAP_eBP(insb, cseip);
        break;

    case I_BSWAP_eBX:
        Handle_BSWAP_eBX(insb, cseip);
        break;

    case I_BSWAP_eCX:
        Handle_BSWAP_eCX(insb, cseip);
        break;

    case I_BSWAP_eDI:
        Handle_BSWAP_eDI(insb, cseip);
        break;

    case I_BSWAP_eDX:
        Handle_BSWAP_eDX(insb, cseip);
        break;

    case I_BSWAP_eSI:
        Handle_BSWAP_eSI(insb, cseip);
        break;

    case I_BSWAP_eSP:
        Handle_BSWAP_eSP(insb, cseip);
        break;

    case I_BTC_Evqp_Gvqp:
        Handle_BTC_Evqp_Gvqp(insb, cseip);
        break;

    case I_BTC_Evqp_Ib:
        Handle_BTC_Evqp_Ib(insb, cseip);
        break;

    case I_BTR_Evqp_Gvqp:
        Handle_BTR_Evqp_Gvqp(insb, cseip);
        break;

    case I_BTR_Evqp_Ib:
        Handle_BTR_Evqp_Ib(insb, cseip);
        break;

    case I_BTS_Evqp_Gvqp:
        Handle_BTS_Evqp_Gvqp(insb, cseip);
        break;

    case I_BTS_Evqp_Ib:
        Handle_BTS_Evqp_Ib(insb, cseip);
        break;

    case I_BT_Evqp_Gvqp:
        Handle_BT_Evqp_Gvqp(insb, cseip);
        break;

    case I_BT_Evqp_Ib:
        Handle_BT_Evqp_Ib(insb, cseip);
        break;

    case I_CALLF_Ap:
        Handle_CALLF_Ap(insb, cseip);
        break;

    case I_CALLF_Mptp:
        Handle_CALLF_Mptp(insb, cseip);
        break;

    case I_CALL_Ev:
        Handle_CALL_Ev(insb, cseip);
        break;

    case I_CALL_Jvds:
        Handle_CALL_Jvds(insb, cseip);
        break;

    case I_CBW:
        Handle_CBW(insb, cseip);
        break;

    case I_CDQ:
        Handle_CDQ(insb, cseip);
        break;

    case I_CLC:
        Handle_CLC(insb, cseip);
        break;

    case I_CLD:
        Handle_CLD(insb, cseip);
        break;

    case I_CLFLUSH_Mb:
        Handle_CLFLUSH_Mb(insb, cseip);
        break;

    case I_CLI:
        Handle_CLI(insb, cseip);
        break;

    case I_CLTS:
        Handle_CLTS(insb, cseip);
        break;

    case I_CMC:
        Handle_CMC(insb, cseip);
        break;

    case I_CMOVBE_Gvqp_Evqp:
        Handle_CMOVBE_Gvqp_Evqp(insb, cseip);
        break;

    case I_CMOVB_Gvqp_Evqp:
        Handle_CMOVB_Gvqp_Evqp(insb, cseip);
        break;

    case I_CMOVLE_Gvqp_Evqp:
        Handle_CMOVLE_Gvqp_Evqp(insb, cseip);
        break;

    case I_CMOVL_Gvqp_Evqp:
        Handle_CMOVL_Gvqp_Evqp(insb, cseip);
        break;

    case I_CMOVNBE_Gvqp_Evqp:
        Handle_CMOVNBE_Gvqp_Evqp(insb, cseip);
        break;

    case I_CMOVNB_Gvqp_Evqp:
        Handle_CMOVNB_Gvqp_Evqp(insb, cseip);
        break;

    case I_CMOVNLE_Gvqp_Evqp:
        Handle_CMOVNLE_Gvqp_Evqp(insb, cseip);
        break;

    case I_CMOVNL_Gvqp_Evqp:
        Handle_CMOVNL_Gvqp_Evqp(insb, cseip);
        break;

    case I_CMOVNO_Gvqp_Evqp:
        Handle_CMOVNO_Gvqp_Evqp(insb, cseip);
        break;

    case I_CMOVNP_Gvqp_Evqp:
        Handle_CMOVNP_Gvqp_Evqp(insb, cseip);
        break;

    case I_CMOVNS_Gvqp_Evqp:
        Handle_CMOVNS_Gvqp_Evqp(insb, cseip);
        break;

    case I_CMOVNZ_Gvqp_Evqp:
        Handle_CMOVNZ_Gvqp_Evqp(insb, cseip);
        break;

    case I_CMOVO_Gvqp_Evqp:
        Handle_CMOVO_Gvqp_Evqp(insb, cseip);
        break;

    case I_CMOVP_Gvqp_Evqp:
        Handle_CMOVP_Gvqp_Evqp(insb, cseip);
        break;

    case I_CMOVS_Gvqp_Evqp:
        Handle_CMOVS_Gvqp_Evqp(insb, cseip);
        break;

    case I_CMOVZ_Gvqp_Evqp:
        Handle_CMOVZ_Gvqp_Evqp(insb, cseip);
        break;

    case I_CMPPD_Vpd_Wpd_Ib:
        Handle_CMPPD_Vpd_Wpd_Ib(insb, cseip);
        break;

    case I_CMPPS_Vps_Wps_Ib:
        Handle_CMPPS_Vps_Wps_Ib(insb, cseip);
        break;

    case I_CMPSD_Vsd_Wsd_Ib:
        Handle_CMPSD_Vsd_Wsd_Ib(insb, cseip);
        break;

    case I_CMPSS_Vss_Wss_Ib:
        Handle_CMPSS_Vss_Wss_Ib(insb, cseip);
        break;

    case I_CMPS_Yb_Xb:
        Handle_CMPS_Yb_Xb(insb, cseip);
        break;

    case I_CMPS_Yv_Xv:
        Handle_CMPS_Yv_Xv(insb, cseip);
        break;

    case I_CMPS_Yw_Xw:
        Handle_CMPS_Yw_Xw(insb, cseip);
        break;

    case I_CMPXCHG8B_Mq:
        Handle_CMPXCHG8B_Mq(insb, cseip);
        break;

    case I_CMPXCHG_Eb_Gb:
        Handle_CMPXCHG_Eb_Gb(insb, cseip);
        break;

    case I_CMPXCHG_Evqp_Gvqp:
        Handle_CMPXCHG_Evqp_Gvqp(insb, cseip);
        break;

    case I_CMP_Eb_Gb:
        Handle_CMP_Eb_Gb(insb, cseip);
        break;

    case I_CMP_Eb_Ib:
        Handle_CMP_Eb_Ib(insb, cseip);
        break;

    case I_CMP_Evqp_Gvqp:
        Handle_CMP_Evqp_Gvqp(insb, cseip);
        break;

    case I_CMP_Evqp_Ibs:
        Handle_CMP_Evqp_Ibs(insb, cseip);
        break;

    case I_CMP_Evqp_Ivds:
        Handle_CMP_Evqp_Ivds(insb, cseip);
        break;

    case I_CMP_Gb_Eb:
        Handle_CMP_Gb_Eb(insb, cseip);
        break;

    case I_CMP_Gvqp_Evqp:
        Handle_CMP_Gvqp_Evqp(insb, cseip);
        break;

    case I_CMP_acc_AL_Ib:
        Handle_CMP_acc_AL_Ib(insb, cseip);
        break;

    case I_CMP_acc_eAX_Ivds:
        Handle_CMP_acc_eAX_Ivds(insb, cseip);
        break;

    case I_COMISD_Vsd_Wsd:
        Handle_COMISD_Vsd_Wsd(insb, cseip);
        break;

    case I_COMISS_Vss_Wss:
        Handle_COMISS_Vss_Wss(insb, cseip);
        break;

    case I_CPUID_serial:
        Handle_CPUID_serial(insb, cseip);
        break;

    case I_CRC32_Gdqp_Eb:
        Handle_CRC32_Gdqp_Eb(insb, cseip);
        break;

    case I_CRC32_Gdqp_Evqp:
        Handle_CRC32_Gdqp_Evqp(insb, cseip);
        break;

    case I_CVTDQ2PD_Vpd_Wdq:
        Handle_CVTDQ2PD_Vpd_Wdq(insb, cseip);
        break;

    case I_CVTDQ2PS_Vps_Wdq:
        Handle_CVTDQ2PS_Vps_Wdq(insb, cseip);
        break;

    case I_CVTPD2DQ_Vdq_Wpd:
        Handle_CVTPD2DQ_Vdq_Wpd(insb, cseip);
        break;

    case I_CVTPD2PI_Ppi_Wpd:
        Handle_CVTPD2PI_Ppi_Wpd(insb, cseip);
        break;

    case I_CVTPD2PS_Vps_Wpd:
        Handle_CVTPD2PS_Vps_Wpd(insb, cseip);
        break;

    case I_CVTPI2PD_Vpd_Qpi:
        Handle_CVTPI2PD_Vpd_Qpi(insb, cseip);
        break;

    case I_CVTPI2PS_Vps_Qpi:
        Handle_CVTPI2PS_Vps_Qpi(insb, cseip);
        break;

    case I_CVTPS2DQ_Vdq_Wps:
        Handle_CVTPS2DQ_Vdq_Wps(insb, cseip);
        break;

    case I_CVTPS2PD_Vpd_Wps:
        Handle_CVTPS2PD_Vpd_Wps(insb, cseip);
        break;

    case I_CVTPS2PI_Ppi_Wpsq:
        Handle_CVTPS2PI_Ppi_Wpsq(insb, cseip);
        break;

    case I_CVTSD2SI_Gdqp_Wsd:
        Handle_CVTSD2SI_Gdqp_Wsd(insb, cseip);
        break;

    case I_CVTSD2SS_Vss_Wsd:
        Handle_CVTSD2SS_Vss_Wsd(insb, cseip);
        break;

    case I_CVTSI2SD_Vsd_Edqp:
        Handle_CVTSI2SD_Vsd_Edqp(insb, cseip);
        break;

    case I_CVTSI2SS_Vss_Edqp:
        Handle_CVTSI2SS_Vss_Edqp(insb, cseip);
        break;

    case I_CVTSS2SD_Vsd_Wss:
        Handle_CVTSS2SD_Vsd_Wss(insb, cseip);
        break;

    case I_CVTSS2SI_Gdqp_Wss:
        Handle_CVTSS2SI_Gdqp_Wss(insb, cseip);
        break;

    case I_CVTTPD2DQ_Vdq_Wpd:
        Handle_CVTTPD2DQ_Vdq_Wpd(insb, cseip);
        break;

    case I_CVTTPD2PI_Ppi_Wpd:
        Handle_CVTTPD2PI_Ppi_Wpd(insb, cseip);
        break;

    case I_CVTTPS2DQ_Vdq_Wps:
        Handle_CVTTPS2DQ_Vdq_Wps(insb, cseip);
        break;

    case I_CVTTPS2PI_Ppi_Wpsq:
        Handle_CVTTPS2PI_Ppi_Wpsq(insb, cseip);
        break;

    case I_CVTTSD2SI_Gdqp_Wsd:
        Handle_CVTTSD2SI_Gdqp_Wsd(insb, cseip);
        break;

    case I_CVTTSS2SI_Gdqp_Wss:
        Handle_CVTTSS2SI_Gdqp_Wss(insb, cseip);
        break;

    case I_CWD:
        Handle_CWD(insb, cseip);
        break;

    case I_CWDE:
        Handle_CWDE(insb, cseip);
        break;

    case I_DAA:
        Handle_DAA(insb, cseip);
        break;

    case I_DAS:
        Handle_DAS(insb, cseip);
        break;

    case I_DEC_Eb:
        Handle_DEC_Eb(insb, cseip);
        break;

    case I_DEC_Evqp:
        Handle_DEC_Evqp(insb, cseip);
        break;

    case I_DEC_eAX:
        Handle_DEC_eAX(insb, cseip);
        break;

    case I_DEC_eBP:
        Handle_DEC_eBP(insb, cseip);
        break;

    case I_DEC_eBX:
        Handle_DEC_eBX(insb, cseip);
        break;

    case I_DEC_eCX:
        Handle_DEC_eCX(insb, cseip);
        break;

    case I_DEC_eDI:
        Handle_DEC_eDI(insb, cseip);
        break;

    case I_DEC_eDX:
        Handle_DEC_eDX(insb, cseip);
        break;

    case I_DEC_eSI:
        Handle_DEC_eSI(insb, cseip);
        break;

    case I_DEC_eSP:
        Handle_DEC_eSP(insb, cseip);
        break;

    case I_DIVPD_Vpd_Wpd:
        Handle_DIVPD_Vpd_Wpd(insb, cseip);
        break;

    case I_DIVPS_Vps_Wps:
        Handle_DIVPS_Vps_Wps(insb, cseip);
        break;

    case I_DIVSD_Vsd_Wsd:
        Handle_DIVSD_Vsd_Wsd(insb, cseip);
        break;

    case I_DIVSS_Vss_Wss:
        Handle_DIVSS_Vss_Wss(insb, cseip);
        break;

    case I_DIV_Eb:
        Handle_DIV_Eb(insb, cseip);
        break;

    case I_DIV_Evqp:
        Handle_DIV_Evqp(insb, cseip);
        break;

    case I_DPPD_Vpd_Wpd:
        Handle_DPPD_Vpd_Wpd(insb, cseip);
        break;

    case I_DPPS_Vps_Wps:
        Handle_DPPS_Vps_Wps(insb, cseip);
        break;

    case I_EMMS:
        Handle_EMMS(insb, cseip);
        break;

    case I_ENTER_Iw_Ib:
        Handle_ENTER_Iw_Ib(insb, cseip);
        break;

    case I_EXTRACTPS_Ed_Vdq_Ib:
        Handle_EXTRACTPS_Ed_Vdq_Ib(insb, cseip);
        break;

    case I_FWAIT:
        Handle_FWAIT(insb, cseip);
        break;

    case I_FXRSTOR_Mstx:
        Handle_FXRSTOR_Mstx(insb, cseip);
        break;

    case I_FXSAVE_Mstx:
        Handle_FXSAVE_Mstx(insb, cseip);
        break;

    case I_GETSEC:
        Handle_GETSEC(insb, cseip);
        break;

    case I_HADDPD_Vpd_Wpd:
        Handle_HADDPD_Vpd_Wpd(insb, cseip);
        break;

    case I_HADDPS_Vps_Wps:
        Handle_HADDPS_Vps_Wps(insb, cseip);
        break;

    case I_HLT:
        Handle_HLT(insb, cseip);
        break;

    case I_HSUBPD_Vpd_Wpd:
        Handle_HSUBPD_Vpd_Wpd(insb, cseip);
        break;

    case I_HSUBPS_Vps_Wps:
        Handle_HSUBPS_Vps_Wps(insb, cseip);
        break;

    case I_IDIV_Eb:
        Handle_IDIV_Eb(insb, cseip);
        break;

    case I_IDIV_Evqp:
        Handle_IDIV_Evqp(insb, cseip);
        break;

    case I_IMUL_Eb:
        Handle_IMUL_Eb(insb, cseip);
        break;

    case I_IMUL_Evqp:
        Handle_IMUL_Evqp(insb, cseip);
        break;

    case I_IMUL_Gvqp_Evqp:
        Handle_IMUL_Gvqp_Evqp(insb, cseip);
        break;

    case I_IMUL_Gvqp_Evqp_Ibs:
        Handle_IMUL_Gvqp_Evqp_Ibs(insb, cseip);
        break;

    case I_IMUL_Gvqp_Evqp_Ivds:
        Handle_IMUL_Gvqp_Evqp_Ivds(insb, cseip);
        break;

    case I_INC_Eb:
        Handle_INC_Eb(insb, cseip);
        break;

    case I_INC_Evqp:
        Handle_INC_Evqp(insb, cseip);
        break;

    case I_INC_eAX:
        Handle_INC_eAX(insb, cseip);
        break;

    case I_INC_eBP:
        Handle_INC_eBP(insb, cseip);
        break;

    case I_INC_eBX:
        Handle_INC_eBX(insb, cseip);
        break;

    case I_INC_eCX:
        Handle_INC_eCX(insb, cseip);
        break;

    case I_INC_eDI:
        Handle_INC_eDI(insb, cseip);
        break;

    case I_INC_eDX:
        Handle_INC_eDX(insb, cseip);
        break;

    case I_INC_eSI:
        Handle_INC_eSI(insb, cseip);
        break;

    case I_INC_eSP:
        Handle_INC_eSP(insb, cseip);
        break;

    case I_INSERTPS_Vps_Ups_Ib:
        Handle_INSERTPS_Vps_Ups_Ib(insb, cseip);
        break;

    case I_INS_Yb_DX:
        Handle_INS_Yb_DX(insb, cseip);
        break;

    case I_INS_Yv_DX:
        Handle_INS_Yv_DX(insb, cseip);
        break;

    case I_INS_Yw_DX:
        Handle_INS_Yw_DX(insb, cseip);
        break;

    case I_INTO:
        Handle_INTO(insb, cseip);
        break;

    case I_INT_I:
        Handle_INT_I(insb, cseip);
        break;

    case I_INT_Ib:
        Handle_INT_Ib(insb, cseip);
        break;

    case I_INVD_serial:
        Handle_INVD_serial(insb, cseip);
        break;

    case I_INVEPT_Gd_Mdq:
        Handle_INVEPT_Gd_Mdq(insb, cseip);
        break;

    case I_INVLPG_serial_M:
        Handle_INVLPG_serial_M(insb, cseip);
        break;

    case I_INVVPID_Gd_Mdq:
        Handle_INVVPID_Gd_Mdq(insb, cseip);
        break;

    case I_IN_AL_DX:
        Handle_IN_AL_DX(insb, cseip);
        break;

    case I_IN_AL_Ib:
        Handle_IN_AL_Ib(insb, cseip);
        break;

    case I_IN_eAX_DX:
        Handle_IN_eAX_DX(insb, cseip);
        break;

    case I_IN_eAX_Ib:
        Handle_IN_eAX_Ib(insb, cseip);
        break;

    case I_IRET:
        Handle_IRET(insb, cseip);
        break;

    case I_IRETD:
        Handle_IRETD(insb, cseip);
        break;

    case I_JBE_Jbs:
        Handle_JBE_Jbs(insb, cseip);
        break;

    case I_JBE_Jvds:
        Handle_JBE_Jvds(insb, cseip);
        break;

    case I_JB_Jbs:
        Handle_JB_Jbs(insb, cseip);
        break;

    case I_JB_Jvds:
        Handle_JB_Jvds(insb, cseip);
        break;

    case I_JCXZ_Jbs:
        Handle_JCXZ_Jbs(insb, cseip);
        break;

    case I_JLE_Jbs:
        Handle_JLE_Jbs(insb, cseip);
        break;

    case I_JLE_Jvds:
        Handle_JLE_Jvds(insb, cseip);
        break;

    case I_JL_Jbs:
        Handle_JL_Jbs(insb, cseip);
        break;

    case I_JL_Jvds:
        Handle_JL_Jvds(insb, cseip);
        break;

    case I_JMPF_Ap:
        Handle_JMPF_Ap(insb, cseip);
        break;

    case I_JMPF_Mptp:
        Handle_JMPF_Mptp(insb, cseip);
        break;

    case I_JMP_Ev:
        Handle_JMP_Ev(insb, cseip);
        break;

    case I_JMP_Jbs:
        Handle_JMP_Jbs(insb, cseip);
        break;

    case I_JMP_Jvds:
        Handle_JMP_Jvds(insb, cseip);
        break;

    case I_JNBE_Jbs:
        Handle_JNBE_Jbs(insb, cseip);
        break;

    case I_JNBE_Jvds:
        Handle_JNBE_Jvds(insb, cseip);
        break;

    case I_JNB_Jbs:
        Handle_JNB_Jbs(insb, cseip);
        break;

    case I_JNB_Jvds:
        Handle_JNB_Jvds(insb, cseip);
        break;

    case I_JNLE_Jbs:
        Handle_JNLE_Jbs(insb, cseip);
        break;

    case I_JNLE_Jvds:
        Handle_JNLE_Jvds(insb, cseip);
        break;

    case I_JNL_Jbs:
        Handle_JNL_Jbs(insb, cseip);
        break;

    case I_JNL_Jvds:
        Handle_JNL_Jvds(insb, cseip);
        break;

    case I_JNO_Jbs:
        Handle_JNO_Jbs(insb, cseip);
        break;

    case I_JNO_Jvds:
        Handle_JNO_Jvds(insb, cseip);
        break;

    case I_JNP_Jbs:
        Handle_JNP_Jbs(insb, cseip);
        break;

    case I_JNP_Jvds:
        Handle_JNP_Jvds(insb, cseip);
        break;

    case I_JNS_Jbs:
        Handle_JNS_Jbs(insb, cseip);
        break;

    case I_JNS_Jvds:
        Handle_JNS_Jvds(insb, cseip);
        break;

    case I_JNZ_Jbs:
        Handle_JNZ_Jbs(insb, cseip);
        break;

    case I_JNZ_Jvds:
        Handle_JNZ_Jvds(insb, cseip);
        break;

    case I_JO_Jbs:
        Handle_JO_Jbs(insb, cseip);
        break;

    case I_JO_Jvds:
        Handle_JO_Jvds(insb, cseip);
        break;

    case I_JP_Jbs:
        Handle_JP_Jbs(insb, cseip);
        break;

    case I_JP_Jvds:
        Handle_JP_Jvds(insb, cseip);
        break;

    case I_JS_Jbs:
        Handle_JS_Jbs(insb, cseip);
        break;

    case I_JS_Jvds:
        Handle_JS_Jvds(insb, cseip);
        break;

    case I_JZ_Jbs:
        Handle_JZ_Jbs(insb, cseip);
        break;

    case I_JZ_Jvds:
        Handle_JZ_Jvds(insb, cseip);
        break;

    case I_LAHF:
        Handle_LAHF(insb, cseip);
        break;

    case I_LAR_Gvqp_Mw:
        Handle_LAR_Gvqp_Mw(insb, cseip);
        break;

    case I_LDDQU_Vdq_Mdq:
        Handle_LDDQU_Vdq_Mdq(insb, cseip);
        break;

    case I_LDMXCSR_Md:
        Handle_LDMXCSR_Md(insb, cseip);
        break;

    case I_LDS_Gv_Mp:
        Handle_LDS_Gv_Mp(insb, cseip);
        break;

    case I_LEAVE:
        Handle_LEAVE(insb, cseip);
        break;

    case I_LEA_Gvqp_M:
        Handle_LEA_Gvqp_M(insb, cseip);
        break;

    case I_LES_Gv_Mp:
        Handle_LES_Gv_Mp(insb, cseip);
        break;

    case I_LFENCE:
        Handle_LFENCE(insb, cseip);
        break;

    case I_LFS_Gvqp_Mptp:
        Handle_LFS_Gvqp_Mptp(insb, cseip);
        break;

    case I_LGDT_serial_Ms:
        Handle_LGDT_serial_Ms(insb, cseip);
        break;

    case I_LGS_Gvqp_Mptp:
        Handle_LGS_Gvqp_Mptp(insb, cseip);
        break;

    case I_LIDT_serial_Ms:
        Handle_LIDT_serial_Ms(insb, cseip);
        break;

    case I_LLDT_serial_Ew:
        Handle_LLDT_serial_Ew(insb, cseip);
        break;

    case I_LMSW_serial_Ew:
        Handle_LMSW_serial_Ew(insb, cseip);
        break;

    case I_LODS_Xb:
        Handle_LODS_Xb(insb, cseip);
        break;

    case I_LODS_Xv:
        Handle_LODS_Xv(insb, cseip);
        break;

    case I_LODS_Xw:
        Handle_LODS_Xw(insb, cseip);
        break;

    case I_LOOPNZ_Jbs:
        Handle_LOOPNZ_Jbs(insb, cseip);
        break;

    case I_LOOPZ_Jbs:
        Handle_LOOPZ_Jbs(insb, cseip);
        break;

    case I_LOOP_Jbs:
        Handle_LOOP_Jbs(insb, cseip);
        break;

    case I_LSL_Gvqp_Mw:
        Handle_LSL_Gvqp_Mw(insb, cseip);
        break;

    case I_LSS_Gvqp_Mptp:
        Handle_LSS_Gvqp_Mptp(insb, cseip);
        break;

    case I_LTR_serial_Ew:
        Handle_LTR_serial_Ew(insb, cseip);
        break;

    case I_MASKMOVDQU_Vdq_Udq:
        Handle_MASKMOVDQU_Vdq_Udq(insb, cseip);
        break;

    case I_MASKMOVQ_Pq_Nq:
        Handle_MASKMOVQ_Pq_Nq(insb, cseip);
        break;

    case I_MAXPD_Vpd_Wpd:
        Handle_MAXPD_Vpd_Wpd(insb, cseip);
        break;

    case I_MAXPS_Vps_Wps:
        Handle_MAXPS_Vps_Wps(insb, cseip);
        break;

    case I_MAXSD_Vsd_Wsd:
        Handle_MAXSD_Vsd_Wsd(insb, cseip);
        break;

    case I_MAXSS_Vss_Wss:
        Handle_MAXSS_Vss_Wss(insb, cseip);
        break;

    case I_MFENCE:
        Handle_MFENCE(insb, cseip);
        break;

    case I_MINPD_Vpd_Wpd:
        Handle_MINPD_Vpd_Wpd(insb, cseip);
        break;

    case I_MINPS_Vps_Wps:
        Handle_MINPS_Vps_Wps(insb, cseip);
        break;

    case I_MINSD_Vsd_Wsd:
        Handle_MINSD_Vsd_Wsd(insb, cseip);
        break;

    case I_MINSS_Vss_Wss:
        Handle_MINSS_Vss_Wss(insb, cseip);
        break;

    case I_MONITOR:
        Handle_MONITOR(insb, cseip);
        break;

    case I_MOVAPD_Vpd_Wpd:
        Handle_MOVAPD_Vpd_Wpd(insb, cseip);
        break;

    case I_MOVAPD_Wpd_Vpd:
        Handle_MOVAPD_Wpd_Vpd(insb, cseip);
        break;

    case I_MOVAPS_Vps_Wps:
        Handle_MOVAPS_Vps_Wps(insb, cseip);
        break;

    case I_MOVAPS_Wps_Vps:
        Handle_MOVAPS_Wps_Vps(insb, cseip);
        break;

    case I_MOVBE_Gvqp_Mvqp:
        Handle_MOVBE_Gvqp_Mvqp(insb, cseip);
        break;

    case I_MOVBE_Mvqp_Gvqp:
        Handle_MOVBE_Mvqp_Gvqp(insb, cseip);
        break;

    case I_MOVDDUP_Vq_Wq:
        Handle_MOVDDUP_Vq_Wq(insb, cseip);
        break;

    case I_MOVDQ2Q_Pq_Uq:
        Handle_MOVDQ2Q_Pq_Uq(insb, cseip);
        break;

    case I_MOVDQA_Vdq_Wdq:
        Handle_MOVDQA_Vdq_Wdq(insb, cseip);
        break;

    case I_MOVDQA_Wdq_Vdq:
        Handle_MOVDQA_Wdq_Vdq(insb, cseip);
        break;

    case I_MOVDQU_Vdq_Wdq:
        Handle_MOVDQU_Vdq_Wdq(insb, cseip);
        break;

    case I_MOVDQU_Wdq_Vdq:
        Handle_MOVDQU_Wdq_Vdq(insb, cseip);
        break;

    case I_MOVD_Ed_Pq:
        Handle_MOVD_Ed_Pq(insb, cseip);
        break;

    case I_MOVD_Ed_Vdq:
        Handle_MOVD_Ed_Vdq(insb, cseip);
        break;

    case I_MOVD_Pq_Ed:
        Handle_MOVD_Pq_Ed(insb, cseip);
        break;

    case I_MOVD_Vdq_Ed:
        Handle_MOVD_Vdq_Ed(insb, cseip);
        break;

    case I_MOVHLPS_Vq_Uq:
        Handle_MOVHLPS_Vq_Uq(insb, cseip);
        break;

    case I_MOVHPD_Mq_Vq:
        Handle_MOVHPD_Mq_Vq(insb, cseip);
        break;

    case I_MOVHPD_Vq_Mq:
        Handle_MOVHPD_Vq_Mq(insb, cseip);
        break;

    case I_MOVHPS_Mq_Vq:
        Handle_MOVHPS_Mq_Vq(insb, cseip);
        break;

    case I_MOVHPS_Vq_Mq:
        Handle_MOVHPS_Vq_Mq(insb, cseip);
        break;

    case I_MOVLHPS_Vq_Uq:
        Handle_MOVLHPS_Vq_Uq(insb, cseip);
        break;

    case I_MOVLPD_Mq_Vq:
        Handle_MOVLPD_Mq_Vq(insb, cseip);
        break;

    case I_MOVLPD_Vq_Mq:
        Handle_MOVLPD_Vq_Mq(insb, cseip);
        break;

    case I_MOVLPS_Mq_Vq:
        Handle_MOVLPS_Mq_Vq(insb, cseip);
        break;

    case I_MOVLPS_Vq_Mq:
        Handle_MOVLPS_Vq_Mq(insb, cseip);
        break;

    case I_MOVMSKPD_Gdqp_Upd:
        Handle_MOVMSKPD_Gdqp_Upd(insb, cseip);
        break;

    case I_MOVMSKPS_Gdqp_Ups:
        Handle_MOVMSKPS_Gdqp_Ups(insb, cseip);
        break;

    case I_MOVNTDQA_Vdq_Mdq:
        Handle_MOVNTDQA_Vdq_Mdq(insb, cseip);
        break;

    case I_MOVNTDQ_Mdq_Vdq:
        Handle_MOVNTDQ_Mdq_Vdq(insb, cseip);
        break;

    case I_MOVNTI_Mdqp_Gdqp:
        Handle_MOVNTI_Mdqp_Gdqp(insb, cseip);
        break;

    case I_MOVNTPD_Mpd_Vpd:
        Handle_MOVNTPD_Mpd_Vpd(insb, cseip);
        break;

    case I_MOVNTPS_Mps_Vps:
        Handle_MOVNTPS_Mps_Vps(insb, cseip);
        break;

    case I_MOVNTQ_Mq_Pq:
        Handle_MOVNTQ_Mq_Pq(insb, cseip);
        break;

    case I_MOVQ2DQ_Vdq_Nq:
        Handle_MOVQ2DQ_Vdq_Nq(insb, cseip);
        break;

    case I_MOVQ_Pq_Qq:
        Handle_MOVQ_Pq_Qq(insb, cseip);
        break;

    case I_MOVQ_Qq_Pq:
        Handle_MOVQ_Qq_Pq(insb, cseip);
        break;

    case I_MOVQ_Vq_Wq:
        Handle_MOVQ_Vq_Wq(insb, cseip);
        break;

    case I_MOVQ_Wq_Vq:
        Handle_MOVQ_Wq_Vq(insb, cseip);
        break;

    case I_MOVSD_Vsd_Wsd:
        Handle_MOVSD_Vsd_Wsd(insb, cseip);
        break;

    case I_MOVSD_Wsd_Vsd:
        Handle_MOVSD_Wsd_Vsd(insb, cseip);
        break;

    case I_MOVSHDUP_Vq_Wq:
        Handle_MOVSHDUP_Vq_Wq(insb, cseip);
        break;

    case I_MOVSLDUP_Vq_Wq:
        Handle_MOVSLDUP_Vq_Wq(insb, cseip);
        break;

    case I_MOVSS_Vss_Wss:
        Handle_MOVSS_Vss_Wss(insb, cseip);
        break;

    case I_MOVSS_Wss_Vss:
        Handle_MOVSS_Wss_Vss(insb, cseip);
        break;

    case I_MOVSX_Gvqp_Eb:
        Handle_MOVSX_Gvqp_Eb(insb, cseip);
        break;

    case I_MOVSX_Gvqp_Ew:
        Handle_MOVSX_Gvqp_Ew(insb, cseip);
        break;

    case I_MOVS_Yb_Xb:
        Handle_MOVS_Yb_Xb(insb, cseip);
        break;

    case I_MOVS_Yv_Xv:
        Handle_MOVS_Yv_Xv(insb, cseip);
        break;

    case I_MOVS_Yw_Xw:
        Handle_MOVS_Yw_Xw(insb, cseip);
        break;

    case I_MOVUPD_Vpd_Wpd:
        Handle_MOVUPD_Vpd_Wpd(insb, cseip);
        break;

    case I_MOVUPD_Wpd_Vpd:
        Handle_MOVUPD_Wpd_Vpd(insb, cseip);
        break;

    case I_MOVUPS_Vps_Wps:
        Handle_MOVUPS_Vps_Wps(insb, cseip);
        break;

    case I_MOVUPS_Wps_Vps:
        Handle_MOVUPS_Wps_Vps(insb, cseip);
        break;

    case I_MOVZX_Gvqp_Eb:
        Handle_MOVZX_Gvqp_Eb(insb, cseip);
        break;

    case I_MOVZX_Gvqp_Ew:
        Handle_MOVZX_Gvqp_Ew(insb, cseip);
        break;

    case I_MOV_AH_Ib:
        Handle_MOV_AH_Ib(insb, cseip);
        break;

    case I_MOV_AL_Ib:
        Handle_MOV_AL_Ib(insb, cseip);
        break;

    case I_MOV_AL_Ob:
        Handle_MOV_AL_Ob(insb, cseip);
        break;

    case I_MOV_BH_Ib:
        Handle_MOV_BH_Ib(insb, cseip);
        break;

    case I_MOV_BL_Ib:
        Handle_MOV_BL_Ib(insb, cseip);
        break;

    case I_MOV_CH_Ib:
        Handle_MOV_CH_Ib(insb, cseip);
        break;

    case I_MOV_CL_Ib:
        Handle_MOV_CL_Ib(insb, cseip);
        break;

    case I_MOV_DH_Ib:
        Handle_MOV_DH_Ib(insb, cseip);
        break;

    case I_MOV_DL_Ib:
        Handle_MOV_DL_Ib(insb, cseip);
        break;

    case I_MOV_Eb_Gb:
        Handle_MOV_Eb_Gb(insb, cseip);
        break;

    case I_MOV_Eb_Ib:
        Handle_MOV_Eb_Ib(insb, cseip);
        break;

    case I_MOV_Evqp_Gvqp:
        Handle_MOV_Evqp_Gvqp(insb, cseip);
        break;

    case I_MOV_Evqp_Ivds:
        Handle_MOV_Evqp_Ivds(insb, cseip);
        break;

    case I_MOV_Gb_Eb:
        Handle_MOV_Gb_Eb(insb, cseip);
        break;

    case I_MOV_Gvqp_Evqp:
        Handle_MOV_Gvqp_Evqp(insb, cseip);
        break;

    case I_MOV_Mw_Sw:
        Handle_MOV_Mw_Sw(insb, cseip);
        break;

    case I_MOV_Ob_AL:
        Handle_MOV_Ob_AL(insb, cseip);
        break;

    case I_MOV_Ovqp_eAX:
        Handle_MOV_Ovqp_eAX(insb, cseip);
        break;

    case I_MOV_Sw_Ew:
        Handle_MOV_Sw_Ew(insb, cseip);
        break;

    case I_MOV_eAX_Ivqp:
        Handle_MOV_eAX_Ivqp(insb, cseip);
        break;

    case I_MOV_eAX_Ovqp:
        Handle_MOV_eAX_Ovqp(insb, cseip);
        break;

    case I_MOV_eBP_Ivqp:
        Handle_MOV_eBP_Ivqp(insb, cseip);
        break;

    case I_MOV_eBX_Ivqp:
        Handle_MOV_eBX_Ivqp(insb, cseip);
        break;

    case I_MOV_eCX_Ivqp:
        Handle_MOV_eCX_Ivqp(insb, cseip);
        break;

    case I_MOV_eDI_Ivqp:
        Handle_MOV_eDI_Ivqp(insb, cseip);
        break;

    case I_MOV_eDX_Ivqp:
        Handle_MOV_eDX_Ivqp(insb, cseip);
        break;

    case I_MOV_eSI_Ivqp:
        Handle_MOV_eSI_Ivqp(insb, cseip);
        break;

    case I_MOV_eSP_Ivqp:
        Handle_MOV_eSP_Ivqp(insb, cseip);
        break;

    case I_MPSADBW_Vdq_Wdq_Ib:
        Handle_MPSADBW_Vdq_Wdq_Ib(insb, cseip);
        break;

    case I_MULPD_Vpd_Wpd:
        Handle_MULPD_Vpd_Wpd(insb, cseip);
        break;

    case I_MULPS_Vps_Wps:
        Handle_MULPS_Vps_Wps(insb, cseip);
        break;

    case I_MULSD_Vsd_Wsd:
        Handle_MULSD_Vsd_Wsd(insb, cseip);
        break;

    case I_MULSS_Vss_Wss:
        Handle_MULSS_Vss_Wss(insb, cseip);
        break;

    case I_MUL_Eb:
        Handle_MUL_Eb(insb, cseip);
        break;

    case I_MUL_Evqp:
        Handle_MUL_Evqp(insb, cseip);
        break;

    case I_MWAIT:
        Handle_MWAIT(insb, cseip);
        break;

    case I_NEG_Eb:
        Handle_NEG_Eb(insb, cseip);
        break;

    case I_NEG_Evqp:
        Handle_NEG_Evqp(insb, cseip);
        break;

    case I_NOP:
        Handle_NOP(insb, cseip);
        break;

    case I_NOP_Ev:
        Handle_NOP_Ev(insb, cseip);
        break;

    case I_NOP_nop:
        Handle_NOP_nop(insb, cseip);
        break;

    case I_NOT_Eb:
        Handle_NOT_Eb(insb, cseip);
        break;

    case I_NOT_Evqp:
        Handle_NOT_Evqp(insb, cseip);
        break;

    case I_ORPD_Vpd_Wpd:
        Handle_ORPD_Vpd_Wpd(insb, cseip);
        break;

    case I_ORPS_Vps_Wps:
        Handle_ORPS_Vps_Wps(insb, cseip);
        break;

    case I_OR_Eb_Gb:
        Handle_OR_Eb_Gb(insb, cseip);
        break;

    case I_OR_Eb_Ib:
        Handle_OR_Eb_Ib(insb, cseip);
        break;

    case I_OR_Evqp_Gvqp:
        Handle_OR_Evqp_Gvqp(insb, cseip);
        break;

    case I_OR_Evqp_Ibs:
        Handle_OR_Evqp_Ibs(insb, cseip);
        break;

    case I_OR_Evqp_Ivds:
        Handle_OR_Evqp_Ivds(insb, cseip);
        break;

    case I_OR_Gb_Eb:
        Handle_OR_Gb_Eb(insb, cseip);
        break;

    case I_OR_Gvqp_Evqp:
        Handle_OR_Gvqp_Evqp(insb, cseip);
        break;

    case I_OR_acc_AL_Ib:
        Handle_OR_acc_AL_Ib(insb, cseip);
        break;

    case I_OR_acc_eAX_Ivds:
        Handle_OR_acc_eAX_Ivds(insb, cseip);
        break;

    case I_OUTS_DX_Xb:
        Handle_OUTS_DX_Xb(insb, cseip);
        break;

    case I_OUTS_DX_Xv:
        Handle_OUTS_DX_Xv(insb, cseip);
        break;

    case I_OUTS_DX_Xw:
        Handle_OUTS_DX_Xw(insb, cseip);
        break;

    case I_OUT_DX_AL:
        Handle_OUT_DX_AL(insb, cseip);
        break;

    case I_OUT_DX_eAX:
        Handle_OUT_DX_eAX(insb, cseip);
        break;

    case I_OUT_Ib_AL:
        Handle_OUT_Ib_AL(insb, cseip);
        break;

    case I_OUT_Ib_eAX:
        Handle_OUT_Ib_eAX(insb, cseip);
        break;

    case I_PABSB_Pq_Qq:
        Handle_PABSB_Pq_Qq(insb, cseip);
        break;

    case I_PABSB_Vdq_Wdq:
        Handle_PABSB_Vdq_Wdq(insb, cseip);
        break;

    case I_PABSD_Pq_Qq:
        Handle_PABSD_Pq_Qq(insb, cseip);
        break;

    case I_PABSD_Vdq_Wdq:
        Handle_PABSD_Vdq_Wdq(insb, cseip);
        break;

    case I_PABSW_Pq_Qq:
        Handle_PABSW_Pq_Qq(insb, cseip);
        break;

    case I_PABSW_Vdq_Wdq:
        Handle_PABSW_Vdq_Wdq(insb, cseip);
        break;

    case I_PACKSSDW_Pq_Qq:
        Handle_PACKSSDW_Pq_Qq(insb, cseip);
        break;

    case I_PACKSSDW_Vdq_Wdq:
        Handle_PACKSSDW_Vdq_Wdq(insb, cseip);
        break;

    case I_PACKSSWB_Pq_Qd:
        Handle_PACKSSWB_Pq_Qd(insb, cseip);
        break;

    case I_PACKSSWB_Vdq_Wdq:
        Handle_PACKSSWB_Vdq_Wdq(insb, cseip);
        break;

    case I_PACKUSDW_Vdq_Wdq:
        Handle_PACKUSDW_Vdq_Wdq(insb, cseip);
        break;

    case I_PACKUSWB_Pq_Qq:
        Handle_PACKUSWB_Pq_Qq(insb, cseip);
        break;

    case I_PACKUSWB_Vdq_Wdq:
        Handle_PACKUSWB_Vdq_Wdq(insb, cseip);
        break;

    case I_PADDB_Pq_Qq:
        Handle_PADDB_Pq_Qq(insb, cseip);
        break;

    case I_PADDB_Vdq_Wdq:
        Handle_PADDB_Vdq_Wdq(insb, cseip);
        break;

    case I_PADDD_Pq_Qq:
        Handle_PADDD_Pq_Qq(insb, cseip);
        break;

    case I_PADDD_Vdq_Wdq:
        Handle_PADDD_Vdq_Wdq(insb, cseip);
        break;

    case I_PADDQ_Pq_Qq:
        Handle_PADDQ_Pq_Qq(insb, cseip);
        break;

    case I_PADDQ_Vdq_Wdq:
        Handle_PADDQ_Vdq_Wdq(insb, cseip);
        break;

    case I_PADDSB_Pq_Qq:
        Handle_PADDSB_Pq_Qq(insb, cseip);
        break;

    case I_PADDSB_Vdq_Wdq:
        Handle_PADDSB_Vdq_Wdq(insb, cseip);
        break;

    case I_PADDSW_Pq_Qq:
        Handle_PADDSW_Pq_Qq(insb, cseip);
        break;

    case I_PADDSW_Vdq_Wdq:
        Handle_PADDSW_Vdq_Wdq(insb, cseip);
        break;

    case I_PADDW_Pq_Qq:
        Handle_PADDW_Pq_Qq(insb, cseip);
        break;

    case I_PADDW_Vdq_Wdq:
        Handle_PADDW_Vdq_Wdq(insb, cseip);
        break;

    case I_PALIGNR_Pq_Qq:
        Handle_PALIGNR_Pq_Qq(insb, cseip);
        break;

    case I_PALIGNR_Vdq_Wdq:
        Handle_PALIGNR_Vdq_Wdq(insb, cseip);
        break;

    case I_PAUSE:
        Handle_PAUSE(insb, cseip);
        break;

    case I_PAVGB_Pq_Qq:
        Handle_PAVGB_Pq_Qq(insb, cseip);
        break;

    case I_PAVGB_Vdq_Wdq:
        Handle_PAVGB_Vdq_Wdq(insb, cseip);
        break;

    case I_PAVGW_Pq_Qq:
        Handle_PAVGW_Pq_Qq(insb, cseip);
        break;

    case I_PAVGW_Vdq_Wdq:
        Handle_PAVGW_Vdq_Wdq(insb, cseip);
        break;

    case I_PBLENDVB_Vdq_Wdq:
        Handle_PBLENDVB_Vdq_Wdq(insb, cseip);
        break;

    case I_PBLENDW_Vdq_Wdq_Ib:
        Handle_PBLENDW_Vdq_Wdq_Ib(insb, cseip);
        break;

    case I_PCMPEQB_Pq_Qq:
        Handle_PCMPEQB_Pq_Qq(insb, cseip);
        break;

    case I_PCMPEQB_Vdq_Wdq:
        Handle_PCMPEQB_Vdq_Wdq(insb, cseip);
        break;

    case I_PCMPEQD_Pq_Qq:
        Handle_PCMPEQD_Pq_Qq(insb, cseip);
        break;

    case I_PCMPEQD_Vdq_Wdq:
        Handle_PCMPEQD_Vdq_Wdq(insb, cseip);
        break;

    case I_PCMPEQQ_Vdq_Wdq:
        Handle_PCMPEQQ_Vdq_Wdq(insb, cseip);
        break;

    case I_PCMPEQW_Pq_Qq:
        Handle_PCMPEQW_Pq_Qq(insb, cseip);
        break;

    case I_PCMPEQW_Vdq_Wdq:
        Handle_PCMPEQW_Vdq_Wdq(insb, cseip);
        break;

    case I_PCMPESTRI_Vdq_Wdq_Ib:
        Handle_PCMPESTRI_Vdq_Wdq_Ib(insb, cseip);
        break;

    case I_PCMPESTRM_Vdq_Wdq_Ib:
        Handle_PCMPESTRM_Vdq_Wdq_Ib(insb, cseip);
        break;

    case I_PCMPGTB_Pq_Qd:
        Handle_PCMPGTB_Pq_Qd(insb, cseip);
        break;

    case I_PCMPGTB_Vdq_Wdq:
        Handle_PCMPGTB_Vdq_Wdq(insb, cseip);
        break;

    case I_PCMPGTD_Pq_Qd:
        Handle_PCMPGTD_Pq_Qd(insb, cseip);
        break;

    case I_PCMPGTD_Vdq_Wdq:
        Handle_PCMPGTD_Vdq_Wdq(insb, cseip);
        break;

    case I_PCMPGTQ_Vdq_Wdq:
        Handle_PCMPGTQ_Vdq_Wdq(insb, cseip);
        break;

    case I_PCMPGTW_Pq_Qd:
        Handle_PCMPGTW_Pq_Qd(insb, cseip);
        break;

    case I_PCMPGTW_Vdq_Wdq:
        Handle_PCMPGTW_Vdq_Wdq(insb, cseip);
        break;

    case I_PCMPISTRI_Vdq_Wdq_Ib:
        Handle_PCMPISTRI_Vdq_Wdq_Ib(insb, cseip);
        break;

    case I_PCMPISTRM_Vdq_Wdq_Ib:
        Handle_PCMPISTRM_Vdq_Wdq_Ib(insb, cseip);
        break;

    case I_PEXTRB_Mb_Vdq_Ib:
        Handle_PEXTRB_Mb_Vdq_Ib(insb, cseip);
        break;

    case I_PEXTRD_Ed_Vdq_Ib:
        Handle_PEXTRD_Ed_Vdq_Ib(insb, cseip);
        break;

    case I_PEXTRW_Gdqp_Nq_Ib:
        Handle_PEXTRW_Gdqp_Nq_Ib(insb, cseip);
        break;

    case I_PEXTRW_Gdqp_Udq_Ib:
        Handle_PEXTRW_Gdqp_Udq_Ib(insb, cseip);
        break;

    case I_PEXTRW_Mw_Vdq_Ib:
        Handle_PEXTRW_Mw_Vdq_Ib(insb, cseip);
        break;

    case I_PHADDD_Pq_Qq:
        Handle_PHADDD_Pq_Qq(insb, cseip);
        break;

    case I_PHADDD_Vdq_Wdq:
        Handle_PHADDD_Vdq_Wdq(insb, cseip);
        break;

    case I_PHADDSW_Pq_Qq:
        Handle_PHADDSW_Pq_Qq(insb, cseip);
        break;

    case I_PHADDSW_Vdq_Wdq:
        Handle_PHADDSW_Vdq_Wdq(insb, cseip);
        break;

    case I_PHADDW_Pq_Qq:
        Handle_PHADDW_Pq_Qq(insb, cseip);
        break;

    case I_PHADDW_Vdq_Wdq:
        Handle_PHADDW_Vdq_Wdq(insb, cseip);
        break;

    case I_PHMINPOSUW_Vdq_Wdq:
        Handle_PHMINPOSUW_Vdq_Wdq(insb, cseip);
        break;

    case I_PHSUBD_Pq_Qq:
        Handle_PHSUBD_Pq_Qq(insb, cseip);
        break;

    case I_PHSUBD_Vdq_Wdq:
        Handle_PHSUBD_Vdq_Wdq(insb, cseip);
        break;

    case I_PHSUBSW_Pq_Qq:
        Handle_PHSUBSW_Pq_Qq(insb, cseip);
        break;

    case I_PHSUBSW_Vdq_Wdq:
        Handle_PHSUBSW_Vdq_Wdq(insb, cseip);
        break;

    case I_PHSUBW_Pq_Qq:
        Handle_PHSUBW_Pq_Qq(insb, cseip);
        break;

    case I_PHSUBW_Vdq_Wdq:
        Handle_PHSUBW_Vdq_Wdq(insb, cseip);
        break;

    case I_PINSRB_Vdq_Mb_Ib:
        Handle_PINSRB_Vdq_Mb_Ib(insb, cseip);
        break;

    case I_PINSRD_Vdq_Ed_Ib:
        Handle_PINSRD_Vdq_Ed_Ib(insb, cseip);
        break;

    case I_PINSRW_Pq_Rdqp_Ib:
        Handle_PINSRW_Pq_Rdqp_Ib(insb, cseip);
        break;

    case I_PINSRW_Vdq_Rdqp_Ib:
        Handle_PINSRW_Vdq_Rdqp_Ib(insb, cseip);
        break;

    case I_PMADDUBSW_Pq_Qq:
        Handle_PMADDUBSW_Pq_Qq(insb, cseip);
        break;

    case I_PMADDUBSW_Vdq_Wdq:
        Handle_PMADDUBSW_Vdq_Wdq(insb, cseip);
        break;

    case I_PMADDWD_Pq_Qd:
        Handle_PMADDWD_Pq_Qd(insb, cseip);
        break;

    case I_PMADDWD_Vdq_Wdq:
        Handle_PMADDWD_Vdq_Wdq(insb, cseip);
        break;

    case I_PMAXSB_Vdq_Wdq:
        Handle_PMAXSB_Vdq_Wdq(insb, cseip);
        break;

    case I_PMAXSD_Vdq_Wdq:
        Handle_PMAXSD_Vdq_Wdq(insb, cseip);
        break;

    case I_PMAXSW_Pq_Qq:
        Handle_PMAXSW_Pq_Qq(insb, cseip);
        break;

    case I_PMAXSW_Vdq_Wdq:
        Handle_PMAXSW_Vdq_Wdq(insb, cseip);
        break;

    case I_PMAXUD_Vdq_Wdq:
        Handle_PMAXUD_Vdq_Wdq(insb, cseip);
        break;

    case I_PMAXUW_Vdq_Wdq:
        Handle_PMAXUW_Vdq_Wdq(insb, cseip);
        break;

    case I_PMINSB_Vdq_Wdq:
        Handle_PMINSB_Vdq_Wdq(insb, cseip);
        break;

    case I_PMINSD_Vdq_Wdq:
        Handle_PMINSD_Vdq_Wdq(insb, cseip);
        break;

    case I_PMINSW_Pq_Qq:
        Handle_PMINSW_Pq_Qq(insb, cseip);
        break;

    case I_PMINSW_Vdq_Wdq:
        Handle_PMINSW_Vdq_Wdq(insb, cseip);
        break;

    case I_PMINUD_Vdq_Wdq:
        Handle_PMINUD_Vdq_Wdq(insb, cseip);
        break;

    case I_PMINUW_Vdq_Wdq:
        Handle_PMINUW_Vdq_Wdq(insb, cseip);
        break;

    case I_PMOVMSKB_Gdqp_Nq:
        Handle_PMOVMSKB_Gdqp_Nq(insb, cseip);
        break;

    case I_PMOVMSKB_Gdqp_Udq:
        Handle_PMOVMSKB_Gdqp_Udq(insb, cseip);
        break;

    case I_PMOVSXBD_Vdq_Md:
        Handle_PMOVSXBD_Vdq_Md(insb, cseip);
        break;

    case I_PMOVSXBQ_Vdq_Mw:
        Handle_PMOVSXBQ_Vdq_Mw(insb, cseip);
        break;

    case I_PMOVSXBW_Vdq_Mq:
        Handle_PMOVSXBW_Vdq_Mq(insb, cseip);
        break;

    case I_PMOVSXDQ_Vdq_Mq:
        Handle_PMOVSXDQ_Vdq_Mq(insb, cseip);
        break;

    case I_PMOVSXWD_Vdq_Mq:
        Handle_PMOVSXWD_Vdq_Mq(insb, cseip);
        break;

    case I_PMOVSXWQ_Vdq_Md:
        Handle_PMOVSXWQ_Vdq_Md(insb, cseip);
        break;

    case I_PMOVZXBD_Vdq_Md:
        Handle_PMOVZXBD_Vdq_Md(insb, cseip);
        break;

    case I_PMOVZXBQ_Vdq_Mw:
        Handle_PMOVZXBQ_Vdq_Mw(insb, cseip);
        break;

    case I_PMOVZXBW_Vdq_Mq:
        Handle_PMOVZXBW_Vdq_Mq(insb, cseip);
        break;

    case I_PMOVZXDQ_Vdq_Mq:
        Handle_PMOVZXDQ_Vdq_Mq(insb, cseip);
        break;

    case I_PMOVZXWD_Vdq_Mq:
        Handle_PMOVZXWD_Vdq_Mq(insb, cseip);
        break;

    case I_PMOVZXWQ_Vdq_Md:
        Handle_PMOVZXWQ_Vdq_Md(insb, cseip);
        break;

    case I_PMULDQ_Vdq_Wdq:
        Handle_PMULDQ_Vdq_Wdq(insb, cseip);
        break;

    case I_PMULHRSW_Pq_Qq:
        Handle_PMULHRSW_Pq_Qq(insb, cseip);
        break;

    case I_PMULHRSW_Vdq_Wdq:
        Handle_PMULHRSW_Vdq_Wdq(insb, cseip);
        break;

    case I_PMULHUW_Pq_Qq:
        Handle_PMULHUW_Pq_Qq(insb, cseip);
        break;

    case I_PMULHUW_Vdq_Wdq:
        Handle_PMULHUW_Vdq_Wdq(insb, cseip);
        break;

    case I_PMULHW_Pq_Qq:
        Handle_PMULHW_Pq_Qq(insb, cseip);
        break;

    case I_PMULHW_Vdq_Wdq:
        Handle_PMULHW_Vdq_Wdq(insb, cseip);
        break;

    case I_PMULLD_Vdq_Wdq:
        Handle_PMULLD_Vdq_Wdq(insb, cseip);
        break;

    case I_PMULLW_Pq_Qq:
        Handle_PMULLW_Pq_Qq(insb, cseip);
        break;

    case I_PMULLW_Vdq_Wdq:
        Handle_PMULLW_Vdq_Wdq(insb, cseip);
        break;

    case I_PMULUDQ_Pq_Qq:
        Handle_PMULUDQ_Pq_Qq(insb, cseip);
        break;

    case I_PMULUDQ_Vdq_Wdq:
        Handle_PMULUDQ_Vdq_Wdq(insb, cseip);
        break;

    case I_POPA:
        Handle_POPA(insb, cseip);
        break;

    case I_POPAD:
        Handle_POPAD(insb, cseip);
        break;

    case I_POPCNT_Gvqp_Evqp:
        Handle_POPCNT_Gvqp_Evqp(insb, cseip);
        break;

    case I_POPF:
        Handle_POPF(insb, cseip);
        break;

    case I_POPFD:
        Handle_POPFD(insb, cseip);
        break;

    case I_POP_DS:
        Handle_POP_DS(insb, cseip);
        break;

    case I_POP_ES:
        Handle_POP_ES(insb, cseip);
        break;

    case I_POP_Ev:
        Handle_POP_Ev(insb, cseip);
        break;

    case I_POP_FS:
        Handle_POP_FS(insb, cseip);
        break;

    case I_POP_GS:
        Handle_POP_GS(insb, cseip);
        break;

    case I_POP_delaysint_SS:
        Handle_POP_delaysint_SS(insb, cseip);
        break;

    case I_POP_eAX:
        Handle_POP_eAX(insb, cseip);
        break;

    case I_POP_eBP:
        Handle_POP_eBP(insb, cseip);
        break;

    case I_POP_eBX:
        Handle_POP_eBX(insb, cseip);
        break;

    case I_POP_eCX:
        Handle_POP_eCX(insb, cseip);
        break;

    case I_POP_eDI:
        Handle_POP_eDI(insb, cseip);
        break;

    case I_POP_eDX:
        Handle_POP_eDX(insb, cseip);
        break;

    case I_POP_eSI:
        Handle_POP_eSI(insb, cseip);
        break;

    case I_POP_eSP:
        Handle_POP_eSP(insb, cseip);
        break;

    case I_POR_Pq_Qq:
        Handle_POR_Pq_Qq(insb, cseip);
        break;

    case I_POR_Vdq_Wdq:
        Handle_POR_Vdq_Wdq(insb, cseip);
        break;

    case I_PREFETCHNTA_Mb:
        Handle_PREFETCHNTA_Mb(insb, cseip);
        break;

    case I_PREFETCHT0_Mb:
        Handle_PREFETCHT0_Mb(insb, cseip);
        break;

    case I_PREFETCHT1_Mb:
        Handle_PREFETCHT1_Mb(insb, cseip);
        break;

    case I_PREFETCHT2_Mb:
        Handle_PREFETCHT2_Mb(insb, cseip);
        break;

    case I_PSADBW_Pq_Qq:
        Handle_PSADBW_Pq_Qq(insb, cseip);
        break;

    case I_PSADBW_Vdq_Wdq:
        Handle_PSADBW_Vdq_Wdq(insb, cseip);
        break;

    case I_PSHUFB_Pq_Qq:
        Handle_PSHUFB_Pq_Qq(insb, cseip);
        break;

    case I_PSHUFB_Vdq_Wdq:
        Handle_PSHUFB_Vdq_Wdq(insb, cseip);
        break;

    case I_PSHUFD_Vdq_Wdq_Ib:
        Handle_PSHUFD_Vdq_Wdq_Ib(insb, cseip);
        break;

    case I_PSHUFHW_Vdq_Wdq_Ib:
        Handle_PSHUFHW_Vdq_Wdq_Ib(insb, cseip);
        break;

    case I_PSHUFLW_Vdq_Wdq_Ib:
        Handle_PSHUFLW_Vdq_Wdq_Ib(insb, cseip);
        break;

    case I_PSHUFW_Pq_Qq_Ib:
        Handle_PSHUFW_Pq_Qq_Ib(insb, cseip);
        break;

    case I_PSIGNB_Pq_Qq:
        Handle_PSIGNB_Pq_Qq(insb, cseip);
        break;

    case I_PSIGNB_Vdq_Wdq:
        Handle_PSIGNB_Vdq_Wdq(insb, cseip);
        break;

    case I_PSIGND_Pq_Qq:
        Handle_PSIGND_Pq_Qq(insb, cseip);
        break;

    case I_PSIGND_Vdq_Wdq:
        Handle_PSIGND_Vdq_Wdq(insb, cseip);
        break;

    case I_PSIGNW_Pq_Qq:
        Handle_PSIGNW_Pq_Qq(insb, cseip);
        break;

    case I_PSIGNW_Vdq_Wdq:
        Handle_PSIGNW_Vdq_Wdq(insb, cseip);
        break;

    case I_PSLLDQ_Udq_Ib:
        Handle_PSLLDQ_Udq_Ib(insb, cseip);
        break;

    case I_PSLLD_Nq_Ib:
        Handle_PSLLD_Nq_Ib(insb, cseip);
        break;

    case I_PSLLD_Pq_Qq:
        Handle_PSLLD_Pq_Qq(insb, cseip);
        break;

    case I_PSLLD_Udq_Ib:
        Handle_PSLLD_Udq_Ib(insb, cseip);
        break;

    case I_PSLLD_Vdq_Wdq:
        Handle_PSLLD_Vdq_Wdq(insb, cseip);
        break;

    case I_PSLLQ_Nq_Ib:
        Handle_PSLLQ_Nq_Ib(insb, cseip);
        break;

    case I_PSLLQ_Pq_Qq:
        Handle_PSLLQ_Pq_Qq(insb, cseip);
        break;

    case I_PSLLQ_Udq_Ib:
        Handle_PSLLQ_Udq_Ib(insb, cseip);
        break;

    case I_PSLLQ_Vdq_Wdq:
        Handle_PSLLQ_Vdq_Wdq(insb, cseip);
        break;

    case I_PSLLW_Nq_Ib:
        Handle_PSLLW_Nq_Ib(insb, cseip);
        break;

    case I_PSLLW_Pq_Qq:
        Handle_PSLLW_Pq_Qq(insb, cseip);
        break;

    case I_PSLLW_Udq_Ib:
        Handle_PSLLW_Udq_Ib(insb, cseip);
        break;

    case I_PSLLW_Vdq_Wdq:
        Handle_PSLLW_Vdq_Wdq(insb, cseip);
        break;

    case I_PSRAD_Nq_Ib:
        Handle_PSRAD_Nq_Ib(insb, cseip);
        break;

    case I_PSRAD_Pq_Qq:
        Handle_PSRAD_Pq_Qq(insb, cseip);
        break;

    case I_PSRAD_Udq_Ib:
        Handle_PSRAD_Udq_Ib(insb, cseip);
        break;

    case I_PSRAD_Vdq_Wdq:
        Handle_PSRAD_Vdq_Wdq(insb, cseip);
        break;

    case I_PSRAW_Nq_Ib:
        Handle_PSRAW_Nq_Ib(insb, cseip);
        break;

    case I_PSRAW_Pq_Qq:
        Handle_PSRAW_Pq_Qq(insb, cseip);
        break;

    case I_PSRAW_Udq_Ib:
        Handle_PSRAW_Udq_Ib(insb, cseip);
        break;

    case I_PSRAW_Vdq_Wdq:
        Handle_PSRAW_Vdq_Wdq(insb, cseip);
        break;

    case I_PSRLDQ_Udq_Ib:
        Handle_PSRLDQ_Udq_Ib(insb, cseip);
        break;

    case I_PSRLD_Nq_Ib:
        Handle_PSRLD_Nq_Ib(insb, cseip);
        break;

    case I_PSRLD_Pq_Qq:
        Handle_PSRLD_Pq_Qq(insb, cseip);
        break;

    case I_PSRLD_Udq_Ib:
        Handle_PSRLD_Udq_Ib(insb, cseip);
        break;

    case I_PSRLD_Vdq_Wdq:
        Handle_PSRLD_Vdq_Wdq(insb, cseip);
        break;

    case I_PSRLQ_Nq_Ib:
        Handle_PSRLQ_Nq_Ib(insb, cseip);
        break;

    case I_PSRLQ_Pq_Qq:
        Handle_PSRLQ_Pq_Qq(insb, cseip);
        break;

    case I_PSRLQ_Udq_Ib:
        Handle_PSRLQ_Udq_Ib(insb, cseip);
        break;

    case I_PSRLQ_Vdq_Wdq:
        Handle_PSRLQ_Vdq_Wdq(insb, cseip);
        break;

    case I_PSRLW_Nq_Ib:
        Handle_PSRLW_Nq_Ib(insb, cseip);
        break;

    case I_PSRLW_Pq_Qq:
        Handle_PSRLW_Pq_Qq(insb, cseip);
        break;

    case I_PSRLW_Udq_Ib:
        Handle_PSRLW_Udq_Ib(insb, cseip);
        break;

    case I_PSRLW_Vdq_Wdq:
        Handle_PSRLW_Vdq_Wdq(insb, cseip);
        break;

    case I_PSUBB_Pq_Qq:
        Handle_PSUBB_Pq_Qq(insb, cseip);
        break;

    case I_PSUBB_Vdq_Wdq:
        Handle_PSUBB_Vdq_Wdq(insb, cseip);
        break;

    case I_PSUBD_Pq_Qq:
        Handle_PSUBD_Pq_Qq(insb, cseip);
        break;

    case I_PSUBD_Vdq_Wdq:
        Handle_PSUBD_Vdq_Wdq(insb, cseip);
        break;

    case I_PSUBQ_Pq_Qq:
        Handle_PSUBQ_Pq_Qq(insb, cseip);
        break;

    case I_PSUBQ_Vdq_Wdq:
        Handle_PSUBQ_Vdq_Wdq(insb, cseip);
        break;

    case I_PSUBSB_Pq_Qq:
        Handle_PSUBSB_Pq_Qq(insb, cseip);
        break;

    case I_PSUBSB_Vdq_Wdq:
        Handle_PSUBSB_Vdq_Wdq(insb, cseip);
        break;

    case I_PSUBSW_Pq_Qq:
        Handle_PSUBSW_Pq_Qq(insb, cseip);
        break;

    case I_PSUBSW_Vdq_Wdq:
        Handle_PSUBSW_Vdq_Wdq(insb, cseip);
        break;

    case I_PSUBW_Pq_Qq:
        Handle_PSUBW_Pq_Qq(insb, cseip);
        break;

    case I_PSUBW_Vdq_Wdq:
        Handle_PSUBW_Vdq_Wdq(insb, cseip);
        break;

    case I_PTEST_Vdq_Wdq:
        Handle_PTEST_Vdq_Wdq(insb, cseip);
        break;

    case I_PUNPCKHBW_Pq_Qq:
        Handle_PUNPCKHBW_Pq_Qq(insb, cseip);
        break;

    case I_PUNPCKHBW_Vdq_Wdq:
        Handle_PUNPCKHBW_Vdq_Wdq(insb, cseip);
        break;

    case I_PUNPCKHDQ_Pq_Qq:
        Handle_PUNPCKHDQ_Pq_Qq(insb, cseip);
        break;

    case I_PUNPCKHDQ_Vdq_Wdq:
        Handle_PUNPCKHDQ_Vdq_Wdq(insb, cseip);
        break;

    case I_PUNPCKHQDQ_Vdq_Wdq:
        Handle_PUNPCKHQDQ_Vdq_Wdq(insb, cseip);
        break;

    case I_PUNPCKHWD_Pq_Qq:
        Handle_PUNPCKHWD_Pq_Qq(insb, cseip);
        break;

    case I_PUNPCKHWD_Vdq_Wdq:
        Handle_PUNPCKHWD_Vdq_Wdq(insb, cseip);
        break;

    case I_PUNPCKLBW_Pq_Qd:
        Handle_PUNPCKLBW_Pq_Qd(insb, cseip);
        break;

    case I_PUNPCKLBW_Vdq_Wdq:
        Handle_PUNPCKLBW_Vdq_Wdq(insb, cseip);
        break;

    case I_PUNPCKLDQ_Pq_Qd:
        Handle_PUNPCKLDQ_Pq_Qd(insb, cseip);
        break;

    case I_PUNPCKLDQ_Vdq_Wdq:
        Handle_PUNPCKLDQ_Vdq_Wdq(insb, cseip);
        break;

    case I_PUNPCKLQDQ_Vdq_Wdq:
        Handle_PUNPCKLQDQ_Vdq_Wdq(insb, cseip);
        break;

    case I_PUNPCKLWD_Pq_Qd:
        Handle_PUNPCKLWD_Pq_Qd(insb, cseip);
        break;

    case I_PUNPCKLWD_Vdq_Wdq:
        Handle_PUNPCKLWD_Vdq_Wdq(insb, cseip);
        break;

    case I_PUSHA:
        Handle_PUSHA(insb, cseip);
        break;

    case I_PUSHAD:
        Handle_PUSHAD(insb, cseip);
        break;

    case I_PUSHF:
        Handle_PUSHF(insb, cseip);
        break;

    case I_PUSHFD:
        Handle_PUSHFD(insb, cseip);
        break;

    case I_PUSH_CS:
        Handle_PUSH_CS(insb, cseip);
        break;

    case I_PUSH_DS:
        Handle_PUSH_DS(insb, cseip);
        break;

    case I_PUSH_ES:
        Handle_PUSH_ES(insb, cseip);
        break;

    case I_PUSH_Ev:
        Handle_PUSH_Ev(insb, cseip);
        break;

    case I_PUSH_FS:
        Handle_PUSH_FS(insb, cseip);
        break;

    case I_PUSH_GS:
        Handle_PUSH_GS(insb, cseip);
        break;

    case I_PUSH_Ibss:
        Handle_PUSH_Ibss(insb, cseip);
        break;

    case I_PUSH_Ivs:
        Handle_PUSH_Ivs(insb, cseip);
        break;

    case I_PUSH_SS:
        Handle_PUSH_SS(insb, cseip);
        break;

    case I_PUSH_eAX:
        Handle_PUSH_eAX(insb, cseip);
        break;

    case I_PUSH_eBP:
        Handle_PUSH_eBP(insb, cseip);
        break;

    case I_PUSH_eBX:
        Handle_PUSH_eBX(insb, cseip);
        break;

    case I_PUSH_eCX:
        Handle_PUSH_eCX(insb, cseip);
        break;

    case I_PUSH_eDI:
        Handle_PUSH_eDI(insb, cseip);
        break;

    case I_PUSH_eDX:
        Handle_PUSH_eDX(insb, cseip);
        break;

    case I_PUSH_eSI:
        Handle_PUSH_eSI(insb, cseip);
        break;

    case I_PUSH_eSP:
        Handle_PUSH_eSP(insb, cseip);
        break;

    case I_PXOR_Pq_Qq:
        Handle_PXOR_Pq_Qq(insb, cseip);
        break;

    case I_PXOR_Vdq_Wdq:
        Handle_PXOR_Vdq_Wdq(insb, cseip);
        break;

    case I_RCL_Eb_CL:
        Handle_RCL_Eb_CL(insb, cseip);
        break;

    case I_RCL_Eb_I:
        Handle_RCL_Eb_I(insb, cseip);
        break;

    case I_RCL_Eb_Ib:
        Handle_RCL_Eb_Ib(insb, cseip);
        break;

    case I_RCL_Evqp_CL:
        Handle_RCL_Evqp_CL(insb, cseip);
        break;

    case I_RCL_Evqp_I:
        Handle_RCL_Evqp_I(insb, cseip);
        break;

    case I_RCL_Evqp_Ib:
        Handle_RCL_Evqp_Ib(insb, cseip);
        break;

    case I_RCPPS_Vps_Wps:
        Handle_RCPPS_Vps_Wps(insb, cseip);
        break;

    case I_RCPSS_Vss_Wss:
        Handle_RCPSS_Vss_Wss(insb, cseip);
        break;

    case I_RCR_Eb_CL:
        Handle_RCR_Eb_CL(insb, cseip);
        break;

    case I_RCR_Eb_I:
        Handle_RCR_Eb_I(insb, cseip);
        break;

    case I_RCR_Eb_Ib:
        Handle_RCR_Eb_Ib(insb, cseip);
        break;

    case I_RCR_Evqp_CL:
        Handle_RCR_Evqp_CL(insb, cseip);
        break;

    case I_RCR_Evqp_I:
        Handle_RCR_Evqp_I(insb, cseip);
        break;

    case I_RCR_Evqp_Ib:
        Handle_RCR_Evqp_Ib(insb, cseip);
        break;

    case I_RDMSR:
        Handle_RDMSR(insb, cseip);
        break;

    case I_RDPMC:
        Handle_RDPMC(insb, cseip);
        break;

    case I_RDTSC:
        Handle_RDTSC(insb, cseip);
        break;

    case I_RDTSCP_serial:
        Handle_RDTSCP_serial(insb, cseip);
        break;

    case I_RETF:
        Handle_RETF(insb, cseip);
        break;

    case I_RETF_Iw:
        Handle_RETF_Iw(insb, cseip);
        break;

    case I_RETN:
        Handle_RETN(insb, cseip);
        break;

    case I_RETN_Iw:
        Handle_RETN_Iw(insb, cseip);
        break;

    case I_ROL_Eb_CL:
        Handle_ROL_Eb_CL(insb, cseip);
        break;

    case I_ROL_Eb_I:
        Handle_ROL_Eb_I(insb, cseip);
        break;

    case I_ROL_Eb_Ib:
        Handle_ROL_Eb_Ib(insb, cseip);
        break;

    case I_ROL_Evqp_CL:
        Handle_ROL_Evqp_CL(insb, cseip);
        break;

    case I_ROL_Evqp_I:
        Handle_ROL_Evqp_I(insb, cseip);
        break;

    case I_ROL_Evqp_Ib:
        Handle_ROL_Evqp_Ib(insb, cseip);
        break;

    case I_ROR_Eb_CL:
        Handle_ROR_Eb_CL(insb, cseip);
        break;

    case I_ROR_Eb_I:
        Handle_ROR_Eb_I(insb, cseip);
        break;

    case I_ROR_Eb_Ib:
        Handle_ROR_Eb_Ib(insb, cseip);
        break;

    case I_ROR_Evqp_CL:
        Handle_ROR_Evqp_CL(insb, cseip);
        break;

    case I_ROR_Evqp_I:
        Handle_ROR_Evqp_I(insb, cseip);
        break;

    case I_ROR_Evqp_Ib:
        Handle_ROR_Evqp_Ib(insb, cseip);
        break;

    case I_ROUNDPD_Vps_Wpd_Ib:
        Handle_ROUNDPD_Vps_Wpd_Ib(insb, cseip);
        break;

    case I_ROUNDPS_Vps_Wps_Ib:
        Handle_ROUNDPS_Vps_Wps_Ib(insb, cseip);
        break;

    case I_ROUNDSD_Vsd_Wsd_Ib:
        Handle_ROUNDSD_Vsd_Wsd_Ib(insb, cseip);
        break;

    case I_ROUNDSS_Vss_Wss_Ib:
        Handle_ROUNDSS_Vss_Wss_Ib(insb, cseip);
        break;

    case I_RSM:
        Handle_RSM(insb, cseip);
        break;

    case I_RSQRTPS_Vps_Wps:
        Handle_RSQRTPS_Vps_Wps(insb, cseip);
        break;

    case I_RSQRTSS_Vss_Wss:
        Handle_RSQRTSS_Vss_Wss(insb, cseip);
        break;

    case I_SAHF:
        Handle_SAHF(insb, cseip);
        break;

    case I_SAR_Eb_CL:
        Handle_SAR_Eb_CL(insb, cseip);
        break;

    case I_SAR_Eb_I:
        Handle_SAR_Eb_I(insb, cseip);
        break;

    case I_SAR_Eb_Ib:
        Handle_SAR_Eb_Ib(insb, cseip);
        break;

    case I_SAR_Evqp_CL:
        Handle_SAR_Evqp_CL(insb, cseip);
        break;

    case I_SAR_Evqp_I:
        Handle_SAR_Evqp_I(insb, cseip);
        break;

    case I_SAR_Evqp_Ib:
        Handle_SAR_Evqp_Ib(insb, cseip);
        break;

    case I_SBB_Eb_Gb:
        Handle_SBB_Eb_Gb(insb, cseip);
        break;

    case I_SBB_Eb_Ib:
        Handle_SBB_Eb_Ib(insb, cseip);
        break;

    case I_SBB_Evqp_Gvqp:
        Handle_SBB_Evqp_Gvqp(insb, cseip);
        break;

    case I_SBB_Evqp_Ibs:
        Handle_SBB_Evqp_Ibs(insb, cseip);
        break;

    case I_SBB_Evqp_Ivds:
        Handle_SBB_Evqp_Ivds(insb, cseip);
        break;

    case I_SBB_Gb_Eb:
        Handle_SBB_Gb_Eb(insb, cseip);
        break;

    case I_SBB_Gvqp_Evqp:
        Handle_SBB_Gvqp_Evqp(insb, cseip);
        break;

    case I_SBB_acc_AL_Ib:
        Handle_SBB_acc_AL_Ib(insb, cseip);
        break;

    case I_SBB_acc_eAX_Ivds:
        Handle_SBB_acc_eAX_Ivds(insb, cseip);
        break;

    case I_SCAS_Yb:
        Handle_SCAS_Yb(insb, cseip);
        break;

    case I_SCAS_Yv:
        Handle_SCAS_Yv(insb, cseip);
        break;

    case I_SCAS_Yw:
        Handle_SCAS_Yw(insb, cseip);
        break;

    case I_SETBE_Eb:
        Handle_SETBE_Eb(insb, cseip);
        break;

    case I_SETB_Eb:
        Handle_SETB_Eb(insb, cseip);
        break;

    case I_SETLE_Eb:
        Handle_SETLE_Eb(insb, cseip);
        break;

    case I_SETL_Eb:
        Handle_SETL_Eb(insb, cseip);
        break;

    case I_SETNBE_Eb:
        Handle_SETNBE_Eb(insb, cseip);
        break;

    case I_SETNB_Eb:
        Handle_SETNB_Eb(insb, cseip);
        break;

    case I_SETNLE_Eb:
        Handle_SETNLE_Eb(insb, cseip);
        break;

    case I_SETNL_Eb:
        Handle_SETNL_Eb(insb, cseip);
        break;

    case I_SETNO_Eb:
        Handle_SETNO_Eb(insb, cseip);
        break;

    case I_SETNP_Eb:
        Handle_SETNP_Eb(insb, cseip);
        break;

    case I_SETNS_Eb:
        Handle_SETNS_Eb(insb, cseip);
        break;

    case I_SETNZ_Eb:
        Handle_SETNZ_Eb(insb, cseip);
        break;

    case I_SETO_Eb:
        Handle_SETO_Eb(insb, cseip);
        break;

    case I_SETP_Eb:
        Handle_SETP_Eb(insb, cseip);
        break;

    case I_SETS_Eb:
        Handle_SETS_Eb(insb, cseip);
        break;

    case I_SETZ_Eb:
        Handle_SETZ_Eb(insb, cseip);
        break;

    case I_SFENCE:
        Handle_SFENCE(insb, cseip);
        break;

    case I_SGDT_Ms:
        Handle_SGDT_Ms(insb, cseip);
        break;

    case I_SHLD_Evqp_Gvqp_CL:
        Handle_SHLD_Evqp_Gvqp_CL(insb, cseip);
        break;

    case I_SHLD_Evqp_Gvqp_Ib:
        Handle_SHLD_Evqp_Gvqp_Ib(insb, cseip);
        break;

    case I_SHL_Eb_CL:
        Handle_SHL_Eb_CL(insb, cseip);
        break;

    case I_SHL_Eb_I:
        Handle_SHL_Eb_I(insb, cseip);
        break;

    case I_SHL_Eb_Ib:
        Handle_SHL_Eb_Ib(insb, cseip);
        break;

    case I_SHL_Evqp_CL:
        Handle_SHL_Evqp_CL(insb, cseip);
        break;

    case I_SHL_Evqp_I:
        Handle_SHL_Evqp_I(insb, cseip);
        break;

    case I_SHL_Evqp_Ib:
        Handle_SHL_Evqp_Ib(insb, cseip);
        break;

    case I_SHRD_Evqp_Gvqp_CL:
        Handle_SHRD_Evqp_Gvqp_CL(insb, cseip);
        break;

    case I_SHRD_Evqp_Gvqp_Ib:
        Handle_SHRD_Evqp_Gvqp_Ib(insb, cseip);
        break;

    case I_SHR_Eb_CL:
        Handle_SHR_Eb_CL(insb, cseip);
        break;

    case I_SHR_Eb_I:
        Handle_SHR_Eb_I(insb, cseip);
        break;

    case I_SHR_Eb_Ib:
        Handle_SHR_Eb_Ib(insb, cseip);
        break;

    case I_SHR_Evqp_CL:
        Handle_SHR_Evqp_CL(insb, cseip);
        break;

    case I_SHR_Evqp_I:
        Handle_SHR_Evqp_I(insb, cseip);
        break;

    case I_SHR_Evqp_Ib:
        Handle_SHR_Evqp_Ib(insb, cseip);
        break;

    case I_SHUFPD_Vpd_Wpd_Ib:
        Handle_SHUFPD_Vpd_Wpd_Ib(insb, cseip);
        break;

    case I_SHUFPS_Vps_Wps_Ib:
        Handle_SHUFPS_Vps_Wps_Ib(insb, cseip);
        break;

    case I_SIDT_Ms:
        Handle_SIDT_Ms(insb, cseip);
        break;

    case I_SLDT_Mw:
        Handle_SLDT_Mw(insb, cseip);
        break;

    case I_SMSW_Mw:
        Handle_SMSW_Mw(insb, cseip);
        break;

    case I_SQRTPD_Vpd_Wpd:
        Handle_SQRTPD_Vpd_Wpd(insb, cseip);
        break;

    case I_SQRTPS_Vps_Wps:
        Handle_SQRTPS_Vps_Wps(insb, cseip);
        break;

    case I_SQRTSD_Vsd_Wsd:
        Handle_SQRTSD_Vsd_Wsd(insb, cseip);
        break;

    case I_SQRTSS_Vss_Wss:
        Handle_SQRTSS_Vss_Wss(insb, cseip);
        break;

    case I_STC:
        Handle_STC(insb, cseip);
        break;

    case I_STD:
        Handle_STD(insb, cseip);
        break;

    case I_STI_delaysint_cond:
        Handle_STI_delaysint_cond(insb, cseip);
        break;

    case I_STMXCSR_Md:
        Handle_STMXCSR_Md(insb, cseip);
        break;

    case I_STOS_Yb:
        Handle_STOS_Yb(insb, cseip);
        break;

    case I_STOS_Yv:
        Handle_STOS_Yv(insb, cseip);
        break;

    case I_STOS_Yw:
        Handle_STOS_Yw(insb, cseip);
        break;

    case I_STR_Mw:
        Handle_STR_Mw(insb, cseip);
        break;

    case I_SUBPD_Vpd_Wpd:
        Handle_SUBPD_Vpd_Wpd(insb, cseip);
        break;

    case I_SUBPS_Vps_Wps:
        Handle_SUBPS_Vps_Wps(insb, cseip);
        break;

    case I_SUBSD_Vsd_Wsd:
        Handle_SUBSD_Vsd_Wsd(insb, cseip);
        break;

    case I_SUBSS_Vss_Wss:
        Handle_SUBSS_Vss_Wss(insb, cseip);
        break;

    case I_SUB_Eb_Gb:
        Handle_SUB_Eb_Gb(insb, cseip);
        break;

    case I_SUB_Eb_Ib:
        Handle_SUB_Eb_Ib(insb, cseip);
        break;

    case I_SUB_Evqp_Gvqp:
        Handle_SUB_Evqp_Gvqp(insb, cseip);
        break;

    case I_SUB_Evqp_Ibs:
        Handle_SUB_Evqp_Ibs(insb, cseip);
        break;

    case I_SUB_Evqp_Ivds:
        Handle_SUB_Evqp_Ivds(insb, cseip);
        break;

    case I_SUB_Gb_Eb:
        Handle_SUB_Gb_Eb(insb, cseip);
        break;

    case I_SUB_Gvqp_Evqp:
        Handle_SUB_Gvqp_Evqp(insb, cseip);
        break;

    case I_SUB_acc_AL_Ib:
        Handle_SUB_acc_AL_Ib(insb, cseip);
        break;

    case I_SUB_acc_eAX_Ivds:
        Handle_SUB_acc_eAX_Ivds(insb, cseip);
        break;

    case I_SYSENTER:
        Handle_SYSENTER(insb, cseip);
        break;

    case I_SYSEXIT:
        Handle_SYSEXIT(insb, cseip);
        break;

    case I_TEST_Eb_Gb:
        Handle_TEST_Eb_Gb(insb, cseip);
        break;

    case I_TEST_Eb_Ib:
        Handle_TEST_Eb_Ib(insb, cseip);
        break;

    case I_TEST_Evqp_Gvqp:
        Handle_TEST_Evqp_Gvqp(insb, cseip);
        break;

    case I_TEST_Evqp_Ivqp:
        Handle_TEST_Evqp_Ivqp(insb, cseip);
        break;

    case I_TEST_acc_AL_Ib:
        Handle_TEST_acc_AL_Ib(insb, cseip);
        break;

    case I_TEST_acc_eAX_Ivds:
        Handle_TEST_acc_eAX_Ivds(insb, cseip);
        break;

    case I_UCOMISD_Vsd_Wsd:
        Handle_UCOMISD_Vsd_Wsd(insb, cseip);
        break;

    case I_UCOMISS_Vss_Wss:
        Handle_UCOMISS_Vss_Wss(insb, cseip);
        break;

    case I_UNPCKHPD_Vpd_Wpd:
        Handle_UNPCKHPD_Vpd_Wpd(insb, cseip);
        break;

    case I_UNPCKHPS_Vps_Wq:
        Handle_UNPCKHPS_Vps_Wq(insb, cseip);
        break;

    case I_UNPCKLPD_Vpd_Wpd:
        Handle_UNPCKLPD_Vpd_Wpd(insb, cseip);
        break;

    case I_UNPCKLPS_Vps_Wq:
        Handle_UNPCKLPS_Vps_Wq(insb, cseip);
        break;

    case I_VERR_Ew:
        Handle_VERR_Ew(insb, cseip);
        break;

    case I_VERW_Ew:
        Handle_VERW_Ew(insb, cseip);
        break;

    case I_VMCALL:
        Handle_VMCALL(insb, cseip);
        break;

    case I_VMCLEAR_Mq:
        Handle_VMCLEAR_Mq(insb, cseip);
        break;

    case I_VMLAUNCH:
        Handle_VMLAUNCH(insb, cseip);
        break;

    case I_VMPTRLD_Mq:
        Handle_VMPTRLD_Mq(insb, cseip);
        break;

    case I_VMPTRST_Mq:
        Handle_VMPTRST_Mq(insb, cseip);
        break;

    case I_VMREAD_Ed_Gd:
        Handle_VMREAD_Ed_Gd(insb, cseip);
        break;

    case I_VMRESUME:
        Handle_VMRESUME(insb, cseip);
        break;

    case I_VMWRITE_Gd_Ed:
        Handle_VMWRITE_Gd_Ed(insb, cseip);
        break;

    case I_VMXOFF:
        Handle_VMXOFF(insb, cseip);
        break;

    case I_VMXON_Mq:
        Handle_VMXON_Mq(insb, cseip);
        break;

    case I_WBINVD_serial:
        Handle_WBINVD_serial(insb, cseip);
        break;

    case I_WRMSR_serial:
        Handle_WRMSR_serial(insb, cseip);
        break;

    case I_XADD_Eb_Gb:
        Handle_XADD_Eb_Gb(insb, cseip);
        break;

    case I_XADD_Evqp_Gvqp:
        Handle_XADD_Evqp_Gvqp(insb, cseip);
        break;

    case I_XCHG_Gb_Eb:
        Handle_XCHG_Gb_Eb(insb, cseip);
        break;

    case I_XCHG_Gvqp_Evqp:
        Handle_XCHG_Gvqp_Evqp(insb, cseip);
        break;

    case I_XCHG_acc_eAX_eAX:
        Handle_XCHG_acc_eAX_eAX(insb, cseip);
        break;

    case I_XCHG_acc_eBP_eAX:
        Handle_XCHG_acc_eBP_eAX(insb, cseip);
        break;

    case I_XCHG_acc_eBX_eAX:
        Handle_XCHG_acc_eBX_eAX(insb, cseip);
        break;

    case I_XCHG_acc_eCX_eAX:
        Handle_XCHG_acc_eCX_eAX(insb, cseip);
        break;

    case I_XCHG_acc_eDI_eAX:
        Handle_XCHG_acc_eDI_eAX(insb, cseip);
        break;

    case I_XCHG_acc_eDX_eAX:
        Handle_XCHG_acc_eDX_eAX(insb, cseip);
        break;

    case I_XCHG_acc_eSI_eAX:
        Handle_XCHG_acc_eSI_eAX(insb, cseip);
        break;

    case I_XCHG_acc_eSP_eAX:
        Handle_XCHG_acc_eSP_eAX(insb, cseip);
        break;

    case I_XGETBV:
        Handle_XGETBV(insb, cseip);
        break;

    case I_XLAT_BBb:
        Handle_XLAT_BBb(insb, cseip);
        break;

    case I_XORPD_Vpd_Wpd:
        Handle_XORPD_Vpd_Wpd(insb, cseip);
        break;

    case I_XORPS_Vps_Wps:
        Handle_XORPS_Vps_Wps(insb, cseip);
        break;

    case I_XOR_Eb_Gb:
        Handle_XOR_Eb_Gb(insb, cseip);
        break;

    case I_XOR_Eb_Ib:
        Handle_XOR_Eb_Ib(insb, cseip);
        break;

    case I_XOR_Evqp_Gvqp:
        Handle_XOR_Evqp_Gvqp(insb, cseip);
        break;

    case I_XOR_Evqp_Ibs:
        Handle_XOR_Evqp_Ibs(insb, cseip);
        break;

    case I_XOR_Evqp_Ivds:
        Handle_XOR_Evqp_Ivds(insb, cseip);
        break;

    case I_XOR_Gb_Eb:
        Handle_XOR_Gb_Eb(insb, cseip);
        break;

    case I_XOR_Gvqp_Evqp:
        Handle_XOR_Gvqp_Evqp(insb, cseip);
        break;

    case I_XOR_acc_AL_Ib:
        Handle_XOR_acc_AL_Ib(insb, cseip);
        break;

    case I_XOR_acc_eAX_Ivds:
        Handle_XOR_acc_eAX_Ivds(insb, cseip);
        break;

    case I_XRSTOR_M:
        Handle_XRSTOR_M(insb, cseip);
        break;

    case I_XSAVE_M:
        Handle_XSAVE_M(insb, cseip);
        break;

    case I_XSETBV:
        Handle_XSETBV(insb, cseip);
        break;

    default:
        break;
    }
}

    #endif //PROJECT_CORE_LLVM_PARSE_H
    