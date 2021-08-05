// Question Link - https://leetcode.com/problems/maximal-square/

// Solution - 

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        // errichto explanation
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        vector<vector<int>> dp(rows, vector<int>(cols, 0));
        int ans = 0;
        
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(matrix[i][j] == '1'){
                    dp[i][j] = 1;
                    if(i > 0 && j > 0)
                        dp[i][j] += min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]});
                }
                
                ans = max(ans, dp[i][j]);
            }
            
        }
        return ans*ans;
    }
};
