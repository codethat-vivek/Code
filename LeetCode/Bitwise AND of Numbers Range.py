# Question Link - https://leetcode.com/problems/bitwise-and-of-numbers-range/

# Solution - 

class Solution:
    import math
    def highestPowerof2(self, n):
        p = int(math.log(n, 2));
        return int(pow(2, p));
    def rangeBitwiseAnd(self, left: int, right: int) -> int:
        if left == 0 or right == 0 : return 0
        if left == right : return left
        l = self.highestPowerof2(left)
        r = self.highestPowerof2(right)
        if l == r : 
            return l + self.rangeBitwiseAnd(left-l, right-l)
        return 0
