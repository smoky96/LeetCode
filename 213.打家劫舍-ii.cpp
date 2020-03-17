/*
 * @lc app=leetcode.cn id=213 lang=cpp
 *
 * [213] 打家劫舍 II
 *
 * https://leetcode-cn.com/problems/house-robber-ii/description/
 *
 * algorithms
 * Medium (36.67%)
 * Likes:    207
 * Dislikes: 0
 * Total Accepted:    23.6K
 * Total Submissions: 64.1K
 * Testcase Example:  '[2,3,2]'
 *
 *
 * 你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都围成一圈，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
 *
 * 给定一个代表每个房屋存放金额的非负整数数组，计算你在不触动警报装置的情况下，能够偷窃到的最高金额。
 *
 * 示例 1:
 *
 * 输入: [2,3,2]
 * 输出: 3
 * 解释: 你不能先偷窃 1 号房屋（金额 = 2），然后偷窃 3 号房屋（金额 = 2）,
 * 因为他们是相邻的。
 *
 *
 * 示例 2:
 *
 * 输入: [1,2,3,1]
 * 输出: 4
 * 解释: 你可以先偷窃 1 号房屋（金额 = 1），然后偷窃 3 号房屋（金额 = 3）。
 * 偷窃到的最高金额 = 1 + 3 = 4 。
 *
 */

// @lc code=start
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  int rob(vector<int>& nums) {
    if (nums.size() < 2) {
      return nums.size() == 0 ? 0 : nums[0];
    }

    int ans = 0;
    int dp_pre = 0;
    int dp_i = nums[0];
    for (int i = 1; i < nums.size() - 1; ++i) {
      int tmp = dp_i;
      dp_i = max(nums[i] + dp_pre, dp_i);
      dp_pre = tmp;
    }
    ans = dp_i;
    dp_pre = 0;
    dp_i = nums[1];
    for (int i = 2; i < nums.size(); ++i) {
      int tmp = dp_i;
      dp_i = max(nums[i] + dp_pre, dp_i);
      dp_pre = tmp;
    }

    return ans > dp_i ? ans : dp_i;
  }
};
// @lc code=end
