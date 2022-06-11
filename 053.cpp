/*
    link: https://leetcode.com/problems/maximum-subarray/
*/

/*
    comment:
    it can be treated as a simple dynamic programming problem
*/

/*
    status:
    Runtime: 20.79%
    Memory Usage: 6.01%
*/

#include <vector>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        vector<int> memo(nums.size());
        memo[0] = nums[0];
        
        for (int i = 1; i < memo.size(); ++i) {
            memo[i] = max(memo[i - 1] + nums[i], nums[i]);
        }
        
        return *max_element(memo.begin(), memo.end());
        
    }

    /*
        another solution that saves more space
    */

   int maxSubArrayTwo(vector<int>& nums) {
        int memo = nums[0];
        int result = memo;
        
        for (int i = 1; i < nums.size(); ++i) {
            int temp = memo;
            memo = max(memo + nums[i], nums[i]);
            result = max(result, memo);
        }
        
        return result;
        
    }
};