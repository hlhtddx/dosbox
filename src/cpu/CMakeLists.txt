set(project "dosbox_cpu")

set(${project}, "")
list(APPEND ${project}_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/callback.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/core_dyn_x86.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/core_dynrec.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/core_full.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/core_normal.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/core_prefetch.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/core_simple.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/core_llvm.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/cpu.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/flags.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/instructions.h
    ${CMAKE_CURRENT_SOURCE_DIR}/lazyflags.h
    ${CMAKE_CURRENT_SOURCE_DIR}/modrm.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/modrm.h
    ${CMAKE_CURRENT_SOURCE_DIR}/paging.cpp
)

list(APPEND ${project}_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/core_full/loadwrite.h
    ${CMAKE_CURRENT_SOURCE_DIR}/core_full/ea_lookup.h
    ${CMAKE_CURRENT_SOURCE_DIR}/core_full/op.h
    ${CMAKE_CURRENT_SOURCE_DIR}/core_full/load.h
    ${CMAKE_CURRENT_SOURCE_DIR}/core_full/save.h
    ${CMAKE_CURRENT_SOURCE_DIR}/core_full/optable.h
    ${CMAKE_CURRENT_SOURCE_DIR}/core_full/string.h
    ${CMAKE_CURRENT_SOURCE_DIR}/core_full/support.h
)

list(APPEND ${project}_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/core_normal/prefix_none.h
    ${CMAKE_CURRENT_SOURCE_DIR}/core_normal/prefix_66.h
    ${CMAKE_CURRENT_SOURCE_DIR}/core_normal/table_ea.h
    ${CMAKE_CURRENT_SOURCE_DIR}/core_normal/prefix_0f.h
    ${CMAKE_CURRENT_SOURCE_DIR}/core_normal/prefix_66_0f.h
    ${CMAKE_CURRENT_SOURCE_DIR}/core_normal/helpers.h
    ${CMAKE_CURRENT_SOURCE_DIR}/core_normal/string.h
    ${CMAKE_CURRENT_SOURCE_DIR}/core_normal/support.h
)

list(APPEND ${project}_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/core_dyn_x86/risc_x86.h
    ${CMAKE_CURRENT_SOURCE_DIR}/core_dyn_x86/dyn_fpu.h
    ${CMAKE_CURRENT_SOURCE_DIR}/core_dyn_x86/decoder.h
    ${CMAKE_CURRENT_SOURCE_DIR}/core_dyn_x86/cache.h
    ${CMAKE_CURRENT_SOURCE_DIR}/core_dyn_x86/dyn_fpu_dh.h
    ${CMAKE_CURRENT_SOURCE_DIR}/core_dyn_x86/helpers.h
    ${CMAKE_CURRENT_SOURCE_DIR}/core_dyn_x86/string.h
)

list(APPEND ${project}_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/core_dynrec/risc_armv4le-o3.h
    ${CMAKE_CURRENT_SOURCE_DIR}/core_dynrec/risc_armv4le-thumb-iw.h
    ${CMAKE_CURRENT_SOURCE_DIR}/core_dynrec/risc_x86.h
    ${CMAKE_CURRENT_SOURCE_DIR}/core_dynrec/dyn_fpu.h
    ${CMAKE_CURRENT_SOURCE_DIR}/core_dynrec/operators.h
    ${CMAKE_CURRENT_SOURCE_DIR}/core_dynrec/risc_armv4le-thumb-niw.h
    ${CMAKE_CURRENT_SOURCE_DIR}/core_dynrec/decoder.h
    ${CMAKE_CURRENT_SOURCE_DIR}/core_dynrec/cache.h
    ${CMAKE_CURRENT_SOURCE_DIR}/core_dynrec/risc_mipsel32.h
    ${CMAKE_CURRENT_SOURCE_DIR}/core_dynrec/risc_armv4le.h
    ${CMAKE_CURRENT_SOURCE_DIR}/core_dynrec/risc_armv4le-thumb.h
    ${CMAKE_CURRENT_SOURCE_DIR}/core_dynrec/risc_armv4le-common.h
    ${CMAKE_CURRENT_SOURCE_DIR}/core_dynrec/decoder_basic.h
    ${CMAKE_CURRENT_SOURCE_DIR}/core_dynrec/decoder_opcodes.h
    ${CMAKE_CURRENT_SOURCE_DIR}/core_dynrec/risc_x64.h
)

add_library ( dosbox_cpu STATIC ${${project}_SOURCES} core_llvm/core_llvm.h)
