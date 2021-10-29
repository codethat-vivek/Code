# Question Link - https://leetcode.com/problems/count-nice-pairs-in-an-array/

# Solution - 

inf = int(1e9+7)
class Solution:
        
    def countNicePairs(self, nums: List[int]) -> int:
        from math import comb
        from collections import Counter
        diff = []
        for i in nums:
            rev = int(str(i)[::-1])
            diff.append(i-rev)
        count = Counter(diff)
        ans = 0
        for each in count:
            ans = ( ans + comb(count[each], 2) ) % inf
        return ans
