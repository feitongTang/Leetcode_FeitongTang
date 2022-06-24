/*
    link: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
*/

/*
    comment:
    the method of hash table doesn't necessarily needs BST
*/

/*
    status:
    Runtime: 22.90%
    Memory Usage: 23.94%
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


#include <unordered_set>

using namespace std;

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> set;
        return dfs(root, set, k);
    }
    
    bool dfs(TreeNode* root, unordered_set<int>& set, int k){
        if (root == nullptr) {
            return false;
        }
        if (set.count(k - root->val)) {
            return true;
        }
        set.insert(root->val);
        return dfs(root->left, set, k) || dfs(root->right, set, k);
    }
};