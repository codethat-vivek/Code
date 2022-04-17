// Question Link - https://leetcode.com/problems/number-of-ways-to-buy-pens-and-pencils/

// Solution - 

class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        
        vector<long long>dp(total+1, 1);
        for(int i=cost1; i<dp.size(); i++)
            dp[i] += dp[i-cost1];
        for(int i=cost2; i<dp.size(); i++)
            dp[i] += dp[i-cost2];
        
        return dp[total];
    }
};
