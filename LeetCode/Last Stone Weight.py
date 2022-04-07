# Question Link - https://leetcode.com/problems/last-stone-weight/

# Solution - 

class Solution:
    def lastStoneWeight(self, stones: List[int]) -> int:
        if len(stones) == 1:
            return stones[0]
        stones.sort()
        
        while len(stones) > 1:
            first, second = stones[-1], stones[-2]
            stones.pop()
            stones.pop()
            if first == second:
                continue
            bisect.insort(stones, abs(second - first))
            
        if len(stones) == 0:
            return 0
        return stones[0]
            
        
