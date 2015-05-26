project(distance-projection)
set(distance-projection-srcs distance-projection.cpp)
add_executable(distance-projection ${distance-projection-srcs})
target_link_libraries(distance-projection ik)
