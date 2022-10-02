# Question Link - https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/

# Solution - 

class Solution:
    def numRollsToTarget(self, n: int, k: int, target: int) -> int:
        
        MOD = int(1e9+7)
        
        def f(t, idx): # idx - index of dice
            if t == 0 and idx == n: return 1
            if t < 0 : return 0
            if idx >= n : return 0
            
            if dp[t][idx] != -1 : return dp[t][idx]
            
            ways = 0
            for i in range(1, k+1):
                x = f(t-i, idx+1)
                ways = (ways+x)%MOD
            dp[t][idx] = ways
            return ways
            
        dp = [[-1 for _ in range(31)] for _ in range(1001)]
        
        return f(target, 0)
