# Question Link - https://leetcode.com/problems/subsets/submissions/

# Solution - 

class Solution:
    def helper(self, nums, i, n, k):
        if k == 0:
            return [[]]
        if k == n-i:
            return [nums[i:]]
        
        f = self.helper(nums, i+1, n, k)
        s = self.helper(nums, i+1, n, k-1)
        
        for j in range(len(s)):
            s[j].append(nums[i])
        
        return f+s
        
        
    def subsets(self, nums: List[int]) -> List[List[int]]:
        ans = []
        for i in range(len(nums)+1):
            t = self.helper(nums, 0, len(nums), i)
            for each in t:
                ans.append(each)
        return ans
