# Question Link - https://leetcode.com/problems/count-numbers-with-unique-digits/

# Solution - 

class Solution:
    def countNumbersWithUniqueDigits(self, n: int) -> int:
        if n == 0:
            return 1
        def calc(digits):
            if digits == 1:
                return 10
            cnt, mul = 1, 9
            for i in range(digits):
                if i == 0 or i == 1:
                    cnt *= mul
                else:
                    cnt *= (mul-1)
                    mul -= 1
            return cnt
        
        ans = 0
        for i in range(1, n+1):
            ans += calc(i)
        return ans
        
