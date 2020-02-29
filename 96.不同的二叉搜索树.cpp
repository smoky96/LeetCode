/*
 * @lc app=leetcode.cn id=96 lang=cpp
 *
 * [96] 不同的二叉搜索树
 *
 * https://leetcode-cn.com/problems/unique-binary-search-trees/description/
 *
 * algorithms
 * Medium (61.82%)
 * Likes:    341
 * Dislikes: 0
 * Total Accepted:    23.4K
 * Total Submissions: 36.7K
 * Testcase Example:  '3'
 *
 * 给定一个整数 n，求以 1 ... n 为节点组成的二叉搜索树有多少种？
 * 
 * 示例:
 * 
 * 输入: 3
 * 输出: 5
 * 解释:
 * 给定 n = 3, 一共有 5 种不同结构的二叉搜索树:
 * 
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
 * 
 */

// @lc code=start
#include <map>
using namespace std;

class Solution {
public:
    int numTrees(int n)
    {
        if (n == 0) {
            return 0;
        }
        map<pair<int, int>, int> mem;
        return aux(1, n + 1, mem);
    }

    int aux(int start, int end, map<pair<int, int>, int>& mem)
    {
        if (mem.find(make_pair(start, end)) != mem.end()) {
            return mem[make_pair(start, end)];
        }
        if (start == end) {
            return 1;
        }
        int sum = 0;
        int left, right;
        for (int mid = start; mid < end; ++mid) {
            left = aux(start, mid, mem);
            right = aux(mid + 1, end, mem);

            sum += left * right;
        }
        mem[make_pair(start, end)] = sum;
        return sum;
    }
};
// @lc code=end
