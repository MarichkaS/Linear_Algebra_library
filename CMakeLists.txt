cmake_minimum_required(VERSION 3.6)
project(Linear_Algebra_library)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Matrix.cpp Matrix.h Vector.cpp Vector.h)
add_executable(Linear_Algebra_library ${SOURCE_FILES})