/*
 * @lc app=leetcode.cn id=29 lang=cpp
 *
 * [29] 两数相除
 *
 * https://leetcode-cn.com/problems/divide-two-integers/description/
 *
 * algorithms
 * Medium (18.64%)
 * Likes:    217
 * Dislikes: 0
 * Total Accepted:    25.9K
 * Total Submissions: 138K
 * Testcase Example:  '10\n3'
 *
 * 给定两个整数，被除数 dividend 和除数 divisor。将两数相除，要求不使用乘法、除法和 mod 运算符。
 * 
 * 返回被除数 dividend 除以除数 divisor 得到的商。
 * 
 * 示例 1:
 * 
 * 输入: dividend = 10, divisor = 3
 * 输出: 3
 * 
 * 示例 2:
 * 
 * 输入: dividend = 7, divisor = -3
 * 输出: -2
 * 
 * 说明:
 * 
 * 
 * 被除数和除数均为 32 位有符号整数。
 * 除数不为 0。
 * 假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−2^31,  2^31 − 1]。本题中，如果除法结果溢出，则返回 2^31 − 1。
 * 
 * 
 */

// @lc code=start
#include <algorithm>
#include <bitset>
#include <climits>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor)
    {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        if (dividend == 0) {
            return 0;
        }
        if (divisor == 1) {
            return dividend;
        }
        if (divisor == -1) {
            return -dividend;
        }

        bool negative = false;
        if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) {
            negative = true;
        }

        bool overflow = false;
        int ret = 0;

        if (dividend == INT_MIN) {
            if (divisor == INT_MIN) {
                return 1;
            }
            dividend += abs(divisor);
            ++ret;
        } else if (divisor == INT_MIN) {
            return 0;
        }

        divisor = abs(divisor);
        dividend = abs(dividend);
        while ((dividend = dividend - divisor) >= 0) {
            ++ret;
        }
        if (negative) {
            return -ret;
        } else {
            return ret;
        }
    }
};
/* class Solution {
public:
    int divide(int dividend, int divisor)
    {
        if (divisor == 1) {
            return dividend;
        }
        if (divisor == -1) {
            return -dividend;
        }
        if (dividend == 0) {
            return 0;
        }
        if (dividend == divisor) {
            return 1;
        }
        if (divisor == INT_MIN) {
            return 0;
        }
        
        bitset<33> dividend_bit = dividend;
        bitset<33> divisor_bit = divisor;

        if ((((dividend & INT_MIN) ^ (divisor & INT_MIN)) >> 31) & 1) {
            dividend = add(dividend, divisor);
        } else {
            dividend = add(dividend, -divisor);
        }
        int count = 32;
        int ret = 0;

        while (--count) {
            if ( ^ (((divisor & INT_MIN) >> 31) & 1)) {
                ret |= 0;
                ret = ret << 1;
                dividend = dividend << 1;
                dividend = add(dividend, divisor);
            } else {
                ret |= 1;
                ret = ret << 1;
                dividend = dividend << 1;
                dividend = add(dividend, -divisor);
            }
        }

        return ret >> 1;
    }

    int add(int a, int b)
    {
        int result = 0;
        int carry = 0;
        do {
            result = a ^ b;
            carry = (a & b) << 1;
            a = result;
            b = carry;
        } while (carry != 0);

        return a;
    }
};

int stringToInteger(string input)
{
    return stoi(input);
}

int main()
{
    string line;
    while (getline(cin, line)) {
        int dividend = stringToInteger(line);
        getline(cin, line);
        int divisor = stringToInteger(line);

        int ret = Solution().divide(dividend, divisor);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
} */
// @lc code=end
