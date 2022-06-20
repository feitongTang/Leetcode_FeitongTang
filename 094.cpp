/*
    link: https://leetcode.com/problems/binary-tree-inorder-traversal/
*/

/*
    comment:
    an easy inorder algorithm
*/

/*
    status:
    Runtime: 100%
    Memory Usage: 9.24%
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

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) {
            return result;
        }
        vector<int> leftResult = inorderTraversal(root->left);
        vector<int> rightResult = inorderTraversal(root->right);
        result.insert(result.end(), leftResult.begin(), leftResult.end());
        result.push_back(root->val);
        result.insert(result.end(), rightResult.begin(), rightResult.end());
        return result;
    }
};