/*
    link: https://leetcode.com/problems/merge-two-binary-trees/
*/

/*
    comment:
    use recursion to solve the tree problem
*/

/*
    status:
    Runtime: 55.59%
    Memory Usage: 25.57%
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

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
};

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if (!root1 && !root2) {
            return nullptr;
        } else if (!root1) {
            return root2;
        } else if (!root2) {
            return root1;
        } else {
            TreeNode* result = new TreeNode(root1->val + root2->val);
            result->left = mergeTrees(root1->left, root2->left);
            result->right = mergeTrees(root1->right, root2->right);
            return result;
        }
    }
};