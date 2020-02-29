/*
 * @lc app=leetcode.cn id=152 lang=cpp
 *
 * [152] 乘积最大子序列
 *
 * https://leetcode-cn.com/problems/maximum-product-subarray/description/
 *
 * algorithms
 * Medium (37.24%)
 * Likes:    381
 * Dislikes: 0
 * Total Accepted:    35.3K
 * Total Submissions: 94.9K
 * Testcase Example:  '[2,3,-2,4]'
 *
 * 给定一个整数数组
 * nums ，找出一个序列中乘积最大的连续子序列（该序列至少包含一个数）。
 *
 * 示例 1:
 *
 * 输入: [2,3,-2,4]
 * 输出: 6
 * 解释: 子数组 [2,3] 有最大乘积 6。
 *
 *
 * 示例 2:
 *
 * 输入: [-2,0,-1]
 * 输出: 0
 * 解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
 *
 */

// @lc code=start
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxProduct(vector<int>& nums) {
    if (nums.size() == 0) {
      return 0;
    }

    int dp_min = nums[0];
    int dp_max = nums[0];

    int ans = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
      int pre_min = dp_min;
      dp_min = min(nums[i], min(dp_min * nums[i], dp_max * nums[i]));
      dp_max = max(nums[i], max(pre_min * nums[i], dp_max * nums[i]));
      ans = max(ans, dp_max);
    }
    return ans;
  }
};
// @lc code=end
