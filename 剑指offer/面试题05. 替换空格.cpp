#include <algorithm>
#include <deque>
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
  string replaceSpace(string s) {
    int len = s.length();
    if (len == 0) return s;
    int new_len = len;
    for (int i = 0; i < len; ++i) {
      if (s[i] == ' ') {
        new_len += 2;
      }
    }

    s.resize(new_len);

    int p_orig = len - 1;
    int p_new = new_len - 1;
    while (p_orig != p_new) {
      if (s[p_orig] == ' ') {
        s[p_new--] = '0';
        s[p_new--] = '2';
        s[p_new--] = '%';
        --p_orig;
      } else {
        s[p_new--] = s[p_orig--];
      }
    }
    return s;
  }
};