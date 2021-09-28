# Question Link - https://leetcode.com/problems/sort-array-by-parity-ii/

# Solution - 

class Solution:
    def sortArrayByParityII(self, nums: List[int]) -> List[int]:
        i, j = 0, 1  # i -> even, j -> odd
        while i < len(nums) and j < len(nums):
            while j < len(nums) and nums[j] % 2 != 0:
                j += 2
            while i < len(nums) and nums[i] % 2 == 0:
                i += 2
            if i < len(nums) and j < len(nums) and nums[j] % 2 == 0 and nums[i] % 2 != 0:
                nums[i], nums[j] = nums[j], nums[i]
        
        return nums
