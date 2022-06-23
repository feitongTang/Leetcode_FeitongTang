/*
    link: https://leetcode.com/problems/path-sum/
*/

/*
    comment:
    tree algorithm
    note that the val can be either true or false
    therefore there's no way to terminate in the middle
*/

/*
    status:
    Runtime: 40.05%
    Memory Usage: 39.67%
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) {
            return false;
        }
        // if the current val of the node is equal to the targetSum and it's the leaf node, return true;
        if (root->val == targetSum && !root->left && !root->right) {
            return true;
        } else {
            return (hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val));
        }
    }
};