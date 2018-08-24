# Generating the library libmisc.a
set(project "dosbox_analysis")

if(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    set(LLVM_CMAKE_INC_PATH /opt/local/libexec/llvm-6.0/lib/cmake/llvm)
    message("set LLVM_CMAKE_INC_PATH to " ${LLVM_CMAKE_INC_PATH})
elseif(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    set(LLVM_CMAKE_INC_PATH /usr/lib/llvm-6.0/lib/cmake/llvm)
    message("set LLVM_CMAKE_INC_PATH to " ${LLVM_CMAKE_INC_PATH})
endif()

set(CMAKE_MODULE_PATH
        ${CMAKE_MODULE_PATH}
        ${LLVM_CMAKE_INC_PATH}
        )

include(LLVMConfig)
include(AddLLVM)

if(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    include_directories(/opt/local/libexec/llvm-6.0/include)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    include_directories(/usr/lib/llvm-6.0/include)
endif()


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
