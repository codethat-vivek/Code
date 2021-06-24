# Question Link - https://leetcode.com/problems/permutations-ii/

# Solution - 

class Solution:
    def permuteUnique(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        ans = []
        if n == 1:
            return [[nums[0]]]
        
        done = set()
        
        for i in range(n):
            if nums[i] not in done:
                rem = nums[:i] + nums[i+1:]
                temp = self.permuteUnique(rem)
                for each in temp:
                    each.append(nums[i])
                    ans.append(each)
            if nums[i] in done:
                continue
            
            done.add(nums[i])
        
        return ans
