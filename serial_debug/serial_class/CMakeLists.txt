cmake_minimum_required(VERSION 3.8)
project(serial_class)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp serial.h serial.cpp)
add_executable(serial_class ${SOURCE_FILES})