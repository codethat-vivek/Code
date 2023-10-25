# Question Link - https://leetcode.com/problems/k-th-symbol-in-grammar/

# Solution - 

class Solution:
    def kthGrammar(self, n: int, k: int) -> int:
        import math
        x = [[0, 1], [1, 0]]
        dt = dict()
        def f(m, i):
            if m == 1 or i == 1 : return 0
            if (m-1, math.ceil(i/2)) in dt:
                return dt[(m-1, math.ceil(i/2))]
            t = f(m-1, max(math.ceil(i/2), 1))
            if i//2 == i/2:
                dt[(m-1, math.ceil(i/2))] = x[t][1]
                return x[t][1]
            dt[(m-1, math.ceil(i/2))] = x[t][0]
            return x[t][0]
        
        
        return f(n, k)
