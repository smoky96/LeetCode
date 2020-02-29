/*
 * @lc app=leetcode.cn id=138 lang=cpp
 *
 * [138] 复制带随机指针的链表
 *
 * https://leetcode-cn.com/problems/copy-list-with-random-pointer/description/
 *
 * algorithms
 * Medium (35.63%)
 * Likes:    185
 * Dislikes: 0
 * Total Accepted:    18.4K
 * Total Submissions: 42.6K
 * Testcase Example:  '[[7,null],[13,0],[11,4],[10,2],[1,0]]\r'
 *
 * 给定一个链表，每个节点包含一个额外增加的随机指针，该指针可以指向链表中的任何节点或空节点。
 *
 * 要求返回这个链表的 深拷贝。 
 *
 * 我们用一个由 n 个节点组成的链表来表示输入/输出中的链表。每个节点用一个 [val,
 * random_index] 表示：
 *
 *
 * val：一个表示 Node.val 的整数。
 * random_index：随机指针指向的节点索引（范围从 0 到 n-1）；如果不指向任何节点，则为  null 。
 *
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：head = [[7,null],[13,0],[11,4],[10,2],[1,0]]
 * 输出：[[7,null],[13,0],[11,4],[10,2],[1,0]]
 *
 *
 * 示例 2：
 *
 *
 *
 * 输入：head = [[1,1],[2,1]]
 * 输出：[[1,1],[2,1]]
 *
 *
 * 示例 3：
 *
 *
 *
 * 输入：head = [[3,null],[3,0],[3,null]]
 * 输出：[[3,null],[3,0],[3,null]]
 *
 *
 * 示例 4：
 *
 * 输入：head = []
 * 输出：[]
 * 解释：给定的链表为空（空指针），因此返回 null。
 *
 *
 *
 *
 * 提示：
 *
 *
 * -10000 <= Node.val <= 10000
 * Node.random 为空（null）或指向链表中的节点。
 * 节点数目不超过 1000 。
 *
 *
 */

// @lc code=start

// Definition for a Node.
/* #include <cstdlib>
class Node {
 public:
  int val;
  Node* next;
  Node* random;

  Node(int _val) {
    val = _val;
    next = NULL;
    random = NULL;
  }
};
 */
#include <map>
using namespace std;

class Solution {
 public:
  Node* copyRandomList(Node* head) {
    if (head == NULL) {
      return NULL;
    }
    Node* cur = head;
    map<Node*, Node*> copy;
    while (cur != NULL) {
      if (copy.find(cur) == copy.end()) {
        copy[cur] = new Node(cur->val);
      }
      if (copy.find(cur->next) == copy.end()) {
        if (cur->next != NULL) {
          copy[cur]->next = new Node(cur->next->val);
          copy[cur->next] = copy[cur]->next;
        } else {
          copy[cur->next] = NULL;
        }
      } else {
        copy[cur]->next = copy[cur->next];
      }
      if (copy.find(cur->random) == copy.end()) {
        if (cur->random != NULL) {
          copy[cur]->random = new Node(cur->random->val);
          copy[cur->random] = copy[cur]->random;
        } else {
          copy[cur->random] = NULL;
        }
      } else {
        copy[cur]->random = copy[cur->random];
      }
      cur = cur->next;
    }
    return copy[head];
  }
};
// @lc code=end
