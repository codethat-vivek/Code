# Question Link - https://leetcode.com/problems/arranging-coins/

# Solution - 

class Solution:
    def arrangeCoins(self, n: int) -> int:
        t = int(sqrt(2*n))
        if t*(t+1) <= 2*n:return t
        return t-1
