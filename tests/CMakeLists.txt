find_program(CTEST_MEMORYCHECK_COMMAND NAMES valgrind)
INCLUDE(Dart)

add_subdirectory(distance-projection distance-projection)
add_subdirectory(vector-math vector-math)
