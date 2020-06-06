#include <math.h>
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
  int countDigitOne(int n) {
    string n_str = to_string(n);
    int ret = 0;
    int len = n_str.length();
    for (int i = 0; i < len; ++i) {
      if (n_str[i] == '0') {
        ret += n / (long)pow(10, (len - i)) * (long)pow(10, (len - i - 1));
      } else if (n_str[i] == '1') {
        ret += (n / (long)pow(10, (len - i)) * (long)pow(10, (len - i - 1))) +
               (n % (long)pow(10, (len - i - 1))) + 1;
      } else {
        ret += (long)((n / pow(10, len - i)) + 1) * pow(10, (len - i - 1));
      }
    }
    return ret;
  }
};
