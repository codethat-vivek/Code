# Question Link - https://leetcode.com/problems/toeplitz-matrix/

# Solution - 

class Solution:
    def isToeplitzMatrix(self, matrix: List[List[int]]) -> bool:
        rows, cols = len(matrix), len(matrix[0])
        i = j = 0
        while i < rows:
            x, y, val = i, j, matrix[i][j]
            while 0<=x<rows and 0<=y<cols:
                if matrix[x][y] != val:
                    return False
                x += 1
                y += 1
            i += 1
        
        i, j = 0, 1
        while j < cols:
            x, y, val = i, j, matrix[i][j]
            while 0<=x<rows and 0<=y<cols:
                if matrix[x][y] != val:
                    return False
                x += 1
                y += 1
            j += 1
        return True
