/*
 * @lc app=leetcode.cn id=120 lang=cpp
 *
 * [120] 三角形最小路径和
 *
 * https://leetcode-cn.com/problems/triangle/description/
 *
 * algorithms
 * Medium (61.28%)
 * Likes:    275
 * Dislikes: 0
 * Total Accepted:    33.3K
 * Total Submissions: 52.8K
 * Testcase Example:  '[[2],[3,4],[6,5,7],[4,1,8,3]]'
 *
 * 给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。
 * 
 * 例如，给定三角形：
 * 
 * [
 * ⁠    [2],
 * ⁠   [3,4],
 * ⁠  [6,5,7],
 * ⁠ [4,1,8,3]
 * ]
 * 
 * 
 * 自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。
 * 
 * 说明：
 * 
 * 如果你可以只使用 O(n) 的额外空间（n 为三角形的总行数）来解决这个问题，那么你的算法会很加分。
 * 
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle)
    {
        vector<vector<int>> mem(triangle.size() + 1, vector<int>(triangle[triangle.size() - 1].size() + 1));
        return aux(triangle, 0, 0, mem);
    }

    int aux(const vector<vector<int>>& triangle, int row, int col, vector<vector<int>>& mem)
    {
        if (row == triangle.size()) {
            return 0;
        }
        if (mem[col][row] != 0) {
            return mem[row][col];
        }

        int tmp1 = triangle[row][col] + aux(triangle, row + 1, col, mem);
        if (col < triangle[row].size() - 1) {
            int tmp2 = triangle[row][col + 1] + aux(triangle, row + 1, col + 1, mem);
            tmp1 = tmp1 < tmp2 ? tmp1 : tmp2;
        }
        mem[col][row] = 1;
        mem[row][col] = tmp1;
        return tmp1;
    }
};
// @lc code=end
