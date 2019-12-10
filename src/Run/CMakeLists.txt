cmake_minimum_required(VERSION 3.15)
project(projet)

set(CMAKE_CXX_STANDARD 14)

set(HEADER_FILES
        Run.h
        )

set(SOURCE_FILES
        Run.cpp
        )
add_library(Run STATIC ${SOURCE_FILES} ${HEADER_FILES})
