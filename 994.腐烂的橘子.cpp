/*
 * @lc app=leetcode.cn id=994 lang=cpp
 *
 * [994] 腐烂的橘子
 *
 * https://leetcode-cn.com/problems/rotting-oranges/description/
 *
 * algorithms
 * Easy (49.51%)
 * Likes:    140
 * Dislikes: 0
 * Total Accepted:    15.3K
 * Total Submissions: 31K
 * Testcase Example:  '[[2,1,1],[1,1,0],[0,1,1]]'
 *
 * 在给定的网格中，每个单元格可以有以下三个值之一：
 *
 *
 * 值 0 代表空单元格；
 * 值 1 代表新鲜橘子；
 * 值 2 代表腐烂的橘子。
 *
 *
 * 每分钟，任何与腐烂的橘子（在 4 个正方向上）相邻的新鲜橘子都会腐烂。
 *
 * 返回直到单元格中没有新鲜橘子为止所必须经过的最小分钟数。如果不可能，返回 -1。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：[[2,1,1],[1,1,0],[0,1,1]]
 * 输出：4
 *
 *
 * 示例 2：
 *
 * 输入：[[2,1,1],[0,1,1],[1,0,1]]
 * 输出：-1
 * 解释：左下角的橘子（第 2 行， 第 0 列）永远不会腐烂，因为腐烂只会发生在 4
 * 个正向上。
 *
 *
 * 示例 3：
 *
 * 输入：[[0,2]]
 * 输出：0
 * 解释：因为 0 分钟时已经没有新鲜橘子了，所以答案就是 0 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= grid.length <= 10
 * 1 <= grid[0].length <= 10
 * grid[i][j] 仅为 0、1 或 2
 *
 *
 */

// @lc code=start
#include <queue>
#include <vector>
using namespace std;

class Solution {
 public:
  int orangesRotting(vector<vector<int>>& grid) {
    vector<vector<int>> time_table(grid.size(),
                                   vector<int>(grid[0].size(), -1));
    vector<pair<int, int>> rot_loc;
    int fresh_cnt = 0;
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        if (grid[i][j] == 1) ++fresh_cnt;
        if (grid[i][j] == 2) rot_loc.push_back({i, j});
      }
    }

    int rotten = aux(grid, time_table, rot_loc);
    if (rotten - rot_loc.size() != fresh_cnt) {
      return -1;
    }

    int ans = 0;
    for (int i = 0; i < time_table.size(); ++i) {
      for (int j = 0; j < time_table[0].size(); ++j) {
        if (time_table[i][j] > ans) {
          ans = time_table[i][j];
        }
      }
    }
    return ans;
  }

  int aux(vector<vector<int>>& grid, vector<vector<int>>& tt,
          vector<pair<int, int>> rottens) {
    queue<pair<int, int>> que;
    for (auto& loc : rottens) {
      que.push(loc);
    }

    int rotten_cnt = 0;
    int t_cnt = 0;
    while (!que.empty()) {
      int n = que.size();
      for (int i = 0; i < n; ++i) {
        auto loc = que.front();
        que.pop();

        int cur_i = loc.first;
        int cur_j = loc.second;
        grid[cur_i][cur_j] = 2;

        if (tt[cur_i][cur_j] == -1) {
          tt[cur_i][cur_j] = t_cnt;
          ++rotten_cnt;
        }

        if (cur_i + 1 < grid.size() && grid[cur_i + 1][cur_j] == 1) {
          que.push({cur_i + 1, cur_j});
        }
        if (cur_i > 0 && grid[cur_i - 1][cur_j] == 1) {
          que.push({cur_i - 1, cur_j});
        }
        if (cur_j > 0 && grid[cur_i][cur_j - 1] == 1) {
          que.push({cur_i, cur_j - 1});
        }
        if (cur_j + 1 < grid[0].size() && grid[cur_i][cur_j + 1] == 1) {
          que.push({cur_i, cur_j + 1});
        }
      }
      ++t_cnt;
    }
    return rotten_cnt;
  }
};
// @lc code=end
