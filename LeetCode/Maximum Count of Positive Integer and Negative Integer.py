# Question Link - https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/

# Solution - 

class Solution:
    def maximumCount(self, nums: List[int]) -> int:
        pos = sum([1 for x in nums if x > 0])
        neg = sum([1 for x in nums if x < 0])
        return max(pos, neg)
