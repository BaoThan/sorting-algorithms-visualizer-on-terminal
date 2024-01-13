cmake_minimum_required(VERSION 2.8)
project(TERMSORT)

set (CMAKE_CXX_STANDARD 11)

add_subdirectory(src)
add_subdirectory(test)

enable_testing()
add_test(NAME TestSort COMMAND TestSort)
