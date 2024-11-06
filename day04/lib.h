#ifndef LIB_H
#define LIB_H
#include <vector>
#include <string>

struct Card {
  int id;
  std::vector<int> win_numbers;
  std::vector<int> numbers;
};

Card parse_line(std::string);

#endif
