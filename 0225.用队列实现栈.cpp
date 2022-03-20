/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 *
 * https://leetcode-cn.com/problems/implement-stack-using-queues/description/
 *
 * algorithms
 * Easy (67.67%)
 * Likes:    456
 * Dislikes: 0
 * Total Accepted:    173K
 * Total Submissions: 255.7K
 * Testcase Example:  '["MyStack","push","push","top","pop","empty"]\n[[],[1],[2],[],[],[]]'
 *
 * 请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（push、top、pop 和 empty）。
 * 
 * 实现 MyStack 类：
 * 
 * 
 * void push(int x) 将元素 x 压入栈顶。
 * int pop() 移除并返回栈顶元素。
 * int top() 返回栈顶元素。
 * boolean empty() 如果栈是空的，返回 true ；否则，返回 false 。
 * 
 * 
 * 
 * 
 * 注意：
 * 
 * 
 * 你只能使用队列的基本操作 —— 也就是 push to back、peek/pop from front、size 和 is empty
 * 这些操作。
 * 你所使用的语言也许不支持队列。 你可以使用 list （列表）或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可。
 * 
 * 
 * 
 * 
 * 示例：
 * 
 * 
 * 输入：
 * ["MyStack", "push", "push", "top", "pop", "empty"]
 * [[], [1], [2], [], [], []]
 * 输出：
 * [null, null, null, 2, 2, false]
 * 
 * 解释：
 * MyStack myStack = new MyStack();
 * myStack.push(1);
 * myStack.push(2);
 * myStack.top(); // 返回 2
 * myStack.pop(); // 返回 2
 * myStack.empty(); // 返回 False
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 1 <= x <= 9
 * 最多调用100 次 push、pop、top 和 empty
 * 每次调用 pop 和 top 都保证栈不为空
 * 
 * 
 * 
 * 
 * 进阶：你能否仅用一个队列来实现栈。
 * 
 */

// @lc code=start
#include <queue>

using namespace std;

class MyStack {
    queue<int> _queue[2];
    int _cur;

public:
    MyStack() : _cur(0) {}
    
    void push(int x) {
        _queue[_cur].push(x);
    }
    
    int pop() {
        auto& queue_out = _queue[_cur];
        auto& queue_in = _queue[(_cur + 1) % 2];
        int last = 0;
        while (!queue_out.empty()) {
            last = queue_out.front();
            queue_out.pop();
            if (queue_out.empty()) {
                break;
            }
            queue_in.push(last);
        }
        _cur = (_cur + 1) % 2;
        return last;
    }
    
    int top() {
        int top = pop();
        _queue[_cur].push(top);
        return top;
    }
    
    bool empty() {
        return _queue[0].empty() && _queue[1].empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end

