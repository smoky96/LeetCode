/*
 * @lc app=leetcode.cn id=58 lang=cpp
 *
 * [58] 最后一个单词的长度
 *
 * https://leetcode-cn.com/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (30.80%)
 * Likes:    147
 * Dislikes: 0
 * Total Accepted:    53.9K
 * Total Submissions: 170.9K
 * Testcase Example:  '"Hello World"'
 *
 * 给定一个仅包含大小写字母和空格 ' ' 的字符串，返回其最后一个单词的长度。
 * 
 * 如果不存在最后一个单词，请返回 0 。
 * 
 * 说明：一个单词是指由字母组成，但不包含任何空格的字符串。
 * 
 * 示例:
 * 
 * 输入: "Hello World"
 * 输出: 5
 * 
 * 
 */

// @lc code=start
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s)
    {
        if (s.size() == 0) {
            return 0;
        }
        int len = 0;
        bool begin = true;
        for (auto it = s.end() - 1; it >= s.begin(); --it) {
            if (*it == ' ') {
                if (begin) {
                    continue;
                } else {
                    break;
                }
            } else {
                begin = false;
                ++len;
            }
        }
        return len;
    }
};
// @lc code=end
