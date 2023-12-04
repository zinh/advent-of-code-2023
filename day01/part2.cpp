#include <cctype>
#include <fstream>
#include <iostream>
#include <regex>
#include <array>
#include <vector>
#include <tuple>

using namespace std;

void read_file(const string &);
int parse_line(string);
string replace_digit(string);

int main(int argc, char **argv) {
  if (argc < 2) {
    cout << "Need filename" << endl;
    return 1;
  }
  char *filename = argv[1];
  read_file(filename);
  return 0;
}

void read_file(const string &filename) {
  ifstream is(filename);
  int total = 0;
  for (string line; getline(is, line);) {
    cout << "Original data: " << line << endl;
    int n = parse_line(replace_digit(line));
    cout << n << endl;
    total += n;
    cout << "---" << endl;
  }
  cout << total << endl;
}

int parse_line(string line) {
  vector<int> v;
  cout << line << endl;
  for (char &c : line) {
    if (isdigit(c))
      v.push_back(c - '0');
  }
  return v.front() * 10 + v.back();
}

string replace_digit(string line) {
  vector<tuple<string, string>> h = {
      {"one", "1"},   {"two", "2"},   {"three", "3"},
      {"four", "4"},  {"five", "5"},  {"six", "6"},
      {"seven", "7"}, {"eight", "8"}, {"nine", "9"}};
  int from_pos = 0;
  bool found = false;
  while (true) {
    found = false;
    vector<tuple<int, tuple<string, string>>> matched;
    for (const auto &[key, value] : h) {
      // cout << "Try search for " << key << endl;
      int pos = line.find(key, from_pos);
      if (pos == string::npos)
        continue;
      // cout << "Found occurence at " << pos << " for " << key << endl;
      matched.push_back({pos, {key, value}});
      found = true;
    }
    if (!found)
      break;
    int smallest_pos = line.size();
    tuple<string, string> smallest_occurence;
    for (const auto &[pos, occurence] : matched) {
      if (pos < smallest_pos) {
        smallest_pos = pos;
        smallest_occurence = occurence;
      }
    }
    // cout << "Will replace " << get<0>(smallest_occurence) << " by " << get<1>(smallest_occurence) << " at " << smallest_pos << endl;
    // cout << "Length = " << get<0>(smallest_occurence).size() << endl;
    line.replace(smallest_pos, get<0>(smallest_occurence).size(), get<1>(smallest_occurence));
    // cout << "After replace: " << line << endl;
    from_pos = smallest_pos;
  }
  return line;
}
