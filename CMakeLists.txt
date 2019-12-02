cmake_minimum_required(VERSION 3.15)
project(projet)

set(CMAKE_CXX_STANDARD 14)

add_executable(projet main.cpp)
add_subdirectory(Input)
add_subdirectory(Data_Fitting)
add_subdirectory(Operations)