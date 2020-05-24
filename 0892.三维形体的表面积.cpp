/*
 * @lc app=leetcode.cn id=892 lang=cpp
 *
 * [892] 三维形体的表面积
 *
 * https://leetcode-cn.com/problems/surface-area-of-3d-shapes/description/
 *
 * algorithms
 * Easy (55.81%)
 * Likes:    92
 * Dislikes: 0
 * Total Accepted:    20.7K
 * Total Submissions: 32.5K
 * Testcase Example:  '[[2]]'
 *
 * 在 N * N 的网格上，我们放置一些 1 * 1 * 1  的立方体。
 *
 * 每个值 v = grid[i][j] 表示 v 个正方体叠放在对应单元格 (i, j) 上。
 *
 * 请你返回最终形体的表面积。
 *
 *
 *
 *
 *
 *
 * 示例 1：
 *
 * 输入：[[2]]
 * 输出：10
 *
 *
 * 示例 2：
 *
 * 输入：[[1,2],[3,4]]
 * 输出：34
 *
 *
 * 示例 3：
 *
 * 输入：[[1,0],[0,2]]
 * 输出：16
 *
 *
 * 示例 4：
 *
 * 输入：[[1,1,1],[1,0,1],[1,1,1]]
 * 输出：32
 *
 *
 * 示例 5：
 *
 * 输入：[[2,2,2],[2,1,2],[2,2,2]]
 * 输出：46
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= N <= 50
 * 0 <= grid[i][j] <= 50
 *
 *
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
 public:
  int surfaceArea(vector<vector<int>>& grid) {
    int ans = 0;
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        int tmp = grid[i][j];
        if (tmp > 0) {
          ans += (tmp << 2) + 2;
          ans -= i > 0 ? (tmp > grid[i - 1][j] ? grid[i - 1][j] : tmp) << 1 : 0;
          ans -= j > 0 ? (tmp > grid[i][j - 1] ? grid[i][j - 1] : tmp) << 1 : 0;
        }
      }
    }
    return ans;
  }
};
// @lc code=end
