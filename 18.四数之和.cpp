/*
 * @lc app=leetcode.cn id=18 lang=cpp
 *
 * [18] 四数之和
 *
 * https://leetcode-cn.com/problems/4sum/description/
 *
 * algorithms
 * Medium (36.01%)
 * Likes:    314
 * Dislikes: 0
 * Total Accepted:    39.9K
 * Total Submissions: 110.8K
 * Testcase Example:  '[1,0,-1,0,-2,2]\n0'
 *
 * 给定一个包含 n 个整数的数组 nums 和一个目标值 target，判断 nums 中是否存在四个元素 a，b，c 和 d ，使得 a + b + c
 * + d 的值与 target 相等？找出所有满足条件且不重复的四元组。
 * 
 * 注意：
 * 
 * 答案中不可以包含重复的四元组。
 * 
 * 示例：
 * 
 * 给定数组 nums = [1, 0, -1, 0, -2, 2]，和 target = 0。
 * 
 * 满足要求的四元组集合为：
 * [
 * ⁠ [-1,  0, 0, 1],
 * ⁠ [-2, -1, 1, 2],
 * ⁠ [-2,  0, 0, 2]
 * ]
 * 
 * 
 */

// @lc code=start
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        sort(nums.begin(), nums.end());
        int L = 0;
        int R = 0;
        int tmp = 0;
        vector<vector<int>> res;
        if (nums.size() < 4) {
            return res;
        }
        for (int i = 0; i < nums.size() - 3; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < nums.size() - 2; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                L = j + 1;
                R = nums.size() - 1;
                while (L < R) {
                    tmp = nums[i] + nums[j] + nums[L] + nums[R];
                    if (tmp < target) {
                        L += 1;
                        while (L < R && nums[L] == nums[L - 1])
                            L += 1;
                    } else if (tmp > target) {
                        R -= 1;
                        while (L < R && nums[R] == nums[R + 1])
                            R -= 1;
                    } else {
                        res.push_back({ nums[i], nums[j], nums[L], nums[R] });
                        R -= 1;
                        L += 1;
                        while (L < R && nums[R] == nums[R + 1])
                            R -= 1;
                        while (L < R && nums[L] == nums[L - 1])
                            L += 1;
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end
