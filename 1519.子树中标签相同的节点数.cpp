/*
 * @lc app=leetcode.cn id=1519 lang=cpp
 *
 * [1519] 子树中标签相同的节点数
 *
 * https://leetcode-cn.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/description/
 *
 * algorithms
 * Medium (25.26%)
 * Likes:    29
 * Dislikes: 0
 * Total Accepted:    3.3K
 * Total Submissions: 12.9K
 * Testcase Example:  '7\n[[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]]\n"abaedcd"'
 *
 * 给你一棵树（即，一个连通的无环无向图），这棵树由编号从 0  到 n - 1 的 n
 * 个节点组成，且恰好有 n - 1 条 edges 。树的根节点为节点 0
 * ，树上的每一个节点都有一个标签，也就是字符串 labels 中的一个小写字符（编号为
 * i 的 节点的标签就是 labels[i] ）
 *
 * 边数组 edges 以 edges[i] = [ai, bi] 的形式给出，该格式表示节点 ai 和 bi
 * 之间存在一条边。
 *
 * 返回一个大小为 n 的数组，其中 ans[i] 表示第 i 个节点的子树中与节点 i
 * 标签相同的节点数。
 *
 * 树 T 中的子树是由 T 中的某个节点及其所有后代节点组成的树。
 *
 *
 *
 * 示例 1：
 *
 *
 *
 * 输入：n = 7, edges = [[0,1],[0,2],[1,4],[1,5],[2,3],[2,6]], labels =
 * "abaedcd" 输出：[2,1,1,1,1,1,1] 解释：节点 0 的标签为 'a' ，以 'a'
 * 为根节点的子树中，节点 2 的标签也是 'a' ，因此答案为 2
 * 。注意树中的每个节点都是这棵子树的一部分。
 * 节点 1 的标签为 'b' ，节点 1 的子树包含节点 1、4 和 5，但是节点 4、5
 * 的标签与节点 1 不同，故而答案为 1（即，该节点本身）。
 *
 *
 * 示例 2：
 *
 *
 *
 * 输入：n = 4, edges = [[0,1],[1,2],[0,3]], labels = "bbbb"
 * 输出：[4,2,1,1]
 * 解释：节点 2 的子树中只有节点 2 ，所以答案为 1 。
 * 节点 3 的子树中只有节点 3 ，所以答案为 1 。
 * 节点 1 的子树中包含节点 1 和 2 ，标签都是 'b' ，因此答案为 2 。
 * 节点 0 的子树中包含节点 0、1、2 和 3，标签都是 'b'，因此答案为 4 。
 *
 *
 * 示例 3：
 *
 *
 *
 * 输入：n = 5, edges = [[0,1],[0,2],[1,3],[0,4]], labels = "aabab"
 * 输出：[3,2,1,1,1]
 *
 *
 * 示例 4：
 *
 * 输入：n = 6, edges = [[0,1],[0,2],[1,3],[3,4],[4,5]], labels = "cbabaa"
 * 输出：[1,2,1,1,2,1]
 *
 *
 * 示例 5：
 *
 * 输入：n = 7, edges = [[0,1],[1,2],[2,3],[3,4],[4,5],[5,6]], labels =
 * "aaabaaa" 输出：[6,5,4,1,3,2,1]
 *
 *
 *
 *
 * 提示：
 *
 *
 * 1 <= n <= 10^5
 * edges.length == n - 1
 * edges[i].length == 2
 * 0 <= ai, bi < n
 * ai != bi
 * labels.length == n
 * labels 仅由小写英文字母组成
 *
 *
 */

// @lc code=start
#include <stdio.h>

#include <algorithm>
#include <deque>
#include <iostream>
#include <iterator>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

template <typename T>
void PrintAry(T cont) {
  copy(cont.begin(), cont.end(), ostream_iterator<T>(cout, " "));
}

using namespace std;

class Solution {
  vector<vector<int>> cnt;
  vector<vector<int>> node;

 public:
  vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
    node.resize(n);
    cnt.assign(n, vector<int>(26, 0));
    for (auto e : edges) {
      node[e[0]].push_back(e[1]);
      node[e[1]].push_back(e[0]);
    }
    aux(0, -1, labels);
    vector<int> ret;
    for (int i = 0; i < n; ++i) {
      ret.push_back(cnt[i][labels[i] - 'a']);
    }
    return ret;
  }

  void aux(int cur, int pre, const string& labels) {
    cnt[cur][labels[cur] - 'a'] += 1;
    for (auto n: node[cur]) {
      if (n == pre) continue;
      aux(n, cur, labels);
      for (int i = 0; i < 26; ++i) {
        cnt[cur][i] += cnt[n][i];
      }
    }
  }
};
// @lc code=end
