#include <stdio.h>

#include <algorithm>
#include <deque>
#include <iostream>
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
  vector<vector<int>> pathSum(TreeNode* root, int sum) {
    if (root == nullptr) return {};
    vector<vector<int>> ans;
    vector<int> tmp;
    aux(root, sum, 0, ans, tmp);
    return ans;
  }

  void aux(TreeNode* root, const int& target, int cur_sum,
           vector<vector<int>>& path, vector<int>& tmp) {
    if (root->left == nullptr && root->right == nullptr) {
      if (cur_sum + root->val == target) {
        tmp.push_back(root->val);
        path.push_back(tmp);
        tmp.pop_back();
      }
      return;
    }

    tmp.push_back(root->val);
    if (root->left) aux(root->left, target, cur_sum + root->val, path, tmp);
    if (root->right) aux(root->right, target, cur_sum + root->val, path, tmp);
    tmp.pop_back();
  }
};