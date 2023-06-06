# Question Link - https://leetcode.com/problems/can-make-arithmetic-progression-from-sequence/

# Solution - 

class Solution:
    def canMakeArithmeticProgression(self, arr: List[int]) -> bool:
        n = len(arr)
        if n == 2 : return True
        arr.sort()
        for i in range(n-1):
            if arr[i+1] - arr[i] != arr[1] - arr[0]:
                return False
        return True
