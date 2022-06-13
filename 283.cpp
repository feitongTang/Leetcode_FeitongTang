/*
    link: https://leetcode.com/problems/move-zeroes/
*/

/*
    comment:
    a two-pointer problem
*/

/*
    Runtime: 75.72%
    Memory Usage: 14.26%
*/

#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int insert_ptr = 0, moving_ptr = 0;
        while (moving_ptr < nums.size()) {
            if (insert_ptr == moving_ptr) {
                if (nums[insert_ptr] != 0) {
                    insert_ptr ++;
                    moving_ptr++;
                } else {
                    moving_ptr++;
                }
            } else {
                if (nums[moving_ptr] == 0) {
                    moving_ptr++;
                } else {
                    nums[insert_ptr] = nums[moving_ptr];
                    nums[moving_ptr] = 0;
                    insert_ptr++;
                    moving_ptr++;
                }
            }
        }
    }
};