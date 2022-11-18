# Question Link - https://leetcode.com/problems/koko-eating-bananas/

# Solution - 

class Solution:
    def helper(self, piles, speed):
        hoursRequired = 0
        for p in piles:
            hoursRequired += math.ceil(p/speed)
        return hoursRequired
    
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        low, high = 1, max(piles)
        ans = None
        while low <= high:
            mid = (low + high)//2
            hours = self.helper(piles, mid)
            if hours > h:
                #increase my speed
                low = mid+1
            else:
                high = mid-1
                ans = mid
        return ans
