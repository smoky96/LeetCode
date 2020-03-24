/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
 *
 * https://leetcode-cn.com/problems/palindrome-linked-list/description/
 *
 * algorithms
 * Easy (40.77%)
 * Likes:    436
 * Dislikes: 0
 * Total Accepted:    73K
 * Total Submissions: 177.8K
 * Testcase Example:  '[1,2]'
 *
 * 请判断一个链表是否为回文链表。
 *
 * 示例 1:
 *
 * 输入: 1->2
 * 输出: false
 *
 * 示例 2:
 *
 * 输入: 1->2->2->1
 * 输出: true
 *
 *
 * 进阶：
 * 你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？
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
  bool isPalindrome(ListNode* head) {
    if (head == nullptr) return true;

    ListNode* dummy_head = new ListNode(0);
    dummy_head->next = head;

    ListNode* slow = dummy_head;
    ListNode* fast = dummy_head;

    ListNode* pre = dummy_head;
    ListNode* next = head;
    while (fast && fast->next != nullptr) {
      fast = fast->next;
      fast = fast->next;
      pre = slow;
      slow = next;
      next = slow->next;
      slow->next = pre;
    }
    delete dummy_head;
    head->next = nullptr;

    if (fast == nullptr) {
      slow = slow->next;
    }
    fast = next;

    for (; slow != nullptr; slow = slow->next, fast = fast->next) {
      if (slow->val != fast->val) return false;
    }
    return true;
  }
};
// @lc code=end
