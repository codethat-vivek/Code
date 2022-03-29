# Question Link - https://leetcode.com/problems/roman-to-integer/

# Solution - 

class Solution:
    def romanToInt(self, s: str) -> int:
        dt = dict()
        dt['I'] = 1
        dt['V'] = 5
        dt['X'] = 10
        dt['L'] = 50
        dt['C'] = 100
        dt['D'] = 500
        dt['M'] = 1000
        
        s = s[::-1]
        ans = dt[s[0]]
        for i in range(1, len(s)):
            if dt[s[i-1]] > dt[s[i]]:
                ans -= dt[s[i]]
            else:
                ans += dt[s[i]]
        return ans
                
