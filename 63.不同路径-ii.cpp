/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 *
 * https://leetcode-cn.com/problems/unique-paths-ii/description/
 *
 * algorithms
 * Medium (31.71%)
 * Likes:    190
 * Dislikes: 0
 * Total Accepted:    30.9K
 * Total Submissions: 96.7K
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为“Start” ）。
 * 
 * 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为“Finish”）。
 * 
 * 现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
 * 
 * 
 * 
 * 网格中的障碍物和空位置分别用 1 和 0 来表示。
 * 
 * 说明：m 和 n 的值均不超过 100。
 * 
 * 示例 1:
 * 
 * 输入:
 * [
 * [0,0,0],
 * [0,1,0],
 * [0,0,0]
 * ]
 * 输出: 2
 * 解释:
 * 3x3 网格的正中间有一个障碍物。
 * 从左上角到右下角一共有 2 条不同的路径：
 * 1. 向右 -> 向右 -> 向下 -> 向下
 * 2. 向下 -> 向下 -> 向右 -> 向右
 * 
 * 
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> memo(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), -1));
        return aux(0, 0, memo, obstacleGrid);
    }

    int aux(int x, int y, vector<vector<int>>& memo, const vector<vector<int>>& obstacleGrid) {
        if (obstacleGrid[x][y] == 1) {
            return 0;
        } else if (x == (obstacleGrid.size() - 1) && y == (obstacleGrid[0].size() - 1)) {
            return 1;
        }

        if (memo[x][y] != -1) {
            return memo[x][y];
        }

        int tmp1 = 0;
        int tmp2 = 0;
        if (x < obstacleGrid.size() - 1) {
            tmp1 = aux(x + 1, y, memo, obstacleGrid);
        }
        if (y < obstacleGrid[0].size() - 1) {
            tmp2 = aux(x, y + 1, memo, obstacleGrid);
        }
        memo[x][y] = tmp1 + tmp2;
        return memo[x][y];
    }
};
// @lc code=end

