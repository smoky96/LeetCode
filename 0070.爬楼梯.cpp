/*
 * @lc app=leetcode.cn id=70 lang=cpp
 *
 * [70] 爬楼梯
 *
 * https://leetcode-cn.com/problems/climbing-stairs/description/
 *
 * algorithms
 * Easy (46.51%)
 * Likes:    732
 * Dislikes: 0
 * Total Accepted:    108K
 * Total Submissions: 228.2K
 * Testcase Example:  '2'
 *
 * 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
 * 
 * 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
 * 
 * 注意：给定 n 是一个正整数。
 * 
 * 示例 1：
 * 
 * 输入： 2
 * 输出： 2
 * 解释： 有两种方法可以爬到楼顶。
 * 1.  1 阶 + 1 阶
 * 2.  2 阶
 * 
 * 示例 2：
 * 
 * 输入： 3
 * 输出： 3
 * 解释： 有三种方法可以爬到楼顶。
 * 1.  1 阶 + 1 阶 + 1 阶
 * 2.  1 阶 + 2 阶
 * 3.  2 阶 + 1 阶
 * 
 * 
 */

// @lc code=start
#include <vector>
using namespace std;

class Solution {
public:
    int climbStairs(int n)
    {
        vector<int> memo(n, -1);
        return aux(0, n, memo);
    }

    int aux(int cur, int n, vector<int>& memo)
    {
        if (cur == n) {
            return 1;
        }
        if (memo[cur] != -1) {
            return memo[cur];
        }

        int tmp1 = 0, tmp2 = 0;
        if ((n - cur) > 1) {
            tmp1 = aux(cur + 2, n, memo);
        }
        tmp2 = aux(cur + 1, n, memo);
        memo[cur] = tmp1 + tmp2;
        return memo[cur];
    }
};
// @lc code=end
