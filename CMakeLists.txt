
project(ENSEMBLE_RANDOM)

cmake_minimum_required(VERSION 3.16)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_compile_definitions("ulong=unsigned long")

add_executable(
    "ensemble-random"
    "${CMAKE_SOURCE_DIR}/inc/random.hpp"
    "${CMAKE_SOURCE_DIR}/src/random.cpp"
    "${CMAKE_SOURCE_DIR}/test/main.cpp"
)
