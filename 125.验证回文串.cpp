/*
 * @lc app=leetcode.cn id=125 lang=cpp
 *
 * [125] 验证回文串
 *
 * https://leetcode-cn.com/problems/valid-palindrome/description/
 *
 * algorithms
 * Easy (40.74%)
 * Likes:    141
 * Dislikes: 0
 * Total Accepted:    71.1K
 * Total Submissions: 169.5K
 * Testcase Example:  '"A man, a plan, a canal: Panama"'
 *
 * 给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
 * 
 * 说明：本题中，我们将空字符串定义为有效的回文串。
 * 
 * 示例 1:
 * 
 * 输入: "A man, a plan, a canal: Panama"
 * 输出: true
 * 
 * 
 * 示例 2:
 * 
 * 输入: "race a car"
 * 输出: false
 * 
 * 
 */

// @lc code=start
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s)
    {
        int L = 0;
        int R = s.length() - 1;
        transform(s.begin(), s.end(), s.begin(), ::toupper);
        while (L < R) {
            while (L < R && !(s[L] >= 'A' && s[L] <= 'Z') && !(s[L] >= '0' && s[L] <= '9')) {
                ++L;
            }
            while (L < R && !(s[R] >= 'A' && s[R] <= 'Z') && !(s[R] >= '0' && s[R] <= '9')) {
                --R;
            }
            if (s[L] != s[R]) {
                return false;
            }
            ++L;
            --R;
        }
        return true;
    }
};
// @lc code=end
