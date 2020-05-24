/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并K个排序链表
 *
 * https://leetcode-cn.com/problems/merge-k-sorted-lists/description/
 *
 * algorithms
 * Hard (47.39%)
 * Likes:    390
 * Dislikes: 0
 * Total Accepted:    55.5K
 * Total Submissions: 115.9K
 * Testcase Example:  '[[1,4,5],[1,3,4],[2,6]]'
 *
 * 合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。
 * 
 * 示例:
 * 
 * 输入:
 * [
 * 1->4->5,
 * 1->3->4,
 * 2->6
 * ]
 * 输出: 1->1->2->3->4->4->5->6
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
    ListNode* mergeKLists(vector<ListNode*>& lists)
    {
        if (lists.size() == 0) {
            return nullptr;
        } else {
            return mergeTwoLists(lists, 0, (lists.size() - 1));
        }
    }

    ListNode* mergeTwoLists(vector<ListNode*>& lists, int L, int R)
    {
        if (R == L) {
            return lists[R];
        }

        int mid = (R + L) / 2;

        ListNode *l1 = mergeTwoLists(lists, L, mid);
        ListNode *l2 = mergeTwoLists(lists, mid + 1, R);

        ListNode *p, *q, *a, *ret;
        if (l1 == nullptr) {
            return l2;
        } else if (l2 == nullptr) {
            return l1;
        }
        p = l1->val < l2->val ? l1 : l2;
        q = p == l1 ? l2 : l1;
        ret = p;
        a = p;
        p = p->next;
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

/* int main()
{
    vector<ListNode*> lists;
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(5);
    
    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);
    
    ListNode* l3 = new ListNode(2);
    l3->next = new ListNode(6);

    lists.push_back(l1);
    lists.push_back(l2);
    lists.push_back(l3);

    ListNode* ret = Solution().mergeKLists(lists);
} */
// @lc code=end
