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
  string reverseWords(string s) {
    string word;
    stack<string> stk;

    int len = s.length();
    for (int i = 0; i <= len; ++i) {
      if ((i == len || s[i] == ' ') && word.length() != 0) {
        stk.push(word);
        word.clear();
      } else if (s[i] != ' ') {
        word += s[i];
      }
    }

    string ret;
    while (!stk.empty()) {
      ret += stk.top();
      stk.pop();
      if (stk.empty()) break;
      ret += ' ';
    }
    return ret;
  }
};
