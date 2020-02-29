/*
 * @lc app=leetcode.cn id=90 lang=cpp
 *
 * [90] 子集 II
 *
 * https://leetcode-cn.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (56.56%)
 * Likes:    144
 * Dislikes: 0
 * Total Accepted:    17.7K
 * Total Submissions: 30.5K
 * Testcase Example:  '[1,2,2]'
 *
 * 给定一个可能包含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
 * 
 * 说明：解集不能包含重复的子集。
 * 
 * 示例:
 * 
 * 输入: [1,2,2]
 * 输出:
 * [
 * ⁠ [2],
 * ⁠ [1],
 * ⁠ [1,2,2],
 * ⁠ [2,2],
 * ⁠ [1,2],
 * ⁠ []
 * ]
 * 
 */

// @lc code=start
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());

        vector<int> tmp;
        vector<vector<int>> ans;
        for (int i = 0; i <= nums.size(); ++i) {
            aux(ans, tmp, i, nums, 0);
        }
        return ans;
    }

    void aux(vector<vector<int>>& ans, vector<int>& tmp, const int& n, const vector<int>& nums, int start)
    {
        if (tmp.size() == n) {
            ans.push_back(tmp);
            return;
        }
        for (int i = start; i < nums.size(); ++i) {
            if (i == start || nums[i - 1] != nums[i]) {
                tmp.push_back(nums[i]);
                aux(ans, tmp, n, nums, i + 1);
                tmp.pop_back();
            }
        }
    }
};
// @lc code=end
