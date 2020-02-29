/*
 * @lc app=leetcode.cn id=88 lang=cpp
 *
 * [88] 合并两个有序数组
 *
 * https://leetcode-cn.com/problems/merge-sorted-array/description/
 *
 * algorithms
 * Easy (45.06%)
 * Likes:    358
 * Dislikes: 0
 * Total Accepted:    90.1K
 * Total Submissions: 196.2K
 * Testcase Example:  '[1,2,3,0,0,0]\n3\n[2,5,6]\n3'
 *
 * 给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。
 * 
 * 说明:
 * 
 * 
 * 初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
 * 你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
 * 
 * 
 * 示例:
 * 
 * 输入:
 * nums1 = [1,2,3,0,0,0], m = 3
 * nums2 = [2,5,6],       n = 3
 * 
 * 输出: [1,2,2,3,5,6]
 * 
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n)
    {
        int i = 0;
        int j = 0;
        while (i != m && j != n) {
            if (nums1[i] > nums2[j]) {
                i = insert(nums1, i, nums2[j], m);
                ++j;
            } else {
                ++i;
            }
        }
        while (j != n) {
            nums1[i++] = nums2[j++];
        }
    }
    int insert(vector<int>& nums, int pos, const int& data, int& len)
    {
        int n = len;
        while (n-- != pos) {
            nums[n + 1] = nums[n];
        }
        nums[pos] = data;
        ++len;
        return ++pos;
    }
};
// @lc code=end
