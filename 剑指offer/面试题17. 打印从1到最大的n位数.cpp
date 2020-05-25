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
  void printNumbers(int n) {
    string s;
    for (int i = 0; i < n; ++i) {
      s += '0';
    }
    aux(s, 0);
  }

  void aux(string& s, int idx) {
    if (idx == s.length()) {
      print(s);
      return;
    }

    for (int i = 0; i < 10; ++i) {
      s[idx] = '0' + i;
      aux(s, idx + 1);
    }
  }

  void print(const string& s) {
    int i = 0;
    int len = s.length();
    for (; i < len && s[i] == '0'; ++i)
      ;
    if (i < len) cout << s.substr(i) << endl;
  }
};