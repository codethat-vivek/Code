# Question Link - https://leetcode.com/problems/consecutive-numbers-sum/

# Solution - 

class Solution:
    def consecutiveNumbersSum(self, n: int) -> int:
        def divisors(n):
            if n == 1:
                return 1
            res = 0
            for i in range(1, int(math.sqrt(n))+1):
                if n % i == 0:
                    res += 1
                    if i != n // i:
                        res += 1
            return res
        
        if n % 2 == 1: return divisors(n)
        
        ans = 1
        i = 3
        while True:
            if n >= (i*(i+1)//2):
                x = n - (i*(i+1)//2)
                if x % i == 0:
                    ans += 1
            else:
                break
            i += 1
        return ans
            
