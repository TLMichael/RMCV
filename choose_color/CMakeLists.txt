cmake_minimum_required(VERSION 2.8)

project(choose_color)

find_package(OpenCV REQUIRED)

message(STATUS "OpenCV library status:")
message(STATUS "    version: ${OpenCV_VERSION}")
message(STATUS "    libraries: ${OpenCV_LIBS}")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")

if(CMAKE_VERSION VERSION_LESS "2.8.11")
  include_directories(${OpenCV_INCLUDE_DIRS})
endif()

add_executable(choose_color choose_color.cpp)

target_link_libraries(choose_color ${OpenCV_LIBS})
