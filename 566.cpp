/*
    link: https://leetcode.com/problems/reshape-the-matrix/
*/

/*
    comment:
    basic operations on vectors
*/

/*
    status:
    Runtime: 44.26%
    Memory Usage: 37.99%
*/

#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > matrixReshape(vector<vector<int> >& mat, int r, int c) {
        if (mat.size() * mat[0].size() != r * c) {
            return mat;
        }
        
        vector<int> temp;
        
        for (int i = 0; i < mat.size(); ++i) {
            for (int j = 0; j < mat[0].size(); ++j) {
                temp.push_back(mat[i][j]);
            }
        }
        
        vector<vector<int> >result(r);
        
        for (int i = 0; i < r; ++i) {
            result[i].resize(c);
            for (int j = 0; j < c; ++j) {
                result[i][j] = temp[i * c + j];
            }
        }

        return result;
    }
};