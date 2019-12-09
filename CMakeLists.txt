cmake_minimum_required(VERSION 3.15)
project(projet)

set(CMAKE_CXX_STANDARD 14)

add_executable(projet main.cpp)

include_directories(src)
add_subdirectory(src)

target_link_libraries(projet Operations)
target_link_libraries(projet Data_Fitting)
target_link_libraries(projet Data_approximation)
target_link_libraries(projet Input)
target_link_libraries(projet InputCreator)
target_link_libraries(projet InputReader)

add_subdirectory(Google_tests)
