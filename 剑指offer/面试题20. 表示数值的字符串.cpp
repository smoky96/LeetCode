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
  bool isNumber(string s) {
    if (s.empty()) return false;
    size_t* idx = new size_t(0);
    rmSpace(s, idx);
    bool is_numeric = isInt(s, idx);

    if (s[*idx] == '.') {
      ++(*idx);
      is_numeric = isUnsignedInt(s, idx) || is_numeric;
    }

    if (s[*idx] == 'e') {
      ++(*idx);
      is_numeric = is_numeric && isInt(s, idx);
    }

    if (*idx != s.length() && !leftSpace(s, idx)) {
      is_numeric = false;
    }
    delete idx;
    return is_numeric;
  }

  void rmSpace(const string& s, size_t* idx) {
    while (s[*idx] == ' ') ++(*idx);
  }

  bool leftSpace(const string& s, size_t* idx) {
    while (*idx != s.length() && s[*idx] == ' ') {
      ++(*idx);
    }
    return *idx == s.length();
  }

  bool isUnsignedInt(const string& s, size_t* idx) {
    size_t start = *idx;
    while (*idx != s.length() && s[*idx] >= '0' && s[*idx] <= '9') {
      ++(*idx);
    }
    return start != *idx;
  }

  bool isInt(const string& s, size_t* idx) {
    if (s[*idx] == '+' || s[*idx] == '-') ++(*idx);

    return isUnsignedInt(s, idx);
  }
};