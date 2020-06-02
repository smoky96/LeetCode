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

class Codec {
 public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    if (root == nullptr) return "";
    string s;
    stack<TreeNode*> stk;
    stk.push(root);

    while (!stk.empty()) {
      TreeNode* top = stk.top();
      stk.pop();
      if (top == nullptr) {
        s += "$,";
      } else {
        s += to_string(top->val) + ",";
        stk.push(top->right);
        stk.push(top->left);
      }
    }
    return s;
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    int idx = 0;
    return aux(data, idx);
  }

  TreeNode* aux(string data, int& idx) {
    string next = getNextNum(data, idx);
    if (next == "$" || next == "#") return nullptr;
    TreeNode* tmp = new TreeNode(atoi(next.c_str()));
    tmp->left = aux(data, idx);
    tmp->right = aux(data, idx);
    return tmp;
  }

  string getNextNum(string data, int& idx) {
    if (data[idx] == ',') ++idx;
    if (idx == data.length()) return "#";
    if (data[idx] == '$') {
      ++idx;
      return "$";
    }
    int start = idx;
    while (data[idx] != ',') ++idx;

    return data.substr(start, idx - start);
  }
};