/*
 * @lc app=leetcode.cn id=85 lang=cpp
 *
 * [85] 最大矩形
 *
 * https://leetcode-cn.com/problems/maximal-rectangle/description/
 *
 * algorithms
 * Hard (43.65%)
 * Likes:    253
 * Dislikes: 0
 * Total Accepted:    13.4K
 * Total Submissions: 31.1K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * 给定一个仅包含 0 和 1 的二维二进制矩阵，找出只包含 1 的最大矩形，并返回其面积。
 * 
 * 示例:
 * 
 * 输入:
 * [
 * ⁠ ["1","0","1","0","0"],
 * ⁠ ["1","0","1","1","1"],
 * ⁠ ["1","1","1","1","1"],
 * ⁠ ["1","0","0","1","0"]
 * ]
 * 输出: 6
 * 
 */

// @lc code=start
#include <stack>
#include <vector>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix)
    {
        if (matrix.size() == 0) {
            return 0;
        }
        int tmp = 0;
        int ans = 0;
        vector<int> height(matrix[0].size(), 0);
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                if (matrix[i][j] == '1') {
                    ++height[j];
                } else {
                    height[j] = 0;
                }
            }
            tmp = area(height);
            if (tmp > ans) {
                ans = tmp;
            }
        }
        return ans;
    }

    int area(vector<int> height)
    {
        stack<int> pos;
        pos.push(-1);
        int p = 0;
        int h = 0;
        int tmp = 0;
        int ans = 0;
        for (p = 0; p < height.size(); ++p) {
            while (pos.top() != -1 && height[p] < height[pos.top()]) {
                h = height[pos.top()];
                pos.pop();
                tmp = (p - pos.top() - 1) * h;
                if (tmp > ans) {
                    ans = tmp;
                }
            }
            pos.push(p);
        }

        while (pos.top() != -1) {
            h = height[pos.top()];
            pos.pop();
            tmp = (height.size() - pos.top() - 1) * h;
            if (tmp > ans) {
                ans = tmp;
            }
        }
        return ans;
    }
};
// @lc code=end
