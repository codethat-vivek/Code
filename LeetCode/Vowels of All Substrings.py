# Question Link - https://leetcode.com/problems/vowels-of-all-substrings/

# Solution - 

class Solution:
    def countVowels(self, word: str) -> int:
        ans = 0
        for i in range(len(word)):
            if word[i] in "aeiou":
                ans += (i+1)*(len(word)-i)
        return ans
