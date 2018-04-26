cmake_minimum_required(VERSION 2.8)
set (project core_dynrec)
set(${project}_SOURCES
	${CMAKE_CURRENT_SOURCE_DIR}/risc_armv4le-o3.h
	${CMAKE_CURRENT_SOURCE_DIR}/risc_armv4le-thumb-iw.h
	${CMAKE_CURRENT_SOURCE_DIR}/risc_x86.h
	${CMAKE_CURRENT_SOURCE_DIR}/dyn_fpu.h
	${CMAKE_CURRENT_SOURCE_DIR}/operators.h
	${CMAKE_CURRENT_SOURCE_DIR}/risc_armv4le-thumb-niw.h
	${CMAKE_CURRENT_SOURCE_DIR}/decoder.h
	${CMAKE_CURRENT_SOURCE_DIR}/cache.h
	${CMAKE_CURRENT_SOURCE_DIR}/risc_mipsel32.h
	${CMAKE_CURRENT_SOURCE_DIR}/risc_armv4le.h
	${CMAKE_CURRENT_SOURCE_DIR}/risc_armv4le-thumb.h
	${CMAKE_CURRENT_SOURCE_DIR}/risc_armv4le-common.h
	${CMAKE_CURRENT_SOURCE_DIR}/decoder_basic.h
	${CMAKE_CURRENT_SOURCE_DIR}/decoder_opcodes.h
	${CMAKE_CURRENT_SOURCE_DIR}/risc_x64.h
)
