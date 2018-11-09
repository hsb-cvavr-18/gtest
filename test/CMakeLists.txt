cmake_minimum_required(VERSION 3.2)
project(unit_tests)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})
include_directories(${DIVISION_HEADERS_DIR})

set(SOURCE_FILES main.cpp src/divider_tests.cpp ../src/division/division.cpp)
message("TEST SOURCE FILES: ${SOURCE_FILES}")

add_executable(
        unit_tests
        ${SOURCE_FILES}
)

target_link_libraries(
        unit_tests
        ${OpenCV_LIBS}
        gtest_main
)

add_test(
        NAME
        unit
        COMMAND
        ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/unit_tests
)