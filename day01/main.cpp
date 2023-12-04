#include <iostream>
#include <fstream>
#include <vector>
#include <cctype>

using namespace std;

void read_file(const string&);
int parse_line(string);

int
main(int argc, char** argv) {
  if (argc < 2) {
    cout << "Need filename" << endl;
    return 1;
  }
  char* filename = argv[1];
  read_file(filename);
  return 0;
}

void
read_file(const string& filename) {
  ifstream is(filename);
  int total = 0;
  for (string line; getline(is, line);) {
    total +=  parse_line(line);
  }
  cout << total << endl;
}

int
parse_line(string line) {
  vector<int> v;
  for (char& c : line) {
    if (isdigit(c))
      v.push_back(c - '0');
  }
  return v.front() * 10 + v.back();
}
