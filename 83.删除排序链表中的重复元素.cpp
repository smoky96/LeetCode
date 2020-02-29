/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
 *
 * https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/description/
 *
 * algorithms
 * Easy (47.31%)
 * Likes:    230
 * Dislikes: 0
 * Total Accepted:    59.7K
 * Total Submissions: 123.5K
 * Testcase Example:  '[1,1,2]'
 *
 * 给定一个排序链表，删除所有重复的元素，使得每个元素只出现一次。
 * 
 * 示例 1:
 * 
 * 输入: 1->1->2
 * 输出: 1->2
 * 
 * 
 * 示例 2:
 * 
 * 输入: 1->1->2->3->3
 * 输出: 1->2->3
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
        ListNode* p1 = head;
        ListNode* p2 = p1->next;
        while (p1 != nullptr) {
            p2 = p1->next;
            while (p2 != nullptr && p2->val == p1->val) {
                p2 = p2->next;
            }
            if (p2 != p1->next) {
                p1->next = p2;
            }
            p1 = p2;
        }
        return head;
    }
};
// @lc code=end
