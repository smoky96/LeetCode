#include <stdio.h>
#include <string.h>

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
  int translateNum(int num) {
    string num_str = to_string(num);
    int len = num_str.length();
    int dp[len + 1];
    dp[len] = 1;
    dp[len - 1] = 1;
    for (int i = len - 2; i >= 0; --i) {
      int tmp = atoi(num_str.substr(i, 2).c_str());
      if (tmp >= 10 && tmp <= 25) {
        dp[i] = dp[i + 1] + dp[i + 2];
      } else {
        dp[i] = dp[i + 1];
      }
    }
    return dp[0];
  }
};