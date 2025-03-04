cmake_minimum_required(VERSION 3.29)
project(Dhungana_Bijay_prog4CSC402)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Dhungana_Bijay_prog4CSC402
    mySet.cpp
    mySet.h
        OrderedSet.h
        OrderedSet.cpp
        main.cpp)
