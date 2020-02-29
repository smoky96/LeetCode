/*
 * @lc app=leetcode.cn id=164 lang=cpp
 *
 * [164] 最大间距
 *
 * https://leetcode-cn.com/problems/maximum-gap/description/
 *
 * algorithms
 * Hard (54.36%)
 * Likes:    113
 * Dislikes: 0
 * Total Accepted:    10.8K
 * Total Submissions: 19.8K
 * Testcase Example:  '[3,6,9,1]'
 *
 * 给定一个无序的数组，找出数组在排序之后，相邻元素之间最大的差值。
 *
 * 如果数组元素个数小于 2，则返回 0。
 *
 * 示例 1:
 *
 * 输入: [3,6,9,1]
 * 输出: 3
 * 解释: 排序后的数组是 [1,3,6,9], 其中相邻元素 (3,6) 和 (6,9)
 * 之间都存在最大差值 3。
 *
 * 示例 2:
 *
 * 输入: [10]
 * 输出: 0
 * 解释: 数组元素个数小于 2，因此返回 0。
 *
 * 说明:
 *
 *
 * 你可以假设数组中所有元素都是非负整数，且数值在 32 位有符号整数范围内。
 * 请尝试在线性时间复杂度和空间复杂度的条件下解决此问题。
 *
 *
 */

// @lc code=start
#include <algorithm>
#include <iterator>
#include <vector>
using namespace std;

class Solution {
 public:
  int maximumGap(vector<int>& nums) {
    if (nums.size() < 2) {
      return 0;
    }

    if (nums.size() == 2) {
      return abs(nums[0] - nums[1]);
    }

    int max_num = *max_element(nums.begin(), nums.end());

    int exp = 1;

    while (max_num) {
      vector<vector<int>> bucket(10);
      vector<int> tmp;
      for (auto i : nums) {
        bucket[i / exp % 10].push_back(i);
      }

      for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < bucket[i].size(); ++j) {
          tmp.push_back(bucket[i][j]);
        }
      }

      nums = tmp;
      max_num /= 10;
      exp *= 10;
    }

    // copy(nums.begin(), nums.end(), ostream_iterator<int>(cout, " "));

    int ans = 0;
    for (int i = 0; i < nums.size() - 1; ++i) {
      if ((nums[i + 1] - nums[i]) > ans) {
        ans = nums[i + 1] - nums[i];
      }
    }

    return ans;
  }
};
// @lc code=end
