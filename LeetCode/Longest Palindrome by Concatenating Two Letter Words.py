# Question Link - https://leetcode.com/problems/longest-palindrome-by-concatenating-two-letter-words/

# Solution - 

class Solution:
    def longestPalindrome(self, words: List[str]) -> int:
        dt = collections.Counter(words)
        lonePalindrome = False
        
        ans = 0
        for each in dt:
            if each != each[::-1] and each[::-1] in dt:
                ans += min(dt[each], dt[each[::-1]])
            if each == each[::-1]:
                ans += 2*(dt[each] // 2)
                if dt[each] % 2 == 1:
                    lonePalindrome = True
        if lonePalindrome:
            return 2*ans + 2
        return 2*ans
