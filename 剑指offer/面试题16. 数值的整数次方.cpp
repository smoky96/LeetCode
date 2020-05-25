#include <limits>

class Solution {
 public:
  double myPow(double x, int n) {
    if (x == 0 && n < 0) {
      return std::numeric_limits<double>::infinity();
    }
    unsigned int abs_n = (unsigned int)n;
    if (n < 0) {
      abs_n = -abs_n;
    }
    double ret = aux(x, abs_n);
    return n < 0 ? 1 / ret : ret;
  }

 private:
  double aux(double x, unsigned int n) {
    if (n == 0) return 1;
    if (n == 1) return x;

    double ret = aux(x, n >> 1);
    ret *= ret;
    return n & 0x1 ? ret * x : ret;
  }
};