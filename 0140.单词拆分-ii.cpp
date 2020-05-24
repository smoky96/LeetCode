/*
 * @lc app=leetcode.cn id=140 lang=cpp
 *
 * [140] 单词拆分 II
 *
 * https://leetcode-cn.com/problems/word-break-ii/description/
 *
 * algorithms
 * Hard (37.63%)
 * Likes:    108
 * Dislikes: 0
 * Total Accepted:    10.6K
 * Total Submissions: 28.1K
 * Testcase Example:  '"catsanddog"\n["cat","cats","and","sand","dog"]'
 *
 * 给定一个非空字符串 s 和一个包含非空单词列表的字典
 * wordDict，在字符串中增加空格来构建一个句子，使得句子中所有的单词都在词典中。返回所有这些可能的句子。
 *
 * 说明：
 *
 *
 * 分隔时可以重复使用字典中的单词。
 * 你可以假设字典中没有重复的单词。
 *
 *
 * 示例 1：
 *
 * 输入:
 * s = "catsanddog"
 * wordDict = ["cat", "cats", "and", "sand", "dog"]
 * 输出:
 * [
 * "cats and dog",
 * "cat sand dog"
 * ]
 *
 *
 * 示例 2：
 *
 * 输入:
 * s = "pineapplepenapple"
 * wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
 * 输出:
 * [
 * "pine apple pen apple",
 * "pineapple pen apple",
 * "pine applepen apple"
 * ]
 * 解释: 注意你可以重复使用字典中的单词。
 *
 *
 * 示例 3：
 *
 * 输入:
 * s = "catsandog"
 * wordDict = ["cats", "dog", "sand", "and", "cat"]
 * 输出:
 * []
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
  vector<string> wordBreak(string s, vector<string>& wordDict) {
    set<string> dict(wordDict.begin(), wordDict.end());
    map<int, vector<string>> mem;
    return aux(s, 0, dict, mem);
  }

  vector<string> aux(const string& s, int start, const set<string>& dict,
                     map<int, vector<string>>& mem) {
    if (start == s.length()) {
      return {""};
    }
    if (mem.find(start) != mem.end()) {
      return mem[start];
    }

    vector<string> ret;
    vector<string> strs;
    for (int len = 1; len <= s.length() - start; ++len) {
      string sub = s.substr(start, len);
      if (dict.find(sub) != dict.end()) {
        if (start == 0) {
          strs = aux(s, start + len, dict, mem);
          for (auto str : strs) {
            ret.push_back(sub + str);
          }
        } else {
          strs = aux(s, start + len, dict, mem);
          for (auto str : strs) {
            ret.push_back(" " + sub + str);
          }
        }
      } else {
        continue;
      }
    }
    mem[start] = ret;
    return ret;
  }
};
// @lc code=end
