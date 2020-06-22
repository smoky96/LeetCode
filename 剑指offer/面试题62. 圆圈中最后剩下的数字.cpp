class Solution {
 public:
  int lastRemaining(int n, int m) {
    int i = 0;
    for (int j = 2; j <= n; ++j) {
      i = (i + m) % j;
    }
    return i;
  }
};