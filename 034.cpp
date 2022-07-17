/*
    link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
*/

/*
    comment:
    the idea is binary search
    however, the performance is not good
*/

/*
    status:
    Runtime: 44.65%
    Memory Usage: 17.99%
*/

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> result{-1, -1};
        if (nums.size() == 0) {
            return result;
        }
        int low = 0, high = nums.size();
        int med = low + (high - low) / 2;
        while (low < high) {
            if (nums[med] == target) {
                break;
            } else if (nums[med] < target) {
                low = med + 1;
            } else {
                high = med - 1;
            }
            med = low + (high - low) / 2;
        }
        if (med < 0 || med >= nums.size() || nums[med] != target) {
            return result;
        }
        int temp = med;
        while (temp >= 0 && nums[temp] == target) {
            temp--;
        }
        result[0] = temp + 1;
        while (med < nums.size() && nums[med] == target) {
            med++;
        }
        result[1] = med - 1;
        return result;
    }
};