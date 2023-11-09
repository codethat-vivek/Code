# Question Link - https://leetcode.com/problems/minimum-increment-operations-to-make-array-beautiful/

# Solution - 

class Solution:
    def minIncrementOperations(self, nums: List[int], k: int) -> int:
        n = len(nums)
        ans = 0
        
        @lru_cache(None)
        def helper(idx, dist):
            if idx >= n:
                return 0
            
            no = 10**40
            if dist < 2:
                no = helper(idx+1, dist+1)
            yes = helper(idx+1, 0) + max(k-nums[idx], 0)
            
            return min(no, yes)
            
        return helper(0, 0)
            
