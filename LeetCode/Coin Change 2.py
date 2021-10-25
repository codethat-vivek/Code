# Question Link - https://leetcode.com/problems/coin-change-2/

# Solution - 

class Solution:
    # memoized
    def helper(self, target, coins, start, dt):
        if target == 0 : return 1
        if target < 0 : return 0
        if start == len(coins) : return 0
        if (target, start) in dt:
            return dt[(target, start)]
        firstWay = self.helper(target-coins[start], coins, start, dt);
        secondWay = self.helper(target, coins, start+1, dt);
        dt[(target, start)] = firstWay + secondWay
        return firstWay + secondWay
    def change(self, amount: int, coins: List[int]) -> int:
        return self.helper(amount, coins, 0, {});
    
