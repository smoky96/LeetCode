/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原IP地址
 *
 * https://leetcode-cn.com/problems/restore-ip-addresses/description/
 *
 * algorithms
 * Medium (45.14%)
 * Likes:    166
 * Dislikes: 0
 * Total Accepted:    20.1K
 * Total Submissions: 44.5K
 * Testcase Example:  '"25525511135"'
 *
 * 给定一个只包含数字的字符串，复原它并返回所有可能的 IP 地址格式。
 * 
 * 示例:
 * 
 * 输入: "25525511135"
 * 输出: ["255.255.11.135", "255.255.111.35"]
 * 
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s)
    {
        if (s.length() > 12 || s.length() < 4) {
            return {};
        }
        vector<string> ans;
        aux(s, ans, "", 0, 0);
        return ans;
    }

    void aux(const string& s, vector<string>& ans, string tmp, int n, int pos)
    {
        if (n == 3) {
            if (pos >= s.length() || stoi(s.substr(pos)) > 255 || ((s.length() - pos) > 1 && s[pos] == '0')) {
                return;
            } else {
                ans.push_back(tmp + "." + s.substr(pos));
            }
        }

        if (pos + 1 < s.length()) {
            if (n == 0) {
                aux(s, ans, s.substr(pos, 1), n + 1, pos + 1);
            } else {
                aux(s, ans, tmp + "." + s.substr(pos, 1), n + 1, pos + 1);
            }
        }

        if (pos + 2 < s.length() && s[pos] != '0') {
            if (n == 0) {
                aux(s, ans, s.substr(pos, 2), n + 1, pos + 2);
            } else {
                aux(s, ans, tmp + "." + s.substr(pos, 2), n + 1, pos + 2);
            }
        }

        if (pos + 3 < s.length() && s[pos] != '0' && stoi(s.substr(pos, 3)) <= 255) {
            if (n == 0) {
                aux(s, ans, s.substr(pos, 3), n + 1, pos + 3);
            } else {
                aux(s, ans, tmp + "." + s.substr(pos, 3), n + 1, pos + 3);
            }
        }
    }
};
// @lc code=end
