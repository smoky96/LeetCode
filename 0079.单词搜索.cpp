/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 *
 * https://leetcode-cn.com/problems/word-search/description/
 *
 * algorithms
 * Medium (38.68%)
 * Likes:    254
 * Dislikes: 0
 * Total Accepted:    28.1K
 * Total Submissions: 71.2K
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * 给定一个二维网格和一个单词，找出该单词是否存在于网格中。
 * 
 * 单词必须按照字母顺序，通过相邻的单元格内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母不允许被重复使用。
 * 
 * 示例:
 * 
 * board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 * 
 * 给定 word = "ABCCED", 返回 true.
 * 给定 word = "SEE", 返回 true.
 * 给定 word = "ABCB", 返回 false.
 * 
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word)
    {
        bool ans = false;
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (word[0] == board[i][j]) {
                    visited[i][j] = true;
                    ans = aux(board, word, visited, 1, i, j);
                    visited[i][j] = false;
                    if (ans) {
                        return ans;
                    }
                }
            }
        }
        return ans;
    }

    bool aux(const vector<vector<char>>& board, const string& word, vector<vector<bool>>& visited, int count, int x, int y)
    {
        if (count == word.size()) {
            return true;
        }

        bool up = false, down = false, right = false, left = false;
        if (x > 0 && !visited[x - 1][y] && board[x - 1][y] == word[count]) {
            visited[x - 1][y] = true;
            up = aux(board, word, visited, count + 1, x - 1, y);
            visited[x - 1][y] = false;
            if (up) {
                return true;
            }
        }
        if (x < (board.size() - 1) && !visited[x + 1][y] && board[x + 1][y] == word[count]) {
            visited[x + 1][y] = true;
            down = aux(board, word, visited, count + 1, x + 1, y);
            visited[x + 1][y] = false;
            if (down) {
                return true;
            }
        }
        if (y < (board[0].size() - 1) && !visited[x][y + 1] && board[x][y + 1] == word[count]) {
            visited[x][y + 1] = true;
            right = aux(board, word, visited, count + 1, x, y + 1);
            visited[x][y + 1] = false;
            if (right) {
                return true;
            }
        }
        if (y > 0 && !visited[x][y - 1] && board[x][y - 1] == word[count]) {
            visited[x][y - 1] = true;
            left = aux(board, word, visited, count + 1, x, y - 1);
            visited[x][y - 1] = false;
            if (left) {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end
