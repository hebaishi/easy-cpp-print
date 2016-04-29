#define BOOST_TEST_MODULE Easyprint_default_tests
#include <boost/test/unit_test.hpp>

#include <unordered_map>

#include "easyprint"

template <typename T, typename DELIMITER>
std::string easyprint_test(T&& container, DELIMITER d ){
    std::stringstream ss;
    print_line(ss, std::forward<T>(container), d);
    return ss.str();
};

BOOST_AUTO_TEST_CASE( Print_Empty_container )
{
    default_delimiter d;
    BOOST_CHECK_EQUAL( easyprint_test(std::vector<int>({}), d), "[]\n" );
    BOOST_CHECK_EQUAL( easyprint_test(std::vector<std::string>({}), d), "[]\n" );
    BOOST_CHECK_EQUAL( easyprint_test(std::set<int>({}), d), "{}\n" );
    BOOST_CHECK_EQUAL( easyprint_test(std::set<std::string>({}), d), "{}\n" );
    BOOST_CHECK_EQUAL( easyprint_test(std::pair<int, int>({}), d), "(0, 0)\n" );
    BOOST_CHECK_EQUAL( easyprint_test(std::pair<int, std::string>({}), d), "(0, \"\")\n" );
    BOOST_CHECK_EQUAL( easyprint_test(std::unordered_map<int, int>({}), d), "{}\n" );
    BOOST_CHECK_EQUAL( easyprint_test(std::unordered_map<int, std::string>({}), d), "{}\n" );
    BOOST_CHECK_EQUAL( easyprint_test(std::tuple<int, int, std::string, int>({}), d), "(0, 0, \"\", 0)\n" );
}

BOOST_AUTO_TEST_CASE( Print_Single_Element_container )
{
    default_delimiter d;
    BOOST_CHECK_EQUAL( easyprint_test(std::vector<int>({3}), d), "[3]\n" );
    BOOST_CHECK_EQUAL( easyprint_test(std::vector<std::string>({"3"}), d), "[\"3\"]\n" );
    BOOST_CHECK_EQUAL( easyprint_test(std::set<int>({4}), d), "{4}\n" );
    BOOST_CHECK_EQUAL( easyprint_test(std::set<std::string>({"v"}), d), "{\"v\"}\n" );
    BOOST_CHECK_EQUAL( easyprint_test(std::pair<int, int>({5, 7}), d), "(5, 7)\n" );
    BOOST_CHECK_EQUAL( easyprint_test(std::pair<int, std::string>({1, "s"}), d), "(1, \"s\")\n" );
    BOOST_CHECK_EQUAL( easyprint_test(std::unordered_map<int, int>({ {1,2} }), d), "{(1, 2)}\n" );
    BOOST_CHECK_EQUAL( easyprint_test(std::unordered_map<int, std::string>({ {1,"s"} }), d), "{(1, \"s\")}\n" );
}

BOOST_AUTO_TEST_CASE( Print_Multiplee_Element_container )
{
    default_delimiter d;
    BOOST_CHECK_EQUAL( easyprint_test(std::vector<int>({3, 7}), d), "[3, 7]\n" );
    BOOST_CHECK_EQUAL( easyprint_test(std::vector<std::string>({"6", "8"}), d), "[\"6\", \"8\"]\n" );
    BOOST_CHECK_EQUAL( easyprint_test(std::set<int>({4, 9}), d), "{4, 9}\n" );
    BOOST_CHECK_EQUAL( easyprint_test(std::set<std::string>({"f", "v"}), d), "{\"f\", \"v\"}\n" );
    BOOST_CHECK_EQUAL( easyprint_test(std::map<int, int>({ {1,2}, {5,7} }), d), "{(1, 2), (5, 7)}\n" );
    BOOST_CHECK_EQUAL( easyprint_test(std::map<int, std::string>({ {1,"s"}, {4, "t"} }), d), "{(1, \"s\"), (4, \"t\")}\n" );
    BOOST_CHECK_EQUAL( easyprint_test(std::make_tuple(1, 5, "s", 9), d), "(1, 5, \"s\", 9)\n" );
}
