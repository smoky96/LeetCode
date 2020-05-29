struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  ListNode* getKthFromEnd(ListNode* head, int k) {
    if (head == nullptr) return nullptr;

    ListNode* p1 = head;
    ListNode* p2 = head;

    for (int i = 1; i < k; ++i) {
      if (p1 == nullptr) return nullptr;
      p1 = p1->next;
    }

    while (p1->next != nullptr) {
      p1 = p1->next;
      p2 = p2->next;
    }

    return p2;
  }
};