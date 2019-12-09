cmake_minimum_required(VERSION 3.15)
project(projet)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(InputCreator)
add_subdirectory(InputReader)

set(HEADER_FILES
        Input.h
        )

set(SOURCE_FILES
        Input.cpp
        )
add_library(Input STATIC ${SOURCE_FILES} ${HEADER_FILES})