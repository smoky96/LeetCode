/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层次遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (58.29%)
 * Likes:    340
 * Dislikes: 0
 * Total Accepted:    66K
 * Total Submissions: 109.9K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，返回其按层次遍历的节点值。 （即逐层地，从左到右访问所有节点）。
 * 
 * 例如:
 * 给定二叉树: [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回其层次遍历结果：
 * 
 * [
 * ⁠ [3],
 * ⁠ [9,20],
 * ⁠ [15,7]
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
#include <queue>
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
    vector<vector<int>> levelOrder(TreeNode* root)
    {
        queue<TreeNode*> qu;
        if (root != NULL) {
            qu.push(root);
        } else {
            return {};
        }
        vector<vector<int>> ans;
        vector<int> tmp;
        TreeNode* end = qu.back();
        TreeNode* front;
        while (!qu.empty()) {
            do {
                front = qu.front();
                qu.pop();
                tmp.push_back(front->val);
                if (front->left != NULL) {
                    qu.push(front->left);
                }
                if (front->right != NULL) {
                    qu.push(front->right);
                }
            } while (front != end);

            end = qu.back();
            ans.push_back(tmp);
            tmp.clear();
        }
        return ans;
    }
};
// @lc code=end
