# Question Link - https://leetcode.com/problems/determine-whether-matrix-can-be-obtained-by-rotation/

# Solution - 

class Solution:
    def findRotation(self, mat: List[List[int]], target: List[List[int]]) -> bool:
        if mat == target:
            return True
        for i in range(3):
            mat = [list(list(i)[::-1]) for i in zip(*mat)]
            if mat == target:
                return True
        return False
