/*
 * @lc app=leetcode.cn id=127 lang=cpp
 *
 * [127] 单词接龙
 *
 * https://leetcode-cn.com/problems/word-ladder/description/
 *
 * algorithms
 * Medium (36.60%)
 * Likes:    190
 * Dislikes: 0
 * Total Accepted:    18.6K
 * Total Submissions: 47.9K
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * 给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord
 * 的最短转换序列的长度。转换需遵循如下规则：
 * 
 * 
 * 每次转换只能改变一个字母。
 * 转换过程中的中间单词必须是字典中的单词。
 * 
 * 
 * 说明:
 * 
 * 
 * 如果不存在这样的转换序列，返回 0。
 * 所有单词具有相同的长度。
 * 所有单词只由小写字母组成。
 * 字典中不存在重复的单词。
 * 你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
 * 
 * 
 * 示例 1:
 * 
 * 输入:
 * beginWord = "hit",
 * endWord = "cog",
 * wordList = ["hot","dot","dog","lot","log","cog"]
 * 
 * 输出: 5
 * 
 * 解释: 一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog",
 * ⁠    返回它的长度 5。
 * 
 * 
 * 示例 2:
 * 
 * 输入:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log"]
 * 
 * 输出: 0
 * 
 * 解释: endWord "cog" 不在字典中，所以无法进行转换。
 * 
 */

// @lc code=start
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        int depth = 1; // 起始位置也要算上，所以从 1 开始
        if (dict.find(endWord) == dict.end()) {
            return 0;
        }
        if (beginWord == endWord) {
            return 1;
        }

        // 模拟队列和缓冲区
        unordered_set<string> q{ beginWord };
        unordered_set<string> next_layer;
        string neighbor;
        for (; q.size() && next_layer.find(endWord) == next_layer.end(); q = next_layer, ++depth) {
            next_layer.clear();
            for (auto s : q) {
                dict.erase(s);
            }
            for (auto s : q) {
                for (int i = 0; i < s.size(); ++i) {
                    neighbor = s;
                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (s[i] == c) {
                            continue;
                        }
                        neighbor[i] = c;
                        if (dict.find(neighbor) != dict.end()) {
                            next_layer.insert(neighbor);
                        }
                    }
                }
            }
        }
        if (next_layer.find(endWord) != next_layer.end())
            return depth;
        else
            return 0;
    }
};
// @lc code=end
