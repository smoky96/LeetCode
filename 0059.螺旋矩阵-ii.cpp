/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 *
 * https://leetcode-cn.com/problems/spiral-matrix-ii/description/
 *
 * algorithms
 * Medium (74.29%)
 * Likes:    127
 * Dislikes: 0
 * Total Accepted:    20.1K
 * Total Submissions: 26.6K
 * Testcase Example:  '3'
 *
 * 给定一个正整数 n，生成一个包含 1 到 n^2 所有元素，且元素按顺时针顺序螺旋排列的正方形矩阵。
 * 
 * 示例:
 * 
 * 输入: 3
 * 输出:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 8, 9, 4 ],
 * ⁠[ 7, 6, 5 ]
 * ]
 * 
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n)
    {
        if (n == 0) {
            return { {} };
        }
        if (n == 1) {
            return { { 1 } };
        }
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int top = 0;
        int bottom = n - 1;
        int left = 0;
        int right = n - 1;

        int direction = 0;

        int count = 1;
        int i = 0, j = 0;
        while (count <= (n * n)) {
            ans[i][j] = count++;
            if (direction % 4 == 0) {
                if (j == right) {
                    ++top;
                    ++i;
                    ++direction;
                } else {
                    ++j;
                }
            } else if (direction % 4 == 1) {
                if (i == bottom) {
                    --right;
                    --j;
                    ++direction;
                } else {
                    ++i;
                }
            } else if (direction % 4 == 2) {
                if (j == left) {
                    --bottom;
                    --i;
                    ++direction;
                } else {
                    --j;
                }
            } else {
                if (i == top) {
                    ++left;
                    ++j;
                    ++direction;
                } else {
                    --i;
                }
            }
        }
        return ans;
    }
};
// @lc code=end
