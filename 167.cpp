/*
    link: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
*/

/*
    comment:
    two pointers; one from the beginning and one from the end
*/

/*
    status:
    Runtime: 94.39%
    Memory Usage: 42.91%
*/

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int begin_ptr = 0, end_ptr = numbers.size() - 1;
        while (begin_ptr < end_ptr) {
            if (numbers[begin_ptr] + numbers[end_ptr] > target) {
                end_ptr--;
            } else if (numbers[begin_ptr] + numbers[end_ptr] == target){
                break;
            } else {
                begin_ptr++;
            }
        }
        vector<int> result{begin_ptr + 1, end_ptr + 1};
        return result;
    }
};