#include <stdio.h>

#include <algorithm>
#include <deque>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
 public:
  bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    if (popped.size() == 0) return true;
    if (pushed.size() == 0) return false;

    stack<int> s;
    int idx = 0;
    for (int i = 0; i < popped.size(); ++i) {
      if (!s.empty()) {
        if (popped[i] == s.top()) {
          s.pop();
          continue;
        } else {
          while (idx < pushed.size() && pushed[idx] != popped[i]) {
            s.push(pushed[idx++]);
          }
          if (idx == pushed.size()) return false;
          ++idx;
        }
      } else {
        s.push(pushed[idx++]);
        --i;
      }
    }
    return true;
  }
};