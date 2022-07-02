# Question Link - https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/

# Solution - 

class Solution:
    def maxArea(self, h: int, w: int, horizontalCuts: List[int], verticalCuts: List[int]) -> int:
        horizontalCuts.sort()
        verticalCuts.sort()
        
        length = breadth = -1
        for i in range(1, len(horizontalCuts)):
            breadth = max(breadth, horizontalCuts[i]-horizontalCuts[i-1])
        breadth = max(breadth, horizontalCuts[0])
        breadth = max(breadth, h-horizontalCuts[-1])
        
        for j in range(1, len(verticalCuts)):
            length = max(length, verticalCuts[j]-verticalCuts[j-1])
        length = max(length, verticalCuts[0])
        length = max(length, w-verticalCuts[-1])
        
        mod = int(1e9+7)
        return (length*breadth)%mod
