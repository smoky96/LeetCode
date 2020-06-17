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
  vector<int> twoSum(vector<int>& nums, int target) {
    int len = nums.size();
    if (len == 1) return nums;
    int i = 0;
    int j = len - 1;
    while (i < j) {
      int tmp = nums[i] + nums[j];
      if (tmp < target)
        ++i;
      else if (tmp > target)
        --j;
      else
        break;
    }
    return {nums[i], nums[j]};
  }
};