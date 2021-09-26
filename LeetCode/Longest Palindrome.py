# Question Link - https://leetcode.com/problems/longest-palindrome/

# Solution - 

class Solution:
    def longestPalindrome(self, s: str) -> int:
        dt = dict()
        for each in s:
            if each not in dt:
                dt[each] = 1
            else:
                dt[each] += 1
        anyone = False
        ans = 0
        for each in dt:
            if dt[each] % 2 != 0:
                anyone = True
                ans += dt[each]-1
            else:
                ans += dt[each]
        if anyone:
            ans += 1
        return ans
                
