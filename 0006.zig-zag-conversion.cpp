#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows)
    {
        // 这里每一个vector都是一个string，而string也算一维，所以相当于二维vector
        vector<string> zigZag(numRows);
        int row = -1;
        int p = 0;
        bool down = true;

        while (true) {
            if (numRows == 1) {
                return s;
            }
            
            if (row == 0) {
                down = true;
            } else if (row == numRows - 1) {
                down = false;
            }

            if (down && p < s.size()) {
                zigZag[++row].push_back(s[p++]);
            } else if (!down && p < s.size()) {
                zigZag[--row].push_back(s[p++]);
            } else
                break;
        }

        // 输出时，只要将每个vector存储的string按顺序输出就可以了
        string ret;
        for (int i = 0; i < numRows; i++) {
            ret += zigZag[i];
        }
        return ret;
    }
};

void test(string s, int numRows)
{
    Solution so;
    string zigZag;
    cout << "string: " << s << endl;
    zigZag = so.convert(s, numRows);
    cout << "zig zag oreder: " << zigZag << endl;
}

int main()
{
    string s;

    s = "AB";
    test(s, 1);

    cout << "press enter to continue" << endl;
    cin.get();
}