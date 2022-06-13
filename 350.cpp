/*
    link: https://leetcode.com/problems/intersection-of-two-arrays-ii/
*/

/*
    comment:
    first sort the nums1 and nums2
    then use two pointers
*/

/*
    Runtime: 68.35%
    Memory Usage: 99.35%
*/

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        vector<int> result;
        
        int ptr1 = 0, ptr2 = 0;
        
        while (ptr1 < nums1.size() && ptr2 < nums2.size()) {
            if (nums1[ptr1] < nums2[ptr2]) {
                ptr1++;
            } else if (nums1[ptr1] > nums2[ptr2]) {
                ptr2++;
            } else {
                result.push_back(nums1[ptr1]);
                ptr1++;
                ptr2++;
            }
        }
        
        return result;
    }
};