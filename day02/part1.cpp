#include "lib.h"
#include <fstream>
#include <iostream>

using namespace std;


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
