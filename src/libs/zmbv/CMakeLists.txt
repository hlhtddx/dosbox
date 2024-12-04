cmake_minimum_required(VERSION 3.10)
set (project dosbox_zmbv)
set(${project}_SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/zmbv.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/zmbv.h
)
add_library( ${project} STATIC ${${project}_SOURCES} )