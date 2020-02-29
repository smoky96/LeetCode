/*
 * @lc app=leetcode.cn id=86 lang=cpp
 *
 * [86] 分隔链表
 *
 * https://leetcode-cn.com/problems/partition-list/description/
 *
 * algorithms
 * Medium (52.00%)
 * Likes:    139
 * Dislikes: 0
 * Total Accepted:    20.3K
 * Total Submissions: 37.5K
 * Testcase Example:  '[1,4,3,2,5,2]\n3'
 *
 * 给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。
 * 
 * 你应当保留两个分区中每个节点的初始相对位置。
 * 
 * 示例:
 * 
 * 输入: head = 1->4->3->2->5->2, x = 3
 * 输出: 1->2->2->4->3->5
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
    ListNode* partition(ListNode* head, int x)
    {
        if (head == nullptr) {
            return head;
        }
        ListNode* dummy_head = new ListNode(-1);
        dummy_head->next = head;
        ListNode* p1 = dummy_head;
        while (p1->next != nullptr && p1->next->val < x) {
            p1 = p1->next;
        }
        ListNode *pre = p1->next, *p2;
        while (pre != nullptr) {
            p2 = pre->next;
            if (p2 != nullptr && p2->val < x) {
                pre->next = p2->next;
                p2->next = p1->next;
                p1->next = p2;
                p1 = p2;
            } else {
                pre = pre->next;
            }
        }
        return dummy_head->next;
    }
};
// @lc code=end
