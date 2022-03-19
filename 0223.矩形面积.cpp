/*
 * @lc app=leetcode.cn id=223 lang=cpp
 *
 * [223] 矩形面积
 *
 * https://leetcode-cn.com/problems/rectangle-area/description/
 *
 * algorithms
 * Medium (52.74%)
 * Likes:    177
 * Dislikes: 0
 * Total Accepted:    45.4K
 * Total Submissions: 86.1K
 * Testcase Example:  '-3\n0\n3\n4\n0\n-1\n9\n2'
 *
 * 给你 二维 平面上两个 由直线构成且边与坐标轴平行/垂直 的矩形，请你计算并返回两个矩形覆盖的总面积。
 * 
 * 每个矩形由其 左下 顶点和 右上 顶点坐标表示：
 * 
 * 
 * 
 * 第一个矩形由其左下顶点 (ax1, ay1) 和右上顶点 (ax2, ay2) 定义。
 * 第二个矩形由其左下顶点 (bx1, by1) 和右上顶点 (bx2, by2) 定义。
 * 
 * 
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：ax1 = -3, ay1 = 0, ax2 = 3, ay2 = 4, bx1 = 0, by1 = -1, bx2 = 9, by2 = 2
 * 输出：45
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：ax1 = -2, ay1 = -2, ax2 = 2, ay2 = 2, bx1 = -2, by1 = -2, bx2 = 2, by2 =
 * 2
 * 输出：16
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * -10^4 <= ax1, ay1, ax2, ay2, bx1, by1, bx2, by2 <= 10^4
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    inline int max(int a, int b) {
        return a >= b ? a : b;
    }

    inline int min(int a, int b) {
        return a <= b ? a : b;
    }

    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        int ovl_w = max(min(ax2, bx2) - max(ax1, bx1), 0);
        int ovl_h = max(min(ay2, by2) - max(ay1, by1), 0);

        return (ax2 - ax1) * (ay2 - ay1) + (bx2 - bx1) * (by2 - by1) - max(min(ax2, bx2) - max(ax1, bx1), 0) * max(min(ay2, by2) - max(ay1, by1), 0);
    }
};
// @lc code=end

