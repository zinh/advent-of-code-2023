#include "lib.h"
#include <fstream>
#include <iostream>

using namespace std;
void print_game(Game game) {
  for (auto &[color, count] : game)
    cout << color << " : " << count << ";";
  cout << endl;
}

void print_game_set(tuple<int, GameSet> game_set) {
  cout << "Game: " << get<0>(game_set) << endl;
  for (auto &game : get<1>(game_set)) {
    print_game(game);
  }
}

bool valid_gameset(GameSet game_set) {
  for (auto &game : game_set) {
    if (game.at("red") > 12 || game.at("green") > 13 || game.at("blue") > 14)
      return false;
  }
  return true;
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
    auto game_set = parse_line(line);
    if (valid_gameset(get<1>(game_set)))
      result += get<0>(game_set);
  }
  cout << result << endl;

  return 0;
}
