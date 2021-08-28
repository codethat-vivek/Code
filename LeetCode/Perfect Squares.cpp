// Question Link - https://leetcode.com/problems/perfect-squares/

// Solution - 

class Solution {
public:
    int numSquares(int n) {
        vector<int>dp(n+1, 100001);
        vector<int>squares;
        int i = 1;
        while(i*i <= n){
            squares.push_back(i*i);
            i++;
        }
        dp[0] = 1;
        dp[1] = 1;
        for(int i=2; i<n+1; i++){
            if(sqrt(i) == (int)sqrt(i))
                dp[i] = 1;
            else{
                for(int j=0; j<squares.size() && squares[j] < i; j++)
                    dp[i] = min(dp[i], 1+dp[i-squares[j]]);
            }
        }
        return dp[n];
    }
};
