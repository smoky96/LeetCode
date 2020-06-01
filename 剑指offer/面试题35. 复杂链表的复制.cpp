class Node {
 public:
  int val;
  Node* next;
  Node* random;

  Node(int _val) {
    val = _val;
    next = nullptr;
    random = nullptr;
  }
};

class Solution {
 public:
  Node* copyRandomList(Node* head) {
    if (head == nullptr) return nullptr;
    Node* cur = head;
    while (cur != nullptr) {
      Node* tmp = cur->next;
      cur->next = new Node(cur->val);
      cur->next->next = tmp;
      cur = tmp;
    }
    cur = head;
    while (cur != nullptr) {
      if (cur->random != nullptr) {
        cur->next->random = cur->random->next;
      }
      cur = cur->next->next;
    }
    cur = head;
    Node* new_head = cur->next;
    Node* new_cur = new_head;
    while (cur != nullptr) {
      cur->next = cur->next->next;
      if (new_cur->next != nullptr) new_cur->next = new_cur->next->next;
      cur = cur->next;
      new_cur = new_cur->next;
    }
    return new_head;
  }
};