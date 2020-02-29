/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
 *
 * https://leetcode-cn.com/problems/merge-two-sorted-lists/description/
 *
 * algorithms
 * Easy (56.65%)
 * Likes:    705
 * Dislikes: 0
 * Total Accepted:    138.6K
 * Total Submissions: 237.9K
 * Testcase Example:  '[1,2,4]\n[1,3,4]'
 *
 * 将两个有序链表合并为一个新的有序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 
 * 
 * 示例：
 * 
 * 输入：1->2->4, 1->3->4
 * 输出：1->1->2->3->4->4
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
// struct ListNode {
//     int val;
//     ListNode* next;
//     ListNode(int x)
//         : val(x)
//         , next(nullptr)
//     {
//     }
// };

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {
        if (l1 == nullptr) {
            return l2;
        } else if (l2 == nullptr) {
            return l1;
        }
        ListNode *p, *q, *a, *ret;
        if (l1->val <= l2->val) {
            ret = l1;
            p = l1;
            q = l2;
            a = nullptr;
        } else {
            ret = l2;
            p = l2;
            q = l1;
            a = nullptr;
        }
        while (p != nullptr && q != nullptr) {
            if (p->val <= q->val) {
                a = p;
                p = p->next;
            } else {
                a->next = q;
                q = q->next;
                a = a->next;
                a->next = p;
            }
        }
        if (q != nullptr) {
            a->next = q;
            return ret;
        } else {
            return ret;
        }
    }
};
// @lc code=end
