/*
 * @lc app=leetcode.cn id=56 lang=cpp
 *
 * [56] 合并区间
 *
 * https://leetcode-cn.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (37.99%)
 * Likes:    217
 * Dislikes: 0
 * Total Accepted:    39.2K
 * Total Submissions: 100K
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * 给出一个区间的集合，请合并所有重叠的区间。
 * 
 * 示例 1:
 * 
 * 输入: [[1,3],[2,6],[8,10],[15,18]]
 * 输出: [[1,6],[8,10],[15,18]]
 * 解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
 * 
 * 
 * 示例 2:
 * 
 * 输入: [[1,4],[4,5]]
 * 输出: [[1,5]]
 * 解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。
 * 
 */

// @lc code=start
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        if (intervals.size() < 2) {
            return intervals;
        }

        auto func = [](vector<int> i, vector<int> j) { return i[0] < j[0]; };
        sort(intervals.begin(), intervals.end(), func);

        vector<vector<int>> ans;

        int start = intervals[0][0];
        int end = intervals[0][1];
        for (auto it = intervals.begin() + 1; it < intervals.end(); ++it) {
            if ((*it)[0] <= end) {
                end = end > (*it)[1] ? end : (*it)[1];
                start = start < (*it)[0] ? start : (*it)[0];
            } else {
                ans.push_back({ start, end });
                start = (*it)[0];
                end = (*it)[1];
            }
        }
        ans.push_back({ start, end });
        return ans;
    }
};
// @lc code=end
