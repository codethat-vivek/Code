# Question Link - https://leetcode.com/problems/unique-number-of-occurrences/

# Solution - 

class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        f = collections.Counter(arr)
        ff = collections.Counter(f.values())
        for each in ff.values():
            if each != 1:
                return False
        return True
