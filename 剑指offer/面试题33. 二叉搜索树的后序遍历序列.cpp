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
  bool verifyPostorder(vector<int>& postorder) {
    return aux(postorder, 0, postorder.size());
  }

  bool aux(const vector<int>& postorder, int first, int last) {
    if (first >= last) return true;
    int root = postorder[last - 1];

    int i = first;
    for (; i < last - 1; ++i) {
      if (postorder[i] > root) break;
    }
    int j = i;
    for (; j < last - 1; ++j) {
      if (postorder[j] < root) return false;
    }
    return aux(postorder, first, i) && aux(postorder, i, j);
  }
};