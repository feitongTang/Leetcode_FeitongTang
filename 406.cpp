/*
    link: https://leetcode.com/problems/queue-reconstruction-by-height/
*/

/*
    comment:
    the idea is sort the people by the first element and then the second element if tie
    the reason is that for the shortest person, he has only one option: the second element means people before him
    after determining the shortest person, the next one can be placed in the result with the same idea
*/

/*
    status:
    Runtime: 36.76%
    Memory Usage: 16.49%
*/

#include <vector>

using namespace std;

class Solution {
public:
    static bool cmp(vector<int> v1, vector<int> v2) {
        return ((v1[0] < v2[0]) || (v1[0] == v2[0] && v1[1] < v2[1]));
    }
    vector<vector<int> > reconstructQueue(vector<vector<int> >& people) {
        vector<int> temp{ -1, -1 };
        vector<vector<int> > result(people.size(), temp);
        
        sort(people.begin(), people.end(), cmp);
        
        int count;

        for (int i = 0; i < people.size(); ++i) {
            count = 0;
            for (int j = 0; j < result.size(); ++j) {
                if (count == people[i][1] && result[j][0] == -1) {
                    result[j] = people[i];
                    break;
                } else if (result[j][0] == -1 || result[j][0] >= people[i][0]) {
                    count++;
                }
            }
        }
        return result;
    }
};