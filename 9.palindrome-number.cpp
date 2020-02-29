#include <cmath>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        int tmp = x;
        int count = 0;
        while (tmp != 0) {
            count += 1;
            tmp /= 10;
        }
        while(count > 1) {
            // 永远不要比较浮点数!!!!
            if (x % 10 == x / (int) pow(10, count - 1)) {
                x = x % (int) pow(10, count - 1);
                x = x / 10;
                count -= 2;
            } else return false;
        }
        return true;
    }
};

void test(int x)
{
    Solution so;
    bool ansmer;
    cout << "number: " << x << endl;
    ansmer = so.isPalindrome(x);
    cout << "is palindrome: " << ansmer << endl;
}

int main()
{
    int x = 12344321;
    test(x);

    x = 234432;
    test(x);

    x = -12344321;
    test(x);

    x = 1463847412;
    test(x);

    cout << "press enter to continue" << endl;
    cin.get();
}