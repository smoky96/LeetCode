#include <stdio.h>

#include <algorithm>
#include <deque>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int ret = numeric_limits<int>::min();
    int tmp = 0;
    for (int i = 0; i < nums.size(); ++i) {
      if (tmp <= 0) {
        tmp = nums[i];
      } else {
        tmp += nums[i];
      }
      ret = max(ret, tmp);
    }
    return ret;
  }
};