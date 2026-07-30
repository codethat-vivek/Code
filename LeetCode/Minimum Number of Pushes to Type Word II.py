# Question Link - https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-ii/

# Solution - 

class Solution:
    def minimumPushes(self, word: str) -> int:
        cnt = collections.Counter(word)
        cnt = dict(sorted(cnt.items(), key = lambda x : -x[1]))
        n, ans = len(cnt), 0
        curr, mul = 0, 0
        for c in cnt:
            if curr % 8 == 0:
                mul += 1
            ans += mul*cnt[c]
            curr += 1

        return ans

