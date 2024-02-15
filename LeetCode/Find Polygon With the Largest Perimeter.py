# Question Link - https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/

# Solution - 

class Solution:
    def largestPerimeter(self, nums: List[int]) -> int:
        nums.sort()
        sm = ans = i = 0
        while i<len(nums)-1:
            sm += nums[i]
            if i >= 1 and sm > nums[i+1]:
                ans = sm+nums[i+1]
            i += 1
            
        if not ans:
            return -1
        return ans
