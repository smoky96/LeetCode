/*
 * @lc app=leetcode.cn id=97 lang=cpp
 *
 * [97] 交错字符串
 *
 * https://leetcode-cn.com/problems/interleaving-string/description/
 *
 * algorithms
 * Hard (37.03%)
 * Likes:    110
 * Dislikes: 0
 * Total Accepted:    7.7K
 * Total Submissions: 20.4K
 * Testcase Example:  '"aabcc"\n"dbbca"\n"aadbbcbcac"'
 *
 * 给定三个字符串 s1, s2, s3, 验证 s3 是否是由 s1 和 s2 交错组成的。
 * 
 * 示例 1:
 * 
 * 输入: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
 * 输出: false
 * 
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3)
    {
        if (s1.length() == 0) {
            return s2 == s3;
        }
        if (s2.length() == 0) {
            return s1 == s3;
        }
        if (s3.length() == 0) {
            return s1.length() == 0 && s2.length() == 0;
        }
        if (s1.length() + s2.length() != s3.length()) {
            return false;
        }

        string cur;
        vector<vector<int>> mem(s1.size(), vector<int>(s2.size(), -1));
        return aux(s1, s2, s3, cur, 0, 0, mem);
    }

    bool aux(const string& s1, const string& s2, const string& s3, string cur, int n_s1, int n_s2, vector<vector<int>>& mem)
    {
        if (n_s1 == s1.size()) {
            if (s2.substr(n_s2) != s3.substr(cur.size())) {
                return false;
            } else {
                return true;
            }
        }
        if (n_s2 == s2.size()) {
            if (s1.substr(n_s1) != s3.substr(cur.size())) {
                return false;
            } else {
                return true;
            }
        }
        if (mem[n_s1][n_s2] != -1) {
            return mem[n_s1][n_s2];
        }
        if (cur.size() == s3.size()) {
            return true;
        }
        if (n_s1 < s1.size() && s1[n_s1] == s3[cur.size()] && aux(s1, s2, s3, cur + s1.substr(n_s1, 1), n_s1 + 1, n_s2, mem)) {
            mem[n_s1][n_s2] = 1;
            return true;
        }
        if (n_s2 < s2.size() && s2[n_s2] == s3[cur.size()] && aux(s1, s2, s3, cur + s2.substr(n_s2, 1), n_s1, n_s2 + 1, mem)) {
            mem[n_s1][n_s2] = 1;
            return true;
        }
        mem[n_s1][n_s2] = 0;
        return false;
    }
};

// #include <iostream>
// int main()
// {
//     Solution s;
//     string s1 = "cacccaa";
//     string s2 = "acccaacabbbab";
//     string s3 = "accccaaaccccabbaabab";
//     cout << s.isInterleave(s1, s2, s3) << endl;
//     ;
// }
// @lc code=end
