// Question Link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock/

// SOLUTION - O(n)

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        int minimum = 1e7;
        for(int i=0; i<prices.size(); i++){
            if (minimum > prices[i])
                minimum = prices[i];
            else
                ans = max(ans, prices[i]-minimum);
            
        }
        return ans;
    }
};
