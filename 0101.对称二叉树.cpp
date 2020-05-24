/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
 *
 * https://leetcode-cn.com/problems/symmetric-tree/description/
 *
 * algorithms
 * Easy (48.11%)
 * Likes:    545
 * Dislikes: 0
 * Total Accepted:    79.2K
 * Total Submissions: 160.9K
 * Testcase Example:  '[1,2,2,3,4,4,3]'
 *
 * 给定一个二叉树，检查它是否是镜像对称的。
 * 
 * 例如，二叉树 [1,2,2,3,4,4,3] 是对称的。
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠/ \ / \
 * 3  4 4  3
 * 
 * 
 * 但是下面这个 [1,2,2,null,3,null,3] 则不是镜像对称的:
 * 
 * ⁠   1
 * ⁠  / \
 * ⁠ 2   2
 * ⁠  \   \
 * ⁠  3    3
 * 
 * 
 * 说明:
 * 
 * 如果你可以运用递归和迭代两种方法解决这个问题，会很加分。
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
#include <vector>
using namespace std;
class Solution {
public:
    bool isSymmetric(TreeNode* root)
    {
        queue<TreeNode*> qu;
        qu.push(root);
        qu.push(root);
        TreeNode* t1;
        TreeNode* t2;
        while (!qu.empty()) {
            t1 = qu.front();
            qu.pop();
            t2 = qu.front();
            qu.pop();
            if (t1 == NULL && t2 == NULL)
                continue;
            if (t1 == NULL || t2 == NULL)
                return false;
            if (t1->val != t2->val)
                return false;
            qu.push(t1->left);
            qu.push(t2->right);
            qu.push(t1->right);
            qu.push(t2->left);
        }
        return true;
    }
};
// @lc code=end
