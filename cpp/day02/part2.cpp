#include "lib.h"
#include <fstream>
#include <iostream>

using namespace std;

int power_of_set(GameSet game_set) {
  map<string, int> m{{"red", 0}, {"green", 0}, {"blue", 0}};

  for (auto &game : game_set) {
    for (auto &[color, cnt] : game) {
      if (cnt > m.at(color))
        m[color] = cnt;
    }
  }
  int result;
  for (auto &[color, cnt] : m)
    result *= cnt;
  return result;
}

int main(int argc, char **argv) {
  if (argc < 2) {
    cout << "Need filename" << endl;
    return 1;
  }
  string filename(argv[1]);
  ifstream is(filename);
  int result = 0;
  for (string line; getline(is, line);) {
    auto parsed_game = parse_line(line);
    auto game_set = get<1>(parsed_game);
    result += power_of_set(game_set);
  }

  cout << result << endl;

  return 0;
}
