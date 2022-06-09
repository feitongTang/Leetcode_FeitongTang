/*
    link: https://leetcode.com/problems/merge-sorted-array/
*/

/*
    comment:
    the idea for this problem is simple: double pointers (one for nums1 and one for nums2)
    the boundary condition is not clearly and neatly handled in my solution
*/

/*
    status:
    Runtime: 36.65%
    Memory Usage: 29.70%
*/

#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        
        if (n == 0) {
            return;
        }
        
        if (m == 0) {
            nums1 = nums2;
            return;
        }
        
        int ptr1 = m - 1;   // the pointer to nums1
        int ptr2 = n - 1;   // the pointer to nums2
        
        int count = 0;
        
        for (int i = 0; i < n; ++i) {
            if (ptr1 < 0 || nums1[ptr1] <= nums2[ptr2]) {
                nums1[m + n - 1 - i - count] = nums2[ptr2];
                ptr2--;
            } else {
                nums1[m + n - 1 - i - count] = nums1[ptr1];
                count++;
                ptr1--;
                i--;
            }
        }
    }
};