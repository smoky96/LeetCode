/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 *
 * https://leetcode-cn.com/problems/valid-parentheses/description/
 *
 * algorithms
 * Easy (39.32%)
 * Likes:    1176
 * Dislikes: 0
 * Total Accepted:    153.5K
 * Total Submissions: 383.3K
 * Testcase Example:  '"()"'
 *
 * 给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串，判断字符串是否有效。
 * 
 * 有效字符串需满足：
 * 
 * 
 * 左括号必须用相同类型的右括号闭合。
 * 左括号必须以正确的顺序闭合。
 * 
 * 
 * 注意空字符串可被认为是有效字符串。
 * 
 * 示例 1:
 * 
 * 输入: "()"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: "()[]{}"
 * 输出: true
 * 
 * 
 * 示例 3:
 * 
 * 输入: "(]"
 * 输出: false
 * 
 * 
 * 示例 4:
 * 
 * 输入: "([)]"
 * 输出: false
 * 
 * 
 * 示例 5:
 * 
 * 输入: "{[]}"
 * 输出: true
 * 
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValid(string s)
    {
        if (s.size() == 0) {
            return true;
        }
        vector<char> stack;
        int i = 0;
        char c;
        do {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                stack.push_back(s[i]);
            } else {
                if (stack.size() == 0) {
                    return false;
                }
                c = *(stack.end() - 1);
                stack.pop_back();
                if (s[i] == ')') {
                    if (c != '(')
                        return false;
                } else if (s[i] == ']') {
                    if (c != '[') {
                        return false;
                    }
                } else {
                    if (c != '{') {
                        return false;
                    }
                }
            }
            i++;
        } while (i < s.size());

        if (stack.size() == 0)
            return true;
        else
            return false;
    }
};
// @lc code=end
