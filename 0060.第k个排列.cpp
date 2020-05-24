/*
 * @lc app=leetcode.cn id=60 lang=cpp
 *
 * [60] 第k个排列
 *
 * https://leetcode-cn.com/problems/permutation-sequence/description/
 *
 * algorithms
 * Medium (46.66%)
 * Likes:    142
 * Dislikes: 0
 * Total Accepted:    17.9K
 * Total Submissions: 37.8K
 * Testcase Example:  '3\n3'
 *
 * 给出集合 [1,2,3,…,n]，其所有元素共有 n! 种排列。
 * 
 * 按大小顺序列出所有排列情况，并一一标记，当 n = 3 时, 所有排列如下：
 * 
 * 
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 * 
 * 
 * 给定 n 和 k，返回第 k 个排列。
 * 
 * 说明：
 * 
 * 
 * 给定 n 的范围是 [1, 9]。
 * 给定 k 的范围是[1,  n!]。
 * 
 * 
 * 示例 1:
 * 
 * 输入: n = 3, k = 3
 * 输出: "213"
 * 
 * 
 * 示例 2:
 * 
 * 输入: n = 4, k = 9
 * 输出: "2314"
 * 
 * 
 */

// @lc code=start
#include <map>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k)
    {
        string res;
        int count = 0;
        int left = k;
        vector<bool> used(n, false);
        aux(n, k, left, res, 0, count, used);
        return res;
    }

    int fact(int n)
    {
        int res = 1;
        for (int i = 2; i <= n; i++) {
            res *= i;
        }
        return res;
    }

    void aux(const int& n, const int& k, int left, string& res, int len, int& count, vector<bool>& used)
    {
        if (len == n) {
            ++count;
            return;
        }

        int tmp = fact(n - len - 1);

        for (int i = 1; i <= n; ++i) {
            if (count + tmp < left) {
                count += tmp;
                continue;
            }

            if (used[i - 1]) {
                continue;
            }
            used[i - 1] = true;
            aux(n, k, left - tmp, res, len + 1, count, used);
            if (count == k) {
                res = char('0' + i) + res;
                return;
            }
            used[i - 1] = false;
        }
    }
};
// @lc code=end
