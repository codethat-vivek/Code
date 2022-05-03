# Question Link - https://leetcode.com/problems/shortest-unsorted-continuous-subarray/

# Solution - 

class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        arr = sorted(nums)
        start = end = 10**10
        for i in range(len(nums)):
            if nums[i] != arr[i]:
                start = i
                break
        if start == 10**10:
            return 0
        for i in range(len(nums)-1, -1, -1):
            if nums[i] != arr[i]:
                end = i
                break
        return end-start+1
