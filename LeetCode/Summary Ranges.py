# Question Link - https://leetcode.com/problems/summary-ranges/

# Solution - 

class Solution:
    def summaryRanges(self, nums: List[int]) -> List[str]:
        n = len(nums)
        if n == 0:return []
        
        ans = []
        
        start = end = nums[0]
        for i in range(n-1):
            if nums[i+1] == 1+nums[i]:
                continue
            else:
                end = nums[i]
            
            if start == end:
                ans.append(str(start))
            else:
                ans.append(str(start) + "->" + str(end))
            start = end = nums[i+1]
        if start == end == nums[n-1]:
            ans.append(str(start))
        else:
            end = nums[n-1]
            ans.append(str(start) + "->" + str(end))
        return ans
