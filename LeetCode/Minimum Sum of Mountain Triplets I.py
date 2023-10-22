# Question Link - https://leetcode.com/problems/minimum-sum-of-mountain-triplets-i/

# Solution - 

class Solution:
    def minimumSum(self, nums: List[int]) -> int:
        sm, n = 1000, len(nums)
        
        for i in range(n):
            for j in range(i+1, n):
                for k in range(j+1, n):
                    if nums[i] < nums[j] and nums[k] < nums[j]:
                        sm = min(sm, nums[i]+nums[j]+nums[k])
        if sm == 1000:
            return -1
        return sm
