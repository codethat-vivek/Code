# Question Link - https://leetcode.com/problems/total-cost-to-hire-k-workers/

# Solution - 

class Solution:
    def totalCost(self, costs: List[int], k: int, candidates: int) -> int:
        n = len(costs)
        arr = []
        heapq.heapify(arr)
        ans = 0
        
        if 2*candidates <= n:
            for i in range(candidates):
                heapq.heappush(arr, (costs[i], i))
                heapq.heappush(arr, (costs[n-i-1], n-i-1))

            left, right = candidates, n-candidates-1
            while k:
                k -= 1
                c, idx = heapq.heappop(arr)
                ans += c
                if idx < left and left <= right:
                    heapq.heappush(arr, (costs[left], left))
                    left += 1
                elif idx > right and left <= right:
                    heapq.heappush(arr, (costs[right], right))
                    right -= 1
            return ans
        
        for idx, ele in enumerate(costs):
            heapq.heappush(arr, (ele, idx))
        
        while k:
            k -= 1
            c, idx = heapq.heappop(arr)
            ans += c
        return ans
        
