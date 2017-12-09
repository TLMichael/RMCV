cmake_minimum_required(VERSION 2.8)

project(opencv_traincascade)

find_package(OpenCV REQUIRED)

message(STATUS "OpenCV library status:")
message(STATUS "    version: ${OpenCV_VERSION}")
message(STATUS "    libraries: ${OpenCV_LIBS}")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")

if(CMAKE_VERSION VERSION_LESS "2.8.11")
  include_directories(${OpenCV_INCLUDE_DIRS})
endif()


file(GLOB SRCS *.cpp)
file(GLOB HDRS *.h*)

set(traincascade_files ${SRCS} ${HDRS})

add_executable(opencv_traincascade ${traincascade_files})

target_link_libraries(opencv_traincascade ${OpenCV_LIBS})
