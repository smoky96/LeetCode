/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 *
 * https://leetcode-cn.com/problems/min-stack/description/
 *
 * algorithms
 * Easy (51.58%)
 * Likes:    383
 * Dislikes: 0
 * Total Accepted:    74.2K
 * Total Submissions: 143.7K
 * Testcase Example:
 '["MinStack","push","push","push","getMin","pop","top","getMin"]\n' +
  '[[],[-2],[0],[-3],[],[],[],[]]'
 *
 * 设计一个支持 push，pop，top 操作，并能在常数时间内检索到最小元素的栈。
 *
 *
 * push(x) -- 将元素 x 推入栈中。
 * pop() -- 删除栈顶的元素。
 * top() -- 获取栈顶元素。
 * getMin() -- 检索栈中的最小元素。
 *
 *
 * 示例:
 *
 * MinStack minStack = new MinStack();
 * minStack.push(-2);
 * minStack.push(0);
 * minStack.push(-3);
 * minStack.getMin();   --> 返回 -3.
 * minStack.pop();
 * minStack.top();      --> 返回 0.
 * minStack.getMin();   --> 返回 -2.
 *
 *
 */

// @lc code=start
#include <algorithm>
#include <climits>
#include <cstdio>
#include <deque>
#include <list>
#include <map>
#include <memory>
#include <vector>
using namespace std;

class MinStack {
 private:
  struct node {
    int data;
    int min;

    unique_ptr<node> next;
    // 不要 delete prev ！
    node* prev;
    node(int d, int m) : data(d), min(m), next(nullptr), prev(nullptr) {}
  };

  unique_ptr<node> st;
  // 不要 delete top !
  node* __top;

 public:
  /** initialize your data structure here. */
  MinStack() : st(new node(INT_MIN, INT_MAX)) { __top = st.get(); }

  void push(int x) {
    int min = x < __top->min ? x : __top->min;
    __top->next.reset(new node(x, min));
    auto* tmp = __top;
    __top = __top->next.get();
    __top->prev = tmp;
    // debug();
  }

  void pop() {
    __top = __top->prev;
    __top->next.reset();
    // debug();
  }

  int top() {
    return __top->data;
    // debug();
  }

  int getMin() {
    return __top->min;
    // debug();
  }

  //   void debug() {
  //     printf("queue(%d): ", qu.size());
  //     for (auto q : qu) {
  //       printf("%d ", *q);
  //     }

  //     printf("sorted(%d): ", sorted.size());
  //     for (auto s : sorted) {
  //       printf("%d ", *s);
  //     }
  //     cout << endl;
  //   }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end
