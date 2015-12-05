cmake_minimum_required(VERSION 2.6)
project(easyprint_test)

if (UNIX)
set(CMAKE_CXX_FLAGS "-Wall -O3 -std=c++0x")
endif()
add_executable(${PROJECT_NAME} ${PROJECT_SOURCE_DIR}/test.cpp)
