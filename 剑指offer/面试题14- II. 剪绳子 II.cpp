#define ull unsigned long long

class Solution {
 public:
  int cuttingRope(int n) {
    if (n == 2) return 1;
    if (n == 3) return 2;
    int rem = n % 3;
    if (rem == 2) {
      return pow(3, n / 3) * 2 % 1000000007;
    } else if (rem == 1) {
      return pow(3, (n / 3) - 1) * 4 % 1000000007;
    }
    return pow(3, n / 3);
  }
  ull pow(int x, int n) {
    ull ret = 1;
    for (int i = 0; i < n; ++i) {
      ret = (ret * x) % 1000000007;
    }
    return ret;
  }
};
