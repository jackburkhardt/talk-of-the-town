cmake_minimum_required(VERSION 3.31)
project(tott)

set(CMAKE_CXX_STANDARD 20)

add_library(tott
        src/actor.h
        src/tie.h
        src/social_net.cpp
        src/social_net.h
        src/types.h)
