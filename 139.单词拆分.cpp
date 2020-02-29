/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 *
 * https://leetcode-cn.com/problems/word-break/description/
 *
 * algorithms
 * Medium (42.57%)
 * Likes:    297
 * Dislikes: 0
 * Total Accepted:    32.6K
 * Total Submissions: 75.7K
 * Testcase Example:  '"leetcode"\n["leet","code"]'
 *
 * 给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，判定 s
 * 是否可以被空格拆分为一个或多个在字典中出现的单词。
 *
 * 说明：
 *
 *
 * 拆分时可以重复使用字典中的单词。
 * 你可以假设字典中没有重复的单词。
 *
 *
 * 示例 1：
 *
 * 输入: s = "leetcode", wordDict = ["leet", "code"]
 * 输出: true
 * 解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。
 *
 *
 * 示例 2：
 *
 * 输入: s = "applepenapple", wordDict = ["apple", "pen"]
 * 输出: true
 * 解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
 * 注意你可以重复使用字典中的单词。
 *
 *
 * 示例 3：
 *
 * 输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
 * 输出: false
 *
 *
 */

// @lc code=start
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    set<string> dict(wordDict.begin(), wordDict.end());
    vector<int> mem(s.length(), -1);
    return aux(s, 0, dict, mem);
  }

  bool aux(const string& s, int start, const set<string>& dict,
           vector<int>& mem) {
    if (start == s.length()) {
      return true;
    }
    if (mem[start] != -1) {
      return mem[start];
    }

    bool ret = false;
    for (int len = 1; len <= s.length() - start; ++len) {
      ret = dict.count(s.substr(start, len)) && aux(s, start + len, dict, mem);
      if (ret) {
        mem[start] = 1;
        return ret;
      }
    }
    mem[start] = 0;
    return ret;
  }
};
// @lc code=end
