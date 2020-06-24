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

class Solution {
 public:
  vector<int> constructArr(vector<int>& a) {
    int len = a.size();
    if (len == 0) return {};
    vector<int> b(len, 1);
    for (int i = 1; i < len; ++i) {
      b[i] = b[i - 1] * a[i - 1];
    }
    int tmp = 1;
    for (int i = len - 2; i >= 0; --i) {
      tmp *= a[i + 1];
      b[i] *= tmp;
    }
    return b;
  }
};