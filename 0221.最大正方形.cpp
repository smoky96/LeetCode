/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 *
 * https://leetcode-cn.com/problems/maximal-square/description/
 *
 * algorithms
 * Medium (39.11%)
 * Likes:    259
 * Dislikes: 0
 * Total Accepted:    26K
 * Total Submissions: 66.2K
 * Testcase Example:
 * '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * 在一个由 0 和 1 组成的二维矩阵内，找到只包含 1 的最大正方形，并返回其面积。
 *
 * 示例:
 *
 * 输入:
 *
 * 1 0 1 0 0
 * 1 0 1 1 1
 * 1 1 1 1 1
 * 1 0 0 1 0
 *
 * 输出: 4
 *
 */

// @lc code=start
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int maximalSquare(vector<vector<char>>& matrix) {
    if (matrix.size() == 0) {
      return 0;
    }

    vector<int> dp(matrix[0].size() + 1, 0);
    int left_top = 0;

    int ans = 0;
    for (int i = 1; i <= matrix.size(); ++i) {
      left_top = 0;
      for (int j = 1; j <= matrix[0].size(); ++j) {
        int tmp = dp[j];
        if (matrix[i - 1][j - 1] == '1') {
          dp[j] = min(min(dp[j - 1], dp[j]), left_top) + 1;
          ans = ans > dp[j] ? ans : dp[j];
        } else {
          dp[j] = 0;
        }
        left_top = tmp;
      }
    }
    return ans * ans;
  }
};
// @lc code=end
