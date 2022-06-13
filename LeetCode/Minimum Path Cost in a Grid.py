# Question Link - https://leetcode.com/problems/minimum-path-cost-in-a-grid/

# Solution - 

class Solution:
    def minPathCost(self, grid: List[List[int]], moveCost: List[List[int]]) -> int:
        rows, cols = len(grid), len(grid[0])
        inf = 10**10
        dp = [[inf for _ in range(cols)] for _ in range(rows)]
        for j in range(cols):
            dp[0][j] = grid[0][j]
        
        for i in range(1, rows):
            for j in range(cols):
                for k in range(cols):
                    dp[i][j] = min(dp[i][j], grid[i][j]+dp[i-1][k]+moveCost[grid[i-1][k]][j])
        
        #print(dp)
        
        return min(dp[rows-1])
                
