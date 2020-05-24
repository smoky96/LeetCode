/*
 * @lc app=leetcode.cn id=33 lang=cpp
 *
 * [33] 搜索旋转排序数组
 *
 * https://leetcode-cn.com/problems/search-in-rotated-sorted-array/description/
 *
 * algorithms
 * Medium (36.09%)
 * Likes:    409
 * Dislikes: 0
 * Total Accepted:    54.5K
 * Total Submissions: 150.7K
 * Testcase Example:  '[4,5,6,7,0,1,2]\n0'
 *
 * 假设按照升序排序的数组在预先未知的某个点上进行了旋转。
 * 
 * ( 例如，数组 [0,1,2,4,5,6,7] 可能变为 [4,5,6,7,0,1,2] )。
 * 
 * 搜索一个给定的目标值，如果数组中存在这个目标值，则返回它的索引，否则返回 -1 。
 * 
 * 你可以假设数组中不存在重复的元素。
 * 
 * 你的算法时间复杂度必须是 O(log n) 级别。
 * 
 * 示例 1:
 * 
 * 输入: nums = [4,5,6,7,0,1,2], target = 0
 * 输出: 4
 * 
 * 
 * 示例 2:
 * 
 * 输入: nums = [4,5,6,7,0,1,2], target = 3
 * 输出: -1
 * 
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        if (nums.size() == 0) {
            return -1;
        }
        if (nums.size() == 1) {
            if (nums[0] == target)
                return 0;
            else
                return -1;
        }

        /* for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == target) {
                return i;
            }
        }
        return -1; */

        int left = 1;
        int right = nums.size() - 1;
        int mid;
        if (nums[0] == target) {
            return 0;
        }
        while (left <= right && nums[left] > nums[0]) {
            if (nums[left] == target) {
                return left;
            }
            ++left;
        }
        if (left == right + 1) {
            return -1;
        }

        while (left <= right) {
            mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
};
// @lc code=end
