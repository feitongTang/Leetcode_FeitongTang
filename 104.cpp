/*
    link: https://leetcode.com/problems/maximum-depth-of-binary-tree/
*/

/*
    comment:
    recursive algorithm
*/

/*
    status:
    Runtime: 96.03%
    Memory Usage: 56.11%
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
    TreeNode *left;
    TreeNode *right;
};

#include <algorithm>

using namespace std;

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
};