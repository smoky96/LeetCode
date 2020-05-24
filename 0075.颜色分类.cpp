/*
 * @lc app=leetcode.cn id=75 lang=cpp
 *
 * [75] 颜色分类
 *
 * https://leetcode-cn.com/problems/sort-colors/description/
 *
 * algorithms
 * Medium (52.73%)
 * Likes:    272
 * Dislikes: 0
 * Total Accepted:    45.8K
 * Total Submissions: 84.9K
 * Testcase Example:  '[2,0,2,1,1,0]'
 *
 * 给定一个包含红色、白色和蓝色，一共 n 个元素的数组，原地对它们进行排序，使得相同颜色的元素相邻，并按照红色、白色、蓝色顺序排列。
 * 
 * 此题中，我们使用整数 0、 1 和 2 分别表示红色、白色和蓝色。
 * 
 * 注意:
 * 不能使用代码库中的排序函数来解决这道题。
 * 
 * 示例:
 * 
 * 输入: [2,0,2,1,1,0]
 * 输出: [0,0,1,1,2,2]
 * 
 * 进阶：
 * 
 * 
 * 一个直观的解决方案是使用计数排序的两趟扫描算法。
 * 首先，迭代计算出0、1 和 2 元素的个数，然后按照0、1、2的排序，重写当前数组。
 * 你能想出一个仅使用常数空间的一趟扫描算法吗？
 * 
 * 
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums)
    {
        // 因为只有三个值，所以只需要知道两个指针就可以定位三个值的位置了。
        // 因为交换的时候只需要将 2 交换到最后面，0 交换到最前面，所以两个指针分别指向 0 的右边界和 2 的左边界就可以了。
        // 左右指针中间的部分就是 1 了。
        // 这样可以很好的设定结束条件。
        int r = 0, b = nums.size() - 1, cur = 0;
        while (cur <= b) {
            if (nums[cur] == 2) {
                swap(nums[cur], nums[b]);
                --b;
            } else if (nums[cur] == 0) {
                swap(nums[cur], nums[r]);
                ++r;
                ++cur;
            } else {
                ++cur;
            }
        }
    }
};

// @lc code=end
