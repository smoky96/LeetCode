/*
 * @lc app=leetcode.cn id=1162 lang=cpp
 *
 * [1162] 地图分析
 *
 * https://leetcode-cn.com/problems/as-far-from-land-as-possible/description/
 *
 * algorithms
 * Medium (38.51%)
 * Likes:    76
 * Dislikes: 0
 * Total Accepted:    16.3K
 * Total Submissions: 36.2K
 * Testcase Example:  '[[1,0,1],[0,0,0],[1,0,1]]'
 *
 * 你现在手里有一份大小为 N x N
 * 的『地图』（网格） grid，上面的每个『区域』（单元格）都用 0 和 1 标记好了。其中 0 代表海洋，1
 * 代表陆地，你知道距离陆地区域最远的海洋区域是是哪一个吗？请返回该海洋区域到离它最近的陆地区域的距离。
 *
 * 我们这里说的距离是『曼哈顿距离』（ Manhattan Distance）：(x0, y0) 和 (x1,
 * y1) 这两个区域之间的距离是 |x0 - x1| + |y0 - y1| 。
 *
 * 如果我们的地图上只有陆地或者海洋，请返回 -1。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：[[1,0,1],[0,0,0],[1,0,1]]
 * 输出：2
 * 解释：
 * 海洋区域 (1, 1) 和所有陆地区域之间的距离都达到最大，最大距离为 2。
 *
 *
 * 示例 2：
 *
 *
 *
 * 输入：[[1,0,0],[0,0,0],[0,0,0]]
 * 输出：4
 * 解释：
 * 海洋区域 (2, 2) 和所有陆地区域之间的距离都达到最大，最大距离为 4。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= grid.length == grid[0].length <= 100
 * grid[i][j] 不是 0 就是 1
 *
 *
 */

// @lc code=start
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<pair<int, int>> direction{{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
  queue<pair<int, int>> que;

  int maxDistance(vector<vector<int>>& grid) {
    bool vis[100][100];
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < grid.size(); ++i) {
      for (int j = 0; j < grid[0].size(); ++j) {
        if (grid[i][j] == 1) {
          que.push({i, j});
          vis[i][j] = true;
        }
      }
    }

    int dis = -1;
    while (!que.empty()) {
      int sz = que.size();
      for (int i = 0; i < sz; ++i) {
        auto loc = que.front();
        que.pop();

        for (const auto& p : direction) {
          int new_i = loc.first + p.first;
          int new_j = loc.second + p.second;

          if (new_i >= 0 && new_i < grid.size() && new_j >= 0 &&
              new_j < grid[0].size()) {
            if (!vis[new_i][new_j]) que.push({new_i, new_j});
            vis[new_i][new_j] = true;
          }
        }
      }
      ++dis;
    }

    return dis <= 0 ? -1 : dis;
  }
};
// @lc code=end
