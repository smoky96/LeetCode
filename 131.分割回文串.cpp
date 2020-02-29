/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 *
 * https://leetcode-cn.com/problems/palindrome-partitioning/description/
 *
 * algorithms
 * Medium (63.64%)
 * Likes:    200
 * Dislikes: 0
 * Total Accepted:    19.1K
 * Total Submissions: 29.5K
 * Testcase Example:  '"aab"'
 *
 * 给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。
 *
 * 返回 s 所有可能的分割方案。
 *
 * 示例:
 *
 * 输入: "aab"
 * 输出:
 * [
 * ⁠ ["aa","b"],
 * ⁠ ["a","a","b"]
 * ]
 *
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<string>> ans;
  vector<string> split;
  vector<vector<string>> partition(string s) {
    aux(s, 0);
    return ans;
  }

  void aux(const string& s, int i) {
    if (i == s.length()) {
      ans.push_back(split);
      return;
    }

    for (int l = 1; l <= s.length() - i; ++l) {
      if (is_palin(s.substr(i, l))) {
        split.push_back(s.substr(i, l));
        aux(s, i + l);
        split.pop_back();
      }
    }
  }

  bool is_palin(const string& s) {
    for (int i = 0, j = s.length() - 1; i < j; ++i, --j) {
      if (s[i] != s[j]) {
        return false;
      }
    }
    return true;
  }
};
// @lc code=end
