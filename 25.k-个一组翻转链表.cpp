/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 *
 * https://leetcode-cn.com/problems/reverse-nodes-in-k-group/description/
 *
 * algorithms
 * Hard (53.89%)
 * Likes:    297
 * Dislikes: 0
 * Total Accepted:    27.3K
 * Total Submissions: 49.8K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * 给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
 * 
 * k 是一个正整数，它的值小于或等于链表的长度。
 * 
 * 如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序。
 * 
 * 示例 :
 * 
 * 给定这个链表：1->2->3->4->5
 * 
 * 当 k = 2 时，应当返回: 2->1->4->3->5
 * 
 * 当 k = 3 时，应当返回: 3->2->1->4->5
 * 
 * 说明 :
 * 
 * 
 * 你的算法只能使用常数的额外空间。
 * 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
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
#include <iostream>
using namespace std;

/* struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x)
        : val(x)
        , next(NULL)
    {
    }
}; */

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k)
    {
        if (k == 1 || head == nullptr) {
            return head;
        }
        ListNode* dummy_head = new ListNode(0);
        dummy_head->next = head;

        ListNode *p = head, *l = dummy_head, *r = p->next;
        ListNode *tmp_head = new ListNode(0), *tmp, *tmp_tail = tmp_head;
        int count = 0;
        while (r != nullptr) {
            count = 1;
            r = p->next;
            while (count != k && r != nullptr) {
                count++;
                r = r->next;
            }
            if (count != k) {
                return dummy_head->next;
            }
            while (p != r) {
                tmp = p;
                p = p->next;

                tmp->next = tmp_head->next;
                tmp_head->next = tmp;
                if (tmp_tail == tmp_head) {
                    tmp_tail = tmp_tail->next;
                }
            }
            l->next = tmp_head->next;
            tmp_tail->next = r;
            l = tmp_tail;
            tmp_head->next = nullptr;
            tmp_tail = tmp_head;
        }
        return dummy_head->next;
    }
};
// @lc code=end
