cmake_minimum_required(VERSION 3.27)
project(AlgosPractice)

set(CMAKE_CXX_STANDARD 23)

add_subdirectory(test)

include_directories(lib)
add_subdirectory(lib)
target_link_libraries(lib)

add_executable(AlgosPractice main.cpp)
