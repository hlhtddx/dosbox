cmake_minimum_required(VERSION 2.8)
set (project core_full)
set(${project}_SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/loadwrite.h
	${CMAKE_CURRENT_SOURCE_DIR}/ea_lookup.h
	${CMAKE_CURRENT_SOURCE_DIR}/op.h
	${CMAKE_CURRENT_SOURCE_DIR}/load.h
	${CMAKE_CURRENT_SOURCE_DIR}/save.h
	${CMAKE_CURRENT_SOURCE_DIR}/optable.h
	${CMAKE_CURRENT_SOURCE_DIR}/string.h
	${CMAKE_CURRENT_SOURCE_DIR}/support.h
)
