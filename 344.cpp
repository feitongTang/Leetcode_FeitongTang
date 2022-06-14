/*
    link: https://leetcode.com/problems/reverse-string/
*/

/*
    comment: two pointer method
*/

/*
    status:
    Runtime: 84.65%
    Memory Storage: 41.23%
*/

#include <vector>

using namespace std;

class Solution {
public:
    void reverseString(vector<char>& s) {
        int begin_ptr = 0;
        int end_ptr = s.size() - 1;
        
        while (begin_ptr <= end_ptr) {
            char temp = s[begin_ptr];
            s[begin_ptr] = s[end_ptr];
            s[end_ptr] = temp;
            begin_ptr++;
            end_ptr--;
        }
    }
};