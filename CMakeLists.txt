# License: MIT. See LICENSE in root directory.
# Date: 2020/07/02

cmake_minimum_required(VERSION 3.1.0)

project("ensemble-random" LANGUAGES CXX C)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

add_compile_definitions("ulong=unsigned long")

include_directories("${CMAKE_CURRENT_LIST_DIR}/inc")

set(ENSEMBLE_RANDOM_LIB "ensemble-random-lib")
add_library(${ENSEMBLE_RANDOM_LIB} STATIC "")
target_sources(
    ${ENSEMBLE_RANDOM_LIB}
    PRIVATE
    "${CMAKE_CURRENT_LIST_DIR}/src/ensemble/random.cpp"
    "${CMAKE_CURRENT_LIST_DIR}/inc/ensemble/random.hpp"
)

if (CMAKE_BUILD_TYPE MATCHES "^[Dd]ebug")
    set(ENSEMBLE_RANDOM_EXE "ensemble-random-exe")
    add_executable(
        ${ENSEMBLE_RANDOM_EXE}
        "${CMAKE_CURRENT_LIST_DIR}/test/main.cpp"
    )
    target_link_libraries(
        ${ENSEMBLE_RANDOM_EXE}
        ${ENSEMBLE_RANDOM_LIB}
    )
endif ()
