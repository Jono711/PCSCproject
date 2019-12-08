cmake_minimum_required(VERSION 3.15)
project(projet)

set(CMAKE_CXX_STANDARD 14)

add_executable(LeastSquares LeastSquares.h LeastSquares.cpp
        ../Operations/OperatingMatrices.h ../Operations/OperatingMatrices.cpp
        ../Operations/OperatingVectors.h ../Operations/OperatingVectors.cpp)