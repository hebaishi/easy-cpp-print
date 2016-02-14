set( TEST_DIR "${PROJECT_SOURCE_DIR}/tests" )

ADD_DEFINITIONS(-DBOOST_TEST_DYN_LINK)

add_executable(easyprint_test ${TEST_DIR}/easyprint_tests.cpp)
target_link_libraries( easyprint_test -lboost_unit_test_framework )

enable_testing()
add_test(Easyprint_test easyprint_test)
