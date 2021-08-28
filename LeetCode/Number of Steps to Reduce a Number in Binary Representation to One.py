# Question Link - https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/

# Solution - 

class Solution:
    def numSteps(self, s: str) -> int:
        n = int(s, 2)
        steps = 0
        while n != 1:
            if n % 2:
                n += 1
            else:
                n = n // 2
            steps += 1
        return steps
