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
  string minNumber(vector<int>& nums) {
    vector<string> nums_str;
    for (const int& i : nums) {
      nums_str.push_back(to_string(i));
    }
    sort(nums_str.begin(), nums_str.end(), comp);
    string ret;
    for (const string& s : nums_str) ret += s;
    return ret;
  }

  static bool comp(const string& s1, const string& s2) {
    string s1s2 = s1 + s2;
    string s2s1 = s2 + s1;
    return s1s2 < s2s1;
  }
};