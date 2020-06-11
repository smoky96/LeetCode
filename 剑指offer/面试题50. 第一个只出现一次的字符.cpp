#include <stdio.h>

#include <algorithm>
#include <deque>
#include <iostream>
#include <iterator>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define PRINT_ARY(container, value_type)           \
  do {                                             \
    copy(container.begin(), container.end(),       \
         ostream_iterator<value_type>(cout, " ")); \
    cout << endl;                                  \
  } while (0)

using namespace std;

class Solution {
 public:
  char firstUniqChar(string s) {
    if (s.length() == 0) return ' ';
    unordered_map<char, int> dict;
    for (const char& c : s) {
      ++dict[c];
    }
    for (const char& c : s) {
      if (dict[c] == 1) return c;
    }
    return ' ';
  }
};