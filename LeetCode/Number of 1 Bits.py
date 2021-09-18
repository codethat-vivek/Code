# Question Link - https://leetcode.com/problems/power-of-two/

# Solution - 

class Solution:
    def hammingWeight(self, n: int) -> int:
        i = 1
        cnt = 0
        while i <= n:
            if (i & n) != 0:
                cnt += 1
            i = (i << 1)
        return cnt
