project(GPPCPP)
cmake_minimum_required(VERSION 2.6.3)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES src/chapter12_example1.cpp)
add_executable(gppcpp ${SOURCE_FILES})