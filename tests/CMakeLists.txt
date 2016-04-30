set( TEST_DIR "${PROJECT_SOURCE_DIR}/tests" )

ADD_DEFINITIONS(-DBOOST_TEST_DYN_LINK)

add_executable(easyprint_test ${TEST_DIR}/easyprint_tests.cpp)
if (UNIX)
  target_link_libraries( easyprint_test -lboost_unit_test_framework )
elseif("${CMAKE_CXX_COMPILER_ID}" STREQUAL "MSVC")
  target_link_libraries( easyprint_test ${PROJECT_SOURCE_DIR}/lib/boost_unit_test_framework-vc140-mt-1_60.lib )
endif()

enable_testing()
add_test(Easyprint_test easyprint_test)
