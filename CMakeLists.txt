cmake_minimum_required(VERSION 3.27)
project(GameMacros)

set(CMAKE_CXX_STANDARD 14)

add_executable(GameMacros
        src/main.cpp
        src/KeyCommands.h
        src/KeyCommands.cpp)
