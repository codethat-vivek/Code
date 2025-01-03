# Question Link - https://leetcode.com/problems/number-of-ways-to-split-array/

# Solution - 

class Solution:
    def waysToSplitArray(self, nums: List[int]) -> int:
        n = len(nums)
        pref = [0]*n
        pref[0] = nums[0]
        for i in range(1, n):
            pref[i] = pref[i-1] + nums[i]
        
        ans = 0
        for i in range(n-1):
            if pref[i] >= pref[n-1]-pref[i]:
                ans+=1
        
        return ans
