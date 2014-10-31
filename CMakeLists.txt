# Basic details.
cmake_minimum_required (VERSION 2.8)
project (AeonTick)

# Dependencies.
find_package (Curses REQUIRED)

add_executable(aeontick main.cpp)

include_directories(${CURSES_INCLUDE_DIRS})
target_link_libraries (aeontick ${CURSES_LIBRARIES})
