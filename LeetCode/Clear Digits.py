# Question Link - https://leetcode.com/problems/clear-digits/

# Solution - 

class Solution:
    def clearDigits(self, s: str) -> str:
        n, stack, i = len(s), [], 0
        while i < n:
            if not s[i].isdigit():
                stack.append(s[i])
            else:
                if stack: stack.pop()
            i += 1
        return ''.join(stack)
