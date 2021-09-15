# Question Link - https://leetcode.com/problems/maximum-matrix-sum/

# Solution - 

class Solution:
    def maxMatrixSum(self, matrix: List[List[int]]) -> int:
        pos = []
        neg = []
        for i in range(len(matrix)):
            for j in range(len(matrix[0])):
                if matrix[i][j] > 0:
                    pos.append(matrix[i][j])
                else:
                    neg.append(matrix[i][j])
        
        for i in range(len(neg)):
                neg[i] *= -1;
        
        if pos == []:
            neg.sort()
            if len(neg) % 2 != 0:
                return sum(neg)-2*neg[0]
            return sum(neg)
        
        if len(neg) % 2 != 0:
            neg.sort()
            if neg[0] <= min(pos):
                return sum(pos)+sum(neg)-2*neg[0]
            else:
                return sum(pos)+sum(neg)-2*min(pos)
        return sum(pos) + sum(neg)
