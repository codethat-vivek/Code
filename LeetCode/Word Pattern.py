# Question Link - https://leetcode.com/problems/word-pattern/

# Solution - 

class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:
        p = len(pattern)
        l = len(s.split(" "))
        if p != l : return False
        s = s.split(" ")
        dt = dict()
        for i in range(p):
            if pattern[i] not in dt:
                if s[i] not in dt.values():
                    dt[pattern[i]] = s[i]
                else:
                    return False
            else:
                if dt[pattern[i]] != s[i]:
                    return False
        return True
