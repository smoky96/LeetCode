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
  int missingNumber(vector<int>& nums) {
    int len = nums.size();
    int i = 0;
    int j = len;

    while (i < j) {
      int mid = (i + j) >> 1;
      if (nums[mid] == mid) {
        i = mid + 1;
      } else {
        j = mid;
      }
    }
    return j == len - 1 && nums[j] == j ? j + 1 : j;
  }
};