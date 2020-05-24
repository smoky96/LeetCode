/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 *
 * https://leetcode-cn.com/problems/combination-sum-ii/description/
 *
 * algorithms
 * Medium (56.32%)
 * Likes:    168
 * Dislikes: 0
 * Total Accepted:    29K
 * Total Submissions: 49.8K
 * Testcase Example:  '[10,1,2,7,6,1,5]\n8'
 *
 * 给定一个数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 * 
 * candidates 中的每个数字在每个组合中只能使用一次。
 * 
 * 说明：
 * 
 * 
 * 所有数字（包括目标数）都是正整数。
 * 解集不能包含重复的组合。 
 * 
 * 
 * 示例 1:
 * 
 * 输入: candidates = [10,1,2,7,6,1,5], target = 8,
 * 所求解集为:
 * [
 * ⁠ [1, 7],
 * ⁠ [1, 2, 5],
 * ⁠ [2, 6],
 * ⁠ [1, 1, 6]
 * ]
 * 
 * 
 * 示例 2:
 * 
 * 输入: candidates = [2,5,2,1,2], target = 5,
 * 所求解集为:
 * [
 * [1,2,2],
 * [5]
 * ]
 * 
 */

// @lc code=start
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res_t;
        vector<int> res;
        int sum = 0;
        backtrack(candidates, target, res_t, res, sum, 0);
        return res_t;
    }

    void backtrack(const vector<int>& candidates, const int& target, vector<vector<int>>& res_t, vector<int>& res, int sum, int start)
    {
        if (sum == target) {
            res_t.push_back(res);
            return;
        }

        if (sum > target)
            return;

        int last_pop = -1;
        for (int i = 0 + start; i < candidates.size(); ++i) {
            if (last_pop == candidates[i]) {
                continue;
            }
            if ((sum + candidates[i]) > target)
                return;
            res.push_back(candidates[i]);
            backtrack(candidates, target, res_t, res, sum + candidates[i], i + 1);
            last_pop = res[res.size() - 1];
            res.pop_back();
        }
    }
};
// @lc code=end
