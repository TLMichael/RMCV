cmake_minimum_required(VERSION 3.8)
project(camshift)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)

find_package(OpenCV REQUIRED)

add_executable(camshift ${SOURCE_FILES})
target_link_libraries(camshift ${OpenCV_LIBS})