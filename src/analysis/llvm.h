#pragma once

#include <dosbox.h>
#include <mem.h>
#include <string>
#include <vector>
#include <list>
#include <map>

#include <llvm/IR/IRBuilder.h>
#include <llvm/IR/LLVMContext.h>
#include <llvm/IR/Module.h>
//#include "llvm/IR/Type.h"
//#include "llvm/IR/Verifier.h"

#include "ir_gen.h"

namespace LLVM {
	class Analyzer : IR_Generator {
	public:
		Analyzer();
		~Analyzer();
		virtual void Init();
		virtual void Finalize();
		virtual void EnterProgram(const char* name, PhysPt start_address);
		virtual void LeaveProgram(PhysPt start_address, bool stay_resident);
		virtual void EnterFunction(PhysPt start_address, bool int_handler);
		virtual void LeaveFunction(PhysPt start_address);
	protected:
		llvm::LLVMContext* GetContext() {
			return m_llvmContext;
		}

		llvm::IRBuilder<>* GetBuilder() {
			return m_llvmBuilder;
		}

	private:
		llvm::LLVMContext *m_llvmContext;
		llvm::IRBuilder<> *m_llvmBuilder;
	};

	typedef Bit32u pointer_type;
	class MemoryRegion
	{
	public:
		static const pointer_type invalid_address = static_cast<pointer_type>(-1);
		MemoryRegion();
		MemoryRegion(MemoryRegion* parent, pointer_type startAddress, pointer_type regionSize = 0, const char* regionName = NULL);

		~MemoryRegion();

		using MemoryRegionPtr = std::shared_ptr<MemoryRegion>;
		using MemoryList = std::list<MemoryRegionPtr>;

	public:
		pointer_type GetStartAddress() const {
			return start_address;
		}

		pointer_type GetEndAddress() const {
			return end_address;
		}

		pointer_type GetRegionSize() const {
			return end_address - start_address;
		}

		bool SetRegionSize(pointer_type newSize) {
			return false;
		}

		bool InsertSubMemRegion(pointer_type startAddress, pointer_type regionSize = 0, const char* u_name = NULL);

		MemoryRegion * GetParent() {
			return parent;
		}
		bool InRange(pointer_type pointer) const {
			return pointer >= start_address && pointer < end_address;
		}

		bool Insects(const MemoryRegion& region) const {
			return InRange(region.start_address) || region.InRange(start_address);
		}

	private:
		PhysPt start_address;
		PhysPt end_address;
		std::string name;
		MemoryRegion * parent;
		std::shared_ptr<MemoryList> subMemoryRegions;
		llvm::Value *value;
	};

	class Module : public MemoryRegion
	{
	public:
		Module();
		~Module();

		llvm::Module* GetModule() {
			return llvmModule.get();
		}

	private:
		std::unique_ptr<llvm::Module> llvmModule;
	};

}
