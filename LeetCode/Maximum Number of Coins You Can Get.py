# Question Link - https://leetcode.com/problems/maximum-number-of-coins-you-can-get/

# Solution - 

class Solution:
    def maxCoins(self, piles: List[int]) -> int:
        n = len(piles)
        piles.sort()
        a, b, c = n-1, n-2, 0
        ans = 0
        
        while c < a and c < b:
            ans += piles[b]
            a -= 2
            b = a-1
            c += 1
        
        return ans
    
