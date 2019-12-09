cmake_minimum_required(VERSION 3.15)
project(projet)

set(CMAKE_CXX_STANDARD 14)

set(HEADER_FILES
        InputReader.h
        )

set(SOURCE_FILES
        InputReader.cpp
        )
add_library(InputReader STATIC ${SOURCE_FILES} ${HEADER_FILES})