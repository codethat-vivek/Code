# Question Link - https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful/

# Solution - 

class Solution:
    def minChanges(self, s: str) -> int:
        cnt = 0
        for i in range(0, len(s)-1, 2):
            if s[i] != s[i+1]:
                cnt += 1
        
        return cnt
    
