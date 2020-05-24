#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p)
    {
        if (p.empty())
            return s.size() == 0;

        // 这里 s 的判空可以优化。将 s.empty() 放到 firstMatch 中判断，调整最后 if else 条件（加上 p.size() >= 2）
        // 并且 return 时，要用到 s.substr() 的判断放在后面，避免出错，因为先判断 s.empty() 的话，如果是空的，就可以直接返回 false 了，避免了空字符串时使用 substr 报错
        // if (s.size() == 0) {
        //     if (p.size() >= 2 && p[1] == '*') {
        //         return isMatch(s, p.substr(2));
        //     } else {
        //         return p.empty();
        //     }
        // }

        // 递归只关注当前状态，其他的交给递归来做
        bool firstMatch = !s.empty() && (s[0] == p[0] || p[0] == '.');

        if (p.size() >= 2 && p[1] == '*') {
            // 如果第二个字符为 *，就要决定是应该让 * 前面的字符重复几次，这里就要用到递归的思想，只关注当前状态，所以将重复几次的决定留给递归来做。
            // 如果重复 0 次，那么就将 * 和其前面的字符去掉，s 保持不变，继续递归的比较两者。如果要重复多次，那么就将 s 往前推进一个字符，p 保持不变，继续递归的比较两者。
            return isMatch(s, p.substr(2)) || (firstMatch && isMatch(s.substr(1), p));
        } else {
            return firstMatch && isMatch(s.substr(1), p.substr(1));
        }
    }

    bool isMatchDpBottomToTop(string s, string p)
    {
        vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
        // 若 s 和 p 都为空，则为真
        s.insert(0, "#");
        p.insert(0, "#");
        dp[0][0] = true;
        // 初始化，若 p 的第二个字符为 * ，那么，只要后面有 * 且在这个 * 的前两个位置字符串是匹配的，那么当前位置字符串依然匹配
        for (int j = 2; j < p.size(); j++) {
            dp[0][j] = p[j] == '*' && dp[0][j - 2];
        }

        for (int i = 1; i < s.size(); i++) {
            for (int j = 1; j < p.size(); j++) {
                // 分两种情况，第一种：当前位置 p 为 . 或者当前位置 p 和 s 相同。第二种：当前位置 p 为 *
                if (p[j] == '.' || s[i] == p[j]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else if (p[j] == '*') {
                    // 这里相当于判断这个 * 是应该重复前面的字符 0 次还是多次。
                    // 第一种是 p 的前一个位置是 . 或者 p 的前一个位置和 s 的当前位置字符相同
                    if (p[j - 1] == '.' || p[j - 1] == s[i]) {
                        // 这里有三种情况都可以让 dp[i][j] 为真，已经有了前提条件：p 的前一个字符串和 s 的当前字符串相等。
                        // 1. s 到前一个位置的字符串和 p 到当前位置的字符串相匹配，因为 p 的当前位置字符为 *，且已知p 的前一个字符串和 s 的当前字符串相等，所以重复 * 前面的字符两次即可。
                        // 2. s 到当前位置的字符串和 p 到前一个位置的字符串相匹配，同样因为 p 的当前位置字符为 *，则重复 * 前面的字符一次即可，也就是相当于 * 不存在。
                        //   （这里 * 和其前面的字符是一个整体。而不是说必须包含 * 前面那个字符，然后在此基础上重复。所以可以重复 0 次，也就是这整个整体都不要了）
                        // 3. p 到前两个位置的字符串如果和 s 到当前位置的字符串匹配的话，也可以使 dp[i][j] 为真，因为 * 可以让 p 前一个字符无效，所以依然是匹配的（重复 0 次）
                        dp[i][j] = dp[i - 1][j] || dp[i][j - 1] || dp[i][j - 2];
                        // 补充：这里其实就是 * 的三种情况，第一种情况是重复两次，第二种情况是重复一次，第三种情况是重复 0 次
                    } else {
                        // 若 p 的前一个字符串和 s 当前字符串不相等。那就只有往 p 前面看两个字符了，如果往 p 前面看两个字符是匹配的，那么 * 可以让其前面的字符重复 0 次，也就是让它无效，结果依然匹配。
                        dp[i][j] = dp[i][j - 2];
                    }
                }
            }
        }
        return dp[s.size() - 1][p.size() - 1];
    }

    bool isMatchDpTopToBottom(string s, string p)
    {
        vector<vector<int>> memo(s.size() + 1, vector<int>(p.size() + 1, 3));
        return (bool)(dp(0, 0, s, p, memo));
    }

    int dp(int i, int j, string s, string p, vector<vector<int>>& memo)
    {
        int ans;
        int firstMatch;

        if (j == p.length()) {
            return (int)i == s.length();
        }
        // if (i == s.length()) {
        //     if (j <= p.length() - 2 && p[j + 1] == '*') {
        //         ans = (int)dp(i, j + 2, s, p, memo);
        //     } else {
        //         ans = 0;
        //     }
        //     memo[i][j] = ans;
        //     return memo[i][j];
        // }

        if (memo[i][j] != 3)
            return memo[i][j];

        firstMatch = (i != s.length()) && (int)(s[i] == p[j] || p[j] == '.');

        if (j <= p.length() - 2 && p[j + 1] == '*') {
            ans = (int)(dp(i, j + 2, s, p, memo) || firstMatch && dp(i + 1, j, s, p, memo));
        } else {
            ans = firstMatch && (int)(dp(i + 1, j + 1, s, p, memo));
        }

        memo[i][j] = ans;

        return memo[i][j];
    }
};

void test(string s, string p)
{
    Solution so;
    cout << "string: " << s << endl;
    cout << "pattern: " << p << endl;
    cout << "is match: " << so.isMatch(s, p) << endl;
    cout << "is match dp (btt): " << so.isMatchDpBottomToTop(s, p) << endl;
    cout << "is match dp (ttb): " << so.isMatchDpTopToBottom(s, p) << endl
         << endl;
}

int main()
{
    string s;
    string p;

    s = "aa";
    p = "a";
    test(s, p);

    s = "aa";
    p = "a*";
    test(s, p);

    s = "ab";
    p = ".*";
    test(s, p);

    s = "aab";
    p = "c*a*b";
    test(s, p);

    s = "mississippi";
    p = "mis*is*p*.";
    test(s, p);

    s = "ab";
    p = ".*c";
    test(s, p);

    s = "";
    p = "c*c*";
    test(s, p);

    cout << "press enter to continue" << endl;
    cin.get();
}