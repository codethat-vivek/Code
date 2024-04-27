# Question Link - https://leetcode.com/problems/count-the-number-of-special-characters-ii/

# Solution - 

class Solution:
    def numberOfSpecialChars(self, word: str) -> int:
        ans = 0
        dt = dict()
        st = set(word)
        
        for idx, c in enumerate(word):
            if c not in dt or 97 <= ord(c) <= 122:
                dt[c] = idx
            
        for c in st:
            if 65 <= ord(c) <= 90:
                if chr(ord(c)+32) in dt and dt[chr(ord(c)+32)] < dt[c]:
                    ans += 1
                    
        
        return ans
