/*
    link: https://leetcode.com/problems/first-unique-character-in-a-string/
*/

/*
    comment:
    try to use hash table but the complexity is O(n) and the method iterates twice
    needs optimization!
*/

/*
    status:
    Runtime: 20.28%
    Memory Usage: 15.66%
*/

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, vector<int>> dict;
        for (int i = 0; i < s.length(); ++i) {
            dict[s[i]].push_back(i);
        }
        for (int i = 0; i < s.length(); ++i) {
            if (dict[s[i]].size() == 1) {
                return i;
            }
        }
        return -1;
    }
};