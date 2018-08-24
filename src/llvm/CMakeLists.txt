# Generating the library libmisc.a
set(project "dosbox_llvm")

set(${project}, "")
list(APPEND ${project}_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/llvm.cpp
)
add_library ( dosbox_llvm STATIC ${${project}_SOURCES} )
