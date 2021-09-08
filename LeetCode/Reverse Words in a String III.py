# Question Link - https://leetcode.com/problems/reverse-words-in-a-string-iii/

# Solution - 

class Solution:
    def reverseWords(self, s: str) -> str:
        lt = s.split(" ")
        # ans = []
        for i in range(len(lt)):
            lt[i] = lt[i][::-1]
        return " ".join(lt)
