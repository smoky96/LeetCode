/*
 * @lc app=leetcode.cn id=31 lang=cpp
 *
 * [31] 下一个排列
 *
 * https://leetcode-cn.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (31.68%)
 * Likes:    319
 * Dislikes: 0
 * Total Accepted:    30.8K
 * Total Submissions: 95.5K
 * Testcase Example:  '[1,2,3]'
 *
 * 实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
 * 
 * 如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
 * 
 * 必须原地修改，只允许使用额外常数空间。
 * 
 * 以下是一些例子，输入位于左侧列，其相应输出位于右侧列。
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 * 
 */

// @lc code=start
#include <vector>
using namespace std;

/* 
1 2 3 4 5 6 7 8
1 2 3 4 5 6 8 7
1 2 3 4 5 7 6 8
1 2 3 4 5 7 8 6
1 2 3 4 6 5 7 8
1 2 3 4 6 5 8 7
1 2 3 4 6 7 5 8
1 2 3 4 6 7 8 5
1 2 3 4 6 8 5 7
1 2 3 4 6 8 7 5
 */

class Solution {
public:
    void nextPermutation(vector<int>& nums)
    {
        if (nums.size() < 2) {
            return;
        }
        decltype(nums.begin()) it;
        decltype(nums.begin()) it_swp;
        decltype(nums.begin()) i;
        decltype(nums.begin()) j;
        int left = nums.size() - 1;
        int right = nums.size() - 1;
        int mid;
        for (it = nums.end() - 1; it > nums.begin(); --it, --left) {
            if (*it > *(it - 1)) {
                it_swp = it - 1;

                // 这样貌似比二分查找还快一些，而且内存还少一点
                /* while ((it + 1) < nums.end() && *(it + 1) > *it_swp) {
                    ++it;
                }
                swap(*it, *it_swp); */

                while (left <= right) {
                    mid = (left + right) / 2;
                    if (nums[mid] <= *it_swp) {
                        right = mid - 1;
                    } else {
                        left = mid + 1;
                    }
                }
                swap(nums[right], *it_swp);

                for (i = it_swp + 1, j = (nums.end() - 1); i < j; ++i, --j) {
                    swap(*i, *j);
                }
                break;
            }
        }
        if (it == nums.begin()) {
            for (i = nums.begin(), j = (nums.end() - 1); i < j; ++i, --j) {
                swap(*i, *j);
            }
        }
    }

    void swap(int& a, int& b)
    {
        int tmp = a;
        a = b;
        b = tmp;
    }
};
// @lc code=end
