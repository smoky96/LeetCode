/*
 * @lc app=leetcode.cn id=17 lang=cpp
 *
 * [17] 电话号码的字母组合
 *
 * https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/description/
 *
 * algorithms
 * Medium (50.61%)
 * Likes:    491
 * Dislikes: 0
 * Total Accepted:    56.6K
 * Total Submissions: 110.1K
 * Testcase Example:  '"23"'
 *
 * 给定一个仅包含数字 2-9 的字符串，返回所有它能表示的字母组合。
 * 
 * 给出数字到字母的映射如下（与电话按键相同）。注意 1 不对应任何字母。
 * 
 * 
 * 
 * 示例:
 * 
 * 输入："23"
 * 输出：["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
 * 
 * 
 * 说明:
 * 尽管上面的答案是按字典序排列的，但是你可以任意选择答案输出的顺序。
 * 
 */

// @lc code=start
#include <map>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> res;
        vector<string> comp;
        if (digits.size() == 0) {
            return res;
        }
        vector<string> alpha_list{ "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };

        int idx;
        for (int i = 0; i < digits.size(); i++) {
            idx = digits[i] - '2';
            comp.push_back(alpha_list[idx]);
        }
        res = getSub(comp, 0);
        return res;
    }

    vector<string> getSub(vector<string> list, int start)
    {
        vector<string> ret;
        vector<string> sub_string;
        if (start == list.size()) {
            ret.push_back("");
            return ret;
        } else {
            for (char c : list[start]) {
                sub_string = getSub(list, start + 1);
                for (string s : sub_string)
                    ret.push_back(c + s);
            }
            return ret;
        }
    }
};
// @lc code=end
