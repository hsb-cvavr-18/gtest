cmake_minimum_required(VERSION 3.2)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O3")

set(CMAKE_INSTALL_PREFIX ${PROJECT_SOURCE_DIR})

set(DOMINOASSISTANT_INSTALL_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)
set(DOMINOASSISTANT_INSTALL_BIN_DIR ${PROJECT_SOURCE_DIR}/bin)
set(DOMINOASSISTANT_INSTALL_LIB_DIR ${PROJECT_SOURCE_DIR}/lib)

set(DIVISION_HEADERS_DIR ${PROJECT_SOURCE_DIR}/src/division)
set(ImgDebugPrinter_HEADERS_DIR ${PROJECT_SOURCE_DIR}/src/ImgDebugPrinter)

include_directories(${DOMINOASSISTANT_INSTALL_INCLUDE_DIR})
#include_directories(${DIVISION_HEADERS_DIR})
#include_directories(${ImgDebugPrinter_HEADERS_DIR})

add_subdirectory(src)

include(cmake/googletest.cmake)
fetch_googletest(
        ${PROJECT_SOURCE_DIR}/cmake
        ${PROJECT_BINARY_DIR}/googletest
)
enable_testing()
add_subdirectory(test)


