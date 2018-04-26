# Generating the library libserial.a
set(project "dosbox_mame")

set(${project}, "")
list(APPEND ${project}_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/emu.h
    ${CMAKE_CURRENT_SOURCE_DIR}/fmopl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/fmopl.h
    ${CMAKE_CURRENT_SOURCE_DIR}/saa1099.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/saa1099.h
    ${CMAKE_CURRENT_SOURCE_DIR}/sn76496.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/sn76496.h
    ${CMAKE_CURRENT_SOURCE_DIR}/ymdeltat.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ymdeltat.h
    ${CMAKE_CURRENT_SOURCE_DIR}/ymf262.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ymf262.h
)
add_library ( dosbox_mame STATIC ${${project}_SOURCES} )
