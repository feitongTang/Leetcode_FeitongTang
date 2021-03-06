/*
    link: https://leetcode.com/problems/partition-labels/
*/

/*
    comment:
    for this question, the idea is straight forward
    first iterate through the string to get each character's first position and last position
    then it can be transfered into interval problem and use greedy algorithm
*/

/*
    status:
    Runtime: 18.58%
    Memory Usage: 5.02%
*/


#include <vector>
#include <unordered_map>
#include <string>
#include <utility>

using namespace std;

class Solution {
public:
    static bool cmp(vector<int> v1, vector<int> v2) {
        return v1[0] < v2[0];
    }
    vector<int> partitionLabels(string s) {
        unordered_map<char, vector<int> > position_dict;
        for (int i = 0; i < s.length(); ++i) {
            if (position_dict.find(s[i]) == position_dict.end()) {
                vector<int> position{ i, i };
                position_dict.insert({s[i], position});
            } else {
                position_dict[s[i]][1] = i;
            }
        }

        vector<vector<int> > intervals;
        for (auto pair : position_dict) {
            intervals.push_back(pair.second);
        }
        
        sort(intervals.begin(), intervals.end(), cmp);
        
        vector<int> result;
        int pos1 = intervals[0][0];
        int pos2 = intervals[0][1];
        
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] == pos2 + 1) {
                result.push_back(pos2 - pos1 + 1);
                pos1 = intervals[i][0];
                pos2 = intervals[i][1];
            } else if (intervals[i][1] > pos2) {
                pos2 = intervals[i][1];
            }
        }
        
        result.push_back(s.length() - pos1);
        
        return result;
    }

    /*
        another solution from online by hi-malik (https://leetcode.com/problems/partition-labels/discuss/1868842/JavaC%2B%2B-VISUALLY-EXPLAINEDDDDD!!)
        the other solution is having a similar idea
        but the way to get the answer after having an unordered map is way more clever
    */

    vector<int> partitionLabels_online(string s) {
        unordered_map<char,int>mp;
        // filling impact of character's
        for(int i = 0; i < s.size(); i++){
            char ch = s[i];
            mp[ch] = i;
        }
        // making of result
        vector<int> res;
        int prev = -1;
        int maxi = 0;
        
        for(int i = 0; i < s.size(); i++){
            maxi = max(maxi, mp[s[i]]);
            if(maxi == i){
                // partition time
                res.push_back(maxi - prev);
                prev = maxi;
            }
        }
        return res;
    }
};