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
  vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    if (nums.size() == 0) return {};
    deque<int> deq;
    deque<int> que;
    vector<int> ans;
    for (int i = 0; i < nums.size(); ++i) {
      if (que.size() < k) {
        que.push_back(i);
      } else {
        ans.push_back(nums[deq.front()]);
        if (que.front() == deq.front()) {
          deq.pop_front();
        }
        que.pop_front();
        que.push_back(i);
      }

      while (!deq.empty() && nums[deq.back()] < nums[i]) deq.pop_back();
      deq.push_back(i);
    }
    ans.push_back(nums[deq.front()]);
    return ans;
  }
};