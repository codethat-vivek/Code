# Question Link - https://leetcode.com/problems/count-servers-that-communicate/description/

# Solution - 

class Solution:
    def countServers(self, grid: List[List[int]]) -> int:
        r, c = len(grid), len(grid[0])
        rows, cols, total = [0]*r, [0]*c, 0
        for i in range(r):
            for j in range(c):
                if grid[i][j] == 1:
                    total += 1
                    rows[i] += 1
                    cols[j] += 1
        
        for i in range(r):
            for j in range(c):
                if grid[i][j] == 1 and rows[i] == 1 and cols[j] == 1:
                    total -= 1
        
        return total
