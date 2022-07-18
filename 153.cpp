/*
    link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
*/

/*
    comment:
    a binary-search-like algorithm
*/

/*
    status:
    Runtime: 44.32%
    Memory Usage: 71.78%
*/

#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while (low < high) {
            int med = low + (high - low) / 2;
            if (nums[med] > nums[high]) {
                low = med + 1;
            } else {
                high = med;
            }
        }
        return nums[low];
    }
};