#include <algorithm>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    int len = preorder.size();
    unordered_map<int, int> m;
    for (int i = 0; i < len; ++i) {
      m[inorder[i]] = i;
    }
    return aux(0, len - 1, 0, len - 1, preorder, inorder, m);
  }

  TreeNode* aux(int pre_i, int pre_j, int in_i, int in_j, vector<int>& preorder,
                vector<int>& inorder, unordered_map<int, int>& m) {
    if (pre_i == pre_j) {
      return new TreeNode(preorder[pre_i]);
    } else if (pre_i > pre_j) {
      return nullptr;
    }
    TreeNode* node = new TreeNode(preorder[pre_i]);
    int in_mid = m[preorder[pre_i]];

    node->left = aux(pre_i + 1, pre_i + (in_mid - in_i), in_i, in_mid - 1,
                     preorder, inorder, m);
    node->right = aux(pre_i + (in_mid - in_i) + 1, pre_j, in_mid + 1, in_j,
                      preorder, inorder, m);
    return node;
  }
};