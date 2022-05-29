/*
    link: https://leetcode.com/problems/candy/
*/

/*
    comment:
    The difficulty of this problem is to control the complexity.
    In this problem, for every number in the vector, only its neighbours needs to be considered.
    Therefore, we can use greedy algorithm to solve two sides seperately.
*/

#include <vector>
#include <numeric>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        vector<int> num(ratings.size(), 1);
        
        for (int i = 0; i < ratings.size() - 1; ++i) {
            if (ratings[i + 1] > ratings[i]) {
                num[i + 1] = num[i] + 1;
            }
        }
        
        for (int j = 0; j < ratings.size() - 1; ++j) {
            if (ratings[ratings.size() - j - 2] > ratings[ratings.size() - j - 1] && num[ratings.size() - j - 2] <= num[ratings.size() - j - 1]) {
                num[ratings.size() - j - 2] = num[ratings.size() - j - 1] + 1;
            }
        }
                
        return accumulate(num.begin(), num.end(), 0);
    }
};