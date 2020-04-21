/*
 * @lc app=leetcode.cn id=1248 lang=cpp
 *
 * [1248] 统计「优美子数组」
 *
 * https://leetcode-cn.com/problems/count-number-of-nice-subarrays/description/
 *
 * algorithms
 * Medium (47.57%)
 * Likes:    79
 * Dislikes: 0
 * Total Accepted:    14.9K
 * Total Submissions: 28K
 * Testcase Example:  '[1,1,2,1,1]\n3'
 *
 * 给你一个整数数组 nums 和一个整数 k。
 *
 * 如果某个 连续 子数组中恰好有 k
 * 个奇数数字，我们就认为这个子数组是「优美子数组」。
 *
 * 请返回这个数组中「优美子数组」的数目。
 *
 *
 *
 * 示例 1：
 *
 * 输入：nums = [1,1,2,1,1], k = 3
 * 输出：2
 * 解释：包含 3 个奇数的子数组是 [1,1,2,1] 和 [1,2,1,1] 。
 *
 *
 * 示例 2：
 *
 * 输入：nums = [2,4,6], k = 1
 * 输出：0
 * 解释：数列中不包含任何奇数，所以不存在优美子数组。
 *
 *
 * 示例 3：
 *
 * 输入：nums = [2,2,2,1,2,2,1,2,2,2], k = 2
 * 输出：16
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= nums.length <= 50000
 * 1 <= nums[i] <= 10^5
 * 1 <= k <= nums.length
 *
 *
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
 public:
  int numberOfSubarrays(vector<int>& nums, int k) {
    int len = nums.size();
    if (len < k) return 0;
    int ans = 0;
    int cnt = 0;
    int i = 0, j = 0;  // i 指向开头, j 指向 the one past last

    while (j < len) {
      int r_even = 0;
      int l_even = 0;
      while (j < len && cnt < k) {
        if (nums[j] % 2) ++cnt;
        ++j;
      }
      if (cnt == k) {
        while (j < len && nums[j] % 2 == 0) {
          ++r_even;
          ++j;
        }
        while (i < len && nums[i] % 2 == 0) {
          ++l_even;
          ++i;
        }
        ans += (r_even + 1) * (l_even + 1);
        ++i;
        --cnt;
      }
    }

    return ans;
  }
};
// @lc code=end
