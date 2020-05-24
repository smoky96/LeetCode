/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 实现 strStr()
 *
 * https://leetcode-cn.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (38.71%)
 * Likes:    295
 * Dislikes: 0
 * Total Accepted:    99.7K
 * Total Submissions: 255.6K
 * Testcase Example:  '"hello"\n"ll"'
 *
 * 实现 strStr() 函数。
 * 
 * 给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置
 * (从0开始)。如果不存在，则返回  -1。
 * 
 * 示例 1:
 * 
 * 输入: haystack = "hello", needle = "ll"
 * 输出: 2
 * 
 * 
 * 示例 2:
 * 
 * 输入: haystack = "aaaaa", needle = "bba"
 * 输出: -1
 * 
 * 
 * 说明:
 * 
 * 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
 * 
 * 对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
 * 
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle)
    {
        if (needle.size() == 0) {
            return 0;
        }

        if (needle.size() > haystack.size()) {
            return -1;
        }
        vector<int> next = getNext(needle);
        int len_h = haystack.size();
        int len_n = needle.size();
        int j = 0;
        int i = 0;
        while (i < len_h && j < len_n) {
            if ((j == -1) || (haystack[i] == needle[j])) {
                ++j;
                ++i;
            } else {
                j = next[j];
            }
        }

        if (j == len_n) {
            return i - j;
        }

        return -1;
    }

    vector<int> getNext(string pattern)
    {
        int i = -1;
        int j = 0;
        vector<int> next = { -1 };
        while (j < (pattern.size() - 1)) {
            if ((i == -1) || (pattern[i] == pattern[j])) {
                ++i;
                ++j;
                next.push_back(i);
            } else {
                i = next[i];
            }
        }
        return next;
    }
};
// @lc code=end
