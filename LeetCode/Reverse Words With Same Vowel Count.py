# Question Link - https://leetcode.com/problems/reverse-words-with-same-vowel-count/description/

# Solution - 

class Solution:
    def reverseWords(self, s: str) -> str:
        words = s.split(' ')
        dt, ans, firstWordVowelCount = dict(), "", -1
        for idx, word in enumerate(words):
            cnt = 0
            for letter in word:
                if letter in 'aeiou':
                    cnt += 1
            dt[idx] = cnt
            if idx == 0:
                firstWordVowelCount = cnt
                ans += word
            elif cnt == firstWordVowelCount:
                ans += (' ' + word[::-1])
            else:
                ans += (' ' + word)
        
        return ans
