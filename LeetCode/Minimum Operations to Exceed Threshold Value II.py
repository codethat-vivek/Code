# Question Link - https://leetcode.com/problems/minimum-operations-to-exceed-threshold-value-ii/description/

# Solution - 

class Solution:
    def minOperations(self, nums: List[int], k: int) -> int:
        n = len(nums)
        hp = []
        for num in nums:
            heapq.heappush(hp, num)
        
        ops = 0
        while True:
            if len(hp) >= 2:
                f = heapq.heappop(hp)
                if f >= k:
                    break
                s = heapq.heappop(hp)
                ops += 1
                heapq.heappush(hp, f*2 + s)
            else:
                break
        return ops
