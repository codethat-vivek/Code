// Question Link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

// Solution - 

class Solution {
public:
    int memo[30001][3];

    int getProfit(vector<int>& prices, int stocks, int idx){
        if(idx >= prices.size())return 0;
        if(memo[idx][stocks] != -1)return memo[idx][stocks];
        if(stocks == 0) // buy and hold, you cannot sell
            return memo[idx][stocks] = max(-prices[idx]+getProfit(prices, 1, idx+1), getProfit(prices, 0, idx+1));
        else // stock == 1, sell and hold, you cannot buy
            return memo[idx][stocks] = max(prices[idx]+getProfit(prices, 0, idx+1), getProfit(prices, 1, idx+1));
        
    }
    int maxProfit(vector<int>& prices) {
        memset(memo, -1, sizeof(memo));
        return getProfit(prices, 0, 0);
    }
};
