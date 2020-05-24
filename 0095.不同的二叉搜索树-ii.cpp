/*
 * @lc app=leetcode.cn id=95 lang=cpp
 *
 * [95] 不同的二叉搜索树 II
 *
 * https://leetcode-cn.com/problems/unique-binary-search-trees-ii/description/
 *
 * algorithms
 * Medium (58.69%)
 * Likes:    244
 * Dislikes: 0
 * Total Accepted:    16K
 * Total Submissions: 26.4K
 * Testcase Example:  '3'
 *
 * 给定一个整数 n，生成所有由 1 ... n 为节点所组成的二叉搜索树。
 * 
 * 示例:
 * 
 * 输入: 3
 * 输出:
 * [
 * [1,null,3,2],
 * [3,2,null,1],
 * [3,1,null,null,2],
 * [2,1,3],
 * [1,null,2,null,3]
 * ]
 * 解释:
 * 以上的输出对应以下 5 种不同结构的二叉搜索树：
 * 
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <cstdlib>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

// struct TreeNode {
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(int x)
//         : val(x)
//         , left(NULL)
//         , right(NULL)
//     {
//     }
// };

class Solution {
public:
    vector<TreeNode*> generateTrees(int n)
    {
        if (n == 0) {
            return {};
        }
        vector<TreeNode*> ans;
        aux(1, n + 1, ans);
        return ans;
    }

    void aux(int start, int end, vector<TreeNode*>& nodes)
    {
        if (start == end) {
            nodes.push_back(NULL);
            return;
        }

        vector<TreeNode*> left;
        vector<TreeNode*> right;
        for (int mid = start; mid < end; ++mid) {
            left.clear();
            right.clear();
            aux(start, mid, left);
            aux(mid + 1, end, right);

            for (const auto& l : left) {
                for (const auto& r : right) {
                    TreeNode* root = new TreeNode(mid);
                    root->left = l;
                    root->right = r;
                    nodes.push_back(root);
                }
            }
        }
    }
};
// @lc code=end
