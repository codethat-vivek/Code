# Question Link - https://leetcode.com/problems/mirror-reflection/

# Solution - 

class Solution:
    def mirrorReflection(self, p: int, q: int) -> int:
        def gcd(a, b):
            while b:
                a, b = b, a%b
            return a
        
        def compute_lcm(a, b):
            return (a*b)//(gcd(a, b))
        
        lcm = compute_lcm(p, q)
        print(lcm)
        
        if (lcm//q) % 2 == 1: # this means that we are going to get either 1 or 0
            if (lcm//p) % 2 == 1: 
                return 1
            return 0
        return 2
            
