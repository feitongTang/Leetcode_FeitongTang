/*
    link: https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/
*/

/*
    comment:
    a simple greedy algorithm
    however, it's difficult to come up with such idea
    also it's hard to judge that the greedy algorithm leads to a global optimal solution
*/

/*
    status:
    Time Limit Exceeded
*/

#include <vector>

using namespace std;

class Solution {
public:
    static bool cmp(vector<int> v1, vector<int> v2) {
        return (v1[1] < v2[1]);
    }
    
    int findMinArrowShots(vector<vector<int> >& points) {
        sort(points.begin(), points.end(), cmp);
        
        int last_num = points[0][1];
        int result = 1;
        
        for (int i = 1; i < points.size(); ++i) {
            if (last_num < points[i][0]) {
                last_num = points[i][1];
                result++;
            }
        }
        
        return result;
    }
};