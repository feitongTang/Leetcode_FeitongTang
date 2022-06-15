/*
    link: https://leetcode.com/problems/pascals-triangle/
*/

/*
    comment:
    basic vector usage
*/

/*
    status:
    Runtime: 100%
    Memory Usage: 99.35%
*/

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > result(numRows);
        vector<int> firstRow{1};
        result[0] = firstRow;
        
        for (int i = 1; i < numRows; ++i) {
            vector<int> tempRow(i + 1, 1);
            for (int j = 1; j < i; ++j) {
                tempRow[j] = result[i - 1][j - 1] + result[i - 1][j];
            }
            result[i]= tempRow;
        }
        return result;
    }
};