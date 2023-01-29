# Question Link - https://leetcode.com/problems/count-collisions-of-monkeys-on-a-polygon/

# Solution - 

class Solution:    
    def monkeyMove(self, n: int) -> int:
        return (pow(2, n, 1000000007) - 2) % 1000000007
