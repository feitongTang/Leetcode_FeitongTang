/*
    link: https://leetcode.com/problems/contains-duplicate/
*/

/*
    comment:
    first sort the vector and then judge whether there are duplicate nums
*/

/*
    status:
    Runtime: 92.24%
    Memory Usage: 97.51%
*/

#include <vector>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] == nums[i + 1]) {
                return true;
            }
        }
        
        return false;
    }
};