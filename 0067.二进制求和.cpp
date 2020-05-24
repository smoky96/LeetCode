/*
 * @lc app=leetcode.cn id=67 lang=cpp
 *
 * [67] 二进制求和
 *
 * https://leetcode-cn.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (50.05%)
 * Likes:    271
 * Dislikes: 0
 * Total Accepted:    50.9K
 * Total Submissions: 99K
 * Testcase Example:  '"11"\n"1"'
 *
 * 给定两个二进制字符串，返回他们的和（用二进制表示）。
 * 
 * 输入为非空字符串且只包含数字 1 和 0。
 * 
 * 示例 1:
 * 
 * 输入: a = "11", b = "1"
 * 输出: "100"
 * 
 * 示例 2:
 * 
 * 输入: a = "1010", b = "1011"
 * 输出: "10101"
 * 
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b)
    {
        if (a.size() < b.size()) {
            swap(a, b);
        }
        int i = 0, j = 0;
        int carry = 0;
        int tmp = 0;
        for (i = a.size() - 1, j = b.size() - 1; j >= 0; --i, --j) {
            if (a[i] ^ b[j]) {
                tmp = 1 + carry;
            } else if (a[i] == '0' && b[j] == '0') {
                tmp = carry;
            } else {
                tmp = 2 + carry;
            }
            a[i] = char('0' + (tmp % 2));
            carry = tmp / 2;
        }
        
        while (carry && i >= 0) {
            tmp = a[i] - '0' + carry;
            a[i] = char('0' + (tmp % 2));
            carry = tmp / 2;
            --i;
        }
        if (carry != 0) {
            a.insert(a.begin(), '1');
        }
        return a;
    }
};
// @lc code=end
