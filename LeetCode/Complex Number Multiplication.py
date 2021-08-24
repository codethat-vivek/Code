# Question Link - https://leetcode.com/problems/complex-number-multiplication/

# Solution - 

class Solution:
    def separate(self, s):
        plus = s.index("+")
        real = int(s[:plus])
        imag = int(s[plus+1:-1])
        return [real, imag]
    def complexNumberMultiply(self, num1: str, num2: str) -> str:
        a, b = self.separate(num1)
        c, d = self.separate(num2)
        first = str(a*c - b*d) + "+"
        second = str(a*d + b*c) + "i"
        return first+second
