#include <math.h>

#include <string>

using namespace std;

class Solution {
 public:
  int findNthDigit(int n) {
    int digit_len = 1;
    long base = 1;
    long cnt = 9;
    while (n > cnt) {
      n -= cnt;
      digit_len += 1;
      base *= 10;
      cnt = digit_len * base * 9;
    }
    long num = base + (n - 1) / digit_len;
    return to_string(num)[(n - 1) % digit_len] - '0';
  }
};