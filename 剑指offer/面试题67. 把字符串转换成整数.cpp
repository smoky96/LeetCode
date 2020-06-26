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
  int strToInt(string str) {
    int len = str.length();
    if (len == 0) return 0;

    bool minus = false;
    int i = 0;
    for (; i < len; ++i) {
      if (str[i] == ' ') {
        continue;
      } else if (str[i] == '-') {
        minus = true;
        ++i;
        break;
      } else if (str[i] == '+') {
        ++i;
        break;
      } else if (str[i] >= '0' && str[i] <= '9') {
        break;
      } else {
        return 0;
      }
    }

    long long ans = 0;
    for (; i < len && str[i] >= '0' && str[i] <= '9'; ++i) {
      ans = ans * 10 + (str[i] - '0');
      if (!minus && ans >= numeric_limits<int>::max()) {
        return numeric_limits<int>::max();
      }
      if (minus && -1 * ans <= numeric_limits<int>::min()) {
        return numeric_limits<int>::min();
      }
    }
    return minus ? -1 * ans : ans;
  }
};