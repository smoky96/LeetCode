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

using namespace std;

class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    int len = nums.size();
    int start = 0;
    int end = len;
    while (start < end) {
      int mid = partition(nums, start, end);
      if (mid == (len >> 1)) return nums[mid];
      if (mid < (len >> 1)) {
        start = mid + 1;
      } else {
        end = mid;
      }
    }
    return -1;
  }

  int partition(vector<int>& nums, int start, int end) {
    int small = start - 1;
    for (int i = start; i < end; ++i) {
      if (nums[i] < nums[end - 1]) {
        ++small;
        if (small != i) swap(nums[i], nums[small]);
      }
    }
    ++small;
    swap(nums[end - 1], nums[small]);
    return small;
  }
};