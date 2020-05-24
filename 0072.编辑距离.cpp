/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 *
 * https://leetcode-cn.com/problems/edit-distance/description/
 *
 * algorithms
 * Hard (53.75%)
 * Likes:    420
 * Dislikes: 0
 * Total Accepted:    21K
 * Total Submissions: 38K
 * Testcase Example:  '"horse"\n"ros"'
 *
 * 给定两个单词 word1 和 word2，计算出将 word1 转换成 word2 所使用的最少操作数 。
 * 
 * 你可以对一个单词进行如下三种操作：
 * 
 * 
 * 插入一个字符
 * 删除一个字符
 * 替换一个字符
 * 
 * 
 * 示例 1:
 * 
 * 输入: word1 = "horse", word2 = "ros"
 * 输出: 3
 * 解释: 
 * horse -> rorse (将 'h' 替换为 'r')
 * rorse -> rose (删除 'r')
 * rose -> ros (删除 'e')
 * 
 * 
 * 示例 2:
 * 
 * 输入: word1 = "intention", word2 = "execution"
 * 输出: 5
 * 解释: 
 * intention -> inention (删除 't')
 * inention -> enention (将 'i' 替换为 'e')
 * enention -> exention (将 'n' 替换为 'x')
 * exention -> exection (将 'n' 替换为 'c')
 * exection -> execution (插入 'u')
 * 
 * 
 */

// @lc code=start
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2)
    {
        vector<vector<int>> memo(word1.length(), vector<int>(word2.length(), -1));
        int i = word1.length() - 1;
        int j = word2.length() - 1;
        return dp(i, j, memo, word1, word2);
    }

    int dp(int i, int j, vector<vector<int>>& memo, const string& word1, const string& word2)
    {
        if (i == -1) {
            return j + 1;
        }
        if (j == -1) {
            return i + 1;
        }

        if (memo[i][j] != -1) {
            return memo[i][j];
        }

        if (word1[i] == word2[j]) {
            memo[i][j] = dp(i - 1, j - 1, memo, word1, word2);
            return memo[i][j];
        }
        int tmp1, tmp2, tmp3;
        tmp1 = 1 + dp(i - 1, j - 1, memo, word1, word2);
        tmp2 = 1 + dp(i - 1, j, memo, word1, word2);
        tmp3 = 1 + dp(i, j - 1, memo, word1, word2);
        memo[i][j] = tmp1 < tmp2 ? tmp1 : tmp2;
        memo[i][j] = memo[i][j] < tmp3 ? memo[i][j] : tmp3;
        return memo[i][j];
    }
};
// @lc code=end
