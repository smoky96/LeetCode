/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 *
 * https://leetcode-cn.com/problems/binary-tree-postorder-traversal/description/
 *
 * algorithms
 * Hard (70.03%)
 * Likes:    224
 * Dislikes: 0
 * Total Accepted:    49.8K
 * Total Submissions: 71K
 * Testcase Example:  '[1,null,2,3]'
 *
 * 给定一个二叉树，返回它的 后序 遍历。
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
 * 输出: [3,2,1]
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
//   TreeNode *left;
//   TreeNode *right;
//   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

#include <stack>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> postorderTraversal(TreeNode *root) {
    vector<int> ans;
    stack<pair<TreeNode *, int>> st;
    if (root != nullptr) {
      st.push(make_pair(root, 0));
    }

    pair<TreeNode *, int> top;

    while (!st.empty()) {
      top = st.top();
      st.pop();
      if (top.second != 1) {
        top.second += 1;
        st.push(top);
        if (top.first->right != nullptr) {
          st.push(make_pair(top.first->right, 0));
        }
        if (top.first->left != nullptr) {
          st.push(make_pair(top.first->left, 0));
        }
      } else {
        ans.push_back(top.first->val);
      }
    }
    return ans;
  }
};
// @lc code=end
