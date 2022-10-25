# Question Link - https://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/

# Solution - 

class Solution:
    def arrayStringsAreEqual(self, word1: List[str], word2: List[str]) -> bool:
        x = y = ""
        for each in word1 : x += each
        for each in word2 : y += each
        
        return x == y
