/*
    link: https://leetcode.com/problems/search-in-rotated-sorted-array/
*/

/*
    comment:
    first find the rotation angle
    then use ordinary binary search
*/

/*
    status:
    Runtime: 56.76%
    Memory Usage: 29.04%
*/

#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int low = 0, high = n - 1;
        int med = low + (high - low) / 2;
        while (low < high) {
            if (nums[med] > nums[high]) {
                low = med + 1;
            } else {
                high = med;
            }
            med = low + (high - low) / 2;
        }
        int rot = med;
        low = 0;
        high = n - 1;
        while (low <= high) {
            med = low + (high - low) / 2;
            int med_rot = (med + rot) % n;
            if (nums[med_rot] == target) {
                return med_rot;
            } else if (nums[med_rot] < target) {
                low = med + 1;
            } else {
                high = med - 1;
            }
        }
        return -1;
    }
};