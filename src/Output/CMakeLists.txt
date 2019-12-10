cmake_minimum_required(VERSION 3.15)
project(projet)

set(CMAKE_CXX_STANDARD 14)

set(HEADER_FILES
        Output.h
        )

set(SOURCE_FILES
        Output.cpp
        )
add_library(Output STATIC ${SOURCE_FILES} ${HEADER_FILES})