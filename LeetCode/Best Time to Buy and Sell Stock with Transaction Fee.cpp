// Question Link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

// Solution - 

class Solution {
public:
    int memo[50001][3];
    
    int getProfit(vector<int>&prices, int stocks, int idx, int fee){
        if(idx >= prices.size())return 0;
        if(memo[idx][stocks] != -1)
            return memo[idx][stocks];
        if(stocks == 0)
            return memo[idx][stocks] = max(-prices[idx]+getProfit(prices, 1, idx+1, fee), getProfit(prices, 0, idx+1, fee));
    
        else
            return memo[idx][stocks] = max(prices[idx]-fee+getProfit(prices, 0, idx+1, fee), getProfit(prices, 1, idx+1, fee));
        
    }
    int maxProfit(vector<int>& prices, int fee) {
        memset(memo, -1, sizeof(memo));
        return getProfit(prices, 0, 0, fee);
    }
};
