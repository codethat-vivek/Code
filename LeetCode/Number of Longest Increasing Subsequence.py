# Question Link - https://leetcode.com/problems/number-of-longest-increasing-subsequence/

# Solution - 

class Solution:
    def findNumberOfLIS(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [1 for i in range(n)]
        length = [1 for i in range(n)]
        lis = 1
        for i in range(1, n):
            for j in range(i):
                if nums[i] > nums[j] and dp[i] < 1 + dp[j]:
                        dp[i] = 1 + dp[j]
                        length[i] = length[j]
                elif dp[i] == 1 + dp[j]:
                    length[i] += length[j]
            lis = max(lis, dp[i])
        print(dp)
        print(length)
        res = 0
        for i in range(n):
            if dp[i] == lis:
                res += length[i]
        return res
        
