/*
 * @lc app=leetcode.cn id=109 lang=cpp
 *
 * [109] 有序链表转换二叉搜索树
 *
 * https://leetcode-cn.com/problems/convert-sorted-list-to-binary-search-tree/description/
 *
 * algorithms
 * Medium (67.86%)
 * Likes:    126
 * Dislikes: 0
 * Total Accepted:    15.3K
 * Total Submissions: 22K
 * Testcase Example:  '[-10,-3,0,5,9]'
 *
 * 给定一个单链表，其中的元素按升序排序，将其转换为高度平衡的二叉搜索树。
 * 
 * 本题中，一个高度平衡二叉树是指一个二叉树每个节点 的左右两个子树的高度差的绝对值不超过 1。
 * 
 * 示例:
 * 
 * 给定的有序链表： [-10, -3, 0, 5, 9],
 * 
 * 一个可能的答案是：[0, -3, 9, -10, null, 5], 它可以表示下面这个高度平衡二叉搜索树：
 * 
 * ⁠     0
 * ⁠    / \
 * ⁠  -3   9
 * ⁠  /   /
 * ⁠-10  5
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
// struct ListNode {
//     int val;
//     ListNode* next;
//     ListNode(int x)
//         : val(x)
//         , next(NULL)
//     {
//     }
// };
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
#include <vector>
using namespace std;
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head)
    {
        ListNode* p = head;
        vector<int> nums;
        while (p != NULL) {
            nums.push_back(p->val);
            p = p->next;
        }
        return aux(nums, 0, nums.size());
    }

    TreeNode* aux(const vector<int>& nums, int start, int end)
    {
        if (start == end) {
            return NULL;
        }
        TreeNode* root = new TreeNode(nums[(start + end) / 2]);
        root->left = aux(nums, start, (start + end) / 2);
        root->right = aux(nums, (start + end) / 2 + 1, end);
        return root;
    }
};
// @lc code=end
