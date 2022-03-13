/*
 * @lc app=leetcode.cn id=219 lang=cpp
 *
 * [219] 存在重复元素 II
 *
 * https://leetcode-cn.com/problems/contains-duplicate-ii/description/
 *
 * algorithms
 * Easy (44.44%)
 * Likes:    454
 * Dislikes: 0
 * Total Accepted:    166.5K
 * Total Submissions: 374.6K
 * Testcase Example:  '[1,2,3,1]\n3'
 *
 * 给你一个整数数组 nums 和一个整数 k ，判断数组中是否存在两个 不同的索引 i 和 j ，满足 nums[i] == nums[j] 且
 * abs(i - j) <= k 。如果存在，返回 true ；否则，返回 false 。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,3,1], k = 3
 * 输出：true
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,0,1,1], k = 1
 * 输出：true
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [1,2,3,1,2,3], k = 2
 * 输出：false
 * 
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= nums.length <= 10^5
 * -10^9 <= nums[i] <= 10^9
 * 0 <= k <= 10^5
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> idx_map;
        for (int i = 0 ; i < nums.size(); ++i) {
            if (idx_map.count(nums[i]) > 0) {
                if ((i - idx_map[nums[i]]) <= k) {
                    return true;
                }
            }
            idx_map[nums[i]] = i;
        }
        return false;
    }
};
// @lc code=end

