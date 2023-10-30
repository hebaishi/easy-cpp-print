#include "catch.hpp"

#define EASY_PRINT_WINDOWS
#include <easyprint.hpp>

#include <sstream>
#include <set>
#include <vector>
#include <map>
#include <unordered_map>

using easyprint::stringify;

TEST_CASE("Empty containers") {
  REQUIRE( stringify(std::vector<int>({})) == "{}" );
  REQUIRE( stringify(std::vector<std::string>({})) == "{}" );
  REQUIRE( stringify(std::vector<std::wstring>({})) == "{}" );
  REQUIRE( stringify(std::set<int>({})) == "{}" );
  REQUIRE( stringify(std::set<std::string>({})) == "{}" );
  REQUIRE( stringify(std::set<std::wstring>({})) == "{}" );
  REQUIRE( stringify(std::pair<int, int>({})) == "{0, 0}" );
  REQUIRE( stringify(std::pair<int, std::string>({})) == "{0, \"\"}");
  REQUIRE( stringify(std::pair<int, std::wstring>({})) == "{0, \"\"}");
  REQUIRE( stringify(std::unordered_map<int, int>({})) == "{}");
  REQUIRE( stringify(std::unordered_map<int, std::string>({})) == "{}");
  REQUIRE( stringify(std::unordered_map<int, std::wstring>({})) == "{}");
  REQUIRE( stringify(std::tuple<int, int, std::string, int>({})) == "{0, 0, \"\", 0}");
  REQUIRE( stringify(std::tuple<int, int, std::wstring, int>({})) == "{0, 0, \"\", 0}");
}

TEST_CASE("Print Single element containers") {
  REQUIRE( stringify(std::vector<int>({3})) == "{3}" );
  REQUIRE( stringify(std::vector<std::string>({"3"}) ) == "{\"3\"}");
  REQUIRE( stringify(std::vector<std::wstring>({L"3"}) ) == "{\"3\"}");
  REQUIRE( stringify(std::set<int>({4})) == "{4}" );
  REQUIRE( stringify(std::set<std::string>({"v"}) ) == "{\"v\"}");
  REQUIRE(stringify(std::set<std::wstring>({ L"v" })) == "{\"v\"}");
  REQUIRE( stringify(std::pair<int, int>({5, 7})) == "{5, 7}" );
  REQUIRE( stringify(std::pair<int, std::string>({1, "s"})) == "{1, \"s\"}");
  REQUIRE( stringify(std::pair<int, std::wstring>({1, L"s"})) == "{1, \"s\"}");
  REQUIRE( stringify(std::unordered_map<int, int>({{1, 2}}) ) == "{{1, 2}}");
  REQUIRE( stringify(std::unordered_map<int, std::string>({{1, "s"}})) == "{{1, \"s\"}}");
  REQUIRE( stringify(std::unordered_map<int, std::wstring>({{1, L"s"}})) == "{{1, \"s\"}}");
}

TEST_CASE("Print multiple element containers") {
  REQUIRE( stringify(std::vector<int>({3, 7})) == "{3, 7}" );
  REQUIRE( stringify(std::vector<std::string>({"6", "8"}) ) == "{\"6\", \"8\"}");
  REQUIRE( stringify(std::vector<std::wstring>({L"6", L"8"}) ) == "{\"6\", \"8\"}");
  REQUIRE( stringify(std::set<int>({4, 9})) == "{4, 9}" );
  REQUIRE( stringify(std::set<std::string>({"f", "v"}) ) == "{\"f\", \"v\"}");
  REQUIRE( stringify(std::set<std::wstring>({L"f", L"v"}) ) == "{\"f\", \"v\"}");
  REQUIRE( stringify(std::map<int, int>({{1, 2}, {5, 7}}) ) == "{{1, 2}, {5, 7}}");
  REQUIRE( stringify(std::map<int, std::string>({{1, "s"}, {4, "t"}})) == "{{1, \"s\"}, {4, \"t\"}}");
  REQUIRE( stringify(std::map<int, std::wstring>({{1, L"s"}, {4, L"t"}})) == "{{1, \"s\"}, {4, \"t\"}}");
  REQUIRE( stringify(std::make_tuple(1, 5, "s", 9) ) == "{1, 5, \"s\", 9}");
}
