cmake_minimum_required(VERSION 2.8)
set (project dosbox_zmbv)
set(${project}_SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/zmbv.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/zmbv.h
)
add_library(dosbox_${project} STATIC ${${project}_SOURCES} )