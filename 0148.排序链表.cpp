/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
 *
 * https://leetcode-cn.com/problems/sort-list/description/
 *
 * algorithms
 * Medium (63.68%)
 * Likes:    414
 * Dislikes: 0
 * Total Accepted:    40.6K
 * Total Submissions: 63.6K
 * Testcase Example:  '[4,2,1,3]'
 *
 * 在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。
 *
 * 示例 1:
 *
 * 输入: 4->2->1->3
 * 输出: 1->2->3->4
 *
 *
 * 示例 2:
 *
 * 输入: -1->5->3->4->0
 * 输出: -1->0->3->4->5
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

#include <vector>
using namespace std;

class Solution {
 public:
  ListNode* sortList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }

    ListNode* tail = head;
    while (tail->next) {
      tail = tail->next;
    }
    auto p = aux(head, tail);
    return p.first;
  }

  pair<ListNode*, ListNode*> aux(ListNode* head, ListNode* tail) {
    if (head->next == tail) {
      if (head->val > tail->val) {
        tail->next = head;
        head->next = nullptr;
        return {tail, head};
      } else {
        tail->next = nullptr;
        return {head, tail};
      }
    }

    if (head == tail) {
      head->next = nullptr;
      return {head, head};
    }

    int len = 1;
    ListNode* cur = head;
    while (cur != tail) {
      cur = cur->next;
      ++len;
    }
    int half = len >> 1;
    cur = head;
    while (--half) {
      cur = cur->next;
    }
    ListNode* right_first = cur->next;

    // cout << head->val << " " << cur->val << endl;
    auto left = aux(head, cur);
    // cur = left.first;
    // while (cur != nullptr) {
    //   cout << cur->val << " ";
    //   cur = cur->next;
    // }
    // cout << endl;

    // cout << right_first->val << " " << tail->val << endl;
    auto right = aux(right_first, tail);
    // cur = right.first;
    // while (cur != nullptr) {
    //   cout << cur->val << " ";
    //   cur = cur->next;
    // }
    // cout << endl;

    ListNode* l_first;
    ListNode* r_first;
    if (left.first->val <= right.first->val) {
      l_first = left.first;
      r_first = right.first;
    } else {
      l_first = right.first;
      r_first = left.first;
    }

    ListNode* l_dummy_head = new ListNode(-1);
    l_dummy_head->next = l_first;
    ListNode* l_pre = l_dummy_head;
    ListNode* r_dummy_head = new ListNode(-1);
    r_dummy_head->next = r_first;
    ListNode* r_pre = r_dummy_head;

    // cur = l_first;
    // while (cur != nullptr) {
    //   cout << cur->val << " ";
    //   cur = cur->next;
    // }
    // cout << endl;

    // cur = r_first;
    // while (cur != nullptr) {
    //   cout << cur->val << " ";
    //   cur = cur->next;
    // }
    // cout << endl;

    while (l_first && r_first) {
      if (l_first->val <= r_first->val) {
        l_first = l_first->next;
        l_pre = l_pre->next;
      } else {
        r_pre->next = r_first->next;
        l_pre->next = r_first;
        r_first->next = l_first;
        l_pre = l_pre->next;
        r_first = r_pre->next;
      }
    }

    // cur = l_dummy_head->next;
    // while (cur) {
    //   cout << cur->val << " ";
    //   cur = cur->next;
    // }
    // cout << endl;

    if (r_first != nullptr) {
      l_first = l_pre;
      l_first->next = r_first;
      while (l_first->next != nullptr) {
        l_first = l_first->next;
      }
    } else if (l_first != nullptr) {
      while (l_first->next != nullptr) {
        l_first = l_first->next;
      }
    }

    // cur = l_dummy_head->next;
    // while (cur) {
    //   cout << cur->val << " ";
    //   cur = cur->next;
    // }
    // cout << endl;
    return {l_dummy_head->next, l_first};
  }
};
// @lc code=end
