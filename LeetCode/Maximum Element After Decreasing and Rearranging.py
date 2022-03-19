# Question Link - https://leetcode.com/problems/maximum-element-after-decreasing-and-rearranging/

# Solution - 

class Solution:
    def maximumElementAfterDecrementingAndRearranging(self, arr: List[int]) -> int:
        arr.sort()
        for i in range(len(arr)):
            if i == 0:
                arr[0] = 1
            arr[i] = min(arr[i-1]+1, arr[i])
        return arr[len(arr)-1]
