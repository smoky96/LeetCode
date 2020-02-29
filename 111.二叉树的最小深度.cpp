/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
 *
 * https://leetcode-cn.com/problems/minimum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (39.82%)
 * Likes:    185
 * Dislikes: 0
 * Total Accepted:    42.8K
 * Total Submissions: 104.9K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，找出其最小深度。
 * 
 * 最小深度是从根节点到最近叶子节点的最短路径上的节点数量。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例:
 * 
 * 给定二叉树 [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 返回它的最小深度  2.
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
#include <climits>
class Solution {
public:
    int ans = INT_MAX;
    int minDepth(TreeNode* root)
    {
        if (root == NULL) {
            return 0;
        }
        aux(root, 1);
        return ans;
    }
    void aux(TreeNode* node, int depth)
    {
        if (depth > ans) {
            return;
        }
        // 到叶子结点
        if (node->right == NULL && node->left == NULL) {
            if (depth < ans) {
                ans = depth;
            }
            return;
        }
        if (node->left != NULL)
            aux(node->left, depth + 1);
        if (node->right != NULL)
            aux(node->right, depth + 1);
    }
};
// @lc code=end
