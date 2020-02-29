#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestPalindrome1(string s)
    {
        int n = s.length();
        string lp = "";
        int start;
        int end;
        int tmpLen;
        int breakFlag;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                tmpLen = 0;
                breakFlag = 0;
                start = i;
                end = j;
                while (start < end) {
                    if (s[start] == s[end]) {
                        tmpLen = tmpLen + 1;
                        start = start + 1;
                        end = end - 1;
                    } else {
                        breakFlag = 1;
                        break;
                    }
                }
                if (breakFlag == 0) {
                    tmpLen = j - i + 1;
                    lp = tmpLen > lp.length() ? s.substr(i, tmpLen) : lp;
                }
            }
        }
        return lp;
    }

    string longestPalindrome2(string s)
    {
        int n = s.length();
        string lp = "";
        int front;
        int rear;
        int tmpLen;
        // 以字符为中心
        for (int i = 0; i < n; i++) {
            front = i;
            rear = i;
            while (front >= 0 && rear < n) {
                if (s[front] == s[rear]) {
                    front = front - 1;
                    rear = rear + 1;
                } else {
                    break;
                }
            }
            tmpLen = rear - front - 1;
            lp = tmpLen > lp.length() ? s.substr(front + 1, tmpLen) : lp;
        }
        // 以两字符中间为中心
        for (int i = 0; i < (n - 1); i++) {
            front = i;
            rear = i + 1;
            while (front >= 0 && rear < n) {
                if (s[front] == s[rear]) {
                    front = front - 1;
                    rear = rear + 1;
                } else {
                    break;
                }
            }
            tmpLen = (rear - front - 1);
            lp = tmpLen > lp.length() ? s.substr(front + 1, tmpLen) : lp;
        }
        return lp;
    }

    string longestPalindrome3(string s)
    {
        int n = s.length();
        int start = 0;
        int maxLength = 1;
        vector<vector<int>> dp(n, vector<int>(n, 0));

        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
            if (s[i] == s[i + 1]) {
                dp[i][i + 1] = 1;
                maxLength = 2;
                start = i;
            }
        }
    
        for (int len = 3; len <= n; len++) {
            for (int i = 0; i < (n - len + 1); i++) {
                int j = i + len - 1;
                if (s[i] == s[j] && dp[i + 1][j - 1]) {
                    dp[i][j] = 1;
                    maxLength = len;
                    start = i;
                }
            }
        }
        
        return s.substr(start, maxLength);
    }
};

void test(string s)
{
    Solution so;
    string sub1, sub2, sub3;
    cout << "string: " << s << endl;
    sub1 = so.longestPalindrome1(s);
    sub2 = so.longestPalindrome2(s);
    sub3 = so.longestPalindrome3(s);
    cout << "longest palindromic with solution 1: " << sub1 << endl;
    cout << "longest palindromic with solution 2: " << sub2 << endl;
    cout << "longest palindromic with solution 3: " << sub3 << endl
         << endl;
}

int main()
{
    string s;

    s = "babad";
    test(s);

    s = "cbbd";
    test(s);

    s = "d";
    test(s);

    s = "";
    test(s);

    s = "aaaaa";
    test(s);

    test(s);
    s = "yilonjvrlpcoylnehfpnysarwegmctgvfidetvpnhooihwnpxd";
    test(s);

    test(s);
    s = "drpcknxvzxtnygmybnkl";
    test(s);

    cout << "press enter to continue" << endl;
    cin.get();
}