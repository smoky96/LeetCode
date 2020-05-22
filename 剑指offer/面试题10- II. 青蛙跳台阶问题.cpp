class Solution {
 public:
  int numWays(int n) {
    if (n < 2) return 1;
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