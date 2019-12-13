cmake_minimum_required(VERSION 3.15)
project(projet)

set(CMAKE_CXX_STANDARD 14)

set(HEADER_FILES
        PolynomialApproximation.h
        )

set(SOURCE_FILES
        PolynomialApproximation.cpp
        )
add_library(Data_approximation STATIC ${SOURCE_FILES} ${HEADER_FILES})