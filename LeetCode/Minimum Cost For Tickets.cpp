// Question Link - https://leetcode.com/problems/minimum-cost-for-tickets/

// Solution - 

class Solution {
public:
    int dp[366];
    
    int helper(vector<int>&days, int idx, vector<int>& costs){
        if(idx == days.size()) return 0;
        if(dp[idx] != -1) return dp[idx];
        
        int i1 = upper_bound(days.begin(), days.end(), days[idx]+1-1)-days.begin();
        int i7 = upper_bound(days.begin(), days.end(), days[idx]+7-1)-days.begin();
        int i3 = upper_bound(days.begin(), days.end(), days[idx]+30-1)-days.begin();
        
        int a = helper(days, i1, costs) + costs[0];
        int b = helper(days, i7, costs) + costs[1];
        int c = helper(days, i3, costs) + costs[2];
        
        return dp[idx] = min(a, min(b, c));
        
    }
    
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(dp, -1, sizeof(dp));
        return helper(days, 0, costs);
    }
};

