/*
 * @lc app=leetcode.cn id=820 lang=cpp
 *
 * [820] 单词的压缩编码
 *
 * https://leetcode-cn.com/problems/short-encoding-of-words/description/
 *
 * algorithms
 * Medium (41.19%)
 * Likes:    122
 * Dislikes: 0
 * Total Accepted:    25.1K
 * Total Submissions: 53.7K
 * Testcase Example:  '["time", "me", "bell"]'
 *
 * 给定一个单词列表，我们将这个列表编码成一个索引字符串 S 与一个索引列表 A。
 *
 * 例如，如果这个列表是 ["time", "me", "bell"]，我们就可以将其表示为 S =
 * "time#bell#" 和 indexes = [0, 2, 5]。
 *
 * 对于每一个索引，我们可以通过从字符串 S 中索引的位置开始读取字符串，直到 "#"
 * 结束，来恢复我们之前的单词列表。
 *
 * 那么成功对给定单词列表进行编码的最小字符串长度是多少呢？
 *
 *
 *
 * 示例：
 *
 * 输入: words = ["time", "me", "bell"]
 * 输出: 10
 * 说明: S = "time#bell#" ， indexes = [0, 2, 5] 。
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= words.length <= 2000
 * 1 <= words[i].length <= 7
 * 每个单词都是小写字母 。
 *
 *
 */

// @lc code=start
#include <algorithm>
#include <memory>
#include <string>
#include <vector>
using namespace std;

struct TrieNode {
  unique_ptr<TrieNode> next[26];
  TrieNode() {
    for (int i = 0; i < 26; ++i) next[i] = nullptr;
  }
};

class Solution {
 public:
  unique_ptr<TrieNode> head;

  int minimumLengthEncoding(vector<string>& words) {
    if (words.size() == 0) return 0;

    head.reset(new TrieNode());
    sort(words.begin(), words.end(), [&](const string& a, const string& b) {
      return b.length() < a.length();
    });

    int ans = 0;
    for (const string& s : words) {
      ans += insert(s);
    }

    return ans;
  }

  int insert(const string& s) {
    bool flag = false;
    TrieNode* p = head.get();
    for (auto rit = s.rbegin(); rit != s.rend(); ++rit) {
      if (p->next[*rit - 'a'] == nullptr) {
        flag = true;
        p->next[*rit - 'a'].reset(new TrieNode());
      }
      p = p->next[*rit - 'a'].get();
    }

    // 如果是新单词，必须整个加上，不能复用前缀
    return flag ? s.length() + 1 : 0;
  }
};
// @lc code=end
