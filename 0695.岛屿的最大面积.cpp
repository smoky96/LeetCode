/*
 * @lc app=leetcode.cn id=695 lang=cpp
 *
 * [695] 岛屿的最大面积
 *
 * https://leetcode-cn.com/problems/max-area-of-island/description/
 *
 * algorithms
 * Medium (59.69%)
 * Likes:    213
 * Dislikes: 0
 * Total Accepted:    28.8K
 * Total Submissions: 46.4K
 * Testcase Example:  '[[1,1,0,0,0],[1,1,0,0,0],[0,0,0,1,1],[0,0,0,1,1]]'
 *
 * 给定一个包含了一些 0 和 1的非空二维数组 grid , 一个 岛屿 是由四个方向
 * (水平或垂直) 的 1 (代表土地)
 * 构成的组合。你可以假设二维矩阵的四个边缘都被水包围着。
 *
 * 找到给定的二维数组中最大的岛屿面积。(如果没有岛屿，则返回面积为0。)
 *
 * 示例 1:
 *
 *
 * [[0,0,1,0,0,0,0,1,0,0,0,0,0],
 * ⁠[0,0,0,0,0,0,0,1,1,1,0,0,0],
 * ⁠[0,1,1,0,1,0,0,0,0,0,0,0,0],
 * ⁠[0,1,0,0,1,1,0,0,1,0,1,0,0],
 * ⁠[0,1,0,0,1,1,0,0,1,1,1,0,0],
 * ⁠[0,0,0,0,0,0,0,0,0,0,1,0,0],
 * ⁠[0,0,0,0,0,0,0,1,1,1,0,0,0],
 * ⁠[0,0,0,0,0,0,0,1,1,0,0,0,0]]
 *
 *
 * 对于上面这个给定矩阵应返回 6。注意答案不应该是11，因为岛屿只能包含水平或垂直的四个方向的‘1’。
 *
 * 示例 2:
 *
 *
 * [[0,0,0,0,0,0,0,0]]
 *
 * 对于上面这个给定的矩阵, 返回 0。
 *
 * 注意: 给定的矩阵grid 的长度和宽度都不超过 50。
 *
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
 public:
  vector<pair<int, int>> direct{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

  int maxAreaOfIsland(vector<vector<int>>& grid) {
    if (grid.size() == 0) return 0;
    int n_row = grid.size();
    int n_col = grid[0].size();

    int ans = 0;
    vector<vector<bool>> vis(n_row, vector<bool>(n_col, false));
    for (int i = 0; i < n_row; ++i) {
      for (int j = 0; j < n_col; ++j) {
        if (!vis[i][j] && grid[i][j] == 1) {
          ans = max(ans, aux(grid, vis, i, j) + 1);
        }
      }
    }
    return ans;
  }

  int aux(const vector<vector<int>>& grid, vector<vector<bool>>& vis, int i,
          int j) {
    vis[i][j] = true;
    int ret = 0;
    for (auto& p : direct) {
      int next_i = i + p.first;
      int next_j = j + p.second;
      if (next_i < grid.size() && next_j < grid[0].size() &&
          !vis[next_i][next_j] && grid[next_i][next_j] == 1)
        ret += (aux(grid, vis, i + p.first, j + p.second) + 1);
    }
    return ret;
  }
};
// @lc code=end
