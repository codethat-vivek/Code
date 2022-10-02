# Question Link - https://leetcode.com/problems/bitwise-xor-of-all-pairings/

# Solution - 

class Solution:
    
    def xorAllNums(self, nums1: List[int], nums2: List[int]) -> int:
        def xorr(nums):
            ans = 0
            for e in nums:
                ans = ans ^ e
            return ans
        
        
        x = xorr(nums1)
        y = xorr(nums2)
        
        m, n = len(nums1), len(nums2)
        
        if m%2 and n%2 : # both are odd
            return x^y
        if m%2: #nums2 is of even length
            return y
        if n%2:
            return x
        return 0
