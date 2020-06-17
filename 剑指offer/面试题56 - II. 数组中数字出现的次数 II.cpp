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
  int singleNumber(vector<int>& nums) {
    int ret = 0;
    int shift = 1;
    int n = 32;
    while (--n) {
      int x = 0;
      for (const int& i : nums) {
        if (shift & i) ++x;
      }
      if (x % 3 != 0) ret |= shift;
      shift <<= 1;
    }
    return ret;
  }
};