/*
 * @lc app=leetcode.cn id=187 lang=cpp
 *
 * [187] 重复的DNA序列
 *
 * https://leetcode-cn.com/problems/repeated-dna-sequences/description/
 *
 * algorithms
 * Medium (43.88%)
 * Likes:    72
 * Dislikes: 0
 * Total Accepted:    12.2K
 * Total Submissions: 27.7K
 * Testcase Example:  '"AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"'
 *
 * 所有 DNA 都由一系列缩写为 A，C，G 和 T
 * 的核苷酸组成，例如：“ACGAATTCCG”。在研究 DNA 时，识别 DNA
 * 中的重复序列有时会对研究非常有帮助。
 *
 * 编写一个函数来查找 DNA 分子中所有出现超过一次的 10 个字母长的序列（子串）。
 *
 *
 *
 * 示例：
 *
 * 输入：s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT"
 * 输出：["AAAAACCCCC", "CCCCCAAAAA"]
 *
 */

// @lc code=start
#include <map>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<string> findRepeatedDnaSequences(string s) {
    if (s.length() < 10) {
      return {};
    }

    map<string, int> cnt_map;
    vector<string> ans;

    for (int i = 0; i < s.length() - 9; ++i) {
      int cnt = ++cnt_map[s.substr(i, 10)];
      if (cnt > 1 && cnt < 3) {
        ans.push_back(s.substr(i, 10));
      }
    }
    return ans;
  }
};
// @lc code=end
