/*
 * @lc app=leetcode.cn id=113 lang=cpp
 *
 * [113] 路径总和 II
 *
 * https://leetcode-cn.com/problems/path-sum-ii/description/
 *
 * algorithms
 * Medium (56.90%)
 * Likes:    147
 * Dislikes: 0
 * Total Accepted:    24.8K
 * Total Submissions: 42.9K
 * Testcase Example:  '[5,4,8,11,null,13,4,7,2,null,null,5,1]\n22'
 *
 * 给定一个二叉树和一个目标和，找到所有从根节点到叶子节点路径总和等于给定目标和的路径。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例:
 * 给定如下二叉树，以及目标和 sum = 22，
 * 
 * ⁠             5
 * ⁠            / \
 * ⁠           4   8
 * ⁠          /   / \
 * ⁠         11  13  4
 * ⁠        /  \    / \
 * ⁠       7    2  5   1
 * 
 * 
 * 返回:
 * 
 * [
 * ⁠  [5,4,11,2],
 * ⁠  [5,8,4,5]
 * ]
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

#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum)
    {
        if (root == NULL) {
            return {};
        }
        vector<int> tmp;
        vector<vector<int>> ans;
        tmp.push_back(root->val);
        aux(root, sum, root->val, ans, tmp);
        return ans;
    }

    void aux(TreeNode* node, const int& target, int sum, vector<vector<int>>& ans, vector<int> tmp)
    {
        if (node->left == NULL && node->right == NULL && sum == target) {
            ans.push_back(tmp);
            return;
        }
        if (node->left != NULL) {
            tmp.push_back(node->left->val);
            aux(node->left, target, sum + node->left->val, ans, tmp);
            tmp.pop_back();
        }
        if (node->right != NULL) {
            tmp.push_back(node->right->val);
            aux(node->right, target, sum + node->right->val, ans, tmp);
            tmp.pop_back();
        }
    }
};
// @lc code=end
