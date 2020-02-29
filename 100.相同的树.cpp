/*
 * @lc app=leetcode.cn id=100 lang=cpp
 *
 * [100] 相同的树
 *
 * https://leetcode-cn.com/problems/same-tree/description/
 *
 * algorithms
 * Easy (54.42%)
 * Likes:    278
 * Dislikes: 0
 * Total Accepted:    52.7K
 * Total Submissions: 94.4K
 * Testcase Example:  '[1,2,3]\n[1,2,3]'
 *
 * 给定两个二叉树，编写一个函数来检验它们是否相同。
 * 
 * 如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。
 * 
 * 示例 1:
 * 
 * 输入:       1         1
 * ⁠         / \       / \
 * ⁠        2   3     2   3
 * 
 * ⁠       [1,2,3],   [1,2,3]
 * 
 * 输出: true
 * 
 * 示例 2:
 * 
 * 输入:      1          1
 * ⁠         /           \
 * ⁠        2             2
 * 
 * ⁠       [1,2],     [1,null,2]
 * 
 * 输出: false
 * 
 * 
 * 示例 3:
 * 
 * 输入:       1         1
 * ⁠         / \       / \
 * ⁠        2   1     1   2
 * 
 * ⁠       [1,2,1],   [1,1,2]
 * 
 * 输出: false
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

#include <stack>
using namespace std;

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q)
    {
        TreeNode* cur_p = p;
        TreeNode* cur_q = q;
        stack<TreeNode*> st_p;
        stack<TreeNode*> st_q;
        if (cur_p != NULL && cur_q != NULL) {
            if (cur_p->val != cur_q->val) {
                return false;
            }
            st_p.push(cur_p);
            st_q.push(cur_q);
        } else if (cur_p != NULL || cur_q != NULL) {
            return false;
        }

        TreeNode* top_p;
        TreeNode* top_q;
        while (!st_p.empty()) {
            top_p = st_p.top();
            st_p.pop();
            top_q = st_q.top();
            st_q.pop();

            if (top_p->left != NULL && top_q->left != NULL) {
                if (top_p->left->val != top_q->left->val) {
                    return false;
                }
                st_p.push(top_p->left);
                st_q.push(top_q->left);
            } else if (top_p->left != NULL || top_q->left != NULL) {
                return false;
            }

            if (top_p->right != NULL && top_q->right != NULL) {
                if (top_p->right->val != top_q->right->val) {
                    return false;
                }
                st_p.push(top_p->right);
                st_q.push(top_q->right);
            } else if (top_p->right != NULL || top_q->right != NULL) {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end
