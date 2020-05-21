#include <algorithm>
#include <deque>
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
  bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
    int n_row = matrix.size();
    if (n_row == 0) return false;
    int n_col = matrix[0].size();

    int i = n_row - 1;
    int j = 0;

    while (i >= 0 && j < n_col) {
      if (matrix[i][j] < target) {
        ++j;
      } else if (matrix[i][j] > target) {
        --i;
      } else {
        return true;
      }
    }
    return false;
  }
};