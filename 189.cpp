/*
    link: https://leetcode.com/problems/rotate-array/
*/

#include <vector>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int original_size = nums.size();
        if (original_size <= k) {
            k = k % original_size;
        }
        nums.insert(nums.end(), nums.begin(), nums.begin() + original_size - k);
        nums.erase(nums.begin(), nums.begin() + original_size - k);
    }
};