/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层次遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-zigzag-level-order-traversal/description/
 *
 * algorithms
 * Medium (51.16%)
 * Likes:    124
 * Dislikes: 0
 * Total Accepted:    26.3K
 * Total Submissions: 49.9K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * 给定一个二叉树，返回其节点值的锯齿形层次遍历。（即先从左往右，再从右往左进行下一层遍历，以此类推，层与层之间交替进行）。
 * 
 * 例如：
 * 给定二叉树 [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 返回锯齿形层次遍历如下：
 * 
 * [
 * ⁠ [3],
 * ⁠ [20,9],
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
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        stack<TreeNode*> st_r;
        stack<TreeNode*> st_l;
        if (root != NULL) {
            st_r.push(root);
        } else {
            return {};
        }
        int size;
        vector<int> tmp;
        vector<vector<int>> ans;
        TreeNode* cur;
        bool to_r = true;
        while (!st_r.empty() || !st_l.empty()) {
            if (!st_r.empty()) {
                while (!st_r.empty()) {
                    cur = st_r.top();
                    st_r.pop();
                    tmp.push_back(cur->val);
                    if (cur->left != NULL)
                        st_l.push(cur->left);
                    if (cur->right != NULL)
                        st_l.push(cur->right);
                }
            } else {
                while (!st_l.empty()) {
                    cur = st_l.top();
                    st_l.pop();
                    tmp.push_back(cur->val);
                    if (cur->right)
                        st_r.push(cur->right);
                    if (cur->left)
                        st_r.push(cur->left);
                }
            }
            ans.push_back(tmp);
            tmp.clear();
        }
        return ans;
    }
};
// @lc code=end
