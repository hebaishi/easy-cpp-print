cmake_minimum_required (VERSION 2.6)
project (easyprint_demo)

include_directories("${PROJECT_SOURCE_DIR}/include")

set( SRC_DIR "${PROJECT_SOURCE_DIR}/src" )

if (UNIX)
SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -std=c++11" )
endif()

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -ftemplate-depth=512" )
endif()

option(BUILD_TESTS "Build Unit Testing Binaries" OFF)

if (BUILD_TESTS)
  add_subdirectory(tests)
endif()

add_executable(${PROJECT_NAME} ${SRC_DIR}/demo.cpp )
install (TARGETS ${PROJECT_NAME} DESTINATION bin)
