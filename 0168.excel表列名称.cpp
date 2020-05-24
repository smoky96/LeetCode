/*
 * @lc app=leetcode.cn id=168 lang=cpp
 *
 * [168] Excel表列名称
 *
 * https://leetcode-cn.com/problems/excel-sheet-column-title/description/
 *
 * algorithms
 * Easy (36.63%)
 * Likes:    180
 * Dislikes: 0
 * Total Accepted:    20.1K
 * Total Submissions: 54.7K
 * Testcase Example:  '1'
 *
 * 给定一个正整数，返回它在 Excel 表中相对应的列名称。
 *
 * 例如，
 *
 * ⁠   1 -> A
 * ⁠   2 -> B
 * ⁠   3 -> C
 * ⁠   ...
 * ⁠   26 -> Z
 * ⁠   27 -> AA
 * ⁠   28 -> AB
 * ⁠   ...
 *
 *
 * 示例 1:
 *
 * 输入: 1
 * 输出: "A"
 *
 *
 * 示例 2:
 *
 * 输入: 28
 * 输出: "AB"
 *
 *
 * 示例 3:
 *
 * 输入: 701
 * 输出: "ZY"
 *
 *
 */

// @lc code=start
#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
 public:
  string convertToTitle(int n) {
    string ans;
    int remain;
    while (n) {
      remain = (n - 1) % 26;
      ans.push_back('A' + remain);
      n = (n - 1) / 26;
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};
// @lc code=end
