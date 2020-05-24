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
  int hammingWeight(int n) {
    int cnt = 0;
    while (n) {
      ++cnt;
      n = (n - 1) & n;
    }
    return cnt;
  }
};

int main(int argc, char **argv) {
  Solution s;
  cout << s.hammingWeight(-1) << endl;

  return 0;
}
