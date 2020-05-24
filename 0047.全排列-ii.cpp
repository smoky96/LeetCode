/*
 * @lc app=leetcode.cn id=47 lang=cpp
 *
 * [47] 全排列 II
 *
 * https://leetcode-cn.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (53.73%)
 * Likes:    181
 * Dislikes: 0
 * Total Accepted:    28.7K
 * Total Submissions: 51.8K
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个可包含重复数字的序列，返回所有不重复的全排列。
 * 
 * 示例:
 * 
 * 输入: [1,1,2]
 * 输出:
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
 * ]
 * 
 */

// @lc code=start
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums)
    {
        vector<vector<int>> results;
        vector<int> res;
        vector<bool> used(nums.size(), false);
        int n_used;
        sort(nums.begin(), nums.end());
        aux(nums, res, results, used, n_used);
        return results;
    }

    void aux(vector<int>& nums, vector<int> res, vector<vector<int>>& results, vector<bool>& used, int n_used)
    {
        if (n_used == nums.size()) {
            results.push_back(res);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) {
                continue;
            }
            used[i] = true;
            res.push_back(nums[i]);
            aux(nums, res, results, used, n_used + 1);
            used[i] = false;
            res.pop_back();
            while (i < nums.size() - 1 && nums[i + 1] == nums[i]) {
                ++i;
            }
        }
    }
};
// @lc code=end
