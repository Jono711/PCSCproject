cmake_minimum_required(VERSION 3.15)
project(projet)

set(CMAKE_CXX_STANDARD 14)

set(HEADER_FILES
        LeastSquares.h
        )

set(SOURCE_FILES
        LeastSquares.cpp
        )
add_library(Data_Fitting STATIC ${SOURCE_FILES} ${HEADER_FILES})