/*
 * @lc app=leetcode.cn id=224 lang=cpp
 *
 * [224] 基本计算器
 *
 * https://leetcode-cn.com/problems/basic-calculator/description/
 *
 * algorithms
 * Hard (41.80%)
 * Likes:    715
 * Dislikes: 0
 * Total Accepted:    82.4K
 * Total Submissions: 197.2K
 * Testcase Example:  '"1 + 1"'
 *
 * 给你一个字符串表达式 s ，请你实现一个基本计算器来计算并返回它的值。
 * 
 * 注意:不允许使用任何将字符串作为数学表达式计算的内置函数，比如 eval() 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：s = "1 + 1"
 * 输出：2
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：s = " 2-1 + 2 "
 * 输出：3
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：s = "(1+(4+5+2)-3)+(6+8)"
 * 输出：23
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= s.length <= 3 * 10^5
 * s 由数字、'+'、'-'、'('、')'、和 ' ' 组成
 * s 表示一个有效的表达式
 * '+' 不能用作一元运算(例如， "+1" 和 "+(2 + 3)" 无效)
 * '-' 可以用作一元运算(即 "-1" 和 "-(2 + 3)" 是有效的)
 * 输入中不存在两个连续的操作符
 * 每个数字和运行的计算将适合于一个有符号的 32位 整数
 * 
 * 
 */

// @lc code=start
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
    int calculate(string s) {
        if (s.length() == 0) {
            return 0;
        }

        stack<char> ops;
        stack<int> nums;
        
        if (s[0] == '+' || s[0] == '-') {
            nums.push(0);
        }

        for (int i = 0; i < s.length();) {
            if (s[i] == ' ') {
                ++i;
            } else if (s[i] == '(') {
                ops.push(s[i]);
                ++i;
            } else if (s[i] == ')') {
                compute(&nums, &ops);
                ops.pop();
                ++i;
            } else if (s[i] == '+' || s[i] == '-') {
                if (!ops.empty() && ops.top() != '(') {
                    compute(&nums, &ops);
                }
                if (i > 0 && (s[i - 1] == '+' || s[i - 1] == '-' || s[i - 1] == '(')) {
                    nums.push(0);
                }
                ops.push(s[i]);
                ++i;
            } else {
                int num = 0;
                while (i < s.length() && s[i] >= '0' && s[i] <= '9') {
                    num = 10 * num + (s[i] - '0');
                    ++i;
                }
                nums.push(num);
            }
        }
        
        if (!ops.empty()) {
            compute(&nums, &ops);
        }
        return nums.top();
    }

    void compute(stack<int>* nums, stack<char>* ops) {
        while (!ops->empty()) {
            char op = ops->top();
            if (op == '(') {
                return; // 注意这里不弹出，遇到右括号时才弹出
            }
            ops->pop();
            int rhs = nums->top();
            nums->pop();
            int lhs = nums->top();
            nums->pop();
            int res = (op == '+' ? lhs + rhs : lhs - rhs);
            nums->push(res);
        }
    }
};
// @lc code=end

