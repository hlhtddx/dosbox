add_subdirectory( cpu )
add_subdirectory( debug )
add_subdirectory( dos )
add_subdirectory( fpu )
add_subdirectory( gui )
add_subdirectory( hardware )
add_subdirectory( libs )
add_subdirectory( ints )
add_subdirectory( misc )
add_subdirectory( shell )
add_subdirectory( platform )

set(project "dosbox")

set(${project}, "")

if(WINDRES)
    list(APPEND ${project}_SOURCES
        winres.rc
    )
endif()

list(APPEND ${project}_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/dosbox.cpp
)

add_executable(dosbox ${${project}_SOURCES} )

target_link_libraries( dosbox
    dosbox_cpu
    dosbox_debug
    dosbox_dos
    dosbox_fpu
    dosbox_hardware
    dosbox_gui
    dosbox_ints
    dosbox_misc
    dosbox_shell
    dosbox_serial
    dosbox_gui_tk
    ${DOSBOX_LIBRARIES}
)
