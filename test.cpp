#include <iostream>
#include <tuple>
#include <vector>
#include <set>
#include <unordered_map>

#include "easyprint"

using namespace std;

int main() {
    // Test different containers
    vector<int> empty_int_vec = {};
    std::cerr << "empty_int_vec = "; print(std::cerr, empty_int_vec); std::cerr << std::endl;
    vector<float> empty_float_vec = {};
    std::cerr << "empty_float_vec = "; print(std::cerr, empty_float_vec); std::cerr << std::endl;
    set<int> empty_int_set = {};
    std::cerr << "empty_int_set = "; print(std::cerr, empty_int_set); std::cerr << std::endl;
    set<float> empty_float_set = {};
    std::cerr << "empty_float_set = "; print(std::cerr, empty_float_set); std::cerr << std::endl;

    // Test string containers
    vector<string> string_vec = {"Hello", "World"};
    std::cerr << "string_vec = "; print(std::cerr, string_vec); std::cerr << std::endl;
    set<string> string_set = {"Hello", "World", "Hello"};
    std::cerr << "string_set = "; print(std::cerr, string_set); std::cerr << std::endl;

    // Test map with different types
    unordered_map<int, string> int_string_map = { {1, "Hello"}, {2, "World"} };
    std::cerr << "int_string_map = "; print(std::cerr, int_string_map); std::cerr << std::endl;
    unordered_map<string, float> string_float_map = { {"Hello", 1}, {"World", 2} };
    std::cerr << "string_float_map = "; print(std::cerr, string_float_map); std::cerr << std::endl;


    // Test tuple of varying sizes and different types
    auto small_tuple = make_tuple(1,2.1, std::string("String"));
    std::cerr << "small_tuple = "; print(std::cerr, small_tuple); std::cerr << std::endl;
    auto medium_tuple = make_tuple(2, 3.4, "Hello", 5.6, "World", 7);
    std::cerr << "medium_tuple = "; print(std::cerr, medium_tuple); std::cerr << std::endl;
    auto long_tuple = make_tuple(2, 3.4, "Hello", 5.6, "World", 7,2, 3.4, "Hello", 5.6, "World", 7,2, 3.4, "Hello", 5.6, "World", 7);
    auto nested_tuple = make_tuple(1, make_tuple(2,3,4),5,6);
    std::cerr << "Nested tuple = ";print(std::cerr, nested_tuple); std::cerr << std::endl;

    std::cerr << "long_tuple = "; print(std::cerr, long_tuple); std::cerr << std::endl;

    // Testing with complex nested types
    vector <set <int>> int_vector_set = {{1}, {4,5}, {6,6,7,8}};
    std::cerr << "int_vector_set = "; print(std::cerr, int_vector_set); std::cerr << std::endl;

    // Simple and complex tuple
    auto t = make_tuple(1, 2.3);
    vector <tuple <int, float>> int_float_vec_tuple = {t, t};
    std::cerr << "int_float_vec_tuple = "; print(std::cerr, int_float_vec_tuple); std::cerr << std::endl;
    vector <int> v_t = {1,2,3};
    return 0;
}
