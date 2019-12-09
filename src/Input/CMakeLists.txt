cmake_minimum_required(VERSION 3.15)
project(projet)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(InputCreator)
add_subdirectory(InputReader)

add_executable(Input Input.h Input.cpp)