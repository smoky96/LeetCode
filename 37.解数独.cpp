/*
 * @lc app=leetcode.cn id=37 lang=cpp
 *
 * [37] 解数独
 *
 * https://leetcode-cn.com/problems/sudoku-solver/description/
 *
 * algorithms
 * Hard (55.87%)
 * Likes:    265
 * Dislikes: 0
 * Total Accepted:    13.7K
 * Total Submissions: 23.8K
 * Testcase Example:  '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * 编写一个程序，通过已填充的空格来解决数独问题。
 * 
 * 一个数独的解法需遵循如下规则：
 * 
 * 
 * 数字 1-9 在每一行只能出现一次。
 * 数字 1-9 在每一列只能出现一次。
 * 数字 1-9 在每一个以粗实线分隔的 3x3 宫内只能出现一次。
 * 
 * 
 * 空白格用 '.' 表示。
 * 
 * 
 * 
 * 一个数独。
 * 
 * 
 * 
 * 答案被标成红色。
 * 
 * Note:
 * 
 * 
 * 给定的数独序列只包含数字 1-9 和字符 '.' 。
 * 你可以假设给定的数独只有唯一解。
 * 给定数独永远是 9x9 形式的。
 * 
 * 
 */

// @lc code=start
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    void backtrace(vector<int>* row, vector<int>* col, vector<int>* mat, bool& is_done,
        vector<vector<char>>& board, int n_row, int n_col)
    {
        if (is_done)
            return;
        if (n_row == 9) {
            is_done = true;
            return;
        }

        int next_row = n_col == 8 ? (n_row + 1) : n_row;
        int next_col = n_col == 8 ? 0 : n_col + 1;

        if (board[n_row][n_col] != '.') {
            backtrace(row, col, mat, is_done, board, next_row, next_col);
            return;
        }

        for (int i = 1; i < 10; i++) {
            if (row[n_row][i - 1] != 1 && col[n_col][i - 1] != 1 && mat[(n_col / 3) + (n_row / 3) * 3][i - 1] != 1) {
                board[n_row][n_col] = '0' + i;
                row[n_row][i - 1] = 1;
                col[n_col][i - 1] = 1;
                mat[(n_col / 3) + (n_row / 3) * 3][i - 1] = 1;

                backtrace(row, col, mat, is_done, board, next_row, next_col);
                if (is_done) {
                    return;
                }
                board[n_row][n_col] = '.';
                row[n_row][i - 1] = 0;
                col[n_col][i - 1] = 0;
                mat[(n_col / 3) + (n_row / 3) * 3][i - 1] = 0;
            }
        }
    }

    void solveSudoku(vector<vector<char>>& board)
    {
        // 用 vector 而不是 map 来加快速度
        vector<int> row[9] = {
            vector<int>(9, 0),
            vector<int>(9, 0),
            vector<int>(9, 0),
            vector<int>(9, 0),
            vector<int>(9, 0),
            vector<int>(9, 0),
            vector<int>(9, 0),
            vector<int>(9, 0),
            vector<int>(9, 0),
        };
        vector<int> col[9] = {
            vector<int>(9, 0),
            vector<int>(9, 0),
            vector<int>(9, 0),
            vector<int>(9, 0),
            vector<int>(9, 0),
            vector<int>(9, 0),
            vector<int>(9, 0),
            vector<int>(9, 0),
            vector<int>(9, 0),
        };
        vector<int> mat[9] = {
            vector<int>(9, 0),
            vector<int>(9, 0),
            vector<int>(9, 0),
            vector<int>(9, 0),
            vector<int>(9, 0),
            vector<int>(9, 0),
            vector<int>(9, 0),
            vector<int>(9, 0),
            vector<int>(9, 0),
        };

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    row[i][board[i][j] - '0' - 1] = 1;
                    col[j][board[i][j] - '0' - 1] = 1;
                    mat[(j / 3) + (i / 3) * 3][board[i][j] - '0' - 1] = 1;
                }
            }
        }
        bool is_done = false;
        backtrace(row, col, mat, is_done, board, 0, 0);
    }
};
// @lc code=end
