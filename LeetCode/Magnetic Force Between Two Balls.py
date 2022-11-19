# Question Link - https://leetcode.com/problems/magnetic-force-between-two-balls/

# Solution - 

class Solution:
    def helper(self, position, force):
        prev = position[0]
        balls = 1
        for i in range(1, len(position)):
            if abs(position[i]-prev) >= force:
                prev = position[i]
                balls += 1
        return balls
        
            
    def maxDistance(self, position: List[int], m: int) -> int:
        position.sort()
        low, high = 0, position[-1]
        ans = None
        while low <= high:
            mid = (low + high)//2
            x = self.helper(position, mid)
            #print(low, high, mid, x)
            if x >= m:
                ans = mid
                low = mid+1
            else:
                high = mid-1
        return ans
