# Question Link - https://leetcode.com/problems/smallest-string-with-a-given-numeric-value/

# Solution - 

class Solution:
    def getSmallestString(self, n: int, k: int) -> str:
        ans = ['z']*n
        points = 26*n
        
        if points > k:
            diff = points - k
            places = diff//25
            rem = diff % 25
            i = 0
            while i < places:
                ans[i] = 'a'
                i += 1
            ans[i] = chr(ord(ans[i])-rem)
        
        return ''.join(ans)
        
        
