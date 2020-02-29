/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 *
 * https://leetcode-cn.com/problems/jump-game-ii/description/
 *
 * algorithms
 * Hard (31.23%)
 * Likes:    289
 * Dislikes: 0
 * Total Accepted:    22.2K
 * Total Submissions: 69.5K
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * 给定一个非负整数数组，你最初位于数组的第一个位置。
 * 
 * 数组中的每个元素代表你在该位置可以跳跃的最大长度。
 * 
 * 你的目标是使用最少的跳跃次数到达数组的最后一个位置。
 * 
 * 示例:
 * 
 * 输入: [2,3,1,1,4]
 * 输出: 2
 * 解释: 跳到最后一个位置的最小跳跃数是 2。
 * 从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
 * 
 * 
 * 说明:
 * 
 * 假设你总是可以到达数组的最后一个位置。
 * 
 */

// @lc code=start
#include <algorithm>
#include <climits>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums)
    {
        int bound = 0;
        int max_pos = 0;
        int step = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            max_pos = max_pos > (nums[i] + i) ? max_pos : (nums[i] + i);
            if (i == bound) {
                bound = max_pos;
                ++step;
                if (max_pos >= nums.size()) {
                    return step;
                }
            }
        }
        return step;
    }
};
// @lc code=end
