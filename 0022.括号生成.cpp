/*
 * @lc app=leetcode.cn id=22 lang=cpp
 *
 * [22] 括号生成
 *
 * https://leetcode-cn.com/problems/generate-parentheses/description/
 *
 * algorithms
 * Medium (71.54%)
 * Likes:    609
 * Dislikes: 0
 * Total Accepted:    53.2K
 * Total Submissions: 73.4K
 * Testcase Example:  '3'
 *
 * 给出 n 代表生成括号的对数，请你写出一个函数，使其能够生成所有可能的并且有效的括号组合。
 * 
 * 例如，给出 n = 3，生成结果为：
 * 
 * [
 * ⁠ "((()))",
 * ⁠ "(()())",
 * ⁠ "(())()",
 * ⁠ "()(())",
 * ⁠ "()()()"
 * ]
 * 
 * 
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n)
    {
        vector<string> ret;
        insertParenthesis(ret, "", n, n);
        return ret;
    }

    void insertParenthesis(vector<string>& p, string s, int L, int R)
    {
        vector<string> ret;
        if (L == 0 && R == 0) {
            p.push_back(s);
            return;
        }
        if (L > 0) {
            insertParenthesis(p, s + '(', L - 1, R);
            if (R > L) {
                insertParenthesis(p, s + ')', L, R - 1);
            }
        } else {
            insertParenthesis(p, s + ')', L, R - 1);
        }
    }
};
// @lc code=end
