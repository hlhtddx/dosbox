#include "llvm.h"

namespace LLVM {
	DosMemoryRegion::DosMemoryRegion(DosMemoryRegion* parentRegion, PhysPt startAddress, Bit32u regionSize, const char* regionName)
		: parent(parentRegion)
		, start(startAddress)
		, size(0)
		, name(regionName ? regionName : "")
		, value(nullptr)
	{
	}

	DosMemoryRegion::~DosMemoryRegion()
	{
	}

	bool DosMemoryRegion::SetSize(Bit32u newSize)
	{
		//check if exceeds parent's range
		if (parent->size != 0 && start + newSize > parent->start + parent->size) {
			return false;
		}

		//check if any region exceeds the range
		PhysPt end = start + newSize;
		for (auto iter = subMemoryRegions->begin(); iter != subMemoryRegions->end(); iter++) {
			DosMemoryRegion& region = *iter;
			if (region.start + region.size >= end)
				return false;
		}
		size = newSize;
		return true;
	}

	bool DosMemoryRegion::InsertSubMemRegion(PhysPt startAddress, Bit32u regionSize, const char* regionName)
	{
		if (OutOfRange(startAddress)) {
			return false;
		}

		PhysPt endAddress = startAddress + regionSize;
		for (auto iter = subMemoryRegions->rbegin(); iter != subMemoryRegions->rend(); iter++) {
			DosMemoryRegion& region = *iter;

			//Skip all regions behind new region
			if (region.start > endAddress) {
				continue;
			}

			//The region insects to new region
			if (region.GetEndAddress() > startAddress) {
				return false;
			}

			break;

		}

		DosMemoryRegion newRegion(this, startAddress, regionSize, regionName);
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
