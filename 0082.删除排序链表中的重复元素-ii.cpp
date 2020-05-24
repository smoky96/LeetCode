/*
 * @lc app=leetcode.cn id=82 lang=cpp
 *
 * [82] 删除排序链表中的重复元素 II
 *
 * https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list-ii/description/
 *
 * algorithms
 * Medium (43.12%)
 * Likes:    180
 * Dislikes: 0
 * Total Accepted:    25.6K
 * Total Submissions: 57.4K
 * Testcase Example:  '[1,2,3,3,4,4,5]'
 *
 * 给定一个排序链表，删除所有含有重复数字的节点，只保留原始链表中 没有重复出现 的数字。
 * 
 * 示例 1:
 * 
 * 输入: 1->2->3->3->4->4->5
 * 输出: 1->2->5
 * 
 * 
 * 示例 2:
 * 
 * 输入: 1->1->1->2->3
 * 输出: 2->3
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
    ListNode* deleteDuplicates(ListNode* head)
    {
        if (head == nullptr) {
            return head;
        }
        ListNode* dummy_head = new ListNode(-1);
        dummy_head->next = head;
        ListNode* pre = dummy_head;
        ListNode* p1 = head;
        ListNode* p2 = p1->next;
        while (p1 != nullptr) {
            p2 = p1->next;
            while (p2 != nullptr && p1->val == p2->val) {
                p2 = p2->next;
            }
            if (p2 != p1->next) {
                pre->next = p2;
            } else {
                pre = pre->next;
            }
            p1 = p2;
        }
        return dummy_head->next;
    }
};
// @lc code=end
