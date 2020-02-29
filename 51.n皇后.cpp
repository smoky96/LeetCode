/*
 * @lc app=leetcode.cn id=51 lang=cpp
 *
 * [51] N皇后
 *
 * https://leetcode-cn.com/problems/n-queens/description/
 *
 * algorithms
 * Hard (64.93%)
 * Likes:    266
 * Dislikes: 0
 * Total Accepted:    18.8K
 * Total Submissions: 28.1K
 * Testcase Example:  '4'
 *
 * n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 * 
 * 
 * 
 * 上图为 8 皇后问题的一种解法。
 * 
 * 给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。
 * 
 * 每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。
 * 
 * 示例:
 * 
 * 输入: 4
 * 输出: [
 * ⁠[".Q..",  // 解法 1
 * ⁠ "...Q",
 * ⁠ "Q...",
 * ⁠ "..Q."],
 * 
 * ⁠["..Q.",  // 解法 2
 * ⁠ "Q...",
 * ⁠ "...Q",
 * ⁠ ".Q.."]
 * ]
 * 解释: 4 皇后问题存在两个不同的解法。
 * 
 * 
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n)
    {
        vector<bool> col(n, false);
        vector<bool> hill(2 * n - 1, false);
        vector<bool> dale(2 * n - 1, false);

        vector<vector<string>> results;
        vector<string> res(n, string(n, '.'));

        backtracking(results, res, col, hill, dale, 0, n);

        return results;
    }

    void backtracking(vector<vector<string>>& results, vector<string>& res, vector<bool>& col, vector<bool>& hill, vector<bool> dale, int n_row, const int& n)
    {
        if (n_row == n) {
            results.push_back(res);
            return;
        }

        for (int i = 0; i < n; ++i) {
            if (col[i] || dale[i - n_row + n - 1] || hill[i + n_row]) {
                continue;
            }
            res[n_row][i] = 'Q';
            col[i] = true;
            dale[i - n_row + n - 1] = true;
            hill[i + n_row] = true;
            
            backtracking(results, res, col, hill, dale, n_row + 1, n);

            res[n_row][i] = '.';
            col[i] = false;
            dale[i - n_row + n - 1] = false;
            hill[i + n_row] = false;
        }
    }
};
// @lc code=end
