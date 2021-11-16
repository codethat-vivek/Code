# Question Link - https://leetcode.com/problems/largest-divisible-subset/

# Solution - 

class Solution:
    def largestDivisibleSubset(self, nums: List[int]) -> List[int]:
        '''
            [1, 2, 3, 4, 6, 8, 12, 16, 24]
            [1, 2, 4, 8, 16] and [1, 3, 6, 12, 24]
            
        '''
        if len(nums) == 1:
            return nums
        nums.sort()
        dp = [1 for _ in range(len(nums))] # dp[i] - lds including nums[i]
        lds = -1 # stores the longest divisible subsequence
        lastNumber = None
        for i in range(1, len(nums)):
            for j in range(i):
                if nums[i] % nums[j] == 0:
                    dp[i] = max(dp[i], dp[j]+1)
            if lds < dp[i]:
                lds = dp[i]
                lastNumber = nums[i]
        
        ans = []
        for i in range(len(dp)-1, -1, -1): # for finding the longest divisible subsequence
            if dp[i] == lds and lastNumber % nums[i] == 0:
                ans.append(nums[i])
                lds -= 1
                lastNumber = nums[i]
        return ans
                    
