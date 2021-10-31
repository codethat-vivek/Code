# Question Link - https://leetcode.com/problems/coin-change/

# Solution - 

inf = int(1e9+7)
class Solution:
    def helper(self, coins, target, dt):
        if target < 0:
            return inf
        if target == 0:
            return 0
        if target in dt : return dt[target]
        ans = inf
        for denomination in coins:
            rem = target - denomination
            temp = self.helper(coins, rem, dt)
            if temp == inf : continue
            ans = min(ans, temp+1)
        dt[target] = ans
        return ans
            
    def coinChange(self, coins: List[int], amount: int) -> int:
        if amount == 0:
            return 0
        ans = self.helper(coins, amount, {})
        if ans == inf : return -1
        return ans
