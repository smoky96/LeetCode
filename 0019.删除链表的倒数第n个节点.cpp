/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第N个节点
 *
 * https://leetcode-cn.com/problems/remove-nth-node-from-end-of-list/description/
 *
 * algorithms
 * Medium (35.14%)
 * Likes:    582
 * Dislikes: 0
 * Total Accepted:    91.5K
 * Total Submissions: 251.6K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给定一个链表，删除链表的倒数第 n 个节点，并且返回链表的头结点。
 *
 * 示例：
 *
 * 给定一个链表: 1->2->3->4->5, 和 n = 2.
 *
 * 当删除了倒数第二个节点后，链表变为 1->2->3->5.
 *
 *
 * 说明：
 *
 * 给定的 n 保证是有效的。
 *
 * 进阶：
 *
 * 你能尝试使用一趟扫描实现吗？
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
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {
        int length = 1;
        ListNode *p = head, *q = head;
        while (n--) {
            q = q->next;
        }
        if (q == nullptr) {
            head = head->next;
            delete (p);
            return head;
        }
        while (q->next != nullptr) {
            p = p->next;
            q = q->next;
        }
        q = p->next;
        p->next = q->next;
        delete (q);
        return head;
    }
};
// @lc code=end
