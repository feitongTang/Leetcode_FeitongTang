/*
    link: https://leetcode.com/problems/binary-tree-postorder-traversal/
*/

/*
    comment: 
    an easy postorder algorithm
*/

/*
    status:
    Runtime: 23.03%
    Memory Usage: 8.76%
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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if (!root) {
            return result;
        }
        vector<int> leftResult = postorderTraversal(root->left);
        vector<int> rightResult = postorderTraversal(root->right);
        result.insert(result.end(), leftResult.begin(), leftResult.end());
        result.insert(result.end(), rightResult.begin(), rightResult.end());
        result.push_back(root->val);
        return result;
    }
};