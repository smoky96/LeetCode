#include <algorithm>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    int len_a = getLen(headA);
    int len_b = getLen(headB);
    ListNode *cur_a = len_a > len_b ? headA : headB;
    ListNode *cur_b = cur_a == headA ? headB : headA;

    int dif = abs(len_a - len_b);
    while (dif--) {
      cur_a = cur_a->next;
    }

    while (cur_a != cur_b) {
      cur_a = cur_a->next;
      cur_b = cur_b->next;
    }

    return cur_a;
  }

  int getLen(ListNode *head) {
    int ret = 0;
    while (head != nullptr) {
      ++ret;
      head = head->next;
    }
    return ret;
  }
};