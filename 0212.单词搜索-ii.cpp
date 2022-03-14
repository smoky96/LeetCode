/*
 * @lc app=leetcode.cn id=212 lang=cpp
 *
 * [212] 单词搜索 II
 *
 * https://leetcode-cn.com/problems/word-search-ii/description/
 *
 * algorithms
 * Hard (46.50%)
 * Likes:    595
 * Dislikes: 0
 * Total Accepted:    66.3K
 * Total Submissions: 142.6K
 * Testcase Example:  '[["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]]\n' +
  '["oath","pea","eat","rain"]'
 *
 * 给定一个 m x n 二维字符网格 board 和一个单词（字符串）列表 words，找出所有同时在二维网格和字典中出现的单词。
 * 
 * 单词必须按照字母顺序，通过 相邻的单元格
 * 内的字母构成，其中“相邻”单元格是那些水平相邻或垂直相邻的单元格。同一个单元格内的字母在一个单词中不允许被重复使用。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：board =
 * [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]],
 * words = ["oath","pea","eat","rain"]
 * 输出：["eat","oath"]
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：board = [["a","b"],["c","d"]], words = ["abcb"]
 * 输出：[]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * m == board.length
 * n == board[i].length
 * 1 
 * board[i][j] 是一个小写英文字母
 * 1 
 * 1 
 * words[i] 由小写英文字母组成
 * words 中的所有字符串互不相同
 * 
 * 
 */

// @lc code=start
#include <cstddef>
#include <string>
#include <utility>
#include <vector>
#include <memory>
#include <unordered_set>

using namespace std;

struct TrieNode {
    vector<TrieNode*> children;
    string word;

    TrieNode() : children(26) {}
};

class Trie {
public:
    TrieNode* root;

    Trie() : root(new TrieNode) {}

    void addWord(const std::string& word) {
        auto cur = root;
        for (char c : word) {
            if (cur->children[c - 'a'] == nullptr) {
                cur->children[c - 'a'] = new TrieNode;
            } 
            cur = cur->children[c - 'a'];
        }
        cur->word = word;
    }
};

class Solution {
    const vector<pair<int, int>> direct = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
    Trie trie;

public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (const auto& word : words) {
            trie.addWord(word);
        }

        vector<string> results;

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                if (trie.root->children[board[i][j] - 'a'] != nullptr) {
                    dfs(board, i, j, results, trie.root->children[board[i][j] - 'a']);
                }
            }
        }

        return results;
    }

    void dfs(vector<vector<char>>& board, int i, int j, vector<string>& result, TrieNode* root) {
        if (root->word.length() > 0) {
            result.push_back(root->word);
            root->word = "";
        }

        char c = board[i][j];
        board[i][j] = '#';
        for (const auto& dir : direct) {
            int next_i = i + dir.first;
            int next_j = j + dir.second;

            if (next_i < 0 || next_i == board.size() || next_j < 0 || next_j == board[0].size()) {
                continue;
            }
            
            if (board[next_i][next_j] == '#') {
                continue;
            }

            if (root->children[board[next_i][next_j] - 'a'] != nullptr) {
                dfs(board, next_i, next_j, result, root->children[board[next_i][next_j] - 'a']);
            }
        }
        board[i][j] = c;
    }
};
// @lc code=end