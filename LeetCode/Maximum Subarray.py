# Question Link - https://leetcode.com/problems/maximum-subarray/

# Solution - 

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        every = True
        for num in nums:
            if num > 0:
                every = False
                break
        if every:
            return max(nums)
        temp = 0
        best = 0
        for each in nums:
            temp = max(each, temp + each)
            best = max(best, temp)
            
        return best
