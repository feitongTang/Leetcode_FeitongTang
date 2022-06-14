/*
    link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock/
*/

/*
    comment:
    at first I try to use dynamic programming to solve the problem;
    however, then I find it's not necessary to store so many values and only the max profit and the min price are needed
*/

/*
    status:
    Runtime: 5.05%
    Memory Usage: 52.29%
*/

#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = prices[0];
        int max_profit = 0;
        
        for (int i = 1; i < prices.size(); ++i) {
            max_profit = max(prices[i] - min_price, max_profit);
            min_price = min(min_price, prices[i]);
        }
        
        return max_profit;
    }
};