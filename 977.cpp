/*
    https://leetcode.com/problems/squares-of-a-sorted-array/
*/

#include <vector>
#include <math.h>

using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int end_idx = nums.size() - 1;
        int start_idx = 0;
        vector<int> result;
        
        while (end_idx >= start_idx) {
            int start_sqr = pow(nums[start_idx], 2);
            int end_sqr = pow(nums[end_idx], 2);
            if (start_sqr >= end_sqr) {
                result.push_back(start_sqr);
                start_idx++;
            } else {
                result.push_back(end_sqr);
                end_idx--;
            }
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};