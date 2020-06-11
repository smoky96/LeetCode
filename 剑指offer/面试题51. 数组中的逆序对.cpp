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
  int count = 0;

 public:
  int reversePairs(vector<int>& nums) {
    aux(nums, 0, nums.size());
    return count;
  }

  void aux(vector<int>& nums, int start, int end) {
    if (start >= end - 1) return;
    int mid = (start + end) >> 1;
    aux(nums, start, mid);
    aux(nums, mid, end);
    vector<int> tmp;
    int i = start;
    int j = mid;
    while (i != mid && j != end) {
      if (nums[i] > nums[j]) {
        tmp.push_back(nums[j]);
        count += mid - i;
        ++j;
      } else {
        tmp.push_back(nums[i]);
        ++i;
      }
    }
    while (i != mid) tmp.push_back(nums[i++]);
    while (j != end) tmp.push_back(nums[j++]);
    int k = start;
    for (const int& i : tmp) nums[k++] = i;
  }
};