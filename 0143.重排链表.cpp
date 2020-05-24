/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
 *
 * https://leetcode-cn.com/problems/reorder-list/description/
 *
 * algorithms
 * Medium (54.36%)
 * Likes:    149
 * Dislikes: 0
 * Total Accepted:    15.8K
 * Total Submissions: 29K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
 * 将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…
 *
 * 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 *
 * 示例 1:
 *
 * 给定链表 1->2->3->4, 重新排列为 1->4->2->3.
 *
 * 示例 2:
 *
 * 给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.
 *
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// struct ListNode {
//   int val;
//   ListNode* next;
//   ListNode(int x) : val(x), next(NULL) {}
// };

class Solution {
 public:
  void reorderList(ListNode* head) {
    if (head == nullptr) {
      return;
    }
    ListNode* h = head;
    int len = 0;
    for (; h != nullptr; ++len, h = h->next)
      ;

    aux(head, len);
  }

  ListNode* aux(ListNode* head, int len) {
    if (len == 1) {
      ListNode* outtail = head->next;
      head->next = nullptr;
      return outtail;
    }
    if (len == 2) {
      ListNode* outtail = head->next->next;
      head->next->next = nullptr;
      return outtail;
    }

    ListNode* tail = aux(head->next, len - 2);
    ListNode* outtail = tail->next;
    ListNode* next = head->next;
    head->next = tail;
    tail->next = next;

    return outtail;
  }
};
// @lc code=end
