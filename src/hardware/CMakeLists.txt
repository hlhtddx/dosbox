
add_subdirectory( serialport )# Generating the library libhardware.a
set(project "dosbox_hardware")

set(${project}, "")
list(APPEND ${project}_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/adlib.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/cmos.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/dbopl.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/disney.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/dma.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/gameblaster.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/gus.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/hardware.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/iohandler.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ipx.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/ipxserver.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/joystick.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/keyboard.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/memory.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/mixer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/mpu401.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/pci_bus.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/pcspeaker.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/pic.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/sblaster.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/tandy_sound.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/timer.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/vga.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/vga_attr.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/vga_crtc.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/vga_dac.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/vga_draw.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/vga_gfx.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/vga_memory.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/vga_misc.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/vga_other.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/vga_paradise.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/vga_s3.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/vga_seq.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/vga_tseng.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/vga_xga.cpp
)
add_library ( dosbox_hardware STATIC ${${project}_SOURCES} )
