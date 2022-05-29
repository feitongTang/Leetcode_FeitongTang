/*
    link: https://leetcode.com/problems/assign-cookies/
*/

#include <vector>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int g_ptr = 0, s_ptr = 0, num = 0;
        
        while (g_ptr < g.size() && s_ptr < s.size()) {
            if (g[g_ptr] <= s[s_ptr]) {
                num++;
                g_ptr++;
            }
            s_ptr++;
        }
        return num;
    }
};