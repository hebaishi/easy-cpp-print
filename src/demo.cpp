#include <iostream>
#include <set>
#include <tuple>
#include <unordered_map>
#include <vector>

#include "easyprint"

using namespace std;

int main(int argc, const char *argv[]) {
  // Test different containers
  vector<int> empty_int_vec = {};
  std::cerr << "empty_int_vec = ";
  print_line(std::cerr, empty_int_vec);
  vector<float> empty_float_vec = {};
  std::cerr << "empty_float_vec = ";
  print_line(std::cerr, empty_float_vec);
  set<int> empty_int_set = {};
  std::cerr << "empty_int_set = ";
  print_line(std::cerr, empty_int_set);
  set<float> empty_float_set = {};
  std::cerr << "empty_float_set = ";
  print_line(std::cerr, empty_float_set);

  // Test string containers
  vector<string> string_vec = {"Hello", "World"};
  std::cerr << "string_vec = ";
  print_line(std::cerr, string_vec);
  set<string> string_set = {"Hello", "World", "Hello"};
  std::cerr << "string_set = ";
  print_line(std::cerr, string_set);

  // Test map with different types
  unordered_map<int, string> int_string_map = {{1, "Hello"}, {2, "World"}};
  std::cerr << "int_string_map = ";
  print_line(std::cerr, int_string_map);
  unordered_map<string, float> string_float_map = {{"Hello", 1}, {"World", 2}};
  std::cerr << "string_float_map = ";
  print_line(std::cerr, string_float_map);

  // Test tuple of varying sizes and different types
  auto small_tuple = make_tuple(1, 2.1, std::string("String"));
  std::cerr << "small_tuple = ";
  print_line(std::cerr, small_tuple);
  auto medium_tuple = make_tuple(2, 3.4, "Hello", 5.6, "World", 7);
  std::cerr << "medium_tuple = ";
  print_line(std::cerr, medium_tuple);
  auto long_tuple =
      make_tuple(2, 3.4, "Hello", 5.6, "World", 7, 2, 3.4, "Hello", 5.6,
                 "World", 7, 2, 3.4, "Hello", 5.6, "World", 7);
  auto nested_tuple = make_tuple(1, make_tuple(2, 3, 4), 5, 6);
  std::cerr << "Nested tuple = ";
  print_line(std::cerr, nested_tuple);

  std::cerr << "long_tuple = ";
  print_line(std::cerr, long_tuple);

  // Testing with complex nested types
  vector<set<int>> int_vector_set = {{1}, {4, 5}, {6, 6, 7, 8}};
  std::cerr << "int_vector_set = ";
  print_line(std::cerr, int_vector_set);

  // Simple and complex tuple
  auto t = make_tuple(1, 2.3);
  vector<tuple<int, float>> int_float_vec_tuple = {t, t};
  std::cerr << "int_float_vec_tuple = ";
  print_line(std::cerr, int_float_vec_tuple);
  vector<int> v_t = {1, 2, 3};

  return 0;
}
