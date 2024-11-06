#include "lib.h"
#include "absl/strings/numbers.h"
#include <absl/strings/str_split.h>
#include <iostream>
#include <regex>
#include <string>

using namespace std;
int get_int(string s) {
  regex r("[0-9]+");
  smatch nmatch;
  regex_search(s, nmatch, r);
  int result;
  absl::SimpleAtoi(nmatch.str(0), &result);
  return result;
}

Card parse_line(string line) {
  vector<string> v = absl::StrSplit(line, ':');
  string card_info{v[0]};
  vector<string> str_wining = absl::StrSplit(v[1], ' ');
  vector<int> wining_numbers;
  transform(str_wining.begin(), str_wining.end(), wining_numbers.begin(),
            [](string n) {
              int result;
              absl::SimpleAtoi(n, &result);
              return result;
            });
  vector<string> str_numbers = absl::StrSplit(v[2], ' ');
  vector<int> numbers;
  transform(str_numbers.begin(), str_numbers.end(), numbers.begin(),
            [](string s) {
              int result;
              absl::SimpleAtoi(s, &result);
              return result;
            });
  struct Card result {
    get_int(card_info), wining_numbers, numbers
  };
  return result;
}
