# Question Link - https://leetcode.com/problems/minimum-time-to-make-rope-colorful/

# Solution - 

class Solution:
    def minCost(self, colors: str, neededTime: List[int]) -> int:
        ans = 0
        n = len(colors)
        mx = neededTime[0]
        sm = neededTime[0]
        
        for i in range(1, n):
            if colors[i] == colors[i-1] : 
                sm += neededTime[i]
                mx = max(mx, neededTime[i])
            else:
                ans += (sm - mx)
                sm = neededTime[i]
                mx = neededTime[i]
        ans += (sm-mx)
        
        return ans
