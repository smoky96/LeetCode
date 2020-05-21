#include <algorithm>
#include <deque>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
 public:
  vector<int> reversePrint(ListNode* head) {
    vector<int> ret;
    aux(ret, head);
    return ret;
  }

  void aux(vector<int>& res, ListNode* head) {
    if (head == nullptr) return;
    aux(res, head->next);
    res.push_back(head->val);
  }
};
