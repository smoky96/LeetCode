/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 *
 * https://leetcode-cn.com/problems/group-anagrams/description/
 *
 * algorithms
 * Medium (58.09%)
 * Likes:    214
 * Dislikes: 0
 * Total Accepted:    37K
 * Total Submissions: 62.3K
 * Testcase Example:  '["eat","tea","tan","ate","nat","bat"]'
 *
 * 给定一个字符串数组，将字母异位词组合在一起。字母异位词指字母相同，但排列不同的字符串。
 * 
 * 示例:
 * 
 * 输入: ["eat", "tea", "tan", "ate", "nat", "bat"],
 * 输出:
 * [
 * ⁠ ["ate","eat","tea"],
 * ⁠ ["nat","tan"],
 * ⁠ ["bat"]
 * ]
 * 
 * 说明：
 * 
 * 
 * 所有输入均为小写字母。
 * 不考虑答案输出的顺序。
 * 
 * 
 */

// @lc code=start
#include <algorithm>
#include <map>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
    {
        map<string, int> hash;
        vector<vector<string>> res(strs.size());
        string key;
        int idx = 0;
        for (string s : strs) {
            key = s;
            sort(key.begin(), key.end());
            if (hash.find(key) != hash.end()) {
                res[hash[key]].push_back(s);
            } else {
                hash[key] = idx;
                res[idx].push_back(s);
                ++idx;
            }
        }
        for (idx = strs.size() - 1; idx >= 0; --idx) {
            if (res[idx].size() == 0) {
                res.pop_back();
            }
        }
        return res;
    }
};
// @lc code=end
