/*
 * @lc app=leetcode.cn id=106 lang=cpp
 *
 * [106] 从中序与后序遍历序列构造二叉树
 *
 * https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/
 *
 * algorithms
 * Medium (63.66%)
 * Likes:    137
 * Dislikes: 0
 * Total Accepted:    20K
 * Total Submissions: 30.3K
 * Testcase Example:  '[9,3,15,20,7]\n[9,15,7,20,3]'
 *
 * 根据一棵树的中序遍历与后序遍历构造二叉树。
 * 
 * 注意:
 * 你可以假设树中没有重复的元素。
 * 
 * 例如，给出
 * 
 * 中序遍历 inorder = [9,3,15,20,7]
 * 后序遍历 postorder = [9,15,7,20,3]
 * 
 * 返回如下的二叉树：
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
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

#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    map<int, int> m;
    int post_i = 0;
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        for (int i = 0; i < inorder.size(); ++i) {
            m[inorder[i]] = i;
        }
        post_i = postorder.size() - 1;
        return aux(inorder, postorder, 0, inorder.size());
    }

    TreeNode* aux(const vector<int>& inorder, const vector<int>& postorder, int start, int end)
    {
        if (start == end) {
            return NULL;
        }

        int root_v = postorder[post_i--];
        TreeNode* root = new TreeNode(root_v);
        root->right = aux(inorder, postorder, m[root_v] + 1, end);
        root->left = aux(inorder, postorder, start, m[root_v]);
        return root;
    }
};
// @lc code=end
