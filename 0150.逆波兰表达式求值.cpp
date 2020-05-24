/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 *
 * https://leetcode-cn.com/problems/evaluate-reverse-polish-notation/description/
 *
 * algorithms
 * Medium (49.02%)
 * Likes:    100
 * Dislikes: 0
 * Total Accepted:    26.9K
 * Total Submissions: 54.8K
 * Testcase Example:  '["2","1","+","3","*"]'
 *
 * 根据逆波兰表示法，求表达式的值。
 *
 * 有效的运算符包括 +, -, *, / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。
 *
 * 说明：
 *
 *
 * 整数除法只保留整数部分。
 * 给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0
 * 的情况。
 *
 *
 * 示例 1：
 *
 * 输入: ["2", "1", "+", "3", "*"]
 * 输出: 9
 * 解释: ((2 + 1) * 3) = 9
 *
 *
 * 示例 2：
 *
 * 输入: ["4", "13", "5", "/", "+"]
 * 输出: 6
 * 解释: (4 + (13 / 5)) = 6
 *
 *
 * 示例 3：
 *
 * 输入: ["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"]
 * 输出: 22
 * 解释:
 * ⁠ ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
 * = ((10 * (6 / (12 * -11))) + 17) + 5
 * = ((10 * (6 / -132)) + 17) + 5
 * = ((10 * 0) + 17) + 5
 * = (0 + 17) + 5
 * = 17 + 5
 * = 22
 *
 */

// @lc code=start
#include <cstdio>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
 public:
  enum op { plus, sub, mul, div };

  int evalRPN(vector<string>& tokens) {
    int i = 0;
    stack<int> st;
    st.push(stoi(tokens[i++]));

    unordered_map<string, op> dict{
        {"+", plus}, {"-", sub}, {"*", mul}, {"/", div}};

    int rhs, lhs, res;
    for (; i != tokens.size(); ++i) {
      if (dict.count(tokens[i])) {
        rhs = st.top();
        st.pop();
        lhs = st.top();
        st.pop();
        switch (dict[tokens[i]]) {
          case plus:
            res = lhs + rhs;
            break;
          case sub:
            res = lhs - rhs;
            break;
          case mul:
            res = lhs * rhs;
            break;
          case div:
            res = lhs / rhs;
            break;
          default:
            break;
        }
        st.push(res);
      } else {
        st.push(stoi(tokens[i]));
      }
    }
    return st.top();
  }
};
// @lc code=end
