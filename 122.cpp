/*
    link: https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/
*/

/*
    comment:
    when consider using greedy algorithm,
    a very simple method is to just judge every day since it's legal to buy it again on the same day
    it's not necessary to consider local minimum and maximum since the equal price is making it more complicated
*/

/*
    status:
    Runtime: 14.07%
    Memory Usage: 88.40%
*/

#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i - 1] < prices[i]) {
                profit += prices[i] - prices[i - 1];
            }
        }
        return profit;
    }
};