#pragma once

#include <dosbox.h>
#include <mem.h>
#include <string>
#include <vector>
#include <map>

#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/IR/Module.h"
//#include "llvm/IR/Type.h"
//#include "llvm/IR/Verifier.h"

namespace LLVM {
	class DosModule;

	class DosMemoryRegion
	{
	public:
		DosMemoryRegion() = delete;

		DosMemoryRegion(DosMemoryRegion* parent, PhysPt startAddress, Bit32u regionSize = 0, const char* regionName = NULL);
		~DosMemoryRegion();

		using DosMemList = std::vector<DosMemoryRegion>;

	public:
		PhysPt GetEndAddress() const {
			return start + size;
		}
		bool SetSize(Bit32u newSize);
		bool InsertSubMemRegion(PhysPt startAddress, Bit32u regionSize = 0, const char* u_name = NULL);

		DosMemoryRegion * GetParent() {
			return parent;
		}
		bool OutOfRange(PhysPt pointer) const {
			if (pointer < start) {
				return true;
			}
			if (size > 0 && pointer >= start + size) {
				return true;
			}
			return false;
		}

		bool Insects(const DosMemoryRegion& region) const {
			return !OutOfRange(region.start) || !region.OutOfRange(start);
		}

	private:
		PhysPt start;
		Bit32u size;
		std::string name;
		DosMemoryRegion * parent;
		std::shared_ptr<DosMemList> subMemoryRegions;
		llvm::Value *value;
	};

	class DosModule : public DosMemoryRegion
	{
	public:
		DosModule();
		~DosModule();

		llvm::Module* GetModule() {
			return llvmModule.get();
		}

	private:
		llvm::LLVMContext llvmContext;
		llvm::IRBuilder<> llvmBuilder;
		std::unique_ptr<llvm::Module> llvmModule;
	};
}
