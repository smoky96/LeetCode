/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
 *
 * https://leetcode-cn.com/problems/path-sum/description/
 *
 * algorithms
 * Easy (47.53%)
 * Likes:    212
 * Dislikes: 0
 * Total Accepted:    43K
 * Total Submissions: 88.7K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,null,1]\n22'
 *
 * 给定一个二叉树和一个目标和，判断该树中是否存在根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例: 
 * 给定如下二叉树，以及目标和 sum = 22，
 * 
 * ⁠             5
 * ⁠            / \
 * ⁠           4   8
 * ⁠          /   / \
 * ⁠         11  13  4
 * ⁠        /  \      \
 * ⁠       7    2      1
 * 
 * 
 * 返回 true, 因为存在目标和为 22 的根节点到叶子节点的路径 5->4->11->2。
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

class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum)
    {
        if (root == NULL) {
            return false;
        }
        return aux(root, root->val, sum);
    }

    bool aux(TreeNode* node, int sum, const int& target)
    {
        if (node->left == NULL && node->right == NULL && sum == target) {
            return true;
        }
        bool tmp1 = false;
        bool tmp2 = false;
        if (node->left != NULL) {
            tmp1 = aux(node->left, sum + node->left->val, target);
        }
        if (node->right != NULL) {
            tmp2 = aux(node->right, sum + node->right->val, target);
        }
        return tmp1 || tmp2;
    }
};
// @lc code=end
