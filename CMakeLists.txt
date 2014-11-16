# Basic details.
cmake_minimum_required (VERSION 2.8.11)
project (AeonTick)

# Dependencies.
find_package (Curses REQUIRED)
find_package (Boost COMPONENTS program_options filesystem system REQUIRED)

set (CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

add_library(
  libtermkey
  STATIC
  libtermkey-0.17/termkey.c
  libtermkey-0.17/driver-csi.c
  libtermkey-0.17/driver-ti.c
)

include_directories (${CURSES_INCLUDE_DIRS})
include_directories (${BOOST_INCLUDE_DIRS})

set(CMAKE_INCLUDE_CURRENT_DIR ON)

SET (BINDIR "bin" CACHE STRING "The directory where the game's binaries will be installed.")
SET (SYSCONFDIR "etc" CACHE STRING "The directory where the game's global settings will be intalled.")
SET (MAINCONFIG_FILENAME "aeontick.ini" CACHE STRING "The file name of the game's primary global config file.")

configure_file (buildvars.cpp.cmake buildvars.cpp @ONLY)

add_executable (aeontick filepaths.cpp buildvars.cpp game.cpp keyconfig.cpp window.cpp key.cpp termkey.cpp main.cpp)

target_link_libraries (libtermkey ${CURSES_LIBRARIES})
target_link_libraries (aeontick ${CURSES_LIBRARIES})
target_link_libraries (aeontick ${Boost_LIBRARIES})
target_link_libraries (aeontick libtermkey)

install (TARGETS aeontick DESTINATION ${BINDIR})
