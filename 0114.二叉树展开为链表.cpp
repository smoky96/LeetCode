/*
 * @lc app=leetcode.cn id=114 lang=cpp
 *
 * [114] 二叉树展开为链表
 *
 * https://leetcode-cn.com/problems/flatten-binary-tree-to-linked-list/description/
 *
 * algorithms
 * Medium (64.24%)
 * Likes:    230
 * Dislikes: 0
 * Total Accepted:    21.6K
 * Total Submissions: 32.4K
 * Testcase Example:  '[1,2,5,3,4,null,6]'
 *
 * 给定一个二叉树，原地将它展开为链表。
 * 
 * 例如，给定二叉树
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   5
 * ⁠/ \   \
 * 3   4   6
 * 
 * 将其展开为：
 * 
 * 1
 * ⁠\
 * ⁠ 2
 * ⁠  \
 * ⁠   3
 * ⁠    \
 * ⁠     4
 * ⁠      \
 * ⁠       5
 * ⁠        \
 * ⁠         6
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
    void flatten(TreeNode* root)
    {
        TreeNode* r_p;
        TreeNode* p;
        while (root) {
            if (root->left == NULL) {
                root = root->right;
            } else {
                r_p = root->right;
                root->right = root->left;
                root->left = NULL; // 这里要将左孩子释放！！
                p = root;
                while (p->right != NULL) {
                    p = p->right;
                }
                if (r_p != NULL)
                    p->right = r_p;
                r_p = NULL;
                root = root->right;
            }
        }
    }
};
// @lc code=end
