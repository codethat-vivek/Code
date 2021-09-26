# Question Link - https://leetcode.com/problems/subarray-sum-equals-k/

# Solution - 

class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        # Prefix Sum
        dt = dict()
        dt[0] = 1
        ans = sm = 0
        for i in range(len(nums)):
            sm += nums[i]
            if sm-k in dt:
                ans += dt[sm-k]
            if sm in dt:
                dt[sm] += 1
            else:
                dt[sm] = 1
        return ans
