/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
 *
 * https://leetcode-cn.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (61.75%)
 * Likes:    336
 * Dislikes: 0
 * Total Accepted:    51.7K
 * Total Submissions: 82.3K
 * Testcase Example:  '[1,2,3,4]'
 *
 * 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
 * 
 * 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 * 
 * 
 * 
 * 示例:
 * 
 * 给定 1->2->3->4, 你应该返回 2->1->4->3.
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

#include <vector>
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
    ListNode* swapPairs(ListNode* head)
    {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode* dummy_head = new ListNode(0);
        dummy_head->next = head;
        ListNode *r = dummy_head, *p = head, *q = p->next;
        while (p != nullptr && q != nullptr) {
            r->next = q;
            p->next = q->next;
            q->next = p;
            r = p;
            p = p->next;
            if (p != nullptr)
                q = p->next;
        }
        // delete 操作很耗时，所以不要 delete，直接返回
        return dummy_head->next;
    }
};
// @lc code=end
