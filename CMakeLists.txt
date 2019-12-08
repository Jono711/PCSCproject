cmake_minimum_required(VERSION 3.15)
project(projet)

set(CMAKE_CXX_STANDARD 14)

add_executable(projet main.cpp
        Test_Suites/TestSuite.h Test_Suites/TestSuite.cpp
        Input/Input.h Input/Input.cpp
        Input/InputCreator/InputCreator.h Input/InputCreator/InputCreator.cpp
        Input/InputReader/InputReader.h Input/InputReader/InputReader.cpp
        Operations/OperatingMatrices.h Operations/OperatingMatrices.cpp
        Operations/OperatingVectors.h Operations/OperatingVectors.cpp
        Data_Fitting/LeastSquares.h Data_Fitting/LeastSquares.cpp)
add_subdirectory(Input)
add_subdirectory(Data_Fitting)
add_subdirectory(Operations)
add_subdirectory(Test_Suites)