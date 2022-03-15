# Question Link - https://leetcode.com/problems/repeated-substring-pattern/

# Solution - 

class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        substring = ""
        for i in s:
            substring += i
            if substring != s and substring * (len(s)//len(substring)) == s:
                return True
        return False
