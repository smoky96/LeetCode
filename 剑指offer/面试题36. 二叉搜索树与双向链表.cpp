struct Node {
  int val;
  Node* left;
  Node* right;
  Node(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  Node* treeToDoublyList(Node* root) {
    if (root == nullptr) return nullptr;
    Node* lastNode = nullptr;
    aux(root, lastNode);
    Node* cur = lastNode;
    while (cur->left != nullptr) {
      cur = cur->left;
    }
    cur->left = lastNode;
    lastNode->right = cur;
    return cur;
  }

  void aux(Node* curNode, Node*& lastNode) {
    if (curNode == nullptr) return;
    aux(curNode->left, lastNode);
    curNode->left = lastNode;
    if (lastNode) lastNode->right = curNode;
    lastNode = curNode;
    aux(curNode->right, lastNode);
  }
};