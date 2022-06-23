/*
    link: https://leetcode.com/problems/symmetric-tree/
*/

/*
    comment:
    use sub-functions to compare two sub trees
*/

/*
    status:
    Runtime: 40.65%
    Memory Usage: 93.64%
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
    bool subTreeCmp(TreeNode *left, TreeNode *right) {
        if (!left && !right) {
            return true;
        }
        if ((!left && right) || (!right && left)) {
            return false;
        }
        if (left->val != right->val) {
            return false;
        }
        return (subTreeCmp(left->left, right->right) && subTreeCmp(left->right, right->left));
    }
    
    bool isSymmetric(TreeNode* root) {
        return subTreeCmp(root->left, root->right);
    }
};