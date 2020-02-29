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

class Solution {
public:
  void solve(vector<vector<char>> &board) {
    if (board.size() == 0) {
      return;
    }

    vector<vector<bool>> visited(board.size(),
                                 vector<bool>(board[0].size(), false));
    vector<pair<int, int>> ready_to_change;
    bool toch_edge = false;
    for (int i = 1; i < board.size() - 1; ++i) {
      for (int j = 1; j < board[0].size() - 1; ++j) {
        if (board[i][j] == 'X' || visited[i][j]) {
          continue;
        }
        aux(board, visited, ready_to_change, i, j, toch_edge);
        if (!toch_edge) {
          for (auto p : ready_to_change) {
            board[p.first][p.second] = 'X';
          }
        }
        ready_to_change.clear();
        toch_edge = false;
      }
    }
  }

  void aux(const vector<vector<char>> &board, vector<vector<bool>> &visited,
           vector<pair<int, int>> &ready_to_change, int i, int j,
           bool &touch_edge) {
    if (visited[i][j]) {
      return;
    }

    visited[i][j] = true;

    if (board[i][j] == 'X') {
      return;
    } else {
      if (i == 0 || i == board.size() - 1 || j == 0 ||
          j == board[0].size() - 1) {
        touch_edge = true;
      }
      if (!touch_edge)
        ready_to_change.push_back(make_pair(i, j));
    }
    if (i + 1 < board.size())
      aux(board, visited, ready_to_change, i + 1, j, touch_edge);
    if (i - 1 >= 0)
      aux(board, visited, ready_to_change, i - 1, j, touch_edge);
    if (j - 1 >= 0)
      aux(board, visited, ready_to_change, i, j - 1, touch_edge);
    if (j + 1 < board[0].size())
      aux(board, visited, ready_to_change, i, j + 1, touch_edge);
  }
};
// @lc code=end
