/*
 * @lc app=leetcode.cn id=126 lang=cpp
 *
 * [126] 单词接龙 II
 *
 * https://leetcode-cn.com/problems/word-ladder-ii/description/
 *
 * algorithms
 * Hard (27.56%)
 * Likes:    98
 * Dislikes: 0
 * Total Accepted:    5.2K
 * Total Submissions: 16.9K
 * Testcase Example:  '"hit"\n"cog"\n["hot","dot","dog","lot","log","cog"]'
 *
 * 给定两个单词（beginWord 和 endWord）和一个字典 wordList，找出所有从 beginWord
 * 到 endWord 的最短转换序列。转换需遵循如下规则：
 *
 *
 * 每次转换只能改变一个字母。
 * 转换过程中的中间单词必须是字典中的单词。
 *
 *
 * 说明:
 *
 *
 * 如果不存在这样的转换序列，返回一个空列表。
 * 所有单词具有相同的长度。
 * 所有单词只由小写字母组成。
 * 字典中不存在重复的单词。
 * 你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
 *
 *
 * 示例 1:
 *
 * 输入:
 * beginWord = "hit",
 * endWord = "cog",
 * wordList = ["hot","dot","dog","lot","log","cog"]
 *
 * 输出:
 * [
 * ⁠ ["hit","hot","dot","dog","cog"],
 * ["hit","hot","lot","log","cog"]
 * ]
 *
 *
 * 示例 2:
 *
 * 输入:
 * beginWord = "hit"
 * endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log"]
 *
 * 输出: []
 *
 * 解释: endWord "cog" 不在字典中，所以不存在符合要求的转换序列。
 *
 */

// @lc code=start
#include <algorithm>
#include <climits>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList)
    {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if (dict.find(endWord) == dict.end()) {
            return {};
        }
        unordered_map<string, unordered_set<string>> graph;
        unordered_set<string> q{ beginWord }, last_layer;
        for (; q.size() && graph.find(endWord) == graph.end(); q = last_layer) {
            for (const string& word : q) {
                dict.erase(word);
            }
            last_layer.clear();
            for (const string& word : q) {
                string neighbor = word;
                for (char c = 'a'; c <= 'z'; ++c) {
                    for (int i = 0; i < word.length(); ++i) {
                        if (word[i] == c) {
                            continue;
                        }
                        neighbor[i] = c;
                        if (dict.find(neighbor) != dict.end()) {
                            graph[word].insert(neighbor);
                            last_layer.insert(neighbor);
                        }
                        neighbor = word;
                    }
                }
            }
        }
        if (graph.size() == 0) {
            return {};
        }
        vector<vector<string>> ans;
        vector<string> path = { beginWord };
        dfs(graph, beginWord, endWord, path, ans);
        return ans;
    }

    void dfs(const unordered_map<string, unordered_set<string>>& graph, const string& curWord, const string& endWord, vector<string>& path, vector<vector<string>>& ans)
    {
        if (curWord == endWord) {
            ans.push_back(path);
            return;
        }
        try {
            for (const string& s : graph.at(curWord)) {
                path.push_back(s);
                dfs(graph, s, endWord, path, ans);
                path.pop_back();
            }
        } catch (out_of_range) {
            return;
        }
    }
};
// @lc code=end
