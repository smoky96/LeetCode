/*
 * @lc app=leetcode.cn id=66 lang=cpp
 *
 * [66] 加一
 *
 * https://leetcode-cn.com/problems/plus-one/description/
 *
 * algorithms
 * Easy (40.41%)
 * Likes:    377
 * Dislikes: 0
 * Total Accepted:    97.5K
 * Total Submissions: 232.4K
 * Testcase Example:  '[1,2,3]'
 *
 * 给定一个由整数组成的非空数组所表示的非负整数，在该数的基础上加一。
 * 
 * 最高位数字存放在数组的首位， 数组中每个元素只存储单个数字。
 * 
 * 你可以假设除了整数 0 之外，这个整数不会以零开头。
 * 
 * 示例 1:
 * 
 * 输入: [1,2,3]
 * 输出: [1,2,4]
 * 解释: 输入数组表示数字 123。
 * 
 * 
 * 示例 2:
 * 
 * 输入: [4,3,2,1]
 * 输出: [4,3,2,2]
 * 解释: 输入数组表示数字 4321。
 * 
 * 
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits)
    {
        if (digits.size() == 0) {
            return { 1 };
        }
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0; --i) {
            if (carry != 0) {
                digits[i] += carry;
                carry = digits[i] / 10;
                digits[i] = digits[i] % 10;
            } else {
                break;
            }
        }

        if (carry != 0) {
            digits.insert(digits.begin(), carry);
        }
        return digits;
    }
};
// @lc code=end
