# Generating the library libserial.a
set(project "dosbox_serial")

set(${project}, "")
list(APPEND ${project}_SOURCES
    ${CMAKE_CURRENT_SOURCE_DIR}/directserial.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/directserial.h
    ${CMAKE_CURRENT_SOURCE_DIR}/libserial.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/libserial.h
    ${CMAKE_CURRENT_SOURCE_DIR}/misc_util.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/misc_util.h
    ${CMAKE_CURRENT_SOURCE_DIR}/nullmodem.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/nullmodem.h
    ${CMAKE_CURRENT_SOURCE_DIR}/serialdummy.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/serialdummy.h
    ${CMAKE_CURRENT_SOURCE_DIR}/serialport.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/softmodem.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/softmodem.h
)
add_library ( dosbox_serial STATIC ${${project}_SOURCES} )
