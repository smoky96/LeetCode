/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 *
 * https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/description/
 *
 * algorithms
 * Hard (46.44%)
 * Likes:    75
 * Dislikes: 0
 * Total Accepted:    13.5K
 * Total Submissions: 29.1K
 * Testcase Example:  '[1,3,5]'
 *
 * 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
 *
 * ( 例如，数组 [0,1,2,4,5,6,7]  可能变为 [4,5,6,7,0,1,2] )。
 *
 * 请找出其中最小的元素。
 *
 * 注意数组中可能存在重复的元素。
 *
 * 示例 1：
 *
 * 输入: [1,3,5]
 * 输出: 1
 *
 * 示例 2：
 *
 * 输入: [2,2,2,0,1]
 * 输出: 0
 *
 * 说明：
 *
 *
 * 这道题是 寻找旋转排序数组中的最小值 的延伸题目。
 * 允许重复会影响算法的时间复杂度吗？会如何影响，为什么？
 *
 *
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
 public:
  int findMin(vector<int>& nums) {
    int i = 0;
    int j = nums.size() - 1;
    while (j > i) {
      int mid = (j + i) >> 1;
      if (nums[mid] > nums[j]) {
        i = mid + 1;
      } else if (nums[mid] < nums[j]) {
        j = mid;
      } else {
        --j;
      }
    }
    return nums[i];
  }
};
// @lc code=end
