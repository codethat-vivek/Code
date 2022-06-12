# Question Link - https://leetcode.com/problems/successful-pairs-of-spells-and-potions/

# Solution - 

class Solution:
    def successfulPairs(self, spells: List[int], potions: List[int], success: int) -> List[int]:
        from bisect import bisect_left
        
        m, n = len(spells), len(potions)
        ans = []
        potions.sort()
        for ele in spells:
            t = success/ele
            if t != int(t):
                t = int(t)+1
            spot = bisect_left(potions, t)
            ans.append(n-spot)
        return ans
            
