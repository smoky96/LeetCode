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
  vector<int> levelOrder(TreeNode *root) {
    vector<int> ans;
    queue<TreeNode *> que;
    if (root) que.push(root);

    while (!que.empty()) {
      TreeNode *front = que.front();
      que.pop();
      ans.push_back(front->val);
      if (front->left) que.push(front->left);
      if (front->right) que.push(front->right);
    }
    return ans;
  }
};