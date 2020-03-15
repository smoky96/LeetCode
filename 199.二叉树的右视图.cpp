/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
 *
 * https://leetcode-cn.com/problems/binary-tree-right-side-view/description/
 *
 * algorithms
 * Medium (63.71%)
 * Likes:    143
 * Dislikes: 0
 * Total Accepted:    19.7K
 * Total Submissions: 30.9K
 * Testcase Example:  '[1,2,3,null,5,null,4]'
 *
 * 给定一棵二叉树，想象自己站在它的右侧，按照从顶部到底部的顺序，返回从右侧所能看到的节点值。
 *
 * 示例:
 *
 * 输入: [1,2,3,null,5,null,4]
 * 输出: [1, 3, 4]
 * 解释:
 *
 * ⁠  1            <---
 * ⁠/   \
 * 2     3         <---
 * ⁠\     \
 * ⁠ 5     4       <---
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
#include <climits>
#include <queue>
#include <vector>
using namespace std;

// struct TreeNode {
//   int val;
//   TreeNode *left;
//   TreeNode *right;
//   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class Solution {
 public:
  vector<int> rightSideView(TreeNode *root) {
    if (root == NULL) {
      return {};
    }

    queue<TreeNode *> que;
    que.push(root);
    vector<int> ans;

    while (!que.empty()) {
      int len = que.size();
      TreeNode *tmp = nullptr;
      for (int i = 0; i < len; ++i) {
        tmp = que.front();
        que.pop();
        if (tmp->left) {
          que.push(tmp->left);
        }
        if (tmp->right) {
          que.push(tmp->right);
        }
      }
      ans.push_back(tmp->val);
    }
    return ans;
  }
};
// @lc code=end
