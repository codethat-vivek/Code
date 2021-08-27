// Question Link - https://leetcode.com/problems/last-stone-weight-ii/

// Solution - 

class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sm = 0;
        for(auto ele : stones)
            sm += ele;
        vector<vector<int>>dp (n+1, vector<int>(sm+1, 0));
        
        for(int i=0; i<n+1; i++){
            for(int j=0; j<sm+1; j++){
                if(j == 0)
                    dp[i][j] = 1;
                else if(i == 0)
                    continue;
                else if(stones[i-1] > j)
                    dp[i][j] = dp[i-1][j];
                else if(stones[i-1] <= j)
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-stones[i-1]];
                    
            }
        }
        int ans = INT_MAX;
        for(int i=0; i<n+1; i++){
            for(int j=0; j<sm+1; j++){
                if(dp[i][j] == 1)
                    ans = min(ans, abs(sm-2*j));
            }
        }
        return ans;
    }
};
