/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 *
 * https://leetcode-cn.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (36.93%)
 * Likes:    243
 * Dislikes: 0
 * Total Accepted:    31.4K
 * Total Submissions: 83.4K
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * 给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。
 * 
 * 示例 1:
 * 
 * 输入:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * 输出: [1,2,3,6,9,8,7,4,5]
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * [
 * ⁠ [1, 2, 3, 4],
 * ⁠ [5, 6, 7, 8],
 * ⁠ [9,10,11,12]
 * ]
 * 输出: [1,2,3,4,8,12,11,10,9,5,6,7]
 * 
 * 
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix)
    {
        if (matrix.size() == 0) {
            return {};
        }
        int up, down, right, left;
        up = 0;
        down = matrix.size() - 1;
        right = matrix[0].size() - 1;
        left = 0;

        int direction = 0;
        int size = (down + 1) * (right + 1);

        vector<int> res;

        int n = 0;
        int i = 0, j = -1;
        while (n < size) {
            direction = direction % 4;
            if (direction == 0) {
                ++j;
                if (j == right) {
                    ++direction;
                    ++up;
                }
            } else if (direction == 1) {
                ++i;
                if (i == down) {
                    ++direction;
                    --right;
                }
            } else if (direction == 2) {
                --j;
                if (j == left) {
                    ++direction;
                    --down;
                }
            } else if (direction == 3) {
                --i;
                if (i == up) {
                    ++direction;
                    ++left;
                }
            }
            res.push_back(matrix[i][j]);
            ++n;
        }
        return res;
    }
};
/* 1  2  3  4
   5  6  7  8
   9  10 11 12 
   13 14 15 16 */
// @lc code=end
