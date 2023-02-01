# Question Link - https://leetcode.com/problems/greatest-common-divisor-of-strings/

# Solution - 

class Solution:
    def gcd(self, a, b):
        while b:
            a, b = b, a%b
        return a
    
    def factors(self, x):
        arr = [1, x]
        for i in range(2, int(math.sqrt(x))+1):
            if x % i == 0:
                arr.append(x)
                if i != x/i:
                    arr.append(x/i)
        return sorted(arr)
    
    def divides(self, sub, string):
        if len(string) % len(sub) != 0:
            return False
        return string == sub*(len(string)//len(sub))
    
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        m, n = len(str1), len(str2)
        x = self.gcd(m, n)
        fac = self.factors(x)
        ans, string = "", ""
        i = 0
        for f in fac:
            t = f-i
            while t:
                t -= 1
                string += str2[i]
                i += 1
            if not self.divides(string, str1) or not self.divides(string, str2):
                continue
            if len(ans) < len(string):
                ans = string
        return ans
