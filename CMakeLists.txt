# Basic details.
cmake_minimum_required (VERSION 2.8.11)
project (AeonTick)

# Dependencies.
find_package (Curses REQUIRED)

SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -std=c99")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")

add_library(
  libtermkey
  STATIC
  libtermkey-0.17/termkey.c
  libtermkey-0.17/driver-csi.c
  libtermkey-0.17/driver-ti.c
)

include_directories (${CURSES_INCLUDE_DIRS})

add_executable (aeontick game.cpp keyconfig.cpp window.cpp key.cpp termkey.cpp main.cpp)

target_link_libraries (libtermkey ${CURSES_LIBRARIES})
target_link_libraries (aeontick ${CURSES_LIBRARIES})
target_link_libraries (aeontick libtermkey)
