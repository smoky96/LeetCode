/*
 * @lc app=leetcode.cn id=718 lang=cpp
 *
 * [718] 最长重复子数组
 *
 * https://leetcode-cn.com/problems/maximum-length-of-repeated-subarray/description/
 *
 * algorithms
 * Medium (49.21%)
 * Likes:    255
 * Dislikes: 0
 * Total Accepted:    31.2K
 * Total Submissions: 59.1K
 * Testcase Example:  '[1,2,3,2,1]\n[3,2,1,4,7]'
 *
 * 给两个整数数组 A 和 B ，返回两个数组中公共的、长度最长的子数组的长度。
 *
 *
 *
 * 示例：
 *
 * 输入：
 * A: [1,2,3,2,1]
 * B: [3,2,1,4,7]
 * 输出：3
 * 解释：
 * 长度最长的公共子数组是 [3, 2, 1] 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= len(A), len(B) <= 1000
 * 0 <= A[i], B[i] < 100
 *
 *
 */

// @lc code=start
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
  int findLength(vector<int>& A, vector<int>& B) {
    int lenA = A.size();
    int lenB = B.size();
    vector<vector<int>> dp(lenA + 1, vector<int>(lenB + 1, 0));
    int ans = 0;
    for (int i = lenA - 1; i >= 0; --i) {
      for (int j = lenB - 1; j >= 0; --j) {
        dp[i][j] = A[i] == B[j] ? dp[i + 1][j + 1] + 1 : 0;
        ans = max(ans, dp[i][j]);
      }
    }
    return ans;
  }
};
// @lc code=end
