class Solution {
 public:
  int fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    int dp_i = 0;
    int dp_j = 1;
    int ret;
    for (int i = 2; i <= n; ++i) {
      ret = (dp_i + dp_j) % 1000000007;
      dp_i = dp_j;
      dp_j = ret;
    }
    return ret;
  }
};
