/*
 * @lc app=leetcode.cn id=135 lang=cpp
 *
 * [135] 分发糖果
 *
 * https://leetcode-cn.com/problems/candy/description/
 *
 * algorithms
 * Hard (41.48%)
 * Likes:    148
 * Dislikes: 0
 * Total Accepted:    13.1K
 * Total Submissions: 31.9K
 * Testcase Example:  '[1,0,2]'
 *
 * 老师想给孩子们分发糖果，有
 * N 个孩子站成了一条直线，老师会根据每个孩子的表现，预先给他们评分。
 *
 * 你需要按照以下要求，帮助老师给这些孩子分发糖果：
 *
 *
 * 每个孩子至少分配到 1 个糖果。
 * 相邻的孩子中，评分高的孩子必须获得更多的糖果。
 *
 *
 * 那么这样下来，老师至少需要准备多少颗糖果呢？
 *
 * 示例 1:
 *
 * 输入: [1,0,2]
 * 输出: 5
 * 解释: 你可以分别给这三个孩子分发 2、1、2 颗糖果。
 *
 *
 * 示例 2:
 *
 * 输入: [1,2,2]
 * 输出: 4
 * 解释: 你可以分别给这三个孩子分发 1、2、1 颗糖果。
 * ⁠    第三个孩子只得到 1
 * 颗糖果，这已满足上述两个条件。
 *
 */

// @lc code=start
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int candy(vector<int>& ratings) {
    vector<int> left2right(ratings.size(), 1);
    vector<int> right2left(ratings.size(), 1);
    for (int i = 1; i < ratings.size(); ++i) {
      if (ratings[i] > ratings[i - 1]) left2right[i] = left2right[i - 1] + 1;
    }
    for (int i = ratings.size() - 2; i >= 0; --i) {
      if (ratings[i] > ratings[i + 1]) right2left[i] = right2left[i + 1] + 1;
    }
    int ans = 0;
    for (int i = 0; i < ratings.size(); ++i) {
      ans += max(left2right[i], right2left[i]);
    }
    return ans;
  }
};
// @lc code=end
