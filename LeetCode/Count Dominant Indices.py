# Question Link - https://leetcode.com/problems/count-dominant-indices/description/

# Solution Link - 

class Solution:
    def dominantIndices(self, nums: List[int]) -> int:
        n = len(nums)
        prefix = [nums[0]]
        for i in range(1, n):
            prefix.append(prefix[-1] + nums[i])
        dom = 0
        for i in range(n-1):
            if nums[i] * (n-i-1) > prefix[-1] - prefix[i]:
                dom += 1
        return dom
