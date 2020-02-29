/*
 * @lc app=leetcode.cn id=84 lang=cpp
 *
 * [84] 柱状图中最大的矩形
 *
 * https://leetcode-cn.com/problems/largest-rectangle-in-histogram/description/
 *
 * algorithms
 * Hard (37.58%)
 * Likes:    340
 * Dislikes: 0
 * Total Accepted:    20.4K
 * Total Submissions: 54.3K
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * 给定 n 个非负整数，用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。
 * 
 * 求在该柱状图中，能够勾勒出来的矩形的最大面积。
 * 
 * 
 * 
 * 
 * 
 * 以上是柱状图的示例，其中每个柱子的宽度为 1，给定的高度为 [2,1,5,6,2,3]。
 * 
 * 
 * 
 * 
 * 
 * 图中阴影部分为所能勾勒出的最大矩形面积，其面积为 10 个单位。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入: [2,1,5,6,2,3]
 * 输出: 10
 * 
 */

// @lc code=start
#include <climits>
#include <vector>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights)
    {
        if (heights.size() == 0) {
            return 0;
        }

        int pre_low = 0;
        int tmp = 0;
        int ans = 0;
        for (int i = 0; i < heights.size(); ++i) {
            pre_low = heights[i];
            for (int j = i; j < heights.size(); ++j) {
                pre_low = pre_low < heights[j] ? pre_low : heights[j];
                tmp = (j - i + 1) * pre_low;
                if (tmp > ans) {
                    ans = tmp;
                }
            }
        }
        return ans;
    }
};
// @lc code=end
