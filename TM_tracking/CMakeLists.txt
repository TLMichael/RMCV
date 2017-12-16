cmake_minimum_required(VERSION 3.8)
project(TM_tracking)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp)

find_package(OpenCV REQUIRED)
add_executable(TM_tracking ${SOURCE_FILES})
target_link_libraries(TM_tracking ${OpenCV_LIBS})