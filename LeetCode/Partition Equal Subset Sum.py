# Question Link - https://leetcode.com/problems/partition-equal-subset-sum/

# Solution - 

class Solution:
    def isSubsetSum(self, nums, n, target):
        dp = [[False for _ in range(target+1)] for i in range(n+1)]
        for i in range(n+1):
            for j in range(target+1):
                if j == 0:
                    dp[i][j] = True
                elif i == 0:
                    dp[i][j] = False
                elif nums[i-1] > j:
                    dp[i][j] = dp[i-1][j]
                else:
                    dp[i][j] = (dp[i-1][j] or dp[i-1][j-nums[i-1]])
        
        return dp[n][target]
        
    def canPartition(self, nums: List[int]) -> bool:
        n = len(nums)
        totalSum = sum(nums)
        if totalSum % 2 != 0:
            return False
        return self.isSubsetSum(nums, n, totalSum//2)
