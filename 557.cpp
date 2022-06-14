/*
    link: https://leetcode.com/problems/reverse-words-in-a-string-iii/
*/

/*
    comment:
    identify the word and reverse respectively
    seems like not an efficient method
*/

/*
    status:
    Runtime: 16.49%
    Memory Storage: 45.27%
*/

#include <string>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int previous_i = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == ' ') {
                reverse(s.begin() + previous_i, s.begin() + i);
                previous_i = i + 1;
            }
        }
        reverse(s.begin() + previous_i, s.end());
        return s;
    }
};