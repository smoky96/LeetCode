/*
 * @lc app=leetcode.cn id=1071 lang=cpp
 *
 * [1071] 字符串的最大公因子
 *
 * https://leetcode-cn.com/problems/greatest-common-divisor-of-strings/description/
 *
 * algorithms
 * Easy (49.75%)
 * Likes:    97
 * Dislikes: 0
 * Total Accepted:    17.3K
 * Total Submissions: 30.1K
 * Testcase Example:  '"ABCABC"\n"ABC"'
 *
 * 对于字符串 S 和 T，只有在 S = T + ... + T（T 与自身连接 1
 * 次或多次）时，我们才认定 “T 能除尽 S”。
 *
 * 返回最长字符串 X，要求满足 X 能除尽 str1 且 X 能除尽 str2。
 *
 *
 *
 * 示例 1：
 *
 * 输入：str1 = "ABCABC", str2 = "ABC"
 * 输出："ABC"
 *
 *
 * 示例 2：
 *
 * 输入：str1 = "ABABAB", str2 = "ABAB"
 * 输出："AB"
 *
 *
 * 示例 3：
 *
 * 输入：str1 = "LEET", str2 = "CODE"
 * 输出：""
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= str1.length <= 1000
 * 1 <= str2.length <= 1000
 * str1[i] 和 str2[i] 为大写英文字母
 *
 *
 */

// @lc code=start
#include <string>
using namespace std;

string operator%(const string& s1, const string& s2) {
  int i = 0;
  int j = 0;
  int ret_pos = 0;
  while (s1[i] == s2[j]) {
    ++i;
    ++j;
    if (i == s1.length() && j == s2.length()) {
      return "";
    }
    if (j == s2.length()) {
      ret_pos = i;
      j = 0;
    }
  }
  return s1.substr(ret_pos);
}

class Solution {
 public:
  string gcdOfStrings(string str1, string str2) {
    if (str1.length() < str2.length()) {
      swap(str1, str2);
    }

    while (str2 != "") {
      string tmp = str1;
      str1 = str2;
      str2 = tmp % str2;
      if (str2 == tmp) {
        return "";
      }
    }
    return str1;
  }
};

// @lc code=end
