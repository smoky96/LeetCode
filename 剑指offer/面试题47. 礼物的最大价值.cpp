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
  int maxValue(vector<vector<int>>& grid) {
    vector<int> dp(grid[0].size() + 1, 0);
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        dp[j + 1] = max(grid[i][j] + dp[j], grid[i][j] + dp[j + 1]);
      }
      PRINT_ARY(dp, int);
    }
    return dp[grid.size()];
  }
};