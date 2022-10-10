# Question Link - https://leetcode.com/problems/break-a-palindrome/

# Solution - 

class Solution:
    def breakPalindrome(self, palindrome: str) -> str:
        n = len(palindrome)
        if n == 1 : return ""
        
        def go(size):
            for i in range(size):
                if palindrome[i] != 'a':
                    return palindrome[:i] + 'a' + palindrome[i+1:]
            return palindrome[:-1] + 'b'
        
        if n % 2:
            return go(n//2)
        
        return go(n)
