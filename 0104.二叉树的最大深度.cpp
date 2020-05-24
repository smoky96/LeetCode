/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
 *
 * https://leetcode-cn.com/problems/maximum-depth-of-binary-tree/description/
 *
 * algorithms
 * Easy (70.54%)
 * Likes:    417
 * Dislikes: 0
 * Total Accepted:    106.6K
 * Total Submissions: 148.9K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，找出其最大深度。
 * 
 * 二叉树的深度为根节点到最远叶子节点的最长路径上的节点数。
 * 
 * 说明: 叶子节点是指没有子节点的节点。
 * 
 * 示例：
 * 给定二叉树 [3,9,20,null,null,15,7]，
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 返回它的最大深度 3 。
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
#include <queue>
using namespace std;

class Solution {
public:
    int maxDepth(TreeNode* root)
    {
        queue<TreeNode*> qu;
        if (root == NULL) {
            return 0;
        } else {
            qu.push(root);
        }

        int size;
        int level = 0;
        TreeNode* cur;
        while (!qu.empty()) {
            size = qu.size();
            while (size--) {
                cur = qu.front();
                qu.pop();
                if (cur->left) {
                    qu.push(cur->left);
                }
                if (cur->right) {
                    qu.push(cur->right);
                }
            }
            ++level;
        }
        return level;
    }
};
// @lc code=end
