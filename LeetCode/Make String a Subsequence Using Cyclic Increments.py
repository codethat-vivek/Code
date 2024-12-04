# Question Link - https://leetcode.com/problems/make-string-a-subsequence-using-cyclic-increments/

# Solution - 

class Solution:
    def canMakeSubsequence(self, str1: str, str2: str) -> bool:
        m, n = len(str1), len(str2)
        if m < n : return False
        
        def next_char(c):
            if c == 'z': return 'a'
            return chr(ord(c)+1)
        def isSub(a, b): # returns True if b is subseq of a
            m, n, i, j = len(a), len(b), 0, 0
            if m < n : return False
            while i < m and j < n:
                if a[i] == b[j] or next_char(a[i]) == b[j]:
                    j += 1
                i += 1
            return j >= n                    
        
        return isSub(str1, str2)
