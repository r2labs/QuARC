cmake_minimum_required(VERSION 2.8.7)

if(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
  set(CMAKE_CXX_FLAGS "-std=c++11")
else(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
  set(CMAKE_CXX_FLAGS "-std=c++11")
endif()

option(ENABLE_PROFILING "Enable profiling build options" OFF)
option(ENABLE_PEDANTIC "Enable pedantic and Wall" ON)

if(ENABLE_PROFILING)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")
endif()

if(ENABLE_PEDANTIC)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pedantic -Wall -Wextra -Werror")
endif()

include_directories("/opt/local/include")
include_directories("lib")

add_subdirectory(lib)
add_subdirectory(tests)
