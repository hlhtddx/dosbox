cmake_minimum_required(VERSION 2.8)

# Option to with alsa midi support (default yes)
option( ALSA_MIDI "with alsa midi support (default yes)" OFF )
# Option to inlined memory handling in CPU Core
option( CORE_INLINE "inlined memory handling in CPU Core" OFF )
# Option to ddraw support
option( DDRAW "ddraw support" OFF )
# Option to debug mode
option( DEBUG "debug mode" OFF )
# Option to all dynamic cores
option( DYNAMIC_CORE "all dynamic cores" ON )
# Option to x86 dynamic cpu core
option( DYNAMIC_X86 "x86 dynamic cpu core" ON )
# Option to recompiling cpu core
option( DYNREC "recompiling cpu core" ON )
# Option to fpu support
option( FPU "fpu support" ON )
# Option to x64 assembly fpu core
option( FPU_X64 "x64 assembly fpu core" ON )
# Option to x86 assembly fpu core
option( FPU_X86 "x86 assembly fpu core" ON )
# Option to opengl support
option( OPENGL "opengl support" ON )
# Option to unaligned memory access
option( UNALIGNED_MEMORY "unaligned memory access" ON )
# Option to Enable WINDRES
option( WINDRES "Enable WINDRES" OFF )
# Option to Enable Screenshots
option( SSHOT "Enable Screenshot" ON )

if(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    set(PKG_CONFIG_EXECUTABLE "/opt/local/bin/pkg-config")
endif()
find_package(PkgConfig)

set(TARGET_CPU "X86_64")
add_definitions(-DC_TARGETCPU=${TARGET_CPU})

if( ALSA_MIDI )
    message(" ALSA_MIDI Enabled")
    add_definitions(-DHAVE_ALSA_MIDI=1)
endif( ALSA_MIDI )

if( CORE_INLINE )
    message(" CORE_INLINE Enabled")
    add_definitions(-DC_CORE_INLINE=1)
endif( CORE_INLINE )

if( DDRAW )
    message(" DDRAW Enabled")
    add_definitions(-DC_DDRAW=1)
endif( DDRAW )

if( DEBUG )
    message(" DEBUG Enabled")
    pkg_check_modules(NCURSES ncurses)
    include_directories( ${NCURSES_INCLUDE_DIRS} )
    link_directories( ${NCURSES_LIBRARY_DIRS} )
    set(DOSBOX_LIBRARIES ${DOSBOX_LIBRARIES} ${NCURSES_LIBRARIES} )
    add_definitions(-DC_DEBUG=1)
    add_definitions(-DC_HEAVY_DEBUG=1)
endif( DEBUG )

if( DYNAMIC_CORE )
    message(" DYNAMIC_CORE Enabled for " ${TARGET_CPU})

    if (TARGET_CPU STREQUAL "X86")
        if (DYNAMIC_X86)
            message(" DYNAMIC_X86 Enabled")
            add_definitions(-DC_DYNAMIC_X86=1)
        endif()
    elseif (TARGET_CPU STREQUAL "X86_64")
        if (DYNAMIC_X86)
            message(" DYNAMIC_X86 cannot be enabled for " ${TARGET_CPU} )
        endif()
        if (DYNREC)
            message(" DYNREC Enabled")
            add_definitions(-DC_DYNREC=1)
        endif( )
    endif ()

endif( DYNAMIC_CORE )

if( FPU )
    message(" FPU Enabled")
    add_definitions(-DC_FPU=1)
    add_definitions(-DC_FPU_X86=1)
endif( FPU )

if( FPU_X64 )
    message(" FPU_X64 Enabled")
    add_definitions(-DC_FPU=1)
    add_definitions(-DC_FPU_X86=1)
endif( FPU_X64 )

if( FPU_X86 )
    message(" FPU_X86 Enabled")
    add_definitions(-DC_FPU=1)
    add_definitions(-DC_FPU_X86=1)
endif( FPU_X86 )

if( OPENGL )
    message(" OPENGL Enabled")
    add_definitions(-DC_OPENGL=1)
endif( OPENGL )

if( UNALIGNED_MEMORY )
    message(" UNALIGNED_MEMORY Enabled")
    add_definitions(-DC_UNALIGNED_MEMORY=1)
endif( UNALIGNED_MEMORY )

if( WINDRES )
    message(" WINDRES Enabled")
    add_definitions(-DHAVE_WINDRES=1)
endif( WINDRES )

if( SSHOT )
    message(" SSHOT Enable")
    add_definitions(-DC_SSHOT=1)
    pkg_check_modules(PNG REQUIRED libpng zlib)
    include_directories( ${PNG_INCLUDE_DIRS} )
    link_directories( ${PNG_LIBRARY_DIRS} )
    set(DOSBOX_LIBRARIES ${DOSBOX_LIBRARIES} ${PNG_LIBRARIES} )
endif(SSHOT)

FIND_LIBRARY(SDL_SND_LIBRARY SDL_sound)
if( SDL_SND_LIBRARY )
    add_definitions(-DC_SDL_SOUND=1)
    set(DOSBOX_LIBRARIES ${DOSBOX_LIBRARIES} ${SDL_SND_LIBRARY} )
endif( SDL_SND_LIBRARY )

pkg_check_modules(SDL_NET REQUIRED sdl<=1.2.99 sdl_net<=1.2.99)
if (SDL_NET_FOUND)
    set(DOSBOX_LIBRARIES ${DOSBOX_LIBRARIES} ${SDL_NET_LIBRARIES} )
    include_directories(${SDL_NET_INCLUDE_DIRS})
    link_directories(${SDL_NET_LIBRARY_DIRS})
    add_definitions(${SDL_NET_CFLAGS})
    add_definitions(-DC_IPX=1)
    add_definitions(-DC_MODEM=1)
endif(SDL_NET_FOUND)

#file(APPEND ${CONFIG_H} "#define C_X11_XKB 1 \n\n ")

if(CMAKE_SYSTEM_NAME STREQUAL "Darwin")
    add_definitions(-DC_DIRECTSERIAL=1)
    add_definitions(-DMACOSX=1)
    add_definitions(-DDB_HAVE_CLOCK_GETTIME=1)
elseif(CMAKE_SYSTEM_NAME STREQUAL "Linux")
    add_definitions(-DC_DIRECTSERIAL=1)
    add_definitions(-DLINUX=1)
    add_definitions(-DDB_HAVE_CLOCK_GETTIME=1)
endif()

include_directories( ${CMAKE_SOURCE_DIR}/include )

add_subdirectory( src )
add_subdirectory( docs )
