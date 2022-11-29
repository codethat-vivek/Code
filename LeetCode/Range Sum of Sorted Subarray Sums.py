# Question Link - https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/

# Solution - 

class Solution:
    def rangeSum(self, nums: List[int], n: int, left: int, right: int) -> int:
        from sortedcontainers import SortedList
        sub = SortedList([])
        for i in range(len(nums)):
            sm = 0
            for j in range(i, len(nums)):
                sm += nums[j]
                sub.add(sm)
        
        return (sum(sub[left-1:right]))%(10**9+7)
