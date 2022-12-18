# Question Link - https://leetcode.com/problems/maximum-value-of-a-string-in-an-array/

# Solution - 

class Solution:
    def maximumValue(self, strs: List[str]) -> int:
        ans = 0
        for each in strs:
            if each.isnumeric():
                ans = max(ans, int(each))
            else:
                ans = max(ans, len(each))
        return ans
