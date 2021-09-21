# Question Link - https://leetcode.com/problems/search-a-2d-matrix/

# Solution - 

class Solution:
    def bs(self, arr, start, end, target):
        while start <= end:
            mid = start + (end - start)//2
            if arr[mid] == target:
                return True
            elif arr[mid] < target:
                start = mid+1
            else:
                end = mid-1
        return False
            
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        arr = []
        for i in range(len(matrix)):
            for j in range(len(matrix[i])):
                arr.append(matrix[i][j])
        return self.bs(arr, 0, len(arr)-1, target)
