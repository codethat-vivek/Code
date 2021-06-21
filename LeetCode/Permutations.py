# Question Link - https://leetcode.com/problems/permutations/submissions/

# Solution - 

class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        ans = []
        if n == 1:
            return [[nums[0]]]
        for i in range(n):
            rem = nums[:i] + nums[i+1:]
            temp = self.permute(rem)
            for each in temp:
                each.append(nums[i])
                ans.append(each)
        return ans
