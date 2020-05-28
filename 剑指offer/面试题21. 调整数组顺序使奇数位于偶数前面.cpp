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
  vector<int> exchange(vector<int>& nums) {
    if (nums.size() == 0) return {};
    vector<int>::size_type i = 0;
    vector<int>::size_type j = nums.size() - 1;

    while (i < j) {
      while (i < j && nums[i] & 0x1) {
        ++i;
      }
      while (i < j && !(nums[j] & 0x1)) {
        --j;
      }
      if (i < j) swap(nums[i], nums[j]);
    }
    return nums;
  }
};