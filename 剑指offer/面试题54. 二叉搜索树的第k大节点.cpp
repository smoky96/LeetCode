struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  int count = 0;
  int kthLargest(TreeNode *root, int k) {
    int ret = 0;
    aux(root, k, ret);
    return ret;
  }

  void aux(TreeNode *node, const int &k, int &ans) {
    if (node->right) aux(node->right, k, ans);
    ++count;
    if (count == k) {
      ans = node->val;
      return;
    }
    if (node->left) aux(node->left, k, ans);
  }
};