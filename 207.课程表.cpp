/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 *
 * https://leetcode-cn.com/problems/course-schedule/description/
 *
 * algorithms
 * Medium (49.66%)
 * Likes:    251
 * Dislikes: 0
 * Total Accepted:    26.7K
 * Total Submissions: 53.8K
 * Testcase Example:  '2\n[[1,0]]'
 *
 * 你这个学期必须选修 numCourse 门课程，记为 0 到 numCourse-1 。
 *
 * 在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程
 * 1 ，我们用一个匹配来表示他们：[0,1]
 *
 * 给定课程总量以及它们的先决条件，请你判断是否可能完成所有课程的学习？
 *
 *
 *
 * 示例 1:
 *
 * 输入: 2, [[1,0]]
 * 输出: true
 * 解释: 总共有 2 门课程。学习课程 1 之前，你需要完成课程 0。所以这是可能的。
 *
 * 示例 2:
 *
 * 输入: 2, [[1,0],[0,1]]
 * 输出: false
 * 解释: 总共有 2 门课程。学习课程 1
 * 之前，你需要先完成​课程 0；并且学习课程 0
 * 之前，你还应先完成课程 1。这是不可能的。
 *
 *
 *
 * 提示：
 *
 *
 * 输入的先决条件是由 边缘列表 表示的图形，而不是 邻接矩阵
 * 。详情请参见图的表示法。 你可以假定输入的先决条件中没有重复的边。 1
 * <= numCourses <= 10^5
 *
 *
 */

// @lc code=start
#include <queue>
#include <vector>
using namespace std;

class Solution {
 public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    if (numCourses == 0) {
      return true;
    }

    vector<vector<int>> adjacent(numCourses);
    vector<int> indegree(numCourses, 0);
    for (int i = 0; i < prerequisites.size(); ++i) {
      // 这里记录出度可以获得更好的效率
      adjacent[prerequisites[i][1]].push_back(prerequisites[i][0]);
      ++indegree[prerequisites[i][0]];
    }

    queue<int> que;
    for (int i = 0; i < numCourses; ++i) {
      if (indegree[i] == 0) {
        que.push(i);
      }
    }

    while (!que.empty()) {
      int tmp = que.front();
      que.pop();
      --numCourses;
      for (int i = 0; i < adjacent[tmp].size(); ++i) {
        if (--indegree[adjacent[tmp][i]] == 0) {
          que.push(adjacent[tmp][i]);
        }
      }
    }
    return numCourses == 0;
  }
};
// @lc code=end
