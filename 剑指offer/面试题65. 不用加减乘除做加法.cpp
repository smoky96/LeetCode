class Solution {
 public:
  int add(int a, int b) {
    int sum = 0;
    int carry = 0;
    do {
      carry = (unsigned int)(a & b) << 1;
      a ^= b;
      b = carry;
    } while (carry != 0);
    return a;
  }
};