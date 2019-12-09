cmake_minimum_required(VERSION 3.15)
project(projet)

set(CMAKE_CXX_STANDARD 14)


set(HEADER_FILES
        OperatingVectors.h
        OperatingMatrices.h
        )

set(SOURCE_FILES
        OperatingVectors.cpp
        OperatingMatrices.cpp
        )
add_library(Operations STATIC ${SOURCE_FILES} ${HEADER_FILES})