/*
 * @lc app=leetcode.cn id=77 lang=cpp
 *
 * [77] 组合
 *
 * https://leetcode-cn.com/problems/combinations/description/
 *
 * algorithms
 * Medium (69.85%)
 * Likes:    184
 * Dislikes: 0
 * Total Accepted:    26.8K
 * Total Submissions: 37.5K
 * Testcase Example:  '4\n2'
 *
 * 给定两个整数 n 和 k，返回 1 ... n 中所有可能的 k 个数的组合。
 * 
 * 示例:
 * 
 * 输入: n = 4, k = 2
 * 输出:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 * 
 */

// @lc code=start
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> ans;
        vector<int> tmp;
        aux(n, k, 1, ans, tmp);
        return ans;
    }

    void aux(const int& n, const int& k, int start, vector<vector<int>>& ans, vector<int>& tmp)
    {
        if (tmp.size() == k) {
            ans.push_back(tmp);
            return;
        }

        for (int i = start; i <= n; ++i) {
            tmp.push_back(i);
            aux(n, k, i + 1, ans, tmp);
            tmp.pop_back();
        }
    }
};
// @lc code=end
