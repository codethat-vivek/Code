# Question Link - https://leetcode.com/problems/strong-password-checker-ii/

# Solution - 

class Solution:
    def strongPasswordCheckerII(self, password: str) -> bool:
        if len(password) < 8:
            return False
        lower = upper = digit = special = False
        prevChar = password[0]
        i = 0
        asc = ord(password[i])
        if 65 <= asc < 91: upper = True
        if 97 <= asc < 123: lower = True
        if password[i].isdigit() : digit = True
        if password[i] in "!@#$%^&*()-+": special = True
        for i in range(1, len(password)):
            asc = ord(password[i])
            if 65 <= asc < 91: upper = True
            if 97 <= asc < 123: lower = True
            if password[i].isdigit() : digit = True
            if password[i] in "!@#$%^&*()-+": special = True
            if prevChar == password[i]:return False
            prevChar = password[i]
        
        if lower and upper and digit and special : return True
        return False
