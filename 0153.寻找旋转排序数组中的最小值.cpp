/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 *
 * https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (50.22%)
 * Likes:    140
 * Dislikes: 0
 * Total Accepted:    32.5K
 * Total Submissions: 64.7K
 * Testcase Example:  '[3,4,5,1,2]'
 *
 * 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
 *
 * ( 例如，数组 [0,1,2,4,5,6,7]  可能变为 [4,5,6,7,0,1,2] )。
 *
 * 请找出其中最小的元素。
 *
 * 你可以假设数组中不存在重复元素。
 *
 * 示例 1:
 *
 * 输入: [3,4,5,1,2]
 * 输出: 1
 *
 * 示例 2:
 *
 * 输入: [4,5,6,7,0,1,2]
 * 输出: 0
 *
 */

// @lc code=start
#include <vector>

using namespace std;

class Solution {
 public:
  int findMin(vector<int>& nums) {
    auto first = nums.begin();
    auto last = nums.end() - 1;
    int len = nums.size();

    while (len) {
      int mid = len >> 1;
      if (*(first + mid) > *last) {
        first = first + mid + 1;
      } else {
        last = first + mid;
      }
      len = last - first;
    }
    return *first;
  }
};
// @lc code=end
