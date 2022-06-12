/*
    link: https://leetcode.com/problems/first-bad-version/
*/

/*
    comment:
    the idea is simply binary search
*/

/*
    status:
    Runtime: 100%
    Memory Usage: 68.22%
*/

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        
        if (isBadVersion(1)) {
            return 1;
        }
        
        int low_idx = 1;
        int up_idx = n;
        // if I directly add low_idx and up_idx together, it will exceed the boundary
        int cur_idx = low_idx / 2 + up_idx / 2 + (low_idx % 2 + up_idx % 2) / 2;
        
        while (cur_idx >= low_idx && cur_idx <= up_idx) {
            if (!isBadVersion(cur_idx) && isBadVersion(cur_idx + 1)) {
                return cur_idx + 1;
            }
            else if (isBadVersion(cur_idx)) {
                up_idx = cur_idx - 1;
                cur_idx = low_idx / 2 + up_idx / 2 + (low_idx % 2 + up_idx % 2) / 2;
            }
            else {
                low_idx = cur_idx + 1;
                cur_idx = low_idx / 2 + up_idx / 2 + (low_idx % 2 + up_idx % 2) / 2;
            }
        }
        return 0;
    }

    /*
        another solution from online by 
        to avoid the overflow problem, always use mid = low + (high - low) / 2
    */


    int firstBadVersion_online(int n) {
        int start = 0, end = n;
        while (end - start > 1) {
            int mid = start + (end - start) / 2;
            if(isBadVersion(mid)) {
                end=mid;
            } 
            else  {
                start=mid;
            }
        }
        return end;
    }
};