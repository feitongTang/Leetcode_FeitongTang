/*
    link: https://leetcode.com/problems/binary-tree-level-order-traversal/
*/

/*
    comment:
    an online solution by deck from https://leetcode.com/problems/binary-tree-level-order-traversal/discuss/33709/Short-8ms-C%2B%2B-solution-with-queue
*/

/*
    status:
    Runtime: 72.25%
    Memory Usage: 95.90%
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
#include <queue>

using namespace std;

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) {
            return {};
        }
        vector<int> row;
        vector<vector<int> > result;
        queue<TreeNode*> q;
        q.push(root);
        int count = 1;

        while (!q.empty()) {
            if (q.front()->left) {
                q.push(q.front()->left);
            }
            if (q.front()->right) {
                q.push(q.front()->right);
            }
            row.push_back(q.front()->val);
            q.pop();
            if (--count == 0) {
                result.emplace_back(row);
                row.clear();
                count = q.size();
            }
        }
        return result;
    }
};