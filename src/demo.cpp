#include <iostream>
#include <set>
#include <map>
#include <tuple>
#include <unordered_map>
#include <vector>
#include <cassert>
using namespace std;

#define EASY_PRINT_WINDOWS
#include <easyprint.hpp>
using namespace easyprint_helper;

using easyprint::print;
using easyprint::stringify;

int main(int argc, const char *argv[]) {
  // Test different containers
  vector<int> empty_int_vec = {};
  std::cout << "empty_int_vec = " << stringify(empty_int_vec) << std::endl;
  vector<float> empty_float_vec = {};
  std::cout << "empty_float_vec = " << stringify(empty_float_vec) << std::endl;
  set<int> empty_int_set = {};
  std::cout << "empty_int_set = " << stringify(empty_int_set) << std::endl;
  set<float> empty_float_set = {};
  std::cout << "empty_float_set = " << stringify(empty_float_set) << std::endl;

  // Test string containers
  vector<string> string_vec = {"Hello", "World"};
  std::cout << "string_vec = " << stringify(string_vec) << std::endl;
  set<string> string_set = {"Hello", "World", "Hello"};
  std::cout << "string_set = " << stringify(string_set) << std::endl;

  // Test map with different types
  unordered_map<int, string> int_string_map = {{1, "Hello"}, {2, "World"}};
  std::cout << "int_string_map = " << stringify(int_string_map) << std::endl;
  unordered_map<string, float> string_float_map = {{"Hello", 1}, {"World", 2}};
  std::cout << "string_float_map = " << stringify(string_float_map) << std::endl;

  // Test tuple of varying sizes and different types
  auto small_tuple = make_tuple(1, 2.1, std::string("String"));
  std::cout << "small_tuple = " << stringify(small_tuple) << std::endl;

  auto medium_tuple = make_tuple(2, 3.4, "Hello", 5.6, "World", 7);
  std::cout << "medium_tuple = " << stringify(medium_tuple) << std::endl;

  auto long_tuple =
      make_tuple(2, 3.4, "Hello", 5.6, "World", 7, 2, 3.4, "Hello", 5.6,
                 "World", 7, 2, 3.4, "Hello", 5.6, "World", 7);
  auto nested_tuple = make_tuple(1, make_tuple(2, 3, 4), 5, 6);
  
  std::cout << "Nested tuple = " << stringify(nested_tuple) << std::endl;
  std::cout << "long_tuple = " << stringify(long_tuple) << std::endl;

  // Testing with complex nested types
  vector<set<int>> int_vector_set = {{1}, {4, 5}, {6, 6, 7, 8}};
  std::cout << "int_vector_set = " << stringify(int_vector_set) << std::endl;

  // Simple and complex tuple
  auto t = make_tuple(1, 2.3);
  vector<tuple<int, float>> int_float_vec_tuple = {t, t};
  std::cout << "int_float_vec_tuple = " << stringify(int_float_vec_tuple) << std::endl;
  vector<int> v_t = {1, 2, 3};

  // Exotic container
  std::map<int, std::vector<int>> m1, m2;
  m1[0] = {0,1,2,3,4};
  m2[0] = {6,7,8,9,10};
  std::cout << stringify(m1) << stringify(m2) << std::endl;

  {
    vector<string> v;
    v.push_back("anh yÃªu em nhiá»u láº¯m"); // utf-8 string
    auto temp = stringify_A(v);
    auto s = __to_string_W(temp, true);
    assert(s == L"{\"anh yêu em nhiều lắm\"}");
    print(v);
  }

  {
    vector<wstring> v;
    v.push_back(L"anh yêu em nhiều lắm"); // unicode string
    auto s = stringify_A(v);
    assert(s == "{\"anh yÃªu em nhiá»u láº¯m\"}");
    print(v);
  }

  return 0;
}
