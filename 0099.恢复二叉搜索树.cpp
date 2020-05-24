/*
 * @lc app=leetcode.cn id=99 lang=cpp
 *
 * [99] 恢复二叉搜索树
 *
 * https://leetcode-cn.com/problems/recover-binary-search-tree/description/
 *
 * algorithms
 * Hard (54.50%)
 * Likes:    120
 * Dislikes: 0
 * Total Accepted:    8.7K
 * Total Submissions: 16.1K
 * Testcase Example:  '[1,3,null,null,2]'
 *
 * 二叉搜索树中的两个节点被错误地交换。
 * 
 * 请在不改变其结构的情况下，恢复这棵树。
 * 
 * 示例 1:
 * 
 * 输入: [1,3,null,null,2]
 * 
 * 1
 * /
 * 3
 * \
 * 2
 * 
 * 输出: [3,1,null,null,2]
 * 
 * 3
 * /
 * 1
 * \
 * 2
 * 
 * 
 * 示例 2:
 * 
 * 输入: [3,1,4,null,null,2]
 * 
 * ⁠ 3
 * ⁠/ \
 * 1   4
 * /
 * 2
 * 
 * 输出: [2,1,4,null,null,3]
 * 
 * ⁠ 2
 * ⁠/ \
 * 1   4
 * /
 * ⁠ 3
 * 
 * 进阶:
 * 
 * 
 * 使用 O(n) 空间复杂度的解法很容易实现。
 * 你能想出一个只使用常数空间的解决方案吗？
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

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    void recoverTree(TreeNode* root)
    {
        TreeNode* cur = root;
        TreeNode* first = NULL;
        TreeNode* second = NULL;
        TreeNode* pre_n = NULL;

        while (cur != NULL) {
            if (cur->left == NULL) {
                if (pre_n != NULL && cur->val < pre_n->val) {
                    if (first == NULL) {
                        first = pre_n;
                        second = cur;
                    } else {
                        second = cur;
                    }
                }
                pre_n = cur;
                cur = cur->right;
            } else {
                TreeNode* pre = cur->left;
                while (pre->right != cur && pre->right != NULL) {
                    pre = pre->right;
                }

                if (pre->right == NULL) {
                    pre->right = cur;
                    cur = cur->left;
                } else {
                    pre->right = NULL;
                    if (pre_n != NULL && cur->val < pre_n->val) {
                        if (first == NULL) {
                            first = pre_n;
                            second = cur;
                        } else {
                            second = cur;
                        }
                    }
                    pre_n = cur;
                    cur = cur->right;
                }
            }
        }

        int tmp = first->val;
        first->val = second->val;
        second->val = tmp;
    }
};
// @lc code=end
