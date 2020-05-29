struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  ListNode* EntryNodeOfLoop(ListNode* pHead) {
    if (pHead == nullptr) return nullptr;
    ListNode* p1 = pHead->next;
    ListNode* p2 = pHead;
    while (p1 != nullptr && p1->next != nullptr && p1 != p2) {
      p1 = p1->next;
      p1 = p1->next;
      p2 = p2->next;
    }
    if (p1 != p2) return nullptr;

    int loop_num = 1;
    p1 = p1->next;
    while (p1 != p2) {
      ++loop_num;
      p1 = p1->next;
    }

    p1 = pHead;
    p2 = pHead;
    for (int i = 0; i < loop_num; ++i) {
      p1 = p1->next;
    }

    while (p1 != p2) {
      p1 = p1->next;
      p2 = p2->next;
    }
    return p1;
  }
};