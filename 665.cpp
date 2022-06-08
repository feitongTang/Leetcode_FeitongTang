/*
    link: https://leetcode.com/problems/non-decreasing-array/
*/

/*
    comment:
    the idea is that if nums[i] > nums[i + 1], then consider let nums[i] = nums[i + 1] or nums[i + 1] = nums[i]
    and this will leads to the comparison with nums[i - 1] and nums[i + 2]
    and mind the boundary condition
    however, the point is how to use greedy algorithm here
*/

/*
    status:
    Runtime: 23.30%
    Memory Usage: 12.56%
*/

#include <vector>

using namespace std;

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int count = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (nums[i] > nums[i + 1]) {
                count++;
                if (count > 1) {
                    return false;
                }
                if ((i != 0) && (i != nums.size() - 2) && (nums[i - 1] > nums[i + 1]) && (nums[i] > nums[i + 2])) {
                    return false;
                }
            }
        }
        return true;
    }

    /*
        another solution from online by caihao0727mail (https://leetcode.com/problems/non-decreasing-array/discuss/106826/JavaC%2B%2B-Simple-greedy-like-solution-with-explanation)
        the main point of greedy here is that: if nums[i] > nums[i + 1], let nums[i] change if possible since it gets smaller and reduce the risk!
        and then consider other boundary conditions
    */

    bool checkPossibility_online(vector<int>& nums) {
        int cnt = 0;                                                                    //the number of changes
        for(int i = 1; i < nums.size() && cnt<=1 ; i++){
            if(nums[i-1] > nums[i]){
                cnt++;
                if(i-2<0 || nums[i-2] <= nums[i])nums[i-1] = nums[i];                    //modify nums[i-1] of a priority
                else nums[i] = nums[i-1];                                                //have to modify nums[i]
            }
        }
        return cnt<=1;
    } 
};