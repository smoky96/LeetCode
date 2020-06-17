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
  vector<int> singleNumbers(vector<int>& nums) {
    int x = 0;
    for (const int& i : nums) {
      x ^= i;
    }

    int shift = 1;
    while (!(x & shift)) {
      shift <<= 1;
    }

    int a = 0, b = 0;
    for (const int& i : nums) {
      if (i & shift) {
        a ^= i;
      } else {
        b ^= i;
      }
    }
    return {a, b};
  }
};