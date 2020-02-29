/*
 * @lc app=leetcode.cn id=105 lang=cpp
 *
 * [105] 从前序与中序遍历序列构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/description/
 *
 * algorithms
 * Medium (60.77%)
 * Likes:    296
 * Dislikes: 0
 * Total Accepted:    35.5K
 * Total Submissions: 56.1K
 * Testcase Example:  '[3,9,20,15,7]\n[9,3,15,20,7]'
 *
 * 根据一棵树的前序遍历与中序遍历构造二叉树。
 * 
 * 注意:
 * 你可以假设树中没有重复的元素。
 * 
 * 例如，给出
 * 
 * 前序遍历 preorder = [3,9,20,15,7]
 * 中序遍历 inorder = [9,3,15,20,7]
 * 
 * 返回如下的二叉树：
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <cstdlib>
#include <memory>
// struct TreeNode {
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(int x)
//         : val(x)
//         , left(NULL)
//         , right(NULL)
//     {
//     }
// };
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    map<int, int> m;
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        for (int i = 0; i < inorder.size(); ++i) {
            m[inorder[i]] = i;
        }
        int p_start = 0;
        return aux(preorder, inorder, p_start, 0, inorder.size());
    }

    TreeNode* aux(const vector<int>& preorder, const vector<int>& inorder, int& p_start, int start, int end)
    {
        if (start == end) {
            return NULL;
        }

        int root_v = preorder[p_start++];
        TreeNode* root = new TreeNode(root_v);
        root->left = aux(preorder, inorder, p_start, start, m[root_v]);
        root->right = aux(preorder, inorder, p_start, m[root_v] + 1, end);
        return root;
    }
};
// @lc code=end
