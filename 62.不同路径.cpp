/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 *
 * https://leetcode-cn.com/problems/unique-paths/description/
 *
 * algorithms
 * Medium (55.59%)
 * Likes:    356
 * Dislikes: 0
 * Total Accepted:    54.6K
 * Total Submissions: 94.8K
 * Testcase Example:  '3\n2'
 *
 * 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
 * 
 * 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
 * 
 * 问总共有多少条不同的路径？
 * 
 * 
 * 
 * 例如，上图是一个7 x 3 的网格。有多少可能的路径？
 * 
 * 说明：m 和 n 的值均不超过 100。
 * 
 * 示例 1:
 * 
 * 输入: m = 3, n = 2
 * 输出: 3
 * 解释:
 * 从左上角开始，总共有 3 条路径可以到达右下角。
 * 1. 向右 -> 向右 -> 向下
 * 2. 向右 -> 向下 -> 向右
 * 3. 向下 -> 向右 -> 向右
 * 
 * 
 * 示例 2:
 * 
 * 输入: m = 7, n = 3
 * 输出: 28
 * 
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n)
    {
        vector<vector<int>> memo(m, vector<int>(n, -1));
        return aux(0, 0, m, n, memo);
    }

    int aux(int x, int y, int m, int n, vector<vector<int>>& memo)
    {
        if (x == (m - 1) && y == (n - 1)) {
            return 1;
        }

        if (memo[x][y] != -1) {
            return memo[x][y];
        }

        int tmp1 = 0;
        int tmp2 = 0;
        if (x < m - 1) {
            tmp1 = aux(x + 1, y, m, n, memo);
        }
        if (y < n - 1) {
            tmp2 = aux(x, y + 1, m, n, memo);
        }
        memo[x][y] = tmp1 + tmp2;
        return memo[x][y];
    }
};
// @lc code=end
