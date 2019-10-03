#include "easyprint"

#include <iostream>
#include <set>
#include <map>
#include <tuple>
#include <unordered_map>
#include <vector>



using namespace std;
using easyprint::print;

int main(int argc, const char *argv[]) {
  // Test different containers
  vector<int> empty_int_vec = {};
  std::cout << "empty_int_vec = ";
  print(empty_int_vec);
  vector<float> empty_float_vec = {};
  std::cout << "empty_float_vec = ";
  print(empty_float_vec);
  set<int> empty_int_set = {};
  std::cout << "empty_int_set = ";
  print(empty_int_set);
  set<float> empty_float_set = {};
  std::cout << "empty_float_set = ";
  print(empty_float_set);

  // Test string containers
  vector<string> string_vec = {"Hello", "World"};
  std::cout << "string_vec = ";
  print(string_vec);
  set<string> string_set = {"Hello", "World", "Hello"};
  std::cout << "string_set = ";
  print(string_set);

  // Test map with different types
  unordered_map<int, string> int_string_map = {{1, "Hello"}, {2, "World"}};
  std::cout << "int_string_map = ";
  print(int_string_map);
  unordered_map<string, float> string_float_map = {{"Hello", 1}, {"World", 2}};
  std::cout << "string_float_map = ";
  print(string_float_map);

  // Test tuple of varying sizes and different types
  auto small_tuple = make_tuple(1, 2.1, std::string("String"));
  std::cout << "small_tuple = ";
  print(small_tuple);
  auto medium_tuple = make_tuple(2, 3.4, "Hello", 5.6, "World", 7);
  std::cout << "medium_tuple = ";
  print(medium_tuple);
  auto long_tuple =
      make_tuple(2, 3.4, "Hello", 5.6, "World", 7, 2, 3.4, "Hello", 5.6,
                 "World", 7, 2, 3.4, "Hello", 5.6, "World", 7);
  auto nested_tuple = make_tuple(1, make_tuple(2, 3, 4), 5, 6);
  std::cout << "Nested tuple = ";
  print(nested_tuple);

  std::cout << "long_tuple = ";
  print(long_tuple);

  // Testing with complex nested types
  vector<set<int>> int_vector_set = {{1}, {4, 5}, {6, 6, 7, 8}};
  std::cout << "int_vector_set = ";
  print(int_vector_set);

  // Simple and complex tuple
  auto t = make_tuple(1, 2.3);
  vector<tuple<int, float>> int_float_vec_tuple = {t, t};
  std::cout << "int_float_vec_tuple = ";
  print(int_float_vec_tuple);
  vector<int> v_t = {1, 2, 3};

  std::map<int, std::vector<int>> m1, m2;
  m1[0] = {0,1,2,3,4};
  m2[0] = {6,7,8,9,10};
  print(m1);
  print(m2);

  return 0;
}
