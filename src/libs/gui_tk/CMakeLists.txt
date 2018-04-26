# Generating the library libgui_tk.a
set(project "dosbox_gui_tk")

set(${project}, "")
list(APPEND ${project}_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/gui_tk.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/gui_tk.h
)
add_library ( dosbox_gui_tk STATIC ${${project}_SOURCES} )
