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
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    stack<TreeNode *> stk[2];
    if (root) stk[0].push(root);

    vector<vector<int>> ans;
    int cur = 0;
    while (!stk[0].empty() || !stk[1].empty()) {
      int idx = cur & 0x1;
      int sz = stk[idx].size();
      vector<int> tmp(sz);
      for (int i = 0; i < sz; ++i) {
        TreeNode *top = stk[idx].top();
        stk[idx].pop();
        tmp[i] = top->val;
        if (cur & 0x1) {
          if (top->right) stk[0].push(top->right);
          if (top->left) stk[0].push(top->left);
        } else {
          if (top->left) stk[1].push(top->left);
          if (top->right) stk[1].push(top->right);
        }
      }
      ++cur;
      ans.push_back(tmp);
    }
    return ans;
  }
};