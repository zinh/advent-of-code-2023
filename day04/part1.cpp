#include "lib.h"
#include <iostream>

using namespace std;
int main(int argc, char **argv) {
  auto card = parse_line("Card 1: 41 48 83 86 17 | 83 86  6 31 17  9 48 53");
  cout << card.id << endl;
}
