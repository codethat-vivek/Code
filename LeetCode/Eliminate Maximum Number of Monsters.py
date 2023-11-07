# Question Link - https://leetcode.com/problems/eliminate-maximum-number-of-monsters/

# Solution - 

class Solution:
    def eliminateMaximum(self, dist: List[int], speed: List[int]) -> int:
        n, arr = len(dist), []
        for u, v in zip(dist, speed):
            arr.append((u, v))
        arr.sort(key = lambda x : (x[0]/x[1]))
        ans = 0
        for i in range(n):
            u, v = arr[i]
            if u-i*v <= 0:
                return ans
            ans += 1
        
        return ans
