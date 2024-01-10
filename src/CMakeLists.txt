cmake_minimum_required(VERSION 3.25)
project(src)

set(CMAKE_CXX_STANDARD 17)

add_executable(src domain/main.cpp domain/Event.h domain/KeyEvents.cpp domain/KeyEvents.h domain/Event.cpp)
