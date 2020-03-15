/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 *
 * https://leetcode-cn.com/problems/remove-linked-list-elements/description/
 *
 * algorithms
 * Easy (44.37%)
 * Likes:    353
 * Dislikes: 0
 * Total Accepted:    64K
 * Total Submissions: 144K
 * Testcase Example:  '[1,2,6,3,4,5,6]\n6'
 *
 * 删除链表中等于给定值 val 的所有节点。
 *
 * 示例:
 *
 * 输入: 1->2->6->3->4->5->6, val = 6
 * 输出: 1->2->3->4->5
 *
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

class Solution {
 public:
  ListNode* removeElements(ListNode* head, int val) {
    ListNode* dummy_head = new ListNode(0);
    dummy_head->next = head;

    ListNode* pre = dummy_head;
    ListNode* cur = dummy_head->next;
    while (cur != nullptr) {
      if (cur->val == val) {
        pre->next = cur->next;
        cur->next = nullptr;
        cur = pre->next;
      } else {
        pre = cur;
        cur = cur->next;
      }
    }
    cur = dummy_head->next;
    delete dummy_head;
    return cur;
  }
};
// @lc code=end
