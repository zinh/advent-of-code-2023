#include "boost/test/tools/interface.hpp"
#define BOOST_TEST_MODULE boost_test_lib
#include "lib.h"
#include <boost/test/included/unit_test.hpp>
#include <string>
#include <tuple>

using namespace std;
BOOST_AUTO_TEST_CASE(boost_test_lib) {
  string line = "Game 1: 3 blue, 4 red";
  auto result = parse_line(line);
  int game_id = get<0>(result);
  GameSet game_set = get<1>(result);
  GameSet expected{Game{{"blue", 1}}};
  BOOST_TEST(1 == game_id);
  BOOST_CHECK_EQUAL_COLLECTIONS(expected.begin(), expected.end(),
                                game_set.begin(), game_set.end());
}
