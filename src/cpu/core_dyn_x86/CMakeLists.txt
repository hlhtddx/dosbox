cmake_minimum_required(VERSION 2.8)
set (project core_dyn_x86)
set(${project}_SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/risc_x86.h
	${CMAKE_CURRENT_SOURCE_DIR}/dyn_fpu.h
	${CMAKE_CURRENT_SOURCE_DIR}/decoder.h
	${CMAKE_CURRENT_SOURCE_DIR}/cache.h
	${CMAKE_CURRENT_SOURCE_DIR}/dyn_fpu_dh.h
	${CMAKE_CURRENT_SOURCE_DIR}/helpers.h
	${CMAKE_CURRENT_SOURCE_DIR}/string.h
)
