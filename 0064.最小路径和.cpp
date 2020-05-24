/*
 * @lc app=leetcode.cn id=64 lang=cpp
 *
 * [64] 最小路径和
 *
 * https://leetcode-cn.com/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (62.28%)
 * Likes:    332
 * Dislikes: 0
 * Total Accepted:    44.8K
 * Total Submissions: 70.8K
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * 给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。
 * 
 * 说明：每次只能向下或者向右移动一步。
 * 
 * 示例:
 * 
 * 输入:
 * [
 * [1,3,1],
 * ⁠ [1,5,1],
 * ⁠ [4,2,1]
 * ]
 * 输出: 7
 * 解释: 因为路径 1→3→1→1→1 的总和最小。
 * 
 * 
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid)
    {
        vector<vector<int>> memo(grid.size(), vector<int>(grid[0].size(), -1));
        return aux(0, 0, memo, grid);
    }

    int aux(int x, int y, vector<vector<int>>& memo, vector<vector<int>>& grid)
    {
        if (x == grid.size() - 1 && y == grid[0].size() - 1) {
            memo[x][y] = grid[grid.size() - 1][grid[0].size() - 1];
            return memo[x][y];
        }

        if (memo[x][y] != -1) {
            return memo[x][y];
        }

        int tmp1 = -1;
        int tmp2 = -1;
        if (x < grid.size() - 1) {
            tmp1 = aux(x + 1, y, memo, grid);
        }
        if (y < grid[0].size() - 1) {
            tmp2 = aux(x, y + 1, memo, grid);
        }
        memo[x][y] = grid[x][y] + (tmp1 > tmp2 ? (tmp2 == -1 ? tmp1 : tmp2) : (tmp1 == -1 ? tmp2 : tmp1));
        return memo[x][y];
    }
};
// @lc code=end
