# Question Link - https://leetcode.com/problems/minimum-average-difference/

# Solution - 

class Solution:
    def minimumAverageDifference(self, nums: List[int]) -> int:
        n = len(nums)
        prefix = [nums[0]]
        for i in range(1, n):
            prefix.append(prefix[-1] + nums[i])
        
        idx, mn = None, 10**20
        
        for i in range(n):
            first = prefix[i]//(i+1)
            if i != n-1:
                second = (prefix[-1]-prefix[i])//(n-i-1)
            else:
                second = 0
            if mn > abs(first-second):
                mn = abs(first-second)
                idx = i
        
        return idx
