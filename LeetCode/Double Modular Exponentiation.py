# Question Link - Double Modular Exponentiation

# Solution - https://leetcode.com/problems/double-modular-exponentiation/

class Solution:
    def getGoodIndices(self, variables: List[List[int]], target: int) -> List[int]:
        ans = []
        for i in range(len(variables)):
            a, b, c, d = variables[i]
            if ((a**b % 10)**c) % d == target:
                ans.append(i)
        return ans
