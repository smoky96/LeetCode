/*
 * @lc app=leetcode.cn id=220 lang=cpp
 *
 * [220] 存在重复元素 III
 *
 * https://leetcode-cn.com/problems/contains-duplicate-iii/description/
 *
 * algorithms
 * Medium (28.84%)
 * Likes:    569
 * Dislikes: 0
 * Total Accepted:    73.1K
 * Total Submissions: 253.7K
 * Testcase Example:  '[1,2,3,1]\n3\n0'
 *
 * 给你一个整数数组 nums 和两个整数 k 和 t 。请你判断是否存在 两个不同下标 i 和 j，使得 abs(nums[i] - nums[j])
 * ，同时又满足 abs(i - j)  。
 * 
 * 如果存在则返回 true，不存在返回 false。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：nums = [1,2,3,1], k = 3, t = 0
 * 输出：true
 * 
 * 示例 2：
 * 
 * 
 * 输入：nums = [1,0,1,1], k = 1, t = 2
 * 输出：true
 * 
 * 示例 3：
 * 
 * 
 * 输入：nums = [1,5,9,1,5,9], k = 2, t = 3
 * 输出：false
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 0 
 * -2^31 
 * 0 
 * 0 
 * 
 * 
 */

// @lc code=start
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    inline long abs(long x) {
        return x < 0 ? -x : x;
    }

    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (nums.size() < 2) {
            return false;
        }

        set<long> nums_set;
        for (int i = 0; i < nums.size(); ++i) {
            auto lb_it = nums_set.lower_bound(long(nums[i]) - long(t));
            if (lb_it != nums_set.end() && *lb_it <= long(nums[i]) + long(t))  {
                return true;
            }
            nums_set.insert(nums[i]);
            if (nums_set.size() > k) {
                nums_set.erase(nums[i - k]);
            }
        }

        return false;
    }
};
// @lc code=end

