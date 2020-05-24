/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 *
 * https://leetcode-cn.com/problems/3sum/description/
 *
 * algorithms
 * Medium (23.69%)
 * Likes:    1511
 * Dislikes: 0
 * Total Accepted:    116.4K
 * Total Submissions: 476.9K
 * Testcase Example:  '[-1,0,1,2,-1,-4]'
 *
 * 给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0
 * ？找出所有满足条件且不重复的三元组。
 * 
 * 注意：答案中不可以包含重复的三元组。
 * 
 * 例如, 给定数组 nums = [-1, 0, 1, 2, -1, -4]，
 * 
 * 满足要求的三元组集合为：
 * [
 * ⁠ [-1, 0, 1],
 * ⁠ [-1, -1, 2]
 * ]
 * 
 * 
 */

// @lc code=start
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        map<int, int> hash;
        vector<vector<int>> res;
        vector<int> triple = { 0, 0, 0 };
        sort(nums.begin(), nums.end());
        if (nums.size() < 3 || nums[0] > 0 || nums[nums.size() - 1] < 0) {
            return res;
        }
        int L = 0;
        int R = 0;
        int tmp = 0;

        for (int i = 0; i < nums.size(); i++) {
            L = i + 1;
            R = nums.size() - 1;
            if (nums[i] > 0)
                break;
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            while (L < R) {
                tmp = nums[i] + nums[L] + nums[R];
                if (tmp < 0) {
                    L += 1;
                    while (L < R && nums[L] == nums[L - 1])
                        L += 1;
                } else if (tmp > 0) {
                    R -= 1;
                    while (L < R && nums[R] == nums[R + 1])
                        R -= 1;
                } else {
                    triple[0] = nums[i];
                    triple[1] = nums[L];
                    triple[2] = nums[R];
                    res.push_back(triple);
                    R -= 1;
                    L += 1;
                    while (L < R && nums[R] == nums[R + 1]) {
                        R -= 1;
                    }
                    while (L < R && nums[L] == nums[L = 1]) {
                        L += 1;
                    }
                }
            }
        }
        return res;
    }
};
// @lc code=end
