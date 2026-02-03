cmake_minimum_required(VERSION 3.31)
project(tott)

set(CMAKE_CXX_STANDARD 20)

add_library(tott
        actor.h
        tie.h
        social_net.cpp
        social_net.h
        types.h
        serialize.h)

target_include_directories(tott SHARED ${CMAKE_SOURCE_DIR}/lib)
