# Question Link - https://leetcode.com/problems/first-unique-character-in-a-string/

# Solution - 

class Solution:
    def firstUniqChar(self, s: str) -> int:
        freq = [0]*26
        for char in s:
            freq[ord(char)-ord('a')]+=1
        
        for idx, char in enumerate(s):
            if freq[ord(char)-ord('a')] == 1:
                return idx
        return -1
