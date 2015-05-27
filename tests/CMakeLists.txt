cmake_minimum_required(VERSION 2.8.7)

if(CMAKE_CXX_COMPILER_ID EQUAL "Clang")
  set(CMAKE_CXX_FLAGS "-std=c++1y -stdlib=libc++")
else(CMAKE_CXX_COMPILER_ID EQUAL "GNU")
  set(CMAKE_CXX_FLAGS "-std=c++11")
endif()

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fprofile-arcs -ftest-coverage")

include_directories("/opt/local/include")
include_directories("ik")

add_subdirectory(ik libik)
add_subdirectory(distance-projection distance-projection)
