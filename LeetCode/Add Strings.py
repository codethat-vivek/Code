# Question Link - https://leetcode.com/problems/add-strings/

# Solution - 

class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        m = len(num1)
        n = len(num2)
        if m > n:
            num2 = (m-n)*"0" + num2
        elif m < n:
            return self.addStrings(num2, num1)
        # now m = n
        i, j = m-1, n-1
        ans = ""
        carry = 0
        while i >= 0:
            t = int(num1[i]) + int(num2[i]) + carry
            if t <= 9:
                ans = str(t) + ans
                carry = 0
            else:
                ans = str(t)[1] + ans
                carry = int(str(t)[0])
            i -= 1
        if carry != 0:
            return str(carry)+ans
        return ans
