/*
 * @lc app=leetcode.cn id=211 lang=cpp
 *
 * [211] 添加与搜索单词 - 数据结构设计
 *
 * https://leetcode-cn.com/problems/design-add-and-search-words-data-structure/description/
 *
 * algorithms
 * Medium (51.11%)
 * Likes:    379
 * Dislikes: 0
 * Total Accepted:    50.8K
 * Total Submissions: 99.5K
 * Testcase Example:  '["WordDictionary","addWord","addWord","addWord","search","search","search","search"]\n' +
  '[[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]'
 *
 * 请你设计一个数据结构，支持 添加新单词 和 查找字符串是否与任何先前添加的字符串匹配 。
 * 
 * 实现词典类 WordDictionary ：
 * 
 * 
 * WordDictionary() 初始化词典对象
 * void addWord(word) 将 word 添加到数据结构中，之后可以对它进行匹配
 * bool search(word) 如果数据结构中存在字符串与 word 匹配，则返回 true ；否则，返回  false 。word 中可能包含一些
 * '.' ，每个 . 都可以表示任何一个字母。
 * 
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 输入：
 * 
 * ["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
 * [[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
 * 输出：
 * [null,null,null,null,false,true,true,true]
 * 
 * 解释：
 * WordDictionary wordDictionary = new WordDictionary();
 * wordDictionary.addWord("bad");
 * wordDictionary.addWord("dad");
 * wordDictionary.addWord("mad");
 * wordDictionary.search("pad"); // return False
 * wordDictionary.search("bad"); // return True
 * wordDictionary.search(".ad"); // return True
 * wordDictionary.search("b.."); // return True
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 
 * addWord 中的 word 由小写英文字母组成
 * search 中的 word 由 '.' 或小写英文字母组成
 * 最多调用 50000 次 addWord 和 search
 * 
 * 
 */

// @lc code=start
#include <string>
#include <memory>
#include <vector>
#include <iostream>

using namespace std;


class Trie {

vector<unique_ptr<Trie>> _children;
bool _is_end;

public:
    Trie() : _children(26), _is_end(false) {}

    void addWord(const string& word, size_t idx) {
        if (word.length() == idx) {
            _is_end = true;
            return;
        }

        int child_idx = word[idx] - 'a';
        if (_children[child_idx] == nullptr) {
            _children[child_idx].reset(new Trie());
        }

        _children[child_idx]->addWord(word, idx + 1);
    }

    bool searchWord(const string& word, size_t idx) {
        if (word.length() == idx) {
            if (_is_end) {
                return true;
            } else {
                return false;
            }
        }

        if (word[idx] == '.') {
            for (int i = 0; i < 26; ++i) {
                if (_children[i] != nullptr && _children[i]->searchWord(word, idx + 1)) {
                    return true;
                }
            }
            return false;
        }
        
        int child_idx = word[idx] - 'a';
        if (_children[child_idx] == nullptr) {
            return false;
        } else {
            return _children[child_idx]->searchWord(word, idx + 1);
        }
    }
};

class WordDictionary {
public:
    WordDictionary() {}
    
    void addWord(string word) {
        _root.addWord(word, 0);
    }
    
    bool search(string word) {
        return _root.searchWord(word, 0);
    }

private:
    Trie _root;
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
// @lc code=end
