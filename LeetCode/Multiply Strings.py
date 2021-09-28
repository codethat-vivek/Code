# Question Link - https://leetcode.com/problems/multiply-strings/

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
        
    def multiply(self, num1: str, num2: str) -> str:
        if num1 == "0" or num2 == "0" : return "0"
        m, n = len(num1), len(num2)
        arr = []
        i, j, times = m-1, n-1, 0
        while j >= 0:
            carry, t = 0, ""
            while i >= 0:
                x = int(num1[i])*int(num2[j])+carry
                if x <= 9:
                    t = str(x)+t
                    carry = 0
                else:
                    t = str(x)[-1] + t
                    carry = int(str(x)[:-1])
                i -= 1
            if carry != 0 : t = str(carry)+t
            t += times*"0"
            times += 1
            i = m-1
            arr.append(t)
            j -= 1
        finalAns = arr[0]
        for i in range(1, len(arr)):
            finalAns = self.addStrings(finalAns, arr[i])
        return finalAns
   
