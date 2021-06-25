# Question Link - https://leetcode.com/problems/unique-binary-search-trees/

# Solution - 

class Solution:
    def numTrees(self, n: int) -> int:
        # CATALAN NUMBERS
        # 1   1   2   5   14   42   132 .....
        # c0 c1  c2  c3   c4   c5   c6 ..... 
        # C(n) = C(0)*C(n-1) + C(1)*C(n-2) + C(2)*C(n-3) + .......... + C(n-1)C(0)

        l = [0 for _ in range(n+1)]
        l[0] = 1
        l[1] = 1 

        for i in range(2, n+1):
            a = 0
            b = i-1
            while a <= b:
                if a!=b:
                    l[i] += 2*l[a]*l[b]
                else:
                    l[i] += l[a]*l[b]
                a += 1
                b -= 1

        return l[n]
