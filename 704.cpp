/*
    link: https://leetcode.com/problems/binary-search/
*/

/*
    comment:
    a typical binary search algorithm
*/

/*
    status:
    Runtime: 7.19%
    Memory Usage: 92.13%
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

    /*
        another solution from online by lone_02wolf (https://leetcode.com/problems/binary-search/discuss/1456130/C%2B%2B-Simple-and-Fast-Binary-Search)
        the idea is the same, but the code is shorter and simpler
    */

   int search_online(vector<int>& nums, int target) {
        int n = nums.size()-1;
        int low = 0, high = n;
        while( low <= high){
            int mid = (low + high)/2;
            if (nums[mid] == target) return mid;
            else if (nums[mid] > target) high = mid -1;
            else low = mid + 1;
        }
        return -1;
  }
};