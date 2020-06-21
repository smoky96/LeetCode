#include <math.h>
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
  vector<double> twoSum(int n) {
    vector<vector<int>> dp(2, vector<int>(6 * n + 1, 0));

    int flag = 0;
    for (int i = 1; i <= 6; ++i) {
      dp[1 - flag][i] = 1;
    }
    for (int i = 2; i <= n; ++i) {
      for (int j = 0; j < i; ++j) {
        dp[flag][j] = 0;
      }
      for (int j = i; j <= 6 * i; ++j) {
        dp[flag][j] = 0;
        for (int k = 1; k <= 6 && k <= j; ++k) {
          dp[flag][j] += dp[1 - flag][j - k];
        }
      }
      flag = 1 - flag;
    }

    flag = 1 - flag;
    double total = pow((double)6, n);
    vector<double> ans;
    for (int i = n; i <= 6 * n; ++i) {
      ans.push_back((double)dp[flag][i] / total);
    }
    return ans;
  }
};