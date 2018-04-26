# Generating the library libfpu.a
set(project "dosbox_fpu")

set(${project}, "")
list(APPEND ${project}_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/fpu.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/fpu_instructions.h
    ${CMAKE_CURRENT_SOURCE_DIR}/fpu_instructions_x86.h
)
add_library ( dosbox_fpu STATIC ${${project}_SOURCES} )
