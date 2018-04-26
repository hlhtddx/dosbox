# Generating the library libints.a
set(project "dosbox_ints")

set(${project}, "")
list(APPEND ${project}_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/bios.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/bios_disk.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/bios_keyboard.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ems.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/int10.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/int10.h
    ${CMAKE_CURRENT_SOURCE_DIR}/int10_char.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/int10_memory.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/int10_misc.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/int10_modes.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/int10_pal.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/int10_put_pixel.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/int10_vesa.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/int10_video_state.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/int10_vptable.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/mouse.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/xms.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/xms.h
)
add_library ( dosbox_ints STATIC ${${project}_SOURCES} )
