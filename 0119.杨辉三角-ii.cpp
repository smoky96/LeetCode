/*
 * @lc app=leetcode.cn id=119 lang=cpp
 *
 * [119] 杨辉三角 II
 *
 * https://leetcode-cn.com/problems/pascals-triangle-ii/description/
 *
 * algorithms
 * Easy (57.47%)
 * Likes:    104
 * Dislikes: 0
 * Total Accepted:    33.5K
 * Total Submissions: 56.5K
 * Testcase Example:  '3'
 *
 * 给定一个非负索引 k，其中 k ≤ 33，返回杨辉三角的第 k 行。
 * 
 * 
 * 
 * 在杨辉三角中，每个数是它左上方和右上方的数的和。
 * 
 * 示例:
 * 
 * 输入: 3
 * 输出: [1,3,3,1]
 * 
 * 
 * 进阶：
 * 
 * 你可以优化你的算法到 O(k) 空间复杂度吗？
 * 
 */

// @lc code=start
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> getRow(int rowIndex)
    {
        vector<int> pre = { 1 };
        vector<int> cur = pre;
        for (int i = 1; i <= rowIndex; ++i) {
            cur.clear();
            cur.push_back(1);
            for (int j = 0; j < pre.size() - 1; ++j) {
                cur.push_back(pre[j] + pre[j + 1]);
            }
            cur.push_back(1);
            pre = cur;
        }
        return cur;
    }
};
// @lc code=end
