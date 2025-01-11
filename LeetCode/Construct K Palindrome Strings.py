# Question Link - https://leetcode.com/problems/construct-k-palindrome-strings/description/

# Solution - 

class Solution:
    def canConstruct(self, s: str, k: int) -> bool:
        cnt = collections.Counter(s)
        mn = 0
        for c in cnt:
            mn += (cnt[c]%2)
        print(mn)
        return mn <= k <= len(s)
