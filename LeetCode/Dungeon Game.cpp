// Question Link - https://leetcode.com/problems/dungeon-game/

// Solution - 

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int rows = dungeon.size();
        int cols = dungeon[0].size();
        vector<vector<int>>dp(rows, vector<int>(cols));
        dp[rows-1][cols-1] = max(1, 1-dungeon[rows-1][cols-1]);
        for(int i=rows-2; i>=0; i--)
            dp[i][cols-1] = max(1, dp[i+1][cols-1]-dungeon[i][cols-1]);
        for(int j=cols-2; j>=0; j--)
            dp[rows-1][j] = max(1, dp[rows-1][j+1]-dungeon[rows-1][j]);
        for(int i=rows-2; i>=0; i--){
            for(int j=cols-2; j>=0; j--){
                dp[i][j] = min(max(1, dp[i+1][j]-dungeon[i][j]), max(1, dp[i][j+1]-dungeon[i][j]));
            }
        }
        return dp[0][0];
    }
};
