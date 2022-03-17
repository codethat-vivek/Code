# Question Link - https://leetcode.com/problems/add-binary/

# Solution - 

class Solution:
    def toBinary(self, a):
        if a == 0:
            return "0"
        ans = ""
        while a:
            ans += str(a % 2)
            a = a//2
        return ans[::-1]
        
    def addBinary(self, a: str, b: str) -> str:
        
        return self.toBinary(int(a, 2) + int(b, 2))
        
