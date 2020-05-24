/*
 * @lc app=leetcode.cn id=16 lang=cpp
 *
 * [16] 最接近的三数之和
 *
 * https://leetcode-cn.com/problems/3sum-closest/description/
 *
 * algorithms
 * Medium (41.49%)
 * Likes:    288
 * Dislikes: 0
 * Total Accepted:    54.1K
 * Total Submissions: 128.9K
 * Testcase Example:  '[-1,2,1,-4]\n1'
 *
 * 给定一个包括 n 个整数的数组 nums 和 一个目标值 target。找出 nums 中的三个整数，使得它们的和与 target
 * 最接近。返回这三个数的和。假定每组输入只存在唯一答案。
 * 
 * 例如，给定数组 nums = [-1，2，1，-4], 和 target = 1.
 * 
 * 与 target 最接近的三个数的和为 2. (-1 + 2 + 1 = 2).
 * 
 * 
 */

// @lc code=start
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        sort(nums.begin(), nums.end());
        int L = 0;
        int R = 0;
        int ans = 0;
        int closest = nums[0] + nums[1] + nums[nums.size() - 1];

        for (int i = 0; i < nums.size(); i++) {
            L = i + 1;
            R = nums.size() - 1;
            while (L < R) {
                ans = nums[i] + nums[L] + nums[R];
                if (abs(closest - target) > abs(ans - target)) {
                    closest = nums[i] + nums[L] + nums[R];
                }
                if (ans < target) {
                    L += 1;
                } else if (ans > target) {
                    R -= 1;
                } else if (ans == target) {
                    return ans;
                }
            }
        }
        return closest;
    }
};
// @lc code=end
