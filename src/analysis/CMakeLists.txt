# Generating the library libmisc.a
set(project "dosbox_analysis")

set(CMAKE_MODULE_PATH
        ${CMAKE_MODULE_PATH}
        /opt/local/libexec/llvm-6.0/lib/cmake/llvm
        )
include(LLVMCOnfig)
include(AddLLVM)

include_directories(/opt/local/libexec/llvm-6.0/include)

set(LLVM_LINK_COMPONENTS
        BitWriter
        Core
        Support
        )

set(${project}, "")
list(APPEND ${project}_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/llvm.h
    ${CMAKE_CURRENT_SOURCE_DIR}/llvm.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ir_gen.cpp
)
add_library ( dosbox_analysis STATIC ${${project}_SOURCES} )
