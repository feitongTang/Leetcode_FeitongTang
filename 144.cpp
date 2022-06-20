/*
    link: https://leetcode.com/problems/binary-tree-preorder-traversal/
*/

/*
    comment:
    the preorder algorithm is simple
    however, the usage of container seems bad and needs optimize
*/

/*
    status:
    Runtime: 9.04%
    Memory Usage: 10.41%
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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) {
            return result;
        }
        result.push_back(root->val);
        vector<int> leftResult = preorderTraversal(root->left);
        vector<int> rightResult = preorderTraversal(root->right);
        result.insert(result.end(), leftResult.begin(), leftResult.end());
        result.insert(result.end(), rightResult.begin(), rightResult.end());
        return result;
    }
};