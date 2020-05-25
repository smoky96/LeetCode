struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  ListNode* deleteNode(ListNode* head, int val) {
    ListNode* dummy_head = new ListNode(-1);
    dummy_head->next = head;
    ListNode* pre = dummy_head;
    ListNode* cur = head;
    while (cur != nullptr) {
      if (cur->val == val) {
        pre->next = cur->next;
        break;
      }
      cur = cur->next;
      pre = pre->next;
    }
    return dummy_head->next;
  }
};