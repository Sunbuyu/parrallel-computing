cmake_minimum_required(VERSION 3.20)
project(parrallel_computing)

set(CMAKE_CXX_STANDARD 14)

add_executable(parrallel_computing
        main.cpp matrix.cpp matrix.h)
