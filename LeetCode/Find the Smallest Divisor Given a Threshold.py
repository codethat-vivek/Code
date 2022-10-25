# Question Link - https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/

# Solution - 

class Solution:
    def smallestDivisor(self, nums: List[int], threshold: int) -> int:
        
        def calc(divisor):
            res = 0
            for each in nums:
                res += math.ceil(each/divisor)
            return res
        
        ans = inf
        def bs(start, end):
            
            if start > end:
                return
            
            mid = (start+end)//2
            x = calc(mid)
            
            if x <= threshold:
                nonlocal ans
                ans = min(ans, mid)
                bs(start, mid-1)
            else:
                bs(mid+1, end)
            
            
            
        bs(1, max(nums))
        return ans
            
                
