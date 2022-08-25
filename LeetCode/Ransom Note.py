# Question Link - https://leetcode.com/problems/ransom-note/

# Solution - 

class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        mgz = collections.Counter(magazine)
        rnt = collections.Counter(ransomNote)
        
        for each in rnt:
            if rnt[each] > mgz[each]:
                return False
        return True
