/*
    link: https://leetcode.com/problems/flood-fill/
*/

/*
    comment:
    treat the problem as a graph
    use depth first search
*/

/*
    status:
    Runtime: 54.55%
    Memory Usage: 16.74%
*/

#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (image[sr][sc] == color) {
            return image;
        }
        int m = image.size(), n = image[0].size(), original_color = image[sr][sc];
        stack<vector<int> > candidates;
        vector<int>buf{sr, sc};
        candidates.push(buf);
        while (!candidates.empty()) {
            vector<int> temp = candidates.top();
            candidates.pop();
            image[temp[0]][temp[1]] = color;
            if (temp[0] != 0) {
                buf[0] = temp[0] - 1;
                buf[1] = temp[1];
                if (image[buf[0]][buf[1]] == original_color) {
                    candidates.push(buf);
                }
            }
            if (temp[0] != m - 1) {
                buf[0] = temp[0] + 1;
                buf[1] = temp[1];
                if (image[buf[0]][buf[1]] == original_color) {
                    candidates.push(buf);
                }
            }
            if (temp[1] != 0) {
                buf[0] = temp[0];
                buf[1] = temp[1] - 1;
                if (image[buf[0]][buf[1]] == original_color) {
                    candidates.push(buf);
                }
            }
            if (temp[1] != n - 1) {
                buf[0] = temp[0];
                buf[1] = temp[1] + 1;
                if (image[buf[0]][buf[1]] == original_color) {
                    candidates.push(buf);
                }
            }
        }
        return image;
    }
};