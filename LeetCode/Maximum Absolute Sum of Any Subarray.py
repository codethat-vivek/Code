# Question Link - https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/description/

# Solution - 

class Solution:
    def maxAbsoluteSum(self, nums: List[int]) -> int:
        n = len(nums)
        mx, mn, ans = nums[0], nums[0], abs(nums[0])
        for i in range(1, n):
            num = nums[i]
            ans = max(ans, abs(num), abs(num+mx), abs(num+mn))
            mx = max(num+mx, num)
            mn = min(num+mn, num)
        return ans
