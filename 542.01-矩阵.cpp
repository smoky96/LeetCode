/*
 * @lc app=leetcode.cn id=542 lang=cpp
 *
 * [542] 01 矩阵
 *
 * https://leetcode-cn.com/problems/01-matrix/description/
 *
 * algorithms
 * Medium (38.07%)
 * Likes:    227
 * Dislikes: 0
 * Total Accepted:    24K
 * Total Submissions: 56K
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * 给定一个由 0 和 1 组成的矩阵，找出每个元素到最近的 0 的距离。
 *
 * 两个相邻元素间的距离为 1 。
 *
 * 示例 1:
 * 输入:
 *
 *
 * 0 0 0
 * 0 1 0
 * 0 0 0
 *
 *
 * 输出:
 *
 *
 * 0 0 0
 * 0 1 0
 * 0 0 0
 *
 *
 * 示例 2:
 * 输入:
 *
 *
 * 0 0 0
 * 0 1 0
 * 1 1 1
 *
 *
 * 输出:
 *
 *
 * 0 0 0
 * 0 1 0
 * 1 2 1
 *
 *
 * 注意:
 *
 *
 * 给定矩阵的元素个数不超过 10000。
 * 给定矩阵中至少有一个元素是 0。
 * 矩阵中的元素只在四个方向上相邻: 上、下、左、右。
 *
 *
 */

// @lc code=start
#include <queue>
#include <vector>
using namespace std;

class Solution {
  vector<pair<int, int>> direct{{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

 public:
  vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
    vector<vector<int>> ans(matrix.size(), vector<int>(matrix[0].size(), 0));

    queue<pair<int, int>> que;
    for (int i = 0; i < matrix.size(); ++i) {
      for (int j = 0; j < matrix[0].size(); ++j) {
        if (matrix[i][j] == 0) {
          que.push({i, j});
        }
      }
    }

    bfs(matrix, ans, que);
    return ans;
  }

  void bfs(const vector<vector<int>>& matrix, vector<vector<int>>& ans,
           queue<pair<int, int>>& que) {
    int cnt = 0;
    while (!que.empty()) {
      int sz = que.size();
      ++cnt;
      for (int k = 0; k < sz; ++k) {
        auto loc = que.front();
        que.pop();
        for (const auto& p : direct) {
          int next_i = loc.first + p.first;
          int next_j = loc.second + p.second;
          if (next_i >= 0 && next_i < matrix.size() && next_j >= 0 &&
              next_j < matrix[0].size() && matrix[next_i][next_j] == 1 &&
              ans[next_i][next_j] == 0) {
            que.push({next_i, next_j});
            ans[next_i][next_j] = cnt;
          }
        }
      }
    }
  }
};
// @lc code=end
