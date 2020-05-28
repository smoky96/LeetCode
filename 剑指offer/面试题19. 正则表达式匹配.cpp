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
  bool isMatch(string s, string p) {
    int s_len = s.length();
    int p_len = p.length();
    vector<vector<bool>> dp(s_len + 1, vector<bool>(p_len + 1, false));

    for (int i = 0; i <= s_len; ++i) {
      for (int j = 0; j <= p_len; ++j) {
        if (j == 0) {
          dp[i][j] = i == 0;
        } else {
          if (p[j - 1] != '*') {
            if (i > 0 && (s[i - 1] == p[j - 1] || p[j - 1] == '.'))
              dp[i][j] = dp[i - 1][j - 1];
          } else if (j > 1) {
            dp[i][j] = dp[i][j - 2];
            if (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.')) {
              dp[i][j] = dp[i - 1][j] || dp[i][j];
            }
          }
        }
      }
    }
    return dp[s_len][p_len];
  }
};