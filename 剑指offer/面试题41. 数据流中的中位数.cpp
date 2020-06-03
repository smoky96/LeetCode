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

using namespace std;

class MedianFinder {
  vector<int> min_heap;
  vector<int> max_heap;

 public:
  /** initialize your data structure here. */
  MedianFinder() {}

  void addNum(int num) {
    int total_size = min_heap.size() + max_heap.size();
    if (total_size & 0x1) {
      if (num > min_heap[0]) {
        int tmp = num;
        pop_heap(min_heap.begin(), min_heap.end(), greater<int>());
        num = min_heap.back();
        min_heap.back() = tmp;
        push_heap(min_heap.begin(), min_heap.end(), greater<int>());
      }
      max_heap.push_back(num);
      push_heap(max_heap.begin(), max_heap.end(), less<int>());
    } else {
      if (min_heap.empty()) {
        min_heap.push_back(num);
      } else {
        if (num < max_heap[0]) {
          int tmp = num;
          pop_heap(max_heap.begin(), max_heap.end(), less<int>());
          num = max_heap.back();
          max_heap.back() = tmp;
          push_heap(max_heap.begin(), max_heap.end(), less<int>());
        }
        min_heap.push_back(num);
        push_heap(min_heap.begin(), min_heap.end(), greater<int>());
      }
    }
  }

  double findMedian() {
    int total_size = min_heap.size() + max_heap.size();
    if (total_size & 0x1) {
      return min_heap[0];
    } else {
      return double(min_heap[0] + max_heap[0]) / 2;
    }
  }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */