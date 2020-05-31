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
    queue<TreeNode *> que;
    if (root) que.push(root);

    vector<vector<int>> ans;

    while (!que.empty()) {
      int sz = que.size();
      vector<int> tmp(sz);
      for (int i = 0; i < sz; ++i) {
        TreeNode *front = que.front();
        que.pop();
        tmp[i] = front->val;
        if (front->left) que.push(front->left);
        if (front->right) que.push(front->right);
      }
      ans.push_back(tmp);
    }
    return ans;
  }
};