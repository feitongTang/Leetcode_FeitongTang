/*
    link: https://leetcode.com/problems/longest-substring-without-repeating-characters/
*/

/*
    comment:
    sliding window
    use unordered_set for find!
*/

/*
    status:
    Runtime: 37.03%
    Memory Usage: 32.44%
*/

#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() == 0) {
            return 0;
        }
        int l = 0, r = 0, max_l = 1;
        unordered_set<char> dict({s[0]});
        for (;r < s.length() - 1; ++r) {
            // judge whether s[r + 1] is in the current substring
            if (dict.find(s[r + 1]) == dict.end()) {
                dict.insert(s[r + 1]);
            } else {
                max_l = max(max_l, r - l + 1);
                while (s[l] != s[r + 1]) {
                    dict.erase(s[l]);
                    l++;
                }
                l++;
            }
        }
        max_l = max(max_l, r - l + 1);
        return max_l;
    }
};