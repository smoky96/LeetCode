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
  vector<vector<int>> findContinuousSequence(int target) {
    if (target <= 2) return {{target}};
    int begin = 1;
    int end = 2;
    int sum = 3;
    vector<vector<int>> ret;
    while (end < target) {
      if (sum < target) {
        ++end;
        sum += end;
      } else if (sum > target) {
        sum -= begin;
        ++begin;
      } else {
        vector<int> res;
        for (int i = begin; i <= end; ++i) {
          res.push_back(i);
        }
        ret.push_back(res);
        ++end;
        sum += end;
      }
    }
    return ret;
  }
};