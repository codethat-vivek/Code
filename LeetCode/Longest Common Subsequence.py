# Question Link - https://leetcode.com/problems/longest-common-subsequence/

# Solution - 

class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        x = len(text1)
        y = len(text2)
        dp = [[0 for i in range(x+1)] for j in range(y+1)]
        for i in range(1, y+1):
            for j in range(1, x+1):
                if text2[i-1] != text1[j-1]:
                    dp[i][j] = max(dp[i][j-1], dp[i-1][j])
                else:
                    dp[i][j] = dp[i-1][j-1]+1
        return dp[y][x]
