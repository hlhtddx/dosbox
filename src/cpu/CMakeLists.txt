
add_subdirectory( core_full )
add_subdirectory( core_normal )
add_subdirectory( core_dyn_x86 )
add_subdirectory( core_dynrec )# Generating the library libcpu.a
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
    ${CMAKE_CURRENT_SOURCE_DIR}/cpu.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/flags.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/instructions.h
    ${CMAKE_CURRENT_SOURCE_DIR}/lazyflags.h
    ${CMAKE_CURRENT_SOURCE_DIR}/modrm.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/modrm.h
    ${CMAKE_CURRENT_SOURCE_DIR}/paging.cpp
)
add_library ( dosbox_cpu STATIC ${${project}_SOURCES} )
