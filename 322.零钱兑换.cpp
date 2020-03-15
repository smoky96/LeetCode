/*
 * @lc app=leetcode.cn id=322 lang=cpp
 *
 * [322] 零钱兑换
 *
 * https://leetcode-cn.com/problems/coin-change/description/
 *
 * algorithms
 * Medium (37.94%)
 * Likes:    457
 * Dislikes: 0
 * Total Accepted:    56.2K
 * Total Submissions: 147.4K
 * Testcase Example:  '[1,2,5]\n11'
 *
 * 给定不同面额的硬币 coins 和一个总金额
 * amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。
 *
 * 示例 1:
 *
 * 输入: coins = [1, 2, 5], amount = 11
 * 输出: 3
 * 解释: 11 = 5 + 5 + 1
 *
 * 示例 2:
 *
 * 输入: coins = [2], amount = 3
 * 输出: -1
 *
 * 说明:
 * 你可以认为每种硬币的数量是无限的。
 *
 */

// @lc code=start
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

class Solution {
 public:
  int ans = INT_MAX;
  int coinChange(vector<int>& coins, int amount) {
    if (amount == 0) {
      return 0;
    }
    sort(coins.rbegin(), coins.rend());
    aux(coins, 0, amount, 0);
    return ans == INT_MAX ? -1 : ans;
  }

  void aux(const vector<int>& coins, int i, int amount, int cnt) {
    if (amount == 0) {
      if (cnt < ans) {
        ans = cnt;
      }
      return;
    }

    if (i == coins.size()) {
      return;
    }

    for (int k = amount / coins[i]; k >= 0 && k + cnt < ans; --k) {
      aux(coins, i + 1, amount - k * coins[i], cnt + k);
    }
  }
};
// @lc code=end
