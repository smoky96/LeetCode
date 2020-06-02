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
  vector<string> permutation(string s) {
    vector<string> ans;
    sort(s.begin(), s.end());
    aux(s, 0, ans);
    return ans;
  }

  void aux(string s, int start, vector<string>& ans) {
    if (start == s.length()) {
      ans.push_back(s);
      return;
    }
    int len = s.length();
    for (int i = start; i < len; ++i) {
      if (i > start && s[i] == s[start]) continue;
      swap(s[i], s[start]);
      aux(s, start + 1, ans);
    }
  }
};