#define BOOST_TEST_MODULE Utility_function_tests
#include <boost/test/unit_test.hpp>

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
    BOOST_CHECK( easyprint_test(std::vector<int>({}), d) == "[]\n" );

    std::cout << easyprint_test(std::vector<int>({}), d) << std::endl;
}
