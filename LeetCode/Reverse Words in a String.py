# Question Link - https://leetcode.com/problems/reverse-words-in-a-string/

# Solution Details - https://leetcode.com/submissions/detail/448547746/

# SOLUTION - 


class Solution:
    def reverseWords(self, s: str) -> str:
        l = s.split(" ")
        sentence = ""
        for i in range(len(l)-1, -1, -1):
            if(l[i] != ""):
                sentence += l[i]
                sentence += " "
        return sentence[:len(sentence)-1]
