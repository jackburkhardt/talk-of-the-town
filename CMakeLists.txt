cmake_minimum_required(VERSION 3.31)
project(tott-demo)

set(CMAKE_CXX_STANDARD 20)

add_executable(tott-demo src/demo.cpp)

find_package(tott)
