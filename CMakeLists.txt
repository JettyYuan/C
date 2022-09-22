cmake_minimum_required(VERSION 3.23)
project(C)

set(CMAKE_CXX_STANDARD 14)

include_directories(src/chapter11/time3)

add_executable(C
        src/chapter11/time3/mytime3.cpp
        src/chapter11/time3/mytime3.h
        src/chapter11/time3/usetime3.cpp)
