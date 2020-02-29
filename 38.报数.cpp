/*
 * @lc app=leetcode.cn id=38 lang=cpp
 *
 * [38] 报数
 *
 * https://leetcode-cn.com/problems/count-and-say/description/
 *
 * algorithms
 * Easy (52.04%)
 * Likes:    337
 * Dislikes: 0
 * Total Accepted:    57.9K
 * Total Submissions: 108.8K
 * Testcase Example:  '1'
 *
 * 报数序列是一个整数序列，按照其中的整数的顺序进行报数，得到下一个数。其前五项如下：
 * 
 * 1.     1
 * 2.     11
 * 3.     21
 * 4.     1211
 * 5.     111221
 * 
 * 
 * 1 被读作  "one 1"  ("一个一") , 即 11。
 * 11 被读作 "two 1s" ("两个一"）, 即 21。
 * 21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。
 * 
 * 给定一个正整数 n（1 ≤ n ≤ 30），输出报数序列的第 n 项。
 * 
 * 注意：整数顺序将表示为一个字符串。
 * 
 * 
 * 
 * 示例 1:
 * 
 * 输入: 1
 * 输出: "1"
 * 
 * 
 * 示例 2:
 * 
 * 输入: 4
 * 输出: "1211"
 * 
 * 
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n)
    {
        return countNext("1", n - 1);
    }

    string countNext(string s, int n)
    {
        if (n == 0) {
            return s;
        }
        char cur_c = s[0];
        int count = 1;
        string ret;
        for (auto it = (s.begin() + 1); it <= s.end(); ++it) {
            if (it != s.end() && *it == cur_c) {
                ++count;
            } else {
                ret += char('0' + count);
                ret += *(it - 1);
                if (it != s.end()) {
                    cur_c = *it;
                    count = 1;
                }
            }
        }
        return countNext(ret, n - 1);
    }
};
// @lc code=end
