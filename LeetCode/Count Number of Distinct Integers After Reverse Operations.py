# Question Link - https://leetcode.com/problems/count-number-of-distinct-integers-after-reverse-operations/

# Solution - 

class Solution:
    def countDistinctIntegers(self, nums: List[int]) -> int:
        def rev(n):
            return int(str(n)[::-1])
        
        st = set(nums)
        for each in nums:
            st.add(rev(each))
        return len(st)
        
