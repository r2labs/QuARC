cmake_minimum_required(VERSION 3.0)
set (CMAKE_CXX_FLAGS "-std=c++1y -stdlib=libc++")
# set (CMAKE_CXX_FLAGS_DEBUG "-O0")
include_directories("/opt/local/include")
include_directories("ik")

add_subdirectory(ik libik)
add_subdirectory(distance-projection distance-projection)
