# Question Link - https://leetcode.com/problems/spiral-matrix/

# Solution - 

class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        # right, down, left, up
        direction = [1, 0, 0, 0]
        rows = len(matrix)
        cols = len(matrix[0])
        #print(rows, cols)
        visited = [[False for _ in range(cols)] for i in range(rows)]
        ans = []
        i = j = 0
        
        while len(ans) < rows*cols:
            if direction[0]: #right
                if j < cols and visited[i][j] == False:
                    ans.append(matrix[i][j])
                    visited[i][j] = True
                    j += 1
                else:
                    direction[0] = 0
                    direction[1] = 1
                    i += 1
                    j -= 1
            elif direction[1]: #down
                if i < rows and visited[i][j] == False:
                    ans.append(matrix[i][j])
                    visited[i][j] = True
                    i += 1
                else:
                    direction[1] = 0
                    direction[2] = 1
                    j -= 1
                    i -= 1
            elif direction[2]: #left
                if j >= 0 and visited[i][j] == False:
                    ans.append(matrix[i][j])
                    visited[i][j] = True
                    j -= 1
                else:
                    direction[2] = 0
                    direction[3] = 1
                    i -= 1
                    j += 1
            elif direction[3]: #up
                if i >= 0 and visited[i][j] == False:
                    ans.append(matrix[i][j])
                    visited[i][j] = True
                    i -= 1
                else:
                    direction[3] = 0
                    direction[0] = 1
                    j += 1
                    i += 1             
                
        return ans
