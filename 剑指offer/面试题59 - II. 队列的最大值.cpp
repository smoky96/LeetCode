#include <stdio.h>

#include <algorithm>
#include <deque>
#include <iostream>
#include <iterator>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

#define PRINT_ARY(container, value_type)           \
  do {                                             \
    copy(container.begin(), container.end(),       \
         ostream_iterator<value_type>(cout, " ")); \
    cout << endl;                                  \
  } while (0)

using namespace std;

class MaxQueue {
  deque<int> que;
  deque<int> max_deq;

 public:
  MaxQueue() {}

  int max_value() {
    if (max_deq.empty()) return -1;
    return max_deq.front();
  }

  void push_back(int value) {
    while (!max_deq.empty() && max_deq.back() < value) max_deq.pop_back();
    max_deq.push_back(value);
    que.push_back(value);
  }

  int pop_front() {
    if (que.empty()) return -1;
    int ret = que.front();
    que.pop_front();
    if (ret == max_deq.front()) max_deq.pop_front();
    return ret;
  }
};
