/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 *
 * https://leetcode-cn.com/problems/find-first-and-last-position-of-element-in-sorted-array/description/
 *
 * algorithms
 * Medium (37.46%)
 * Likes:    246
 * Dislikes: 0
 * Total Accepted:    44.3K
 * Total Submissions: 116.2K
 * Testcase Example:  '[5,7,7,8,8,10]\n8'
 *
 * 给定一个按照升序排列的整数数组 nums，和一个目标值 target。找出给定目标值在数组中的开始位置和结束位置。
 * 
 * 你的算法时间复杂度必须是 O(log n) 级别。
 * 
 * 如果数组中不存在目标值，返回 [-1, -1]。
 * 
 * 示例 1:
 * 
 * 输入: nums = [5,7,7,8,8,10], target = 8
 * 输出: [3,4]
 * 
 * 示例 2:
 * 
 * 输入: nums = [5,7,7,8,8,10], target = 6
 * 输出: [-1,-1]
 * 
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        if (nums.size() == 0) {
            return { -1, -1 };
        }

        int mid;
        int left_bound;
        int right_bound;

        int left = 0;
        int right = nums.size();
        while (left < right) {
            mid = (left + right) / 2;
            if (nums[mid] == target) {
                right = mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        // 这里一定要判断一下 nums[left] 是不是等于 target 因为在查找的过程中，left 和 right 都是会变的，如果所有数都比 target 大的话，left 一直指向第 0 个元素，也要检查一下第零个元素是不是 target ，找右边界同理
        if (left == nums.size() || nums[left] != target) {
            return { -1, -1 };
        } else {
            left_bound = left;
        }

        left = 0;
        right = nums.size();
        while (left < right) {
            mid = (left + right) / 2;
            if (nums[mid] == target) {
                left = mid + 1;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        right_bound = left - 1;

        return { left_bound, right_bound };
    }
};
// @lc code=end
