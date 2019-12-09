cmake_minimum_required(VERSION 3.15)
project(projet)

set(CMAKE_CXX_STANDARD 14)

set(HEADER_FILES
        Polynomial_approximation.h
        )

set(SOURCE_FILES
        Polynomial_approximation.cpp
        )
add_library(Data_approximation STATIC ${SOURCE_FILES} ${HEADER_FILES})