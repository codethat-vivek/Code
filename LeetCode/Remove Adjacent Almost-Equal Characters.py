# Question Link - https://leetcode.com/problems/remove-adjacent-almost-equal-characters/

# Solution - 

class Solution:
    def removeAlmostEqualCharacters(self, word: str) -> int:
        n = len(word)
        ans, i = 0, 0
        while i < n-1:
            if word[i] == word[i+1] or abs(ord(word[i]) - ord(word[i+1])) == 1:
                ans += 1
                i += 2
            else:
                i += 1
        return ans
