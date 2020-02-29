/*
 * @lc app=leetcode.cn id=52 lang=cpp
 *
 * [52] N皇后 II
 *
 * https://leetcode-cn.com/problems/n-queens-ii/description/
 *
 * algorithms
 * Hard (75.04%)
 * Likes:    84
 * Dislikes: 0
 * Total Accepted:    11.8K
 * Total Submissions: 15.4K
 * Testcase Example:  '4'
 *
 * n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 * 
 * 
 * 
 * 上图为 8 皇后问题的一种解法。
 * 
 * 给定一个整数 n，返回 n 皇后不同的解决方案的数量。
 * 
 * 示例:
 * 
 * 输入: 4
 * 输出: 2
 * 解释: 4 皇后问题存在如下两个不同的解法。
 * [
 * [".Q..",  // 解法 1
 * "...Q",
 * "Q...",
 * "..Q."],
 * 
 * ["..Q.",  // 解法 2
 * "Q...",
 * "...Q",
 * ".Q.."]
 * ]
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int totalNQueens(int n)
    {
        vector<string> res(n, string(n, '.'));
        vector<int> row(n, 0);
        vector<int> col(n, 0);
        int result = 0;
        backtracking(result, res, row, col, 0, -1, 0, n);
        return result;
    }

    void backtracking(int& result, vector<string>& res, vector<int>& row, vector<int>& col, int p_row, int p_col, int added, const int& n)
    {
        if (added == n) {
            ++result;
            return;
        }

        if (p_col == n - 1) {
            ++p_row;
            if (p_row == n) {
                return;
            }
            p_col = 0;
        } else {
            ++p_col;
        }

        if (row[p_row] != 1 && col[p_col] != 1) {
            int i, j;
            i = p_row;
            j = p_col;
            while (i != 0 && j != 0) {
                --i;
                --j;
                if (res[i][j] == 'Q') {
                    goto begin;
                }
            }
            i = p_row;
            j = p_col;
            while (i != 0 && j != n - 1) {
                --i;
                ++j;
                if (res[i][j] == 'Q') {
                    goto begin;
                }
            }
            i = p_row;
            j = p_col;
            while (row[i] == 1 && col[j] == 1) {
                ++i;
                --j;
                if (res[i][j] == 'Q') {
                    goto begin;
                }
            }
            i = p_row;
            j = p_col;
            while (i != n - 1 && j != n - 1) {
                ++i;
                ++j;
                if (res[i][j] == 'Q') {
                    goto begin;
                }
            }

            res[p_row][p_col] = 'Q';
            col[p_col] = 1;
            row[p_row] = 1;

            backtracking(result, res, row, col, p_row, p_col, added + 1, n);

            res[p_row][p_col] = '.';
            col[p_col] = 0;
            row[p_row] = 0;
        }
    begin:
        backtracking(result, res, row, col, p_row, p_col, added, n);
    }
};
// @lc code=end
