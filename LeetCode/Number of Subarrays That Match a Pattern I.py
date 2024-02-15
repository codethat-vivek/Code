# Question Link - https://leetcode.com/problems/number-of-subarrays-that-match-a-pattern-i/

# Solution - 

class Solution:
    def countMatchingSubarrays(self, nums: List[int], pattern: List[int]) -> int:
        n, m = len(nums), len(pattern)
        i, ans = 0 , 0
        while i <= n-m-1:
            j, times = i, m
            while times:
                if (pattern[j-i] == 1 and nums[j] < nums[j+1]) or (pattern[j-i] == 0 and nums[j] == nums[j+1]) or (pattern[j-i] == -1 and nums[j] > nums[j+1]):
                    j += 1
                    times -= 1
                else:
                    break
            
            if not times:
                ans += 1
            i += 1
        
        return ans
