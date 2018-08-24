//
// Created by 张航 on 2018/8/25.
//

#ifndef DOSBOX_IR_GEN_H
#define DOSBOX_IR_GEN_H

#ifndef DOSBOX_DOSBOX_H
#include "dosbox.h"
#endif

#include "dos_inc.h"

class IR_Generator {
public:
	IR_Generator() {

	}

	~IR_Generator() {

	}

	virtual void Init() = 0;
	virtual void Finalize() = 0;
	virtual void EnterProgram(PhysPt start_address) = 0;
	virtual void LeaveProgram(PhysPt start_address, bool stay_resident) = 0;
	virtual void EnterFunction(PhysPt start_address, bool int_handler) = 0;
	virtual void LeaveFunction(PhysPt start_address) = 0;

};

#endif //PROJECT_IR_GEN_H
