# Question Link - https://leetcode.com/problems/happy-number/

# Solution - 

class Solution:
    def isHappy(self, n: int) -> bool:
        dt = dict()
        while n != 1:
            if n in dt:
                return False
            dt[n] = 1
            t = 0
            for each in str(n):
                t += (int(each))**2
            n = t
            #print(n)
        if n == 1:return True
        return False
            
