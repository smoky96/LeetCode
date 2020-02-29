/*
 * @lc app=leetcode.cn id=46 lang=cpp
 *
 * [46] 全排列
 *
 * https://leetcode-cn.com/problems/permutations/description/
 *
 * algorithms
 * Medium (71.25%)
 * Likes:    448
 * Dislikes: 0
 * Total Accepted:    58.9K
 * Total Submissions: 81K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个没有重复数字的序列，返回其所有可能的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,2,3]
 * 输出:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums)
    {
        vector<vector<int>> results;
        vector<int> res;
        vector<bool> is_pop(nums.size(), false);
        int pop_num = 0;
        backtracking(nums, res, results, is_pop, pop_num);
        return results;
    }

    void backtracking(vector<int> nums, vector<int> res, vector<vector<int>>& results, vector<bool> is_pop, int pop_num)
    {
        if (pop_num == nums.size()) {
            results.push_back(res);
            return;
        }

        bool skip;
        for (int i = 0; i < nums.size(); ++i) {
            if (is_pop[i]) {
                continue;
            }
            is_pop[i] = true;
            res.push_back(nums[i]);
            backtracking(nums, res, results, is_pop, pop_num + 1);
            is_pop[i] = false;
            res.pop_back();
        }
    }
};
// @lc code=end
