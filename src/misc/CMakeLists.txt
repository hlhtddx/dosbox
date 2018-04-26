# Generating the library libmisc.a
set(project "dosbox_misc")

set(${project}, "")
list(APPEND ${project}_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/cross.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/messages.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/programs.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/setup.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/support.cpp
)
add_library ( dosbox_misc STATIC ${${project}_SOURCES} )
