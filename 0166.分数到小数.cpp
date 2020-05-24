/*
 * @lc app=leetcode.cn id=166 lang=cpp
 *
 * [166] 分数到小数
 *
 * https://leetcode-cn.com/problems/fraction-to-recurring-decimal/description/
 *
 * algorithms
 * Medium (25.66%)
 * Likes:    105
 * Dislikes: 0
 * Total Accepted:    8.5K
 * Total Submissions: 33K
 * Testcase Example:  '1\n2'
 *
 * 给定两个整数，分别表示分数的分子 numerator 和分母
 * denominator，以字符串形式返回小数。
 *
 * 如果小数部分为循环小数，则将循环的部分括在括号内。
 *
 * 示例 1:
 *
 * 输入: numerator = 1, denominator = 2
 * 输出: "0.5"
 *
 *
 * 示例 2:
 *
 * 输入: numerator = 2, denominator = 1
 * 输出: "2"
 *
 * 示例 3:
 *
 * 输入: numerator = 2, denominator = 3
 * 输出: "0.(6)"
 *
 *
 */

// @lc code=start
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  string fractionToDecimal(int numerator, int denominator) {
    string ans;
    long num = numerator;
    long den = denominator;

    if (num < 0 && den > 0 || num > 0 && den < 0) {
      ans = "-";
    }

    num = abs(num);
    den = abs(den);

    long dec = num / den;
    ans += to_string(dec);

    num = num - dec * den;
    string after_p;
    unordered_map<long, int> m;

    int repeat_index = -1;
    int cnt = 0;
    while (num != 0) {
      num *= 10;

      if (m.find(num) != m.end()) {
        repeat_index = m[num];
        break;
      }

      m[num] = cnt++;
      dec = num / den;
      after_p += to_string(dec);

      num = num - dec * den;
    }

    if (repeat_index != -1) {
      ans += "." + after_p.substr(0, repeat_index) + "(" +
             after_p.substr(repeat_index) + ")";
    } else if (m.size() != 0) {
      ans += "." + after_p;
    }
    return ans;
  }
};
// @lc code=end
