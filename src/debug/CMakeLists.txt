# Generating the library libdebug.a
set(project "dosbox_debug")

set(${project}, "")
list(APPEND ${project}_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/debug.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/debug_disasm.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/debug_gui.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/debug_inc.h
    ${CMAKE_CURRENT_SOURCE_DIR}/debug_win32.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/disasm_tables.h
)
add_library ( dosbox_debug STATIC ${${project}_SOURCES} )
