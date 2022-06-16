# Question Link - https://leetcode.com/problems/partition-array-such-that-maximum-difference-is-k/

# Solution - 

class Solution:
    def partitionArray(self, nums: List[int], k: int) -> int:
        if k == 0:
            return len(set(nums))
        nums.sort()
        minimum = nums[0]
        maximum = nums[0]
        
        ans = 1

        for i in range(len(nums)):
            maximum = nums[i]
            if maximum-minimum > k:
                minimum = nums[i]
                ans += 1
            
        return ans
