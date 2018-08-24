#include "llvm.h"

namespace LLVM {
	DosMemoryRegion::DosMemoryRegion(DosMemoryRegion* parentRegion, PhysPt startAddress, Bit32u regionSize, const char* regionName)
		: parent(parentRegion)
		, start_address(startAddress)
		, end_address(startAddress + regionSize)
		, name(regionName ? regionName : "")
		, value(nullptr)
	{
	}

	DosMemoryRegion::~DosMemoryRegion()
	{
	}

	bool DosMemoryRegion::InsertSubMemRegion(PhysPt startAddress, Bit32u regionSize, const char* regionName)
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

		DosMemoryRegionPtr newRegion(new DosMemoryRegion(this, startAddress, regionSize, regionName));
		subMemoryRegions->push_back(newRegion);
		return true;
	}

	DosModule::DosModule()
		: llvmBuilder(llvmContext)
		, DosMemoryRegion(this, 0)
	{
		llvmModule = llvm::make_unique<llvm::Module>("dosbox", llvmContext);
	}

	DosModule::~DosModule()
	{
	}
}
