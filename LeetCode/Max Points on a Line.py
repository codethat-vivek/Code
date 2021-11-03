# Question Link - https://leetcode.com/problems/max-points-on-a-line/

# Solution - 

class Solution:
    def slope(self, p, q):
        if p[0] == q[0]: # vertical line
            #return infinity
            return None
        return (p[1]-q[1])/(p[0]-q[0])
    
    def maxPoints(self, points: List[List[int]]) -> int:
        n = len(points)
        ans = 0
        if n <= 2:return n
        for i in range(n-ans):
            dt_sub = dict()
            for j in range(i+1, n):
                sl = self.slope(points[i], points[j])
                if sl in dt_sub:
                    dt_sub[sl] += 1
                else:
                    dt_sub[sl] = 2
                ans = max(ans, dt_sub[sl])
        return ans
                    
                
