/*
 * @lc app=leetcode.cn id=73 lang=cpp
 *
 * [73] 矩阵置零
 *
 * https://leetcode-cn.com/problems/set-matrix-zeroes/description/
 *
 * algorithms
 * Medium (53.90%)
 * Likes:    152
 * Dislikes: 0
 * Total Accepted:    23.7K
 * Total Submissions: 43.4K
 * Testcase Example:  '[[1,1,1],[1,0,1],[1,1,1]]'
 *
 * 给定一个 m x n 的矩阵，如果一个元素为 0，则将其所在行和列的所有元素都设为 0。请使用原地算法。
 * 
 * 示例 1:
 * 
 * 输入: 
 * [
 * [1,1,1],
 * [1,0,1],
 * [1,1,1]
 * ]
 * 输出: 
 * [
 * [1,0,1],
 * [0,0,0],
 * [1,0,1]
 * ]
 * 
 * 
 * 示例 2:
 * 
 * 输入: 
 * [
 * [0,1,2,0],
 * [3,4,5,2],
 * [1,3,1,5]
 * ]
 * 输出: 
 * [
 * [0,0,0,0],
 * [0,4,5,0],
 * [0,3,1,0]
 * ]
 * 
 * 进阶:
 * 
 * 
 * 一个直接的解决方案是使用  O(mn) 的额外空间，但这并不是一个好的解决方案。
 * 一个简单的改进方案是使用 O(m + n) 的额外空间，但这仍然不是最好的解决方案。
 * 你能想出一个常数空间的解决方案吗？
 * 
 * 
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix)
    {
        int i, j;
        bool col = false;
        for (i = 0; i < matrix.size(); ++i) {
            if (matrix[i][0] == 0) {
                col = true;
            }
            for (j = 1; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == 0) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }

        for (i = 1; i < matrix.size(); ++i) {
            if (matrix[i][0] == 0) {
                for (j = 1; j < matrix[0].size(); ++j) {
                    matrix[i][j] = 0;
                }
            }
        }
        for (j = 1; j < matrix[0].size(); ++j) {
            if (matrix[0][j] == 0) {
                for (i = 1; i < matrix.size(); ++i) {
                    matrix[i][j] = 0;
                }
            }
        }

        if (matrix[0][0] == 0) {
            for (j = 0; j < matrix[0].size(); ++j) {
                matrix[0][j] = 0;
            }
        }
        if (col) {
            for (i = 0; i < matrix.size(); ++i) {
                matrix[i][0] = 0;
            }
        }
    }
};
// @lc code=end
