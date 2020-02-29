/*
 * @lc app=leetcode.cn id=91 lang=cpp
 *
 * [91] 解码方法
 *
 * https://leetcode-cn.com/problems/decode-ways/description/
 *
 * algorithms
 * Medium (21.60%)
 * Likes:    237
 * Dislikes: 0
 * Total Accepted:    24.9K
 * Total Submissions: 110.9K
 * Testcase Example:  '"12"'
 *
 * 一条包含字母 A-Z 的消息通过以下方式进行了编码：
 * 
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * 
 * 
 * 给定一个只包含数字的非空字符串，请计算解码方法的总数。
 * 
 * 示例 1:
 * 
 * 输入: "12"
 * 输出: 2
 * 解释: 它可以解码为 "AB"（1 2）或者 "L"（12）。
 * 
 * 
 * 示例 2:
 * 
 * 输入: "226"
 * 输出: 3
 * 解释: 它可以解码为 "BZ" (2 26), "VF" (22 6), 或者 "BBF" (2 2 6) 。
 * 
 * 
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int numDecodings(string s)
    {
        vector<int> mem(s.size(), -1);
        return aux(s, mem, 0);
    }

    int aux(const string& s, vector<int>& mem, int pos)
    {
        if (pos == s.length()) {
            return 1;
        }

        if (mem[pos] != -1) {
            return mem[pos];
        }

        if (s[pos] == '0') {
            mem[pos] = 0;
            return 0;
        } else if (pos < s.length() - 1 && (stoi(s.substr(pos, 2)) <= 26)) {
            mem[pos] = aux(s, mem, pos + 1) + aux(s, mem, pos + 2);
            return mem[pos];
        } else {
            mem[pos] = aux(s, mem, pos + 1);
            return mem[pos];
        }
    }
};
// @lc code=end
