/*
 * @lc app=leetcode.cn id=132 lang=cpp
 *
 * [132] 分割回文串 II
 *
 * https://leetcode-cn.com/problems/palindrome-partitioning-ii/description/
 *
 * algorithms
 * Hard (40.22%)
 * Likes:    95
 * Dislikes: 0
 * Total Accepted:    6.6K
 * Total Submissions: 15.9K
 * Testcase Example:  '"aab"'
 *
 * 给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。
 *
 * 返回符合要求的最少分割次数。
 *
 * 示例:
 *
 * 输入: "aab"
 * 输出: 1
 * 解释: 进行一次分割就可将 s 分割成 ["aa","b"] 这样两个回文子串。
 *
 *
 */

// @lc code=start
#include <climits>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  int minCut(string s) {
    vector<int> mem(s.length(), -1);
    vector<vector<bool>> dp_palin(s.length(), vector<bool>(s.length(), false));
    // dp 法判断回文串！！
    for (int len = 1; len <= s.length(); ++len) {
      for (int i = 0; i <= s.length() - len; ++i) {
        int j = i + len - 1;
        dp_palin[i][j] = (s[i] == s[j] && (len < 3 || dp_palin[i + 1][j - 1]));
      }
    }
    aux(s, 0, mem, dp_palin);
    return mem[0] - 1;
  }

  unsigned int aux(const string s, int i, vector<int>& mem,
                   const vector<vector<bool>>& palin) {
    if (i == s.length()) {
      return 0;
    }
    if (mem[i] != -1) {
      return mem[i];
    }

    int tmp;
    int min = INT_MAX;
    for (int len = 1; len <= s.length() - i; ++len) {
      if (palin[i][i + len - 1]) {
        tmp = 1 + aux(s, i + len, mem, palin);
        if (tmp < min) {
          min = tmp;
        }
      }
    }
    mem[i] = min;
    return min;
  }
};
// @lc code=end
