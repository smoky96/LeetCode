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
  int nthUglyNumber(int n) {
    if (n == 0) return 0;
    vector<int> ugly_num(n);
    ugly_num[0] = 1;
    auto cur2 = ugly_num.begin();
    auto cur3 = ugly_num.begin();
    auto cur5 = ugly_num.begin();
    int i = 0;
    while (i < n - 1) {
      ugly_num[++i] = min(*cur2 * 2, min(*cur3 * 3, *cur5 * 5));
      while (*cur2 * 2 <= ugly_num[i]) ++cur2;
      while (*cur3 * 3 <= ugly_num[i]) ++cur3;
      while (*cur5 * 5 <= ugly_num[i]) ++cur5;
    }
    return ugly_num[n - 1];
  }
};