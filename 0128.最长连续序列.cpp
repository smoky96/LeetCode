/*
 * @lc app=leetcode.cn id=128 lang=cpp
 *
 * [128] 最长连续序列
 *
 * https://leetcode-cn.com/problems/longest-consecutive-sequence/description/
 *
 * algorithms
 * Hard (46.34%)
 * Likes:    215
 * Dislikes: 0
 * Total Accepted:    22.7K
 * Total Submissions: 47.9K
 * Testcase Example:  '[100,4,200,1,3,2]'
 *
 * 给定一个未排序的整数数组，找出最长连续序列的长度。
 *
 * 要求算法的时间复杂度为 O(n)。
 *
 * 示例:
 *
 * 输入: [100, 4, 200, 1, 3, 2]
 * 输出: 4
 * 解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。
 *
 */

// @lc code=start
#include <climits>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    if (nums.size() == 0) {
      return 0;
    }
    unordered_set<int> dict(nums.begin(), nums.end());
    int tmp = 1;
    int ans = 1;
    for (auto i : dict) {
      while (dict.find(i + 1) != dict.end()) {
        ++tmp;
        ++i;
      }
      if (tmp > ans) ans = tmp;
      tmp = 1;
    }
    return ans;
  }
};
// @lc code=end
