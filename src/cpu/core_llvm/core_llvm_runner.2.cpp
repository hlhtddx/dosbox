#include "core_llvm_runner.h"
namespace core_llvm {

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

}

