# Question Link - https://leetcode.com/problems/array-with-elements-not-equal-to-average-of-neighbors/

# Solution - 

class Solution:
    def rearrangeArray(self, nums: List[int]) -> List[int]:
        nums.sort()
        arr = [0 for _ in range(len(nums))]
        i = 0
        j = 0
        while i < len(nums):
            arr[i] = nums[j]
            j += 1
            i += 2
        i = 1
        while i < len(nums):
            arr[i] = nums[j]
            j += 1
            i += 2
        return arr
