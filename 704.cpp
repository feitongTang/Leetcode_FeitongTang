/*
    link: https://leetcode.com/problems/binary-search/
*/

#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low_idx = 0;
        int up_idx = nums.size() - 1;
        int cur_idx = (low_idx + up_idx) / 2;
        
        while (cur_idx >= low_idx && cur_idx <= up_idx) {
            if (nums[cur_idx] == target) {
                return cur_idx;
            }
            else if (nums[cur_idx] < target) {
                low_idx = cur_idx + 1;
                cur_idx = (low_idx + up_idx) / 2; 
            } else {
                up_idx = cur_idx - 1;
                cur_idx = (low_idx + up_idx) / 2;
            }
        }
        return -1;
    }
};