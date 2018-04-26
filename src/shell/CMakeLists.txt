# Generating the library libshell.a
set(project "dosbox_shell")

set(${project}, "")
list(APPEND ${project}_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/shell.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/shell_batch.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/shell_cmds.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/shell_misc.cpp
)
add_library ( dosbox_shell STATIC ${${project}_SOURCES} )
