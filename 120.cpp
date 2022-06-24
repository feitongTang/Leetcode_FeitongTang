/*
    link: https://leetcode.com/problems/triangle/
*/

/*
    comment:
    dynamic programming
    however, the method uses too many space and should be optimized
*/

/*
    status:
    Runtime: 56.67%
    Memory Usage: 7.75%
*/

#include <vector>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> sum(triangle.size());
        sum[0].push_back(triangle[0][0]);
        for (int i = 1; i < triangle.size(); ++i) {
            for (int j = 0; j < triangle[i].size(); ++j) {
                if (j == 0) {
                    sum[i].push_back(sum[i - 1][j] + triangle[i][j]);
                } else if (j == triangle[i].size() - 1) {
                    sum[i].push_back(sum[i - 1][j - 1] + triangle[i][j]);
                } else {
                    sum[i].push_back(min(sum[i - 1][j - 1], sum[i - 1][j]) + triangle[i][j]);
                }
            }
        }
        return *min_element(sum[triangle.size() - 1].begin(), sum[triangle.size() - 1].end());
    }
};