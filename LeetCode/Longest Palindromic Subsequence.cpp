// Question Link - https://leetcode.com/problems/longest-palindromic-subsequence/

// Solution - 

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        vector<vector<int>>dp(n, vector<int>(n, 0));
        for(int i=0; i<n; i++)dp[i][i] = 1;
        for(int i=n-1; i>=0; i--){
            for(int j=i; j<n; j++){
                if(i == j)continue;
                if(s[i] == s[j])
                    dp[i][j] = dp[i+1][j-1]+2;
                else
                    dp[i][j] = max(max(dp[i][j-1], dp[i+1][j]), dp[i+1][j-1]);
            }
        }
        return dp[0][n-1];
    }
};
