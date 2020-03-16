/*
 * @lc app=leetcode.cn id=209 lang=cpp
 *
 * [209] 长度最小的子数组
 *
 * https://leetcode-cn.com/problems/minimum-size-subarray-sum/description/
 *
 * algorithms
 * Medium (41.53%)
 * Likes:    207
 * Dislikes: 0
 * Total Accepted:    30.7K
 * Total Submissions: 73.8K
 * Testcase Example:  '7\n[2,3,1,2,4,3]'
 *
 * 给定一个含有 n 个正整数的数组和一个正整数 s ，找出该数组中满足其和 ≥ s
 * 的长度最小的连续子数组。如果不存在符合条件的连续子数组，返回 0。
 *
 * 示例: 
 *
 * 输入: s = 7, nums = [2,3,1,2,4,3]
 * 输出: 2
 * 解释: 子数组 [4,3] 是该条件下的长度最小的连续子数组。
 *
 *
 * 进阶:
 *
 * 如果你已经完成了O(n) 时间复杂度的解法, 请尝试 O(n log n) 时间复杂度的解法。
 *
 */

// @lc code=start
#include <climits>
#include <vector>
using namespace std;

class Solution {
 public:
  int minSubArrayLen(int s, vector<int>& nums) {
    if (nums.size() == 0) {
      return 0;
    }
    int i = 0;
    int j = 0;
    int sum = nums[i];
    int ans = INT_MAX;
    while (i <= j && j < nums.size()) {
      if (sum < s) {
        ++j;
        if (j < nums.size()) sum += nums[j];
      } else {
        ans = min(ans, j - i + 1);
        sum -= nums[i];
        ++i;
      }
    }
    return ans == INT_MAX ? 0 : ans;
  }
};
// @lc code=end
