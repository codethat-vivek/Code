# Question Link - https://leetcode.com/problems/largest-local-values-in-a-matrix/

# Solution - 

class Solution:
    def largestLocal(self, grid: List[List[int]]) -> List[List[int]]:
        ans = []
        rows, cols = len(grid), len(grid[0])
        for i in range(rows-2):
            ans.append([])
            for j in range(cols-2):
                mx = -1
                for p in range(i, i+3):
                    for q in range(j, j+3):
                        mx = max(mx, grid[p][q])
                ans[i].append(mx)
        return ans
