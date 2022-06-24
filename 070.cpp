/*
    link: https://leetcode.com/problems/climbing-stairs/
*/

/*
    comment:
    the basic dynamic programming method
*/

/*
    status:
    Runtime: 41.55%
    Memory Usage: 83.51%
*/

class Solution {
public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }
        
        int memo1 = 1, memo2= 2;
        
        for (int i = 3; i < n; ++i) {
            int temp = memo1;
            memo1 = memo2;
            memo2 = temp + memo1;
        }
        return memo1 + memo2;
    }
};