/*
 * @lc app=leetcode.cn id=43 lang=cpp
 *
 * [43] 字符串相乘
 *
 * https://leetcode-cn.com/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (40.16%)
 * Likes:    233
 * Dislikes: 0
 * Total Accepted:    33.6K
 * Total Submissions: 82.3K
 * Testcase Example:  '"2"\n"3"'
 *
 * 给定两个以字符串形式表示的非负整数 num1 和 num2，返回 num1 和 num2 的乘积，它们的乘积也表示为字符串形式。
 * 
 * 示例 1:
 * 
 * 输入: num1 = "2", num2 = "3"
 * 输出: "6"
 * 
 * 示例 2:
 * 
 * 输入: num1 = "123", num2 = "456"
 * 输出: "56088"
 * 
 * 说明：
 * 
 * 
 * num1 和 num2 的长度小于110。
 * num1 和 num2 只包含数字 0-9。
 * num1 和 num2 均不以零开头，除非是数字 0 本身。
 * 不能使用任何标准库的大数类型（比如 BigInteger）或直接将输入转换为整数来处理。
 * 
 * 
 */

// @lc code=start
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2)
    {
        if ((num1.size() == 1 && !stoi(num1)) || (num2.size() == 1 && !stoi(num2))) {
            return "0";
        }
        if (num1.size() > num2.size()) {
            swap(num1, num2);
        }
        int num_i;
        int num_j;
        int k;
        int tmp;
        int carry;
        int count = 0;
        vector<string> results;

        for (int i = num1.size() - 1; i >= 0; --i) {
            string res;
            num_i = num1[i] - '0';
            carry = 0;
            for (int j = num2.size() - 1; j >= 0; --j) {
                num_j = num2[j] - '0';
                tmp = num_i * num_j + carry;
                carry = tmp / 10;
                res = static_cast<char>('0' + (tmp % 10)) + res;
            }
            if (carry > 0) {
                res = static_cast<char>('0' + carry) + res;
            }
            for (k = 0; k < count; ++k) {
                res += "0";
            }
            ++count;
            results.push_back(res);
            res.clear();
        }

        int res_len = num1.size() + num2.size();
        string res(res_len, '0');
        for (string s : results) {
            res_len = res.size();
            k = s.size();
            while (k--) {
                --res_len;
                tmp = (res[res_len] - '0') + (s[k] - '0');
                res[res_len] = '0' + (tmp % 10);
                if (res_len > 0)
                    res[res_len - 1] += tmp / 10;
            }
        }
        for (int i = 0; i < res.size(); ++i) {
            if (res[i] != '0') {
                return res.substr(i);
            }
        }
        return res;
    }
};

/* string stringToString(string input) {
    assert(input.length() >= 2);
    string result;
    for (int i = 1; i < input.length() -1; i++) {
        char currentChar = input[i];
        if (input[i] == '\\') {
            char nextChar = input[i+1];
            switch (nextChar) {
                case '\"': result.push_back('\"'); break;
                case '/' : result.push_back('/'); break;
                case '\\': result.push_back('\\'); break;
                case 'b' : result.push_back('\b'); break;
                case 'f' : result.push_back('\f'); break;
                case 'r' : result.push_back('\r'); break;
                case 'n' : result.push_back('\n'); break;
                case 't' : result.push_back('\t'); break;
                default: break;
            }
            i++;
        } else {
          result.push_back(currentChar);
        }
    }
    return result;
}

int main() {
    string line;
    while (getline(cin, line)) {
        string num1 = stringToString(line);
        getline(cin, line);
        string num2 = stringToString(line);
        
        string ret = Solution().multiply(num1, num2);

        string out = (ret);
        cout << out << endl;
    }
    return 0;
} */
// @lc code=end
