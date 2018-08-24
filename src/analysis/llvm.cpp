#include "llvm.h"

namespace LLVM {

	Analyzer::Analyzer() {
		m_llvmBuilder =
	}

	Analyzer::~Analyzer() {

	}

	void Analyzer::Init() {
		
	}

	void Analyzer::Finalize() {

	}

	void Analyzer::EnterProgram(const char* name, PhysPt start_address) {

	}

	void Analyzer::LeaveProgram(PhysPt start_address, bool stay_resident) {

	}

	void Analyzer::EnterFunction(PhysPt start_address, bool int_handler) {

	}

	void Analyzer::LeaveFunction(PhysPt start_address) {

	}

	MemoryRegion::MemoryRegion(MemoryRegion* parentRegion, PhysPt startAddress, Bit32u regionSize, const char* regionName)
		: parent(parentRegion)
		, start_address(startAddress)
		, end_address(startAddress + regionSize)
		, name(regionName ? regionName : "")
		, value(nullptr)
	{
	}

	MemoryRegion::~MemoryRegion()
	{
	}

	bool MemoryRegion::InsertSubMemRegion(PhysPt startAddress, Bit32u regionSize, const char* regionName)
	{
		if (!InRange(startAddress)) {
			return false;
		}

		PhysPt endAddress = startAddress + regionSize;
		for (auto iter = subMemoryRegions->rbegin(); iter != subMemoryRegions->rend(); iter++) {
			DosMemoryRegionPtr region = *iter;

			//Skip all regions behind new region
			if (region->GetStartAddress() > endAddress) {
				continue;
			}

			//The region insects to new region
			if (region->GetEndAddress() > startAddress) {
				return false;
			}

			break;
		}

		DosMemoryRegionPtr newRegion(new MemoryRegion(this, startAddress, regionSize, regionName));
		subMemoryRegions->push_back(newRegion);
		return true;
	}

	DosModule::DosModule()
		: llvmBuilder(llvmContext)
		, MemoryRegion(this, 0)
	{
		llvmModule = llvm::make_unique<llvm::Module>("dosbox", llvmContext);
	}

	DosModule::~DosModule()
	{
	}
}
