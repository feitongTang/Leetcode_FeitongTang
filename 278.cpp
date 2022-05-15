/*
    link: https://leetcode.com/problems/first-bad-version/
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
};