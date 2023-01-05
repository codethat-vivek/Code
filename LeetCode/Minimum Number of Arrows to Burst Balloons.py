# Question Link - https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

# Solution - 

class Solution:
    def findMinArrowShots(self, points: List[List[int]]) -> int:
        points.sort()
        #print(points)
        n, arrows = len(points), 0
        intersection = points[0]
        for i in range(n):
            if intersection[1] >= points[i][0]:
                # there is an intersection
                intersection = [points[i][0], min(intersection[1], points[i][1])]
            else:
                arrows += 1
                intersection = points[i]
        return arrows+1
                
        
