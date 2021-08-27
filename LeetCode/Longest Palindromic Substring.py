# Question Link - https://leetcode.com/problems/longest-palindromic-substring/

# Solution - 

class Solution:
    def longestPalindrome(self, s):
        ans = ''
        dp = [[0]*len(s) for _ in range(len(s))]
        for i in range(len(s)):
            dp[i][i] = True
            ans = s[i]

        for i in range(len(s)-1,-1,-1):
            for j in range(i+1,len(s)):  
                if s[i] == s[j]:
                    if j-i ==1 or dp[i+1][j-1] is True:
                        dp[i][j] = True
                        if len(ans) < j-i+1:
                            ans = s[i:j+1]

        return ans
