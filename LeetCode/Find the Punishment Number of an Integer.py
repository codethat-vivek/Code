# Question Link - https://leetcode.com/problems/find-the-punishment-number-of-an-integer/

# Solution - 

class Solution:
    def punishmentNumber(self, n: int) -> int:
        def part(x):
            n = len(x)
            if n == 0:
                return []
            if n == 1:
                return [int(x)]
            
            p = set()
            
            for i in range(1, n):
                f = part(x[:i])
                s = part(x[i:])
                for a in f:
                    for b in s:
                        p.add(a + b)
            p.add(int(x))
            return p
        
        ans = 0
        for i in range(1, n+1):
            if i in part(str(i**2)):
                ans += i**2
        
        return ans
