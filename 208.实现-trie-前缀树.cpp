/*
 * @lc app=leetcode.cn id=208 lang=cpp
 *
 * [208] 实现 Trie (前缀树)
 *
 * https://leetcode-cn.com/problems/implement-trie-prefix-tree/description/
 *
 * algorithms
 * Medium (65.19%)
 * Likes:    218
 * Dislikes: 0
 * Total Accepted:    27K
 * Total Submissions: 41.4K
 * Testcase Example:
 '["Trie","insert","search","search","startsWith","insert","search"]\n' +
  '[[],["apple"],["apple"],["app"],["app"],["app"],["app"]]'
 *
 * 实现一个 Trie (前缀树)，包含 insert, search, 和 startsWith 这三个操作。
 *
 * 示例:
 *
 * Trie trie = new Trie();
 *
 * trie.insert("apple");
 * trie.search("apple");   // 返回 true
 * trie.search("app");     // 返回 false
 * trie.startsWith("app"); // 返回 true
 * trie.insert("app");
 * trie.search("app");     // 返回 true
 *
 * 说明:
 *
 *
 * 你可以假设所有的输入都是由小写字母 a-z 构成的。
 * 保证所有输入均为非空字符串。
 *
 *
 */

// @lc code=start
#include <memory>
#include <string>
#include <vector>
using namespace std;

struct TrieNode {
  unique_ptr<TrieNode> childs[26];
  bool isEnd;
  TrieNode(bool _isEnd) : isEnd(_isEnd), childs() {
    for (int i = 0; i < 26; ++i) childs[i] = nullptr;
  }
};

class Trie {
  unique_ptr<TrieNode> root;

 public:
  /** Initialize your data structure here. */
  Trie() : root(new TrieNode(true)) {}

  /** Inserts a word into the trie. */
  void insert(string word) {
    TrieNode* cur = root.get();
    for (int i = 0; i < word.size(); ++i) {
      int idx = word[i] - 'a';
      if (cur->childs[idx] == nullptr) {
        cur->childs[idx].reset(new TrieNode(false));
      }
      cur = cur->childs[idx].get();
    }
    cur->isEnd = true;
  }

  /** Returns if the word is in the trie. */
  bool search(string word) {
    TrieNode* cur = root.get();
    for (int i = 0; i < word.size(); ++i) {
      int idx = word[i] - 'a';
      if (cur->childs[idx] == nullptr) {
        return false;
      } else {
        cur = cur->childs[idx].get();
      }
    }
    return cur->isEnd;
  }

  /** Returns if there is any word in the trie that starts with the given
   * prefix. */
  bool startsWith(string prefix) {
    TrieNode* cur = root.get();
    for (int i = 0; i < prefix.size(); ++i) {
      int idx = prefix[i] - 'a';
      if (cur->childs[idx] != nullptr) {
        cur = cur->childs[idx].get();
      } else {
        return false;
      }
    }
    return true;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
// @lc code=end
