class Instruction {

private:
    enum DecodeState{
        Start,
        OptionalPrefix,
        MandatoryPrefix,
        Two_Bytes_Escape,
        Two_Bytes_Prefix_Escape,
        Three_Bytes_Escape_38,
        Three_Bytes_Escape_3a,
    };
    enum InstructionMnemonic {
        IllegalInstruction,
    };

    InstructionMnemonic Decode(PhysPt &cseip) {

    }
};
