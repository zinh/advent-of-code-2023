#include <map>
#include <string>
#include <tuple>
#include <vector>

using Game = std::map<std::string, int>;
using GameSet = std::vector<Game>;

std::tuple<int, GameSet> parse_line(std::string);
void print_game(Game game);
void print_game_set(std::tuple<int, GameSet> game_set);
bool valid_gameset(GameSet game_set);
