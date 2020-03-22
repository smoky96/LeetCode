/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 *
 * https://leetcode-cn.com/problems/surrounded-regions/description/
 *
 * algorithms
 * Medium (37.54%)
 * Likes:    135
 * Dislikes: 0
 * Total Accepted:    18.3K
 * Total Submissions: 47.3K
 * Testcase Example:
 * '[["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]'
 *
 * 给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。
 *
 * 找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。
 *
 * 示例:
 *
 * X X X X
 * X O O X
 * X X O X
 * X O X X
 *
 *
 * 运行你的函数后，矩阵变为：
 *
 * X X X X
 * X X X X
 * X X X X
 * X O X X
 *
 *
 * 解释:
 *
 * 被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。
 * 任何不在边界上，或不与边界上的 'O' 相连的 'O'
 * 最终都会被填充为 'X'。如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。
 *
 */

// @lc code=start
#include <queue>
#include <vector>
using namespace std;

class UnionFind {
  vector<int> parent;

 public:
  UnionFind(int sz) {
    parent.resize(sz);
    for (int i = 0; i < sz; ++i) {
      parent[i] = i;
    }
  }

  void Union(const int& x, const int& y) {
    int px = find(x);
    int py = find(y);
    if (px != py) {
      parent[py] = px;
    }
  }

  int find(const int& x) {
    int i = x;
    while (parent[i] != i) {
      parent[i] = parent[parent[i]];  // 路径压缩
      i = parent[i];
    }
    return i;
  }

  bool isConnect(const int& x, const int& y) { return find(x) == find(y); }
};

class Solution {
 public:
  int n_row;
  int n_col;
  void solve(vector<vector<char>>& board) {
    if (board.size() == 0) {
      return;
    }
    n_row = board.size();
    n_col = board[0].size();
    int dummy = n_row * n_col;
    UnionFind uf(n_row * n_col + 1);
    for (int i = 0; i < n_row; ++i) {
      for (int j = 0; j < n_col; ++j) {
        if (board[i][j] == 'O') {
          if (i == 0 || i == n_row - 1 || j == 0 || j == n_col - 1) {
            uf.Union(node(i, j), dummy);
          } else {
            if (board[i - 1][j] == 'O') uf.Union(node(i, j), node(i - 1, j));
            if (board[i + 1][j] == 'O') uf.Union(node(i, j), node(i + 1, j));
            if (board[i][j - 1] == 'O') uf.Union(node(i, j), node(i, j - 1));
            if (board[i][j + 1] == 'O') uf.Union(node(i, j), node(i, j + 1));
          }
        }
      }
    }

    for (int i = 0; i < n_row; ++i) {
      for (int j = 0; j < n_col; ++j) {
        if (!uf.isConnect(node(i, j), dummy)) board[i][j] = 'X';
      }
    }
  }

  int node(int i, int j) { return i * n_col + j; }
};
// @lc code=end
