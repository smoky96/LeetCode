struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr) return nullptr;
    if (root->val < p->val && root->val < q->val)
      return lowestCommonAncestor(root->right, p, q);
    if (root->val > p->val && root->val > q->val)
      return lowestCommonAncestor(root->left, p, q);

    return root;
  }
};