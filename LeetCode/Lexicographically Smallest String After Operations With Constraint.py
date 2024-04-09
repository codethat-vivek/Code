# Question Link - https://leetcode.com/problems/lexicographically-smallest-string-after-operations-with-constraint/

# Solution - 

class Solution:
    
    def getSmallestString(self, s: str, k: int) -> str:
        n, i = len(s), 0
        ans = [c for c in s]
        if k == 0:
            return s
        while i < n and k > 0:
            t = ord(s[i])-ord('a')
            if t <= 12:
                if k >= t:
                    k -= t
                    ans[i] = 'a'
                else:
                    ans[i] = chr(ord(s[i])-k)
                    return ''.join(ans)
            else:
                if k >= 26-t:
                    k -= (26-t)
                    ans[i] = 'a'
                else:
                    ans[i] = chr(ord(s[i])-k)
                    return ''.join(ans)
            i += 1
        
        return ''.join(ans)
                    
