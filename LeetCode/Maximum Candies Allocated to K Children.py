# Question Link - https://leetcode.com/problems/maximum-candies-allocated-to-k-children/

# Solution - 

class Solution:
    def maximumCandies(self, candies: List[int], k: int) -> int:
        '''
        Max -> max of candies
        min -> 1
        '''

        def good(mid):
            res = 0
            for each in candies:
                res += each//mid
            return res
        

        n, sm = len(candies), sum(candies)
        if k > sm: return 0
        if sm == k: return 1
        ans = 0
        left, right = 1, max(candies)
        while left <= right:
            mid = left + (right - left)//2
            g = good(mid)
            print(left, right, mid, g)
            if g >= k:
                ans = mid
                left = mid+1
            elif g < k:
                right = mid-1

        return ans

