/*
 * @lc app=leetcode.cn id=149 lang=cpp
 *
 * [149] 直线上最多的点数
 *
 * https://leetcode-cn.com/problems/max-points-on-a-line/description/
 *
 * algorithms
 * Hard (20.46%)
 * Likes:    108
 * Dislikes: 0
 * Total Accepted:    8.3K
 * Total Submissions: 40.5K
 * Testcase Example:  '[[1,1],[2,2],[3,3]]'
 *
 * 给定一个二维平面，平面上有 n 个点，求最多有多少个点在同一条直线上。
 *
 * 示例 1:
 *
 * 输入: [[1,1],[2,2],[3,3]]
 * 输出: 3
 * 解释:
 * ^
 * |
 * |        o
 * |     o
 * |  o  
 * +------------->
 * 0  1  2  3  4
 *
 *
 * 示例 2:
 *
 * 输入: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
 * 输出: 4
 * 解释:
 * ^
 * |
 * |  o
 * |     o        o
 * |        o
 * |  o        o
 * +------------------->
 * 0  1  2  3  4  5  6
 *
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
 public:
  int maxPoints(vector<vector<int>>& points) {
    if (points.size() == 0) {
      return 0;
    }
    if (points.size() == 2) {
      return 2;
    }

    int ans = 0;
    for (int i = 0; i < points.size(); ++i) {
      for (int j = i + 1; j < points.size(); ++j) {
        long long x0 = points[i][0];
        long long y0 = points[i][1];
        long long x1 = points[j][0];
        long long y1 = points[j][1];
        // 若两点重叠，则无法形成一条直线，跳过
        if (x0 == x1 && y0 == y1) {
          continue;
        }
        long long a = x1 - x0;
        long long b = y1 - y0;
        int tmp = 2;
        for (int k = 0; k < points.size(); ++k) {
          if (k != i && k != j) {
            if (a * (y1 - points[k][1]) == b * (x1 - points[k][0])) {
              ++tmp;
            }
          }
        }
        ans = tmp > ans ? tmp : ans;
      }
    }
    // 检查是否所有点都相等，若时这样，则所有点都在一条直线上
    if (ans == 0) {
      return points.size();
    }

    return ans;
  }
};
// @lc code=end
