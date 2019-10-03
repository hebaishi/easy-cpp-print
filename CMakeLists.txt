cmake_minimum_required (VERSION 2.6)
project (easyprint_demo)

if (UNIX)
SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -std=c++11" )
endif()

if ("${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
  SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -ftemplate-depth=512" )
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
  add_definitions(-DTEST_INCLUDED)
endif()

enable_testing()

add_subdirectory(tests)

add_executable(
  ${PROJECT_NAME}
  src/demo.cpp
  include/easyprint.hpp
)

target_include_directories(
  ${PROJECT_NAME}
  PRIVATE
  include
)

install (
  TARGETS
    ${PROJECT_NAME}
  DESTINATION
    bin
)
