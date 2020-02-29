#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int reverse(int x)
    {
        int reversed = 0;

        while (x != 0) {
            // 当 reversed * 10 + X % 10 >= INT32_MAX 或 <= INT32_MIN 时，溢出。
            // 也就是 reversed > INT32_MAX / 10 或 reversed == INT32_MAX / 10 且 x % 10 > 7 时 返回0; 负数情况同理
            if (reversed > (INT32_MAX / 10) || (reversed == INT32_MAX / 10 && x % 10 > 7)) return 0;
            if (reversed < (INT32_MIN / 10) || (reversed == INT32_MIN / 10 && x % 10 < -8)) return 0;
            reversed = reversed * 10 + x % 10;
            x = x / 10;
        }

        return reversed;
    }
};

void test(int x)
{
    Solution so;
    int reversed;
    cout << "x: " << x << endl;
    reversed = so.reverse(x);
    cout << "reversed: " << reversed << endl;
}

int main()
{
    int x = 2147483647;
    test(x);

    x = 12345;
    test(x);

    x = -12345;
    test(x);

    x = 1463847412;
    test(x);

    cout << "press enter to continue" << endl;
    cin.get();
}