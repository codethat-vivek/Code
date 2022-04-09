// Question Link - https://leetcode.com/problems/wildcard-matching/

// Solution - 

class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<int>>dp;
        int rows = s.length(), cols = p.length();
        dp.assign(rows+1, vector<int>(cols+1, 0));
        dp[0][0] = 1;
        bool seen = false;
        for(int j=1; j<=cols; j++){
            if(!seen && p[j-1] == '*')
                dp[0][j] = 1;
            if( (p[j-1] >= 97 && p[j-1] <= 122) || p[j-1] == '?' )
                seen = true;
        }
        
        for(int i=1; i<=rows; i++){
            for(int j=1; j<=cols; j++){
                if(s[i-1] == p[j-1] || p[j-1] == '?')// both are characters or character in pattern is '?'
                    dp[i][j] = dp[i-1][j-1];
                else if(p[j-1] >= 97 && p[j-1] <= 122)
                    dp[i][j] = 0;
                else
                    dp[i][j] = dp[i-1][j-1] | dp[i][j-1] | dp[i-1][j];
                
            }
        }
        
        return dp[rows][cols] == 1 ? true : false;
        
    }
};
