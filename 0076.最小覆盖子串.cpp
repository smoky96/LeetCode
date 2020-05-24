/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 *
 * https://leetcode-cn.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (36.07%)
 * Likes:    274
 * Dislikes: 0
 * Total Accepted:    17.4K
 * Total Submissions: 50.2K
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * 给你一个字符串 S、一个字符串 T，请在字符串 S 里面找出：包含 T 所有字母的最小子串。
 * 
 * 示例：
 * 
 * 输入: S = "ADOBECODEBANC", T = "ABC"
 * 输出: "BANC"
 * 
 * 说明：
 * 
 * 
 * 如果 S 中不存这样的子串，则返回空字符串 ""。
 * 如果 S 中存在这样的子串，我们保证它是唯一的答案。
 * 
 * 
 */

// @lc code=start
#include <deque>
#include <map>
#include <string>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t)
    {
        int start;
        int end;
        int next;
        int i;
        int match = 0;
        map<char, int> t_map;
        for (auto c : t) {
            ++t_map[c];
        }
        deque<int> pos;
        map<char, int> tmp;
        string ans;
        for (i = 0; i < s.size(); ++i) {
            if (t_map.find(s[i]) != t_map.end()) {
                next = i;
                if (++tmp[s[next]] == t_map[s[i]]) {
                    ++match;
                }
                pos.push_back(next);
                break;
            }
        }
        if (i == s.size()) {
            return ans;
        }
        if (match == t_map.size()) {
            return t;
        }
        end = next;
        while (i < s.size()) {
            start = next;
            for (i = end + 1; i < s.size(); ++i) {
                if (t_map.find(s[i]) != t_map.end()) {
                    if (++tmp[s[i]] == t_map[s[i]]) {
                        ++match;
                    }
                    end = i;
                    pos.push_back(i);
                    while (match == t_map.size()) {
                        start = pos[0];
                        if ((end - start + 1) < ans.size() || ans.size() == 0) {
                            ans = s.substr(start, (end - start + 1));
                        }

                        pos.pop_front();
                        next = *(pos.begin());
                        if (--tmp[s[start]] < t_map[s[start]]) {
                            --match;
                        }
                    }
                    break;
                }
            }
        }
        return ans;
    }
};
// @lc code=end
