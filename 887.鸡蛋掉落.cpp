/*
 * @lc app=leetcode.cn id=887 lang=cpp
 *
 * [887] 鸡蛋掉落
 *
 * https://leetcode-cn.com/problems/super-egg-drop/description/
 *
 * algorithms
 * Hard (21.49%)
 * Likes:    252
 * Dislikes: 0
 * Total Accepted:    11.7K
 * Total Submissions: 49.6K
 * Testcase Example:  '1\n2'
 *
 * 你将获得 K 个鸡蛋，并可以使用一栋从 1 到 N  共有 N 层楼的建筑。
 *
 * 每个蛋的功能都是一样的，如果一个蛋碎了，你就不能再把它掉下去。
 *
 * 你知道存在楼层 F ，满足 0 <= F <= N 任何从高于
 * F 的楼层落下的鸡蛋都会碎，从 F 楼层或比它低的楼层落下的鸡蛋都不会破。
 *
 * 每次移动，你可以取一个鸡蛋（如果你有完整的鸡蛋）并把它从任一楼层 X 扔下（满足 1
 * <= X <= N）。
 *
 * 你的目标是确切地知道 F 的值是多少。
 *
 * 无论 F 的初始值如何，你确定 F 的值的最小移动次数是多少？
 *
 *
 *
 *
 *
 *
 * 示例 1：
 *
 * 输入：K = 1, N = 2
 * 输出：2
 * 解释：
 * 鸡蛋从 1 楼掉落。如果它碎了，我们肯定知道 F = 0 。
 * 否则，鸡蛋从 2 楼掉落。如果它碎了，我们肯定知道 F = 1 。
 * 如果它没碎，那么我们肯定知道 F = 2 。
 * 因此，在最坏的情况下我们需要移动 2 次以确定 F 是多少。
 *
 *
 * 示例 2：
 *
 * 输入：K = 2, N = 6
 * 输出：3
 *
 *
 * 示例 3：
 *
 * 输入：K = 3, N = 14
 * 输出：4
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= K <= 100
 * 1 <= N <= 10000
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
  int superEggDrop(int K, int N) {
    vector<vector<int>> mem(K + 1, vector<int>(N + 1, -1));
    return aux(mem, K, N);
  }

  int aux(vector<vector<int>>& mem, int k, int n) {
    if (mem[k][n] != -1) return mem[k][n];

    int ans;
    if (n == 0)
      ans = 0;
    else if (k == 1)
      ans = n;
    else {
      int low = 1;
      int high = n;
      while ((low + 1) < high) {
        int mid = (low + high) / 2;
        int break_cnt = aux(mem, k - 1, mid - 1);
        int int_cnt = aux(mem, k, n - mid);

        if (break_cnt < int_cnt)
          low = mid;
        else if (break_cnt > int_cnt)
          high = mid;
        else
          low = high = mid;
      }
      ans = min(max(aux(mem, k - 1, low - 1), aux(mem, k, n - low)),
                max(aux(mem, k - 1, high - 1), aux(mem, k, n - high))) +
            1;
    }
    mem[k][n] = ans;
    return ans;
  }
};
// @lc code=end
