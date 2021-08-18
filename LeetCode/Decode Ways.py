# Question Link - https://leetcode.com/problems/decode-ways/

# Solution - 

class Solution:
    def helper(self, s, memo):
        if s in memo:
            return memo[s]
        size = len(s)
        if size == 0:
            return 0
        if s[0] == "0":
            return 0
        if size == 1:
            return 1
        if size == 2:
            if int(s) <= 26:
                if s[1] != "0":
                    return 2
                return 1
        ways = self.helper(s[1:], memo)
        if int(s[:2]) <= 26:
            ways += self.helper(s[2:], memo)
        memo[s] = ways
        return ways
    
    def numDecodings(self, s: str) -> int:
        return self.helper(s, {})
