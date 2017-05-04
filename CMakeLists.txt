cmake_minimum_required(VERSION 3.6)
project(Linear_Algebra_library)

set(CMAKE_CXX_STANDARD 11)
add_subdirectory(lib/googletest-master)

include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

set(SOURCE_FILES Matrix.cpp Matrix.h Vector.cpp Vector.h)
add_executable(Linear_Algebra_library ${SOURCE_FILES} main.cpp)
add_executable(test1 ${SOURCE_FILES} test1_main.cpp)


target_link_libraries(Linear_Algebra_library gtest gtest_main)
target_link_libraries(test1 gtest gtest_main)