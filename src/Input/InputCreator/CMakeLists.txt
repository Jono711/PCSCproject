cmake_minimum_required(VERSION 3.15)
project(projet)

set(CMAKE_CXX_STANDARD 14)

set(HEADER_FILES
        InputCreator.h
        )

set(SOURCE_FILES
        InputCreator.cpp
        )
add_library(InputCreator STATIC ${SOURCE_FILES} ${HEADER_FILES})