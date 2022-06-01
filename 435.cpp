/*
    link: https://leetcode.com/problems/non-overlapping-intervals/
*/

/*
    status:
    Time Limit Exceeded
*/

/*
    comment:
    For interval questions, the point is to sort according to its starting number or its ending number;
    Make sure how greedy algorithm works in such cases.
*/

#include <vector>

using namespace std;

class Solution {
public:
    static bool cmp(vector<int> v1, vector<int> v2) {
        return (v1[1] < v2[1]);
    }
    int eraseOverlapIntervals(vector<vector<int> >& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int cnt = 0;
        int last_num = intervals[0][0] - 1;
        
        for (int i = 0; i < intervals.size(); ++i) {
            if (last_num <= intervals[i][0]) {
                last_num = intervals[i][1];
            } else {
                cnt++;
            }
        }
        return cnt;
    }
};