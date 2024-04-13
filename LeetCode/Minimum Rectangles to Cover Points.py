# Question Link - https://leetcode.com/problems/minimum-rectangles-to-cover-points/

# Solution - 

class Solution:
    def minRectanglesToCoverPoints(self, points: List[List[int]], w: int) -> int:
        points.sort()
        n = len(points)
        
        ans = 1
        start = points[0][0]
        
        for i in range(n):
            if start <= points[i][0] <= start + w:
                continue
            else:
                ans += 1
                start = points[i][0]
        
        return ans
