# Question Link - https://leetcode.com/problems/sum-of-numbers-with-units-digit-k

# Solution - 

class Solution:
    def minimumNumbers(self, num: int, k: int) -> int:
        if num == 0 : return 0
        if num < 0 : return 0
        if k == 0 and num%10 != 0: return -1
        if k == 0 and num%10 == 0: return 1
        original = num
        while num > 0 and num % 10 != k:
            num -= k
        if num < 0:
            return -1
        return 1 + self.minimumNumbers(original-num, k)
        
        
