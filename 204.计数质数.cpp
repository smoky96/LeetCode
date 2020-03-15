/*
 * @lc app=leetcode.cn id=204 lang=cpp
 *
 * [204] 计数质数
 *
 * https://leetcode-cn.com/problems/count-primes/description/
 *
 * algorithms
 * Easy (32.61%)
 * Likes:    303
 * Dislikes: 0
 * Total Accepted:    46.4K
 * Total Submissions: 141.9K
 * Testcase Example:  '10'
 *
 * 统计所有小于非负整数 n 的质数的数量。
 *
 * 示例:
 *
 * 输入: 10
 * 输出: 4
 * 解释: 小于 10 的质数一共有 4 个, 它们是 2, 3, 5, 7 。
 *
 *
 */

// @lc code=start

class Solution {
 public:
  int countPrimes(int n) {
    if (n < 3) return 0;

    bool set[n];
    for (int i = 0; i < n; ++i) {
      set[i] = true;
    }

    for (int i = 2; i * i < n; ++i) {
      if (set[i]) {
        for (int j = i * i; j < n; j += i) {
          set[j] = false;
        }
      }
    }
    int cnt = 0;
    for (int i = 2; i < n; ++i) {
      if (set[i]) ++cnt;
    }
    return cnt;
  }
};
// @lc code=end
