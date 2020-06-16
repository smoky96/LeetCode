#include <stdio.h>

#include <algorithm>
#include <deque>
#include <iostream>
#include <iterator>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define PRINT_ARY(container, value_type)           \
  do {                                             \
    copy(container.begin(), container.end(),       \
         ostream_iterator<value_type>(cout, " ")); \
    cout << endl;                                  \
  } while (0)

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  bool isBalanced(TreeNode *root) {
    if (aux(root) < 0) return false;
    return true;
  }

  int aux(TreeNode *node) {
    if (node == nullptr) {
      return 0;
    }
    int left = aux(node->left);
    int right = aux(node->right);
    if (left >= 0 && right >= 0 && abs(left - right) <= 1) {
      return left > right ? left + 1 : right + 1;
    } else {
      return -1;
    }
  }
};