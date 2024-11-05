#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <tuple>
#include <vector>

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
    // cout << "Original data: " << line << endl;
    auto digits = replace_digit(line);
    // cout << line << ":" << digits << endl;
    total += parse_line(digits);
  }
  cout << total << endl;
}

int parse_line(string line) {
  vector<int> v;
  // cout << line << endl;
  for (char &c : line) {
    if (isdigit(c))
      v.push_back(c - '0');
  }
  return v.front() * 10 + v.back();
}

bool cmp_fn(tuple<int, string> a, tuple<int, string> b) {
  return get<0>(a) < get<0>(b);
}

string replace_digit(string line) {
  vector<string> h = {"one",   "two",  "three", "four", "five", "six", "seven",
                      "eight", "nine", "0",     "1",    "2",    "3",   "4",
                      "5",     "6",    "7",     "8",    "9"};
  map<string, string> m = {{"one", "1"},   {"two", "2"},   {"three", "3"},
                           {"four", "4"},  {"five", "5"},  {"six", "6"},
                           {"seven", "7"}, {"eight", "8"}, {"nine", "9"}};
  vector<tuple<int, string>> results;
  stringstream ss;
  for (auto sub : h) {
    size_t pos = line.find(sub, 0);
    while (pos != string::npos) {
      results.push_back({pos, sub});
      pos = line.find(sub, pos + 1);
    }
  }
  sort(results.begin(), results.end(), cmp_fn);
  for (auto item : results) {
    string s = get<1>(item);
    try {
      auto value = m.at(s);
      ss << value;
    } catch (out_of_range err) {
      ss << s;
    }
  }
  return ss.str();
}
