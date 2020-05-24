/*
 * @lc app=leetcode.cn id=445 lang=cpp
 *
 * [445] 两数相加 II
 *
 * https://leetcode-cn.com/problems/add-two-numbers-ii/description/
 *
 * algorithms
 * Medium (54.63%)
 * Likes:    180
 * Dislikes: 0
 * Total Accepted:    30.6K
 * Total Submissions: 53.9K
 * Testcase Example:  '[7,2,4,3]\n[5,6,4]'
 *
 * 给你两个 非空
 * 链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储一位数字。将这两数相加会返回一个新的链表。
 *
 * 你可以假设除了数字 0 之外，这两个数字都不会以零开头。
 *
 *
 *
 * 进阶：
 *
 * 如果输入链表不能修改该如何处理？换句话说，你不能对列表中的节点进行翻转。
 *
 *
 *
 * 示例：
 *
 * 输入：(7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
 * 输出：7 -> 8 -> 0 -> 7
 *
 *
 */

// @lc code=start
/* *
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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    vector<int> v1;
    vector<int> v2;
    for (ListNode* cur = l1; cur != nullptr; cur = cur->next)
      v1.push_back(cur->val);
    for (ListNode* cur = l2; cur != nullptr; cur = cur->next)
      v2.push_back(cur->val);

    ListNode* head = nullptr;
    int cf = 0;
    int cur;
    ListNode* tmp;
    for (vector<int>::reverse_iterator rit1 = v1.rbegin(), rit2 = v2.rbegin();
         rit1 != v1.rend() || rit2 != v2.rend() || cf;) {
      cur = 0;
      cur += (rit1 == v1.rend() ? 0 : *(rit1++));
      cur += (rit2 == v2.rend() ? 0 : *(rit2++));
      cur += cf;
      cf = cur / 10;
      cur %= 10;
      tmp = new ListNode(cur);
      tmp->next = head;
      head = tmp;
    }

    return head;
  }
};
// @lc code=end
