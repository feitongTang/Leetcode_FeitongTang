/*
    link: https://leetcode.com/problems/insert-into-a-binary-search-tree/
*/

/*
    comment:
    insert as a new leaf
*/

/*
    status:
    Runtime: 73.62%
    Memory Usage: 48.38%
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
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (!root) {
            root = new TreeNode(val);
            return root;
        }
        if (val < root->val) {
            if (!root->left) {
                root->left = new TreeNode(val);
            } else {
                insertIntoBST(root->left, val);
            }
        } else {
            if (!root->right) {
                root->right = new TreeNode(val);
            } else {
                insertIntoBST(root->right, val);
            }
        }
        return root;
    }
};