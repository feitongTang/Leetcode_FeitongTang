/*
    link: https://leetcode.com/problems/valid-anagram/
*/

/*
    comment:
    use unordered_map to summarize one string and check the other string
    seems like the performance is bad
    needs optimization!
*/

/*
    status:
    Runtime: 5.69%
    Memory Usage: 8.17%
*/

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) {
            return false;
        }
        unordered_map<char, int> dict;
        for (int i = 0; i < s.length(); ++i) {
            if (dict.find(s[i]) == dict.end()) {
                dict[s[i]] = 1;
            } else {
                dict[s[i]]++;
            }
        }
        
        for (int i = 0; i < t.length(); ++i) {
            if (dict.find(t[i]) == dict.end() || dict[t[i]] == 0) {
                return false;
            } else {
                dict[t[i]]--;
            }
        }
        return true;
    }
};