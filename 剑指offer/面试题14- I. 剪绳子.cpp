class Solution {
 public:
  int cuttingRope(int n) {
    if (n == 2) return 1;
    if (n == 3) return 2;
    int dp[n + 1];
    dp[2] = 2;
    dp[3] = 3;
    for (int i = 4; i <= n; i++) {
      int max = 0;
      for (int j = 2; j <= i / 2; j++) {
        int tmp = dp[j] * dp[i - j];
        if (tmp > max) max = tmp;
      }
      dp[i] = max;
    }
    return dp[n];
  }
};