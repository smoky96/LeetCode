/*
 * @lc app=leetcode.cn id=179 lang=cpp
 *
 * [179] 最大数
 *
 * https://leetcode-cn.com/problems/largest-number/description/
 *
 * algorithms
 * Medium (35.63%)
 * Likes:    227
 * Dislikes: 0
 * Total Accepted:    22.5K
 * Total Submissions: 63.1K
 * Testcase Example:  '[10,2]'
 *
 * 给定一组非负整数，重新排列它们的顺序使之组成一个最大的整数。
 *
 * 示例 1:
 *
 * 输入: [10,2]
 * 输出: 210
 *
 * 示例 2:
 *
 * 输入: [3,30,34,5,9]
 * 输出: 9534330
 *
 * 说明: 输出结果可能非常大，所以你需要返回一个字符串而不是整数。
 *
 */

// @lc code=start
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
 public:
  string largestNumber(vector<int>& nums) {
    vector<string> num_str;
    bool ret = true;
    for (const auto& i : nums) {
      if (i != 0) {
        ret = false;
      }
      num_str.push_back(to_string(i));
    }
    if (ret) {
      return "0";
    }

    sort(num_str.begin(), num_str.end(),
         [&](string a, string b) { return b + a < a + b; });

    string ans;
    for (const auto& s : num_str) {
      ans += s;
    }
    return ans;
  }
};
// @lc code=end
