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
  int search(vector<int>& nums, int target) {
    int begin = 0;
    int end = nums.size();
    int mid = 0;

    while (begin < end) {
      mid = (begin + end) >> 1;
      if (nums[mid] < target) {
        begin = mid + 1;
      } else if (nums[mid] >= target) {
        end = mid;
      }
    }
    int first = begin;

    begin = 0;
    end = nums.size();
    while (begin < end) {
      mid = (begin + end) >> 1;
      if (nums[mid] <= target) {
        begin = mid + 1;
      } else if (nums[mid] > target) {
        end = mid;
      }
    }
    int last = begin;

    return last - first - 1;
  }
};