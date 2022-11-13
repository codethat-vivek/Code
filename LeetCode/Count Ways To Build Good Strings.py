# Question Link - https://leetcode.com/problems/count-ways-to-build-good-strings/

# Solution - 

class Solution:
    def countGoodStrings(self, low: int, high: int, zero: int, one: int) -> int:
        # zero, one
        MOD = int(1e9+7)
        @lru_cache(None)
        def f(length):
            if length < 0 : return -1 # not possible
            if length < zero and length < one : return 0
            if length == zero:
                if length < one: return 1
                if length == one: return 2
                return (f(length - one)+1)%MOD
            
            if length == one:
                if length < zero: return 1
                return (f(length - zero)+1)%MOD
                
            firstWay = f(length - zero)
            secondWay = f(length - one)
            
            if firstWay == secondWay == -1 : return -1
            if firstWay == -1 : return secondWay
            if secondWay == -1 : return firstWay
            
            return (firstWay + secondWay)%MOD
        
        ans = 0
        for i in range(low, high+1):
            x = f(i)
            ans = (ans+x)%MOD
        return ans
            
