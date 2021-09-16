# Question Link - https://leetcode.com/problems/01-matrix/

# Solution - 

class Solution:
    def updateMatrix(self, mat: List[List[int]]) -> List[List[int]]:
        rows = len(mat)
        cols = len(mat[0])
        #print(rows, cols)
        inf = int(1e9+7)
        ans = [[inf for i in range(cols+2)] for j in range(rows+2)]
        for i in range(1, rows+1):
            for j in range(1, cols+1):
                if mat[i-1][j-1] == 0:
                    ans[i][j] = 0
                else:
                    ans[i][j] = 1+min(ans[i][j], ans[i-1][j], ans[i][j-1])
        
        for i in range(rows, 0, -1):
            for j in range(cols, 0, -1):
                if mat[i-1][j-1] == 0:
                    ans[i][j] = 0
                else:
                    ans[i][j] = min(ans[i][j], 1+min(ans[i+1][j], ans[i][j+1]))
        
        res = []
        for i in range(1, rows+1):
            res.append([])
            for j in range(1, cols+1):
                res[i-1].append(ans[i][j])
        return res
