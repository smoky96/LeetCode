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
  int lengthOfLongestSubstring(string s) {
    if (s.length() == 0) return 0;
    int len = s.length();
    unordered_map<char, int> pos_dict;
    vector<int> dp(len + 1, 0);
    int ret = numeric_limits<int>::min();
    for (int i = 0; i < len; ++i) {
      if (pos_dict.count(s[i]) == 0) {
        dp[i + 1] = dp[i] + 1;
      } else {
        if (pos_dict[s[i]] < i - dp[i]) {
          dp[i + 1] = dp[i] + 1;
        } else {
          dp[i + 1] = i - pos_dict[s[i]];
        }
      }
      pos_dict[s[i]] = i;
      ret = ret >= dp[i + 1] ? ret : dp[i + 1];
    }
    return ret;
  }
};