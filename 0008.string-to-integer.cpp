#include <climits>
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int myAtoi(string str)
    {
        int i = 0;
        int syb = 1;
        int ret = 0;

        while (str[i] == ' ')
            i++;

        if (str[i] != '+' && str[i] != '-' && (str[i] < '0' && str[i] > '9'))
            return 0;
        if (str[i] == '-') {
            syb = -1;
            i += 1;
        } else if (str[i] == '+') {
            i += 1;
        }

        while (str[i] >= '0' && str[i] <= '9' && i < str.size()) {
            if (syb == 1 && (ret > INT32_MAX / 10 || (ret == INT32_MAX / 10 && str[i] > '6')))
                return INT32_MAX;
            if (syb == -1 && (ret > INT32_MAX / 10 || (ret == INT32_MAX / 10 && str[i] > '7')))
                return INT32_MIN;

            ret = ret * 10 + (str[i++] - '0');
        }

        return syb * ret;
    }
};

void test(string str)
{
    Solution so;
    int atoi;
    cout << "str: " << str << endl;
    atoi = so.myAtoi(str);
    cout << "atoi: " << atoi << endl;
}

int main()
{
    string str;
    str = "43";
    test(str);

    str = "+43";
    test(str);

    str = "-43";
    test(str);

    str = "";
    test(str);

    str = " ";
    test(str);

    str = "  +123ads";
    test(str);

    str = "  -123ads";
    test(str);

    str = "  + 345 fds";
    test(str);

    str = "  we can 123";
    test(str);

    str = "  +we can 3";
    test(str);

    str = " 23456789876543";
    test(str);

    str = " -23456789876543";
    test(str);

    str = "-2147483648";
    test(str);

    str = "2147483648";
    test(str);

    cout << "press enter to continue" << endl;
    cin.get();
}