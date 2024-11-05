#include "lib.h"
#include "absl/strings/numbers.h"
#include "absl/strings/str_split.h"
#include <iostream>
#include <map>
#include <regex>
#include <sstream>
#include <tuple>

using namespace std;
// Return first integer in string s
int get_int(string s) {
  regex r("[0-9]+");
  smatch nmatch;
  regex_search(s, nmatch, r);
  int result;
  absl::SimpleAtoi(nmatch.str(0), &result);
  return result;
}

map<string, int> parse_gameset(string set) {
  vector<string> games = absl::StrSplit(set, ',');
  map<string, int> m{{"red", 0}, {"green", 0}, {"blue", 0}};
  for (string game : games) {
    vector<string> g = absl::StrSplit(game, ' ');
    // for (auto i : g)
    //   cout << i << "/";
    // cout << endl;
    string color = g[2];
    int count;
    absl::SimpleAtoi(g[1], &count);
    m[color] = count;
  }
  // for (auto &[k, v] : m)
  //   cout << k << " : " << v << " ; ";
  // cout << endl;
  return m;
}

tuple<int, GameSet> parse_line(string line) {
  vector<string> items = absl::StrSplit(line, ':');
  int game_id = get_int(items.at(0));
  vector<string> game_sets = absl::StrSplit(items.at(1), ';');
  GameSet s;
  for (const string &game_set : game_sets) {
    s.push_back(parse_gameset(game_set));
  }
  return tuple<int, GameSet>(game_id, s);
}

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
