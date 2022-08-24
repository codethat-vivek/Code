# Question Link - https://leetcode.com/problems/power-of-three/

# Solution - 

class Solution:
    def isPowerOfThree(self, n: int) -> bool:
        if n <= 0 : return False
        return log10(n)/log10(3) == int(log10(n)/log10(3))
