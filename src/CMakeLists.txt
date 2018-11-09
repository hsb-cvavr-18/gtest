cmake_minimum_required(VERSION 3.2)
project(divider)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
add_subdirectory(division)
set(SOURCE_FILES main.cpp)

add_executable(divider ${SOURCE_FILES})
target_link_libraries("${PROJECT_NAME}" division ${OpenCV_LIBS})
