# Question Link - https://leetcode.com/problems/valid-palindrome-ii/

# Solution - 

class Solution:
    def validPalindrome(self, s: str) -> bool:
        def isPalindrome(s):
            return s == s[::-1]
        i, j = 0, len(s)-1
        while i < j and s[i] == s[j]:
            i += 1
            j -= 1
        
        if i >= j:
            return True
        
        if isPalindrome(s[i+1:j+1]) or isPalindrome(s[i:j]):
            return True
        
        return False
            
