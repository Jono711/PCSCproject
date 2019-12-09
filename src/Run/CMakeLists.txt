cmake_minimum_required(VERSION 3.15)
project(projet)

set(CMAKE_CXX_STANDARD 14)

add_executable(Run Run.h Run.cpp
        ../Output/Output.h ../Output/Output.cpp
        ../Input/Input.h ../Input/Input.cpp
        ../Input/InputCreator/InputCreator.h ../Input/InputCreator/InputCreator.cpp
        ../Input/InputReader/InputReader.h ../Input/InputReader/InputReader.cpp
        ../Operations/OperatingMatrices.h ../Operations/OperatingMatrices.cpp
        ../Operations/OperatingVectors.h ../Operations/OperatingVectors.cpp
        ../Data_Fitting/LeastSquares.h ../Data_Fitting/LeastSquares.cpp)