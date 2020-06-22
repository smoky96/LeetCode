#include <iostream>
#include <vector>
#include <deque>
#include <list>
#include <stack>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iterator>
#include <stdio.h>

#define PRINT_ARY(container, value_type)           \
  do {                                             \
    copy(container.begin(), container.end(),       \
         ostream_iterator<value_type>(cout, " ")); \
    cout << endl;                                  \
  } while (0)

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int len = prices.size();
      if (len < 2) return 0;
      int low = prices[0];
      int max_profit = 0;
      for (int i = 1; i < len; ++i) {
        int tmp = prices[i] - low;
        max_profit = tmp > max_profit ?  tmp : max_profit;
        low = prices[i] < low ? prices[i] : low;
      }
      return max_profit;
    }
};