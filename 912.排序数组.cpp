/*
 * @lc app=leetcode.cn id=912 lang=cpp
 *
 * [912] 排序数组
 *
 * https://leetcode-cn.com/problems/sort-an-array/description/
 *
 * algorithms
 * Medium (53.29%)
 * Likes:    96
 * Dislikes: 0
 * Total Accepted:    44.7K
 * Total Submissions: 75.7K
 * Testcase Example:  '[5,2,3,1]'
 *
 * 给你一个整数数组 nums，请你将该数组升序排列。
 *
 *
 *
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [5,2,3,1]
 * 输出：[1,2,3,5]
 *
 *
 * 示例 2：
 *
 * 输入：nums = [5,1,1,2,0,0]
 * 输出：[0,0,1,1,2,5]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 50000
 * -50000 <= nums[i] <= 50000
 *
 *
 */

// @lc code=start
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> sortArray(vector<int>& nums) {
    if (nums.size() == 0) return nums;
    int MAX = *(max_element(nums.begin(), nums.end()));
    int MIN = *(min_element(nums.begin(), nums.end()));

    vector<int> cnt(MAX - MIN + 1, 0);

    for (const int& i : nums) {
      ++cnt[i - MIN];
    }

    int idx = 0;
    for (int i = 0; i < cnt.size(); ++i) {
      int tmp = i + MIN;
      while (cnt[i]--) nums[idx++] = tmp;
    }

    return nums;
  }
};
// @lc code=end
