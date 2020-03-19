/*
 * @lc app=leetcode.cn id=409 lang=cpp
 *
 * [409] 最长回文串
 *
 * https://leetcode-cn.com/problems/longest-palindrome/description/
 *
 * algorithms
 * Easy (52.11%)
 * Likes:    135
 * Dislikes: 0
 * Total Accepted:    34.3K
 * Total Submissions: 63K
 * Testcase Example:  '"abccccdd"'
 *
 * 给定一个包含大写字母和小写字母的字符串，找到通过这些字母构造成的最长的回文串。
 *
 * 在构造过程中，请注意区分大小写。比如 "Aa" 不能当做一个回文字符串。
 *
 * 注意:
 * 假设字符串的长度不会超过 1010。
 *
 * 示例 1:
 *
 *
 * 输入:
 * "abccccdd"
 *
 * 输出:
 * 7
 *
 * 解释:
 * 我们可以构造的最长的回文串是"dccaccd", 它的长度是 7。
 *
 *
 */

// @lc code=start
#include <map>
#include <string>
using namespace std;

class Solution {
 public:
  int longestPalindrome(string s) {
    map<char, int> dict;
    for (const char& c : s) {
      ++dict[c];
    }

    int ans = 0;
    for (auto it = dict.begin(); it != dict.end(); ++it) {
      ans += ((*it).second / 2) * 2;
      (*it).second -= ((*it).second / 2) * 2;
    }

    for (auto it = dict.begin(); it != dict.end(); ++it) {
      if ((*it).second == 1) {
        ans += 1;
        break;
      }
    }
    return ans;
  }
};
// @lc code=end
