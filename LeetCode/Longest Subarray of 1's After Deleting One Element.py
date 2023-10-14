# Question Link - https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/

# Solution - 

class Solution:
    def longestSubarray(self, nums: List[int]) -> int:
        n, i, j = len(nums), 0, 0
        zero = 1
        cnt = best = 0
        while j < n:
            if nums[j] == 1:
                cnt += 1
                j += 1
            else:
                if zero > 0:
                    zero -= 1
                elif zero == 0:
                    best = max(best, cnt)
                    while nums[i] == 1:
                        i += 1
                        cnt -= 1
                    i += 1
                j += 1
        
        best = max(best, cnt)
        if 0 not in nums: 
            return best - 1
        return best
                    
