# Generating the library libdos.a
set(project "dosbox_dos")

set(${project}, "")
list(APPEND ${project}_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/cdrom.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/cdrom.h
    ${CMAKE_CURRENT_SOURCE_DIR}/cdrom_aspi_win32.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/cdrom_image.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/cdrom_ioctl_linux.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/cdrom_ioctl_os2.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/cdrom_ioctl_win32.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/dev_con.h
    ${CMAKE_CURRENT_SOURCE_DIR}/dos.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/dos_classes.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/dos_devices.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/dos_execute.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/dos_files.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/dos_ioctl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/dos_keyboard_layout.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/dos_memory.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/dos_misc.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/dos_mscdex.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/dos_programs.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/dos_tables.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/drive_cache.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/drive_fat.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/drive_iso.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/drive_local.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/drive_virtual.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/drives.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/drives.h
)
add_library ( dosbox_dos STATIC ${${project}_SOURCES} )
