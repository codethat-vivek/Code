# Question Link - https://leetcode.com/problems/interleaving-string/

# Solution - 

class Solution:
    def isInterleave(self, s1: str, s2: str, s3: str) -> bool:
        a, b, c = len(s1), len(s2), len(s3)
        if c != a + b:
            return False
        @lru_cache
        def helper(i, j, k):
            if k == c:
                return True
            if not(0 <= i < a):
                if s2[j:] == s3[k:] : return True
                return False
            if not(0 <= j < b):
                if s1[i:] == s3[k:] : return True
                return False
            if s1[i] != s3[k] and s2[j] != s3[k]:
                return False
            if s1[i] == s3[k] and s2[j] != s3[k]:
                return helper(i+1, j, k+1)
            if s2[j] == s3[k] and s1[i] != s3[k]:
                return helper(i, j+1, k+1)
            return helper(i+1, j, k+1) or helper(i, j+1, k+1)
            
            
        return helper(0, 0, 0)
