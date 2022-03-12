# Question Link - https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iv/

# Solution - 

class Solution:
    def maxProfit(self, k: int, prices: List[int]) -> int:
        @lru_cache(None)
        
        # cnt - count of the transactions that have been completed till now
        def go(stocks, idx, cnt):
            
            if idx >= len(prices) or cnt >= k:
                return 0
            
            buy = (-prices[idx]+go(stocks+1, idx+1, cnt) if stocks == 0 else -inf)
            sell = (prices[idx]+go(stocks-1, idx+1, cnt+1) if stocks == 1 else -inf)
            hold = go(stocks, idx+1, cnt) 
            
            return max(buy, sell, hold)
        
        return go(0, 0, 0)
