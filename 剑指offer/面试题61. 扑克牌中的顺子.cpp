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
    \ 
    cout << endl;                                  \
  } while (0)

using namespace std;

class Solution {
 public:
  bool isStraight(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int len = nums.size();
    int num_zero = 0;
    int num_gap = 0;
    for (int i = 0; i < len; ++i) {
      if (nums[i] == 0) {
        ++num_zero;
        continue;
      }
      if (i != len - 1 && nums[i] == nums[i + 1]) return false;
      if (i != len - 1 && nums[i] + 1 != nums[i + 1])
        num_gap += nums[i + 1] - nums[i] - 1;
    }
    return num_zero >= num_gap;
  }
};