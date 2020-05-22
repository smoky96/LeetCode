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

class CQueue {
 private:
  stack<int> stk_in;
  stack<int> stk_out;

 public:
  CQueue() {}

  void appendTail(int value) { stk_in.push(value); }

  int deleteHead() {
    int ret = -1;
    if (!stk_out.empty()) {
      ret = stk_out.top();
      stk_out.pop();
    } else {
      while (stk_in.size() > 1) {
        stk_out.push(stk_in.top());
        stk_in.pop();
      }
      if (stk_in.size() == 1) {
        ret = stk_in.top();
        stk_in.pop();
      }
    }
    return ret;
  }
};
