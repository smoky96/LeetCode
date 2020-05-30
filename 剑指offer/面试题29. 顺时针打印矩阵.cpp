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
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    int n_row = matrix.size();
    if (n_row == 0) return {};
    int n_col = matrix[0].size();
    vector<int> ans;
    int cnt = (min(n_row, n_col) + 1) / 2;
    for (int i = 0; i < cnt; ++i) {
      aux(matrix, ans, i);
    }
    return ans;
  }

  void aux(const vector<vector<int>>& matrix, vector<int>& ans, int start) {
    int end_x = matrix.size() - start - 1;
    int end_y = matrix[0].size() - start - 1;
    for (int i = start; i <= end_y; ++i) {
      ans.push_back(matrix[start][i]);
    }

    if (start < end_x)
      for (int i = start + 1; i <= end_x; ++i) {
        ans.push_back(matrix[i][end_y]);
      }

    if (start < end_y && start < end_x)
      for (int i = end_y - 1; i >= start; --i) {
        ans.push_back(matrix[end_x][i]);
      }

    if (start < end_x - 1 && start < end_y)
      for (int i = end_x - 1; i > start; --i) {
        ans.push_back(matrix[i][start]);
      }
  }
};