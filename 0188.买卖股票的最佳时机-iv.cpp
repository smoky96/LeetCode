/*
 * @lc app=leetcode.cn id=188 lang=cpp
 *
 * [188] 买卖股票的最佳时机 IV
 *
 * https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv/description/
 *
 * algorithms
 * Hard (29.28%)
 * Likes:    162
 * Dislikes: 0
 * Total Accepted:    12.4K
 * Total Submissions: 42.4K
 * Testcase Example:  '2\n[2,4,1]'
 *
 * 给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。
 *
 * 设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。
 *
 * 注意: 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 *
 * 示例 1:
 *
 * 输入: [2,4,1], k = 2
 * 输出: 2
 * 解释: 在第 1 天 (股票价格 = 2) 的时候买入，在第 2 天 (股票价格 = 4)
 * 的时候卖出，这笔交易所能获得利润 = 4-2 = 2 。
 *
 *
 * 示例 2:
 *
 * 输入: [3,2,6,5,0,3], k = 2
 * 输出: 7
 * 解释: 在第 2 天 (股票价格 = 2) 的时候买入，在第 3 天 (股票价格 = 6)
 * 的时候卖出, 这笔交易所能获得利润 = 6-2 = 4 。 随后，在第 5 天 (股票价格 = 0)
 * 的时候买入，在第 6 天 (股票价格 = 3) 的时候卖出, 这笔交易所能获得利润 = 3-0 =
 * 3 。
 *
 *
 */

// @lc code=start
#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

class Solution {
 public:
  int maxProfitInf(vector<int>& prices) {
    int n = prices.size();

    int dp_i_0 = 0;
    int dp_i_1 = INT_MIN;
    for (int i = 0; i < n; ++i) {
      int tmp = dp_i_0;
      dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
      dp_i_1 = max(dp_i_1, tmp - prices[i]);
    }
    return dp_i_0;
  }

  int maxProfit(int k, vector<int>& prices) {
    if (k == 0) {
      return 0;
    }
    int n = prices.size();
    if (k > n / 2) {
      return maxProfitInf(prices);
    }

    int dp[k + 1][2];

    for (int i = 0; i < n; ++i) {
      dp[0][0] = 0;
      dp[0][1] = INT_MIN;
      for (int j = k; j > 0; --j) {
        if (i == 0) {
          dp[j][0] = 0;
          dp[j][1] = -prices[i];
          continue;
        }
        dp[j][0] = max(dp[j][0], dp[j][1] + prices[i]);
        dp[j][1] = max(dp[j][1], dp[j - 1][0] - prices[i]);
      }
    }
    return dp[k][0];
  }
};
// @lc code=end
