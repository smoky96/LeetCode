/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-preorder-traversal/description/
 *
 * algorithms
 * Medium (63.97%)
 * Likes:    206
 * Dislikes: 0
 * Total Accepted:    66.8K
 * Total Submissions: 104.4K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的 前序 遍历。
 *
 * 示例:
 *
 * 输入: [1,null,2,3]
 * ⁠  1
 * ⁠   \
 * ⁠    2
 * ⁠   /
 * ⁠  3
 *
 * 输出: [1,2,3]
 *
 *
 * 进阶: 递归算法很简单，你可以通过迭代算法完成吗？
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

// struct TreeNode {
//   int val;
//   TreeNode* left;
//   TreeNode* right;
//   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

#include <stack>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;
    TreeNode* cur = root;

    while (cur != nullptr) {
      if (cur->left != nullptr) {
        TreeNode* pre = cur->left;
        while (pre->right != nullptr && pre->right != cur) pre = pre->right;

        if (pre->right == nullptr) {
          pre->right = cur;
          ans.push_back(cur->val);
          cur = cur->left;
        } else {
          cur = cur->right;
          pre->right = nullptr;
        }

      } else {
        ans.push_back(cur->val);
        cur = cur->right;
      }
    }

    return ans;
  }
};
// @lc code=end
