struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  bool isSubStructure(TreeNode* A, TreeNode* B) {
    if (A == nullptr || B == nullptr) return false;

    bool ret = false;
    if (A->val == B->val) {
      ret = aux(A, B);
    }
    if (!ret) {
      ret = isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
    return ret;
  }

  bool aux(TreeNode* A, TreeNode* B) {
    if (B == nullptr) return true;
    if (A == nullptr) return false;

    if (A->val != B->val) return false;
    return aux(A->left, B->left) && aux(A->right, B->right);
  }
};