/*
    link: https://leetcode.com/problems/find-peak-element/
*/

/*
    comment:
    the point is that nums[i] != nums[i + 1] is valid
    then using a binary search there are three cases:
    1. med is the peak
    2. med is less than med - 1; then there must exists a peak on the left
    3. med is less than med + 1; then there must exists a peak on the right
*/

/*
    status:
    Runtime: 76.37%
    Memory Usage: 49.64%
*/

#include <vector>

using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        int med = low + (high - low) / 2;
        while (low < high) {
            if (med == 0) {
                if (nums[med] > nums[med + 1]) {
                    return med;
                } else {
                    low = med + 1;
                }
            } else {
                if (nums[med] > max(nums[med - 1], nums[med + 1])) {
                    return med;
                } else if (nums[med] < nums[med - 1]) {
                    high = med - 1;
                } else {
                    low = med + 1;
                }
            }
            med = low + (high - low) / 2;
        }
        return med;
    }
};