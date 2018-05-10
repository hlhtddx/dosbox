#include "core_llvm_runner.h"
namespace core_llvm {


/* Segment override prefix */
inline bool CpuRunnerLLVM::handler_pr26() {
    return true;
};

/* Segment override prefix */
inline bool CpuRunnerLLVM::handler_pr2E() {
    return true;
};

/* Segment override prefix */
inline bool CpuRunnerLLVM::handler_pr36() {
    return true;
};

/* Segment override prefix */
inline bool CpuRunnerLLVM::handler_pr3E() {
    return true;
};

/* Segment override prefix */
inline bool CpuRunnerLLVM::handler_pr64() {
    return true;
};

/* Segment override prefix */
inline bool CpuRunnerLLVM::handler_pr65() {
    return true;
};

/* Operand-size override prefix */
inline bool CpuRunnerLLVM::handler_pr66() {
    return true;
};

/* Address-size override prefix */
inline bool CpuRunnerLLVM::handler_pr67() {
    return true;
};

/* Lock prefix */
inline bool CpuRunnerLLVM::handler_prF0() {
    return true;
};

/* REP/REPZ/REPNZ prefix */
inline bool CpuRunnerLLVM::handler_prF2() {
    return true;
};

/* REP/REPZ/REPNZ prefix */
inline bool CpuRunnerLLVM::handler_prF3() {
    return true;
};

/*
 ADD
*/
inline bool CpuRunnerLLVM::handler_in_00_ADD_Eb_Gb() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetRmReg<data_type>(rmmod);
    lf_var1b = destination->Read();
    lf_var2b = source->Read();
    lf_resb = lf_var1b + lf_var2b;
    destination->Write(lf_resb);
    lflags.type=t_ADDb;
    return true;
}

/*
 ADD
*/
inline bool CpuRunnerLLVM::handler_in_01_ADD_Evqp_Gvqp() {
    if (Is32BitOperandMode()) {
        return handler_in_01_ADD_Evqp_Gvqp_32();
    } else {
        return handler_in_01_ADD_Evqp_Gvqp_16();
    }
}

/*
 ADD
*/
inline bool CpuRunnerLLVM::handler_in_01_ADD_Evqp_Gvqp_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetRmReg<data_type>(rmmod);
    lf_var1w = destination->Read();
    lf_var2w = source->Read();
    lf_resw = lf_var1w + lf_var2w;
    destination->Write(lf_resw);
    lflags.type=t_ADDw;
    return true;
}

/*
 ADD
*/
inline bool CpuRunnerLLVM::handler_in_01_ADD_Evqp_Gvqp_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetRmReg<data_type>(rmmod);
    lf_var1d = destination->Read();
    lf_var2d = source->Read();
    lf_resd = lf_var1d + lf_var2d;
    destination->Write(lf_resd);
    lflags.type=t_ADDd;
    return true;
}

/*
 ADD
*/
inline bool CpuRunnerLLVM::handler_in_02_ADD_Gb_Eb() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto destination = GetRmReg<data_type>(rmmod);
    auto source = GetRmMod<data_type>(rmmod);
    lf_var1b = destination->Read();
    lf_var2b = source->Read();
    lf_resb = lf_var1b + lf_var2b;
    destination->Write(lf_resb);
    lflags.type=t_ADDb;
    return true;
}

/*
 ADD
*/
inline bool CpuRunnerLLVM::handler_in_03_ADD_Gvqp_Evqp() {
    if (Is32BitOperandMode()) {
        return handler_in_03_ADD_Gvqp_Evqp_32();
    } else {
        return handler_in_03_ADD_Gvqp_Evqp_16();
    }
}

/*
 ADD
*/
inline bool CpuRunnerLLVM::handler_in_03_ADD_Gvqp_Evqp_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmReg<data_type>(rmmod);
    auto source = GetRmMod<data_type>(rmmod);
    lf_var1w = destination->Read();
    lf_var2w = source->Read();
    lf_resw = lf_var1w + lf_var2w;
    destination->Write(lf_resw);
    lflags.type=t_ADDw;
    return true;
}

/*
 ADD
*/
inline bool CpuRunnerLLVM::handler_in_03_ADD_Gvqp_Evqp_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmReg<data_type>(rmmod);
    auto source = GetRmMod<data_type>(rmmod);
    lf_var1d = destination->Read();
    lf_var2d = source->Read();
    lf_resd = lf_var1d + lf_var2d;
    destination->Write(lf_resd);
    lflags.type=t_ADDd;
    return true;
}

/*
 ADD
*/
inline bool CpuRunnerLLVM::handler_in_04_ADD_ALb_Ib() {
    typedef Bit8u data_type;
    auto& destination = reg_al;
    auto source = GetImmediate<data_type>();
    lf_var1b = destination;
    lf_var2b = source;
    lf_resb = lf_var1b + lf_var2b;
    destination = lf_resb;
    lflags.type=t_ADDb;
    return true;
}

/*
 ADD
*/
inline bool CpuRunnerLLVM::handler_in_05_ADD_rAXvqp_Ivds() {
    if (Is32BitOperandMode()) {
        return handler_in_05_ADD_rAXvqp_Ivds_32();
    } else {
        return handler_in_05_ADD_rAXvqp_Ivds_16();
    }
}

/*
 ADD
*/
inline bool CpuRunnerLLVM::handler_in_05_ADD_rAXvqp_Ivds_16() {
    typedef Bit16u data_type;
    auto destination = reg_ax;
    auto source = GetImmediate<data_type>();
    lf_var1w = destination;
    lf_var2w = source;
    lf_resw = lf_var1w + lf_var2w;
    destination = lf_resw;
    lflags.type=t_ADDw;
    return true;
}

/*
 ADD
*/
inline bool CpuRunnerLLVM::handler_in_05_ADD_rAXvqp_Ivds_32() {
    typedef Bit32u data_type;
    auto& destination = reg_eax;
    auto source = GetImmediate<data_type>();
    lf_var1d = destination;
    lf_var2d = source;
    lf_resd = lf_var1d + lf_var2d;
    destination = lf_resd;
    lflags.type=t_ADDd;
    return true;
}

/*
 PUSH
*/
inline bool CpuRunnerLLVM::handler_in_06_PUSH_ESw() {
    typedef Bit16u data_type;
    auto source = Segs.val[es];
    CPU_Push16(source);
    return true;
}

/*
 POP
*/
inline bool CpuRunnerLLVM::handler_in_07_POP_ESw() {
    typedef Bit16u data_type;
    if (CPU_PopSeg(es, false))
        RunException();
    return true;
}

/*
 OR
*/
inline bool CpuRunnerLLVM::handler_in_08_OR_Eb_Gb() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetRmReg<data_type>(rmmod);
    lf_var1b = destination->Read();
    lf_var2b = source->Read();
	lf_resb=lf_var1b | lf_var2b;
    destination->Write(lf_resb);
	lflags.type=t_ORb;
    return true;
}

/*
 OR
*/
inline bool CpuRunnerLLVM::handler_in_09_OR_Evqp_Gvqp() {
    if (Is32BitOperandMode()) {
        return handler_in_09_OR_Evqp_Gvqp_32();
    } else {
        return handler_in_09_OR_Evqp_Gvqp_16();
    }
}

/*
 OR
*/
inline bool CpuRunnerLLVM::handler_in_09_OR_Evqp_Gvqp_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetRmReg<data_type>(rmmod);
    lf_var1w = destination->Read();
    lf_var2w = source->Read();
    lf_resw=lf_var1w | lf_var2w;
    destination->Write(lf_resw);
    lflags.type=t_ORw;
    return true;
}

/*
 OR
*/
inline bool CpuRunnerLLVM::handler_in_09_OR_Evqp_Gvqp_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetRmReg<data_type>(rmmod);
    lf_var1d = destination->Read();
    lf_var2d = source->Read();
    lf_resd=lf_var1d | lf_var2d;
    destination->Write(lf_resd);
    lflags.type=t_ORd;
    return true;
}

/*
 OR
*/
inline bool CpuRunnerLLVM::handler_in_0A_OR_Gb_Eb() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto destination = GetRmReg<data_type>(rmmod);
    auto source = GetRmMod<data_type>(rmmod);
    lf_var1b = destination->Read();
    lf_var2b = source->Read();
    lf_resb=lf_var1b | lf_var2b;
    destination->Write(lf_resb);
    lflags.type=t_ORb;
    return true;
}

/*
 OR
*/
inline bool CpuRunnerLLVM::handler_in_0B_OR_Gvqp_Evqp() {
    if (Is32BitOperandMode()) {
        return handler_in_0B_OR_Gvqp_Evqp_32();
    } else {
        return handler_in_0B_OR_Gvqp_Evqp_16();
    }
}

/*
 OR
*/
inline bool CpuRunnerLLVM::handler_in_0B_OR_Gvqp_Evqp_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmReg<data_type>(rmmod);
    auto source = GetRmMod<data_type>(rmmod);
    lf_var1w = destination->Read();
    lf_var2w = source->Read();
    lf_resw=lf_var1w | lf_var2w;
    destination->Write(lf_resw);
    lflags.type=t_ORw;
    return true;
}

/*
 OR
*/
inline bool CpuRunnerLLVM::handler_in_0B_OR_Gvqp_Evqp_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmReg<data_type>(rmmod);
    auto source = GetRmMod<data_type>(rmmod);
    lf_var1d = destination->Read();
    lf_var2d = source->Read();
    lf_resd=lf_var1d | lf_var2d;
    destination->Write(lf_resd);
    lflags.type=t_ORd;
    return true;
}

/*
 OR
*/
inline bool CpuRunnerLLVM::handler_in_0C_OR_ALb_Ib() {
    typedef Bit8u data_type;
    auto& destination = reg_al;
    auto source = GetImmediate<data_type>();
    lf_var1b = destination;
    lf_var2b = source;
    lf_resb=lf_var1b | lf_var2b;
    destination = lf_resb;
    lflags.type=t_ORb;
    return true;
}

/*
 OR
*/
inline bool CpuRunnerLLVM::handler_in_0D_OR_rAXvqp_Ivds() {
    if (Is32BitOperandMode()) {
        return handler_in_0D_OR_rAXvqp_Ivds_32();
    } else {
        return handler_in_0D_OR_rAXvqp_Ivds_16();
    }
}

/*
 OR
*/
inline bool CpuRunnerLLVM::handler_in_0D_OR_rAXvqp_Ivds_16() {
    typedef Bit16u data_type;
    auto& destination = reg_ax;
    auto source = GetImmediate<data_type>();
    lf_var1w = destination;
    lf_var2w = source;
    lf_resw=lf_var1w | lf_var2w;
    destination = lf_resw;
    lflags.type=t_ORw;
    return true;
}

/*
 OR
*/
inline bool CpuRunnerLLVM::handler_in_0D_OR_rAXvqp_Ivds_32() {
    typedef Bit32u data_type;
    auto& destination = reg_eax;
    auto source = GetImmediate<data_type>();
    lf_var1d = destination;
    lf_var2d = source;
    lf_resd=lf_var1d | lf_var2d;
    destination = lf_resd;
    lflags.type=t_ORd;
    return true;
}

/*
 PUSH
*/
inline bool CpuRunnerLLVM::handler_in_0E_PUSH_CSw() {
    typedef Bit16u data_type;
    auto source = Segs.val[cs];
    CPU_Push16(source);
    return true;
}

/*
 SLDT
*/
inline bool CpuRunnerLLVM::handler_in_0F_00_00_SLDT_Mw() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmMem<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 STR
*/
inline bool CpuRunnerLLVM::handler_in_0F_00_01_STR_Mw() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmMem<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 LLDT
*/
inline bool CpuRunnerLLVM::handler_in_0F_00_02_LLDT_Ew() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto source = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 LTR
*/
inline bool CpuRunnerLLVM::handler_in_0F_00_03_LTR_Ew() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto source = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 VERR
*/
inline bool CpuRunnerLLVM::handler_in_0F_00_04_VERR_Ew() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto source = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 VERW
*/
inline bool CpuRunnerLLVM::handler_in_0F_00_05_VERW_Ew() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto source = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 SGDT
*/
inline bool CpuRunnerLLVM::handler_in_0F_01_00_SGDT_Ms() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit48u data_type;
    auto destination = GetRmMem<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 SIDT
*/
inline bool CpuRunnerLLVM::handler_in_0F_01_01_SIDT_Ms() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit48u data_type;
    auto destination = GetRmMem<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 LGDT
*/
inline bool CpuRunnerLLVM::handler_in_0F_01_02_LGDT_Ms() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit48u data_type;
    auto source = GetRmMem<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 LIDT
*/
inline bool CpuRunnerLLVM::handler_in_0F_01_03_LIDT_Ms() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit48u data_type;
    auto source = GetRmMem<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 SMSW
*/
inline bool CpuRunnerLLVM::handler_in_0F_01_04_SMSW_Mw() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmMem<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 LMSW
*/
inline bool CpuRunnerLLVM::handler_in_0F_01_06_LMSW_Ew() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto source = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 INVLPG
*/
inline bool CpuRunnerLLVM::handler_in_0F_01_07_INVLPG() {
    return true;
}

/*
 LAR
*/
inline bool CpuRunnerLLVM::handler_in_0F_02_LAR_Gvqp_Mw() {
    if (Is32BitOperandMode()) {
        return handler_in_0F_02_LAR_Gvqp_Mw_32();
    } else {
        return handler_in_0F_02_LAR_Gvqp_Mw_16();
    }
}

/*
 LAR
*/
inline bool CpuRunnerLLVM::handler_in_0F_02_LAR_Gvqp_Mw_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmReg<data_type>(rmmod);
    auto source = GetRmMem<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 LAR
*/
inline bool CpuRunnerLLVM::handler_in_0F_02_LAR_Gvqp_Mw_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmReg<data_type>(rmmod);
    auto source = GetRmMem<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 LSL
*/
inline bool CpuRunnerLLVM::handler_in_0F_03_LSL_Gvqp_Mw() {
    if (Is32BitOperandMode()) {
        return handler_in_0F_03_LSL_Gvqp_Mw_32();
    } else {
        return handler_in_0F_03_LSL_Gvqp_Mw_16();
    }
}

/*
 LSL
*/
inline bool CpuRunnerLLVM::handler_in_0F_03_LSL_Gvqp_Mw_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmReg<data_type>(rmmod);
    auto source = GetRmMem<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 LSL
*/
inline bool CpuRunnerLLVM::handler_in_0F_03_LSL_Gvqp_Mw_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmReg<data_type>(rmmod);
    auto source = GetRmMem<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 CLTS
*/
inline bool CpuRunnerLLVM::handler_in_0F_06_CLTS() {
    return true;
}

/*
 LOADALL
*/
inline bool CpuRunnerLLVM::handler_in_0F_07_LOADALL() {
    return true;
}

/*
 INVD
*/
inline bool CpuRunnerLLVM::handler_in_0F_08_INVD() {
    return true;
}

/*
 WBINVD
*/
inline bool CpuRunnerLLVM::handler_in_0F_09_WBINVD() {
    return true;
}

/*
 MOV
*/
inline bool CpuRunnerLLVM::handler_in_0F_20_MOV_Hd_Cd() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmRm<data_type>(rmmod);
    auto source = rmmod & 0x07u;
    //TODO do the actual operation
    return true;
}

/*
 MOV
*/
inline bool CpuRunnerLLVM::handler_in_0F_21_MOV_Hd_Dd() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmRm<data_type>(rmmod);
    auto source = rmmod & 0x07u;
    //TODO do the actual operation
    return true;
}

/*
 MOV
*/
inline bool CpuRunnerLLVM::handler_in_0F_22_MOV_Cd_Hd() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = rmmod & 0x07u;
    auto source = GetRmRm<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 MOV
*/
inline bool CpuRunnerLLVM::handler_in_0F_23_MOV_Dq_Hq() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = rmmod & 0x07u;
    auto source = GetRmRm<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 MOV
*/
inline bool CpuRunnerLLVM::handler_in_0F_24_MOV_Hd_Td() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmRm<data_type>(rmmod);
    auto source = rmmod & 0x07u;
    //TODO do the actual operation
    return true;
}

/*
 MOV
*/
inline bool CpuRunnerLLVM::handler_in_0F_26_MOV_Td_Hd() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = rmmod & 0x07u;
    auto source = GetRmRm<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 JO
*/
inline bool CpuRunnerLLVM::handler_in_0F_80_JO_Jvds() {
    if (Is32BitOperandMode()) {
        return handler_in_0F_80_JO_Jvds_32();
    } else {
        return handler_in_0F_80_JO_Jvds_16();
    }
}

