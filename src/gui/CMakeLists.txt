# Generating the library libgui.a
set(project "dosbox_gui")

set(${project}, "")
list(APPEND ${project}_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/dosbox_logo.h
    ${CMAKE_CURRENT_SOURCE_DIR}/dosbox_splash.h
    ${CMAKE_CURRENT_SOURCE_DIR}/midi.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/midi_alsa.h
    ${CMAKE_CURRENT_SOURCE_DIR}/midi_coreaudio.h
    ${CMAKE_CURRENT_SOURCE_DIR}/midi_coremidi.h
    ${CMAKE_CURRENT_SOURCE_DIR}/midi_oss.h
    ${CMAKE_CURRENT_SOURCE_DIR}/midi_win32.h
    ${CMAKE_CURRENT_SOURCE_DIR}/render.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/render_loops.h
    ${CMAKE_CURRENT_SOURCE_DIR}/render_scalers.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/render_scalers.h
    ${CMAKE_CURRENT_SOURCE_DIR}/render_simple.h
    ${CMAKE_CURRENT_SOURCE_DIR}/render_templates.h
    ${CMAKE_CURRENT_SOURCE_DIR}/render_templates_hq.h
    ${CMAKE_CURRENT_SOURCE_DIR}/render_templates_hq2x.h
    ${CMAKE_CURRENT_SOURCE_DIR}/render_templates_hq3x.h
    ${CMAKE_CURRENT_SOURCE_DIR}/render_templates_sai.h
    ${CMAKE_CURRENT_SOURCE_DIR}/sdl_gui.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/sdl_mapper.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/sdlmain.cpp
)
add_library ( dosbox_gui STATIC ${${project}_SOURCES} )
