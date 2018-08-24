project("dosbox" C CXX)

set(${project}, "")

if(WINDRES)
    list(APPEND ${project}_SOURCES
        winres.rc
    )
endif()

list(APPEND ${project}_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/dosbox.cpp
)

list(APPEND ${project}_SOURCES
    ${CMAKE_SOURCE_DIR}/include/config.h
    ${CMAKE_SOURCE_DIR}/include/dosbox.h
    ${CMAKE_SOURCE_DIR}/include/bios.h
    ${CMAKE_SOURCE_DIR}/include/bios_disk.h
    ${CMAKE_SOURCE_DIR}/include/callback.h
    ${CMAKE_SOURCE_DIR}/include/control.h
    ${CMAKE_SOURCE_DIR}/include/cpu.h
    ${CMAKE_SOURCE_DIR}/include/cross.h
    ${CMAKE_SOURCE_DIR}/include/debug.h
    ${CMAKE_SOURCE_DIR}/include/dma.h
    ${CMAKE_SOURCE_DIR}/include/dos_inc.h
    ${CMAKE_SOURCE_DIR}/include/dos_system.h
    ${CMAKE_SOURCE_DIR}/include/fpu.h
    ${CMAKE_SOURCE_DIR}/include/hardware.h
    ${CMAKE_SOURCE_DIR}/include/inout.h
    ${CMAKE_SOURCE_DIR}/include/ipx.h
    ${CMAKE_SOURCE_DIR}/include/ipxserver.h
    ${CMAKE_SOURCE_DIR}/include/joystick.h
    ${CMAKE_SOURCE_DIR}/include/keyboard.h
    ${CMAKE_SOURCE_DIR}/include/llvm.h
    ${CMAKE_SOURCE_DIR}/include/logging.h
    ${CMAKE_SOURCE_DIR}/include/mapper.h
    ${CMAKE_SOURCE_DIR}/include/mem.h
    ${CMAKE_SOURCE_DIR}/include/midi.h
    ${CMAKE_SOURCE_DIR}/include/mixer.h
    ${CMAKE_SOURCE_DIR}/include/modules.h
    ${CMAKE_SOURCE_DIR}/include/mouse.h
    ${CMAKE_SOURCE_DIR}/include/paging.h
    ${CMAKE_SOURCE_DIR}/include/pci_bus.h
    ${CMAKE_SOURCE_DIR}/include/pic.h
    ${CMAKE_SOURCE_DIR}/include/programs.h
    ${CMAKE_SOURCE_DIR}/include/regs.h
    ${CMAKE_SOURCE_DIR}/include/render.h
    ${CMAKE_SOURCE_DIR}/include/serialport.h
    ${CMAKE_SOURCE_DIR}/include/setup.h
    ${CMAKE_SOURCE_DIR}/include/shell.h
    ${CMAKE_SOURCE_DIR}/include/support.h
    ${CMAKE_SOURCE_DIR}/include/timer.h
    ${CMAKE_SOURCE_DIR}/include/vga.h
    ${CMAKE_SOURCE_DIR}/include/video.h
)

add_executable(dosbox ${${project}_SOURCES} )

if(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    find_library(COCOA_LIB Cocoa)
    find_library(APPKIT_LIB AppKit)
    find_library(COREMIDI_LIB CoreMIDI)
    find_library(AUDIO_UNIT_LIB AudioUnit)
    find_library(AUDIO_TOOLBOX_LIB AudioToolbox)
    target_link_libraries( dosbox ${COCOA_LIB} ${APPKIT_LIB} ${COREMIDI_LIB} ${AUDIO_UNIT_LIB} ${AUDIO_TOOLBOX_LIB} )
elseif(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    #TODO Add Linux libraries
elseif(CMAKE_SYSTEM_NAME STREQUAL "Windows")
    #TODO Add Windows libraries
endif()

add_subdirectory( cpu )
add_subdirectory( debug )
add_subdirectory( dos )
add_subdirectory( fpu )
add_subdirectory( gui )
add_subdirectory( hardware )
add_subdirectory( libs )
add_subdirectory( llvm )
add_subdirectory( ints )
add_subdirectory( misc )
add_subdirectory( shell )
add_subdirectory( platform )

target_link_libraries( dosbox
    dosbox_cpu
    dosbox_debug
    dosbox_dos
    dosbox_fpu
    dosbox_hardware
    dosbox_gui
    dosbox_ints
    dosbox_llvm
    dosbox_misc
    dosbox_shell
    dosbox_serial
    dosbox_mame
    dosbox_gui_tk
    dosbox_zmbv
    ${DOSBOX_LIBRARIES}
)
