# Question Link - https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/

# Solution - 

class Solution:
        
    def minOperations(self, nums: List[int]) -> int:
        dt = collections.Counter(nums)
        ans = 0
        for key in dt:
            if dt[key] == 1:
                return -1
            r = dt[key] % 3
            d = dt[key]//3
            if r == 0:
                ans += d
            else:
                ans += (d+1)
            
        return ans

  
