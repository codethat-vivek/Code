# Question Link - https://leetcode.com/problems/where-will-the-ball-fall/

# Solution - 

class Solution:
    def findBall(self, grid: List[List[int]]) -> List[int]:
        rows, cols = len(grid), len(grid[0])
        ans = []
        
        def f(i, j):
            if i == rows:
                return j
            if not 0<=j<cols:
                return -1
            if (j == 0 and grid[i][j] == -1) or (j == cols-1 and grid[i][j] == 1):
                return -1
            if grid[i][j] == 1:
                if grid[i][j+1] == -1:
                    return -1
                return f(i+1, j+1)
            if grid[i][j-1] == 1:
                return -1
            return f(i+1, j-1)
            
        
        for j in range(cols):
            ans.append(f(0, j))
        return ans
