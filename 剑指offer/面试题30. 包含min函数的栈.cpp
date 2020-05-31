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

class MinStack {
  stack<int> s;
  stack<int> min_s;

 public:
  /** initialize your data structure here. */
  MinStack() {}

  void push(int x) {
    s.push(x);
    if (min_s.empty()) {
      min_s.push(x);
    } else if (min_s.top() < x) {
      min_s.push(min_s.top());
    } else {
      min_s.push(x);
    }
  }

  void pop() {
    s.pop();
    min_s.pop();
  }

  int top() { return s.top(); }

  int min() { return min_s.top(); }
};