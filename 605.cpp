/*
    link: https://leetcode.com/problems/can-place-flowers/
*/

/*
    comment:
    the idea is quite simple and we just need to use greedy algorithm
    remember to consider the first and last range
*/

/*
    status:
    Runtime: 31.50%
    Memory Usage: 99.34%
*/

#include <vector>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int flower_idx = -2;
        for (int i = 0; i < flowerbed.size(); ++i) {
            if (flowerbed[i] == 1) {
                n -= (i - flower_idx) / 2 - 1;
                if (n <= 0) {
                    break;
                }
                flower_idx = i;
            }
        }
        n -= (flowerbed.size() + 1 - flower_idx) / 2 - 1;
        return (n <= 0);
    }
};