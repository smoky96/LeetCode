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
  vector<int> getLeastNumbers(vector<int>& arr, int k) {
    vector<int> heap;
    for (int& i : arr) {
      heap.push_back(i);
      push_heap(heap.begin(), heap.end());
      if (heap.size() > k) {
        pop_heap(heap.begin(), heap.end());
        heap.pop_back();
      }
    }
    return heap;
  }
};