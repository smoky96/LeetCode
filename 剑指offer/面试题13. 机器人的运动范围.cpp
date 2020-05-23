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
  vector<pair<int, int>> direction{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  int movingCount(int m, int n, int k) {
    vector<vector<bool>> vis(m, vector<bool>(n, false));
    return aux(m, n, 0, 0, k, vis);
  }

  int aux(int m, int n, int x, int y, int k, vector<vector<bool>>& vis) {
    int ret = 0;
    if (x >= 0 && x < m && y >= 0 && y < n && !vis[x][y] && check(x, y, k)) {
      vis[x][y] = true;
      ret += 1;
      for (auto& loc : direction) {
        ret += aux(m, n, x + loc.first, y + loc.second, k, vis);
      }
    }
    return ret;
  }

  bool check(int x, int y, int k) {
    int sum = 0;
    while (x) {
      sum += x % 10;
      x /= 10;
    }
    while (y) {
      sum += y % 10;
      y /= 10;
    }
    if (sum > k) return false;
    return true;
  }
};