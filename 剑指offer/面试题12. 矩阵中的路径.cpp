#include <stdio.h>

#include <algorithm>
#include <deque>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<pair<int, int>> direction{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
  bool exist(vector<vector<char>>& board, string word) {
    if (board.size() == 0 || board[0].size() == 0) return false;
    if (word.length() == 0) return true;

    int n_row = board.size();
    int n_col = board[0].size();

    vector<vector<bool>> vis(n_row, vector<bool>(n_col, false));
    for (int i = 0; i < n_row; ++i) {
      for (int j = 0; j < n_col; ++j) {
        if (board[i][j] == word[0]) {
          if (aux(board, vis, i, j, 0, word)) return true;
        }
      }
    }
    return false;
  }

  bool aux(const vector<vector<char>>& board, vector<vector<bool>>& vis, int x,
           int y, int cur, const string& word) {
    if (cur == word.length()) return true;

    bool ret = false;
    if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size() &&
        !vis[x][y] && board[x][y] == word[cur]) {
      ++cur;
      vis[x][y] = true;
      ret = aux(board, vis, x + 1, y, cur, word) ||
            aux(board, vis, x - 1, y, cur, word) ||
            aux(board, vis, x, y + 1, cur, word) ||
            aux(board, vis, x, y - 1, cur, word);
      vis[x][y] = false;
      --cur;
    }
    return ret;
  }
};