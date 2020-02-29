/*
 * @lc app=leetcode.cn id=115 lang=cpp
 *
 * [115] 不同的子序列
 *
 * https://leetcode-cn.com/problems/distinct-subsequences/description/
 *
 * algorithms
 * Hard (44.65%)
 * Likes:    119
 * Dislikes: 0
 * Total Accepted:    7.3K
 * Total Submissions: 15.9K
 * Testcase Example:  '"rabbbit"\n"rabbit"'
 *
 * 给定一个字符串 S 和一个字符串 T，计算在 S 的子序列中 T 出现的个数。
 * 
 * 一个字符串的一个子序列是指，通过删除一些（也可以不删除）字符且不干扰剩余字符相对位置所组成的新字符串。（例如，"ACE" 是 "ABCDE"
 * 的一个子序列，而 "AEC" 不是）
 * 
 * 示例 1:
 * 
 * 输入: S = "rabbbit", T = "rabbit"
 * 输出: 3
 * 解释:
 * 
 * 如下图所示, 有 3 种可以从 S 中得到 "rabbit" 的方案。
 * (上箭头符号 ^ 表示选取的字母)
 * 
 * rabbbit
 * ^^^^ ^^
 * rabbbit
 * ^^ ^^^^
 * rabbbit
 * ^^^ ^^^
 * 
 * 
 * 示例 2:
 * 
 * 输入: S = "babgbag", T = "bag"
 * 输出: 5
 * 解释:
 * 
 * 如下图所示, 有 5 种可以从 S 中得到 "bag" 的方案。 
 * (上箭头符号 ^ 表示选取的字母)
 * 
 * babgbag
 * ^^ ^
 * babgbag
 * ^^    ^
 * babgbag
 * ^    ^^
 * babgbag
 * ⁠ ^  ^^
 * babgbag
 * ⁠   ^^^
 * 
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t)
    {
        vector<vector<int>> mem(s.length(), vector<int>(t.length(), -1));
        return aux(s, t, 0, 0, mem);
    }

    int aux(const string& s, const string& t, int i_s, int i_t, vector<vector<int>>& mem)
    {
        if (i_t == t.length()) {
            return 1;
        }
        if (i_s == s.length()) {
            return 0;
        }
        if (mem[i_s][i_t] != -1) {
            return mem[i_s][i_t];
        }

        int num1 = 0;
        int num2 = 0;
        if (s[i_s] == t[i_t]) {
            num1 = aux(s, t, i_s + 1, i_t + 1, mem);
        }
        num2 = aux(s, t, i_s + 1, i_t, mem);
        mem[i_s][i_t] = num1 + num2;
        return mem[i_s][i_t];
    }
};

// @lc code=end
