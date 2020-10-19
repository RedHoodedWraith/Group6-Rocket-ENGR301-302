cmake_minimum_required(VERSION 3.16)
project(Rocket_Control)

set(CMAKE_CXX_STANDARD 14)

set(LIB lib)
include_directories(${LIB})

set(ROCKET_FILES ${LIB}/RocketControl.cpp ${LIB}/RocketControl.h)
add_library(Rocket_Control_LIB ${ROCKET_FILES})

add_executable(Rocket_Control main.cpp lib/RocketControl.cpp lib/RocketControl.h)