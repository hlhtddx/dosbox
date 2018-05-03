#pragma once

#include <dosbox.h>
#include <string>
#include <map>

#include "llvm/IR/BasicBlock.h"
#include "llvm/IR/Constants.h"
#include "llvm/IR/DerivedTypes.h"
#include "llvm/IR/Function.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
#include "llvm/IR/Type.h"
#include "llvm/IR/Verifier.h"
using namespace llvm;

namespace LLVM {
	class CachedModule;

	class CachedFunction
	{
	public:
		CachedFunction(CachedModule* module, Bitu u_startAddress, const char* u_name);
		~CachedFunction();

	private:
		Bitu startAddress;
		Bitu sizeLimit;
		std::string name;
	};

	class CachedModule
	{
	public:
		CachedModule();
		~CachedModule();

		Module* GetModule() {
			return llvmModule.get();
		}

	private:
		LLVMContext llvmContext;
		IRBuilder<> llvmBuilder;
		std::unique_ptr<Module> llvmModule;
	};
}
