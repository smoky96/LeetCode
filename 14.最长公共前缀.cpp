/*
 * @lc app=leetcode.cn id=14 lang=cpp
 *
 * [14] 最长公共前缀
 *
 * https://leetcode-cn.com/problems/longest-common-prefix/description/
 *
 * algorithms
 * Easy (34.49%)
 * Likes:    763
 * Dislikes: 0
 * Total Accepted:    145.6K
 * Total Submissions: 413.1K
 * Testcase Example:  '["flower","flow","flight"]'
 *
 * 编写一个函数来查找字符串数组中的最长公共前缀。
 * 
 * 如果不存在公共前缀，返回空字符串 ""。
 * 
 * 示例 1:
 * 
 * 输入: ["flower","flow","flight"]
 * 输出: "fl"
 * 
 * 
 * 示例 2:
 * 
 * 输入: ["dog","racecar","car"]
 * 输出: ""
 * 解释: 输入不存在公共前缀。
 * 
 * 
 * 说明:
 * 
 * 所有输入只包含小写字母 a-z 。
 * 
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        string prefix = "";
        char c;
        int i = 0;
        if (strs.size() == 0) {
            return prefix;
        }
        while (i < strs[0].length()) {
            c = strs[0][i];
            for (string s : strs) {
                if (s.length() == i || c != s[i]) {
                    return prefix;
                }
            }
            prefix += c;
            i++;
        }
        return prefix;
    }
};
// @lc code=end
