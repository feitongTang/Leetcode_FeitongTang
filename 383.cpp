/*
    link: https://leetcode.com/problems/ransom-note/
*/

/*
    comment:
    first use unordered_map to record the characters and their numbers in magazine
    then iterate over ransomNote to judge whether it's true or false
*/

/*
    status:
    Runtime: 22.06%
    Memory Usage: 72.88%
*/

#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> dict;
        for (int i = 0; i < magazine.length(); ++i) {
            if (dict.find(magazine[i]) == dict.end()) {
                dict[magazine[i]] = 1;
            } else {
                dict[magazine[i]]++;
            }
        }
        
        for (int i = 0; i < ransomNote.length(); ++i) {
            if (dict.find(ransomNote[i]) == dict.end() || dict[ransomNote[i]] == 0) {
                return false;
            } else {
                dict[ransomNote[i]]--;
            }
        }
        return true;
    }
};