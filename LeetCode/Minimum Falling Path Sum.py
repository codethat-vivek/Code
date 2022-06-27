# Question Link - https://leetcode.com/problems/minimum-falling-path-sum/

# Solution - 

class Solution:
    def minFallingPathSum(self, matrix: List[List[int]]) -> int:
        n = len(matrix)
        for i in range(1, n):
            for j in range(n):            
                if 1<=j<=n-2:
                    matrix[i][j] += min(matrix[i-1][j-1], matrix[i-1][j], matrix[i-1][j+1])
                elif j == 0:
                    matrix[i][j] += min(matrix[i-1][j], matrix[i-1][j+1])
                elif j == n-1:
                    matrix[i][j] += min(matrix[i-1][j-1], matrix[i-1][j])
        return min(matrix[n-1])
