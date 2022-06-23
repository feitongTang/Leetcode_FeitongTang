/*
    link: https://leetcode.com/problems/search-in-a-binary-search-tree/
*/

/*
    comment:
    recursive method
*/

/*
    status:
    Runtime: 12.75%
    Memory Usage: 23.38%
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
};


class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root) {
            return nullptr;
        }
        if (root->val > val) {
            return searchBST(root->left, val);
        } else if (root->val < val) {
            return searchBST(root->right, val);
        } else {
            return root;
        }
    }
};