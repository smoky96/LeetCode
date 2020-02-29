/*
 * @lc app=leetcode.cn id=39 lang=cpp
 *
 * [39] 组合总和
 *
 * https://leetcode-cn.com/problems/combination-sum/description/
 *
 * algorithms
 * Medium (66.50%)
 * Likes:    443
 * Dislikes: 0
 * Total Accepted:    46K
 * Total Submissions: 68.3K
 * Testcase Example:  '[2,3,6,7]\n7'
 *
 * 给定一个无重复元素的数组 candidates 和一个目标数 target ，找出 candidates 中所有可以使数字和为 target 的组合。
 * 
 * candidates 中的数字可以无限制重复被选取。
 * 
 * 说明：
 * 
 * 
 * 所有数字（包括 target）都是正整数。
 * 解集不能包含重复的组合。 
 * 
 * 
 * 示例 1:
 * 
 * 输入: candidates = [2,3,6,7], target = 7,
 * 所求解集为:
 * [
 * ⁠ [7],
 * ⁠ [2,2,3]
 * ]
 * 
 * 
 * 示例 2:
 * 
 * 输入: candidates = [2,3,5], target = 8,
 * 所求解集为:
 * [
 * [2,2,2,2],
 * [2,3,3],
 * [3,5]
 * ]
 * 
 */

// @lc code=start
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target)
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
        if (sum > target) {
            return;
        }

        for (int i = 0 + start; i < candidates.size(); ++i) {
            res.push_back(candidates[i]);
            backtrack(candidates, target, res_t, res, sum + candidates[i], i);
            res.pop_back();
        }
    }
};
// @lc code=end
