#include "llvm.h"
#ifndef _DEBUG

namespace LLVM {
	CachedFunction::CachedFunction(CachedModule* module, Bitu u_startAddress, const char* u_name)
		: startAddress(u_startAddress)
		, name(u_name)
	{
		Function* function;
	}

	CachedFunction::~CachedFunction()
	{

	}

	CachedModule::CachedModule()
		: llvmBuilder(llvmContext)
	{
		llvmModule = llvm::make_unique<Module>("dosbox", llvmContext);
	}

	CachedModule::~CachedModule()
	{
	}
}

#endif