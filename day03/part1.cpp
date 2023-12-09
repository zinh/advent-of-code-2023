#define BOOST_TEST_MODULE boost_test_macro_overview
#include <boost/algorithm/string.hpp>
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(test_macro_overview) {
 BOOST_TEST(1 != 1);
}
