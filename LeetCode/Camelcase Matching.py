# Question Link - https://leetcode.com/problems/camelcase-matching/description/

# Solution - 

class Solution:
    def camelMatch(self, queries: List[str], pattern: str) -> List[bool]:
        def countCapitalLetters(s):
            return sum([1 for each in s if ord('A') <= ord(each) <= ord('Z')])
        
        def isSubsequence(big, small):
            m, n = len(big), len(small)
            if m < n: return False
            i, j = 0, 0
            while i<m and j<n:
                if big[i] == small[j]:
                    j += 1
                i += 1
            return j >= n

        ans = []
        p = countCapitalLetters(pattern)
        for each in queries:
            if countCapitalLetters(each) == p and isSubsequence(each, pattern):
                ans.append(True)
            else:
                ans.append(False)
        
        return ans
