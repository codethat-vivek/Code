# Question Link - https://leetcode.com/problems/absolute-difference-between-maximum-and-minimum-k-elements/description/

# Solution - 

class Solution:
    def absDifference(self, nums: List[int], k: int) -> int:
        return abs(sum(sorted(nums)[:k]) - sum(sorted(nums, reverse=True)[:k]))
