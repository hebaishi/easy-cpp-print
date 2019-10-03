add_executable(
  easyprint_tests
  easyprint_tests.cpp
  catch_main.cpp
)

target_include_directories(
  easyprint_tests
  PRIVATE
  ../include
)

add_test(
  NAME
    easyprint_tests
  COMMAND
    easyprint_tests
)
