#include "llvm.h"

namespace LLVM {

Analyzer::Analyzer()
	: m_llvmBuilder(m_llvmContext) {
}

Analyzer::~Analyzer() {

}

void Analyzer::Init() {

}

void Analyzer::Finalize() {

}

void Analyzer::EnterProgram(const char *name, PhysPt start_address) {

}

void Analyzer::LeaveProgram(PhysPt start_address, bool stay_resident) {

}

void Analyzer::EnterFunction(PhysPt start_address, bool int_handler) {

}

void Analyzer::LeaveFunction(PhysPt start_address) {

}

MemoryRegion::MemoryRegion(Analyzer *pAnalyzer)
	: m_pAnalyzer(pAnalyzer) {
}

MemoryRegion::MemoryRegion(Analyzer *pAnalyzer,
						   MemoryRegion *parentRegion,
						   pointer_type startAddress,
						   pointer_type regionSize,
						   const char *regionName)
	: m_pParent(parentRegion),
	  m_nStartAddress(startAddress),
	  m_nEndAddress(startAddress + regionSize),
	  m_strName(regionName ? regionName : ""),
	  m_pLLVMValue(nullptr) {
}

MemoryRegion::~MemoryRegion() {
}

bool MemoryRegion::InsertSubMemRegion(PhysPt startAddress, Bit32u regionSize, const char *regionName) {
	if (!InRange(startAddress)) {
		return false;
	}

	PhysPt endAddress = startAddress + regionSize;
	for (auto iter = subMemoryRegions->rbegin(); iter != subMemoryRegions->rend(); iter++) {
		MemoryRegionPtr region = *iter;

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

	return true;
}

Module::Module(Analyzer *pAnalyzer, const char *name)
	: MemoryRegion(pAnalyzer) {
	llvmModule = llvm::make_unique<llvm::Module>("dosbox", m_pAnalyzer->GetContext());
}

Module::~Module() {
}
}
