/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 *
 * https://leetcode-cn.com/problems/subsets/description/
 *
 * algorithms
 * Medium (74.66%)
 * Likes:    401
 * Dislikes: 0
 * Total Accepted:    48.5K
 * Total Submissions: 64.1K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一组不含重复元素的整数数组 nums，返回该数组所有可能的子集（幂集）。
 * 
 * 说明：解集不能包含重复的子集。
 * 
 * 示例:
 * 
 * 输入: nums = [1,2,3]
 * 输出:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        vector<int> tmp;
        vector<vector<int>> ans;
        for (int i = 0; i <= nums.size(); ++i) {
            aux(nums, i, 0, tmp, ans);
        }
        return ans;
    }

    void aux(const vector<int>& nums, const int& n, int start, vector<int>& tmp, vector<vector<int>>& ans)
    {
        if (tmp.size() == n) {
            ans.push_back(tmp);
            return;
        }

        for (int i = start; i < nums.size(); ++i) {
            tmp.push_back(nums[i]);
            aux(nums, n, i + 1, tmp, ans);
            tmp.pop_back();
        }
    }
};
// @lc code=end
