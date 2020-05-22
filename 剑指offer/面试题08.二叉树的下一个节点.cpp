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

struct TreeLinkNode {
  int val;
  struct TreeLinkNode *left;
  struct TreeLinkNode *right;
  struct TreeLinkNode *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
 public:
  TreeLinkNode *GetNext(TreeLinkNode *pNode) {
    if (pNode == nullptr) return nullptr;

    if (pNode->right != nullptr) {
      pNode = pNode->right;
      while (pNode->left != nullptr) pNode = pNode->left;
      return pNode;
    } else if (pNode->next != nullptr) {
      TreeLinkNode *pNodeCur = pNode;
      TreeLinkNode *pNodeNxt = pNode->next;
      while (pNodeNxt->right == pNodeCur) {
        if (pNodeNxt->next == nullptr) return nullptr;
        pNodeCur = pNodeNxt;
        pNodeNxt = pNodeNxt->next;
      }
      return pNodeNxt;
    }
    return nullptr;
  }
};