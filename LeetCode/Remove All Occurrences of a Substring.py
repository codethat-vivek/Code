# Question Link - https://leetcode.com/problems/remove-all-occurrences-of-a-substring/description/

# Solution -

class Solution:
    def removeOccurrences(self, s: str, part: str) -> str:
        while True:
            try:
                idx = s.index(part)
                s = s[:idx] + s[idx+len(part):]
            except ValueError:
                return s

        return s
