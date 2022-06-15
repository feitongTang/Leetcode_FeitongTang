/*
    link: https://leetcode.com/problems/search-a-2d-matrix/
*/

/*
    comment:
    first judge the row
    then use binary search to judge the column
*/

/*
    status:
    Runtime: 90.30%
    Memory Usage: 52.20%
*/

#include <vector>

using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int r = m - 1;
        for (int i = 0; i < m - 1; ++i) {
            if (matrix[i][0] <= target && matrix[i + 1][0] > target) {
                r = i;
            }
        }
        if (matrix[r][n - 1] < target) {
            return false;
        }
        // the target should be in the rth row if it exists
        int low = 0, up = n - 1;
        while (low <= up) {
            int mid = low + (up - low) / 2;
            if (target < matrix[r][mid]) {
                up = mid - 1;
            } else if (target > matrix[r][mid]) {
                low = mid + 1;
            } else {
                return true;
            }
        }
        return false;
    }
};