/*
 JO
*/
inline bool CpuRunnerLLVM::handler_in_0F_80_JO_Jvds_16() {
    typedef Bit16u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 JO
*/
inline bool CpuRunnerLLVM::handler_in_0F_80_JO_Jvds_32() {
    typedef Bit32u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 JNO
*/
inline bool CpuRunnerLLVM::handler_in_0F_81_JNO_Jvds() {
    if (Is32BitOperandMode()) {
        return handler_in_0F_81_JNO_Jvds_32();
    } else {
        return handler_in_0F_81_JNO_Jvds_16();
    }
}

/*
 JNO
*/
inline bool CpuRunnerLLVM::handler_in_0F_81_JNO_Jvds_16() {
    typedef Bit16u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 JNO
*/
inline bool CpuRunnerLLVM::handler_in_0F_81_JNO_Jvds_32() {
    typedef Bit32u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 JB
*/
inline bool CpuRunnerLLVM::handler_in_0F_82_JB_Jvds() {
    if (Is32BitOperandMode()) {
        return handler_in_0F_82_JB_Jvds_32();
    } else {
        return handler_in_0F_82_JB_Jvds_16();
    }
}

/*
 JB
*/
inline bool CpuRunnerLLVM::handler_in_0F_82_JB_Jvds_16() {
    typedef Bit16u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 JB
*/
inline bool CpuRunnerLLVM::handler_in_0F_82_JB_Jvds_32() {
    typedef Bit32u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 JNB
*/
inline bool CpuRunnerLLVM::handler_in_0F_83_JNB_Jvds() {
    if (Is32BitOperandMode()) {
        return handler_in_0F_83_JNB_Jvds_32();
    } else {
        return handler_in_0F_83_JNB_Jvds_16();
    }
}

/*
 JNB
*/
inline bool CpuRunnerLLVM::handler_in_0F_83_JNB_Jvds_16() {
    typedef Bit16u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 JNB
*/
inline bool CpuRunnerLLVM::handler_in_0F_83_JNB_Jvds_32() {
    typedef Bit32u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 JZ
*/
inline bool CpuRunnerLLVM::handler_in_0F_84_JZ_Jvds() {
    if (Is32BitOperandMode()) {
        return handler_in_0F_84_JZ_Jvds_32();
    } else {
        return handler_in_0F_84_JZ_Jvds_16();
    }
}

/*
 JZ
*/
inline bool CpuRunnerLLVM::handler_in_0F_84_JZ_Jvds_16() {
    typedef Bit16u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 JZ
*/
inline bool CpuRunnerLLVM::handler_in_0F_84_JZ_Jvds_32() {
    typedef Bit32u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 JNZ
*/
inline bool CpuRunnerLLVM::handler_in_0F_85_JNZ_Jvds() {
    if (Is32BitOperandMode()) {
        return handler_in_0F_85_JNZ_Jvds_32();
    } else {
        return handler_in_0F_85_JNZ_Jvds_16();
    }
}

/*
 JNZ
*/
inline bool CpuRunnerLLVM::handler_in_0F_85_JNZ_Jvds_16() {
    typedef Bit16u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 JNZ
*/
inline bool CpuRunnerLLVM::handler_in_0F_85_JNZ_Jvds_32() {
    typedef Bit32u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 JBE
*/
inline bool CpuRunnerLLVM::handler_in_0F_86_JBE_Jvds() {
    if (Is32BitOperandMode()) {
        return handler_in_0F_86_JBE_Jvds_32();
    } else {
        return handler_in_0F_86_JBE_Jvds_16();
    }
}

/*
 JBE
*/
inline bool CpuRunnerLLVM::handler_in_0F_86_JBE_Jvds_16() {
    typedef Bit16u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 JBE
*/
inline bool CpuRunnerLLVM::handler_in_0F_86_JBE_Jvds_32() {
    typedef Bit32u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 JNBE
*/
inline bool CpuRunnerLLVM::handler_in_0F_87_JNBE_Jvds() {
    if (Is32BitOperandMode()) {
        return handler_in_0F_87_JNBE_Jvds_32();
    } else {
        return handler_in_0F_87_JNBE_Jvds_16();
    }
}

/*
 JNBE
*/
inline bool CpuRunnerLLVM::handler_in_0F_87_JNBE_Jvds_16() {
    typedef Bit16u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 JNBE
*/
inline bool CpuRunnerLLVM::handler_in_0F_87_JNBE_Jvds_32() {
    typedef Bit32u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 JS
*/
inline bool CpuRunnerLLVM::handler_in_0F_88_JS_Jvds() {
    if (Is32BitOperandMode()) {
        return handler_in_0F_88_JS_Jvds_32();
    } else {
        return handler_in_0F_88_JS_Jvds_16();
    }
}

/*
 JS
*/
inline bool CpuRunnerLLVM::handler_in_0F_88_JS_Jvds_16() {
    typedef Bit16u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 JS
*/
inline bool CpuRunnerLLVM::handler_in_0F_88_JS_Jvds_32() {
    typedef Bit32u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 JNS
*/
inline bool CpuRunnerLLVM::handler_in_0F_89_JNS_Jvds() {
    if (Is32BitOperandMode()) {
        return handler_in_0F_89_JNS_Jvds_32();
    } else {
        return handler_in_0F_89_JNS_Jvds_16();
    }
}

/*
 JNS
*/
inline bool CpuRunnerLLVM::handler_in_0F_89_JNS_Jvds_16() {
    typedef Bit16u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 JNS
*/
inline bool CpuRunnerLLVM::handler_in_0F_89_JNS_Jvds_32() {
    typedef Bit32u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 JP
*/
inline bool CpuRunnerLLVM::handler_in_0F_8A_JP_Jvds() {
    if (Is32BitOperandMode()) {
        return handler_in_0F_8A_JP_Jvds_32();
    } else {
        return handler_in_0F_8A_JP_Jvds_16();
    }
}

/*
 JP
*/
inline bool CpuRunnerLLVM::handler_in_0F_8A_JP_Jvds_16() {
    typedef Bit16u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 JP
*/
inline bool CpuRunnerLLVM::handler_in_0F_8A_JP_Jvds_32() {
    typedef Bit32u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 JNP
*/
inline bool CpuRunnerLLVM::handler_in_0F_8B_JNP_Jvds() {
    if (Is32BitOperandMode()) {
        return handler_in_0F_8B_JNP_Jvds_32();
    } else {
        return handler_in_0F_8B_JNP_Jvds_16();
    }
}

/*
 JNP
*/
inline bool CpuRunnerLLVM::handler_in_0F_8B_JNP_Jvds_16() {
    typedef Bit16u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 JNP
*/
inline bool CpuRunnerLLVM::handler_in_0F_8B_JNP_Jvds_32() {
    typedef Bit32u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 JL
*/
inline bool CpuRunnerLLVM::handler_in_0F_8C_JL_Jvds() {
    if (Is32BitOperandMode()) {
        return handler_in_0F_8C_JL_Jvds_32();
    } else {
        return handler_in_0F_8C_JL_Jvds_16();
    }
}

/*
 JL
*/
inline bool CpuRunnerLLVM::handler_in_0F_8C_JL_Jvds_16() {
    typedef Bit16u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 JL
*/
inline bool CpuRunnerLLVM::handler_in_0F_8C_JL_Jvds_32() {
    typedef Bit32u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 JNL
*/
inline bool CpuRunnerLLVM::handler_in_0F_8D_JNL_Jvds() {
    if (Is32BitOperandMode()) {
        return handler_in_0F_8D_JNL_Jvds_32();
    } else {
        return handler_in_0F_8D_JNL_Jvds_16();
    }
}

/*
 JNL
*/
inline bool CpuRunnerLLVM::handler_in_0F_8D_JNL_Jvds_16() {
    typedef Bit16u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 JNL
*/
inline bool CpuRunnerLLVM::handler_in_0F_8D_JNL_Jvds_32() {
    typedef Bit32u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 JLE
*/
inline bool CpuRunnerLLVM::handler_in_0F_8E_JLE_Jvds() {
    if (Is32BitOperandMode()) {
        return handler_in_0F_8E_JLE_Jvds_32();
    } else {
        return handler_in_0F_8E_JLE_Jvds_16();
    }
}

/*
 JLE
*/
inline bool CpuRunnerLLVM::handler_in_0F_8E_JLE_Jvds_16() {
    typedef Bit16u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 JLE
*/
inline bool CpuRunnerLLVM::handler_in_0F_8E_JLE_Jvds_32() {
    typedef Bit32u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 JNLE
*/
inline bool CpuRunnerLLVM::handler_in_0F_8F_JNLE_Jvds() {
    if (Is32BitOperandMode()) {
        return handler_in_0F_8F_JNLE_Jvds_32();
    } else {
        return handler_in_0F_8F_JNLE_Jvds_16();
    }
}

/*
 JNLE
*/
inline bool CpuRunnerLLVM::handler_in_0F_8F_JNLE_Jvds_16() {
    typedef Bit16u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 JNLE
*/
inline bool CpuRunnerLLVM::handler_in_0F_8F_JNLE_Jvds_32() {
    typedef Bit32u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 SETO
*/
inline bool CpuRunnerLLVM::handler_in_0F_90_00_SETO_Eb() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 SETNO
*/
inline bool CpuRunnerLLVM::handler_in_0F_91_00_SETNO_Eb() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 SETB
*/
inline bool CpuRunnerLLVM::handler_in_0F_92_00_SETB_Eb() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 SETNB
*/
inline bool CpuRunnerLLVM::handler_in_0F_93_00_SETNB_Eb() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 SETZ
*/
inline bool CpuRunnerLLVM::handler_in_0F_94_00_SETZ_Eb() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 SETNZ
*/
inline bool CpuRunnerLLVM::handler_in_0F_95_00_SETNZ_Eb() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 SETBE
*/
inline bool CpuRunnerLLVM::handler_in_0F_96_00_SETBE_Eb() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 SETNBE
*/
inline bool CpuRunnerLLVM::handler_in_0F_97_00_SETNBE_Eb() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 SETS
*/
inline bool CpuRunnerLLVM::handler_in_0F_98_00_SETS_Eb() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 SETNS
*/
inline bool CpuRunnerLLVM::handler_in_0F_99_00_SETNS_Eb() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 SETP
*/
inline bool CpuRunnerLLVM::handler_in_0F_9A_00_SETP_Eb() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 SETNP
*/
inline bool CpuRunnerLLVM::handler_in_0F_9B_00_SETNP_Eb() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 SETL
*/
inline bool CpuRunnerLLVM::handler_in_0F_9C_00_SETL_Eb() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 SETNL
*/
inline bool CpuRunnerLLVM::handler_in_0F_9D_00_SETNL_Eb() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 SETLE
*/
inline bool CpuRunnerLLVM::handler_in_0F_9E_00_SETLE_Eb() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 SETNLE
*/
inline bool CpuRunnerLLVM::handler_in_0F_9F_00_SETNLE_Eb() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 PUSH
*/
inline bool CpuRunnerLLVM::handler_in_0F_A0_PUSH_FSw() {
    typedef Bit16u data_type;
    auto source = Segs.val[fs];
    //TODO do the actual operation
    return true;
}

/*
 POP
*/
inline bool CpuRunnerLLVM::handler_in_0F_A1_POP_FSw() {
    typedef Bit16u data_type;
    auto& destination = Segs.val[fs];
    //TODO do the actual operation
    return true;
}

/*
 CPUID
*/
inline bool CpuRunnerLLVM::handler_in_0F_A2_CPUID() {
    return true;
}

/*
 BT
*/
inline bool CpuRunnerLLVM::handler_in_0F_A3_BT_Gvqp() {
    if (Is32BitOperandMode()) {
        return handler_in_0F_A3_BT_Gvqp_32();
    } else {
        return handler_in_0F_A3_BT_Gvqp_16();
    }
}

/*
 BT
*/
inline bool CpuRunnerLLVM::handler_in_0F_A3_BT_Gvqp_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto source = GetRmReg<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 BT
*/
inline bool CpuRunnerLLVM::handler_in_0F_A3_BT_Gvqp_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto source = GetRmReg<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 SHLD
*/
inline bool CpuRunnerLLVM::handler_in_0F_A4_SHLD_Evqp_Ib() {
    if (Is32BitOperandMode()) {
        return handler_in_0F_A4_SHLD_Evqp_Ib_32();
    } else {
        return handler_in_0F_A4_SHLD_Evqp_Ib_16();
    }
}

/*
 SHLD
*/
inline bool CpuRunnerLLVM::handler_in_0F_A4_SHLD_Evqp_Ib_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 SHLD
*/
inline bool CpuRunnerLLVM::handler_in_0F_A4_SHLD_Evqp_Ib_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 SHLD
*/
inline bool CpuRunnerLLVM::handler_in_0F_A5_SHLD_Evqp_CLb() {
    if (Is32BitOperandMode()) {
        return handler_in_0F_A5_SHLD_Evqp_CLb_32();
    } else {
        return handler_in_0F_A5_SHLD_Evqp_CLb_16();
    }
}

/*
 SHLD
*/
inline bool CpuRunnerLLVM::handler_in_0F_A5_SHLD_Evqp_CLb_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = reg_cx;
    //TODO do the actual operation
    return true;
}

/*
 SHLD
*/
inline bool CpuRunnerLLVM::handler_in_0F_A5_SHLD_Evqp_CLb_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = reg_ecx;
    //TODO do the actual operation
    return true;
}

/*
 PUSH
*/
inline bool CpuRunnerLLVM::handler_in_0F_A8_PUSH_GSw() {
    typedef Bit16u data_type;
    auto source = Segs.val[gs];
    //TODO do the actual operation
    return true;
}

/*
 POP
*/
inline bool CpuRunnerLLVM::handler_in_0F_A9_POP_GSw() {
    typedef Bit16u data_type;
    auto& destination = Segs.val[gs];
    //TODO do the actual operation
    return true;
}

/*
 RSM
*/
inline bool CpuRunnerLLVM::handler_in_0F_AA_RSM() {
    return true;
}

/*
 BTS
*/
inline bool CpuRunnerLLVM::handler_in_0F_AB_BTS_Evqp_Gvqp() {
    if (Is32BitOperandMode()) {
        return handler_in_0F_AB_BTS_Evqp_Gvqp_32();
    } else {
        return handler_in_0F_AB_BTS_Evqp_Gvqp_16();
    }
}

/*
 BTS
*/
inline bool CpuRunnerLLVM::handler_in_0F_AB_BTS_Evqp_Gvqp_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetRmReg<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 BTS
*/
inline bool CpuRunnerLLVM::handler_in_0F_AB_BTS_Evqp_Gvqp_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetRmReg<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 SHRD
*/
inline bool CpuRunnerLLVM::handler_in_0F_AC_SHRD_Evqp_Ib() {
    if (Is32BitOperandMode()) {
        return handler_in_0F_AC_SHRD_Evqp_Ib_32();
    } else {
        return handler_in_0F_AC_SHRD_Evqp_Ib_16();
    }
}

/*
 SHRD
*/
inline bool CpuRunnerLLVM::handler_in_0F_AC_SHRD_Evqp_Ib_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 SHRD
*/
inline bool CpuRunnerLLVM::handler_in_0F_AC_SHRD_Evqp_Ib_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 SHRD
*/
inline bool CpuRunnerLLVM::handler_in_0F_AD_SHRD_Evqp_CLb() {
    if (Is32BitOperandMode()) {
        return handler_in_0F_AD_SHRD_Evqp_CLb_32();
    } else {
        return handler_in_0F_AD_SHRD_Evqp_CLb_16();
    }
}

/*
 SHRD
*/
inline bool CpuRunnerLLVM::handler_in_0F_AD_SHRD_Evqp_CLb_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = reg_cx;
    //TODO do the actual operation
    return true;
}

/*
 SHRD
*/
inline bool CpuRunnerLLVM::handler_in_0F_AD_SHRD_Evqp_CLb_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = reg_ecx;
    //TODO do the actual operation
    return true;
}

/*
 IMUL
*/
inline bool CpuRunnerLLVM::handler_in_0F_AF_IMUL_Gvqp_Evqp() {
    if (Is32BitOperandMode()) {
        return handler_in_0F_AF_IMUL_Gvqp_Evqp_32();
    } else {
        return handler_in_0F_AF_IMUL_Gvqp_Evqp_16();
    }
}

/*
 IMUL
*/
inline bool CpuRunnerLLVM::handler_in_0F_AF_IMUL_Gvqp_Evqp_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmReg<data_type>(rmmod);
    auto source = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 IMUL
*/
inline bool CpuRunnerLLVM::handler_in_0F_AF_IMUL_Gvqp_Evqp_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmReg<data_type>(rmmod);
    auto source = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 CMPXCHG
*/
inline bool CpuRunnerLLVM::handler_in_0F_B0_CMPXCHG_Eb_Gb() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetRmReg<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 CMPXCHG
*/
inline bool CpuRunnerLLVM::handler_in_0F_B1_CMPXCHG_Evqp_Gvqp() {
    if (Is32BitOperandMode()) {
        return handler_in_0F_B1_CMPXCHG_Evqp_Gvqp_32();
    } else {
        return handler_in_0F_B1_CMPXCHG_Evqp_Gvqp_16();
    }
}

/*
 CMPXCHG
*/
inline bool CpuRunnerLLVM::handler_in_0F_B1_CMPXCHG_Evqp_Gvqp_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetRmReg<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 CMPXCHG
*/
inline bool CpuRunnerLLVM::handler_in_0F_B1_CMPXCHG_Evqp_Gvqp_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetRmReg<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 LSS
*/
inline bool CpuRunnerLLVM::handler_in_0F_B2_LSS_Gvqp_Mptp() {
    if (Is32BitOperandMode()) {
        return handler_in_0F_B2_LSS_Gvqp_Mptp_32();
    } else {
        return handler_in_0F_B2_LSS_Gvqp_Mptp_16();
    }
}

/*
 LSS
*/
inline bool CpuRunnerLLVM::handler_in_0F_B2_LSS_Gvqp_Mptp_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmReg<data_type>(rmmod);
    auto source = GetRmMem<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 LSS
*/
inline bool CpuRunnerLLVM::handler_in_0F_B2_LSS_Gvqp_Mptp_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmReg<data_type>(rmmod);
    auto source = GetRmMem<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 BTR
*/
inline bool CpuRunnerLLVM::handler_in_0F_B3_BTR_Evqp_Gvqp() {
    if (Is32BitOperandMode()) {
        return handler_in_0F_B3_BTR_Evqp_Gvqp_32();
    } else {
        return handler_in_0F_B3_BTR_Evqp_Gvqp_16();
    }
}

/*
 BTR
*/
inline bool CpuRunnerLLVM::handler_in_0F_B3_BTR_Evqp_Gvqp_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetRmReg<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 BTR
*/
inline bool CpuRunnerLLVM::handler_in_0F_B3_BTR_Evqp_Gvqp_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetRmReg<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 LFS
*/
inline bool CpuRunnerLLVM::handler_in_0F_B4_LFS_Gvqp_Mptp() {
    if (Is32BitOperandMode()) {
        return handler_in_0F_B4_LFS_Gvqp_Mptp_32();
    } else {
        return handler_in_0F_B4_LFS_Gvqp_Mptp_16();
    }
}

/*
 LFS
*/
inline bool CpuRunnerLLVM::handler_in_0F_B4_LFS_Gvqp_Mptp_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmReg<data_type>(rmmod);
    auto source = GetRmMem<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 LFS
*/
inline bool CpuRunnerLLVM::handler_in_0F_B4_LFS_Gvqp_Mptp_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmReg<data_type>(rmmod);
    auto source = GetRmMem<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 LGS
*/
inline bool CpuRunnerLLVM::handler_in_0F_B5_LGS_Gvqp_Mptp() {
    if (Is32BitOperandMode()) {
        return handler_in_0F_B5_LGS_Gvqp_Mptp_32();
    } else {
        return handler_in_0F_B5_LGS_Gvqp_Mptp_16();
    }
}

/*
 LGS
*/
inline bool CpuRunnerLLVM::handler_in_0F_B5_LGS_Gvqp_Mptp_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmReg<data_type>(rmmod);
    auto source = GetRmMem<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 LGS
*/
inline bool CpuRunnerLLVM::handler_in_0F_B5_LGS_Gvqp_Mptp_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmReg<data_type>(rmmod);
    auto source = GetRmMem<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 MOVZX
*/
inline bool CpuRunnerLLVM::handler_in_0F_B6_MOVZX_Gvqp_Eb() {
    if (Is32BitOperandMode()) {
        return handler_in_0F_B6_MOVZX_Gvqp_Eb_32();
    } else {
        return handler_in_0F_B6_MOVZX_Gvqp_Eb_16();
    }
}

/*
 MOVZX
*/
inline bool CpuRunnerLLVM::handler_in_0F_B6_MOVZX_Gvqp_Eb_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmReg<data_type>(rmmod);
    auto source = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 MOVZX
*/
inline bool CpuRunnerLLVM::handler_in_0F_B6_MOVZX_Gvqp_Eb_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmReg<data_type>(rmmod);
    auto source = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 MOVZX
*/
inline bool CpuRunnerLLVM::handler_in_0F_B7_MOVZX_Gvqp_Ew() {
    if (Is32BitOperandMode()) {
        return handler_in_0F_B7_MOVZX_Gvqp_Ew_32();
    } else {
        return handler_in_0F_B7_MOVZX_Gvqp_Ew_16();
    }
}

/*
 MOVZX
*/
inline bool CpuRunnerLLVM::handler_in_0F_B7_MOVZX_Gvqp_Ew_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmReg<data_type>(rmmod);
    auto source = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 MOVZX
*/
inline bool CpuRunnerLLVM::handler_in_0F_B7_MOVZX_Gvqp_Ew_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmReg<data_type>(rmmod);
    auto source = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 BT
*/
inline bool CpuRunnerLLVM::handler_in_0F_BA_04_BT_Ib() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 BTS
*/
inline bool CpuRunnerLLVM::handler_in_0F_BA_05_BTS_Evqp_Ib() {
    if (Is32BitOperandMode()) {
        return handler_in_0F_BA_05_BTS_Evqp_Ib_32();
    } else {
        return handler_in_0F_BA_05_BTS_Evqp_Ib_16();
    }
}

/*
 BTS
*/
inline bool CpuRunnerLLVM::handler_in_0F_BA_05_BTS_Evqp_Ib_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 BTS
*/
inline bool CpuRunnerLLVM::handler_in_0F_BA_05_BTS_Evqp_Ib_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 BTR
*/
inline bool CpuRunnerLLVM::handler_in_0F_BA_06_BTR_Evqp_Ib() {
    if (Is32BitOperandMode()) {
        return handler_in_0F_BA_06_BTR_Evqp_Ib_32();
    } else {
        return handler_in_0F_BA_06_BTR_Evqp_Ib_16();
    }
}

/*
 BTR
*/
inline bool CpuRunnerLLVM::handler_in_0F_BA_06_BTR_Evqp_Ib_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 BTR
*/
inline bool CpuRunnerLLVM::handler_in_0F_BA_06_BTR_Evqp_Ib_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 BTC
*/
inline bool CpuRunnerLLVM::handler_in_0F_BA_07_BTC_Evqp_Ib() {
    if (Is32BitOperandMode()) {
        return handler_in_0F_BA_07_BTC_Evqp_Ib_32();
    } else {
        return handler_in_0F_BA_07_BTC_Evqp_Ib_16();
    }
}

/*
 BTC
*/
inline bool CpuRunnerLLVM::handler_in_0F_BA_07_BTC_Evqp_Ib_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 BTC
*/
inline bool CpuRunnerLLVM::handler_in_0F_BA_07_BTC_Evqp_Ib_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 BTC
*/
inline bool CpuRunnerLLVM::handler_in_0F_BB_BTC_Evqp_Gvqp() {
    if (Is32BitOperandMode()) {
        return handler_in_0F_BB_BTC_Evqp_Gvqp_32();
    } else {
        return handler_in_0F_BB_BTC_Evqp_Gvqp_16();
    }
}

/*
 BTC
*/
inline bool CpuRunnerLLVM::handler_in_0F_BB_BTC_Evqp_Gvqp_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetRmReg<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 BTC
*/
inline bool CpuRunnerLLVM::handler_in_0F_BB_BTC_Evqp_Gvqp_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetRmReg<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 BSF
*/
inline bool CpuRunnerLLVM::handler_in_0F_BC_BSF_Gvqp_Evqp() {
    if (Is32BitOperandMode()) {
        return handler_in_0F_BC_BSF_Gvqp_Evqp_32();
    } else {
        return handler_in_0F_BC_BSF_Gvqp_Evqp_16();
    }
}

/*
 BSF
*/
inline bool CpuRunnerLLVM::handler_in_0F_BC_BSF_Gvqp_Evqp_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmReg<data_type>(rmmod);
    auto source = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 BSF
*/
inline bool CpuRunnerLLVM::handler_in_0F_BC_BSF_Gvqp_Evqp_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmReg<data_type>(rmmod);
    auto source = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 BSR
*/
inline bool CpuRunnerLLVM::handler_in_0F_BD_BSR_Gvqp_Evqp() {
    if (Is32BitOperandMode()) {
        return handler_in_0F_BD_BSR_Gvqp_Evqp_32();
    } else {
        return handler_in_0F_BD_BSR_Gvqp_Evqp_16();
    }
}

/*
 BSR
*/
inline bool CpuRunnerLLVM::handler_in_0F_BD_BSR_Gvqp_Evqp_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmReg<data_type>(rmmod);
    auto source = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 BSR
*/
inline bool CpuRunnerLLVM::handler_in_0F_BD_BSR_Gvqp_Evqp_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmReg<data_type>(rmmod);
    auto source = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 MOVSX
*/
inline bool CpuRunnerLLVM::handler_in_0F_BE_MOVSX_Gvqp_Eb() {
    if (Is32BitOperandMode()) {
        return handler_in_0F_BE_MOVSX_Gvqp_Eb_32();
    } else {
        return handler_in_0F_BE_MOVSX_Gvqp_Eb_16();
    }
}

/*
 MOVSX
*/
inline bool CpuRunnerLLVM::handler_in_0F_BE_MOVSX_Gvqp_Eb_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmReg<data_type>(rmmod);
    auto source = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 MOVSX
*/
inline bool CpuRunnerLLVM::handler_in_0F_BE_MOVSX_Gvqp_Eb_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmReg<data_type>(rmmod);
    auto source = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 MOVSX
*/
inline bool CpuRunnerLLVM::handler_in_0F_BF_MOVSX_Gvqp_Ew() {
    if (Is32BitOperandMode()) {
        return handler_in_0F_BF_MOVSX_Gvqp_Ew_32();
    } else {
        return handler_in_0F_BF_MOVSX_Gvqp_Ew_16();
    }
}

/*
 MOVSX
*/
inline bool CpuRunnerLLVM::handler_in_0F_BF_MOVSX_Gvqp_Ew_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmReg<data_type>(rmmod);
    auto source = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 MOVSX
*/
inline bool CpuRunnerLLVM::handler_in_0F_BF_MOVSX_Gvqp_Ew_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmReg<data_type>(rmmod);
    auto source = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 XADD
*/
inline bool CpuRunnerLLVM::handler_in_0F_C0_XADD_Gb() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto destination = GetRmReg<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 XADD
*/
inline bool CpuRunnerLLVM::handler_in_0F_C1_XADD_Gvqp() {
    if (Is32BitOperandMode()) {
        return handler_in_0F_C1_XADD_Gvqp_32();
    } else {
        return handler_in_0F_C1_XADD_Gvqp_16();
    }
}

/*
 XADD
*/
inline bool CpuRunnerLLVM::handler_in_0F_C1_XADD_Gvqp_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmReg<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 XADD
*/
inline bool CpuRunnerLLVM::handler_in_0F_C1_XADD_Gvqp_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmReg<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 BSWAP
*/
inline bool CpuRunnerLLVM::handler_in_0F_C8_BSWAP_rAXvqp() {
    if (Is32BitOperandMode()) {
        return handler_in_0F_C8_BSWAP_rAXvqp_32();
    } else {
        return handler_in_0F_C8_BSWAP_rAXvqp_16();
    }
}

/*
 BSWAP
*/
inline bool CpuRunnerLLVM::handler_in_0F_C8_BSWAP_rAXvqp_16() {
    typedef Bit16u data_type;
    auto& destination = reg_ax;
    //TODO do the actual operation
    return true;
}

/*
 BSWAP
*/
inline bool CpuRunnerLLVM::handler_in_0F_C8_BSWAP_rAXvqp_32() {
    typedef Bit32u data_type;
    auto& destination = reg_eax;
    //TODO do the actual operation
    return true;
}

/*
 BSWAP
*/
inline bool CpuRunnerLLVM::handler_in_0F_C9_BSWAP_rCXvqp() {
    if (Is32BitOperandMode()) {
        return handler_in_0F_C9_BSWAP_rCXvqp_32();
    } else {
        return handler_in_0F_C9_BSWAP_rCXvqp_16();
    }
}

/*
 BSWAP
*/
inline bool CpuRunnerLLVM::handler_in_0F_C9_BSWAP_rCXvqp_16() {
    typedef Bit16u data_type;
    auto& destination = reg_cx;
    //TODO do the actual operation
    return true;
}

/*
 BSWAP
*/
inline bool CpuRunnerLLVM::handler_in_0F_C9_BSWAP_rCXvqp_32() {
    typedef Bit32u data_type;
    auto& destination = reg_ecx;
    //TODO do the actual operation
    return true;
}

/*
 BSWAP
*/
inline bool CpuRunnerLLVM::handler_in_0F_CA_BSWAP_rDXvqp() {
    if (Is32BitOperandMode()) {
        return handler_in_0F_CA_BSWAP_rDXvqp_32();
    } else {
        return handler_in_0F_CA_BSWAP_rDXvqp_16();
    }
}

/*
 BSWAP
*/
inline bool CpuRunnerLLVM::handler_in_0F_CA_BSWAP_rDXvqp_16() {
    typedef Bit16u data_type;
    auto& destination = reg_dx;
    //TODO do the actual operation
    return true;
}

/*
 BSWAP
*/
inline bool CpuRunnerLLVM::handler_in_0F_CA_BSWAP_rDXvqp_32() {
    typedef Bit32u data_type;
    auto& destination = reg_edx;
    //TODO do the actual operation
    return true;
}

/*
 BSWAP
*/
inline bool CpuRunnerLLVM::handler_in_0F_CB_BSWAP_rBXvqp() {
    if (Is32BitOperandMode()) {
        return handler_in_0F_CB_BSWAP_rBXvqp_32();
    } else {
        return handler_in_0F_CB_BSWAP_rBXvqp_16();
    }
}

/*
 BSWAP
*/
inline bool CpuRunnerLLVM::handler_in_0F_CB_BSWAP_rBXvqp_16() {
    typedef Bit16u data_type;
    auto& destination = reg_bx;
    //TODO do the actual operation
    return true;
}

/*
 BSWAP
*/
inline bool CpuRunnerLLVM::handler_in_0F_CB_BSWAP_rBXvqp_32() {
    typedef Bit32u data_type;
    auto& destination = reg_ebx;
    //TODO do the actual operation
    return true;
}

/*
 BSWAP
*/
inline bool CpuRunnerLLVM::handler_in_0F_CC_BSWAP_rSPvqp() {
    if (Is32BitOperandMode()) {
        return handler_in_0F_CC_BSWAP_rSPvqp_32();
    } else {
        return handler_in_0F_CC_BSWAP_rSPvqp_16();
    }
}

/*
 BSWAP
*/
inline bool CpuRunnerLLVM::handler_in_0F_CC_BSWAP_rSPvqp_16() {
    typedef Bit16u data_type;
    auto& destination = reg_sp;
    //TODO do the actual operation
    return true;
}

/*
 BSWAP
*/
inline bool CpuRunnerLLVM::handler_in_0F_CC_BSWAP_rSPvqp_32() {
    typedef Bit32u data_type;
    auto& destination = reg_esp;
    //TODO do the actual operation
    return true;
}

/*
 BSWAP
*/
inline bool CpuRunnerLLVM::handler_in_0F_CD_BSWAP_rBPvqp() {
    if (Is32BitOperandMode()) {
        return handler_in_0F_CD_BSWAP_rBPvqp_32();
    } else {
        return handler_in_0F_CD_BSWAP_rBPvqp_16();
    }
}

/*
 BSWAP
*/
inline bool CpuRunnerLLVM::handler_in_0F_CD_BSWAP_rBPvqp_16() {
    typedef Bit16u data_type;
    auto& destination = reg_bp;
    //TODO do the actual operation
    return true;
}

/*
 BSWAP
*/
inline bool CpuRunnerLLVM::handler_in_0F_CD_BSWAP_rBPvqp_32() {
    typedef Bit32u data_type;
    auto& destination = reg_ebp;
    //TODO do the actual operation
    return true;
}

/*
 BSWAP
*/
inline bool CpuRunnerLLVM::handler_in_0F_CE_BSWAP_rSIvqp() {
    if (Is32BitOperandMode()) {
        return handler_in_0F_CE_BSWAP_rSIvqp_32();
    } else {
        return handler_in_0F_CE_BSWAP_rSIvqp_16();
    }
}

/*
 BSWAP
*/
inline bool CpuRunnerLLVM::handler_in_0F_CE_BSWAP_rSIvqp_16() {
    typedef Bit16u data_type;
    auto& destination = reg_si;
    //TODO do the actual operation
    return true;
}

/*
 BSWAP
*/
inline bool CpuRunnerLLVM::handler_in_0F_CE_BSWAP_rSIvqp_32() {
    typedef Bit32u data_type;
    auto& destination = reg_esi;
    //TODO do the actual operation
    return true;
}

/*
 BSWAP
*/
inline bool CpuRunnerLLVM::handler_in_0F_CF_BSWAP_rDIvqp() {
    if (Is32BitOperandMode()) {
        return handler_in_0F_CF_BSWAP_rDIvqp_32();
    } else {
        return handler_in_0F_CF_BSWAP_rDIvqp_16();
    }
}

/*
 BSWAP
*/
inline bool CpuRunnerLLVM::handler_in_0F_CF_BSWAP_rDIvqp_16() {
    typedef Bit16u data_type;
    auto& destination = reg_di;
    //TODO do the actual operation
    return true;
}

/*
 BSWAP
*/
inline bool CpuRunnerLLVM::handler_in_0F_CF_BSWAP_rDIvqp_32() {
    typedef Bit32u data_type;
    auto& destination = reg_edi;
    //TODO do the actual operation
    return true;
}

/*
 ADC
*/
inline bool CpuRunnerLLVM::handler_in_10_ADC_Eb_Gb() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetRmReg<data_type>(rmmod);
    lflags.oldcf = get_CF() != 0;
    lf_var1b = destination->Read();
    lf_var2b = source->Read();
    lf_resb = lf_var1b + lf_var2b + lflags.oldcf;
    destination->Write(lf_resb);
    lflags.type = t_ADCb;
    return true;
}

/*
 ADC
*/
inline bool CpuRunnerLLVM::handler_in_11_ADC_Evqp_Gvqp() {
    if (Is32BitOperandMode()) {
        return handler_in_11_ADC_Evqp_Gvqp_32();
    } else {
        return handler_in_11_ADC_Evqp_Gvqp_16();
    }
}

/*
 ADC
*/
inline bool CpuRunnerLLVM::handler_in_11_ADC_Evqp_Gvqp_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetRmReg<data_type>(rmmod);
    lflags.oldcf = get_CF() != 0;
    lf_var1w = destination->Read();
    lf_var2w = source->Read();
    lf_resw = lf_var1w + lf_var2w + lflags.oldcf;
    destination->Write(lf_resw);
    lflags.type = t_ADCw;
    return true;
}

/*
 ADC
*/
inline bool CpuRunnerLLVM::handler_in_11_ADC_Evqp_Gvqp_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetRmReg<data_type>(rmmod);
    lflags.oldcf = get_CF() != 0;
    lf_var1d = destination->Read();
    lf_var2d = source->Read();
    lf_resd = lf_var1d + lf_var2d + lflags.oldcf;
    destination->Write(lf_resd);
    lflags.type = t_ADCd;
    return true;
}

/*
 ADC
*/
inline bool CpuRunnerLLVM::handler_in_12_ADC_Gb_Eb() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto destination = GetRmReg<data_type>(rmmod);
    auto source = GetRmMod<data_type>(rmmod);
    lflags.oldcf = get_CF() != 0;
    lf_var1b = destination->Read();
    lf_var2b = source->Read();
    lf_resb = lf_var1b + lf_var2b + lflags.oldcf;
    destination->Write(lf_resb);
    lflags.type = t_ADCb;
    return true;
}

/*
 ADC
*/
inline bool CpuRunnerLLVM::handler_in_13_ADC_Gvqp_Evqp() {
    if (Is32BitOperandMode()) {
        return handler_in_13_ADC_Gvqp_Evqp_32();
    } else {
        return handler_in_13_ADC_Gvqp_Evqp_16();
    }
}

/*
 ADC
*/
inline bool CpuRunnerLLVM::handler_in_13_ADC_Gvqp_Evqp_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmReg<data_type>(rmmod);
    auto source = GetRmMod<data_type>(rmmod);
    lflags.oldcf = get_CF() != 0;
    lf_var1w = destination->Read();
    lf_var2w = source->Read();
    lf_resw = lf_var1w + lf_var2w + lflags.oldcf;
    destination->Write(lf_resw);
    lflags.type = t_ADCw;
    return true;
}

/*
 ADC
*/
inline bool CpuRunnerLLVM::handler_in_13_ADC_Gvqp_Evqp_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmReg<data_type>(rmmod);
    auto source = GetRmMod<data_type>(rmmod);
    lflags.oldcf = get_CF() != 0;
    lf_var1d = destination->Read();
    lf_var2d = source->Read();
    lf_resd = lf_var1d + lf_var2d + lflags.oldcf;
    destination->Write(lf_resd);
    lflags.type = t_ADCd;
    return true;
}

/*
 ADC
*/
inline bool CpuRunnerLLVM::handler_in_14_ADC_ALb_Ib() {
    typedef Bit8u data_type;
    auto& destination = reg_al;
    auto source = GetImmediate<data_type>();
    lflags.oldcf = get_CF() != 0;
    lf_var1b = destination;
    lf_var2b = source;
    lf_resd = lf_var1d + lf_var2d + lflags.oldcf;
    destination = lf_resb;
    lflags.type=t_ADCb;
    return true;
}

/*
 ADC
*/
inline bool CpuRunnerLLVM::handler_in_15_ADC_rAXvqp_Ivds() {
    if (Is32BitOperandMode()) {
        return handler_in_15_ADC_rAXvqp_Ivds_32();
    } else {
        return handler_in_15_ADC_rAXvqp_Ivds_16();
    }
}

/*
 ADC
*/
inline bool CpuRunnerLLVM::handler_in_15_ADC_rAXvqp_Ivds_16() {
    typedef Bit16u data_type;
    auto& destination = reg_ax;
    auto source = GetImmediate<data_type>();
    lflags.oldcf = get_CF() != 0;
    lf_var1w = destination;
    lf_var2w = source;
    lf_resd = lf_var1d + lf_var2d + lflags.oldcf;
    destination = lf_resw;
    lflags.type=t_ADCw;
    return true;
}

/*
 ADC
*/
inline bool CpuRunnerLLVM::handler_in_15_ADC_rAXvqp_Ivds_32() {
    typedef Bit32u data_type;
    auto& destination = reg_eax;
    auto source = GetImmediate<data_type>();
    lflags.oldcf = get_CF() != 0;
    lf_var1d = destination;
    lf_var2d = source;
    lf_resd = lf_var1d + lf_var2d + lflags.oldcf;
    destination = lf_resd;
    lflags.type=t_ADCd;
    return true;
}

/*
 PUSH
*/
inline bool CpuRunnerLLVM::handler_in_16_PUSH_SSw() {
    typedef Bit16u data_type;
    auto source = Segs.val[ss];
    //TODO do the actual operation
    return true;
}

/*
 POP
*/
inline bool CpuRunnerLLVM::handler_in_17_POP_SSw() {
    typedef Bit16u data_type;
    auto& destination = Segs.val[ss];
    //TODO do the actual operation
    return true;
}

/*
 SBB
*/
inline bool CpuRunnerLLVM::handler_in_18_SBB_Eb_Gb() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetRmReg<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 SBB
*/
inline bool CpuRunnerLLVM::handler_in_19_SBB_Evqp_Gvqp() {
    if (Is32BitOperandMode()) {
        return handler_in_19_SBB_Evqp_Gvqp_32();
    } else {
        return handler_in_19_SBB_Evqp_Gvqp_16();
    }
}

/*
 SBB
*/
inline bool CpuRunnerLLVM::handler_in_19_SBB_Evqp_Gvqp_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetRmReg<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 SBB
*/
inline bool CpuRunnerLLVM::handler_in_19_SBB_Evqp_Gvqp_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetRmReg<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 SBB
*/
inline bool CpuRunnerLLVM::handler_in_1A_SBB_Gb_Eb() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto destination = GetRmReg<data_type>(rmmod);
    auto source = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 SBB
*/
inline bool CpuRunnerLLVM::handler_in_1B_SBB_Gvqp_Evqp() {
    if (Is32BitOperandMode()) {
        return handler_in_1B_SBB_Gvqp_Evqp_32();
    } else {
        return handler_in_1B_SBB_Gvqp_Evqp_16();
    }
}

/*
 SBB
*/
inline bool CpuRunnerLLVM::handler_in_1B_SBB_Gvqp_Evqp_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmReg<data_type>(rmmod);
    auto source = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 SBB
*/
inline bool CpuRunnerLLVM::handler_in_1B_SBB_Gvqp_Evqp_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmReg<data_type>(rmmod);
    auto source = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 SBB
*/
inline bool CpuRunnerLLVM::handler_in_1C_SBB_ALb_Ib() {
    typedef Bit8u data_type;
    auto& destination = reg_al;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 SBB
*/
inline bool CpuRunnerLLVM::handler_in_1D_SBB_rAXvqp_Ivds() {
    if (Is32BitOperandMode()) {
        return handler_in_1D_SBB_rAXvqp_Ivds_32();
    } else {
        return handler_in_1D_SBB_rAXvqp_Ivds_16();
    }
}

/*
 SBB
*/
inline bool CpuRunnerLLVM::handler_in_1D_SBB_rAXvqp_Ivds_16() {
    typedef Bit16u data_type;
    auto& destination = reg_ax;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 SBB
*/
inline bool CpuRunnerLLVM::handler_in_1D_SBB_rAXvqp_Ivds_32() {
    typedef Bit32u data_type;
    auto& destination = reg_eax;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 PUSH
*/
inline bool CpuRunnerLLVM::handler_in_1E_PUSH_DSw() {
    typedef Bit16u data_type;
    auto source = Segs.val[ds];
    //TODO do the actual operation
    return true;
}

/*
 POP
*/
inline bool CpuRunnerLLVM::handler_in_1F_POP_DSw() {
    typedef Bit16u data_type;
    auto& destination = Segs.val[ds];
    //TODO do the actual operation
    return true;
}

/*
 AND
*/
inline bool CpuRunnerLLVM::handler_in_20_AND_Eb_Gb() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetRmReg<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 AND
*/
inline bool CpuRunnerLLVM::handler_in_21_AND_Evqp_Gvqp() {
    if (Is32BitOperandMode()) {
        return handler_in_21_AND_Evqp_Gvqp_32();
    } else {
        return handler_in_21_AND_Evqp_Gvqp_16();
    }
}

/*
 AND
*/
inline bool CpuRunnerLLVM::handler_in_21_AND_Evqp_Gvqp_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetRmReg<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 AND
*/
inline bool CpuRunnerLLVM::handler_in_21_AND_Evqp_Gvqp_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetRmReg<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 AND
*/
inline bool CpuRunnerLLVM::handler_in_22_AND_Gb_Eb() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto destination = GetRmReg<data_type>(rmmod);
    auto source = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 AND
*/
inline bool CpuRunnerLLVM::handler_in_23_AND_Gvqp_Evqp() {
    if (Is32BitOperandMode()) {
        return handler_in_23_AND_Gvqp_Evqp_32();
    } else {
        return handler_in_23_AND_Gvqp_Evqp_16();
    }
}

/*
 AND
*/
inline bool CpuRunnerLLVM::handler_in_23_AND_Gvqp_Evqp_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmReg<data_type>(rmmod);
    auto source = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 AND
*/
inline bool CpuRunnerLLVM::handler_in_23_AND_Gvqp_Evqp_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmReg<data_type>(rmmod);
    auto source = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 AND
*/
inline bool CpuRunnerLLVM::handler_in_24_AND_ALb_Ib() {
    typedef Bit8u data_type;
    auto& destination = reg_al;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 AND
*/
inline bool CpuRunnerLLVM::handler_in_25_AND_rAXvqp_Ivds() {
    if (Is32BitOperandMode()) {
        return handler_in_25_AND_rAXvqp_Ivds_32();
    } else {
        return handler_in_25_AND_rAXvqp_Ivds_16();
    }
}

/*
 AND
*/
inline bool CpuRunnerLLVM::handler_in_25_AND_rAXvqp_Ivds_16() {
    typedef Bit16u data_type;
    auto& destination = reg_ax;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 AND
*/
inline bool CpuRunnerLLVM::handler_in_25_AND_rAXvqp_Ivds_32() {
    typedef Bit32u data_type;
    auto& destination = reg_eax;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 DAA
*/
inline bool CpuRunnerLLVM::handler_in_27_DAA() {
    return true;
}

/*
 SUB
*/
inline bool CpuRunnerLLVM::handler_in_28_SUB_Eb_Gb() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetRmReg<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 SUB
*/
inline bool CpuRunnerLLVM::handler_in_29_SUB_Evqp_Gvqp() {
    if (Is32BitOperandMode()) {
        return handler_in_29_SUB_Evqp_Gvqp_32();
    } else {
        return handler_in_29_SUB_Evqp_Gvqp_16();
    }
}

/*
 SUB
*/
inline bool CpuRunnerLLVM::handler_in_29_SUB_Evqp_Gvqp_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetRmReg<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 SUB
*/
inline bool CpuRunnerLLVM::handler_in_29_SUB_Evqp_Gvqp_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetRmReg<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 SUB
*/
inline bool CpuRunnerLLVM::handler_in_2A_SUB_Gb_Eb() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto destination = GetRmReg<data_type>(rmmod);
    auto source = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 SUB
*/
inline bool CpuRunnerLLVM::handler_in_2B_SUB_Gvqp_Evqp() {
    if (Is32BitOperandMode()) {
        return handler_in_2B_SUB_Gvqp_Evqp_32();
    } else {
        return handler_in_2B_SUB_Gvqp_Evqp_16();
    }
}

/*
 SUB
*/
inline bool CpuRunnerLLVM::handler_in_2B_SUB_Gvqp_Evqp_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmReg<data_type>(rmmod);
    auto source = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 SUB
*/
inline bool CpuRunnerLLVM::handler_in_2B_SUB_Gvqp_Evqp_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmReg<data_type>(rmmod);
    auto source = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 SUB
*/
inline bool CpuRunnerLLVM::handler_in_2C_SUB_ALb_Ib() {
    typedef Bit8u data_type;
    auto& destination = reg_al;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 SUB
*/
inline bool CpuRunnerLLVM::handler_in_2D_SUB_rAXvqp_Ivds() {
    if (Is32BitOperandMode()) {
        return handler_in_2D_SUB_rAXvqp_Ivds_32();
    } else {
        return handler_in_2D_SUB_rAXvqp_Ivds_16();
    }
}

/*
 SUB
*/
inline bool CpuRunnerLLVM::handler_in_2D_SUB_rAXvqp_Ivds_16() {
    typedef Bit16u data_type;
    auto& destination = reg_ax;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 SUB
*/
inline bool CpuRunnerLLVM::handler_in_2D_SUB_rAXvqp_Ivds_32() {
    typedef Bit32u data_type;
    auto& destination = reg_eax;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 DAS
*/
inline bool CpuRunnerLLVM::handler_in_2F_DAS() {
    return true;
}

/*
 XOR
*/
inline bool CpuRunnerLLVM::handler_in_30_XOR_Eb_Gb() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetRmReg<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 XOR
*/
inline bool CpuRunnerLLVM::handler_in_31_XOR_Evqp_Gvqp() {
    if (Is32BitOperandMode()) {
        return handler_in_31_XOR_Evqp_Gvqp_32();
    } else {
        return handler_in_31_XOR_Evqp_Gvqp_16();
    }
}

/*
 XOR
*/
inline bool CpuRunnerLLVM::handler_in_31_XOR_Evqp_Gvqp_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetRmReg<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 XOR
*/
inline bool CpuRunnerLLVM::handler_in_31_XOR_Evqp_Gvqp_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetRmReg<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 XOR
*/
inline bool CpuRunnerLLVM::handler_in_32_XOR_Gb_Eb() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto destination = GetRmReg<data_type>(rmmod);
    auto source = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 XOR
*/
inline bool CpuRunnerLLVM::handler_in_33_XOR_Gvqp_Evqp() {
    if (Is32BitOperandMode()) {
        return handler_in_33_XOR_Gvqp_Evqp_32();
    } else {
        return handler_in_33_XOR_Gvqp_Evqp_16();
    }
}

/*
 XOR
*/
inline bool CpuRunnerLLVM::handler_in_33_XOR_Gvqp_Evqp_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmReg<data_type>(rmmod);
    auto source = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 XOR
*/
inline bool CpuRunnerLLVM::handler_in_33_XOR_Gvqp_Evqp_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmReg<data_type>(rmmod);
    auto source = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 XOR
*/
inline bool CpuRunnerLLVM::handler_in_34_XOR_ALb_Ib() {
    typedef Bit8u data_type;
    auto& destination = reg_al;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 XOR
*/
inline bool CpuRunnerLLVM::handler_in_35_XOR_rAXvqp_Ivds() {
    if (Is32BitOperandMode()) {
        return handler_in_35_XOR_rAXvqp_Ivds_32();
    } else {
        return handler_in_35_XOR_rAXvqp_Ivds_16();
    }
}

/*
 XOR
*/
inline bool CpuRunnerLLVM::handler_in_35_XOR_rAXvqp_Ivds_16() {
    typedef Bit16u data_type;
    auto& destination = reg_ax;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 XOR
*/
inline bool CpuRunnerLLVM::handler_in_35_XOR_rAXvqp_Ivds_32() {
    typedef Bit32u data_type;
    auto& destination = reg_eax;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 AAA
*/
inline bool CpuRunnerLLVM::handler_in_37_AAA() {
    return true;
}

/*
 CMP
*/
inline bool CpuRunnerLLVM::handler_in_38_CMP_Gb() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto source = GetRmReg<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 CMP
*/
inline bool CpuRunnerLLVM::handler_in_39_CMP_Gvqp() {
    if (Is32BitOperandMode()) {
        return handler_in_39_CMP_Gvqp_32();
    } else {
        return handler_in_39_CMP_Gvqp_16();
    }
}

/*
 CMP
*/
inline bool CpuRunnerLLVM::handler_in_39_CMP_Gvqp_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto source = GetRmReg<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 CMP
*/
inline bool CpuRunnerLLVM::handler_in_39_CMP_Gvqp_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto source = GetRmReg<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 CMP
*/
inline bool CpuRunnerLLVM::handler_in_3A_CMP_Eb() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto source = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 CMP
*/
inline bool CpuRunnerLLVM::handler_in_3B_CMP_Evqp() {
    if (Is32BitOperandMode()) {
        return handler_in_3B_CMP_Evqp_32();
    } else {
        return handler_in_3B_CMP_Evqp_16();
    }
}

/*
 CMP
*/
inline bool CpuRunnerLLVM::handler_in_3B_CMP_Evqp_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto source = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 CMP
*/
inline bool CpuRunnerLLVM::handler_in_3B_CMP_Evqp_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto source = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 CMP
*/
inline bool CpuRunnerLLVM::handler_in_3C_CMP_Ib() {
    typedef Bit8u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 CMP
*/
inline bool CpuRunnerLLVM::handler_in_3D_CMP_Ivds() {
    if (Is32BitOperandMode()) {
        return handler_in_3D_CMP_Ivds_32();
    } else {
        return handler_in_3D_CMP_Ivds_16();
    }
}

/*
 CMP
*/
inline bool CpuRunnerLLVM::handler_in_3D_CMP_Ivds_16() {
    typedef Bit16u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 CMP
*/
inline bool CpuRunnerLLVM::handler_in_3D_CMP_Ivds_32() {
    typedef Bit32u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 AAS
*/
inline bool CpuRunnerLLVM::handler_in_3F_AAS() {
    return true;
}

/*
 INC
*/
inline bool CpuRunnerLLVM::handler_in_40_INC_rAXv() {
    if (Is32BitOperandMode()) {
        return handler_in_40_INC_rAXv_32();
    } else {
        return handler_in_40_INC_rAXv_16();
    }
}

/*
 INC
*/
inline bool CpuRunnerLLVM::handler_in_40_INC_rAXv_16() {
    typedef Bit16u data_type;
    auto& destination = reg_ax;
    //TODO do the actual operation
    return true;
}

/*
 INC
*/
inline bool CpuRunnerLLVM::handler_in_40_INC_rAXv_32() {
    typedef Bit32u data_type;
    auto& destination = reg_eax;
    //TODO do the actual operation
    return true;
}

/*
 INC
*/
inline bool CpuRunnerLLVM::handler_in_41_INC_rCXv() {
    if (Is32BitOperandMode()) {
        return handler_in_41_INC_rCXv_32();
    } else {
        return handler_in_41_INC_rCXv_16();
    }
}

/*
 INC
*/
inline bool CpuRunnerLLVM::handler_in_41_INC_rCXv_16() {
    typedef Bit16u data_type;
    auto& destination = reg_cx;
    //TODO do the actual operation
    return true;
}

/*
 INC
*/
inline bool CpuRunnerLLVM::handler_in_41_INC_rCXv_32() {
    typedef Bit32u data_type;
    auto& destination = reg_ecx;
    //TODO do the actual operation
    return true;
}

/*
 INC
*/
inline bool CpuRunnerLLVM::handler_in_42_INC_rDXv() {
    if (Is32BitOperandMode()) {
        return handler_in_42_INC_rDXv_32();
    } else {
        return handler_in_42_INC_rDXv_16();
    }
}

/*
 INC
*/
inline bool CpuRunnerLLVM::handler_in_42_INC_rDXv_16() {
    typedef Bit16u data_type;
    auto& destination = reg_dx;
    //TODO do the actual operation
    return true;
}

/*
 INC
*/
inline bool CpuRunnerLLVM::handler_in_42_INC_rDXv_32() {
    typedef Bit32u data_type;
    auto& destination = reg_edx;
    //TODO do the actual operation
    return true;
}

/*
 INC
*/
inline bool CpuRunnerLLVM::handler_in_43_INC_rBXv() {
    if (Is32BitOperandMode()) {
        return handler_in_43_INC_rBXv_32();
    } else {
        return handler_in_43_INC_rBXv_16();
    }
}

/*
 INC
*/
inline bool CpuRunnerLLVM::handler_in_43_INC_rBXv_16() {
    typedef Bit16u data_type;
    auto& destination = reg_bx;
    //TODO do the actual operation
    return true;
}

/*
 INC
*/
inline bool CpuRunnerLLVM::handler_in_43_INC_rBXv_32() {
    typedef Bit32u data_type;
    auto& destination = reg_ebx;
    //TODO do the actual operation
    return true;
}

/*
 INC
*/
inline bool CpuRunnerLLVM::handler_in_44_INC_rSPv() {
    if (Is32BitOperandMode()) {
        return handler_in_44_INC_rSPv_32();
    } else {
        return handler_in_44_INC_rSPv_16();
    }
}

/*
 INC
*/
inline bool CpuRunnerLLVM::handler_in_44_INC_rSPv_16() {
    typedef Bit16u data_type;
    auto& destination = reg_sp;
    //TODO do the actual operation
    return true;
}

/*
 INC
*/
inline bool CpuRunnerLLVM::handler_in_44_INC_rSPv_32() {
    typedef Bit32u data_type;
    auto& destination = reg_esp;
    //TODO do the actual operation
    return true;
}

/*
 INC
*/
inline bool CpuRunnerLLVM::handler_in_45_INC_rBPv() {
    if (Is32BitOperandMode()) {
        return handler_in_45_INC_rBPv_32();
    } else {
        return handler_in_45_INC_rBPv_16();
    }
}

/*
 INC
*/
inline bool CpuRunnerLLVM::handler_in_45_INC_rBPv_16() {
    typedef Bit16u data_type;
    auto& destination = reg_bp;
    //TODO do the actual operation
    return true;
}

/*
 INC
*/
inline bool CpuRunnerLLVM::handler_in_45_INC_rBPv_32() {
    typedef Bit32u data_type;
    auto& destination = reg_ebp;
    //TODO do the actual operation
    return true;
}

/*
 INC
*/
inline bool CpuRunnerLLVM::handler_in_46_INC_rSIv() {
    if (Is32BitOperandMode()) {
        return handler_in_46_INC_rSIv_32();
    } else {
        return handler_in_46_INC_rSIv_16();
    }
}

/*
 INC
*/
inline bool CpuRunnerLLVM::handler_in_46_INC_rSIv_16() {
    typedef Bit16u data_type;
    auto& destination = reg_si;
    //TODO do the actual operation
    return true;
}

/*
 INC
*/
inline bool CpuRunnerLLVM::handler_in_46_INC_rSIv_32() {
    typedef Bit32u data_type;
    auto& destination = reg_esi;
    //TODO do the actual operation
    return true;
}

/*
 INC
*/
inline bool CpuRunnerLLVM::handler_in_47_INC_rDIv() {
    if (Is32BitOperandMode()) {
        return handler_in_47_INC_rDIv_32();
    } else {
        return handler_in_47_INC_rDIv_16();
    }
}

/*
 INC
*/
inline bool CpuRunnerLLVM::handler_in_47_INC_rDIv_16() {
    typedef Bit16u data_type;
    auto& destination = reg_di;
    //TODO do the actual operation
    return true;
}

/*
 INC
*/
inline bool CpuRunnerLLVM::handler_in_47_INC_rDIv_32() {
    typedef Bit32u data_type;
    auto& destination = reg_edi;
    //TODO do the actual operation
    return true;
}

/*
 DEC
*/
inline bool CpuRunnerLLVM::handler_in_48_DEC_rAXv() {
    if (Is32BitOperandMode()) {
        return handler_in_48_DEC_rAXv_32();
    } else {
        return handler_in_48_DEC_rAXv_16();
    }
}

/*
 DEC
*/
inline bool CpuRunnerLLVM::handler_in_48_DEC_rAXv_16() {
    typedef Bit16u data_type;
    auto& destination = reg_ax;
    //TODO do the actual operation
    return true;
}

/*
 DEC
*/
inline bool CpuRunnerLLVM::handler_in_48_DEC_rAXv_32() {
    typedef Bit32u data_type;
    auto& destination = reg_eax;
    //TODO do the actual operation
    return true;
}

/*
 DEC
*/
inline bool CpuRunnerLLVM::handler_in_49_DEC_rCXv() {
    if (Is32BitOperandMode()) {
        return handler_in_49_DEC_rCXv_32();
    } else {
        return handler_in_49_DEC_rCXv_16();
    }
}

/*
 DEC
*/
inline bool CpuRunnerLLVM::handler_in_49_DEC_rCXv_16() {
    typedef Bit16u data_type;
    auto& destination = reg_cx;
    //TODO do the actual operation
    return true;
}

/*
 DEC
*/
inline bool CpuRunnerLLVM::handler_in_49_DEC_rCXv_32() {
    typedef Bit32u data_type;
    auto& destination = reg_ecx;
    //TODO do the actual operation
    return true;
}

/*
 DEC
*/
inline bool CpuRunnerLLVM::handler_in_4A_DEC_rDXv() {
    if (Is32BitOperandMode()) {
        return handler_in_4A_DEC_rDXv_32();
    } else {
        return handler_in_4A_DEC_rDXv_16();
    }
}

/*
 DEC
*/
inline bool CpuRunnerLLVM::handler_in_4A_DEC_rDXv_16() {
    typedef Bit16u data_type;
    auto& destination = reg_dx;
    //TODO do the actual operation
    return true;
}

/*
 DEC
*/
inline bool CpuRunnerLLVM::handler_in_4A_DEC_rDXv_32() {
    typedef Bit32u data_type;
    auto& destination = reg_edx;
    //TODO do the actual operation
    return true;
}

/*
 DEC
*/
inline bool CpuRunnerLLVM::handler_in_4B_DEC_rBXv() {
    if (Is32BitOperandMode()) {
        return handler_in_4B_DEC_rBXv_32();
    } else {
        return handler_in_4B_DEC_rBXv_16();
    }
}

/*
 DEC
*/
inline bool CpuRunnerLLVM::handler_in_4B_DEC_rBXv_16() {
    typedef Bit16u data_type;
    auto& destination = reg_bx;
    //TODO do the actual operation
    return true;
}

/*
 DEC
*/
inline bool CpuRunnerLLVM::handler_in_4B_DEC_rBXv_32() {
    typedef Bit32u data_type;
    auto& destination = reg_ebx;
    //TODO do the actual operation
    return true;
}

/*
 DEC
*/
inline bool CpuRunnerLLVM::handler_in_4C_DEC_rSPv() {
    if (Is32BitOperandMode()) {
        return handler_in_4C_DEC_rSPv_32();
    } else {
        return handler_in_4C_DEC_rSPv_16();
    }
}

/*
 DEC
*/
inline bool CpuRunnerLLVM::handler_in_4C_DEC_rSPv_16() {
    typedef Bit16u data_type;
    auto& destination = reg_sp;
    //TODO do the actual operation
    return true;
}

/*
 DEC
*/
inline bool CpuRunnerLLVM::handler_in_4C_DEC_rSPv_32() {
    typedef Bit32u data_type;
    auto& destination = reg_esp;
    //TODO do the actual operation
    return true;
}

/*
 DEC
*/
inline bool CpuRunnerLLVM::handler_in_4D_DEC_rBPv() {
    if (Is32BitOperandMode()) {
        return handler_in_4D_DEC_rBPv_32();
    } else {
        return handler_in_4D_DEC_rBPv_16();
    }
}

/*
 DEC
*/
inline bool CpuRunnerLLVM::handler_in_4D_DEC_rBPv_16() {
    typedef Bit16u data_type;
    auto& destination = reg_bp;
    //TODO do the actual operation
    return true;
}

/*
 DEC
*/
inline bool CpuRunnerLLVM::handler_in_4D_DEC_rBPv_32() {
    typedef Bit32u data_type;
    auto& destination = reg_ebp;
    //TODO do the actual operation
    return true;
}

/*
 DEC
*/
inline bool CpuRunnerLLVM::handler_in_4E_DEC_rSIv() {
    if (Is32BitOperandMode()) {
        return handler_in_4E_DEC_rSIv_32();
    } else {
        return handler_in_4E_DEC_rSIv_16();
    }
}

/*
 DEC
*/
inline bool CpuRunnerLLVM::handler_in_4E_DEC_rSIv_16() {
    typedef Bit16u data_type;
    auto& destination = reg_si;
    //TODO do the actual operation
    return true;
}

/*
 DEC
*/
inline bool CpuRunnerLLVM::handler_in_4E_DEC_rSIv_32() {
    typedef Bit32u data_type;
    auto& destination = reg_esi;
    //TODO do the actual operation
    return true;
}

/*
 DEC
*/
inline bool CpuRunnerLLVM::handler_in_4F_DEC_rDIv() {
    if (Is32BitOperandMode()) {
        return handler_in_4F_DEC_rDIv_32();
    } else {
        return handler_in_4F_DEC_rDIv_16();
    }
}

/*
 DEC
*/
inline bool CpuRunnerLLVM::handler_in_4F_DEC_rDIv_16() {
    typedef Bit16u data_type;
    auto& destination = reg_di;
    //TODO do the actual operation
    return true;
}

/*
 DEC
*/
inline bool CpuRunnerLLVM::handler_in_4F_DEC_rDIv_32() {
    typedef Bit32u data_type;
    auto& destination = reg_edi;
    //TODO do the actual operation
    return true;
}

/*
 PUSH
*/
inline bool CpuRunnerLLVM::handler_in_50_PUSH_rAXv() {
    if (Is32BitOperandMode()) {
        return handler_in_50_PUSH_rAXv_32();
    } else {
        return handler_in_50_PUSH_rAXv_16();
    }
}

/*
 PUSH
*/
inline bool CpuRunnerLLVM::handler_in_50_PUSH_rAXv_16() {
    typedef Bit16u data_type;
    auto source = reg_ax;
    //TODO do the actual operation
    return true;
}

/*
 PUSH
*/
inline bool CpuRunnerLLVM::handler_in_50_PUSH_rAXv_32() {
    typedef Bit32u data_type;
    auto source = reg_eax;
    //TODO do the actual operation
    return true;
}

/*
 PUSH
*/
inline bool CpuRunnerLLVM::handler_in_51_PUSH_rCXv() {
    if (Is32BitOperandMode()) {
        return handler_in_51_PUSH_rCXv_32();
    } else {
        return handler_in_51_PUSH_rCXv_16();
    }
}

/*
 PUSH
*/
inline bool CpuRunnerLLVM::handler_in_51_PUSH_rCXv_16() {
    typedef Bit16u data_type;
    auto source = reg_cx;
    //TODO do the actual operation
    return true;
}

/*
 PUSH
*/
inline bool CpuRunnerLLVM::handler_in_51_PUSH_rCXv_32() {
    typedef Bit32u data_type;
    auto source = reg_ecx;
    //TODO do the actual operation
    return true;
}

/*
 PUSH
*/
inline bool CpuRunnerLLVM::handler_in_52_PUSH_rDXv() {
    if (Is32BitOperandMode()) {
        return handler_in_52_PUSH_rDXv_32();
    } else {
        return handler_in_52_PUSH_rDXv_16();
    }
}

/*
 PUSH
*/
inline bool CpuRunnerLLVM::handler_in_52_PUSH_rDXv_16() {
    typedef Bit16u data_type;
    auto source = reg_dx;
    //TODO do the actual operation
    return true;
}

/*
 PUSH
*/
inline bool CpuRunnerLLVM::handler_in_52_PUSH_rDXv_32() {
    typedef Bit32u data_type;
    auto source = reg_edx;
    //TODO do the actual operation
    return true;
}

/*
 PUSH
*/
inline bool CpuRunnerLLVM::handler_in_53_PUSH_rBXv() {
    if (Is32BitOperandMode()) {
        return handler_in_53_PUSH_rBXv_32();
    } else {
        return handler_in_53_PUSH_rBXv_16();
    }
}

/*
 PUSH
*/
inline bool CpuRunnerLLVM::handler_in_53_PUSH_rBXv_16() {
    typedef Bit16u data_type;
    auto source = reg_bx;
    //TODO do the actual operation
    return true;
}

/*
 PUSH
*/
inline bool CpuRunnerLLVM::handler_in_53_PUSH_rBXv_32() {
    typedef Bit32u data_type;
    auto source = reg_ebx;
    //TODO do the actual operation
    return true;
}

/*
 PUSH
*/
inline bool CpuRunnerLLVM::handler_in_54_PUSH_rSPv() {
    if (Is32BitOperandMode()) {
        return handler_in_54_PUSH_rSPv_32();
    } else {
        return handler_in_54_PUSH_rSPv_16();
    }
}

/*
 PUSH
*/
inline bool CpuRunnerLLVM::handler_in_54_PUSH_rSPv_16() {
    typedef Bit16u data_type;
    auto source = reg_sp;
    //TODO do the actual operation
    return true;
}

/*
 PUSH
*/
inline bool CpuRunnerLLVM::handler_in_54_PUSH_rSPv_32() {
    typedef Bit32u data_type;
    auto source = reg_esp;
    //TODO do the actual operation
    return true;
}

/*
 PUSH
*/
inline bool CpuRunnerLLVM::handler_in_55_PUSH_rBPv() {
    if (Is32BitOperandMode()) {
        return handler_in_55_PUSH_rBPv_32();
    } else {
        return handler_in_55_PUSH_rBPv_16();
    }
}

/*
 PUSH
*/
inline bool CpuRunnerLLVM::handler_in_55_PUSH_rBPv_16() {
    typedef Bit16u data_type;
    auto source = reg_bp;
    //TODO do the actual operation
    return true;
}

/*
 PUSH
*/
inline bool CpuRunnerLLVM::handler_in_55_PUSH_rBPv_32() {
    typedef Bit32u data_type;
    auto source = reg_ebp;
    //TODO do the actual operation
    return true;
}

/*
 PUSH
*/
inline bool CpuRunnerLLVM::handler_in_56_PUSH_rSIv() {
    if (Is32BitOperandMode()) {
        return handler_in_56_PUSH_rSIv_32();
    } else {
        return handler_in_56_PUSH_rSIv_16();
    }
}

/*
 PUSH
*/
inline bool CpuRunnerLLVM::handler_in_56_PUSH_rSIv_16() {
    typedef Bit16u data_type;
    auto source = reg_si;
    //TODO do the actual operation
    return true;
}

/*
 PUSH
*/
inline bool CpuRunnerLLVM::handler_in_56_PUSH_rSIv_32() {
    typedef Bit32u data_type;
    auto source = reg_esi;
    //TODO do the actual operation
    return true;
}

/*
 PUSH
*/
inline bool CpuRunnerLLVM::handler_in_57_PUSH_rDIv() {
    if (Is32BitOperandMode()) {
        return handler_in_57_PUSH_rDIv_32();
    } else {
        return handler_in_57_PUSH_rDIv_16();
    }
}

/*
 PUSH
*/
inline bool CpuRunnerLLVM::handler_in_57_PUSH_rDIv_16() {
    typedef Bit16u data_type;
    auto source = reg_di;
    //TODO do the actual operation
    return true;
}

/*
 PUSH
*/
inline bool CpuRunnerLLVM::handler_in_57_PUSH_rDIv_32() {
    typedef Bit32u data_type;
    auto source = reg_edi;
    //TODO do the actual operation
    return true;
}

/*
 POP
*/
inline bool CpuRunnerLLVM::handler_in_58_POP_rAXv() {
    if (Is32BitOperandMode()) {
        return handler_in_58_POP_rAXv_32();
    } else {
        return handler_in_58_POP_rAXv_16();
    }
}

/*
 POP
*/
inline bool CpuRunnerLLVM::handler_in_58_POP_rAXv_16() {
    typedef Bit16u data_type;
    auto& destination = reg_ax;
    //TODO do the actual operation
    return true;
}

/*
 POP
*/
inline bool CpuRunnerLLVM::handler_in_58_POP_rAXv_32() {
    typedef Bit32u data_type;
    auto& destination = reg_eax;
    //TODO do the actual operation
    return true;
}

/*
 POP
*/
inline bool CpuRunnerLLVM::handler_in_59_POP_rCXv() {
    if (Is32BitOperandMode()) {
        return handler_in_59_POP_rCXv_32();
    } else {
        return handler_in_59_POP_rCXv_16();
    }
}

/*
 POP
*/
inline bool CpuRunnerLLVM::handler_in_59_POP_rCXv_16() {
    typedef Bit16u data_type;
    auto& destination = reg_cx;
    //TODO do the actual operation
    return true;
}

/*
 POP
*/
inline bool CpuRunnerLLVM::handler_in_59_POP_rCXv_32() {
    typedef Bit32u data_type;
    auto& destination = reg_ecx;
    //TODO do the actual operation
    return true;
}

/*
 POP
*/
inline bool CpuRunnerLLVM::handler_in_5A_POP_rDXv() {
    if (Is32BitOperandMode()) {
        return handler_in_5A_POP_rDXv_32();
    } else {
        return handler_in_5A_POP_rDXv_16();
    }
}

/*
 POP
*/
inline bool CpuRunnerLLVM::handler_in_5A_POP_rDXv_16() {
    typedef Bit16u data_type;
    auto& destination = reg_dx;
    //TODO do the actual operation
    return true;
}

/*
 POP
*/
inline bool CpuRunnerLLVM::handler_in_5A_POP_rDXv_32() {
    typedef Bit32u data_type;
    auto& destination = reg_edx;
    //TODO do the actual operation
    return true;
}

/*
 POP
*/
inline bool CpuRunnerLLVM::handler_in_5B_POP_rBXv() {
    if (Is32BitOperandMode()) {
        return handler_in_5B_POP_rBXv_32();
    } else {
        return handler_in_5B_POP_rBXv_16();
    }
}

/*
 POP
*/
inline bool CpuRunnerLLVM::handler_in_5B_POP_rBXv_16() {
    typedef Bit16u data_type;
    auto& destination = reg_bx;
    //TODO do the actual operation
    return true;
}

/*
 POP
*/
inline bool CpuRunnerLLVM::handler_in_5B_POP_rBXv_32() {
    typedef Bit32u data_type;
    auto& destination = reg_ebx;
    //TODO do the actual operation
    return true;
}

/*
 POP
*/
inline bool CpuRunnerLLVM::handler_in_5C_POP_rSPv() {
    if (Is32BitOperandMode()) {
        return handler_in_5C_POP_rSPv_32();
    } else {
        return handler_in_5C_POP_rSPv_16();
    }
}

/*
 POP
*/
inline bool CpuRunnerLLVM::handler_in_5C_POP_rSPv_16() {
    typedef Bit16u data_type;
    auto& destination = reg_sp;
    //TODO do the actual operation
    return true;
}

/*
 POP
*/
inline bool CpuRunnerLLVM::handler_in_5C_POP_rSPv_32() {
    typedef Bit32u data_type;
    auto& destination = reg_esp;
    //TODO do the actual operation
    return true;
}

/*
 POP
*/
inline bool CpuRunnerLLVM::handler_in_5D_POP_rBPv() {
    if (Is32BitOperandMode()) {
        return handler_in_5D_POP_rBPv_32();
    } else {
        return handler_in_5D_POP_rBPv_16();
    }
}

/*
 POP
*/
inline bool CpuRunnerLLVM::handler_in_5D_POP_rBPv_16() {
    typedef Bit16u data_type;
    auto& destination = reg_bp;
    //TODO do the actual operation
    return true;
}

/*
 POP
*/
inline bool CpuRunnerLLVM::handler_in_5D_POP_rBPv_32() {
    typedef Bit32u data_type;
    auto& destination = reg_ebp;
    //TODO do the actual operation
    return true;
}

/*
 POP
*/
inline bool CpuRunnerLLVM::handler_in_5E_POP_rSIv() {
    if (Is32BitOperandMode()) {
        return handler_in_5E_POP_rSIv_32();
    } else {
        return handler_in_5E_POP_rSIv_16();
    }
}

/*
 POP
*/
inline bool CpuRunnerLLVM::handler_in_5E_POP_rSIv_16() {
    typedef Bit16u data_type;
    auto& destination = reg_si;
    //TODO do the actual operation
    return true;
}

/*
 POP
*/
inline bool CpuRunnerLLVM::handler_in_5E_POP_rSIv_32() {
    typedef Bit32u data_type;
    auto& destination = reg_esi;
    //TODO do the actual operation
    return true;
}

/*
 POP
*/
inline bool CpuRunnerLLVM::handler_in_5F_POP_rDIv() {
    if (Is32BitOperandMode()) {
        return handler_in_5F_POP_rDIv_32();
    } else {
        return handler_in_5F_POP_rDIv_16();
    }
}

/*
 POP
*/
inline bool CpuRunnerLLVM::handler_in_5F_POP_rDIv_16() {
    typedef Bit16u data_type;
    auto& destination = reg_di;
    //TODO do the actual operation
    return true;
}

/*
 POP
*/
inline bool CpuRunnerLLVM::handler_in_5F_POP_rDIv_32() {
    typedef Bit32u data_type;
    auto& destination = reg_edi;
    //TODO do the actual operation
    return true;
}

/*
 PUSHA
*/
inline bool CpuRunnerLLVM::handler_in_60_PUSHA() {
    return true;
}

/*
 POPA
*/
inline bool CpuRunnerLLVM::handler_in_61_POPA() {
    return true;
}

/*
 BOUND
*/
inline bool CpuRunnerLLVM::handler_in_62_BOUND_Ma() {
    if (Is32BitOperandMode()) {
        return handler_in_62_BOUND_Ma_32();
    } else {
        return handler_in_62_BOUND_Ma_16();
    }
}

/*
 BOUND
*/
inline bool CpuRunnerLLVM::handler_in_62_BOUND_Ma_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto source = GetRmMem<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 BOUND
*/
inline bool CpuRunnerLLVM::handler_in_62_BOUND_Ma_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto source = GetRmMem<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 ARPL
*/
inline bool CpuRunnerLLVM::handler_in_63_ARPL_Gw() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto source = GetRmReg<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 PUSH
*/
inline bool CpuRunnerLLVM::handler_in_68_PUSH_Ivs() {
    if (Is32BitOperandMode()) {
        return handler_in_68_PUSH_Ivs_32();
    } else {
        return handler_in_68_PUSH_Ivs_16();
    }
}

/*
 PUSH
*/
inline bool CpuRunnerLLVM::handler_in_68_PUSH_Ivs_16() {
    typedef Bit16u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 PUSH
*/
inline bool CpuRunnerLLVM::handler_in_68_PUSH_Ivs_32() {
    typedef Bit32u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 IMUL
*/
inline bool CpuRunnerLLVM::handler_in_69_IMUL_Gvqp_Ivds() {
    if (Is32BitOperandMode()) {
        return handler_in_69_IMUL_Gvqp_Ivds_32();
    } else {
        return handler_in_69_IMUL_Gvqp_Ivds_16();
    }
}

/*
 IMUL
*/
inline bool CpuRunnerLLVM::handler_in_69_IMUL_Gvqp_Ivds_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmReg<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 IMUL
*/
inline bool CpuRunnerLLVM::handler_in_69_IMUL_Gvqp_Ivds_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmReg<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 PUSH
*/
inline bool CpuRunnerLLVM::handler_in_6A_PUSH_Ibss() {
    typedef Bit8u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 IMUL
*/
inline bool CpuRunnerLLVM::handler_in_6B_IMUL_Gvqp_Ibs() {
    if (Is32BitOperandMode()) {
        return handler_in_6B_IMUL_Gvqp_Ibs_32();
    } else {
        return handler_in_6B_IMUL_Gvqp_Ibs_16();
    }
}

/*
 IMUL
*/
inline bool CpuRunnerLLVM::handler_in_6B_IMUL_Gvqp_Ibs_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmReg<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 IMUL
*/
inline bool CpuRunnerLLVM::handler_in_6B_IMUL_Gvqp_Ibs_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmReg<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 INS
*/
inline bool CpuRunnerLLVM::handler_in_6C_INS_Yb_DXw() {
    typedef Bit8u data_type;
    auto destination = GetMemoryReference<data_type>(reg_bh);
    auto source = reg_dl;
    //TODO do the actual operation
    return true;
}

/*
 INS
*/
inline bool CpuRunnerLLVM::handler_in_6D_INS_Ywo_DXw() {
    if (Is32BitOperandMode()) {
        return handler_in_6D_INS_Ywo_DXw_32();
    } else {
        return handler_in_6D_INS_Ywo_DXw_16();
    }
}

/*
 INS
*/
inline bool CpuRunnerLLVM::handler_in_6D_INS_Ywo_DXw_16() {
    typedef Bit16u data_type;
    auto destination = GetMemoryReference<data_type>(reg_di);
    auto source = reg_dx;
    //TODO do the actual operation
    return true;
}

/*
 INS
*/
inline bool CpuRunnerLLVM::handler_in_6D_INS_Ywo_DXw_32() {
    typedef Bit16u data_type;
    auto source = reg_dx;
    //TODO do the actual operation
    return true;
}

/*
 OUTS
*/
inline bool CpuRunnerLLVM::handler_in_6E_OUTS_DXw_Xb() {
    typedef Bit16u data_type;
    auto& destination = reg_dx;
    auto source = GetMemoryReference<data_type>(reg_si);
    //TODO do the actual operation
    return true;
}

/*
 OUTS
*/
inline bool CpuRunnerLLVM::handler_in_6F_OUTS_DXw_Xwo() {
    if (Is32BitOperandMode()) {
        return handler_in_6F_OUTS_DXw_Xwo_32();
    } else {
        return handler_in_6F_OUTS_DXw_Xwo_16();
    }
}

/*
 OUTS
*/
inline bool CpuRunnerLLVM::handler_in_6F_OUTS_DXw_Xwo_16() {
    typedef Bit16u data_type;
    auto& destination = reg_dx;
    auto source = GetMemoryReference<data_type>(reg_si);
    //TODO do the actual operation
    return true;
}

/*
 OUTS
*/
inline bool CpuRunnerLLVM::handler_in_6F_OUTS_DXw_Xwo_32() {
    typedef Bit16u data_type;
    auto& destination = reg_dx;
    //TODO do the actual operation
    return true;
}

/*
 JO
*/
inline bool CpuRunnerLLVM::handler_in_70_JO_Jbs() {
    typedef Bit8u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 JNO
*/
inline bool CpuRunnerLLVM::handler_in_71_JNO_Jbs() {
    typedef Bit8u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 JB
*/
inline bool CpuRunnerLLVM::handler_in_72_JB_Jbs() {
    typedef Bit8u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 JNB
*/
inline bool CpuRunnerLLVM::handler_in_73_JNB_Jbs() {
    typedef Bit8u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 JZ
*/
inline bool CpuRunnerLLVM::handler_in_74_JZ_Jbs() {
    typedef Bit8u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 JNZ
*/
inline bool CpuRunnerLLVM::handler_in_75_JNZ_Jbs() {
    typedef Bit8u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 JBE
*/
inline bool CpuRunnerLLVM::handler_in_76_JBE_Jbs() {
    typedef Bit8u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 JNBE
*/
inline bool CpuRunnerLLVM::handler_in_77_JNBE_Jbs() {
    typedef Bit8u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 JS
*/
inline bool CpuRunnerLLVM::handler_in_78_JS_Jbs() {
    typedef Bit8u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 JNS
*/
inline bool CpuRunnerLLVM::handler_in_79_JNS_Jbs() {
    typedef Bit8u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 JP
*/
inline bool CpuRunnerLLVM::handler_in_7A_JP_Jbs() {
    typedef Bit8u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 JNP
*/
inline bool CpuRunnerLLVM::handler_in_7B_JNP_Jbs() {
    typedef Bit8u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 JL
*/
inline bool CpuRunnerLLVM::handler_in_7C_JL_Jbs() {
    typedef Bit8u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 JNL
*/
inline bool CpuRunnerLLVM::handler_in_7D_JNL_Jbs() {
    typedef Bit8u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 JLE
*/
inline bool CpuRunnerLLVM::handler_in_7E_JLE_Jbs() {
    typedef Bit8u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 JNLE
*/
inline bool CpuRunnerLLVM::handler_in_7F_JNLE_Jbs() {
    typedef Bit8u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 ADD
*/
inline bool CpuRunnerLLVM::handler_in_81_00_ADD_Evqp_Ivds() {
    if (Is32BitOperandMode()) {
        return handler_in_81_00_ADD_Evqp_Ivds_32();
    } else {
        return handler_in_81_00_ADD_Evqp_Ivds_16();
    }
}

/*
 ADD
*/
inline bool CpuRunnerLLVM::handler_in_81_00_ADD_Evqp_Ivds_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 ADD
*/
inline bool CpuRunnerLLVM::handler_in_81_00_ADD_Evqp_Ivds_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 OR
*/
inline bool CpuRunnerLLVM::handler_in_81_01_OR_Evqp_Ivds() {
    if (Is32BitOperandMode()) {
        return handler_in_81_01_OR_Evqp_Ivds_32();
    } else {
        return handler_in_81_01_OR_Evqp_Ivds_16();
    }
}

/*
 OR
*/
inline bool CpuRunnerLLVM::handler_in_81_01_OR_Evqp_Ivds_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 OR
*/
inline bool CpuRunnerLLVM::handler_in_81_01_OR_Evqp_Ivds_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 ADC
*/
inline bool CpuRunnerLLVM::handler_in_81_02_ADC_Evqp_Ivds() {
    if (Is32BitOperandMode()) {
        return handler_in_81_02_ADC_Evqp_Ivds_32();
    } else {
        return handler_in_81_02_ADC_Evqp_Ivds_16();
    }
}

/*
 ADC
*/
inline bool CpuRunnerLLVM::handler_in_81_02_ADC_Evqp_Ivds_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 ADC
*/
inline bool CpuRunnerLLVM::handler_in_81_02_ADC_Evqp_Ivds_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 SBB
*/
inline bool CpuRunnerLLVM::handler_in_81_03_SBB_Evqp_Ivds() {
    if (Is32BitOperandMode()) {
        return handler_in_81_03_SBB_Evqp_Ivds_32();
    } else {
        return handler_in_81_03_SBB_Evqp_Ivds_16();
    }
}

/*
 SBB
*/
inline bool CpuRunnerLLVM::handler_in_81_03_SBB_Evqp_Ivds_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 SBB
*/
inline bool CpuRunnerLLVM::handler_in_81_03_SBB_Evqp_Ivds_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 AND
*/
inline bool CpuRunnerLLVM::handler_in_81_04_AND_Evqp_Ivds() {
    if (Is32BitOperandMode()) {
        return handler_in_81_04_AND_Evqp_Ivds_32();
    } else {
        return handler_in_81_04_AND_Evqp_Ivds_16();
    }
}

/*
 AND
*/
inline bool CpuRunnerLLVM::handler_in_81_04_AND_Evqp_Ivds_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 AND
*/
inline bool CpuRunnerLLVM::handler_in_81_04_AND_Evqp_Ivds_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 SUB
*/
inline bool CpuRunnerLLVM::handler_in_81_05_SUB_Evqp_Ivds() {
    if (Is32BitOperandMode()) {
        return handler_in_81_05_SUB_Evqp_Ivds_32();
    } else {
        return handler_in_81_05_SUB_Evqp_Ivds_16();
    }
}

/*
 SUB
*/
inline bool CpuRunnerLLVM::handler_in_81_05_SUB_Evqp_Ivds_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 SUB
*/
inline bool CpuRunnerLLVM::handler_in_81_05_SUB_Evqp_Ivds_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 XOR
*/
inline bool CpuRunnerLLVM::handler_in_81_06_XOR_Evqp_Ivds() {
    if (Is32BitOperandMode()) {
        return handler_in_81_06_XOR_Evqp_Ivds_32();
    } else {
        return handler_in_81_06_XOR_Evqp_Ivds_16();
    }
}

/*
 XOR
*/
inline bool CpuRunnerLLVM::handler_in_81_06_XOR_Evqp_Ivds_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 XOR
*/
inline bool CpuRunnerLLVM::handler_in_81_06_XOR_Evqp_Ivds_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 CMP
*/
inline bool CpuRunnerLLVM::handler_in_81_07_CMP_Ivds() {
    if (Is32BitOperandMode()) {
        return handler_in_81_07_CMP_Ivds_32();
    } else {
        return handler_in_81_07_CMP_Ivds_16();
    }
}

/*
 CMP
*/
inline bool CpuRunnerLLVM::handler_in_81_07_CMP_Ivds_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 CMP
*/
inline bool CpuRunnerLLVM::handler_in_81_07_CMP_Ivds_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 ADD
*/
inline bool CpuRunnerLLVM::handler_in_82_00_ADD_Eb_Ib() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 OR
*/
inline bool CpuRunnerLLVM::handler_in_82_01_OR_Eb_Ib() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 ADC
*/
inline bool CpuRunnerLLVM::handler_in_82_02_ADC_Eb_Ib() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 SBB
*/
inline bool CpuRunnerLLVM::handler_in_82_03_SBB_Eb_Ib() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 AND
*/
inline bool CpuRunnerLLVM::handler_in_82_04_AND_Eb_Ib() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 SUB
*/
inline bool CpuRunnerLLVM::handler_in_82_05_SUB_Eb_Ib() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 XOR
*/
inline bool CpuRunnerLLVM::handler_in_82_06_XOR_Eb_Ib() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 CMP
*/
inline bool CpuRunnerLLVM::handler_in_82_07_CMP_Ib() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 ADD
*/
inline bool CpuRunnerLLVM::handler_in_83_00_ADD_Evqp_Ibs() {
    if (Is32BitOperandMode()) {
        return handler_in_83_00_ADD_Evqp_Ibs_32();
    } else {
        return handler_in_83_00_ADD_Evqp_Ibs_16();
    }
}

/*
 ADD
*/
inline bool CpuRunnerLLVM::handler_in_83_00_ADD_Evqp_Ibs_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 ADD
*/
inline bool CpuRunnerLLVM::handler_in_83_00_ADD_Evqp_Ibs_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 OR
*/
inline bool CpuRunnerLLVM::handler_in_83_01_OR_Evqp_Ibs() {
    if (Is32BitOperandMode()) {
        return handler_in_83_01_OR_Evqp_Ibs_32();
    } else {
        return handler_in_83_01_OR_Evqp_Ibs_16();
    }
}

/*
 OR
*/
inline bool CpuRunnerLLVM::handler_in_83_01_OR_Evqp_Ibs_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 OR
*/
inline bool CpuRunnerLLVM::handler_in_83_01_OR_Evqp_Ibs_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 ADC
*/
inline bool CpuRunnerLLVM::handler_in_83_02_ADC_Evqp_Ibs() {
    if (Is32BitOperandMode()) {
        return handler_in_83_02_ADC_Evqp_Ibs_32();
    } else {
        return handler_in_83_02_ADC_Evqp_Ibs_16();
    }
}

/*
 ADC
*/
inline bool CpuRunnerLLVM::handler_in_83_02_ADC_Evqp_Ibs_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 ADC
*/
inline bool CpuRunnerLLVM::handler_in_83_02_ADC_Evqp_Ibs_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 SBB
*/
inline bool CpuRunnerLLVM::handler_in_83_03_SBB_Evqp_Ibs() {
    if (Is32BitOperandMode()) {
        return handler_in_83_03_SBB_Evqp_Ibs_32();
    } else {
        return handler_in_83_03_SBB_Evqp_Ibs_16();
    }
}

/*
 SBB
*/
inline bool CpuRunnerLLVM::handler_in_83_03_SBB_Evqp_Ibs_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 SBB
*/
inline bool CpuRunnerLLVM::handler_in_83_03_SBB_Evqp_Ibs_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 AND
*/
inline bool CpuRunnerLLVM::handler_in_83_04_AND_Evqp_Ibs() {
    if (Is32BitOperandMode()) {
        return handler_in_83_04_AND_Evqp_Ibs_32();
    } else {
        return handler_in_83_04_AND_Evqp_Ibs_16();
    }
}

/*
 AND
*/
inline bool CpuRunnerLLVM::handler_in_83_04_AND_Evqp_Ibs_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 AND
*/
inline bool CpuRunnerLLVM::handler_in_83_04_AND_Evqp_Ibs_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 SUB
*/
inline bool CpuRunnerLLVM::handler_in_83_05_SUB_Evqp_Ibs() {
    if (Is32BitOperandMode()) {
        return handler_in_83_05_SUB_Evqp_Ibs_32();
    } else {
        return handler_in_83_05_SUB_Evqp_Ibs_16();
    }
}

/*
 SUB
*/
inline bool CpuRunnerLLVM::handler_in_83_05_SUB_Evqp_Ibs_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 SUB
*/
inline bool CpuRunnerLLVM::handler_in_83_05_SUB_Evqp_Ibs_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 XOR
*/
inline bool CpuRunnerLLVM::handler_in_83_06_XOR_Evqp_Ibs() {
    if (Is32BitOperandMode()) {
        return handler_in_83_06_XOR_Evqp_Ibs_32();
    } else {
        return handler_in_83_06_XOR_Evqp_Ibs_16();
    }
}

/*
 XOR
*/
inline bool CpuRunnerLLVM::handler_in_83_06_XOR_Evqp_Ibs_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 XOR
*/
inline bool CpuRunnerLLVM::handler_in_83_06_XOR_Evqp_Ibs_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 CMP
*/
inline bool CpuRunnerLLVM::handler_in_83_07_CMP_Ibs() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 TEST
*/
inline bool CpuRunnerLLVM::handler_in_84_TEST_Gb() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto source = GetRmReg<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 TEST
*/
inline bool CpuRunnerLLVM::handler_in_85_TEST_Gvqp() {
    if (Is32BitOperandMode()) {
        return handler_in_85_TEST_Gvqp_32();
    } else {
        return handler_in_85_TEST_Gvqp_16();
    }
}

/*
 TEST
*/
inline bool CpuRunnerLLVM::handler_in_85_TEST_Gvqp_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto source = GetRmReg<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 TEST
*/
inline bool CpuRunnerLLVM::handler_in_85_TEST_Gvqp_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto source = GetRmReg<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 XCHG
*/
inline bool CpuRunnerLLVM::handler_in_86_XCHG_Eb() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 XCHG
*/
inline bool CpuRunnerLLVM::handler_in_87_XCHG_Evqp() {
    if (Is32BitOperandMode()) {
        return handler_in_87_XCHG_Evqp_32();
    } else {
        return handler_in_87_XCHG_Evqp_16();
    }
}

/*
 XCHG
*/
inline bool CpuRunnerLLVM::handler_in_87_XCHG_Evqp_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 XCHG
*/
inline bool CpuRunnerLLVM::handler_in_87_XCHG_Evqp_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 MOV
*/
inline bool CpuRunnerLLVM::handler_in_88_MOV_Eb_Gb() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetRmReg<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 MOV
*/
inline bool CpuRunnerLLVM::handler_in_89_MOV_Evqp_Gvqp() {
    if (Is32BitOperandMode()) {
        return handler_in_89_MOV_Evqp_Gvqp_32();
    } else {
        return handler_in_89_MOV_Evqp_Gvqp_16();
    }
}

/*
 MOV
*/
inline bool CpuRunnerLLVM::handler_in_89_MOV_Evqp_Gvqp_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetRmReg<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 MOV
*/
inline bool CpuRunnerLLVM::handler_in_89_MOV_Evqp_Gvqp_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetRmReg<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 MOV
*/
inline bool CpuRunnerLLVM::handler_in_8A_MOV_Gb_Eb() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto destination = GetRmReg<data_type>(rmmod);
    auto source = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 MOV
*/
inline bool CpuRunnerLLVM::handler_in_8B_MOV_Gvqp_Evqp() {
    if (Is32BitOperandMode()) {
        return handler_in_8B_MOV_Gvqp_Evqp_32();
    } else {
        return handler_in_8B_MOV_Gvqp_Evqp_16();
    }
}

/*
 MOV
*/
inline bool CpuRunnerLLVM::handler_in_8B_MOV_Gvqp_Evqp_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmReg<data_type>(rmmod);
    auto source = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 MOV
*/
inline bool CpuRunnerLLVM::handler_in_8B_MOV_Gvqp_Evqp_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmReg<data_type>(rmmod);
    auto source = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 MOV
*/
inline bool CpuRunnerLLVM::handler_in_8C_MOV_Mw_Sw() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmMem<data_type>(rmmod);
    auto source = rmmod & 0x07u;
    //TODO do the actual operation
    return true;
}

/*
 LEA
*/
inline bool CpuRunnerLLVM::handler_in_8D_LEA_Gvqp() {
    if (Is32BitOperandMode()) {
        return handler_in_8D_LEA_Gvqp_32();
    } else {
        return handler_in_8D_LEA_Gvqp_16();
    }
}

/*
 LEA
*/
inline bool CpuRunnerLLVM::handler_in_8D_LEA_Gvqp_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmReg<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 LEA
*/
inline bool CpuRunnerLLVM::handler_in_8D_LEA_Gvqp_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmReg<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 MOV
*/
inline bool CpuRunnerLLVM::handler_in_8E_MOV_Sw_Ew() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = rmmod & 0x07u;
    auto source = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 POP
*/
inline bool CpuRunnerLLVM::handler_in_8F_00_POP_Ev() {
    if (Is32BitOperandMode()) {
        return handler_in_8F_00_POP_Ev_32();
    } else {
        return handler_in_8F_00_POP_Ev_16();
    }
}

/*
 POP
*/
inline bool CpuRunnerLLVM::handler_in_8F_00_POP_Ev_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 POP
*/
inline bool CpuRunnerLLVM::handler_in_8F_00_POP_Ev_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 XCHG
*/
inline bool CpuRunnerLLVM::handler_in_90_XCHG_rAXvqp() {
    if (Is32BitOperandMode()) {
        return handler_in_90_XCHG_rAXvqp_32();
    } else {
        return handler_in_90_XCHG_rAXvqp_16();
    }
}

/*
 XCHG
*/
inline bool CpuRunnerLLVM::handler_in_90_XCHG_rAXvqp_16() {
    typedef Bit16u data_type;
    auto& destination = reg_ax;
    //TODO do the actual operation
    return true;
}

/*
 XCHG
*/
inline bool CpuRunnerLLVM::handler_in_90_XCHG_rAXvqp_32() {
    typedef Bit32u data_type;
    auto& destination = reg_eax;
    //TODO do the actual operation
    return true;
}

/*
 XCHG
*/
inline bool CpuRunnerLLVM::handler_in_91_XCHG_rAXvqp() {
    if (Is32BitOperandMode()) {
        return handler_in_91_XCHG_rAXvqp_32();
    } else {
        return handler_in_91_XCHG_rAXvqp_16();
    }
}

/*
 XCHG
*/
inline bool CpuRunnerLLVM::handler_in_91_XCHG_rAXvqp_16() {
    typedef Bit16u data_type;
    auto& destination = reg_ax;
    //TODO do the actual operation
    return true;
}

/*
 XCHG
*/
inline bool CpuRunnerLLVM::handler_in_91_XCHG_rAXvqp_32() {
    typedef Bit32u data_type;
    auto& destination = reg_eax;
    //TODO do the actual operation
    return true;
}

/*
 XCHG
*/
inline bool CpuRunnerLLVM::handler_in_92_XCHG_rAXvqp() {
    if (Is32BitOperandMode()) {
        return handler_in_92_XCHG_rAXvqp_32();
    } else {
        return handler_in_92_XCHG_rAXvqp_16();
    }
}

/*
 XCHG
*/
inline bool CpuRunnerLLVM::handler_in_92_XCHG_rAXvqp_16() {
    typedef Bit16u data_type;
    auto& destination = reg_ax;
    //TODO do the actual operation
    return true;
}

/*
 XCHG
*/
inline bool CpuRunnerLLVM::handler_in_92_XCHG_rAXvqp_32() {
    typedef Bit32u data_type;
    auto& destination = reg_eax;
    //TODO do the actual operation
    return true;
}

/*
 XCHG
*/
inline bool CpuRunnerLLVM::handler_in_93_XCHG_rAXvqp() {
    if (Is32BitOperandMode()) {
        return handler_in_93_XCHG_rAXvqp_32();
    } else {
        return handler_in_93_XCHG_rAXvqp_16();
    }
}

/*
 XCHG
*/
inline bool CpuRunnerLLVM::handler_in_93_XCHG_rAXvqp_16() {
    typedef Bit16u data_type;
    auto& destination = reg_ax;
    //TODO do the actual operation
    return true;
}

/*
 XCHG
*/
inline bool CpuRunnerLLVM::handler_in_93_XCHG_rAXvqp_32() {
    typedef Bit32u data_type;
    auto& destination = reg_eax;
    //TODO do the actual operation
    return true;
}

/*
 XCHG
*/
inline bool CpuRunnerLLVM::handler_in_94_XCHG_rAXvqp() {
    if (Is32BitOperandMode()) {
        return handler_in_94_XCHG_rAXvqp_32();
    } else {
        return handler_in_94_XCHG_rAXvqp_16();
    }
}

/*
 XCHG
*/
inline bool CpuRunnerLLVM::handler_in_94_XCHG_rAXvqp_16() {
    typedef Bit16u data_type;
    auto& destination = reg_ax;
    //TODO do the actual operation
    return true;
}

/*
 XCHG
*/
inline bool CpuRunnerLLVM::handler_in_94_XCHG_rAXvqp_32() {
    typedef Bit32u data_type;
    auto& destination = reg_eax;
    //TODO do the actual operation
    return true;
}

/*
 XCHG
*/
inline bool CpuRunnerLLVM::handler_in_95_XCHG_rAXvqp() {
    if (Is32BitOperandMode()) {
        return handler_in_95_XCHG_rAXvqp_32();
    } else {
        return handler_in_95_XCHG_rAXvqp_16();
    }
}

/*
 XCHG
*/
inline bool CpuRunnerLLVM::handler_in_95_XCHG_rAXvqp_16() {
    typedef Bit16u data_type;
    auto& destination = reg_ax;
    //TODO do the actual operation
    return true;
}

/*
 XCHG
*/
inline bool CpuRunnerLLVM::handler_in_95_XCHG_rAXvqp_32() {
    typedef Bit32u data_type;
    auto& destination = reg_eax;
    //TODO do the actual operation
    return true;
}

/*
 XCHG
*/
inline bool CpuRunnerLLVM::handler_in_96_XCHG_rAXvqp() {
    if (Is32BitOperandMode()) {
        return handler_in_96_XCHG_rAXvqp_32();
    } else {
        return handler_in_96_XCHG_rAXvqp_16();
    }
}

/*
 XCHG
*/
inline bool CpuRunnerLLVM::handler_in_96_XCHG_rAXvqp_16() {
    typedef Bit16u data_type;
    auto& destination = reg_ax;
    //TODO do the actual operation
    return true;
}

/*
 XCHG
*/
inline bool CpuRunnerLLVM::handler_in_96_XCHG_rAXvqp_32() {
    typedef Bit32u data_type;
    auto& destination = reg_eax;
    //TODO do the actual operation
    return true;
}

/*
 XCHG
*/
inline bool CpuRunnerLLVM::handler_in_97_XCHG_rAXvqp() {
    if (Is32BitOperandMode()) {
        return handler_in_97_XCHG_rAXvqp_32();
    } else {
        return handler_in_97_XCHG_rAXvqp_16();
    }
}

/*
 XCHG
*/
inline bool CpuRunnerLLVM::handler_in_97_XCHG_rAXvqp_16() {
    typedef Bit16u data_type;
    auto& destination = reg_ax;
    //TODO do the actual operation
    return true;
}

/*
 XCHG
*/
inline bool CpuRunnerLLVM::handler_in_97_XCHG_rAXvqp_32() {
    typedef Bit32u data_type;
    auto& destination = reg_eax;
    //TODO do the actual operation
    return true;
}

/*
 CBW
*/
inline bool CpuRunnerLLVM::handler_in_98_CBW() {
    return true;
}

/*
 CWDE
*/
inline bool CpuRunnerLLVM::handler_in_98_CWDE() {
    return true;
}

/*
 CDQ
*/
inline bool CpuRunnerLLVM::handler_in_99_CDQ() {
    return true;
}

/*
 CWD
*/
inline bool CpuRunnerLLVM::handler_in_99_CWD() {
    return true;
}

/*
 CALLF
*/
inline bool CpuRunnerLLVM::handler_in_9A_CALLF_Ap() {
    if (Is32BitOperandMode()) {
        return handler_in_9A_CALLF_Ap_32();
    } else {
        return handler_in_9A_CALLF_Ap_16();
    }
}

/*
 CALLF
*/
inline bool CpuRunnerLLVM::handler_in_9A_CALLF_Ap_16() {
    typedef Bit16u data_type;
    auto source = GetMemoryReference<data_type>(GetImmediate<Bit16u>() + GetImmediate<data_type>());
    //TODO do the actual operation
    return true;
}

/*
 CALLF
*/
inline bool CpuRunnerLLVM::handler_in_9A_CALLF_Ap_32() {
    typedef Bit32u data_type;
    auto source = GetMemoryReference<data_type>(GetImmediate<Bit16u>() + GetImmediate<data_type>());
    //TODO do the actual operation
    return true;
}

/*
 FWAIT
*/
inline bool CpuRunnerLLVM::handler_in_9B_FWAIT() {
    return true;
}

/*
 PUSHF
*/
inline bool CpuRunnerLLVM::handler_in_9C_PUSHF() {
    return true;
}

/*
 POPF
*/
inline bool CpuRunnerLLVM::handler_in_9D_POPF() {
    return true;
}

/*
 SAHF
*/
inline bool CpuRunnerLLVM::handler_in_9E_SAHF() {
    return true;
}

/*
 LAHF
*/
inline bool CpuRunnerLLVM::handler_in_9F_LAHF() {
    return true;
}

/*
 MOV
*/
inline bool CpuRunnerLLVM::handler_in_A0_MOV_ALb_Ob() {
    typedef Bit8u data_type;
    auto& destination = reg_al;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 MOV
*/
inline bool CpuRunnerLLVM::handler_in_A1_MOV_rAXvqp_Ovqp() {
    if (Is32BitOperandMode()) {
        return handler_in_A1_MOV_rAXvqp_Ovqp_32();
    } else {
        return handler_in_A1_MOV_rAXvqp_Ovqp_16();
    }
}

/*
 MOV
*/
inline bool CpuRunnerLLVM::handler_in_A1_MOV_rAXvqp_Ovqp_16() {
    typedef Bit16u data_type;
    auto& destination = reg_ax;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 MOV
*/
inline bool CpuRunnerLLVM::handler_in_A1_MOV_rAXvqp_Ovqp_32() {
    typedef Bit32u data_type;
    auto& destination = reg_eax;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 MOV
*/
inline bool CpuRunnerLLVM::handler_in_A2_MOV_Ob_ALb() {
    typedef Bit8u data_type;
    auto destination = GetImmediate<data_type>();
    auto source = reg_al;
    //TODO do the actual operation
    return true;
}

/*
 MOV
*/
inline bool CpuRunnerLLVM::handler_in_A3_MOV_Ovqp_rAXvqp() {
    if (Is32BitOperandMode()) {
        return handler_in_A3_MOV_Ovqp_rAXvqp_32();
    } else {
        return handler_in_A3_MOV_Ovqp_rAXvqp_16();
    }
}

/*
 MOV
*/
inline bool CpuRunnerLLVM::handler_in_A3_MOV_Ovqp_rAXvqp_16() {
    typedef Bit16u data_type;
    auto destination = GetImmediate<data_type>();
    auto source = reg_ax;
    //TODO do the actual operation
    return true;
}

/*
 MOV
*/
inline bool CpuRunnerLLVM::handler_in_A3_MOV_Ovqp_rAXvqp_32() {
    typedef Bit32u data_type;
    auto destination = GetImmediate<data_type>();
    auto source = reg_eax;
    //TODO do the actual operation
    return true;
}

/*
 MOVS
*/
inline bool CpuRunnerLLVM::handler_in_A4_MOVS_Yb_Xb() {
    typedef Bit8u data_type;
    auto destination = GetMemoryReference<data_type>(reg_bh);
    auto source = GetMemoryReference<data_type>(reg_dh);
    //TODO do the actual operation
    return true;
}

/*
 MOVS
*/
inline bool CpuRunnerLLVM::handler_in_A5_MOVS_Ywo_Xwo() {
    typedef Bit16u data_type;
    auto destination = GetMemoryReference<data_type>(reg_di);
    auto source = GetMemoryReference<data_type>(reg_si);
    //TODO do the actual operation
    return true;
}

/*
 CMPS
*/
inline bool CpuRunnerLLVM::handler_in_A6_CMPS_Xb() {
    typedef Bit8u data_type;
    auto source = GetMemoryReference<data_type>(reg_dh);
    //TODO do the actual operation
    return true;
}

/*
 CMPS
*/
inline bool CpuRunnerLLVM::handler_in_A7_CMPS_Xwo() {
    typedef Bit16u data_type;
    auto source = GetMemoryReference<data_type>(reg_si);
    //TODO do the actual operation
    return true;
}

/*
 TEST
*/
inline bool CpuRunnerLLVM::handler_in_A8_TEST_Ib() {
    typedef Bit8u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 TEST
*/
inline bool CpuRunnerLLVM::handler_in_A9_TEST_Ivds() {
    if (Is32BitOperandMode()) {
        return handler_in_A9_TEST_Ivds_32();
    } else {
        return handler_in_A9_TEST_Ivds_16();
    }
}

/*
 TEST
*/
inline bool CpuRunnerLLVM::handler_in_A9_TEST_Ivds_16() {
    typedef Bit16u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 TEST
*/
inline bool CpuRunnerLLVM::handler_in_A9_TEST_Ivds_32() {
    typedef Bit32u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 STOS
*/
inline bool CpuRunnerLLVM::handler_in_AA_STOS_Yb() {
    typedef Bit8u data_type;
    auto destination = GetMemoryReference<data_type>(reg_bh);
    //TODO do the actual operation
    return true;
}

/*
 STOS
*/
inline bool CpuRunnerLLVM::handler_in_AB_STOS_Ywo() {
    typedef Bit16u data_type;
    auto destination = GetMemoryReference<data_type>(reg_di);
    //TODO do the actual operation
    return true;
}

/*
 LODS
*/
inline bool CpuRunnerLLVM::handler_in_AC_LODS_Xb() {
    typedef Bit8u data_type;
    auto source = GetMemoryReference<data_type>(reg_dh);
    //TODO do the actual operation
    return true;
}

/*
 LODS
*/
inline bool CpuRunnerLLVM::handler_in_AD_LODS_Xwo() {
    typedef Bit16u data_type;
    auto source = GetMemoryReference<data_type>(reg_si);
    //TODO do the actual operation
    return true;
}

/*
 SCAS
*/
inline bool CpuRunnerLLVM::handler_in_AE_SCAS_Yb() {
    typedef Bit8u data_type;
    auto source = GetMemoryReference<data_type>(reg_bh);
    //TODO do the actual operation
    return true;
}

/*
 SCAS
*/
inline bool CpuRunnerLLVM::handler_in_AF_SCAS_Ywo() {
    typedef Bit16u data_type;
    auto source = GetMemoryReference<data_type>(reg_di);
    //TODO do the actual operation
    return true;
}

/*
 MOV
*/
inline bool CpuRunnerLLVM::handler_in_B0_MOV_ALb_Ib() {
    typedef Bit8u data_type;
    auto& destination = reg_al;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 MOV
*/
inline bool CpuRunnerLLVM::handler_in_B1_MOV_CLb_Ib() {
    typedef Bit8u data_type;
    auto& destination = reg_cl;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 MOV
*/
inline bool CpuRunnerLLVM::handler_in_B2_MOV_DLb_Ib() {
    typedef Bit8u data_type;
    auto& destination = reg_dl;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 MOV
*/
inline bool CpuRunnerLLVM::handler_in_B4_MOV_AHb_Ib() {
    typedef Bit8u data_type;
    auto& destination = reg_ah;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 MOV
*/
inline bool CpuRunnerLLVM::handler_in_B5_MOV_CHb_Ib() {
    typedef Bit8u data_type;
    auto& destination = reg_ch;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 MOV
*/
inline bool CpuRunnerLLVM::handler_in_B6_MOV_DHb_Ib() {
    typedef Bit8u data_type;
    auto& destination = reg_dh;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 MOV
*/
inline bool CpuRunnerLLVM::handler_in_B7_MOV_BHb_Ib() {
    typedef Bit8u data_type;
    auto& destination = reg_bh;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 MOV
*/
inline bool CpuRunnerLLVM::handler_in_B8_MOV_rAXvqp_Ivqp() {
    if (Is32BitOperandMode()) {
        return handler_in_B8_MOV_rAXvqp_Ivqp_32();
    } else {
        return handler_in_B8_MOV_rAXvqp_Ivqp_16();
    }
}

/*
 MOV
*/
inline bool CpuRunnerLLVM::handler_in_B8_MOV_rAXvqp_Ivqp_16() {
    typedef Bit16u data_type;
    auto& destination = reg_ax;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 MOV
*/
inline bool CpuRunnerLLVM::handler_in_B8_MOV_rAXvqp_Ivqp_32() {
    typedef Bit32u data_type;
    auto& destination = reg_eax;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 MOV
*/
inline bool CpuRunnerLLVM::handler_in_B9_MOV_rCXvqp_Ivqp() {
    if (Is32BitOperandMode()) {
        return handler_in_B9_MOV_rCXvqp_Ivqp_32();
    } else {
        return handler_in_B9_MOV_rCXvqp_Ivqp_16();
    }
}

/*
 MOV
*/
inline bool CpuRunnerLLVM::handler_in_B9_MOV_rCXvqp_Ivqp_16() {
    typedef Bit16u data_type;
    auto& destination = reg_cx;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 MOV
*/
inline bool CpuRunnerLLVM::handler_in_B9_MOV_rCXvqp_Ivqp_32() {
    typedef Bit32u data_type;
    auto& destination = reg_ecx;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 MOV
*/
inline bool CpuRunnerLLVM::handler_in_BA_MOV_rDXvqp_Ivqp() {
    if (Is32BitOperandMode()) {
        return handler_in_BA_MOV_rDXvqp_Ivqp_32();
    } else {
        return handler_in_BA_MOV_rDXvqp_Ivqp_16();
    }
}

/*
 MOV
*/
inline bool CpuRunnerLLVM::handler_in_BA_MOV_rDXvqp_Ivqp_16() {
    typedef Bit16u data_type;
    auto& destination = reg_dx;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 MOV
*/
inline bool CpuRunnerLLVM::handler_in_BA_MOV_rDXvqp_Ivqp_32() {
    typedef Bit32u data_type;
    auto& destination = reg_edx;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 MOV
*/
inline bool CpuRunnerLLVM::handler_in_BB_MOV_rBXvqp_Ivqp() {
    if (Is32BitOperandMode()) {
        return handler_in_BB_MOV_rBXvqp_Ivqp_32();
    } else {
        return handler_in_BB_MOV_rBXvqp_Ivqp_16();
    }
}

/*
 MOV
*/
inline bool CpuRunnerLLVM::handler_in_BB_MOV_rBXvqp_Ivqp_16() {
    typedef Bit16u data_type;
    auto& destination = reg_bx;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 MOV
*/
inline bool CpuRunnerLLVM::handler_in_BB_MOV_rBXvqp_Ivqp_32() {
    typedef Bit32u data_type;
    auto& destination = reg_ebx;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 MOV
*/
inline bool CpuRunnerLLVM::handler_in_BC_MOV_rSPvqp_Ivqp() {
    if (Is32BitOperandMode()) {
        return handler_in_BC_MOV_rSPvqp_Ivqp_32();
    } else {
        return handler_in_BC_MOV_rSPvqp_Ivqp_16();
    }
}

/*
 MOV
*/
inline bool CpuRunnerLLVM::handler_in_BC_MOV_rSPvqp_Ivqp_16() {
    typedef Bit16u data_type;
    auto& destination = reg_sp;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 MOV
*/
inline bool CpuRunnerLLVM::handler_in_BC_MOV_rSPvqp_Ivqp_32() {
    typedef Bit32u data_type;
    auto& destination = reg_esp;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 MOV
*/
inline bool CpuRunnerLLVM::handler_in_BD_MOV_rBPvqp_Ivqp() {
    if (Is32BitOperandMode()) {
        return handler_in_BD_MOV_rBPvqp_Ivqp_32();
    } else {
        return handler_in_BD_MOV_rBPvqp_Ivqp_16();
    }
}

/*
 MOV
*/
inline bool CpuRunnerLLVM::handler_in_BD_MOV_rBPvqp_Ivqp_16() {
    typedef Bit16u data_type;
    auto& destination = reg_bp;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 MOV
*/
inline bool CpuRunnerLLVM::handler_in_BD_MOV_rBPvqp_Ivqp_32() {
    typedef Bit32u data_type;
    auto& destination = reg_ebp;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 MOV
*/
inline bool CpuRunnerLLVM::handler_in_BE_MOV_rSIvqp_Ivqp() {
    if (Is32BitOperandMode()) {
        return handler_in_BE_MOV_rSIvqp_Ivqp_32();
    } else {
        return handler_in_BE_MOV_rSIvqp_Ivqp_16();
    }
}

/*
 MOV
*/
inline bool CpuRunnerLLVM::handler_in_BE_MOV_rSIvqp_Ivqp_16() {
    typedef Bit16u data_type;
    auto& destination = reg_si;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 MOV
*/
inline bool CpuRunnerLLVM::handler_in_BE_MOV_rSIvqp_Ivqp_32() {
    typedef Bit32u data_type;
    auto& destination = reg_esi;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 MOV
*/
inline bool CpuRunnerLLVM::handler_in_BF_MOV_rDIvqp_Ivqp() {
    if (Is32BitOperandMode()) {
        return handler_in_BF_MOV_rDIvqp_Ivqp_32();
    } else {
        return handler_in_BF_MOV_rDIvqp_Ivqp_16();
    }
}

/*
 MOV
*/
inline bool CpuRunnerLLVM::handler_in_BF_MOV_rDIvqp_Ivqp_16() {
    typedef Bit16u data_type;
    auto& destination = reg_di;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 MOV
*/
inline bool CpuRunnerLLVM::handler_in_BF_MOV_rDIvqp_Ivqp_32() {
    typedef Bit32u data_type;
    auto& destination = reg_edi;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 ROL
*/
inline bool CpuRunnerLLVM::handler_in_C0_00_ROL_Eb_Ib() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 ROR
*/
inline bool CpuRunnerLLVM::handler_in_C0_01_ROR_Eb_Ib() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 RCL
*/
inline bool CpuRunnerLLVM::handler_in_C0_02_RCL_Eb_Ib() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 RCR
*/
inline bool CpuRunnerLLVM::handler_in_C0_03_RCR_Eb_Ib() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 SHL
*/
inline bool CpuRunnerLLVM::handler_in_C0_04_SHL_Eb_Ib() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 SHR
*/
inline bool CpuRunnerLLVM::handler_in_C0_05_SHR_Eb_Ib() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 SAL
*/
inline bool CpuRunnerLLVM::handler_in_C0_06_SAL_Eb_Ib() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 SAR
*/
inline bool CpuRunnerLLVM::handler_in_C0_07_SAR_Eb_Ib() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 ROL
*/
inline bool CpuRunnerLLVM::handler_in_C1_00_ROL_Evqp_Ib() {
    if (Is32BitOperandMode()) {
        return handler_in_C1_00_ROL_Evqp_Ib_32();
    } else {
        return handler_in_C1_00_ROL_Evqp_Ib_16();
    }
}

/*
 ROL
*/
inline bool CpuRunnerLLVM::handler_in_C1_00_ROL_Evqp_Ib_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 ROL
*/
inline bool CpuRunnerLLVM::handler_in_C1_00_ROL_Evqp_Ib_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 ROR
*/
inline bool CpuRunnerLLVM::handler_in_C1_01_ROR_Evqp_Ib() {
    if (Is32BitOperandMode()) {
        return handler_in_C1_01_ROR_Evqp_Ib_32();
    } else {
        return handler_in_C1_01_ROR_Evqp_Ib_16();
    }
}

/*
 ROR
*/
inline bool CpuRunnerLLVM::handler_in_C1_01_ROR_Evqp_Ib_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 ROR
*/
inline bool CpuRunnerLLVM::handler_in_C1_01_ROR_Evqp_Ib_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 RCL
*/
inline bool CpuRunnerLLVM::handler_in_C1_02_RCL_Evqp_Ib() {
    if (Is32BitOperandMode()) {
        return handler_in_C1_02_RCL_Evqp_Ib_32();
    } else {
        return handler_in_C1_02_RCL_Evqp_Ib_16();
    }
}

/*
 RCL
*/
inline bool CpuRunnerLLVM::handler_in_C1_02_RCL_Evqp_Ib_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 RCL
*/
inline bool CpuRunnerLLVM::handler_in_C1_02_RCL_Evqp_Ib_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 RCR
*/
inline bool CpuRunnerLLVM::handler_in_C1_03_RCR_Evqp_Ib() {
    if (Is32BitOperandMode()) {
        return handler_in_C1_03_RCR_Evqp_Ib_32();
    } else {
        return handler_in_C1_03_RCR_Evqp_Ib_16();
    }
}

/*
 RCR
*/
inline bool CpuRunnerLLVM::handler_in_C1_03_RCR_Evqp_Ib_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 RCR
*/
inline bool CpuRunnerLLVM::handler_in_C1_03_RCR_Evqp_Ib_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 SHL
*/
inline bool CpuRunnerLLVM::handler_in_C1_04_SHL_Evqp_Ib() {
    if (Is32BitOperandMode()) {
        return handler_in_C1_04_SHL_Evqp_Ib_32();
    } else {
        return handler_in_C1_04_SHL_Evqp_Ib_16();
    }
}

/*
 SHL
*/
inline bool CpuRunnerLLVM::handler_in_C1_04_SHL_Evqp_Ib_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 SHL
*/
inline bool CpuRunnerLLVM::handler_in_C1_04_SHL_Evqp_Ib_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 SHR
*/
inline bool CpuRunnerLLVM::handler_in_C1_05_SHR_Evqp_Ib() {
    if (Is32BitOperandMode()) {
        return handler_in_C1_05_SHR_Evqp_Ib_32();
    } else {
        return handler_in_C1_05_SHR_Evqp_Ib_16();
    }
}

/*
 SHR
*/
inline bool CpuRunnerLLVM::handler_in_C1_05_SHR_Evqp_Ib_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 SHR
*/
inline bool CpuRunnerLLVM::handler_in_C1_05_SHR_Evqp_Ib_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 SAL
*/
inline bool CpuRunnerLLVM::handler_in_C1_06_SAL_Evqp_Ib() {
    if (Is32BitOperandMode()) {
        return handler_in_C1_06_SAL_Evqp_Ib_32();
    } else {
        return handler_in_C1_06_SAL_Evqp_Ib_16();
    }
}

/*
 SAL
*/
inline bool CpuRunnerLLVM::handler_in_C1_06_SAL_Evqp_Ib_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 SAL
*/
inline bool CpuRunnerLLVM::handler_in_C1_06_SAL_Evqp_Ib_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 SAR
*/
inline bool CpuRunnerLLVM::handler_in_C1_07_SAR_Evqp_Ib() {
    if (Is32BitOperandMode()) {
        return handler_in_C1_07_SAR_Evqp_Ib_32();
    } else {
        return handler_in_C1_07_SAR_Evqp_Ib_16();
    }
}

/*
 SAR
*/
inline bool CpuRunnerLLVM::handler_in_C1_07_SAR_Evqp_Ib_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 SAR
*/
inline bool CpuRunnerLLVM::handler_in_C1_07_SAR_Evqp_Ib_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 RETN
*/
inline bool CpuRunnerLLVM::handler_in_C2_RETN_Iw() {
    typedef Bit16u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 RETN
*/
inline bool CpuRunnerLLVM::handler_in_C3_RETN() {
    return true;
}

/*
 LES
*/
inline bool CpuRunnerLLVM::handler_in_C4_LES_Gv_Mp() {
    if (Is32BitOperandMode()) {
        return handler_in_C4_LES_Gv_Mp_32();
    } else {
        return handler_in_C4_LES_Gv_Mp_16();
    }
}

/*
 LES
*/
inline bool CpuRunnerLLVM::handler_in_C4_LES_Gv_Mp_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmReg<data_type>(rmmod);
    auto source = GetRmMem<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 LES
*/
inline bool CpuRunnerLLVM::handler_in_C4_LES_Gv_Mp_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmReg<data_type>(rmmod);
    auto source = GetRmMem<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 LDS
*/
inline bool CpuRunnerLLVM::handler_in_C5_LDS_Gv_Mp() {
    if (Is32BitOperandMode()) {
        return handler_in_C5_LDS_Gv_Mp_32();
    } else {
        return handler_in_C5_LDS_Gv_Mp_16();
    }
}

/*
 LDS
*/
inline bool CpuRunnerLLVM::handler_in_C5_LDS_Gv_Mp_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmReg<data_type>(rmmod);
    auto source = GetRmMem<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 LDS
*/
inline bool CpuRunnerLLVM::handler_in_C5_LDS_Gv_Mp_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmReg<data_type>(rmmod);
    auto source = GetRmMem<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 MOV
*/
inline bool CpuRunnerLLVM::handler_in_C6_00_MOV_Eb_Ib() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 MOV
*/
inline bool CpuRunnerLLVM::handler_in_C7_00_MOV_Evqp_Ivds() {
    if (Is32BitOperandMode()) {
        return handler_in_C7_00_MOV_Evqp_Ivds_32();
    } else {
        return handler_in_C7_00_MOV_Evqp_Ivds_16();
    }
}

/*
 MOV
*/
inline bool CpuRunnerLLVM::handler_in_C7_00_MOV_Evqp_Ivds_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 MOV
*/
inline bool CpuRunnerLLVM::handler_in_C7_00_MOV_Evqp_Ivds_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 ENTER
*/
inline bool CpuRunnerLLVM::handler_in_C8_ENTER_Ib() {
    typedef Bit8u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 LEAVE
*/
inline bool CpuRunnerLLVM::handler_in_C9_LEAVE() {
    return true;
}

/*
 RETF
*/
inline bool CpuRunnerLLVM::handler_in_CA_RETF_Iw() {
    typedef Bit16u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 RETF
*/
inline bool CpuRunnerLLVM::handler_in_CB_RETF() {
    return true;
}

/*
 INT
*/
inline bool CpuRunnerLLVM::handler_in_CC_INT() {
    return true;
}

/*
 INT
*/
inline bool CpuRunnerLLVM::handler_in_CD_INT_Ib() {
    typedef Bit8u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 INTO
*/
inline bool CpuRunnerLLVM::handler_in_CE_INTO() {
    return true;
}

/*
 IRET
*/
inline bool CpuRunnerLLVM::handler_in_CF_IRET() {
    return true;
}

/*
 ROL
*/
inline bool CpuRunnerLLVM::handler_in_D0_00_ROL_Eb() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 ROR
*/
inline bool CpuRunnerLLVM::handler_in_D0_01_ROR_Eb() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 RCL
*/
inline bool CpuRunnerLLVM::handler_in_D0_02_RCL_Eb() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 RCR
*/
inline bool CpuRunnerLLVM::handler_in_D0_03_RCR_Eb() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 SHL
*/
inline bool CpuRunnerLLVM::handler_in_D0_04_SHL_Eb() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 SHR
*/
inline bool CpuRunnerLLVM::handler_in_D0_05_SHR_Eb() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 SAL
*/
inline bool CpuRunnerLLVM::handler_in_D0_06_SAL_Eb() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 SAR
*/
inline bool CpuRunnerLLVM::handler_in_D0_07_SAR_Eb() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 ROL
*/
inline bool CpuRunnerLLVM::handler_in_D1_00_ROL_Evqp() {
    if (Is32BitOperandMode()) {
        return handler_in_D1_00_ROL_Evqp_32();
    } else {
        return handler_in_D1_00_ROL_Evqp_16();
    }
}

/*
 ROL
*/
inline bool CpuRunnerLLVM::handler_in_D1_00_ROL_Evqp_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 ROL
*/
inline bool CpuRunnerLLVM::handler_in_D1_00_ROL_Evqp_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 ROR
*/
inline bool CpuRunnerLLVM::handler_in_D1_01_ROR_Evqp() {
    if (Is32BitOperandMode()) {
        return handler_in_D1_01_ROR_Evqp_32();
    } else {
        return handler_in_D1_01_ROR_Evqp_16();
    }
}

/*
 ROR
*/
inline bool CpuRunnerLLVM::handler_in_D1_01_ROR_Evqp_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 ROR
*/
inline bool CpuRunnerLLVM::handler_in_D1_01_ROR_Evqp_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 RCL
*/
inline bool CpuRunnerLLVM::handler_in_D1_02_RCL_Evqp() {
    if (Is32BitOperandMode()) {
        return handler_in_D1_02_RCL_Evqp_32();
    } else {
        return handler_in_D1_02_RCL_Evqp_16();
    }
}

/*
 RCL
*/
inline bool CpuRunnerLLVM::handler_in_D1_02_RCL_Evqp_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 RCL
*/
inline bool CpuRunnerLLVM::handler_in_D1_02_RCL_Evqp_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 RCR
*/
inline bool CpuRunnerLLVM::handler_in_D1_03_RCR_Evqp() {
    if (Is32BitOperandMode()) {
        return handler_in_D1_03_RCR_Evqp_32();
    } else {
        return handler_in_D1_03_RCR_Evqp_16();
    }
}

/*
 RCR
*/
inline bool CpuRunnerLLVM::handler_in_D1_03_RCR_Evqp_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 RCR
*/
inline bool CpuRunnerLLVM::handler_in_D1_03_RCR_Evqp_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 SHL
*/
inline bool CpuRunnerLLVM::handler_in_D1_04_SHL_Evqp() {
    if (Is32BitOperandMode()) {
        return handler_in_D1_04_SHL_Evqp_32();
    } else {
        return handler_in_D1_04_SHL_Evqp_16();
    }
}

/*
 SHL
*/
inline bool CpuRunnerLLVM::handler_in_D1_04_SHL_Evqp_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 SHL
*/
inline bool CpuRunnerLLVM::handler_in_D1_04_SHL_Evqp_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 SHR
*/
inline bool CpuRunnerLLVM::handler_in_D1_05_SHR_Evqp() {
    if (Is32BitOperandMode()) {
        return handler_in_D1_05_SHR_Evqp_32();
    } else {
        return handler_in_D1_05_SHR_Evqp_16();
    }
}

/*
 SHR
*/
inline bool CpuRunnerLLVM::handler_in_D1_05_SHR_Evqp_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 SHR
*/
inline bool CpuRunnerLLVM::handler_in_D1_05_SHR_Evqp_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 SAL
*/
inline bool CpuRunnerLLVM::handler_in_D1_06_SAL_Evqp() {
    if (Is32BitOperandMode()) {
        return handler_in_D1_06_SAL_Evqp_32();
    } else {
        return handler_in_D1_06_SAL_Evqp_16();
    }
}

/*
 SAL
*/
inline bool CpuRunnerLLVM::handler_in_D1_06_SAL_Evqp_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 SAL
*/
inline bool CpuRunnerLLVM::handler_in_D1_06_SAL_Evqp_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 SAR
*/
inline bool CpuRunnerLLVM::handler_in_D1_07_SAR_Evqp() {
    if (Is32BitOperandMode()) {
        return handler_in_D1_07_SAR_Evqp_32();
    } else {
        return handler_in_D1_07_SAR_Evqp_16();
    }
}

/*
 SAR
*/
inline bool CpuRunnerLLVM::handler_in_D1_07_SAR_Evqp_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 SAR
*/
inline bool CpuRunnerLLVM::handler_in_D1_07_SAR_Evqp_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 ROL
*/
inline bool CpuRunnerLLVM::handler_in_D2_00_ROL_Eb_CLb() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = reg_cl;
    //TODO do the actual operation
    return true;
}

/*
 ROR
*/
inline bool CpuRunnerLLVM::handler_in_D2_01_ROR_Eb_CLb() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = reg_cl;
    //TODO do the actual operation
    return true;
}

/*
 RCL
*/
inline bool CpuRunnerLLVM::handler_in_D2_02_RCL_Eb_CLb() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = reg_cl;
    //TODO do the actual operation
    return true;
}

/*
 RCR
*/
inline bool CpuRunnerLLVM::handler_in_D2_03_RCR_Eb_CLb() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = reg_cl;
    //TODO do the actual operation
    return true;
}

/*
 SHL
*/
inline bool CpuRunnerLLVM::handler_in_D2_04_SHL_Eb_CLb() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = reg_cl;
    //TODO do the actual operation
    return true;
}

/*
 SHR
*/
inline bool CpuRunnerLLVM::handler_in_D2_05_SHR_Eb_CLb() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = reg_cl;
    //TODO do the actual operation
    return true;
}

/*
 SAL
*/
inline bool CpuRunnerLLVM::handler_in_D2_06_SAL_Eb_CLb() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = reg_cl;
    //TODO do the actual operation
    return true;
}

/*
 SAR
*/
inline bool CpuRunnerLLVM::handler_in_D2_07_SAR_Eb_CLb() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = reg_cl;
    //TODO do the actual operation
    return true;
}

/*
 ROL
*/
inline bool CpuRunnerLLVM::handler_in_D3_00_ROL_Evqp_CLb() {
    if (Is32BitOperandMode()) {
        return handler_in_D3_00_ROL_Evqp_CLb_32();
    } else {
        return handler_in_D3_00_ROL_Evqp_CLb_16();
    }
}

/*
 ROL
*/
inline bool CpuRunnerLLVM::handler_in_D3_00_ROL_Evqp_CLb_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = reg_cx;
    //TODO do the actual operation
    return true;
}

/*
 ROL
*/
inline bool CpuRunnerLLVM::handler_in_D3_00_ROL_Evqp_CLb_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = reg_ecx;
    //TODO do the actual operation
    return true;
}

/*
 ROR
*/
inline bool CpuRunnerLLVM::handler_in_D3_01_ROR_Evqp_CLb() {
    if (Is32BitOperandMode()) {
        return handler_in_D3_01_ROR_Evqp_CLb_32();
    } else {
        return handler_in_D3_01_ROR_Evqp_CLb_16();
    }
}

/*
 ROR
*/
inline bool CpuRunnerLLVM::handler_in_D3_01_ROR_Evqp_CLb_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = reg_cx;
    //TODO do the actual operation
    return true;
}

/*
 ROR
*/
inline bool CpuRunnerLLVM::handler_in_D3_01_ROR_Evqp_CLb_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = reg_ecx;
    //TODO do the actual operation
    return true;
}

/*
 RCL
*/
inline bool CpuRunnerLLVM::handler_in_D3_02_RCL_Evqp_CLb() {
    if (Is32BitOperandMode()) {
        return handler_in_D3_02_RCL_Evqp_CLb_32();
    } else {
        return handler_in_D3_02_RCL_Evqp_CLb_16();
    }
}

/*
 RCL
*/
inline bool CpuRunnerLLVM::handler_in_D3_02_RCL_Evqp_CLb_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = reg_cx;
    //TODO do the actual operation
    return true;
}

/*
 RCL
*/
inline bool CpuRunnerLLVM::handler_in_D3_02_RCL_Evqp_CLb_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = reg_ecx;
    //TODO do the actual operation
    return true;
}

/*
 RCR
*/
inline bool CpuRunnerLLVM::handler_in_D3_03_RCR_Evqp_CLb() {
    if (Is32BitOperandMode()) {
        return handler_in_D3_03_RCR_Evqp_CLb_32();
    } else {
        return handler_in_D3_03_RCR_Evqp_CLb_16();
    }
}

/*
 RCR
*/
inline bool CpuRunnerLLVM::handler_in_D3_03_RCR_Evqp_CLb_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = reg_cx;
    //TODO do the actual operation
    return true;
}

/*
 RCR
*/
inline bool CpuRunnerLLVM::handler_in_D3_03_RCR_Evqp_CLb_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = reg_ecx;
    //TODO do the actual operation
    return true;
}

/*
 SHL
*/
inline bool CpuRunnerLLVM::handler_in_D3_04_SHL_Evqp_CLb() {
    if (Is32BitOperandMode()) {
        return handler_in_D3_04_SHL_Evqp_CLb_32();
    } else {
        return handler_in_D3_04_SHL_Evqp_CLb_16();
    }
}

/*
 SHL
*/
inline bool CpuRunnerLLVM::handler_in_D3_04_SHL_Evqp_CLb_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = reg_cx;
    //TODO do the actual operation
    return true;
}

/*
 SHL
*/
inline bool CpuRunnerLLVM::handler_in_D3_04_SHL_Evqp_CLb_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = reg_ecx;
    //TODO do the actual operation
    return true;
}

/*
 SHR
*/
inline bool CpuRunnerLLVM::handler_in_D3_05_SHR_Evqp_CLb() {
    if (Is32BitOperandMode()) {
        return handler_in_D3_05_SHR_Evqp_CLb_32();
    } else {
        return handler_in_D3_05_SHR_Evqp_CLb_16();
    }
}

/*
 SHR
*/
inline bool CpuRunnerLLVM::handler_in_D3_05_SHR_Evqp_CLb_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = reg_cx;
    //TODO do the actual operation
    return true;
}

/*
 SHR
*/
inline bool CpuRunnerLLVM::handler_in_D3_05_SHR_Evqp_CLb_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = reg_ecx;
    //TODO do the actual operation
    return true;
}

/*
 SAL
*/
inline bool CpuRunnerLLVM::handler_in_D3_06_SAL_Evqp_CLb() {
    if (Is32BitOperandMode()) {
        return handler_in_D3_06_SAL_Evqp_CLb_32();
    } else {
        return handler_in_D3_06_SAL_Evqp_CLb_16();
    }
}

/*
 SAL
*/
inline bool CpuRunnerLLVM::handler_in_D3_06_SAL_Evqp_CLb_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = reg_cx;
    //TODO do the actual operation
    return true;
}

/*
 SAL
*/
inline bool CpuRunnerLLVM::handler_in_D3_06_SAL_Evqp_CLb_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = reg_ecx;
    //TODO do the actual operation
    return true;
}

/*
 SAR
*/
inline bool CpuRunnerLLVM::handler_in_D3_07_SAR_Evqp_CLb() {
    if (Is32BitOperandMode()) {
        return handler_in_D3_07_SAR_Evqp_CLb_32();
    } else {
        return handler_in_D3_07_SAR_Evqp_CLb_16();
    }
}

/*
 SAR
*/
inline bool CpuRunnerLLVM::handler_in_D3_07_SAR_Evqp_CLb_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = reg_cx;
    //TODO do the actual operation
    return true;
}

/*
 SAR
*/
inline bool CpuRunnerLLVM::handler_in_D3_07_SAR_Evqp_CLb_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    auto source = reg_ecx;
    //TODO do the actual operation
    return true;
}

/*
 AMX
*/
inline bool CpuRunnerLLVM::handler_in_D4_AMX_Ib() {
    typedef Bit8u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 ADX
*/
inline bool CpuRunnerLLVM::handler_in_D5_ADX_Ib() {
    typedef Bit8u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 SALC
*/
inline bool CpuRunnerLLVM::handler_in_D6_SALC() {
    return true;
}

/*
 XLAT
*/
inline bool CpuRunnerLLVM::handler_in_D7_XLAT_BBb() {
    typedef Bit8u data_type;
    auto source = GetMemoryReference<data_type>(reg_bh);
    //TODO do the actual operation
    return true;
}

/*
 LOOPNZ
*/
inline bool CpuRunnerLLVM::handler_in_E0_LOOPNZ_Jbs() {
    typedef Bit8u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 LOOPZ
*/
inline bool CpuRunnerLLVM::handler_in_E1_LOOPZ_Jbs() {
    typedef Bit8u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 LOOP
*/
inline bool CpuRunnerLLVM::handler_in_E2_LOOP_Jbs() {
    typedef Bit8u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 JCXZ
*/
inline bool CpuRunnerLLVM::handler_in_E3_JCXZ_Jbs() {
    typedef Bit8u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 IN
*/
inline bool CpuRunnerLLVM::handler_in_E4_IN_ALb_Ib() {
    typedef Bit8u data_type;
    auto& destination = reg_al;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 IN
*/
inline bool CpuRunnerLLVM::handler_in_E5_IN_rAXv_Ib() {
    if (Is32BitOperandMode()) {
        return handler_in_E5_IN_rAXv_Ib_32();
    } else {
        return handler_in_E5_IN_rAXv_Ib_16();
    }
}

/*
 IN
*/
inline bool CpuRunnerLLVM::handler_in_E5_IN_rAXv_Ib_16() {
    typedef Bit16u data_type;
    auto& destination = reg_ax;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 IN
*/
inline bool CpuRunnerLLVM::handler_in_E5_IN_rAXv_Ib_32() {
    typedef Bit32u data_type;
    auto& destination = reg_eax;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 OUT
*/
inline bool CpuRunnerLLVM::handler_in_E6_OUT_Ib_ALb() {
    typedef Bit8u data_type;
    auto destination = GetImmediate<data_type>();
    auto source = reg_al;
    //TODO do the actual operation
    return true;
}

/*
 OUT
*/
inline bool CpuRunnerLLVM::handler_in_E7_OUT_Ib_rAXv() {
    if (Is32BitOperandMode()) {
        return handler_in_E7_OUT_Ib_rAXv_32();
    } else {
        return handler_in_E7_OUT_Ib_rAXv_16();
    }
}

/*
 OUT
*/
inline bool CpuRunnerLLVM::handler_in_E7_OUT_Ib_rAXv_16() {
    typedef Bit8u data_type;
    auto destination = GetImmediate<data_type>();
    auto source = reg_al;
    //TODO do the actual operation
    return true;
}

/*
 OUT
*/
inline bool CpuRunnerLLVM::handler_in_E7_OUT_Ib_rAXv_32() {
    typedef Bit8u data_type;
    auto destination = GetImmediate<data_type>();
    auto source = reg_al;
    //TODO do the actual operation
    return true;
}

/*
 CALL
*/
inline bool CpuRunnerLLVM::handler_in_E8_CALL_Jvds() {
    if (Is32BitOperandMode()) {
        return handler_in_E8_CALL_Jvds_32();
    } else {
        return handler_in_E8_CALL_Jvds_16();
    }
}

/*
 CALL
*/
inline bool CpuRunnerLLVM::handler_in_E8_CALL_Jvds_16() {
    typedef Bit16u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 CALL
*/
inline bool CpuRunnerLLVM::handler_in_E8_CALL_Jvds_32() {
    typedef Bit32u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 JMP
*/
inline bool CpuRunnerLLVM::handler_in_E9_JMP_Jvds() {
    if (Is32BitOperandMode()) {
        return handler_in_E9_JMP_Jvds_32();
    } else {
        return handler_in_E9_JMP_Jvds_16();
    }
}

/*
 JMP
*/
inline bool CpuRunnerLLVM::handler_in_E9_JMP_Jvds_16() {
    typedef Bit16u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 JMP
*/
inline bool CpuRunnerLLVM::handler_in_E9_JMP_Jvds_32() {
    typedef Bit32u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 JMPF
*/
inline bool CpuRunnerLLVM::handler_in_EA_JMPF_Ap() {
    if (Is32BitOperandMode()) {
        return handler_in_EA_JMPF_Ap_32();
    } else {
        return handler_in_EA_JMPF_Ap_16();
    }
}

/*
 JMPF
*/
inline bool CpuRunnerLLVM::handler_in_EA_JMPF_Ap_16() {
    typedef Bit16u data_type;
    auto source = GetMemoryReference<data_type>(GetImmediate<Bit16u>() + GetImmediate<data_type>());
    //TODO do the actual operation
    return true;
}

/*
 JMPF
*/
inline bool CpuRunnerLLVM::handler_in_EA_JMPF_Ap_32() {
    typedef Bit32u data_type;
    auto source = GetMemoryReference<data_type>(GetImmediate<Bit16u>() + GetImmediate<data_type>());
    //TODO do the actual operation
    return true;
}

/*
 JMP
*/
inline bool CpuRunnerLLVM::handler_in_EB_JMP_Jbs() {
    typedef Bit8u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 IN
*/
inline bool CpuRunnerLLVM::handler_in_EC_IN_ALb_DXw() {
    typedef Bit8u data_type;
    auto& destination = reg_al;
    auto source = reg_dl;
    //TODO do the actual operation
    return true;
}

/*
 IN
*/
inline bool CpuRunnerLLVM::handler_in_ED_IN_rAXv_DXw() {
    if (Is32BitOperandMode()) {
        return handler_in_ED_IN_rAXv_DXw_32();
    } else {
        return handler_in_ED_IN_rAXv_DXw_16();
    }
}

/*
 IN
*/
inline bool CpuRunnerLLVM::handler_in_ED_IN_rAXv_DXw_16() {
    typedef Bit16u data_type;
    auto& destination = reg_ax;
    auto source = reg_dx;
    //TODO do the actual operation
    return true;
}

/*
 IN
*/
inline bool CpuRunnerLLVM::handler_in_ED_IN_rAXv_DXw_32() {
    typedef Bit32u data_type;
    auto& destination = reg_eax;
    auto source = reg_edx;
    //TODO do the actual operation
    return true;
}

/*
 OUT
*/
inline bool CpuRunnerLLVM::handler_in_EE_OUT_DXw_ALb() {
    typedef Bit16u data_type;
    auto& destination = reg_dx;
    auto source = reg_ax;
    //TODO do the actual operation
    return true;
}

/*
 OUT
*/
inline bool CpuRunnerLLVM::handler_in_EF_OUT_DXw_rAXv() {
    if (Is32BitOperandMode()) {
        return handler_in_EF_OUT_DXw_rAXv_32();
    } else {
        return handler_in_EF_OUT_DXw_rAXv_16();
    }
}

/*
 OUT
*/
inline bool CpuRunnerLLVM::handler_in_EF_OUT_DXw_rAXv_16() {
    typedef Bit16u data_type;
    auto& destination = reg_dx;
    auto source = reg_ax;
    //TODO do the actual operation
    return true;
}

/*
 OUT
*/
inline bool CpuRunnerLLVM::handler_in_EF_OUT_DXw_rAXv_32() {
    typedef Bit16u data_type;
    auto& destination = reg_dx;
    auto source = reg_ax;
    //TODO do the actual operation
    return true;
}

/*
 INT1
*/
inline bool CpuRunnerLLVM::handler_in_F1_INT1() {
    return true;
}

/*
 NOP
*/
inline bool CpuRunnerLLVM::handler_in_F3_90_NOP() {
    return true;
}

/*
 HLT
*/
inline bool CpuRunnerLLVM::handler_in_F4_HLT() {
    return true;
}

/*
 CMC
*/
inline bool CpuRunnerLLVM::handler_in_F5_CMC() {
    return true;
}

/*
 TEST
*/
inline bool CpuRunnerLLVM::handler_in_F6_01_TEST_Ib() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 NOT
*/
inline bool CpuRunnerLLVM::handler_in_F6_02_NOT_Eb() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 NEG
*/
inline bool CpuRunnerLLVM::handler_in_F6_03_NEG_Eb() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 MUL
*/
inline bool CpuRunnerLLVM::handler_in_F6_04_MUL_Eb() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto source = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 IMUL
*/
inline bool CpuRunnerLLVM::handler_in_F6_05_IMUL_Eb() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto source = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 DIV
*/
inline bool CpuRunnerLLVM::handler_in_F6_06_DIV_Eb() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto source = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 IDIV
*/
inline bool CpuRunnerLLVM::handler_in_F6_07_IDIV_Eb() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto source = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 TEST
*/
inline bool CpuRunnerLLVM::handler_in_F7_01_TEST_Ivqp() {
    if (Is32BitOperandMode()) {
        return handler_in_F7_01_TEST_Ivqp_32();
    } else {
        return handler_in_F7_01_TEST_Ivqp_16();
    }
}

/*
 TEST
*/
inline bool CpuRunnerLLVM::handler_in_F7_01_TEST_Ivqp_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 TEST
*/
inline bool CpuRunnerLLVM::handler_in_F7_01_TEST_Ivqp_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto source = GetImmediate<data_type>();
    //TODO do the actual operation
    return true;
}

/*
 NOT
*/
inline bool CpuRunnerLLVM::handler_in_F7_02_NOT_Evqp() {
    if (Is32BitOperandMode()) {
        return handler_in_F7_02_NOT_Evqp_32();
    } else {
        return handler_in_F7_02_NOT_Evqp_16();
    }
}

/*
 NOT
*/
inline bool CpuRunnerLLVM::handler_in_F7_02_NOT_Evqp_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 NOT
*/
inline bool CpuRunnerLLVM::handler_in_F7_02_NOT_Evqp_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 NEG
*/
inline bool CpuRunnerLLVM::handler_in_F7_03_NEG_Evqp() {
    if (Is32BitOperandMode()) {
        return handler_in_F7_03_NEG_Evqp_32();
    } else {
        return handler_in_F7_03_NEG_Evqp_16();
    }
}

/*
 NEG
*/
inline bool CpuRunnerLLVM::handler_in_F7_03_NEG_Evqp_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 NEG
*/
inline bool CpuRunnerLLVM::handler_in_F7_03_NEG_Evqp_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 MUL
*/
inline bool CpuRunnerLLVM::handler_in_F7_04_MUL_Evqp() {
    if (Is32BitOperandMode()) {
        return handler_in_F7_04_MUL_Evqp_32();
    } else {
        return handler_in_F7_04_MUL_Evqp_16();
    }
}

/*
 MUL
*/
inline bool CpuRunnerLLVM::handler_in_F7_04_MUL_Evqp_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto source = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 MUL
*/
inline bool CpuRunnerLLVM::handler_in_F7_04_MUL_Evqp_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto source = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 IMUL
*/
inline bool CpuRunnerLLVM::handler_in_F7_05_IMUL_Evqp() {
    if (Is32BitOperandMode()) {
        return handler_in_F7_05_IMUL_Evqp_32();
    } else {
        return handler_in_F7_05_IMUL_Evqp_16();
    }
}

/*
 IMUL
*/
inline bool CpuRunnerLLVM::handler_in_F7_05_IMUL_Evqp_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto source = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 IMUL
*/
inline bool CpuRunnerLLVM::handler_in_F7_05_IMUL_Evqp_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto source = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 DIV
*/
inline bool CpuRunnerLLVM::handler_in_F7_06_DIV_Evqp() {
    if (Is32BitOperandMode()) {
        return handler_in_F7_06_DIV_Evqp_32();
    } else {
        return handler_in_F7_06_DIV_Evqp_16();
    }
}

/*
 DIV
*/
inline bool CpuRunnerLLVM::handler_in_F7_06_DIV_Evqp_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto source = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 DIV
*/
inline bool CpuRunnerLLVM::handler_in_F7_06_DIV_Evqp_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto source = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 IDIV
*/
inline bool CpuRunnerLLVM::handler_in_F7_07_IDIV_Evqp() {
    if (Is32BitOperandMode()) {
        return handler_in_F7_07_IDIV_Evqp_32();
    } else {
        return handler_in_F7_07_IDIV_Evqp_16();
    }
}

/*
 IDIV
*/
inline bool CpuRunnerLLVM::handler_in_F7_07_IDIV_Evqp_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto source = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 IDIV
*/
inline bool CpuRunnerLLVM::handler_in_F7_07_IDIV_Evqp_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto source = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 CLC
*/
inline bool CpuRunnerLLVM::handler_in_F8_CLC() {
    return true;
}

/*
 STC
*/
inline bool CpuRunnerLLVM::handler_in_F9_STC() {
    return true;
}

/*
 CLI
*/
inline bool CpuRunnerLLVM::handler_in_FA_CLI() {
    return true;
}

/*
 STI
*/
inline bool CpuRunnerLLVM::handler_in_FB_STI() {
    return true;
}

/*
 CLD
*/
inline bool CpuRunnerLLVM::handler_in_FC_CLD() {
    return true;
}

/*
 STD
*/
inline bool CpuRunnerLLVM::handler_in_FD_STD() {
    return true;
}

/*
 INC
*/
inline bool CpuRunnerLLVM::handler_in_FE_00_INC_Eb() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 DEC
*/
inline bool CpuRunnerLLVM::handler_in_FE_01_DEC_Eb() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit8u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 INC
*/
inline bool CpuRunnerLLVM::handler_in_FF_00_INC_Evqp() {
    if (Is32BitOperandMode()) {
        return handler_in_FF_00_INC_Evqp_32();
    } else {
        return handler_in_FF_00_INC_Evqp_16();
    }
}

/*
 INC
*/
inline bool CpuRunnerLLVM::handler_in_FF_00_INC_Evqp_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 INC
*/
inline bool CpuRunnerLLVM::handler_in_FF_00_INC_Evqp_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 DEC
*/
inline bool CpuRunnerLLVM::handler_in_FF_01_DEC_Evqp() {
    if (Is32BitOperandMode()) {
        return handler_in_FF_01_DEC_Evqp_32();
    } else {
        return handler_in_FF_01_DEC_Evqp_16();
    }
}

/*
 DEC
*/
inline bool CpuRunnerLLVM::handler_in_FF_01_DEC_Evqp_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 DEC
*/
inline bool CpuRunnerLLVM::handler_in_FF_01_DEC_Evqp_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto destination = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 CALL
*/
inline bool CpuRunnerLLVM::handler_in_FF_02_CALL_Ev() {
    if (Is32BitOperandMode()) {
        return handler_in_FF_02_CALL_Ev_32();
    } else {
        return handler_in_FF_02_CALL_Ev_16();
    }
}

/*
 CALL
*/
inline bool CpuRunnerLLVM::handler_in_FF_02_CALL_Ev_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto source = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 CALL
*/
inline bool CpuRunnerLLVM::handler_in_FF_02_CALL_Ev_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto source = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 CALLF
*/
inline bool CpuRunnerLLVM::handler_in_FF_03_CALLF_Mptp() {
    if (Is32BitOperandMode()) {
        return handler_in_FF_03_CALLF_Mptp_32();
    } else {
        return handler_in_FF_03_CALLF_Mptp_16();
    }
}

/*
 CALLF
*/
inline bool CpuRunnerLLVM::handler_in_FF_03_CALLF_Mptp_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto source = GetRmMem<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 CALLF
*/
inline bool CpuRunnerLLVM::handler_in_FF_03_CALLF_Mptp_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto source = GetRmMem<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 JMP
*/
inline bool CpuRunnerLLVM::handler_in_FF_04_JMP_Ev() {
    if (Is32BitOperandMode()) {
        return handler_in_FF_04_JMP_Ev_32();
    } else {
        return handler_in_FF_04_JMP_Ev_16();
    }
}

/*
 JMP
*/
inline bool CpuRunnerLLVM::handler_in_FF_04_JMP_Ev_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto source = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 JMP
*/
inline bool CpuRunnerLLVM::handler_in_FF_04_JMP_Ev_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto source = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 JMPF
*/
inline bool CpuRunnerLLVM::handler_in_FF_05_JMPF_Mptp() {
    if (Is32BitOperandMode()) {
        return handler_in_FF_05_JMPF_Mptp_32();
    } else {
        return handler_in_FF_05_JMPF_Mptp_16();
    }
}

/*
 JMPF
*/
inline bool CpuRunnerLLVM::handler_in_FF_05_JMPF_Mptp_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto source = GetRmMem<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 JMPF
*/
inline bool CpuRunnerLLVM::handler_in_FF_05_JMPF_Mptp_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto source = GetRmMem<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 PUSH
*/
inline bool CpuRunnerLLVM::handler_in_FF_06_PUSH_Ev() {
    if (Is32BitOperandMode()) {
        return handler_in_FF_06_PUSH_Ev_32();
    } else {
        return handler_in_FF_06_PUSH_Ev_16();
    }
}

/*
 PUSH
*/
inline bool CpuRunnerLLVM::handler_in_FF_06_PUSH_Ev_16() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit16u data_type;
    auto source = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/*
 PUSH
*/
inline bool CpuRunnerLLVM::handler_in_FF_06_PUSH_Ev_32() {
    auto rmmod = Fetch<Bit8u>();
    typedef Bit32u data_type;
    auto source = GetRmMod<data_type>(rmmod);
    //TODO do the actual operation
    return true;
}

/* Init state */
inline bool CpuRunnerLLVM::handler_s0(Bit8u rmmod) {

    switch(rmmod) {
    case 0x00:
        return handler_in_00_ADD_Eb_Gb();
    case 0x01:
        return handler_in_01_ADD_Evqp_Gvqp();
    case 0x02:
        return handler_in_02_ADD_Gb_Eb();
    case 0x03:
        return handler_in_03_ADD_Gvqp_Evqp();
    case 0x04:
        return handler_in_04_ADD_ALb_Ib();
    case 0x05:
        return handler_in_05_ADD_rAXvqp_Ivds();
    case 0x06:
        return handler_in_06_PUSH_ESw();
    case 0x07:
        return handler_in_07_POP_ESw();
    case 0x08:
        return handler_in_08_OR_Eb_Gb();
    case 0x09:
        return handler_in_09_OR_Evqp_Gvqp();
    case 0x0a:
        return handler_in_0A_OR_Gb_Eb();
    case 0x0b:
        return handler_in_0B_OR_Gvqp_Evqp();
    case 0x0c:
        return handler_in_0C_OR_ALb_Ib();
    case 0x0d:
        return handler_in_0D_OR_rAXvqp_Ivds();
    case 0x0e:
        return handler_in_0E_PUSH_CSw();
    case 0x0f:
        return handler_st_0F();
    case 0x10:
        return handler_in_10_ADC_Eb_Gb();
    case 0x11:
        return handler_in_11_ADC_Evqp_Gvqp();
    case 0x12:
        return handler_in_12_ADC_Gb_Eb();
    case 0x13:
        return handler_in_13_ADC_Gvqp_Evqp();
    case 0x14:
        return handler_in_14_ADC_ALb_Ib();
    case 0x15:
        return handler_in_15_ADC_rAXvqp_Ivds();
    case 0x16:
        return handler_in_16_PUSH_SSw();
    case 0x17:
        return handler_in_17_POP_SSw();
    case 0x18:
        return handler_in_18_SBB_Eb_Gb();
    case 0x19:
        return handler_in_19_SBB_Evqp_Gvqp();
    case 0x1a:
        return handler_in_1A_SBB_Gb_Eb();
    case 0x1b:
        return handler_in_1B_SBB_Gvqp_Evqp();
    case 0x1c:
        return handler_in_1C_SBB_ALb_Ib();
    case 0x1d:
        return handler_in_1D_SBB_rAXvqp_Ivds();
    case 0x1e:
        return handler_in_1E_PUSH_DSw();
    case 0x1f:
        return handler_in_1F_POP_DSw();
    case 0x20:
        return handler_in_20_AND_Eb_Gb();
    case 0x21:
        return handler_in_21_AND_Evqp_Gvqp();
    case 0x22:
        return handler_in_22_AND_Gb_Eb();
    case 0x23:
        return handler_in_23_AND_Gvqp_Evqp();
    case 0x24:
        return handler_in_24_AND_ALb_Ib();
    case 0x25:
        return handler_in_25_AND_rAXvqp_Ivds();
    case 0x27:
        return handler_in_27_DAA();
    case 0x28:
        return handler_in_28_SUB_Eb_Gb();
    case 0x29:
        return handler_in_29_SUB_Evqp_Gvqp();
    case 0x2a:
        return handler_in_2A_SUB_Gb_Eb();
    case 0x2b:
        return handler_in_2B_SUB_Gvqp_Evqp();
    case 0x2c:
        return handler_in_2C_SUB_ALb_Ib();
    case 0x2d:
        return handler_in_2D_SUB_rAXvqp_Ivds();
    case 0x2f:
        return handler_in_2F_DAS();
    case 0x30:
        return handler_in_30_XOR_Eb_Gb();
    case 0x31:
        return handler_in_31_XOR_Evqp_Gvqp();
    case 0x32:
        return handler_in_32_XOR_Gb_Eb();
    case 0x33:
        return handler_in_33_XOR_Gvqp_Evqp();
    case 0x34:
        return handler_in_34_XOR_ALb_Ib();
    case 0x35:
        return handler_in_35_XOR_rAXvqp_Ivds();
    case 0x37:
        return handler_in_37_AAA();
    case 0x38:
        return handler_in_38_CMP_Gb();
    case 0x39:
        return handler_in_39_CMP_Gvqp();
    case 0x3a:
        return handler_in_3A_CMP_Eb();
    case 0x3b:
        return handler_in_3B_CMP_Evqp();
    case 0x3c:
        return handler_in_3C_CMP_Ib();
    case 0x3d:
        return handler_in_3D_CMP_Ivds();
    case 0x3f:
        return handler_in_3F_AAS();
    case 0x40:
        return handler_in_40_INC_rAXv();
    case 0x41:
        return handler_in_41_INC_rCXv();
    case 0x42:
        return handler_in_42_INC_rDXv();
    case 0x43:
        return handler_in_43_INC_rBXv();
    case 0x44:
        return handler_in_44_INC_rSPv();
    case 0x45:
        return handler_in_45_INC_rBPv();
    case 0x46:
        return handler_in_46_INC_rSIv();
    case 0x47:
        return handler_in_47_INC_rDIv();
    case 0x48:
        return handler_in_48_DEC_rAXv();
    case 0x49:
        return handler_in_49_DEC_rCXv();
    case 0x4a:
        return handler_in_4A_DEC_rDXv();
    case 0x4b:
        return handler_in_4B_DEC_rBXv();
    case 0x4c:
        return handler_in_4C_DEC_rSPv();
    case 0x4d:
        return handler_in_4D_DEC_rBPv();
    case 0x4e:
        return handler_in_4E_DEC_rSIv();
    case 0x4f:
        return handler_in_4F_DEC_rDIv();
    case 0x50:
        return handler_in_50_PUSH_rAXv();
    case 0x51:
        return handler_in_51_PUSH_rCXv();
    case 0x52:
        return handler_in_52_PUSH_rDXv();
    case 0x53:
        return handler_in_53_PUSH_rBXv();
    case 0x54:
        return handler_in_54_PUSH_rSPv();
    case 0x55:
        return handler_in_55_PUSH_rBPv();
    case 0x56:
        return handler_in_56_PUSH_rSIv();
    case 0x57:
        return handler_in_57_PUSH_rDIv();
    case 0x58:
        return handler_in_58_POP_rAXv();
    case 0x59:
        return handler_in_59_POP_rCXv();
    case 0x5a:
        return handler_in_5A_POP_rDXv();
    case 0x5b:
        return handler_in_5B_POP_rBXv();
    case 0x5c:
        return handler_in_5C_POP_rSPv();
    case 0x5d:
        return handler_in_5D_POP_rBPv();
    case 0x5e:
        return handler_in_5E_POP_rSIv();
    case 0x5f:
        return handler_in_5F_POP_rDIv();
    case 0x60:
        return handler_in_60_PUSHA();
    case 0x61:
        return handler_in_61_POPA();
    case 0x62:
        return handler_in_62_BOUND_Ma();
    case 0x63:
        return handler_in_63_ARPL_Gw();
    case 0x68:
        return handler_in_68_PUSH_Ivs();
    case 0x69:
        return handler_in_69_IMUL_Gvqp_Ivds();
    case 0x6a:
        return handler_in_6A_PUSH_Ibss();
    case 0x6b:
        return handler_in_6B_IMUL_Gvqp_Ibs();
    case 0x6c:
        return handler_in_6C_INS_Yb_DXw();
    case 0x6d:
        return handler_in_6D_INS_Ywo_DXw();
    case 0x6e:
        return handler_in_6E_OUTS_DXw_Xb();
    case 0x6f:
        return handler_in_6F_OUTS_DXw_Xwo();
    case 0x70:
        return handler_in_70_JO_Jbs();
    case 0x71:
        return handler_in_71_JNO_Jbs();
    case 0x72:
        return handler_in_72_JB_Jbs();
    case 0x73:
        return handler_in_73_JNB_Jbs();
    case 0x74:
        return handler_in_74_JZ_Jbs();
    case 0x75:
        return handler_in_75_JNZ_Jbs();
    case 0x76:
        return handler_in_76_JBE_Jbs();
    case 0x77:
        return handler_in_77_JNBE_Jbs();
    case 0x78:
        return handler_in_78_JS_Jbs();
    case 0x79:
        return handler_in_79_JNS_Jbs();
    case 0x7a:
        return handler_in_7A_JP_Jbs();
    case 0x7b:
        return handler_in_7B_JNP_Jbs();
    case 0x7c:
        return handler_in_7C_JL_Jbs();
    case 0x7d:
        return handler_in_7D_JNL_Jbs();
    case 0x7e:
        return handler_in_7E_JLE_Jbs();
    case 0x7f:
        return handler_in_7F_JNLE_Jbs();
    case 0x81:
        return handler_st_81();
    case 0x82:
        return handler_st_82();
    case 0x83:
        return handler_st_83();
    case 0x84:
        return handler_in_84_TEST_Gb();
    case 0x85:
        return handler_in_85_TEST_Gvqp();
    case 0x86:
        return handler_in_86_XCHG_Eb();
    case 0x87:
        return handler_in_87_XCHG_Evqp();
    case 0x88:
        return handler_in_88_MOV_Eb_Gb();
    case 0x89:
        return handler_in_89_MOV_Evqp_Gvqp();
    case 0x8a:
        return handler_in_8A_MOV_Gb_Eb();
    case 0x8b:
        return handler_in_8B_MOV_Gvqp_Evqp();
    case 0x8c:
        return handler_in_8C_MOV_Mw_Sw();
    case 0x8d:
        return handler_in_8D_LEA_Gvqp();
    case 0x8e:
        return handler_in_8E_MOV_Sw_Ew();
    case 0x8f:
        return handler_st_8F();
    case 0x90:
        return handler_in_90_XCHG_rAXvqp();
    case 0x91:
        return handler_in_91_XCHG_rAXvqp();
    case 0x92:
        return handler_in_92_XCHG_rAXvqp();
    case 0x93:
        return handler_in_93_XCHG_rAXvqp();
    case 0x94:
        return handler_in_94_XCHG_rAXvqp();
    case 0x95:
        return handler_in_95_XCHG_rAXvqp();
    case 0x96:
        return handler_in_96_XCHG_rAXvqp();
    case 0x97:
        return handler_in_97_XCHG_rAXvqp();
    case 0x98:
        return handler_in_98_CWDE();
    case 0x99:
        return handler_in_99_CDQ();
    case 0x9a:
        return handler_in_9A_CALLF_Ap();
    case 0x9b:
        return handler_in_9B_FWAIT();
    case 0x9c:
        return handler_in_9C_PUSHF();
    case 0x9d:
        return handler_in_9D_POPF();
    case 0x9e:
        return handler_in_9E_SAHF();
    case 0x9f:
        return handler_in_9F_LAHF();
    case 0xa0:
        return handler_in_A0_MOV_ALb_Ob();
    case 0xa1:
        return handler_in_A1_MOV_rAXvqp_Ovqp();
    case 0xa2:
        return handler_in_A2_MOV_Ob_ALb();
    case 0xa3:
        return handler_in_A3_MOV_Ovqp_rAXvqp();
    case 0xa4:
        return handler_in_A4_MOVS_Yb_Xb();
    case 0xa5:
        return handler_in_A5_MOVS_Ywo_Xwo();
    case 0xa6:
        return handler_in_A6_CMPS_Xb();
    case 0xa7:
        return handler_in_A7_CMPS_Xwo();
    case 0xa8:
        return handler_in_A8_TEST_Ib();
    case 0xa9:
        return handler_in_A9_TEST_Ivds();
    case 0xaa:
        return handler_in_AA_STOS_Yb();
    case 0xab:
        return handler_in_AB_STOS_Ywo();
    case 0xac:
        return handler_in_AC_LODS_Xb();
    case 0xad:
        return handler_in_AD_LODS_Xwo();
    case 0xae:
        return handler_in_AE_SCAS_Yb();
    case 0xaf:
        return handler_in_AF_SCAS_Ywo();
    case 0xb0:
        return handler_in_B0_MOV_ALb_Ib();
    case 0xb1:
        return handler_in_B1_MOV_CLb_Ib();
    case 0xb2:
        return handler_in_B2_MOV_DLb_Ib();
    case 0xb4:
        return handler_in_B4_MOV_AHb_Ib();
    case 0xb5:
        return handler_in_B5_MOV_CHb_Ib();
    case 0xb6:
        return handler_in_B6_MOV_DHb_Ib();
    case 0xb7:
        return handler_in_B7_MOV_BHb_Ib();
    case 0xb8:
        return handler_in_B8_MOV_rAXvqp_Ivqp();
    case 0xb9:
        return handler_in_B9_MOV_rCXvqp_Ivqp();
    case 0xba:
        return handler_in_BA_MOV_rDXvqp_Ivqp();
    case 0xbb:
        return handler_in_BB_MOV_rBXvqp_Ivqp();
    case 0xbc:
        return handler_in_BC_MOV_rSPvqp_Ivqp();
    case 0xbd:
        return handler_in_BD_MOV_rBPvqp_Ivqp();
    case 0xbe:
        return handler_in_BE_MOV_rSIvqp_Ivqp();
    case 0xbf:
        return handler_in_BF_MOV_rDIvqp_Ivqp();
    case 0xc0:
        return handler_st_C0();
    case 0xc1:
        return handler_st_C1();
    case 0xc2:
        return handler_in_C2_RETN_Iw();
    case 0xc3:
        return handler_in_C3_RETN();
    case 0xc4:
        return handler_in_C4_LES_Gv_Mp();
    case 0xc5:
        return handler_in_C5_LDS_Gv_Mp();
    case 0xc6:
        return handler_st_C6();
    case 0xc7:
        return handler_st_C7();
    case 0xc8:
        return handler_in_C8_ENTER_Ib();
    case 0xc9:
        return handler_in_C9_LEAVE();
    case 0xca:
        return handler_in_CA_RETF_Iw();
    case 0xcb:
        return handler_in_CB_RETF();
    case 0xcc:
        return handler_in_CC_INT();
    case 0xcd:
        return handler_in_CD_INT_Ib();
    case 0xce:
        return handler_in_CE_INTO();
    case 0xcf:
        return handler_in_CF_IRET();
    case 0xd0:
        return handler_st_D0();
    case 0xd1:
        return handler_st_D1();
    case 0xd2:
        return handler_st_D2();
    case 0xd3:
        return handler_st_D3();
    case 0xd4:
        return handler_in_D4_AMX_Ib();
    case 0xd5:
        return handler_in_D5_ADX_Ib();
    case 0xd6:
        return handler_in_D6_SALC();
    case 0xd7:
        return handler_in_D7_XLAT_BBb();
    case 0xe0:
        return handler_in_E0_LOOPNZ_Jbs();
    case 0xe1:
        return handler_in_E1_LOOPZ_Jbs();
    case 0xe2:
        return handler_in_E2_LOOP_Jbs();
    case 0xe3:
        return handler_in_E3_JCXZ_Jbs();
    case 0xe4:
        return handler_in_E4_IN_ALb_Ib();
    case 0xe5:
        return handler_in_E5_IN_rAXv_Ib();
    case 0xe6:
        return handler_in_E6_OUT_Ib_ALb();
    case 0xe7:
        return handler_in_E7_OUT_Ib_rAXv();
    case 0xe8:
        return handler_in_E8_CALL_Jvds();
    case 0xe9:
        return handler_in_E9_JMP_Jvds();
    case 0xea:
        return handler_in_EA_JMPF_Ap();
    case 0xeb:
        return handler_in_EB_JMP_Jbs();
    case 0xec:
        return handler_in_EC_IN_ALb_DXw();
    case 0xed:
        return handler_in_ED_IN_rAXv_DXw();
    case 0xee:
        return handler_in_EE_OUT_DXw_ALb();
    case 0xef:
        return handler_in_EF_OUT_DXw_rAXv();
    case 0xf1:
        return handler_in_F1_INT1();
    case 0xf3:
        return handler_st_F3();
    case 0xf4:
        return handler_in_F4_HLT();
    case 0xf5:
        return handler_in_F5_CMC();
    case 0xf6:
        return handler_st_F6();
    case 0xf7:
        return handler_st_F7();
    case 0xf8:
        return handler_in_F8_CLC();
    case 0xf9:
        return handler_in_F9_STC();
    case 0xfa:
        return handler_in_FA_CLI();
    case 0xfb:
        return handler_in_FB_STI();
    case 0xfc:
        return handler_in_FC_CLD();
    case 0xfd:
        return handler_in_FD_STD();
    case 0xfe:
        return handler_st_FE();
    case 0xff:
        return handler_st_FF();

    default:
        break;
    };
    return false;
};

/*  */
inline bool CpuRunnerLLVM::handler_st_0F() {
    auto rmmod = Fetch<Bit8u>();

    switch(rmmod) {
    case 0x00:
        return handler_st_0F_00();
    case 0x01:
        return handler_st_0F_01();
    case 0x02:
        return handler_in_0F_02_LAR_Gvqp_Mw();
    case 0x03:
        return handler_in_0F_03_LSL_Gvqp_Mw();
    case 0x06:
        return handler_in_0F_06_CLTS();
    case 0x07:
        return handler_in_0F_07_LOADALL();
    case 0x08:
        return handler_in_0F_08_INVD();
    case 0x09:
        return handler_in_0F_09_WBINVD();
    case 0x20:
        return handler_in_0F_20_MOV_Hd_Cd();
    case 0x21:
        return handler_in_0F_21_MOV_Hd_Dd();
    case 0x22:
        return handler_in_0F_22_MOV_Cd_Hd();
    case 0x23:
        return handler_in_0F_23_MOV_Dq_Hq();
    case 0x24:
        return handler_in_0F_24_MOV_Hd_Td();
    case 0x26:
        return handler_in_0F_26_MOV_Td_Hd();
    case 0x80:
        return handler_in_0F_80_JO_Jvds();
    case 0x81:
        return handler_in_0F_81_JNO_Jvds();
    case 0x82:
        return handler_in_0F_82_JB_Jvds();
    case 0x83:
        return handler_in_0F_83_JNB_Jvds();
    case 0x84:
        return handler_in_0F_84_JZ_Jvds();
    case 0x85:
        return handler_in_0F_85_JNZ_Jvds();
    case 0x86:
        return handler_in_0F_86_JBE_Jvds();
    case 0x87:
        return handler_in_0F_87_JNBE_Jvds();
    case 0x88:
        return handler_in_0F_88_JS_Jvds();
    case 0x89:
        return handler_in_0F_89_JNS_Jvds();
    case 0x8a:
        return handler_in_0F_8A_JP_Jvds();
    case 0x8b:
        return handler_in_0F_8B_JNP_Jvds();
    case 0x8c:
        return handler_in_0F_8C_JL_Jvds();
    case 0x8d:
        return handler_in_0F_8D_JNL_Jvds();
    case 0x8e:
        return handler_in_0F_8E_JLE_Jvds();
    case 0x8f:
        return handler_in_0F_8F_JNLE_Jvds();
    case 0x90:
        return handler_st_0F_90();
    case 0x91:
        return handler_st_0F_91();
    case 0x92:
        return handler_st_0F_92();
    case 0x93:
        return handler_st_0F_93();
    case 0x94:
        return handler_st_0F_94();
    case 0x95:
        return handler_st_0F_95();
    case 0x96:
        return handler_st_0F_96();
    case 0x97:
        return handler_st_0F_97();
    case 0x98:
        return handler_st_0F_98();
    case 0x99:
        return handler_st_0F_99();
    case 0x9a:
        return handler_st_0F_9A();
    case 0x9b:
        return handler_st_0F_9B();
    case 0x9c:
        return handler_st_0F_9C();
    case 0x9d:
        return handler_st_0F_9D();
    case 0x9e:
        return handler_st_0F_9E();
    case 0x9f:
        return handler_st_0F_9F();
    case 0xa0:
        return handler_in_0F_A0_PUSH_FSw();
    case 0xa1:
        return handler_in_0F_A1_POP_FSw();
    case 0xa2:
        return handler_in_0F_A2_CPUID();
    case 0xa3:
        return handler_in_0F_A3_BT_Gvqp();
    case 0xa4:
        return handler_in_0F_A4_SHLD_Evqp_Ib();
    case 0xa5:
        return handler_in_0F_A5_SHLD_Evqp_CLb();
    case 0xa8:
        return handler_in_0F_A8_PUSH_GSw();
    case 0xa9:
        return handler_in_0F_A9_POP_GSw();
    case 0xaa:
        return handler_in_0F_AA_RSM();
    case 0xab:
        return handler_in_0F_AB_BTS_Evqp_Gvqp();
    case 0xac:
        return handler_in_0F_AC_SHRD_Evqp_Ib();
    case 0xad:
        return handler_in_0F_AD_SHRD_Evqp_CLb();
    case 0xaf:
        return handler_in_0F_AF_IMUL_Gvqp_Evqp();
    case 0xb0:
        return handler_in_0F_B0_CMPXCHG_Eb_Gb();
    case 0xb1:
        return handler_in_0F_B1_CMPXCHG_Evqp_Gvqp();
    case 0xb2:
        return handler_in_0F_B2_LSS_Gvqp_Mptp();
    case 0xb3:
        return handler_in_0F_B3_BTR_Evqp_Gvqp();
    case 0xb4:
        return handler_in_0F_B4_LFS_Gvqp_Mptp();
    case 0xb5:
        return handler_in_0F_B5_LGS_Gvqp_Mptp();
    case 0xb6:
        return handler_in_0F_B6_MOVZX_Gvqp_Eb();
    case 0xb7:
        return handler_in_0F_B7_MOVZX_Gvqp_Ew();
    case 0xba:
        return handler_st_0F_BA();
    case 0xbb:
        return handler_in_0F_BB_BTC_Evqp_Gvqp();
    case 0xbc:
        return handler_in_0F_BC_BSF_Gvqp_Evqp();
    case 0xbd:
        return handler_in_0F_BD_BSR_Gvqp_Evqp();
    case 0xbe:
        return handler_in_0F_BE_MOVSX_Gvqp_Eb();
    case 0xbf:
        return handler_in_0F_BF_MOVSX_Gvqp_Ew();
    case 0xc0:
        return handler_in_0F_C0_XADD_Gb();
    case 0xc1:
        return handler_in_0F_C1_XADD_Gvqp();
    case 0xc8:
        return handler_in_0F_C8_BSWAP_rAXvqp();
    case 0xc9:
        return handler_in_0F_C9_BSWAP_rCXvqp();
    case 0xca:
        return handler_in_0F_CA_BSWAP_rDXvqp();
    case 0xcb:
        return handler_in_0F_CB_BSWAP_rBXvqp();
    case 0xcc:
        return handler_in_0F_CC_BSWAP_rSPvqp();
    case 0xcd:
        return handler_in_0F_CD_BSWAP_rBPvqp();
    case 0xce:
        return handler_in_0F_CE_BSWAP_rSIvqp();
    case 0xcf:
        return handler_in_0F_CF_BSWAP_rDIvqp();

    default:
        break;
    };
    return false;
};

/*  */
inline bool CpuRunnerLLVM::handler_st_0F_00() {
    auto rmmod = Fetch<Bit8u>();

    auto rm = static_cast<Bit8u>(rmmod & 0x38u);
    auto mod = static_cast<Bit8u>(rmmod & 0xc0u);

    switch(rm) {
    case 0x00:
        if (mod != 0xc0)
            return handler_in_0F_00_00_SLDT_Mw();
    case 0x01:
        if (mod != 0xc0)
            return handler_in_0F_00_01_STR_Mw();
    case 0x02:
        return handler_in_0F_00_02_LLDT_Ew();
    case 0x03:
        return handler_in_0F_00_03_LTR_Ew();
    case 0x04:
        return handler_in_0F_00_04_VERR_Ew();
    case 0x05:
        return handler_in_0F_00_05_VERW_Ew();

    default:
        break;
    };
    return false;
};

/*  */
inline bool CpuRunnerLLVM::handler_st_0F_01() {
    auto rmmod = Fetch<Bit8u>();

    auto rm = static_cast<Bit8u>(rmmod & 0x38u);
    auto mod = static_cast<Bit8u>(rmmod & 0xc0u);

    switch(rm) {
    case 0x00:
        return handler_in_0F_01_00_SGDT_Ms();
    case 0x01:
        return handler_in_0F_01_01_SIDT_Ms();
    case 0x02:
        return handler_in_0F_01_02_LGDT_Ms();
    case 0x03:
        return handler_in_0F_01_03_LIDT_Ms();
    case 0x04:
        if (mod != 0xc0)
            return handler_in_0F_01_04_SMSW_Mw();
    case 0x06:
        return handler_in_0F_01_06_LMSW_Ew();
    case 0x07:
        return handler_in_0F_01_07_INVLPG();

    default:
        break;
    };
    return false;
};

/*  */
inline bool CpuRunnerLLVM::handler_st_0F_90() {
    auto rmmod = Fetch<Bit8u>();

    auto rm = static_cast<Bit8u>(rmmod & 0x38u);

    switch(rm) {
    case 0x00:
        return handler_in_0F_90_00_SETO_Eb();

    default:
        break;
    };
    return false;
};

/*  */
inline bool CpuRunnerLLVM::handler_st_0F_91() {
    auto rmmod = Fetch<Bit8u>();

    auto rm = static_cast<Bit8u>(rmmod & 0x38u);

    switch(rm) {
    case 0x00:
        return handler_in_0F_91_00_SETNO_Eb();

    default:
        break;
    };
    return false;
};

/*  */
inline bool CpuRunnerLLVM::handler_st_0F_92() {
    auto rmmod = Fetch<Bit8u>();

    auto rm = static_cast<Bit8u>(rmmod & 0x38u);

    switch(rm) {
    case 0x00:
        return handler_in_0F_92_00_SETB_Eb();

    default:
        break;
    };
    return false;
};

/*  */
inline bool CpuRunnerLLVM::handler_st_0F_93() {
    auto rmmod = Fetch<Bit8u>();

    auto rm = static_cast<Bit8u>(rmmod & 0x38u);

    switch(rm) {
    case 0x00:
        return handler_in_0F_93_00_SETNB_Eb();

    default:
        break;
    };
    return false;
};

/*  */
inline bool CpuRunnerLLVM::handler_st_0F_94() {
    auto rmmod = Fetch<Bit8u>();

    auto rm = static_cast<Bit8u>(rmmod & 0x38u);

    switch(rm) {
    case 0x00:
        return handler_in_0F_94_00_SETZ_Eb();

    default:
        break;
    };
    return false;
};

/*  */
inline bool CpuRunnerLLVM::handler_st_0F_95() {
    auto rmmod = Fetch<Bit8u>();

    auto rm = static_cast<Bit8u>(rmmod & 0x38u);

    switch(rm) {
    case 0x00:
        return handler_in_0F_95_00_SETNZ_Eb();

    default:
        break;
    };
    return false;
};

/*  */
inline bool CpuRunnerLLVM::handler_st_0F_96() {
    auto rmmod = Fetch<Bit8u>();

    auto rm = static_cast<Bit8u>(rmmod & 0x38u);

    switch(rm) {
    case 0x00:
        return handler_in_0F_96_00_SETBE_Eb();

    default:
        break;
    };
    return false;
};

/*  */
inline bool CpuRunnerLLVM::handler_st_0F_97() {
    auto rmmod = Fetch<Bit8u>();

    auto rm = static_cast<Bit8u>(rmmod & 0x38u);

    switch(rm) {
    case 0x00:
        return handler_in_0F_97_00_SETNBE_Eb();

    default:
        break;
    };
    return false;
};

/*  */
inline bool CpuRunnerLLVM::handler_st_0F_98() {
    auto rmmod = Fetch<Bit8u>();

    auto rm = static_cast<Bit8u>(rmmod & 0x38u);

    switch(rm) {
    case 0x00:
        return handler_in_0F_98_00_SETS_Eb();

    default:
        break;
    };
    return false;
};

/*  */
inline bool CpuRunnerLLVM::handler_st_0F_99() {
    auto rmmod = Fetch<Bit8u>();

    auto rm = static_cast<Bit8u>(rmmod & 0x38u);

    switch(rm) {
    case 0x00:
        return handler_in_0F_99_00_SETNS_Eb();

    default:
        break;
    };
    return false;
};

/*  */
inline bool CpuRunnerLLVM::handler_st_0F_9A() {
    auto rmmod = Fetch<Bit8u>();

    auto rm = static_cast<Bit8u>(rmmod & 0x38u);

    switch(rm) {
    case 0x00:
        return handler_in_0F_9A_00_SETP_Eb();

    default:
        break;
    };
    return false;
};

/*  */
inline bool CpuRunnerLLVM::handler_st_0F_9B() {
    auto rmmod = Fetch<Bit8u>();

    auto rm = static_cast<Bit8u>(rmmod & 0x38u);

    switch(rm) {
    case 0x00:
        return handler_in_0F_9B_00_SETNP_Eb();

    default:
        break;
    };
    return false;
};

/*  */
inline bool CpuRunnerLLVM::handler_st_0F_9C() {
    auto rmmod = Fetch<Bit8u>();

    auto rm = static_cast<Bit8u>(rmmod & 0x38u);

    switch(rm) {
    case 0x00:
        return handler_in_0F_9C_00_SETL_Eb();

    default:
        break;
    };
    return false;
};

/*  */
inline bool CpuRunnerLLVM::handler_st_0F_9D() {
    auto rmmod = Fetch<Bit8u>();

    auto rm = static_cast<Bit8u>(rmmod & 0x38u);

    switch(rm) {
    case 0x00:
        return handler_in_0F_9D_00_SETNL_Eb();

    default:
        break;
    };
    return false;
};

/*  */
inline bool CpuRunnerLLVM::handler_st_0F_9E() {
    auto rmmod = Fetch<Bit8u>();

    auto rm = static_cast<Bit8u>(rmmod & 0x38u);

    switch(rm) {
    case 0x00:
        return handler_in_0F_9E_00_SETLE_Eb();

    default:
        break;
    };
    return false;
};

/*  */
inline bool CpuRunnerLLVM::handler_st_0F_9F() {
    auto rmmod = Fetch<Bit8u>();

    auto rm = static_cast<Bit8u>(rmmod & 0x38u);

    switch(rm) {
    case 0x00:
        return handler_in_0F_9F_00_SETNLE_Eb();

    default:
        break;
    };
    return false;
};

/*  */
inline bool CpuRunnerLLVM::handler_st_0F_BA() {
    auto rmmod = Fetch<Bit8u>();

    auto rm = static_cast<Bit8u>(rmmod & 0x38u);

    switch(rm) {
    case 0x04:
        return handler_in_0F_BA_04_BT_Ib();
    case 0x05:
        return handler_in_0F_BA_05_BTS_Evqp_Ib();
    case 0x06:
        return handler_in_0F_BA_06_BTR_Evqp_Ib();
    case 0x07:
        return handler_in_0F_BA_07_BTC_Evqp_Ib();

    default:
        break;
    };
    return false;
};

/*  */
inline bool CpuRunnerLLVM::handler_st_81() {
    auto rmmod = Fetch<Bit8u>();

    auto rm = static_cast<Bit8u>(rmmod & 0x38u);

    switch(rm) {
    case 0x00:
        return handler_in_81_00_ADD_Evqp_Ivds();
    case 0x01:
        return handler_in_81_01_OR_Evqp_Ivds();
    case 0x02:
        return handler_in_81_02_ADC_Evqp_Ivds();
    case 0x03:
        return handler_in_81_03_SBB_Evqp_Ivds();
    case 0x04:
        return handler_in_81_04_AND_Evqp_Ivds();
    case 0x05:
        return handler_in_81_05_SUB_Evqp_Ivds();
    case 0x06:
        return handler_in_81_06_XOR_Evqp_Ivds();
    case 0x07:
        return handler_in_81_07_CMP_Ivds();

    default:
        break;
    };
    return false;
};

/*  */
inline bool CpuRunnerLLVM::handler_st_82() {
    auto rmmod = Fetch<Bit8u>();

    auto rm = static_cast<Bit8u>(rmmod & 0x38u);

    switch(rm) {
    case 0x00:
        return handler_in_82_00_ADD_Eb_Ib();
    case 0x01:
        return handler_in_82_01_OR_Eb_Ib();
    case 0x02:
        return handler_in_82_02_ADC_Eb_Ib();
    case 0x03:
        return handler_in_82_03_SBB_Eb_Ib();
    case 0x04:
        return handler_in_82_04_AND_Eb_Ib();
    case 0x05:
        return handler_in_82_05_SUB_Eb_Ib();
    case 0x06:
        return handler_in_82_06_XOR_Eb_Ib();
    case 0x07:
        return handler_in_82_07_CMP_Ib();

    default:
        break;
    };
    return false;
};

/*  */
inline bool CpuRunnerLLVM::handler_st_83() {
    auto rmmod = Fetch<Bit8u>();

    auto rm = static_cast<Bit8u>(rmmod & 0x38u);

    switch(rm) {
    case 0x00:
        return handler_in_83_00_ADD_Evqp_Ibs();
    case 0x01:
        return handler_in_83_01_OR_Evqp_Ibs();
    case 0x02:
        return handler_in_83_02_ADC_Evqp_Ibs();
    case 0x03:
        return handler_in_83_03_SBB_Evqp_Ibs();
    case 0x04:
        return handler_in_83_04_AND_Evqp_Ibs();
    case 0x05:
        return handler_in_83_05_SUB_Evqp_Ibs();
    case 0x06:
        return handler_in_83_06_XOR_Evqp_Ibs();
    case 0x07:
        return handler_in_83_07_CMP_Ibs();

    default:
        break;
    };
    return false;
};

/*  */
inline bool CpuRunnerLLVM::handler_st_8F() {
    auto rmmod = Fetch<Bit8u>();

    auto rm = static_cast<Bit8u>(rmmod & 0x38u);

    switch(rm) {
    case 0x00:
        return handler_in_8F_00_POP_Ev();

    default:
        break;
    };
    return false;
};

/*  */
inline bool CpuRunnerLLVM::handler_st_C0() {
    auto rmmod = Fetch<Bit8u>();

    auto rm = static_cast<Bit8u>(rmmod & 0x38u);

    switch(rm) {
    case 0x00:
        return handler_in_C0_00_ROL_Eb_Ib();
    case 0x01:
        return handler_in_C0_01_ROR_Eb_Ib();
    case 0x02:
        return handler_in_C0_02_RCL_Eb_Ib();
    case 0x03:
        return handler_in_C0_03_RCR_Eb_Ib();
    case 0x04:
        return handler_in_C0_04_SHL_Eb_Ib();
    case 0x05:
        return handler_in_C0_05_SHR_Eb_Ib();
    case 0x06:
        return handler_in_C0_06_SAL_Eb_Ib();
    case 0x07:
        return handler_in_C0_07_SAR_Eb_Ib();

    default:
        break;
    };
    return false;
};

/*  */
inline bool CpuRunnerLLVM::handler_st_C1() {
    auto rmmod = Fetch<Bit8u>();

    auto rm = static_cast<Bit8u>(rmmod & 0x38u);

    switch(rm) {
    case 0x00:
        return handler_in_C1_00_ROL_Evqp_Ib();
    case 0x01:
        return handler_in_C1_01_ROR_Evqp_Ib();
    case 0x02:
        return handler_in_C1_02_RCL_Evqp_Ib();
    case 0x03:
        return handler_in_C1_03_RCR_Evqp_Ib();
    case 0x04:
        return handler_in_C1_04_SHL_Evqp_Ib();
    case 0x05:
        return handler_in_C1_05_SHR_Evqp_Ib();
    case 0x06:
        return handler_in_C1_06_SAL_Evqp_Ib();
    case 0x07:
        return handler_in_C1_07_SAR_Evqp_Ib();

    default:
        break;
    };
    return false;
};

/*  */
inline bool CpuRunnerLLVM::handler_st_C6() {
    auto rmmod = Fetch<Bit8u>();

    auto rm = static_cast<Bit8u>(rmmod & 0x38u);

    switch(rm) {
    case 0x00:
        return handler_in_C6_00_MOV_Eb_Ib();

    default:
        break;
    };
    return false;
};

/*  */
inline bool CpuRunnerLLVM::handler_st_C7() {
    auto rmmod = Fetch<Bit8u>();

    auto rm = static_cast<Bit8u>(rmmod & 0x38u);

    switch(rm) {
    case 0x00:
        return handler_in_C7_00_MOV_Evqp_Ivds();

    default:
        break;
    };
    return false;
};

/*  */
inline bool CpuRunnerLLVM::handler_st_D0() {
    auto rmmod = Fetch<Bit8u>();

    auto rm = static_cast<Bit8u>(rmmod & 0x38u);

    switch(rm) {
    case 0x00:
        return handler_in_D0_00_ROL_Eb();
    case 0x01:
        return handler_in_D0_01_ROR_Eb();
    case 0x02:
        return handler_in_D0_02_RCL_Eb();
    case 0x03:
        return handler_in_D0_03_RCR_Eb();
    case 0x04:
        return handler_in_D0_04_SHL_Eb();
    case 0x05:
        return handler_in_D0_05_SHR_Eb();
    case 0x06:
        return handler_in_D0_06_SAL_Eb();
    case 0x07:
        return handler_in_D0_07_SAR_Eb();

    default:
        break;
    };
    return false;
};

/*  */
inline bool CpuRunnerLLVM::handler_st_D1() {
    auto rmmod = Fetch<Bit8u>();

    auto rm = static_cast<Bit8u>(rmmod & 0x38u);

    switch(rm) {
    case 0x00:
        return handler_in_D1_00_ROL_Evqp();
    case 0x01:
        return handler_in_D1_01_ROR_Evqp();
    case 0x02:
        return handler_in_D1_02_RCL_Evqp();
    case 0x03:
        return handler_in_D1_03_RCR_Evqp();
    case 0x04:
        return handler_in_D1_04_SHL_Evqp();
    case 0x05:
        return handler_in_D1_05_SHR_Evqp();
    case 0x06:
        return handler_in_D1_06_SAL_Evqp();
    case 0x07:
        return handler_in_D1_07_SAR_Evqp();

    default:
        break;
    };
    return false;
};

/*  */
inline bool CpuRunnerLLVM::handler_st_D2() {
    auto rmmod = Fetch<Bit8u>();

    auto rm = static_cast<Bit8u>(rmmod & 0x38u);

    switch(rm) {
    case 0x00:
        return handler_in_D2_00_ROL_Eb_CLb();
    case 0x01:
        return handler_in_D2_01_ROR_Eb_CLb();
    case 0x02:
        return handler_in_D2_02_RCL_Eb_CLb();
    case 0x03:
        return handler_in_D2_03_RCR_Eb_CLb();
    case 0x04:
        return handler_in_D2_04_SHL_Eb_CLb();
    case 0x05:
        return handler_in_D2_05_SHR_Eb_CLb();
    case 0x06:
        return handler_in_D2_06_SAL_Eb_CLb();
    case 0x07:
        return handler_in_D2_07_SAR_Eb_CLb();

    default:
        break;
    };
    return false;
};

/*  */
inline bool CpuRunnerLLVM::handler_st_D3() {
    auto rmmod = Fetch<Bit8u>();

    auto rm = static_cast<Bit8u>(rmmod & 0x38u);

    switch(rm) {
    case 0x00:
        return handler_in_D3_00_ROL_Evqp_CLb();
    case 0x01:
        return handler_in_D3_01_ROR_Evqp_CLb();
    case 0x02:
        return handler_in_D3_02_RCL_Evqp_CLb();
    case 0x03:
        return handler_in_D3_03_RCR_Evqp_CLb();
    case 0x04:
        return handler_in_D3_04_SHL_Evqp_CLb();
    case 0x05:
        return handler_in_D3_05_SHR_Evqp_CLb();
    case 0x06:
        return handler_in_D3_06_SAL_Evqp_CLb();
    case 0x07:
        return handler_in_D3_07_SAR_Evqp_CLb();

    default:
        break;
    };
    return false;
};

/*  */
inline bool CpuRunnerLLVM::handler_st_F3() {
    auto rmmod = Fetch<Bit8u>();

    switch(rmmod) {
    case 0x90:
        return handler_in_F3_90_NOP();

    default:
        break;
    };
    return false;
};

/*  */
inline bool CpuRunnerLLVM::handler_st_F6() {
    auto rmmod = Fetch<Bit8u>();

    auto rm = static_cast<Bit8u>(rmmod & 0x38u);

    switch(rm) {
    case 0x01:
        return handler_in_F6_01_TEST_Ib();
    case 0x02:
        return handler_in_F6_02_NOT_Eb();
    case 0x03:
        return handler_in_F6_03_NEG_Eb();
    case 0x04:
        return handler_in_F6_04_MUL_Eb();
    case 0x05:
        return handler_in_F6_05_IMUL_Eb();
    case 0x06:
        return handler_in_F6_06_DIV_Eb();
    case 0x07:
        return handler_in_F6_07_IDIV_Eb();

    default:
        break;
    };
    return false;
};

/*  */
inline bool CpuRunnerLLVM::handler_st_F7() {
    auto rmmod = Fetch<Bit8u>();

    auto rm = static_cast<Bit8u>(rmmod & 0x38u);

    switch(rm) {
    case 0x01:
        return handler_in_F7_01_TEST_Ivqp();
    case 0x02:
        return handler_in_F7_02_NOT_Evqp();
    case 0x03:
        return handler_in_F7_03_NEG_Evqp();
    case 0x04:
        return handler_in_F7_04_MUL_Evqp();
    case 0x05:
        return handler_in_F7_05_IMUL_Evqp();
    case 0x06:
        return handler_in_F7_06_DIV_Evqp();
    case 0x07:
        return handler_in_F7_07_IDIV_Evqp();

    default:
        break;
    };
    return false;
};

/*  */
inline bool CpuRunnerLLVM::handler_st_FE() {
    auto rmmod = Fetch<Bit8u>();

    auto rm = static_cast<Bit8u>(rmmod & 0x38u);

    switch(rm) {
    case 0x00:
        return handler_in_FE_00_INC_Eb();
    case 0x01:
        return handler_in_FE_01_DEC_Eb();

    default:
        break;
    };
    return false;
};

/*  */
inline bool CpuRunnerLLVM::handler_st_FF() {
    auto rmmod = Fetch<Bit8u>();

    auto rm = static_cast<Bit8u>(rmmod & 0x38u);

    switch(rm) {
    case 0x00:
        return handler_in_FF_00_INC_Evqp();
    case 0x01:
        return handler_in_FF_01_DEC_Evqp();
    case 0x02:
        return handler_in_FF_02_CALL_Ev();
    case 0x03:
        return handler_in_FF_03_CALLF_Mptp();
    case 0x04:
        return handler_in_FF_04_JMP_Ev();
    case 0x05:
        return handler_in_FF_05_JMPF_Mptp();
    case 0x06:
        return handler_in_FF_06_PUSH_Ev();

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
        insb = Fetch<Bit8u>();
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
    return handler_s0(insb);
}

}

