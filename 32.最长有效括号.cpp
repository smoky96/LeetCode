/*
 * @lc app=leetcode.cn id=32 lang=cpp
 *
 * [32] 最长有效括号
 *
 * https://leetcode-cn.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (28.04%)
 * Likes:    386
 * Dislikes: 0
 * Total Accepted:    27.8K
 * Total Submissions: 96.8K
 * Testcase Example:  '"(()"'
 *
 * 给定一个只包含 '(' 和 ')' 的字符串，找出最长的包含有效括号的子串的长度。
 * 
 * 示例 1:
 * 
 * 输入: "(()"
 * 输出: 2
 * 解释: 最长有效括号子串为 "()"
 * 
 * 
 * 示例 2:
 * 
 * 输入: ")()())"
 * 输出: 4
 * 解释: 最长有效括号子串为 "()()"
 * 
 * 
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s)
    {
        vector<int> dp(s.size(), 0);
        int i = 1;
        int max_len = 0;
        while (i < s.size()) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    if (i >= 2) {
                        dp[i] = dp[i - 2] + 2;
                    } else {
                        dp[i] = 2;
                    }
                } else {
                    if (i - dp[i - 1] - 1 >= 0 && s[i - dp[i - 1] - 1] == '(') {
                        if (i - dp[i - 1] - 2 > 0) {
                            dp[i] = dp[i - 1] + dp[i - dp[i - 1] - 2] + 2;
                        } else {
                            dp[i] = dp[i - 1] + 2;
                        }
                    }
                }
            }

            if (dp[i] > max_len) {
                max_len = dp[i];
            }
            ++i;
        }
        return max_len;
    }
};
// @lc code=end