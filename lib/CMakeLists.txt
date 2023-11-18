cmake_minimum_required(VERSION 3.27)
project(AlgosPractice)

set(CMAKE_CXX_STANDARD 23)

set(HEADER_FILES
        Fibonacci.h
)

set(SOURCE_FILES
        Fibonacci.cpp
        Search.cpp
        Search.h
        Sorting.cpp
        Sorting.h
)

add_library(lib STATIC ${SOURCE_FILES} ${HEADER_FILES})
