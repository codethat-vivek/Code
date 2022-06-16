# Question Link - https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/

# Solution - 

class Solution:
    def maximumBags(self, capacity: List[int], rocks: List[int], additionalRocks: int) -> int:
        n = len(rocks)
        diff = []
        for i in range(n):
            diff.append(capacity[i]-rocks[i])
        
        ans = 0
        diff.sort()
        for i in range(n):
            additionalRocks -= diff[i]
            if additionalRocks >= 0:
                ans += 1
            else:
                break
        
        return ans
