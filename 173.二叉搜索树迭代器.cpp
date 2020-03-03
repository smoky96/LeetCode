/*
 * @lc app=leetcode.cn id=173 lang=cpp
 *
 * [173] 二叉搜索树迭代器
 *
 * https://leetcode-cn.com/problems/binary-search-tree-iterator/description/
 *
 * algorithms
 * Medium (71.41%)
 * Likes:    136
 * Dislikes: 0
 * Total Accepted:    13.9K
 * Total Submissions: 19.4K
 * Testcase Example:
 * '["BSTIterator","next","next","hasNext","next","hasNext","next","hasNext","next","hasNext"]\n[[[7,3,15,null,null,9,20]],[null],[null],[null],[null],[null],[null],[null],[null],[null]]'
 *
 * 实现一个二叉搜索树迭代器。你将使用二叉搜索树的根节点初始化迭代器。
 *
 * 调用 next() 将返回二叉搜索树中的下一个最小的数。
 *
 *
 *
 * 示例：
 *
 *
 *
 * BSTIterator iterator = new BSTIterator(root);
 * iterator.next();    // 返回 3
 * iterator.next();    // 返回 7
 * iterator.hasNext(); // 返回 true
 * iterator.next();    // 返回 9
 * iterator.hasNext(); // 返回 true
 * iterator.next();    // 返回 15
 * iterator.hasNext(); // 返回 true
 * iterator.next();    // 返回 20
 * iterator.hasNext(); // 返回 false
 *
 *
 *
 * 提示：
 *
 *
 * next() 和 hasNext() 操作的时间复杂度是 O(1)，并使用 O(h)
 * 内存，其中 h 是树的高度。 你可以假设 next() 调用总是有效的，也就是说，当调用
 * next() 时，BST 中至少存在一个下一个最小的数。
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

// struct TreeNode {
//   int val;
//   TreeNode *left;
//   TreeNode *right;
//   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
// };

class BSTIterator {
 protected:
  TreeNode *node;

 public:
  BSTIterator(TreeNode *root) : node(root) {}

  /** @return the next smallest number */
  int next() {
    TreeNode *cur = node;
    int ans;
    while (node->left) {
      cur = node->left;
      while (cur->right) {
        if (cur->right == node) {
          cur->right = nullptr;
          ans = node->val;
          node = node->right;
          return ans;
        }
        cur = cur->right;
      }
      cur->right = node;
      node = node->left;
    }
    ans = node->val;
    node = node->right;
    return ans;
  }

  /** @return whether we have a next smallest number */
  bool hasNext() {
    if (node) {
      return true;
    }
    return false;
  }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end
