# Question Link - https://leetcode.com/problems/largest-positive-integer-that-exists-with-its-negative/

# Solution - 

class Solution:
    def findMaxK(self, nums: List[int]) -> int:
        hashh = collections.Counter(nums)
        for i in range(max(nums), 0, -1):
            if hashh[i] > 0 and hashh[-i] > 0:
                return i
        return -1
