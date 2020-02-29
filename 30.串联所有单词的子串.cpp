/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 *
 * https://leetcode-cn.com/problems/substring-with-concatenation-of-all-words/description/
 *
 * algorithms
 * Hard (27.63%)
 * Likes:    170
 * Dislikes: 0
 * Total Accepted:    16.9K
 * Total Submissions: 60.7K
 * Testcase Example:  '"barfoothefoobarman"\n["foo","bar"]'
 *
 * 给定一个字符串 s 和一些长度相同的单词 words。找出 s 中恰好可以由 words 中所有单词串联形成的子串的起始位置。
 * 
 * 注意子串要与 words 中的单词完全匹配，中间不能有其他字符，但不需要考虑 words 中单词串联的顺序。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 输入：
 * ⁠ s = "barfoothefoobarman",
 * ⁠ words = ["foo","bar"]
 * 输出：[0,9]
 * 解释：
 * 从索引 0 和 9 开始的子串分别是 "barfoo" 和 "foobar" 。
 * 输出的顺序不重要, [9,0] 也是有效答案。
 * 
 * 
 * 示例 2：
 * 
 * 输入：
 * ⁠ s = "wordgoodgoodgoodbestword",
 * ⁠ words = ["word","good","best","word"]
 * 输出：[]
 * 
 * 
 */

// @lc code=start
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words)
    {
        map<string, int> hash_words;
        map<string, int> hash_words_tmp;
        vector<int> ret;
        if (s.size() == 0 || words.size() == 0) {
            return ret;
        }
        if (words.size() * words[0].size() > s.size()) {
            return ret;
        }
        for (auto w : words) {
            hash_words[w] += 1;
        }

        int word_len = words[0].size();
        int total_len = word_len * words.size();
        int i = 0;
        int j = 0;
        int k = 0;
        string sub;
        while (j <= (s.size() - total_len)) {
            for (i = 0; i < total_len; i = i + word_len) {
                sub = s.substr(j + i, word_len);
                if (hash_words[sub] == 0) {
                    goto reset;
                }
                hash_words_tmp[sub] += 1;
                if (hash_words_tmp[sub] > hash_words[sub]) {
                    goto reset;
                }
            }

            for (k = 0; k < words.size(); k++) {
                if (hash_words[words[k]] != hash_words_tmp[words[k]])
                    break;
            }
            if (k == words.size()) {
                ret.push_back(j);
            }
        reset:
            hash_words_tmp.clear();
            ++j;
        }
        return ret;
    }
};
// @lc code=end
