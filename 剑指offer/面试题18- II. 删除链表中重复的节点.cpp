struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  ListNode* deleteDuplication(ListNode* pHead) {
    ListNode* dummy_head = new ListNode(-1);
    dummy_head->next = pHead;
    ListNode* pre = dummy_head;
    ListNode* cur = pHead;
    while (cur) {
      while (cur->next && cur->val == cur->next->val) {
        cur = cur->next;
      }
      if (pre->next != cur) {
        pre->next = cur->next;
        cur = pre->next;
      } else {
        pre = pre->next;
        cur = cur->next;
      }
    }
    pHead = dummy_head->next;
    delete dummy_head;
    return pHead;
  }
};