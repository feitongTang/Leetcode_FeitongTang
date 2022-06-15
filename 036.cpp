/*
    link: https://leetcode.com/problems/valid-sudoku/
*/

/*
    comment:
    check on different requirements
*/

/*
    status:
    Runtime: 69.52%
    Memory Usage: 74.11%
*/

#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                // judge the board[i][j] element
                if (board[i][j] != '.') {
                    // row judgement
                    for (int m = j + 1; m < 9; ++m) {
                        if (board[i][m] != '.' && board[i][m] == board[i][j]) {
                            return false;
                        }
                    }
                    // column judgement
                    for (int n = i + 1; n < 9; ++n) {
                        if (board[n][j] != '.' && board[n][j] == board[i][j]) {
                            return false;
                        }
                    }
                    // square judgement
                    for (int k = 3 * (i / 3); k < 3 * (i / 3 + 1); ++k) {
                        for (int l = 3 * (j / 3); l < 3 * (j / 3 + 1); ++l) {
                            if (k != i && l != j && board[k][l] != '.' && board[k][l] == board[i][j]) {
                                return false;
                            }
                        }
                    }
                }
                
            }
        }
        return true;
    }
};