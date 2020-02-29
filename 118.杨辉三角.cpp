/*
 * @lc app=leetcode.cn id=118 lang=cpp
 *
 * [118] 杨辉三角
 *
 * https://leetcode-cn.com/problems/pascals-triangle/description/
 *
 * algorithms
 * Easy (63.68%)
 * Likes:    217
 * Dislikes: 0
 * Total Accepted:    51.5K
 * Total Submissions: 79.2K
 * Testcase Example:  '5'
 *
 * 给定一个非负整数 numRows，生成杨辉三角的前 numRows 行。
 * 
 * 
 * 
 * 在杨辉三角中，每个数是它左上方和右上方的数的和。
 * 
 * 示例:
 * 
 * 输入: 5
 * 输出:
 * [
 * ⁠    [1],
 * ⁠   [1,1],
 * ⁠  [1,2,1],
 * ⁠ [1,3,3,1],
 * ⁠[1,4,6,4,1]
 * ]
 * 
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows)
    {
        vector<vector<int>> ans;
        for (int i = 0; i < numRows; ++i) {
            ans.push_back({ 1 });
            for (int j = 0; j < i - 1; ++j) {
                ans[i].push_back(ans[i - 1][j] + ans[i - 1][j + 1]);
            }
            if (i > 0) {
                ans[i].push_back(1);
            }
        }
        return ans;
    }
};
// @lc code=end
