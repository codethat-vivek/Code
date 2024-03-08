# Question Link - https://leetcode.com/problems/count-elements-with-maximum-frequency/

# Solution - 

class Solution:
    def maxFrequencyElements(self, nums: List[int]) -> int:
        values = list(collections.Counter(nums).values())
        maxVal = max(values)
        return maxVal*values.count(maxVal)
