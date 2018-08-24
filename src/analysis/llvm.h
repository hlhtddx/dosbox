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

		using DosMemoryRegionPtr = std::shared_ptr<DosMemoryRegion>;
		using DosMemList = std::vector<DosMemoryRegionPtr>;

	public:
		PhysPt GetStartAddress() const {
			return start_address;
		}

		PhysPt GetEndAddress() const {
			return end_address;
		}

		Bitu GetRegionSize() const {
			return end_address - start_address;
		}

		bool SetRegionSize(Bit32u newSize) {
			return false;
		}

		bool InsertSubMemRegion(PhysPt startAddress, Bit32u regionSize = 0, const char* u_name = NULL);

		DosMemoryRegion * GetParent() {
			return parent;
		}
		bool InRange(PhysPt pointer) const {
			return pointer >= start_address && pointer < end_address;
		}

		bool Insects(const DosMemoryRegion& region) const {
			return InRange(region.start_address) || region.InRange(start_address);
		}

	private:
		PhysPt start_address;
		PhysPt end_address;
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
